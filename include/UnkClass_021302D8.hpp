#ifndef POKERANGER2_UNKCLASS_021302D8_HPP
#define POKERANGER2_UNKCLASS_021302D8_HPP

#include "common.hpp"

class CGame;

// Defined in ov11, owned by UnkClass_0211E05C::unk_718 (DWC connection)
class UnkClass_021302D8 {
public:
    UnkClass_021302D8(CGame *game);
    ~UnkClass_021302D8();
    int ov11_0213031C();
    void ov11_021304B4();

public:
    u8 unk_00[0x14];
    void *unk_14;
};

STATIC_SIZE_ASSERT(UnkClass_021302D8, 0x18);

#endif // POKERANGER2_UNKCLASS_021302D8_HPP
