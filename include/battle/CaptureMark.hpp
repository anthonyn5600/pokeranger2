#ifndef POKERANGER2_BATTLE_CAPTUREMARK_HPP
#define POKERANGER2_BATTLE_CAPTUREMARK_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"

class UnkClass_021297C0;
class CSoftwareSprite;
class Camera2D;

// Defined in ov1
class CaptureMark {
public:
    CaptureMark(); // ov1_021299CC
    ~CaptureMark(); // ov1_02129A0C
    void Update();
    void Render(Camera2D *camera);
    void Show(u16 duration);
    int SetZ(int z);

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }
    void SetData(UnkClass_021297C0 *data);

public:
    UnkClass_021297C0 *m_data;
    CSoftwareSprite *m_sprite;
    BOOL unk_08;
    u16 m_duration;
    u16 m_frame;
    fx32 m_scale;
    Point2D m_pos;
};

STATIC_SIZE_ASSERT(CaptureMark, 0x1C);

#endif // POKERANGER2_BATTLE_CAPTUREMARK_HPP
