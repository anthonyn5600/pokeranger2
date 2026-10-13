#ifndef POKERANGER2_FIELD_CFIELDPOKEMOVE_HPP
#define POKERANGER2_FIELD_CFIELDPOKEMOVE_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class CFieldActor;

// Enemy record from the table behind MAIN_BSS_0210CA6C (sub_02041D58).
struct FieldEnemyData {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    u16 unk_0A;
    fx32 unk_0C;
    fx32 unk_10;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u16 unk_1A;
    fx32 unk_1C;
    fx32 unk_20;
    u8 unk_24;
    u8 unk_25;
    u8 unk_26;
    u8 unk_27;
    u16 unk_28;
    u16 unk_2A;
    u16 unk_2C;
    u16 unk_2E;
    u16 unk_30;
    u16 unk_32;
    u8 unk_34;
    u8 unk_35;
    u8 unk_36;
    u8 unk_37;
    u8 unk_38;
    u8 unk_39;
    u8 unk_3A;
    u8 unk_3B;
    u8 unk_3C;
    s8 unk_3D;
    s8 unk_3E;
    u8 unk_3F;
};

// FieldPokeMove.cpp (ov0): scripted movement of a Pokémon, embedded in each CFieldEnemy.
class CFieldPokeMove {
public:
    CFieldPokeMove();
    virtual ~CFieldPokeMove();

    void ov0_02152AD0(CFieldActor *owner, Point2D target, int arg);
    void ov0_02152B04();
    void ov0_0215674C(int sequence);
    void ov0_0215844C(void *buf, void *end);
    void ov0_021585B8(void *data);
    void ov0_02158954();
    void ov0_02158988();

    inline void SetUnk04(Point2D pos)
    {
        unk_04 = pos;
    }

public:
    Point2D unk_04;
    u8 unk_0C[0x24];
    Point2D unk_30;
    u8 unk_38[0x8];
    int unk_40;
    int unk_44;
    CFieldActor *unk_48;
    u8 unk_4C[0x4];
    int unk_50;
    u8 unk_54[0x10];
    int unk_64;
    int unk_68;
    FieldEnemyData unk_6C;
    u8 unk_AC[0x4];
    int unk_B0;
    u8 unk_B4[0x8];
    int unk_BC;
    int unk_C0;
    u8 unk_C4[0x8];
    int unk_CC;
    int unk_D0;
    u8 unk_D4[0x2];
    u16 unk_D6;
};

STATIC_SIZE_ASSERT(CFieldPokeMove, 0xD8);

extern "C" {
void ov0_02158F38(CFieldPokeMove *move);
}

#endif // POKERANGER2_FIELD_CFIELDPOKEMOVE_HPP
