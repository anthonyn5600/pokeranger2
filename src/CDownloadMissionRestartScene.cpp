#include "scene/CDownloadMissionRestartScene.hpp"

#include "DiskHPTable.hpp"
#include "DisplayUtil.hpp"
#include "FieldData.hpp"
#include "SaveData.hpp"
#include "ScriptManager.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkStruct_02044464.hpp"
#include "scene/DownloadMission.hpp"

extern FieldData *MAIN_BSS_0210CA6C;

void CDownloadMissionRestartScene::func6()
{
    unk_0010 = MAIN_BSS_020B26A0.unk_81AC;
    unk_000C = new SaveManager(1);
    unk_0008 = 0;
    game->m_textboxData->Init(game->unk_0014, game->touchPanel, &game->unk_14AC->unk_0C, game->m_nameTables, game->unk_0024, game->m_audioEngine, 0x10, 0x4000, 0);
    SetupBGFonts();
    game->m_textboxData->LoadSystemMessages(0);
    game->unk_146C.SetFps(60);
}

void CDownloadMissionRestartScene::func7()
{
    if (unk_000C != NULL) {
        delete unk_000C;
        unk_000C = NULL;
    }
    game->m_textboxData->FreeSystemMessages();
    game->m_textboxData->Reset();
}

u32 CDownloadMissionRestartScene::func0()
{
    switch (unk_0008) {
    case 0:
        unk_000C->Load(unk_0010 + 1);
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
                unk_0008 = 7;
                break;
            case 10:
                unk_0008 = 3;
                break;
            case 3:
            case 9:
            case 11:
                unk_0008 = 3;
                break;
            }
        } else {
            unk_0008 = 2;
            game->ApplyTextSettings();
            MAIN_BSS_020B26A0.m_areaType = FieldData_GetMap(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.m_mapId)->unk_04;
        }
        break;
    }
    case 2: {
        ScriptManager *script = game->m_scriptManager;
        u32 *data = (u32 *)MAIN_BSS_020AF620.unk_00.unk_04;
        CRYPTORC4FastContext ctx;
        CRYPTO_RC4FastInit(&ctx, g_downloadMissionKey, 0x10);
        CRYPTO_RC4FastEncrypt(&ctx, data, 0x3000, data);
        switch ((int)(*data & 0xF0)) {
        case 0x10:
            MI_UncompressLZ8(data, script->m_chapterBuffer);
            break;
        case 0x20:
            MI_UncompressHuffman(data, script->m_chapterBuffer);
            break;
        case 0x30:
            MI_UncompressRL8(data, script->m_chapterBuffer);
            break;
        case 0x80:
            MI_UnfilterDiff8(data, script->m_chapterBuffer);
            break;
        }
        Script_Link(script->m_chapterBuffer);
        return 1;
    }
    case 3:
        unk_000C->Clear(unk_0010 + 1);
        unk_0008 = 4;
        break;
    case 4:
        if (unk_000C->Update() == 0) {
            break;
        }
        game->m_mainFade->Start(3, 5);
        game->m_subFade->Start(3, 5);
        game->m_textboxData->ResetTextSpeed();
        game->m_textboxData->ShowMessage(0, 0x73, 1, 1, 0);
        unk_0008 = 5;
        break;
    case 5:
        if (game->m_textboxData->IsActive()) {
            break;
        }
        game->m_textboxData->ResetTextSpeed();
        game->m_textboxData->ShowMessage(0, 0x74, 1, 1, 0);
        unk_0008 = 6;
        break;
    case 6:
        if (game->m_textboxData->IsActive()) {
            break;
        }
        game->m_textboxData->CloseAndClear(1, 1);
        unk_0008 = 11;
        break;
    case 9:
        game->m_textboxData->ResetTextSpeed();
        game->m_textboxData->ShowMessage(0, 0x50, 1, 1, 0);
        game->m_mainFade->Start(3, 5);
        game->m_subFade->Start(3, 5);
        unk_0008 = 10;
        break;
    case 10:
        if (game->m_textboxData->IsActive()) {
            break;
        }
        game->m_textboxData->CloseAndClear(1, 1);
        unk_0008 = 11;
        break;
    case 7:
        game->m_textboxData->ResetTextSpeed();
        game->m_textboxData->ShowMessage(0, 0x45, 1, 1, 0);
        game->m_mainFade->Start(3, 5);
        game->m_subFade->Start(3, 5);
        unk_0008 = 8;
        break;
    case 8:
        break;
    case 11:
        game->m_mainFade->Start(2, 30);
        game->m_subFade->Start(2, 30);
        unk_0008 = 12;
        break;
    case 12:
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

void CDownloadMissionRestartScene::func5()
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
