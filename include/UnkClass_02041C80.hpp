#ifndef POKERANGER2_UNKCLASS_02041C80_HPP
#define POKERANGER2_UNKCLASS_02041C80_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in main (still asm); CGame::unk_14CC, opened on data/field/fielddata.bin
class UnkClass_02041C80 {
public:
    UnkClass_02041C80(const char *path, int arg1);

public:
    u8 unk_00[0x14];
};

STATIC_SIZE_ASSERT(UnkClass_02041C80, 0x14);

#endif // POKERANGER2_UNKCLASS_02041C80_HPP
