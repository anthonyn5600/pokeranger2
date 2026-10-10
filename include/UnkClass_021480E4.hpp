#ifndef POKERANGER2_UNKCLASS_021480E4_HPP
#define POKERANGER2_UNKCLASS_021480E4_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in ov0
class UnkClass_021480E4 {
public:
    UnkClass_021480E4();
    ~UnkClass_021480E4();

public:
    u8 unk_00[0xC4];
};

STATIC_SIZE_ASSERT(UnkClass_021480E4, 0xC4);

extern "C" {
void ov0_0214816C(UnkClass_021480E4 *obj, int arg1, int arg2, int arg3, int arg4);
}

#endif // POKERANGER2_UNKCLASS_021480E4_HPP
