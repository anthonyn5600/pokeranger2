#ifndef POKERANGER2_FIELDDATA_HPP
#define POKERANGER2_FIELDDATA_HPP

#include <nitro.h>

#include "common.hpp"

class CBinaryFile;
struct FieldEnemyData;
struct FieldTargetObjectData;
struct UnkStruct_02041D80;

// Field data tables (CGame::unk_14CC, singleton MAIN_BSS_0210CA6C), opened on data/field/fielddata.bin:
// NPC (4 bytes), enemy (0x40), target object (0x20) and map (0x54) records.
class FieldData {
public:
    FieldData(const char *path, int heapId);
    void Load(const char *path, int heapId);

public:
    CBinaryFile *unk_00;
    u32 *unk_04;
    FieldEnemyData *unk_08;
    FieldTargetObjectData *unk_0C;
    UnkStruct_02041D80 *unk_10;
};

STATIC_SIZE_ASSERT(FieldData, 0x14);

#endif // POKERANGER2_FIELDDATA_HPP
