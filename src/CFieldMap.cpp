#include "field/CFieldMap.hpp"

#include <nitro.h>
#include <string.h>

#include "CGame.hpp"
#include "UnkClass_02003718.hpp"
#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "field/CFieldMapLayer.hpp"
#include "file/CBinaryFile.hpp"
#include "heap.hpp"

extern "C" {
void LogError(const char *fmt, ...);
void sub_02044AC8(void *script);
void sub_02044B48(UnkStruct_02044464 *vm, void *stack, u32 stackSize);
void sub_02044B78(UnkStruct_02044464 *vm);
int sub_02044C9C(UnkStruct_02044464 *vm, u32 steps);
int sub_02045A18(UnkStruct_02044464 *vm, void *script, const char *name);
void ov0_0212F86C(UnkClass_0212F82C *obj, void *data);
void ov0_0212FE54(UnkClass_0212F82C *obj, int fps);
void ov0_0212FF30(UnkClass_0212FEDC *obj, void *data);
void ov0_02130030(UnkClass_0212FEDC *obj, int fps);
void ov0_021300C8(UnkClass_0212FEDC *obj);
void ov0_0213033C(UnkClass_021302BC *tex, UnkClass_020074D4 *image, NNSGfdTexKey key);
void ov0_02130404(UnkClass_021302BC *tex, UnkClass_02007AA4 *palette, NNSGfdPlttKey key, void *data);
}

extern CFieldMap *MAIN_BSS_0210CA54;

// The original TU also has the chunk tags ("TEX", "TXIF", "RLCN", "MLY", "PLA", "MPIF", "CTA", "RGCN", "LYR") as
// 4-byte strings in .rodata, right after the "MTP" initializer. Nothing references them and their source form is
// unknown, so they're still at the start of the next asm file's .rodata.

CFieldMap::CFieldMap()
{
    MAIN_BSS_0210CA54 = this;
    unk_00 = FALSE;
    unk_20 = NULL;
    unk_24 = 0;
    unk_28 = NULL;
    unk_34 = NULL;
    unk_38 = NULL;
    unk_10 = NULL;
    unk_14 = 0;
    unk_18 = NULL;
    unk_1C = 0;
    m_info.size.width = 0;
    m_info.size.height = 0;
    unk_4C = NULL;
    unk_78 = NULL;
    unk_7C = Heap_AllocWithAlignment(0x200, 4);
    unk_50 = 2;
    unk_04 = NULL;
    unk_08 = 0;
    unk_0C = 0;
}

CFieldMap::~CFieldMap()
{
    ov0_02124EE4();
    if (unk_7C != NULL) {
        Heap_Free(unk_7C);
        unk_7C = NULL;
    }
    MAIN_BSS_0210CA54 = NULL;
}

void CFieldMap::ov0_02124D98(const char *name)
{
    char path[0x80];
    ov0_02124E9C();
    u32 heapId = s_game->unk_14A8;
    OS_SPrintf(path, "data/Script/field/map/%s", name);
    unk_4C = new CBinaryFile(path, 0, 0, heapId, NULL, 0);
    unk_78 = unk_4C->unk_4C;
    sub_02044AC8(unk_78);
    if (unk_78 != NULL) {
        sub_02044B48(&unk_54, unk_7C, 0x80);
    } else {
        LogError("ScriptBlock ==  NULL by FieldMap.cpp");
    }
}

void CFieldMap::ov0_02124E48()
{
    if (unk_78 == NULL) {
        return;
    }
    if (sub_02045A18(&unk_54, unk_78, "main") == -1) {
        LogError("not found func FieldMap.cpp");
    }
    unk_50 = sub_02044C9C(&unk_54, 0xFFFFF);
}

void CFieldMap::ov0_02124E9C()
{
    sub_02044B78(&unk_54);
    SAFE_DELETE(unk_4C);
    unk_78 = NULL;
    unk_50 = 2;
}

