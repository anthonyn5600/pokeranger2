#include "UnkClass_0211CD68.hpp"

#include "CGame.hpp"
#include "Camera2D.hpp"
#include "UnkClass_0200C38C.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_0201FC80.hpp"
#include "UnkClass_02021404.hpp"
#include "UnkClass_02040F34.hpp"
#include "UnkClass_0211E05C.hpp"

struct RNMissionEntry {
    u16 kind;
    u16 unk_2;
};

UnkClass_0211CD68::UnkClass_0211CD68(CGame *game, UnkClass_0211E05C *menu)
{
    unk_5F0 = game;
    unk_058 = menu;
    ov11_0211CDE8();
}

UnkClass_0211CD68::~UnkClass_0211CD68()
{
    ov11_0211CF40();
}

void UnkClass_0211CD68::ov11_0211CDE8()
{
    unk_000 = 0;
    unk_018 = NULL;
    unk_010 = NULL;
    unk_004 = 0;
    unk_5E0 = 1;
    unk_5E4 = 0;
    unk_5E8 = 0;
    unk_062 = 0;
    unk_064 = 0;
    unk_068 = -1;
}

void UnkClass_0211CD68::ov11_0211CE20()
{
    int step = 60 / unk_5F0->unk_146C.sub_02008E50();
    if (unk_064 < 0x780) {
        unk_064 += step * 8;
    } else {
        unk_062 += step;
        if (unk_062 > 60) {
            unk_062 = 0;
            unk_064 = -0x280;
        }
    }
    G2_SetBG1Offset(0, -(unk_064 / 10));
    if (unk_018 == NULL) {
        return;
    }
    unk_018->sub_0200F64C();
    switch (unk_068) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        unk_0A0[unk_5EC].sub_0203C87C(NULL);
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

void UnkClass_0211CD68::ov11_0211CF04()
{
    ov11_0211D02C();
}

void UnkClass_0211CD68::ov11_0211CF10()
{
    ov11_0211D8C4();
}

void UnkClass_0211CD68::ov11_0211CF1C()
{
    if (unk_018 != NULL) {
        unk_5F0->unk_1494->sub_0200C588();
    }
}

void UnkClass_0211CD68::ov11_0211CF40()
{
    SAFE_DELETE(unk_008);
    SAFE_DELETE(unk_00C);
    SAFE_DELETE(unk_018);
    SAFE_DELETE(unk_010);
    for (int i = 0; i < 6; i++) {
        SAFE_DELETE(unk_040[i]);
    }
}

static inline void DrawActor(CFieldActor *actor, Camera2D *camera)
{
    if (actor->unk_08 != NULL) {
        actor->unk_08->sub_020091D4(camera, 0);
    }
}

void UnkClass_0211CD68::ov11_0211D02C()
{
    if (unk_018 == NULL) {
        return;
    }
    unk_018->sub_0200F71C();
    switch (unk_068) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        if (unk_008 != NULL) {
            unk_008->SetOffset(0x41000, -0x17000);
            unk_008->sub_020037B4();
            unk_008->sub_0200381C();
            G3_StoreMtx(0);
            DrawActor(&unk_0A0[unk_5EC], unk_008);
        }
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

void UnkClass_0211CD68::ov11_0211D0D0()
{
    static RNMissionEntry sMissionEntries[6] = {
        { 0x12, 0 },
        { 0x12, 0 },
        { 0x1D, 0 },
        { 0x1A, 0 },
        { 0x1A, 0 },
        { 0x1A, 0 },
    };
    char path[0x40];

    GX_SetVisiblePlane(GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
    G2_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x1000, GX_BG_CHARBASE_0x10000, GX_BG_EXTPLTT_01);
    G2_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x1800, GX_BG_CHARBASE_0x10000);
    G2_SetBG0Priority(0);
    G2_SetBG1Priority(2);
    G2_SetBG2Priority(3);
    G2_SetBG3Priority(0);
    BGS_LoadCharAndPltt("menu/", "rn000_bg_", 1, "rn000", 0, "rn000", 1);
    BGS_LoadScr("menu/", "rn000_bg_", 2, "rn000_02", 1, 0, 0, 0);
    BGS_LoadScr("menu/", "rn000_bg_", 1, "rn000_01", 1, 0, 0, 0);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_BG1, GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2, 8, 7);

    unk_018 = new UnkClass_0200ECD0((GXOamAttr *)unk_5F0->unk_0024, unk_5F0->unk_14A8, FALSE, 0x40);
    unk_018->sub_0200EE14("data/menu", "rn000_00", 0, 1);
    unk_01C[1] = unk_018->sub_0200F4FC(0, 0x80, 0x60, 1);
    unk_01C[2] = unk_018->sub_0200F4FC(1, 0x80, 0x60, 1);
    unk_01C[3] = unk_018->sub_0200F4FC(2, 0x80, 0x60, 1);
    unk_01C[4] = unk_018->sub_0200F4FC(3, 0x80, 0x60, 1);
    unk_01C[5] = unk_018->sub_0200F4FC(4, 0x80, 0x60, 1);
    unk_01C[6] = unk_018->sub_0200F4FC(5, 0x80, 0x60, 1);
    unk_01C[0] = unk_018->sub_0200F4FC(8, 0x80, 0x60, 1);
    ov11_0211DED0();

    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    unk_5F0->unk_1494->sub_0200C408(3, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x18000);
    unk_00C = new UnkClass_02040F34();
    unk_008 = new Camera2D();
    unk_008->sub_02003788(0, 0xC0000, 0, 0x100000, -0x400000, 0x800000, 0x400000);

    for (int i = 0; i < 6; i++) {
        u16 kind = sMissionEntries[i].kind;
        OS_SPrintf(path, "data/message/etc/mission_info_%02d", i + 0x50);
        unk_040[i] = new UnkClass_02021404(path);
        int type = 1;
        if (kind == 0) {
            kind = 3;
            type = 4;
        }
        unk_0A0[i].sub_0203C418(type, kind, 0, 2, 0);
        if (unk_0A0[i].unk_08 != NULL && unk_0A0[i].unk_08->unk_0C != NULL) {
            unk_0A0[i].unk_08->unk_0C->sub_020128EC(0x4000);
        }
    }
}

