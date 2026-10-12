#include "UnkClass_0202A510.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkClass_020B26A0.hpp"
#include "common.hpp"

extern UnkClass_02041C80 *MAIN_BSS_0210CA6C;

static MapMenuArea sMapMenuAreas[] = {
    { 8, 0x100ULL, 0, 0, 0 },
    { 7, 0x80ULL, 2, 4, 8 },
    { 4, 0x30ULL, 0, 0, 0 },
    { 2, 0xCULL, 2, 8, 4 },
    { 1, 0x2ULL, 0, 0, 0 },
    { 6, 0x40ULL, 1, 0, 0 },
    { 9, 0x200ULL, 2, 4, 12 },
    { 10, 0x400ULL, 0, 0, 0 },
    { 14, 0x4000ULL, 0, 0, 0 },
    { 201, 0x800ULL, 2, 0, 0 },
    { 11, 0x800ULL, 1, 0, 0 },
    { 15, 0x8000ULL, 2, 4, 16 },
    { 17, 0x20000ULL, 0, 0, 0 },
    { 16, 0x10000ULL, 1, 0, 0 },
    { 202, 0x40000ULL, 2, 0, 0 },
    { 18, 0x40000ULL, 0, 0, 0 },
    { 19, 0x80000ULL, 1, 0, 0 },
    { 20, 0x100000ULL, 1, 0, 0 },
    { 120, 0x100000ULL, 1, 0, 0 },
    { 21, 0x200000ULL, 2, 4, 12 },
    { 22, 0x400000ULL, 1, 0, 0 },
    { 23, 0x800000ULL, 1, 0, 0 },
    { 24, 0x1000000ULL, 2, 4, 22 },
    { 26, 0x4000000ULL, 2, 9, 4 },
    { 25, 0x2000000ULL, 0, 0, 0 },
    { 27, 0x8000000ULL, 2, 4, 9 },
    { 28, 0x10000000ULL, 1, 0, 0 },
    { 203, 0x20000000ULL, 2, 0, 0 },
    { 29, 0x20000000ULL, 1, 0, 0 },
    { 30, 0x40000000ULL, 1, 0, 0 },
    { 204, 0x300000000ULL, 2, 0, 0 },
    { 33, 0x300000000ULL, 0, 0, 0 },
    { 34, 0xC00000000ULL, 2, 4, 8 },
    { 36, 0x1000000000ULL, 1, 0, 0 },
    { 38, 0x4000000000ULL, 1, 0, 0 },
    { 39, 0x8000000000ULL, 1, 0, 0 },
    { 41, 0x1F0000000000ULL, 0, 0, 0 },
};

UnkClass_0202A510::UnkClass_0202A510(CGame *game)
{
    unk_64 = game;
    Init();
}

UnkClass_0202A510::~UnkClass_0202A510()
{
    Release();
}

void UnkClass_0202A510::Init()
{
    unk_00 = 0;
    unk_10 = NULL;
    unk_14 = NULL;
    unk_18 = NULL;
    unk_08 = NULL;
    unk_0C = NULL;
    unk_20 = NULL;
    for (int i = 0; i < 5; i++) {
        unk_28[i] = NULL;
    }
    unk_04 = 0;
    unk_5C = 0;
    unk_24 = 37;
    unk_1C = new Entry[unk_24];
    unk_60 = TRUE;
}

void UnkClass_0202A510::sub_0202A5A8()
{
    if (unk_10 != NULL) {
        unk_10->sub_0200F64C();
    }
    if (unk_14 != NULL) {
        unk_14->sub_0200F64C();
    }
    if (unk_18 != NULL) {
        unk_18->sub_0200F64C();
    }
    sub_0202AE7C();
}

void UnkClass_0202A510::sub_0202A5EC()
{
    sub_0202A6E8();
}

void UnkClass_0202A510::sub_0202A5F8()
{
}

void UnkClass_0202A510::Release()
{
    SAFE_DELETE(unk_0C);
    SAFE_DELETE(unk_10);
    SAFE_DELETE(unk_14);
    SAFE_DELETE(unk_18);
    SAFE_DELETE_ARRAY(unk_1C);
    SAFE_DELETE(unk_20);
}

