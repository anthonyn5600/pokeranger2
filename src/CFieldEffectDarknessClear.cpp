#include "field/CFieldEffectDarknessClear.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "Camera2D.hpp"
#include "MathUtil.hpp"
#include "file/CArchiveGuard.hpp"
#include "fx_utils.hpp"

// Built through meson.build's pokeranger2_ov0_darkness targets, not src/meson.build: the original TU's .data order
// came from a size sort that included two objects the linker later dropped, so the equal-size typeinfos/vtables are
// put in the original order after compiling (tools/elfdataorder/CFieldEffectDarknessClear.txt), and the
// <CSimpleSpriteNTF> template copies that ov3's COPDTitleScreen also emits get overlay 0's own names.

static Point2D sDarknessClearPoints[32] = {
    { -0x49600, -0x56A00 },
    { -0x36980, -0x4D9A0 },
    { 0x1AD80, -0x516F0 },
    { 0x60080, -0x35640 },
    { -0x7B9C0, -0x6150 },
    { -0x28840, -0x29610 },
    { 0x2140, -0xCFC0 },
    { 0x45140, -0x15BD0 },
    { -0x43300, 0x5190 },
    { -0x32C40, 0x1CF80 },
    { 0xD080, 0x18570 },
    { 0x59FC0, 0x2E380 },
    { -0x73680, 0x40AD0 },
    { -0x21500, 0x37050 },
    { 0x1EFC0, 0x5B680 },
    { 0x53300, 0x361B0 },
    { -0x76100, -0x42B10 },
    { -0xF980, -0x43C20 },
    { 0x18640, -0x556E0 },
    { 0x58400, -0x59BB0 },
    { -0x5E2C0, -0x5CA0 },
    { -0xD240, -0x25D40 },
    { 0x30140, -0x11A30 },
    { 0x6B4C0, -0x2B050 },
    { -0x62B40, 0x12EA0 },
    { -0x2A700, 0x1E9F0 },
    { 0x24880, 0x2C310 },
    { 0x68140, 0x19B0 },
    { -0x416C0, 0x56E50 },
    { -0x2DA00, 0x4BCF0 },
    { 0x5280, 0x33090 },
    { 0x5B580, 0x45D20 }
};

CFieldEffectDarknessClear::CFieldEffectDarknessClear(int kind)
{
    unk_A8 = 0;
    Load();
    SetParam(0, 0x30);
    SetParam(3, 0x100);
    SetParam(4, 0xC0);
    m_emitter.m_count = 0x20;
}

CFieldEffectDarknessClear::~CFieldEffectDarknessClear()
{
}

void CFieldEffectDarknessClear::Load()
{
    CArchiveGuard guard("MEF", "data/Field/Effect/ef102_LZ.bin", 1, 1, 0, NULL, 0);
    m_texture.Load("MEF:ef102_00.ntft", "MEF:ef102_00.ntfp", 0);
    m_texture.m_texFmt = GX_TEXFMT_A5I3;
    m_texture.m_sizeS = GX_TEXSIZE_S32;
    m_texture.m_sizeT = GX_TEXSIZE_T32;
    NtfTextureParam *texture = &m_texture;
    ov0_021423E8(texture);
}

int CFieldEffectDarknessClear::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 3:
        m_emitter.m_width = value << 12;
        break;
    case 4:
        m_emitter.m_height = value << 12;
        break;
    case 1:
    case 2:
        break;
    default:
        ret = TFieldEffectParticle<CSimpleSpriteNTF>::SetParam(param, value);
        break;
    }
    return ret;
}

template TFieldParticle<CSimpleSpriteNTF>::~TFieldParticle();
template TFieldParticle<CSimpleSpriteNTF>::TFieldParticle();

BOOL CFieldEffectDarknessClear::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    if (outTime <= 0) {
        outTime = 0xB4;
    }
    m_emitter.m_lifeMin = holdTime;
    m_emitter.m_lifeMax = outTime;
    m_forceField.m_delay = holdTime << 12;
    return TFieldEffectParticle<CSimpleSpriteNTF>::ov0_021421F0(0, holdTime, outTime);
}

