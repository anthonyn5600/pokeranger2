#ifndef POKERANGER2_UNKCLASS_0200CFF4_HPP
#define POKERANGER2_UNKCLASS_0200CFF4_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"
#include "file/CBinaryFile.hpp"

class UnkClass_0200CFF4 {
public:
    UnkClass_0200CFF4(u32 arg0);

public:
    CBinaryFile *unk_00;
    CBinaryFile *unk_04;
    u32 unk_08;
    NNSG2dFont unk_0C;
    NNSG2dFont unk_14;
};

STATIC_SIZE_ASSERT(UnkClass_0200CFF4, 0x1C);

#endif // POKERANGER2_UNKCLASS_0200CFF4_HPP
