#include "battle/CBattleEnemy.hpp"

#include "AudioEngine.hpp"
#include "CGame.hpp"
#include "battle/BattleEffectivenessMark.hpp"
#include "battle/BattleHPNumber.hpp"
#include "battle/BattleParticle.hpp"
#include "battle/BattleParticlePool.hpp"
#include "battle/BattleStatusDebug.hpp"
#include "battle/BattleStatusIcon.hpp"
#include "battle/CBattleEnemyGauge.hpp"
#include "battle/CaptureEffect.hpp"
#include "battle/CaptureMark.hpp"
#include "battle/UnkClass_0212770C.hpp"
#include "battle/UnkClass_02127B48.hpp"
#include "interpolation.hpp"

CBattleEnemy::CBattleEnemy(u8 index, CBattleEnemyData *data)
{
    m_index = index;
    unk_184 = data;
    SetData(data);
    u32 size = 0;
    for (u8 i = 0; i < 0x1D; i++) {
        CActorAnim *anim = data->GetAnim(i);
        if (anim != NULL && (anim->flags & 1)) {
            m_cellBuffers[i].SetImage(anim->image);
            m_cellBuffers[i].SetCells(anim->cells);
            if (size < m_cellBuffers[i].m_size) {
                size = m_cellBuffers[i].m_size;
            }
        }
    }
    m_texKey = NNS_GfdAllocLnkTexVram(size, FALSE, 0);
    unk_198 = new CaptureEffect();
    unk_19C = new CaptureMark();
    unk_1A0 = new UnkClass_02127B48();
    unk_1A4 = new UnkClass_0212770C();
    unk_1A8 = new BattleEffectivenessMark();
    unk_1AC = new BattleHPNumber();
    unk_1B0 = new BattleStatusIcon();
    unk_1B4 = new BattleStatusDebug();
    unk_1AC->m_hp = unk_188 = data->unk_1C->unk_00;
    unk_198->Stop();
    SetTargetable(TRUE);
    unk_18C = 0;
    unk_1B0->SetStatus(0);
    unk_480 = 0;
    unk_484.x = 0;
    unk_484.y = 0;
    m_sphere.m_color = 0x7FFF;
    m_sphere.m_z = 0x400;
    m_sphere.m_alpha = 0x10;
    m_sphere.m_circle.r = data->unk_1C->unk_08 << FX32_SHIFT;
    m_sphere.m_polygonID = 0x3F;
    m_line.m_color = 0x7C00;
    m_line.m_z = 0x401;
    m_line.m_alpha = 0x1F;
    m_line.m_polygonID = 0x3E;
}

CBattleEnemy::~CBattleEnemy()
{
    SAFE_DELETE(unk_198);
    SAFE_DELETE(unk_19C);
    SAFE_DELETE(unk_1A0);
    SAFE_DELETE(unk_1A4);
    SAFE_DELETE(unk_1A8);
    SAFE_DELETE(unk_1AC);
    SAFE_DELETE(unk_1B0);
    SAFE_DELETE(unk_1B4);
    NNS_GfdFreeLnkTexVram(m_texKey);
}

void CBattleEnemy::vfunc_08()
{
    if (!HasData()) {
        return;
    }
    if (IsAlive()) {
        UpdateAlive();
    } else if (IsUnk2000()) {
        UpdateCaptureGather();
    } else {
        UpdateCapture();
    }
}

void CBattleEnemy::RunScript()
{
    if (!HasData()) {
        return;
    }
    if (!IsAlive() || unk_18C == 4) {
        return;
    }
    if (m_flags & 0x100) {
        return;
    }
    ScriptVM_Run(&m_vm, 0xFFFFF);
}

