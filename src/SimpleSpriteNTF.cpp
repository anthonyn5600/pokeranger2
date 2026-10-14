#include "Camera2D.hpp"
#include "field/CSimpleSpriteNTF.hpp"

void NtfTextureParam::Bind(GXTexPlttColor0 plttColor0, GXTexGen texGen)
{
    G3_TexImageParam(m_texFmt, texGen, m_sizeS, m_sizeT, GX_TEXREPEAT_NONE, GX_TEXFLIP_NONE, plttColor0, m_texAddr);
    G3_TexPlttBase(m_plttAddr, m_texFmt);
}

u32 CSimpleSpriteNTF::Render(Camera2D *camera)
{
    if (m_alpha == 0) {
        return 0;
    }

    SetRect(m_coords[0], m_coords[1], unk_4C, unk_50);
    BindTexture();

    u16 shift = camera->unk_28;
    fx32 x = FX_Whole(m_coords[0]) << shift;
    fx32 y = FX_Whole(m_coords[1]) << shift;

    G3_RestoreMtx(0);
    if (m_rotAngle != 0 || m_scale[0] != FX32_ONE || m_scale[1] != FX32_ONE) {
        G3_Translate(x, y, 0);
        if (m_rotAngle != 0) {
            MtxFx33 mtx;
            MTX_RotZ33(&mtx, FX_SinIdx(m_rotAngle), FX_CosIdx(m_rotAngle));
            G3_MultMtx33(&mtx);
        }
        if (m_scale[0] != FX32_ONE || m_scale[1] != FX32_ONE) {
            G3_Scale(m_scale[0], m_scale[1], FX32_ONE);
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
        ((NtfTextureParam *)unk_18)->Bind(unk_58, GX_TEXGEN_NONE);
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
