#include "AudioEngine.hpp"
#include "Collision.hpp"
#include "SaveData.hpp"
#include "battle/BattleEffectivenessMark.hpp"
#include "battle/BattleParamTable.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleAttackEffect.hpp"
#include "battle/CBattleDisk.hpp"
#include "battle/CBattleEnemy.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "battle/StylerLine.hpp"
#include "fx_utils.hpp"
#include "interpolation.hpp"

extern "C" fx32 GetAssistTypeRate(int assistType, int type);
extern "C" u16 GetAssistEffectTime(int assistType, int idx);

static inline Circle GetCircle(CBattleAttackEffect *effect)
{
    return effect->m_sphere.m_circle;
}

CBattleAssistGhost::CBattleAssistGhost(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, BattleParamTable *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
    MI_CpuFill8(m_ghosts, 0, sizeof(m_ghosts));
}

CBattleAssistGhost::~CBattleAssistGhost()
{
}

int CBattleAssistGhost::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (unk_04 == 0) {
        return 0;
    }
    unk_04--;
    u8 *level = &MAIN_BSS_020B26A0.m_stylerLevel;
    for (u8 k = 0; k < 5; k++) {
        if (m_ghosts[k].m_flags & 1) {
            m_ghosts[k].m_angle += 0x100;
            fx32 radius = LinearInterpolate(0, 0x40000, m_ghosts[k].m_timer, 0xF0);
            Point2D pos = m_ghosts[k].m_center;
            pos.x += FX32_MUL(radius, FX_CosIdx(m_ghosts[k].m_angle));
            pos.y += FX32_MUL(radius, FX_SinIdx(m_ghosts[k].m_angle));
            m_ghosts[k].m_effect->m_motion.SetPos(pos);
            m_ghosts[k].m_effect->m_motion.MoveInDirection(m_ghosts[k].m_effect->m_motion.m_angle + 0x100, 0x800);
            m_ghosts[k].m_timer++;
            if (m_ghosts[k].m_timer >= 0xF0) {
                m_ghosts[k].m_effect->FadeAlpha(0x20, 0);
                m_ghosts[k].m_effect->ScaleTo(0x20, 0x2000, 0x2000);
                m_ghosts[k].m_effect->SetCollisionEnabled(FALSE);
                m_ghosts[k].m_flags &= ~1;
            }
            if (m_ghosts[k].m_effect->IsUnk100Clear()) {
                Circle circle = GetCircle(m_ghosts[k].m_effect);
                for (u8 i = 0; i < 8; i++) {
                    if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable()
                        && CircleHitCircle(circle, enemies[i]->m_sphere.m_circle, NULL)) {
                        u16 power = unk_10->GetAssistPower(vfunc_10(), *level, 0);
                        fx32 rate = GetAssistTypeRate(vfunc_10(), enemies[i]->unk_184->unk_18->unk_03);
                        enemies[i]->TakeDamage((u16)(FX32_MUL(rate, power << FX32_SHIFT) >> FX32_SHIFT), TRUE);
                        enemies[i]->SetStatus(2, GetAssistEffectTime(vfunc_10(), 0));
                        if (rate == 0x1000) {
                            enemies[i]->unk_1A8->Show(0);
                        } else if (rate > 0x1000) {
                            enemies[i]->unk_1A8->Show(1);
                        } else if (rate < 0x1000) {
                            enemies[i]->unk_1A8->Show(2);
                        }
                        m_ghosts[k].m_effect->Terminate();
                        unk_14->PlaySe(0x13C);
                        m_ghosts[k].m_flags &= ~1;
                    }
                }
            }
        }
    }
    if (disk->IsActive() && disk->IsLoopClosed()) {
        for (u8 i = 0; i < 8; i++) {
            if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable()) {
                Point2D enemyPos;
                enemyPos = enemies[i]->m_motion.GetPos();
                if (disk->unk_1B8->IsInsideLoop(enemyPos.x, enemyPos.y)) {
                    return 1;
                }
            }
        }
        Rectangle rect = disk->unk_1B8->m_rect.m_rectangle;
        if (rect.size.x >= 0x20000 && rect.size.y >= 0x20000) {
            GhostSlot *ghost = FindFreeGhost();
            if (ghost != NULL) {
                Point2D newPos;
                newPos = rect.pos;
                ghost->m_effect = GetFreeEffect();
                ghost->m_effect->Start(unk_0C[0]);
                ghost->m_effect->m_motion.SetPos(newPos);
                ghost->m_effect->m_motion.MoveInDirection(0, 0x800);
                ghost->m_timer = 0;
                ghost->m_center = newPos;
                unk_14->PlaySe(0x13B);
                ghost->m_flags |= 1;
            }
        }
    }
    return 1;
}

int CBattleAssistGhost::vfunc_10()
{
    return 13;
}

void CBattleAssistGhost::vfunc_0C()
{
    unk_14->StopSe(0x13B);
    unk_14->StopSe(0x13C);
}

GhostSlot *CBattleAssistGhost::FindFreeGhost()
{
    for (u8 i = 0; i < 5; i++) {
        if (!(m_ghosts[i].m_flags & 1)) {
            return &m_ghosts[i];
        }
    }
    return NULL;
}