void CFieldMap::ov0_02124EE4()
{
    ov0_02124E9C();
    for (int i = 0; i < unk_0C; i++) {
        SAFE_DELETE(unk_04[i]);
    }
    if (unk_04 != NULL) {
        Heap_Free(unk_04);
        unk_04 = NULL;
    }
    unk_08 = 0;
    unk_0C = 0;
    if (unk_24 > 0 && unk_20 != NULL) {
        for (int i = 0; i < unk_24; i++) {
            if (unk_20[i] != NULL && unk_38[i] > 0) {
                for (int j = 0; j < unk_38[i]; j++) {
                    SAFE_DELETE(unk_20[i][j]);
                }
            }
            SAFE_DELETE_ARRAY(unk_20[i]);
        }
    }
    SAFE_DELETE_ARRAY(unk_20);
    if (unk_14 > 0 && unk_10 != NULL) {
        for (int i = 0; i < unk_14; i++) {
            SAFE_DELETE(unk_10[i]);
        }
    }
    SAFE_DELETE_ARRAY(unk_10);
    unk_14 = 0;
    if (unk_1C > 0 && unk_18 != NULL) {
        for (int i = 0; i < unk_1C; i++) {
            SAFE_DELETE(unk_18[i]);
        }
    }
    SAFE_DELETE_ARRAY(unk_18);
    unk_1C = 0;
    unk_24 = 0;
    SAFE_DELETE_ARRAY(unk_28);
    SAFE_DELETE_ARRAY(unk_2C);
    SAFE_DELETE_ARRAY(unk_30);
    SAFE_DELETE_ARRAY(unk_34);
    SAFE_DELETE_ARRAY(unk_38);
}

void CFieldMap::ov0_021251D8(BOOL runScript, int fps)
{
    if (unk_14 > 0 && unk_10 != NULL) {
        for (int i = 0; i < unk_14; i++) {
            if (unk_10[i] != NULL) {
                ov0_0212FE54(unk_10[i], fps);
            }
        }
    }
    if (unk_1C > 0 && unk_18 != NULL) {
        for (int i = 0; i < unk_1C; i++) {
            if (unk_18[i] != NULL) {
                ov0_02130030(unk_18[i], fps);
            }
        }
    }
    if (unk_24 > 0 && unk_20 != NULL) {
        for (int i = 0; i < unk_24; i++) {
            if (unk_20[i] != NULL) {
                for (int j = 0; j < unk_38[i]; j++) {
                    if (unk_20[i][j] != NULL) {
                        unk_20[i][j]->Update(fps);
                    }
                }
            }
        }
    }
    if (runScript) {
        unk_50 = sub_02044C9C(&unk_54, 0xFFFFF);
    }
}

void CFieldMap::ov0_02125338(UnkClass_02003718 *camera)
{
    G3_RestoreMtx(0);
    if (unk_24 > 0 && unk_20 != NULL) {
        for (int i = unk_24 - 1; i >= 0; i--) {
            int depth = (s16)(((i + 1) << 11) - 0x2001);
            if (GetCharacterPriority(i) < 0) {
                depth -= GetPolygonCount(i);
            }
            if (unk_20[i] != NULL) {
                for (int j = unk_38[i] - 1; j >= 0; j--) {
                    if (unk_20[i][j] != NULL) {
                        unk_20[i][j]->unk_04 = depth;
                        depth -= unk_20[i][j]->Draw(camera);
                    }
                    if (j == GetCharacterPriority(i)) {
                        depth -= GetPolygonCount(i);
                    }
                }
            }
        }
    }
    G3_RestoreMtx(0);
}

int CFieldMap::ov0_0212546C(int group)
{
    int depth = ((group + 1) << 11) - 0x2001;
    if (group < unk_24 && unk_28[group] >= 0 && unk_20[group] != NULL) {
        for (int j = unk_38[group] - 1; j > unk_28[group]; j--) {
            if (unk_20[group][j] != NULL) {
                depth -= unk_20[group][j]->GetPolygonCount();
            }
        }
    }
    return depth;
}

