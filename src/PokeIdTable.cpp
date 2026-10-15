#include "PokeIdTable.hpp"

#include "ParamTableFile.hpp"
#include "PokeIdTableEntry.hpp"

PokeIdTable::PokeIdTable(u32 arg0)
{
    ParamTableFile *table = new ParamTableFile(arg0);
    table->Load("data/param/PokeID.bin");
    m_count = table->GetRowCount();
    m_entries = new PokeIdTableEntry[m_count];

    u32 value = 0;
    for (int i = 0; i < m_count; i++) {
        table->GetValue(i, 1, &value);
        m_entries[i].unk_00 = (u16)value;
        table->GetValue(i, 2, &value);
        m_entries[i].unk_02 = (u8)value;
        table->GetValue(i, 4, &value);
        m_entries[i].unk_03 = (u8)value;
        table->GetValue(i, 5, &value);
        m_entries[i].unk_04 = (u8)value;
        table->GetValue(i, 6, &value);
        m_entries[i].unk_05 = (u8)value;
        table->GetValue(i, 7, &value);
        m_entries[i].unk_06 = (u8)value;
        table->GetValue(i, 8, &value);
        m_entries[i].unk_07 = (u8)value;
        table->GetValue(i, 9, &value);
        m_entries[i].unk_08 = (u8)value;
        table->GetValue(i, 10, &value);
        m_entries[i].unk_09 = (u8)value;
        table->GetValue(i, 11, &value);
        m_entries[i].unk_0A = (u8)value;
        table->GetValue(i, 12, &value);
        m_entries[i].unk_0B = (u8)value;
        table->GetValue(i, 13, &value);
        m_entries[i].unk_0C = (u8)value;
        table->GetValue(i, 14, &value);
        m_entries[i].unk_0D = (u8)value;
        table->GetValue(i, 15, &value);
        m_entries[i].unk_0E = (u8)value;
        table->GetValue(i, 16, &value);
        m_entries[i].unk_0F = (u8)value;
        table->GetValue(i, 21, &value);
        m_entries[i].unk_10 = (u16)value;
        table->GetValue(i, 22, &value);
        m_entries[i].unk_12 = (u16)value;
        table->GetValue(i, 23, &value);
        m_entries[i].unk_14 = value;
    }

    delete table;
}

extern "C" {

PokeIdTableEntry *PokeIdTable_Get(void *obj, u16 id)
{
    PokeIdTable *self = (PokeIdTable *)obj;
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