template void TFieldParticleEmitter<CSimpleSpriteNTF>::func2();

int CFieldEffectDarknessClear::ov0_02142344(Camera2D *camera)
{
    TFieldParticleSystem<CSimpleSpriteNTF> *system = m_system;
    if (system != NULL) {
        system->m_offset.x = -camera->unk_1C;
        system->m_offset.y = -camera->unk_20;
    }
    return TFieldEffectParticle<CSimpleSpriteNTF>::ov0_02142344(camera);
}

void CFieldEffectDarknessClear::CForceField::Apply(TFieldParticle<CSimpleSpriteNTF> *p, int dt)
{
    fx32 elapsed = p->maxLife - p->life;
    if (elapsed < m_delay) {
        return;
    }
    p->sprite.SetScale(p->sprite.m_scale[0] + 0x28, p->sprite.m_scale[1] + 0x28);
    p->sprite.m_alpha = FX32_DIV(p->life * 31, p->maxLife) >> 12;
    if (p->vel.x != 0) {
        return;
    }
    fx32 remain = p->maxLife - elapsed;
    CGame *game = CGame::GetInstance();
    MATHRandContext32 *rand = &game->m_rand32;
    int r = MATH_Rand32(rand, 0x80) + 0x40;
    fx32 speed = FX32_DIV(r << 12, remain);
    if (p->animIdx == 0) {
        p->vel.x = -speed;
        p->vel.y = 0;
    } else {
        p->vel.x = speed;
        p->vel.y = 0;
    }
}

void CFieldEffectDarknessClear::CEmitter::Emit(TFieldParticle<CSimpleSpriteNTF> *p)
{
    fx32 w = m_width >> 2;
    fx32 h = m_height >> 2;
    fx32 rx = RandCentered(w);
    fx32 ry = RandCentered(h);
    u8 cell = m_cell;
    fx32 gx = (cell & 3) * w - (m_width >> 1) + (w >> 1);
    fx32 gy = (cell >> 2) * h - (m_height >> 1) + (h >> 1);
    m_cell++;
    m_cell &= 0xF;
    p->pos = (Point2D) { gx + (m_pos.x + rx), gy + (m_pos.y + ry) };
    int life = m_lifeMin + MATH_Rand32(&CGame::GetInstance()->m_rand32, m_lifeMax - m_lifeMin + 1);
    p->life = life << 12;
    p->maxLife = life << 12;
    p->sprite.m_color = 0;
    p->sprite.m_alpha = 0x1F;
    p->sprite.m_z = -1;
    p->rotVel = 0;
    p->sprite.SetTexCoords(0, 0, 0x20000, 0x20000);
    p->sprite.unk_4C = 0x20000;
    p->sprite.unk_50 = 0x20000;
    fx32 scale = MATH_Rand32(&CGame::GetInstance()->m_rand32, 0xC01) + 0x1800;
    p->sprite.m_scale[0] = FX32_MUL(scale, MATH_Rand32(&CGame::GetInstance()->m_rand32, 0x801) + 0x1800);
    p->sprite.m_scale[1] = scale;
    int dir;
    if (p->pos.x < -0x20000) {
        dir = 0;
    } else if (p->pos.x > 0x20000) {
        dir = 1;
    } else if (MATH_Rand32(&CGame::GetInstance()->m_rand32, 2) != 0) {
        dir = 0;
    } else {
        dir = 1;
    }
    p->sprite.m_polygonID = m_polyCounter + 8;
    m_polyCounter++;
    m_polyCounter &= 0x1F;
    p->vel.x = 0;
    p->vel.y = 0;
    p->animIdx = dir;
}

CFieldEffectDarknessClear2::CFieldEffectDarknessClear2(int kind)
{
    unk_B4 = 0;
    Load();
    SetParam(0, 0x20);
    SetParam(3, 0x100);
    SetParam(4, 0xC0);
    m_emitter.m_count = 0x20;
}

