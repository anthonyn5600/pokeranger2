#ifndef POKERANGER2_BATTLE_BATTLEDAMAGENUMBER_HPP
#define POKERANGER2_BATTLE_BATTLEDAMAGENUMBER_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"

class BattleDamageNumberGfx;
class CSoftwareSprite;

class Camera2D;

// Defined in ov1
class BattleDamageNumber {
public:
    BattleDamageNumber();
    ~BattleDamageNumber();
    void SetData(BattleDamageNumberGfx *data);
    void Update();
    void Render(Camera2D *camera);
    void UpdateHold();
    void UpdateFadeOut();
    void Show(Point2D pos, int value);
    int SetZ(int z);

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }

public:
    u8 m_state;
    u8 m_timer;
    u16 m_value;
    Point2D m_pos;
    fx32 m_zDigits;
    fx32 m_zLabel;
    CSoftwareSprite *m_sprite;
    BattleDamageNumberGfx *m_data;
};

STATIC_SIZE_ASSERT(BattleDamageNumber, 0x1C);

#endif // POKERANGER2_BATTLE_BATTLEDAMAGENUMBER_HPP
