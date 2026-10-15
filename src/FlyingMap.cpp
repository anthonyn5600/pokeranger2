#include "FlyingMap.hpp"

#include <string.h>

#include "AudioEngine.hpp"
#include "BrightnessFade.hpp"
#include "FontSet.hpp"
#include "MissionQuestData.hpp"
#include "SaveData.hpp"
#include "TextPrinter.hpp"
#include "TextboxManager.hpp"

extern FieldData *MAIN_BSS_0210CA6C;

// Same tables as ov8's mission/quest actors (MissionQuestInfo)
struct FlyingMapActor {
    u16 actorId;
    u16 placeId;
};

static FlyingMapActor sMissionActors[26] = {
    { 0x12, 0x04 },
    { 0x12, 0x06 },
    { 0x12, 0x09 },
    { 0x12, 0x0A },
    { 0x12, 0x0B },
    { 0x12, 0x10 },
    { 0x13, 0x01 },
    { 0x13, 0x12 },
    { 0x1D, 0x17 },
    { 0x1A, 0x1A },
    { 0x1A, 0x12 },
    { 0x00, 0x1D },
    { 0x1E, 0x1E },
    { 0x00, 0x24 },
    { 0x00, 0x11 },
    { 0x1A, 0x26 },
    { 0x1A, 0x26 },
    { 0x12, 0x08 },
    { 0x1A, 0x26 },
    { 0x12, 0x08 },
    { 0x12, 0x04 },
    { 0x12, 0x1E },
    { 0x1D, 0x27 },
    { 0x1A, 0x1C },
    { 0x1A, 0x24 },
    { 0x1A, 0x0A },
};

