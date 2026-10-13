#include "primitive/CPrimitiveSPHERE.hpp"

#include <nitro.h>

#include "Camera2D.hpp"
#include "fx_utils.hpp"

CPrimitiveSPHERE::CPrimitiveSPHERE()
{
    MI_CpuFill8(&m_circle, 0, sizeof(m_circle));
}

CPrimitiveSPHERE::~CPrimitiveSPHERE()
{
}

u32 CPrimitiveSPHERE::Render(Camera2D *camera)
{
    u16 shift = camera->unk_28;
    u32 numTriangles = 8;
    u16 angle = 0;

    G3_TexImageParam(GX_TEXFMT_NONE, GX_TEXGEN_TEXCOORD, GX_TEXSIZE_S8, GX_TEXSIZE_T8, GX_TEXREPEAT_NONE, GX_TEXFLIP_NONE, GX_TEXPLTTCOLOR0_USE, 0);
    G3_PolygonAttr(GX_LIGHTMASK_NONE, m_polygonMode, GX_CULL_NONE, m_polygonID, m_alpha, GX_POLYGON_ATTR_MISC_NONE);

    G3_Begin(GX_BEGIN_TRIANGLES);
    G3_Color(m_color);

    // The circle is a fan of triangles (center, edge point, next edge point), going clockwise
    for (u8 i = 0; i < numTriangles; i++) {
        G3_Vtx((m_circle.pos.x >> FX32_SHIFT) << shift, (m_circle.pos.y >> FX32_SHIFT) << shift, m_z);
        G3_VtxXY(((m_circle.pos.x + FX32_MUL(m_circle.r, FX_CosIdx(angle))) >> FX32_SHIFT) << shift, ((m_circle.pos.y + FX32_MUL(m_circle.r, FX_SinIdx(angle))) >> FX32_SHIFT) << shift);

        // 0x10000 / numTriangles; MATH_CTZ's inline asm (clz) keeps the optimizer (IRO) off this whole function
        angle -= 0x10000 >> MATH_CTZ(numTriangles);
        angle &= 0xFFFF;

        G3_VtxXY(((m_circle.pos.x + FX32_MUL(m_circle.r, FX_CosIdx(angle))) >> FX32_SHIFT) << shift, ((m_circle.pos.y + FX32_MUL(m_circle.r, FX_SinIdx(angle))) >> FX32_SHIFT) << shift);
    }

    G3_End();
    G3_PopMtx(0);

    return numTriangles;
}
