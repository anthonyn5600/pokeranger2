#ifndef POKERANGER2_FIELD_FIELDPOINTMOVER_HPP
#define POKERANGER2_FIELD_FIELDPOINTMOVER_HPP

#include <nitro.h>

#include "sub_02006000.hpp"

// Moves a point linearly from `from` to `to` over `duration` frames (ov0 DarkCloud, DarkShadow).
struct FieldPointMover {
    FieldPointMover()
    {
        duration = 0;
        frame = 0;
        active = FALSE;
    }

    void Start(const Point2D &start, const Point2D &end, int frames)
    {
        from.x = start.x;
        from.y = start.y;
        to.x = end.x;
        to.y = end.y;
        duration = frames;
        active = TRUE;
        cur.x = from.x;
        cur.y = from.y;
        frame = 0;
    }

    BOOL Update(int dt)
    {
        if (!active) {
            return FALSE;
        }
        frame += dt;
        fx32 t;
        if (duration <= 0) {
            t = FX32_ONE;
        } else if (frame >= duration) {
            t = FX32_ONE;
        } else {
            t = (frame << 12) / duration;
        }
        cur.x = from.x + FX32_MUL(t, to.x - from.x);
        cur.y = from.y + FX32_MUL(t, to.y - from.y);
        if (frame >= duration) {
            active = FALSE;
        }
        return TRUE;
    }

    Point2D from;
    Point2D to;
    Point2D cur;
    int duration;
    int frame;
    BOOL active;
};

#endif // POKERANGER2_FIELD_FIELDPOINTMOVER_HPP
