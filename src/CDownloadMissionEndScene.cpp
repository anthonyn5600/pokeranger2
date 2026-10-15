#include "scene/CDownloadMissionEndScene.hpp"

#include "DiskHPTable.hpp"
#include "SaveData.hpp"

void CDownloadMissionEndScene::func6()
{
    unk_0010 = MAIN_BSS_020B26A0.m_maxEnergy;
    unk_0011 = MAIN_BSS_020B26A0.m_stylerLevel;
    unk_0014 = MAIN_BSS_020B26A0.m_levelExp;
    unk_0018 = MAIN_BSS_020B26A0.m_exp;
    MI_CpuCopyFast(MAIN_BSS_020B26A0.m_pokemonStates, unk_001C, sizeof(unk_001C));
    MI_CpuCopyFast(MAIN_BSS_020B26A0.unk_7EB0, unk_009C, sizeof(unk_009C));
    MI_CpuCopy8(MAIN_BSS_020B26A0.m_captureCounts, unk_011C, sizeof(unk_011C));
    unk_0314 = MAIN_BSS_020B26A0.m_stepsWalked;
    unk_0318 = MAIN_BSS_020B26A0.m_conversations;
    unk_031C = MAIN_BSS_020B26A0.m_targetsChecked;
    unk_0320 = MAIN_BSS_020B26A0.m_saveCount;
    unk_0324 = MAIN_BSS_020B26A0.m_pokemonRides;
    MI_CpuCopyFast(MAIN_BSS_020B26A0.m_partnerCounts, unk_0328, sizeof(unk_0328));
    unk_036C = MAIN_BSS_020B26A0.m_captureLineLength;
    unk_0370 = MAIN_BSS_020B26A0.m_loopCount;
    unk_0374 = MAIN_BSS_020B26A0.m_totalCaptures;
    unk_0376 = MAIN_BSS_020B26A0.m_fledCount;
    unk_0378 = MAIN_BSS_020B26A0.m_assistsUsed;
    unk_037C = MAIN_BSS_020B26A0.m_lastPlayHours;
    unk_0380 = MAIN_BSS_020B26A0.m_lastPlayMinutes;
    unk_0384 = MAIN_BSS_020B26A0.m_playHours;
    unk_0388 = MAIN_BSS_020B26A0.m_playMinutes;
    unk_0389 = MAIN_BSS_020B26A0.m_playSeconds;
    unk_038A = MAIN_BSS_020B26A0.unk_87DA;
    unk_0310 = MAIN_BSS_020B26A0.unk_8803;
    unk_038C = MAIN_BSS_020B26A0.unk_81AC;
    game->m_textboxData->Init(game->unk_0014, game->touchPanel, &game->unk_14AC->unk_0C, game->m_nameTables, game->unk_0024, game->m_audioEngine, 0x10, 0x4000, 0);
    game->m_textboxData->LoadSystemMessages(0);
    unk_0008 = 0;
    game->unk_146C.SetFps(60);
}

void CDownloadMissionEndScene::func7()
{
    if (unk_000C != NULL) {
        delete unk_000C;
        unk_000C = NULL;
    }
    game->m_textboxData->FreeSystemMessages();
    game->m_textboxData->Reset();
}

