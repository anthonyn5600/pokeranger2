#ifndef POKERANGER2_TOUCHDOTLINE_HPP
#define POKERANGER2_TOUCHDOTLINE_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"
#include "primitive/CSoftwareSprite.hpp"

class Camera2D;
class CNCERFile;
class VramImage;
class VramPalette;
class CellAnimController;

// Defined in ov0: dotted line from the player to the touch position (CFieldScene unk_00DC)
class TouchDotLine {
public:
    TouchDotLine();
    ~TouchDotLine();

public:
    CSoftwareSprite m_dot;
    CSoftwareSprite m_cursor;
    BOOL m_visible;
    CellAnimController *m_cac;
    Point2D m_start;
    Point2D m_end;
    Point2D m_dir;
    fx32 m_phase;
    u16 m_kind; // 0: right, 1: up, 2: left, 3: down
    u16 m_cacId;
    s8 m_alpha;
    s8 m_alphaStep;
};

STATIC_SIZE_ASSERT(TouchDotLine, 0xC4);

extern "C" {
void ov0_0214816C(TouchDotLine *obj, VramImage *ncbr, VramPalette *palette, CNCERFile *ncer, CellAnimController *cac);
void ov0_021481EC(TouchDotLine *obj, int fps);
void ov0_02148288(TouchDotLine *obj, Camera2D *camera);
void ov0_02148480(TouchDotLine *obj, Point2D *pos, Point2D *target);
}

#endif // POKERANGER2_TOUCHDOTLINE_HPP
