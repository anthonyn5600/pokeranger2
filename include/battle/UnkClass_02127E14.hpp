#ifndef POKERANGER2_BATTLE_UNKCLASS_02127E14_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02127E14_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class UnkClass_02127CD8;
class UnkClass_02008788;
class CSoftwareSprite;

class Camera2D;

// Defined in ov1
class UnkClass_02127E14 {
public:
    UnkClass_02127E14();
    ~UnkClass_02127E14();
    void ov1_02127EE4();
    void ov1_02127FAC(Camera2D *camera);
    void ov1_0212807C(UnkClass_02127CD8 *data);
    void ov1_0212812C(fx32 x, fx32 y, int flags);

public:
    UnkClass_02127CD8 *m_data;
    BOOL unk_04;
    u16 unk_08;
    u8 m_flags;
    u8 m_alpha;
    fx32 m_scale;
    Point2D m_pos;
    u16 m_cell0;
    u16 m_cell1;
    CSoftwareSprite *m_sprite0;
    CSoftwareSprite *m_sprite1;
    UnkClass_02008788 *m_anim0;
    UnkClass_02008788 *m_anim1;
    u16 m_animId0;
    u16 m_animId1;
};

STATIC_SIZE_ASSERT(UnkClass_02127E14, 0x30);

#endif // POKERANGER2_BATTLE_UNKCLASS_02127E14_HPP
