#include "UnkClass_02010470.hpp"

#include "UnkClass_0200D114.hpp"
#include "UnkStruct_020107A8.hpp"

UnkClass_02010470::UnkClass_02010470(u32 arg0)
{
    UnkClass_0200D114 *table = new UnkClass_0200D114(arg0);
    table->sub_0200D148("data/param/PokeID.bin");
    m_count = table->sub_0200D390();
    m_entries = new UnkStruct_020107A8[m_count];

    u32 value = 0;
    for (int i = 0; i < m_count; i++) {
        table->sub_0200D3B8(i, 1, &value);
        m_entries[i].unk_00 = (u16)value;
        table->sub_0200D3B8(i, 2, &value);
        m_entries[i].unk_02 = (u8)value;
        table->sub_0200D3B8(i, 4, &value);
        m_entries[i].unk_03 = (u8)value;
        table->sub_0200D3B8(i, 5, &value);
        m_entries[i].unk_04 = (u8)value;
        table->sub_0200D3B8(i, 6, &value);
        m_entries[i].unk_05 = (u8)value;
        table->sub_0200D3B8(i, 7, &value);
        m_entries[i].unk_06 = (u8)value;
        table->sub_0200D3B8(i, 8, &value);
        m_entries[i].unk_07 = (u8)value;
        table->sub_0200D3B8(i, 9, &value);
        m_entries[i].unk_08 = (u8)value;
        table->sub_0200D3B8(i, 10, &value);
        m_entries[i].unk_09 = (u8)value;
        table->sub_0200D3B8(i, 11, &value);
        m_entries[i].unk_0A = (u8)value;
        table->sub_0200D3B8(i, 12, &value);
        m_entries[i].unk_0B = (u8)value;
        table->sub_0200D3B8(i, 13, &value);
        m_entries[i].unk_0C = (u8)value;
        table->sub_0200D3B8(i, 14, &value);
        m_entries[i].unk_0D = (u8)value;
        table->sub_0200D3B8(i, 15, &value);
        m_entries[i].unk_0E = (u8)value;
        table->sub_0200D3B8(i, 16, &value);
        m_entries[i].unk_0F = (u8)value;
        table->sub_0200D3B8(i, 21, &value);
        m_entries[i].unk_10 = (u16)value;
        table->sub_0200D3B8(i, 22, &value);
        m_entries[i].unk_12 = (u16)value;
        table->sub_0200D3B8(i, 23, &value);
        m_entries[i].unk_14 = value;
    }

    delete table;
}

extern "C" {

UnkStruct_020107A8 *sub_020107A8(void *obj, u16 id)
{
    UnkClass_02010470 *self = (UnkClass_02010470 *)obj;
    if (id >= self->m_count) {
        return NULL;
    }
    return &self->m_entries[id];
}

int sub_020107C4(int arg0)
{
    switch (arg0) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        return 1;
    case 9:
    case 10:
    case 11:
    case 12:
        return 2;
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
        return 3;
    case 0:
    default:
        return 0;
    }
}
}
