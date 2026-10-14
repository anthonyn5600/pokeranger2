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
    unk_68 = game;
    Init();
}

FieldSubScreen::~FieldSubScreen()
{
    SAFE_DELETE(unk_30);
    SAFE_DELETE(unk_40);
    SAFE_DELETE(unk_34);
    SAFE_DELETE(unk_18);
    SAFE_DELETE(unk_4C);
    SAFE_DELETE(unk_54);
}

void FieldSubScreen::Update()
{
    switch (unk_00) {
    case 0:
        break;
    case 1:
        unk_18->Update();
        break;
    case 2:
        unk_30->Update();
        break;
    case 3:
        break;
    case 4:
        if (unk_34->unk_70 == 0x10) {
            unk_34->Update();
            UpdateIdleTimer();
        }
        break;
    case 5:
        break;
    case 6:
        if (unk_40->unk_50 == 0x10) {
            unk_40->Update();
            UpdateIdleTimer();
        }
        break;
    case 7:
        break;
    case 9:
        unk_48 = unk_4C->LoadStep(unk_48);
        if (unk_48 == -1) {
            unk_4C->ReleaseMessages();
            unk_00 = 8;
            sub_02023230(10);
        }
        break;
    case 8:
        unk_4C->Update();
        break;
    case 10:
        unk_54->Update();
        break;
    }

    if (unk_04) {
        if (sub_0202331C()) {
            return;
        }
        unk_04 = FALSE;
        switch (unk_02) {
        case 0:
            break;
        case 1:
            sub_02022EE8();
            break;
        case 2:
            sub_02022F50();
            break;
        case 3:
            break;
        case 4:
            unk_00 = 3;
            if (sub_02022FF4() != 0x10) {
                unk_04 = TRUE;
                return;
            }
            sub_02023134();
            unk_34->ReleaseMessages();
            unk_00 = 4;
            break;
        case 5:
            break;
        case 6:
            unk_00 = 5;
            if (sub_02023060() != 0x10) {
                unk_04 = TRUE;
                return;
            }
            sub_02023134();
            unk_40->ReleaseMessages();
            unk_00 = 6;
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            sub_02023078();
            break;
        case 10:
            sub_020230D4();
            break;
        }
    }
}

void FieldSubScreen::sub_02022710()
{
}

void FieldSubScreen::Render()
{
    switch (unk_00) {
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
        if (unk_34->unk_70 == 0x10) {
            RenderPokemonInfo();
        }
        break;
    case 5:
        break;
    case 6:
        if (unk_40->unk_50 == 0x10) {
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
        sub_02001210();
        break;
    }
}

void FieldSubScreen::sub_020227AC()
{
    if (unk_00 == 7) {
        sub_02007D78();
    }
}

void FieldSubScreen::Init()
{
    unk_02 = unk_00 = 0;
    sInstance = this;
    sub_020228C0();
    unk_04 = FALSE;
    unk_18 = new SubScreenAreaMap(unk_68);
    unk_18->Load();
    unk_40 = new SubScreenTargetInfo();
    unk_40->LoadBG();
    unk_34 = new SubScreenPokemonInfo();
    unk_34->LoadPTC();
    unk_30 = new SubScreenPartyPanel();
    unk_4C = new SubScreenRangerCard();
    unk_54 = new SubScreenPicture(unk_68);
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
    unk_18->Render();
}

void FieldSubScreen::RenderPartyPanel()
{
    unk_30->Render();
}

void FieldSubScreen::RenderPokemonInfo()
{
    unk_34->Render();
}

void FieldSubScreen::RenderTargetInfo()
{
    unk_40->Render();
}

void FieldSubScreen::RenderRangerCard()
{
    unk_4C->Render();
}

void FieldSubScreen::RenderPicture()
{
    unk_54->Render();
}

void FieldSubScreen::HideAreaMap()
{
    if (unk_18 != NULL) {
        unk_18->Hide();
    }
}

BOOL FieldSubScreen::ShowAreaMap(u32 mapId, int x, int y)
{
    unk_64 = FALSE;
    unk_2C = 0;
    unk_1C = mapId;
    unk_18->SetMap(mapId, x, y);
    if (unk_58) {
        return FALSE;
    }
    unk_44 = -1;
    unk_38 = -1;
    SetVramBanks();
    if (MAIN_BSS_020B26A0.unk_8B70 == 0) {
        unk_30->Release();
        unk_30->LoadPanel();
        ResetBGOffsets();
        unk_00 = 2;
        unk_02 = 0;
        return FALSE;
    }
    unk_18->Show(unk_1C, x, y);
    unk_00 = 1;
    unk_02 = 0;
    MAIN_BSS_020B26A0.unk_8B70 = 1;
    return TRUE;
}

void FieldSubScreen::SwitchToAreaMap(int mapId, int x, int y)
{
    unk_64 = FALSE;
    if (unk_58) {
        return;
    }
    unk_02 = 1;
    if (x == -1000 && y == -1000 && mapId == -1000) {
        unk_20 = unk_1C;
        unk_24 = unk_18->unk_30;
        unk_28 = unk_18->unk_34;
    } else {
        unk_20 = mapId;
        unk_24 = x;
        unk_28 = y;
    }
    if (!sub_02022ED0()) {
        unk_04 = FALSE;
        sub_02022EE8();
    }
    MAIN_BSS_020B26A0.unk_8B70 = 1;
    unk_38 = -1;
    unk_44 = -1;
}

void FieldSubScreen::SetMapPos(int x, int y)
{
    if (!unk_58) {
        unk_18->SetPos(x, y);
    }
}

BOOL FieldSubScreen::SwitchToPartyPanel()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    unk_2C = 0;
    unk_02 = 2;
    if (!sub_02022ED0()) {
        unk_04 = FALSE;
        sub_02022F50();
    }
    MAIN_BSS_020B26A0.unk_8B70 = 0;
    unk_38 = -1;
    unk_44 = -1;
    return TRUE;
}

