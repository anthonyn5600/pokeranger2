#include <nitro.h>

#include "field/CFieldScreenEffect.hpp"
#include "fx_utils.hpp"

extern MATHRandContext16 MAIN_BSS_0210CEC8;

CFieldSEFHinoko::CFieldSEFHinoko(BOOL withSparks)
{
    Load();
    m_rect.m_color = GX_RGB(18, 18, 10);
    m_rect.m_alpha = 0;
    m_density = 21;

    GXRgb color = m_rect.m_color;
    int density = m_density;
    CFieldSEFFog::s_color[0] = color & 0x1F;
    CFieldSEFFog::s_color[1] = (color >> 5) & 0x1F;
    CFieldSEFFog::s_color[2] = (color >> 10) & 0x1F;
    CFieldSEFFog::s_density = density;
    CFieldSEFFog::s_dirty = FALSE;

    m_withSparks = withSparks;
}

int CFieldSEFHinoko::Update(int fps)
{
    if (m_releaseDelay != 0) {
        if (--m_releaseDelay == 0) {
            m_tex.ReleaseFiles();
        }
    }

    CFieldScreenEffectObjectBase::Update(fps);

    if (CFieldSEFFog::s_dirty) {
        m_rect.m_color = GX_RGB(CFieldSEFFog::s_color[0], CFieldSEFFog::s_color[1], CFieldSEFFog::s_color[2]);
        m_density = CFieldSEFFog::s_density;
        CFieldSEFFog::s_dirty = FALSE;
    }

    m_actorData->Update();

    if (m_withSparks) {
        for (int i = 0; i < 16; i++) {
            HinokoSpark *spark = &m_sparks1[i];
            spark->phase += s_frameStep;

            spark->pos.x += FX32_MUL(spark->vel.x * s_frameStep, FX32_ONE);
            if (spark->pos.x < 0) {
                spark->pos.x += FX32_CONST(320);
                spark->vel.y = FX32_MUL(MATH_Rand16(&MAIN_BSS_0210CEC8, 16) << FX32_SHIFT, (fx32)(0.04 * FX32_ONE)) + FX32_CONST(0.4);
            } else if (spark->pos.x > FX32_CONST(320)) {
                spark->pos.x -= FX32_CONST(320);
            }

            spark->pos.y += FX32_MUL(spark->vel.y * s_frameStep, FX32_ONE);
            if (spark->pos.y < 0) {
                spark->pos.y += FX32_CONST(256);
            } else if (spark->pos.y > FX32_CONST(256)) {
                spark->pos.y -= FX32_CONST(256);
                spark->vel.y = FX32_MUL(MATH_Rand16(&MAIN_BSS_0210CEC8, 16) << FX32_SHIFT, (fx32)(0.04 * FX32_ONE)) + FX32_CONST(0.4);
            }

            if (MATH_Rand16(&MAIN_BSS_0210CEC8, 8) == 0) {
                spark->vel.y += FX32_MUL(MATH_Rand16(&MAIN_BSS_0210CEC8, 2) << FX32_SHIFT, (fx32)(0.04 * FX32_ONE));
            }

            spark->pos.x += s_scroll.x;
            spark->pos.y += s_scroll.y;

            if (spark->timer-- == 0) {
                spark->timer = MATH_Rand16(&MAIN_BSS_0210CEC8, 10) + 10;
                fx32 scale = FX32_MUL(MATH_Rand16(&MAIN_BSS_0210CEC8, 12) << FX32_SHIFT, (fx32)(0.05 * FX32_ONE)) + FX32_CONST(0.7);
                spark->vel.x = FX32_MUL(spark->baseVel.x, scale);
                spark->vel.y = FX32_MUL(spark->baseVel.y, scale);
            }
        }

        for (int i = 0; i < 16; i++) {
            HinokoSpark *spark = &m_sparks2[i];
            spark->phase += s_frameStep;

            spark->pos.x += FX32_MUL(spark->vel.x * s_frameStep, FX32_ONE);
            if (spark->pos.x < 0) {
                spark->pos.x += FX32_CONST(320);
                spark->vel.y = FX32_MUL(MATH_Rand16(&MAIN_BSS_0210CEC8, 16) << FX32_SHIFT, (fx32)(0.04 * FX32_ONE)) + FX32_CONST(0.4);
            } else if (spark->pos.x > FX32_CONST(320)) {
                spark->pos.x -= FX32_CONST(320);
            }

            spark->pos.y += FX32_MUL(spark->vel.y * s_frameStep, FX32_ONE);
            if (spark->pos.y < 0) {
                spark->pos.y += FX32_CONST(256);
            } else if (spark->pos.y > FX32_CONST(256)) {
                spark->pos.y -= FX32_CONST(256);
                spark->vel.y = FX32_MUL(MATH_Rand16(&MAIN_BSS_0210CEC8, 16) << FX32_SHIFT, (fx32)(0.04 * FX32_ONE)) + FX32_CONST(0.4);
            }

            if (MATH_Rand16(&MAIN_BSS_0210CEC8, 8) == 0) {
                spark->vel.y += FX32_MUL(MATH_Rand16(&MAIN_BSS_0210CEC8, 2) << FX32_SHIFT, (fx32)(0.04 * FX32_ONE));
            }

            spark->pos.x += s_scroll.x;
            spark->pos.y += s_scroll.y;

            if (spark->timer-- == 0) {
                spark->timer = MATH_Rand16(&MAIN_BSS_0210CEC8, 10) + 10;
                fx32 scale = FX32_MUL(MATH_Rand16(&MAIN_BSS_0210CEC8, 12) << FX32_SHIFT, (fx32)(0.05 * FX32_ONE)) + FX32_CONST(0.7);
                spark->vel.x = FX32_MUL(spark->baseVel.x, scale);
                spark->vel.y = FX32_MUL(spark->baseVel.y, scale);
            }
        }
    }

    m_s -= (fx32)(s_frameStep * -0.1f * 4096.0f) + FX32_MUL(s_scroll.x, FX32_HALF);
    m_s &= 0xFFFFF;
    m_t -= FX32_MUL(s_scroll.y, FX32_HALF);
    m_t &= 0xFFFFF;

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

void CFieldSEFHinoko::Draw(UnkClass_02003718 *camera)
{
    UnkClass_02008788 *cac = m_actorData->GetCac(0);
    Point2D offset = camera->GetOffsetCopy();

    if (m_withSparks) {
        for (int i = 0; i < 16; i++) {
            HinokoSpark *spark = &m_sparks1[i];
            u8 alpha;
            GXRgb color;

            switch ((spark->phase >> 6) & 3) {
            case 0:
                alpha = spark->phase >> 1;
                color = GX_RGB(31, 31, 31);
                break;
            case 1:
                alpha = 31;
                color = GX_RGB(31, 31, 31);
                break;
            case 2:
                alpha = 31 - ((spark->phase >> 1) & 31);
                color = GX_RGB(alpha, alpha, alpha);
                break;
            case 3:
            default:
                alpha = 0;
                color = 0;
                break;
            }

            if (alpha != 0) {
                m_sprite->m_color = color;
                m_sprite->m_alpha = alpha;
                m_sprite->m_cellDataIdx = cac->sub_02008828(m_cells[i & 7]);
                Point2D pos = spark->pos - offset;
                pos.x -= FX32_CONST(160);
                pos.y -= FX32_CONST(128);
                m_sprite->SetPos(pos);
                m_sprite->Render((CPrimitive_Render_arg *)camera);
            }
        }

        for (int i = 0; i < 16; i++) {
            HinokoSpark *spark = &m_sparks2[i];
            u8 alpha;
            GXRgb color;

            switch ((spark->phase >> 6) & 3) {
            case 0:
                alpha = spark->phase >> 1;
                color = GX_RGB(31, 31, 31);
                break;
            case 1:
                alpha = 31;
                color = GX_RGB(31, 31, 31);
                break;
            case 2:
                alpha = 31 - ((spark->phase >> 1) & 31);
                color = GX_RGB(alpha, alpha, alpha);
                break;
            case 3:
            default:
                alpha = 0;
                color = 0;
                break;
            }

            if (alpha != 0) {
                m_sprite->m_color = color;
                m_sprite->m_alpha = alpha;
                m_sprite->m_cellDataIdx = cac->sub_02008828(m_bigCell);
                Point2D pos = spark->pos - offset;
                pos.x -= FX32_CONST(160);
                pos.y -= FX32_CONST(128);
                m_sprite->SetPos(pos);
                m_sprite->Render((CPrimitive_Render_arg *)camera);
            }
        }
    }

    if (m_rect.m_alpha == 0) {
        return;
    }

    SetupMatrix(camera);

    CPrimitiveRectNTF *rect = &m_rect;

    rect->m_polygonID = unk_1C;
    rect->SetRect(0, 0, FX32_CONST(256), FX32_CONST(256));
    rect->SetTexCoords(m_s, m_t, m_s + FX32_CONST(128), m_t + FX32_CONST(128));
    m_tex.Bind();
    rect->Render((CPrimitive_Render_arg *)camera);

    G3_PopMtx(0);
}

BOOL CFieldSEFHinoko::Load()
{
    m_actorData = new CFieldScreenEffectActorData();
    m_actorData->Load(8);

    m_sprite = new CSoftwareSprite();
    m_sprite->m_z = 1;
    m_sprite->m_polygonID = unk_1C;
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)m_actorData->GetPalette();
    m_sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)m_actorData->GetNcbr(0), NULL);
    m_sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)m_actorData->GetNcer(0);

    UnkClass_02008788 *cac = m_actorData->GetCac(0);

    for (int i = 0; i < 8; i++) {
        m_cells[i] = cac->sub_02008A80(1, 0);
        cac->sub_02008990(m_cells[i], i % 3);
    }

    HinokoSpark *spark = m_sparks1;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++, spark++) {
            spark->pos.x = col * FX32_CONST(80) + (MATH_Rand16(&MAIN_BSS_0210CEC8, 80) << FX32_SHIFT);
            spark->pos.y = row * FX32_CONST(64) + (MATH_Rand16(&MAIN_BSS_0210CEC8, 64) << FX32_SHIFT);
            spark->phase = MATH_Rand16(&MAIN_BSS_0210CEC8, 256);
            spark->vel.x = spark->baseVel.x = FX32_MUL(MATH_Rand16(&MAIN_BSS_0210CEC8, 8) << FX32_SHIFT, (fx32)(-0.08 * FX32_ONE)) - FX32_CONST(2);
            spark->vel.y = spark->baseVel.y = FX32_MUL(MATH_Rand16(&MAIN_BSS_0210CEC8, 8) << FX32_SHIFT, (fx32)(0.04 * FX32_ONE)) + FX32_CONST(0.4);
            spark->timer = MATH_Rand16(&MAIN_BSS_0210CEC8, 10) + 10;
        }
    }

    m_bigCell = cac->sub_02008A80(1, 0);
    cac->sub_02008990(m_bigCell, 3);

    spark = m_sparks2;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++, spark++) {
            spark->pos.x = col * FX32_CONST(80) + (MATH_Rand16(&MAIN_BSS_0210CEC8, 80) << FX32_SHIFT);
            spark->pos.y = row * FX32_CONST(64) + (MATH_Rand16(&MAIN_BSS_0210CEC8, 64) << FX32_SHIFT);
            spark->phase = MATH_Rand16(&MAIN_BSS_0210CEC8, 256);
            spark->vel.x = spark->baseVel.x = FX32_MUL(MATH_Rand16(&MAIN_BSS_0210CEC8, 8) << FX32_SHIFT, (fx32)(-0.08 * FX32_ONE)) - FX32_CONST(2);
            spark->vel.y = spark->baseVel.y = FX32_MUL(MATH_Rand16(&MAIN_BSS_0210CEC8, 8) << FX32_SHIFT, (fx32)(0.04 * FX32_ONE)) + FX32_CONST(0.4);
            spark->timer = MATH_Rand16(&MAIN_BSS_0210CEC8, 10) + 10;
        }
    }

    m_tex.LoadDeferred("data/field/effect/kiri02.ntft", "data/field/effect/kiri02.ntfp", 2);
    m_releaseDelay = 2;
    return TRUE;
}

BOOL CFieldSEFHinoko::Unload()
{
    m_tex.Release();
    SAFE_DELETE(m_sprite);
    SAFE_DELETE(m_actorData);
    return TRUE;
}

BOOL CFieldSEFHinoko::Start(int fadeIn, int hold, int fadeOut)
{
    BOOL result = CFieldScreenEffectObjectBase::Start(fadeIn, hold, fadeOut);
    m_rect.m_alpha = (m_density * m_alpha) >> FX32_SHIFT;
    return result;
}
