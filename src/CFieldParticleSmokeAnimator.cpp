#include "field/CFieldParticleSmokeAnimator.hpp"

#include <nitro.h>

#include "fx_utils.hpp"

CFieldParticleSmokeAnimator::CFieldParticleSmokeAnimator()
{
    m_scaleStart = 0x1000;
    m_scaleEnd = 0x1000;
    m_sway = FALSE;
    m_alpha = 0x1F;
}

void CFieldParticleSmokeAnimator::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    fx32 maxLife = p->maxLife;
    fx32 elapsed = maxLife - p->life;
    fx32 scale = m_scaleStart + FX32_DIV(FX32_MUL(elapsed, m_scaleEnd - m_scaleStart), maxLife);
    p->sprite.m_scale[0] = scale;
    p->sprite.m_scale[1] = scale;
    p->sprite.m_alpha = FX32_DIV(m_alpha * p->life, maxLife) >> 12;
    if (m_sway) {
        p->vel.x = FX32_MUL(FX_CosIdx((u16)(elapsed >> 3)), 0x1000);
    }
}
