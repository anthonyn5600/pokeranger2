#include "AudioEngine.hpp"
#include "SaveData.hpp"
#include "battle/BattleParamTable.hpp"
#include "battle/BattlePokemonParam.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleAttackEffect.hpp"
#include "battle/CBattleDisk.hpp"
#include "battle/CBattleEnemy.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "battle/StylerLine.hpp"

extern "C" u16 GetAssistEffectTime(int assistType, int idx);

CBattleAssistFire::CBattleAssistFire(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, BattleParamTable *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
}

CBattleAssistFire::~CBattleAssistFire()
{
}

int CBattleAssistFire::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    disk->unk_19E = unk_10->GetAssistPower(vfunc_10(), MAIN_BSS_020B26A0.m_stylerLevel, 0);
    for (u8 i = 0; i < 0x20; i++) {
        if (unk_08[i]->HasData() && !unk_08[i]->IsAnimActive()) {
            unk_08[i]->Terminate();
        }
    }
    BOOL hit = FALSE;
    if (disk->IsActive() && disk->IsLoopClosed()) {
        for (u8 i = 0; i < 8; i++) {
            if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable()) {
                Point2D pos;
                Circle area;
                Circle circle = enemies[i]->m_sphere.m_circle;
                area.pos.x = circle.pos.x;
                area.pos.y = circle.pos.y;
                area.r = circle.r;
                Point2D center = area.pos;
                if (disk->unk_1B8->IsInsideLoop(center.x, center.y)) {
                    CBattleAttackEffect *effect = GetFreeEffect();
                    if (effect == NULL) {
                        break;
                    }
                    effect->Start(unk_0C[0]);
                    effect->PlayAction(0x20, 0);
                    effect->SetAnimSequence(7, enemies[i]->unk_184->unk_1C->unk_0E);
                    CBattleEnemy *enemy = enemies[i];
                    pos = enemy->m_motion.m_pos;
                    pos += enemy->unk_484;
                    pos.y -= enemy->m_bobHeight + (enemy->m_height + enemy->m_jumpHeight);
                    effect->m_motion.SetPos(pos);
                    enemies[i]->SetStatus(2, GetAssistEffectTime(vfunc_10(), 0));
                    hit = TRUE;
                }
            }
        }
        if (hit) {
            unk_14->PlaySe(0x12E);
        }
    }
    if (unk_04 == 0) {
        return 0;
    }
    unk_04--;
    return 1;
}

int CBattleAssistFire::vfunc_10()
{
    return 1;
}

void CBattleAssistFire::vfunc_0C()
{
    unk_14->StopSe(0x12E);
}
