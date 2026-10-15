#include "AudioEngine.hpp"
#include "CTouchPanel.hpp"
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

extern "C" fx32 GetAssistTypeRate(int assistType, int type);
extern "C" u16 GetAssistEffectTime(int assistType, int idx);

CBattleAssistEsper::CBattleAssistEsper(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, BattleParamTable *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
}

CBattleAssistEsper::~CBattleAssistEsper()
{
}

int CBattleAssistEsper::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
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
        for (u8 i = 0; i < 4; i++) {
            if (m_effects[i] != NULL && m_effects[i]->HasData() && IsInRect(pos, m_slots[i].rect)) {
                m_selected = i;
                m_last = pos;
                m_flags |= 2;
                break;
            }
        }
    }
    if (touch->unk_05 != 0) {
        if (!(m_flags & 2) && disk->IsLoopClosed()) {
            for (u8 i = 0; i < 8; i++) {
                if (enemies[i] != NULL && enemies[i]->IsAlive()
                    && disk->unk_1B8->IsInsideLoop(enemies[i]->m_motion.m_pos.x, enemies[i]->m_motion.m_pos.y)) {
                    return 1;
                }
            }
            Rectangle rect = disk->unk_1B8->m_rect.m_rectangle;
            if (rect.size.x >= 0x20000 && rect.size.y >= 0x20000) {
                u8 idx = 0;
                if (CreateEffect(&idx)) {
                    m_selected = idx;
                    Rectangle *dst = &m_slots[idx].rect;
                    dst->pos = rect.pos;
                    dst->size = rect.size;
                    m_slots[idx].rect.size.x = 0x30000;
                    m_slots[idx].rect.size.y = 0x20000;
                    CBattleAttackEffect *effect = m_effects[idx];
                    effect->m_motion.SetX(rect.pos.x);
                    effect->m_motion.SetY(rect.pos.y);
                    m_effects[idx]->SetCollisionEnabled(FALSE);
                    m_effects[idx]->ScaleTo(0, 0x1000, 0x1000);
                    unk_14->PlaySe(0x127);
                }
            }
        }
        if (m_timer == 10) {
            m_timer = 0;
            m_last = pos;
        } else if (m_timer < 10) {
            m_timer++;
        }
    }
    if (touch->unk_06 != 0) {
        if ((m_flags & 2) && m_effects[m_selected] != NULL && m_effects[m_selected]->HasData()) {
            u16 angle = FX_Atan2Idx(pos.y - m_last.y, pos.x - m_last.x);
            m_effects[m_selected]->m_motion.MoveInDirection(angle, 0x1000);
            m_last = pos;
            m_slots[m_selected].unk_00 = 1;
            unk_14->PlaySe(0x128);
        }
        m_flags &= ~2;
    }
    return 1;
}

void CBattleAssistEsper::UpdateEffects(CBattleEnemy **enemies)
{
    for (u8 i = 0; i < 4; i++) {
        if (m_effects[i] != NULL && m_effects[i]->HasData()) {
            if (m_effects[i]->IsUnk100Clear() && HitEnemies(m_effects[i], enemies)) {
                m_effects[i]->m_motion.m_mode = 0;
                m_effects[i]->PlayAction(0x20, 2);
                m_effects[i]->SetCollisionEnabled(FALSE);
                m_slots[i].state = 2;
            }
            UpdateSlotAnim(i);
            Point2D pos = m_effects[i]->m_motion.m_pos;
            m_slots[i].rect.pos.x = pos.x - FX32_MUL(m_slots[i].rect.size.x, 0x800);
            m_slots[i].rect.pos.y = pos.y - FX32_MUL(m_slots[i].rect.size.y, 0x800);
        }
    }
}

void CBattleAssistEsper::UpdateSlotAnim(u8 i)
{
    if (!m_effects[i]->IsAnimActive() && m_slots[i].state == 0) {
        m_slots[i].state = 1;
        m_effects[i]->PlayAction(0x20, 1);
        m_effects[i]->SetCollisionEnabled(TRUE);
    }
    if (!m_effects[i]->IsAnimActive() && m_slots[i].state == 2) {
        m_effects[i]->Terminate();
    }
}

BOOL CBattleAssistEsper::FindFreeSlot(u8 *idx)
{
    for (u8 i = 0; i < 4; i++) {
        if (m_effects[i] == NULL || !m_effects[i]->HasData()) {
            *idx = i;
            return TRUE;
        }
    }
    return FALSE;
}

BOOL CBattleAssistEsper::CreateEffect(u8 *outIdx)
{
    u8 idx = 0;
    if (!FindFreeSlot(&idx)) {
        return FALSE;
    }
    CBattleAttackEffect *effect = GetFreeEffect();
    if (effect == NULL) {
        return FALSE;
    }
    m_slots[idx].unk_00 = 0;
    m_slots[idx].state = 0;
    m_slots[idx].unk_02 = 0;
    effect->Start(unk_0C[0]);
    effect->PlayAction(0x20, 0);
    effect->SetCollisionEnabled(TRUE);
    effect->ScaleTo(0, 0, 0);
    m_effects[idx] = effect;
    *outIdx = idx;
    return TRUE;
}

BOOL CBattleAssistEsper::HitEnemies(CBattleAttackEffect *effect, CBattleEnemy **enemies)
{
    Circle area;
    Circle circle = effect->m_sphere.m_circle;
    area.pos.x = circle.pos.x;
    area.pos.y = circle.pos.y;
    area.r = circle.r;
    BOOL hit = FALSE;
    for (int i = 0; i < 8; i++) {
        if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable()
            && CircleHitCircle(area, enemies[i]->m_sphere.m_circle, NULL)) {
            fx32 rate = GetAssistTypeRate(vfunc_10(), enemies[i]->unk_184->unk_18->unk_03);
            if (effect->m_motion.m_speed != 0) {
                u16 power = unk_10->GetAssistPower(vfunc_10(), MAIN_BSS_020B26A0.m_stylerLevel, 0);
                enemies[i]->TakeDamage((u16)(FX32_MUL(rate, power << FX32_SHIFT) >> FX32_SHIFT), TRUE);
                enemies[i]->SetStatus(4, GetAssistEffectTime(vfunc_10(), 0));
                if (rate == 0x1000) {
                    unk_14->PlaySe(0x129);
                    enemies[i]->unk_1A8->Show(0);
                } else if (rate > 0x1000) {
                    unk_14->PlaySe(0x146);
                    enemies[i]->unk_1A8->Show(1);
                } else if (rate < 0x1000) {
                    unk_14->PlaySe(0x147);
                    enemies[i]->unk_1A8->Show(2);
                }
                hit = TRUE;
            }
        }
    }
    return hit;
}

int CBattleAssistEsper::vfunc_10()
{
    return 10;
}

BOOL CBattleAssistEsper::IsInRect(Point2D pos, Rectangle rect)
{
    if (rect.pos.x <= pos.x && rect.pos.x + rect.size.x >= pos.x && rect.pos.y <= pos.y && rect.pos.y + rect.size.y >= pos.y) {
        return TRUE;
    }
    return FALSE;
}

void CBattleAssistEsper::vfunc_0C()
{
    unk_14->StopSe(0x127);
    unk_14->StopSe(0x128);
    unk_14->StopSe(0x129);
    unk_14->StopSe(0x146);
    unk_14->StopSe(0x147);
}
