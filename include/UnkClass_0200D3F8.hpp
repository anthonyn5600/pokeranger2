#ifndef POKERANGER2_UNKCLASS_0200D3F8_HPP
#define POKERANGER2_UNKCLASS_0200D3F8_HPP

#include <nitro.h>

#include "common.hpp"

struct UnkStruct_0200D3F8_Target {
    u8 unk_00[0x1C];
    fx32 x;
    fx32 y;
    u16 rotation;
};

class UnkClass_0200D3F8 {
public:
    UnkClass_0200D3F8(UnkStruct_0200D3F8_Target *target);
    ~UnkClass_0200D3F8();

    void sub_0200D418();
    void sub_0200D44C(fx32 x, fx32 y);
    void sub_0200D460(fx32 scale);
    void sub_0200D468(fx32 dx, fx32 dy);
    void sub_0200D490(fx32 x, fx32 y, fx32 speed);
    void sub_0200D5FC(fx32 x, fx32 y, u16 frames);
    void sub_0200D6E8(fx32 amplitude, u16 speed, u16 duration);
    void sub_0200D748(fx32 scale, u16 frames);
    void sub_0200D7B8(u16 speed, u16 duration);
    void sub_0200D7F4(fx32 scale, u16 speed, u16 frames);
    void sub_0200D870(fx32 amplitude, u16 duration);
    void sub_0200D8C8(fx32 amplitude);
    void sub_0200D924(fx32 amplitude);
    void sub_0200D980();
    void sub_0200D994();
    void sub_0200D9A8(fx32 amplitude);
    BOOL sub_0200D9B8();
    void sub_0200D9CC();
    BOOL sub_0200E098();
    void sub_0200E0AC(UnkStruct_0200D3F8_Target *target);

public:
    UnkStruct_0200D3F8_Target *unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    fx32 unk_0C;
    fx32 unk_10;
    fx32 unk_14;
    fx32 unk_18;
    u16 unk_1C;
    u16 unk_1E;
    fx32 unk_20;
    fx32 unk_24;
};

STATIC_SIZE_ASSERT(UnkClass_0200D3F8, 0x28);

#endif // POKERANGER2_UNKCLASS_0200D3F8_HPP
