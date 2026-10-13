#ifndef POKERANGER2_FIELD_CFIELDEFFECTDARKCLOUD_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTDARKCLOUD_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// size 0x154, ctor ov0_021675CC
class CFieldEffectDarkCloud : public TFieldEffectParticle<CSoftwareSprite> {
public:
    class CAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual ~CAnimator();
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    class CEmitter : public TFieldParticleSmokeRectEmitter<CSoftwareSprite> {
    public:
        virtual ~CEmitter();
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);
    };

    class CRemainsAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual ~CRemainsAnimator();
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    class CRemainsEmitter : public TFieldParticleSmokeRectEmitter<CSoftwareSprite> {
    public:
        virtual ~CRemainsEmitter();
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);
    };

    virtual ~CFieldEffectDarkCloud();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual void sub_0203331C(const Point2D &pos, int arg1);
    virtual TFieldParticleForceField<CSoftwareSprite> *GetForceField();
    virtual TFieldParticleEmitter<CSoftwareSprite> *GetEmitter();
    virtual int ov0_02167BA4(); // TODO signature, new virtual (slot 26)
};

class CFieldEffectDarkCloudFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTDARKCLOUD_HPP
