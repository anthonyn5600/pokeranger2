#ifndef POKERANGER2_FIELD_CFIELDEVENTRECT_HPP
#define POKERANGER2_FIELD_CFIELDEVENTRECT_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

// FieldEventRect.cpp (ov0): a map area that runs a script (EventEnter/EventLeave) when entered or left.
class CFieldEventRect {
public:
    CFieldEventRect();
    ~CFieldEventRect();

    virtual void SetIndex(int index)
    {
        m_index = index;
    }

    void LoadScript(int id);

public:
    int m_group;
    Rectangle m_rect;
    int unk_18;
    u8 unk_1C[0x78];
    int m_index;
};

STATIC_SIZE_ASSERT(CFieldEventRect, 0x98);

#endif // POKERANGER2_FIELD_CFIELDEVENTRECT_HPP
