#include "FieldData.hpp"

#include <nitro.h>

#include "FieldDataRecords.hpp"
#include "common.hpp"
#include "field/CFieldPokeMove.hpp"
#include "file/CBinaryFile.hpp"

extern FieldData *MAIN_BSS_0210CA6C;

FieldData::FieldData(const char *path, int heapId)
{
    MAIN_BSS_0210CA6C = this;
    unk_00 = NULL;
    unk_04 = NULL;
    unk_08 = NULL;
    unk_0C = NULL;
    Load(path, heapId);
}

void FieldData::Load(const char *path, int heapId)
{
    unk_00 = new CBinaryFile(path, 0, 0, heapId, NULL, 0);
    u8 *data = (u8 *)unk_00->unk_4C;
    u32 *offsets = (u32 *)data;
    unk_08 = (FieldEnemyData *)(data + offsets[2] + 8);
    unk_0C = (FieldTargetObjectData *)(data + offsets[3] + 8);
    unk_04 = (u32 *)(data + offsets[4] + 8);
    unk_10 = (FieldMapData *)(data + offsets[5] + 8);
}

extern "C" u32 *FieldData_GetNpc(FieldData *obj, int kind)
{
    if (obj->unk_04 != NULL) {
        return &obj->unk_04[kind];
    }
    return NULL;
}

extern "C" FieldEnemyData *FieldData_GetEnemy(FieldData *obj, int kind)
{
    if (obj->unk_08 != NULL) {
        return &obj->unk_08[kind];
    }
    return NULL;
}

extern "C" FieldTargetObjectData *FieldData_GetTargetObject(FieldData *obj, int kind)
{
    if (obj->unk_0C != NULL) {
        return &obj->unk_0C[kind];
    }
    return NULL;
}

extern "C" FieldMapData *FieldData_GetMap(FieldData *obj, u32 mapId)
{
    if (obj->unk_10 != NULL) {
        return &obj->unk_10[mapId];
    }
    return NULL;
}
