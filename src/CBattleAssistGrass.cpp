#include "CGame.hpp"
#include "CTouchPanel.hpp"
#include "UnkClass_02034478.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleAttackEffect.hpp"
#include "battle/CBattleDisk.hpp"
#include "battle/CBattleEnemy.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "fx_utils.hpp"
#include "sub_02006000.hpp"
#include "sub_02007254.hpp"

extern "C" u16 ov1_0212EE98(int assistType, int idx);

CBattleAssistGrass::CBattleAssistGrass(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
    m_next = 0;
    m_bound = 0;
    MI_CpuFill8(m_slots, 0, sizeof(m_slots));
}

CBattleAssistGrass::~CBattleAssistGrass()
{
}

int CBattleAssistGrass::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (unk_04 == 0) {
        return 0;
    }
    unk_04--;
    for (u8 k = 0; k < 0x18; k++) {
        GrassSlot *slot = &m_slots[k];
        if (!(slot->m_flags & 1)) {
            continue;
        }
        if ((slot->m_flags & 4) && !slot->m_effect->ov1_0212747C()) {
            slot->m_effect->ov1_02127454(0x20, 1);
            slot->m_effect->ov1_021273A0(8, slot->m_size);
            slot->m_flags &= ~4;
        }
        slot->m_timer++;
        if (slot->m_timer >= 300) {
            slot->m_effect->sub_020129F4(0x18, 0);
            slot->m_flags &= ~1;
            continue;
        }
        m_prevBound = m_bound;
        Circle circle = slot->m_effect->m_sphere.m_circle;
        for (u8 i = 0; i < 8; i++) {
            if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable() && !enemies[i]->ov1_02126424()) {
                if (sub_02006164(circle, enemies[i]->m_sphere.m_circle, NULL)) {
                    u16 duration = ov1_0212EE98(vfunc_10(), 0);
                    switch (enemies[i]->unk_184->unk_18->unk_03) {
                    case 2:
                    case 8:
                    case 12:
                        duration = FX32_MUL(duration << FX32_SHIFT, 0x2000) >> FX32_SHIFT;
                        break;
                    case 1:
                    case 4:
                    case 7:
                    case 9:
                    case 11:
                    case 14:
                    case 16:
                        duration = FX32_MUL(duration << FX32_SHIFT, 0xC00) >> FX32_SHIFT;
                        break;
                    }
                    enemies[i]->ov1_021263A4(3, duration);
                    if (!(slot->m_flags & 2)) {
                        slot->m_effect->ov1_02127454(0x20, 2);
                        slot->m_effect->ov1_021273A0(9, slot->m_size);
                        m_bound++;
                        slot->m_flags |= 2;
                    }
                } else if (slot->m_flags & 2) {
                    slot->m_effect->ov1_02127454(0x20, 1);
                    slot->m_effect->ov1_021273A0(8, slot->m_size);
                    m_bound--;
                    slot->m_flags &= ~2;
                }
            }
        }
        if (m_prevBound == 0 && m_bound >= 1) {
            unk_14->sub_02034C44(0x130);
        } else if (m_bound == 0 && m_prevBound >= 1) {
            unk_14->sub_02034C5C(0x130);
        }
    }
    if (touch->unk_04 != 0) {
        m_last.x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
        m_last.y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
    } else if (disk->ov1_0212C5C0()) {
        fx32 x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
        fx32 y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
        if (sub_02007254(x - m_last.x, y - m_last.y) >= 0x10000) {
            ov1_02131FE4(x, y);
            unk_14->sub_02034C44(0x12F);
            m_last.x = x;
            m_last.y = y;
        }
    }
    return 1;
}

int CBattleAssistGrass::vfunc_10()
{
    return 4;
}

void CBattleAssistGrass::vfunc_0C()
{
    unk_14->sub_02034C5C(0x12F);
    unk_14->sub_02034C5C(0x130);
}

GrassSlot *CBattleAssistGrass::ov1_02131FE4(fx32 x, fx32 y)
{
    GrassSlot *slot = &m_slots[m_next];
    if (slot->m_effect != NULL) {
        slot->m_effect->ov1_02127300();
    }
    slot->m_effect = ov1_0212EE3C();
    if (slot->m_effect == NULL) {
        return NULL;
    }
    u16 roll = MATH_Rand16(&CGame::GetInstance()->m_rand16, 100);
    if (roll <= 1) {
        slot->m_size = 2;
    } else if (roll <= 10) {
        slot->m_size = 1;
    } else {
        slot->m_size = 0;
    }
    slot->m_effect->ov1_021270FC(unk_0C[0]);
    slot->m_effect->ov1_02127454(0x20, 0);
    slot->m_effect->ov1_021273A0(7, slot->m_size);
    CBattleAttackEffect *effect = slot->m_effect;
    effect->m_motion.sub_02011D1C(x);
    effect->m_motion.sub_02011D2C(y);
    slot->m_timer = 0;
    slot->m_flags |= 5;
    m_next++;
    if (m_next >= 0x18) {
        m_next -= 0x18;
    }
    return slot;
}
