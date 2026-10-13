#ifndef POKERANGER2_UNKCLASS_0212CE58_HPP
#define POKERANGER2_UNKCLASS_0212CE58_HPP

#include "common.hpp"

class CGame;
class UnkClass_0211E05C;

// Defined in ov11
// 0x30-byte block owned by UnkClass_0212CE58::unk_0 and UnkClass_0212D97C::unk_060/064 (no ctor)
struct UnkClass_0212CE58_000 {
    u8 unk_00[0x30];
};

// Defined in ov11, owned by UnkClass_0211E05C::unk_720
class UnkClass_0212CE58 {
public:
    UnkClass_0212CE58(CGame *game, UnkClass_0211E05C *menu);
    ~UnkClass_0212CE58();
    void ov11_0212D018(int v);
    BOOL ov11_0212D030();

public:
    UnkClass_0212CE58_000 *unk_0;
    u8 unk_004[0x3E8];
};

STATIC_SIZE_ASSERT(UnkClass_0212CE58, 0x3EC);

#endif // POKERANGER2_UNKCLASS_0212CE58_HPP
