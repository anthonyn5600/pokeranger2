#ifndef POKERANGER2_UNKCLASS_02033F04_HPP
#define POKERANGER2_UNKCLASS_02033F04_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in main (still asm); CGame::m_scriptManager
class UnkClass_02033F04 {
public:
    UnkClass_02033F04(u32 arg0);

public:
    u8 unk_00[0x18];
    int unk_18;
    u8 unk_1C[0x18800];
};

STATIC_SIZE_ASSERT(UnkClass_02033F04, 0x1881C);

extern "C" {
void sub_02033F90(void *scriptManager, int arg1);
void sub_02034184(UnkClass_02033F04 *mgr, const char *name);
void sub_02034290(UnkClass_02033F04 *mgr);
}

#endif // POKERANGER2_UNKCLASS_02033F04_HPP
