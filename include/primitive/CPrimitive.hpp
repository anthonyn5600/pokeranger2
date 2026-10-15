#ifndef POKERANGER2_PRIMITIVE_CPRIMITIVE_HPP
#define POKERANGER2_PRIMITIVE_CPRIMITIVE_HPP

#include <nitro.h>
#include <nnsys.h>

class Camera2D;

// TODO: Figure out what this is
class UnkClass_CPrimitive_ImageProxy {
public:
#ifdef PC_PORT
    u8 unk_00[2 * sizeof(void *)]; // the two pointers in front of VramImage::unk_08 (src/pc/LayoutChecks.cpp)
#else
    u8 unk_00[0x8];
#endif
    NNSG2dImageProxy imageProxy;
};

// TODO: Figure out what this is
class UnkClass_CPrimitive_ImagePaletteProxy {
public:
#ifdef PC_PORT
    u8 unk_00[2 * sizeof(void *)]; // the two pointers in front of VramPalette::unk_08 (src/pc/LayoutChecks.cpp)
#else
    u8 unk_00[0x8];
#endif
    NNSG2dImagePaletteProxy imagePlttProxy;
};

class CPrimitive {
public:
    CPrimitive();
    virtual ~CPrimitive();

    virtual u32 Render(Camera2D *camera) = 0;

public:
    struct CoordinatesPair2D {
        fx32 x1;
        fx32 y1;
        fx32 x2;
        fx32 y2;
    };

    fx32 m_z;
    GXRgb m_color;
    GXPolygonMode m_polygonMode;
    int m_polygonID;
    int m_alpha;
};

#endif // POKERANGER2_PRIMITIVE_CPRIMITIVE_HPP
