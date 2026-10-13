#ifndef POKERANGER2_FIELD_CFIELDPARTICLESMOKEANIMATOR_HPP
#define POKERANGER2_FIELD_CFIELDPARTICLESMOKEANIMATOR_HPP

#include <nitro.h>

#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Grows particles from m_scaleStart to m_scaleEnd and fades them out (also used by CFieldEffectSpreadSmoke).
class CFieldParticleSmokeAnimator : public TFieldParticleForceField<CSoftwareSprite> {
public:
    CFieldParticleSmokeAnimator();
    virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);

    fx32 m_scaleStart;
    fx32 m_scaleEnd;
    BOOL m_sway;
    u8 m_alpha;
};

#endif // POKERANGER2_FIELD_CFIELDPARTICLESMOKEANIMATOR_HPP
