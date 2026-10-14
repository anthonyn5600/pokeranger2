#ifndef POKERANGER2_FIELD_CFIELDEFFECTSCATTERLEAVES_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSCATTERLEAVES_HPP

#include <nitro.h>

#include "field/CFieldEffectFactory.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// The TU's data order needs the emitter template's vtable made in the first TU-end pass (explicit instantiation; its
// member copies are weak and dropped for CFieldEffectWaterGun's) and TFieldEffectParticle completed before the
// particle classes (the size check does that without instantiating its members).
template class TFieldParticleEmitter<CSoftwareSprite>;
STATIC_SIZE_ASSERT(TFieldEffectParticle<CSoftwareSprite>, 0x28);

// Bursts of 8..12 leaves from a rectangle, flying away from its centre. Defined before the animator: the weak D0s at
// the TU end come in class completion order (emitter D0 first).
class CFieldParticleLeavesEmitter : public TFieldParticleRectEmitter<CSoftwareSprite> {
public:
    CFieldParticleLeavesEmitter()
    {
        m_life = 0x28000;
    }
    virtual void func2()
    {
        m_timer = 0x1000;
    }
    virtual u32 Update(int dt);
    virtual void Emit(TFieldParticle<CSoftwareSprite> *p);

    int m_interval;
    fx32 m_timer;
    u32 m_count;
    fx32 m_life;
};

// Pulls the leaves down (ov0).
class CFieldParticleLeavesAnimator : public TFieldParticleForceField<CSoftwareSprite> {
public:
    virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
};

class CFieldEffectScatterLeaves : public TFieldEffectParticle<CSoftwareSprite> {
public:
    CFieldEffectScatterLeaves(int kind);
    virtual int sub_02033028()
    {
        return 11;
    }
    virtual int sub_0203312C(int param, int value);
    virtual TFieldParticleForceField<CSoftwareSprite> *GetForceField()
    {
        return &m_animator;
    }
    virtual TFieldParticleEmitter<CSoftwareSprite> *GetEmitter()
    {
        return &m_emitter;
    }

    CFieldParticleLeavesAnimator m_animator;
    CFieldParticleLeavesEmitter m_emitter;
};
STATIC_SIZE_ASSERT(CFieldEffectScatterLeaves, 0x6C);

class CFieldEffectScatterLeavesFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTSCATTERLEAVES_HPP
