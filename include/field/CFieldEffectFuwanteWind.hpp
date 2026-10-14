#ifndef POKERANGER2_FIELD_CFIELDEFFECTFUWANTEWIND_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTFUWANTEWIND_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// size 0x90, ctor ov0_0216F540
class CFieldEffectFuwanteWind : public TFieldEffectParticle<CSoftwareSprite> {
public:
    class CEmitter : public TFieldParticleSmokeRectEmitter<CSoftwareSprite> {
    public:
        virtual ~CEmitter();
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);
    };

    class CAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual ~CAnimator();
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    virtual ~CFieldEffectFuwanteWind();
    virtual int GetEffectId();
    virtual int ov0_02142344(Camera2D *camera);
    virtual int SetParam(int param, int value);
    virtual TFieldParticleForceField<CSoftwareSprite> *GetForceField();
    virtual TFieldParticleEmitter<CSoftwareSprite> *GetEmitter();
};

class CFieldEffectFuwanteWindFactory : public CFieldEffectFactory {
public:
    CFieldEffectFuwanteWindFactory()
    {
        unk_38 = 0;
    }
    virtual ~CFieldEffectFuwanteWindFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Update(int frames);
    virtual void Reset();

public:
    CFieldEffectNormalActorData m_data;
    int unk_38;
};

STATIC_SIZE_ASSERT(CFieldEffectFuwanteWindFactory, 0x3C);

#endif // POKERANGER2_FIELD_CFIELDEFFECTFUWANTEWIND_HPP
