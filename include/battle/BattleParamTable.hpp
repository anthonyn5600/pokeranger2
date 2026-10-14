#ifndef POKERANGER2_BATTLE_BATTLEPARAMTABLE_HPP
#define POKERANGER2_BATTLE_BATTLEPARAMTABLE_HPP

#include <nitro.h>

#include "common.hpp"

struct UnkStruct_0212F310 {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04[3];
    u16 unk_0A;
    u16 unk_0C[3];
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u16 unk_1A[3];
    u16 unk_20;
    u16 unk_22;
    u16 unk_24[3];
    u16 unk_2A;
    u16 unk_2C[3];
};

STATIC_SIZE_ASSERT(UnkStruct_0212F310, 0x32);

// Assist parameter table (BattleAssist param .bin), CBattleAssist::unk_10
class BattleParamTable {
public:
    BattleParamTable(const char *path, u32 arg1);
    ~BattleParamTable();

    UnkStruct_0212F310 *ov1_0212F310(int id);
    u16 ov1_0212F32C(int kind, u16 id, u16 index);

public:
    u16 m_count;
    UnkStruct_0212F310 *m_entries;
};

STATIC_SIZE_ASSERT(BattleParamTable, 0x8);

#endif // POKERANGER2_BATTLE_BATTLEPARAMTABLE_HPP
