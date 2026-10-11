#ifndef POKERANGER2_UNKCLASS_02034478_HPP
#define POKERANGER2_UNKCLASS_02034478_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in main (still asm); CGame::m_audioEngine
class UnkClass_02034478 {
public:
    UnkClass_02034478();

public:
    u8 unk_00[0xC4];
    s32 unk_C4;
    u8 unk_C8[0x8];
    s32 unk_D0;
    u8 unk_D4[0x1C];
    s32 unk_F0;
    u8 unk_F4[0xB8];
};

STATIC_SIZE_ASSERT(UnkClass_02034478, 0x1AC);

#endif // POKERANGER2_UNKCLASS_02034478_HPP
