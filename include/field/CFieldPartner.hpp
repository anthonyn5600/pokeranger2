#ifndef POKERANGER2_FIELD_CFIELDPARTNER_HPP
#define POKERANGER2_FIELD_CFIELDPARTNER_HPP

#include <nitro.h>

#include "UnkClass_02158F38.hpp"
#include "common.hpp"
#include "field/CFieldActor.hpp"

// Defined in ov0
class CFieldPartner : public CFieldActor {
public:
    inline BOOL IsKind0()
    {
        return unk_1FC == 0;
    }

public:
    u8 unk_E0[0xC];
    UnkClass_02158F38 unk_EC;
    u8 unk_F0[0x10C];
    u32 unk_1FC;
    u32 unk_200;
    u8 unk_204[0x64];
    u32 unk_268;
    u8 unk_26C[0x8];
    UnkStruct_0211EA94 *unk_274;
};

extern "C" {
void ov0_0213E158(CFieldActor *actor, void *arg1);
}

#endif // POKERANGER2_FIELD_CFIELDPARTNER_HPP
