#ifndef POKERANGER2_UNKCLASS_0212D97C_HPP
#define POKERANGER2_UNKCLASS_0212D97C_HPP

#include "UnkClass_0212CE58.hpp"
#include "common.hpp"

class UnkClass_0211E05C;

// Defined in ov11, owned by UnkClass_0211E05C::unk_71C
class UnkClass_0212D97C {
public:
    UnkClass_0212D97C(UnkClass_0211E05C *menu);
    ~UnkClass_0212D97C();
    void ov11_0212E9B4(int state); // SetState: unk_151 = unk_150, unk_150 = state
    int ov11_0212DA48();

public:
    u8 unk_000[0x4C];
    u8 *unk_04C;
    u8 *unk_050;
    u8 unk_054[0x8];
    u8 *unk_05C;
    UnkClass_0212CE58_000 *unk_060;
    UnkClass_0212CE58_000 *unk_064;
    u8 unk_068[0xE8];
    u8 unk_150;
    u8 unk_151[0x43];
    int unk_194;
};

STATIC_SIZE_ASSERT(UnkClass_0212D97C, 0x198);

#endif // POKERANGER2_UNKCLASS_0212D97C_HPP
