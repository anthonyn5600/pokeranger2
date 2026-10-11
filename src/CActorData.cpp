#include "CActorData.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "UnkClass_02008788.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBinaryFile.hpp"
#include "file/CNCERFile.hpp"
#include "heap.hpp"

CActorData::CActorData()
{
    Init();
}

CActorData::CActorData(int type, int id, int form, u16 mask, BOOL releaseArchive, const char *arcName)
{
    Init();
    sub_02013154(type, id, form, mask, releaseArchive, arcName, 0);
}

CActorData::CActorData(const char *path, const char *name, int mask, BOOL releaseArchive, const char *arcName)
{
    Init();
    sub_020138E4(path, name, mask, releaseArchive, arcName);
}

CActorData::~CActorData()
{
    Release();
}

void CActorData::Init()
{
    m_palette = NULL;
    m_archive = NULL;
    m_anims = NULL;
    m_animCount = 0;
    unk_06 = 0;
}

void CActorData::sub_02013154(int type, int id, int form, u16 mask, BOOL releaseArchive, const char *arcName, u32 heapId)
{
    char name[0x60];
    char path[0x60];
    char palettePath[0x60];
    char file[0x60];
    char base[0x60];
    char arc[4];

    Release();

    int count = 0;
    for (int i = 0; i < 0x1D; i++) {
        int bit = 1 << i;
        if (mask & bit) {
            switch (bit) {
            case 0x10:
                count += 3;
                break;
            case 0x20:
                count += 12;
                break;
            default:
                count++;
                break;
            }
        }
    }
    if (count == 0) {
        return;
    }

    m_anims = (CActorAnim *)Heap_AllocWithAlignment(count * sizeof(CActorAnim), 4);
    MI_CpuClearFast(m_anims, count * sizeof(CActorAnim));
    m_animCount = count;

    switch (type) {
    case 0:
        unk_05 = 0;
        unk_06 = 0;
        OS_SPrintf(name, "p%03d_%02d", id, form);
        break;
    case 1:
        unk_05 = 1;
        unk_06 = 0;
        OS_SPrintf(name, "npc%03d", id);
        break;
    case 2:
        unk_05 = 1;
        unk_06 = 1;
        OS_SPrintf(name, "t%03d_%02d", id, form);
        break;
    case 3:
        unk_05 = 0;
        unk_06 = 0;
        OS_SPrintf(name, "e%03d", id);
        break;
    default:
        unk_05 = 1;
        unk_06 = 0;
        return;
    }

    if (arcName != NULL) {
        STD_CopyLString(arc, arcName, sizeof(arc));
    } else {
        STD_CopyString(arc, "ACT");
    }

    switch (type) {
    case 0:
        OS_SPrintf(path, "data/poke/%s_LZ.bin", name);
        break;
    case 1:
        OS_SPrintf(path, "data/npc/%s_LZ.bin", name);
        break;
    case 2:
        OS_SPrintf(path, "data/target/%s_LZ.bin", name);
        break;
    case 3:
        OS_SPrintf(path, "data/effect/%s_LZ.bin", name);
        break;
    }

    m_archive = new CArchiveGuard(arc, path, heapId == 0, 1, 0, NULL, 0);
    if (m_archive == NULL) {
        return;
    }

    OS_SPrintf(palettePath, "%s:%s.NCLR", arc, name);
    m_palette = new UnkClass_02007AA4(palettePath, 0, 0);
    UnkClass_020074D4 *image = NULL;
    OS_SPrintf(base, "%s:%s", arc, name);

    int index = 0;

    if (mask & 1) {
        OS_SPrintf(file, "%s:%s", arc, name);
        sub_02013CD4(&m_anims[index], file, heapId);
        m_anims[index].id = 0;
        index++;
    }

    if (mask & 2) {
        OS_SPrintf(file, "%s:%s_s", arc, name);
        if (unk_06) {
            if (!sub_02013E78(&m_anims[index], base, file, image, heapId)) {
                sub_02013CD4(&m_anims[index], file, heapId);
            } else {
                image = m_anims[index].image;
            }
        } else {
            sub_02013CD4(&m_anims[index], file, heapId);
        }
        m_anims[index].id = 1;
        index++;
    }

    if (mask & 4) {
        OS_SPrintf(file, "%s:%s_w", arc, name);
        if (unk_06) {
            if (!sub_02013E78(&m_anims[index], base, file, image, heapId)) {
                sub_02013CD4(&m_anims[index], file, heapId);
            } else {
                image = m_anims[index].image;
            }
        } else {
            sub_02013CD4(&m_anims[index], file, heapId);
        }
        m_anims[index].id = 2;
        index++;
    }

    if (mask & 8) {
        OS_SPrintf(file, "%s:%s_t", arc, name);
        if (unk_06) {
            if (!sub_02013E78(&m_anims[index], base, file, image, heapId)) {
                sub_02013CD4(&m_anims[index], file, heapId);
            }
        } else {
            sub_02013CD4(&m_anims[index], file, heapId);
        }
        m_anims[index].id = 3;
        index++;
    }

    if (mask & 0x10) {
        if (type != 1) {
            for (int i = 0; i < 0x1D; i++) {
                if (index >= m_animCount) {
                    break;
                }
                OS_SPrintf(file, "%s:%s_p%02d", arc, name, i + 1);
                if (!sub_02013CD4(&m_anims[index], file, heapId)) {
                    break;
                }
                m_anims[index].id = i + 4;
                index++;
            }
        } else {
            OS_SPrintf(file, "%s:%s_p", arc, name);
            sub_02013CD4(&m_anims[index], file, heapId);
            m_anims[index].id = 4;
            index++;
        }
    } else {
        int i = 0;
        for (int bit = 0x40; bit <= 0x100; bit <<= 1) {
            if (mask & bit) {
                OS_SPrintf(file, "%s:%s_p%02d", arc, name, i + 1);
                sub_02013CD4(&m_anims[index], file, heapId);
                m_anims[index].id = i + 4;
                index++;
            }
            i++;
        }
    }

    if (mask & 0x20) {
        for (int i = 0; i < 0x1D; i++) {
            if (index >= m_animCount) {
                break;
            }
            OS_SPrintf(file, "%s:%s_a%02d", arc, name, i + 1);
            if (!sub_02013CD4(&m_anims[index], file, heapId)) {
                break;
            }
            m_anims[index].id = i + 7;
            index++;
        }
    } else {
        int i = 0;
        for (int bit = 0x200; bit <= 0x1000; bit <<= 1) {
            if (mask & bit) {
                OS_SPrintf(file, "%s:%s_a%02d", arc, name, i + 1);
                sub_02013CD4(&m_anims[index], file, heapId);
                m_anims[index].id = i + 7;
                index++;
            }
            i++;
        }
    }

    if (releaseArchive) {
        SAFE_DELETE(m_archive);
    }
}

