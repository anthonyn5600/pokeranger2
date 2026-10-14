#include "field/CFieldEffectJumon.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "field/TFieldParticle.hpp"

CFieldEffectJumon::CFieldEffectJumon(int arg)
{
    InitSprites();
    m_pos.x = 0;
    m_pos.y = 0;
}

CFieldEffectJumon::~CFieldEffectJumon()
{
}

int CFieldEffectJumon::ov0_02142264(int step)
{
    int state = CFieldEffect::ov0_02142264(step);
    if (state != 0 && state != 4) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 2; j++) {
                m_rings[i].m_trail[2 - j] = m_rings[i].m_trail[1 - j];
            }
            m_rings[i].m_timer -= step;
            if (m_rings[i].m_timer < 0) {
                m_rings[i].m_timer = m_rings[i].m_timerReset;
                if (i == 2) {
                    m_rings[i].m_targetRadius = MATH_Rand16(&MAIN_BSS_0210CEC8, 9) + 0x18;
                } else {
                    m_rings[i].m_targetRadius = MATH_Rand16(&MAIN_BSS_0210CEC8, 9) + 8;
                }
            }
            m_rings[i].m_angle += m_rings[i].m_angleStep;
            if (m_rings[i].m_radius != m_rings[i].m_targetRadius) {
                m_rings[i].m_radius = m_rings[i].m_targetRadius;
            }
            m_rings[i].m_trail[0].x = m_rings[i].m_radius * FX_CosIdx(m_rings[i].m_angle) + m_pos.x;
            m_rings[i].m_trail[0].y = m_rings[i].m_radius * FX_SinIdx(m_rings[i].m_angle) + m_pos.y;
        }
    }
    return state;
}

int CFieldEffectJumon::ov0_02142344(Camera2D *camera)
{
    if (m_state != 4 && m_state != 0) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                m_sprites[i][j].SetPos(m_rings[i].m_trail[j]);
                m_sprites[i][j].Render(camera);
            }
        }
    }
    return 0;
}

int CFieldEffectJumon::sub_0203312C(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 1:
        m_pos.x = value << 12;
        break;
    case 2:
        m_pos.y = value << 12;
        break;
    case 3:
        m_size.x = value << 12;
        break;
    case 4:
        m_size.y = value << 12;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

BOOL CFieldEffectJumon::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    const int t8 = 8;
    const int t20 = 20;
    const int t10 = 10;
    m_rings[1].m_angle = 0;
    m_rings[1].m_angleStep = 0x2000;
    m_rings[1].m_radius = MATH_Rand16(&MAIN_BSS_0210CEC8, 9) + 8;
    m_rings[1].m_targetRadius = m_rings[1].m_radius;
    m_rings[1].m_timerReset = m_rings[1].m_timer = t8;
    m_rings[0].m_angle = 0x5555;
    m_rings[0].m_angleStep = 0xF334;
    m_rings[0].m_radius = MATH_Rand16(&MAIN_BSS_0210CEC8, 9) + 8;
    m_rings[0].m_targetRadius = m_rings[0].m_radius;
    m_rings[0].m_timerReset = m_rings[0].m_timer = t20;
    m_rings[2].m_angle = 0xAAAA;
    m_rings[2].m_angleStep = 0x1999;
    m_rings[2].m_radius = MATH_Rand16(&MAIN_BSS_0210CEC8, 9) + 0x18;
    m_rings[2].m_targetRadius = m_rings[2].m_radius;
    m_rings[2].m_timerReset = m_rings[2].m_timer = t10;
    for (int i = 0; i < 3; i++) {
        Point2D p;
        p.x = m_rings[i].m_radius * FX_CosIdx(m_rings[i].m_angle) + m_pos.x;
        p.y = m_rings[i].m_radius * FX_SinIdx(m_rings[i].m_angle) + m_pos.y;
        for (int j = 0; j < 3; j++) {
            m_rings[i].m_trail[j] = p;
        }
    }
    return CFieldEffect::ov0_021421F0(inTime, holdTime, outTime);
}

void CFieldEffectJumon::InitSprites()
{
    CFieldEffectManage *mgr = MAIN_BSS_0210CA60;
    u16 colors[3] = { 0x0000, 0x001F, 0x7C1F };
    u16 alphas[3] = { 0x1F, 0x14, 0x0A };
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m_sprites[i][j].SetResources((UnkClass_CPrimitive_ImageProxy *)mgr->m_resident.GetNcbr(0), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)mgr->m_resident.GetPalette(), (UnkClass_CSoftwareSprite_38 *)mgr->m_resident.GetNcer(0));
            m_sprites[i][j].m_cellDataIdx = 1;
            m_sprites[i][j].m_polygonID = i * 3 + 8 + j;
            m_sprites[i][j].m_z = i + 0x622;
            m_sprites[i][j].m_color = colors[i];
            m_sprites[i][j].m_alpha = alphas[j];
            if (i == 2) {
                m_sprites[i][j].SetScale(0x2000, 0x2000);
            }
        }
    }
}

CFieldEffect *CFieldEffectJumonFactory::Create(int arg)
{
    return new CFieldEffectJumon(arg);
}

int CFieldEffectJumon::sub_02033028()
{
    return 0x10;
}
