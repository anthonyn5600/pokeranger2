#include "NameTables.hpp"

#include <nitro.h>

#include "file/CBinaryFileMes.hpp"

NameTables::NameTables()
{
    unk_00 = NULL;
    unk_04 = NULL;
    unk_08 = NULL;
    unk_0C = NULL;
    LoadPokemonNames();
    LoadItemNames();
    LoadYakumonoNames();
    LoadNpcNames();
    LoadFieldMoveNames();
}

UnkClass_020091E8_004 *NameTables::LoadPokemonNames()
{
    if (unk_00 != NULL) {
        FreePokemonNames();
    }

    CBinaryFileMes *file = new CBinaryFileMes("/data/message/etc/pokemon_name", 1);

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
    return unk_00;
}

void NameTables::FreePokemonNames()
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

UnkClass_020091E8_004 *NameTables::LoadItemNames()
{
    if (unk_04 != NULL) {
        FreeItemNames();
    }

    CBinaryFileMes *file = new CBinaryFileMes("/data/message/etc/item_name", 1);

    unk_04 = new UnkClass_020091E8_004();
    u32 pos = 2;
    unk_04->unk_00 = ((u32 *)file->unk_4C)[0];
    unk_04->unk_04 = ((u32 *)file->unk_4C)[1];
    unk_04->unk_08 = new UnkClass_020091E8_004_08[unk_04->unk_04];

    for (u32 i = 0; i < unk_04->unk_04; ++i) {
        unk_04->unk_08[i].unk_00 = ((u32 *)file->unk_4C)[pos];
        ++pos;

        unk_04->unk_08[i].unk_04 = new u8[unk_04->unk_08[i].unk_00];
        MI_CpuCopyFast(&((u32 *)file->unk_4C)[pos], unk_04->unk_08[i].unk_04, unk_04->unk_08[i].unk_00);

        pos += unk_04->unk_08[i].unk_00 / 4;
    }

    delete file;
    return unk_04;
}

void NameTables::FreeItemNames()
{
    if (unk_04 == NULL) {
        return;
    }

    for (u32 i = 0; i < unk_04->unk_04; ++i) {
        if (unk_04->unk_08[i].unk_04 != NULL) {
            delete[] unk_04->unk_08[i].unk_04;
            unk_04->unk_08[i].unk_04 = NULL;
        }
    }

    if (unk_04->unk_08 != NULL) {
        delete[] unk_04->unk_08;
        unk_04->unk_08 = NULL;
    }

    if (unk_04 != NULL) {
        delete unk_04;
        unk_04 = NULL;
    }
}

UnkClass_020091E8_004 *NameTables::LoadYakumonoNames()
{
    if (unk_08 != NULL) {
        FreeYakumonoNames();
    }

    CBinaryFileMes *file = new CBinaryFileMes("/data/message/etc/yakumono_name", 1);

    unk_08 = new UnkClass_020091E8_004();
    u32 pos = 2;
    unk_08->unk_00 = ((u32 *)file->unk_4C)[0];
    unk_08->unk_04 = ((u32 *)file->unk_4C)[1];
    unk_08->unk_08 = new UnkClass_020091E8_004_08[unk_08->unk_04];

    for (u32 i = 0; i < unk_08->unk_04; ++i) {
        unk_08->unk_08[i].unk_00 = ((u32 *)file->unk_4C)[pos];
        ++pos;

        unk_08->unk_08[i].unk_04 = new u8[unk_08->unk_08[i].unk_00];
        MI_CpuCopyFast(&((u32 *)file->unk_4C)[pos], unk_08->unk_08[i].unk_04, unk_08->unk_08[i].unk_00);

        pos += unk_08->unk_08[i].unk_00 / 4;
    }

    delete file;
    return unk_08;
}

void NameTables::FreeYakumonoNames()
{
    if (unk_08 == NULL) {
        return;
    }

    for (u32 i = 0; i < unk_08->unk_04; ++i) {
        if (unk_08->unk_08[i].unk_04 != NULL) {
            delete[] unk_08->unk_08[i].unk_04;
            unk_08->unk_08[i].unk_04 = NULL;
        }
    }

    if (unk_08->unk_08 != NULL) {
        delete[] unk_08->unk_08;
        unk_08->unk_08 = NULL;
    }

    if (unk_08 != NULL) {
        delete unk_08;
        unk_08 = NULL;
    }
}

