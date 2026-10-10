#ifndef POKERANGER2_FIELD_CFIELDENEMY_HPP
#define POKERANGER2_FIELD_CFIELDENEMY_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldActor.hpp"

// Defined in ov0
class CFieldEnemy : public CFieldActor {
public:
    u32 unk_E0;
    u8 unk_E4[0x4];
    u32 unk_E8;
    u8 unk_EC[0x5A];
    u16 unk_146;
    u8 unk_148[0xFC];
    int unk_244;
};

#endif // POKERANGER2_FIELD_CFIELDENEMY_HPP
