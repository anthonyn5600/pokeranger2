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
    virtual void Process(CFieldMap *map);
    virtual BOOL UpdateMove(CFieldMap *map);
    virtual BOOL Talk();

    void SetName(const char *name);
    void ClearName();

public:
    char m_name[0x20];
};

STATIC_SIZE_ASSERT(CFieldPartnerNpc, 0x288);

#endif // POKERANGER2_FIELD_CFIELDPARTNERNPC_HPP
