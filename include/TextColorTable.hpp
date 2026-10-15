#ifndef POKERANGER2_TEXTCOLORTABLE_HPP
#define POKERANGER2_TEXTCOLORTABLE_HPP

#include <nitro.h>

#include "common.hpp"

union TextColorTable {
    struct {
        u32 unk_00;
        u32 unk_04;
        u32 unk_08;
        u32 unk_0C;
        u32 unk_10;
        u32 unk_14;
    };
    u32 raw[6];
};

STATIC_SIZE_ASSERT(TextColorTable, 0x18);

#endif // POKERANGER2_TEXTCOLORTABLE_HPP
