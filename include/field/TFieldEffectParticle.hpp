#ifndef POKERANGER2_FIELD_TFIELDEFFECTPARTICLE_HPP
#define POKERANGER2_FIELD_TFIELDEFFECTPARTICLE_HPP

#include <nitro.h>

#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/TFieldParticle.hpp"
#include "file/CNCERFile.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Particle effect base (ov0). Slots 24/25 hand the particle system its force field and emitter 0 (names ours).
template <class T>
class TFieldEffectParticle : public CFieldEffect {
public:
    TFieldEffectParticle()
    {
        TFieldParticleRes<T>::Clear(m_res);
    }
    virtual ~TFieldEffectParticle()
    {
        SAFE_DELETE(m_system);
    }
    virtual BOOL Start(int inTime, int holdTime, int outTime)
    {
        TFieldParticleEmitter<T> *emitter = GetEmitter();
        if (emitter != NULL) {
            emitter->func2();
        }
        return CFieldEffect::Start(inTime, holdTime, outTime);
    }
    virtual int Update(int step)
    {
        int state = CFieldEffect::Update(step);
        if (state != 4 && m_system != NULL) {
            m_system->Update(step);
        }
        return state;
    }

    virtual void SetParticleRes(const typename TFieldParticleRes<T>::Type &res)
    {
        m_res = res;
        if (m_system != NULL) {
            m_system->m_res = m_res;
        }
    }

    virtual int SetParam(int param, int value)
    {
        int ret = 0;
        switch (param) {
        case 0:
            if (value > 0) {
                SAFE_DELETE(m_system);
                m_system = new TFieldParticleSystem<T>(1, value);
                if (m_system != NULL) {
                    m_system->SetEmitter(0, GetEmitter());
                    m_system->m_forceField = GetForceField();
                    m_system->m_res = m_res;
                }
            }
            ret = 1;
            break;
        case 1:
            if (m_system != NULL) {
                m_system->m_offset.x = value << 12;
            }
            break;
        case 2:
            if (m_system != NULL) {
                m_system->m_offset.y = value << 12;
            }
            break;
        }
        return ret;
    }
    virtual int Render(Camera2D *camera)
    {
        if (m_system != NULL) {
            m_system->Draw(camera);
        }
        return 0;
    }
    virtual TFieldParticleForceField<T> *GetForceField() = 0;
    virtual TFieldParticleEmitter<T> *GetEmitter() = 0;

    TFieldParticleSystem<T> *m_system;
    typename TFieldParticleRes<T>::Type m_res;
};

// Emits m_count particles every m_interval seconds (m_mode picks the start velocity).
template <class T>
class TFieldParticleSmokeRectEmitter : public TFieldParticleRectEmitter<T> {
public:
    TFieldParticleSmokeRectEmitter(int mode)
    {
        m_timer = 0;
        m_interval = 0;
        m_mode = mode;
        m_lifeMin = 10;
        m_lifeMax = 15;
        m_count = 0x10;
        m_colorMode = 0;
        m_vel.x = 0;
        m_vel.y = -0x800;
        m_polygonID = 0;
    }
    virtual void func2();
    virtual void Stop();
    virtual u32 Update(int dt);
    virtual void Emit(TFieldParticle<T> *p);

    fx32 m_timer;
    int m_interval;
    int m_mode;
    int m_lifeMin;
    int m_lifeMax;
    u32 m_count;
    int m_colorMode;
    Point2D m_vel;
    u8 m_polygonID;
};
template <class T>
void TFieldParticleSmokeRectEmitter<T>::func2()
{
    m_timer = 0x1000;
}

template <class T>
void TFieldParticleSmokeRectEmitter<T>::Stop()
{
    m_timer = 0;
}

template <class T>
u32 TFieldParticleSmokeRectEmitter<T>::Update(int dt)
{
    u32 count = 0;
    if (m_timer > 0) {
        m_timer -= dt;
        if (m_timer <= 0) {
            count = m_count;
            if (m_interval > 0) {
                m_timer = m_interval << 12;
            }
        }
    }
    return count;
}

