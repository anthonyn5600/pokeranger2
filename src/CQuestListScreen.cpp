#include "AudioEngine.hpp"
#include "BGLayer.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "MissionQuestData.hpp"
#include "OamSpriteSet.hpp"
#include "SubTextPrinter.hpp"
#include "file/CArchiveGuard.hpp"
#include "heap.hpp"
#include "scene/CQuestListScene.hpp"

CQuestListScreen::CQuestListScreen(QuestGiverInfo *map)
    : unk_044(NULL)
    , unk_184(1)
    , unk_338(0)
    , unk_33C(NULL)
    , unk_34C(NULL)
    , unk_35C(map)
{
    MI_CpuClear8(unk_010, sizeof(unk_010));
}

CQuestListScreen::~CQuestListScreen()
{
    SAFE_DELETE_ARRAY(unk_34C);
    SAFE_DELETE_ARRAY(unk_33C);
}

void CQuestListScreen::ov27_0211D0E0()
{
    unk_350 = GXS_GetDispCnt().bgMode;
    unk_354 = GXS_GetVisibleWnd();
    unk_358 = G2S_GetWnd0InsidePlane();
    unk_359 = G2S_GetWndOutsidePlane();
}

void CQuestListScreen::ov27_0211D150()
{
    G2S_SetWnd0InsidePlane(unk_358.planeMask, unk_358.effect);
    G2S_SetWndOutsidePlane(unk_359.planeMask, unk_359.effect);
    GXS_SetVisibleWnd(unk_354);
    GXS_SetGraphicsMode((GXBGMode)unk_350);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
}

void CQuestListScreen::func2()
{
    CGame::GetInstance()->unk_1498->SetupBG();
    G2S_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x8000, GX_BG_CHARBASE_0x00000, GX_BG_EXTPLTT_23);
    MI_CpuClearFast((void *)HW_DB_BG_VRAM, 0x20);
    MI_CpuClearFast(G2S_GetBG0ScrPtr(), 0x800);
    ov27_0211DBB4();
    GXS_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2S_SetWnd0Position(0, 48, 255, 160);
    G2S_SetWnd0InsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ,
        FALSE);
    G2S_SetWnd1Position(0, 24, 255, 38);
    G2S_SetWnd1InsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_OBJ,
        FALSE);
    G2S_SetWndOutsidePlane(GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_OBJ, FALSE);
    GXS_SetVisibleWnd(GX_WNDMASK_W0 | GX_WNDMASK_W1);
}

void CQuestListScreen::func0()
{
    ov27_0211DE28();
    ov27_0211DC64();
    unk_044 = unk_038.ov27_0211E2B8("data/menu", "ql000_00", 5, -1);
    unk_184.ov27_0211E958(0, unk_044, 8, 11, 12, 13, 8, 48, 208, 112, 8, 13, 0, unk_010[2].data);
    unk_184.SetListener(this);
    unk_04C[0].ov27_0211E394(0, unk_044, 0, 1, 232, 51, 24, 24, 1, 0);
    unk_04C[0].unk_10 = this;
    unk_04C[1].ov27_0211E394(1, unk_044, 2, 3, 232, 173, 24, 24, 1, 0);
    unk_04C[1].unk_10 = this;
    unk_04C[2].ov27_0211E394(2, unk_044, 4, 5, 232, 92, 16, 16, 1, 0);
    unk_04C[2].unk_10 = this;
    unk_04C[3].ov27_0211E394(3, unk_044, 6, 7, 232, 132, 16, 16, 1, 0);
    unk_04C[3].unk_10 = this;
    unk_04C[4].ov27_0211E394(4, unk_044, 14, 15, 160, 178, 104, 16, 1, 1);
    unk_04C[4].unk_10 = this;
    unk_04C[4].unk_30 = unk_184.ov27_0211F648(0) > 0 ? TRUE : FALSE;
    unk_31C.ov27_0211F8C8(unk_044, 9, 10, 154, 17, 1);
    unk_038.ov27_0211E374(unk_044, -1);
    unk_048 = unk_038.ov27_0211E2B8("data/menu", "ma005_00", 1, -1);
    unk_04C[5].ov27_0211E394(5, unk_048, 0, 0, 240, 16, 24, 24, 0, 0);
    unk_04C[5].unk_10 = this;
    unk_044->Update();
}