static FlyingMapActor sQuestActors[61] = {
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

// Never called (mwld strips it): only keeps both tables in .data, where the original has them
u16 ov9_GetMissionQuestActor(BOOL quest, int i)
{
    return quest ? sQuestActors[i].actorId : sMissionActors[i].actorId;
}

static FlyDestination sFlyDestinations[40] = {
    { 0x1, 496, 352, 0x7C, 0x98, 1, 0x1, 0, 0x32 },
    { 0x0, 0, 0, 0x6D, 0x94, 0, 0x2, 2, 0x0 },
    { 0x0, 0, 0, 0x6D, 0x94, 0, 0x3, 2, 0x0 },
    { 0x16, 640, 368, 0x4C, 0x8C, 1, 0x4, 0, 0x33 },
    { 0x0, 0, 0, 0x3A, 0x8E, 0, 0x5, 2, 0x0 },
    { 0x0, 272, 480, 0x40, 0x7C, 16, 0x6, 1, 0x0 },
    { 0x0, 0, 0, 0x5D, 0x8E, 0, 0x7, 2, 0x0 },
    { 0x2D, 240, 512, 0x5C, 0x9C, 1, 0x8, 0, 0x35 },
    { 0x0, 0, 0, 0x64, 0x7C, 21, 0x9, 2, 0x0 },
    { 0x49, 336, 816, 0x7C, 0x74, 28, 0xA, 0, 0x37 },
    { 0x0, 0, 0, 0x8E, 0x83, 0, 0xB, 2, 0x0 },
    { 0x65, 272, 368, 0x8C, 0x5C, 30, 0x26, 0, 0x64 },
    { 0x0, 0, 0, 0x66, 0x4E, 0, 0xF, 2, 0x0 },
    { 0x0, 0, 0, 0x82, 0x46, 0, 0x10, 1, 0x0 },
    { 0x77, 320, 176, 0x34, 0x44, 30, 0x11, 0, 0x38 },
    { 0x86, 704, 848, 0x2C, 0xAC, 38, 0x12, 0, 0x39 },
    { 0x0, 0, 0, 0x40, 0xAC, 0, 0x13, 1, 0x0 },
    { 0x0, 0, 0, 0x4C, 0xB4, 0, 0x14, 1, 0x0 },
    { 0x0, 0, 0, 0x8E, 0xA1, 0, 0x78, 1, 0x0 },
    { 0x0, 0, 0, 0xAC, 0x38, 0, 0x15, 2, 0x0 },
    { 0xB1, 256, 864, 0xC4, 0x25, 43, 0x16, 1, 0x3A },
    { 0xB2, 320, 304, 0xB0, 0x24, 43, 0x17, 1, 0x3B },
    { 0x0, 240, 144, 0x5C, 0x3C, 30, 0x18, 2, 0x0 },
    { 0xCF, 480, 448, 0x5C, 0x28, 46, 0x19, 0, 0x3D },
    { 0x0, 0, 0, 0x44, 0x2C, 0, 0x1A, 2, 0x0 },
    { 0x0, 0, 0, 0x6D, 0x31, 0, 0x1B, 2, 0x0 },
    { 0xD8, 640, 240, 0x7C, 0x28, 48, 0x1C, 1, 0x40 },
    { 0x0, 0, 0, 0xA0, 0x8C, 0, 0x1D, 1, 0x0 },
    { 0x10A, 232, 168, 0xAC, 0x7C, 54, 0x1E, 1, 0x41 },
    { 0x127, 464, 384, 0xBE, 0xB4, 0, 0x20, 0, 0x42 },
    { 0x127, 464, 384, 0xB4, 0xA4, 55, 0x21, 0, 0x42 },
    { 0x0, 0, 0, 0xCD, 0xA1, 0, 0x22, 2, 0x0 },
    { 0x0, 0, 0, 0xE4, 0x9C, 35, 0x23, 2, 0x0 },
    { 0x130, 576, 352, 0xE4, 0x9C, 0, 0x24, 1, 0x43 },
    { 0x155, 320, 368, 0xD6, 0x5C, 0, 0x27, 1, 0x44 },
    { 0x180, 368, 160, 0xD6, 0x5C, 0, 0x29, 0, 0x65 },
    { 0x0, 0, 0, 0xD6, 0x5C, 0, 0x2A, 0, 0x0 },
    { 0x0, 0, 0, 0xD6, 0x5C, 0, 0x2B, 0, 0x0 },
    { 0x0, 0, 0, 0xD6, 0x5C, 0, 0x2C, 0, 0x0 },
    { 0x0, 0, 0, 0x88, 0x68, 0, 0xE, 2, 0x0 },
};

FlyingMap::FlyingMap(CGame *game)
{
    unk_54 = game;
    Init();
}

FlyingMap::~FlyingMap()
{
    Release();
}

void FlyingMap::Init()
{
    unk_00 = 0;
    unk_24 = NULL;
    unk_28 = 0;
    unk_2C = 0;
    unk_30 = NULL;
    unk_34 = NULL;
    unk_1C = NULL;
    unk_20 = NULL;
    unk_18 = NULL;
    for (int i = 0; i < 2; i++) {
        unk_3C[i] = NULL;
    }
    unk_04 = 0;
    unk_10 = 0;
    unk_50 = 0;
    unk_14 = new RegionMap(unk_54);
}

void FlyingMap::Update()
{
    if (unk_24 != NULL) {
        unk_24->Update();
    }
    if (unk_30 != NULL) {
        unk_30->Update();
    }
    if (unk_18 != NULL) {
        unk_18->Update();
    }
    if (unk_14 != NULL) {
        unk_14->Update();
    }
    switch (unk_00) {
    case 0:
    case 2:
    case 5:
        break;
    case 4:
        if (UpdateButtonAnim()) {
            break;
        }
        unk_3C[1]->SetVisible(FALSE);
        ShowConfirmMessage();
        unk_00 = 3;
        break;
    case 3:
        if (unk_54->m_textboxData->IsActive()) {
            break;
        }
        if (unk_54->m_textboxData->CloseIfNoPrompt(1)) {
            break;
        }
        if (unk_54->m_textboxData->GetYesNoResult() == 0) {
            Close();
            SetDestination(unk_48);
            break;
        }
        unk_00 = 1;
        GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_OBJ);
        break;
    case 1:
        UpdateSelect();
        break;
    }
}

void FlyingMap::Render()
{
    if (unk_18 != NULL) {
        unk_18->Render();
    }
    if (unk_14 != NULL) {
        unk_14->Render();
    }
    switch (unk_00) {
    case 2:
        if (!IsFading()) {
            unk_00 = 5;
        }
    case 1:
    case 3:
    case 4:
        WriteOam();
        break;
    case 5:
        break;
    }
}

void FlyingMap::OnVBlank()
{
    if (unk_14 != NULL) {
        unk_14->sub_0202A5F8();
    }
    PrintPlaceName();
}

void FlyingMap::ResetMarker()
{
    unk_3C[1]->SetVisible(FALSE);
    unk_14->SetAreaMarker(0, 4);
    unk_54->unk_1494->LoadPalette();
}