void CBattleEnemy::UpdateAlive()
{
    if (unk_18C != 0) {
        unk_1B0->Update();
        if (unk_190 <= 1) {
            if (unk_18C == 0) {
                unk_47C = 0;
                unk_47E = 0;
            }
            SetStatus(0, 0);
            unk_1B0->SetStatus(unk_18C);
            FaceMoveDir();
        } else {
            unk_190--;
        }
    }
    if (unk_18C != 2) {
        if (unk_47C >= 180) {
            unk_47E++;
            if (unk_47E == unk_184->unk_1C->unk_16) {
                unk_47E = 0;
                BattlePokemonParam *param = unk_184->unk_1C;
                u16 max = param->unk_00;
                if (unk_188 + param->unk_17 >= max) {
                    unk_188 = max;
                } else {
                    unk_188 += param->unk_17;
                }
            }
        } else {
            unk_47C++;
        }
    }
    if (unk_18C != 4) {
        Update();
        UpdateOrbit();
        CSoftwareSprite *sprite = m_sprite;
        sprite->SetPos(sprite->GetPos() + unk_484);
    }
    unk_1A0->Update();
    unk_1A4->Update();
    unk_1A8->Update();
    Circle circle = unk_184->unk_20;
    circle.pos += m_motion.m_pos;
    circle.pos += unk_484;
    circle.pos.y -= m_bobHeight + (m_height + m_jumpHeight);
    m_sphere.SetCircle(circle);
}

void CBattleEnemy::UpdateCapture()
{
    unk_198->Update();
    unk_19C->Update();
    UpdateAlphaTween();
    UpdateScaleTween();
    UpdateHeightTween();
    if (unk_192 == unk_194) {
        CGame::GetInstance()->m_audioEngine->PlaySe(0xE);
    } else if (unk_192 == 0x30) {
        m_flags |= 0x401;
        m_flags |= 0x800;
        unk_198->Stop();
        SpawnBurstParticles();
        CGame::GetInstance()->m_audioEngine->StopSe(0xE);
        CGame::GetInstance()->m_audioEngine->PlaySe(0x39);
    } else if (unk_192 == 0) {
        Terminate();
    }
    unk_192--;
}

void CBattleEnemy::UpdateCaptureGather()
{
    unk_198->Update();
    unk_19C->Update();
    UpdateAlphaTween();
    UpdateScaleTween();
    UpdateHeightTween();
    if (unk_192 == unk_194) {
        CGame::GetInstance()->m_audioEngine->PlaySe(0xE);
    } else if (unk_192 == 0x30) {
        m_flags |= 0x401;
        m_flags |= 0x800;
        unk_198->Stop();
        SpawnBurstParticles();
        CGame::GetInstance()->m_audioEngine->StopSe(0xE);
        CGame::GetInstance()->m_audioEngine->PlaySe(0x39);
    } else if (unk_192 == 0) {
        Terminate();
    } else if (unk_192 > 0x70) {
        u8 count = LinearInterpolate(0, 8, unk_194 - unk_192, 0x30);
        SpawnGatherParticles(count);
    }
    unk_192--;
}

void CBattleEnemy::UpdateOrbit()
{
    BattlePokemonParam *param = unk_184->unk_1C;
    if (param->unk_09 == 0) {
        return;
    }
    unk_480 += param->unk_0C;
    unk_484.x = FX32_MUL(param->unk_0A << FX32_SHIFT, FX_CosIdx(unk_480));
    unk_484.y = FX32_MUL(param->unk_0B << FX32_SHIFT, FX_SinIdx(unk_480));
}

void CBattleEnemy::vfunc_0C(Camera2D *camera)
{
    if (m_flags & 1) {
        return;
    }
    CActorAnim *anim = m_data->GetAnim(unk_C0);
    CellCharBuffer *pal = &m_cellBuffers[unk_C0];
    CSoftwareSprite *sprite = m_sprite;
    sprite->unk_30 = (UnkClass_CSoftwareSprite_30 *)pal;
    sprite->unk_2C = NULL;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)anim->cells;
    u16 cell = anim->bank->GetCell(unk_C8[unk_C0]);
    sprite->m_cellDataIdx = cell;
    pal->LoadCell(cell);
    pal->SetVramAddr(NNS_GfdGetTexKeyAddr(m_texKey));
    NNS_GfdRegisterNewVramTransferTask(NNS_GFD_DST_3D_TEX_VRAM, NNS_GfdGetTexKeyAddr(m_texKey), pal->m_buffer, pal->m_size);
    sprite->m_alpha = unk_108.value;
    sprite->m_scale[0] = unk_11C.value;
    sprite->m_scale[1] = unk_134.value;
    *(u16 *)unk_06 = sprite->Render(camera);
}

