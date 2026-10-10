#ifndef POKERANGER2_UNKCLASS_0200E330_HPP
#define POKERANGER2_UNKCLASS_0200E330_HPP

#include <nitro.h>

#include "common.hpp"

struct UnkStruct_0200E330_Rect {
    u8 x1;
    u8 y1;
    u8 x2;
    u8 y2;
};

class UnkClass_0200E330 {
public:
    UnkClass_0200E330(u8 screen);

    void sub_0200E378(int x, int y, u16 duration, u16 mode);
    void sub_0200E44C();
    void sub_0200E4A8();
    u8 sub_0200E5AC(int value, int min, int max);
    void sub_0200E5C8(int windows);
    void sub_0200E614(int buffer, int radius);
    void sub_0200E6F8(int buffer, int radius);
    void sub_0200E834();
    int sub_0200E904();
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

STATIC_SIZE_ASSERT(UnkClass_0200E330, 0xC7C);

#endif // POKERANGER2_UNKCLASS_0200E330_HPP
