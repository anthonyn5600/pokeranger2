#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUANGER_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUANGER_HPP

#include <nitro.h>

#include "field/CFieldEffectManpu.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Explicit instantiations: complete both particle templates before the nested classes, which puts their RTTI ahead of
// CEmitter's and CAnimator's in the TU's data sort (typeinfo order CAnimator, CEmitter, CFieldEffectManpuAnger).
template class TFieldParticleEmitter<CSoftwareSprite>;
template class TFieldParticleForceField<CSoftwareSprite>;

// Anger marks (manpu) popping out above an actor's head.
class CFieldEffectManpuAnger : public CFieldEffectManpu {
public:
    // Emits one mark per interval, cycling (with a random skip) through left, right and centre.
    class CEmitter : public TFieldParticleEmitter<CSoftwareSprite> {
    public:
        CEmitter()
        {
            m_actor = NULL;
            m_interval = 20;
            m_timer = 0;
            m_dir = 0;
        }

        virtual void func2();
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);

        CFieldActor *m_actor;
        int m_interval;
        int m_timer;
        u8 m_dir;
    };

    // Grows the marks after their first 4 seconds; marks flagged in animIdx are mirrored.
    class CAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    CFieldEffectManpuAnger(CEffectActorData *data);
    virtual ~CFieldEffectManpuAnger();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int Draw(Camera2D *camera);
    virtual void SetDepth(fx32 z);

    TFieldParticleSystem<CSoftwareSprite> m_system;
    CEmitter m_emitter;
    CAnimator m_animator;
};

STATIC_SIZE_ASSERT(CFieldEffectManpuAnger, 0x94);

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUANGER_HPP
