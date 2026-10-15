#include "RangerNetMissionList.hpp"

#include "BGLayer.hpp"
#include "CGame.hpp"
#include "Camera2D.hpp"
#include "FieldDrawActorDataPool.hpp"
#include "MessageTable.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "RangerNetMenu.hpp"
#include "TextPrinter.hpp"

struct RNMissionEntry {
    u16 kind;
    u16 unk_2;
};

RangerNetMissionList::RangerNetMissionList(CGame *game, RangerNetMenu *menu)
{
    unk_5F0 = game;
    unk_058 = menu;
    Init();
}

RangerNetMissionList::~RangerNetMissionList()
{
    Release();
}

void RangerNetMissionList::Init()
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

void RangerNetMissionList::Update()
{
    int step = 60 / unk_5F0->unk_146C.GetFps();
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
    unk_018->Update();
    switch (unk_068) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        unk_0A0[unk_5EC].Update(NULL);
        break;
    case 3:
        break;
    case 4:
        break;
    }
}

void RangerNetMissionList::Draw()
{
    Render();
}

void RangerNetMissionList::PrintText()
{
    PrintPendingText();
}

void RangerNetMissionList::LoadPalette()
{
    if (unk_018 != NULL) {
        unk_5F0->unk_1494->LoadPalette();
    }
}

void RangerNetMissionList::Release()
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
    if (actor->m_drawObject != NULL) {
        actor->m_drawObject->Draw(camera, 0);
    }
}