u32 CDownloadMissionEndScene::func0()
{
    switch (unk_0008) {
    case 0:
        unk_000C = new SaveManager(1);
        unk_000C->Load(0);
        unk_0008 = 1;
        break;
    case 1: {
        u32 result = unk_000C->Update();
        if (result == 0) {
            break;
        }
        if (result & 0x80) {
            switch (result & ~0x80) {
            case 0:
            case 1:
            case 2:
            case 8:
                unk_0008 = 6;
                break;
            case 10:
                unk_0008 = 8;
                break;
            case 3:
            case 9:
            case 11:
                unk_0008 = 4;
                break;
            }
        } else {
            unk_0008 = 2;
            game->ApplyTextSettings();
        }
        break;
    }
    case 2: {
        MAIN_BSS_020B26A0.m_maxEnergy = unk_0010;
        SaveData_SetStylerLevel(&MAIN_BSS_020B26A0, unk_0011);
        MAIN_BSS_020B26A0.m_levelExp = unk_0014;
        SaveData_SetExp(&MAIN_BSS_020B26A0, unk_0018);
        MI_CpuCopyFast(unk_001C, MAIN_BSS_020B26A0.m_pokemonStates, sizeof(unk_001C));
        MI_CpuCopyFast(unk_009C, MAIN_BSS_020B26A0.unk_7EB0, sizeof(unk_009C));
        MI_CpuCopy8(unk_011C, MAIN_BSS_020B26A0.m_captureCounts, sizeof(unk_011C));
        MAIN_BSS_020B26A0.unk_8803 = unk_0310;
        SaveData_SetStepsWalked(&MAIN_BSS_020B26A0, unk_0314);
        SaveData_SetConversations(&MAIN_BSS_020B26A0, unk_0318);
        SaveData_SetTargetsChecked(&MAIN_BSS_020B26A0, unk_031C);
        SaveData_SetSaveCount(&MAIN_BSS_020B26A0, unk_0320);
        SaveData_SetPokemonRides(&MAIN_BSS_020B26A0, unk_0324);
        MI_CpuCopyFast(unk_0328, MAIN_BSS_020B26A0.m_partnerCounts, sizeof(unk_0328));
        SaveData_SetCaptureLineLength(&MAIN_BSS_020B26A0, unk_036C);
        SaveData_SetLoopCount(&MAIN_BSS_020B26A0, unk_0370);
        SaveData_SetTotalCaptures(&MAIN_BSS_020B26A0, unk_0374);
        SaveData_SetFledCount(&MAIN_BSS_020B26A0, unk_0376);
        SaveData_SetAssistsUsed(&MAIN_BSS_020B26A0, unk_0378);
        MAIN_BSS_020B26A0.m_lastPlayHours = unk_037C;
        MAIN_BSS_020B26A0.m_lastPlayMinutes = unk_0380;
        MAIN_BSS_020B26A0.m_playHours = unk_0384;
        MAIN_BSS_020B26A0.m_playMinutes = unk_0388;
        MAIN_BSS_020B26A0.m_playSeconds = unk_0389;
        MAIN_BSS_020B26A0.unk_87DA = unk_038A;
        int idx = unk_038C - 1;
        if (idx >= 0 && idx < 6) {
            DownloadMissionClears_Set(&MAIN_BSS_020AF598, idx);
            if (idx < 3) {
                DownloadMissionRecord_SetCleared(&MAIN_BSS_020AF5E4[idx], idx);
            }
        }
        unk_0008 = 3;
        break;
    }
    case 3:
        return 0x15;
    case 4:
        game->m_textboxData->ResetTextSpeed();
        game->m_textboxData->ShowMessage(0, 0x48, 1, 1, 0);
        game->m_mainFade->Start(3, 5);
        game->m_subFade->Start(3, 5);
        unk_0008 = 5;
        break;
    case 5:
        if (game->m_textboxData->IsActive()) {
            break;
        }
        game->m_textboxData->CloseAndClear(1, 1);
        unk_0008 = 10;
        break;
    case 6:
        game->m_textboxData->ResetTextSpeed();
        game->m_textboxData->ShowMessage(0, 0x45, 1, 1, 0);
        game->m_mainFade->Start(3, 5);
        game->m_subFade->Start(3, 5);
        unk_0008 = 7;
        break;
    case 7:
        break;
    case 8:
        game->m_textboxData->ResetTextSpeed();
        game->m_textboxData->ShowMessage(0, 0x50, 1, 1, 0);
        game->m_mainFade->Start(3, 5);
        game->m_subFade->Start(3, 5);
        unk_0008 = 9;
        break;
    case 9:
        if (game->m_textboxData->IsActive()) {
            break;
        }
        game->m_textboxData->CloseAndClear(1, 1);
        unk_0008 = 10;
        break;
    case 10:
        game->m_mainFade->Start(2, 30);
        game->m_subFade->Start(2, 30);
        unk_0008 = 11;
        break;
    case 11:
        if (game->m_mainFade->IsActive()) {
            break;
        }
        if (game->m_subFade->IsActive()) {
            break;
        }
        return 0x11;
    }

    return -1;
}

void CDownloadMissionEndScene::func5()
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
    GXS_SetVisiblePlane(GX_PLANEMASK_BG3);
    GX_DispOn();
    GXS_DispOn();
}
