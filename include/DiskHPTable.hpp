#ifndef POKERANGER2_DISKHPTABLE_HPP
#define POKERANGER2_DISKHPTABLE_HPP

#include <nitro.h>

#include "common.hpp"

class SaveManager;

// Table loaded from data/param/DiskHP.bin; CGame::unk_1438
class DiskHPTable {
public:
    DiskHPTable(int arg0);

public:
    u8 m_count;
    u8 *m_maxEnergy;
    u16 *m_power;
    u16 *m_exp;
};

STATIC_SIZE_ASSERT(DiskHPTable, 0x10);

// MAIN_BSS_020AF5D0, MAIN_BSS_020AF5E4[3]
class DownloadMissionRecord {
public:
    DownloadMissionRecord();
    ~DownloadMissionRecord();

public:
    u16 unk_00;
    u16 m_cleared;
    u16 m_transferred;
    u16 unk_06;
    u16 unk_08;
    u8 unk_0A[0x6];
    SaveManager *unk_10;
};

STATIC_SIZE_ASSERT(DownloadMissionRecord, 0x14);

struct UnkStruct_0201100C {
    u32 unk_00;
    u8 unk_04[0x3000];
};

// MAIN_BSS_020AF620
class DownloadMissionData {
public:
    DownloadMissionData();
    ~DownloadMissionData();

public:
    UnkStruct_0201100C unk_00;
    u16 m_step;
    SaveManager *m_saveManager;
};

STATIC_SIZE_ASSERT(DownloadMissionData, 0x300C);

// MAIN_BSS_020AF598
class DownloadMissionClears {
public:
    DownloadMissionClears();
    ~DownloadMissionClears();

public:
    u16 unk_00;
    SaveManager *unk_04;
};

STATIC_SIZE_ASSERT(DownloadMissionClears, 0x8);

extern DownloadMissionRecord MAIN_BSS_020AF5D0;
extern DownloadMissionRecord MAIN_BSS_020AF5E4[3];
extern DownloadMissionData MAIN_BSS_020AF620;
extern DownloadMissionClears MAIN_BSS_020AF598;

extern "C" {
u8 DiskHPTable_GetMaxLevel(DiskHPTable *obj);
u16 DiskHPTable_GetPower(DiskHPTable *obj, u8 idx);
u16 DiskHPTable_GetExp(DiskHPTable *obj, u8 idx);
void DownloadMissionRecord_Init(DownloadMissionRecord *obj);
void DownloadMissionRecord_SetCleared(DownloadMissionRecord *obj, int bit);
void DownloadMissionClears_Reset(DownloadMissionClears *obj);
void DownloadMissionClears_Set(DownloadMissionClears *obj, int bit);
}

#endif // POKERANGER2_DISKHPTABLE_HPP
