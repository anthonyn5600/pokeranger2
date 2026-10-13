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

extern "C" fx32 ov1_0212EE80(int assistType, int type);

static const fx32 sBirdScales[] = { 0x28, 0x400, 0x800, 0xC00, 0x1000, 0x1000 };

// HasData() read as an integer: IRO keeps this second check, the backend merges the loads
static inline BOOL IsLoaded(CBattleAttackEffect *effect)
{
    return (u32)effect->m_data != 0;
}

CBattleAssistFly::CBattleAssistFly(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
    m_bird = NULL;
    m_level = 0;
}

CBattleAssistFly::~CBattleAssistFly()
{
}

int CBattleAssistFly::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    for (u8 i = 0; i < 0x20; i++) {
        if ((m_bird == NULL || unk_08[i] != m_bird) && unk_08[i]->HasData()) {
            unk_08[i]->m_motion.sub_02011C90(unk_08[i]->m_motion.m_angle + 0x200, unk_08[i]->m_motion.m_speed + 0x333);
        }
    }
    if (m_bird != NULL && m_bird->unk_108.value == 0) {
        m_bird->ov1_02127300();
        m_bird = NULL;
    }
    u8 *level = &MAIN_BSS_020B26A0.unk_87DB;
    for (u8 j = 0; j < 8; j++) {
        if (enemies[j] != NULL && enemies[j]->IsAlive() && enemies[j]->IsTargetable()) {
            Circle area;
            Circle circle = enemies[j]->m_sphere.m_circle;
            area = circle;
            for (u8 i = 0; i < 0x20; i++) {
                CBattleAttackEffect *effect = unk_08[i];
                if (effect->HasData() && (m_bird == NULL || effect != m_bird) && IsLoaded(effect)
                    && sub_02006164(area, effect->m_sphere.m_circle, NULL)) {
                    u16 power = unk_10->ov1_0212F32C(vfunc_10(), *level, 0);
                    fx32 rate = ov1_0212EE80(vfunc_10(), enemies[j]->unk_184->unk_18->unk_03);
                    enemies[j]->ov1_02126310((u16)(FX32_MUL(rate, power << FX32_SHIFT) >> FX32_SHIFT), TRUE);
                    if (rate == 0x1000) {
                        unk_14->sub_02034C44(0x137);
                        enemies[j]->unk_1A8->ov1_02128598(0);
                    } else if (rate > 0x1000) {
                        unk_14->sub_02034C44(0x14C);
                        enemies[j]->unk_1A8->ov1_02128598(1);
                    } else if (rate < 0x1000) {
                        unk_14->sub_02034C44(0x14D);
                        enemies[j]->unk_1A8->ov1_02128598(2);
                    }
                    unk_08[i]->ov1_02127300();
                }
            }
        }
    }
    switch (m_state) {
    case 0:
        ov1_021311E4(touch, disk, enemies);
        break;
    case 1:
        ov1_021311F8(touch, disk, enemies);
        break;
    }
    if (unk_04 == 0) {
        return 0;
    }
    unk_04--;
    return 1;
}

int CBattleAssistFly::vfunc_10()
{
    return 9;
}

void CBattleAssistFly::ov1_021311E4(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (touch->unk_04 != 0) {
        m_state = 1;
    }
}

void CBattleAssistFly::ov1_021311F8(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (touch->unk_06 != 0) {
        if (m_bird != NULL) {
            m_bird->sub_020129F4(0x18, 0);
            m_bird->sub_02012A3C(0x18, 0x1800, 0x1800);
            unk_14->sub_02034C5C(0x135);
        }
        m_state = 0;
        return;
    }
    if (!disk->ov1_0212C4CC()) {
        return;
    }
    if (m_bird == NULL) {
        Rectangle rect = disk->unk_1B8->m_rect.m_rectangle;
        ov1_02131410(rect.pos.x, rect.pos.y);
        unk_14->sub_02034C44(0x135);
        return;
    }
    if (disk->unk_1B8->ov1_02124650(m_bird->m_motion.m_pos.x, m_bird->m_motion.m_pos.y)) {
        if (m_level >= 5) {
            for (u8 i = 0; i < 4; i++) {
                ov1_021314A0(m_bird->m_motion.m_pos.x, m_bird->m_motion.m_pos.y, m_angle);
                m_angle += 0x4000;
            }
            m_angle += 0x1000;
            unk_14->sub_02034C44(0x136);
            return;
        }
        m_level++;
        m_bird->sub_02012A3C(0x20, sBirdScales[m_level], sBirdScales[m_level]);
    } else {
        Rectangle rect = disk->unk_1B8->m_rect.m_rectangle;
        ov1_02131410(rect.pos.x, rect.pos.y);
    }
}

void CBattleAssistFly::vfunc_0C()
{
    if (m_bird != NULL) {
        m_bird->sub_020129F4(0x3C, 0);
    }
    m_state = 0;
    unk_14->sub_02034C5C(0x135);
    unk_14->sub_02034C5C(0x136);
    unk_14->sub_02034C5C(0x137);
    unk_14->sub_02034C5C(0x14C);
    unk_14->sub_02034C5C(0x14D);
}

void CBattleAssistFly::ov1_02131410(fx32 x, fx32 y)
{
    if (m_bird != NULL) {
        m_bird->ov1_02127300();
    }
    m_level = 1;
    m_bird = ov1_0212EE3C();
    m_bird->ov1_021270FC(unk_0C[0]);
    m_bird->ov1_02127454(0x20, 0);
    CBattleAttackEffect *bird = m_bird;
    bird->m_motion.sub_02011D1C(x);
    bird->m_motion.sub_02011D2C(y);
    m_bird->sub_02012A3C(0, sBirdScales[m_level], sBirdScales[m_level]);
}

void CBattleAssistFly::ov1_021314A0(fx32 x, fx32 y, u16 angle)
{
    CBattleAttackEffect *effect = ov1_0212EE3C();
    if (effect == NULL) {
        return;
    }
    effect->ov1_021270FC(unk_0C[0]);
    effect->ov1_021273A0(7, 1);
    effect->m_motion.sub_02011D1C(x);
    effect->m_motion.sub_02011D2C(y);
    effect->m_motion.sub_02011C90(angle, 0x4000);
}
