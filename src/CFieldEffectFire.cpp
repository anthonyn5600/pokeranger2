// clang-format off
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/TFieldParticle.hpp"

// Data order (traced and modelled, ~/scratch/ov0/f01d4/layout.py): with CFieldEffect and CFieldEffectFactory complete,
// the explicit instantiation makes the emitter template's vtable in the first TU-end walk; that gives the original's
// typeinfo order (factory, animator, effect, emitter). The class order in the header gives the weak D0 order.
template class TFieldParticleEmitter<CSoftwareSprite>;

#include "field/CFieldEffectFire.hpp"
// clang-format on

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"

CFieldEffectFire::CFieldEffectFire(int kind)
    : m_data(NULL)
    , m_cacId(0)
{
    CFieldEffectNormalActorData *data = new CFieldEffectNormalActorData();
    if (data != NULL) {
        data->ov0_021503B8(kind, FALSE);
        CellAnimController *cac = data->GetCac(0);
        if (cac != NULL) {
            m_cacId = cac->Create(1, 0);
        }
        ov0_021423E8(FieldEffectSpriteRes(data->GetNcbr(0), data->GetPalette(), data->GetNcer(0)));
    }
    m_data = data;
    m_emitter.m_lifeMin = 300;
    m_emitter.m_lifeMax = 300;
}

CFieldEffectFire::~CFieldEffectFire()
{
    if (m_data != NULL) {
        CellAnimController *cac = m_data->GetCac(0);
        if (cac != NULL) {
            cac->Remove(m_cacId);
        }
    }
    SAFE_DELETE(m_data);
}

int CFieldEffectFire::SetParam(int param, int value)
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
    case 7:
        break;
    default:
        ret = TFieldEffectParticle<CSoftwareSprite>::SetParam(param, value);
        break;
    }
    return ret;
}

// The particle system update written out as in CFieldEffectDarknessClear2 (shape reconstructed there): the particle
// walk one inline level deep with `next` declared before `p`, the emitter part expanded here. Calling the base
// inline (m_system->Update) swaps p/next registers.
static inline void UpdateParticlesW(TFieldParticleSystem<CSoftwareSprite> *sys, int dt)
{
    TFieldParticle<CSoftwareSprite> *next;
    TFieldParticle<CSoftwareSprite> *p = sys->m_active;
    while (p != NULL) {
        next = p->next;
        if (p->life != 0) {
            if (sys->m_forceField != NULL) {
                sys->m_forceField->Apply(p, dt);
            }
            if (p->life > 0) {
                p->pos += p->vel * (fx64)dt;
                p->rot += (p->rotVel * dt) >> 12;
                p->life -= dt;
                if (p->life < 0) {
                    p->life = 0;
                }
            }
        } else {
            sys->Free(p, next);
        }
        p = next;
    }
}

int CFieldEffectFire::ov0_02142264(int step)
{
    int state = CFieldEffect::ov0_02142264(step);
    if (state != 4 && m_system != NULL) {
        TFieldParticleSystem<CSoftwareSprite> *sys = m_system;
        int dt = step * sys->m_speed;
        UpdateParticlesW(sys, dt);
        u32 total = sys->UpdateEmitters(dt);
        if (total != 0) {
            for (u32 i = 0; i < sys->m_emitterCount; i++) {
                if (sys->m_emitters[i] != NULL && sys->m_emitCounts[i] != 0) {
                    for (u32 j = 0; j < sys->m_emitCounts[i]; j++) {
                        TFieldParticle<CSoftwareSprite> *np = sys->Alloc();
                        if (np != NULL) {
                            TFieldParticleRes<CSoftwareSprite>::Set(np, sys->m_res);
                            sys->m_emitters[i]->Emit(np);
                            if (sys->m_forceField != NULL) {
                                sys->m_forceField->Apply(np, dt);
                            }
                        }
                    }
                }
            }
        }
    }
    if (state != 0 && state != 4 && m_data != NULL) {
        m_data->Update();
        CellAnimController *cac = m_data->GetCac(0);
        if (cac != NULL) {
            m_animator.m_cell = cac->GetCell(m_cacId);
        }
    }
    return state;
}

u32 CFieldEffectFire::CParticleEmitter::Update(int dt)
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

void CFieldEffectFire::CParticleEmitter::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    CGame *game = CGame::GetInstance();
    MATHRandContext32 *rand = &game->m_rand32;
    int life = m_lifeMin + MATH_Rand32(rand, m_lifeMax - m_lifeMin + 1);
    fx32 x = RandCentered(m_width);
    fx32 y = RandCentered(m_height);
    p->pos = (Point2D) { m_pos.x + x, m_pos.y + y };
    p->life = life << 12;
    p->maxLife = life << 12;
    p->vel.x = 0;
    p->vel.y = 0;
    p->rotVel = 0;
    p->sprite.m_z = (((m_width >> 1) + p->pos.y) >> 12) + 0x622;
}

void CFieldEffectFire::CParticleAnimator::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    p->sprite.m_cellDataIdx = m_cell;
}

CFieldEffect *CFieldEffectFireFactory::Create(int arg)
{
    return new CFieldEffectFire(arg);
}
