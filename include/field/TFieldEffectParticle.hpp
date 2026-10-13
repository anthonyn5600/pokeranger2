#ifndef POKERANGER2_FIELD_TFIELDEFFECTPARTICLE_HPP
#define POKERANGER2_FIELD_TFIELDEFFECTPARTICLE_HPP

#include <nitro.h>

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/TFieldParticle.hpp"
#include "file/CNCERFile.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Particle effect base (ov0). Slots 24/25 hand the particle system its force field and emitter 0 (names ours).
template <class T>
class TFieldEffectParticle : public CFieldEffect {
public:
    virtual ~TFieldEffectParticle();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step)
    {
        int state = CFieldEffect::ov0_02142264(step);
        if (state != 4 && m_system != NULL) {
            m_system->Update(step);
        }
        return state;
    }

    virtual void ov0_021423E8(const FieldEffectSpriteRes &res)
    {
        m_res = res;
        if (m_system != NULL) {
            m_system->m_res = m_res;
        }
    }

    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual TFieldParticleForceField<T> *GetForceField() = 0;
    virtual TFieldParticleEmitter<T> *GetEmitter() = 0;

    TFieldParticleSystem<T> *m_system;
    FieldEffectSpriteRes m_res;
};

// Smoke particle effect (ov0, CFieldEffectSteam / CFieldEffectVolcanicSteam): owns its emitter (slot 25 returns it).
template <class T>
class TFieldEffectSmoke : public TFieldEffectParticle<T> {
public:
    virtual ~TFieldEffectSmoke();
    virtual int sub_0203312C(int param, int value);
    virtual TFieldParticleEmitter<T> *GetEmitter();
};

#endif // POKERANGER2_FIELD_TFIELDEFFECTPARTICLE_HPP
