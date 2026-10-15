#include <nitro.h>

#include "AudioEngine.hpp"
#include "BGLayer.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "PadInput.hpp"
#include "SubScreenButton.hpp"
#include "TextPrinter.hpp"
#include "scene/CStylerScreens.hpp"

// Power-up entry on the status screen: tile position, sprite, assist message and CStylerData::m_powerLevels index
struct StylerStatusPart {
    int x;
    int y;
    int anim;
    int msg;
    int idx;
};

// Level mark: shown when CStylerData::m_powerLevels[idx] >= minLevel
struct StylerStatusMark {
    int x;
    int y;
    int anim;
    int idx;
    int minLevel;
};

static StylerStatusPart sExtraParts[4] = {
    { 3, 19, 20, 21, 17 },
    { 18, 19, 21, 22, 18 },
    { 3, 21, 22, 24, 20 },
    { 18, 21, 23, 23, 19 },
};

static StylerStatusMark sMarks[7] = {
    { 112, 160, 24, 17, 1 },
    { 120, 160, 24, 17, 2 },
    { 232, 160, 24, 18, 1 },
    { 240, 160, 24, 18, 2 },
    { 112, 176, 24, 20, 1 },
    { 120, 176, 24, 20, 2 },
    { 236, 176, 25, 19, 1 },
};

static StylerStatusPart sParts[17] = {
    { 3, 3, 1, 0, 14 },
    { 3, 5, 2, 1, 3 },
    { 3, 7, 3, 2, 1 },
    { 3, 9, 4, 3, 2 },
    { 3, 11, 5, 4, 0 },
    { 3, 13, 6, 5, 13 },
    { 3, 15, 7, 6, 4 },
    { 3, 17, 8, 7, 5 },
    { 18, 1, 9, 8, 8 },
    { 18, 3, 10, 9, 10 },
    { 18, 5, 11, 10, 6 },
    { 18, 7, 12, 11, 7 },
    { 18, 9, 13, 12, 9 },
    { 18, 11, 14, 13, 12 },
    { 18, 13, 15, 14, 16 },
    { 18, 15, 16, 15, 11 },
    { 18, 17, 17, 16, 15 },
};

CStylerStatusScreen::CStylerStatusScreen(CGame *game, CStylerData *data)
{
    unk_0C = 0;
    m_sprites = NULL;
    unk_224 = NULL;
    m_game = game;
    m_data = data;
    m_menuMessages = data->m_menuMessages;
    unk_218 = data->unk_10;
}

CStylerStatusScreen::~CStylerStatusScreen()
{
    Release();
}

void CStylerStatusScreen::Load()
{
    LoadData();
    SetupBG();
    LoadSprites();
    LoadBG();
    DrawTexts();
}

void CStylerStatusScreen::Release()
{
    SAFE_DELETE(m_sprites);
    SAFE_DELETE(unk_224);
}

void CStylerStatusScreen::Reset()
{
    CStylerScreen::Reset();
    SetupBG();
    m_backButton->unk_14 = TRUE;
    m_backButtonPressed->unk_14 = FALSE;
    MI_CpuCopyFast(m_palette, (void *)HW_OBJ_PLTT, 0x1E0);
}

void CStylerStatusScreen::LoadData()
{
}

void CStylerStatusScreen::SetupBG()
{
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    G2_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x9800, GX_BG_CHARBASE_0x10000, GX_BG_EXTPLTT_01);
    G2_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0xa800, GX_BG_CHARBASE_0x04000);
    G2_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0xb800, GX_BG_CHARBASE_0x04000);
    G2_SetBG1Priority(0);
    G2_SetBG0Priority(1);
    G2_SetBG2Priority(2);
    G2_SetBG3Priority(3);
    G2_BlendNone();
}

void CStylerStatusScreen::LoadSprites()
{
    m_sprites = new OamSpriteSet((GXOamAttr *)&m_game->unk_0024[2], m_game->unk_14A8, FALSE, 0x40);
    m_sprites->Load("data/menu", "stl000_00", 0x350, 0);

    for (int i = 0; i < 17; i++) {
        m_sprites->AddSprite(m_data->m_powerLevels[sParts[i].idx] != 0 ? sParts[i].anim : 26, sParts[i].x * 8 - 8, sParts[i].y * 8 + 8, 0);
    }
    for (int i = 0; i < 4; i++) {
        m_sprites->AddSprite(m_data->m_powerLevels[sExtraParts[i].idx] != 0 ? sExtraParts[i].anim : 26, sExtraParts[i].x * 8 - 8, sExtraParts[i].y * 8 + 8, 0);
    }
    for (int i = 0; i < 7; i++) {
        if (m_data->m_powerLevels[sMarks[i].idx] >= sMarks[i].minLevel) {
            m_sprites->AddSprite(sMarks[i].anim, sMarks[i].x, sMarks[i].y, 0);
        }
    }

    m_backButton = m_sprites->AddSprite(0, 0xF0, 0x5C, 0);
    m_backButton->SetTouchRect(0x20, 0x20, 0, 0);
    m_backButtonPressed = m_sprites->AddSprite(0x1B, 0xF0, 0x5C, 0);
    m_backButtonPressed->unk_14 = FALSE;
    MI_CpuCopyFast((void *)HW_OBJ_PLTT, m_palette, 0x1E0);
}

