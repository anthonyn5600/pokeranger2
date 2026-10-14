#ifndef POKERANGER2_BATTLE_CAPTURELINETRAIL_HPP
#define POKERANGER2_BATTLE_CAPTURELINETRAIL_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveLINE.hpp"
#include "primitive/CPrimitiveQUAD.hpp"

class Camera2D;

// Defined in ov1: the fading capture line trail (a quad strip built around the disk's line segments)
class CaptureLineTrail {
public:
    CaptureLineTrail();
    ~CaptureLineTrail(); // ov1_0212E8FC
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

STATIC_SIZE_ASSERT(CaptureLineTrail, 0x341C);

#endif // POKERANGER2_BATTLE_CAPTURELINETRAIL_HPP
