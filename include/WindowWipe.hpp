#ifndef POKERANGER2_WINDOWWIPE_HPP
#define POKERANGER2_WINDOWWIPE_HPP

#include <nitro.h>

#include "common.hpp"

struct UnkStruct_0200E330_Rect {
    u8 x1;
    u8 y1;
    u8 x2;
    u8 y2;
};

class WindowWipe {
public:
    WindowWipe(u8 screen);

    void Start(int x, int y, u16 duration, u16 mode);
    void Update();
    void Apply();
    u8 Clamp(int value, int min, int max);
    void SetVisibleWnd(int windows);
    void sub_0200E614(int buffer, int radius);
    void BuildCircle(int buffer, int radius);
    void Advance();
    int GetRadius();
    BOOL sub_0200E91C();

    inline BOOL func0()
    {
        return unk_0000 & 0x8 ? TRUE : FALSE;
    }

public:
    u16 unk_0000;
    u8 unk_0002;
    u16 unk_0004;
    u16 unk_0006;
    int unk_0008;
    int unk_000C;
    int unk_0010;
    fx32 unk_0014;
    fx32 unk_0018;
    u8 unk_001C;
    vu16 *unk_0020;
    u8 unk_0024;
    u8 unk_0025;
    u8 unk_0026;
    u8 unk_0027;
    UnkStruct_0200E330_Rect unk_0028[2][0x107];
    u16 unk_0860[2][0x107];
};

STATIC_SIZE_ASSERT(WindowWipe, 0xC7C);

#endif // POKERANGER2_WINDOWWIPE_HPP
