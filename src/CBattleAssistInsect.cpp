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

extern "C" fx32 ov1_0212EE80(int assistType, int type);
extern "C" u16 ov1_0212EE98(int assistType, int idx);

static const fx32 sSpeeds[] = { 0, 0x2000, 0x4000, 0x8000 };

CBattleAssistInsect::CBattleAssistInsect(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, BattleParamTable *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
    MI_CpuFill8(m_slots, 0, sizeof(m_slots));
    MI_CpuFill8(m_bugs, 0, sizeof(m_bugs));
}

CBattleAssistInsect::~CBattleAssistInsect()
{
}

int CBattleAssistInsect::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    for (u8 i = 0; i < 4; i++) {
        if ((m_slots[i].m_flags & 1) && !m_effects[i]->HasData()) {
            m_effects[i]->ov1_02127300();
            m_effects[i] = NULL;
            m_slots[i].m_flags &= ~1;
        }
    }
    InsectBug *bug;
    for (u8 k = 0; k < 16; k++) {
        bug = &m_bugs[k];
        if (bug->m_flags & 1) {
            bug->m_effect->FadeAlpha(0x40, 0);
            bug->m_flags &= ~1;
        } else if (bug->m_effect != NULL && bug->m_effect->unk_108.value == 0) {
            bug->m_effect->ov1_02127300();
            bug->m_effect = NULL;
        }
    }
    u8 *level = &MAIN_BSS_020B26A0.m_stylerLevel;
    for (u8 j = 0; j < 8; j++) {
        if (enemies[j] != NULL && enemies[j]->IsAlive() && enemies[j]->IsTargetable()) {
            Circle area;
            Circle circle = enemies[j]->m_sphere.m_circle;
            area = circle;
            for (u8 i = 0; i < 4; i++) {
                if (m_effects[i] == NULL || !CircleHitCircle(area, m_effects[i]->m_sphere.m_circle, NULL)) {
                    continue;
                }
                u16 power = unk_10->ov1_0212F32C(11, *level, (u8)(m_slots[i].m_level - 1));
                fx32 rate = ov1_0212EE80(vfunc_10(), enemies[j]->unk_184->unk_18->unk_03);
                enemies[j]->ov1_02126310((u16)(FX32_MUL(rate, power << FX32_SHIFT) >> FX32_SHIFT), TRUE);
                if (rate == 0x1000) {
                    enemies[j]->unk_1A8->ov1_02128598(0);
                } else if (rate > 0x1000) {
                    enemies[j]->unk_1A8->ov1_02128598(1);
                } else if (rate < 0x1000) {
                    enemies[j]->unk_1A8->ov1_02128598(2);
                }
                enemies[j]->ov1_021263A4(3, ov1_0212EE98(vfunc_10(), (u8)(m_slots[i].m_level - 1)));
                m_effects[i]->ov1_02127300();
                m_effects[i] = NULL;
                m_slots[i].m_flags &= ~1;
                unk_14->PlaySe(0x13A);
                u8 idx;
                if (ov1_02133B08(&idx)) {
                    InsectBug *bug = &m_bugs[idx];
                    bug->m_flags |= 1;
                    bug->m_timer = 0;
                    if (bug->m_effect != NULL) {
                        bug->m_effect->ov1_02127300();
                    }
                    bug->m_effect = ov1_0212EE3C();
                    if (bug->m_effect == NULL) {
                        continue;
                    }
                    bug->m_effect->ov1_021270FC(unk_0C[1]);
                    bug->m_effect->ov1_02127454(0x20, 2);
                    CBattleEnemy *enemy = enemies[j];
                    Point2D pos;
                    pos = enemy->m_motion.m_pos;
                    pos += enemy->unk_484;
                    pos.y -= enemy->m_bobHeight + (enemy->unk_8C + enemy->m_jumpHeight);
                    bug->m_effect->m_motion.SetPos(pos);
                }
            }
        }
    }
    switch (m_state) {
    case 0:
        ov1_021335A4(touch, disk, enemies);
        break;
    case 1:
        ov1_021336CC(touch, disk, enemies);
        break;
    }
    if (unk_04 == 0) {
        return 0;
    }
    unk_04--;
    return 1;
}

int CBattleAssistInsect::vfunc_10()
{
    return 11;
}

