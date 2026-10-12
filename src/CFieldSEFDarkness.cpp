#include <nitro.h>

#include "field/CFieldScreenEffect.hpp"
#include "fx_utils.hpp"

static inline fx32 Sin8(int angle)
{
    return FX32_MUL(FX_SinIdx((u16)angle), FX32_CONST(8));
}

static inline fx32 Cos8(int angle)
{
    return FX32_MUL(FX_CosIdx((u16)angle), FX32_CONST(8));
}

CFieldSEFDarkness::CFieldSEFDarkness(int type)
{
    m_type = type;
    Load();

    for (int i = 0; i < 16; i++) {
        m_quads[i].m_color = GX_RGB(0, 0, 0);
        m_quads[i].m_alpha = 0;
    }
    for (int i = 0; i < 3; i++) {
        m_angles[i] = i * 0x300;
    }

    m_rect.m_color = GX_RGB(0, 0, 0);
    m_rect.m_alpha = 0;
    m_density = 10;
    m_rectDensity = 8;

    CFieldSEFFog::s_color[0] = 31;
    CFieldSEFFog::s_color[1] = 31;
    CFieldSEFFog::s_color[2] = 31;
    CFieldSEFFog::s_density = 31;
    CFieldSEFFog::s_dirty = FALSE;
}

int CFieldSEFDarkness::Update(int fps)
{
    if (m_releaseDelay != 0) {
        if (--m_releaseDelay == 0) {
            m_tex.ReleaseFiles();
        }
    }

    CFieldScreenEffectObjectBase::Update(fps);

    for (int i = 0; i < 16; i++) {
        if (CFieldSEFFog::s_dirty) {
            m_quads[i].m_color = GX_RGB(CFieldSEFFog::s_color[0], CFieldSEFFog::s_color[1], CFieldSEFFog::s_color[2]);
            m_density = CFieldSEFFog::s_density;
            CFieldSEFFog::s_dirty = FALSE;
        }

        switch (m_state) {
        case STATE_FADE_IN:
            m_quads[i].m_alpha = (m_density * m_alpha) >> FX32_SHIFT;
            break;
        case STATE_SHOWN:
            m_quads[i].m_alpha = m_density;
            break;
        case STATE_FADE_OUT:
            m_quads[i].m_alpha = (m_density * m_alpha) >> FX32_SHIFT;
            break;
        default:
            m_quads[i].m_alpha = 0;
            break;
        }
    }

    switch (m_state) {
    case STATE_FADE_IN:
        m_rect.m_alpha = (m_rectDensity * m_alpha) >> FX32_SHIFT;
        break;
    case STATE_SHOWN:
        m_rect.m_alpha = m_rectDensity;
        break;
    case STATE_FADE_OUT:
        m_rect.m_alpha = (m_rectDensity * m_alpha) >> FX32_SHIFT;
        break;
    default:
        m_rect.m_alpha = 0;
        break;
    }

    return m_state;
}

