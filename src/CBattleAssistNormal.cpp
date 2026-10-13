#include "UnkClass_020B26A0.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleDisk.hpp"
#include "battle/UnkClass_0212EEB4.hpp"

CBattleAssistNormal::CBattleAssistNormal(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
}

CBattleAssistNormal::~CBattleAssistNormal()
{
}

int CBattleAssistNormal::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    disk->unk_19E = unk_10->ov1_0212F32C(vfunc_10(), MAIN_BSS_020B26A0.unk_87DB, 0);
    if (unk_04 == 0) {
        return 0;
    }
    unk_04--;
    return 1;
}

int CBattleAssistNormal::vfunc_10()
{
    return 0;
}

void CBattleAssistNormal::vfunc_0C()
{
}
