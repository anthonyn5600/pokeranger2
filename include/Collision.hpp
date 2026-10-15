#ifndef POKERANGER2_COLLISION_HPP
#define POKERANGER2_COLLISION_HPP

#include <nitro.h>

#include "fx_utils.hpp"

struct Point2D {
    fx32 x;
    fx32 y;

    inline int DistSqTo(const Point2D &o) const
    {
        int dy = (y - o.y) >> FX32_SHIFT;
        int dx = (x - o.x) >> FX32_SHIFT;
        return dx * dx + dy * dy;
    }

    inline Point2D operator+(Point2D other) const
    {
        return (Point2D) {
            .x = x + other.x,
            .y = y + other.y,
        };
    }

    // Both overloads are needed for matching: mwcc doesn't CSE or forward a read through the const `this`
    // with plain reads of the same field (Attribute::Sweep needs that, SegmentHitCircle and Collision::CollideFine
    // must not have it).
    inline Point2D operator-(Point2D other)
    {
        return (Point2D) {
            .x = x - other.x,
            .y = y - other.y,
        };
    }

    inline Point2D operator-(Point2D other) const
    {
        return (Point2D) {
            .x = x - other.x,
            .y = y - other.y,
        };
    }

    inline Point2D &operator+=(Point2D other)
    {
        x += other.x;
        y += other.y;

        return *this;
    }

    inline Point2D &operator-=(Point2D other)
    {
        x -= other.x;
        y -= other.y;

        return *this;
    }

    inline Point2D operator*(fx64 other) const
    {
        return (Point2D) {
            .x = FX32_MUL(x, other),
            .y = FX32_MUL(y, other),
        };
    }

    inline Point2D &operator*=(fx32 other)
    {
        x = FX32_MUL(x, other);
        y = FX32_MUL(y, other);

        return *this;
    }

    inline Point2D operator/(fx32 other) const
    {
        return (Point2D) {
            .x = FX32_DIV(x, other),
            .y = FX32_DIV(y, other),
        };
    }

    inline Point2D &operator/=(fx32 other)
    {
        x = FX32_DIV(x, other);
        y = FX32_DIV(y, other);

        return *this;
    }
};

struct PointPair2D {
    Point2D p1;
    Point2D p2;
};

struct Rectangle {
    Point2D pos;
    Point2D size;
};

struct Circle {
    Point2D pos;
    fx32 r;
};

struct Sector {
    Point2D pos;
    fx32 unk_08;
    u32 unk_0C;
    u32 unk_10;
};

// TODO: Make sure those function signatures are correct
BOOL PointInRect(Point2D arg0, Rectangle arg1, u32 arg2);
BOOL PointInCircle(Point2D arg0, Circle arg1);
BOOL CircleHitCircle(Circle arg0, Circle arg1, Point2D *arg2);
BOOL CircleInSector(Circle arg0, Sector arg1);
BOOL SegmentHitSegment(PointPair2D arg0, PointPair2D arg1, Point2D *arg2, BOOL arg3);
BOOL SegmentHitSegmentBBox(PointPair2D arg0, PointPair2D arg1, Point2D *arg2);
BOOL SegmentHitCircle(PointPair2D arg0, Circle arg1, Point2D *arg2, s32 arg3);
s8 SideOfLine(PointPair2D arg0, Point2D arg1);
BOOL SegmentHitRect(PointPair2D arg0, Rectangle arg1, Point2D *arg2);
BOOL CircleHitRectEdge(Circle arg0, Rectangle arg1, Point2D *arg2, s32 arg3);
BOOL CircleHitRect(Circle arg0, Rectangle arg1);
// TODO: End

BOOL RectanglesOverlap(Rectangle rect1, Rectangle rect2);

#endif // POKERANGER2_COLLISION_HPP
