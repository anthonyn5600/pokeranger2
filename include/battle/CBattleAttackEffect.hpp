#ifndef POKERANGER2_BATTLE_CBATTLEATTACKEFFECT_HPP
#define POKERANGER2_BATTLE_CBATTLEATTACKEFFECT_HPP

#include <nitro.h>

#include "CActor.hpp"
#include "battle/CBattleAttackEffectData.hpp"
#include "common.hpp"
#include "sub_02006000.hpp"

// Defined in ov1
class CBattleAttackEffect : public CActor {
public:
    CBattleAttackEffect(u8 arg0);
    virtual ~CBattleAttackEffect();
    virtual void vfunc_08();
    virtual void vfunc_0C(Camera2D *camera);
    virtual void vfunc_10();

    void ov1_02126F90();
    void ov1_021272AC();
    void ov1_02127300();

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
    u8 unk_188[0x6];
    u16 unk_18E;
    u8 unk_190[0x2A0];
    Circle unk_430;
    u8 unk_43C[0x2C];
};

STATIC_SIZE_ASSERT(CBattleAttackEffect, 0x468);

#endif // POKERANGER2_BATTLE_CBATTLEATTACKEFFECT_HPP
