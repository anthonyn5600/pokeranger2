#ifndef POKERANGER2_POKEIDTABLE_HPP
#define POKERANGER2_POKEIDTABLE_HPP

#include <nitro.h>

#include "PokeIdTableEntry.hpp"
#include "common.hpp"

// Table loaded from data/param/PokeID.bin; CGame::unk_1434
class PokeIdTable {
public:
    PokeIdTable(u32 arg0);

public:
    u16 m_count;
    PokeIdTableEntry *m_entries;
};

STATIC_SIZE_ASSERT(PokeIdTable, 0x8);

#endif // POKERANGER2_POKEIDTABLE_HPP
