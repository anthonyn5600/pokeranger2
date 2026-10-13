#ifndef POKERANGER2_FIELD_CFIELDEFFECTSPRAY_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSPRAY_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// size 0xBC, ctor ov0_0215F538
class CFieldEffectSpray : public CFieldEffectActor {
public:
    class CWaveParticleEmitter : public TFieldParticleEmitter<CSoftwareSprite> {
    public:
        virtual ~CWaveParticleEmitter();
        virtual void func2();
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);
    };

    class CWaveParticleAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual ~CWaveParticleAnimator();
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    virtual ~CFieldEffectSpray();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
};

class CFieldEffectSprayFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTSPRAY_HPP
