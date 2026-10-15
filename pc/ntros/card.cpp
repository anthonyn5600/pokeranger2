// The game card (NitroSDK card_common.c / card_rom.c / card_backup.c): ROM reads come from the files folder
// (romfs.cpp), the backup memory (flash / EEPROM / FRAM) lives in a raw .sav file, the same format melonDS and
// DeSmuME use. As in the SDK, asynchronous requests run on the card thread (priority CARD_THREAD_PRIORITY_DEFAULT), which
// calls the request's callback when done; synchronous ones run on the caller.
//
// The save is $NTR_SAVE, else NtrOs_Cartridge.saveName in the current directory. A missing save reads as an erased chip (all 0xFF); the file is written
// on the first write, the whole chip, then only the bytes each request changes.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>

#include "ntros.h"

#include "internal.hpp"

namespace ntros {
namespace {

    enum : u32 {
        kStatInit = 0x0001,
        kStatBusy = 0x0004, // a request runs (CARD_STAT_BUSY)
        kStatTask = 0x0008, // the card thread has a task (CARD_STAT_TASK)
        kStatCancel = 0x0040, // CARD_CancelBackupAsync
    };

    enum Target {
        kTargetNone,
        kTargetRom,
        kTargetBackup,
    };

    struct BackupSpec {
        u32 totalSize;
        u32 sectorSize;
        u32 pageSize;
        bool flash; // programming can only clear bits (an erase sets them back to 1)
    };

    struct Card {
        u32 flag;
        CARDResult result;
        // Lock (CARD_LockRom / CARD_LockBackup)
        s32 lockOwner = OS_LOCK_ID_ERROR;
        int lockRef;
        Target lockTarget;
        OSThreadQueue lockQueue;
        // Request in progress
        OSThreadQueue busyQueue;
        MIDmaCallback callback;
        void *callbackArg;
        void (*task)();
        uPtr src;
        uPtr dst;
        u32 len;
        CARDRequest request;
        CARDRequestMode mode;
        BOOL verify; // CARDi_RequestWriteSectorCommand
        // Card thread
        OSThread thread;
        u32 priority;
        u64 stack[0x400 / sizeof(u64)];
        CARDPulledOutCallback pulledOutCallback;
        // Backup memory
        CARDBackupType backupType;
        BackupSpec spec;
        std::vector<u8> backup;
        std::string savePath;
        FILE *save;
        bool saveComplete; // the file holds the whole chip
    };

    Card sCard;

    void Fail(const char *what, const std::string &path)
    {
        OS_Panic("card: %s '%s'", what, path.c_str());
    }

    void LoadRomHeader()
    {
        RomFs_Init();
        // What the boot loader leaves in memory (CARD_GetRomRegionFNT/FAT read it), and the card's own copy
        RomFs_Read(0, (void *)HW_ROM_HEADER_BUF, HW_CARD_ROM_HEADER_SIZE);
        MI_CpuCopy8((const void *)HW_ROM_HEADER_BUF, (void *)HW_CARD_ROM_HEADER, HW_CARD_ROM_HEADER_SIZE);
    }

    // Backup memory

    std::string SavePath()
    {
        if (const char *env = getenv("NTR_SAVE")) {
            return env;
        }
        return NtrOs_Cartridge.saveName;
    }

    // CARDi_IdentifyBackupCore's table
    bool Identify(CARDBackupType type, BackupSpec *spec)
    {
        u32 size = 1u << ((type >> CARD_BACKUP_TYPE_SIZEBIT_SHIFT) & CARD_BACKUP_TYPE_SIZEBIT_MASK);
        int device = (type >> CARD_BACKUP_TYPE_DEVICE_SHIFT) & CARD_BACKUP_TYPE_DEVICE_MASK;
        *spec = {};
        spec->totalSize = size;
        switch (device) {
        case CARD_BACKUP_TYPE_DEVICE_EEPROM:
            if (size == 0x200) {
                spec->pageSize = 0x10;
            } else if (size == 0x2000) {
                spec->pageSize = 0x20;
            } else if (size == 0x10000) {
                spec->pageSize = 0x80;
            } else {
                return false;
            }
            spec->sectorSize = spec->pageSize;
            return true;
        case CARD_BACKUP_TYPE_DEVICE_FLASH:
            if (size != 0x40000 && size != 0x80000 && size != 0x100000 && size != 0x200000 && size != 0x400000
                && size != 0x800000) {
                return false;
            }
            spec->sectorSize = 0x10000;
            spec->pageSize = 0x100;
            spec->flash = true;
            return true;
        case CARD_BACKUP_TYPE_DEVICE_FRAM:
            if (size != 0x2000 && size != 0x8000) {
                return false;
            }
            spec->pageSize = size;
            spec->sectorSize = size;
            return true;
        default:
            return false;
        }
    }

