#include "Camera2D.hpp"
#include "field/CSimpleSpriteNTF.hpp"

void UnkClass_02041D98::Bind(GXTexPlttColor0 plttColor0, GXTexGen texGen)
{
    G3_TexImageParam(m_texFmt, texGen, m_sizeS, m_sizeT, GX_TEXREPEAT_NONE, GX_TEXFLIP_NONE, plttColor0, m_texAddr);
    G3_TexPlttBase(m_plttAddr, m_texFmt);
}

u32 CSimpleSpriteNTF::Render(Camera2D *camera)
{
    if (m_alpha == 0) {
        return 0;
    }

    SetRect(unk_3C, unk_40, unk_4C, unk_50);
    BindTexture();

    u16 shift = camera->unk_28;
    fx32 x = FX_Whole(unk_3C) << shift;
    fx32 y = FX_Whole(unk_40) << shift;

    G3_RestoreMtx(0);
    if (unk_54 != 0 || unk_44 != FX32_ONE || unk_48 != FX32_ONE) {
        G3_Translate(x, y, 0);
        if (unk_54 != 0) {
            MtxFx33 mtx;
            MTX_RotZ33(&mtx, FX_SinIdx(unk_54), FX_CosIdx(unk_54));
            G3_MultMtx33(&mtx);
        }
        if (unk_44 != FX32_ONE || unk_48 != FX32_ONE) {
            G3_Scale(unk_44, unk_48, FX32_ONE);
        }
        G3_Translate(-x, -y, 0);
    }

    u32 ret = CPrimitiveRectNTF::Render(camera);
    G3_PopMtx(0);
    return ret;
}

void CSimpleSpriteNTF::BindTexture()
{
    if (unk_18 != NULL) {
        ((UnkClass_02041D98 *)unk_18)->Bind(unk_58, GX_TEXGEN_NONE);
    }
}

u32 CSimplePrimitiveQuadNTF::Render(Camera2D *camera)
{
    if (unk_18 != NULL) {
        unk_18->Bind(GX_TEXPLTTCOLOR0_USE, GX_TEXGEN_NONE);
    }

    int i;
    G3_RestoreMtx(0);
    int shift = FX32_SHIFT - camera->unk_28;
    G3_Color(m_color);
    G3_PolygonAttr(GX_LIGHTMASK_NONE, m_polygonMode, GX_CULL_NONE, m_polygonID, m_alpha, GX_POLYGON_ATTR_MISC_NONE);
    G3_Translate(unk_1C >> shift, unk_20 >> shift, 0);
    G3_Begin(GX_BEGIN_QUADS);

    for (i = 0; i < 4; i++) {
        G3_TexCoord(m_tex[i].x, m_tex[i].y);
        G3_Vtx(m_vtx[i].x >> shift, m_vtx[i].y >> shift, m_z);
    }

    G3_End();
    G3_PopMtx(0);
    return 1;
}