CFieldEffectDarknessClear2::~CFieldEffectDarknessClear2()
{
}

void CFieldEffectDarknessClear2::Load()
{
    CArchiveGuard guard("MEF", "data/Field/Effect/ef102_LZ.bin", 1, 1, 0, NULL, 0);
    m_texture.Load("MEF:ef102_00.ntft", "MEF:ef102_00.ntfp", 0);
    m_texture.m_texFmt = GX_TEXFMT_A5I3;
    m_texture.m_sizeS = GX_TEXSIZE_S32;
    m_texture.m_sizeT = GX_TEXSIZE_T32;
    NtfTextureParam *texture = &m_texture;
    ov0_021423E8(texture);
}

int CFieldEffectDarknessClear2::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 3:
        m_emitter.m_width = value << 12;
        break;
    case 4:
        m_emitter.m_height = value << 12;
        break;
    case 1:
    case 2:
        break;
    default:
        ret = TFieldEffectParticle<CSimpleSpriteNTF>::SetParam(param, value);
        break;
    }
    return ret;
}

BOOL CFieldEffectDarknessClear2::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    if (outTime <= 0) {
        outTime = 0xB4;
    }
    m_emitter.m_lifeMin = holdTime;
    m_emitter.m_lifeMax = outTime;
    m_forceField.m_delay = holdTime << 12;
    m_forceField.m_center = m_emitter.m_pos;
    return TFieldEffectParticle<CSimpleSpriteNTF>::ov0_021421F0(0, holdTime, outTime);
}

