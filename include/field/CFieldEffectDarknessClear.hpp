#ifndef POKERANGER2_FIELD_CFIELDEFFECTDARKNESSCLEAR_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTDARKNESSCLEAR_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CSimpleSpriteNTF.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"

// size 0xAC, ctor ov0_0216A448
class CFieldEffectDarknessClear : public TFieldEffectParticle<CSimpleSpriteNTF> {
public:
    class CForceField : public TFieldParticleForceField<CSimpleSpriteNTF> {
    public:
        virtual ~CForceField();
        virtual void Apply(TFieldParticle<CSimpleSpriteNTF> *p, int dt);
    };

    class CEmitter : public TFieldParticleSmokeRectEmitter<CSimpleSpriteNTF> {
    public:
        virtual ~CEmitter();
        virtual void Emit(TFieldParticle<CSimpleSpriteNTF> *p);
    };

    virtual ~CFieldEffectDarknessClear();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual TFieldParticleForceField<CSimpleSpriteNTF> *GetForceField();
    virtual TFieldParticleEmitter<CSimpleSpriteNTF> *GetEmitter();
};

// size 0xB8, ctor ov0_0216B39C
class CFieldEffectDarknessClear2 : public TFieldEffectParticle<CSimpleSpriteNTF> {
public:
    class CForceField : public TFieldParticleForceField<CSimpleSpriteNTF> {
    public:
        virtual ~CForceField();
        virtual void Apply(TFieldParticle<CSimpleSpriteNTF> *p, int dt);
    };

    class CEmitter : public TFieldParticleSmokeRectEmitter<CSimpleSpriteNTF> {
    public:
        virtual ~CEmitter();
        virtual void Emit(TFieldParticle<CSimpleSpriteNTF> *p);
    };

    virtual ~CFieldEffectDarknessClear2();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual TFieldParticleForceField<CSimpleSpriteNTF> *GetForceField();
    virtual TFieldParticleEmitter<CSimpleSpriteNTF> *GetEmitter();
};

class CFieldEffectDarknessClearFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTDARKNESSCLEAR_HPP