void FlyingMap::Release()
{
    unk_54->unk_146C.SetFps(30);
    unk_54->unk_1494->FreeWindows();
    SAFE_DELETE(unk_18);
    SAFE_DELETE(unk_20);
    SAFE_DELETE(unk_24);
    SAFE_DELETE(unk_30);
    SAFE_DELETE_ARRAY(unk_34);
    SAFE_DELETE(unk_14);
    unk_54->m_textboxData->ResetTextSpeed();
    unk_54->m_textboxData->CloseAndClear(1, 1);
    unk_54->m_textboxData->FreeSystemMessages();
    unk_54->m_textboxData->Reset();
}

void FlyingMap::WriteOam()
{
    if (unk_24 != NULL) {
        unk_24->WriteOam();
    }
    if (unk_30 != NULL) {
        unk_30->WriteOam();
    }
}

void FlyingMap::InitGraphics()
{
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2_SetBG0Offset(0, 0);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
    G2_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_256, GX_BG_SCRBASE_0x4800, GX_BG_CHARBASE_0x10000);
    G2_SetBG0Priority(0);
    G2_SetBG1Priority(0);
    G2_SetBG2Priority(3);
    unk_54->m_audioEngine->LoadSystemSe();

    CGame *game = unk_54;
    game->m_textboxData->Init(game->unk_0014, game->touchPanel, &game->unk_14AC->unk_0C, game->m_nameTables, game->unk_0024, game->m_audioEngine, 0x10, 0x4000, 0);
    unk_54->m_textboxData->LoadSystemMessages(0);
    unk_54->unk_1494->FreeWindows();
    unk_54->unk_1494->SetupBG(0, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x18000);
    unk_54->unk_1494->AllocWindows(1);
    unk_54->unk_1494->InitWindow(0, 0x10, 2, 1, 0, 8, 0, 2);

    int charNo = 0;
    u8 oamIndex = 0x20;
    int paletteSlot = 5;
    unk_14->Load(2, &oamIndex, &charNo, &paletteSlot, TRUE);
    paletteSlot += 2;

    unk_30 = new OamSpriteSet((GXOamAttr *)&unk_54->unk_0024[oamIndex], unk_54->unk_14A8, FALSE, 0x40);
    charNo += unk_30->Load("data/menu", "ma005_00", charNo / 32, paletteSlot);
    unk_3C[0] = unk_30->AddSprite(0, 0xF0, 0x10, 0);
    unk_3C[0]->SetTouchRect(0x20, 0x20, 0, 0);
    oamIndex += unk_30->unk_30;
    paletteSlot += 1;

    unk_24 = new OamSpriteSet((GXOamAttr *)&unk_54->unk_0024[oamIndex], unk_54->unk_14A8, FALSE, 0x40);
    charNo += unk_24->Load("data/menu", "mam000_01", charNo / 32, paletteSlot);
    unk_3C[1] = unk_24->AddSprite(0, 0x80, 0xB0, 0);
    unk_3C[1]->SetTouchRect(0x28, 0x18, 0, 4);
    unk_44 = unk_24->unk_24;
    oamIndex += unk_24->unk_30;

    unk_1C = MAIN_BSS_0210CA6C;
    unk_20 = new MessageTable("/data/message/etc/place_name");
    unk_18 = new SubScreenPokemonInfo();
    unk_18->Release();
    unk_18->Load(0xAC, 0, 0);
}

BOOL FlyingMap::Start()
{
    unk_00 = 1;
    Setup();
    return TRUE;
}

BOOL FlyingMap::Setup()
{
    InitGraphics();
    ResetMarker();
    unk_54->unk_146C.SetFps(60);
    MarkDestinations();
    return TRUE;
}

void FlyingMap::MarkDestinations()
{
    u64 flags = 0;
    for (u32 i = 0; i < 40; i++) {
        if (sFlyDestinations[i].mapId != 0) {
            flags |= (u64)1 << sFlyDestinations[i].placeId;
        }
    }
    if (unk_14 != NULL) {
        unk_14->HighlightAreas(&flags);
    }
}

void FlyingMap::UpdateSelect()
{
    u32 cancel = (u16)(unk_54->unk_0014->unk_0002 & PAD_BUTTON_B);
    BOOL touched = unk_3C[0]->GetTouchTrigger() ? TRUE : FALSE;
    if (touched | cancel) {
        unk_54->m_audioEngine->PlaySe(0x103);
        Close();
        return;
    }
    if (unk_3C[1]->unk_14 != 0 && unk_3C[1]->GetTouchTrigger()) {
        unk_54->m_audioEngine->PlaySe(0xFA);
        PressFlyButton();
        return;
    }
    s16 kind;
    u16 id;
    unk_14->GetSelection(&kind, &id);
    switch ((u16)kind) {
    case 1:
        unk_54->m_audioEngine->PlaySe(0xFA);
        SelectCurrentArea();
        break;
    case 6:
        unk_54->m_audioEngine->PlaySe(0xFA);
        SelectArea(id);
        break;
    }
}

