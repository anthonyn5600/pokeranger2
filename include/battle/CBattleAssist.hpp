#ifndef POKERANGER2_BATTLE_CBATTLEASSIST_HPP
#define POKERANGER2_BATTLE_CBATTLEASSIST_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class CBattleAttackEffect;
class CBattleDisk;
class CBattleEnemy;
class CTouchPanel;
class CBattleAttackEffectData;
class CPlayerHPGauge;
class UnkClass_0200D3F8;
class UnkClass_02034478;
class UnkClass_0212EEB4;

// Defined in ov1: the partner pokemon assist effects
class CBattleAssist {
public:
    CBattleAssist(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssist();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies) = 0;
    virtual void vfunc_0C() = 0;
    virtual int vfunc_10() = 0;

    CBattleAttackEffect *ov1_0212EE3C();

public:
    u16 unk_04;
    u8 unk_06[0x2];
    CBattleAttackEffect **unk_08;
    CBattleAttackEffectData **unk_0C;
    UnkClass_0212EEB4 *unk_10;
    UnkClass_02034478 *unk_14;
};

STATIC_SIZE_ASSERT(CBattleAssist, 0x18);

class CBattleAssistNormal : public CBattleAssist {
public:
    CBattleAssistNormal(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistNormal();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();
};

STATIC_SIZE_ASSERT(CBattleAssistNormal, 0x18);

class CBattleAssistFire : public CBattleAssist {
public:
    CBattleAssistFire(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistFire();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();
};

STATIC_SIZE_ASSERT(CBattleAssistFire, 0x18);

class CBattleAssistWater : public CBattleAssist {
public:
    CBattleAssistWater(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistWater();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();

public:
    u8 unk_18[0x50];
};

STATIC_SIZE_ASSERT(CBattleAssistWater, 0x68);

struct ElectricBolt {
    u8 m_flags;
    u16 m_timer;
    CBattleAttackEffect *m_effect;
    CBattleAttackEffect *m_effect2;
};

STATIC_SIZE_ASSERT(ElectricBolt, 0xC);

class CBattleAssistElectric : public CBattleAssist {
public:
    CBattleAssistElectric(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistElectric();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();

    ElectricBolt *ov1_02130038();
    void ov1_02130074(ElectricBolt *bolt, fx32 x, fx32 y);

public:
    ElectricBolt m_bolts[1];
};

STATIC_SIZE_ASSERT(CBattleAssistElectric, 0x24);

class CBattleAssistGrass : public CBattleAssist {
public:
    CBattleAssistGrass(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistGrass();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();

public:
    u8 unk_18[0xCC];
};

STATIC_SIZE_ASSERT(CBattleAssistGrass, 0xE4);

class CBattleAssistIce : public CBattleAssist {
public:
    CBattleAssistIce(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistIce();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();

public:
    u8 unk_18[0xB4];
};

STATIC_SIZE_ASSERT(CBattleAssistIce, 0xCC);

class CBattleAssistGrapple : public CBattleAssist {
public:
    CBattleAssistGrapple(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistGrapple();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();
};

STATIC_SIZE_ASSERT(CBattleAssistGrapple, 0x18);

class CBattleAssistPoison : public CBattleAssist {
public:
    CBattleAssistPoison(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistPoison();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();

public:
    u8 unk_18[0xDC];
};

STATIC_SIZE_ASSERT(CBattleAssistPoison, 0xF4);

class CBattleAssistGround : public CBattleAssist {
public:
    CBattleAssistGround(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistGround();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();
    void ov1_0213219C(UnkClass_0200D3F8 *arg0);

public:
    u8 unk_18[0x14];
};

STATIC_SIZE_ASSERT(CBattleAssistGround, 0x2C);

class CBattleAssistFly : public CBattleAssist {
public:
    CBattleAssistFly(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistFly();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();

    void ov1_021311E4(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    void ov1_021311F8(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    void ov1_02131410(fx32 x, fx32 y);
    void ov1_021314A0(fx32 x, fx32 y, u16 angle);

public:
    int m_state;
    u8 unk_1C[0x8];
    u8 m_level;
    u16 m_angle;
    CBattleAttackEffect *m_bird;
};

STATIC_SIZE_ASSERT(CBattleAssistFly, 0x2C);

struct EsperSlot {
    u8 unk_00;
    u8 state;
    u16 unk_02;
    Rectangle rect;
};

STATIC_SIZE_ASSERT(EsperSlot, 0x14);

class CBattleAssistEsper : public CBattleAssist {
public:
    CBattleAssistEsper(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistEsper();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();

    void ov1_021304F0(CBattleEnemy **enemies);
    void ov1_02130628(u8 i);
    BOOL ov1_021306C0(u8 *idx);
    BOOL ov1_0213071C(u8 *outIdx);
    BOOL ov1_021307E8(CBattleAttackEffect *effect, CBattleEnemy **enemies);
    BOOL ov1_021309F4(Point2D pos, Rectangle rect);

public:
    u8 m_flags;
    u8 m_selected;
    u16 unk_1A;
    u16 m_timer;
    Point2D m_last;
    CBattleAttackEffect *m_effects[4];
    EsperSlot m_slots[4];
};

STATIC_SIZE_ASSERT(CBattleAssistEsper, 0x88);

class CBattleAssistInsect : public CBattleAssist {
public:
    CBattleAssistInsect(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistInsect();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();
    void ov1_02133B3C(CBattleAttackEffect **effects);

public:
    u8 unk_18[0xD0];
};

STATIC_SIZE_ASSERT(CBattleAssistInsect, 0xE8);

class CBattleAssistRock : public CBattleAssist {
public:
    CBattleAssistRock(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistRock();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();

public:
    u8 unk_18[0x38];
};

STATIC_SIZE_ASSERT(CBattleAssistRock, 0x50);

class CBattleAssistGhost : public CBattleAssist {
public:
    CBattleAssistGhost(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistGhost();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();

public:
    u8 unk_18[0x64];
};

STATIC_SIZE_ASSERT(CBattleAssistGhost, 0x7C);

class CBattleAssistDragon : public CBattleAssist {
public:
    CBattleAssistDragon(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistDragon();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();

    void ov1_0212F56C(CTouchPanel *touch);
    void ov1_0212F620(CTouchPanel *touch);
    void ov1_0212F700(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    void ov1_0212F9D4();
    BOOL ov1_0212FA80(fx32 x, fx32 y, u8 level, u8 frame);
    CBattleAttackEffect *ov1_0212FBD0(fx32 x, fx32 y);

public:
    int m_state;
    u16 m_chargeTimer;
    u16 m_frame;
    u8 m_burstFrame;
    u8 m_level;
    Point2D m_pos;
    Circle m_touchArea;
    Circle m_hitArea;
    UnkClass_0200D3F8 *unk_44;
    CBattleAttackEffect *m_charge;
    CBattleAttackEffect *m_dragon;
    CBattleAttackEffect *m_bursts[5];
};

STATIC_SIZE_ASSERT(CBattleAssistDragon, 0x64);

class CBattleAssistEvil : public CBattleAssist {
public:
    CBattleAssistEvil(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistEvil();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();
};

STATIC_SIZE_ASSERT(CBattleAssistEvil, 0x18);

class CBattleAssistSteel : public CBattleAssist {
public:
    CBattleAssistSteel(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistSteel();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();

public:
    u8 unk_18[0x50];
};

STATIC_SIZE_ASSERT(CBattleAssistSteel, 0x68);

class CBattleAssistRecover : public CBattleAssist {
public:
    CBattleAssistRecover(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3);
    virtual ~CBattleAssistRecover();
    virtual int vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies);
    virtual void vfunc_0C();
    virtual int vfunc_10();

public:
    u8 unk_18[0x4];
    CPlayerHPGauge *unk_1C;
};

STATIC_SIZE_ASSERT(CBattleAssistRecover, 0x20);

#endif // POKERANGER2_BATTLE_CBATTLEASSIST_HPP
