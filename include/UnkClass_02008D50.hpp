#ifndef POKERANGER2_UNKCLASS_02008D50_HPP
#define POKERANGER2_UNKCLASS_02008D50_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_02008D50 {
public:
    UnkClass_02008D50();

    void sub_02008D7C();
    void sub_02008DB4(u16 fps);
    u16 sub_02008E50();
    void sub_02008E58();
    void sub_02008E68();

public:
    OSTick unk_00;
    s64 unk_08;
    u16 unk_10;
    vu16 unk_12;
    u16 unk_14;
    u32 unk_18;
    u32 unk_1C;
};

STATIC_SIZE_ASSERT(UnkClass_02008D50, 0x20);

#endif // POKERANGER2_UNKCLASS_02008D50_HPP
