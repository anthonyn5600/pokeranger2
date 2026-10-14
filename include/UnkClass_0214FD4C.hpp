#ifndef POKERANGER2_UNKCLASS_0214FD4C_HPP
#define POKERANGER2_UNKCLASS_0214FD4C_HPP

#include <nitro.h>

#include "common.hpp"

class Camera2D;
class CPrimitiveRECT;
class CSoftwareSprite;
class GraphicsSet;

// Defined in ov0
// Field icon i044 (FMB archive), animated for 4 frames after ov0_0214FF44
class UnkClass_0214FD4C {
public:
    UnkClass_0214FD4C();
    ~UnkClass_0214FD4C();
    void Init(); // ov0_0214FD74
    void Release(); // ov0_0214FE74
    void ov0_0214FEF0();
    void ov0_0214FF20(Camera2D *camera);
    void ov0_0214FF44();

public:
    u8 m_flags;
    u8 m_frame;
    u16 m_z;
    CPrimitiveRECT *m_rect;
    CSoftwareSprite *m_sprite;
    GraphicsSet *m_res;
};

STATIC_SIZE_ASSERT(UnkClass_0214FD4C, 0x10);

#endif // POKERANGER2_UNKCLASS_0214FD4C_HPP
