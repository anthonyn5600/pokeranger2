#include <nitro.h>

#include "field/CFieldScreenEffect.hpp"

static inline void DrawRay(CPrimitiveQuadNTF *quad, KomorebiRay *ray, fx32 alpha, UnkClass_02003718 *camera, fx32 x0, fx32 dx0, fx32 dy0, fx32 x1, fx32 dx1, fx32 dy1)
{
    fx32 len = ray->len;

    quad->m_alpha = (u16)((alpha * ray->alpha) >> FX32_SHIFT);
    quad->m_color = ray->color;
    quad->m_vtx[0].x = x0;
    quad->m_vtx[0].y = -FX32_CONST(96);
    quad->m_vtx[1].x = x0 + FX32_MUL(len, dx0);
    quad->m_vtx[1].y = -FX32_CONST(96) + FX32_MUL(len, dy0);
    quad->m_vtx[2].x = x1 + FX32_MUL(len, dx1);
    quad->m_vtx[2].y = -FX32_CONST(96) + FX32_MUL(len, dy1);
    quad->m_vtx[3].x = x1;
    quad->m_vtx[3].y = -FX32_CONST(96);
    quad->Render((CPrimitive_Render_arg *)camera);
}

CFieldSEFKomorebi::CFieldSEFKomorebi()
{
    Load();
    unk_20 = 0x1F;
}

CFieldSEFKomorebi::~CFieldSEFKomorebi()
{
    Unload();
}

int CFieldSEFKomorebi::Update(int fps)
{
    if (m_releaseDelay != 0) {
        if (--m_releaseDelay == 0) {
            m_tex.ReleaseFiles();
        }
    }

    CFieldScreenEffectObjectBase::Update(fps);

    for (int i = 0; i < 9; i++) {
        m_rays[i].angle += m_rays[i].speed;
        m_rays[i].alpha = (MATH_ABS(FX_CosIdx(m_rays[i].angle) * 16) >> FX32_SHIFT) + 15;
        m_rays[i].len = FX32_CONST(1.5) - MATH_ABS(FX_CosIdx(m_rays[i].angle));
    }

    switch (m_state) {
    case STATE_FADE_IN:
        m_drawAlpha = m_alpha;
        break;
    case STATE_SHOWN:
        m_drawAlpha = FX32_ONE;
        break;
    case STATE_FADE_OUT:
        m_drawAlpha = m_alpha;
        break;
    default:
        m_drawAlpha = 0;
        break;
    }

    return m_state;
}

void CFieldSEFKomorebi::Draw(UnkClass_02003718 *camera)
{
    if (m_drawAlpha == 0) {
        return;
    }

    SetupMatrix(camera);

    m_quad.m_polygonID = unk_1C;
    m_quad.m_tex[0].x = m_quad.m_tex[1].x = 0;
    m_quad.m_tex[2].x = m_quad.m_tex[3].x = FX32_CONST(32);
    m_quad.m_tex[0].y = m_quad.m_tex[3].y = 0;
    m_quad.m_tex[1].y = m_quad.m_tex[2].y = FX32_CONST(32);
    m_tex.Bind();

    DrawRay(&m_quad, &m_rays[0], m_drawAlpha, camera, -FX32_CONST(25), 0, FX32_CONST(96), FX32_CONST(25), 0, FX32_CONST(96));
    DrawRay(&m_quad, &m_rays[1], m_drawAlpha, camera, -FX32_CONST(75), -FX32_CONST(10), FX32_CONST(88), -FX32_CONST(25), 0, FX32_CONST(96));
    DrawRay(&m_quad, &m_rays[2], m_drawAlpha, camera, -FX32_CONST(125), -FX32_CONST(20), FX32_CONST(80), -FX32_CONST(75), -FX32_CONST(10), FX32_CONST(88));
    DrawRay(&m_quad, &m_rays[3], m_drawAlpha, camera, FX32_CONST(25), 0, FX32_CONST(96), FX32_CONST(75), FX32_CONST(10), FX32_CONST(88));
    DrawRay(&m_quad, &m_rays[4], m_drawAlpha, camera, FX32_CONST(75), FX32_CONST(10), FX32_CONST(88), FX32_CONST(125), FX32_CONST(20), FX32_CONST(80));

    m_quad.m_polygonID = unk_1C + 1;

    DrawRay(&m_quad, &m_rays[5], m_drawAlpha, camera, -FX32_CONST(50), -FX32_CONST(5), FX32_CONST(92), 0, 0, FX32_CONST(96));
    DrawRay(&m_quad, &m_rays[6], m_drawAlpha, camera, -FX32_CONST(100), -FX32_CONST(15), FX32_CONST(84), -FX32_CONST(50), -FX32_CONST(5), FX32_CONST(92));
    DrawRay(&m_quad, &m_rays[7], m_drawAlpha, camera, 0, 0, FX32_CONST(96), FX32_CONST(50), FX32_CONST(5), FX32_CONST(92));
    DrawRay(&m_quad, &m_rays[8], m_drawAlpha, camera, FX32_CONST(50), FX32_CONST(5), FX32_CONST(92), FX32_CONST(100), FX32_CONST(15), FX32_CONST(84));

    G3_PopMtx(0);
}

BOOL CFieldSEFKomorebi::Load()
{
    m_tex.LoadDeferred("data/field/effect/komorebi.ntft", "data/field/effect/komorebi.ntfp", 3);
    m_releaseDelay = 2;

    m_rays[0].angle = 0;
    m_rays[0].speed = 0xC0;
    m_rays[0].color = 0x53FF;
    m_rays[1].angle = 0;
    m_rays[1].speed = 0x120;
    m_rays[1].color = 0x73FA;
    m_rays[2].angle = 0;
    m_rays[2].speed = 0x180;
    m_rays[2].color = 0x631F;
    m_rays[3].angle = 0;
    m_rays[3].speed = 0xC0;
    m_rays[3].color = 0x73FA;
    m_rays[4].angle = 0;
    m_rays[4].speed = 0x180;
    m_rays[4].color = 0x631F;
    m_rays[5].angle = 0x2000;
    m_rays[5].speed = 0x120;
    m_rays[5].color = 0x53FF;
    m_rays[6].angle = 0x4000;
    m_rays[6].speed = 0x120;
    m_rays[6].color = 0x53FF;
    m_rays[7].angle = 0x2000;
    m_rays[7].speed = 0xC0;
    m_rays[7].color = 0x53FF;
    m_rays[8].angle = 0x4000;
    m_rays[8].speed = 0x120;
    m_rays[8].color = 0x53FF;
    return TRUE;
}

BOOL CFieldSEFKomorebi::Unload()
{
    m_tex.Release();
    return TRUE;
}

void CFieldSEFKomorebi::sub_02037330(int arg)
{
    m_drawAlpha = m_alpha;
}

BOOL CFieldSEFKomorebi::Start(int fadeIn, int hold, int fadeOut)
{
    BOOL result = CFieldScreenEffectObjectBase::Start(fadeIn, hold, fadeOut);
    m_drawAlpha = 0;
    return result;
}