void CActorData::sub_020138E4(const char *path, const char *name, int mask, BOOL releaseArchive, const char *arcName)
{
    char nameBuf[0x60];
    char pathBuf[0x60];
    char palettePath[0x60];
    char file[0x60];
    char arc[4];

    Release();

    int count = 0;
    for (int i = 0; i < 0x1D; i++) {
        int bit = 1 << i;
        if (mask & bit) {
            switch (bit) {
            case 0x10:
                count += 3;
                break;
            case 0x20:
                count += 12;
                break;
            default:
                count++;
                break;
            }
        }
    }
    if (count == 0) {
        return;
    }

    m_anims = (CActorAnim *)Heap_AllocWithAlignment(count * sizeof(CActorAnim), 4);
    MI_CpuClearFast(m_anims, count * sizeof(CActorAnim));
    m_animCount = count;

    STD_CopyLString(nameBuf, name, sizeof(nameBuf));
    if (arcName != NULL) {
        STD_CopyLString(arc, arcName, sizeof(arc));
    } else {
        STD_CopyString(arc, "ACT");
    }
    STD_CopyLString(pathBuf, path, sizeof(pathBuf));

    m_archive = new CArchiveGuard(arc, pathBuf, 1, 1, 0, NULL, 0);
    if (m_archive == NULL) {
        return;
    }

    OS_SPrintf(palettePath, "%s:%s.NCLR", arc, nameBuf);
    m_palette = new UnkClass_02007AA4(palettePath, 0, 0);

    int index = 0;

    if (mask & 1) {
        OS_SPrintf(file, "%s:%s", arc, nameBuf);
        sub_02013CD4(&m_anims[index], file, 0);
        m_anims[index].id = 0;
        index++;
    }

    if (mask & 2) {
        OS_SPrintf(file, "%s:%s_s", arc, nameBuf);
        sub_02013CD4(&m_anims[index], file, 0);
        m_anims[index].id = 1;
        index++;
    }

    if (mask & 4) {
        OS_SPrintf(file, "%s:%s_w", arc, nameBuf);
        sub_02013CD4(&m_anims[index], file, 0);
        m_anims[index].id = 2;
        index++;
    }

    if (mask & 8) {
        OS_SPrintf(file, "%s:%s_t", arc, nameBuf);
        sub_02013CD4(&m_anims[index], file, 0);
        m_anims[index].id = 3;
        index++;
    }

    if (mask & 0x10) {
        for (int i = 0; i < 0x1D; i++) {
            if (index >= m_animCount) {
                break;
            }
            OS_SPrintf(file, "%s:%s_p%02d", arc, nameBuf, i + 1);
            if (!sub_02013CD4(&m_anims[index], file, 0)) {
                break;
            }
            m_anims[index].id = i + 4;
            index++;
        }
    }

    if (mask & 0x20) {
        for (int i = 0; i < 0x1D; i++) {
            if (index >= m_animCount) {
                break;
            }
            OS_SPrintf(file, "%s:%s_a%02d", arc, nameBuf, i + 1);
            if (!sub_02013CD4(&m_anims[index], file, 0)) {
                break;
            }
            m_anims[index].id = i + 7;
            index++;
        }
    }

    if (releaseArchive) {
        SAFE_DELETE(m_archive);
    }
}

