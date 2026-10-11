#include <nitro.h>

#include "field/CFieldScreenEffect.hpp"

static FogParam sFogParams[5] = {
    { GX_RGB(30, 30, 30), 24 },
    { GX_RGB(8, 8, 8), 14 },
    { GX_RGB(30, 0, 30), 16 },
    { GX_RGB(30, 30, 0), 24 },
    { GX_RGB(30, 30, 30), 8 },
};

CFieldSEFFog::CFieldSEFFog(int type)
{
    m_flickerTimer = 0;
    m_type = type;
    Load();
    m_rect.m_alpha = 0;

    switch (type) {
    case 4:
        m_rect.m_color = sFogParams[0].color;
        m_density = sFogParams[0].density;
        break;
    case 5:
        m_rect.m_color = sFogParams[1].color;
        m_density = sFogParams[1].density;
        break;
    case 6:
        m_rect.m_color = sFogParams[2].color;
        m_density = sFogParams[2].density;
        break;
    case 7:
        m_rect.m_color = sFogParams[3].color;
        m_density = sFogParams[3].density;
        break;
    case 16:
        m_rect.m_color = sFogParams[4].color;
        m_density = sFogParams[4].density;
        break;
    }

    GXRgb color = m_rect.m_color;
    int density = m_density;
    s_color[0] = color & 0x1F;
    s_color[1] = (color >> 5) & 0x1F;
    s_color[2] = (color >> 10) & 0x1F;
    s_density = density;
    s_dirty = FALSE;

    for (int i = 0; i < 2; i++) {
        m_s[i] = i * FX32_CONST(64);
        m_t[i] = i * FX32_CONST(48);
    }
}

int CFieldSEFFog::Update(int fps)
{
    if (m_releaseDelay != 0) {
        if (--m_releaseDelay == 0) {
            m_tex[0].ReleaseFiles();
            m_tex[1].ReleaseFiles();
        }
    }

    m_s[0] -= (fx32)(s_frameStep * 0.04f * 4096.0f) + FX32_MUL(s_scroll.x, FX32_HALF);
    m_s[1] -= -(fx32)(s_frameStep * 0.06f * 4096.0f) + FX32_MUL(s_scroll.x, FX32_HALF);
    m_s[0] &= 0xFFFFF;
    m_s[1] &= 0xFFFFF;
    m_t[0] -= FX32_MUL(s_scroll.y, FX32_HALF);
    m_t[1] -= FX32_MUL(s_scroll.y, FX32_HALF);
    m_t[0] &= 0xFFFFF;
    m_t[1] &= 0xFFFFF;

    CFieldScreenEffectObjectBase::Update(fps);

    if (s_dirty) {
        m_rect.m_color = GX_RGB(s_color[0], s_color[1], s_color[2]);
        m_density = s_density;
        s_dirty = FALSE;
    }

    switch (m_state) {
    case STATE_FADE_IN:
        m_rect.m_alpha = (m_density * m_alpha) >> FX32_SHIFT;
        break;
    case STATE_SHOWN:
        if (m_type == 5) {
            int t = ++m_flickerTimer >> 2;
            int flicker;
            if (t & 8) {
                flicker = 15 - (t & 15);
            } else {
                flicker = t & 15;
            }
            m_rect.m_alpha = m_density + flicker;
        } else {
            m_rect.m_alpha = m_density;
        }
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

void CFieldSEFFog::Draw(UnkClass_02003718 *camera)
{
    if (m_rect.m_alpha == 0) {
        return;
    }

    SetupMatrix(camera);

    CPrimitiveRectNTF *rect = &m_rect;

    rect->m_polygonID = unk_1C;
    rect->SetRect(0, 0, FX32_CONST(256), FX32_CONST(256));
    rect->SetTexCoords(m_s[0], m_t[0], m_s[0] + FX32_CONST(128), m_t[0] + FX32_CONST(128));
    m_tex[0].Bind();
    rect->Render((CPrimitive_Render_arg *)camera);

    rect->m_polygonID = unk_1C + 1;
    rect->SetRect(0, 0, FX32_CONST(256), FX32_CONST(256));
    rect->SetTexCoords(m_s[1], m_t[1], m_s[1] + FX32_CONST(128), m_t[1] + FX32_CONST(128));
    m_tex[1].Bind();
    rect->Render((CPrimitive_Render_arg *)camera);

    G3_PopMtx(0);
}

BOOL CFieldSEFFog::Load()
{
    m_tex[0].LoadDeferred("data/field/effect/kiri02.ntft", "data/field/effect/kiri02.ntfp", 2);
    m_tex[1].LoadDeferred("data/field/effect/kiri02.ntft", "data/field/effect/kiri02.ntfp", 2);
    m_releaseDelay = 2;
    return TRUE;
}

BOOL CFieldSEFFog::Unload()
{
    m_tex[0].Release();
    m_tex[1].Release();
    return TRUE;
}

BOOL CFieldSEFFog::Start(int fadeIn, int hold, int fadeOut)
{
    BOOL result = CFieldScreenEffectObjectBase::Start(fadeIn, hold, fadeOut);
    m_rect.m_alpha = (m_density * m_alpha) >> FX32_SHIFT;
    return result;
}
