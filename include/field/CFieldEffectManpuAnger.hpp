#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUANGER_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUANGER_HPP

#include <nitro.h>

#include "field/CFieldEffectManpu.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// size 0x94, ctor ov0_02163A88
class CFieldEffectManpuAnger : public CFieldEffectManpu {
public:
    class CAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual ~CAnimator();
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    class CEmitter : public TFieldParticleEmitter<CSoftwareSprite> {
    public:
        virtual ~CEmitter();
        virtual void func2();
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);
    };

    virtual ~CFieldEffectManpuAnger();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int Draw(Camera2D *camera);
    virtual void SetDepth(fx32 z);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUANGER_HPP
