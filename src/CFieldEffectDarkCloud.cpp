#include "field/CFieldEffectDarkCloud.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"

CFieldEffectDarkCloud::CFieldEffectDarkCloud(int mode)
    : m_polygonID(0)
    , m_emitter(&m_polygonID)
    , m_remains(1, 16)
    , m_remainsEmitter(&m_polygonID)
{
    m_emitter.m_width = 0x20000;
    m_emitter.m_height = 0x20000;
    m_emitter.m_interval = 15;
    m_emitter.m_count = 2;
    switch (mode) {
    case 0:
    default:
        SetParam(0, 32);
        m_animator.m_scaleStart = 0x1333;
        m_animator.m_scaleEnd = 0x2000;
        break;
    case 1:
        SetParam(0, 16);
        m_animator.m_scaleStart = 0x1999;
        m_animator.m_scaleEnd = 0x2000;
        break;
    }
    m_remainsEmitter.m_width = 0x20000;
    m_remainsEmitter.m_height = 0x20000;
    m_remainsEmitter.m_interval = 20;
    m_remainsEmitter.m_count = 1;
    m_remains.SetEmitter(0, &m_remainsEmitter);
    m_remains.m_forceField = &m_remainsAnimator;
}

CFieldEffectDarkCloud::~CFieldEffectDarkCloud()
{
}

void CFieldEffectDarkCloud::SetRes(VramImage *ncbr, VramPalette *palette, CNCERFile *ncer)
{
    m_remains.m_res.ncbr = ncbr;
    m_remains.m_res.palette = palette;
    m_remains.m_res.ncer = ncer;
    SetParticleRes(FieldEffectSpriteRes(ncbr, palette, ncer));
}

int CFieldEffectDarkCloud::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 3:
        m_emitter.m_width = value << 12;
        break;
    case 4:
        m_emitter.m_height = value << 12;
        break;
    case 20:
        m_system->m_speed = value << 12;
        break;
    default:
        ret = TFieldEffectParticle<CSoftwareSprite>::SetParam(param, value);
        break;
    }
    return ret;
}

// The base particle system update written out as in CFieldEffectFire (shape from CFieldEffectDarknessClear2): the
// particle walk one inline level deep with `next` declared before `p`, the emitter part expanded at the caller.
// Calling the base inline (TFieldEffectParticle::Update) swaps p/next registers.
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

BOOL CFieldEffectDarkCloud::Start(int inTime, int holdTime, int outTime)
{
    BOOL ret = TFieldEffectParticle<CSoftwareSprite>::Start(inTime, holdTime, outTime);
    for (int n = 0; n < 100; n++) {
        int state = CFieldEffect::Update(3);
        if (state != 4 && m_system != NULL) {
            TFieldParticleSystem<CSoftwareSprite> *sys = m_system;
            int dt = 3 * sys->m_speed;
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
    }
    return ret;
}

int CFieldEffectDarkCloud::Update(int step)
{
    if (m_mover.Update(step)) {
        m_system->m_offset = m_mover.cur;
        m_remainsEmitter.m_pos = m_mover.cur;
    } else {
        m_remainsEmitter.Stop();
    }
    m_remains.Update(step);
    int state = CFieldEffect::Update(step);
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
    return state;
}

int CFieldEffectDarkCloud::Render(Camera2D *camera)
{
    m_remains.Draw(camera);
    return TFieldEffectParticle<CSoftwareSprite>::Render(camera);
}

void CFieldEffectDarkCloud::MoveTo(const Point2D &pos, int arg1)
{
    m_mover.Start(m_system->m_offset, pos, arg1);
    m_remainsEmitter.func2();
}

void CFieldEffectDarkCloud::CAnimator::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    fx32 maxLife = p->maxLife;
    fx32 elapsed = maxLife - p->life;
    fx32 range = m_scaleEnd - m_scaleStart;
    fx32 scale = m_scaleStart + FX32_DIV(FX32_MUL(range, elapsed), maxLife);
    if (elapsed > 0x3C000) {
        fx32 vy = p->vel.y;
        fx32 vx = p->vel.x;
        fx32 d = FX32_MUL(dt, 0x14);
        fx32 x = p->pos.x < 0 ? vx + d : vx - d;
        // The first store is dead, but its use keeps vx a variable (PCode copy propagation stops at it),
        // which gives d, vy, vx the original's registers.
        p->vel.x = vx;
        p->vel.x = x;
        p->vel.y = vy;
        if (p->life < 0x1E000) {
            p->sprite.m_alpha = FX32_DIV(FX32_MUL(p->life, 0x14000), 0x1E000) >> 12;
        }
    } else {
        p->sprite.m_alpha = FX32_DIV(FX32_MUL(elapsed, 0x14000), 0x3C000) >> 12;
    }
    p->sprite.m_scale[0] = scale;
    p->sprite.m_scale[1] = scale;
}

