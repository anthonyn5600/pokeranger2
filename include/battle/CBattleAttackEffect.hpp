#ifndef POKERANGER2_BATTLE_CBATTLEATTACKEFFECT_HPP
#define POKERANGER2_BATTLE_CBATTLEATTACKEFFECT_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "Collision.hpp"
#include "ScriptVM.hpp"
#include "battle/CBattleAttackEffectData.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveLINE.hpp"
#include "primitive/CPrimitiveSPHERE.hpp"

class CBattleEnemy;

// Defined in ov1
class CBattleAttackEffect : public CActor {
public:
    CBattleAttackEffect(u8 arg0);
    virtual ~CBattleAttackEffect();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10(Camera2D *camera);

    void RunScript();
    void Start(CBattleAttackEffectData *data);
    void Clear();
    void AttachTo(CBattleEnemy *target, int mode);
    void StartVanish();
    void Terminate();
    void SetShadowVisible(BOOL arg0);
    void SetCollisionEnabled(BOOL arg0);
    void SetAnimSequence(u8 anim, u16 seq);
    void PlayAnim(u8 anim);
    void PlayAction(int action, u32 sub);
    BOOL IsAnimActive();
    int GetDirAnimSeq(u16 dir);

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
    ScriptVM m_vm;
    CPrimitiveSPHERE m_sphere;
    u16 unk_43C;
    CPrimitiveLINE m_line;
};

STATIC_SIZE_ASSERT(CBattleAttackEffect, 0x468);

#endif // POKERANGER2_BATTLE_CBATTLEATTACKEFFECT_HPP
