#include "CBackup.hpp"

#include <nitro.h>

#include "common.hpp"

CBackup::CBackup()
{
    unk_10 = NULL;
}

CBackup::~CBackup()
{
}

static void BackupCallback(void *arg);

BOOL CBackup::Write(u32 dst, const void *src, u32 len, MIDmaCallback callback)
{
    unk_10 = NULL;
    if (!unk_04 && !Init()) {
        return FALSE;
    }

    CARD_GetBackupPageSize();
    CARD_GetBackupTotalSize();
    CARD_LockBackup((u16)unk_08);
    if (CARD_IsBackupEeprom()) {
        CARD_WriteAndVerifyEepromAsync(dst, src, len, BackupCallback, this);
    } else if (CARD_IsBackupFlash()) {
        CARD_WriteAndVerifyFlashAsync(dst, src, len, BackupCallback, this);
    }
    unk_0C = CARD_GetResultCode();
    if (unk_0C != CARD_RESULT_SUCCESS) {
        return FALSE;
    }
    unk_10 = callback;
    return TRUE;
}

BOOL CBackup::Read(u32 src, void *dst, u32 len, MIDmaCallback callback)
{
    if (!unk_04 && !Init()) {
        return FALSE;
    }

    CARD_GetBackupPageSize();
    CARD_GetBackupTotalSize();
    CARD_LockBackup((u16)unk_08);
    if (CARD_IsBackupEeprom()) {
        CARD_ReadEepromAsync(src, dst, len, BackupCallback, this);
    } else if (CARD_IsBackupFlash()) {
        CARD_ReadFlashAsync(src, dst, len, BackupCallback, this);
    }
    unk_0C = CARD_GetResultCode();
    return unk_0C == CARD_RESULT_SUCCESS;
}

BOOL CBackup::Wait(BOOL block)
{
    if (block) {
        CARD_WaitBackupAsync();
        unk_0C = CARD_GetResultCode();
        return TRUE;
    }
    if (CARD_TryWaitBackupAsync() != TRUE) {
        return FALSE;
    }
    unk_0C = CARD_GetResultCode();
    return TRUE;
}

static void BackupCallback(void *arg)
{
    CBackup *backup = (CBackup *)arg;
    if (backup == NULL) {
        return;
    }
    CARD_UnlockBackup((u16)backup->unk_08);
    if (backup->unk_10 != NULL) {
        backup->unk_10(NULL);
    }
}
