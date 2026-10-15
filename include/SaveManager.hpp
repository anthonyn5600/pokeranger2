#ifndef POKERANGER2_SAVEMANAGER_HPP
#define POKERANGER2_SAVEMANAGER_HPP

#include <nitro.h>

#include "CBackup.hpp"
#include "common.hpp"

// A save file region: a list of RAM blocks (terminated by a NULL block whose size is the number of copies)
struct SaveBlock {
    void *data;
    u32 size;
};

// Header in front of each region's copies
struct SaveHeader {
    char magic[8];
    u32 offsets[2]; // of each copy, -2: none
    u16 sums[2];
    u16 slot; // last written copy
    u16 unk_0E;
    u16 checksum; // of the 0x18 bytes before it
    u16 unk_12;
};

// Saves and loads the save data regions through CBackup (card) or CBackupSync
class SaveManager {
public:
    SaveManager(u32 card);
    ~SaveManager();

    void SetDevice(int device);
    u32 GetCopies(int list);
    u32 GetSize(int list);
    u32 GetOffset(u16 list);
    u32 SumRegions(u16 count);
    u32 GetSlotOffset(int slot);
    u32 GetRegionSize(int list);
    void SelectList(u16 list);
    BOOL Save(u16 list);
    BOOL Load(u16 list);
    BOOL LoadPreviousCopy(u16 list);
    BOOL Clear(u16 list);
    BOOL CheckHeader(u16 list);
    u32 Update();
    u8 UpdateWrite(BOOL clear);
    u8 UpdateLoad();
    u8 UpdateClear();
    void CopyToBuffer(BOOL clear);
    void CopyFromBuffer();
    BOOL IsMagicValid();
    u16 Checksum(const void *data, int len);
    BOOL CheckSum(const void *data, int len, u16 sum);
    u8 UpdateWriteSteps();
    BOOL StartWriteSteps(u16 list);
    BOOL FinishWriteSteps();

    inline void SetState(int state, u8 error)
    {
        unk_54 = state;
        unk_64 = error;
    }

public:
    CBackupBase *unk_00;
    CBackup unk_04;
    CBackupSync unk_18;
    SaveHeader unk_38;
    int unk_54; // state
    u8 *unk_58; // buffer
    u32 unk_5C; // size of one copy
    u32 unk_60; // offset of the region
    u8 unk_64; // error
    u8 unk_65; // mode: 1 write, 2 load, 3 clear
    u16 unk_66; // list
    SaveBlock *unk_68;
    BOOL unk_6C;
    BOOL unk_70;
};

STATIC_SIZE_ASSERT(SaveManager, 0x74);

#endif // POKERANGER2_SAVEMANAGER_HPP
