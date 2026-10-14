#ifndef POKERANGER2_GLOBALVALUES_HPP
#define POKERANGER2_GLOBALVALUES_HPP

#include <nitro.h>

#include "common.hpp"

// Global value banks (MAIN_BSS_0210C0B0, CGame::unk_14B4); the 31 values at unk_54 follow the story progress.
class GlobalValues {
public:
    GlobalValues();
    ~GlobalValues();

public:
    s32 unk_00[21];
    s32 unk_54[31];
    s32 unk_D0[11];
};

STATIC_SIZE_ASSERT(GlobalValues, 0xFC);

extern GlobalValues MAIN_BSS_0210C0B0;

extern "C" {
void GlobalValues_Init(GlobalValues *obj);
void GlobalValues_ClearChapterValues(GlobalValues *obj);
void GlobalValues_SetChapterValue(GlobalValues *obj, int index, s32 value);
s32 GlobalValues_GetChapterValue(GlobalValues *obj, int index);
void GlobalValues_ClearQuestValues(GlobalValues *obj);
void GlobalValues_SetQuestValue(GlobalValues *obj, int index, s32 value);
s32 GlobalValues_GetQuestValue(GlobalValues *obj, int index);
void GlobalValues_ApplyProgress(GlobalValues *obj, int progress);
void GlobalValues_Set(GlobalValues *obj, int index, s32 value);
s32 GlobalValues_Get(GlobalValues *obj, int index);
}

#endif // POKERANGER2_GLOBALVALUES_HPP
