#include "FieldSubScreen.hpp"

#include <nitro.h>

#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "DisplayUtil.hpp"
#include "SaveData.hpp"
#include "SubScreenAreaMap.hpp"
#include "SubScreenPartyPanel.hpp"
#include "SubScreenPicture.hpp"
#include "SubScreenPokemonInfo.hpp"
#include "SubScreenRangerCard.hpp"
#include "SubScreenTargetInfo.hpp"
#include "WindowWipe.hpp"
#include "common.hpp"
#include "main.hpp"

extern SaveData MAIN_BSS_020B26A0;

FieldSubScreen *FieldSubScreen::sInstance;

FieldSubScreen::FieldSubScreen(CGame *game)
{
    m_game = game;
    Init();
}

FieldSubScreen::~FieldSubScreen()
{
    SAFE_DELETE(m_partyPanel);
    SAFE_DELETE(m_targetInfo);
    SAFE_DELETE(m_pokemonInfo);
    SAFE_DELETE(m_areaMap);
    SAFE_DELETE(m_rangerCard);
    SAFE_DELETE(m_picture);
}

void FieldSubScreen::Update()
{
    switch (m_mode) {
    case 0:
        break;
    case 1:
        m_areaMap->Update();
        break;
    case 2:
        m_partyPanel->Update();
        break;
    case 3:
        break;
    case 4:
        if (m_pokemonInfo->unk_70 == 0x10) {
            m_pokemonInfo->Update();
            UpdateIdleTimer();
        }
        break;
    case 5:
        break;
    case 6:
        if (m_targetInfo->unk_50 == 0x10) {
            m_targetInfo->Update();
            UpdateIdleTimer();
        }
        break;
    case 7:
        break;
    case 9:
        unk_48 = m_rangerCard->LoadStep(unk_48);
        if (unk_48 == -1) {
            m_rangerCard->ReleaseMessages();
            m_mode = 8;
            FadeIn(10);
        }
        break;
    case 8:
        m_rangerCard->Update();
        break;
    case 10:
        m_picture->Update();
        break;
    }

    if (m_switching) {
        if (IsFading()) {
            return;
        }
        m_switching = FALSE;
        switch (m_nextMode) {
        case 0:
            break;
        case 1:
            LoadAreaMap();
            break;
        case 2:
            LoadPartyPanel();
            break;
        case 3:
            break;
        case 4:
            m_mode = 3;
            if (LoadPokemonInfoStep() != 0x10) {
                m_switching = TRUE;
                return;
            }
            FinishSwitch();
            m_pokemonInfo->ReleaseMessages();
            m_mode = 4;
            break;
        case 5:
            break;
        case 6:
            m_mode = 5;
            if (LoadTargetInfoStep() != 0x10) {
                m_switching = TRUE;
                return;
            }
            FinishSwitch();
            m_targetInfo->ReleaseMessages();
            m_mode = 6;
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            LoadRangerCard();
            break;
        case 10:
            LoadPicture();
            break;
        }
    }
}

void FieldSubScreen::sub_02022710()
{
}

void FieldSubScreen::Render()
{
    switch (m_mode) {
    case 0:
        break;
    case 1:
        RenderAreaMap();
        break;
    case 2:
        RenderPartyPanel();
        break;
    case 3:
        break;
    case 4:
        if (m_pokemonInfo->unk_70 == 0x10) {
            RenderPokemonInfo();
        }
        break;
    case 5:
        break;
    case 6:
        if (m_targetInfo->unk_50 == 0x10) {
            RenderTargetInfo();
        }
        break;
    case 8:
        RenderRangerCard();
        break;
    case 9:
        break;
    case 10:
        RenderPicture();
        break;
    case 7:
        ReportFrameTime();
        break;
    }
}

void FieldSubScreen::FlushDebugInfo()
{
    if (m_mode == 7) {
        FlushBGFonts();
    }
}

