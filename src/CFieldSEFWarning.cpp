#include <nitro.h>

#include "field/CFieldScreenEffect.hpp"

CFieldSEFWarning::CFieldSEFWarning()
{
    Load();
    m_density = 16;
    m_rect.m_color = GX_RGB(31, 0, 0);
    m_rect.m_alpha = 0;

    GXRgb color = m_rect.m_color;
    int density = m_density;
    CFieldSEFFog::s_color[0] = color & 0x1F;
    CFieldSEFFog::s_color[1] = (color >> 5) & 0x1F;
    CFieldSEFFog::s_color[2] = (color >> 10) & 0x1F;
    CFieldSEFFog::s_density = density;
    CFieldSEFFog::s_dirty = FALSE;

    m_pulseTimer = 0;
    m_pulsePeriod = 30;
}

int CFieldSEFWarning::Update(int fps)
{
    CFieldScreenEffectObjectBase::Update(fps);

    if (CFieldSEFFog::s_dirty) {
        m_rect.m_color = GX_RGB(CFieldSEFFog::s_color[0], CFieldSEFFog::s_color[1], CFieldSEFFog::s_color[2]);
        m_density = CFieldSEFFog::s_density;
        CFieldSEFFog::s_dirty = FALSE;
    }

    if (m_state != STATE_FADE_IN && m_state != STATE_SHOWN && m_state != STATE_FADE_OUT) {
        m_rect.m_alpha = 0;
    }

    if (fps == 60) {
        m_pulseTimer++;
    } else {
        m_pulseTimer += 2;
    }
    if (m_pulseTimer >= m_pulsePeriod) {
        m_pulseTimer = 0;
    }

    int half = m_pulsePeriod / 2;
    fx32 t;
    if (m_pulseTimer < half) {
        t = (m_pulseTimer << FX32_SHIFT) / half;
    } else {
        t = ((m_pulsePeriod - m_pulseTimer) << FX32_SHIFT) / half;
    }
    m_rect.m_alpha = (m_density * t) >> FX32_SHIFT;

    return m_state;
}

void CFieldSEFWarning::Draw(UnkClass_02003718 *camera)
{
    if (m_rect.m_alpha == 0) {
        return;
    }

    SetupMatrix(camera);

    CPrimitiveRectNTF *rect = &m_rect;

    rect->m_polygonID = unk_1C;
    rect->SetRect(0, 0, FX32_CONST(256), FX32_CONST(256));
    m_tex.Bind();
    G3_PolygonAttr(GX_LIGHTMASK_NONE, GX_POLYGONMODE_MODULATE, GX_CULL_NONE, unk_1C + 3, rect->m_alpha, GX_POLYGON_ATTR_MISC_NONE);
    rect->Render((CPrimitive_Render_arg *)camera);

    G3_PopMtx(0);
}

BOOL CFieldSEFWarning::Load()
{
    return TRUE;
}

BOOL CFieldSEFWarning::Unload()
{
    return TRUE;
}
