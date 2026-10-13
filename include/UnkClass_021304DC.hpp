#ifndef POKERANGER2_UNKCLASS_021304DC_HPP
#define POKERANGER2_UNKCLASS_021304DC_HPP

#include "common.hpp"

class CGame;
class UnkClass_021302D8;
class UnkClass_0211E05C;

// Defined in ov11, owned by UnkClass_0211E05C::unk_714
class UnkClass_021304DC {
public:
    UnkClass_021304DC(CGame *game, UnkClass_021302D8 *dwc, UnkClass_0211E05C *menu);
    ~UnkClass_021304DC();
    void ov11_02130B14();
    void ov11_02130B30();
    int ov11_0213051C();

public:
    u8 unk_000[0x2C];
    u16 unk_02C;
    u8 unk_02E[0x486];
    u16 unk_4B4;
    u8 unk_4B6[0xA];
    void *unk_4C0;
    u8 unk_4C4[0x20];
};

STATIC_SIZE_ASSERT(UnkClass_021304DC, 0x4E4);

#endif // POKERANGER2_UNKCLASS_021304DC_HPP