BOOL CActorData::sub_02013CD4(CActorAnim *anim, const char *base, u32 heapId)
{
    char imagePath[0x60];
    char cellPath[0x60];
    char animPath[0x60];

    OS_SPrintf(imagePath, "%s.NCBR", base);
    if (!CBinaryFile::sub_02003108(imagePath, 0)) {
        return FALSE;
    }
    OS_SPrintf(cellPath, "%s.NCER", base);
    if (!CBinaryFile::sub_02003108(cellPath, 0)) {
        return FALSE;
    }
    OS_SPrintf(animPath, "%s.cac", base);
    if (!CBinaryFile::sub_02003108(animPath, 0)) {
        return FALSE;
    }

    SAFE_DELETE(anim->image);
    anim->image = new UnkClass_020074D4(imagePath, 0, 0, heapId);
    SAFE_DELETE(anim->cells);
    anim->cells = new CNCERFile(cellPath, heapId, 0, 0);
    SAFE_DELETE(anim->bank);
    anim->bank = new UnkClass_02008788();
    anim->bank->sub_0200887C(animPath, 0, heapId);
    anim->flags |= 1;
    return TRUE;
}

BOOL CActorData::sub_02013E78(CActorAnim *anim, const char *imageBase, const char *base, UnkClass_020074D4 *image, u32 heapId)
{
    char imagePath[0x60];
    char cellPath[0x60];
    char animPath[0x60];

    OS_SPrintf(imagePath, "%s.NCBR", imageBase);
    if (!CBinaryFile::sub_02003108(imagePath, 0) && image == NULL) {
        return FALSE;
    }
    OS_SPrintf(cellPath, "%s.NCER", base);
    if (!CBinaryFile::sub_02003108(cellPath, 0)) {
        return FALSE;
    }
    OS_SPrintf(animPath, "%s.cac", base);
    if (!CBinaryFile::sub_02003108(animPath, 0)) {
        return FALSE;
    }

    SAFE_DELETE(anim->image);
    if (image != NULL) {
        anim->image = image;
    } else {
        anim->image = new UnkClass_020074D4(imagePath, 0, 0, heapId);
    }
    SAFE_DELETE(anim->cells);
    anim->cells = new CNCERFile(cellPath, heapId, 0, 0);
    SAFE_DELETE(anim->bank);
    anim->bank = new UnkClass_02008788();
    anim->bank->sub_0200887C(animPath, 0, heapId);
    anim->flags |= 1;
    return TRUE;
}

