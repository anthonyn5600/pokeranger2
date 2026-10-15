#include "scene/CRetryScene.hpp"

#include "CGame.hpp"
#include "DisplayUtil.hpp"
#include "SaveData.hpp"
#include "SaveDataBuffer.hpp"
#include "UnkClass_02041D80.hpp"

extern SaveData MAIN_BSS_020B26A0;
extern FieldData *MAIN_BSS_0210CA6C;

CRetryScene::CRetryScene()
{
    unk_0004 = 0;
    unk_0008 = 0;
    unk_0010 = NULL;
    unk_000C = 0x11;
}

CRetryScene::~CRetryScene()
{
}

u32 CRetryScene::func0()
{
    switch (unk_0008) {
    case 0:
        if (s_game->m_mainFade->IsActive()) {
            break;
        }
        if (s_game->m_subFade->IsActive()) {
            break;
        }
        s_game->m_textboxData->ShowMessage(0, 0x4F, 1, 1, 0);
        unk_0008 = 1;
        break;
    case 1:
        if (s_game->m_textboxData->IsActive()) {
            break;
        }
        if (s_game->m_textboxData->CloseIfNoPrompt(1)) {
            break;
        }
        if (s_game->m_textboxData->GetYesNoResult() == 0) {
            unk_0008 = 2;
        } else {
            s_game->m_textboxData->ShowMessage(0, 0x51, 1, 1, 0);
            unk_0008 = 8;
        }
        break;
    case 2:
        unk_0010 = new SaveManager(1);
        unk_0010->Load(0);
        unk_0008 = 3;
        break;
    case 3: {
        int result = unk_0010->Update();
        if (result == 0) {
            break;
        }
        if (!(result & 0x80)) {
            s_game->ApplyTextSettings();
            MAIN_BSS_020B26A0.m_areaType = FieldData_GetMap(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.m_mapId)->unk_04;
            MAIN_BSS_020B26A0.unk_8B68 = 0;
            MAIN_BSS_020B26A0.unk_8B6C = 0;
            MAIN_BSS_0210C1C0.unk_60 = 1;
            MAIN_BSS_0210C228.unk_800 = 1;
            s_game->m_mainFade->Start(4, 30);
            s_game->m_subFade->Start(4, 30);
            unk_000C = 1;
            unk_0008 = 10;
        } else {
            switch (result & ~0x80) {
            case 1:
            case 2:
            case 8:
                s_game->m_textboxData->ShowMessage(0, 0x45, 1, 1, 0);
                unk_0008 = 7;
                break;
            case 10:
                s_game->m_textboxData->ShowMessage(0, 0x50, 1, 1, 0);
                unk_0008 = 4;
                break;
            default:
                unk_0010->sub_02028360(0);
                unk_0008 = 5;
                break;
            }
        }
        break;
    }
    case 5: {
        int result = unk_0010->Update();
        if (result == 0) {
            break;
        }
        SAFE_DELETE(unk_0010);
        if (!(result & 0x80)) {
            s_game->ApplyTextSettings();
            MAIN_BSS_020B26A0.m_areaType = FieldData_GetMap(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.m_mapId)->unk_04;
            MAIN_BSS_020B26A0.unk_8B68 = 0;
            MAIN_BSS_020B26A0.unk_8B6C = 0;
            MAIN_BSS_0210C1C0.unk_60 = 1;
            MAIN_BSS_0210C228.unk_800 = 1;
            s_game->m_mainFade->Start(4, 30);
            s_game->m_subFade->Start(4, 30);
            unk_000C = 1;
            unk_0008 = 10;
        } else {
            switch (result & ~0x80) {
            case 1:
            case 2:
            case 8:
                s_game->m_textboxData->ShowMessage(0, 0x45, 1, 1, 0);
                unk_0008 = 7;
                break;
            case 10:
            default:
                s_game->m_textboxData->ShowMessage(0, 0x47, 1, 1, 0);
                unk_0008 = 4;
                break;
            }
        }
        break;
    }
    case 4:
        if (s_game->m_textboxData->IsActive()) {
            break;
        }
        s_game->m_textboxData->ShowMessage(0, 0x51, 1, 1, 0);
        unk_0008 = 8;
        break;
    case 8:
        if (s_game->m_textboxData->IsActive()) {
            break;
        }
        s_game->m_mainFade->Start(4, 30);
        s_game->m_subFade->Start(4, 30);
        unk_000C = 0x11;
        unk_0008 = 10;
        break;
    case 10:
        if (s_game->m_mainFade->IsActive()) {
            break;
        }
        if (s_game->m_subFade->IsActive()) {
            break;
        }
        RTCTime time;
        RTCDate date;
        RTC_GetTime(&time);
        RTC_GetDate(&date);
        MAIN_BSS_020B26A0.m_lastTime = time;
        MAIN_BSS_020B26A0.m_lastDate = date;
        return unk_000C;
    }

    return -1;
}

void CRetryScene::func1()
{
}

void CRetryScene::func2()
{
}

void CRetryScene::func5()
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

    GX_SetBankForTex(GX_VRAM_TEX_0123_ABCD);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_0_G);
    GX_SetBankForOBJ(GX_VRAM_OBJ_64_E);
    GX_SetBankForBG(GX_VRAM_BG_16_F);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_32_H);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_SetVisiblePlane(GX_PLANEMASK_BG3);
    GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
    GX_DispOn();
    GXS_DispOn();
}

void CRetryScene::func6()
{
    s_game->unk_146C.SetFps(60);
    unk_0004 = 0;
    unk_0008 = 0;
    SaveData_Init(&MAIN_BSS_020B26A0);
    SetupBGFonts();
    s_game->m_textboxData->Init(s_game->unk_0014, s_game->touchPanel, &s_game->unk_14AC->unk_0C, s_game->m_nameTables, s_game->unk_0024, s_game->m_audioEngine, 0x10, 0x4000, 0);
    s_game->m_textboxData->LoadSystemMessages(0);
    s_game->m_mainFade->Start(3, 30);
    s_game->m_subFade->Start(3, 30);
}

void CRetryScene::func7()
{
    SAFE_DELETE(unk_0010);
    s_game->m_textboxData->FreeSystemMessages();
    s_game->m_textboxData->Reset();
    s_game->unk_146C.SetFps(30);
}

u32 CRetryScene::getSceneId()
{
    return 0x19;
}
