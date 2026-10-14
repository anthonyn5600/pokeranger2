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
    void ov1_02129274(BattleStatusIconGfx *data);
    void ov1_021292CC();
    void ov1_02129368(Camera2D *camera);
    void ov1_021293D4(Camera2D *camera);
    void ov1_021293D8(int state);
    int ov1_02129490(int z);

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
