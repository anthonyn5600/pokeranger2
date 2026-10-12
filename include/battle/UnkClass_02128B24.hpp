#ifndef POKERANGER2_BATTLE_UNKCLASS_02128B24_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02128B24_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class UnkClass_02128A60;
class CSoftwareSprite;

class Camera2D;

// Defined in ov1
class UnkClass_02128B24 {
public:
    UnkClass_02128B24();
    ~UnkClass_02128B24();
    void ov1_02128BE4(UnkClass_02128A60 *data);
    void ov1_02128C2C();
    void ov1_02128C70(Camera2D *camera);
    void ov1_02128DD4();
    void ov1_02128DF4();
    void ov1_02128E34(Point2D pos, int value);
    int ov1_02128E74(int z);

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
    UnkClass_02128A60 *m_data;
};

STATIC_SIZE_ASSERT(UnkClass_02128B24, 0x1C);

#endif // POKERANGER2_BATTLE_UNKCLASS_02128B24_HPP