UnkClass_021302BC *CFieldMap::ov0_0212550C(void *data, int id)
{
    char arcName[] = "MTP";
    NNSFndArchive archive;
    if (data != NULL && NNS_FndMountArchive(&archive, arcName, data)) {
        int count = archive.fatData->numFiles;
        UnkClass_021302BC *tex = new UnkClass_021302BC();
        tex->unk_3C = id;
        for (int i = 0; i < count; i++) {
            void *file = NNS_FndGetArchiveFileByIndex(&archive, i);
            if (file == NULL) {
                continue;
            }
            u32 tag;
            memcpy(&tag, file, sizeof(tag));
            if (tag == 0x4E434752 /* "RGCN" */) {
                NNSG2dCharacterData *chr;
                if (!NNS_G2dGetUnpackedCharacterData(file, &chr)) {
                    continue;
                }
                if (!(id & 1)) {
                    UnkClass_020074D4 *image = new UnkClass_020074D4(chr);
                    NNSGfdTexKey key = NNS_GfdAllocLnkTexVram(image->unk_38, FALSE, 0);
                    image->sub_020076E8(NNS_GfdGetTexKeyAddr(key));
                    image->sub_020076B0();
                    ov0_0213033C(tex, image, key);
                    NNS_G2dGetImageLocation(&image->unk_08, NNS_G2D_VRAM_TYPE_3DMAIN);
                } else {
                    NNSG2dCharacterData block = *chr;
                    block.W = 2;
                    block.H = 2;
                    block.szByte = 0x80;
                    u8 *src = (u8 *)chr->pRawData;
                    u8 *buf = (u8 *)Heap_AllocWithAlignment(0x80, -0x20);
                    block.pRawData = buf;
                    for (int y = 0; y < chr->H / 2; y++) {
                        for (int x = 0; x < chr->W / 2; x++) {
                            for (int row = 0; row < 16; row++) {
                                memcpy(buf + row * 8, src + (chr->W * 4 * (row + y * 16) + x * 8), 8);
                            }
                            UnkClass_020074D4 *image = new UnkClass_020074D4(&block);
                            NNSGfdTexKey key = NNS_GfdAllocLnkTexVram(image->unk_38, FALSE, 0);
                            image->sub_020076E8(NNS_GfdGetTexKeyAddr(key));
                            image->sub_020076B0();
                            ov0_0213033C(tex, image, key);
                            NNS_G2dGetImageLocation(&image->unk_08, NNS_G2D_VRAM_TYPE_3DMAIN);
                        }
                    }
                    if (buf != NULL) {
                        Heap_Free(buf);
                    }
                }
            } else if (tag == 0x4E434C52 /* "RLCN" */) {
                FSFile fsFile;
                FS_InitFile(&fsFile);
                if (NNS_FndOpenArchiveFileByIndex(&fsFile, &archive, i)) {
                    u32 size = FS_GetLength(&fsFile);
                    void *buf = Heap_AllocWithAlignment(size, 4);
                    FS_ReadFile(&fsFile, buf, size);
                    NNSG2dPaletteData *pal;
                    if (NNS_G2dGetUnpackedPaletteData(buf, &pal)) {
                        UnkClass_02007AA4 *palette = new UnkClass_02007AA4(pal);
                        NNSGfdPlttKey key = NNS_GfdAllocLnkPlttVram(palette->unk_04->szByte, FALSE, 0);
                        palette->sub_02007BFC(NNS_GfdGetPlttKeyAddr(key));
                        ov0_02130404(tex, palette, key, buf);
                        NNS_G2dGetImagePaletteLocation(&palette->unk_08, NNS_G2D_VRAM_TYPE_3DMAIN);
                    }
                    FS_CloseFile(&fsFile);
                }
            }
        }
        NNS_FndUnmountArchive(&archive);
        return tex;
    }
    return NULL;
}

