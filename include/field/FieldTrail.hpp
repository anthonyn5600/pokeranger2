#ifndef POKERANGER2_FIELD_FIELDTRAIL_HPP
#define POKERANGER2_FIELD_FIELDTRAIL_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "fx_utils.hpp"

// Recent cells an actor walked through (newest first) and where its partner stood then.
struct FieldTrail {
    Point2D pos[6];
    Point2D partner[6];
    int count;

    inline Point2D GetPartner(int i)
    {
        return partner[i];
    }

    // The partner position closest to `pos` (the last of equally close ones).
    inline Point2D GetNearestPartner(Point2D pos)
    {
        int best = 0;
        fx32 bestDist = 0x7FFFFFFF;
        for (int i = 0; i < count; i++) {
            Point2D diff = partner[i] - pos;
            fx32 dist = FX32_MUL(diff.x, diff.x) + FX32_MUL(diff.y, diff.y);
            if (dist <= bestDist) {
                best = i;
                bestDist = dist;
            }
        }
        return partner[best];
    }
};

#endif // POKERANGER2_FIELD_FIELDTRAIL_HPP
