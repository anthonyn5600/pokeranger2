#ifndef POKERANGER2_FIELD_CFIELDPARTNERMANAGE_HPP
#define POKERANGER2_FIELD_CFIELDPARTNERMANAGE_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActorManage.hpp"
#include "field/CFieldEffectManageEventListener.hpp"
#include "field/CFieldPartner.hpp"

class CFieldPartnerManage;

extern CFieldPartnerManage *MAIN_BSS_0210CA4C;

// Defined in ov0
class CFieldPartnerManage : public CFieldActorManage, public CFieldEffectManageEventListener {
public:
    CFieldPartnerManage();

    virtual ~CFieldPartnerManage()
    {
        sub_0203F034();
        MAIN_BSS_0210CA4C = NULL;
    }

    virtual void sub_0203EFE4(int capacity);
    virtual void sub_0203F034();

    virtual void func0();

    void ov0_0213A858();

    inline CFieldPartner *FindPartner(u32 target)
    {
        u32 kind;
        u32 id;
        u32 type = ((s32)target >> 24) & 0xFF;
        if (type == 2) {
            id = (target & 0xFFFFFF) | 0x5000000;
            kind = 1;
        } else if (type == 1) {
            id = (target & 0xFFFFFF) | 0x6000000;
            kind = 0;
        } else {
            return NULL;
        }
        for (int i = 0; i < m_count; i++) {
            CFieldPartner *partner = (CFieldPartner *)Get(i);
            if (partner != NULL && id == partner->unk_58 && kind == partner->unk_1FC) {
                return partner;
            }
        }
        return NULL;
    }

public:
    u8 unk_14[0x84];
};

STATIC_SIZE_ASSERT(CFieldPartnerManage, 0x98);

extern "C" {
int ov0_02139920(CFieldPartnerManage *mgr, u32 id, u16 arg2, int arg3, int arg4, int arg5);
void ov0_02139E14(CFieldPartnerManage *mgr, int arg1);
void ov0_0213A7FC(CFieldPartnerManage *mgr, int arg1);
}

#endif // POKERANGER2_FIELD_CFIELDPARTNERMANAGE_HPP
