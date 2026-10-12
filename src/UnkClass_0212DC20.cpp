#include "battle/UnkClass_0212DC20.hpp"

#include "UnkClass_0200D114.hpp"
#include "battle/UnkClass_0212E008.hpp"

UnkClass_0212DC20::UnkClass_0212DC20(u32 arg0)
{
    UnkClass_0200D114 *reader = new UnkClass_0200D114(arg0);
    reader->sub_0200D148("data/param/BattlePokemon.bin");
    m_count = reader->sub_0200D390();
    m_entries = new UnkStruct_0212DFEC[m_count];
    u32 value = 0;
    for (int i = 0; i < m_count; i++) {
        reader->sub_0200D3B8(i, 1, &value);
        m_entries[i].unk_04 = value;
        reader->sub_0200D3B8(i, 2, &value);
        m_entries[i].unk_00 = value;
        reader->sub_0200D3B8(i, 3, &value);
        m_entries[i].unk_02 = value;
        reader->sub_0200D3B8(i, 4, &value);
        m_entries[i].unk_05 = value;
        reader->sub_0200D3B8(i, 5, &value);
        m_entries[i].unk_06 = value;
        reader->sub_0200D3B8(i, 6, &value);
        m_entries[i].unk_07 = value;
        reader->sub_0200D3B8(i, 7, &value);
        m_entries[i].unk_08 = value;
        reader->sub_0200D3B8(i, 8, &value);
        m_entries[i].unk_09 = value;
        reader->sub_0200D3B8(i, 9, &value);
        m_entries[i].unk_0A = value;
        reader->sub_0200D3B8(i, 10, &value);
        m_entries[i].unk_0B = value;
        reader->sub_0200D3B8(i, 11, &value);
        m_entries[i].unk_0C = value;
        reader->sub_0200D3B8(i, 12, &value);
        m_entries[i].unk_0E = value;
        reader->sub_0200D3B8(i, 13, &value);
        m_entries[i].unk_0F = value;
        reader->sub_0200D3B8(i, 14, &value);
        m_entries[i].unk_10 = value;
        reader->sub_0200D3B8(i, 15, &value);
        m_entries[i].unk_11 = value;
        reader->sub_0200D3B8(i, 16, &value);
        m_entries[i].unk_12 = value;
        reader->sub_0200D3B8(i, 17, &value);
        m_entries[i].unk_13 = value;
        reader->sub_0200D3B8(i, 18, &value);
        m_entries[i].unk_14 = value;
        reader->sub_0200D3B8(i, 19, &value);
        m_entries[i].unk_15 = value;
        reader->sub_0200D3B8(i, 20, &value);
        m_entries[i].unk_16 = value;
        reader->sub_0200D3B8(i, 21, &value);
        m_entries[i].unk_17 = value;
    }
    delete reader;
}

UnkClass_0212DC20::~UnkClass_0212DC20()
{
    if (m_entries != NULL) {
        delete[] m_entries;
        m_entries = NULL;
    }
}

UnkStruct_0212DFEC *UnkClass_0212DC20::ov1_0212DFEC(u16 id)
{
    if (id > m_count) {
        return NULL;
    }
    return &m_entries[id];
}

UnkClass_0212E008::UnkClass_0212E008(u32 arg0)
{
    UnkClass_0200D114 *reader = new UnkClass_0200D114(arg0);
    reader->sub_0200D148("data/param/BattleEffect.bin");
    m_count = reader->sub_0200D390();
    m_entries = new UnkStruct_0212E008[m_count];
    u32 value = 0;
    for (int i = 0; i < m_count; i++) {
        m_entries[i].unk_00 = i;
        reader->sub_0200D3B8(i, 1, &value);
        m_entries[i].unk_02 = value;
        reader->sub_0200D3B8(i, 2, &value);
        m_entries[i].unk_04 = value;
        reader->sub_0200D3B8(i, 3, &value);
        m_entries[i].unk_08 = value;
        reader->sub_0200D3B8(i, 4, &value);
        m_entries[i].unk_0C = value;
        reader->sub_0200D3B8(i, 5, &value);
        m_entries[i].unk_10 = value;
        reader->sub_0200D3B8(i, 6, &value);
        m_entries[i].unk_11 = value;
        reader->sub_0200D3B8(i, 7, &value);
        m_entries[i].unk_12 = value;
        reader->sub_0200D3B8(i, 8, &value);
        m_entries[i].unk_13 = value;
        reader->sub_0200D3B8(i, 9, &value);
        m_entries[i].unk_14 = value;
        reader->sub_0200D3B8(i, 10, &value);
        m_entries[i].unk_15 = value;
        reader->sub_0200D3B8(i, 11, &value);
        m_entries[i].unk_16 = value;
        reader->sub_0200D3B8(i, 12, &value);
        m_entries[i].unk_17 = value;
        reader->sub_0200D3B8(i, 13, &value);
        m_entries[i].unk_18 = value;
        reader->sub_0200D3B8(i, 14, &value);
        m_entries[i].unk_19 = value;
        reader->sub_0200D3B8(i, 15, &value);
        m_entries[i].unk_1A = value;
        reader->sub_0200D3B8(i, 16, &value);
        m_entries[i].unk_1B = value;
    }
    delete reader;
}

UnkClass_0212E008::~UnkClass_0212E008()
{
    if (m_entries != NULL) {
        delete[] m_entries;
        m_entries = NULL;
    }
}
