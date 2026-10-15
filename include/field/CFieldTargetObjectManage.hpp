#ifndef POKERANGER2_FIELD_CFIELDTARGETOBJECTMANAGE_HPP
#define POKERANGER2_FIELD_CFIELDTARGETOBJECTMANAGE_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActorManage.hpp"

class CFieldTargetObjectManage;
class FieldTargetObjectScript;

extern CFieldTargetObjectManage *MAIN_BSS_0210CA7C;

// Defined in ov0: the target objects' script cache (data/Script/field/targetobject, targettouch).
class FieldTargetObjectScriptCache {
public:
    FieldTargetObjectScriptCache();
    ~FieldTargetObjectScriptCache();
    void Clear();
    void *Get(int id, BOOL touch);

public:
    FieldTargetObjectScript *m_scripts[32];
};

// Defined in ov0
class CFieldTargetObjectManage : public CFieldActorManage {
public:
    CFieldTargetObjectManage()
    {
        MAIN_BSS_0210CA7C = this;
        unk_0C = 3;
    }

    virtual ~CFieldTargetObjectManage()
    {
        Free();
        MAIN_BSS_0210CA7C = NULL;
    }

    virtual void Alloc(int capacity);
    virtual void Free();
    virtual BOOL Clear();

    int Create(int slot, u16 kind, u16 script, u16 touchScript, int arg5);
    int ov0_0213D564();

public:
    FieldTargetObjectScriptCache *unk_10;
};

STATIC_SIZE_ASSERT(CFieldTargetObjectManage, 0x14);

#endif // POKERANGER2_FIELD_CFIELDTARGETOBJECTMANAGE_HPP
