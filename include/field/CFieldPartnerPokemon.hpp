#ifndef POKERANGER2_FIELD_CFIELDPARTNERPOKEMON_HPP
#define POKERANGER2_FIELD_CFIELDPARTNERPOKEMON_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActorScript.hpp"
#include "field/CFieldPartner.hpp"
#include "file/CBinaryFile.hpp"

// FieldPartnerPokemon.cpp (ov0): runs a "TargetClear" script with the partner's id and a target id.
class CFieldPokemonTargetClearScript : public CFieldActorScript {
public:
    CFieldPokemonTargetClearScript()
        : CFieldActorScript(0x30)
    {
    }

    BOOL Run(u32 actorId, u32 targetId);
};

// FieldPartnerPokemon.cpp (ov0)
class CFieldPartnerPokemon : public CFieldPartner {
public:
    CFieldPartnerPokemon();
    virtual ~CFieldPartnerPokemon();
    virtual void sub_0203DA40(CFieldMap *map);
    virtual BOOL sub_0203D578(CFieldMap *map);

    BOOL ov0_0213E3E4(u16 kind, u8 arg1);
    BOOL ov0_0213E4BC(u32 targetId);
    void ov0_0213E4F0();

public:
    int unk_268;
    CBinaryFile *unk_26C;
    u8 *unk_270;
    CFieldPokemonTargetClearScript *unk_274;
    BOOL unk_278;
};

STATIC_SIZE_ASSERT(CFieldPartnerPokemon, 0x27C);

#endif // POKERANGER2_FIELD_CFIELDPARTNERPOKEMON_HPP
