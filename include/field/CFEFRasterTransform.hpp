#ifndef POKERANGER2_FIELD_CFEFRASTERTRANSFORM_HPP
#define POKERANGER2_FIELD_CFEFRASTERTRANSFORM_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CSimpleSpriteNTF.hpp"
#include "primitive/CPrimitive.hpp"

// A textured quad strip whose rows scroll upward, each row's texture shifted sideways by a sine wave.
class CFEFRasterTransform : public CPrimitive {
public:
    CFEFRasterTransform()
    {
        m_width = 0;
        m_height = 0;
        m_tex = NULL;
        m_verts = NULL;
        m_texCoords = NULL;
        m_waves = NULL;
        m_rowHeight = 0;
        m_angle = 0;
        m_scroll = 0;
        m_texGen = FALSE;
        m_scale[1] = FX32_ONE;
        m_scale[0] = FX32_ONE;
    }
    virtual ~CFEFRasterTransform();
    virtual u32 Render(Camera2D *camera);

    void Setup(int rows, fx32 width, fx32 height, fx32 s1, fx32 t1, fx32 s2, fx32 t2);
    void Release();
    void Advance();

public:
    Point2D m_pos;
    fx32 m_scale[2];
    fx32 m_width;
    fx32 m_height;
    fx32 m_s1;
    fx32 m_t1;
    fx32 m_s2;
    fx32 m_t2;
    NtfTextureParam *m_tex;
    Point2D *m_verts;
    Point2D *m_texCoords;
    fx32 *m_waves;
    u8 m_head;
    u16 m_rows;
    fx32 m_rowHeight;
    u16 m_angle;
    fx32 m_scroll;
    u8 m_shifted;
    u8 m_texGen;
};

STATIC_SIZE_ASSERT(CFEFRasterTransform, 0x64);

#endif // POKERANGER2_FIELD_CFEFRASTERTRANSFORM_HPP
