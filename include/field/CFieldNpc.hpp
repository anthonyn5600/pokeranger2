#ifndef POKERANGER2_FIELD_CFIELDNPC_HPP
#define POKERANGER2_FIELD_CFIELDNPC_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldActorScript.hpp"
#include "field/CFieldPokeMove.hpp"

class CBinaryFile;

// FieldNpc.cpp (ov0): an NPC's script; pushes the NPC's id before calling a script function.
class CFieldNpcActorScript : public CFieldActorScript {
public:
    CFieldNpcActorScript()
        : CFieldActorScript(0x20)
    {
    }

    virtual ~CFieldNpcActorScript()
    {
    }

    virtual BOOL Call(CFieldActor *actor, const char *func);
};

// FieldNpc.cpp (ov0)
class CFieldNpc : public CFieldActor {
public:
    CFieldNpc();
    virtual ~CFieldNpc();
    virtual void Process(CFieldMap *map);
    virtual BOOL UpdateMove(CFieldMap *map);
    virtual BOOL Talk();
    virtual void StopMotion();
    virtual void SetMoveSequence(int sequence);

    void LoadScript(int npcId);
    void ApplyFloatHeight();

public:
    int unk_E0;
    int unk_E4;
    int unk_E8;
    u16 unk_EC;
    int unk_F0;
    CFieldPokeMove unk_F4;
    CBinaryFile *unk_1D0;
    int unk_1D4;
};

STATIC_SIZE_ASSERT(CFieldNpc, 0x1D8);

#endif // POKERANGER2_FIELD_CFIELDNPC_HPP