void FieldSubScreen::Init()
{
    m_nextMode = m_mode = 0;
    sInstance = this;
    sub_020228C0();
    m_switching = FALSE;
    m_areaMap = new SubScreenAreaMap(m_game);
    m_areaMap->Load();
    m_targetInfo = new SubScreenTargetInfo();
    m_targetInfo->LoadBG();
    m_pokemonInfo = new SubScreenPokemonInfo();
    m_pokemonInfo->LoadPTC();
    m_partyPanel = new SubScreenPartyPanel();
    m_rangerCard = new SubScreenRangerCard();
    m_picture = new SubScreenPicture(m_game);
    unk_38 = -1;
    unk_44 = -1;
    unk_58 = FALSE;
    SetIdleReturn(1);
    unk_64 = FALSE;
}

void FieldSubScreen::sub_020228C0()
{
}

void FieldSubScreen::RenderAreaMap()
{
    m_areaMap->Render();
}

void FieldSubScreen::RenderPartyPanel()
{
    m_partyPanel->Render();
}

void FieldSubScreen::RenderPokemonInfo()
{
    m_pokemonInfo->Render();
}

void FieldSubScreen::RenderTargetInfo()
{
    m_targetInfo->Render();
}

void FieldSubScreen::RenderRangerCard()
{
    m_rangerCard->Render();
}

void FieldSubScreen::RenderPicture()
{
    m_picture->Render();
}

void FieldSubScreen::HideAreaMap()
{
    if (m_areaMap != NULL) {
        m_areaMap->Hide();
    }
}

BOOL FieldSubScreen::ShowAreaMap(u32 mapId, int x, int y)
{
    unk_64 = FALSE;
    unk_2C = 0;
    m_mapId = mapId;
    m_areaMap->SetMap(mapId, x, y);
    if (unk_58) {
        return FALSE;
    }
    unk_44 = -1;
    unk_38 = -1;
    SetVramBanks();
    if (MAIN_BSS_020B26A0.m_subScreenShowsMap == 0) {
        m_partyPanel->Release();
        m_partyPanel->LoadPanel();
        ResetBGOffsets();
        m_mode = 2;
        m_nextMode = 0;
        return FALSE;
    }
    m_areaMap->Show(m_mapId, x, y);
    m_mode = 1;
    m_nextMode = 0;
    MAIN_BSS_020B26A0.m_subScreenShowsMap = 1;
    return TRUE;
}

void FieldSubScreen::SwitchToAreaMap(int mapId, int x, int y)
{
    unk_64 = FALSE;
    if (unk_58) {
        return;
    }
    m_nextMode = 1;
    if (x == -1000 && y == -1000 && mapId == -1000) {
        unk_20 = m_mapId;
        unk_24 = m_areaMap->unk_30;
        unk_28 = m_areaMap->unk_34;
    } else {
        unk_20 = mapId;
        unk_24 = x;
        unk_28 = y;
    }
    if (!BeginSwitch()) {
        m_switching = FALSE;
        LoadAreaMap();
    }
    MAIN_BSS_020B26A0.m_subScreenShowsMap = 1;
    unk_38 = -1;
    unk_44 = -1;
}

void FieldSubScreen::SetMapPos(int x, int y)
{
    if (!unk_58) {
        m_areaMap->SetPos(x, y);
    }
}

BOOL FieldSubScreen::SwitchToPartyPanel()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    unk_2C = 0;
    m_nextMode = 2;
    if (!BeginSwitch()) {
        m_switching = FALSE;
        LoadPartyPanel();
    }
    MAIN_BSS_020B26A0.m_subScreenShowsMap = 0;
    unk_38 = -1;
    unk_44 = -1;
    return TRUE;
}

BOOL FieldSubScreen::RefreshPartyPanel()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    if (m_mode == 2 && m_nextMode != 2) {
        SwitchToPartyPanel();
    }
    return TRUE;
}

BOOL FieldSubScreen::SwitchToPokemonInfo(u32 id, int arg2)
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    unk_2C = 0;
    if (id != unk_38) {
        m_nextMode = 4;
        unk_38 = id;
        unk_3C = arg2;
        BeginSwitch();
        BeginLoadPokemonInfo();
        unk_44 = -1;
        return TRUE;
    }
    return FALSE;
}

