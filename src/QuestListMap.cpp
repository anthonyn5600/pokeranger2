#include "AudioEngine.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "MessageTable.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "RegionMap.hpp"
#include "SubTextPrinter.hpp"
#include "scene/CQuestListScene.hpp"

extern FieldData *MAIN_BSS_0210CA6C;

static QuestGiverActor sQuestActors[61] = {
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

QuestListMap::QuestListMap(CGame *game)
{
    unk_38 = game;
    Init();
}

QuestListMap::~QuestListMap()
{
    Release();
}

void QuestListMap::Init()
{
    unk_00 = 0;
    unk_14 = NULL;
    unk_18 = NULL;
    unk_0C = NULL;
    unk_10 = NULL;
    for (int i = 0; i < 5; i++) {
        unk_20[i] = NULL;
    }
    unk_04 = 0;
    unk_08 = new RegionMap(unk_38);
}

BOOL QuestListMap::Update()
{
    if (unk_14 != NULL) {
        unk_14->Update();
    }
    if (unk_18 != NULL) {
        unk_18->Update();
    }
    if (unk_08 != NULL) {
        unk_08->Update();
    }
    switch (unk_00) {
    case 0:
    case 4:
    case 6:
        break;
    case 2:
        if (IsFading()) {
            break;
        }
        unk_00 = 1;
    case 1:
        UpdateInput();
        break;
    case 3:
        if (IsFading()) {
            break;
        }
        unk_00 = 5;
        return FALSE;
    case 5:
        return FALSE;
    }
    return TRUE;
}

void QuestListMap::Render()
{
    if (unk_08 != NULL) {
        unk_08->Render();
    }
    switch (unk_00) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
        WriteOam();
        break;
    }
}

void QuestListMap::OnVBlank()
{
    if (unk_08 != NULL) {
        unk_08->sub_0202A5F8();
    }
    DrawPlaceName();
}

void QuestListMap::LoadPalette()
{
    unk_38->unk_1498->LoadPalette();
}

void QuestListMap::Release()
{
    unk_38->unk_1498->FreeWindows();
    SAFE_DELETE(unk_10);
    SAFE_DELETE(unk_14);
    SAFE_DELETE(unk_18);
    SAFE_DELETE(unk_08);
}

void QuestListMap::WriteOam()
{
    if (unk_14 != NULL) {
        unk_14->WriteOam();
    }
    if (unk_18 != NULL) {
        unk_18->WriteOam();
    }
}

void QuestListMap::Load()
{
    SetupBG();

    int charNo = 0;
    int paletteSlot = 2;
    u8 oamIndex = 0;
    unk_08->Load(6, &oamIndex, &charNo, &paletteSlot, FALSE);

    unk_18 = new OamSpriteSet((GXOamAttr *)&unk_38->unk_0424[oamIndex], unk_38->unk_14A8, TRUE, 0x40);
    charNo += unk_18->LoadFiles("data/menu", "ma005_00", charNo / 32, 0);
    unk_18->CopyToVram();
    unk_20[2] = unk_18->AddSprite(0, 0xF0, 0x10, 0);
    unk_20[2]->SetTouchRect(0x20, 0x20, 0, 0);
    oamIndex += unk_18->unk_30;

    unk_14 = new OamSpriteSet((GXOamAttr *)&unk_38->unk_0424[oamIndex], unk_38->unk_14A8, TRUE, 0x40);
    charNo += unk_14->LoadFiles("data/menu", "ql000_01", charNo / 32, 1);
    unk_14->CopyToVram();
    unk_20[0] = unk_14->AddSprite(0, 0, 0, 1);
    unk_20[0]->SetTouchRect(0x18, 0x18, 0, 0);
    oamIndex += unk_14->unk_30;

    unk_0C = MAIN_BSS_0210CA6C;
    unk_10 = new MessageTable("/data/message/etc/place_name");
}

