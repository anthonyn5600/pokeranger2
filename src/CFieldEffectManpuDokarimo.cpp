#include "field/CFieldEffectManpuDokarimo.hpp"

#include "field/CFieldEffectManpuPos.hpp"

static const u8 sColors[9][3] = {
    { 31, 31, 0 },
    { 31, 0, 0 },
    { 31, 31, 31 },
    { 31, 0, 0 },
    { 31, 0, 31 },
    { 31, 31, 31 },
    { 12, 0, 31 },
    { 0, 0, 0 },
    { 31, 31, 31 },
};

CFieldEffectManpuDokarimo::CFieldEffectManpuDokarimo(CFieldEffectManage::CResidentResource *res, AnimSlotPool *slots, int cac, int type)
    : CFieldEffectManpuAnime((CEffectActorData *)res, slots, cac)
{
    m_bobSpeed = 0x2AA;
    m_fade = 0;
    m_colorBase = 0;
    m_colorIdx = 0;
    m_fadeLen = 16;
    unk_28 = 1;
    m_offset.y = 0;
    m_offset.x = 0;
    SetColors(type);
}

void CFieldEffectManpuDokarimo::SetColors(int type)
{
    switch (type) {
    default:
    case 9:
        m_colorBase = 0;
        m_fadeLen = 16;
        break;
    case 12:
        m_colorBase = 3;
        m_fadeLen = 16;
        break;
    case 13:
        m_colorBase = 6;
        m_fadeLen = 8;
        break;
    }
}

void CFieldEffectManpuDokarimo::UpdatePos(int step)
{
    if (unk_1C == NULL) {
        return;
    }
    m_offset.y += m_bobSpeed * step;
    if (m_offset.y >= 0x2000) {
        m_offset.y = 0x2000;
        m_bobSpeed = -m_bobSpeed;
    } else if (m_offset.y <= -0x2000) {
        m_offset.y = -0x2000;
        m_bobSpeed = -m_bobSpeed;
    }
    m_sprite.SetPos(GetBalloonPos(unk_1C) + m_offset);
    u8 from = m_colorBase + m_colorIdx;
    u8 to = from + 1;
    if (to >= m_colorBase + 3) {
        to = m_colorBase;
    }
    u8 rgb[3];
    for (int i = 0; i < 3; i++) {
        rgb[i] = sColors[from][i] + ((m_fade * (sColors[to][i] - sColors[from][i])) >> 4);
    }
    m_sprite.m_color = GX_RGB(rgb[0], rgb[1], rgb[2]);
    m_fade += step;
    if (m_fade < m_fadeLen) {
        return;
    }
    if (++m_colorIdx >= 3) {
        m_colorIdx = 0;
    }
    m_fade -= m_fadeLen;
}

CFieldEffectManpuDokarimo::~CFieldEffectManpuDokarimo()
{
}