CFieldMapLayerBase *CFieldMap::ov0_02125904(void *data, int group, int index)
{
    CFieldMapLayerBase *layer = NULL;
    if (data != NULL) {
        u32 type;
        memcpy(&type, data, sizeof(type));
        switch (type) {
        case 2: {
            CFieldMapLayerNormalView *normalView = new CFieldMapLayerNormalView();
            layer = normalView;
            normalView->unk_08 = group;
            normalView->m_textures = unk_04;
            normalView->m_mct = unk_10;
            normalView->Load((u8 *)data + 4);
            break;
        }
        case 5:
        case 13: {
            CFieldMapLayerStatic *layerStatic = new CFieldMapLayerStatic();
            layer = layerStatic;
            layerStatic->unk_08 = group;
            layerStatic->m_textures = unk_04;
            layerStatic->Load((u8 *)data + 4);
            break;
        }
        case 1:
            layer = new CFieldMapLayerCharacterPriority();
            layer->unk_08 = group;
            break;
        case 3: {
            CFieldMapLayerCollision *collision = new CFieldMapLayerCollision();
            layer = collision;
            collision->unk_08 = group;
            collision->Load((u8 *)data + 4);
            break;
        }
        case 14: {
            CFieldMapLayerCharaTrans *charaTrans = new CFieldMapLayerCharaTrans();
            layer = charaTrans;
            charaTrans->unk_08 = group;
            charaTrans->m_mct = unk_10;
            charaTrans->Load((u8 *)data + 4);
            break;
        }
        case 8: {
            CFieldMapLayerNpc *npc = new CFieldMapLayerNpc();
            layer = npc;
            npc->unk_08 = group;
            npc->Load((u8 *)data + 4);
            break;
        }
        case 9: {
            CFieldMapLayerEnemy *enemy = new CFieldMapLayerEnemy();
            layer = enemy;
            enemy->unk_08 = group;
            enemy->Load((u8 *)data + 4);
            break;
        }
        case 4: {
            CFieldMapLayerObject *object = new CFieldMapLayerObject();
            layer = object;
            object->unk_08 = group;
            object->Load((u8 *)data + 4);
            break;
        }
        case 7: {
            CFieldMapLayerEventRect *eventRect = new CFieldMapLayerEventRect();
            layer = eventRect;
            eventRect->unk_08 = group;
            eventRect->Load((u8 *)data + 4);
            break;
        }
        case 6: {
            CFieldMapLayerAttribute *attribute = new CFieldMapLayerAttribute();
            layer = attribute;
            attribute->unk_08 = group;
            attribute->Load((u8 *)data + 4);
            break;
        }
        case 10: {
            CFieldMapLayerMultiScroll *multiScroll = new CFieldMapLayerMultiScroll();
            layer = multiScroll;
            multiScroll->unk_08 = group;
            multiScroll->m_textures = unk_04;
            multiScroll->m_mct = unk_10;
            multiScroll->Load((u8 *)data + 4);
            multiScroll->SetMapSize(m_info.size.width, m_info.size.height);
            break;
        }
        case 11: {
            CFieldMapLayerUVScroll *uvScroll = new CFieldMapLayerUVScroll();
            layer = uvScroll;
            uvScroll->unk_08 = group;
            uvScroll->m_textures = unk_04;
            uvScroll->Load((u8 *)data + 4);
            break;
        }
        case 12: {
            CFieldMapLayerColorAnime *colorAnime = new CFieldMapLayerColorAnime();
            layer = colorAnime;
            colorAnime->unk_08 = group;
            colorAnime->m_textures = unk_04;
            colorAnime->m_mct = unk_10;
            colorAnime->Load((u8 *)data + 4);
            break;
        }
        }
    }
    return layer;
}

UnkClass_0212F82C *CFieldMap::ov0_02125CA8(void *data, int index)
{
    UnkClass_0212F82C *obj = new UnkClass_0212F82C();
    obj->unk_00 = unk_04;
    ov0_0212F86C(obj, data);
    return obj;
}

UnkClass_0212FEDC *CFieldMap::ov0_02125CE8(void *data, int index)
{
    UnkClass_0212FEDC *obj = new UnkClass_0212FEDC();
    obj->unk_00 = unk_04;
    ov0_0212FF30(obj, data);
    return obj;
}

