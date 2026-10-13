#ifndef POKERANGER2_BATTLE_UNKCLASS_021382D0_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021382D0_HPP

#include <nitro.h>

#include "common.hpp"

class Camera2D;
class CPrimitiveRECT;
class CSoftwareSprite;
class UnkClass_0201AAE0;

// Defined in ov1
// Battle icon i047 (BES archive), animated for 16 frames after Start
class UnkClass_021382D0 {
public:
    UnkClass_021382D0();
    ~UnkClass_021382D0(); // ov1_021382E4
    void Init();
    void Release();
    void ov1_02138460();
    void ov1_02138490(Camera2D *camera);
    void ov1_021384A8();
    int ov1_021384CC(int z);

public:
    u8 m_flags;
    u8 m_frame;
    CPrimitiveRECT *m_rect;
    CSoftwareSprite *m_sprite;
    UnkClass_0201AAE0 *m_res;
};

STATIC_SIZE_ASSERT(UnkClass_021382D0, 0x10);

#endif // POKERANGER2_BATTLE_UNKCLASS_021382D0_HPP
