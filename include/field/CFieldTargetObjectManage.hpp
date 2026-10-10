#ifndef POKERANGER2_FIELD_CFIELDTARGETOBJECTMANAGE_HPP
#define POKERANGER2_FIELD_CFIELDTARGETOBJECTMANAGE_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActorManage.hpp"

class CFieldTargetObjectManage;

extern CFieldTargetObjectManage *MAIN_BSS_0210CA7C;

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

public:
    u32 unk_10;
};

STATIC_SIZE_ASSERT(CFieldTargetObjectManage, 0x14);

#endif // POKERANGER2_FIELD_CFIELDTARGETOBJECTMANAGE_HPP
