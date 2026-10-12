#ifndef POKERANGER2_BATTLE_CBATTLEATTACKEFFECTDATA_HPP
#define POKERANGER2_BATTLE_CBATTLEATTACKEFFECTDATA_HPP

#include <nitro.h>

#include "CActorData.hpp"
#include "battle/UnkStruct_0212E008.hpp"
#include "common.hpp"

// Defined in ov1
class CBattleAttackEffectData : public CActorData {
public:
    CBattleAttackEffectData(u16 id, UnkStruct_0212E008 *entry, u32 arg2);
    virtual ~CBattleAttackEffectData();

public:
    UnkStruct_0212E008 *unk_18;
    u8 unk_1C[0xF4];
};

STATIC_SIZE_ASSERT(CBattleAttackEffectData, 0x110);

#endif // POKERANGER2_BATTLE_CBATTLEATTACKEFFECTDATA_HPP
