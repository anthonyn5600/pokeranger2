#include "UnkClass_02034478.hpp"
#include "UnkClass_020B26A0.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleAttackEffect.hpp"
#include "battle/CBattleDisk.hpp"
#include "battle/CBattleEnemy.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "battle/UnkClass_0212306C.hpp"
#include "battle/UnkClass_0212EEB4.hpp"
#include "battle/UnkStruct_0212DFEC.hpp"

extern "C" u16 ov1_0212EE98(int assistType, int idx);

CBattleAssistFire::CBattleAssistFire(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
}

CBattleAssistFire::~CBattleAssistFire()
{
}

int CBattleAssistFire::vfunc_08(CTouchPanel *touch, CBattleDisk *disk, CBattleEnemy **enemies)
{
    disk->unk_19E = unk_10->ov1_0212F32C(vfunc_10(), MAIN_BSS_020B26A0.unk_87DB, 0);
    for (u8 i = 0; i < 0x20; i++) {
        if (unk_08[i]->HasData() && !unk_08[i]->ov1_0212747C()) {
            unk_08[i]->ov1_02127300();
        }
    }
    BOOL hit = FALSE;
    if (disk->ov1_0212C5C0() && disk->ov1_0212C4CC()) {
        for (u8 i = 0; i < 8; i++) {
            if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable()) {
                Point2D pos;
                Circle area;
                Circle circle = enemies[i]->m_sphere.m_circle;
                area.pos.x = circle.pos.x;
                area.pos.y = circle.pos.y;
                area.r = circle.r;
                Point2D center = area.pos;
                if (disk->unk_1B8->ov1_02124650(center.x, center.y)) {
                    CBattleAttackEffect *effect = ov1_0212EE3C();
                    if (effect == NULL) {
                        break;
                    }
                    effect->ov1_021270FC(unk_0C[0]);
                    effect->ov1_02127454(0x20, 0);
                    effect->ov1_021273A0(7, enemies[i]->unk_184->unk_1C->unk_0E);
                    CBattleEnemy *enemy = enemies[i];
                    pos = enemy->m_motion.m_pos;
                    pos += enemy->unk_484;
                    pos.y -= enemy->m_bobHeight + (enemy->unk_8C + enemy->m_jumpHeight);
                    effect->m_motion.sub_02011D3C(pos);
                    enemies[i]->ov1_021263A4(2, ov1_0212EE98(vfunc_10(), 0));
                    hit = TRUE;
                }
            }
        }
        if (hit) {
            unk_14->sub_02034C44(0x12E);
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
    unk_14->sub_02034C5C(0x12E);
}
