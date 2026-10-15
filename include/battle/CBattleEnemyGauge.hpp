#ifndef POKERANGER2_BATTLE_CBATTLEENEMYGAUGE_HPP
#define POKERANGER2_BATTLE_CBATTLEENEMYGAUGE_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "Collision.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveQUAD.hpp"
#include "primitive/CSoftwareSprite.hpp"

class BattleEnemyGaugeGfx;

// Defined in ov1
class CBattleEnemyGauge : public CActor {
public:
    CBattleEnemyGauge(BattleEnemyGaugeGfx *arg0);
    virtual ~CBattleEnemyGauge();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);
    void SetHP(u16 hp, Point2D pos);
    int SetZ(int z);
    void ShowDamage(int damage);
    void Setup(int arg0, u16 arg1, u16 arg2, Point2D pos);
    void Init();
    BOOL IsVisible();
    void UpdateDamageIn();
    void UpdateDamageHold();
    void UpdateDamageOut();

public:
    CPrimitiveQUAD m_bar;
    int unk_1E4;
    int m_z;
    u16 m_flags;
    u16 m_hp;
    u16 m_maxHP;
    u8 m_width;
    BattleEnemyGaugeGfx *m_res;
    u16 m_cell;
    fx32 m_barLen;
    u8 m_dmgFrame;
    u8 m_dmgState;
    u8 m_digitCount;
    u16 m_damage;
    fx32 m_dmgOffset;
    CSoftwareSprite m_dmgLabel;
    CSoftwareSprite m_digits[4];
};

STATIC_SIZE_ASSERT(CBattleEnemyGauge, 0x388);

#endif // POKERANGER2_BATTLE_CBATTLEENEMYGAUGE_HPP