void CActorData::Release()
{
    SAFE_DELETE(m_palette);

    UnkClass_020074D4 *first = NULL;
    for (int i = 0; i < m_animCount; i++) {
        m_anims[i].flags &= ~1;
        UnkClass_020074D4 *image = m_anims[i].image;
        if (first != image) {
            if (first == NULL) {
                first = image;
            }
            SAFE_DELETE(m_anims[i].image);
        } else {
            m_anims[i].image = NULL;
        }
        SAFE_DELETE(m_anims[i].cells);
        SAFE_DELETE(m_anims[i].bank);
    }

    if (m_anims != NULL) {
        Heap_Free(m_anims);
        m_anims = NULL;
    }
    m_animCount = 0;
    SAFE_DELETE(m_archive);
    unk_06 = 0;
}

void CActorData::sub_020141AC(u32 addr)
{
    for (int i = 0; i < m_animCount; i++) {
        if (m_anims[i].image != NULL) {
            m_anims[i].image->sub_020076E8(addr);
            addr += m_anims[i].image->unk_38;
            if (unk_06) {
                return;
            }
        }
    }
}

void CActorData::sub_02014218(NNSGfdTexKey *keys)
{
    for (int i = 0; i < m_animCount; i++) {
        if (m_anims[i].image != NULL) {
            keys[i] = NNS_GfdAllocLnkTexVram(m_anims[i].image->unk_38, FALSE, 0);
            m_anims[i].image->sub_020076E8(NNS_GfdGetTexKeyAddr(keys[i]));
            if (unk_06) {
                return;
            }
        }
    }
}

void CActorData::sub_0201429C(u32 addr)
{
    if (m_palette != NULL) {
        m_palette->sub_02007BFC(addr);
    }
}

void CActorData::sub_020142B4()
{
    for (int i = 0; i < m_animCount; i++) {
        if (m_anims[i].image != NULL) {
            m_anims[i].image->sub_020076B0();
        }
    }
}

void CActorData::sub_020142F8()
{
    if (m_palette != NULL) {
        m_palette->sub_02007BC4();
    }
}

u32 CActorData::sub_02014310()
{
    u32 size = 0;
    for (int i = 0; i < m_animCount; i++) {
        if (m_anims[i].image != NULL) {
            size += m_anims[i].image->unk_38;
            if (unk_06) {
                break;
            }
        }
    }
    return size;
}

u32 CActorData::sub_02014364()
{
    return m_palette != NULL ? m_palette->unk_04->szByte : 0;
}

CActorAnim *CActorData::GetAnim(u8 id)
{
    for (int i = 0; i < m_animCount; i++) {
        if (id == m_anims[i].id) {
            return &m_anims[i];
        }
    }
    return NULL;
}

CActorAnim *CActorData::sub_020143B8(int action, u32 sub)
{
    u8 id = GetAnimId(action, sub);
    if (id == 0xFF) {
        return NULL;
    }
    for (int i = 0; i < m_animCount; i++) {
        if (id == m_anims[i].id) {
            return &m_anims[i];
        }
    }
    return NULL;
}

u8 CActorData::GetAnimId(int action, u32 sub)
{
    u8 id = 0;

    switch (action) {
    case 1:
        id = 0;
        break;
    case 2:
        id = 1;
        break;
    case 4:
        id = 2;
        break;
    case 0x10:
        if (sub >= 3) {
            id = 0xFF;
        } else {
            id = sub + 4;
        }
        break;
    case 0x20:
        if (sub >= 12) {
            id = 0xFF;
        } else {
            id = sub + 7;
        }
        break;
    case 8:
        id = 3;
        break;
    case 0x40:
        id = 4;
        break;
    case 0x80:
        id = 5;
        break;
    case 0x100:
        id = 6;
        break;
    case 0x200:
        id = 7;
        break;
    case 0x400:
        id = 8;
        break;
    case 0x800:
        id = 9;
        break;
    case 0x1000:
        id = 10;
        break;
    }

    return id;
}

