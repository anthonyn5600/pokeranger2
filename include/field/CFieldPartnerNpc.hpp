#ifndef POKERANGER2_FIELD_CFIELDPARTNERNPC_HPP
#define POKERANGER2_FIELD_CFIELDPARTNERNPC_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldPartner.hpp"

// Defined in ov0
class CFieldPartnerNpc : public CFieldPartner {
public:
    CFieldPartnerNpc();
    virtual ~CFieldPartnerNpc();
    virtual void sub_0203DA40(CFieldMap *map);
    virtual BOOL sub_0203D578(CFieldMap *map);
    virtual BOOL sub_0203DA38();

public:
    u8 unk_278[0x10];
};

STATIC_SIZE_ASSERT(CFieldPartnerNpc, 0x288);

#endif // POKERANGER2_FIELD_CFIELDPARTNERNPC_HPP
