#ifndef POKERANGER2_BATTLE_BATTLEPOKEMONTABLE_HPP
#define POKERANGER2_BATTLE_BATTLEPOKEMONTABLE_HPP

#include <nitro.h>

#include "battle/BattlePokemonParam.hpp"
#include "common.hpp"

// Defined in ov1
class BattlePokemonTable {
public:
    BattlePokemonTable(u32 arg0);
    ~BattlePokemonTable(); // ov1_0212DFC4
    BattlePokemonParam *GetEntry(u16 id);

public:
    u16 m_count;
    u8 unk_02[0x2];
    BattlePokemonParam *m_entries;
};

STATIC_SIZE_ASSERT(BattlePokemonTable, 0x8);

#endif // POKERANGER2_BATTLE_BATTLEPOKEMONTABLE_HPP