BOOL FieldSubScreen::SwitchToTargetInfo(u32 id)
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    unk_2C = 0;
    if (id != unk_44) {
        m_nextMode = 6;
        unk_44 = id;
        BeginSwitch();
        BeginLoadTargetInfo();
        unk_38 = -1;
        return TRUE;
    }
    return FALSE;
}

BOOL FieldSubScreen::SwitchToRangerCard()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    unk_38 = -1;
    unk_44 = -1;
    m_nextMode = 9;
    if (!BeginSwitch()) {
        m_switching = FALSE;
        LoadRangerCard();
    }
    return TRUE;
}

BOOL FieldSubScreen::ShowRangerCardNow()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    SetVramBanks();
    unk_38 = -1;
    unk_44 = -1;
    SetVramBanks();
    m_rangerCard->Release();
    unk_48 = 0;
    while (unk_48 != -1) {
        unk_48 = m_rangerCard->LoadStep(unk_48);
    }
    m_rangerCard->ReleaseMessages();
    m_mode = 8;
    ResetBGOffsets();
    return TRUE;
}

BOOL FieldSubScreen::ShowDebugInfo()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    if (m_game->unk_15D4 == 0) {
        return FALSE;
    }
    if (m_mode == 8 || m_nextMode == 9 || m_mode == 9) {
        return FALSE;
    }
    SetVramBanks();
    m_mode = 7;
    GXS_SetVisiblePlane(GX_PLANEMASK_BG3);
    SetupBGFonts();
    return TRUE;
}

void FieldSubScreen::TogglePanel()
{
    unk_64 = FALSE;
    if (unk_58) {
        return;
    }
    if (MAIN_BSS_020B26A0.m_subScreenShowsMap != 0) {
        SwitchToPartyPanel();
    } else {
        SwitchToAreaMap(m_mapId, m_areaMap->unk_30, m_areaMap->unk_34);
    }
}

void FieldSubScreen::SwitchToDefaultPanel()
{
    unk_64 = FALSE;
    if (m_nextMode == 9) {
        return;
    }
    if (unk_58) {
        return;
    }
    if (MAIN_BSS_020B26A0.m_subScreenShowsMap != 0) {
        if (m_mode != 1 && m_nextMode != 1) {
            SwitchToAreaMap(m_mapId, m_areaMap->unk_30, m_areaMap->unk_34);
        }
    } else {
        if (m_mode != 2 && m_nextMode != 2) {
            SwitchToPartyPanel();
        }
    }
}

void FieldSubScreen::ShowPicture(int picId)
{
    unk_64 = FALSE;
    m_partyPanel->Release();
    m_pokemonInfo->Release();
    m_targetInfo->Release();
    m_rangerCard->Release();
    m_picture->Init();
    unk_58 = TRUE;
    unk_50 = picId;
    m_nextMode = 10;
    if (!BeginSwitch()) {
        m_switching = FALSE;
        LoadPicture();
    }
    unk_64 = FALSE;
}

void FieldSubScreen::HidePicture()
{
    unk_58 = FALSE;
}

BOOL FieldSubScreen::BeginSwitch()
{
    m_switching = TRUE;
    return FadeOut(10);
}

BOOL FieldSubScreen::LoadAreaMap()
{
    m_partyPanel->Release();
    m_pokemonInfo->Release();
    m_targetInfo->Release();
    m_rangerCard->Release();
    m_picture->Init();
    SetVramBanks();
    FinishSwitch();
    unk_2C = 0;
    m_mapId = unk_20;
    m_areaMap->Show(m_mapId, unk_24, unk_28);
    return TRUE;
}

BOOL FieldSubScreen::LoadPartyPanel()
{
    m_pokemonInfo->Release();
    m_targetInfo->Release();
    m_rangerCard->Release();
    m_picture->Init();
    SetVramBanks();
    unk_2C = 0;
    m_partyPanel->Release();
    m_partyPanel->LoadPanel();
    FinishSwitch();
    return TRUE;
}