int CBattleEnemy::DrawOverlays(Camera2D *camera, int z)
{
    if (unk_108.value == 0x1F) {
        Point2D pos;
        pos.x = m_motion.m_pos.x;
        pos.y = m_motion.m_pos.y - (m_bobHeight + (m_height + m_jumpHeight));
        if (unk_198->unk_14) {
            z = unk_198->SetZ(z);
            unk_198->unk_04->SetPos(pos);
            unk_198->unk_08->SetPos(m_sphere.m_circle.pos);
            unk_198->Render(camera);
        }
        if (unk_19C->unk_08) {
            Point2D offset = { 0, 0 };
            if (pos.y >= 0) {
                offset.y -= 0x20000;
            } else {
                offset.y += 0x20000;
            }
            z = unk_19C->SetZ(z);
            unk_19C->SetPos(pos + offset);
            unk_19C->Render(camera);
        }
        if (IsAlive()) {
            if (unk_1B0->unk_08) {
                z = unk_1B0->SetZ(z);
                unk_1B0->SetPos(pos + unk_184->unk_3C[1]);
                unk_1B0->Render(camera);
            }
            if (unk_1A0->unk_08) {
                z = unk_1A0->SetZ(z);
                unk_1A0->SetPos(pos + unk_184->unk_3C[0]);
                unk_1A0->Render(camera);
            }
            if (unk_1A4->unk_08) {
                z = unk_1A4->SetZ(z);
                unk_1A4->SetPos(pos + unk_184->unk_3C[2]);
                unk_1A4->Render(camera);
            }
            if (unk_1A8->unk_08) {
                z = unk_1A8->SetZ(z);
                unk_1A8->SetPos(pos);
                unk_1A8->Render(camera);
            }
        }
    }
    return z;
}

void CBattleEnemy::vfunc_10(Camera2D *camera)
{
    Point2D pos = m_motion.m_pos;
    if ((unk_6B4 & 2) && IsTargetable()) {
        m_sphere.Render(camera);
    }
    if (unk_6B4 & 4) {
        m_line.SetStart(pos);
        m_line.SetEnd(m_motion.m_end);
        m_line.Render(camera);
    }
    if (unk_6B4 & 8) {
        unk_1AC->m_hp = unk_188;
        unk_1AC->SetPos(pos);
        unk_1AC->Render(camera);
    }
    if (unk_6B4 & 0x10) {
        unk_1B0->SetPos(pos);
        unk_1B0->ov1_021293D4(camera);
    }
}

void CBattleEnemy::InitScript()
{
    if (unk_184->m_script == NULL) {
        return;
    }
    ScriptVM_Init(&m_vm, m_stack, 0x80);
    *--m_vm.unk_04 = m_index;
    ScriptVM_CallFunction(&m_vm, unk_184->m_script, "initialize", 1);
    *--m_vm.unk_04 = m_index;
    ScriptVM_Start(&m_vm, unk_184->m_script, "proc");
}

void CBattleEnemy::Terminate()
{
    if (unk_184->m_script != NULL) {
        ScriptVM_Reset(&m_vm);
        *--m_vm.unk_04 = m_index;
        ScriptVM_CallFunction(&m_vm, unk_184->m_script, "terminate", 1);
    }
    ClearData();
    unk_184 = NULL;
}

void CBattleEnemy::TakeDamage(int damage, BOOL keepAlive)
{
    if (m_flags & 0x1000) {
        damage = 0;
    } else if ((u32)damage >= unk_188) {
        if (keepAlive) {
            damage = (u16)(unk_188 - 1);
            unk_188 = 1;
            unk_47C = 0;
        } else {
            damage = unk_188;
            unk_188 = 0;
        }
    } else {
        unk_188 -= damage;
        unk_47C = 0;
    }
    unk_1B8->ShowDamage(damage);
    unk_1AC->m_hp = unk_188;
}

