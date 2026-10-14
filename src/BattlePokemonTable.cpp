#include "battle/BattlePokemonTable.hpp"

#include "ParamTableFile.hpp"
#include "battle/BattleEffectTable.hpp"

BattlePokemonTable::BattlePokemonTable(u32 arg0)
{
    ParamTableFile *reader = new ParamTableFile(arg0);
    reader->Load("data/param/BattlePokemon.bin");
    m_count = reader->sub_0200D390();
    m_entries = new UnkStruct_0212DFEC[m_count];
    u32 value = 0;
    for (int i = 0; i < m_count; i++) {
        reader->GetValue(i, 1, &value);
        m_entries[i].unk_04 = value;
        reader->GetValue(i, 2, &value);
        m_entries[i].unk_00 = value;
        reader->GetValue(i, 3, &value);
        m_entries[i].unk_02 = value;
        reader->GetValue(i, 4, &value);
        m_entries[i].unk_05 = value;
        reader->GetValue(i, 5, &value);
        m_entries[i].unk_06 = value;
        reader->GetValue(i, 6, &value);
        m_entries[i].unk_07 = value;
        reader->GetValue(i, 7, &value);
        m_entries[i].unk_08 = value;
        reader->GetValue(i, 8, &value);
        m_entries[i].unk_09 = value;
        reader->GetValue(i, 9, &value);
        m_entries[i].unk_0A = value;
        reader->GetValue(i, 10, &value);
        m_entries[i].unk_0B = value;
        reader->GetValue(i, 11, &value);
        m_entries[i].unk_0C = value;
        reader->GetValue(i, 12, &value);
        m_entries[i].unk_0E = value;
        reader->GetValue(i, 13, &value);
        m_entries[i].unk_0F = value;
        reader->GetValue(i, 14, &value);
        m_entries[i].unk_10 = value;
        reader->GetValue(i, 15, &value);
        m_entries[i].unk_11 = value;
        reader->GetValue(i, 16, &value);
        m_entries[i].unk_12 = value;
        reader->GetValue(i, 17, &value);
        m_entries[i].unk_13 = value;
        reader->GetValue(i, 18, &value);
        m_entries[i].unk_14 = value;
        reader->GetValue(i, 19, &value);
        m_entries[i].unk_15 = value;
        reader->GetValue(i, 20, &value);
        m_entries[i].unk_16 = value;
        reader->GetValue(i, 21, &value);
        m_entries[i].unk_17 = value;
    }
    delete reader;
}

BattlePokemonTable::~BattlePokemonTable()
{
    if (m_entries != NULL) {
        delete[] m_entries;
        m_entries = NULL;
    }
}

UnkStruct_0212DFEC *BattlePokemonTable::ov1_0212DFEC(u16 id)
{
    if (id > m_count) {
        return NULL;
    }
    return &m_entries[id];
}

BattleEffectTable::BattleEffectTable(u32 arg0)
{
    ParamTableFile *reader = new ParamTableFile(arg0);
    reader->Load("data/param/BattleEffect.bin");
    m_count = reader->sub_0200D390();
    m_entries = new UnkStruct_0212E008[m_count];
    u32 value = 0;
    for (int i = 0; i < m_count; i++) {
        m_entries[i].unk_00 = i;
        reader->GetValue(i, 1, &value);
        m_entries[i].unk_02 = value;
        reader->GetValue(i, 2, &value);
        m_entries[i].unk_04 = value;
        reader->GetValue(i, 3, &value);
        m_entries[i].unk_08 = value;
        reader->GetValue(i, 4, &value);
        m_entries[i].unk_0C = value;
        reader->GetValue(i, 5, &value);
        m_entries[i].unk_10 = value;
        reader->GetValue(i, 6, &value);
        m_entries[i].unk_11 = value;
        reader->GetValue(i, 7, &value);
        m_entries[i].unk_12 = value;
        reader->GetValue(i, 8, &value);
        m_entries[i].unk_13 = value;
        reader->GetValue(i, 9, &value);
        m_entries[i].unk_14 = value;
        reader->GetValue(i, 10, &value);
        m_entries[i].unk_15 = value;
        reader->GetValue(i, 11, &value);
        m_entries[i].unk_16 = value;
        reader->GetValue(i, 12, &value);
        m_entries[i].unk_17 = value;
        reader->GetValue(i, 13, &value);
        m_entries[i].unk_18 = value;
        reader->GetValue(i, 14, &value);
        m_entries[i].unk_19 = value;
        reader->GetValue(i, 15, &value);
        m_entries[i].unk_1A = value;
        reader->GetValue(i, 16, &value);
        m_entries[i].unk_1B = value;
    }
    delete reader;
}

BattleEffectTable::~BattleEffectTable()
{
    if (m_entries != NULL) {
        delete[] m_entries;
        m_entries = NULL;
    }
}
