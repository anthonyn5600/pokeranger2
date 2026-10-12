#ifndef POKERANGER2_UNKCLASS_02018DF4_HPP
#define POKERANGER2_UNKCLASS_02018DF4_HPP

#include <nitro.h>

#include "common.hpp"

// Global value banks (MAIN_BSS_0210C0B0, CGame::unk_14B4); the 31 values at unk_54 follow the story progress.
class UnkClass_02018DF4 {
public:
    UnkClass_02018DF4();
    ~UnkClass_02018DF4();

public:
    s32 unk_00[21];
    s32 unk_54[31];
    s32 unk_D0[11];
};

STATIC_SIZE_ASSERT(UnkClass_02018DF4, 0xFC);

extern UnkClass_02018DF4 MAIN_BSS_0210C0B0;

extern "C" {
void sub_02018E1C(UnkClass_02018DF4 *obj);
void sub_02018E30(UnkClass_02018DF4 *obj);
void sub_02018E4C(UnkClass_02018DF4 *obj, int index, s32 value);
s32 sub_02018E54(UnkClass_02018DF4 *obj, int index);
void sub_02018E5C(UnkClass_02018DF4 *obj);
void sub_02018E7C(UnkClass_02018DF4 *obj, int index, s32 value);
s32 sub_02018E88(UnkClass_02018DF4 *obj, int index);
void sub_02018E94(UnkClass_02018DF4 *obj, int progress);
void sub_0201926C(UnkClass_02018DF4 *obj, int index, s32 value);
s32 sub_02019278(UnkClass_02018DF4 *obj, int index);
}

#endif // POKERANGER2_UNKCLASS_02018DF4_HPP