void CQuestListScreen::func1()
{
    for (int i = 0; i < 5; i++) {
        if (unk_010[i].data != NULL) {
            Heap_Free(unk_010[i].data);
            unk_010[i].data = NULL;
        }
        unk_010[i].size = 0;
    }
    SAFE_DELETE(unk_048);
    SAFE_DELETE(unk_044);
    SAFE_DELETE_ARRAY(unk_34C);
    SAFE_DELETE_ARRAY(unk_33C);
}

void CQuestListScreen::func3(int prev)
{
    int charNo;
    int i;
    CGame *game = CGame::GetInstance();
    ov27_0211DDC0();
    unk_184.ov27_0211EACC();
    if (unk_044 != NULL) {
        unk_044->CopyToVram();
    }
    if (unk_048 != NULL) {
        unk_048->CopyToVram();
    }
    SubTextPrinter *text = game->unk_1498;
    text->FreeWindows();
    text->AllocWindows(16);
    for (charNo = 0, i = 0; i < 16; charNo += 64, i++) {
        text->InitWindow(i, 32, 2, 0, i * 2, charNo, 0, 2);
    }
    unk_04 = 0;
    int current = -1;
    for (int i = 0; i < unk_338; i++) {
        if (unk_34C[i].unk_04 == 2) {
            current = i;
            break;
        }
    }
    text->ClearWindow(15);
    const char *title;
    if (current >= 0) {
        title = unk_34C[current].unk_00;
    } else {
        title = unk_340.ov27_0211FB38(7);
    }
    if (title != NULL) {
        text->Print(15, 24, 2, 3, (u8 *)title, FALSE, 0);
    }
    unk_31C.ov27_0211F954(current >= 0 ? TRUE : FALSE);
    unk_184.ov27_0211F4B0(0);
    if (prev < 0 && unk_338 > 0) {
        if (current >= 0) {
            unk_184.ov27_0211EBEC(current);
        } else {
            unk_184.ov27_0211EBEC(0);
        }
    }
    unk_184.ov27_0211EF30();
    if (unk_338 > 0) {
        int cursor = unk_184.ov27_0211EBB8();
        if (unk_35C != NULL && unk_33C != NULL && unk_34C != NULL) {
            int id = unk_34C[cursor].unk_08;
            unk_35C->ov27_02120CA8(&unk_33C[cursor], id, !MissionQuestData_IsQuestEntered(&MAIN_BSS_020B2638, id) ? TRUE : FALSE);
        }
    }
    for (int i = 0; i < 6; i++) {
        unk_04C[i].ov27_0211E7CC();
    }
    GXS_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    game->m_subFade->Start(3, 15);
}

