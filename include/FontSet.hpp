#ifndef POKERANGER2_FONTSET_HPP
#define POKERANGER2_FONTSET_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"
#include "file/CBinaryFile.hpp"

class FontSet {
public:
    FontSet(u32 arg0);

public:
    CBinaryFile *unk_00;
    CBinaryFile *unk_04;
    u32 unk_08;
    NNSG2dFont unk_0C;
    NNSG2dFont unk_14;
};

STATIC_SIZE_ASSERT(FontSet, 0x1C);

#endif // POKERANGER2_FONTSET_HPP
