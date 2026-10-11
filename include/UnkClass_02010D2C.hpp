#ifndef POKERANGER2_UNKCLASS_02010D2C_HPP
#define POKERANGER2_UNKCLASS_02010D2C_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in main (still asm); CGame::unk_1438
class UnkClass_02010D2C {
public:
    UnkClass_02010D2C(int arg0);

public:
    u8 unk_00[0x10];
};

STATIC_SIZE_ASSERT(UnkClass_02010D2C, 0x10);

#endif // POKERANGER2_UNKCLASS_02010D2C_HPP