int CQuestListScreen::func4()
{
    CGame *game = CGame::GetInstance();
    int ret = 0;
    switch (unk_04) {
    case 0:
        if (!game->m_mainFade->IsActive() && !game->m_subFade->IsActive()) {
            unk_04 = 1;
        }
        break;
    case 1:
        unk_04C[2].unk_18 = (u16)(game->unk_0014->unk_0000 & PAD_KEY_UP);
        unk_04C[3].unk_18 = (u16)(game->unk_0014->unk_0000 & PAD_KEY_DOWN);
        unk_04C[0].unk_18 = (u16)(game->unk_0014->unk_0000 & PAD_KEY_LEFT);
        unk_04C[1].unk_18 = (u16)(game->unk_0014->unk_0000 & PAD_KEY_RIGHT);
        unk_04C[4].unk_18 = (u16)(game->unk_0014->unk_0000 & PAD_BUTTON_A);
        unk_04C[5].unk_18 = (u16)(game->unk_0014->unk_0002 & PAD_BUTTON_B);
        for (int i = 0; i < 6; i++) {
            unk_04C[i].ov27_0211E438();
        }
        if (unk_044 != NULL) {
            unk_044->Update();
        }
        if (unk_048 != NULL) {
            unk_048->Update();
        }
        unk_184.ov27_0211F140();
        unk_31C.ov27_0211F9C0();
        break;
    case 2:
        if (!game->m_mainFade->IsActive() && !game->m_subFade->IsActive()) {
            ret = -1;
        }
        break;
    case 3:
        if (!game->m_subFade->IsActive()) {
            ret = 1;
        }
        break;
    }
    for (int i = 0; i < 6; i++) {
        unk_04C[i].ov27_0211E64C();
    }
    unk_184.ov27_0211F294();
    if (ret != 0) {
        OS_CancelAllVAlarms();
        GXS_SetVisibleWnd(GX_WNDMASK_NONE);
        game->unk_1498->FreeWindows();
    }
    return ret;
}

void CQuestListScreen::func5()
{
    if (unk_044 != NULL) {
        unk_044->WriteOam();
    }
    if (unk_048 != NULL) {
        unk_048->WriteOam();
    }
}

void CQuestListScreen::ov27_0211DB4C()
{
    CGame *game = CGame::GetInstance();
    unk_04 = 2;
    game->m_audioEngine->PlaySe(0x103);
    game->m_mainFade->Start(4, 15);
    game->m_subFade->Start(4, 15);
}

void CQuestListScreen::func7()
{
    unk_184.ov27_0211F674();
}

void CQuestListScreen::ov27_0211DBB4()
{
    GXS_SetGraphicsMode(GX_BGMODE_0);
    G2S_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x8800, GX_BG_CHARBASE_0x0c000, GX_BG_EXTPLTT_01);
    G2S_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x9000, GX_BG_CHARBASE_0x0c000);
    G2S_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x9800, GX_BG_CHARBASE_0x0c000);
    G2S_SetBG0Priority(0);
    G2S_SetBG1Priority(3);
    G2S_SetBG2Priority(2);
    G2S_SetBG3Priority(1);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
}

void CQuestListScreen::ov27_0211DC64()
{
    ov27_0211DBB4();
    CArchiveGuard guard("BGS", "data/menu/ql000_bg_LZ.bin", 1, 1, 0, NULL, 0);
    unk_010[0].data = BGS_LoadCharByName("BGS", 5, "ql000", 0, 1, 0);
    unk_010[0].size = gBGLoadedSize;
    unk_010[1].data = BGS_LoadPlttByName("BGS", 5, "ql000", 0, 1, 0);
    unk_010[1].size = gBGLoadedSize;
    unk_010[4].data = BGS_LoadScrByName("BGS", 5, "ql000_02", 0, 0, 1, 0, 0);
    unk_010[4].size = gBGLoadedSize;
    unk_010[3].data = BGS_LoadScrByName("BGS", 6, "ql000_01", 0, 0, 1, 0, 0);
    unk_010[3].size = gBGLoadedSize;
    unk_010[2].data = BGS_LoadScrByName("BGS", 7, "ql000_03", 0, 0, 1, 0, 0);
    unk_010[2].size = gBGLoadedSize;
}

void CQuestListScreen::ov27_0211DDC0()
{
    BG_LoadChar(5, unk_010[0].data, unk_010[0].size, 0);
    BG_LoadPltt(5, unk_010[1].data, unk_010[1].size, 0, FALSE);
    BG_LoadScr(5, unk_010[4].data, unk_010[4].size, 0);
    BG_LoadScr(6, unk_010[3].data, unk_010[3].size, 0);
}

