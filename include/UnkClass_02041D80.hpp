#ifndef POKERANGER2_UNKCLASS_02041D80_HPP
#define POKERANGER2_UNKCLASS_02041D80_HPP

#include <nitro.h>

#include "common.hpp"

struct UnkStruct_02041D80 {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u8 unk_07[0x3];
    u8 unk_0A;
    u8 unk_0B[0x3];
    u8 unk_0E;
    u8 unk_0F[0x3];
    u8 unk_12;
    u8 unk_13[0x3];
    u8 unk_16;
    u8 unk_17[0x3];
    u8 unk_1A;
    u8 unk_1B[0x3];
    u8 unk_1E;
    u8 unk_1F[0x3];
    u8 unk_22;
    u8 unk_23[0x3];
    u8 unk_26;
    u8 unk_27[0x3];
    u8 unk_2A;
    u8 unk_2B[0x3];
    u8 unk_2E;
    u8 unk_2F[0x3];
    u8 unk_32;
    u8 unk_33[0x3];
    u8 unk_36;
    u8 unk_37[0x3];
    u8 unk_3A;
    u8 unk_3B[0x3];
    u8 unk_3E;
    u8 unk_3F[0x3];
    u8 unk_42;
    u8 unk_43[0x3];
    u8 unk_46;
    u8 unk_47[0x9];
    int unk_50;
};

class UnkClass_02041D80;

extern "C" {
UnkStruct_02041D80 *sub_02041D80(UnkClass_02041D80 *obj, u32 mapId);
}

STATIC_SIZE_ASSERT(UnkStruct_02041D80, 0x54);

#endif // POKERANGER2_UNKCLASS_02041D80_HPP
