#ifndef POKERANGER2_UNKCLASS_0214FD4C_HPP
#define POKERANGER2_UNKCLASS_0214FD4C_HPP

#include <nitro.h>

#include "UnkClass_0214FB28.hpp"
#include "common.hpp"

// Defined in ov0
class UnkClass_0214FD4C {
public:
    UnkClass_0214FD4C();
    ~UnkClass_0214FD4C();

public:
    u16 unk_00;
    u16 unk_02;
    UnkStruct_0214FB28 *unk_04;
    u8 unk_08[0x8];
};

STATIC_SIZE_ASSERT(UnkClass_0214FD4C, 0x10);

#endif // POKERANGER2_UNKCLASS_0214FD4C_HPP