void RangerNetMissionList::Render()
{
    if (unk_018 == NULL) {
        return;
    }
    unk_018->WriteOam();
    switch (unk_068) {
    case 0:
        break;
    case 1:
        break;
    case 2:
        if (unk_008 != NULL) {
            unk_008->SetOffset(0x41000, -0x17000);
            unk_008->ApplyProjection();
            unk_008->ApplyView();
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

void RangerNetMissionList::LoadGraphics()
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

    unk_018 = new OamSpriteSet((GXOamAttr *)unk_5F0->unk_0024, unk_5F0->unk_14A8, FALSE, 0x40);
    unk_018->Load("data/menu", "rn000_00", 0, 1);
    unk_01C[1] = unk_018->AddSprite(0, 0x80, 0x60, 1);
    unk_01C[2] = unk_018->AddSprite(1, 0x80, 0x60, 1);
    unk_01C[3] = unk_018->AddSprite(2, 0x80, 0x60, 1);
    unk_01C[4] = unk_018->AddSprite(3, 0x80, 0x60, 1);
    unk_01C[5] = unk_018->AddSprite(4, 0x80, 0x60, 1);
    unk_01C[6] = unk_018->AddSprite(5, 0x80, 0x60, 1);
    unk_01C[0] = unk_018->AddSprite(8, 0x80, 0x60, 1);
    HideSprites();

    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    unk_5F0->unk_1494->SetupBG(3, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x18000);
    unk_00C = new FieldDrawActorDataPool();
    unk_008 = new Camera2D();
    unk_008->SetOrtho(0, 0xC0000, 0, 0x100000, -0x400000, 0x800000, 0x400000);

    for (int i = 0; i < 6; i++) {
        u16 kind = sMissionEntries[i].kind;
        OS_SPrintf(path, "data/message/etc/mission_info_%02d", i + 0x50);
        unk_040[i] = new MessageTable(path);
        int type = 1;
        if (kind == 0) {
            kind = 3;
            type = 4;
        }
        unk_0A0[i].CreateDrawObject(type, kind, 0, 2, 0);
        if (unk_0A0[i].m_drawObject != NULL && unk_0A0[i].m_drawObject->m_actor != NULL) {
            unk_0A0[i].m_drawObject->m_actor->SetDir(0x4000);
        }
    }
}

void RangerNetMissionList::SetLayout(int mode)
{
    if (unk_068 == mode) {
        return;
    }
    unk_068 = mode;
    unk_5F0->unk_1494->SetupBG(3, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x18000);
    unk_5F0->unk_1494->FreeWindows();
    HideSprites();
    GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG3);
    switch (mode) {
    case 0:
        GX_SetVisiblePlane(GX_GetVisiblePlane() & ~GX_PLANEMASK_BG3);
        break;
    case 1:
        unk_01C[4]->SetVisible(TRUE);
        unk_5F0->unk_1494->AllocWindows(1);
        unk_5F0->unk_1494->InitWindow(0, 0x1A, 0x14, 3, 2, 8, 0, 2);
        break;
    case 2:
        unk_01C[0]->SetVisible(TRUE);
        unk_01C[1]->SetVisible(TRUE);
        unk_01C[2]->SetVisible(TRUE);
        unk_01C[3]->SetVisible(TRUE);
        unk_5F0->unk_1494->AllocWindows(4);
        unk_5F0->unk_1494->InitWindow(0, 0x18, 2, 4, 2, 8, 0, 2);
        unk_5F0->unk_1494->InitWindow(1, 0x11, 2, 5, 6, 0x38, 0, 2);
        unk_5F0->unk_1494->InitWindow(2, 0xF, 2, 6, 8, 0x5A, 0, 2);
        unk_5F0->unk_1494->InitWindow(3, 0x1E, 0xA, 2, 0xC, 0x78, 0, 2);
        break;
    case 3:
    case 4:
        unk_01C[5]->SetVisible(TRUE);
        unk_01C[6]->SetVisible(TRUE);
        unk_5F0->unk_1494->AllocWindows(2);
        unk_5F0->unk_1494->InitWindow(0, 0x1B, 0xA, 3, 2, 8, 0, 2);
        unk_5F0->unk_1494->InitWindow(1, 0x1B, 4, 3, 0x10, 0x116, 0, 2);
        break;
    }
    unk_018->Update();
    unk_018->WriteOam();
}

BOOL RangerNetMissionList::ShowMessage(int a, int b, MessageTable *c)
{
    unk_06C = a;
    ov11_0211D860(a);
    SetMessage(b, c);
    return TRUE;
}

BOOL RangerNetMissionList::ShowMission(int idx)
{
    unk_5EC = idx;
    unk_06C = 2;
    ov11_0211D860(2);
    SetMessage(1, unk_040[idx]);
    AddMessage(2);
    AddMessage(3);
    AddMessage(4);
    return TRUE;
}

void RangerNetMissionList::ov11_0211D860(int mode)
{
}

BOOL RangerNetMissionList::Load()
{
    LoadGraphics();
    LoadPalette();
    return TRUE;
}

void RangerNetMissionList::SetMessage(int a, MessageTable *b)
{
    unk_004 = 1;
    unk_070 = b;
    unk_09C = 0;
    AddMessage(a);
}

void RangerNetMissionList::AddMessage(int v)
{
    if (unk_09C < 10) {
        unk_074[unk_09C] = v;
        unk_09C++;
    }
}

void RangerNetMissionList::PrintPendingText()
{
    TextPrinter *tb;
    if (unk_004 == 0) {
        return;
    }
    unk_004 = 0;
    SetLayout(unk_06C);
    switch (unk_06C) {
    case 0:
        break;
    case 1:
        if (unk_070 == NULL) {
            return;
        }
        unk_5F0->unk_1494->ClearWindow(0);
        tb = unk_5F0->unk_1494;
        tb->Print(0, 0, 2, 3, (u8 *)unk_070->GetString(unk_074[0]), 0, 0);
        break;
    case 2:
        unk_070 = unk_040[unk_5EC];
        tb = unk_5F0->unk_1494;
        tb->Print(0, 0, 3, 3, (u8 *)unk_070->GetString(unk_074[0]), 1, 0);
        tb = unk_5F0->unk_1494;
        tb->Print(1, 0, 0, 3, (u8 *)unk_070->GetString(unk_074[1]), 1, 0);
        tb = unk_5F0->unk_1494;
        tb->Print(2, 0, 0, 3, (u8 *)unk_070->GetString(unk_074[2]), 1, 0);
        tb = unk_5F0->unk_1494;
        tb->Print(3, 0, 6, 3, (u8 *)unk_070->GetString(unk_074[3]), 0, 0);
        break;
    case 3:
        if (unk_070 == NULL) {
            return;
        }
        unk_5F0->unk_1494->ClearWindow(0);
        unk_5F0->unk_1494->ClearWindow(1);
        tb = unk_5F0->unk_1494;
        tb->Print(0, 0, 2, 3, (u8 *)unk_070->GetString(unk_074[0]), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->Print(0, 0, 0xE, 3, (u8 *)unk_070->GetString(0xF), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->Print(0, 0, 0x26, 3, (u8 *)unk_070->GetString(0x10), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->Print(0, 0, 0x32, 3, (u8 *)unk_070->GetString(0x11), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->Print(1, 0, 2, 3, (u8 *)unk_070->GetString(0x12), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->Print(1, 0x8C, 0xE, 3, (u8 *)unk_070->GetString(0x13), 0, 0);
        unk_058->PrintNumber(0, 0x50, 0x26, -1, 3, 1, 5);
        unk_058->PrintApplicationNo(0, 0x64, 0x32, 3, 1);
        break;
    case 4:
        if (unk_070 == NULL) {
            return;
        }
        unk_5F0->unk_1494->ClearWindow(0);
        unk_5F0->unk_1494->ClearWindow(1);
        tb = unk_5F0->unk_1494;
        tb->Print(0, 0, 2, 3, (u8 *)unk_070->GetString(unk_074[0]), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->Print(0, 0, 0xE, 3, (u8 *)unk_070->GetString(0xF), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->Print(0, 0, 0x26, 3, (u8 *)unk_070->GetString(0xA), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->Print(0, 0, 0x32, 3, (u8 *)unk_070->GetString(0x10), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->Print(1, 0, 2, 3, (u8 *)unk_070->GetString(0x11), 0, 0);
        tb = unk_5F0->unk_1494;
        tb->Print(1, 0x8C, 0xE, 3, (u8 *)unk_070->GetString(0x12), 0, 0);
        unk_058->PrintNumber(0, 0x50, 0x26, -1, 3, 1, 5);
        unk_058->PrintTrainerName(0, 0x50, 0x32, 0, 3, 1);
        break;
    }
}

void RangerNetMissionList::HideSprites()
{
    for (int i = 1; i < 7; i++) {
        if (unk_01C[i] != NULL) {
            unk_01C[i]->unk_14 = 0;
        }
    }
}
