#include "CTouchPanel.hpp"
#include "UnkClass_02034478.hpp"
#include "UnkClass_020B26A0.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleAttackEffect.hpp"
#include "battle/CBattleDisk.hpp"
#include "battle/CBattleEnemy.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "battle/UnkClass_0212306C.hpp"
#include "battle/UnkClass_02128414.hpp"
#include "battle/UnkClass_0212EEB4.hpp"
#include "fx_utils.hpp"
#include "sub_02006000.hpp"
#include "sub_02007254.hpp"

extern "C" fx32 ov1_0212EE80(int assistType, int type);
extern "C" u16 ov1_0212EE98(int assistType, int idx);

CBattleAssistSteel::CBattleAssistSteel(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
}

CBattleAssistSteel::~CBattleAssistSteel()
{
}

int CBattleAssistSteel::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (unk_04 == 0) {
        return 0;
    }
    unk_04--;
    ov1_02134E04(enemies);
    Point2D pos;
    pos.x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
    pos.y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
    if (touch->unk_04 != 0) {
        m_last = pos;
        u8 idx = 0;
        if (ov1_02134F68(&idx)) {
            m_selected = idx;
            m_effects[idx]->m_motion.sub_02011D3C(pos);
            m_flags |= 1;
            unk_14->sub_02034C44(0x140);
        }
    }
    if (touch->unk_05 != 0) {
        if ((m_flags & 1) && m_effects[m_selected] != NULL && m_effects[m_selected]->HasData()) {
            if (sub_02007254(m_last.y - pos.y, m_last.x - pos.x) > 0x5000) {
                fx32 scale = m_slots[m_selected].m_scale + 0x28;
                if (scale < 0x1000) {
                    m_slots[m_selected].m_scale = scale;
                }
            } else {
                fx32 scale = m_slots[m_selected].m_scale - 0x14;
                if (scale > 0x333) {
                    m_slots[m_selected].m_scale = scale;
                }
            }
            m_slots[m_selected].m_level = ov1_021352B0(m_slots[m_selected].m_scale);
            m_effects[m_selected]->sub_02012A3C(0, m_slots[m_selected].m_scale, m_slots[m_selected].m_scale);
            m_effects[m_selected]->m_motion.sub_02011D3C(pos);
            if (m_effects[m_selected] != NULL && m_effects[m_selected]->HasData()) {
                m_effects[m_selected]->m_motion.sub_02011D3C(pos);
            }
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
                m_effects[m_selected]->m_motion.sub_02011D3C(pos);
                u16 angle = FX_Atan2Idx(pos.y - m_last.y, pos.x - m_last.x);
                m_effects[m_selected]->m_motion.sub_02011C90(angle, 0x4000);
                m_slots[m_selected].m_flags |= 1;
                unk_14->sub_02034C44(0x141);
            } else {
                m_effects[m_selected]->ov1_02127300();
            }
            unk_14->sub_02034C5C(0x140);
        }
        m_flags &= ~1;
    }
    return 1;
}

void CBattleAssistSteel::ov1_02134E04(CBattleEnemy **enemies)
{
    for (u8 i = 0; i < 4; i++) {
        if (m_effects[i] == NULL || !m_effects[i]->HasData()) {
            continue;
        }
        if ((m_flags & 1) && m_selected == i) {
            continue;
        }
        if (m_effects[i]->IsUnk100Clear() && ov1_0213502C(m_effects[i], enemies, m_slots[i].m_level)) {
            m_effects[i]->m_motion.m_mode = 0;
            m_effects[i]->ov1_021273A0(8, 2);
            m_effects[i]->ov1_02127388(FALSE);
            m_slots[i].m_state = 1;
        }
        if (m_slots[i].m_state == 1 && !m_effects[i]->ov1_0212747C()) {
            m_effects[i]->ov1_02127300();
        }
    }
}

BOOL CBattleAssistSteel::ov1_02134F0C(u8 *idx)
{
    for (u8 i = 0; i < 4; i++) {
        if (m_effects[i] == NULL || !m_effects[i]->HasData()) {
            *idx = i;
            return TRUE;
        }
    }
    return FALSE;
}

BOOL CBattleAssistSteel::ov1_02134F68(u8 *outIdx)
{
    u8 idx = 0;
    if (!ov1_02134F0C(&idx)) {
        return FALSE;
    }
    CBattleAttackEffect *effect = ov1_0212EE3C();
    if (effect == NULL) {
        return FALSE;
    }
    m_slots[idx].m_flags = 0;
    m_slots[idx].m_state = 0;
    m_slots[idx].m_timer = 0;
    m_slots[idx].m_scale = 0x333;
    effect->ov1_021270FC(unk_0C[0]);
    effect->ov1_021273A0(7, 2);
    effect->ov1_02127388(TRUE);
    m_effects[idx] = effect;
    *outIdx = idx;
    return TRUE;
}

BOOL CBattleAssistSteel::ov1_0213502C(CBattleAttackEffect *effect, CBattleEnemy **enemies, u8 level)
{
    Circle area;
    Circle circle = effect->m_sphere.m_circle;
    area = circle;
    for (int i = 0; i < 8; i++) {
        if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable()
            && sub_02006164(area, enemies[i]->m_sphere.m_circle, NULL)) {
            u16 power = unk_10->ov1_0212F32C(vfunc_10(), MAIN_BSS_020B26A0.unk_87DB, level);
            fx32 rate = ov1_0212EE80(vfunc_10(), enemies[i]->unk_184->unk_18->unk_03);
            enemies[i]->ov1_02126310((u16)(FX32_MUL(rate, power << FX32_SHIFT) >> FX32_SHIFT), TRUE);
            enemies[i]->ov1_021263A4(1, ov1_0212EE98(vfunc_10(), level));
            if (rate == 0x1000) {
                unk_14->sub_02034C44(0x142);
                enemies[i]->unk_1A8->ov1_02128598(0);
            } else if (rate > 0x1000) {
                unk_14->sub_02034C44(0x14E);
                enemies[i]->unk_1A8->ov1_02128598(1);
            } else if (rate < 0x1000) {
                unk_14->sub_02034C44(0x14F);
                enemies[i]->unk_1A8->ov1_02128598(2);
            }
            return TRUE;
        }
    }
    return FALSE;
}

int CBattleAssistSteel::vfunc_10()
{
    return 16;
}

void CBattleAssistSteel::vfunc_0C()
{
    if (m_flags & 1) {
        m_effects[m_selected]->ov1_02127300();
        m_flags &= ~1;
    }
    unk_14->sub_02034C5C(0x140);
    unk_14->sub_02034C5C(0x141);
    unk_14->sub_02034C5C(0x142);
    unk_14->sub_02034C5C(0x14E);
    unk_14->sub_02034C5C(0x14F);
}

u8 CBattleAssistSteel::ov1_021352B0(fx32 scale)
{
    if (scale <= 0x800) {
        return 0;
    }
    if (scale <= 0xE66) {
        return 1;
    }
    return 2;
}
