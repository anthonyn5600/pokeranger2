#ifndef POKERANGER2_UNKCLASS_0202A2AC_HPP
#define POKERANGER2_UNKCLASS_0202A2AC_HPP

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "common.hpp"

// Sub-screen "ma005" button sprite (used by overlays 5 and 21).
class UnkClass_0202A2AC {
public:
    UnkClass_0202A2AC();
    ~UnkClass_0202A2AC();

    void sub_0202A32C(u32 charOffset, int oamIndex, u32 paletteSlot, int x, int y);
    BOOL sub_0202A404();
    void sub_0202A47C();

public:
    CGame *unk_00;
    UnkClass_0200E960 *unk_04;
    UnkClass_0200ECD0 *unk_08;
    u32 unk_0C;
    int unk_10;
    int unk_14;
    int unk_18;
    u32 unk_1C;
    BOOL unk_20;
    BOOL unk_24;
};

STATIC_SIZE_ASSERT(UnkClass_0202A2AC, 0x28);

#endif // POKERANGER2_UNKCLASS_0202A2AC_HPP
