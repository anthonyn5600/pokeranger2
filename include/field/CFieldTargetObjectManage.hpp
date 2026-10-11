#ifndef POKERANGER2_FIELD_CFIELDTARGETOBJECTMANAGE_HPP
#define POKERANGER2_FIELD_CFIELDTARGETOBJECTMANAGE_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActorManage.hpp"

class CFieldTargetObjectManage;

extern CFieldTargetObjectManage *MAIN_BSS_0210CA7C;

// Defined in ov0: the target objects' script cache (data/Script/field/targetobject, targettouch).
class UnkClass_02142028 {
public:
    UnkClass_02142028();
    ~UnkClass_02142028();
    void ov0_02142068();
    void *ov0_021420AC(int id, BOOL touch);

public:
    void *m_scripts[32];
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
        sub_0203F034();
        MAIN_BSS_0210CA7C = NULL;
    }

    virtual void sub_0203EFE4(int capacity);
    virtual void sub_0203F034();
    virtual BOOL sub_0203F190();

    int ov0_0213D1AC(int slot, u16 kind, u16 script, u16 touchScript, int arg5);
    int ov0_0213D564();

public:
    UnkClass_02142028 *unk_10;
};

STATIC_SIZE_ASSERT(CFieldTargetObjectManage, 0x14);

#endif // POKERANGER2_FIELD_CFIELDTARGETOBJECTMANAGE_HPP
