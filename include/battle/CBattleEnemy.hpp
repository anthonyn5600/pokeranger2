#ifndef POKERANGER2_BATTLE_CBATTLEENEMY_HPP
#define POKERANGER2_BATTLE_CBATTLEENEMY_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "UnkClass_02007770.hpp"
#include "UnkStruct_02044464.hpp"
#include "battle/CBattleEnemyData.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveLINE.hpp"
#include "primitive/CPrimitiveSPHERE.hpp"
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
    virtual void vfunc_10(Camera2D *camera);

    void ov1_0212580C();
    void ov1_0212586C();
    void ov1_02125A80();
    void ov1_02125B74();
    void ov1_02125C94();
    int ov1_02125E00(Camera2D *camera, int z);
    void ov1_02126224();
    void ov1_021262AC();
    void ov1_02126310(int damage, BOOL keepAlive);
    void ov1_021263A4(int state, int duration);
    u8 ov1_02126424();
    void ov1_02126434();
    void ov1_0212656C(u8 count);
    void ov1_0212671C(BOOL targetable);
    void ov1_02126734(BOOL invincible);
    void ov1_0212674C(BOOL arg0);
    void ov1_02126764(BOOL arg0);
    void ov1_0212677C(u16 duration);
    BOOL ov1_021267E8();

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
        rect.pos.x += unk_484.x;
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

public:
    CBattleEnemyData *unk_184;
    u16 unk_188;
    int unk_18C;
    u16 unk_190;
    u16 unk_192;
    u16 unk_194;
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
    UnkClass_02007770 m_palettes[0x1D];
    NNSGfdTexKey m_texKey;
    u16 unk_47C;
    u8 unk_47E;
    u16 unk_480;
    Point2D unk_484;
    u8 m_index;
    u32 m_stack[0x80];
    UnkStruct_02044464 m_vm;
    u16 unk_6B4;
    CPrimitiveLINE m_line;
    CPrimitiveSPHERE m_sphere;
};

STATIC_SIZE_ASSERT(CBattleEnemy, 0x704);

#endif // POKERANGER2_BATTLE_CBATTLEENEMY_HPP
