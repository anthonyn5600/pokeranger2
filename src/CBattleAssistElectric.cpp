#include "AudioEngine.hpp"
#include "CTouchPanel.hpp"
#include "Collision.hpp"
#include "SaveData.hpp"
#include "battle/BattleEffectivenessMark.hpp"
#include "battle/BattleParamTable.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleAttackEffect.hpp"
#include "battle/CBattleEnemy.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "fx_utils.hpp"

extern "C" fx32 GetAssistTypeRate(int assistType, int type);
extern "C" u16 GetAssistEffectTime(int assistType, int idx);

CBattleAssistElectric::CBattleAssistElectric(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, BattleParamTable *params, u16 arg3)
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
                && PointInCircle(pos, enemies[i]->m_sphere.m_circle)) {
                hit = TRUE;
            }
        }
        if (!hit) {
            ElectricBolt *bolt = FindFreeBolt();
            if (bolt != NULL) {
                StartBolt(bolt, pos.x, pos.y);
                unk_14->PlaySe(0x131);
            }
        }
    }
    u8 *level = &MAIN_BSS_020B26A0.m_stylerLevel;
    if (m_bolts[0].m_flags & 1) {
        m_bolts[0].m_timer++;
        switch (m_bolts[0].m_timer) {
        case 0x3C:
            m_bolts[0].m_effect->PlayAction(0x20, 0);
            m_bolts[0].m_effect->m_motion.SetY(m_bolts[0].m_effect->m_motion.m_pos.y - 0x60000);
            unk_14->PlaySe(0x132);
            break;
        case 0x46: {
            m_bolts[0].m_effect->PlayAction(0x20, 2);
            m_bolts[0].m_effect->m_motion.SetY(m_bolts[0].m_effect->m_motion.m_pos.y + 0x60000);
            unk_14->PlaySe(0x133);
            Point2D pos = m_bolts[0].m_effect->m_motion.m_pos;
            Circle area;
            area.pos = pos;
            area.r = 0x20000;
            for (u8 i = 0; i < 8; i++) {
                if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable()
                    && CircleHitCircle(area, enemies[i]->m_sphere.m_circle, NULL)) {
                    u16 power = unk_10->GetAssistPower(vfunc_10(), *level, 0);
                    fx32 rate = GetAssistTypeRate(vfunc_10(), enemies[i]->unk_184->unk_18->unk_03);
                    enemies[i]->TakeDamage((u16)(FX32_MUL(rate, power << FX32_SHIFT) >> FX32_SHIFT), TRUE);
                    enemies[i]->SetStatus(4, GetAssistEffectTime(vfunc_10(), 0));
                    if (rate == 0x1000) {
                        enemies[i]->unk_1A8->Show(0);
                    } else if (rate > 0x1000) {
                        enemies[i]->unk_1A8->Show(1);
                    } else if (rate < 0x1000) {
                        enemies[i]->unk_1A8->Show(2);
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
    unk_14->StopSe(0x131);
    unk_14->StopSe(0x132);
    unk_14->StopSe(0x133);
}

ElectricBolt *CBattleAssistElectric::FindFreeBolt()
{
    for (u8 i = 0; i < 1; i++) {
        if (!(m_bolts[i].m_flags & 1)) {
            return &m_bolts[i];
        }
    }
    return NULL;
}

void CBattleAssistElectric::StartBolt(ElectricBolt *bolt, fx32 x, fx32 y)
{
    if (bolt->m_effect != NULL) {
        bolt->m_effect->Terminate();
    }
    if (bolt->m_effect2 != NULL) {
        bolt->m_effect2->Terminate();
    }
    bolt->m_effect = GetFreeEffect();
    if (bolt->m_effect == NULL) {
        bolt->m_flags &= ~1;
        return;
    }
    bolt->m_effect->Start(unk_0C[0]);
    bolt->m_effect->PlayAction(0x20, 3);
    bolt->m_effect->m_motion.SetX(x);
    bolt->m_effect->m_motion.SetY(y);
    bolt->m_timer = 0;
    bolt->m_flags |= 1;
}
