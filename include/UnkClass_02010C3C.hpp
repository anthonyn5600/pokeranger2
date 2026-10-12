#ifndef POKERANGER2_UNKCLASS_02010C3C_HPP
#define POKERANGER2_UNKCLASS_02010C3C_HPP

#include <nitro.h>

#include "common.hpp"

// CGame::unk_1440 (empty); resets the global records below
class UnkClass_02010C3C {
public:
    UnkClass_02010C3C();
};

struct UnkStruct_02010C3C {
    u8 unk_00[0x4C];
    u16 unk_4C;
    u8 unk_4E[0x1E];
    u16 unk_6C;
    u16 unk_6E;
    u8 unk_70[0x2];
};

STATIC_SIZE_ASSERT(UnkStruct_02010C3C, 0x72);

extern UnkStruct_02010C3C MAIN_BSS_020AF35C;
extern UnkStruct_02010C3C MAIN_BSS_020AF3CE[4];

extern "C" {
void sub_02010C50(UnkClass_02010C3C *obj);
void sub_02010C94(UnkClass_02010C3C *obj, UnkStruct_02010C3C *entry);
UnkStruct_02010C3C *sub_02010CC0(void);
}

#endif // POKERANGER2_UNKCLASS_02010C3C_HPP