BOOL CFieldMap::ov0_02125D28(u8 group, const char *name, u32 heapId)
{
    ov0_02124EE4();
    CBinaryFile *texFile = NULL;
    unk_00 = FALSE;
    if (name != NULL) {
        char mapName[0x20];
        char path[0x60];
        STD_CopyString(mapName, name);
        OS_SPrintf(path, "data/field/map/%s.map.lz", mapName);
        OS_SPrintf(path, "data/field/map/%s.map.dat.lz", mapName);
        CBinaryFile *file = new CBinaryFile(path, 1, 1, heapId, NULL, 0);
        if (file == NULL || file->unk_4C == NULL) {
            if (file != NULL) {
                delete file;
            }
            OS_SPrintf(path, "data/field/map/%s.map.lz", mapName);
            file = new CBinaryFile(path, 1, 1, heapId, NULL, 0);
        } else {
            OS_SPrintf(path, "data/field/map/%s.map.tex.lz", mapName);
            texFile = new CBinaryFile(path, 1, 1, heapId, NULL, 0);
        }
        if (file != NULL && file->unk_4C != NULL) {
            NNSFndArchive archive;
            BOOL mounted = FALSE;
            if (NNS_FndMountArchive(&archive, "MPK", file->unk_4C)) {
                mounted = TRUE;
            }
            int mode = texFile != NULL ? 1 : 2;
            if (mounted && mode != 0) {
                int count = archive.fatData->numFiles;
                void *mpif = NULL;
                void *txif = NULL;
                void *tex = NULL;
                void *lyr = NULL;
                void *cta = NULL;
                void *pla = NULL;
                u16 *texIds = NULL;
                for (int i = 0; i < count; i++) {
                    void *chunk = NNS_FndGetArchiveFileByIndex(&archive, i);
                    if (chunk == NULL) {
                        continue;
                    }
                    u32 tag;
                    memcpy(&tag, chunk, sizeof(tag));
                    if (tag == 0x4649504D /* "MPIF" */) {
                        mpif = (u8 *)chunk + 4;
                    } else if (tag == 0x46495854 /* "TXIF" */) {
                        txif = (u8 *)chunk + 4;
                    } else if (tag == 0x00584554 /* "TEX" */) {
                        tex = (u8 *)chunk + 4;
                    } else if (tag == 0x0052594C /* "LYR" */) {
                        lyr = (u8 *)chunk + 4;
                    } else if (tag == 0x00415443 /* "CTA" */) {
                        cta = (u8 *)chunk + 4;
                    } else if (tag == 0x00414C50 /* "PLA" */) {
                        pla = (u8 *)chunk + 4;
                    }
                }
                if (mode == 1) {
                    void *texData = texFile->unk_4C;
                    if (texData != NULL) {
                        u32 tag;
                        memcpy(&tag, texData, sizeof(tag));
                        if (tag == 0x00584554 /* "TEX" */) {
                            tex = (u8 *)texData + 4;
                        }
                    }
                }
                if (mpif != NULL) {
                    memcpy(&m_info.size.width, (u8 *)mpif + 0x0, 4);
                    memcpy(&m_info.size.height, (u8 *)mpif + 0x4, 4);
                    memcpy(&m_info.unk_08, (u8 *)mpif + 0x8, 4);
                    memcpy(&m_info.unk_0C, (u8 *)mpif + 0xC, 4);
                }
                if (txif != NULL) {
                    u16 texCount;
                    memcpy(&texCount, txif, sizeof(texCount));
                    u8 *p = (u8 *)txif + 2;
                    texIds = (u16 *)Heap_AllocWithAlignment(texCount * 2, -4);
                    for (int i = 0; i < texCount; i++) {
                        u16 value;
                        u16 valueCount;
                        memcpy(&texIds[i], p, sizeof(u16));
                        memcpy(&valueCount, p + 2, sizeof(valueCount));
                        memcpy(&value, p + 4, sizeof(value));
                        p += 6;
                        for (int j = 0; j < valueCount; j++) {
                            memcpy(&value, p, sizeof(value));
                            p += 2;
                        }
                    }
                }
                if (tex != NULL) {
                    NNSFndArchive texArchive;
                    if (NNS_FndMountArchive(&texArchive, "MTX", tex)) {
                        int texCount = texArchive.fatData->numFiles;
                        if (unk_04 != NULL) {
                            for (int i = 0; i < unk_0C; i++) {
                                SAFE_DELETE(unk_04[i]);
                            }
                            if (unk_04 != NULL) {
                                Heap_Free(unk_04);
                                unk_04 = NULL;
                            }
                        }
                        unk_04 = (UnkClass_021302BC **)Heap_AllocWithAlignment(texCount * sizeof(UnkClass_021302BC *), 4);
                        unk_0C = texCount;
                        unk_08 = 0;
                        for (int i = 0; i < texCount; i++) {
                            void *texData = NNS_FndGetArchiveFileByIndex(&texArchive, i);
                            if (texData != NULL) {
                                UnkClass_021302BC *texture = ov0_0212550C(texData, texIds != NULL ? texIds[i] : 0);
                                if (texture != NULL) {
                                    unk_04[unk_08] = texture;
                                    unk_08++;
                                }
                            }
                        }
                        NNS_FndUnmountArchive(&texArchive);
                    }
                }
                if (cta != NULL) {
                    NNSFndArchive ctaArchive;
                    if (NNS_FndMountArchive(&ctaArchive, "MCT", cta)) {
                        int ctaCount = ctaArchive.fatData->numFiles;
                        unk_10 = new UnkClass_0212F82C *[ctaCount];
                        unk_14 = ctaCount;
                        for (int i = 0; i < ctaCount; i++) {
                            unk_10[i] = ov0_02125CA8(NNS_FndGetArchiveFileByIndex(&ctaArchive, i), i);
                        }
                        NNS_FndUnmountArchive(&ctaArchive);
                    }
                }
                if (pla != NULL) {
                    NNSFndArchive plaArchive;
                    if (NNS_FndMountArchive(&plaArchive, "MPA", pla)) {
                        int plaCount = plaArchive.fatData->numFiles;
                        unk_18 = new UnkClass_0212FEDC *[plaCount];
                        unk_1C = plaCount;
                        for (int i = 0; i < plaCount; i++) {
                            unk_18[i] = ov0_02125CE8(NNS_FndGetArchiveFileByIndex(&plaArchive, i), i);
                        }
                        NNS_FndUnmountArchive(&plaArchive);
                    }
                }
                SAFE_DELETE(texFile);
                if (lyr != NULL) {
                    NNSFndArchive lyrArchive;
                    if (NNS_FndMountArchive(&lyrArchive, "MLY", lyr)) {
                        int groupCount = lyrArchive.fatData->numFiles;
                        unk_20 = new CFieldMapLayerBase **[groupCount];
                        unk_24 = groupCount;
                        unk_28 = new int[unk_24];
                        unk_2C = new void *[unk_24];
                        unk_30 = new void *[unk_24];
                        unk_34 = new int[unk_24];
                        unk_38 = new int[unk_24];
                        for (int i = 0; i < unk_24; i++) {
                            unk_28[i] = -1;
                            unk_2C[i] = NULL;
                            unk_30[i] = NULL;
                            unk_34[i] = 0;
                            unk_38[i] = 0;
                        }
                        for (int i = 0; i < groupCount; i++) {
                            NNSFndArchive groupArchive;
                            if (NNS_FndMountArchive(&groupArchive, "MLG", NNS_FndGetArchiveFileByIndex(&lyrArchive, i))) {
                                int layerCount = groupArchive.fatData->numFiles;
                                unk_20[i] = new CFieldMapLayerBase *[layerCount];
                                unk_38[i] = layerCount;
                                for (int j = 0; j < layerCount; j++) {
                                    unk_20[i][j] = ov0_02125904(NNS_FndGetArchiveFileByIndex(&groupArchive, j), i, j);
                                    if (unk_20[i][j] != NULL) {
                                        switch (unk_20[i][j]->GetType()) {
                                        case 1:
                                            unk_28[i] = j;
                                            break;
                                        case 3:
                                            unk_2C[i] = unk_20[i][j];
                                            break;
                                        case 6:
                                            unk_30[i] = unk_20[i][j];
                                            break;
                                        }
                                    }
                                }
                                NNS_FndUnmountArchive(&groupArchive);
                            }
                        }
                        NNS_FndUnmountArchive(&lyrArchive);
                    }
                }
                unk_00 = TRUE;
                if (texIds != NULL) {
                    Heap_Free(texIds);
                }
            }
            if (mounted == TRUE) {
                NNS_FndUnmountArchive(&archive);
            }
        }
        if (texFile != NULL) {
            delete texFile;
        }
        if (file != NULL) {
            delete file;
        }
    }
    return unk_00;
}

void CFieldMap::ov0_02126658()
{
    if (unk_1C > 0 && unk_18 != NULL) {
        for (int i = 0; i < unk_1C; i++) {
            if (unk_18[i] != NULL) {
                ov0_021300C8(unk_18[i]);
            }
        }
    }
}
