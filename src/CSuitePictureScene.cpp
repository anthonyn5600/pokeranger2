#include "scene/CSuitePictureScene.hpp"

#include "AudioEngine.hpp"
#include "BGLayer.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "DisplayUtil.hpp"

extern int MAIN_BSS_0210CAB0;

static SuitePictureMsg sMsgs_0211D630[] = {
    { 2, 8, 1 },
    { -1, 0, 0 },
};

static SuitePictureMsg sMsgs_0211D648[] = {
    { 2, 7, 1 },
    { -1, 0, 0 },
};

static SuitePictureMsg sMsgs_0211D600[] = {
    { 2, 6, 1 },
    { -1, 0, 0 },
};

static SuitePictureMsg sMsgs_0211D618[] = {
    { 2, 0xD, 1 },
    { -1, 0, 0 },
};

static SuitePictureMsg sMsgs_0211D660[] = {
    { 2, 0xE, 1 },
    { 2, 0xF, 0 },
    { -1, 0, 0 },
};

static SuitePicture sPictures_0211D79C[] = {
    { 0, 0, NULL, 0, 1 },
    { 1, 0, NULL, 0, 1 },
    { 2, 0, NULL, 0, 1 },
    { 3, 0, NULL, 0, 1 },
    { 4, 0, NULL, 0, 1 },
    { 5, 0, NULL, 0, 1 },
    { 6, 0, NULL, 0, 1 },
    { 7, 0, NULL, 0, 1 },
    { 8, 0, NULL, 0, 1 },
    { 9, 0, NULL, 0, 1 },
    { 10, 0, NULL, 0, 1 },
    { 20, 0, NULL, 0, 1 },
    { 21, 0, NULL, 0, 1 },
    { 22, 0, NULL, 0, 1 },
    { 23, 0, NULL, 0, 1 },
    { 24, 0, NULL, 0, 1 },
    { 25, 0, NULL, 0, 1 },
    { 26, 0, NULL, 0, 1 },
    { 27, 0, NULL, 0, 1 },
    { 28, 0, NULL, 0, 1 },
    { 29, 0, NULL, 0, 1 },
    { 30, 0, NULL, 0, 1 },
    { 31, 0, NULL, 0, 1 },
    { 32, 0, NULL, 0, 1 },
    { 33, 0, NULL, 0, 1 },
    { 34, 0, NULL, 0, 1 },
    { 35, 0, NULL, 0, 1 },
    { 36, 0, NULL, 0, 1 },
    { 37, 0, NULL, 0, 1 },
    { 38, 0, NULL, 0, 1 },
    { 50, 0, NULL, 0, 1 },
    { 51, 0, NULL, 0, 1 },
    { 52, 0, NULL, 0, 1 },
    { 53, 0, NULL, 0, 1 },
    { 54, 0, NULL, 0, 1 },
    { 55, 0, NULL, 0, 1 },
    { 56, 0, NULL, 0, 1 },
    { 57, 0, NULL, 0, 1 },
    { -1, 0, NULL, 0, 1 },
};

static SuitePicture sPictures_0211D6FC[] = {
    { 0x32, 0x18, sMsgs_0211D618, -60, 0 },
    { 0x34, 0x18, sMsgs_0211D660, -60, 0 },
    { 0x39, 0x18, sMsgs_0211D600, -60, 0 },
    { -1, 0, NULL, 0, 0 },
};

static SuitePicture sPictures_0211D74C[] = {
    { 0x33, 0x18, sMsgs_0211D618, -60, 0 },
    { 0x34, 0x18, sMsgs_0211D660, -60, 0 },
    { 0x39, 0x18, sMsgs_0211D600, -60, 0 },
    { -1, 0, NULL, 0, 0 },
};

static SuitePicture sPictures_0211D6C0[] = {
    { 0x35, 0x17, sMsgs_0211D648, -60, 0 },
    { 0x37, 0x17, sMsgs_0211D630, -60, 0 },
    { -1, 0, NULL, 0, 0 },
};

static SuitePicture sPictures_0211D684[] = {
    { 0x36, 0x17, sMsgs_0211D648, -60, 0 },
    { 0x38, 0x17, sMsgs_0211D630, -60, 0 },
    { -1, 0, NULL, 0, 0 },
};

static SuitePicture *sPictureLists[] = {
    sPictures_0211D79C,
    sPictures_0211D6FC,
    sPictures_0211D74C,
    sPictures_0211D6C0,
    sPictures_0211D684,
};

