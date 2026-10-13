#ifndef POKERANGER2_BATTLE_UNKCLASS_021380AC_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021380AC_HPP

#include <nitro.h>

#include "common.hpp"

class Camera2D;
class CPrimitiveRECT;
class CSoftwareSprite;
class UnkClass_0201AAE0;

// Defined in ov1
// Battle icon i046 (BAS archive), animated for 16 frames after Start
class UnkClass_021380AC {
public:
    UnkClass_021380AC();
    ~UnkClass_021380AC(); // ov1_021380C0
    void Init();
    void Release();
    void ov1_02138238();
    void ov1_02138268(Camera2D *camera);
    void ov1_02138280();
    int ov1_021382A4(int z);

public:
    u8 m_flags;
    u8 m_frame;
    CPrimitiveRECT *m_rect;
    CSoftwareSprite *m_sprite;
    UnkClass_0201AAE0 *m_res;
};

STATIC_SIZE_ASSERT(UnkClass_021380AC, 0x10);

#endif // POKERANGER2_BATTLE_UNKCLASS_021380AC_HPP
