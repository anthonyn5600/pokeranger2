#include "field/CFieldEffectManpuJumping.hpp"

#include <nitro.h>

#include "field/CFieldEffectManpuPos.hpp"
#include "fx_utils.hpp"

int CFieldEffectManpuJumping::ov0_02142264(int step)
{
    fx32 scale = 0x1000;
    Point2D pos = GetBalloonPos(unk_1C);
    if (unk_1C == NULL) {
        return 0;
    }
    switch (m_state) {
    case 1: {
        int top = m_inTime - 4;
        if (m_frame < top) {
            scale = FX32_MUL(m_frame << 12, 0x1333) / top;
        } else {
            scale = FX32_DIV(FX32_MUL((m_frame - top) << 12, -0x333), 0x4000) + 0x1333;
        }
        break;
    }
    case 2:
    case 3:
        break;
    }
    m_sprite.SetScale(0x1000, scale);
    m_sprite.m_cellDataIdx = 0;
    m_sprite.SetPos(pos);
    return CFieldEffectActor::ov0_02142264(step);
}

int CFieldEffectManpuJumping::Draw(Camera2D *camera)
{
    if (unk_1C == NULL) {
        return 0;
    }
    m_sprite.Render(camera);
    return 0;
}

BOOL CFieldEffectManpuJumping::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    if (inTime > 0) {
        inTime += 4;
    }
    return CFieldEffect::ov0_021421F0(inTime, holdTime, outTime);
}

CFieldEffectManpuJumping::~CFieldEffectManpuJumping()
{
}
