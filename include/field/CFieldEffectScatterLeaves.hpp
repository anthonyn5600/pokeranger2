#ifndef POKERANGER2_FIELD_CFIELDEFFECTSCATTERLEAVES_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSCATTERLEAVES_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CFieldParticleLeavesAnimator : public TFieldParticleForceField<CSoftwareSprite> {
public:
    virtual ~CFieldParticleLeavesAnimator();
    virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
};

class CFieldParticleLeavesEmitter : public TFieldParticleRectEmitter<CSoftwareSprite> {
public:
    virtual ~CFieldParticleLeavesEmitter();
    virtual void func2();
    virtual u32 Update(int dt);
    virtual void Emit(TFieldParticle<CSoftwareSprite> *p);
};

// size 0x6C, ctor ov0_0215BDCC
class CFieldEffectScatterLeaves : public TFieldEffectParticle<CSoftwareSprite> {
public:
    virtual ~CFieldEffectScatterLeaves();
    virtual int sub_02033028();
    virtual int sub_0203312C(int param, int value);
    virtual TFieldParticleForceField<CSoftwareSprite> *GetForceField();
    virtual TFieldParticleEmitter<CSoftwareSprite> *GetEmitter();
};

class CFieldEffectScatterLeavesFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTSCATTERLEAVES_HPP
