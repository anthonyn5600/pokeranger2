#ifndef POKERANGER2_BATTLE_UNKCLASS_0212E008_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0212E008_HPP

#include <nitro.h>

#include "battle/UnkStruct_0212E008.hpp"
#include "common.hpp"

// Defined in ov1
class UnkClass_0212E008 {
public:
    UnkClass_0212E008(u32 arg0);
    ~UnkClass_0212E008(); // ov1_0212E304

    inline UnkStruct_0212E008 *GetEntry(u16 id)
    {
        if (id >= m_count) {
            return NULL;
        }
        return &m_entries[id];
    }

public:
    u16 m_count;
    u8 unk_02[0x2];
    UnkStruct_0212E008 *m_entries;
};

STATIC_SIZE_ASSERT(UnkClass_0212E008, 0x8);

#endif // POKERANGER2_BATTLE_UNKCLASS_0212E008_HPP
