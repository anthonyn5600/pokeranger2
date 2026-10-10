#ifndef POKERANGER2_UNKCLASS_020233C8_HPP
#define POKERANGER2_UNKCLASS_020233C8_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;

class UnkClass_020233C8 {
public:
    UnkClass_020233C8(CGame *game);
    ~UnkClass_020233C8();

public:
    u8 unk_00[0x10];
};

STATIC_SIZE_ASSERT(UnkClass_020233C8, 0x10);

extern "C" {
void sub_020234F0(UnkClass_020233C8 *obj);
}

#endif // POKERANGER2_UNKCLASS_020233C8_HPP