UnkClass_020091E8_004 *NameTables::LoadNpcNames()
{
    if (unk_0C != NULL) {
        FreeNpcNames();
    }

    CBinaryFileMes *file = new CBinaryFileMes("/data/message/etc/npc_name", 1);

    unk_0C = new UnkClass_020091E8_004();
    u32 pos = 2;
    unk_0C->unk_00 = ((u32 *)file->unk_4C)[0];
    unk_0C->unk_04 = ((u32 *)file->unk_4C)[1];
    unk_0C->unk_08 = new UnkClass_020091E8_004_08[unk_0C->unk_04];

    for (u32 i = 0; i < unk_0C->unk_04; ++i) {
        unk_0C->unk_08[i].unk_00 = ((u32 *)file->unk_4C)[pos];
        ++pos;

        unk_0C->unk_08[i].unk_04 = new u8[unk_0C->unk_08[i].unk_00];
        MI_CpuCopyFast(&((u32 *)file->unk_4C)[pos], unk_0C->unk_08[i].unk_04, unk_0C->unk_08[i].unk_00);

        pos += unk_0C->unk_08[i].unk_00 / 4;
    }

    delete file;
    return unk_0C;
}

void NameTables::FreeNpcNames()
{
    if (unk_0C == NULL) {
        return;
    }

    for (u32 i = 0; i < unk_0C->unk_04; ++i) {
        if (unk_0C->unk_08[i].unk_04 != NULL) {
            delete[] unk_0C->unk_08[i].unk_04;
            unk_0C->unk_08[i].unk_04 = NULL;
        }
    }

    if (unk_0C->unk_08 != NULL) {
        delete[] unk_0C->unk_08;
        unk_0C->unk_08 = NULL;
    }

    if (unk_0C != NULL) {
        delete unk_0C;
        unk_0C = NULL;
    }
}

UnkClass_020091E8_004 *NameTables::LoadFieldMoveNames()
{
    if (unk_10 != NULL) {
        FreeFieldMoveNames();
    }

    CBinaryFileMes *file = new CBinaryFileMes("/data/message/etc/fieldwaza_name", 1);

    unk_10 = new UnkClass_020091E8_004();
    u32 pos = 2;
    unk_10->unk_00 = ((u32 *)file->unk_4C)[0];
    unk_10->unk_04 = ((u32 *)file->unk_4C)[1];
    unk_10->unk_08 = new UnkClass_020091E8_004_08[unk_10->unk_04];

    for (u32 i = 0; i < unk_10->unk_04; ++i) {
        unk_10->unk_08[i].unk_00 = ((u32 *)file->unk_4C)[pos];
        ++pos;

        unk_10->unk_08[i].unk_04 = new u8[unk_10->unk_08[i].unk_00];
        MI_CpuCopyFast(&((u32 *)file->unk_4C)[pos], unk_10->unk_08[i].unk_04, unk_10->unk_08[i].unk_00);

        pos += unk_10->unk_08[i].unk_00 / 4;
    }

    delete file;
    return unk_10;
}

void NameTables::FreeFieldMoveNames()
{
    if (unk_10 == NULL) {
        return;
    }

    for (u32 i = 0; i < unk_10->unk_04; ++i) {
        if (unk_10->unk_08[i].unk_04 != NULL) {
            delete[] unk_10->unk_08[i].unk_04;
            unk_10->unk_08[i].unk_04 = NULL;
        }
    }

    if (unk_10->unk_08 != NULL) {
        delete[] unk_10->unk_08;
        unk_10->unk_08 = NULL;
    }

    if (unk_10 != NULL) {
        delete unk_10;
        unk_10 = NULL;
    }
}

extern "C" u8 *NameTables_GetPokemonName(NameTables *obj, u32 i)
{
    if (obj->unk_00 == NULL) {
        return NULL;
    }
    return obj->unk_00->unk_08[i].unk_04;
}

extern "C" u8 *NameTables_GetItemName(NameTables *obj, u32 i)
{
    if (obj->unk_04 == NULL) {
        return NULL;
    }
    return obj->unk_04->unk_08[i].unk_04;
}

extern "C" u8 *NameTables_GetYakumonoName(NameTables *obj, u32 i)
{
    if (obj->unk_08 == NULL) {
        return NULL;
    }
    return obj->unk_08->unk_08[i].unk_04;
}

extern "C" u8 *NameTables_GetNpcName(NameTables *obj, u32 i)
{
    if (obj->unk_0C == NULL) {
        return NULL;
    }
    return obj->unk_0C->unk_08[i].unk_04;
}

extern "C" u8 *NameTables_GetFieldMoveName(NameTables *obj, u32 i)
{
    if (obj->unk_10 == NULL) {
        return NULL;
    }
    return obj->unk_10->unk_08[i].unk_04;
}
