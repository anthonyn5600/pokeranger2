#ifndef POKERANGER2_BATTLE_BATTLEEFFECTTABLE_HPP
#define POKERANGER2_BATTLE_BATTLEEFFECTTABLE_HPP

#include <nitro.h>

#include "battle/BattleEffectParam.hpp"
#include "common.hpp"

// Defined in ov1
class BattleEffectTable {
public:
    BattleEffectTable(u32 arg0);
    ~BattleEffectTable(); // ov1_0212E304

    inline BattleEffectParam *GetEntry(u16 id)
    {
        if (id >= m_count) {
            return NULL;
        }
        return &m_entries[id];
    }

public:
    u16 m_count;
    u8 unk_02[0x2];
    BattleEffectParam *m_entries;
};

STATIC_SIZE_ASSERT(BattleEffectTable, 0x8);

#endif // POKERANGER2_BATTLE_BATTLEEFFECTTABLE_HPP
