#include <nitro.h>

#include "field/CFieldScreenEffect.hpp"

CFieldSEFTheWater::CFieldSEFTheWater(int type)
{
    GXRgb color;

    Load();
    m_type = type;

    switch (type) {
    case 10:
        m_density = 16;
        color = GX_RGB(0, 31, 31);
        break;
    case 11:
        m_density = 10;
        color = GX_RGB(0, 0, 0);
        break;
    case 15:
        m_density = 10;
        color = GX_RGB(0, 0, 0);
        break;
    }

    m_rect.m_color = color;
    m_rect.m_alpha = 0;

    GXRgb c = m_rect.m_color;
    int density = m_density;
    CFieldSEFFog::s_color[0] = c & 0x1F;
    CFieldSEFFog::s_color[1] = (c >> 5) & 0x1F;
    CFieldSEFFog::s_color[2] = (c >> 10) & 0x1F;
    CFieldSEFFog::s_density = density;
    CFieldSEFFog::s_dirty = FALSE;
}

int CFieldSEFTheWater::Update(int fps)
{
    CFieldScreenEffectObjectBase::Update(fps);

    if (CFieldSEFFog::s_dirty) {
        m_rect.m_color = GX_RGB(CFieldSEFFog::s_color[0], CFieldSEFFog::s_color[1], CFieldSEFFog::s_color[2]);
        m_density = CFieldSEFFog::s_density;
        CFieldSEFFog::s_dirty = FALSE;
    }

    switch (m_state) {
    case STATE_FADE_IN:
        m_rect.m_alpha = (m_density * m_alpha) >> FX32_SHIFT;
        break;
    case STATE_SHOWN:
        m_rect.m_alpha = m_density;
        break;
    case STATE_FADE_OUT:
        m_rect.m_alpha = (m_density * m_alpha) >> FX32_SHIFT;
        break;
    default:
        m_rect.m_alpha = 0;
        break;
    }

    return m_state;
}

void CFieldSEFTheWater::Draw(UnkClass_02003718 *camera)
{
    if (m_rect.m_alpha == 0) {
        return;
    }

    SetupMatrix(camera);

    CPrimitiveRectNTF *rect = &m_rect;

    rect->m_polygonID = unk_1C;
    rect->SetRect(0, 0, FX32_CONST(256), FX32_CONST(256));
    m_tex.Bind();
    G3_PolygonAttr(GX_LIGHTMASK_NONE, GX_POLYGONMODE_MODULATE, GX_CULL_NONE, unk_1C + 3, rect->m_alpha, 0);
    rect->Render((CPrimitive_Render_arg *)camera);

    G3_PopMtx(0);
}

BOOL CFieldSEFTheWater::Load()
{
    return TRUE;
}

BOOL CFieldSEFTheWater::Unload()
{
    m_tex.Release();
    return TRUE;
}

BOOL CFieldSEFTheWater::Start(int fadeIn, int hold, int fadeOut)
{
    BOOL result = CFieldScreenEffectObjectBase::Start(fadeIn, hold, fadeOut);
    m_rect.m_alpha = (m_density * m_alpha) >> FX32_SHIFT;
    return result;
}
