#include <nitro.h>

#include "Camera2D.hpp"
#include "common.hpp"
#include "scene/COPDScreen.hpp"

COPDScreenMeshNTF::~COPDScreenMeshNTF()
{
    ov3_02129C54();
}

void COPDScreenMeshNTF::ov3_02129AC0(int columns, int rows, fx32 x, fx32 y, fx32 s0, fx32 t0, fx32 s1, fx32 t1)
{
    unk_24 = columns;
    unk_26 = rows;
    unk_1C = new Point2D[(unk_24 + 1) * (unk_26 + 1)];
    unk_20 = new Point2D[(unk_24 + 1) * (unk_26 + 1)];
    Point2D *vtx = unk_1C;
    Point2D *tex = unk_20;
    for (int j = 0; j < unk_26 + 1; j++) {
        fx32 vy = y + j * 0xC0000 / unk_26;
        fx32 ty = t0 + j * (t1 - t0) / unk_26;
        for (int i = 0; i < unk_24 + 1; i++) {
            vtx->x = x + i * 0x100000 / unk_24;
            vtx->y = vy;
            tex->x = s0 + i * (s1 - s0) / unk_24;
            tex->y = ty;
            vtx++;
            tex++;
        }
    }
}

void COPDScreenMeshNTF::ov3_02129C54()
{
    if (unk_1C != NULL) {
        delete[] unk_1C;
        unk_1C = NULL;
    }
    if (unk_20 != NULL) {
        delete[] unk_20;
        unk_20 = NULL;
    }
}

u32 COPDScreenMeshNTF::Render(Camera2D *camera)
{
    Point2D *vtx;
    Point2D *tex;
    int j;
    int i;
    u16 cs;
    if (unk_18 != NULL) {
        ((UnkClass_02041D98 *)unk_18)->Bind(GX_TEXPLTTCOLOR0_USE, GX_TEXGEN_NONE);
    }
    G3_RestoreMtx(0);
    cs = camera->unk_28;
    G3_Color(m_color);
    G3_PolygonAttr(GX_LIGHTMASK_NONE, m_polygonMode, GX_CULL_NONE, m_polygonID, m_alpha, 0);
    vtx = unk_1C;
    tex = unk_20;
    for (j = 0; j < unk_26; j++) {
        G3_Begin(GX_BEGIN_QUAD_STRIP);
        for (i = 0; i < unk_24 + 1; i++) {
            G3_TexCoord(tex[0].x, tex[0].y);
            G3_Vtx(vtx[0].x >> (FX32_SHIFT - cs), vtx[0].y >> (FX32_SHIFT - cs), m_z);
            G3_TexCoord(tex[unk_24 + 1].x, tex[unk_24 + 1].y);
            G3_Vtx(vtx[unk_24 + 1].x >> (FX32_SHIFT - cs), vtx[unk_24 + 1].y >> (FX32_SHIFT - cs), m_z);
            vtx++;
            tex++;
        }
        G3_End();
    }
    G3_PopMtx(0);
    return 1;
}
