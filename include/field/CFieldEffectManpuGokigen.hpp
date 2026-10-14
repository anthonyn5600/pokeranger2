#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUGOKIGEN_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUGOKIGEN_HPP

#include <nitro.h>

#include "field/CFieldEffectManpu.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// size 0xA0
class CFieldEffectManpuGokigen : public CFieldEffectManpu {
public:
    CFieldEffectManpuGokigen(CEffectActorData *data);
    class CEmitter : public TFieldParticleEmitter<CSoftwareSprite> {
    public:
        virtual ~CEmitter();
        virtual void func2();
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);
    };

    class CAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual ~CAnimator();
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    virtual ~CFieldEffectManpuGokigen();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual void SetType(int type);
    virtual int Draw(Camera2D *camera);
    virtual void SetDepth(fx32 z);

    u8 unk_2C[0x74];
};

STATIC_SIZE_ASSERT(CFieldEffectManpuGokigen, 0xA0);

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUGOKIGEN_HPP
