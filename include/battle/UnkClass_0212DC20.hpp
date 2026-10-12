#ifndef POKERANGER2_BATTLE_UNKCLASS_0212DC20_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0212DC20_HPP

#include <nitro.h>

#include "battle/UnkStruct_0212DFEC.hpp"
#include "common.hpp"

// Defined in ov1
class UnkClass_0212DC20 {
public:
    UnkClass_0212DC20(u32 arg0);
    ~UnkClass_0212DC20(); // ov1_0212DFC4
    UnkStruct_0212DFEC *ov1_0212DFEC(u16 id);

public:
    u8 unk_00[0x8];
};

STATIC_SIZE_ASSERT(UnkClass_0212DC20, 0x8);

#endif // POKERANGER2_BATTLE_UNKCLASS_0212DC20_HPP