void UnkClass_0202A510::sub_0202A6E8()
{
    if (unk_10 != NULL) {
        unk_10->sub_0200F71C();
    }
    if (unk_14 != NULL) {
        unk_14->sub_0200F71C();
    }
    if (unk_18 != NULL) {
        unk_18->sub_0200F71C();
    }
}

void UnkClass_0202A510::sub_0202A724(int bg, u8 *oamIndex, int *charNo, int *paletteSlot, BOOL extPltt)
{
    int i;
    SAFE_DELETE(unk_20);
    unk_20 = new UnkClass_0201FC80((int)unk_64);
    unk_20->SetBG(bg);
    unk_20->LoadArchive("menu/", "map000_");
    unk_20->LoadChar("map000", 0, 0, 0);
    unk_20->LoadPltt("map000", 0, 0, 0);
    unk_20->LoadScr("map000", 0, 0, 0, 0, 0);
    unk_20->ReleaseArchive();
    unk_20->LoadCharToVram();
    unk_20->LoadPlttToVram(extPltt);
    unk_20->LoadScrToVram();

    BOOL mainScreen;
    switch (bg) {
    case 0:
    case 1:
    case 2:
    case 3:
        mainScreen = TRUE;
        break;
    default:
        mainScreen = FALSE;
        break;
    }

    unk_50 = *paletteSlot;
    int chr = *charNo;
    u8 oam = *oamIndex;

    SAFE_DELETE(unk_10);
    if (mainScreen) {
        unk_10 = new UnkClass_0200ECD0((GXOamAttr *)&unk_64->unk_0024[oam], unk_64->unk_14A8, FALSE, 0x40);
    } else {
        unk_10 = new UnkClass_0200ECD0((GXOamAttr *)&unk_64->unk_0424[oam], unk_64->unk_14A8, TRUE, 0x40);
    }
    chr += unk_10->sub_0200F168("data/menu", "map000_00", chr / 32, *paletteSlot);
    unk_10->sub_0200F398();
    for (i = 0; i < unk_24; i++) {
        unk_1C[i].sprite = unk_10->sub_0200F4FC(i, 0x80, 0x60, 3);
        unk_1C[i].cellId = unk_10->unk_24;
        const NNSG2dCellOAMAttrData *attr = unk_1C[i].sprite->unk_04->pOamAttrArray;
        s16 x = attr->attr1 & 0x1FF;
        s16 y = attr->attr0 & 0xFF;
        s16 left = x + 0x88;
        s16 top = y + 0x68;
        unk_1C[i].sprite->sub_0200EBF4(16, 16, (u8)left - 0x80, (u8)top - 0x60);
    }
    oam += unk_10->unk_30;

    SAFE_DELETE(unk_14);
    if (mainScreen) {
        unk_14 = new UnkClass_0200ECD0((GXOamAttr *)&unk_64->unk_0024[oam], unk_64->unk_14A8, FALSE, 0x40);
    } else {
        unk_14 = new UnkClass_0200ECD0((GXOamAttr *)&unk_64->unk_0424[oam], unk_64->unk_14A8, TRUE, 0x40);
    }
    *paletteSlot += 2;
    chr += unk_14->sub_0200F168("data/menu", "map000_01", chr / 32, *paletteSlot);
    unk_14->sub_0200F398();
    int anim = 0;
    if (MAIN_BSS_020B26A0.unk_0000 != 0) {
        anim = 1;
    }
    unk_28[1] = unk_14->sub_0200F4FC(anim, 0, 0, 1);
    unk_28[1]->sub_0200EBF4(24, 24, 0, 0);
    oam += unk_14->unk_30;

    SAFE_DELETE(unk_18);
    if (mainScreen) {
        unk_18 = new UnkClass_0200ECD0((GXOamAttr *)&unk_64->unk_0024[oam], unk_64->unk_14A8, FALSE, 0x40);
    } else {
        unk_18 = new UnkClass_0200ECD0((GXOamAttr *)&unk_64->unk_0424[oam], unk_64->unk_14A8, TRUE, 0x40);
    }
    *paletteSlot += 1;
    chr += unk_18->sub_0200F168("data/menu", "map000_02", chr / 32, *paletteSlot);
    unk_18->sub_0200F398();
    unk_28[4] = unk_18->sub_0200F4FC(0, 0, 0, 1);
    unk_28[4]->sub_0200EBF4(32, 32, 0, 0);
    unk_28[3] = unk_18->sub_0200F4FC(0, 0, 0, 1);
    unk_28[3]->sub_0200EBF4(24, 24, 0, 0);
    oam += unk_18->unk_30;

    unk_08 = MAIN_BSS_0210CA6C;
    *charNo = chr;
    *oamIndex = oam;
    sub_0202B2CC();
    sub_0202AED4();
}

