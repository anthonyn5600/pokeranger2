#include <nitro.h>

#include "field/CFieldScreenEffect.hpp"
#include "fx_utils.hpp"

extern MATHRandContext16 MAIN_BSS_0210CEC8;

static fx32 sSnowSpeeds[3] = {
    (fx32)(0.3 * FX32_ONE),
    (fx32)(0.5 * FX32_ONE),
    (fx32)(0.7 * FX32_ONE),
};

CFieldSEFSnow::CFieldSEFSnow()
{
    Load();
    m_rect.m_color = GX_RGB(16, 16, 31);
    m_rect.m_alpha = 0;
    m_density = 12;

    GXRgb color = m_rect.m_color;
    int density = m_density;
    CFieldSEFFog::s_color[0] = color & 0x1F;
    CFieldSEFFog::s_color[1] = (color >> 5) & 0x1F;
    CFieldSEFFog::s_color[2] = (color >> 10) & 0x1F;
    CFieldSEFFog::s_density = density;
    CFieldSEFFog::s_dirty = FALSE;
}

int CFieldSEFSnow::Update(int fps)
{
    CFieldScreenEffectObjectBase::Update(fps);

    if (CFieldSEFFog::s_dirty) {
        m_rect.m_color = GX_RGB(CFieldSEFFog::s_color[0], CFieldSEFFog::s_color[1], CFieldSEFFog::s_color[2]);
        m_density = CFieldSEFFog::s_density;
        CFieldSEFFog::s_dirty = FALSE;
    }

    m_actorData->Update();

    for (int i = 0; i < 32; i++) {
        SnowFlake *flake = &m_flakes[i];
        flake->phase += s_frameStep;

        if (flake->pos.x < 0) {
            flake->pos.x += FX32_CONST(320);
        } else if (flake->pos.x > FX32_CONST(320)) {
            flake->pos.x -= FX32_CONST(320);
        }

        flake->pos.y += FX32_MUL(flake->vel.y * s_frameStep, FX32_ONE);
        if (flake->pos.y < 0) {
            flake->pos.y += FX32_CONST(256);
        } else if (flake->pos.y > FX32_CONST(256)) {
            flake->pos.y -= FX32_CONST(256);
            flake->pos.x = flake->basePos.x + (MATH_Rand16(&MAIN_BSS_0210CEC8, 64) << FX32_SHIFT);
            flake->vel.y = flake->baseVel.y = sSnowSpeeds[flake->type];
        }

        flake->pos.x += s_scroll.x;
        flake->pos.y += s_scroll.y;
        flake->angle += s_frameStep << 8;

        if (flake->timer-- == 0) {
            flake->timer = MATH_Rand16(&MAIN_BSS_0210CEC8, 10) + 10;
            fx32 scale = FX32_MUL(MATH_Rand16(&MAIN_BSS_0210CEC8, 12) << FX32_SHIFT, (fx32)(0.05 * FX32_ONE)) + FX32_CONST(0.7);
            flake->vel.x = FX32_MUL(flake->baseVel.x, scale);
            flake->vel.y = FX32_MUL(flake->baseVel.y, scale);
        }
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

void CFieldSEFSnow::Draw(Camera2D *camera)
{
    UnkClass_02008788 *cac = m_actorData->GetCac(0);
    Point2D offset = camera->GetOffsetCopy();
    int i;
    SnowFlake *flake;
    int alpha;

    switch (m_state) {
    case STATE_FADE_IN:
        alpha = (31 * m_alpha) >> FX32_SHIFT;
        break;
    case STATE_SHOWN:
        alpha = 31;
        break;
    case STATE_FADE_OUT:
        alpha = (31 * m_alpha) >> FX32_SHIFT;
        break;
    default:
        alpha = 0;
        break;
    }

    flake = m_flakes;
    for (i = 0; i < 32; flake++, i++) {
        m_sprite->m_color = GX_RGB(31, 31, 31);
        m_sprite->m_alpha = alpha;
        m_sprite->m_cellDataIdx = flake->type;
        Point2D pos = flake->pos - offset;
        pos.x -= FX32_MUL(FX_SinIdx(flake->angle), FX32_CONST(6)) + FX32_CONST(160);
        pos.y -= FX32_CONST(128);
        m_sprite->SetPos(pos);
        m_sprite->Render(camera);
    }

    if (m_rect.m_alpha == 0) {
        return;
    }

    SetupMatrix(camera);

    m_rect.m_polygonID = unk_1C;
    m_rect.SetRect(0, 0, FX32_CONST(256), FX32_CONST(256));
    m_tex.Bind();
    m_rect.Render(camera);

    G3_PopMtx(0);
}

BOOL CFieldSEFSnow::Load()
{
    m_actorData = new CFieldScreenEffectActorData();
    m_actorData->Load(4);

    m_sprite = new CSoftwareSprite();
    m_sprite->m_z = 1;
    m_sprite->m_polygonID = unk_1C;
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)m_actorData->GetPalette();
    m_sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)m_actorData->GetNcbr(0), NULL);
    m_sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)m_actorData->GetNcer(0);

    UnkClass_02008788 *cac = m_actorData->GetCac(0);

    for (int i = 0; i < 8; i++) {
        m_cells[i] = cac->sub_02008A80(1, 0);
        cac->sub_02008990(m_cells[i], 0);
    }

    SnowFlake *flake = m_flakes;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 4; col++, flake++) {
            flake->type = 2 - MATH_Rand16(&MAIN_BSS_0210CEC8, 3);
            flake->type = 2 - row % 3;
            flake->pos.x = col * FX32_CONST(64) + (MATH_Rand16(&MAIN_BSS_0210CEC8, 64) << FX32_SHIFT);
            flake->pos.y = row * FX32_CONST(24) + (MATH_Rand16(&MAIN_BSS_0210CEC8, 24) << FX32_SHIFT);
            flake->basePos.x = col * FX32_CONST(64);
            flake->angle = MATH_Rand16(&MAIN_BSS_0210CEC8, 16) << FX32_SHIFT;
            flake->phase = MATH_Rand16(&MAIN_BSS_0210CEC8, 256);
            flake->vel.x = 0;
            flake->vel.y = flake->baseVel.y = sSnowSpeeds[flake->type];
            flake->timer = MATH_Rand16(&MAIN_BSS_0210CEC8, 10) + 10;
        }
    }

    return TRUE;
}

BOOL CFieldSEFSnow::Unload()
{
    m_tex.Release();
    SAFE_DELETE(m_sprite);
    SAFE_DELETE(m_actorData);
    return TRUE;
}

BOOL CFieldSEFSnow::Start(int fadeIn, int hold, int fadeOut)
{
    BOOL result = CFieldScreenEffectObjectBase::Start(fadeIn, hold, fadeOut);
    m_rect.m_alpha = (m_density * m_alpha) >> FX32_SHIFT;
    return result;
}
