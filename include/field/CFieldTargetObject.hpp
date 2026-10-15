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
    CFieldTargetObjectActorScript(int size)
        : CFieldActorScript(size)
    {
        unk_38 = -1;
    }

    virtual ~CFieldTargetObjectActorScript()
    {
    }

    virtual BOOL Call(CFieldActor *actor, const char *func);

public:
    int unk_38;
};

STATIC_SIZE_ASSERT(CFieldTargetObjectActorScript, 0x3C);

// Defined in ov0
class CFieldTargetObject : public CFieldActor {
public:
    CFieldTargetObject();
    virtual ~CFieldTargetObject();
    virtual void Process(CFieldMap *map);
    virtual BOOL UpdateMove(CFieldMap *map);
    virtual BOOL sub_0203DA38();
    virtual void StopMotion();
    virtual void PlayAnim(int arg0, int arg1);

    BOOL ov0_0213CD3C();
    BOOL ov0_0213CD78(int arg);
    BOOL ov0_0213CDB4(int arg);
    BOOL ov0_0213CF30(CFieldActorScript *script, void *block);
    BOOL ov0_0213CF60(const char *func);
    void ov0_0213CFBC();
    BOOL ov0_0213CFDC();

    CFieldTargetObjectActorScript *GetScript()
    {
        return (CFieldTargetObjectActorScript *)m_script;
    }

public:
    int unk_E0;
    int unk_E4;
    int unk_E8;
    int unk_EC;
    int m_offsetX;
    int m_offsetY;
    CFieldActorScript *unk_F8;
    BOOL unk_FC;
    char unk_100[0x10];
    int unk_110;
};

STATIC_SIZE_ASSERT(CFieldTargetObject, 0x114);

#endif // POKERANGER2_FIELD_CFIELDTARGETOBJECT_HPP
