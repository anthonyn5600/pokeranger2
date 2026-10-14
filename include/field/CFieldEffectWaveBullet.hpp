#ifndef POKERANGER2_FIELD_CFIELDEFFECTWAVEBULLET_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTWAVEBULLET_HPP

#include <nitro.h>

#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// The original completes the emitter template, then the factory classes, then the effect classes: the TU-end
// typeinfo/vtable creation order decides the data layout. The size check stands in for the unknown first step.
template class TFieldParticleEmitter<CSoftwareSprite>;

// clang-format off
#include "field/CFieldEffectFactory.hpp"
class CFieldEffectWaveBulletFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#include "field/CFieldEffectActor.hpp"
// clang-format on

STATIC_SIZE_ASSERT(TFieldParticleForceField<CSoftwareSprite>, 0x4);

// Particle stream from m_emitter.m_pos towards its target whose direction swings back and forth (ov0); the
// attack effect m_kind provides the sprites.
class CFieldEffectWaveBullet : public CFieldEffectActor {
public:
    // Emits one particle every m_interval frames along m_dir +/- the swinging m_phase.
    class CWaveParticleEmitter : public TFieldParticleEmitter<CSoftwareSprite> {
    public:
        CWaveParticleEmitter()
        {
            m_period = 0;
            m_amp = 0;
            m_dir = 0;
            m_phase = 0;
            m_phaseStep = 0;
            m_speed = 0x1000;
            m_interval = 0;
            m_timer = 0;
            m_life = 0x3C000;
            m_rotVel = 0;
        }
        virtual void func2();
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);

        Point2D m_target;
        int m_period;
        int m_amp;
        int m_dir;
        int m_phase;
        int m_phaseStep;
        fx32 m_speed;
        int m_interval;
        fx32 m_timer;
        fx32 m_life;
        u16 m_rotVel;
    };

    // Sets the cell and grows the particles from m_scaleStart to m_scaleEnd.
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

    CFieldEffectWaveBullet(int kind);
    virtual ~CFieldEffectWaveBullet();
    virtual int GetEffectId();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int SetParam(int param, int value);
    virtual void sub_0203365C(int arg0);

public:
    int m_kind;
    u16 m_cacId;
    int m_se;
    TFieldParticleSystem<CSoftwareSprite> m_system;
    CWaveParticleEmitter m_emitter;
    CWaveParticleAnimator m_animator;
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTWAVEBULLET_HPP
