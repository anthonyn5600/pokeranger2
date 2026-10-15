#ifndef POKERANGER2_FIELD_CFIELDEFFECTSPRAY_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSPRAY_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Spray of particles from m_emitter.m_pos towards its target (ov0): every other burst emits two particles spread
// randomly around the direction, the ones between emit one straight particle.
class CFieldEffectSpray : public CFieldEffectActor {
public:
    // Emits m_interval frames apart, alternating a single particle and a randomly spread pair.
    class CWaveParticleEmitter : public TFieldParticleEmitter<CSoftwareSprite> {
    public:
        CWaveParticleEmitter()
        {
            unk_20 = 0;
            m_dir = 0;
            m_speed = 0x1000;
            m_interval = 0;
            m_timer = 0;
            m_life = 0x3C000;
            m_rotVel = 0;
            m_spread = 0;
        }
        virtual void func2();
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);

        Point2D m_target;
        int unk_20;
        int m_dir;
        fx32 m_speed;
        int m_interval;
        fx32 m_timer;
        fx32 m_life;
        u16 m_rotVel;
        u16 m_spread;
        int m_offsets[3];
        int m_index;
    };

    // Sets the cell, grows the particles from m_scaleStart to m_scaleEnd and fades them out over their last 16 frames.
    class CWaveParticleAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        CWaveParticleAnimator()
        {
            m_cell = 0;
            m_scaleStart = 0x1000;
            m_scaleEnd = 0x1000;
        }
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);

        u16 m_cell;
        fx32 m_scaleStart;
        fx32 m_scaleEnd;
    };

    CFieldEffectSpray(int kind);
    virtual ~CFieldEffectSpray();
    virtual int GetEffectId();
    virtual BOOL Start(int inTime, int holdTime, int outTime);
    virtual int Update(int step);
    virtual int Render(Camera2D *camera);
    virtual int SetParam(int param, int value);

public:
    int m_kind;
    u16 m_cacId;
    TFieldParticleSystem<CSoftwareSprite> m_system;
    CWaveParticleEmitter m_emitter;
    CWaveParticleAnimator m_animator;
};
STATIC_SIZE_ASSERT(CFieldEffectSpray, 0xBC);

class CFieldEffectSprayFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTSPRAY_HPP
