#ifndef POKERANGER2_UNKCLASS_0202773C_HPP
#define POKERANGER2_UNKCLASS_0202773C_HPP

#include <nitro.h>

#include "common.hpp"

class CGame;

// Opened from the sub-screen icon menu (UnkClass_02023558::unk_11C); still asm
class UnkClass_0202773C {
public:
    UnkClass_0202773C(CGame *game);
    ~UnkClass_0202773C();

    BOOL sub_0202780C();
    void sub_020279A4();

public:
    u8 unk_00[0x18];
};

STATIC_SIZE_ASSERT(UnkClass_0202773C, 0x18);

#endif // POKERANGER2_UNKCLASS_0202773C_HPP
