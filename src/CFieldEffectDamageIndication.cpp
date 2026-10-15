#include "CPlayerHPGauge.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldEffectManpuPos.hpp"
#include "field/CFieldPlayer.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;

CFieldEffectDamageIndication::CFieldEffectDamageIndication()
{
    m_player = NULL;
    if (MAIN_BSS_0210CA40 != NULL && MAIN_BSS_0210CA40->m_hpGauge != NULL) {
        InitRects(MAIN_BSS_0210CA40->m_hpGauge->GetPart(2));
    }
    m_vel.y = 0;
    m_vel.x = 0;
}

void CFieldEffectDamageIndication::Show(int damage, int duration, CFieldPlayer *player)
{
    if (player == NULL) {
        return;
    }
    m_player = player;
    if (damage < 0 || damage >= 100) {
        return;
    }
    // Unused; written out (player->GetPos() swaps the zero temps' stack slots).
    Point2D pos;
    if (player->m_drawObject != NULL) {
        pos = player->m_drawObject->GetPos();
    } else {
        Point2D zero = { 0, 0 };
        pos = zero;
    }
    m_vel.x = 0;
    m_vel.y = -0x3000;
    m_offset.y = 0;
    m_offset.x = 0;
    if (damage < 10) {
        m_digits = 1;
        m_rects[0].SetTexCoords(damage << 15, 0, (damage + 1) << 15, FX32_ONE * 16);
    } else {
        m_digits = 2;
        m_rects[0].SetTexCoords(damage / 10 << 15, 0, (damage / 10 + 1) << 15, FX32_ONE * 16);
        m_rects[1].SetTexCoords((damage - damage / 10 * 10) << 15, 0, (damage - damage / 10 * 10 + 1) << 15, FX32_ONE * 16);
    }
    Start(15, duration - 15, 0);
}

int CFieldEffectDamageIndication::Update(int step)
{
    int state = CFieldEffect::Update(step);
    if (state == 4 || state == 0) {
        m_digits = 0;
        return state;
    }
    if (m_player == NULL) {
        return state;
    }
    Point2D pos = GetBalloonPos(m_player);
    fx32 x = pos.x + m_offset.x;
    fx32 y = pos.y + m_offset.y;
    if (m_digits == 1) {
        m_rects[0].SetPos(x, y);
    } else if (m_digits == 2) {
        m_rects[0].SetPos(x - 0x4000, y);
        m_rects[1].SetPos(x + 0x4000, y);
    }
    if (state == 1) {
        m_offset += m_vel * (step << 12);
        m_vel.y += step * 0x6DB;
    }
    return state;
}

int CFieldEffectDamageIndication::Render(Camera2D *camera)
{
    for (int i = 0; i < m_digits; i++) {
        m_rects[i].Render(camera);
    }
    return 0;
}

void CFieldEffectDamageIndication::InitRects(GraphicsSet *digits)
{
    for (int i = 0; i < 2; i++) {
        m_rects[i].unk_38 = (UnkClass_CPrimitive_ImageProxy *)digits->m_image;
        m_rects[i].unk_3C = (UnkClass_CPrimitive_ImagePaletteProxy *)digits->m_palette;
        m_rects[i].m_color = 0x1F;
        m_rects[i].m_z = 0x11;
        m_rects[i].m_polygonID = 8;
        m_rects[i].SetSize(0x8000, 0x10000);
    }
}
