#ifndef POKERANGER2_FIELD_CFIELDEFFECTFIRE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTFIRE_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// size 0x7C, ctor ov0_021601D4
class CFieldEffectFire : public TFieldEffectParticle<CSoftwareSprite> {
public:
    class CParticleAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual ~CParticleAnimator();
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    class CParticleEmitter : public TFieldParticleRectEmitter<CSoftwareSprite> {
    public:
        virtual ~CParticleEmitter();
        virtual void func2();
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);
    };

    virtual ~CFieldEffectFire();
    virtual int sub_02033028();
    virtual int sub_020332A4();
    virtual int ov0_02142264(int step);
    virtual int sub_0203312C(int param, int value);
    virtual TFieldParticleForceField<CSoftwareSprite> *GetForceField();
    virtual TFieldParticleEmitter<CSoftwareSprite> *GetEmitter();
};

class CFieldEffectFireFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTFIRE_HPP
