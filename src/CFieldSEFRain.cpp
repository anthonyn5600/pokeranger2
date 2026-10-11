#include <nitro.h>

#include "field/CFieldScreenEffect.hpp"
#include "fx_utils.hpp"

extern MATHRandContext16 MAIN_BSS_0210CEC8;

BOOL CFieldSEFRain::Load()
{
    ResetDrops();

    m_actorData = new CFieldScreenEffectActorData();
    m_actorData->Load(0);

    m_sprite = NULL;
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
        for (int j = 0; j < i * 3; j++) {
            cac->sub_02008A38(m_cells[i]);
        }
    }

    RainSplash *splash = m_splashes;
    for (int i = 0; i < 16; i++, splash++) {
        splash->pos.x = MATH_Rand16(&MAIN_BSS_0210CEC8, 256) << FX32_SHIFT;
        splash->pos.y = MATH_Rand16(&MAIN_BSS_0210CEC8, 192) << FX32_SHIFT;
    }

    m_state = 1;
    m_timer = 0;
    return TRUE;
}

BOOL CFieldSEFRain::Unload()
{
    SAFE_DELETE(m_sprite);
    SAFE_DELETE(m_actorData);
    return TRUE;
}

int CFieldSEFRain::Update(int fps)
{
    int numDrops = 0;
    int numStreaks = 0;
    int numSplashes = 0;

    switch (m_state) {
    case STATE_FADE_START:
    case STATE_FADE_IN:
        if (m_fadeIn != 0) {
            numDrops = (m_timer * 32) / m_fadeIn;
            if (m_timer > m_fadeIn / 2) {
                numStreaks = numDrops * (m_timer - m_fadeIn / 2) / (m_fadeIn / 2);
            }
            numSplashes = m_timer * 16 * m_timer / (m_fadeIn * m_fadeIn);
        }
        break;
    case STATE_SHOWN:
        numDrops = 32;
        numStreaks = 32;
        numSplashes = 16;
        break;
    case STATE_FADE_OUT:
        if (m_fadeOut != 0) {
            numDrops = ((m_fadeOut - m_timer) * 32) / m_fadeOut;
            if (m_timer < m_fadeOut / 2) {
                numStreaks = numDrops * (m_fadeOut / 2 - m_timer) / (m_fadeOut / 2);
            }
            numSplashes = (m_fadeOut - m_timer) * 16 * (m_fadeOut - m_timer) / (m_fadeOut * m_fadeOut);
        }
        break;
    case STATE_FADE_END:
        break;
    }

    for (int i = 0; i < 32; i++) {
        if (i <= numStreaks) {
            m_drops[i].m_mode = 2;
            fx32 x = MATH_Rand16(&MAIN_BSS_0210CEC8, 320) << FX32_SHIFT;
            m_drops[i].m_line.m_points.p1.x = x;
            m_drops[i].m_line.m_points.p1.y = 0;
            m_drops[i].m_line.m_points.p2.x = x - ((MATH_Rand16(&MAIN_BSS_0210CEC8, 16) + 16) << FX32_SHIFT);
            m_drops[i].m_line.m_points.p2.y = FX32_CONST(256);
            m_drops[i].m_line.m_alpha = MATH_Rand16(&MAIN_BSS_0210CEC8, 20) + 8;
        } else if (i <= numDrops) {
            m_drops[i].m_mode = 1;
            fx32 x = m_drops[i].m_line.m_points.p1.x - FX32_CONST(4);
            fx32 y = m_drops[i].m_line.m_points.p1.y + FX32_CONST(24);
            if (y > FX32_CONST(256) || x < 0) {
                y = 0;
                x = MATH_Rand16(&MAIN_BSS_0210CEC8, 320) << FX32_SHIFT;
            }
            m_drops[i].m_line.m_points.p1.x = x;
            m_drops[i].m_line.m_points.p1.y = y;
            m_drops[i].m_line.m_points.p2.x = x - FX32_CONST(12);
            m_drops[i].m_line.m_points.p2.y = y + FX32_CONST(72);
        } else {
            m_drops[i].m_mode = 0;
        }
    }

    for (int i = 0; i < 16; i++) {
        if (i <= numSplashes) {
            m_splashes[i].active = TRUE;
        } else {
            m_splashes[i].active = FALSE;
        }
    }

    UnkClass_02008788 *cac = m_actorData->GetCac(0);

    for (int i = 0; i < 8; i++) {
        cac->sub_02008A38(m_cells[i]);
        if (cac->sub_02008860(m_cells[i]) == 0) {
            cac->sub_020089B8(m_cells[i]);
            for (int j = 0; j < 2; j++) {
                m_splashes[i + j * 8].pos.x = MATH_Rand16(&MAIN_BSS_0210CEC8, 256) << FX32_SHIFT;
                m_splashes[i + j * 8].pos.y = MATH_Rand16(&MAIN_BSS_0210CEC8, 192) << FX32_SHIFT;
            }
        }
    }

    CFieldScreenEffectObjectBase::Update(fps);
    return m_state;
}

void CFieldSEFRain::Draw(UnkClass_02003718 *camera)
{
    Point2D offset = camera->GetOffsetCopy();

    for (int i = 0; i < 32; i++) {
        if (m_drops[i].m_mode != 0) {
            Point2D start = m_drops[i].m_line.GetStart();
            Point2D end = m_drops[i].m_line.GetEnd();
            Point2D drawStart = start - offset;
            Point2D drawEnd = end - offset;
            drawStart += s_scroll;
            drawEnd += s_scroll;
            drawStart.x -= FX32_CONST(160);
            drawStart.y -= FX32_CONST(128);
            drawEnd.x -= FX32_CONST(160);
            drawEnd.y -= FX32_CONST(128);
            m_drops[i].m_line.SetStart(drawStart);
            m_drops[i].m_line.SetEnd(drawEnd);
            m_drops[i].m_line.Render((CPrimitive_Render_arg *)camera);
            m_drops[i].m_line.SetStart(start);
            m_drops[i].m_line.SetEnd(end);
        }
    }

    UnkClass_02008788 *cac = m_actorData->GetCac(0);

    for (int i = 0; i < 16; i++) {
        if (m_splashes[i].active) {
            m_sprite->m_cellDataIdx = cac->sub_02008828(m_cells[i & 7]);
            Point2D pos = m_splashes[i].pos - offset;
            pos.x -= FX32_CONST(128);
            pos.y -= FX32_CONST(96);
            m_sprite->SetPos(pos);
            m_sprite->Render((CPrimitive_Render_arg *)camera);
        }
    }
}

void CFieldSEFRain::ResetDrops()
{
    CFieldSEFRainDrop *drop = m_drops;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 4; col++, drop++) {
            Point2D pos;
            pos.x = row * FX32_CONST(40) + (MATH_Rand16(&MAIN_BSS_0210CEC8, 40) << FX32_SHIFT);
            pos.y = MATH_Rand16(&MAIN_BSS_0210CEC8, 256) << FX32_SHIFT;
            drop->m_line.SetStart(pos);
            pos.y += FX32_CONST(32);
            drop->m_line.SetEnd(pos);
            drop->m_line.m_alpha = 12;
            drop->m_line.m_polygonID = unk_1C;
            drop->m_mode = 0;
        }
    }
}
