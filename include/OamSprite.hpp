#ifndef POKERANGER2_OAMSPRITE_HPP
#define POKERANGER2_OAMSPRITE_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"

class OamSprite {
public:
    ~OamSprite()
    {
    }

    void Init(u32 arg0);
    GXOamAttr *WriteOam(GXOamAttr *dst, int nameShift, int charShift);
    int Setup(const NNSG2dCellData *cell, int x, int y, int palette, int charName, int priority);
    int SetCellData(const NNSG2dCellData *cell);
    void SetPalette(u16 palette);
    void SetPos(int x, int y);
    void SetAffine(int affineIdx, BOOL doubleSize);
    void SetMosaic(BOOL mosaic);
    GXOamAttr *Write(GXOamAttr *dst, int nameShift, int charShift);
    u8 GetTouchTrigger();
    u8 GetTouchHold();
    void SetTouchRect(s16 width, s16 height, s16 offsetX, s16 offsetY);
    BOOL IsTouchInside();

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

STATIC_SIZE_ASSERT(OamSprite, 0x3C);

#endif // POKERANGER2_OAMSPRITE_HPP
