#include <nitro.h>

#include "UnkClass_02041C80.hpp"
#include "UnkClass_02041D80.hpp"
#include "common.hpp"
#include "field/CFieldPokeMove.hpp"
#include "file/CBinaryFile.hpp"

extern UnkClass_02041C80 *MAIN_BSS_0210CA6C;

UnkClass_02041C80::UnkClass_02041C80(const char *path, int heapId)
{
    MAIN_BSS_0210CA6C = this;
    unk_00 = NULL;
    unk_04 = NULL;
    unk_08 = NULL;
    unk_0C = NULL;
    Load(path, heapId);
}

void UnkClass_02041C80::Load(const char *path, int heapId)
{
    unk_00 = new CBinaryFile(path, 0, 0, heapId, NULL, 0);
    u8 *data = (u8 *)unk_00->unk_4C;
    u32 *offsets = (u32 *)data;
    unk_08 = (FieldEnemyData *)(data + offsets[2] + 8);
    unk_0C = (FieldTargetObjectData *)(data + offsets[3] + 8);
    unk_04 = (u32 *)(data + offsets[4] + 8);
    unk_10 = (UnkStruct_02041D80 *)(data + offsets[5] + 8);
}

extern "C" u32 *sub_02041D44(UnkClass_02041C80 *obj, int kind)
{
    if (obj->unk_04 != NULL) {
        return &obj->unk_04[kind];
    }
    return NULL;
}

extern "C" FieldEnemyData *sub_02041D58(UnkClass_02041C80 *obj, int kind)
{
    if (obj->unk_08 != NULL) {
        return &obj->unk_08[kind];
    }
    return NULL;
}

extern "C" FieldTargetObjectData *sub_02041D6C(UnkClass_02041C80 *obj, int kind)
{
    if (obj->unk_0C != NULL) {
        return &obj->unk_0C[kind];
    }
    return NULL;
}

extern "C" UnkStruct_02041D80 *sub_02041D80(UnkClass_02041C80 *obj, u32 mapId)
{
    if (obj->unk_10 != NULL) {
        return &obj->unk_10[mapId];
    }
    return NULL;
}
