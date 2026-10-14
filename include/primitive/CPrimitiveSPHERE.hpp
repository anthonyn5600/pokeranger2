#ifndef POKERANGER2_PRIMITIVE_CPRIMITIVESPHERE_HPP
#define POKERANGER2_PRIMITIVE_CPRIMITIVESPHERE_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "primitive/CPrimitive.hpp"

class CPrimitiveSPHERE : public CPrimitive {
public:
    CPrimitiveSPHERE();
    virtual ~CPrimitiveSPHERE();

    virtual u32 Render(Camera2D *camera);

    inline void SetCircle(Circle circle)
    {
        m_circle = circle;
    }

public:
    Circle m_circle;
};

#endif // POKERANGER2_PRIMITIVE_CPRIMITIVESPHERE_HPP
