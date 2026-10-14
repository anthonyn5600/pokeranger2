#ifndef POKERANGER2_FIELD_CFIELDEFFECTFOGCUT_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTFOGCUT_HPP

#include <nitro.h>

#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// clang-format off
#include "field/CFieldEffect.hpp"
// clang-format on

// Explicit instantiation: completes the emitter template here and makes its vtable in the first TU-end pass (the
// TU's data layout depends on both; the member copies it emits are weak and dropped for CFieldEffectWaterGun's).
template class TFieldParticleEmitter<CSoftwareSprite>;

// clang-format off
#include "field/CFieldEffectFootStepSmoke.hpp"
#include "field/CFieldEffectActor.hpp"
// clang-format on

// Fog swirling around m_pos (ov0): particles spawn at a rotating angle and spiral outwards.

class CFieldEffectFogcut : public CFieldEffectActor {
public:
    // Emits the queued spawns (up to 4 per frame).
    class CFPEmitterFogcut : public TFieldParticleEmitter<CSoftwareSprite> {
    public:
        struct Entry {
            int angle;
            Point2D pos;
            u16 color;
        };

        CFPEmitterFogcut()
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

        void Add(int angle, u16 color, fx32 x, fx32 y);

        Entry m_entries[4];
        u8 m_count;
        u8 m_emitIdx;
    };

    // Moves the particles on a growing circle around m_center.
    class CFPForceFieldFogcut : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);

        void Reset(Point2D center)
        {
            m_center = center;
            m_angle = 0;
        }

        u16 m_cell;
        Point2D m_center;
        u16 m_angle;
    };

    CFieldEffectFogcut();
    virtual ~CFieldEffectFogcut();
    virtual int GetEffectId()
    {
        return 0x21;
    }
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142240(int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual void ov0_0214234C(Point2D pos, int arg1, int arg2, int arg3, int arg4);
    virtual int SetParam(int param, int value);

    void AddPoint(int angle, fx32 x, fx32 y);

public:
    Point2D m_pos;
    int m_timer;
    u16 m_angle;
    TFieldParticleSystem<CSoftwareSprite> m_system;
    CFPEmitterFogcut m_emitter;
    CFPForceFieldFogcut m_forceField;
    u16 m_cacId;
};

#include "field/CFieldEffectFactory.hpp"

class CFieldEffectFogcutFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTFOGCUT_HPP
