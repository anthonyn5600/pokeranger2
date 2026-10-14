#include "AudioEngine.hpp"
#include "CPlayerHPGauge.hpp"
#include "SaveData.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleDisk.hpp"

CBattleAssistRecover::CBattleAssistRecover(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, BattleParamTable *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
}

CBattleAssistRecover::~CBattleAssistRecover()
{
}

int CBattleAssistRecover::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    if (!(m_flags & 1)) {
        u8 hp = unk_04 + disk->unk_19C;
        u8 max = MAIN_BSS_020B26A0.m_maxEnergy;
        if (hp >= max) {
            hp = max;
        }
        disk->unk_19C = hp;
        unk_1C->SetCurrentHP(hp);
        unk_1C->StartHeal(ov1_02134354(unk_04));
        unk_14->PlaySe(0x143);
        m_flags |= 1;
    } else if (!unk_1C->IsHealing()) {
        unk_14->StopSe(0x143);
        return 0;
    }
    return 1;
}

void CBattleAssistRecover::vfunc_0C()
{
}

u8 CBattleAssistRecover::ov1_02134354(u8 amount)
{
    if (amount <= 5) {
        return 0;
    }
    if (amount <= 10) {
        return 1;
    }
    if (amount <= 20) {
        return 2;
    }
    if (amount <= 30) {
        return 3;
    }
    return 4;
}

int CBattleAssistRecover::vfunc_10()
{
    return 17;
}
