#include "UnkClass_020B26A0.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleDisk.hpp"
#include "battle/UnkClass_0212EEB4.hpp"

CBattleAssistGrapple::CBattleAssistGrapple(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
}

CBattleAssistGrapple::~CBattleAssistGrapple()
{
}

int CBattleAssistGrapple::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    disk->unk_19E = unk_10->ov1_0212F32C(vfunc_10(), MAIN_BSS_020B26A0.unk_87DB, 0);
    if (unk_04 == 0) {
        return 0;
    }
    unk_04--;
    return 1;
}

int CBattleAssistGrapple::vfunc_10()
{
    return 6;
}

void CBattleAssistGrapple::vfunc_0C()
{
}
