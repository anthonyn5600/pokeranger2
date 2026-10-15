#include "scene/CMissionQuestScene.hpp"

#include "AudioEngine.hpp"
#include "BrightnessFade.hpp"
#include "MissionQuestData.hpp"
#include "SubTextPrinter.hpp"
#include "TextPrinter.hpp"

extern FieldData *MAIN_BSS_0210CA6C;

CMissionQuestScene::CMissionQuestScene(CGame *game)
{
    m_game = game;
    Create();
}

CMissionQuestScene::~CMissionQuestScene()
{
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    SAFE_DELETE(unk_08);
}

void CMissionQuestScene::Create()
{
    unk_08 = new MissionQuestMap(m_game);
}

void CMissionQuestScene::func5()
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

    GX_SetBankForTex(GX_VRAM_TEX_0_B);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_0_G);
    GX_SetBankForOBJ(GX_VRAM_OBJ_80_EF);
    GX_SetBankForBG(GX_VRAM_BG_128_A);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
    GXS_SetGraphicsMode(GX_BGMODE_0);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_128_D);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);
    GX_SetBGScrOffset(GX_BGSCROFFSET_0x00000);
    GX_SetBGCharOffset(GX_BGCHAROFFSET_0x00000);
    GX_SetVisiblePlane(GX_PLANEMASK_NONE);
    GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
    GX_DispOn();
    GXS_DispOn();
}

void CMissionQuestScene::func6()
{
    m_game->InitVramManagers(0x20000, 0, 0x4000);
    if (unk_08 != NULL) {
        unk_08->Start();
        unk_08->FadeIn();
    }
}

void CMissionQuestScene::func7()
{
    m_game->InitVramManagers(0x80000, 0, 0x4000);
}

u32 CMissionQuestScene::func0()
{
    if (unk_08 != NULL) {
        unk_08->Update();
        if (unk_08->GetResult() != -1) {
            return 6;
        }
    }
    return -1;
}

void CMissionQuestScene::func1()
{
    if (unk_08 != NULL) {
        unk_08->Render();
    }
}

void CMissionQuestScene::func2()
{
    if (unk_08 != NULL) {
        unk_08->OnVBlank();
    }
}

u32 CMissionQuestScene::getSceneId()
{
    return 0xA;
}

MissionQuestMap::MissionQuestMap(CGame *game)
{
    unk_40 = game;
    Init();
}

MissionQuestMap::~MissionQuestMap()
{
    Release();
}

void MissionQuestMap::Init()
{
    unk_00 = 0;
    unk_18 = NULL;
    unk_1C = NULL;
    unk_10 = NULL;
    unk_14 = NULL;
    unk_0C = NULL;
    for (int i = 0; i < 6; i++) {
        unk_24[i] = NULL;
    }
    unk_04 = 0;
    unk_08 = new RegionMap(unk_40);
}

void MissionQuestMap::Update()
{
    if (unk_18 != NULL) {
        unk_18->Update();
    }
    if (unk_1C != NULL) {
        unk_1C->Update();
    }
    if (unk_0C != NULL) {
        unk_0C->Update();
    }
    if (unk_08 != NULL) {
        unk_08->Update();
    }
    switch (unk_00) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    case 1:
        UpdateInput();
        break;
    }
}

void MissionQuestMap::Render()
{
    if (unk_0C != NULL) {
        unk_0C->Render();
    }
    if (unk_08 != NULL) {
        unk_08->Render();
    }
    switch (unk_00) {
    case 2:
        if (!IsFading()) {
            unk_00 = 4;
        }
    case 1:
    case 3:
    case 5:
        WriteOam();
        break;
    }
}

void MissionQuestMap::OnVBlank()
{
    if (unk_0C != NULL) {
        unk_0C->OnVBlank();
    }
    if (unk_08 != NULL) {
        unk_08->sub_0202A5F8();
    }
    DrawPlaceName();
}

void MissionQuestMap::ov8_0211CEAC()
{
    ShowMissionPlace();
    unk_40->unk_1498->LoadPalette();
}

void MissionQuestMap::Release()
{
    unk_40->unk_146C.SetFps(30);
    unk_40->unk_1498->FreeWindows();
    SAFE_DELETE(unk_0C);
    SAFE_DELETE(unk_14);
    SAFE_DELETE(unk_18);
    SAFE_DELETE(unk_1C);
    SAFE_DELETE(unk_08);
}

void MissionQuestMap::WriteOam()
{
    if (unk_18 != NULL) {
        unk_18->WriteOam();
    }
    if (unk_1C != NULL) {
        unk_1C->WriteOam();
    }
}

