#ifndef POKERANGER2_UNKCLASS_0215994C_HPP
#define POKERANGER2_UNKCLASS_0215994C_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in ov0
class UnkClass_0215994C {
public:
    UnkClass_0215994C();
    ~UnkClass_0215994C();

public:
    u8 unk_00[0x2C];
};

STATIC_SIZE_ASSERT(UnkClass_0215994C, 0x2C);

extern "C" {
void ov0_02159970(UnkClass_0215994C *obj);
}

#endif // POKERANGER2_UNKCLASS_0215994C_HPP
