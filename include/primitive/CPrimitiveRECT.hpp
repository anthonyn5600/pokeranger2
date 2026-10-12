#ifndef POKERANGER2_PRIMITIVE_CPRIMITIVERECT_HPP
#define POKERANGER2_PRIMITIVE_CPRIMITIVERECT_HPP

#include <nitro.h>

#include "primitive/CPrimitive.hpp"
#include "sub_02006000.hpp"

class CPrimitiveRECT : public CPrimitive {
public:
    CPrimitiveRECT();
    virtual ~CPrimitiveRECT();

    virtual u32 Render(Camera2D *camera);

    void SetRectangle(fx32 x, fx32 y, fx32 w, fx32 h, fx32 z);
    u32 RenderWithTexture(Camera2D *camera);
    u32 RenderWithoutTexture(Camera2D *camera);

    static void sub_02003C00(Point2D *arg0, CPrimitiveRECT *arg1);

    inline void SetPos(Point2D pos)
    {
        m_rectangle.pos.x = pos.x;
        m_rectangle.pos.y = pos.y;
    }

    inline void SetPos(fx32 x, fx32 y)
    {
        m_rectangle.pos.x = x;
        m_rectangle.pos.y = y;
    }

    inline void SetTexCoords(fx32 x1, fx32 y1, fx32 x2, fx32 y2)
    {
        m_texCoords.x1 = x1;
        m_texCoords.y1 = y1;
        m_texCoords.x2 = x2;
        m_texCoords.y2 = y2;
    }

public:
    Rectangle m_rectangle;
    CoordinatesPair2D m_texCoords;

    UnkClass_CPrimitive_ImageProxy *unk_38;
    UnkClass_CPrimitive_ImagePaletteProxy *unk_3C;
};

#endif // POKERANGER2_PRIMITIVE_CPRIMITIVERECT_HPP
