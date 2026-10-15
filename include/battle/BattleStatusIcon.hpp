#ifndef POKERANGER2_BATTLE_BATTLESTATUSICON_HPP
#define POKERANGER2_BATTLE_BATTLESTATUSICON_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"

class BattleStatusIconGfx;
class CSoftwareSprite;

class Camera2D;

// Defined in ov1
class BattleStatusIcon {
public:
    BattleStatusIcon();
    ~BattleStatusIcon();
    void SetData(BattleStatusIconGfx *data);
    void Update();
    void Render(Camera2D *camera);
    void ov1_021293D4(Camera2D *camera);
    void SetStatus(int state);
    int SetZ(int z);

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }

public:
    BattleStatusIconGfx *m_data;
    CSoftwareSprite *m_sprite;
    BOOL unk_08;
    u16 m_frame;
    int m_state;
    fx32 m_offsetY;
    Point2D m_pos;
    u16 m_animIds[5];
};

STATIC_SIZE_ASSERT(BattleStatusIcon, 0x2C);

#endif // POKERANGER2_BATTLE_BATTLESTATUSICON_HPP
