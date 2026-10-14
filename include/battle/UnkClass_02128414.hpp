#ifndef POKERANGER2_BATTLE_UNKCLASS_02128414_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02128414_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"

class UnkClass_021281B4;
class CSoftwareSprite;

class Camera2D;

// Defined in ov1
class UnkClass_02128414 {
public:
    UnkClass_02128414();
    ~UnkClass_02128414();
    void ov1_0212849C();
    void ov1_021284C0(Camera2D *camera);
    void ov1_0212854C(UnkClass_021281B4 *data);
    void ov1_02128598(int anim);
    int ov1_021285D4(int z);

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }

public:
    UnkClass_021281B4 *m_data;
    CSoftwareSprite *m_sprite;
    BOOL unk_08;
    Point2D m_pos;
    u16 m_animId;
};

STATIC_SIZE_ASSERT(UnkClass_02128414, 0x18);

#endif // POKERANGER2_BATTLE_UNKCLASS_02128414_HPP
