#include "AudioEngine.hpp"
#include "CTouchPanel.hpp"
#include "CameraController.hpp"
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

static const u16 sChargeTimes[] = { 30, 60, 0xFFFF };

CBattleAssistDragon::CBattleAssistDragon(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, BattleParamTable *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
    m_state = 0;
}

CBattleAssistDragon::~CBattleAssistDragon()
{
    unk_44->StopShake();
}

int CBattleAssistDragon::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (unk_04 == 0) {
        return 0;
    }
    unk_04--;
    switch (m_state) {
    case 0:
        UpdateWait(touch);
        break;
    case 1:
        UpdateCharge(touch);
        break;
    case 2:
        UpdateAttack(touch, disk, enemies);
        break;
    case 3:
        UpdateBurst();
        break;
    }
    for (u8 i = 0; i < 5; i++) {
        if (m_bursts[i] != NULL && !m_bursts[i]->IsAnimActive()) {
            m_bursts[i]->Terminate();
            m_bursts[i] = NULL;
        }
    }
    return 1;
}

void CBattleAssistDragon::UpdateWait(CTouchPanel *touch)
{
    if (touch->unk_04 == 0) {
        return;
    }
    m_chargeTimer = 0;
    m_frame = 0;
    m_burstFrame = 0;
    m_level = 0;
    m_pos.x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
    m_pos.y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
    m_touchArea.pos.x = m_pos.x;
    m_touchArea.pos.y = m_pos.y;
    m_touchArea.r = 0xC000;
    m_charge = GetFreeEffect();
    m_charge->Start(unk_0C[0]);
    m_charge->PlayAction(0x20, 0);
    m_charge->m_motion.SetPos(m_pos);
    unk_14->PlaySe(0x13D);
    m_state = 1;
}

void CBattleAssistDragon::UpdateCharge(CTouchPanel *touch)
{
    Point2D pos;
    pos.x = (touch->unk_0A.x - 0x80) << FX32_SHIFT;
    pos.y = (touch->unk_0A.y - 0x60) << FX32_SHIFT;
    if (touch->unk_06 != 0 || !PointInCircle(pos, m_touchArea)) {
        m_state = 2;
        unk_14->StopSe(0x13D);
        return;
    }
    if (m_level >= 3) {
        return;
    }
    m_chargeTimer++;
    if (m_chargeTimer < sChargeTimes[m_level]) {
        return;
    }
    m_level++;
    m_charge->SetAnimSequence(7, m_level);
}

void CBattleAssistDragon::UpdateAttack(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    switch (m_frame) {
    case 1:
        unk_44->StartShake(0x1000);
        unk_14->PlaySe(0x13E);
        break;
    case 0x3C: {
        m_dragon = GetFreeEffect();
        m_dragon->Start(unk_0C[0]);
        m_dragon->PlayAction(0x20, 1);
        Point2D start = m_pos;
        if (m_pos.x >= 0) {
            start.x -= 0x80000;
            m_dragon->SetDir(0x2000);
        } else {
            start.x += 0x80000;
            m_dragon->SetDir(0x6000);
        }
        m_dragon->m_motion.SetPos(start);
        m_dragon->m_motion.MoveLinear(m_pos, 0x3C);
        m_dragon->m_height = 0xC0000;
        m_dragon->MoveHeightTo(0, 0x3C);
        break;
    }
    case 0x78:
        m_dragon->Terminate();
        unk_14->PlaySe(0x13F);
        m_charge->Terminate();
        m_charge = NULL;
        m_hitArea.pos.x = m_pos.x;
        m_hitArea.pos.y = m_pos.y;
        m_hitArea.r = 0x18000;
        for (u8 i = 0; i < 8; i++) {
            if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable()
                && CircleHitCircle(m_hitArea, enemies[i]->m_sphere.m_circle, NULL)) {
                u16 power = unk_10->GetAssistPower(14, MAIN_BSS_020B26A0.m_stylerLevel, m_level);
                fx32 rate = GetAssistTypeRate(vfunc_10(), enemies[i]->unk_184->unk_18->unk_03);
                enemies[i]->TakeDamage((u16)(FX32_MUL(rate, power << FX32_SHIFT) >> FX32_SHIFT), TRUE);
                enemies[i]->SetStatus(2, GetAssistEffectTime(vfunc_10(), m_level));
                if (rate == 0x1000) {
                    enemies[i]->unk_1A8->Show(0);
                } else if (rate > 0x1000) {
                    enemies[i]->unk_1A8->Show(1);
                } else if (rate < 0x1000) {
                    enemies[i]->unk_1A8->Show(2);
                }
            }
        }
        unk_44->SetShakeAmplitude(0x8000);
        m_state = 3;
        break;
    }
    m_frame++;
}

int CBattleAssistDragon::vfunc_10()
{
    return 14;
}

void CBattleAssistDragon::UpdateBurst()
{
    if (SpawnBursts(m_pos.x, m_pos.y, m_level, m_burstFrame) == TRUE) {
        unk_44->StopShake();
        m_state = 0;
    }
    m_burstFrame++;
}

void CBattleAssistDragon::vfunc_0C()
{
    if (m_state == 1) {
        m_charge->Terminate();
        m_charge = NULL;
        m_state = 0;
    }
    unk_14->StopSe(0x13D);
    unk_14->StopSe(0x13E);
    unk_14->StopSe(0x13F);
}

BOOL CBattleAssistDragon::SpawnBursts(fx32 x, fx32 y, u8 level, u8 frame)
{
    BOOL done = FALSE;
    switch (level) {
    case 0:
        switch (frame) {
        case 1:
            m_bursts[0] = SpawnBurst(x, y);
            break;
        case 8:
            done = TRUE;
            break;
        }
        break;
    case 1:
        switch (frame) {
        case 1:
            m_bursts[0] = SpawnBurst(x, y);
            break;
        case 8:
            m_bursts[1] = SpawnBurst(x - 0x18000, y + 0xC000);
            break;
        case 0x10:
            m_bursts[2] = SpawnBurst(x + 0x10000, y - 0x12000);
            done = TRUE;
            break;
        }
        break;
    case 2:
        switch (frame) {
        case 1:
            m_bursts[0] = SpawnBurst(x, y);
            break;
        case 8:
            m_bursts[1] = SpawnBurst(x - 0x18000, y + 0xC000);
            break;
        case 0x10:
            m_bursts[2] = SpawnBurst(x + 0x10000, y - 0x12000);
            break;
        case 0x18:
            m_bursts[3] = SpawnBurst(x - 0xC000, y - 0x10000);
            break;
        case 0x20:
            m_bursts[4] = SpawnBurst(x + 0x1C000, y + 0x16000);
            done = TRUE;
            break;
        }
        break;
    }
    return done;
}

CBattleAttackEffect *CBattleAssistDragon::SpawnBurst(fx32 x, fx32 y)
{
    CBattleAttackEffect *effect = GetFreeEffect();
    if (effect != NULL) {
        effect->Start(unk_0C[0]);
        effect->PlayAction(0x20, 2);
        effect->m_motion.SetX(x);
        effect->m_motion.SetY(y);
    }
    return effect;
}
