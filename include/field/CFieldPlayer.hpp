#ifndef POKERANGER2_FIELD_CFIELDPLAYER_HPP
#define POKERANGER2_FIELD_CFIELDPLAYER_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActor.hpp"

class CFieldPlayer;

extern "C" {
void ov0_021341E0(CFieldPlayer *player);
}

// Defined in ov0
class CFieldPlayer : public CFieldActor {
public:
    CFieldPlayer();
    virtual ~CFieldPlayer();

    inline void SetFollow(u32 id)
    {
        unk_5C = 1;
        unk_60 = id;
    }

    inline void ResetMove()
    {
        Point2D zero = { 0, 0 };
        unk_F4 = zero;
        unk_FC = unk_F4;
        unk_104 = 0;
    }

    // Emitted (weak) by CFieldScene_3.cpp after CFieldScene::ov0_02123E58, which calls it through the vtable.
    virtual void sub_0202D7E0()
    {
        ResetMove();
        ov0_021341E0(this);
        sub_show();
        sub_0201287C_();
        ResetUnk00C();
    }

    inline void sub_flag2()
    {
        unk_10C |= 1;
        unk_E4 = 60;
        unk_140 = 1;
    }

public:
    u8 unk_E0[0x4];
    int unk_E4;
    u8 unk_E8;
    u8 unk_E9[0xB];
    Point2D unk_F4;
    Point2D unk_FC;
    int unk_104;
    u8 unk_108[0x4];
    u32 unk_10C;
    int unk_110;
    u8 unk_114[0x2C];
    int unk_140;
    u8 unk_144[0x74];
};

STATIC_SIZE_ASSERT(CFieldPlayer, 0x1B8);

extern "C" {
void ov0_02132F14(CFieldPlayer *player, u8 arg1, int arg2, u8 arg3);
void ov0_02132FA0(CFieldPlayer *player, u8 arg1);
}

#endif // POKERANGER2_FIELD_CFIELDPLAYER_HPP
