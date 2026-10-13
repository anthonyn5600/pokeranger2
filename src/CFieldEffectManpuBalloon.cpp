#include "field/CFieldEffectManpuBalloon.hpp"

#include <nitro.h>

#include "field/CFieldEffectManpuPos.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;

void CFieldEffectManpuBalloon::SetType(int type)
{
    switch (type) {
    case 0:
    case 1:
    case 2:
        m_sprite.m_cellDataIdx = type;
        break;
    }
    unk_24 = type;
}

int CFieldEffectManpuBalloon::ov0_02142264(int step)
{
    if (unk_1C == NULL) {
        return 0;
    }
    fx32 scale = 0x1000;
    fx32 sway = 0;
    Point2D pos = GetBalloonPos(unk_1C);
    switch (m_state) {
    case 1:
        scale = (m_frame << 12) / m_inTime;
        break;
    case 2: {
        int t = ((u16)(m_frames << 12) >> 4) * 4;
        if (m_frames & 0x10) {
            sway = t - 0x2000;
        } else {
            sway = 0x2000 - t;
        }
        m_frames++;
        break;
    }
    case 3:
        scale = ((m_outTime - m_frame) << 12) / m_outTime;
        break;
    }
    pos.y -= scale << 3;
    pos.y += sway;
    m_sprite.SetScale(0x1000, scale);
    m_sprite.SetPos(pos);
    return CFieldEffectActor::ov0_02142264(step);
}

int CFieldEffectManpuBalloon::Draw(Camera2D *camera)
{
    if (!MAIN_BSS_0210CA40->ov0_02124BFC()) {
        return 0;
    }
    m_sprite.Render(camera);
    return 0;
}

CFieldEffectManpuBalloon::~CFieldEffectManpuBalloon()
{
}
