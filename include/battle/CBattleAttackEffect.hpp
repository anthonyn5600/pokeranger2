#ifndef POKERANGER2_BATTLE_CBATTLEATTACKEFFECT_HPP
#define POKERANGER2_BATTLE_CBATTLEATTACKEFFECT_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "UnkStruct_02044464.hpp"
#include "battle/CBattleAttackEffectData.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveLINE.hpp"
#include "primitive/CPrimitiveSPHERE.hpp"
#include "sub_02006000.hpp"

class CBattleEnemy;

// Defined in ov1
class CBattleAttackEffect : public CActor {
public:
    CBattleAttackEffect(u8 arg0);
    virtual ~CBattleAttackEffect();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);

    void ov1_02126F90();
    void ov1_021270FC(CBattleAttackEffectData *data);
    void ov1_02127280();
    void ov1_0212728C(CBattleEnemy *target, int mode);
    void ov1_021272AC();
    void ov1_02127300();
    void ov1_02127370(BOOL arg0);
    void ov1_02127388(BOOL arg0);
    void ov1_021273A0(u8 anim, u16 seq);
    void ov1_02127408(u8 anim);
    void ov1_02127454(int action, u32 sub);
    BOOL ov1_0212747C();
    int ov1_02127484(u16 dir);

    inline BOOL IsUnk200Clear()
    {
        return (m_flags & 0x200) == 0;
    }

    inline BOOL IsUnk100Clear()
    {
        return (m_flags & 0x100) == 0;
    }

public:
    CBattleAttackEffectData *unk_184;
    u16 unk_188;
    u16 unk_18A;
    u8 unk_18C;
    u8 unk_18D;
    u16 unk_18E;
    CBattleEnemy *unk_190;
    int unk_194;
    NNSG2dCellAnimation m_cellAnim;
    u8 m_index;
    u32 m_stack[0x80];
    UnkStruct_02044464 m_vm;
    CPrimitiveSPHERE m_sphere;
    u16 unk_43C;
    CPrimitiveLINE m_line;
};

STATIC_SIZE_ASSERT(CBattleAttackEffect, 0x468);

#endif // POKERANGER2_BATTLE_CBATTLEATTACKEFFECT_HPP
