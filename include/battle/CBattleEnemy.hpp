#ifndef POKERANGER2_BATTLE_CBATTLEENEMY_HPP
#define POKERANGER2_BATTLE_CBATTLEENEMY_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "common.hpp"
#include "sub_02006000.hpp"

class CBattleEnemyGauge;
class UnkClass_02136AD4;
class UnkClass_02129DD4;
class UnkClass_021299CC;
class UnkClass_02127B48;
class UnkClass_0212770C;
class UnkClass_02128414;
class UnkClass_02128860;
class UnkClass_021291BC;
class UnkClass_021296C8;

// Defined in ov1
class CBattleEnemy : public CActor {
public:
    CBattleEnemy(u8 index, CBattleEnemyData *data);
    virtual ~CBattleEnemy();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10();

    void ov1_02126224();
    void ov1_02126310(int arg0, int arg1);
    void ov1_021263A4(int arg0, int arg1);
    void ov1_0212580C();
    int ov1_02125E00(Camera2D *camera, int z);
    void ov1_0212677C(u16 arg0);
    int ov1_021267E8();

    inline BOOL IsAlive()
    {
        return unk_188 != 0;
    }

    inline BOOL IsTargetable()
    {
        return (m_flags & 0x200) == 0;
    }

    inline Rectangle GetShadowRect()
    {
        Rectangle rect = unk_184->unk_2C;
        rect.pos.x += m_motion.m_pos.x;
        rect.pos.y += m_motion.m_pos.y;
        rect.pos.x += unk_484;
        return rect;
    }

    inline BOOL IsUnk800Clear()
    {
        return (m_flags & 0x800) == 0;
    }

    inline BOOL IsUnk400Clear()
    {
        return (m_flags & 0x400) == 0;
    }

    inline BOOL IsUnk2000()
    {
        return (m_flags & 0x2000) != 0;
    }
    void ov1_02126764(int arg0);

public:
    CBattleEnemyData *unk_184;
    u16 unk_188;
    u8 unk_18A[0xE];
    UnkClass_02129DD4 *unk_198;
    UnkClass_021299CC *unk_19C;
    UnkClass_02127B48 *unk_1A0;
    UnkClass_0212770C *unk_1A4;
    UnkClass_02128414 *unk_1A8;
    UnkClass_02128860 *unk_1AC;
    UnkClass_021291BC *unk_1B0;
    UnkClass_021296C8 *unk_1B4;
    CBattleEnemyGauge *unk_1B8;
    UnkClass_02136AD4 *unk_1BC;
    u8 unk_1C0[0x2C4];
    fx32 unk_484;
    u8 unk_488[0x270];
    Circle unk_6F8;
};

STATIC_SIZE_ASSERT(CBattleEnemy, 0x704);

#endif // POKERANGER2_BATTLE_CBATTLEENEMY_HPP
