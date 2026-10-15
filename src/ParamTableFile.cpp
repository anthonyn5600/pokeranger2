#include "ParamTableFile.hpp"

#include <string.h>

ParamTableFile::ParamTableFile(u32 arg0)
{
    unk_00 = NULL;
    unk_04 = NULL;
    unk_08 = arg0;
    unk_1C = 0;
    unk_14 = 0;
    unk_18 = 0;
}

ParamTableFile::~ParamTableFile()
{
    Release();
}

void ParamTableFile::Load(const char *path)
{
    unk_00 = new CBinaryFile(path, 1, 0, unk_08, NULL, 0);
    unk_04 = (UnkStruct_0200D114_Header *)unk_00->unk_4C;
    Parse();
}

void ParamTableFile::Release()
{
    if (unk_00 != NULL) {
        delete unk_00;
        unk_00 = NULL;
    }
    if (unk_0C != NULL) {
        delete[] unk_0C;
        unk_0C = NULL;
    }
    if (unk_10 != NULL) {
        delete[] unk_10;
        unk_10 = NULL;
    }
}

void ParamTableFile::Parse()
{
    s8 *types = ((UnkStruct_0200D114_Header *)unk_00->unk_4C)->columnTypes;
    unk_14 = unk_04->numColumns;
    u8 *data = (u8 *)types + unk_14;
    unk_18 = unk_04->numCells;
    unk_0C = new s8[unk_14];
    unk_10 = new u32[unk_18];

    int i;
    for (i = 0; i < unk_14; i++) {
        unk_0C[i] = types[i];
    }

    unk_1C = unk_18 / unk_14;

    for (int row = 0; row < unk_1C; row++) {
        for (i = 0; i < unk_14; i++) {
            u32 value = 0;
            int idx = row * unk_14 + i;
            switch (unk_0C[i]) {
            case 1:
            case 2:
                memcpy(&value, data, 1);
                data += 1;
                unk_10[idx] = value;
                break;
            case 3:
            case 4:
                memcpy(&value, data, 2);
                data += 2;
                unk_10[idx] = value;
                break;
            case 5:
            case 6:
                memcpy(&value, data, 4);
                data += 4;
                unk_10[idx] = value;
                break;
            case 7:
                unk_10[idx] = value;
                break;
            }
        }
    }
}

s32 ParamTableFile::GetRowCount()
{
    return unk_1C;
}

BOOL ParamTableFile::GetIndex(int row, int column, u32 *index)
{
    if (column > unk_14 - 1) {
        return FALSE;
    }
    *index = row * unk_14 + column;
    return TRUE;
}

BOOL ParamTableFile::GetValue(int row, int column, u32 *value)
{
    u32 idx = 0;
    if (!GetIndex(row, column, &idx)) {
        return FALSE;
    }
    *value = unk_10[idx];
    return TRUE;
}