void UnkClass_0211CD68::ov11_0211D4C0(int mode)
{
    if (unk_068 == mode) {
        return;
    }
    unk_068 = mode;
    unk_5F0->unk_1494->sub_0200C408(3, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x18000);
    unk_5F0->unk_1494->sub_0200C3D0();
    ov11_0211DED0();
    GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG3);
    switch (mode) {
    case 0:
        GX_SetVisiblePlane(GX_GetVisiblePlane() & ~GX_PLANEMASK_BG3);
        break;
    case 1:
        unk_01C[4]->SetVisible(TRUE);
        unk_5F0->unk_1494->sub_0200C680(1);
        unk_5F0->unk_1494->sub_0200C6C8(0, 0x1A, 0x14, 3, 2, 8, 0, 2);
        break;
    case 2:
        unk_01C[0]->SetVisible(TRUE);
        unk_01C[1]->SetVisible(TRUE);
        unk_01C[2]->SetVisible(TRUE);
        unk_01C[3]->SetVisible(TRUE);
        unk_5F0->unk_1494->sub_0200C680(4);
        unk_5F0->unk_1494->sub_0200C6C8(0, 0x18, 2, 4, 2, 8, 0, 2);
        unk_5F0->unk_1494->sub_0200C6C8(1, 0x11, 2, 5, 6, 0x38, 0, 2);
        unk_5F0->unk_1494->sub_0200C6C8(2, 0xF, 2, 6, 8, 0x5A, 0, 2);
        unk_5F0->unk_1494->sub_0200C6C8(3, 0x1E, 0xA, 2, 0xC, 0x78, 0, 2);
        break;
    case 3:
    case 4:
        unk_01C[5]->SetVisible(TRUE);
        unk_01C[6]->SetVisible(TRUE);
        unk_5F0->unk_1494->sub_0200C680(2);
        unk_5F0->unk_1494->sub_0200C6C8(0, 0x1B, 0xA, 3, 2, 8, 0, 2);
        unk_5F0->unk_1494->sub_0200C6C8(1, 0x1B, 4, 3, 0x10, 0x116, 0, 2);
        break;
    }
    unk_018->sub_0200F64C();
    unk_018->sub_0200F71C();
}

BOOL UnkClass_0211CD68::ov11_0211D7D4(int a, int b, UnkClass_02021404 *c)
{
    unk_06C = a;
    ov11_0211D860(a);
    ov11_0211D880(b, c);
    return TRUE;
}

