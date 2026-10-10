#ifndef POKERANGER2_UNKCLASS_0213DDCC_HPP
#define POKERANGER2_UNKCLASS_0213DDCC_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_0213D84C;

// Defined in ov0
class UnkClass_0213DDCC {
public:
    UnkClass_0213DDCC();
    ~UnkClass_0213DDCC();

    inline UnkClass_0213D84C *Get(int i)
    {
        if (m_count < i) {
            return NULL;
        }
        return m_items[i];
    }

public:
    int m_count;
    UnkClass_0213D84C **m_items;
    u8 unk_08[0x4];
};

STATIC_SIZE_ASSERT(UnkClass_0213DDCC, 0xC);

extern "C" {
void ov0_0213DE10(UnkClass_0213DDCC *obj, int arg1);
}

#endif // POKERANGER2_UNKCLASS_0213DDCC_HPP
