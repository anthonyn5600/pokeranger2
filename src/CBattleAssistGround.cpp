#include "CTouchPanel.hpp"
#include "UnkClass_0200D3F8.hpp"
#include "UnkClass_02034478.hpp"
#include "UnkClass_020B26A0.hpp"
#include "battle/CBattleAssist.hpp"
#include "battle/CBattleEnemy.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "battle/UnkClass_02128414.hpp"
#include "battle/UnkClass_0212EEB4.hpp"
#include "fx_utils.hpp"
#include "sub_02007254.hpp"

extern "C" fx32 ov1_0212EE80(int assistType, int type);
extern "C" u16 ov1_0212EE98(int assistType, int idx);

CBattleAssistGround::CBattleAssistGround(CBattleAttackEffect **effects, CBattleAttackEffectData **effectData, UnkClass_0212EEB4 *params, u16 arg3)
    : CBattleAssist(effects, effectData, params, arg3)
{
}

CBattleAssistGround::~CBattleAssistGround()
{
    m_quake->sub_0200D994();
}

void CBattleAssistGround::ov1_0213219C(UnkClass_0200D3F8 *quake)
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
        fx32 dist = sub_02007254(x - m_last.x, y - m_last.y);
        if (dist > 0x8000) {
            if (dist >= 0x8000) {
                dist = 0x8000;
            }
            if (!m_quake->sub_0200E098()) {
                m_quake->sub_0200D924(dist);
                m_shakes++;
                unk_14->sub_02034C44(0x12C);
            }
        } else if (m_quake->sub_0200E098()) {
            m_quake->sub_0200D994();
            unk_14->sub_02034C5C(0x12C);
        }
        m_last.x = x;
        m_last.y = y;
    }
    if (touch->unk_06 != 0 && m_quake->sub_0200E098()) {
        m_quake->sub_0200D994();
        unk_14->sub_02034C5C(0x12C);
        m_shakes = 0;
        m_touching = FALSE;
    }
    if (m_shakes == 5) {
        BOOL hit = FALSE;
        int sound = 0;
        u8 *level = &MAIN_BSS_020B26A0.unk_87DB;
        for (int i = 0; i < 8; i++) {
            if (enemies[i] != NULL && enemies[i]->IsAlive() && enemies[i]->IsTargetable() && !enemies[i]->ov1_02126424()) {
                u16 power = unk_10->ov1_0212F32C(vfunc_10(), *level, 0);
                fx32 rate = ov1_0212EE80(vfunc_10(), enemies[i]->unk_184->unk_18->unk_03);
                enemies[i]->ov1_02126310((u16)(FX32_MUL(rate, power << FX32_SHIFT) >> FX32_SHIFT), TRUE);
                enemies[i]->ov1_021263A4(1, ov1_0212EE98(vfunc_10(), 0));
                if (rate == 0x1000) {
                    enemies[i]->unk_1A8->ov1_02128598(0);
                } else if (rate > 0x1000) {
                    sound = 1;
                    enemies[i]->unk_1A8->ov1_02128598(1);
                } else if (rate < 0x1000) {
                    if (sound == 0) {
                        sound = 1;
                    }
                    enemies[i]->unk_1A8->ov1_02128598(2);
                }
                hit = TRUE;
            }
        }
        if (hit) {
            switch (sound) {
            case 0:
                unk_14->sub_02034C44(0x12D);
                break;
            case 1:
                unk_14->sub_02034C44(0x14A);
                break;
            case 2:
                unk_14->sub_02034C44(0x14B);
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
    if (m_quake->sub_0200E098()) {
        m_quake->sub_0200D994();
        m_shakes = 0;
    }
    m_touching = FALSE;
    unk_14->sub_02034C5C(0x12C);
    unk_14->sub_02034C5C(0x12D);
    unk_14->sub_02034C5C(0x14A);
    unk_14->sub_02034C5C(0x14B);
}
