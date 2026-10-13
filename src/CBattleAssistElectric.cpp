#include "CTouchPanel.hpp"
#include "UnkClass_02034478.hpp"
#include "UnkClass_020B26A0.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleAttackEffect.hpp"
#include "battle/CBattleEnemy.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "battle/UnkClass_02128414.hpp"
#include "battle/UnkClass_0212EEB4.hpp"
#include "fx_utils.hpp"
#include "sub_02006000.hpp"

extern "C" fx32 ov1_0212EE80(int assistType, int type);
extern "C" u16 ov1_0212EE98(int assistType, int idx);

CBattleAssistElectric::CBattleAssistElectric(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
}

CBattleAssistElectric::~CBattleAssistElectric()
{
}

int CBattleAssistElectric::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (unk_04 == 0) {
        return 0;
    }
    unk_04--;
    if (touch->unk_04 != 0) {
        BOOL hit = FALSE;
        Point2D pos;
        pos.x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
        pos.y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
        for (u8 i = 0; i < 8; i++) {
            if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable()
                && sub_02006100(pos, enemies[i]->m_sphere.m_circle)) {
                hit = TRUE;
            }
        }
        if (!hit) {
            ElectricBolt *bolt = ov1_02130038();
            if (bolt != NULL) {
                ov1_02130074(bolt, pos.x, pos.y);
                unk_14->sub_02034C44(0x131);
            }
        }
    }
    u8 *level = &MAIN_BSS_020B26A0.unk_87DB;
    if (m_bolts[0].m_flags & 1) {
        m_bolts[0].m_timer++;
        switch (m_bolts[0].m_timer) {
        case 0x3C:
            m_bolts[0].m_effect->ov1_02127454(0x20, 0);
            m_bolts[0].m_effect->m_motion.sub_02011D2C(m_bolts[0].m_effect->m_motion.m_pos.y - 0x60000);
            unk_14->sub_02034C44(0x132);
            break;
        case 0x46: {
            m_bolts[0].m_effect->ov1_02127454(0x20, 2);
            m_bolts[0].m_effect->m_motion.sub_02011D2C(m_bolts[0].m_effect->m_motion.m_pos.y + 0x60000);
            unk_14->sub_02034C44(0x133);
            Point2D pos = m_bolts[0].m_effect->m_motion.m_pos;
            Circle area;
            area.pos = pos;
            area.r = 0x20000;
            for (u8 i = 0; i < 8; i++) {
                if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable()
                    && sub_02006164(area, enemies[i]->m_sphere.m_circle, NULL)) {
                    u16 power = unk_10->ov1_0212F32C(vfunc_10(), *level, 0);
                    fx32 rate = ov1_0212EE80(vfunc_10(), enemies[i]->unk_184->unk_18->unk_03);
                    enemies[i]->ov1_02126310((u16)(FX32_MUL(rate, power << FX32_SHIFT) >> FX32_SHIFT), TRUE);
                    enemies[i]->ov1_021263A4(4, ov1_0212EE98(vfunc_10(), 0));
                    if (rate == 0x1000) {
                        enemies[i]->unk_1A8->ov1_02128598(0);
                    } else if (rate > 0x1000) {
                        enemies[i]->unk_1A8->ov1_02128598(1);
                    } else if (rate < 0x1000) {
                        enemies[i]->unk_1A8->ov1_02128598(2);
                    }
                }
            }
            break;
        }
        case 0x5E:
            m_bolts[0].m_flags &= ~1;
            break;
        }
    }
    return 1;
}

int CBattleAssistElectric::vfunc_10()
{
    return 3;
}

void CBattleAssistElectric::vfunc_0C()
{
    unk_14->sub_02034C5C(0x131);
    unk_14->sub_02034C5C(0x132);
    unk_14->sub_02034C5C(0x133);
}

ElectricBolt *CBattleAssistElectric::ov1_02130038()
{
    for (u8 i = 0; i < 1; i++) {
        if (!(m_bolts[i].m_flags & 1)) {
            return &m_bolts[i];
        }
    }
    return NULL;
}

void CBattleAssistElectric::ov1_02130074(ElectricBolt *bolt, fx32 x, fx32 y)
{
    if (bolt->m_effect != NULL) {
        bolt->m_effect->ov1_02127300();
    }
    if (bolt->m_effect2 != NULL) {
        bolt->m_effect2->ov1_02127300();
    }
    bolt->m_effect = ov1_0212EE3C();
    if (bolt->m_effect == NULL) {
        bolt->m_flags &= ~1;
        return;
    }
    bolt->m_effect->ov1_021270FC(unk_0C[0]);
    bolt->m_effect->ov1_02127454(0x20, 3);
    bolt->m_effect->m_motion.sub_02011D1C(x);
    bolt->m_effect->m_motion.sub_02011D2C(y);
    bolt->m_timer = 0;
    bolt->m_flags |= 1;
}
