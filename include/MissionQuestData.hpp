#ifndef POKERANGER2_MISSIONQUESTDATA_HPP
#define POKERANGER2_MISSIONQUESTDATA_HPP

#include <nitro.h>

#include "common.hpp"

class TextboxManager;
class ScriptManager;

// Mission/quest progress; global MAIN_BSS_020B2638 (CGame::m_missionQuestData)
class MissionQuestData {
public:
    MissionQuestData();
    ~MissionQuestData();

public:
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u32 unk_04;
    s32 m_chapter;
    u32 unk_0C;
    u32 unk_10;
    u8 m_questStates[0x3E]; // low nibble: state, 0x10: flag
    TextboxManager *unk_54;
    ScriptManager *unk_58;
};

STATIC_SIZE_ASSERT(MissionQuestData, 0x5C);

extern MissionQuestData MAIN_BSS_020B2638;

extern "C" {
void MissionQuestData_Clear(MissionQuestData *obj);
BOOL MissionQuestData_IsQuestActive(MissionQuestData *obj, int arg1);
BOOL sub_02011528(MissionQuestData *obj, int arg1);
void sub_020116C0(MissionQuestData *obj, int arg1);
BOOL MissionQuestData_IsQuestCleared(MissionQuestData *obj, int arg1);
}

#endif // POKERANGER2_MISSIONQUESTDATA_HPP
