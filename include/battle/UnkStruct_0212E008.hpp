#ifndef POKERANGER2_BATTLE_UNKSTRUCT_0212E008_HPP
#define POKERANGER2_BATTLE_UNKSTRUCT_0212E008_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

// Attack effect parameter record (UnkClass_0212E008 table entry)
struct UnkStruct_0212E008 {
    u16 unk_00;
    u8 unk_02[0x6];
    u8 unk_08;
    u8 unk_09[0x3];
    u32 unk_0C;
    u8 unk_10[0x3];
    u8 unk_13;
    u8 unk_14;
    u8 unk_15;
    u8 unk_16;
    u8 unk_17;
    s8 unk_18;
    s8 unk_19;
    u8 unk_1A;
    u8 unk_1B;

    inline Rectangle GetShadowRect()
    {
        Rectangle rect = { unk_18 << 12, unk_19 << 12, unk_1A << 12, unk_1B << 12 };
        return rect;
    }
};

STATIC_SIZE_ASSERT(UnkStruct_0212E008, 0x1C);

#endif // POKERANGER2_BATTLE_UNKSTRUCT_0212E008_HPP
