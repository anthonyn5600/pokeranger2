#include "AudioEngine.hpp"
#include "CTouchPanel.hpp"
#include "Collision.hpp"
#include "MathUtil.hpp"
#include "SaveData.hpp"
#include "battle/BattleParamTable.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleAttackEffect.hpp"
#include "battle/CBattleDisk.hpp"
#include "battle/CBattleEnemy.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "battle/StylerLine.hpp"
#include "battle/UnkClass_02128414.hpp"
#include "fx_utils.hpp"

extern "C" u16 ov1_0212EE98(int assistType, int idx);

CBattleAssistPoison::CBattleAssistPoison(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, BattleParamTable *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
}

CBattleAssistPoison::~CBattleAssistPoison()
{
}

int CBattleAssistPoison::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    PoisonSlot *slot;
    for (u8 i = 0; i < 16; i++) {
        slot = &m_slots[i];
        if (m_current == slot) {
            continue;
        }
        if (slot->m_flags & 1) {
            slot->m_timer--;
            if (slot->m_timer == 0) {
                slot->m_effect->FadeAlpha(0x3C, 0);
                slot->m_flags &= ~1;
            }
        } else if (slot->m_effect != NULL && slot->m_effect->unk_108.value == 0) {
            slot->m_effect->ov1_02127300();
            slot->m_effect = NULL;
        }
    }
    for (u8 j = 0; j < 8; j++) {
        if (enemies[j] == NULL || !enemies[j]->IsAlive() || !enemies[j]->IsTargetable() || enemies[j]->ov1_02126424() != 0) {
            continue;
        }
        for (u8 k = 0; k < 16; k++) {
            slot = &m_slots[k];
            if ((slot->m_flags & 1)
                && CircleHitCircle(enemies[j]->m_sphere.m_circle, slot->m_effect->m_sphere.m_circle, NULL)) {
                u16 duration = ov1_0212EE98(vfunc_10(), 0);
                switch (enemies[j]->unk_184->unk_18->unk_03) {
                case 4:
                    duration = FX32_MUL(duration << FX32_SHIFT, 0x2000) >> FX32_SHIFT;
                    break;
                case 7:
                case 8:
                case 12:
                case 13:
                case 16:
                    duration = FX32_MUL(duration << FX32_SHIFT, 0xC00) >> FX32_SHIFT;
                    break;
                }
                enemies[j]->ov1_021263A4(2, duration);
            }
        }
    }
    switch (m_state) {
    case 0:
        ov1_02133F9C(touch, disk, enemies);
        break;
    case 1:
        ov1_02134120(touch, disk, enemies);
        break;
    }
    if (unk_04 == 0) {
        return 0;
    }
    unk_04--;
    return 1;
}

int CBattleAssistPoison::vfunc_10()
{
    return 7;
}

void CBattleAssistPoison::vfunc_0C()
{
    if (m_current == NULL) {
        return;
    }
    CBattleAttackEffect *effect = m_current->m_effect;
    if (m_current->m_timer >= 30) {
        effect->ScaleTo(0, effect->unk_11C.value, effect->unk_134.value);
        m_current->m_timer = 0xB4;
    } else {
        effect->ScaleTo(0, effect->unk_11C.value, effect->unk_134.value);
        effect->FadeAlpha(0x3C, 0);
    }
    m_current = NULL;
    m_state = 0;
    unk_14->StopSe(0x134);
}

void CBattleAssistPoison::ov1_02133F9C(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (touch->unk_04 == 0) {
        return;
    }
    m_pos.x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
    m_pos.y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
    m_area.pos = m_pos;
    m_area.r = 0x10000;
    for (u8 i = 0; i < 8; i++) {
        if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable()
            && PointInCircle(m_pos, enemies[i]->m_sphere.m_circle)) {
            return;
        }
    }
    m_current = ov1_021341FC();
    if (m_current == NULL) {
        return;
    }
    CBattleAttackEffect *effect = ov1_0212EE3C();
    if (effect == NULL) {
        return;
    }
    effect->ov1_021270FC(unk_0C[0]);
    effect->m_motion.SetPos(m_pos);
    effect->ov1_02127454(0x20, 0);
    effect->ScaleTo(0, 0x28, 0x28);
    effect->ScaleTo(0x3C, 0x1000, 0x1000);
    m_current->m_effect = effect;
    m_current->m_flags |= 1;
    unk_14->PlaySe(0x134);
    m_state = 1;
}

void CBattleAssistPoison::ov1_02134120(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    m_pos.x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
    m_pos.y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
    m_current->m_timer++;
    if (touch->unk_06 == 0 && PointInCircle(m_pos, m_area)) {
        return;
    }
    CBattleAttackEffect *effect = m_current->m_effect;
    if (m_current->m_timer >= 30) {
        effect->ScaleTo(0, effect->unk_11C.value, effect->unk_134.value);
        m_current->m_timer = 0xB4;
    } else {
        effect->ScaleTo(0, effect->unk_11C.value, effect->unk_134.value);
        effect->FadeAlpha(0x3C, 0);
        m_current->m_flags &= ~1;
    }
    m_current = NULL;
    m_state = 0;
}

PoisonSlot *CBattleAssistPoison::ov1_021341FC()
{
    for (u8 i = 0; i < 16; i++) {
        if (!(m_slots[i].m_flags & 1) && m_slots[i].m_effect == NULL) {
            return &m_slots[i];
        }
    }
    return NULL;
}
