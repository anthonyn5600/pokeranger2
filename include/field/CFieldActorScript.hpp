#ifndef POKERANGER2_FIELD_CFIELDACTORSCRIPT_HPP
#define POKERANGER2_FIELD_CFIELDACTORSCRIPT_HPP

#include <nitro.h>

#include "UnkStruct_02044464.hpp"
#include "common.hpp"

class CFieldActor;

// FieldActor.cpp (arm9): an actor's script (CFieldActor::unk_DC).
class CFieldActorScript {
public:
    CFieldActorScript(int stackSize);
    virtual ~CFieldActorScript();
    virtual BOOL sub_0203BE48(CFieldActor *actor, const char *func);
    virtual BOOL sub_0203BF00();

public:
    int unk_04;
    UnkStruct_02044464 unk_08;
    void *unk_2C;
    u32 *unk_30;
    int unk_34;
};

STATIC_SIZE_ASSERT(CFieldActorScript, 0x38);

#endif // POKERANGER2_FIELD_CFIELDACTORSCRIPT_HPP