CSuitePictureScene::CSuitePictureScene()
{
    unk_0004 = 0;
    unk_0008 = 0;
    unk_001C = 0;
    unk_000C = NULL;
    unk_0010 = NULL;
    unk_0014 = NULL;
    unk_0018 = NULL;
}

CSuitePictureScene::~CSuitePictureScene()
{
    func7();
}

u32 CSuitePictureScene::func0()
{
    switch (unk_0008) {
    case 0:
        if (s_game->m_mainFade->IsActive()) {
            break;
        }
        if (s_game->m_subFade->IsActive()) {
            break;
        }
        if (unk_0014 != NULL && unk_0014->unk_00 >= 0) {
            s_game->m_textboxData->ResetTextSpeed();
            s_game->m_textboxData->ShowMessage(unk_0014->unk_00, unk_0014->unk_04, unk_0014->unk_08, 1, 0);
            unk_0014++;
            unk_0008 = 1;
        } else {
            unk_0014 = NULL;
            unk_0008 = 2;
        }
        unk_0004 = 0;
        break;
    case 1:
        if (s_game->m_textboxData->IsActive()) {
            break;
        }
        s_game->m_textboxData->CloseAndClear(1, 1);
        if (unk_0014 != NULL && unk_0014->unk_00 >= 0) {
            s_game->m_textboxData->ResetTextSpeed();
            s_game->m_textboxData->ShowMessage(unk_0014->unk_00, unk_0014->unk_04, unk_0014->unk_08, 1, 0);
            unk_0014++;
            unk_0008 = 1;
        } else {
            unk_0014 = NULL;
            unk_0008 = 2;
            unk_0004 = 0;
        }
        break;
    case 2:
        if (unk_0004 < MATH_ABS(unk_001C)) {
            unk_0004++;
        } else {
            if (unk_001C < 0) {
                unk_0008 = 4;
            } else {
                GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_OBJ);
                unk_0008 = 3;
            }
            unk_0004 = 0;
        }
        break;
    case 3:
        if (s_game->touchPanel->unk_04 != 0 || (u16)(s_game->unk_0014->unk_0002 & 3)) {
            unk_0008 = 4;
        }
        break;
    case 4:
        if (unk_0018 != NULL) {
            unk_0020 = unk_0018->unk_10;
        }
        if (unk_0020 == 0) {
            s_game->m_mainFade->Start(4, 20);
            s_game->m_subFade->Start(4, 20);
        } else {
            s_game->m_mainFade->Start(2, 20);
            s_game->m_subFade->Start(2, 20);
        }
        if (unk_0014 == NULL) {
            s_game->m_audioEngine->PlaySe(3);
        }
        unk_0008 = 5;
        break;
    case 5:
        if (s_game->m_mainFade->IsActive()) {
            break;
        }
        if (s_game->m_subFade->IsActive()) {
            break;
        }
        if (unk_0018 != NULL && unk_0018->id >= 0) {
            unk_0014 = unk_0018->msgs;
            unk_001C = unk_0018->unk_0C;
            unk_0020 = unk_0018->unk_10;
            LoadPicture(unk_0018->id);
            s_game->m_textboxData->LoadChapterMessages(unk_0018->unk_04);
            unk_0018++;
            if (unk_0020 == 0) {
                s_game->m_mainFade->Start(3, 20);
                s_game->m_subFade->Start(3, 20);
            } else {
                s_game->m_mainFade->Start(1, 20);
                s_game->m_subFade->Start(1, 20);
            }
            unk_0008 = 0;
            unk_0004 = 0;
        } else {
            return 1;
        }
        break;
    }

    unk_000C->Update();
    return -1;
}

void CSuitePictureScene::func1()
{
    if (unk_0008 == 3) {
        unk_000C->WriteOam();
    }
}

void CSuitePictureScene::func2()
{
}

