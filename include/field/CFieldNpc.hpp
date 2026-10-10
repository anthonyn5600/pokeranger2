#ifndef POKERANGER2_FIELD_CFIELDNPC_HPP
#define POKERANGER2_FIELD_CFIELDNPC_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActor.hpp"

// Defined in ov0
class CFieldNpc : public CFieldActor {
public:
    u8 unk_E0[0x8];
    int unk_E8;
    u16 unk_EC;
};

#endif // POKERANGER2_FIELD_CFIELDNPC_HPP
