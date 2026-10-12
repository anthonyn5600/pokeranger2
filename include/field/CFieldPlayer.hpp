#ifndef POKERANGER2_FIELD_CFIELDPLAYER_HPP
#define POKERANGER2_FIELD_CFIELDPLAYER_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActor.hpp"

class CFieldPlayer;
class CTouchPanel;
class UnkClass_02001C04;
class Camera2D;

// Defined in ov0
class CFieldPlayer : public CFieldActor {
public:
    CFieldPlayer();
    virtual ~CFieldPlayer();

    virtual void sub_0202E68C(int arg0);

    void ov0_02132E68(BOOL arg1);
    BOOL ov0_02132EE4(u16 arg1, int arg2, u32 arg3);
    BOOL ov0_02132F14(u8 arg1, int arg2, u8 arg3);
    void ov0_02132FA0(u8 mode);
    void ov0_021307B0(UnkClass_02001C04 *pad, CTouchPanel *touch, Camera2D *camera, CFieldMap *map, u32 flags);
    BOOL ov0_021333A0(fx32 dx, fx32 dy, int arg3, int damage, int arg5);
    BOOL ov0_021337DC(int dir, int dir2, fx32 vx, fx32 vy, int arg5, int arg6, fx32 distX, fx32 distY, int arg9, int mode);
    void ov0_02133E8C(int arg1);
    void ov0_02133EB4();
    void ov0_02133EE4();
    inline void PushHistory(Point2D pos, Point2D partnerPos);

    inline Point2D GetTrail(int i)
    {
        return unk_150[i];
    }

    inline Point2D GetPartnerTrail(int i)
    {
        return unk_180[i];
    }
    BOOL ov0_0213416C();
    BOOL ov0_021341E0();

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
        ov0_021341E0();
        sub_show();
        sub_0201287C_();
        ResetUnk00C();
    }

    inline void SetInvincible(int time, int type)
    {
        unk_10C |= 1;
        unk_E4 = time;
        unk_140 = type;
    }

    inline void sub_flag2()
    {
        unk_10C |= 1;
        unk_E4 = 60;
        unk_140 = 1;
    }

public:
    int unk_E0;
    int unk_E4;
    u8 unk_E8;
    u8 unk_E9[0x3];
    int unk_EC;
    int unk_F0;
    Point2D unk_F4;
    Point2D unk_FC;
    int unk_104;
    int unk_108;
    u32 unk_10C;
    int unk_110;
    int unk_114;
    int unk_118;
    int unk_11C;
    int unk_120;
    int unk_124;
    int unk_128;
    int unk_12C;
    int unk_130;
    int unk_134;
    int unk_138;
    int unk_13C;
    int unk_140;
    int unk_144;
    int unk_148;
    int unk_14C;
    Point2D unk_150[6];
    Point2D unk_180[6];
    int unk_1B0;
    int unk_1B4;
};

STATIC_SIZE_ASSERT(CFieldPlayer, 0x1B8);

#endif // POKERANGER2_FIELD_CFIELDPLAYER_HPP
