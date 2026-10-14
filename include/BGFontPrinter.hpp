#ifndef POKERANGER2_BGFONTPRINTER_HPP
#define POKERANGER2_BGFONTPRINTER_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"

class BGFontPrinter {
public:
    BGFontPrinter();

    void Init(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
    void sub_020027E8();
    int Printf(s32 arg0, u32 arg1, char *arg2, ...);
    void PutChar(s32 arg0, u32 arg1, char arg2);
    u16 GetCharTile(s32 arg0);
    void ResetArea();
    void SetAreaPalette(u32 arg0, u32 arg1, int arg2, int arg3, u32 arg4);
    void ClearArea(u32 arg0, u32 arg1, u32 arg2, s32 arg3);
    NNS_GFD_DST_TYPE GetVramDstType(u32 arg0, u32 arg1);

public:
    s32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u16 unk_0C;
    u8 unk_0E[0x2];
    fx32 unk_10[4];
    u16 *unk_20;
    u32 unk_24;
    char unk_28[33];
};

STATIC_SIZE_ASSERT(BGFontPrinter, 0x4C);

#endif // POKERANGER2_BGFONTPRINTER_HPP
