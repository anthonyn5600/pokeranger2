#ifndef POKERANGER2_BATTLE_UNKCLASS_02128860_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02128860_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class UnkClass_02128600;

// Defined in ov1
class UnkClass_02128860 {
public:
    UnkClass_02128860();
    void ov1_02128E34(Point2D pos, int arg1);
    void ov1_0212891C(UnkClass_02128600 *arg0);

public:
    u8 unk_00[0x18];
};

STATIC_SIZE_ASSERT(UnkClass_02128860, 0x18);

#endif // POKERANGER2_BATTLE_UNKCLASS_02128860_HPP