BOOL FieldSubScreen::sub_02022B20()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    if (unk_00 == 2 && unk_02 != 2) {
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
        unk_02 = 4;
        unk_38 = id;
        unk_3C = arg2;
        sub_02022ED0();
        sub_02022FA8();
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
        unk_02 = 6;
        unk_44 = id;
        sub_02022ED0();
        sub_02023014();
        unk_38 = -1;
        return TRUE;
    }
    return FALSE;
}

BOOL FieldSubScreen::sub_02022C1C()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    unk_38 = -1;
    unk_44 = -1;
    unk_02 = 9;
    if (!sub_02022ED0()) {
        unk_04 = FALSE;
        sub_02023078();
    }
    return TRUE;
}

BOOL FieldSubScreen::sub_02022C74()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    SetVramBanks();
    unk_38 = -1;
    unk_44 = -1;
    SetVramBanks();
    unk_4C->Release();
    unk_48 = 0;
    while (unk_48 != -1) {
        unk_48 = unk_4C->LoadStep(unk_48);
    }
    unk_4C->ReleaseMessages();
    unk_00 = 8;
    ResetBGOffsets();
    return TRUE;
}

BOOL FieldSubScreen::sub_02022D04()
{
    unk_64 = FALSE;
    if (unk_58) {
        return FALSE;
    }
    if (unk_68->unk_15D4 == 0) {
        return FALSE;
    }
    if (unk_00 == 8 || unk_02 == 9 || unk_00 == 9) {
        return FALSE;
    }
    SetVramBanks();
    unk_00 = 7;
    GXS_SetVisiblePlane(GX_PLANEMASK_BG3);
    SetupBGFonts();
    return TRUE;
}

void FieldSubScreen::sub_02022D88()
{
    unk_64 = FALSE;
    if (unk_58) {
        return;
    }
    if (MAIN_BSS_020B26A0.unk_8B70 != 0) {
        SwitchToPartyPanel();
    } else {
        SwitchToAreaMap(unk_1C, unk_18->unk_30, unk_18->unk_34);
    }
}

void FieldSubScreen::sub_02022DD4()
{
    unk_64 = FALSE;
    if (unk_02 == 9) {
        return;
    }
    if (unk_58) {
        return;
    }
    if (MAIN_BSS_020B26A0.unk_8B70 != 0) {
        if (unk_00 != 1 && unk_02 != 1) {
            SwitchToAreaMap(unk_1C, unk_18->unk_30, unk_18->unk_34);
        }
    } else {
        if (unk_00 != 2 && unk_02 != 2) {
            SwitchToPartyPanel();
        }
    }
}

void FieldSubScreen::ShowPicture(int picId)
{
    unk_64 = FALSE;
    unk_30->Release();
    unk_34->Release();
    unk_40->Release();
    unk_4C->Release();
    unk_54->Init();
    unk_58 = TRUE;
    unk_50 = picId;
    unk_02 = 10;
    if (!sub_02022ED0()) {
        unk_04 = FALSE;
        sub_020230D4();
    }
    unk_64 = FALSE;
}

