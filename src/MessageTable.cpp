#include "MessageTable.hpp"

#include <nitro.h>

#include "file/CBinaryFileMes.hpp"

MessageTable::MessageTable(const char *path)
{
    Init();
    Load(path);
}

MessageTable::~MessageTable()
{
    Release();
}

void MessageTable::Release()
{
    if (unk_00 == NULL) {
        return;
    }

    for (u32 i = 0; i < unk_00->unk_04; ++i) {
        if (unk_00->unk_08[i].unk_04 != NULL) {
            delete[] unk_00->unk_08[i].unk_04;
            unk_00->unk_08[i].unk_04 = NULL;
        }
    }

    if (unk_00->unk_08 != NULL) {
        delete[] unk_00->unk_08;
        unk_00->unk_08 = NULL;
    }

    if (unk_00 != NULL) {
        delete unk_00;
        unk_00 = NULL;
    }
}

void MessageTable::Init()
{
    unk_00 = NULL;
}

void MessageTable::Load(const char *path)
{
    Release();

    CBinaryFileMes *file = new CBinaryFileMes(path, 1);

    unk_00 = new UnkClass_020091E8_004();
    u32 pos = 2;
    unk_00->unk_00 = ((u32 *)file->unk_4C)[0];
    unk_00->unk_04 = ((u32 *)file->unk_4C)[1];
    unk_00->unk_08 = new UnkClass_020091E8_004_08[unk_00->unk_04];

    for (u32 i = 0; i < unk_00->unk_04; ++i) {
        unk_00->unk_08[i].unk_00 = ((u32 *)file->unk_4C)[pos];
        ++pos;

        unk_00->unk_08[i].unk_04 = new u8[unk_00->unk_08[i].unk_00];
        MI_CpuCopyFast(&((u32 *)file->unk_4C)[pos], unk_00->unk_08[i].unk_04, unk_00->unk_08[i].unk_00);

        pos += unk_00->unk_08[i].unk_00 / 4;
    }

    delete file;
}

const char *MessageTable::GetString(u32 index)
{
    if (unk_00 == NULL) {
        return "";
    }

    if (index >= unk_00->unk_04) {
        return NULL;
    }

    return (const char *)unk_00->unk_08[index].unk_04;
}

u32 MessageTable::GetCount()
{
    if (unk_00 == NULL) {
        return 0;
    }

    return unk_00->unk_04;
}
