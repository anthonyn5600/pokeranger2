#ifndef POKERANGER2_BATTLE_BATTLEHITEFFECT_HPP
#define POKERANGER2_BATTLE_BATTLEHITEFFECT_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"

class BattleHitEffectGfx;
class CellAnimController;
class CSoftwareSprite;

class Camera2D;

// Defined in ov1
class BattleHitEffect {
public:
    BattleHitEffect();
    ~BattleHitEffect();
    void Update();
    void Render(Camera2D *camera);
    void SetData(BattleHitEffectGfx *data);
    void Show(fx32 x, fx32 y, int flags);

public:
    BattleHitEffectGfx *m_data;
    BOOL unk_04;
    u16 unk_08;
    u8 m_flags;
    u8 m_alpha;
    fx32 m_scale;
    Point2D m_pos;
    u16 m_cell0;
    u16 m_cell1;
    CSoftwareSprite *m_sprite0;
    CSoftwareSprite *m_sprite1;
    CellAnimController *m_anim0;
    CellAnimController *m_anim1;
    u16 m_animId0;
    u16 m_animId1;
};

STATIC_SIZE_ASSERT(BattleHitEffect, 0x30);

#endif // POKERANGER2_BATTLE_BATTLEHITEFFECT_HPP
