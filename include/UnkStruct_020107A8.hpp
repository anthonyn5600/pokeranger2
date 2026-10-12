#ifndef POKERANGER2_UNKSTRUCT_020107A8_HPP
#define POKERANGER2_UNKSTRUCT_020107A8_HPP

#include <nitro.h>

#include "common.hpp"

// Record returned by sub_020107A8 (from the table at CGame::unk_1434)
struct UnkStruct_020107A8 {
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    s8 unk_07;
    s8 unk_08;
    u8 unk_09;
    s8 unk_0A;
    s8 unk_0B;
    s8 unk_0C;
    s8 unk_0D;
    s8 unk_0E;
    s8 unk_0F;
    u16 unk_10;
    u16 unk_12;
    u32 unk_14;
};

STATIC_SIZE_ASSERT(UnkStruct_020107A8, 0x18);

extern "C" {
UnkStruct_020107A8 *sub_020107A8(void *obj, u16 arg1);
}

#endif // POKERANGER2_UNKSTRUCT_020107A8_HPP
