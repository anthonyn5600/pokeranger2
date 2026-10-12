#ifndef POKERANGER2_BATTLE_UNKCLASS_0212306C_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0212306C_HPP

#include <nitro.h>

#include "common.hpp"
#include "primitive/CPrimitiveLINE.hpp"

// Defined in ov1
class UnkClass_0212306C {
public:
    UnkClass_0212306C();
    void ov1_02124AF4(u16 arg0);
    void ov1_02124B08(int type);
    void ov1_02124DEC();
    BOOL ov1_02124650(fx32 x, fx32 y);

public:
    u8 unk_0000[0x4];
    CPrimitiveLINE m_lines[0x60];
    u8 unk_0F04[0x459E];
    u16 unk_54A2;
    u8 unk_54A4[0x24];
    u32 unk_54C8;
    u8 unk_54CC[0x8];
    CPrimitiveLINE m_lines2[0x60];
    u8 unk_63D4[0x40];
    u16 unk_6414;
    u8 unk_6416[0xEE];
};

STATIC_SIZE_ASSERT(UnkClass_0212306C, 0x6504);

#endif // POKERANGER2_BATTLE_UNKCLASS_0212306C_HPP
