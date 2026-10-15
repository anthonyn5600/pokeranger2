#ifndef POKERANGER2_BATTLE_UNKCLASS_02127B48_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02127B48_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"

class UnkClass_021278E8;
class CSoftwareSprite;

class Camera2D;

// Defined in ov1
class UnkClass_02127B48 {
public:
    UnkClass_02127B48();
    ~UnkClass_02127B48();
    void Update();
    void Render(Camera2D *camera);
    void SetData(UnkClass_021278E8 *data);
    int SetZ(int z);

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }

public:
    UnkClass_021278E8 *m_data;
    CSoftwareSprite *m_sprite;
    BOOL unk_08;
    Point2D m_pos;
    u16 m_animId;
};

STATIC_SIZE_ASSERT(UnkClass_02127B48, 0x18);

#endif // POKERANGER2_BATTLE_UNKCLASS_02127B48_HPP