    void LoadSave()
    {
        if (sCard.save != NULL) {
            fclose(sCard.save);
            sCard.save = NULL;
        }
        sCard.savePath = SavePath();
        sCard.backup.assign(sCard.spec.totalSize, 0xFF);
        sCard.saveComplete = false;
        FILE *f = fopen(sCard.savePath.c_str(), "rb+");
        if (f == NULL) {
            return;
        }
        size_t got = fread(sCard.backup.data(), 1, sCard.backup.size(), f);
        sCard.save = f;
        sCard.saveComplete = got == sCard.backup.size();
        if (!sCard.saveComplete) {
            // Shorter than the chip (another type, or cut): the rest reads as erased
            memset(sCard.backup.data() + got, 0xFF, sCard.backup.size() - got);
        }
    }

    // Write bytes [offset, offset + len) of the chip to the file
    void StoreSave(u32 offset, u32 len)
    {
        if (sCard.save == NULL) {
            sCard.save = fopen(sCard.savePath.c_str(), "wb+");
            if (sCard.save == NULL) {
                Fail("cannot create the save file", sCard.savePath);
            }
        }
        if (!sCard.saveComplete) {
            offset = 0;
            len = (u32)sCard.backup.size();
        }
        if (fseek(sCard.save, offset, SEEK_SET) != 0 || fwrite(sCard.backup.data() + offset, 1, len, sCard.save) != len
            || fflush(sCard.save) != 0) {
            Fail("cannot write the save file", sCard.savePath);
        }
        sCard.saveComplete = true;
    }

    bool InChip(u32 offset, u32 len)
    {
        return offset <= sCard.backup.size() && len <= sCard.backup.size() - offset;
    }

    // One chip command. Reads: chip offset src -> memory dst. The others: memory src -> chip offset dst.
    CARDResult BackupCommand(CARDRequest request, uPtr src, uPtr dstAddress, u32 len)
    {
        u8 *chip = sCard.backup.data();
        if (request == CARD_REQ_READ_BACKUP) {
            if (!InChip((u32)src, len)) {
                return CARD_RESULT_INVALID_PARAM;
            }
            memcpy((void *)dstAddress, chip + src, len);
            return CARD_RESULT_SUCCESS;
        }
        u32 dst = (u32)dstAddress;
        switch (request) {
        case CARD_REQ_WRITE_BACKUP: // page write: erase + program (flash), or a plain write
            if (!InChip(dst, len)) {
                return CARD_RESULT_INVALID_PARAM;
            }
            memcpy(chip + dst, (const void *)src, len);
            break;
        case CARD_REQ_PROGRAM_BACKUP:
            if (!InChip(dst, len)) {
                return CARD_RESULT_INVALID_PARAM;
            }
            if (sCard.spec.flash) {
                for (u32 i = 0; i < len; i++) {
                    chip[dst + i] &= ((const u8 *)src)[i];
                }
            } else {
                memcpy(chip + dst, (const void *)src, len);
            }
            break;
        case CARD_REQ_VERIFY_BACKUP:
            if (!InChip(dst, len)) {
                return CARD_RESULT_INVALID_PARAM;
            }
            return memcmp(chip + dst, (const void *)src, len) == 0 ? CARD_RESULT_SUCCESS : CARD_RESULT_FAILURE;
        case CARD_REQ_ERASE_PAGE_BACKUP:
        case CARD_REQ_ERASE_SECTOR_BACKUP:
        case CARD_REQ_ERASE_SUBSECTOR_BACKUP: {
            u32 unit = request == CARD_REQ_ERASE_PAGE_BACKUP ? sCard.spec.pageSize : sCard.spec.sectorSize;
            if (!sCard.spec.flash || unit == 0 || dst % unit != 0 || !InChip(dst, len)) {
                return CARD_RESULT_INVALID_PARAM;
            }
            memset(chip + dst, 0xFF, len);
            break;
        }
        case CARD_REQ_ERASE_CHIP_BACKUP:
            if (!sCard.spec.flash) {
                return CARD_RESULT_UNSUPPORTED;
            }
            dst = 0;
            len = (u32)sCard.backup.size();
            memset(chip, 0xFF, len);
            break;
        default:
            return CARD_RESULT_UNSUPPORTED;
        }
        StoreSave(dst, len);
        return CARD_RESULT_SUCCESS;
    }

