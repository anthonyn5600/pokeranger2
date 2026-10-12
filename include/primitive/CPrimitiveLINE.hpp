#ifndef POKERANGER2_PRIMITIVE_CPRIMITIVELINE_HPP
#define POKERANGER2_PRIMITIVE_CPRIMITIVELINE_HPP

#include <nitro.h>

#include "primitive/CPrimitive.hpp"
#include "sub_02006000.hpp"

class CPrimitiveLINE : public CPrimitive {
public:
    CPrimitiveLINE();
    virtual ~CPrimitiveLINE();

    virtual u32 Render(Camera2D *camera);

    inline Point2D GetStart()
    {
        return m_points.p1;
    }
    inline Point2D GetEnd()
    {
        return m_points.p2;
    }
    inline void SetStart(Point2D pos)
    {
        m_points.p1.x = pos.x;
        m_points.p1.y = pos.y;
    }
    inline void SetEnd(Point2D pos)
    {
        m_points.p2.x = pos.x;
        m_points.p2.y = pos.y;
    }

public:
    PointPair2D m_points;
};

#endif // POKERANGER2_PRIMITIVE_CPRIMITIVELINE_HPP
