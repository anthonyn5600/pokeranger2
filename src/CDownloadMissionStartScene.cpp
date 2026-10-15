#include "scene/CDownloadMissionStartScene.hpp"

#include "DiskHPTable.hpp"
#include "DisplayUtil.hpp"
#include "FieldData.hpp"
#include "FieldDataRecords.hpp"
#include "GlobalValues.hpp"
#include "MissionQuestData.hpp"
#include "SaveData.hpp"
#include "ScriptManager.hpp"
#include "ScriptVM.hpp"
#include "scene/DownloadMission.hpp"

struct FieldEffectSaveBuffer {
    u8 unk_00[0x60];
    u8 unk_60;
    void *unk_64;
};

struct FieldEnemySaveBuffer {
    u8 unk_000[0x800];
    u8 unk_800;
    void *unk_804;
};

extern FieldData *MAIN_BSS_0210CA6C;
extern FieldEffectSaveBuffer MAIN_BSS_0210C1C0;
extern FieldEnemySaveBuffer MAIN_BSS_0210C228;

u8 g_downloadMissionKey[16] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F };

void CDownloadMissionStartScene::func6()
{
    unk_0010 = MAIN_BSS_020B26A0.unk_81AC;
    unk_000C = new SaveManager(1);
    unk_0008 = 0;
    game->m_textboxData->Init(game->unk_0014, game->touchPanel, &game->unk_14AC->unk_0C, game->m_nameTables, game->unk_0024, game->m_audioEngine, 0x10, 0x4000, 0);
    SetupBGFonts();
    game->m_textboxData->LoadSystemMessages(0);
    game->unk_146C.SetFps(60);
}

void CDownloadMissionStartScene::func7()
{
    if (unk_000C != NULL) {
        delete unk_000C;
        unk_000C = NULL;
    }
    game->m_textboxData->FreeSystemMessages();
    game->m_textboxData->Reset();
}

