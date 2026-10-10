#ifndef POKERANGER2_UNKCLASS_0213DDCC_HPP
#define POKERANGER2_UNKCLASS_0213DDCC_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEventRect.hpp"

class UnkClass_0213DDCC;

extern UnkClass_0213DDCC *MAIN_BSS_0210CA58;

// Defined in ov0
class UnkClass_0213DDCC {
public:
    UnkClass_0213DDCC();
    ~UnkClass_0213DDCC();

    inline CFieldEventRect *Get(int i)
    {
        if (m_count < i) {
            return NULL;
        }
        return m_items[i];
    }

    inline int Add(CFieldEventRect *rect)
    {
        for (int i = 0; i < m_count; i++) {
            if (m_items[i] == NULL) {
                m_items[i] = rect;
                rect->SetIndex(i);
                return i;
            }
        }
        return -1;
    }

public:
    int m_count;
    CFieldEventRect **m_items;
    u8 unk_08[0x4];
};

STATIC_SIZE_ASSERT(UnkClass_0213DDCC, 0xC);

extern "C" {
void ov0_0213DE10(UnkClass_0213DDCC *obj, int arg1);
}

#endif // POKERANGER2_UNKCLASS_0213DDCC_HPP
