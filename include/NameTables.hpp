#ifndef POKERANGER2_NAMETABLES_HPP
#define POKERANGER2_NAMETABLES_HPP

#include <nitro.h>

#include "TextboxManager.hpp"
#include "common.hpp"

// Name tables of /data/message/etc (pokemon, item, yakumono, npc, fieldwaza); CGame::unk_14B0
class NameTables {
public:
    NameTables();

    UnkClass_020091E8_004 *LoadPokemonNames();
    void FreePokemonNames();
    UnkClass_020091E8_004 *LoadItemNames();
    void FreeItemNames();
    UnkClass_020091E8_004 *LoadYakumonoNames();
    void FreeYakumonoNames();
    UnkClass_020091E8_004 *LoadNpcNames();
    void FreeNpcNames();
    UnkClass_020091E8_004 *LoadFieldMoveNames();
    void FreeFieldMoveNames();

public:
    UnkClass_020091E8_004 *unk_00;
    UnkClass_020091E8_004 *unk_04;
    UnkClass_020091E8_004 *unk_08;
    UnkClass_020091E8_004 *unk_0C;
    UnkClass_020091E8_004 *unk_10;
};

STATIC_SIZE_ASSERT(NameTables, 0x14);

#endif // POKERANGER2_NAMETABLES_HPP