static void SetTilePalette(u16 *scr, int x, int y, int level)
{
    u16 palettes[4] = { 0x1000, 0x2000, 0x3000, 0x4000 };
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            int idx = (i + x) + (j + y) * 32;
            scr[idx] = (scr[idx] & 0x8FFF) | palettes[level];
        }
    }
}

void CStylerStatusScreen::LoadBG()
{
    u16 scr[0x400];

    BGS_LoadCharAndPltt("menu/", "stl000_bg_", 2, "stl000", 0x200, "stl000", 8);
    BGS_LoadScr("menu/", "stl000_bg_", 2, "stl000_01", 8, 0x200, PTR_CAST(int, scr), 0);
    BGS_LoadScr("menu/", "stl000_bg_", 3, "stl000_00", 8, 0x200, 0, 0);

    for (int i = 0; i < 17; i++) {
        if (m_data->m_powerLevels[sParts[i].idx] != 0) {
            SetTilePalette(scr, sParts[i].x, sParts[i].y, m_data->m_powerLevels[sParts[i].idx]);
        }
    }

    MI_CpuCopyFast(scr, G2_GetBG2ScrPtr(), sizeof(scr));
}

void CStylerStatusScreen::DrawTexts()
{
    int charNo;
    int i;
    TextPrinter *printer;
    UnkClass_020091E8_004 *assistMessages;
    printer = m_game->unk_1494;
    printer->FreeWindows();
    printer->SetupBG(0, GX_BG_SCRBASE_0x9800, GX_BG_CHARBASE_0x10000);
    printer->AllocWindows(0x16);

    assistMessages = m_data->m_assistMessages;
    charNo = 0x3D;
    printer->InitWindow(0, 11, 3, 1, 0, charNo, 0, 2);
    charNo += 11 * 3;

    if (m_menuMessages->unk_08[63].unk_04 != NULL) {
        printer->Print(0, 4, 6, 3, m_menuMessages->unk_08[63].unk_04, FALSE, 0);
    }

    for (i = 0; i < 17; i++) {
        printer->InitWindow(i + 1, 10, 2, sParts[i].x, sParts[i].y, charNo, 0, 2);
        charNo += 10 * 2;

        int level = m_data->m_powerLevels[sParts[i].idx];
        if (level != 0) {
            // fake: the self-assignment keeps the name load as its own earlier step; written inline, mwcc stores
            // the color argument first and merges that store with the else branch's
            u8 *name;
            name = (name = assistMessages->unk_08[sParts[i].msg + 1].unk_04);
            printer->Print(i + 1, 2, 2, 3, name, FALSE, 0);
            int levelNames[3] = { 0x41, 0x42, 0x43 };
            printer->Print(i + 1, 0x36, 3, 3, m_menuMessages->unk_08[levelNames[level - 1]].unk_04, FALSE, 0);
        } else {
            printer->Print(i + 1, 4, 2, 3, assistMessages->unk_08[25].unk_04, FALSE, 0);
        }
    }

    for (int i = 0; i < 4; i++) {
        printer->InitWindow(i + 18, 10, 2, sExtraParts[i].x, sExtraParts[i].y, charNo, 0, 2);
        charNo += 10 * 2;

        if (m_data->m_powerLevels[sExtraParts[i].idx] != 0) {
            printer->Print(i + 18, 4, 2, 3, assistMessages->unk_08[sExtraParts[i].msg].unk_04, FALSE, 0);
        } else {
            printer->Print(i + 18, 4, 2, 3, assistMessages->unk_08[25].unk_04, FALSE, 0);
        }
    }
}

int CStylerStatusScreen::Update()
{
    if (m_sprites != NULL) {
        m_sprites->Update();
    }
    if (unk_224 != NULL) {
        unk_224->Update();
    }

    switch (unk_04) {
    case 0:
        if (!m_game->m_mainFade->IsActive() && !m_game->m_subFade->IsActive()) {
            unk_04 = 1;
        }
        break;
    case 1: {
        PadInput *pad = m_game->unk_0014;
        if (unk_218->UpdateInput()) {
            unk_04 = 2;
            m_game->m_mainFade->Start(4, 20);
            m_game->m_subFade->Start(4, 20);
            unk_0C = 0;
        } else if (m_backButton->GetTouchTrigger() || (u16)(pad->unk_0002 & PAD_BUTTON_R)) {
            m_backButton->unk_14 = FALSE;
            m_backButtonPressed->unk_14 = TRUE;
            m_game->m_audioEngine->PlaySe(0xFA);
            unk_04 = 2;
            m_game->m_mainFade->Start(4, 20);
            unk_0C = 1;
        }
        break;
    }
    case 2:
        if (unk_0C == 0) {
            if (!m_game->m_mainFade->IsActive() && !m_game->m_subFade->IsActive()) {
                return -1;
            }
        } else {
            if (!m_game->m_mainFade->IsActive()) {
                return 1;
            }
        }
        break;
    }

    return 0;
}

void CStylerStatusScreen::Render()
{
    unk_218->Render();
    if (m_sprites != NULL) {
        m_sprites->WriteOam();
    }
    if (unk_224 != NULL) {
        unk_224->WriteOam();
    }
}

void CStylerStatusScreen::func7()
{
}

void CStylerStatusScreen::func8()
{
}
