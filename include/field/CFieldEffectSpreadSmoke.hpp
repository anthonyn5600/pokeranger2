#ifndef POKERANGER2_FIELD_CFIELDEFFECTSPREADSMOKE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSPREADSMOKE_HPP

#include <nitro.h>

#include "field/CFieldEffectFactory.hpp"
#include "field/CFieldParticleSmokeAnimator.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CFieldEffectSpreadSmoke : public TFieldEffectParticle<CSoftwareSprite> {
public:
    CFieldEffectSpreadSmoke(int kind);
    virtual ~CFieldEffectSpreadSmoke();
    virtual int GetEffectId()
    {
        return 10;
    }
    virtual int SetParam(int param, int value);
    virtual TFieldParticleForceField<CSoftwareSprite> *GetForceField()
    {
        return &m_animator;
    }
    virtual TFieldParticleEmitter<CSoftwareSprite> *GetEmitter()
    {
        return &m_emitter;
    }

    TFieldParticleSmokeRectEmitter<CSoftwareSprite> m_emitter;
    CFieldParticleSmokeAnimator m_animator;
};
STATIC_SIZE_ASSERT(CFieldEffectSpreadSmoke, 0x94);

class CFieldEffectSpreadSmokeFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTSPREADSMOKE_HPP
