#ifndef POKERANGER2_UNKCLASS_0200D114_HPP
#define POKERANGER2_UNKCLASS_0200D114_HPP

#include <nitro.h>

#include "common.hpp"
#include "file/CBinaryFile.hpp"

struct UnkStruct_0200D114_Header {
    u32 unk_00;
    s32 numColumns;
    u32 unk_08;
    s32 numCells;
    s8 columnTypes[];
};

class UnkClass_0200D114 {
public:
    UnkClass_0200D114(u32 arg0);
    ~UnkClass_0200D114();

    void sub_0200D148(const char *path);
    void sub_0200D1A0();
    void sub_0200D200();
    s32 sub_0200D390();
    BOOL sub_0200D398(int row, int column, u32 *index);
    BOOL sub_0200D3B8(int row, int column, u32 *value);

public:
    CBinaryFile *unk_00;
    UnkStruct_0200D114_Header *unk_04;
    u32 unk_08;
    s8 *unk_0C;
    u32 *unk_10;
    s32 unk_14;
    s32 unk_18;
    s32 unk_1C;
};

STATIC_SIZE_ASSERT(UnkClass_0200D114, 0x20);

#endif // POKERANGER2_UNKCLASS_0200D114_HPP
