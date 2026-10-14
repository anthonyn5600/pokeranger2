#ifndef POKERANGER2_FIELD_CSIMPLESPRITENTF_HPP
#define POKERANGER2_FIELD_CSIMPLESPRITENTF_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"
#include "field/CPrimitiveNTF.hpp"
#include "primitive/CPrimitive.hpp"

// NtfTexture with its texture parameters (what CSimpleSpriteNTF draws with)
class NtfTextureParam : public NtfTexture {
public:
    NtfTextureParam()
    {
        m_texFmt = GX_TEXFMT_NONE;
        m_sizeS = GX_TEXSIZE_S8;
        m_sizeT = GX_TEXSIZE_T8;
    }

    void Bind(GXTexPlttColor0 plttColor0, GXTexGen texGen);

public:
    GXTexFmt m_texFmt;
    GXTexSizeS m_sizeS;
    GXTexSizeT m_sizeT;
};

class CSimpleSpriteNTF : public CPrimitiveRectNTF {
public:
    CSimpleSpriteNTF()
    {
        unk_4C = 0;
        unk_50 = 0;
        m_rotAngle = 0;
        unk_58 = GX_TEXPLTTCOLOR0_USE;
        m_scale[0] = m_scale[1] = FX32_ONE;
    }
    virtual u32 Render(Camera2D *camera);

    void BindTexture();

    void SetScale(fx32 x, fx32 y)
    {
        m_scale[0] = x;
        m_scale[1] = y;
    }

public:
    fx32 m_coords[2];
    fx32 m_scale[2];
    fx32 unk_4C;
    fx32 unk_50;
    u16 m_rotAngle;
    GXTexPlttColor0 unk_58;
};

class CSimplePrimitiveQuadNTF : public CPrimitive {
public:
    CSimplePrimitiveQuadNTF()
    {
        unk_18 = NULL;
        unk_20 = 0;
        unk_1C = 0;
    }
    virtual u32 Render(Camera2D *camera);

public:
    NtfTextureParam *unk_18;
    fx32 unk_1C;
    fx32 unk_20;
    Point2D m_vtx[4];
    Point2D m_tex[4];
};

STATIC_SIZE_ASSERT(NtfTextureParam, 0x28);
STATIC_SIZE_ASSERT(CSimpleSpriteNTF, 0x5C);
STATIC_SIZE_ASSERT(CSimplePrimitiveQuadNTF, 0x64);

#endif // POKERANGER2_FIELD_CSIMPLESPRITENTF_HPP
