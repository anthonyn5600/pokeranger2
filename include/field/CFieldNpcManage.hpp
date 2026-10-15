#ifndef POKERANGER2_FIELD_CFIELDNPCMANAGE_HPP
#define POKERANGER2_FIELD_CFIELDNPCMANAGE_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActorManage.hpp"

class CFieldNpcManage;

extern CFieldNpcManage *MAIN_BSS_0210CA50;

// Defined in ov0
class CFieldNpcManage : public CFieldActorManage {
public:
    CFieldNpcManage()
    {
        MAIN_BSS_0210CA50 = this;
        unk_0C = 2;
    }

    virtual ~CFieldNpcManage()
    {
        Free();
        MAIN_BSS_0210CA50 = NULL;
    }

    virtual void Alloc(int capacity);
    virtual void Free();

    int Create(int slot, int type, u16 kind, u16 script, int arg5);
};

STATIC_SIZE_ASSERT(CFieldNpcManage, 0x10);

#endif // POKERANGER2_FIELD_CFIELDNPCMANAGE_HPP