    // Requests (CARDi_WaitTask / CARDi_EndTask / CARDi_SetTask)

    void WaitTask(MIDmaCallback callback, void *arg)
    {
        OSIntrMode psr = OS_DisableInterrupts();
        while ((sCard.flag & kStatBusy) != 0) {
            OS_SleepThread(&sCard.busyQueue);
        }
        sCard.flag |= kStatBusy;
        sCard.callback = callback;
        sCard.callbackArg = arg;
        (void)OS_RestoreInterrupts(psr);
    }

    void EndTask(CARDResult result)
    {
        MIDmaCallback callback = sCard.callback;
        void *arg = sCard.callbackArg;
        OSIntrMode psr = OS_DisableInterrupts();
        sCard.result = result;
        sCard.flag &= ~(kStatBusy | kStatTask | kStatCancel);
        OS_WakeupThread(&sCard.busyQueue);
        (void)OS_RestoreInterrupts(psr);
        if (callback != NULL) {
            callback(arg);
        }
    }

    void Run(void (*task)(), BOOL async)
    {
        if (async) {
            (void)OS_SetThreadPriority(&sCard.thread, sCard.priority);
            sCard.task = task;
            sCard.flag |= kStatTask;
            OS_WakeupThreadDirect(&sCard.thread);
        } else {
            task();
        }
    }

    void TaskThread(void *)
    {
        for (;;) {
            OSIntrMode psr = OS_DisableInterrupts();
            while ((sCard.flag & kStatTask) == 0) {
                OS_SleepThread(NULL);
            }
            (void)OS_RestoreInterrupts(psr);
            sCard.task();
        }
    }

    void ReadRomTask()
    {
        RomFs_Read((u32)sCard.src, (void *)sCard.dst, sCard.len);
        EndTask(CARD_RESULT_SUCCESS);
    }

    // CARDi_RequestStreamCommandCore: the SDK splits a request into chip pages; the result is the same in one go
    void StreamTask()
    {
        CARDResult result;
        if ((sCard.flag & kStatCancel) != 0) {
            result = CARD_RESULT_CANCELED;
        } else {
            result = BackupCommand(sCard.request, sCard.src, sCard.dst, sCard.len);
            if (result == CARD_RESULT_SUCCESS && sCard.mode == CARD_REQUEST_MODE_SEND_VERIFY) {
                result = BackupCommand(CARD_REQ_VERIFY_BACKUP, sCard.src, sCard.dst, sCard.len);
            }
        }
        EndTask(result);
    }

    // CARDi_RequestWriteSectorCommandCore: erase each sector, program it, verify it if asked
    void WriteSectorTask()
    {
        CARDResult result = CARD_RESULT_SUCCESS;
        u32 sector = sCard.spec.sectorSize;
        if (sector == 0 || sCard.dst % sector != 0 || sCard.len % sector != 0) {
            result = CARD_RESULT_INVALID_PARAM;
        }
        for (u32 done = 0; result == CARD_RESULT_SUCCESS && done < sCard.len; done += sector) {
            if ((sCard.flag & kStatCancel) != 0) {
                result = CARD_RESULT_CANCELED;
                break;
            }
            u32 dst = (u32)sCard.dst + done;
            uPtr src = sCard.src + done;
            result = BackupCommand(CARD_REQ_ERASE_SECTOR_BACKUP, 0, dst, sector);
            if (result == CARD_RESULT_SUCCESS) {
                result = BackupCommand(CARD_REQ_PROGRAM_BACKUP, src, dst, sector);
            }
            if (result == CARD_RESULT_SUCCESS && sCard.verify) {
                result = BackupCommand(CARD_REQ_VERIFY_BACKUP, src, dst, sector);
            }
        }
        EndTask(result);
    }

