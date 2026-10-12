#ifndef POKERANGER2_UNKCLASS_0200E960_HPP
#define POKERANGER2_UNKCLASS_0200E960_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"

class UnkClass_0200E960 {
public:
    ~UnkClass_0200E960()
    {
    }

    void sub_0200E960(u32 arg0);
    GXOamAttr *sub_0200E9A4(GXOamAttr *dst, int nameShift, int charShift);
    int sub_0200EA84(const NNSG2dCellData *cell, int x, int y, int palette, int charName, int priority);
    int sub_0200EAFC(const NNSG2dCellData *cell);
    void sub_0200EB20(u16 palette);
    void sub_0200EB28(int x, int y);
    void sub_0200EB34(int affineIdx, BOOL doubleSize);
    void sub_0200EB64(BOOL mosaic);
    GXOamAttr *sub_0200EB78(GXOamAttr *dst, int nameShift, int charShift);
    u8 sub_0200EB84();
    u8 sub_0200EBBC();
    void sub_0200EBF4(s16 width, s16 height, s16 offsetX, s16 offsetY);
    BOOL sub_0200EC0C();

    void SetVisible(BOOL visible)
    {
        unk_14 = visible ? TRUE : FALSE;
    }

public:
    u32 unk_00;
    const NNSG2dCellData *unk_04;
    int unk_08;
    s16 unk_0C;
    s16 unk_0E;
    u32 unk_10;
    int unk_14;
    u16 unk_18;
    u16 unk_1A;
    u16 unk_1C;
    u8 unk_1E[6];
    u16 unk_24;
    u16 unk_26;
    u8 unk_28;
    u8 unk_29[7];
    u8 unk_30;
    s16 unk_32;
    s16 unk_34;
    s16 unk_36;
    s16 unk_38;
};

STATIC_SIZE_ASSERT(UnkClass_0200E960, 0x3C);

#endif // POKERANGER2_UNKCLASS_0200E960_HPP
