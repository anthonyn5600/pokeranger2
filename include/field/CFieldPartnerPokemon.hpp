#ifndef POKERANGER2_FIELD_CFIELDPARTNERPOKEMON_HPP
#define POKERANGER2_FIELD_CFIELDPARTNERPOKEMON_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldPartner.hpp"

// FieldPartnerPokemon.cpp (ov0)
class CFieldPartnerPokemon : public CFieldPartner {
public:
    CFieldPartnerPokemon();
    virtual ~CFieldPartnerPokemon();
    virtual void sub_0203DA40(CFieldMap *map);
    virtual BOOL sub_0203D578(CFieldMap *map);

    void ov0_0213E3E4(u16 kind, u8 arg1);

public:
    u32 unk_268;
    u8 unk_26C[0x8];
    UnkStruct_0211EA94 *unk_274;
    u8 unk_278[0x4];
};

STATIC_SIZE_ASSERT(CFieldPartnerPokemon, 0x27C);

#endif // POKERANGER2_FIELD_CFIELDPARTNERPOKEMON_HPP