void CBattleEnemy::SetStatus(int state, int duration)
{
    if (m_flags & 0x1000) {
        return;
    }
    if (unk_18C == state) {
        if (unk_190 < (u32)duration) {
            unk_190 = duration;
        }
    } else {
        unk_18C = state;
        unk_190 = duration;
        unk_1B0->SetStatus(state);
    }
    if (state == 4) {
        m_motion.SetPos(m_motion.m_pos);
        m_flags &= ~8;
    } else {
        m_flags |= 8;
    }
}

u8 CBattleEnemy::ov1_02126424()
{
    return unk_184->unk_1C->unk_09;
}

void CBattleEnemy::SpawnBurstParticles()
{
    CGame *game = CGame::GetInstance();
    Point2D pos = m_motion.GetPos();
    for (int i = 0; i < 8; i++) {
        MATHRandContext32 *rand = &game->m_rand32;
        BattleParticle *particle = unk_1BC->Spawn(0x40, pos.x, pos.y - MATH_Rand32(rand, 0x40000), 0, FX32_ONE, 0x7FFF);
        particle->SetVelocityY(-MATH_Rand32(rand, 0x3000), FX32_ONE);
        particle->SetAlphaFade(0x1F, 0);
        particle->SetScaleFade(FX32_ONE, 0x28);
    }
}

void CBattleEnemy::SpawnGatherParticles(u8 count)
{
    CGame *game = CGame::GetInstance();
    for (u8 i = 0; i < count; i++) {
        Point2D pos = m_sphere.m_circle.pos;
        MATHRandContext16 *rand16 = &game->m_rand16;
        MATHRandContext32 *rand32 = &game->m_rand32;
        u16 angle = MATH_Rand16(rand16, 0xFFFF);
        fx32 radius = MATH_Rand32(rand32, 0x30000) + 0x20000;
        fx32 dx = FX32_MUL(radius, FX_CosIdx(angle));
        fx32 dy = FX32_MUL(radius, FX_SinIdx(angle));
        BattleParticle *particle = unk_1BC->Spawn(0x40, pos.x + dx, pos.y + dy, 0, FX32_ONE, 0x7FFF);
        particle->SetVelocityX(-dx / 64, FX32_ONE);
        particle->SetVelocityY(-dy / 64, FX32_ONE);
        particle->SetAlphaFade(1, 0x1F);
        particle->SetScaleFade(0x1800, 0x800);
    }
}

void CBattleEnemy::SetTargetable(BOOL targetable)
{
    if (targetable) {
        m_flags &= ~0x200;
    } else {
        m_flags |= 0x200;
    }
}

void CBattleEnemy::SetInvincible(BOOL invincible)
{
    if (invincible) {
        m_flags |= 0x1000;
    } else {
        m_flags &= ~0x1000;
    }
}

void CBattleEnemy::SetShadowVisible(BOOL arg0)
{
    if (arg0) {
        m_flags &= ~0x800;
    } else {
        m_flags |= 0x800;
    }
}

void CBattleEnemy::ov1_02126764(BOOL arg0)
{
    if (arg0) {
        m_flags |= 0x2000;
    } else {
        m_flags &= ~0x2000;
    }
}

void CBattleEnemy::StartCapture(u16 duration)
{
    if (duration < 0x71) {
        duration = 0x71;
    }
    unk_19C->Show(duration);
    Circle circle = m_sphere.m_circle;
    CaptureEffect *fx = unk_198;
    fx->unk_14 = TRUE;
    fx->unk_18 = duration;
    fx->unk_1A = duration;
    fx->unk_0C = circle.r + 0x10000;
    unk_192 = duration;
    unk_194 = duration;
}

BOOL CBattleEnemy::IsCaptureFinished()
{
    return unk_192 <= 0x30;
}