void QuestListMap::LoadToVram()
{
    SetupBG();
    if (unk_08 != NULL) {
        unk_08->LoadToVram(FALSE);
    }
    if (unk_14 != NULL) {
        unk_14->CopyToVram();
    }
    if (unk_18 != NULL) {
        unk_18->CopyToVram();
    }
    SelectCurrentArea();
    unk_38->unk_1498->FreeWindows();
    unk_38->unk_1498->SetupBG();
    unk_38->unk_1498->AllocWindows(1);
    unk_38->unk_1498->InitWindow(0, 0x10, 2, 1, 0, 0xD, 0, 2);
}

void QuestListMap::SetupBG()
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
}

void QuestListMap::Start(u16 idx)
{
    unk_00 = 2;
    Setup();
    ShowQuestPlace(idx);
    FadeIn();
}

BOOL QuestListMap::Setup()
{
    LoadToVram();
    LoadPalette();
    unk_38->unk_146C.SetFps(60);
    return TRUE;
}

void QuestListMap::UpdateInput()
{
    u32 cancel = (u16)(unk_38->unk_0014->unk_0002 & PAD_BUTTON_B);
    BOOL touched = unk_20[2]->GetTouchTrigger() ? TRUE : FALSE;
    if (touched | cancel) {
        Close();
        return;
    }
    if (unk_20[0]->unk_14 != 0 && unk_20[0]->GetTouchTrigger()) {
        unk_38->m_audioEngine->PlaySe(0xFA);
        SelectQuestPlace();
        return;
    }
    s16 kind;
    u16 id;
    unk_08->GetSelection(&kind, &id);
    switch ((u16)kind) {
    case 1:
        unk_38->m_audioEngine->PlaySe(0xFA);
        SelectCurrentArea();
        break;
    case 6:
        unk_38->m_audioEngine->PlaySe(0xFA);
        SelectArea(id);
        break;
    }
}

void QuestListMap::Close()
{
    unk_38->m_audioEngine->PlaySe(0x103);
    unk_00 = 3;
    FadeOut();
}

void QuestListMap::RequestPlaceName(u16 id)
{
    unk_34 = id;
    unk_04 = 1;
}

void QuestListMap::DrawPlaceName()
{
    if (!unk_04) {
        return;
    }
    unk_04 = 0;
    if (unk_08 == NULL) {
        return;
    }
    u8 idx = unk_34;
    if (idx > 200) {
        idx -= 155;
    } else if (idx > 100) {
        idx %= 100;
    }
    unk_38->unk_1498->ClearWindow(0);
    SubTextPrinter *text = unk_38->unk_1498;
    text->Print(0, 0, 3, 3, (u8 *)unk_10->GetString(idx), TRUE, 0);
}

void QuestListMap::ShowQuestPlace(u16 idx)
{
    unk_36 = sQuestActors[idx].placeId;
    unk_20[0]->unk_14 = TRUE;
    SetSpriteToArea(0, unk_36);
}

void QuestListMap::SetSpriteToArea(int idx, u16 id)
{
    if (unk_08 == NULL) {
        return;
    }
    int x;
    int y;
    unk_08->GetAreaPos(id, &x, &y);
    unk_20[idx]->SetPos(x, y);
}

void QuestListMap::SelectQuestPlace()
{
    SetAreaMarker(unk_36, 2);
    RequestPlaceName(unk_36);
}

void QuestListMap::SelectCurrentArea()
{
    u16 id = unk_08->unk_56;
    SetAreaMarker(id, 2);
    RequestPlaceName(id);
}

void QuestListMap::SelectArea(u16 id)
{
    SetAreaMarker(id, 3);
    RequestPlaceName(id);
}

void QuestListMap::SetAreaMarker(u16 id, int mode)
{
    unk_08->SetAreaMarker(id, mode);
}

void QuestListMap::FadeIn()
{
    if (unk_38 != NULL) {
        unk_38->m_subFade->Start(3, 15);
    }
}

void QuestListMap::FadeOut()
{
    if (unk_38 != NULL) {
        unk_38->m_subFade->Start(4, 15);
    }
}

BOOL QuestListMap::IsFading()
{
    if (unk_38->m_subFade->IsActive() || unk_38->m_subFade->IsActive()) {
        return TRUE;
    }
    return FALSE;
}
