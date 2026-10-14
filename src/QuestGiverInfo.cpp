#include "BGLayer.hpp"
#include "CActor.hpp"
#include "CGame.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "TextPrinter.hpp"
#include "scene/CQuestListScene.hpp"

static UnkStruct_021213AC sQuestActors[61] = {
    { 0x39, 0x04 },
    { 0x2B, 0x04 },
    { 0x2E, 0x04 },
    { 0x58, 0x09 },
    { 0x54, 0x0A },
    { 0x2B, 0x0A },
    { 0x2B, 0x09 },
    { 0x2D, 0x0A },
    { 0x24, 0x0E },
    { 0x2C, 0x01 },
    { 0x3B, 0x04 },
    { 0x28, 0x0F },
    { 0x57, 0x12 },
    { 0x30, 0x12 },
    { 0x2A, 0x0A },
    { 0x58, 0x0F },
    { 0x2C, 0x0A },
    { 0x24, 0x19 },
    { 0x66, 0x19 },
    { 0x5A, 0x0A },
    { 0x31, 0x12 },
    { 0x35, 0x1A },
    { 0x31, 0x0A },
    { 0x31, 0x0A },
    { 0x24, 0x21 },
    { 0x30, 0x21 },
    { 0x34, 0x21 },
    { 0x37, 0x04 },
    { 0x1C, 0x11 },
    { 0x20, 0x11 },
    { 0x24, 0x11 },
    { 0x86, 0x1A },
    { 0x02, 0x08 },
    { 0x28, 0x0E },
    { 0x56, 0x09 },
    { 0x27, 0x0F },
    { 0x30, 0x15 },
    { 0x86, 0x1A },
    { 0x30, 0x13 },
    { 0x30, 0x16 },
    { 0x04, 0x01 },
    { 0x03, 0x08 },
    { 0x30, 0x23 },
    { 0x2D, 0x11 },
    { 0x36, 0x1A },
    { 0x25, 0x08 },
    { 0x52, 0x21 },
    { 0x2E, 0x12 },
    { 0x26, 0x08 },
    { 0x54, 0x04 },
    { 0x64, 0x0E },
    { 0x01, 0x08 },
    { 0x2E, 0x21 },
    { 0x2C, 0x08 },
    { 0x05, 0x01 },
    { 0x57, 0x12 },
    { 0x38, 0x04 },
    { 0x66, 0x19 },
    { 0x1F, 0x11 },
    { 0x3A, 0x0A },
    { 0x3E, 0x16 },
};

static void ov27_02120E2C(void *arg);

QuestGiverInfo::QuestGiverInfo()
{
    ov27_0212062C();
}

QuestGiverInfo::~QuestGiverInfo()
{
    ov27_02120758();
}

void QuestGiverInfo::ov27_0212062C()
{
    unk_0000 = -1;
    unk_0005 = FALSE;
    unk_000C = NULL;
    unk_0010 = NULL;
    unk_002C = NULL;
    unk_01F1 = FALSE;
    unk_01F0 = 0;
    unk_0008 = -1;
    OS_InitMessageQueue(&unk_12BC, unk_12DC, 1);
    OS_CreateThread(&unk_01FC, ov27_02120E2C, this, unk_02BC + sizeof(unk_02BC), sizeof(unk_02BC), 20);
    OS_WakeupThreadDirect(&unk_01FC);
}

void QuestGiverInfo::ov27_021206B4()
{
    G2_SetBG1Offset(0, -((int)CGame::GetInstance()->unk_15D0 >> FX32_SHIFT));
    if (unk_0010 == NULL) {
        return;
    }
    unk_0010->Update();
    if (unk_01F1) {
        unk_0030[unk_01F0].Update(NULL);
    }
    if (unk_0008 < 0) {
        return;
    }
    if (OS_SendMessage(&unk_12BC, (OSMessage)unk_0008, OS_MESSAGE_NOBLOCK)) {
        unk_0008 = -1;
    }
}

void QuestGiverInfo::ov27_02120748()
{
    ov27_021207E4();
}

void QuestGiverInfo::ov27_02120754()
{
}

void QuestGiverInfo::ov27_02120758()
{
    CGame::GetInstance()->unk_1494->FreeWindows();
    SAFE_DELETE(unk_000C);
    SAFE_DELETE(unk_0010);
    unk_0008 = -1;
    OS_SendMessage(&unk_12BC, (OSMessage)-1, OS_MESSAGE_BLOCK);
    OS_JoinThread(&unk_01FC);
}

static inline void DrawActor(CFieldActor *actor, Camera2D *camera)
{
    if (actor->unk_08 != NULL) {
        actor->unk_08->Draw(camera, 0);
    }
}

void QuestGiverInfo::ov27_021207E4()
{
    if (unk_0010 == NULL) {
        return;
    }
    unk_0010->WriteOam();
    if (unk_000C == NULL) {
        return;
    }
    unk_000C->SetOffset(0x41000, -0x17000);
    unk_000C->ApplyProjection();
    unk_000C->ApplyView();
    G3_StoreMtx(0);
    if (unk_01F1) {
        DrawActor(&unk_0030[unk_01F0], unk_000C);
    }
}