void CSuitePictureScene::func5()
{
    GX_ResetBankForBG();
    GX_ResetBankForOBJ();
    GX_ResetBankForBGExtPltt();
    GX_ResetBankForOBJExtPltt();
    GX_ResetBankForTex();
    GX_ResetBankForTexPltt();
    GX_ResetBankForClearImage();
    GX_ResetBankForSubBG();
    GX_ResetBankForSubOBJ();
    GX_ResetBankForSubBGExtPltt();
    GX_ResetBankForSubOBJExtPltt();
    GX_ResetBankForARM7();

    GX_SetBankForTex(GX_VRAM_TEX_NONE);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_NONE);
    GX_SetBankForOBJ(GX_VRAM_OBJ_32_FG);
    GX_SetBankForBG(GX_VRAM_BG_256_AB);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
    GX_SetBankForBGExtPltt(GX_VRAM_BGEXTPLTT_0123_E);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_128_D);
    GX_SetBankForSubBGExtPltt(GX_VRAM_SUB_BGEXTPLTT_0123_H);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_OBJ);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG0);
    GX_DispOn();
    GXS_DispOn();

    G2S_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_256, GX_BG_SCRBASE_0x0000, GX_BG_CHARBASE_0x08000, GX_BG_EXTPLTT_01);
    G2_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_256, GX_BG_SCRBASE_0x8000, GX_BG_CHARBASE_0x10000, GX_BG_EXTPLTT_01);
    G2_SetBG0Priority(1);
    G2_SetBG1Priority(0);
}

void CSuitePictureScene::func6()
{
    s_game->unk_146C.SetFps(60);
    s_game->m_textboxData->Init(s_game->unk_0014, s_game->touchPanel, &s_game->unk_14AC->unk_0C, s_game->m_nameTables, s_game->unk_0024, s_game->m_audioEngine, 0x10, 0x4000, 0);
    SetupBGFonts();
    s_game->m_textboxData->LoadSystemMessages(0);

    unk_000C = new OamSpriteSet((GXOamAttr *)s_game->unk_0024, s_game->unk_14A8, FALSE, 0x40);
    unk_000C->Load("data/eventicon", "eventicon000", 0, 8);
    unk_0010 = unk_000C->AddSprite(0, 0xF0, 0xB3, 0);
    unk_0010->unk_14 = 1;
    s_game->m_audioEngine->LoadSystemSe();

    switch (MAIN_BSS_0210CAB0 / 1000) {
    case 0:
    default:
        unk_0014 = NULL;
        unk_0018 = NULL;
        unk_001C = 120;
        unk_0020 = 1;
        LoadPicture(MAIN_BSS_0210CAB0 % 1000);
        break;
    case 1:
        unk_0018 = sPictureLists[MAIN_BSS_0210CAB0 % 1000];
        unk_0014 = unk_0018->msgs;
        unk_001C = unk_0018->unk_0C;
        unk_0020 = unk_0018->unk_10;
        LoadPicture(unk_0018->id);
        s_game->m_textboxData->LoadChapterMessages(unk_0018->unk_04);
        unk_0018++;
        break;
    }

    unk_0008 = 0;
    unk_0004 = 0;
    if (unk_0020 == 0) {
        s_game->m_mainFade->Start(3, 30);
        s_game->m_subFade->Start(3, 30);
    } else {
        s_game->m_mainFade->Start(1, 30);
        s_game->m_subFade->Start(1, 30);
    }
}

void CSuitePictureScene::func7()
{
    s_game->m_textboxData->FreeSystemMessages();
    s_game->m_textboxData->Reset();
    SAFE_DELETE(unk_000C);
    s_game->unk_146C.SetFps(30);
}

void CSuitePictureScene::LoadPicture(int id)
{
    char arc[30];
    char name[30];
    const char *dir = "event/";

    OS_SPrintf(arc, "event%03d_00_", id);
    OS_SPrintf(name, "event%03d_00", id);
    BGLayer *bg1 = new BGLayer(PTR_CAST(int, s_game));
    BGLayer *bg2 = new BGLayer(PTR_CAST(int, s_game));

    bg1->SetBG(4);
    bg1->LoadArchive(dir, arc);
    bg1->LoadChar(name, 0, 0, 0);
    bg1->LoadPltt(name, 0, 0, 0);
    bg1->LoadScr(name, 0, 0, 0, 0, 0);
    bg1->ReleaseArchive();
    bg1->LoadCharToVram();
    bg1->LoadPlttToVram(TRUE);
    bg1->LoadScrToVram();

    OS_SPrintf(arc, "event%03d_01_", id);
    OS_SPrintf(name, "event%03d_01", id);
    bg2->SetBG(0);
    bg2->LoadArchive(dir, arc);
    bg2->LoadChar(name, 0, 0, 0);
    bg2->LoadPltt(name, 0, 0, 0);
    bg2->LoadScr(name, 0, 0, 0, 0, 0);
    bg2->ReleaseArchive();
    bg2->LoadCharToVram();
    bg2->LoadPlttToVram(TRUE);
    bg2->LoadScrToVram();

    delete bg2;
    delete bg1;
}

u32 CSuitePictureScene::getSceneId()
{
    return 0x1B;
}
