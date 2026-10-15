#include "battle/CBattleEnemy.hpp"

#include "AudioEngine.hpp"
#include "CGame.hpp"
#include "battle/BattleHPNumber.hpp"
#include "battle/BattleParticle.hpp"
#include "battle/BattleParticlePool.hpp"
#include "battle/BattleStatusDebug.hpp"
#include "battle/BattleStatusIcon.hpp"
#include "battle/CBattleEnemyGauge.hpp"
#include "battle/UnkClass_0212770C.hpp"
#include "battle/UnkClass_02127B48.hpp"
#include "battle/UnkClass_02128414.hpp"
#include "battle/UnkClass_021299CC.hpp"
#include "battle/UnkClass_02129DD4.hpp"
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
    unk_198 = new UnkClass_02129DD4();
    unk_19C = new UnkClass_021299CC();
    unk_1A0 = new UnkClass_02127B48();
    unk_1A4 = new UnkClass_0212770C();
    unk_1A8 = new UnkClass_02128414();
    unk_1AC = new BattleHPNumber();
    unk_1B0 = new BattleStatusIcon();
    unk_1B4 = new BattleStatusDebug();
    unk_1AC->m_hp = unk_188 = data->unk_1C->unk_00;
    unk_198->Stop();
    ov1_0212671C(TRUE);
    unk_18C = 0;
    unk_1B0->ov1_021293D8(0);
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
        ov1_0212586C();
    } else if (IsUnk2000()) {
        ov1_02125B74();
    } else {
        ov1_02125A80();
    }
}

void CBattleEnemy::ov1_0212580C()
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