template <class T>
void TFieldParticleSmokeRectEmitter<T>::Emit(TFieldParticle<T> *p)
{
    CGame *game = CGame::GetInstance();
    MATHRandContext32 *rand = &game->m_rand32;
    int life = m_lifeMin + MATH_Rand32(rand, m_lifeMax - m_lifeMin + 1);
    fx32 x = RandCentered(m_width);
    fx32 y = RandCentered(m_height);
    p->pos = (Point2D) { this->m_pos.x + x, this->m_pos.y + y };
    p->life = life << 12;
    p->maxLife = life << 12;
    TFieldParticleRes<T>::SetCell(p, 1);
    u8 id = m_polygonID++;
    p->sprite.m_polygonID = id + 8;
    m_polygonID &= 0x1F;
    switch (m_colorMode) {
    case 0:
        p->sprite.m_color = 0x439C;
        break;
    case 1:
    default:
        p->sprite.m_color = 0x7FFF;
        break;
    }
    fx32 vx;
    fx32 vy;
    switch (m_mode) {
    case 2:
        if (p->pos.x == 0) {
            MATHRandContext32 *rand = &game->m_rand32;
            switch (MATH_Rand32(rand, 3)) {
            case 0:
                vx = 0;
                break;
            case 1:
                vx = 0x1000;
                break;
            case 2:
                vx = -0x1000;
                break;
            }
        } else {
            vx = p->pos.x < 0 ? -0x1000 : 0x1000;
        }
        if (p->pos.y == 0) {
            MATHRandContext32 *rand = &game->m_rand32;
            switch (MATH_Rand32(rand, 3)) {
            case 0:
                vy = vx == 0 ? 0x1000 : 0;
                break;
            case 1:
                vy = 0x1000;
                break;
            case 2:
                vy = -0x1000;
                break;
            }
        } else {
            vx = p->pos.y < 0 ? -0x800 : 0x800;
        }
        break;
    case 1:
    default:
        vx = m_vel.x;
        vy = m_vel.y;
        break;
    case 3: {
        MATHRandContext32 *rand = &game->m_rand32;
        vx = MATH_Rand32(rand, 0x333) - 0x199;
        vy = m_vel.y;
        break;
    }
    }
    p->vel.x = vx;
    p->vel.y = vy;
    p->rotVel = 0;
}

// Smoke particle effect (ov0, CFieldEffectSteam / CFieldEffectVolcanicSteam): owns its emitter (slot 25 returns it).
template <class T>
class TFieldEffectSmoke : public TFieldEffectParticle<T> {
public:
    TFieldEffectSmoke(int mode);
    virtual ~TFieldEffectSmoke();
    virtual int SetParam(int param, int value);
    virtual TFieldParticleEmitter<T> *GetEmitter();

    TFieldParticleSmokeRectEmitter<T> m_emitter;
};

template <class T>
TFieldEffectSmoke<T>::TFieldEffectSmoke(int mode)
    : m_emitter(mode)
{
    m_emitter.m_lifeMin = 0x3C;
    m_emitter.m_lifeMax = 0x78;
    m_emitter.m_colorMode = 1;
}

template <class T>
TFieldEffectSmoke<T>::~TFieldEffectSmoke()
{
}

template <class T>
int TFieldEffectSmoke<T>::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 5:
        m_emitter.m_interval = value;
        break;
    case 6:
        m_emitter.m_count = value;
        break;
    case 3:
        m_emitter.m_width = value << 12;
        break;
    case 4:
        m_emitter.m_height = value << 12;
        break;
    case 8:
        m_emitter.m_lifeMin = value;
        m_emitter.m_lifeMax = value;
        break;
    default:
        ret = TFieldEffectParticle<T>::SetParam(param, value);
        break;
    }
    return ret;
}

template <class T>
TFieldParticleEmitter<T> *TFieldEffectSmoke<T>::GetEmitter()
{
    return &m_emitter;
}

#endif // POKERANGER2_FIELD_TFIELDEFFECTPARTICLE_HPP
