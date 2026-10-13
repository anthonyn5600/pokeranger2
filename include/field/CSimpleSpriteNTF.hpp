#ifndef POKERANGER2_FIELD_CSIMPLESPRITENTF_HPP
#define POKERANGER2_FIELD_CSIMPLESPRITENTF_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"
#include "field/CPrimitiveNTF.hpp"
#include "primitive/CPrimitive.hpp"

// Texture in texture VRAM with its own format fields
class UnkClass_02041D98 {
public:
    void Bind(GXTexPlttColor0 plttColor0, GXTexGen texGen);

public:
    NNSGfdTexKey m_texKey;
    NNSGfdPlttKey m_plttKey;
    u32 m_texAddr;
    u32 m_plttAddr;
    u8 unk_10[0xC];
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
        unk_54 = 0;
        unk_58 = GX_TEXPLTTCOLOR0_USE;
        unk_44 = unk_48 = FX32_ONE;
    }
    virtual ~CSimpleSpriteNTF();
    virtual u32 Render(Camera2D *camera);

    void BindTexture();

public:
    fx32 unk_3C;
    fx32 unk_40;
    fx32 unk_44;
    fx32 unk_48;
    fx32 unk_4C;
    fx32 unk_50;
    u16 unk_54;
    GXTexPlttColor0 unk_58;
};

class CSimplePrimitiveQuadNTF : public CPrimitive {
public:
    virtual ~CSimplePrimitiveQuadNTF();
    virtual u32 Render(Camera2D *camera);

public:
    UnkClass_02041D98 *unk_18;
    fx32 unk_1C;
    fx32 unk_20;
    Point2D m_vtx[4];
    Point2D m_tex[4];
};

STATIC_SIZE_ASSERT(UnkClass_02041D98, 0x28);
STATIC_SIZE_ASSERT(CSimpleSpriteNTF, 0x5C);
STATIC_SIZE_ASSERT(CSimplePrimitiveQuadNTF, 0x64);

#endif // POKERANGER2_FIELD_CSIMPLESPRITENTF_HPP
