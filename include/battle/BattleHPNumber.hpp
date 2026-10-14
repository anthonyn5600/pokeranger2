#ifndef POKERANGER2_BATTLE_BATTLEHPNUMBER_HPP
#define POKERANGER2_BATTLE_BATTLEHPNUMBER_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"

class BattleHPNumberGfx;
class CSoftwareSprite;

class Camera2D;

// Defined in ov1
class BattleHPNumber {
public:
    BattleHPNumber();
    ~BattleHPNumber();
    void ov1_02128970(Camera2D *camera);

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }
    void ov1_0212891C(BattleHPNumberGfx *arg0);

public:
    Point2D m_pos;
    u16 m_hp;
    CSoftwareSprite *m_sprite;
    BattleHPNumberGfx *m_data;
    u16 m_animId;
};

STATIC_SIZE_ASSERT(BattleHPNumber, 0x18);

#endif // POKERANGER2_BATTLE_BATTLEHPNUMBER_HPP