void CActorData::sub_02014514(int type, int id, int form, u16 mask, const char *arcName, u32 heapId, u32 archiveArg, BOOL fromArchive)
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
        int bit = 1 << i;
        if (mask & bit) {
            switch (bit) {
            case 0x10:
                count += 3;
                break;
            case 0x20:
                count += 12;
                break;
            default:
                count++;
                break;
            }
        }
    }
    if (count == 0) {
        return;
    }

    m_anims = (CActorAnim *)Heap_AllocWithAlignment(count * sizeof(CActorAnim), 4);
    MI_CpuClearFast(m_anims, count * sizeof(CActorAnim));
    m_animCount = count;

    switch (type) {
    case 0:
        unk_05 = 0;
        unk_06 = 0;
        OS_SPrintf(name, "p%03d_%02d", id, form);
        break;
    case 1:
        unk_05 = 1;
        unk_06 = 0;
        OS_SPrintf(name, "npc%03d", id);
        break;
    case 2:
        unk_05 = 1;
        unk_06 = 1;
        OS_SPrintf(name, "t%03d_%02d", id, form);
        break;
    case 3:
        unk_05 = 0;
        unk_06 = 0;
        OS_SPrintf(name, "e%03d", id);
        break;
    default:
        unk_05 = 1;
        unk_06 = 0;
        return;
    }

    if (arcName != NULL) {
        STD_CopyLString(arc, arcName, sizeof(arc));
    } else {
        STD_CopyString(arc, "ACT");
    }

    switch (type) {
    case 0:
        OS_SPrintf(path, "data/poke/%s_LZ.bin", name);
        break;
    case 1:
        OS_SPrintf(path, "data/npc/%s_LZ.bin", name);
        break;
    case 2:
        OS_SPrintf(path, "data/target/%s_LZ.bin", name);
        break;
    case 3:
        OS_SPrintf(path, "data/effect/%s_LZ.bin", name);
        break;
    }

    m_archive = new CArchiveGuard(arc, path, archiveArg, 1, 0, NULL, 0);
    if (m_archive == NULL) {
        return;
    }

    OS_SPrintf(palettePath, "%s:%s.NCLR", arc, name);
    if (fromArchive) {
        void *file = NNS_FndGetArchiveFileByName(palettePath);
        if (file != NULL && NNS_G2dGetUnpackedPaletteData(file, &paletteData)) {
            m_palette = new UnkClass_02007AA4(paletteData);
        }
    } else {
        m_palette = new UnkClass_02007AA4(palettePath, 0, 0);
    }
    UnkClass_020074D4 *image = NULL;
    OS_SPrintf(base, "%s:%s", arc, name);

    int index = 0;

    if (mask & 1) {
        OS_SPrintf(file, "%s:%s", arc, name);
        sub_02014CEC(&m_anims[index], file, heapId, fromArchive);
        m_anims[index].id = 0;
        index++;
    }

    if (mask & 2) {
        OS_SPrintf(file, "%s:%s_s", arc, name);
        if (unk_06) {
            if (!sub_02014EA4(&m_anims[index], base, file, image, heapId, fromArchive)) {
                sub_02014CEC(&m_anims[index], file, heapId, fromArchive);
            } else {
                image = m_anims[index].image;
            }
        } else {
            sub_02014CEC(&m_anims[index], file, heapId, fromArchive);
        }
        m_anims[index].id = 1;
        index++;
    }

    if (mask & 4) {
        OS_SPrintf(file, "%s:%s_w", arc, name);
        if (unk_06) {
            if (!sub_02014EA4(&m_anims[index], base, file, image, heapId, fromArchive)) {
                sub_02014CEC(&m_anims[index], file, heapId, fromArchive);
            } else {
                image = m_anims[index].image;
            }
        } else {
            sub_02014CEC(&m_anims[index], file, heapId, fromArchive);
        }
        m_anims[index].id = 2;
        index++;
    }

    if (mask & 8) {
        OS_SPrintf(file, "%s:%s_t", arc, name);
        if (unk_06) {
            if (!sub_02014EA4(&m_anims[index], base, file, image, heapId, fromArchive)) {
                sub_02014CEC(&m_anims[index], file, heapId, fromArchive);
            }
        } else {
            sub_02014CEC(&m_anims[index], file, heapId, fromArchive);
        }
        m_anims[index].id = 3;
        index++;
    }

    if (mask & 0x10) {
        if (type != 1) {
            for (int i = 0; i < 0x1D; i++) {
                if (index >= m_animCount) {
                    break;
                }
                OS_SPrintf(file, "%s:%s_p%02d", arc, name, i + 1);
                if (!sub_02014CEC(&m_anims[index], file, heapId, fromArchive)) {
                    break;
                }
                m_anims[index].id = i + 4;
                index++;
            }
        } else {
            OS_SPrintf(file, "%s:%s_p", arc, name);
            sub_02014CEC(&m_anims[index], file, heapId, fromArchive);
            m_anims[index].id = 4;
            index++;
        }
    } else {
        int i = 0;
        for (int bit = 0x40; bit <= 0x100; bit <<= 1) {
            if (mask & bit) {
                OS_SPrintf(file, "%s:%s_p%02d", arc, name, i + 1);
                sub_02014CEC(&m_anims[index], file, heapId, fromArchive);
                m_anims[index].id = i + 4;
                index++;
            }
            i++;
        }
    }

    if (mask & 0x20) {
        for (int i = 0; i < 0x1D; i++) {
            if (index >= m_animCount) {
                break;
            }
            OS_SPrintf(file, "%s:%s_a%02d", arc, name, i + 1);
            if (!sub_02014CEC(&m_anims[index], file, heapId, fromArchive)) {
                break;
            }
            m_anims[index].id = i + 7;
            index++;
        }
    } else {
        int i = 0;
        for (int bit = 0x200; bit <= 0x1000; bit <<= 1) {
            if (mask & bit) {
                OS_SPrintf(file, "%s:%s_a%02d", arc, name, i + 1);
                sub_02014CEC(&m_anims[index], file, heapId, fromArchive);
                m_anims[index].id = i + 7;
                index++;
            }
            i++;
        }
    }
}

