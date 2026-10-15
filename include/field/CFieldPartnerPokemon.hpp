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
    virtual void Process(CFieldMap *map);
    virtual BOOL UpdateMove(CFieldMap *map);

    BOOL LoadTargetClearScript(u16 kind, u8 arg1);
    BOOL RunTargetClearScript(u32 targetId);
    void UpdateTargetClearScript();

public:
    int unk_268;
    CBinaryFile *unk_26C;
    u8 *unk_270;
    CFieldPokemonTargetClearScript *unk_274;
    BOOL unk_278;
};

STATIC_SIZE_ASSERT(CFieldPartnerPokemon, 0x27C);

#endif // POKERANGER2_FIELD_CFIELDPARTNERPOKEMON_HPP