void FieldSubScreen::sub_02022EC4()
{
    unk_58 = FALSE;
}

BOOL FieldSubScreen::sub_02022ED0()
{
    unk_04 = TRUE;
    return sub_02023298(10);
}

BOOL FieldSubScreen::sub_02022EE8()
{
    unk_30->Release();
    unk_34->Release();
    unk_40->Release();
    unk_4C->Release();
    unk_54->Init();
    SetVramBanks();
    sub_02023134();
    unk_2C = 0;
    unk_1C = unk_20;
    unk_18->Show(unk_1C, unk_24, unk_28);
    return TRUE;
}

BOOL FieldSubScreen::sub_02022F50()
{
    unk_34->Release();
    unk_40->Release();
    unk_4C->Release();
    unk_54->Init();
    SetVramBanks();
    unk_2C = 0;
    unk_30->Release();
    unk_30->LoadPanel();
    sub_02023134();
    return TRUE;
}

void FieldSubScreen::sub_02022FA8()
{
    unk_30->Release();
    unk_40->Release();
    unk_4C->Release();
    unk_54->Init();
    SetVramBanks();
    unk_2C = 0;
    unk_34->Release();
    unk_34->ResetLoad();
}

int FieldSubScreen::sub_02022FF4()
{
    return unk_34->LoadStep(unk_38, unk_3C, 0);
}

void FieldSubScreen::sub_02023014()
{
    unk_30->Release();
    unk_40->Release();
    unk_4C->Release();
    unk_54->Init();
    SetVramBanks();
    unk_2C = 0;
    unk_40->Release();
    unk_40->ResetLoad();
}

int FieldSubScreen::sub_02023060()
{
    return unk_40->Load(unk_44);
}

BOOL FieldSubScreen::sub_02023078()
{
    unk_30->Release();
    unk_34->Release();
    unk_40->Release();
    unk_54->Init();
    SetVramBanks();
    unk_4C->Release();
    ResetBGOffsets();
    unk_00 = unk_02;
    unk_02 = 0;
    unk_48 = 0;
    return TRUE;
}

BOOL FieldSubScreen::sub_020230D4()
{
    unk_30->Release();
    unk_34->Release();
    unk_40->Release();
    unk_4C->Release();
    unk_2C = 0;
    unk_54->Init();
    unk_54->Load(unk_50);
    sub_02023134();
    sub_02023230(30);
    return TRUE;
}

void FieldSubScreen::sub_02023134()
{
    ResetBGOffsets();
    unk_00 = unk_02;
    unk_02 = 0;
    sub_02023230(10);
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
        unk_2C += 60 / unk_68->unk_146C.GetFps();
        if (unk_2C >= 300) {
            sub_02022DD4();
            unk_64 = TRUE;
            unk_2C = 0;
        }
    }
}

void FieldSubScreen::ClearMapIcons()
{
    if (unk_18 != NULL) {
        unk_18->ClearIcons();
    }
}

void FieldSubScreen::AddMapIcon(int x, int y, int kind)
{
    if (unk_18 != NULL) {
        unk_18->AddIcon(x, y, kind);
    }
}

void FieldSubScreen::sub_02023230(u16 duration)
{
    if (unk_68 == NULL) {
        return;
    }
    if (unk_60) {
        return;
    }
    if (unk_68->unk_14C0->GetMode() == 2) {
        unk_68->unk_14C0->Start(1, duration);
    } else {
        unk_68->unk_14C0->Start(3, duration);
    }
}

BOOL FieldSubScreen::sub_02023298(u16 duration)
{
    if (unk_68 == NULL) {
        return FALSE;
    }
    unk_60 = 0;
    if (unk_68->unk_14C0->GetMode() == 4 || unk_68->unk_14C0->GetMode() == 2) {
        return unk_68->unk_14C0->IsActive();
    }
    unk_68->unk_14C0->Start(4, duration);
    return TRUE;
}

BOOL FieldSubScreen::sub_0202331C()
{
    if (unk_64) {
        if (unk_68->unk_14C0->IsActive() || unk_68->unk_14BC->IsActive() || unk_68->unk_14C4->func0()) {
            return TRUE;
        }
        unk_64 = FALSE;
        return FALSE;
    }
    return unk_68->unk_14C0->IsActive();
}

FieldSubScreen *FieldSubScreen::GetInstance()
{
    return sInstance;
}

BOOL FieldSubScreen::IsRangerCardShown()
{
    return unk_00 == 8;
}