BOOL UnkClass_0211CD68::ov11_0211D804(int idx)
{
    unk_5EC = idx;
    unk_06C = 2;
    ov11_0211D860(2);
    ov11_0211D880(1, unk_040[idx]);
    ov11_0211D8A0(2);
    ov11_0211D8A0(3);
    ov11_0211D8A0(4);
    return TRUE;
}

void UnkClass_0211CD68::ov11_0211D860(int mode)
{
}

BOOL UnkClass_0211CD68::ov11_0211D864()
{
    ov11_0211D0D0();
    ov11_0211CF1C();
    return TRUE;
}

void UnkClass_0211CD68::ov11_0211D880(int a, UnkClass_02021404 *b)
{
    unk_004 = 1;
    unk_070 = b;
    unk_09C = 0;
    ov11_0211D8A0(a);
}

void UnkClass_0211CD68::ov11_0211D8A0(int v)
{
    if (unk_09C < 10) {
        unk_074[unk_09C] = v;
        unk_09C++;
    }
}

void UnkClass_0211CD68::ov11_0211D8C4()
{
    UnkClass_0200C38C *tb;
    if (unk_004 == 0) {
        return;
    }
    unk_004 = 0;
    ov11_0211D4C0(unk_06C);
    switch (unk_06C) {
    case 0:
        break;
    case 1:
        if (unk_070 == NULL) {
            return;
        }
        unk_5F0->unk_1494->sub_0200C980(0);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(0, 0, 2, 3, (u8 *)unk_070->GetString(unk_074[0]), 0, 0);
        break;
    case 2:
        unk_070 = unk_040[unk_5EC];
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(0, 0, 3, 3, (u8 *)unk_070->GetString(unk_074[0]), 1, 0);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(1, 0, 0, 3, (u8 *)unk_070->GetString(unk_074[1]), 1, 0);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(2, 0, 0, 3, (u8 *)unk_070->GetString(unk_074[2]), 1, 0);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(3, 0, 6, 3, (u8 *)unk_070->GetString(unk_074[3]), 0, 0);
        break;
    case 3:
        if (unk_070 == NULL) {
            return;
        }
        unk_5F0->unk_1494->sub_0200C980(0);
        unk_5F0->unk_1494->sub_0200C980(1);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(0, 0, 2, 3, (u8 *)unk_070->GetString(unk_074[0]), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(0, 0, 0xE, 3, (u8 *)unk_070->GetString(0xF), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(0, 0, 0x26, 3, (u8 *)unk_070->GetString(0x10), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(0, 0, 0x32, 3, (u8 *)unk_070->GetString(0x11), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(1, 0, 2, 3, (u8 *)unk_070->GetString(0x12), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(1, 0x8C, 0xE, 3, (u8 *)unk_070->GetString(0x13), 0, 0);
        unk_058->ov11_0212331C(0, 0x50, 0x26, -1, 3, 1, 5);
        unk_058->ov11_02123228(0, 0x64, 0x32, 3, 1);
        break;
    case 4:
        if (unk_070 == NULL) {
            return;
        }
        unk_5F0->unk_1494->sub_0200C980(0);
        unk_5F0->unk_1494->sub_0200C980(1);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(0, 0, 2, 3, (u8 *)unk_070->GetString(unk_074[0]), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(0, 0, 0xE, 3, (u8 *)unk_070->GetString(0xF), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(0, 0, 0x26, 3, (u8 *)unk_070->GetString(0xA), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(0, 0, 0x32, 3, (u8 *)unk_070->GetString(0x10), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(1, 0, 2, 3, (u8 *)unk_070->GetString(0x11), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->sub_0200C7A4(1, 0x8C, 0xE, 3, (u8 *)unk_070->GetString(0x12), 0, 0);
        unk_058->ov11_0212331C(0, 0x50, 0x26, -1, 3, 1, 5);
        unk_058->ov11_02123598(0, 0x50, 0x32, 0, 3, 1);
        break;
    }
}

void UnkClass_0211CD68::ov11_0211DED0()
{
    for (int i = 1; i < 7; i++) {
        if (unk_01C[i] != NULL) {
            unk_01C[i]->unk_14 = 0;
        }
    }
}