void CFieldEffectDarkCloud::CEmitter::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    fx32 x = RandCentered(m_width);
    fx32 y = RandCentered(m_height);
    p->pos = (Point2D) { m_pos.x + x, m_pos.y + y };
    p->life = 0x12C000;
    p->maxLife = 0x12C000;
    p->sprite.m_cellDataIdx = 6;
    p->sprite.m_color = 0;
    u8 *next = m_nextPolygonID;
    u8 id = (*next)++;
    *next &= 0x1F;
    p->sprite.m_polygonID = id + 8;
    p->sprite.m_z = -1;
    p->sprite.m_alpha = 20;
    if (p->pos.x >= 0) {
        p->vel.x = 0xCC;
    } else {
        p->vel.x = -0xCC;
    }
    p->vel.y = -0xCC;
    CGame *game = CGame::GetInstance();
    MATHRandContext32 *rand = &game->m_rand32;
    int deg = MATH_Rand32(rand, 7) - 3;
    p->rotVel = deg;
    p->rotVel = (deg << 16) / 360;
}

void CFieldEffectDarkCloud::CRemainsEmitter::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    fx32 x = RandCentered(m_width);
    fx32 y = RandCentered(m_height);
    p->pos = (Point2D) { m_pos.x + x, m_pos.y + y };
    p->life = 0x78000;
    p->maxLife = 0x78000;
    p->sprite.m_cellDataIdx = 6;
    p->sprite.m_color = 0;
    u8 *next = m_nextPolygonID;
    u8 id = (*next)++;
    *next &= 0x1F;
    p->sprite.m_polygonID = id + 8;
    p->sprite.m_alpha = 20;
    p->sprite.m_z = -1;
    p->vel.x = 0;
    p->vel.y = 0x333;
    CGame *game = CGame::GetInstance();
    MATHRandContext32 *rand = &game->m_rand32;
    int deg = MATH_Rand32(rand, 7) - 3;
    p->rotVel = deg;
    p->rotVel = (deg << 16) / 360;
}

void CFieldEffectDarkCloud::CRemainsAnimator::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    fx32 maxLife = p->maxLife;
    fx32 scale = FX32_DIV(FX32_MUL(maxLife - p->life, 0x667), maxLife) + 0x1999;
    p->sprite.m_scale[0] = scale;
    p->sprite.m_scale[1] = scale;
    if (p->life < 0x1E000) {
        p->sprite.m_alpha = FX32_DIV(FX32_MUL(p->life, 0x14000), 0x1E000) >> 12;
    }
}

CFieldEffect *CFieldEffectDarkCloudFactory::Create(int arg)
{
    CFieldEffectDarkCloud *effect = new CFieldEffectDarkCloud(arg);
    CFieldEffectManage *mgr;
    if (effect != NULL && (mgr = MAIN_BSS_0210CA60) != NULL) {
        CNCERFile *ncer = mgr->m_resident.GetNcer(0);
        VramPalette *palette = mgr->m_resident.GetPalette();
        effect->SetRes(mgr->m_resident.GetNcbr(0), palette, ncer);
    }
    return effect;
}

TFieldParticleEmitter<CSoftwareSprite> *CFieldEffectDarkCloud::GetEmitter()
{
    return &m_emitter;
}

TFieldParticleForceField<CSoftwareSprite> *CFieldEffectDarkCloud::GetForceField()
{
    return &m_animator;
}

int CFieldEffectDarkCloud::GetEffectId()
{
    return 0x14;
}

// Never called (mwld strips it): makes CAnimator's implicit D0 come out here, first of the TU's D0 tail as in the
// original (rule E-WEAK-TAIL-WALK; the three virtuals above are out of line so they stay before it).
static void DeleteAnimator(CFieldEffectDarkCloud::CAnimator *animator)
{
    delete animator;
}
