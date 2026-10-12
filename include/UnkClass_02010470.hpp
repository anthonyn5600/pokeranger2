#ifndef POKERANGER2_UNKCLASS_02010470_HPP
#define POKERANGER2_UNKCLASS_02010470_HPP

#include <nitro.h>

#include "UnkStruct_020107A8.hpp"
#include "common.hpp"

// Table loaded from data/param/PokeID.bin; CGame::unk_1434
class UnkClass_02010470 {
public:
    UnkClass_02010470(u32 arg0);

public:
    u16 m_count;
    UnkStruct_020107A8 *m_entries;
};

STATIC_SIZE_ASSERT(UnkClass_02010470, 0x8);

#endif // POKERANGER2_UNKCLASS_02010470_HPP
