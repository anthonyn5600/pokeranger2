#ifndef POKERANGER2_UNKCLASS_0214FB28_HPP
#define POKERANGER2_UNKCLASS_0214FB28_HPP

#include <nitro.h>

#include "common.hpp"

class Camera2D;
class CPrimitiveRECT;
class CSoftwareSprite;
class GraphicsSet;

// Defined in ov0
// Field icon i045 (FIB archive), animated for 4 frames after Press
class UnkClass_0214FB28 {
public:
    UnkClass_0214FB28();
    ~UnkClass_0214FB28();
    void Init(); // ov0_0214FB50
    void Release(); // ov0_0214FC54
    void Update();
    void Draw(Camera2D *camera);
    void Press();

public:
    u8 m_flags;
    u8 m_frame;
    u16 m_z;
    CPrimitiveRECT *m_rect;
    CSoftwareSprite *m_sprite;
    GraphicsSet *m_res;
};

STATIC_SIZE_ASSERT(UnkClass_0214FB28, 0x10);

#endif // POKERANGER2_UNKCLASS_0214FB28_HPP
