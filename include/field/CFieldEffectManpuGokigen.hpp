#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUGOKIGEN_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUGOKIGEN_HPP

#include <nitro.h>

#include "field/CFieldEffectManpu.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Happy marks (manpu) floating up from an actor's head; type 11 cycles their colour through a rainbow.
class CFieldEffectManpuGokigen : public CFieldEffectManpu {
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

    // Sways the marks sideways while they rise and fades them out; type 11 blends their colour.
    class CAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        CAnimator()
        {
            m_type = 0;
            m_frame = 0;
            m_timer = 0;
        }

        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);

        void Step(int dt);

        int m_type;
        int m_frame;
        int m_timer;
    };

    CFieldEffectManpuGokigen(CEffectActorData *data);
    virtual ~CFieldEffectManpuGokigen();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual void SetType(int type);
    virtual int Draw(Camera2D *camera);
    virtual void SetDepth(fx32 z);

    TFieldParticleSystem<CSoftwareSprite> m_system;
    CEmitter m_emitter;
    CAnimator m_animator;
};

STATIC_SIZE_ASSERT(CFieldEffectManpuGokigen, 0xA0);

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUGOKIGEN_HPP
