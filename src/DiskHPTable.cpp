#include "DiskHPTable.hpp"

#include "ParamTableFile.hpp"
#include "SaveManager.hpp"

DownloadMissionRecord MAIN_BSS_020AF5D0;
DownloadMissionRecord MAIN_BSS_020AF5E4[3];
DownloadMissionData MAIN_BSS_020AF620;
DownloadMissionClears MAIN_BSS_020AF598;
// Never referenced (mwld strips it); with it in the TU mwcc's unstable size sort lays out the four destructor
// chain objects in .bss like the original (598, 620, 5D0, 5E4).
u32 g_unk_02010D2C_unused;

DiskHPTable::DiskHPTable(int arg0)
{
    ParamTableFile *table = new ParamTableFile(arg0);
    table->Load("data/param/DiskHP.bin");
    m_count = table->sub_0200D390();
    m_maxEnergy = new u8[m_count];
    m_power = new u16[m_count];
    m_exp = new u16[m_count];

    u32 value = 0;
    for (int i = 0; i < m_count; i++) {
        table->GetValue(i, 1, &value);
        m_maxEnergy[i] = (u8)value;
        table->GetValue(i, 2, &value);
        m_power[i] = (u16)value;
        table->GetValue(i, 3, &value);
        m_exp[i] = (u16)value;
    }

    delete table;
}

extern "C" {

u8 DiskHPTable_GetMaxLevel(DiskHPTable *obj)
{
    if (obj->m_count == 0) {
        return 0;
    }
    return obj->m_count - 1;
}

u8 DiskHPTable_GetMaxEnergy(DiskHPTable *obj, u8 idx)
{
    if (idx > obj->m_count) {
        return 0;
    }
    return obj->m_maxEnergy[idx];
}

u16 DiskHPTable_GetPower(DiskHPTable *obj, u8 idx)
{
    if (idx > obj->m_count) {
        return 0;
    }
    return obj->m_power[idx];
}

u16 DiskHPTable_GetExp(DiskHPTable *obj, u8 idx)
{
    if (idx > obj->m_count) {
        return 0;
    }
    return obj->m_exp[idx];
}
}

DownloadMissionRecord::DownloadMissionRecord()
{
    unk_10 = NULL;
}

DownloadMissionRecord::~DownloadMissionRecord()
{
    SAFE_DELETE(unk_10);
}

extern "C" {

void sub_02010F0C(DownloadMissionRecord *obj)
{
    obj->unk_08 = 0;
}

void DownloadMissionRecord_Init(DownloadMissionRecord *obj)
{
    MI_CpuClear8(obj, 8);
    obj->unk_00 = 0xC68F;
    obj->m_cleared = 0;
    obj->m_transferred = 0;
    obj->unk_06 = 0xE97C;
    sub_02010F0C(obj);
}

void DownloadMissionRecord_SetCleared(DownloadMissionRecord *obj, int bit)
{
    obj->m_cleared |= (u16)(1 << bit);
}

BOOL DownloadMissionRecord_IsValid(DownloadMissionRecord *obj, DownloadMissionRecord *other)
{
    if (other != NULL) {
        obj = other;
    }
    return obj->unk_00 == 0xC68F && obj->unk_06 == 0xE97C;
}

void DownloadMissionRecord_SetTransferred(DownloadMissionRecord *obj, int bit)
{
    obj->m_transferred |= (u16)(1 << bit);
}

int DownloadMissionRecord_GetStatus(DownloadMissionRecord *obj, int bit)
{
    u16 mask = 1 << bit;
    BOOL set = (obj->m_cleared & mask) ? TRUE : FALSE;
    if ((obj->m_transferred & mask) ? TRUE : FALSE) {
        return 2;
    }
    return set ? 1 : 0;
}
}

DownloadMissionData::DownloadMissionData()
{
    m_saveManager = NULL;
}

DownloadMissionData::~DownloadMissionData()
{
    SAFE_DELETE(m_saveManager);
}

extern "C" {

void sub_020110E0(DownloadMissionData *obj, u32 arg1);
void DownloadMissionData_ResetStep(DownloadMissionData *obj);

void DownloadMissionData_Reset(DownloadMissionData *obj)
{
    sub_020110E0(obj, 0);
    MI_CpuClear8(&MAIN_BSS_020AF620.unk_00, sizeof(UnkStruct_0201100C));
    SAFE_DELETE(obj->m_saveManager);
    obj->m_saveManager = new SaveManager(1);
    DownloadMissionData_ResetStep(obj);
}

void sub_020110E0(DownloadMissionData *obj, u32 arg1)
{
    obj->unk_00.unk_00 = arg1;
}

void DownloadMissionData_ResetStep(DownloadMissionData *obj)
{
    obj->m_step = 0;
}

int DownloadMissionData_Save(DownloadMissionData *obj, u16 list)
{
    switch (obj->m_step) {
    case 0:
        obj->m_saveManager->Save(list + 2);
        obj->m_step = 1;
        break;
    case 1:
        u32 result = obj->m_saveManager->Update();
        if (result != 0) {
            if (!(result & 0x80)) {
                obj->m_step = 3;
                return 1;
            }
            obj->m_step = 4;
            return -1;
        }
        break;
    }
    return 0;
}

int DownloadMissionData_Load(DownloadMissionData *obj, u16 list)
{
    switch (obj->m_step) {
    case 0:
        obj->m_saveManager->sub_02028408(list + 2);
        obj->m_step = 1;
        break;
    case 1:
        u32 result = obj->m_saveManager->Update();
        if (result != 0) {
            if (!(result & 0x80)) {
                DownloadMissionData_ResetStep(obj);
                return 1;
            }
            DownloadMissionData_ResetStep(obj);
            switch (result & 0x7F) {
            case 1:
            case 2:
            case 4:
            case 6:
            case 8:
                return -2;
            default:
                return -1;
            }
        }
        break;
    }
    return 0;
}
}

DownloadMissionClears::DownloadMissionClears()
{
    unk_04 = NULL;
}

DownloadMissionClears::~DownloadMissionClears()
{
    SAFE_DELETE(unk_04);
}

extern "C" {

void DownloadMissionClears_Set(DownloadMissionClears *obj, int bit);

void DownloadMissionClears_Reset(DownloadMissionClears *obj)
{
    DownloadMissionClears_Set(obj, -1);
    MI_CpuClear8(&MAIN_BSS_020AF598.unk_00, sizeof(u16));
    SAFE_DELETE(obj->unk_04);
}

void DownloadMissionClears_Set(DownloadMissionClears *obj, int bit)
{
    if (bit < 0) {
        MAIN_BSS_020AF598.unk_00 = 0;
        return;
    }
    MAIN_BSS_020AF598.unk_00 |= (u16)(1 << bit);
}

int DownloadMissionClears_Get(DownloadMissionClears *obj, int bit)
{
    return (u16)(1 << bit) & MAIN_BSS_020AF598.unk_00;
}
}
