#ifndef POKERANGER2_CBATTLERESULTPARAMETER_HPP
#define POKERANGER2_CBATTLERESULTPARAMETER_HPP

#include <nitro.h>

#include "common.hpp"

// Field names are offsets in CBattleResultParameter (the struct sits after its vptr)
struct strBattleResultParameter {
    u8 unk_04;
    u8 unk_05[0x3];
    u32 unk_08;
    u8 unk_0C;
    u8 unk_0D[0x3];
    s32 unk_10;
    u8 unk_14;
    u8 unk_15[0x3];
    u32 unk_18[8];
    u32 unk_38[8];
    u8 unk_58;
    u8 unk_59;
    u16 unk_5A[8];
    u8 unk_6A;
    u8 unk_6B;
    u8 unk_6C;
    u8 unk_6D[8];
    u8 unk_75[0x3];
    u32 unk_78;
    u32 unk_7C;
    s32 unk_80;
};

STATIC_SIZE_ASSERT(strBattleResultParameter, 0x80);

// Non-public base (RTTI flags 0)
class CBattleResultParameter : strBattleResultParameter {
public:
    CBattleResultParameter();
    virtual ~CBattleResultParameter();

    using strBattleResultParameter::unk_04;
    using strBattleResultParameter::unk_08;
    using strBattleResultParameter::unk_0C;
    using strBattleResultParameter::unk_10;
    using strBattleResultParameter::unk_14;
    using strBattleResultParameter::unk_18;
    using strBattleResultParameter::unk_38;
    using strBattleResultParameter::unk_58;
    using strBattleResultParameter::unk_59;
    using strBattleResultParameter::unk_5A;
    using strBattleResultParameter::unk_6A;
    using strBattleResultParameter::unk_6B;
    using strBattleResultParameter::unk_6C;
    using strBattleResultParameter::unk_6D;
    using strBattleResultParameter::unk_78;
    using strBattleResultParameter::unk_7C;
    using strBattleResultParameter::unk_80;
};

STATIC_SIZE_ASSERT(CBattleResultParameter, 0x84);

extern "C" {
void BattleResultParameter_Reset(CBattleResultParameter *obj);
}

#endif // POKERANGER2_CBATTLERESULTPARAMETER_HPP
