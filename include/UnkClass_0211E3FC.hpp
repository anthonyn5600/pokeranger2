#ifndef POKERANGER2_UNKCLASS_0211E3FC_HPP
#define POKERANGER2_UNKCLASS_0211E3FC_HPP

#include <nitro.h>

#include "common.hpp"

extern "C" {
void sub_020091DC(void *obj);
}

// Defined in ov0
class UnkClass_0211E3FC {
public:
    UnkClass_0211E3FC()
    {
        sub_020091DC(this);
    }

    ~UnkClass_0211E3FC()
    {
    }

public:
    u32 unk_00;
};

STATIC_SIZE_ASSERT(UnkClass_0211E3FC, 0x4);

#endif // POKERANGER2_UNKCLASS_0211E3FC_HPP
