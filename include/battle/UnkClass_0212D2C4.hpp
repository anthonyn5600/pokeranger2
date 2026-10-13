#ifndef POKERANGER2_BATTLE_UNKCLASS_0212D2C4_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0212D2C4_HPP

#include <nitro.h>

#include "common.hpp"
#include "primitive/CPrimitiveLINE.hpp"

class CSoftwareSprite;
class UnkClass_0201AAE0;
class UnkClass_02008788;

// Defined in ov1: the BSE i071 ring around the disk (CBattleDisk::unk_264)
class UnkClass_0212D2C4 {
public:
    UnkClass_0212D2C4();
    ~UnkClass_0212D2C4();
    void ov1_0212D5DC();
    void ov1_0212D774();
    void ov1_0212D870();
    void ov1_0212D880();
    void ov1_0212D974(Camera2D *camera);
    void ov1_0212DAF0();
    void ov1_0212DB04();
    int ov1_0212DB18(int z);
    void ov1_0212DBB0(u8 alpha);

    inline void SetPos(Point2D pos)
    {
        m_pos = pos;
    }

public:
    int m_state;
    u16 m_frame;
    u16 m_angle;
    fx32 m_radius;
    Point2D m_pos;
    UnkClass_0201AAE0 *m_res;
    CSoftwareSprite *m_sprites0[3];
    CSoftwareSprite *m_sprites1[3];
    UnkClass_02008788 *m_anim;
    u16 m_cells0[3];
    u16 m_cells1[3];
    CPrimitiveLINE m_lines[3][8];
};

STATIC_SIZE_ASSERT(UnkClass_0212D2C4, 0x400);

#endif // POKERANGER2_BATTLE_UNKCLASS_0212D2C4_HPP
