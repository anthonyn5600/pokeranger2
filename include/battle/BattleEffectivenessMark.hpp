#ifndef POKERANGER2_BATTLE_BATTLEEFFECTIVENESSMARK_HPP
#define POKERANGER2_BATTLE_BATTLEEFFECTIVENESSMARK_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"

class BattleEffectivenessMarkGfx;
class CSoftwareSprite;

class Camera2D;

// Defined in ov1
class BattleEffectivenessMark {
public:
    BattleEffectivenessMark();
    ~BattleEffectivenessMark();
    void Update();
    void Render(Camera2D *camera);
    void SetData(BattleEffectivenessMarkGfx *data);
    void Show(int anim);
    int SetZ(int z);

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }

public:
    BattleEffectivenessMarkGfx *m_data;
    CSoftwareSprite *m_sprite;
    BOOL unk_08;
    Point2D m_pos;
    u16 m_animId;
};

STATIC_SIZE_ASSERT(BattleEffectivenessMark, 0x18);

#endif // POKERANGER2_BATTLE_BATTLEEFFECTIVENESSMARK_HPP
