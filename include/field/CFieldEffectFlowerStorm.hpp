#ifndef POKERANGER2_FIELD_CFIELDEFFECTFLOWERSTORM_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTFLOWERSTORM_HPP

#include <nitro.h>

// clang-format off
#include "field/CFieldEffect.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// The original completes the particle emitter template between CFieldEffect and CFieldEffectActor: the TU-end
// typeinfo/vtable creation order decides the data layout. How it did that is unknown; this size check does the same.
STATIC_SIZE_ASSERT(TFieldParticleEmitter<CSoftwareSprite>, 0x18);

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
// clang-format on

// Petals swirling around m_pos (ov0): bursts of 1..5 particles on an elliptic, growing orbit.

class CFieldEffectFlowerStorm : public CFieldEffectActor {
public:
    // Emits the queued spawns (up to 6 per frame).
    class CFPEmitterFlowerStorm : public TFieldParticleEmitter<CSoftwareSprite> {
    public:
        struct Entry {
            Point2D pos;
            int angle;
        };

        CFPEmitterFlowerStorm()
        {
            unk_60 = 0;
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

        void Add(fx32 x, fx32 y, int angle);

        Entry m_entries[6];
        u8 unk_60;
        u8 m_count;
        u8 m_emitIdx;
    };

    // Moves the particles on an ellipse around m_center that grows with age.
    class CFPForceFieldFlowerStorm : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);

        void Step(int step);
        void Reset(Point2D center)
        {
            m_center = center;
            m_angle = 0;
        }

        u16 unk_04;
        Point2D m_center;
        u16 m_angle;
        int unk_14;
    };

    CFieldEffectFlowerStorm();
    virtual ~CFieldEffectFlowerStorm();
    virtual int GetEffectId()
    {
        return 0x1D;
    }
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142240(int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual void ov0_0214234C(Point2D pos, int arg1, int arg2, int arg3, int arg4);
    virtual int SetParam(int param, int value);

public:
    Point2D m_pos;
    int m_timer;
    u16 m_angle;
    TFieldParticleSystem<CSoftwareSprite> m_system;
    CFPEmitterFlowerStorm m_emitter;
    CFPForceFieldFlowerStorm m_forceField;
};

#include "field/CFieldEffectFactory.hpp"

class CFieldEffectFlowerStormFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTFLOWERSTORM_HPP
