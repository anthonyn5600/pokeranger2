#include "battle/BattleParamTable.hpp"

#include "ParamTableFile.hpp"

BattleParamTable::BattleParamTable(const char *path, u32 arg1)
{
    ParamTableFile *reader = new ParamTableFile(arg1);
    reader->Load(path);
    m_count = reader->sub_0200D390();
    m_entries = new UnkStruct_0212F310[m_count];
    u32 value = 0;
    for (int i = 0; i < m_count; i++) {
        reader->GetValue(i, 1, &value);
        m_entries[i].unk_00 = value;
        reader->GetValue(i, 2, &value);
        m_entries[i].unk_02 = value;
        reader->GetValue(i, 3, &value);
        m_entries[i].unk_04[0] = value;
        reader->GetValue(i, 4, &value);
        m_entries[i].unk_04[1] = value;
        reader->GetValue(i, 5, &value);
        m_entries[i].unk_04[2] = value;
        reader->GetValue(i, 6, &value);
        m_entries[i].unk_0A = value;
        reader->GetValue(i, 7, &value);
        m_entries[i].unk_0C[0] = value;
        reader->GetValue(i, 8, &value);
        m_entries[i].unk_0C[1] = value;
        reader->GetValue(i, 9, &value);
        m_entries[i].unk_0C[2] = value;
        reader->GetValue(i, 10, &value);
        m_entries[i].unk_12 = value;
        reader->GetValue(i, 11, &value);
        m_entries[i].unk_14 = value;
        reader->GetValue(i, 12, &value);
        m_entries[i].unk_16 = value;
        reader->GetValue(i, 13, &value);
        m_entries[i].unk_18 = value;
        reader->GetValue(i, 14, &value);
        m_entries[i].unk_1A[0] = value;
        reader->GetValue(i, 15, &value);
        m_entries[i].unk_1A[1] = value;
        reader->GetValue(i, 16, &value);
        m_entries[i].unk_1A[2] = value;
        reader->GetValue(i, 17, &value);
        m_entries[i].unk_20 = value;
        reader->GetValue(i, 18, &value);
        m_entries[i].unk_22 = value;
        reader->GetValue(i, 19, &value);
        m_entries[i].unk_24[0] = value;
        reader->GetValue(i, 20, &value);
        m_entries[i].unk_24[1] = value;
        reader->GetValue(i, 21, &value);
        m_entries[i].unk_24[2] = value;
        reader->GetValue(i, 22, &value);
        m_entries[i].unk_2A = value;
        reader->GetValue(i, 23, &value);
        m_entries[i].unk_2C[0] = value;
        reader->GetValue(i, 24, &value);
        m_entries[i].unk_2C[1] = value;
        reader->GetValue(i, 25, &value);
        m_entries[i].unk_2C[2] = value;
    }
    delete reader;
}

BattleParamTable::~BattleParamTable()
{
    if (m_entries != NULL) {
        delete[] m_entries;
        m_entries = NULL;
    }
}

UnkStruct_0212F310 *BattleParamTable::ov1_0212F310(int id)
{
    if (id > m_count) {
        return NULL;
    }
    return &m_entries[id];
}

u16 BattleParamTable::ov1_0212F32C(int kind, u16 id, u16 index)
{
    u16 result = 0;
    UnkStruct_0212F310 *entry = ov1_0212F310(id);
    switch (kind) {
    case 0:
        result = entry->unk_00;
        break;
    case 1:
        result = entry->unk_02;
        break;
    case 2:
        result = entry->unk_04[index];
        break;
    case 3:
        result = entry->unk_0A;
        break;
    case 4:
        break;
    case 5:
        result = entry->unk_0C[index];
        break;
    case 6:
        result = entry->unk_12;
        break;
    case 7:
        break;
    case 8:
        result = entry->unk_14;
        break;
    case 9:
        result = entry->unk_16;
        break;
    case 10:
        result = entry->unk_18;
        break;
    case 11:
        result = entry->unk_1A[index];
        break;
    case 12:
        result = entry->unk_20;
        break;
    case 13:
        result = entry->unk_22;
        break;
    case 14:
        result = entry->unk_24[index];
        break;
    case 15:
        result = entry->unk_2A;
        break;
    case 16:
        result = entry->unk_2C[index];
        break;
    case 17:
        break;
    }
    return result;
}