    void LockResource(u16 id, Target target)
    {
        OSIntrMode psr = OS_DisableInterrupts();
        if (sCard.lockOwner == id) {
            if (sCard.lockTarget != target) {
                OS_Panic("card-lock : can not reuse same ID for locking without unlocking!");
            }
        } else {
            while (sCard.lockOwner != OS_LOCK_ID_ERROR) {
                OS_SleepThread(&sCard.lockQueue);
            }
            sCard.lockOwner = id;
            sCard.lockTarget = target;
        }
        sCard.lockRef++;
        sCard.result = CARD_RESULT_SUCCESS;
        (void)OS_RestoreInterrupts(psr);
    }

    void UnlockResource(u16 id, Target target)
    {
        OSIntrMode psr = OS_DisableInterrupts();
        if (sCard.lockOwner != id || sCard.lockRef == 0) {
            OS_Panic("card-unlock : specified ID for unlocking is not locking one!");
        }
        if (sCard.lockTarget != target) {
            OS_Panic("card-unlock : locking target and unlocking one are different!");
        }
        if (--sCard.lockRef == 0) {
            sCard.lockOwner = OS_LOCK_ID_ERROR;
            sCard.lockTarget = kTargetNone;
            OS_WakeupThread(&sCard.lockQueue);
        }
        sCard.result = CARD_RESULT_SUCCESS;
        (void)OS_RestoreInterrupts(psr);
    }

} // namespace
} // namespace ntros

using namespace ntros;

