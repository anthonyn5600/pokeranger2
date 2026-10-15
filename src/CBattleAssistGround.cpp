#include "AudioEngine.hpp"
#include "CTouchPanel.hpp"
#include "CameraController.hpp"
#include "MathUtil.hpp"
#include "SaveData.hpp"
#include "battle/BattleEffectivenessMark.hpp"
#include "battle/BattleParamTable.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleEnemy.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "fx_utils.hpp"

extern "C" fx32 GetAssistTypeRate(int assistType, int type);
extern "C" u16 GetAssistEffectTime(int assistType, int idx);

CBattleAssistGround::CBattleAssistGround(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, BattleParamTable *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
}

CBattleAssistGround::~CBattleAssistGround()
{
    m_quake->StopShakeX();
}

void CBattleAssistGround::SetQuake(CameraController *quake)
{
    m_quake = quake;
}

int CBattleAssistGround::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (unk_04 == 0) {
        return 0;
    }
    unk_04--;
    if (m_quake == NULL) {
        return 1;
    }
    fx32 x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
    fx32 y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
    if (touch->unk_04 != 0) {
        m_touching = TRUE;
    }
    if (touch->unk_05 != 0 && m_touching) {
        fx32 dist = ApproxLength(x - m_last.x, y - m_last.y);
        if (dist > 0x8000) {
            if (dist >= 0x8000) {
                dist = 0x8000;
            }
            if (!m_quake->IsBusy()) {
                m_quake->StartShakeX(dist);
                m_shakes++;
                unk_14->PlaySe(0x12C);
            }
        } else if (m_quake->IsBusy()) {
            m_quake->StopShakeX();
            unk_14->StopSe(0x12C);
        }
        m_last.x = x;
        m_last.y = y;
    }
    if (touch->unk_06 != 0 && m_quake->IsBusy()) {
        m_quake->StopShakeX();
        unk_14->StopSe(0x12C);
        m_shakes = 0;
        m_touching = FALSE;
    }
    if (m_shakes == 5) {
        BOOL hit = FALSE;
        int sound = 0;
        u8 *level = &MAIN_BSS_020B26A0.m_stylerLevel;
        for (int i = 0; i < 8; i++) {
            if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable() && !enemies[i]->ov1_02126424()) {
                u16 power = unk_10->GetAssistPower(vfunc_10(), *level, 0);
                fx32 rate = GetAssistTypeRate(vfunc_10(), enemies[i]->unk_184->unk_18->unk_03);
                enemies[i]->TakeDamage((u16)(FX32_MUL(rate, power << FX32_SHIFT) >> FX32_SHIFT), TRUE);
                enemies[i]->SetStatus(1, GetAssistEffectTime(vfunc_10(), 0));
                if (rate == 0x1000) {
                    enemies[i]->unk_1A8->Show(0);
                } else if (rate > 0x1000) {
                    sound = 1;
                    enemies[i]->unk_1A8->Show(1);
                } else if (rate < 0x1000) {
                    if (sound == 0) {
                        sound = 1;
                    }
                    enemies[i]->unk_1A8->Show(2);
                }
                hit = TRUE;
            }
        }
        if (hit) {
            switch (sound) {
            case 0:
                unk_14->PlaySe(0x12D);
                break;
            case 1:
                unk_14->PlaySe(0x14A);
                break;
            case 2:
                unk_14->PlaySe(0x14B);
                break;
            }
        }
        m_shakes = 0;
    }
    return 1;
}

int CBattleAssistGround::vfunc_10()
{
    return 8;
}

void CBattleAssistGround::vfunc_0C()
{
    if (m_quake->IsBusy()) {
        m_quake->StopShakeX();
        m_shakes = 0;
    }
    m_touching = FALSE;
    unk_14->StopSe(0x12C);
    unk_14->StopSe(0x12D);
    unk_14->StopSe(0x14A);
    unk_14->StopSe(0x14B);
}