void UnkClass_0202A510::sub_0202AD04(BOOL extPltt)
{
    if (unk_20 != NULL) {
        unk_20->LoadCharToVram();
        unk_20->LoadPlttToVram(extPltt);
        unk_20->LoadScrToVram();
    }
    if (unk_10 != NULL) {
        unk_10->sub_0200F398();
    }
    if (unk_14 != NULL) {
        unk_14->sub_0200F398();
    }
    if (unk_18 != NULL) {
        unk_18->sub_0200F398();
    }
    sub_0202B2CC();
    sub_0202AED4();
}

void UnkClass_0202A510::sub_0202AD78()
{
    int i;
    if (!unk_60) {
        return;
    }
    unk_58 = -1;
    unk_54 = 0xFFFF;
    for (i = 0; i <= 1; i++) {
        UnkClass_0200E960 *sprite = unk_28[i];
        if (sprite != NULL && (i == 1 || sprite->unk_14 != 0)) {
            if (sprite->sub_0200EB84()) {
                unk_58 = i;
                return;
            }
        }
    }
    for (i = 0; i < unk_24; i++) {
        if (unk_1C[i].sprite->unk_14 != 0 && unk_1C[i].sprite->sub_0200EB84() && unk_50 == unk_1C[i].sprite->unk_1A
            && sMapMenuAreas[i].type != 2) {
            unk_54 = sMapMenuAreas[i].id;
            unk_58 = 6;
            return;
        }
    }
}

void UnkClass_0202A510::sub_0202AE7C()
{
    unk_5C = (unk_5C + 1) % 30;
    unk_28[1]->SetVisible(unk_5C < 15);
}

void UnkClass_0202A510::sub_0202AED4()
{
    u64 flags = MAIN_BSS_020B26A0.unk_7F64;
    for (int i = 0; i < unk_24; i++) {
        unk_1C[i].sprite->unk_14 = FALSE;
        if (sub_0202B244(i, &flags)) {
            unk_1C[i].sprite->unk_14 = TRUE;
        }
    }
}

BOOL UnkClass_0202A510::sub_0202AF5C(u64 *flags)
{
    int i;
    BOOL found = FALSE;
    UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
    for (i = 0; i < unk_24; i++) {
        unk_1C[i].sprite->unk_14 = FALSE;
    }
    u64 saved = save->unk_7F64;
    switch ((u16)((*flags >> 60) & 0xF)) {
    case 0:
        return FALSE;
    case 1:
        break;
    case 2:
        if ((int)unk_64->m_missionQuestData->unk_08 < 69) {
            return FALSE;
        }
        break;
    case 3:
        if ((int)unk_64->m_missionQuestData->unk_08 < 55) {
            return FALSE;
        }
        break;
    }
    for (i = 0; i < unk_24; i++) {
        if (sub_0202B244(i, &saved)) {
            u64 mask = sMapMenuAreas[i].mask;
            if (sMapMenuAreas[i].id >= 200) {
                mask = 0;
            }
            unk_1C[i].sprite->unk_14 = TRUE;
            if (mask & *flags) {
                found = TRUE;
                unk_1C[i].sprite->unk_1A = unk_50;
            } else {
                unk_1C[i].sprite->unk_1A = unk_50 + 1;
            }
        }
    }
    if (!found) {
        for (i = 0; i < unk_24; i++) {
            unk_1C[i].sprite->unk_14 = FALSE;
        }
    }
    return found;
}

