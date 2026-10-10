#ifndef POKERANGER2_UNKCLASS_0213D624_HPP
#define POKERANGER2_UNKCLASS_0213D624_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in ov0
class UnkClass_0213D624 {
public:
    UnkClass_0213D624();
    ~UnkClass_0213D624();

public:
    u8 unk_00[0x1C];
};

STATIC_SIZE_ASSERT(UnkClass_0213D624, 0x1C);

extern "C" {
void ov0_0213D658(UnkClass_0213D624 *obj);
}

#endif // POKERANGER2_UNKCLASS_0213D624_HPP
