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

CBattleAssistRock::CBattleAssistRock(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, BattleParamTable *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
}

CBattleAssistRock::~CBattleAssistRock()
{
}

int CBattleAssistRock::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
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
        }
    }
    if (touch->unk_05 != 0) {
        if ((m_flags & 1) && m_effects[m_selected] != NULL && m_effects[m_selected]->HasData()) {
            m_effects[m_selected]->m_motion.SetPos(pos);
        }
        if (m_timer == 10) {
            m_last = pos;
            m_timer = 0;
        } else if (m_timer < 10) {
            m_timer++;
        }
    }
    if (touch->unk_06 != 0) {
        if (m_flags & 1) {
            if (m_effects[m_selected] != NULL && m_effects[m_selected]->HasData()) {
                m_effects[m_selected]->m_motion.SetPos(pos);
                u16 angle = FX_Atan2Idx(pos.y - m_last.y, pos.x - m_last.x);
                m_effects[m_selected]->m_motion.MoveInDirection(angle, 0x6000);
                unk_14->PlaySe(0x12A);
                m_slots[m_selected].m_flags |= 1;
            } else {
                m_effects[m_selected]->Terminate();
            }
        }
        m_flags &= ~1;
    }
    return 1;
}

void CBattleAssistRock::UpdateEffects(CBattleEnemy **enemies)
{
    for (u8 i = 0; i < 4; i++) {
        if (m_effects[i] == NULL || !m_effects[i]->HasData()) {
            continue;
        }
        if ((m_flags & 1) && m_selected == i) {
            continue;
        }
        if (m_effects[i]->IsUnk100Clear() && HitEnemies(m_effects[i], enemies)) {
            m_effects[i]->m_motion.m_mode = 0;
            m_effects[i]->SetCollisionEnabled(FALSE);
            m_slots[i].m_flags |= 2;
            m_effects[i]->PlayAction(0x20, 1);
        }
        if ((m_slots[i].m_flags & 2) && !m_effects[i]->IsAnimActive()) {
            m_effects[i]->Terminate();
        }
    }
}

BOOL CBattleAssistRock::FindFreeSlot(u8 *idx)
{
    for (u8 i = 0; i < 4; i++) {
        if (m_effects[i] == NULL || !m_effects[i]->HasData()) {
            *idx = i;
            return TRUE;
        }
    }
    return FALSE;
}

BOOL CBattleAssistRock::CreateEffect(u8 *outIdx)
{
    u8 idx = 0;
    if (!FindFreeSlot(&idx)) {
        return FALSE;
    }
    CBattleAttackEffect *effect = GetFreeEffect();
    if (effect == NULL) {
        return FALSE;
    }
    m_slots[idx].m_flags = 0;
    m_slots[idx].unk_01 = 0;
    m_slots[idx].unk_04 = 0;
    m_slots[idx].unk_02 = 0x1F;
    effect->Start(unk_0C[0]);
    effect->SetCollisionEnabled(TRUE);
    m_effects[idx] = effect;
    *outIdx = idx;
    return TRUE;
}

BOOL CBattleAssistRock::HitEnemies(CBattleAttackEffect *effect, CBattleEnemy **enemies)
{
    Circle area;
    Circle circle = effect->m_sphere.m_circle;
    area = circle;
    for (int i = 0; i < 8; i++) {
        if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable()
            && CircleHitCircle(area, enemies[i]->m_sphere.m_circle, NULL)) {
            u16 power = unk_10->GetAssistPower(vfunc_10(), MAIN_BSS_020B26A0.m_stylerLevel, 0);
            fx32 rate = GetAssistTypeRate(vfunc_10(), enemies[i]->unk_184->unk_18->unk_03);
            enemies[i]->TakeDamage((u16)(FX32_MUL(rate, power << FX32_SHIFT) >> FX32_SHIFT), TRUE);
            if (rate == 0x1000) {
                unk_14->PlaySe(0x12B);
                enemies[i]->unk_1A8->Show(0);
            } else if (rate > 0x1000) {
                unk_14->PlaySe(0x148);
                enemies[i]->unk_1A8->Show(1);
            } else if (rate < 0x1000) {
                unk_14->PlaySe(0x149);
                enemies[i]->unk_1A8->Show(2);
            }
            return TRUE;
        }
    }
    return FALSE;
}

int CBattleAssistRock::vfunc_10()
{
    return 12;
}

void CBattleAssistRock::vfunc_0C()
{
    if (m_flags & 1) {
        if (m_effects[m_selected] != NULL && m_effects[m_selected]->HasData()) {
            m_effects[m_selected]->Terminate();
        }
        m_flags &= ~1;
    }
    unk_14->StopSe(0x12A);
    unk_14->StopSe(0x12B);
    unk_14->StopSe(0x148);
    unk_14->StopSe(0x149);
}
