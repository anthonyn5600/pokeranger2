#ifndef POKERANGER2_BATTLE_UNKCLASS_0212E88C_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0212E88C_HPP

#include <nitro.h>

#include "common.hpp"
#include "primitive/CPrimitiveLINE.hpp"
#include "primitive/CPrimitiveQUAD.hpp"
#include "sub_02006000.hpp"

class Camera2D;

// Defined in ov1: the fading capture line trail (a quad strip built around the disk's line segments)
class UnkClass_0212E88C {
public:
    UnkClass_0212E88C();
    ~UnkClass_0212E88C(); // ov1_0212E8FC
    void ov1_0212E940();
    void ov1_0212E998(Camera2D *camera);
    void ov1_0212EA1C(Point2D pos);
    void ov1_0212EA7C(Point2D pos);
    void ov1_0212EAD4();
    void ov1_0212EB20(fx32 width);
    int ov1_0212EDB4(int z);

public:
    u16 m_count;
    CPrimitiveLINE m_lines[0x62];
    CPrimitiveQUAD m_quads[0x62];
    fx32 m_width;
    u16 m_color;
    u16 m_timer;
};

STATIC_SIZE_ASSERT(UnkClass_0212E88C, 0x341C);

#endif // POKERANGER2_BATTLE_UNKCLASS_0212E88C_HPP
