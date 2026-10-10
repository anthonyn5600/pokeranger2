#ifndef POKERANGER2_FIELD_CFIELDENEMYMANAGE_HPP
#define POKERANGER2_FIELD_CFIELDENEMYMANAGE_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActorManage.hpp"
#include "field/IFieldEnemyDataBuilder.hpp"

class CFieldEnemyManage;

extern CFieldEnemyManage *MAIN_BSS_0210CA5C;

// Defined in ov0
class CFieldEnemyManage : public CFieldActorManage, public IFieldEnemyDataBuilder {
public:
    CFieldEnemyManage()
    {
        MAIN_BSS_0210CA5C = this;
        unk_0C = 1;
    }

    virtual ~CFieldEnemyManage()
    {
        sub_0203F034();
        MAIN_BSS_0210CA5C = NULL;
    }

    virtual void sub_0203EFE4(int capacity);
    virtual void sub_0203F034();

    virtual void func0();

public:
    u32 unk_14;
};

STATIC_SIZE_ASSERT(CFieldEnemyManage, 0x18);

extern "C" {
void ov0_02136878(CFieldEnemyManage *mgr);
}

#endif // POKERANGER2_FIELD_CFIELDENEMYMANAGE_HPP
