#include "UnkClass_02021404.hpp"

#include <nitro.h>

#include "file/CBinaryFileMes.hpp"

UnkClass_02021404::UnkClass_02021404(const char *path)
{
    Init();
    Load(path);
}

UnkClass_02021404::~UnkClass_02021404()
{
    Release();
}

void UnkClass_02021404::Release()
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

void UnkClass_02021404::Init()
{
    unk_00 = NULL;
}

void UnkClass_02021404::Load(const char *path)
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

const char *UnkClass_02021404::GetString(u32 index)
{
    if (unk_00 == NULL) {
        return "";
    }

    if (index >= unk_00->unk_04) {
        return NULL;
    }

    return (const char *)unk_00->unk_08[index].unk_04;
}

u32 UnkClass_02021404::GetCount()
{
    if (unk_00 == NULL) {
        return 0;
    }

    return unk_00->unk_04;
}
