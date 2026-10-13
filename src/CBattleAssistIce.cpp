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

CBattleAssistIce::CBattleAssistIce(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
}

CBattleAssistIce::~CBattleAssistIce()
{
}

int CBattleAssistIce::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (unk_04 == 0) {
        return 0;
    }
    unk_04--;
    for (u8 i = 0; i < 4; i++) {
        if (m_effects[i] != NULL && !m_effects[i]->HasData()) {
            m_effects[i]->ov1_02127300();
            m_effects[i] = NULL;
        }
    }
    m_disk = disk;
    ov1_021329C8(enemies);
    Point2D pos;
    pos.x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
    pos.y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
    if (touch->unk_04 != 0) {
        m_last = pos;
        u8 idx = 0;
        if (ov1_02132BD4(&idx)) {
            m_selected = idx;
            m_effects[idx]->m_motion.sub_02011D3C(pos);
            m_flags |= 1;
            unk_14->sub_02034C44(0x124);
        }
    }
    if (touch->unk_05 != 0 && (m_flags & 1)) {
        if (m_effects[m_selected] != NULL && m_effects[m_selected]->HasData()) {
            ov1_02132EC4(pos);
            if (sub_02007254(m_last.y - pos.y, m_last.x - pos.x) > 0x8000) {
                fx32 scale = m_slots[m_selected].scale + 10;
                if (scale <= 0x2000) {
                    m_slots[m_selected].scale = scale;
                    m_slots[m_selected].growth++;
                }
                unk_14->sub_02034C44(0x124);
            }
            m_effects[m_selected]->m_motion.sub_02011D3C(pos);
            m_slots[m_selected].level = ov1_021330DC(m_disk->unk_1B8->unk_54CC);
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
                m_effects[m_selected]->m_motion.sub_02011C90(angle, 0x1800);
                unk_14->sub_02034C44(0x125);
                m_slots[m_selected].thrown = 1;
            } else {
                m_effects[m_selected]->ov1_02127300();
                m_effects[m_selected] = NULL;
            }
        }
        m_flags &= ~1;
    }
    for (u8 i = 0; i < 8; i++) {
        switch (m_freeze[i].state) {
        case 0:
            break;
        case 1:
            if (!m_freeze[i].effect->ov1_0212747C()) {
                m_freeze[i].state = 2;
                m_freeze[i].effect->ov1_021273A0(8, m_freeze[i].size);
            }
            break;
        case 2:
            if (enemies[i]->unk_18C == 0 || !enemies[i]->HasData()) {
                m_freeze[i].state = 3;
                m_freeze[i].effect->ov1_021273A0(9, m_freeze[i].size);
                unk_14->sub_02034C44(0x151);
            }
            break;
        case 3:
            if (!m_freeze[i].effect->ov1_0212747C()) {
                m_freeze[i].state = 0;
                m_freeze[i].effect->ov1_02127300();
                m_freeze[i].effect = NULL;
            }
            break;
        }
    }
    return 1;
}

void CBattleAssistIce::ov1_021329C8(CBattleEnemy **enemies)
{
    for (u8 i = 0; i < 4; i++) {
        if (m_effects[i] == NULL || !m_effects[i]->HasData()) {
            continue;
        }
        m_effects[i]->sub_02012A3C(0, m_slots[i].scale, m_slots[i].scale);
        if ((m_flags & 1) && m_selected == i) {
            continue;
        }
        if (m_effects[i]->IsUnk100Clear() && ov1_02132CAC(m_effects[i], enemies, m_slots[i].level)) {
            m_effects[i]->m_motion.m_mode = 0;
            m_effects[i]->ov1_02127454(0x20, 2);
            m_effects[i]->ov1_02127388(FALSE);
            m_slots[i].state = 2;
        }
        if (m_effects[i]->IsUnk100Clear() && m_slots[i].thrown == 1) {
            if (m_slots[i].timer == 0x78) {
                m_effects[i]->m_motion.m_mode = 0;
                m_effects[i]->ov1_02127454(0x20, 2);
                m_effects[i]->ov1_02127388(FALSE);
                m_slots[i].state = 2;
                m_slots[i].thrown = 0;
                m_slots[i].timer = 0;
            } else if (m_slots[i].timer < 0x78) {
                m_slots[i].timer++;
            }
        }
        if (m_slots[i].state == 2 && !m_effects[i]->ov1_0212747C()) {
            m_effects[i]->ov1_02127300();
            m_effects[i] = NULL;
        }
    }
}

