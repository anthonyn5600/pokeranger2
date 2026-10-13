#ifndef POKERANGER2_FIELD_CFIELDEFFECTSTEAM_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSTEAM_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CFieldParticleSmokeAnimator : public TFieldParticleForceField<CSoftwareSprite> {
public:
    virtual ~CFieldParticleSmokeAnimator();
    virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
};

// size 0x94, ctor ov0_0215AD18
class CFieldEffectSteam : public TFieldEffectSmoke<CSoftwareSprite> {
public:
    virtual ~CFieldEffectSteam();
    virtual int sub_02033028();
    virtual int sub_0203312C(int param, int value);
    virtual TFieldParticleForceField<CSoftwareSprite> *GetForceField();
};

class CFieldEffectSteamFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTSTEAM_HPP
