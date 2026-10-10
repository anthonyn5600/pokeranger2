#ifndef POKERANGER2_UNKCLASS_02008788_HPP
#define POKERANGER2_UNKCLASS_02008788_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_02008788 {
public:
    UnkClass_02008788();
    ~UnkClass_02008788();

    u16 sub_02008828(u16 id);
    BOOL sub_0200887C(const char *path, u32 arg1, u32 arg2);
    BOOL sub_02008990(u16 id, u16 anim);
    void sub_020089EC();
    u16 sub_02008A80(u32 arg0, u32 arg1);
    void sub_02008BF0();
    u8 sub_02008C6C();

public:
    u8 unk_00[0x10];
};

STATIC_SIZE_ASSERT(UnkClass_02008788, 0x10);

#endif // POKERANGER2_UNKCLASS_02008788_HPP