void FieldSubScreen::BeginLoadPokemonInfo()
{
    m_partyPanel->Release();
    m_targetInfo->Release();
    m_rangerCard->Release();
    m_picture->Init();
    SetVramBanks();
    unk_2C = 0;
    m_pokemonInfo->Release();
    m_pokemonInfo->ResetLoad();
}

int FieldSubScreen::LoadPokemonInfoStep()
{
    return m_pokemonInfo->LoadStep(unk_38, unk_3C, 0);
}

void FieldSubScreen::BeginLoadTargetInfo()
{
    m_partyPanel->Release();
    m_targetInfo->Release();
    m_rangerCard->Release();
    m_picture->Init();
    SetVramBanks();
    unk_2C = 0;
    m_targetInfo->Release();
    m_targetInfo->ResetLoad();
}

int FieldSubScreen::LoadTargetInfoStep()
{
    return m_targetInfo->Load(unk_44);
}

BOOL FieldSubScreen::LoadRangerCard()
{
    m_partyPanel->Release();
    m_pokemonInfo->Release();
    m_targetInfo->Release();
    m_picture->Init();
    SetVramBanks();
    m_rangerCard->Release();
    ResetBGOffsets();
    m_mode = m_nextMode;
    m_nextMode = 0;
    unk_48 = 0;
    return TRUE;
}

BOOL FieldSubScreen::LoadPicture()
{
    m_partyPanel->Release();
    m_pokemonInfo->Release();
    m_targetInfo->Release();
    m_rangerCard->Release();
    unk_2C = 0;
    m_picture->Init();
    m_picture->Load(unk_50);
    FinishSwitch();
    FadeIn(30);
    return TRUE;
}

void FieldSubScreen::FinishSwitch()
{
    ResetBGOffsets();
    m_mode = m_nextMode;
    m_nextMode = 0;
    FadeIn(10);
}

void FieldSubScreen::ResetBGOffsets()
{
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
}

void FieldSubScreen::SetVramBanks()
{
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_32_H);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);
}

void FieldSubScreen::SetIdleReturn(int arg1)
{
    unk_5C = arg1;
}

void FieldSubScreen::UpdateIdleTimer()
{
    if (unk_5C) {
        unk_2C += 60 / m_game->unk_146C.GetFps();
        if (unk_2C >= 300) {
            SwitchToDefaultPanel();
            unk_64 = TRUE;
            unk_2C = 0;
        }
    }
}

void FieldSubScreen::ClearMapIcons()
{
    if (m_areaMap != NULL) {
        m_areaMap->ClearIcons();
    }
}

void FieldSubScreen::AddMapIcon(int x, int y, int kind)
{
    if (m_areaMap != NULL) {
        m_areaMap->AddIcon(x, y, kind);
    }
}

void FieldSubScreen::FadeIn(u16 duration)
{
    if (m_game == NULL) {
        return;
    }
    if (unk_60) {
        return;
    }
    if (m_game->m_subFade->GetMode() == 2) {
        m_game->m_subFade->Start(1, duration);
    } else {
        m_game->m_subFade->Start(3, duration);
    }
}

BOOL FieldSubScreen::FadeOut(u16 duration)
{
    if (m_game == NULL) {
        return FALSE;
    }
    unk_60 = 0;
    if (m_game->m_subFade->GetMode() == 4 || m_game->m_subFade->GetMode() == 2) {
        return m_game->m_subFade->IsActive();
    }
    m_game->m_subFade->Start(4, duration);
    return TRUE;
}

BOOL FieldSubScreen::IsFading()
{
    if (unk_64) {
        if (m_game->m_subFade->IsActive() || m_game->m_mainFade->IsActive() || m_game->m_mainWipe->func0()) {
            return TRUE;
        }
        unk_64 = FALSE;
        return FALSE;
    }
    return m_game->m_subFade->IsActive();
}

FieldSubScreen *FieldSubScreen::GetInstance()
{
    return sInstance;
}

BOOL FieldSubScreen::IsRangerCardShown()
{
    return m_mode == 8;
}
