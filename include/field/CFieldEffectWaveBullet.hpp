#ifndef POKERANGER2_FIELD_CFIELDEFFECTWAVEBULLET_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTWAVEBULLET_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// size 0xBC, ctor ov0_0215CDC4
class CFieldEffectWaveBullet : public CFieldEffectActor {
public:
    class CWaveParticleAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual ~CWaveParticleAnimator();
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    class CWaveParticleEmitter : public TFieldParticleEmitter<CSoftwareSprite> {
    public:
        virtual ~CWaveParticleEmitter();
        virtual void func2();
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);
    };

    virtual ~CFieldEffectWaveBullet();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual void sub_0203365C(int arg0);
};

class CFieldEffectWaveBulletFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTWAVEBULLET_HPP
