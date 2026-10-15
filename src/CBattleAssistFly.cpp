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

static const fx32 sBirdScales[] = { 0x28, 0x400, 0x800, 0xC00, 0x1000, 0x1000 };

// HasData() read as an integer: IRO keeps this second check, the backend merges the loads
static inline BOOL IsLoaded(CBattleAttackEffect *effect)
{
    return PTR_CAST(u32, effect->m_data) != 0;
}

CBattleAssistFly::CBattleAssistFly(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, BattleParamTable *params, u16 arg3)
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
            unk_08[i]->m_motion.MoveInDirection(unk_08[i]->m_motion.m_angle + 0x200, unk_08[i]->m_motion.m_speed + 0x333);
        }
    }
    if (m_bird != NULL && m_bird->unk_108.value == 0) {
        m_bird->Terminate();
        m_bird = NULL;
    }
    u8 *level = &MAIN_BSS_020B26A0.m_stylerLevel;
    for (u8 j = 0; j < 8; j++) {
        if (enemies[j] != NULL && enemies[j]->IsAlive() && enemies[j]->IsTargetable()) {
            Circle area;
            Circle circle = enemies[j]->m_sphere.m_circle;
            area = circle;
            for (u8 i = 0; i < 0x20; i++) {
                CBattleAttackEffect *effect = unk_08[i];
                if (effect->HasData() && (m_bird == NULL || effect != m_bird) && IsLoaded(effect)
                    && CircleHitCircle(area, effect->m_sphere.m_circle, NULL)) {
                    u16 power = unk_10->GetAssistPower(vfunc_10(), *level, 0);
                    fx32 rate = GetAssistTypeRate(vfunc_10(), enemies[j]->unk_184->unk_18->unk_03);
                    enemies[j]->TakeDamage((u16)(FX32_MUL(rate, power << FX32_SHIFT) >> FX32_SHIFT), TRUE);
                    if (rate == 0x1000) {
                        unk_14->PlaySe(0x137);
                        enemies[j]->unk_1A8->Show(0);
                    } else if (rate > 0x1000) {
                        unk_14->PlaySe(0x14C);
                        enemies[j]->unk_1A8->Show(1);
                    } else if (rate < 0x1000) {
                        unk_14->PlaySe(0x14D);
                        enemies[j]->unk_1A8->Show(2);
                    }
                    unk_08[i]->Terminate();
                }
            }
        }
    }
    switch (m_state) {
    case 0:
        UpdateWait(touch, disk, enemies);
        break;
    case 1:
        UpdateHold(touch, disk, enemies);
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

void CBattleAssistFly::UpdateWait(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (touch->unk_04 != 0) {
        m_state = 1;
    }
}

void CBattleAssistFly::UpdateHold(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (touch->unk_06 != 0) {
        if (m_bird != NULL) {
            m_bird->FadeAlpha(0x18, 0);
            m_bird->ScaleTo(0x18, 0x1800, 0x1800);
            unk_14->StopSe(0x135);
        }
        m_state = 0;
        return;
    }
    if (!disk->IsLoopClosed()) {
        return;
    }
    if (m_bird == NULL) {
        Rectangle rect = disk->unk_1B8->m_rect.m_rectangle;
        SpawnBird(rect.pos.x, rect.pos.y);
        unk_14->PlaySe(0x135);
        return;
    }
    if (disk->unk_1B8->IsInsideLoop(m_bird->m_motion.m_pos.x, m_bird->m_motion.m_pos.y)) {
        if (m_level >= 5) {
            for (u8 i = 0; i < 4; i++) {
                SpawnProjectile(m_bird->m_motion.m_pos.x, m_bird->m_motion.m_pos.y, m_angle);
                m_angle += 0x4000;
            }
            m_angle += 0x1000;
            unk_14->PlaySe(0x136);
            return;
        }
        m_level++;
        m_bird->ScaleTo(0x20, sBirdScales[m_level], sBirdScales[m_level]);
    } else {
        Rectangle rect = disk->unk_1B8->m_rect.m_rectangle;
        SpawnBird(rect.pos.x, rect.pos.y);
    }
}

void CBattleAssistFly::vfunc_0C()
{
    if (m_bird != NULL) {
        m_bird->FadeAlpha(0x3C, 0);
    }
    m_state = 0;
    unk_14->StopSe(0x135);
    unk_14->StopSe(0x136);
    unk_14->StopSe(0x137);
    unk_14->StopSe(0x14C);
    unk_14->StopSe(0x14D);
}

void CBattleAssistFly::SpawnBird(fx32 x, fx32 y)
{
    if (m_bird != NULL) {
        m_bird->Terminate();
    }
    m_level = 1;
    m_bird = GetFreeEffect();
    m_bird->Start(unk_0C[0]);
    m_bird->PlayAction(0x20, 0);
    CBattleAttackEffect *bird = m_bird;
    bird->m_motion.SetX(x);
    bird->m_motion.SetY(y);
    m_bird->ScaleTo(0, sBirdScales[m_level], sBirdScales[m_level]);
}

void CBattleAssistFly::SpawnProjectile(fx32 x, fx32 y, u16 angle)
{
    CBattleAttackEffect *effect = GetFreeEffect();
    if (effect == NULL) {
        return;
    }
    effect->Start(unk_0C[0]);
    effect->SetAnimSequence(7, 1);
    effect->m_motion.SetX(x);
    effect->m_motion.SetY(y);
    effect->m_motion.MoveInDirection(angle, 0x4000);
}
