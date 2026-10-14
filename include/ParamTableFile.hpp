#ifndef POKERANGER2_PARAMTABLEFILE_HPP
#define POKERANGER2_PARAMTABLEFILE_HPP

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

class ParamTableFile {
public:
    ParamTableFile(u32 arg0);
    ~ParamTableFile();

    void Load(const char *path);
    void Release();
    void Parse();
    s32 sub_0200D390();
    BOOL GetIndex(int row, int column, u32 *index);
    BOOL GetValue(int row, int column, u32 *value);

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

STATIC_SIZE_ASSERT(ParamTableFile, 0x20);

#endif // POKERANGER2_PARAMTABLEFILE_HPP
