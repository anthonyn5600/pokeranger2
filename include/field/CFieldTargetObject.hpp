#ifndef POKERANGER2_FIELD_CFIELDTARGETOBJECT_HPP
#define POKERANGER2_FIELD_CFIELDTARGETOBJECT_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldActorScript.hpp"

class CFieldMap;

// Defined in ov0
class CFieldTargetObjectActorScript : public CFieldActorScript {
public:
    CFieldTargetObjectActorScript()
        : CFieldActorScript(0x30)
    {
        unk_38 = -1;
    }

    virtual ~CFieldTargetObjectActorScript()
    {
    }

    virtual BOOL sub_0203BE48(CFieldActor *actor, const char *func);

public:
    int unk_38;
};

STATIC_SIZE_ASSERT(CFieldTargetObjectActorScript, 0x3C);

// Defined in ov0
class CFieldTargetObject : public CFieldActor {
public:
    CFieldTargetObject();
    virtual ~CFieldTargetObject();
    virtual void sub_0203DA40(CFieldMap *map);
    virtual BOOL sub_0203D578(CFieldMap *map);
    virtual BOOL sub_0203DA38();
    virtual void sub_0202D7E0();
    virtual void sub_0202DC54(int arg0, int arg1);

    BOOL ov0_0213CD3C();
    BOOL ov0_0213CD78(int arg);
    BOOL ov0_0213CDB4(int arg);
    BOOL ov0_0213CF30(CFieldActorScript *script, void *block);
    BOOL ov0_0213CF60(const char *func);
    void ov0_0213CFBC();
    BOOL ov0_0213CFDC();

    CFieldTargetObjectActorScript *GetScript()
    {
        return (CFieldTargetObjectActorScript *)unk_DC;
    }

public:
    int unk_E0;
    int unk_E4;
    int unk_E8;
    int unk_EC;
    int unk_F0;
    int unk_F4;
    CFieldActorScript *unk_F8;
    BOOL unk_FC;
    char unk_100[0x10];
    int unk_110;
};

STATIC_SIZE_ASSERT(CFieldTargetObject, 0x114);

#endif // POKERANGER2_FIELD_CFIELDTARGETOBJECT_HPP