void CBattleAssistInsect::ov1_021335A4(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (touch->unk_04 == 0) {
        return;
    }
    m_start.x = m_end.x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
    m_start.y = m_end.y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
    m_line.p1 = m_start;
    m_startMark = ov1_0212EE3C();
    m_startMark->ov1_021270FC(unk_0C[0]);
    m_startMark->m_motion.SetPos(m_start);
    m_startMark->ov1_02127454(0x20, 0);
    m_string = ov1_0212EE3C();
    m_string->ov1_021270FC(unk_0C[0]);
    m_string->m_motion.SetPos(m_start);
    m_string->ov1_02127454(0x20, 1);
    m_string->ScaleTo(0, 0x28, 0x28);
    m_endMark = ov1_0212EE3C();
    m_endMark->ov1_021270FC(unk_0C[0]);
    m_endMark->m_motion.SetPos(m_end);
    m_endMark->ov1_02127454(0x20, 2);
    unk_14->PlaySe(0x138);
    m_state = 1;
}

void CBattleAssistInsect::ov1_021336CC(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (touch->unk_06 != 0) {
        u8 level = ov1_02133AAC(ApproxLength(m_end.x - m_start.x, m_end.y - m_start.y));
        u8 idx;
        if (level != 0 && ov1_02133AD4(&idx)) {
            CBattleAttackEffect *effect = ov1_0212EE3C();
            m_effects[idx] = effect;
            effect->ov1_021270FC(unk_0C[0]);
            effect->ov1_02127454(0x20, 2);
            effect->m_motion.SetPos(m_end);
            effect->m_motion.MoveInDirection(FX_Atan2Idx(m_start.y - m_end.y, m_start.x - m_end.x), sSpeeds[level]);
            m_slots[idx].m_level = level;
            unk_14->PlaySe(0x139);
            m_slots[idx].m_flags |= 1;
        }
        m_startMark->ov1_02127300();
        m_string->ov1_02127300();
        m_endMark->ov1_02127300();
        unk_14->StopSe(0x138);
        m_state = 0;
        return;
    }
    m_end.x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
    m_end.y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
    m_endMark->m_motion.SetPos(m_end);
    m_line.p2 = m_end;
    fx32 dist = ApproxLength(m_end.x - m_start.x, m_end.y - m_start.y);
    m_string->ScaleTo(0, ((fx64)dist << FX32_SHIFT) / 0x2C000, 0x1000);
    m_string->LookAt(m_end);
    BOOL hit = FALSE;
    for (u8 i = 0; i < 8; i++) {
        if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable()
            && SegmentHitCircle(m_line, enemies[i]->m_sphere.m_circle, NULL, 0)
            && enemies[i]->m_bobHeight + (enemies[i]->unk_8C + enemies[i]->m_jumpHeight) < 0x8000) {
            hit = TRUE;
        }
    }
    for (u8 i = 0; i < 0x60; i++) {
        if (m_targets[i]->HasData() && m_targets[i]->IsUnk100Clear()
            && SegmentHitCircle(m_line, m_targets[i]->m_sphere.m_circle, NULL, 0)
            && m_targets[i]->m_bobHeight + (m_targets[i]->unk_8C + m_targets[i]->m_jumpHeight) < 0x8000) {
            hit = TRUE;
        }
    }
    if (!hit) {
        return;
    }
    m_startMark->ov1_02127300();
    m_string->ov1_02127300();
    m_endMark->ov1_02127300();
    unk_14->StopSe(0x138);
    m_state = 0;
}

void CBattleAssistInsect::vfunc_0C()
{
    if (m_state == 1) {
        m_startMark->ov1_02127300();
        m_string->ov1_02127300();
        m_endMark->ov1_02127300();
        m_state = 0;
    }
    unk_14->StopSe(0x138);
    unk_14->StopSe(0x139);
    unk_14->StopSe(0x13A);
}

u8 CBattleAssistInsect::ov1_02133AAC(fx32 dist)
{
    if (dist < 0x10000) {
        return 0;
    }
    if (dist < 0x30000) {
        return 1;
    }
    if (dist < 0x5C000) {
        return 2;
    }
    return 3;
}

BOOL CBattleAssistInsect::ov1_02133AD4(u8 *idx)
{
    for (u8 i = 0; i < 4; i++) {
        if (!(m_slots[i].m_flags & 1)) {
            *idx = i;
            return TRUE;
        }
    }
    return FALSE;
}

// Scans m_slots with the bug count (the original reads past m_slots into m_bugs)
BOOL CBattleAssistInsect::ov1_02133B08(u8 *idx)
{
    for (u8 i = 0; i < 16; i++) {
        if (!(m_slots[i].m_flags & 1)) {
            *idx = i;
            return TRUE;
        }
    }
    return FALSE;
}

void CBattleAssistInsect::ov1_02133B3C(CBattleAttackEffect **effects)
{
    m_targets = effects;
}
