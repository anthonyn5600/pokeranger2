#ifndef POKERANGER2_BATTLE_UNKCLASS_021299CC_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021299CC_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class UnkClass_021297C0;
class CSoftwareSprite;
class Camera2D;

// Defined in ov1
class UnkClass_021299CC {
public:
    UnkClass_021299CC(); // ov1_021299CC
    ~UnkClass_021299CC(); // ov1_02129A0C
    void ov1_02129A40();
    void ov1_02129A98(Camera2D *camera);
    void ov1_02129B30(u16 duration);
    int ov1_02129B48(int z);

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }
    void ov1_02129AF4(UnkClass_021297C0 *data);

public:
    UnkClass_021297C0 *m_data;
    CSoftwareSprite *m_sprite;
    BOOL unk_08;
    u16 m_duration;
    u16 m_frame;
    fx32 m_scale;
    Point2D m_pos;
};

STATIC_SIZE_ASSERT(UnkClass_021299CC, 0x1C);

#endif // POKERANGER2_BATTLE_UNKCLASS_021299CC_HPP