// DC2 runs the particle system update itself instead of calling the base inline. Reconstructed shape (the original's
// source is unknown): the register/stack layout depends on how deep each part sits in pre-expanded inline bodies
// (each copied level reverses its temps' creation order). Original = particle walk one inline level deep with its
// own operator temps, UpdateEmitters expanded directly in DC2 (see NOTES.md 2026-10-13 (4)). `next` declared
// before `p` keeps their order.
static inline void UpdateParticlesW(TFieldParticleSystem<CSimpleSpriteNTF> *sys, int dt)
{
    TFieldParticle<CSimpleSpriteNTF> *next;
    TFieldParticle<CSimpleSpriteNTF> *p = sys->m_active;
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

int CFieldEffectDarknessClear2::ov0_02142264(int step)
{
    m_emitter.m_index = 0;
    int state = CFieldEffect::ov0_02142264(step);
    if (state != 4 && m_system != NULL) {
        TFieldParticleSystem<CSimpleSpriteNTF> *sys = m_system;
        int dt = step * sys->m_speed;
        UpdateParticlesW(sys, dt);
        u32 total = sys->UpdateEmitters(dt);
        if (total != 0) {
            for (u32 i = 0; i < sys->m_emitterCount; i++) {
                if (sys->m_emitters[i] != NULL && sys->m_emitCounts[i] != 0) {
                    for (u32 j = 0; j < sys->m_emitCounts[i]; j++) {
                        TFieldParticle<CSimpleSpriteNTF> *np = sys->Alloc();
                        if (np != NULL) {
                            TFieldParticleRes<CSimpleSpriteNTF>::Set(np, sys->m_res);
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

// Never called (mwld strips it): makes mwcc emit the template's ov0_02142264 right after DC2's, as in the original.
int DarknessClear2_EmitBaseUpdate(CFieldEffectDarknessClear2 *self, int step)
{
    return self->TFieldEffectParticle<CSimpleSpriteNTF>::ov0_02142264(step);
}

template u32 TFieldParticleEmitter<CSimpleSpriteNTF>::Update(int dt);

int CFieldEffectDarknessClear2::ov0_02142344(Camera2D *camera)
{
    TFieldParticleSystem<CSimpleSpriteNTF> *system = m_system;
    if (system != NULL) {
        system->m_offset.x = -camera->unk_1C;
        system->m_offset.y = -camera->unk_20;
    }
    return TFieldEffectParticle<CSimpleSpriteNTF>::ov0_02142344(camera);
}

void CFieldEffectDarknessClear2::CForceField::Apply(TFieldParticle<CSimpleSpriteNTF> *p, int dt)
{
    fx32 elapsed = p->maxLife - p->life;
    if (elapsed < m_delay) {
        return;
    }
    p->sprite.SetScale(p->sprite.m_scale[0] + 0x28, p->sprite.m_scale[1] + 0x28);
    p->sprite.m_alpha = FX32_DIV(p->life * 31, p->maxLife) >> 12;
    u32 flags = p->animIdx;
    if (!(flags & 0x40000000)) {
        if (flags & 0x80000000) {
            Point2D d = p->pos - m_center;
            fx32 len = ApproxLength(d.x, d.y);
            fx32 k = len < 0x1000 ? 0x51 : FX32_DIV(0x2000, len);
            p->vel.x = FX32_MUL(k, d.y);
            p->vel.y = FX32_MUL(k, -d.x);
        } else {
            fx32 remain = p->maxLife - elapsed;
            CGame *game = CGame::GetInstance();
            MATHRandContext32 *rand = &game->m_rand32;
            int r = MATH_Rand32(rand, 0x80) + 0x40;
            fx32 speed = FX32_DIV(r << 12, remain);
            if (p->animIdx == 0) {
                p->vel.x = -speed;
                p->vel.y = 0;
            } else {
                p->vel.x = speed;
                p->vel.y = 0;
            }
        }
        p->animIdx = flags | 0x40000000;
    } else if (flags & 0x80000000) {
        Point2D d = p->pos - m_center;
        fx32 len = ApproxLength(d.x, d.y);
        fx32 k = len < 0x1000 ? 0x51 : FX32_DIV(0x2000, len);
        fx32 vx = FX32_MUL(k, d.y);
        fx32 vy = FX32_MUL(k, -d.x);
        p->vel.x = vx + FX32_MUL(d.x, 0x28);
        p->vel.y = vy + FX32_MUL(d.y, 0x28);
    }
}

void CFieldEffectDarknessClear2::CEmitter::Emit(TFieldParticle<CSimpleSpriteNTF> *p)
{
    p->pos = (Point2D) { sDarknessClearPoints[m_index].x, sDarknessClearPoints[m_index].y };
    m_index++;
    int dir;
    if (p->pos.x < -0x20000) {
        dir = 0;
    } else if (p->pos.x > 0x20000) {
        dir = 1;
    } else if (MATH_Rand32(&CGame::GetInstance()->m_rand32, 2) != 0) {
        dir = 0;
    } else {
        dir = 1;
    }
    if (m_emitted < 0x10) {
        p->animIdx = dir;
    } else {
        p->animIdx = (m_emitted - 0x10) | 0x80000000;
    }
    p->vel.x = 0;
    p->vel.y = 0;
    int life = m_lifeMin + MATH_Rand32(&CGame::GetInstance()->m_rand32, m_lifeMax - m_lifeMin + 1);
    p->life = life << 12;
    p->maxLife = life << 12;
    p->sprite.m_color = 0;
    p->sprite.m_alpha = 0x1F;
    p->sprite.m_z = -1;
    p->rotVel = 0;
    p->sprite.SetTexCoords(0, 0, 0x20000, 0x20000);
    p->sprite.unk_4C = 0x20000;
    p->sprite.unk_50 = 0x20000;
    fx32 scale = MATH_Rand32(&CGame::GetInstance()->m_rand32, 0xC01) + 0x1800;
    p->sprite.m_scale[0] = FX32_MUL(scale, MATH_Rand32(&CGame::GetInstance()->m_rand32, 0x801) + 0x1800);
    p->sprite.m_scale[1] = scale;
    p->sprite.m_polygonID = m_polyCounter + 8;
    m_polyCounter++;
    m_polyCounter &= 0x1F;
    m_emitted++;
}

CFieldEffect *CFieldEffectDarknessClearFactory::Create(int arg)
{
    if (arg == 0) {
        return new CFieldEffectDarknessClear(arg);
    }
    return new CFieldEffectDarknessClear2(arg);
}