void QuestGiverInfo::ov27_02120870(BOOL noInfo)
{
    CGame *game = CGame::GetInstance();
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
    BGS_LoadCharAndPltt("menu/", "mmq000_bg_", 1, "mmq000", 0, "mmq000", 1);
    BGS_LoadScr("menu/", "mmq000_bg_", 2, "mmq000_02", 1, 0, 0, 0);
    BGS_LoadScr("menu/", "mmq000_bg_", 1, "mmq000_01", 1, 0, 0, 0);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_BG1, GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2, 8, 7);

    unk_0010 = new OamSpriteSet((GXOamAttr *)&game->unk_0024[0x0A], game->unk_14A8, FALSE, 0x40);
    unk_0010->Load("data/menu", "mmq000_00", 0, 1);
    unk_0014[5] = unk_0010->AddSprite(5, 0x80, 0x60, 1);
    unk_0014[0] = unk_0010->AddSprite(2, 0x16, 0x17, 1);
    unk_0014[1] = unk_0010->AddSprite(2, 0xEA, 0x17, 1);
    unk_0014[2] = unk_0010->AddSprite(0, 0x80, 0x18, 1);
    unk_0014[3] = unk_0010->AddSprite(3, 0x80, 0x90, 1);
    unk_0014[4] = unk_0010->AddSprite(4, 0x78, 0x38, 1);
    if (noInfo) {
        for (int i = 0; i < 6; i++) {
            if (i != 5 && unk_0014[i] != NULL) {
                unk_0014[i]->unk_14 = 0;
            }
        }
        return;
    }

    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    TextPrinter *text = game->unk_1494;
    text->FreeWindows();
    text->SetupBG(3, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x18000);
    text->AllocWindows(4);
    text->InitWindow(0, 0x18, 2, 4, 2, 8, 0, 2);
    text->InitWindow(1, 0x11, 2, 5, 6, 0x38, 0, 2);
    text->InitWindow(2, 0xF, 2, 6, 8, 0x5A, 0, 2);
    text->InitWindow(3, 0x1E, 0xA, 1, 0xC, 0x78, 0, 2);
    unk_000C = new Camera2D();
    unk_000C->SetOrtho(0, 0xC0000, 0, 0x100000, -0x400000, 0x800000, 0x400000);
}

BOOL QuestGiverInfo::ov27_02120CA8(QLMessageStrings *info, int questId, BOOL notCleared)
{
    unk_002C = info;
    unk_0005 = notCleared;
    unk_01F1 = TRUE;
    unk_0008 = questId;
    return TRUE;
}

BOOL QuestGiverInfo::ov27_02120CC4(BOOL noInfo)
{
    ov27_02120870(noInfo);
    return TRUE;
}

void QuestGiverInfo::ov27_02120CD4()
{
    TextPrinter *text = CGame::GetInstance()->unk_1494;
    text->ClearWindow(0);
    text->ClearWindow(1);
    text->ClearWindow(2);
    text->ClearWindow(3);
    if (unk_01F1 && unk_002C != NULL) {
        text->Print(0, 0, 2, 3, (u8 *)unk_002C->ov27_0211FB38(unk_0005 ? 5 : 1), 1, 0);
        text->Print(1, 0, 0, 3, (u8 *)unk_002C->ov27_0211FB38(2), 1, 0);
        text->Print(2, 0, 0, 3, (u8 *)unk_002C->ov27_0211FB38(3), 1, 0);
        text->Print(3, 2, 6, 1, (u8 *)unk_002C->ov27_0211FB38(unk_0005 ? 6 : 4), 0, 0);
    }
}

static void ov27_02120E2C(void *arg)
{
    QuestGiverInfo *p = (QuestGiverInfo *)arg;
    if (p == NULL) {
        return;
    }
    while (TRUE) {
        OSMessage msg;
        OS_ReceiveMessage(&p->unk_12BC, &msg, OS_MESSAGE_BLOCK);
        if ((int)msg < 0) {
            break;
        }
        p->ov27_02120E70((int)msg);
    }
}

void QuestGiverInfo::ov27_02120E70(int questId)
{
    if (unk_0000 == questId) {
        return;
    }
    u16 id = sQuestActors[questId - 1].actorId;
    int type = 1;
    if (id == 0) {
        type = 4;
        id = 3;
    }
    unk_0030[1 - unk_01F0].CreateDrawObject(type, id, 0, 2, 0);
    if (unk_0030[1 - unk_01F0].unk_08 != NULL && unk_0030[1 - unk_01F0].unk_08->unk_0C != NULL) {
        unk_0030[1 - unk_01F0].unk_08->unk_0C->SetDir(0x4000);
    }
    unk_01F0 = 1 - unk_01F0;
    ov27_02120CD4();
    unk_0000 = questId;
}
