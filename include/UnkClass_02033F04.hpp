#ifndef POKERANGER2_UNKCLASS_02033F04_HPP
#define POKERANGER2_UNKCLASS_02033F04_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in main (still asm); CGame::m_scriptManager
class UnkClass_02033F04 {
public:
    UnkClass_02033F04(u32 arg0);

public:
    u8 unk_00[0x1881C];
};

STATIC_SIZE_ASSERT(UnkClass_02033F04, 0x1881C);

#endif // POKERANGER2_UNKCLASS_02033F04_HPP
