#ifndef POKERANGER2_FIELD_CFIELDEFFECTFIRE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTFIRE_HPP

#include <nitro.h>

#include "CEffectActorData.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Flames rising from a rectangle (ov0): still particles drawn in front of what lies below their base, animated by the
// effect's cell animation.
class CFieldEffectFire : public TFieldEffectParticle<CSoftwareSprite> {
public:
    // Emits m_count flames every m_interval seconds, living m_lifeMin..m_lifeMax frames.
    class CParticleEmitter : public TFieldParticleRectEmitter<CSoftwareSprite> {
    public:
        CParticleEmitter()
        {
            m_timer = 0;
            m_interval = 0;
            m_lifeMin = 0;
            m_lifeMax = 0;
            m_count = 0x10;
        }
        virtual void func2()
        {
            m_timer = 0x1000;
        }
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);

        fx32 m_timer;
        int m_interval;
        int m_lifeMin;
        int m_lifeMax;
        u32 m_count;
    };

    // Sets the current cell of the effect's animation.
    class CParticleAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        CParticleAnimator()
        {
            m_cell = 0;
        }
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);

        u16 m_cell;
    };

    CFieldEffectFire(int kind);
    virtual ~CFieldEffectFire();
    virtual int GetEffectId()
    {
        return 0x11;
    }
    virtual int IsReady()
    {
        BOOL ret = TRUE;
        if (m_data != NULL && !m_data->IsLoaded()) {
            ret = FALSE;
        }
        return ret;
    }
    virtual int ov0_02142264(int step);
    virtual int SetParam(int param, int value);
    // Declared in reverse: the inline virtuals are emitted in reverse declaration order.
    virtual TFieldParticleEmitter<CSoftwareSprite> *GetEmitter()
    {
        return &m_emitter;
    }
    virtual TFieldParticleForceField<CSoftwareSprite> *GetForceField()
    {
        return &m_animator;
    }

    CParticleEmitter m_emitter;
    CParticleAnimator m_animator;
    CEffectActorData *m_data;
    u16 m_cacId;
};
STATIC_SIZE_ASSERT(CFieldEffectFire, 0x7C);

class CFieldEffectFireFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTFIRE_HPP
