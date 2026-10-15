#include "GlobalValues.hpp"

#include <nitro.h>

#include "SaveData.hpp"
#include "field/CFieldPlayer.hpp"

extern CFieldPlayer *MAIN_BSS_0210CA48;

GlobalValues MAIN_BSS_0210C0B0;

GlobalValues::GlobalValues()
{
    GlobalValues_Init(this);
}

GlobalValues::~GlobalValues()
{
    GlobalValues_Init(this);
}

extern "C" void GlobalValues_Init(GlobalValues *obj)
{
    MI_CpuFill8(obj, 0, sizeof(GlobalValues));
}

extern "C" void GlobalValues_ClearChapterValues(GlobalValues *obj)
{
    for (int i = 0; i < 21; i++) {
        obj->unk_00[i] = 0;
    }
}

extern "C" void GlobalValues_SetChapterValue(GlobalValues *obj, int index, s32 value)
{
    obj->unk_00[index] = value;
}

extern "C" s32 GlobalValues_GetChapterValue(GlobalValues *obj, int index)
{
    return obj->unk_00[index];
}

extern "C" void GlobalValues_ClearQuestValues(GlobalValues *obj)
{
    for (int i = 0; i < 11; i++) {
        obj->unk_D0[i] = 0;
    }
}

extern "C" void GlobalValues_SetQuestValue(GlobalValues *obj, int index, s32 value)
{
    obj->unk_D0[index] = value;
}

extern "C" s32 GlobalValues_GetQuestValue(GlobalValues *obj, int index)
{
    return obj->unk_D0[index];
}

extern "C" void GlobalValues_ApplyProgress(GlobalValues *obj, int progress)
{
    if (progress > 69) {
        return;
    }

    if (progress == 0) {
        for (int i = 0; i < 31; i++) {
            obj->unk_54[i] = 0;
        }
        return;
    }

    if (progress < 30) {
        obj->unk_54[8] = FALSE;
    } else {
        obj->unk_54[8] = TRUE;
    }
    if (progress < 23) {
        obj->unk_54[9] = FALSE;
    } else {
        obj->unk_54[9] = TRUE;
    }
    if (progress < 27) {
        obj->unk_54[10] = FALSE;
    } else {
        obj->unk_54[10] = TRUE;
    }
    if (progress < 49) {
        obj->unk_54[13] = FALSE;
    } else {
        obj->unk_54[13] = TRUE;
    }
    if (progress < 66) {
        obj->unk_54[14] = 0;
    } else if (progress == 66) {
        obj->unk_54[14] = 1;
    } else {
        obj->unk_54[14] = 2;
    }
    if (progress < 63) {
        obj->unk_54[15] = FALSE;
        obj->unk_54[16] = FALSE;
        obj->unk_54[17] = FALSE;
    } else {
        obj->unk_54[15] = TRUE;
        obj->unk_54[16] = TRUE;
        obj->unk_54[17] = TRUE;
    }
    if (progress != 19) {
        obj->unk_54[18] = FALSE;
    } else {
        obj->unk_54[18] = TRUE;
    }
    if (progress < 40) {
        obj->unk_54[19] = FALSE;
    } else {
        obj->unk_54[19] = TRUE;
    }
    if (progress < 40) {
        obj->unk_54[20] = 0;
    } else if (progress < 53) {
        obj->unk_54[20] = 1;
    } else if (progress < 60) {
        obj->unk_54[20] = 2;
    } else if (progress < 67) {
        obj->unk_54[20] = 3;
    } else {
        obj->unk_54[20] = 4;
    }
    if (progress != 55) {
        obj->unk_54[22] = FALSE;
    } else {
        obj->unk_54[22] = TRUE;
    }
    if (obj->unk_54[2] == 0) {
        obj->unk_54[2] = 2;
    }
    if (progress < 62) {
        obj->unk_54[24] = 0;
    } else if (progress < 64) {
        obj->unk_54[24] = 1;
    } else if (progress < 67) {
        obj->unk_54[24] = 2;
    } else {
        obj->unk_54[24] = 0;
    }

    SaveData *save = &MAIN_BSS_020B26A0;
    if (progress <= 23) {
        save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF0) | 0;
    } else if (progress <= 27) {
        save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF0) | 1;
    } else if (progress <= 29) {
        save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF0) | 2;
    } else if (progress <= 33) {
        save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF0) | 3;
    } else if (progress <= 43) {
        save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF0) | 4;
    } else if (progress <= 48) {
        save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF0) | 5;
    } else if (progress <= 52) {
        save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF0) | 6;
    } else if (progress <= 54) {
        save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF0) | 7;
    } else if (progress <= 59) {
        save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF0) | 8;
    } else {
        save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF0) | 9;
    }

    u32 oldStage = (save->m_rangerClassGrade >> 4) & 0xF;
    if (progress <= 21) {
        save->m_rangerClassGrade = save->m_rangerClassGrade & 0xF;
    } else if (progress <= 43) {
        save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF) | 0x10;
    } else {
        save->m_rangerClassGrade = (save->m_rangerClassGrade & 0xF) | 0x20;
    }

    CFieldPlayer *player;
    if (((save->m_rangerClassGrade >> 4) & 0xF) != oldStage && (player = MAIN_BSS_0210CA48) != NULL) {
        Point2D pos = player->GetPos();
        player->LoadModel(save->m_sex, (u8)((save->m_rangerClassGrade >> 4) & 0xF), save->m_areaType);
        player->SetRideMode(save->unk_8802);
        player->SetPos(pos);
    }
}

extern "C" void GlobalValues_Set(GlobalValues *obj, int index, s32 value)
{
    obj->unk_54[index] = value;
}

extern "C" s32 GlobalValues_Get(GlobalValues *obj, int index)
{
    return obj->unk_54[index];
}
