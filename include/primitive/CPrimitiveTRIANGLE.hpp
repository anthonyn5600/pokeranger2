#ifndef POKERANGER2_PRIMITIVE_CPRIMITIVETRIANGLE_HPP
#define POKERANGER2_PRIMITIVE_CPRIMITIVETRIANGLE_HPP

#include <nitro.h>

#include "primitive/CPrimitive.hpp"

class CPrimitiveTRIANGLE : public CPrimitive {
public:
    CPrimitiveTRIANGLE();
    virtual ~CPrimitiveTRIANGLE();

    virtual u32 Render(Camera2D *camera);

    u32 RenderWithTexture(Camera2D *camera);
    u32 RenderWithoutTexture(Camera2D *camera);

public:
    struct TriangleCoordinates {
        fx32 x1;
        fx32 y1;
        fx32 x2;
        fx32 y2;
        fx32 x3;
        fx32 y3;
    };

    TriangleCoordinates m_vtxCoords;
    TriangleCoordinates m_texCoords;

    UnkClass_CPrimitive_ImageProxy *unk_48;
    UnkClass_CPrimitive_ImagePaletteProxy *unk_4C;
};

#endif // POKERANGER2_PRIMITIVE_CPRIMITIVETRIANGLE_HPP