void CFieldSEFDarkness::Draw(UnkClass_02003718 *camera)
{
    fx32 x;
    fx32 y;
    fx32 s;
    fx32 c;
    u16 a;

    if (m_quads[0].m_alpha == 0) {
        return;
    }

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            m_quads[row * 4 + col].m_polygonID = unk_1C;
            m_quads[row * 4 + col].m_vtx[0].x = m_quads[row * 4 + col].m_vtx[1].x = ((col * 64 - 96) << FX32_SHIFT) - FX32_CONST(32);
            m_quads[row * 4 + col].m_vtx[2].x = m_quads[row * 4 + col].m_vtx[3].x = ((col * 64 - 96) << FX32_SHIFT) + FX32_CONST(32);
            m_quads[row * 4 + col].m_vtx[0].y = m_quads[row * 4 + col].m_vtx[3].y = ((row * 48 - 72) << FX32_SHIFT) - FX32_CONST(24);
            m_quads[row * 4 + col].m_vtx[1].y = m_quads[row * 4 + col].m_vtx[2].y = ((row * 48 - 72) << FX32_SHIFT) + FX32_CONST(24);
            m_quads[row * 4 + col].m_tex[0].x = m_quads[row * 4 + col].m_tex[1].x = col * FX32_CONST(16);
            m_quads[row * 4 + col].m_tex[2].x = m_quads[row * 4 + col].m_tex[3].x = (col * 16 + 16) << FX32_SHIFT;
            m_quads[row * 4 + col].m_tex[0].y = m_quads[row * 4 + col].m_tex[3].y = row << 16;
            m_quads[row * 4 + col].m_tex[1].y = m_quads[row * 4 + col].m_tex[2].y = (row * 16 + 16) << FX32_SHIFT;
            m_tex.Bind();
        }
    }

    m_angles[0] += 0x800;
    m_angles[1] -= 0xC00;
    m_angles[2] -= 0x600;
    m_angles[0] = 0;
    m_angles[1] = 0;
    m_angles[2] = 0;

    a = m_angles[0];
    s = Sin8(a);
    c = Cos8(a);
    x = FX32_CONST(-96) - s;
    y = FX32_CONST(-72) - c;
    SetGridPoint(0, x, y);
    a = m_angles[2];
    s = Sin8(a);
    c = Cos8(a);
    x = FX32_CONST(-96) - s;
    y = c + FX32_CONST(72);
    SetGridPoint(8, x, y);
    a = m_angles[0] + 0x400;
    s = Sin8(a);
    c = Cos8(a);
    x = s + FX32_CONST(96);
    y = FX32_CONST(-72) - c;
    SetGridPoint(2, x, y);
    a = m_angles[1] + 0x800;
    s = Sin8(a);
    c = Cos8(a);
    x = s + FX32_CONST(96);
    y = c + FX32_CONST(72);
    SetGridPoint(10, x, y);
    a = m_angles[1] + 0x800;
    c = Cos8(a);
    x = 0;
    y = c - FX32_CONST(72);
    SetGridPoint(1, x, y);
    a = m_angles[2] + 0x600;
    c = Cos8(a);
    x = 0;
    y = FX32_CONST(72) - c;
    SetGridPoint(9, x, y);
    a = m_angles[0] + 0xC00;
    s = Sin8(a);
    x = s - FX32_CONST(96);
    y = 0;
    SetGridPoint(4, x, y);
    a = m_angles[1] + 0xA00;
    s = Sin8(a);
    x = FX32_CONST(96) - s;
    y = 0;
    SetGridPoint(6, x, y);

    SetupMatrix(camera);

    for (int i = 0; i < 16; i++) {
        CPrimitiveQuadNTF *quad = &m_quads[i];
        quad->Render((CPrimitive_Render_arg *)camera);
    }

    if (m_rect.m_alpha != 0) {
        CPrimitiveRectNTF *rect = &m_rect;

        rect->m_polygonID = unk_1C + 1;
        rect->SetRect(0, 0, FX32_CONST(260), FX32_CONST(200));
        m_rectTex.Bind();
        rect->Render((CPrimitive_Render_arg *)camera);
    }

    G3_PopMtx(0);
}

BOOL CFieldSEFDarkness::Load()
{
    m_tex.LoadDeferred("data/field/effect/dokarimo03.ntft", "data/field/effect/dokarimo03.ntfp", 4);
    m_releaseDelay = 2;
    return TRUE;
}

BOOL CFieldSEFDarkness::Unload()
{
    m_tex.Release();
    m_rectTex.Release();
    return TRUE;
}

void CFieldSEFDarkness::SetGridPoint(int index, fx32 x, fx32 y)
{
    m_quads[index].m_vtx[2].x = x;
    m_quads[index].m_vtx[2].y = y;
    m_quads[index + 1].m_vtx[1].x = x;
    m_quads[index + 1].m_vtx[1].y = y;
    m_quads[index + 4].m_vtx[3].x = x;
    m_quads[index + 4].m_vtx[3].y = y;
    m_quads[index + 5].m_vtx[0].x = x;
    m_quads[index + 5].m_vtx[0].y = y;
}

BOOL CFieldSEFDarkness::Start(int fadeIn, int hold, int fadeOut)
{
    BOOL result = CFieldScreenEffectObjectBase::Start(fadeIn, hold, fadeOut);
    for (int i = 0; i < 16; i++) {
        m_quads[i].m_alpha = (m_density * m_alpha) >> FX32_SHIFT;
    }
    m_rect.m_alpha = (m_rectDensity * m_alpha) >> FX32_SHIFT;
    return result;
}
