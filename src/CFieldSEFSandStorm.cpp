#include <nitro.h>

#include "field/CFieldScreenEffect.hpp"
#include "fx_utils.hpp"

extern MATHRandContext16 MAIN_BSS_0210CEC8;

static inline fx32 RandSpeed(fx32 scale)
{
    return FX32_MUL((MATH_Rand16(&MAIN_BSS_0210CEC8, 8) + 1) << FX32_SHIFT, scale);
}

CFieldSEFSandStorm::CFieldSEFSandStorm()
{
    Load();
    m_rect.m_color = GX_RGB(30, 30, 12);
    m_rect.m_alpha = 0;
    m_density = 22;
    m_frame = 0;

    GXRgb color = m_rect.m_color;
    int density = m_density;
    CFieldSEFFog::s_color[0] = color & 0x1F;
    CFieldSEFFog::s_color[1] = (color >> 5) & 0x1F;
    CFieldSEFFog::s_color[2] = (color >> 10) & 0x1F;
    CFieldSEFFog::s_density = density;
    CFieldSEFFog::s_dirty = FALSE;

    for (int i = 0; i < 2; i++) {
        SandStormLayer *layer = &m_layers[i];
        layer->s = 0;
        layer->t = 0;
    }

    m_layers[0].ds = (fx32)(0.1 * FX32_ONE);
    m_layers[0].dt = (fx32)(0.02 * FX32_ONE);
    m_layers[1].ds = (fx32)(-0.05 * FX32_ONE);
    m_layers[1].dt = (fx32)(-0.01 * FX32_ONE);
}

int CFieldSEFSandStorm::Update(int fps)
{
    m_frame++;

    if (m_releaseDelay != 0) {
        if (--m_releaseDelay == 0) {
            m_tex[0].ReleaseFiles();
            m_tex[1].ReleaseFiles();
        }
    }

    for (int i = 0; i < 2; i++) {
        SandStormLayer *layer = &m_layers[i];

        layer->s -= layer->ds * s_frameStep + FX32_MUL(s_scroll.x, FX32_ONE);
        layer->s &= 0xFFFFF;
        layer->t -= layer->dt * s_frameStep + FX32_MUL(s_scroll.y, FX32_ONE);
        layer->t &= 0xFFFFF;

        if ((m_frame & 1) == 0) {
            if (layer->ds > 0) {
                layer->ds = RandSpeed(FX32_CONST(0.4));
                layer->ds *= -1;
            } else {
                layer->ds = RandSpeed(FX32_CONST(0.4));
            }
            if (layer->dt < 0) {
                layer->dt = RandSpeed(FX32_CONST(0.2));
                layer->dt *= -1;
            } else {
                layer->dt = RandSpeed(FX32_CONST(0.2));
            }
        }
    }

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

void CFieldSEFSandStorm::Draw(Camera2D *camera)
{
    if (m_rect.m_alpha == 0) {
        return;
    }

    SetupMatrix(camera);

    CPrimitiveRectNTF *rect = &m_rect;

    rect->m_polygonID = unk_1C;
    rect->SetRect(0, 0, FX32_CONST(256), FX32_CONST(256));
    rect->SetTexCoords(m_layers[0].s, m_layers[0].t, m_layers[0].s + FX32_CONST(255), m_layers[0].t + FX32_CONST(255));
    m_tex[0].Bind();
    rect->Render(camera);

    rect->m_polygonID = unk_1C + 1;
    rect->SetRect(0, 0, FX32_CONST(256), FX32_CONST(256));
    rect->SetTexCoords(m_layers[1].s, m_layers[1].t, m_layers[1].s + FX32_CONST(255), m_layers[1].t + FX32_CONST(255));
    m_tex[1].Bind();
    rect->Render(camera);

    G3_PopMtx(0);
}

BOOL CFieldSEFSandStorm::Load()
{
    m_tex[0].LoadDeferred("data/field/effect/suna01.ntft", "data/field/effect/suna01.ntfp", 2);
    m_tex[1].LoadDeferred("data/field/effect/suna01.ntft", "data/field/effect/suna01.ntfp", 2);
    m_releaseDelay = 2;
    return TRUE;
}

BOOL CFieldSEFSandStorm::Unload()
{
    m_tex[0].Release();
    m_tex[1].Release();
    return TRUE;
}

BOOL CFieldSEFSandStorm::Start(int fadeIn, int hold, int fadeOut)
{
    BOOL result = CFieldScreenEffectObjectBase::Start(fadeIn, hold, fadeOut);
    m_rect.m_alpha = (m_density * m_alpha) >> FX32_SHIFT;
    return result;
}
