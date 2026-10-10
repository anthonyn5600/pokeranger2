#ifndef POKERANGER2_UNKCLASS_0214FB28_HPP
#define POKERANGER2_UNKCLASS_0214FB28_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

struct UnkStruct_0214FB28 {
    u8 unk_00[0x18];
    Rectangle unk_18;
};

// Defined in ov0
class UnkClass_0214FB28 {
public:
    UnkClass_0214FB28();
    ~UnkClass_0214FB28();

public:
    u16 unk_00;
    u16 unk_02;
    UnkStruct_0214FB28 *unk_04;
    u8 unk_08[0x8];
};

STATIC_SIZE_ASSERT(UnkClass_0214FB28, 0x10);

#endif // POKERANGER2_UNKCLASS_0214FB28_HPP