extern "C" {

void CARD_Init(void)
{
    // libntr's ARM7 side (OS_Init7, its own host thread) calls this too; the card is the game thread's
    if (sCard.flag != 0 || !OnGameThread()) {
        return;
    }
    sCard.flag = kStatInit;
    LoadRomHeader();
    OS_InitThreadQueue(&sCard.lockQueue);
    OS_InitThreadQueue(&sCard.busyQueue);
    sCard.priority = CARD_THREAD_PRIORITY_DEFAULT;
    OS_CreateThread(&sCard.thread, TaskThread, NULL, sCard.stack + sizeof(sCard.stack) / sizeof(sCard.stack[0]), sizeof(sCard.stack), sCard.priority);
    OS_WakeupThreadDirect(&sCard.thread);
}

BOOL CARD_IsAvailable(void)
{
    return sCard.flag != 0;
}

BOOL CARD_IsEnabled(void)
{
    return TRUE;
}

void CARD_CheckEnabled(void)
{
}

void CARD_Enable(BOOL enable)
{
    (void)enable;
}

CARDResult CARD_GetResultCode(void)
{
    return sCard.result;
}

u32 CARD_GetThreadPriority(void)
{
    return sCard.priority;
}

u32 CARD_SetThreadPriority(u32 priority)
{
    OSIntrMode psr = OS_DisableInterrupts();
    u32 old = sCard.priority;
    sCard.priority = priority;
    (void)OS_SetThreadPriority(&sCard.thread, priority);
    (void)OS_RestoreInterrupts(psr);
    return old;
}

void CARD_GetCacheFlushThreshold(u32 *icache, u32 *dcache)
{
    if (icache != NULL) {
        *icache = 0xFFFFFFFF;
    }
    if (dcache != NULL) {
        *dcache = 0xFFFFFFFF;
    }
}

void CARD_SetCacheFlushThreshold(u32 icache, u32 dcache)
{
    (void)icache;
    (void)dcache;
}

const u8 *CARD_GetRomHeader(void)
{
    return (const u8 *)HW_CARD_ROM_HEADER;
}

// The card stays in: no pulled-out events
void CARD_InitPulledOutCallback(void)
{
}

void CARD_SetPulledOutCallback(CARDPulledOutCallback callback)
{
    sCard.pulledOutCallback = callback;
}

BOOL CARD_IsPulledOut(void)
{
    return FALSE;
}

void CARD_CheckPulledOut(void)
{
}

void CARD_TerminateForPulledOut(void)
{
    OS_Terminate();
}

// ROM

void CARD_LockRom(u16 id)
{
    LockResource(id, kTargetRom);
}

void CARD_UnlockRom(u16 id)
{
    UnlockResource(id, kTargetRom);
}

void CARDi_ReadRom(u32 dma, const void *src, void *dst, u32 len, MIDmaCallback callback, void *arg, BOOL async)
{
    (void)dma; // no DMA here: the SDK's transfer without DMA, on the card thread when asynchronous
    WaitTask(callback, arg);
    sCard.src = (uPtr)src;
    sCard.dst = (uPtr)dst;
    sCard.len = len;
    Run(ReadRomTask, async);
}

void CARD_WaitRomAsync(void)
{
    OSIntrMode psr = OS_DisableInterrupts();
    while ((sCard.flag & kStatBusy) != 0) {
        OS_SleepThread(&sCard.busyQueue);
    }
    (void)OS_RestoreInterrupts(psr);
}

BOOL CARD_TryWaitRomAsync(void)
{
    return (sCard.flag & kStatBusy) == 0;
}

// Backup

void CARD_LockBackup(u16 id)
{
    LockResource(id, kTargetBackup);
}

void CARD_UnlockBackup(u16 id)
{
    if (!CARD_TryWaitBackupAsync()) {
        OS_TWarning("called CARD_UnlockBackup() during backup asynchronous operation. (force to wait)\n");
        (void)CARD_WaitBackupAsync();
    }
    UnlockResource(id, kTargetBackup);
}

BOOL CARD_IdentifyBackup(CARDBackupType type)
{
    if (type == CARD_BACKUP_TYPE_NOT_USE) {
        OS_Panic("cannot specify CARD_BACKUP_TYPE_NOT_USE.");
    }
    if (sCard.lockTarget != kTargetBackup) {
        OS_Panic("CARD_IdentifyBackup() must be called with CARD locked by CARD_LockBackup()!");
    }
    WaitTask(NULL, NULL);
    CARDResult result = CARD_RESULT_SUCCESS;
    if (Identify(type, &sCard.spec)) {
        if (type != sCard.backupType) {
            sCard.backupType = type;
            LoadSave();
        }
    } else {
        sCard.backupType = CARD_BACKUP_TYPE_NOT_USE;
        sCard.spec = {};
        sCard.backup.clear();
        result = CARD_RESULT_UNSUPPORTED;
    }
    EndTask(result);
    return result == CARD_RESULT_SUCCESS;
}

CARDBackupType CARD_GetCurrentBackupType(void)
{
    return sCard.backupType;
}

u32 CARD_GetBackupTotalSize(void)
{
    return sCard.spec.totalSize;
}

u32 CARD_GetBackupSectorSize(void)
{
    return sCard.spec.sectorSize;
}

u32 CARD_GetBackupPageSize(void)
{
    return sCard.spec.pageSize;
}

BOOL CARDi_RequestStreamCommand(uPtr src, uPtr dst, u32 len, MIDmaCallback callback, void *arg, BOOL async, CARDRequest request, int retry, CARDRequestMode mode)
{
    (void)retry; // the file does not time out
    if (sCard.backupType == CARD_BACKUP_TYPE_NOT_USE) {
        OS_Panic("card: backup request before CARD_IdentifyBackup");
    }
    WaitTask(callback, arg);
    sCard.src = src;
    sCard.dst = dst;
    sCard.len = len;
    sCard.request = request;
    sCard.mode = mode;
    Run(StreamTask, async);
    return async || sCard.result == CARD_RESULT_SUCCESS;
}

BOOL CARDi_RequestWriteSectorCommand(uPtr src, u32 dst, u32 len, BOOL verify, MIDmaCallback callback, void *arg, BOOL async)
{
    if (sCard.backupType == CARD_BACKUP_TYPE_NOT_USE) {
        OS_Panic("card: backup request before CARD_IdentifyBackup");
    }
    WaitTask(callback, arg);
    sCard.src = src;
    sCard.dst = dst;
    sCard.len = len;
    sCard.verify = verify;
    Run(WriteSectorTask, async);
    return async || sCard.result == CARD_RESULT_SUCCESS;
}

int CARDi_AccessStatus(CARDRequest command, u8 value)
{
    (void)command;
    (void)value;
    return -1; // status register access: not supported here
}

BOOL CARD_WaitBackupAsync(void)
{
    CARD_WaitRomAsync();
    return sCard.result == CARD_RESULT_SUCCESS;
}

BOOL CARD_TryWaitBackupAsync(void)
{
    return CARD_TryWaitRomAsync();
}

void CARD_CancelBackupAsync(void)
{
    OSIntrMode psr = OS_DisableInterrupts();
    sCard.flag |= kStatCancel;
    (void)OS_RestoreInterrupts(psr);
}

} // extern "C"