u32 CDownloadMissionStartScene::func0()
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
                unk_0008 = 0x10;
                break;
            case 10:
                unk_0008 = 10;
                break;
            case 3:
            case 9:
            case 11:
                unk_0008 = 10;
                break;
            }
        } else {
            unk_0008 = 2;
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
        unk_0008 = 5;
        game->ApplyTextSettings();
        MAIN_BSS_020B26A0.m_areaType = FieldData_GetMap(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.m_mapId)->unk_04;
        break;
    }
    case 3:
        unk_000C->Load(0);
        unk_0008 = 4;
        break;
    case 4: {
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
                unk_0008 = 0x10;
                break;
            case 10:
                unk_0008 = 8;
                break;
            case 3:
            case 9:
            case 11:
                unk_0008 = 6;
                break;
            }
        } else {
            unk_0008 = 5;
            game->ApplyTextSettings();
            MAIN_BSS_020B26A0.m_areaType = FieldData_GetMap(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.m_mapId)->unk_04;
        }
        break;
    }
    case 5: {
        SaveData *save = &MAIN_BSS_020B26A0;
        int progress = unk_0010 + 0x45;
        SaveData_SelectPartyEntry(save, 0);
        save->unk_8802 = 0;
        save->unk_81AC = unk_0010;
        save->unk_8B68 = 1;
        save->unk_8B6C = progress;
        for (int i = 0; i < 2; i++) {
            save->m_partners[i].unk_00 = 0;
        }

        PartyEntry *found = NULL;
        int foundIdx = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 0 && (save->m_party[i][j].m_flags & 2)) {
                    found = &save->m_party[i][j];
                    foundIdx = j;
                } else {
                    SaveEntry_Clear(&save->m_party[i][j]);
                }
            }
        }
        if (found != NULL && foundIdx != 0) {
            *(PartyEntryData *)&save->m_party[0][0] = *(PartyEntryData *)found;
            save->m_party[0][0].m_flags = 0;
            save->m_party[0][0].m_flags |= found->m_flags;
            SaveEntry_Clear(found);
        }

        SaveData_ClearActorPositions(save);
        MIi_CpuClearFast(0, save->unk_81B4, sizeof(save->unk_81B4));
        save->unk_8434 = 0;
        save->m_partners[0].unk_00 = 0;
        save->m_partners[1].unk_00 = 0;

        s32 v1 = GlobalValues_Get(&MAIN_BSS_0210C0B0, 1);
        s32 v2 = GlobalValues_Get(&MAIN_BSS_0210C0B0, 2);
        s32 v1B = GlobalValues_Get(&MAIN_BSS_0210C0B0, 0x1B);
        s32 v1C = GlobalValues_Get(&MAIN_BSS_0210C0B0, 0x1C);
        s32 v1D = GlobalValues_Get(&MAIN_BSS_0210C0B0, 0x1D);
        s32 v1E = GlobalValues_Get(&MAIN_BSS_0210C0B0, 0x1E);
        s32 v4 = GlobalValues_Get(&MAIN_BSS_0210C0B0, 4);
        MissionQuestData_Clear(&MAIN_BSS_020B2638);
        GlobalValues_Init(&MAIN_BSS_0210C0B0);
        GlobalValues_ClearChapterValues(&MAIN_BSS_0210C0B0);
        GlobalValues_ApplyProgress(&MAIN_BSS_0210C0B0, 0);
        GlobalValues_ApplyProgress(&MAIN_BSS_0210C0B0, progress);
        MissionQuestData_ApplyProgress(&MAIN_BSS_020B2638, 0);
        GlobalValues_Set(&MAIN_BSS_0210C0B0, 1, v1);
        GlobalValues_Set(&MAIN_BSS_0210C0B0, 2, v2);
        GlobalValues_Set(&MAIN_BSS_0210C0B0, 0x1B, v1B);
        GlobalValues_Set(&MAIN_BSS_0210C0B0, 0x1C, v1C);
        GlobalValues_Set(&MAIN_BSS_0210C0B0, 0x1D, v1D);
        GlobalValues_Set(&MAIN_BSS_0210C0B0, 0x1E, v1E);
        GlobalValues_Set(&MAIN_BSS_0210C0B0, 4, v4);
        MI_CpuFill8(&MAIN_BSS_0210C1C0, 0, 0x60);
        MI_CpuFill8(&MAIN_BSS_0210C228, 0, 0x800);
        save->m_energy = save->m_maxEnergy;
        save->unk_0004 = 0;

        RTCTime time;
        RTCDate date;
        RTC_GetTime(&time);
        RTC_GetDate(&date);
        MAIN_BSS_020B26A0.m_lastTime = time;
        MAIN_BSS_020B26A0.m_lastDate = date;
        return 1;
    }
    case 6:
        game->m_textboxData->ResetTextSpeed();
        game->m_textboxData->ShowMessage(0, 0x48, 1, 1, 0);
        game->m_mainFade->Start(3, 5);
        game->m_subFade->Start(3, 5);
        unk_0008 = 7;
        break;
    case 7:
        if (game->m_textboxData->IsActive()) {
            break;
        }
        game->m_textboxData->CloseAndClear(1, 1);
        unk_0008 = 0x12;
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
        unk_0008 = 0x12;
        break;
    case 10:
        unk_000C->Clear(unk_0010 + 1);
        unk_0008 = 11;
        break;
    case 11:
        if (unk_000C->Update() == 0) {
            break;
        }
        game->m_mainFade->Start(3, 5);
        game->m_subFade->Start(3, 5);
        game->m_textboxData->ResetTextSpeed();
        game->m_textboxData->ShowMessage(0, 0x73, 1, 1, 0);
        unk_0008 = 12;
        break;
    case 12:
        if (game->m_textboxData->IsActive()) {
            break;
        }
        game->m_textboxData->ResetTextSpeed();
        game->m_textboxData->ShowMessage(0, 0x74, 1, 1, 0);
        unk_0008 = 13;
        break;
    case 13:
        if (game->m_textboxData->IsActive()) {
            break;
        }
        game->m_textboxData->CloseAndClear(1, 1);
        unk_0008 = 0x12;
        break;
    case 14:
        game->m_textboxData->ResetTextSpeed();
        game->m_textboxData->ShowMessage(0, 0x50, 1, 1, 0);
        game->m_mainFade->Start(3, 5);
        game->m_subFade->Start(3, 5);
        unk_0008 = 15;
        break;
    case 15:
        if (game->m_textboxData->IsActive()) {
            break;
        }
        game->m_textboxData->CloseAndClear(1, 1);
        unk_0008 = 0x12;
        break;
    case 16:
        game->m_textboxData->ResetTextSpeed();
        game->m_textboxData->ShowMessage(0, 0x45, 1, 1, 0);
        game->m_mainFade->Start(3, 5);
        game->m_subFade->Start(3, 5);
        unk_0008 = 0x11;
        break;
    case 17:
        break;
    case 18:
        game->m_mainFade->Start(2, 30);
        game->m_subFade->Start(2, 30);
        unk_0008 = 0x13;
        break;
    case 19:
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

void CDownloadMissionStartScene::func5()
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
    GX_SetBGScrOffset(GX_BGSCROFFSET_0x00000);
    GX_SetBGCharOffset(GX_BGCHAROFFSET_0x00000);
    G2_SetBG0Offset(0, 0);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);
    GX_DispOn();
    GXS_DispOn();
}