BOOL CActorData::sub_02014CEC(CActorAnim *anim, const char *base, u32 heapId, BOOL arg3)
{
    char imagePath[0x60];
    char cellPath[0x60];
    char animPath[0x60];
    NNSG2dCharacterData *charData;

    OS_SPrintf(imagePath, "%s.NCBR", base);
    if (!CBinaryFile::sub_02003108(imagePath, 0)) {
        return FALSE;
    }
    OS_SPrintf(cellPath, "%s.NCER", base);
    if (!CBinaryFile::sub_02003108(cellPath, 0)) {
        return FALSE;
    }
    OS_SPrintf(animPath, "%s.cac", base);
    if (!CBinaryFile::sub_02003108(animPath, 0)) {
        return FALSE;
    }

    SAFE_DELETE(anim->image);
    void *file = NNS_FndGetArchiveFileByName(imagePath);
    if (file != NULL && NNS_G2dGetUnpackedCharacterData(file, &charData)) {
        anim->image = new UnkClass_020074D4(charData);
    }
    SAFE_DELETE(anim->cells);
    anim->cells = new CNCERFile(cellPath, heapId, 0, 0);
    SAFE_DELETE(anim->bank);
    anim->bank = new UnkClass_02008788();
    anim->bank->sub_0200887C(animPath, 0, heapId);
    anim->flags |= 1;
    return TRUE;
}

BOOL CActorData::sub_02014EA4(CActorAnim *anim, const char *imageBase, const char *base, UnkClass_020074D4 *image, u32 heapId, BOOL arg5)
{
    char imagePath[0x60];
    char cellPath[0x60];
    char animPath[0x60];
    NNSG2dCharacterData *charData;

    OS_SPrintf(imagePath, "%s.NCBR", imageBase);
    if (!CBinaryFile::sub_02003108(imagePath, 0) && image == NULL) {
        return FALSE;
    }
    OS_SPrintf(cellPath, "%s.NCER", base);
    if (!CBinaryFile::sub_02003108(cellPath, 0)) {
        return FALSE;
    }
    OS_SPrintf(animPath, "%s.cac", base);
    if (!CBinaryFile::sub_02003108(animPath, 0)) {
        return FALSE;
    }

    SAFE_DELETE(anim->image);
    if (image != NULL) {
        anim->image = image;
    } else {
        void *file = NNS_FndGetArchiveFileByName(imagePath);
        if (file != NULL && NNS_G2dGetUnpackedCharacterData(file, &charData)) {
            anim->image = new UnkClass_020074D4(charData);
        }
    }
    SAFE_DELETE(anim->cells);
    anim->cells = new CNCERFile(cellPath, heapId, 0, 0);
    SAFE_DELETE(anim->bank);
    anim->bank = new UnkClass_02008788();
    anim->bank->sub_0200887C(animPath, 0, heapId);
    anim->flags |= 1;
    return TRUE;
}

int CActorData::sub_02015070(u8 id)
{
    for (int i = 0; i < m_animCount; i++) {
        if (id == m_anims[i].id) {
            return i;
        }
    }
    return -1;
}

CActorAnim *CActorData::GetAnimAt(int index)
{
    return &m_anims[index];
}