void CQuestListScreen::ov27_0211DE28()
{
    u8 ids[61];
    char path[0x60];
    MissionQuestData *quests = &MAIN_BSS_020B2638;

    OS_SPrintf(path, "data/message/etc/quest_info_%02d", 61);
    unk_340.ov27_0211FA84(path);
    unk_338 = 0;
    for (int id = 1; id < 62; id++) {
        if (MissionQuestData_IsQuestActive(quests, id) || MissionQuestData_IsQuestCleared(quests, id)) {
            ids[unk_338++] = id;
        }
    }
    if (unk_338 <= 0) {
        return;
    }
    unk_33C = new QLMessageStrings[unk_338];
    if (unk_33C != NULL) {
        for (int i = 0; i < unk_338; i++) {
            OS_SPrintf(path, "data/message/etc/quest_info_%02d", ids[i]);
            unk_33C[i].ov27_0211FA84(path);
        }
    }
    unk_34C = new UnkStruct_0211DE28[unk_338];
    if (unk_34C == NULL) {
        return;
    }
    for (int i = 0; i < unk_338; i++) {
        unk_34C[i].unk_00 = unk_33C[i].ov27_0211FB38(1);
        unk_34C[i].unk_08 = ids[i];
        if (MissionQuestData_IsQuestCleared(quests, ids[i])) {
            unk_34C[i].unk_04 = 1;
        } else if (MissionQuestData_IsQuestActive(quests, ids[i])) {
            if (quests->m_questActive == 1 && ids[i] == quests->m_questId) {
                unk_34C[i].unk_04 = 2;
            } else {
                unk_34C[i].unk_04 = 0;
                if (!MissionQuestData_IsQuestEntered(quests, ids[i])) {
                    unk_34C[i].unk_00 = unk_340.ov27_0211FB38(5);
                }
            }
        }
    }
    unk_184.ov27_0211EB84(0, unk_34C, unk_338);
}

void CQuestListScreen::OnPushButton(int id, BOOL repeat)
{
    if (unk_04 == 2) {
        return;
    }
    switch (id) {
    case 0:
        unk_360 = TRUE;
        unk_184.ov27_0211EEB8();
        break;
    case 1:
        unk_360 = TRUE;
        unk_184.ov27_0211EE28();
        break;
    case 2:
        unk_360 = TRUE;
        unk_184.ov27_0211ED84();
        break;
    case 3:
        unk_360 = TRUE;
        unk_184.ov27_0211EC68();
        break;
    case 5:
        ov27_0211DB4C();
        break;
    case 4:
        CGame::GetInstance()->m_subFade->Start(4, 15);
        unk_04 = 3;
        break;
    }
}

void CQuestListScreen::OnReleaseButton(int id)
{
}

void CQuestListScreen::OnListBoxEvent0(int id, int idx)
{
}

void CQuestListScreen::OnListBoxEvent1(int id, int cursor, u32 flags, u8 changed)
{
    if (cursor >= 0 && unk_35C != NULL && unk_33C != NULL && unk_34C != NULL && (unk_360 || changed)) {
        int questId = unk_34C[cursor].unk_08;
        unk_35C->ov27_02120CA8(&unk_33C[cursor], questId, !MissionQuestData_IsQuestEntered(&MAIN_BSS_020B2638, questId) ? TRUE : FALSE);
        unk_360 = FALSE;
    }
    unk_04C[0].unk_30 = (flags & 2) ? TRUE : FALSE;
    unk_04C[2].unk_30 = (flags & 8) ? TRUE : FALSE;
    unk_04C[1].unk_30 = (flags & 1) ? TRUE : FALSE;
    unk_04C[3].unk_30 = (flags & 4) ? TRUE : FALSE;
}

void CQuestListScreen::OnListBoxEvent2()
{
}

int CQuestListScreen::ov27_0211E204()
{
    int id = 0;
    int cursor = unk_184.ov27_0211EBB8();
    if (cursor >= 0 && unk_34C != NULL) {
        id = unk_34C[cursor].unk_08;
    }
    return id;
}
