#include "MissionQuestData.hpp"

#include "TextboxManager.hpp"

extern "C" {
void ScriptManager_LoadChapter(void *scriptManager);
void ScriptManager_LoadQuest(void *scriptManager, int arg1);
void ScriptManager_UnloadQuest(void *scriptManager);
}

MissionQuestData MAIN_BSS_020B2638;

extern "C" {

void MissionQuestData_Clear(MissionQuestData *obj)
{
    MI_CpuClear8(obj, 0x54);
}
}

MissionQuestData::MissionQuestData()
{
    MissionQuestData_Clear(this);
}

MissionQuestData::~MissionQuestData()
{
    unk_58 = NULL;
    unk_54 = NULL;
}

extern "C" {

void MissionQuestData_Init(MissionQuestData *obj, ScriptManager *scriptManager, TextboxManager *textboxData)
{
    MissionQuestData_Clear(obj);
    obj->unk_58 = scriptManager;
    obj->unk_54 = textboxData;
}

void sub_020113B4(MissionQuestData *obj, int arg1)
{
    if (arg1 == 0) {
        obj->unk_02 = arg1;
        return;
    }
    if (arg1 <= 0x4C) {
        if (obj->unk_00 != 0) {
            OS_Terminate();
        }
        if (arg1 < 0x32) {
            obj->unk_00 = 1;
        } else if (arg1 >= 0x46) {
            obj->unk_00 = 1;
        }
        obj->unk_02 = arg1;
    } else {
        OS_Terminate();
    }
}

void sub_0201140C(MissionQuestData *obj)
{
    if (obj->unk_02 == 0) {
        return;
    }
    if (obj->unk_02 <= 0x4C) {
        if (obj->unk_02 < 0x32) {
            if (obj->unk_00 != 1) {
                OS_Terminate();
            }
            obj->unk_00 = 2;
        } else if (obj->unk_02 >= 0x46) {
            obj->unk_00 = 2;
        }
    } else {
        OS_Terminate();
    }
}

void sub_02011464(MissionQuestData *obj)
{
    if (obj->unk_02 == 0) {
        return;
    }
    if (obj->unk_02 <= 0x4C) {
        if (obj->unk_02 < 0x32) {
            if (obj->unk_00 != 2) {
                OS_Terminate();
            }
            obj->unk_00 = 0;
            obj->unk_04 = obj->unk_02;
        } else if (obj->unk_02 >= 0x46) {
            obj->unk_00 = 0;
        }
    } else {
        OS_Terminate();
    }
}

void MissionQuestData_StartQuest(MissionQuestData *obj, int arg1)
{
    if ((obj->m_questStates[arg1] & 0xF) == 2) {
        OS_Terminate();
    }
    obj->m_questStates[arg1] = (obj->m_questStates[arg1] & ~0xF) | 1;
}

BOOL MissionQuestData_IsQuestActive(MissionQuestData *obj, int arg1)
{
    return (obj->m_questStates[arg1] & 0xF) == 1;
}

void sub_02011514(MissionQuestData *obj, int arg1)
{
    obj->m_questStates[arg1] |= 0x10;
}

BOOL sub_02011528(MissionQuestData *obj, int arg1)
{
    return (obj->m_questStates[arg1] & 0x10) ? TRUE : FALSE;
}

void sub_02011540(MissionQuestData *obj, int arg1)
{
    if (obj->unk_01 != 0) {
        OS_Terminate();
    }
    if ((obj->m_questStates[arg1] & 0xF) == 2) {
        OS_Terminate();
    }
    obj->unk_01 = 1;
    obj->unk_03 = arg1;
    sub_02011514(obj, arg1);
    ScriptManager_LoadQuest(obj->unk_58, arg1);
    obj->unk_54->LoadQuestMessages(arg1);
}

void sub_020115A8(MissionQuestData *obj)
{
    if (obj->unk_01 != 1) {
        OS_Terminate();
    }
    obj->unk_01 = 0;
    obj->m_questStates[obj->unk_03] = (obj->m_questStates[obj->unk_03] & ~0xF) | 2;
    obj->unk_03 = 0;
    ScriptManager_UnloadQuest(obj->unk_58);
    obj->unk_54->FreeQuestMessages();
}

void sub_020115F8(MissionQuestData *obj)
{
    if (obj->unk_01 != 1) {
        OS_Terminate();
    }
    obj->unk_01 = 0;
    obj->unk_03 = 0;
    ScriptManager_UnloadQuest(obj->unk_58);
    obj->unk_54->FreeQuestMessages();
}

BOOL MissionQuestData_IsQuestCleared(MissionQuestData *obj, int arg1)
{
    return (obj->m_questStates[arg1] & 0xF) == 2;
}

void MissionQuestData_SetChapter(MissionQuestData *obj, int arg1)
{
    if (arg1 > 0x4C) {
        return;
    }
    obj->m_chapter = arg1;
    ScriptManager_LoadChapter(obj->unk_58);
    obj->unk_54->LoadChapterMessages(obj->m_chapter);
}

int MissionQuestData_CountClearedQuests(MissionQuestData *obj)
{
    int count = 0;
    for (int i = 0; i < 0x3E; i++) {
        if ((obj->m_questStates[i] & 0xF) == 2) {
            count++;
        }
    }
    return count;
}

void MissionQuestData_LoadChapterMessages(MissionQuestData *obj, int arg1)
{
    if (arg1 > 0x4C) {
        return;
    }
    obj->unk_54->LoadChapterMessages(arg1);
}

void sub_020116C0(MissionQuestData *obj, int arg1)
{
    int i;
    if (arg1 > 0x45) {
        for (i = 0; i < 0x3E; i++) {
            obj->m_questStates[i] &= ~0xF;
        }
        return;
    }
    if (arg1 == 0) {
        for (i = 0; i < 0x3E; i++) {
            obj->m_questStates[i] &= ~0xF;
        }
        return;
    }
    const int table[0x3E] = {
        99,
        99,
        30,
        28,
        29,
        32,
        34,
        34,
        31,
        34,
        44,
        28,
        44,
        44,
        44,
        47,
        47,
        49,
        49,
        49,
        52,
        52,
        52,
        59,
        56,
        56,
        59,
        59,
        59,
        69,
        69,
        69,
        69,
        69,
        69,
        30,
        44,
        47,
        56,
        52,
        56,
        69,
        69,
        69,
        69,
        49,
        34,
        69,
        69,
        26,
        28,
        31,
        44,
        69,
        69,
        69,
        69,
        69,
        69,
        69,
        69,
        69,
    };
    for (i = 0; i < 0x3E; i++) {
        if (table[i] <= arg1 && (obj->m_questStates[i] & 0xF) != 2) {
            obj->m_questStates[i] = (obj->m_questStates[i] & ~0xF) | 1;
        }
    }
}
}
