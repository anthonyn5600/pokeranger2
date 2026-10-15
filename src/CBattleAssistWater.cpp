#include "AudioEngine.hpp"
#include "CTouchPanel.hpp"
#include "Collision.hpp"
#include "MathUtil.hpp"
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

extern "C" fx32 GetAssistTypeRate(int assistType, int type);
extern "C" u16 GetAssistEffectTime(int assistType, int idx);

CBattleAssistWater::CBattleAssistWater(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, BattleParamTable *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
}

CBattleAssistWater::~CBattleAssistWater()
{
}

int CBattleAssistWater::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (unk_04 == 0) {
        return 0;
    }
    unk_04--;
    UpdateEffects(enemies);
    Point2D pos;
    pos.x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
    pos.y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
    if (touch->unk_04 != 0) {
        m_last = pos;
        u8 idx = 0;
        if (CreateEffect(&idx)) {
            m_selected = idx;
            m_effects[idx]->m_motion.SetPos(pos);
            m_flags |= 1;
            unk_14->PlaySe(0x121);
        }
    }
    if (touch->unk_05 != 0 && (m_flags & 1)) {
        if (m_effects[m_selected] != NULL && m_effects[m_selected]->HasData()) {
            m_effects[m_selected]->m_motion.SetPos(pos);
        }
        UpdateGrowth(m_selected);
        if (m_timer == 5) {
            m_last = pos;
            m_timer = 0;
        } else if (m_timer < 5) {
            m_timer++;
        }
    }
    if (touch->unk_06 != 0) {
        if ((m_flags & 1) && m_effects[m_selected] != NULL && m_effects[m_selected]->HasData()) {
            if (ApproxLength(pos.x - m_last.x, pos.y - m_last.y) >= 0x8000) {
                m_effects[m_selected]->m_motion.SetPos(pos);
                u16 angle = FX_Atan2Idx(pos.y - m_last.y, pos.x - m_last.x);
                m_effects[m_selected]->m_motion.MoveInDirection(angle, 0x2000);
                m_slots[m_selected].m_thrown = 1;
                unk_14->PlaySe(0x122);
            } else {
                m_effects[m_selected]->Terminate();
                m_slots[m_selected].m_thrown = 1;
            }
        }
        unk_14->StopSe(0x121);
        m_flags &= ~1;
    }
    return 1;
}

void CBattleAssistWater::UpdateEffects(CBattleEnemy **enemies)
{
    for (u8 i = 0; i < 4; i++) {
        if (m_effects[i] == NULL || !m_effects[i]->HasData()) {
            continue;
        }
        if ((m_flags & 1) && m_selected == i) {
            continue;
        }
        if (m_effects[i]->IsUnk100Clear() && HitEnemies(m_effects[i], enemies, m_slots[i].m_level)) {
            m_effects[i]->m_motion.m_mode = 0;
            m_effects[i]->SetAnimSequence(8, 2);
            m_effects[i]->SetCollisionEnabled(FALSE);
            m_slots[i].m_state = 1;
        }
        if (m_effects[i]->IsUnk100Clear() && m_slots[i].m_thrown == 1) {
            if (m_slots[i].m_timer == 0x78) {
                m_effects[i]->m_motion.m_mode = 0;
                m_effects[i]->PlayAction(0x20, 1);
                m_effects[i]->SetCollisionEnabled(FALSE);
                m_slots[i].m_state = 1;
                m_slots[i].m_thrown = 0;
                m_slots[i].m_timer = 0;
            } else if (m_slots[i].m_timer < 0x78) {
                m_slots[i].m_timer++;
            }
        }
        if (!m_effects[i]->IsAnimActive()) {
            m_effects[i]->Terminate();
        }
    }
}

BOOL CBattleAssistWater::FindFreeSlot(u8 *idx)
{
    for (u8 i = 0; i < 4; i++) {
        if (m_effects[i] == NULL || !m_effects[i]->HasData()) {
            *idx = i;
            return TRUE;
        }
    }
    return FALSE;
}

void CBattleAssistWater::UpdateGrowth(u8 idx)
{
    u8 level = m_slots[idx].m_level;
    u16 timer = m_slots[idx].m_growTimer;
    fx32 scale = m_slots[idx].m_scale;
    if (level == 0) {
        if (timer == 50) {
            timer = 0;
            level = 1;
            scale = 0xC00;
        } else if (timer < 50) {
            timer++;
        }
    } else if (level == 1) {
        if (timer == 50) {
            timer = 0;
            level = 2;
            scale = 0x1000;
        } else if (timer < 50) {
            timer++;
        }
    }
    m_slots[idx].m_level = level;
    m_slots[idx].m_growTimer = timer;
    m_slots[idx].m_scale = scale;
    m_effects[idx]->ScaleTo(0, m_slots[idx].m_scale, m_slots[idx].m_scale);
}

BOOL CBattleAssistWater::CreateEffect(u8 *outIdx)
{
    u8 idx = 0;
    if (!FindFreeSlot(&idx)) {
        return FALSE;
    }
    CBattleAttackEffect *effect = GetFreeEffect();
    if (effect == NULL) {
        return FALSE;
    }
    m_slots[idx].m_thrown = 0;
    m_slots[idx].m_state = 0;
    m_slots[idx].m_level = 0;
    m_slots[idx].m_timer = 0;
    m_slots[idx].m_growTimer = 0;
    m_slots[idx].m_scale = 0x800;
    effect->Start(unk_0C[0]);
    effect->SetAnimSequence(7, 2);
    effect->SetCollisionEnabled(TRUE);
    effect->ScaleTo(0, m_slots[idx].m_scale, m_slots[idx].m_scale);
    m_effects[idx] = effect;
    *outIdx = idx;
    return TRUE;
}

BOOL CBattleAssistWater::HitEnemies(CBattleAttackEffect *effect, CBattleEnemy **enemies, u8 level)
{
    Circle area;
    Circle circle = effect->m_sphere.m_circle;
    area = circle;
    for (int i = 0; i < 8; i++) {
        if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable()
            && CircleHitCircle(area, enemies[i]->m_sphere.m_circle, NULL)) {
            u16 power = unk_10->GetAssistPower(vfunc_10(), MAIN_BSS_020B26A0.m_stylerLevel, level);
            fx32 rate = GetAssistTypeRate(vfunc_10(), enemies[i]->unk_184->unk_18->unk_03);
            enemies[i]->TakeDamage((u16)(FX32_MUL(rate, power << FX32_SHIFT) >> FX32_SHIFT), TRUE);
            enemies[i]->SetStatus(3, GetAssistEffectTime(vfunc_10(), level));
            if (rate == 0x1000) {
                enemies[i]->unk_1A8->Show(0);
            } else if (rate > 0x1000) {
                enemies[i]->unk_1A8->Show(1);
            } else if (rate < 0x1000) {
                enemies[i]->unk_1A8->Show(2);
            }
            unk_14->PlaySe(0x123);
            return TRUE;
        }
    }
    return FALSE;
}

int CBattleAssistWater::vfunc_10()
{
    return 2;
}

void CBattleAssistWater::vfunc_0C()
{
    if (m_flags & 1) {
        if (m_effects[m_selected] != NULL && m_effects[m_selected]->HasData()) {
            m_effects[m_selected]->Terminate();
            m_slots[m_selected].m_thrown = 1;
        }
        m_flags &= ~1;
    }
    unk_14->StopSe(0x121);
    unk_14->StopSe(0x122);
    unk_14->StopSe(0x123);
}
