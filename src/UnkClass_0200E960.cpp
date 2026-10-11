#include "UnkClass_0200E960.hpp"

#include "CGame.hpp"

extern "C" {
}

void UnkClass_0200E960::sub_0200E960(u32 arg0)
{
    unk_00 = arg0;
    unk_0C = 0;
    unk_0E = 0;
    unk_14 = 0;
    unk_18 = 0;
    unk_1A = 0;
    unk_1C = 0;
    unk_24 = 0;
    unk_26 = 0;
    unk_30 = 0;
    sub_0200EBF4(0, 0, 0, 0);
}

GXOamAttr *UnkClass_0200E960::sub_0200E9A4(GXOamAttr *dst, int nameShift, int charShift)
{
    const NNSG2dCellOAMAttrData *src = unk_04->pOamAttrArray;
    for (int i = 0; i < unk_08; i++) {
        u16 attr0 = (src->attr0 & 0xFF00) | (u16)((src->attr0 + unk_0E) & 0xFF) | (unk_24 << 8) | (unk_28 << 10) | (unk_30 << 12);
        u16 x = (src->attr1 + unk_0C) & 0x1FF;
        int pal = (u16)(unk_1A + (src->attr2 >> 12)) << 12;
        int name = (unk_18 + (src->attr2 << charShift)) >> nameShift & 0x3FF;
        dst->attr0 = attr0;
        dst->attr1 = (src->attr1 & 0xFE00) | x | (unk_26 << 9);
        dst->attr2 = (unk_1C << 10) | pal | (u16)name;
        src++;
        dst++;
    }
    return dst;
}

int UnkClass_0200E960::sub_0200EA84(const NNSG2dCellData *cell, s16 x, s16 y, int palette, int charName, int priority)
{
    unk_04 = cell;
    sub_0200EB28(x, y);
    unk_14 = 1;
    unk_18 = charName;
    unk_1A = palette;
    unk_1C = priority;
    unk_24 = 0;
    unk_26 = 0;
    unk_30 = 0;
    unk_08 = unk_04->numOAMAttrs;
    sub_0200EBF4(0, 0, 0, 0);
    return unk_08;
}

int UnkClass_0200E960::sub_0200EAFC(const NNSG2dCellData *cell)
{
    if (unk_04 == cell) {
        return unk_08;
    }
    unk_04 = cell;
    unk_08 = cell->numOAMAttrs;
    return unk_08;
}

void UnkClass_0200E960::sub_0200EB20(u16 palette)
{
    unk_1A = palette;
}

void UnkClass_0200E960::sub_0200EB28(s16 x, s16 y)
{
    unk_0C = x;
    unk_0E = y;
}

void UnkClass_0200E960::sub_0200EB34(int affineIdx, BOOL doubleSize)
{
    if (affineIdx < 32) {
        unk_24 = doubleSize ? 3 : 1;
        unk_26 = affineIdx;
    } else {
        unk_24 = 0;
        unk_26 = 0;
    }
}

void UnkClass_0200E960::sub_0200EB64(BOOL mosaic)
{
    unk_30 = mosaic ? 1 : 0;
}

GXOamAttr *UnkClass_0200E960::sub_0200EB78(GXOamAttr *dst, int nameShift, int charShift)
{
    return sub_0200E9A4(dst, nameShift, charShift);
}

u8 UnkClass_0200E960::sub_0200EB84()
{
    u8 state = CGame::GetInstance()->activeTouchPanel->unk_04;
    if (state != 0 && sub_0200EC0C()) {
        return state;
    }
    return 0;
}

u8 UnkClass_0200E960::sub_0200EBBC()
{
    u8 state = CGame::GetInstance()->activeTouchPanel->unk_05;
    if (state != 0 && sub_0200EC0C()) {
        return state;
    }
    return 0;
}

void UnkClass_0200E960::sub_0200EBF4(s16 width, s16 height, s16 offsetX, s16 offsetY)
{
    unk_32 = width;
    unk_34 = height;
    unk_36 = offsetX;
    unk_38 = offsetY;
}

BOOL UnkClass_0200E960::sub_0200EC0C()
{
    if (unk_32 <= 0 || unk_34 <= 0) {
        return FALSE;
    }

    CTouchPanel *tp = CGame::GetInstance()->activeTouchPanel;
    u16 tx = tp->unk_0A.x;
    u16 ty = tp->unk_0A.y;
    int left = unk_0C + unk_36 - unk_32 / 2;
    int top = unk_0E + unk_38 - unk_34 / 2;

    if (left < 0) {
        left = 0;
    } else if (left > 256) {
        left = 256;
    }
    if (top < 0) {
        top = 0;
    } else if (top > 192) {
        top = 192;
    }

    if (tx < left || tx > left + unk_32) {
        return FALSE;
    }
    if (ty < top || ty > top + unk_34) {
        return FALSE;
    }
    return TRUE;
}
