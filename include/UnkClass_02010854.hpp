#ifndef POKERANGER2_UNKCLASS_02010854_HPP
#define POKERANGER2_UNKCLASS_02010854_HPP

#include <nitro.h>

#include "common.hpp"

// CGame::unk_143C
class UnkClass_02010854 {
public:
    UnkClass_02010854();

public:
    u32 unk_00;
    u8 unk_04;
    u8 unk_05;
    u8 unk_06;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u8 unk_14;
    u16 unk_16[8];
    u8 unk_26[8];
    u8 unk_2E;
    u16 unk_30[4];
    u8 unk_38[4];
    u8 unk_3C[4];
    u8 unk_40;
    u8 unk_41[8];
    u8 unk_49;
    u8 unk_4A;
    u8 unk_4B;
    u8 unk_4C;
    u8 unk_4D;
    u8 unk_4E;
    u8 unk_4F;
    u8 unk_50;
    u8 unk_51;
    u8 unk_52;
    u8 unk_53;
    u8 unk_54;
    u16 unk_56;
    u8 unk_58;
};

STATIC_SIZE_ASSERT(UnkClass_02010854, 0x5C);

extern "C" {
void sub_02010868(UnkClass_02010854 *obj);
u32 sub_02010B24(UnkClass_02010854 *obj);
u8 sub_02010B2C(UnkClass_02010854 *obj);
u8 sub_02010B34(UnkClass_02010854 *obj);
BOOL sub_02010B3C(UnkClass_02010854 *obj);
u32 sub_02010B50(UnkClass_02010854 *obj);
u32 sub_02010B58(UnkClass_02010854 *obj);
u32 sub_02010B60(UnkClass_02010854 *obj);
u8 sub_02010B68(UnkClass_02010854 *obj);
u16 sub_02010B70(UnkClass_02010854 *obj, int idx);
u8 sub_02010B7C(UnkClass_02010854 *obj);
u8 sub_02010B84(UnkClass_02010854 *obj, int idx);
u8 sub_02010B90(UnkClass_02010854 *obj);
u16 sub_02010B98(UnkClass_02010854 *obj, int idx);
u8 sub_02010BA4(UnkClass_02010854 *obj, int idx);
u8 sub_02010BB0(UnkClass_02010854 *obj);
u8 sub_02010BB8(UnkClass_02010854 *obj);
u8 sub_02010BC0(UnkClass_02010854 *obj);
u8 sub_02010BC8(UnkClass_02010854 *obj);
u8 sub_02010BD0(UnkClass_02010854 *obj);
BOOL sub_02010C08(UnkClass_02010854 *obj);
u8 sub_02010C1C(UnkClass_02010854 *obj);
u8 sub_02010C2C(UnkClass_02010854 *obj);
u16 sub_02010C34(UnkClass_02010854 *obj);
u8 sub_02010BD8(UnkClass_02010854 *obj);
BOOL sub_02010BE0(UnkClass_02010854 *obj);
BOOL sub_02010BF4(UnkClass_02010854 *obj);
}

#endif // POKERANGER2_UNKCLASS_02010854_HPP
