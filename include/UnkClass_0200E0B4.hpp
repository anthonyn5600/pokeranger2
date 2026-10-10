#ifndef POKERANGER2_UNKCLASS_0200E0B4_HPP
#define POKERANGER2_UNKCLASS_0200E0B4_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_0200E0B4 {
public:
    UnkClass_0200E0B4(u8 screen, int brightness);

    void sub_0200E0E0(u16 mode, u16 duration);
    int sub_0200E1A4(u16 mode);
    int sub_0200E1DC(u16 mode);
    void sub_0200E210();
    void sub_0200E2D4();
    BOOL sub_0200E310();
    u16 sub_0200E324();

public:
    u16 unk_00;
    u8 unk_02;
    u16 unk_04;
    u16 unk_06;
    int unk_08;
    int unk_0C;
    int unk_10;
    fx32 unk_14;
    fx32 unk_18;
};

STATIC_SIZE_ASSERT(UnkClass_0200E0B4, 0x1C);

#endif // POKERANGER2_UNKCLASS_0200E0B4_HPP