BOOL CBattleAssistIce::ov1_02132B78(u8 *idx)
{
    for (u8 i = 0; i < 4; i++) {
        if (m_effects[i] == NULL || !m_effects[i]->HasData()) {
            *idx = i;
            return TRUE;
        }
    }
    return FALSE;
}

BOOL CBattleAssistIce::ov1_02132BD4(u8 *outIdx)
{
    u8 idx = 0;
    if (!ov1_02132B78(&idx)) {
        return FALSE;
    }
    CBattleAttackEffect *effect = ov1_0212EE3C();
    if (effect == NULL) {
        return FALSE;
    }
    m_slots[idx].thrown = 0;
    m_slots[idx].state = 0;
    m_slots[idx].timer = 0;
    m_slots[idx].scale = 0x800;
    m_slots[idx].growth = 0;
    effect->ov1_021270FC(unk_0C[0]);
    effect->ov1_02127454(0x20, 0);
    effect->ov1_02127388(TRUE);
    effect->sub_02012A3C(0, 0x800, 0x800);
    m_effects[idx] = effect;
    *outIdx = idx;
    return TRUE;
}

BOOL CBattleAssistIce::ov1_02132CAC(CBattleAttackEffect *effect, CBattleEnemy **enemies, u8 level)
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
            if (rate == 0x1000) {
                unk_14->sub_02034C44(0x126);
                enemies[i]->unk_1A8->ov1_02128598(0);
            } else if (rate > 0x1000) {
                unk_14->sub_02034C44(0x144);
                enemies[i]->unk_1A8->ov1_02128598(1);
            } else if (rate < 0x1000) {
                unk_14->sub_02034C44(0x145);
                enemies[i]->unk_1A8->ov1_02128598(2);
            }
            enemies[i]->ov1_021263A4(4, ov1_0212EE98(vfunc_10(), level));
            ov1_02132FD4(&m_freeze[i], enemies[i]);
            return TRUE;
        }
    }
    return FALSE;
}

int CBattleAssistIce::vfunc_10()
{
    return 5;
}

u8 CBattleAssistIce::ov1_02132EC4(Point2D pos)
{
    int angle = FX_Atan2Idx(m_last.y - pos.y, m_last.x - pos.x) - 0xB004;
    if (angle < 0) {
        angle += 0x10000;
    }
    return angle >> 13;
}

void CBattleAssistIce::vfunc_0C()
{
    if (m_flags & 1) {
        if (m_effects[m_selected] != NULL && m_effects[m_selected]->HasData()) {
            m_effects[m_selected]->ov1_02127300();
            m_effects[m_selected] = NULL;
        }
        m_flags &= ~1;
    }
    unk_14->sub_02034C5C(0x124);
    unk_14->sub_02034C5C(0x125);
    unk_14->sub_02034C5C(0x126);
    unk_14->sub_02034C5C(0x144);
    unk_14->sub_02034C5C(0x145);
    unk_14->sub_02034C5C(0x150);
    unk_14->sub_02034C5C(0x151);
}

void CBattleAssistIce::ov1_02132FD4(IceFreeze *freeze, CBattleEnemy *enemy)
{
    if (freeze->effect != NULL) {
        freeze->effect->ov1_02127300();
    }
    freeze->effect = ov1_0212EE3C();
    if (freeze->effect == NULL) {
        return;
    }
    freeze->timer = 0;
    freeze->state = 1;
    Circle circle = enemy->m_sphere.m_circle;
    if (circle.r >= 0x10000) {
        freeze->size = 2;
    } else if (circle.r <= 0xB000) {
        freeze->size = 0;
    } else {
        freeze->size = 1;
    }
    freeze->effect->ov1_021270FC(unk_0C[1]);
    freeze->effect->ov1_021273A0(7, freeze->size);
    Point2D pos = enemy->m_motion.m_pos;
    pos += enemy->unk_484;
    pos.y -= enemy->m_bobHeight + (enemy->unk_8C + enemy->m_jumpHeight);
    freeze->effect->m_motion.sub_02011D3C(pos);
    unk_14->sub_02034C44(0x150);
}

u8 CBattleAssistIce::ov1_021330DC(u32 value)
{
    if (value >= 0x28) {
        return 2;
    }
    if (value >= 0x14) {
        return 1;
    }
    return 0;
}