void FlyingMap::Close()
{
    unk_00 = 2;
    FadeOut();
}

void FlyingMap::SetSelected(u16 id)
{
    unk_48 = id;
    unk_04 = 1;
}

void FlyingMap::PrintPlaceName()
{
    if (!unk_04) {
        return;
    }
    unk_04 = 0;
    u8 idx = unk_48;
    if (idx > 200) {
        idx -= 155;
    } else if (idx > 100) {
        idx %= 100;
    }
    unk_54->unk_1494->ClearWindow(0);
    TextPrinter *text = unk_54->unk_1494;
    text->Print(0, 0, 3, 3, (u8 *)unk_20->GetString(idx), TRUE, 0);
}

BOOL FlyingMap::UpdateButtonAnim()
{
    if (++unk_08 < 15) {
        return TRUE;
    }
    unk_08 = 0;
    unk_24->SetAnim(unk_44, 0);
    return FALSE;
}

void FlyingMap::ShowConfirmMessage()
{
    unk_54->m_textboxData->SetTextSpeed(0);
    TextboxManager *textbox = unk_54->m_textboxData;
    textbox->ShowSystemMessage(sFlyDestinations[FindDestination(unk_48)].messageId, 1, 1, 0);
}

void FlyingMap::SelectCurrentArea()
{
    u16 id = unk_14->unk_56;
    SetSelected(id);
    SetMarker(id, 1);
    if (sFlyDestinations[unk_4A].unk_0C == 2) {
        unk_3C[1]->SetVisible(FALSE);
    }
}

void FlyingMap::PressFlyButton()
{
    unk_00 = 4;
    unk_08 = 0;
    unk_24->SetAnim(unk_44, 1);
}

void FlyingMap::SelectArea(u16 id)
{
    SetSelected(id);
    SetMarker(id, 3);
}

u16 FlyingMap::FindDestination(u8 placeId)
{
    FlyDestination *entry = sFlyDestinations;
    if (placeId == 0x14 && unk_54->m_missionQuestData->m_chapter >= 0x28) {
        placeId = 0x78;
    }
    u16 i;
    for (i = 0; (int)i < 40; i++, entry++) {
        if (entry->placeId == placeId) {
            break;
        }
    }
    if ((int)i >= 40) {
        i = 0;
    }
    return i;
}

static inline void SetSaveName(SaveData *save, const char *name)
{
    if (name != NULL) {
        strcpy(save->m_saveName, name);
    } else {
        save->m_saveName[0] = '\0';
    }
}

void FlyingMap::SetDestination(u16 placeId)
{
    u16 idx = FindDestination(placeId);
    SaveData *save = &MAIN_BSS_020B26A0;
    save->unk_8B78 = sFlyDestinations[idx].mapId;
    save->unk_8B7A = sFlyDestinations[idx].x;
    save->unk_8B7C = sFlyDestinations[idx].y;
    SetSaveName(save, "sFlying");
    unk_10 = 1;
}

void FlyingMap::SetMarker(u16 id, int mode)
{
    unk_14->SetAreaMarker(id, mode);
    if (mode == 4) {
        unk_3C[1]->SetVisible(FALSE);
        return;
    }
    unk_3C[1]->SetVisible(sFlyDestinations[FindDestination(unk_48)].mapId != 0);
}

void FlyingMap::FadeIn()
{
    if (unk_54 != NULL) {
        unk_54->m_subFade->Start(3, 15);
        unk_54->m_mainFade->Start(3, 15);
    }
}

void FlyingMap::FadeOut()
{
    if (unk_54 != NULL) {
        unk_54->m_subFade->Start(4, 15);
        unk_54->m_mainFade->Start(4, 15);
    }
}

BOOL FlyingMap::IsFading()
{
    if (unk_54->m_subFade->IsActive() || unk_54->m_subFade->IsActive()) {
        return TRUE;
    }
    return FALSE;
}

int FlyingMap::GetResult()
{
    if (unk_00 == 5) {
        return unk_10 ? 1 : 0;
    }
    return -1;
}
