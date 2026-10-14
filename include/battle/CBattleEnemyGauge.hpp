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
    void ov1_02135F2C(u16 hp, Point2D pos);
    int ov1_02136248(int z);
    void ov1_021362A0(int damage);
    void ov1_02135E70(int arg0, u16 arg1, u16 arg2, Point2D pos);
    void ov1_02135D8C();
    BOOL ov1_0213607C();
    void ov1_02136344();
    void ov1_021363D0();
    void ov1_0213642C();

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
