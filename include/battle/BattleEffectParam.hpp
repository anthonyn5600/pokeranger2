#ifndef POKERANGER2_BATTLE_BATTLEEFFECTPARAM_HPP
#define POKERANGER2_BATTLE_BATTLEEFFECTPARAM_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"

// Attack effect parameter record (BattleEffectTable table entry)
struct BattleEffectParam {
    u16 unk_00;
    u16 unk_02;
    int unk_04;
    u8 unk_08;
    u8 unk_09[0x3];
    u32 unk_0C;
    s8 unk_10;
    s8 unk_11;
    u8 unk_12;
    u8 unk_13;
    u8 unk_14;
    u8 unk_15;
    u8 unk_16;
    u8 unk_17;
    s8 unk_18;
    s8 unk_19;
    u8 unk_1A;
    u8 unk_1B;

    inline Circle GetCircle()
    {
        Circle circle = { unk_10 << 12, unk_11 << 12, unk_12 << 12 };
        return circle;
    }

    inline Rectangle GetShadowRect()
    {
        Rectangle rect = { unk_18 << 12, unk_19 << 12, unk_1A << 12, unk_1B << 12 };
        return rect;
    }
};

STATIC_SIZE_ASSERT(BattleEffectParam, 0x1C);

#endif // POKERANGER2_BATTLE_BATTLEEFFECTPARAM_HPP
