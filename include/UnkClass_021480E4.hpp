#ifndef POKERANGER2_UNKCLASS_021480E4_HPP
#define POKERANGER2_UNKCLASS_021480E4_HPP

#include <nitro.h>

#include "common.hpp"
#include "primitive/CSoftwareSprite.hpp"
#include "sub_02006000.hpp"

class Camera2D;
class CNCERFile;
class UnkClass_020074D4;
class UnkClass_02007AA4;
class UnkClass_02008788;

// Defined in ov0: dotted line from the player to the touch position (CFieldScene unk_00DC)
class UnkClass_021480E4 {
public:
    UnkClass_021480E4();
    ~UnkClass_021480E4();

public:
    CSoftwareSprite m_dot;
    CSoftwareSprite m_cursor;
    BOOL m_visible;
    UnkClass_02008788 *m_cac;
    Point2D m_start;
    Point2D m_end;
    Point2D m_dir;
    fx32 m_phase;
    u16 m_kind; // 0: right, 1: up, 2: left, 3: down
    u16 m_cacId;
    s8 m_alpha;
    s8 m_alphaStep;
};

STATIC_SIZE_ASSERT(UnkClass_021480E4, 0xC4);

extern "C" {
void ov0_0214816C(UnkClass_021480E4 *obj, UnkClass_020074D4 *ncbr, UnkClass_02007AA4 *palette, CNCERFile *ncer, UnkClass_02008788 *cac);
void ov0_021481EC(UnkClass_021480E4 *obj, int fps);
void ov0_02148288(UnkClass_021480E4 *obj, Camera2D *camera);
void ov0_02148480(UnkClass_021480E4 *obj, Point2D *pos, Point2D *target);
}

#endif // POKERANGER2_UNKCLASS_021480E4_HPP