BOOL UnkClass_0202A510::sub_0202B140(u64 *flags)
{
    u64 saved = MAIN_BSS_020B26A0.unk_7F64;
    BOOL found = FALSE;
    for (int i = 0; i < unk_24; i++) {
        unk_1C[i].sprite->unk_14 = FALSE;
        if (sub_0202B244(i, &saved)) {
            unk_1C[i].sprite->unk_14 = TRUE;
            u64 bit = (u64)1 << sMapMenuAreas[i].id;
            if (bit & *flags) {
                found = TRUE;
                unk_1C[i].sprite->unk_1A = unk_50;
            } else {
                unk_1C[i].sprite->unk_1A = unk_50 + 1;
            }
        }
    }
    return found;
}

BOOL UnkClass_0202A510::sub_0202B244(int i, u64 *flags)
{
    if ((int)unk_64->m_missionQuestData->unk_08 >= 40) {
        if (sMapMenuAreas[i].id == 20) {
            return FALSE;
        }
    } else if (sMapMenuAreas[i].id == 120) {
        return FALSE;
    }
    return (*flags & sMapMenuAreas[i].mask) != 0;
}

void UnkClass_0202A510::sub_0202B2CC()
{
    unk_56 = sub_0202B338(MAIN_BSS_020B26A0.unk_001A);
    sub_0202B2FC(1, unk_56);
}

void UnkClass_0202A510::sub_0202B2FC(int sprite, u16 id)
{
    int x;
    int y;
    sub_0202B370(id, &x, &y);
    unk_28[sprite]->sub_0200EB28(x, y);
}

u16 UnkClass_0202A510::sub_0202B338(u32 mapId)
{
    u16 id = sub_02041D80(unk_08, mapId)->unk_00;
    if ((int)unk_64->m_missionQuestData->unk_08 >= 40 && id == 20) {
        id = 120;
    }
    return id;
}

void UnkClass_0202A510::sub_0202B370(u16 id, int *x, int *y)
{
    if (unk_10 == NULL) {
        return;
    }
    *x = 0;
    *y = 0xE0;
    int i = sub_0202B458(id);
    if (i < 0) {
        return;
    }
    int dx;
    int dy;
    if (sMapMenuAreas[i].type == 2) {
        dx = sMapMenuAreas[i].offsetX;
        dy = sMapMenuAreas[i].offsetY;
    } else {
        dy = dx = 8;
    }
    s16 px = dx + (s16)(unk_1C[i].sprite->unk_04->pOamAttrArray->attr1 & 0x1FF) + unk_1C[i].sprite->unk_0C;
    s16 py = dy + (s16)(unk_1C[i].sprite->unk_04->pOamAttrArray->attr0 & 0xFF) + unk_1C[i].sprite->unk_0E;
    *x = (u8)px & 0xFF;
    *y = (u8)py & 0xFF;
}

int UnkClass_0202A510::sub_0202B458(u16 id)
{
    int i;
    for (i = 0; i < unk_24; i++) {
        if (id == sMapMenuAreas[i].id) {
            break;
        }
    }
    if (i < unk_24) {
        return i;
    }
    for (i = 0; i < unk_24; i++) {
        if (sMapMenuAreas[i].id < 200 && (sMapMenuAreas[i].mask & ((u64)1 << id))) {
            break;
        }
    }
    if (i >= unk_24) {
        i = -1;
    }
    return i;
}

void UnkClass_0202A510::sub_0202B50C(u16 id, int mode)
{
    int idx = 3;
    switch (mode) {
    case 4:
        unk_28[4]->unk_14 = FALSE;
        unk_28[3]->unk_14 = FALSE;
        return;
    case 0:
        idx = 4;
        break;
    case 3:
        break;
    }
    int x;
    int y;
    sub_0202B370(id, &x, &y);
    unk_28[idx == 4 ? 3 : 4]->unk_14 = FALSE;
    unk_28[idx]->unk_14 = TRUE;
    unk_28[idx]->sub_0200EB28(x, y);
}

void UnkClass_0202A510::sub_0202B5A8(s16 *kind, u16 *id)
{
    sub_0202AD78();
    *kind = unk_58;
    *id = unk_54;
}