void CBattleEnemy::ov1_0212586C()
{
    if (unk_18C != 0) {
        unk_1B0->ov1_021292CC();
        if (unk_190 <= 1) {
            if (unk_18C == 0) {
                unk_47C = 0;
                unk_47E = 0;
            }
            ov1_021263A4(0, 0);
            unk_1B0->ov1_021293D8(unk_18C);
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
                UnkStruct_0212DFEC *param = unk_184->unk_1C;
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
        ov1_02125C94();
        CSoftwareSprite *sprite = m_sprite;
        sprite->SetPos(sprite->GetPos() + unk_484);
    }
    unk_1A0->ov1_02127BCC();
    unk_1A4->ov1_02127780();
    unk_1A8->ov1_0212849C();
    Circle circle = unk_184->unk_20;
    circle.pos += m_motion.m_pos;
    circle.pos += unk_484;
    circle.pos.y -= m_bobHeight + (m_height + m_jumpHeight);
    m_sphere.SetCircle(circle);
}

void CBattleEnemy::ov1_02125A80()
{
    unk_198->ov1_02129ED4();
    unk_19C->ov1_02129A40();
    UpdateAlphaTween();
    UpdateScaleTween();
    UpdateHeightTween();
    if (unk_192 == unk_194) {
        CGame::GetInstance()->m_audioEngine->PlaySe(0xE);
    } else if (unk_192 == 0x30) {
        m_flags |= 0x401;
        m_flags |= 0x800;
        unk_198->Stop();
        ov1_02126434();
        CGame::GetInstance()->m_audioEngine->StopSe(0xE);
        CGame::GetInstance()->m_audioEngine->PlaySe(0x39);
    } else if (unk_192 == 0) {
        ov1_021262AC();
    }
    unk_192--;
}

void CBattleEnemy::ov1_02125B74()
{
    unk_198->ov1_02129ED4();
    unk_19C->ov1_02129A40();
    UpdateAlphaTween();
    UpdateScaleTween();
    UpdateHeightTween();
    if (unk_192 == unk_194) {
        CGame::GetInstance()->m_audioEngine->PlaySe(0xE);
    } else if (unk_192 == 0x30) {
        m_flags |= 0x401;
        m_flags |= 0x800;
        unk_198->Stop();
        ov1_02126434();
        CGame::GetInstance()->m_audioEngine->StopSe(0xE);
        CGame::GetInstance()->m_audioEngine->PlaySe(0x39);
    } else if (unk_192 == 0) {
        ov1_021262AC();
    } else if (unk_192 > 0x70) {
        u8 count = LinearInterpolate(0, 8, unk_194 - unk_192, 0x30);
        ov1_0212656C(count);
    }
    unk_192--;
}

void CBattleEnemy::ov1_02125C94()
{
    UnkStruct_0212DFEC *param = unk_184->unk_1C;
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

int CBattleEnemy::ov1_02125E00(Camera2D *camera, int z)
{
    if (unk_108.value == 0x1F) {
        Point2D pos;
        pos.x = m_motion.m_pos.x;
        pos.y = m_motion.m_pos.y - (m_bobHeight + (m_height + m_jumpHeight));
        if (unk_198->unk_14) {
            z = unk_198->ov1_0212A0D8(z);
            unk_198->unk_04->SetPos(pos);
            unk_198->unk_08->SetPos(m_sphere.m_circle.pos);
            unk_198->ov1_02129FD0(camera);
        }
        if (unk_19C->unk_08) {
            Point2D offset = { 0, 0 };
            if (pos.y >= 0) {
                offset.y -= 0x20000;
            } else {
                offset.y += 0x20000;
            }
            z = unk_19C->ov1_02129B48(z);
            unk_19C->SetPos(pos + offset);
            unk_19C->ov1_02129A98(camera);
        }
        if (IsAlive()) {
            if (unk_1B0->unk_08) {
                z = unk_1B0->ov1_02129490(z);
                unk_1B0->SetPos(pos + unk_184->unk_3C[1]);
                unk_1B0->ov1_02129368(camera);
            }
            if (unk_1A0->unk_08) {
                z = unk_1A0->ov1_02127CAC(z);
                unk_1A0->SetPos(pos + unk_184->unk_3C[0]);
                unk_1A0->ov1_02127BF0(camera);
            }
            if (unk_1A4->unk_08) {
                z = unk_1A4->ov1_021278BC(z);
                unk_1A4->SetPos(pos + unk_184->unk_3C[2]);
                unk_1A4->ov1_02127810(camera);
            }
            if (unk_1A8->unk_08) {
                z = unk_1A8->ov1_021285D4(z);
                unk_1A8->SetPos(pos);
                unk_1A8->ov1_021284C0(camera);
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
        unk_1AC->ov1_02128970(camera);
    }
    if (unk_6B4 & 0x10) {
        unk_1B0->SetPos(pos);
        unk_1B0->ov1_021293D4(camera);
    }
}

void CBattleEnemy::ov1_02126224()
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

void CBattleEnemy::ov1_021262AC()
{
    if (unk_184->m_script != NULL) {
        ScriptVM_Reset(&m_vm);
        *--m_vm.unk_04 = m_index;
        ScriptVM_CallFunction(&m_vm, unk_184->m_script, "terminate", 1);
    }
    ClearData();
    unk_184 = NULL;
}

void CBattleEnemy::ov1_02126310(int damage, BOOL keepAlive)
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
    unk_1B8->ov1_021362A0(damage);
    unk_1AC->m_hp = unk_188;
}

void CBattleEnemy::ov1_021263A4(int state, int duration)
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
        unk_1B0->ov1_021293D8(state);
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

void CBattleEnemy::ov1_02126434()
{
    CGame *game = CGame::GetInstance();
    Point2D pos = m_motion.GetPos();
    for (int i = 0; i < 8; i++) {
        MATHRandContext32 *rand = &game->m_rand32;
        BattleParticle *particle = unk_1BC->ov1_02136B24(0x40, pos.x, pos.y - MATH_Rand32(rand, 0x40000), 0, FX32_ONE, 0x7FFF);
        particle->ov1_02136A58(-MATH_Rand32(rand, 0x3000), FX32_ONE);
        particle->ov1_02136A88(0x1F, 0);
        particle->ov1_02136AA0(FX32_ONE, 0x28);
    }
}

void CBattleEnemy::ov1_0212656C(u8 count)
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
        BattleParticle *particle = unk_1BC->ov1_02136B24(0x40, pos.x + dx, pos.y + dy, 0, FX32_ONE, 0x7FFF);
        particle->ov1_02136A40(-dx / 64, FX32_ONE);
        particle->ov1_02136A58(-dy / 64, FX32_ONE);
        particle->ov1_02136A88(1, 0x1F);
        particle->ov1_02136AA0(0x1800, 0x800);
    }
}

void CBattleEnemy::ov1_0212671C(BOOL targetable)
{
    if (targetable) {
        m_flags &= ~0x200;
    } else {
        m_flags |= 0x200;
    }
}

void CBattleEnemy::ov1_02126734(BOOL invincible)
{
    if (invincible) {
        m_flags |= 0x1000;
    } else {
        m_flags &= ~0x1000;
    }
}

void CBattleEnemy::ov1_0212674C(BOOL arg0)
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

void CBattleEnemy::ov1_0212677C(u16 duration)
{
    if (duration < 0x71) {
        duration = 0x71;
    }
    unk_19C->ov1_02129B30(duration);
    Circle circle = m_sphere.m_circle;
    UnkClass_02129DD4 *fx = unk_198;
    fx->unk_14 = TRUE;
    fx->unk_18 = duration;
    fx->unk_1A = duration;
    fx->unk_0C = circle.r + 0x10000;
    unk_192 = duration;
    unk_194 = duration;
}

BOOL CBattleEnemy::ov1_021267E8()
{
    return unk_192 <= 0x30;
}