void MissionQuestMap::Load()
{
    GXS_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    GXS_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
    G2S_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_256, GX_BG_SCRBASE_0x4800, GX_BG_CHARBASE_0x10000);
    G2S_SetBG0Priority(0);
    G2S_SetBG1Priority(1);
    G2S_SetBG2Priority(3);
    unk_40->m_audioEngine->LoadSystemSe();

    int charNo = 0;
    int paletteSlot = 2;
    u8 oamIndex = 0;
    unk_08->Load(6, &oamIndex, &charNo, &paletteSlot, FALSE);

    unk_1C = new OamSpriteSet((GXOamAttr *)&unk_40->unk_0424[oamIndex], unk_40->unk_14A8, TRUE, 0x40);
    charNo += unk_1C->Load("data/menu", "ma005_00", charNo / 32, 0);
    unk_24[3] = unk_1C->AddSprite(0, 0xF0, 0x10, 0);
    unk_24[3]->SetTouchRect(0x20, 0x20, 0, 0);
    oamIndex += unk_1C->unk_30;

    unk_18 = new OamSpriteSet((GXOamAttr *)&unk_40->unk_0424[oamIndex], unk_40->unk_14A8, TRUE, 0x40);
    charNo += unk_18->Load("data/menu", "mam000_00", charNo / 32, 1);
    unk_24[0] = unk_18->AddSprite(0, 0, 0, 1);
    unk_24[0]->SetTouchRect(0x18, 0x18, 0, 0);
    oamIndex += unk_18->unk_30;

    unk_10 = MAIN_BSS_0210CA6C;
    unk_14 = new MessageTable("/data/message/etc/place_name");
    unk_40->unk_1498->FreeWindows();
    unk_40->unk_1498->SetupBG();
    unk_40->unk_1498->AllocWindows(1);
    unk_40->unk_1498->InitWindow(0, 0x10, 2, 1, 0, 0xD, 0, 2);
    unk_0C = new MissionQuestInfo(unk_40);
    unk_0C->Setup();
    SelectCurrentArea();
}

BOOL MissionQuestMap::Start()
{
    unk_00 = 1;
    Setup();
    return TRUE;
}

BOOL MissionQuestMap::Setup()
{
    Load();
    ov8_0211CEAC();
    unk_40->unk_146C.SetFps(60);
    return TRUE;
}

void MissionQuestMap::UpdateInput()
{
    u32 cancel = (u16)(unk_40->unk_0014->unk_0002 & PAD_BUTTON_B);
    BOOL touched = unk_24[3]->GetTouchTrigger() ? TRUE : FALSE;
    if (touched | cancel) {
        Close();
        return;
    }
    if (unk_24[0]->unk_14 != 0 && unk_24[0]->GetTouchTrigger()) {
        unk_40->m_audioEngine->PlaySe(0xFA);
        SelectMissionPlace();
        return;
    }
    s16 kind;
    u16 id;
    unk_08->GetSelection(&kind, &id);
    switch ((u16)kind) {
    case 1:
        unk_40->m_audioEngine->PlaySe(0xFA);
        SelectCurrentArea();
        break;
    case 6:
        unk_40->m_audioEngine->PlaySe(0xFA);
        SelectArea(id);
        break;
    }
}

void MissionQuestMap::Close()
{
    unk_40->m_audioEngine->PlaySe(0x103);
    unk_00 = 2;
    FadeOut();
}

void MissionQuestMap::RequestPlaceName(u16 id)
{
    unk_3C = id;
    unk_04 = 1;
}

void MissionQuestMap::DrawPlaceName()
{
    if (!unk_04) {
        return;
    }
    unk_04 = 0;
    if (unk_08 == NULL) {
        return;
    }
    u8 idx = unk_3C;
    if (idx > 200) {
        idx -= 155;
    } else if (idx > 100) {
        idx %= 100;
    }
    unk_40->unk_1498->ClearWindow(0);
    SubTextPrinter *text = unk_40->unk_1498;
    text->Print(0, 0, 3, 3, (u8 *)unk_14->GetString(idx), TRUE, 0);
}

void MissionQuestMap::ShowMissionPlace()
{
    if (unk_40->m_missionQuestData->m_missionState == 0) {
        unk_24[0]->unk_14 = 0;
        return;
    }
    unk_3E = unk_0C->GetMissionPlace();
    unk_24[0]->unk_14 = 1;
    SetSpriteToArea(0, unk_3E);
}

void MissionQuestMap::SetSpriteToArea(int idx, u16 id)
{
    if (unk_08 == NULL) {
        return;
    }
    int x;
    int y;
    unk_08->GetAreaPos(id, &x, &y);
    unk_24[idx]->SetPos(x, y);
}

void MissionQuestMap::SelectMissionPlace()
{
    SetAreaMarker(unk_3E, 1);
    RequestPlaceName(unk_3E);
}

void MissionQuestMap::SelectCurrentArea()
{
    u16 id = unk_08->unk_56;
    SetAreaMarker(id, 1);
    RequestPlaceName(id);
}

void MissionQuestMap::SelectArea(u16 id)
{
    SetAreaMarker(id, 3);
    RequestPlaceName(id);
}

void MissionQuestMap::SetAreaMarker(u16 id, int mode)
{
    unk_08->SetAreaMarker(id, mode);
}

void MissionQuestMap::FadeIn()
{
    if (unk_40 != NULL) {
        unk_40->m_subFade->Start(3, 15);
        unk_40->m_mainFade->Start(3, 15);
    }
}

void MissionQuestMap::FadeOut()
{
    if (unk_40 != NULL) {
        unk_40->m_subFade->Start(4, 15);
        unk_40->m_mainFade->Start(4, 15);
    }
}

BOOL MissionQuestMap::IsFading()
{
    if (unk_40->m_subFade->IsActive() || unk_40->m_subFade->IsActive()) {
        return TRUE;
    }
    return FALSE;
}

int MissionQuestMap::GetResult()
{
    return unk_00 != 4 ? -1 : 0;
}
