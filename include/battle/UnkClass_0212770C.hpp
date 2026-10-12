#ifndef POKERANGER2_BATTLE_UNKCLASS_0212770C_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0212770C_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class UnkClass_021274AC;
class CSoftwareSprite;

class Camera2D;

// Defined in ov1
class UnkClass_0212770C {
public:
    UnkClass_0212770C();
    ~UnkClass_0212770C();
    void ov1_02127780();
    void ov1_02127810(Camera2D *camera);
    void ov1_02127854(UnkClass_021274AC *data);
    void ov1_02127888(int cell, u16 duration);
    int ov1_021278BC(int z);

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }

public:
    UnkClass_021274AC *m_data;
    CSoftwareSprite *m_sprite;
    BOOL unk_08;
    u16 m_duration;
    u16 m_frame;
    int m_cell;
    fx32 m_offsetY;
    Point2D m_pos;
};

STATIC_SIZE_ASSERT(UnkClass_0212770C, 0x20);

#endif // POKERANGER2_BATTLE_UNKCLASS_0212770C_HPP
