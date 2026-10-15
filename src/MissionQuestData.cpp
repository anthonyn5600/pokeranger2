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
    m_scriptManager = NULL;
    m_textbox = NULL;
}

extern "C" {

void MissionQuestData_Init(MissionQuestData *obj, ScriptManager *scriptManager, TextboxManager *textboxData)
{
    MissionQuestData_Clear(obj);
    obj->m_scriptManager = scriptManager;
    obj->m_textbox = textboxData;
}

void MissionQuestData_ReceiveMission(MissionQuestData *obj, int arg1)
{
    if (arg1 == 0) {
        obj->m_missionId = arg1;
        return;
    }
    if (arg1 <= 0x4C) {
        if (obj->m_missionState != 0) {
            OS_Terminate();
        }
        if (arg1 < 0x32) {
            obj->m_missionState = 1;
        } else if (arg1 >= 0x46) {
            obj->m_missionState = 1;
        }
        obj->m_missionId = arg1;
    } else {
        OS_Terminate();
    }
}

void MissionQuestData_StartMission(MissionQuestData *obj)
{
    if (obj->m_missionId == 0) {
        return;
    }
    if (obj->m_missionId <= 0x4C) {
        if (obj->m_missionId < 0x32) {
            if (obj->m_missionState != 1) {
                OS_Terminate();
            }
            obj->m_missionState = 2;
        } else if (obj->m_missionId >= 0x46) {
            obj->m_missionState = 2;
        }
    } else {
        OS_Terminate();
    }
}

void MissionQuestData_ClearMission(MissionQuestData *obj)
{
    if (obj->m_missionId == 0) {
        return;
    }
    if (obj->m_missionId <= 0x4C) {
        if (obj->m_missionId < 0x32) {
            if (obj->m_missionState != 2) {
                OS_Terminate();
            }
            obj->m_missionState = 0;
            obj->m_lastMissionId = obj->m_missionId;
        } else if (obj->m_missionId >= 0x46) {
            obj->m_missionState = 0;
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

void MissionQuestData_SetQuestEntered(MissionQuestData *obj, int arg1)
{
    obj->m_questStates[arg1] |= 0x10;
}

BOOL MissionQuestData_IsQuestEntered(MissionQuestData *obj, int arg1)
{
    return (obj->m_questStates[arg1] & 0x10) ? TRUE : FALSE;
}

void MissionQuestData_EnterQuest(MissionQuestData *obj, int arg1)
{
    if (obj->m_questActive != 0) {
        OS_Terminate();
    }
    if ((obj->m_questStates[arg1] & 0xF) == 2) {
        OS_Terminate();
    }
    obj->m_questActive = 1;
    obj->m_questId = arg1;
    MissionQuestData_SetQuestEntered(obj, arg1);
    ScriptManager_LoadQuest(obj->m_scriptManager, arg1);
    obj->m_textbox->LoadQuestMessages(arg1);
}

void MissionQuestData_ExitQuestCleared(MissionQuestData *obj)
{
    if (obj->m_questActive != 1) {
        OS_Terminate();
    }
    obj->m_questActive = 0;
    obj->m_questStates[obj->m_questId] = (obj->m_questStates[obj->m_questId] & ~0xF) | 2;
    obj->m_questId = 0;
    ScriptManager_UnloadQuest(obj->m_scriptManager);
    obj->m_textbox->FreeQuestMessages();
}

void MissionQuestData_ExitQuest(MissionQuestData *obj)
{
    if (obj->m_questActive != 1) {
        OS_Terminate();
    }
    obj->m_questActive = 0;
    obj->m_questId = 0;
    ScriptManager_UnloadQuest(obj->m_scriptManager);
    obj->m_textbox->FreeQuestMessages();
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
    ScriptManager_LoadChapter(obj->m_scriptManager);
    obj->m_textbox->LoadChapterMessages(obj->m_chapter);
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
    obj->m_textbox->LoadChapterMessages(arg1);
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
