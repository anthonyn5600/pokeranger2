#ifndef POKERANGER2_BATTLE_UNKCLASS_02128600_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02128600_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in ov1
class UnkClass_02128600 {
public:
    UnkClass_02128600();
    ~UnkClass_02128600(); // ov1_02128614

public:
    u8 unk_00[0x18];
};

STATIC_SIZE_ASSERT(UnkClass_02128600, 0x18);

#endif // POKERANGER2_BATTLE_UNKCLASS_02128600_HPP
