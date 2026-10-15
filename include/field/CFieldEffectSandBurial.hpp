#ifndef POKERANGER2_FIELD_CFIELDEFFECTSANDBURIAL_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSANDBURIAL_HPP

#include <nitro.h>

// clang-format off
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFootStepSmoke.hpp"
#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
// clang-format on
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Sand puffs around m_center (ov0): every other frame while holding, queues one particle at a random offset.
class CFieldEffectSandBurial : public CFieldEffectActor {
public:
    // Emits the queued points (up to 8 per frame).
    class CFPEmitterSandBurial : public TFieldParticleEmitter<CSoftwareSprite> {
    public:
        struct Entry {
            Point2D pos;
            u16 color;
        };

        CFPEmitterSandBurial()
        {
            m_count = 0;
            m_emitIdx = 0;
        }

        virtual u32 Update(int dt)
        {
            u32 count = m_count;
            m_count = 0;
            m_emitIdx = 0;
            return count;
        }
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);

        void Add(u16 color, fx32 x, fx32 y);

        Entry m_entries[8];
        u8 m_count;
        u8 m_emitIdx;
    };

    // Grows the particles with age and fades them out.
    class CFPForceFieldSandBurial : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    CFieldEffectSandBurial();
    virtual ~CFieldEffectSandBurial();
    virtual int GetEffectId()
    {
        return 0x1F;
    }
    virtual int Update(int step);
    virtual int Render(Camera2D *camera);
    virtual void StartAt(Point2D pos, int arg1, int arg2, int arg3, int arg4);

    void AddPoint(fx32 x, fx32 y);

public:
    Point2D m_center;
    int m_timer;
    TFieldParticleSystem<CSoftwareSprite> m_system;
    CFPEmitterSandBurial m_emitter;
    CFPForceFieldSandBurial m_forceField;
};

class CFieldEffectSandBurialFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTSANDBURIAL_HPP
