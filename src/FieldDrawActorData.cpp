#include <nitro.h>

#include "CActorData.hpp"
#include "FieldDrawActorDataPool.hpp"
#include "VramPalette.hpp"
#include "common.hpp"
#include "field/CFieldDrawActorData.hpp"
#include "file/CArchiveGuard.hpp"
#include "heap.hpp"

CFieldDrawActorData::CFieldDrawActorData()
{
    unk_18 = -1;
    unk_1C = 0xFFFF;
    unk_1E = 0xFFFF;
    unk_20 = 0;
    unk_24 = 0;
    unk_28 = 1;
    unk_2C = 0;
    unk_30 = 0;
}

void CFieldDrawActorData::LoadData(int type, u16 id, int form, u16 mask, BOOL useTransfer, const char *arcName, BOOL alloc)
{
    if (type != 2) {
        if (useTransfer) {
            Load(type, id, form, mask, TRUE, arcName, 0);
        } else {
            LoadArchived(type, id, form, mask, arcName, 0, 1, useTransfer);
        }
    } else {
        sub_020409B4(id, form, mask, 0, arcName);
    }
    unk_18 = type;
    unk_1C = id;
    unk_1E = form;
    unk_28 = useTransfer;
    unk_20 = mask;
    if (alloc) {
        if (!useTransfer) {
            unk_2C = NNS_GfdAllocLnkTexVram(GetImagesSize(), FALSE, 0);
            LoadImagesToVram(NNS_GfdGetTexKeyAddr(unk_2C));
            ReleaseImages();
        }
        unk_30 = NNS_GfdAllocLnkPlttVram(GetPaletteSize(), FALSE, 0);
        if (useTransfer) {
            if (m_palette != NULL) {
                m_palette->LoadToVramDeferred(NNS_GfdGetPlttKeyAddr(unk_30));
            }
        } else {
            LoadPaletteToVram(NNS_GfdGetPlttKeyAddr(unk_30));
            ReleasePalette();
        }
    }
    SAFE_DELETE(m_archive);
}

void CFieldDrawActorData::sub_020409B4(u16 id, int form, u16 mask, u32 heapId, const char *arcName)
{
    char name[0x60];
    char path[0x60];
    char palettePath[0x60];
    char file[0x60];
    char base[0x60];
    char arc[4];
    NNSG2dPaletteData *paletteData;

    Release();

    int count = 0;
    for (int i = 0; i < 0x1D; i++) {
        if (mask & (1 << i)) {
            count++;
        }
    }
    if (count == 0) {
        return;
    }

    m_anims = (CActorAnim *)Heap_AllocWithAlignment(count * sizeof(CActorAnim), 4);
    MI_CpuClearFast(m_anims, count * sizeof(CActorAnim));
    m_animCount = count;
    unk_05 = 1;
    unk_06 = 1;
    OS_SPrintf(name, "t%03d_%02d", id, form);

    if (arcName != NULL) {
        STD_CopyString(arc, arcName);
    } else {
        STD_CopyString(arc, "ACT");
    }
    OS_SPrintf(path, "data/target/%s_LZ.bin", name);

    m_archive = new CArchiveGuard(arc, path, heapId == 0, 1, 0, NULL, 0);
    if (m_archive == NULL) {
        return;
    }

    OS_SPrintf(palettePath, "%s:%s.NCLR", arc, name);
    void *data = NNS_FndGetArchiveFileByName(palettePath);
    if (data != NULL && NNS_G2dGetUnpackedPaletteData(data, &paletteData)) {
        m_palette = new VramPalette(paletteData);
    }
    VramImage *image = NULL;
    OS_SPrintf(base, "%s:%s", arc, name);

    int index = 0;

    if (mask & 1) {
        OS_SPrintf(file, "%s:%s", arc, name);
        sub_02014CEC(&m_anims[index], file, heapId, FALSE);
        m_anims[index].id = 0;
        index++;
    }

    if (mask & 2) {
        OS_SPrintf(file, "%s:%s_s", arc, name);
        if (!sub_02014EA4(&m_anims[index], base, file, image, 0, FALSE)) {
            sub_02014CEC(&m_anims[index], file, heapId, FALSE);
        } else {
            image = m_anims[index].image;
        }
        m_anims[index].id = 1;
        index++;
    }

    if (mask & 4) {
        OS_SPrintf(file, "%s:%s_a", arc, name);
        if (!sub_02014EA4(&m_anims[index], base, file, image, 0, FALSE)) {
            sub_02014CEC(&m_anims[index], file, heapId, FALSE);
        } else {
            image = m_anims[index].image;
        }
        m_anims[index].id = 2;
        index++;
    }

    if (mask & 8) {
        OS_SPrintf(file, "%s:%s_c", arc, name);
        if (!sub_02014EA4(&m_anims[index], base, file, image, 0, FALSE)) {
            sub_02014CEC(&m_anims[index], file, heapId, FALSE);
        }
        m_anims[index].id = 3;
    }
}

