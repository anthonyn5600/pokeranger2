#ifndef POKERANGER2_FIELD_CFIELDTARGETOBJECT_HPP
#define POKERANGER2_FIELD_CFIELDTARGETOBJECT_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActor.hpp"

// Defined in ov0
class CFieldTargetObject : public CFieldActor {
public:
    u8 unk_E0[0x8];
    int unk_E8;
};

#endif // POKERANGER2_FIELD_CFIELDTARGETOBJECT_HPP