void CFieldDrawActorData::Release()
{
    if (unk_24 <= 0) {
        return;
    }
    if (--unk_24 != 0) {
        return;
    }
    if (!unk_28) {
        NNS_GfdFreeLnkTexVram(unk_2C);
    }
    NNS_GfdFreeLnkPlttVram(unk_30);
    CActorData::Release();
    unk_18 = -1;
    unk_1C = 0xFFFF;
    unk_1E = 0xFFFF;
    unk_24 = 0;
    unk_28 = 1;
    unk_2C = 0;
    unk_30 = 0;
}

void CFieldDrawActorData::sub_02040DB8()
{
    if (!unk_28 && unk_2C != 0) {
        NNS_GfdFreeLnkTexVram(unk_2C);
    }
    if (unk_30 != 0) {
        NNS_GfdFreeLnkPlttVram(unk_30);
    }
    CActorData::Release();
    unk_24 = 0;
    unk_18 = -1;
    unk_1C = 0xFFFF;
    unk_1E = 0xFFFF;
    unk_24 = 0;
    unk_28 = 1;
    unk_2C = 0;
    unk_30 = 0;
}

void CFieldDrawActorData::AllocVram()
{
    ReleaseVram();
    if (!unk_28) {
        unk_2C = NNS_GfdAllocLnkTexVram(GetImagesSize(), FALSE, 0);
    }
    unk_30 = NNS_GfdAllocLnkPlttVram(GetPaletteSize(), FALSE, 0);
}

void CFieldDrawActorData::ReleaseVram()
{
    if (unk_2C != 0) {
        NNS_GfdFreeLnkTexVram(unk_2C);
        unk_2C = 0;
    }
    if (unk_30 != 0) {
        NNS_GfdFreeLnkPlttVram(unk_30);
        unk_30 = 0;
    }
}

void CFieldDrawActorData::LoadToVram()
{
    if (!unk_28) {
        LoadImagesToVram(NNS_GfdGetTexKeyAddr(unk_2C));
    }
    LoadPaletteToVram(NNS_GfdGetPlttKeyAddr(unk_30));
}

void CFieldDrawActorData::LoadPaletteDeferred()
{
    if (m_palette != NULL) {
        m_palette->LoadToVramDeferred(NNS_GfdGetPlttKeyAddr(unk_30));
    }
}

extern "C" {
void LogInfo(const char *fmt, ...);
}

FieldDrawActorDataPool::FieldDrawActorDataPool()
{
    MAIN_BSS_0210CA64 = this;
    m_count = 0x28;
    m_data = new CFieldDrawActorData[m_count];
}

FieldDrawActorDataPool::~FieldDrawActorDataPool()
{
    for (int i = 0; i < m_count; i++) {
        m_data[i].sub_02040DB8();
    }
    SAFE_DELETE_ARRAY(m_data);
    m_count = 0;
    MAIN_BSS_0210CA64 = NULL;
}

CFieldDrawActorData *FieldDrawActorDataPool::Acquire(int type, u16 id, int form, u16 mask, BOOL useTransfer)
{
    int i;
    for (i = 0; i < m_count; i++) {
        CFieldDrawActorData *data = &m_data[i];
        if (data->unk_24 > 0 && type == data->unk_18 && id == data->unk_1C && form == data->unk_1E && mask == data->unk_20 && useTransfer == data->unk_28) {
            data->unk_24++;
            return data;
        }
    }
    for (i = 0; i < m_count; i++) {
        CFieldDrawActorData *data = &m_data[i];
        if (data->unk_24 == 0) {
            char arc[4];
            OS_SPrintf(arc, "F%02d", i);
            data->LoadData(type, id, form, mask, useTransfer, arc, TRUE);
            data->unk_24 = 1;
            return data;
        }
    }
    LogInfo("NO EMPTY!! m_nActorDataMax = %d", m_count);
    return NULL;
}

CActorDataPartner::CActorDataPartner()
{
    unk_34 = 0;
}

CActorDataPartner::~CActorDataPartner()
{
    Release();
}

void CActorDataPartner::Release()
{
    if (unk_34 != 0) {
        sub_02040DB8();
        unk_34 = 0;
    }
}

void CActorDataPartner::AllocVram()
{
    if (!unk_28 && unk_2C == 0) {
        unk_2C = NNS_GfdAllocLnkTexVram(GetImagesSize(), FALSE, 0);
    }
    if (unk_30 == 0) {
        unk_30 = NNS_GfdAllocLnkPlttVram(GetPaletteSize(), FALSE, 0);
    }
}

void CActorDataPartner::sub_02041230(int type, u16 id, int form, u16 mask)
{
    if (unk_34 != 0) {
        Release();
    }
    LoadData(type, id, form, mask, TRUE, NULL, FALSE);
    unk_34 = 1;
}

void CActorDataPartner::ReleaseVram()
{
}
