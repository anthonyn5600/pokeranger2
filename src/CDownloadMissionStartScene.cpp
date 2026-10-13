#include "scene/CDownloadMissionStartScene.hpp"

#include "UnkClass_02010D2C.hpp"
#include "UnkClass_0201164C.hpp"
#include "UnkClass_02018DF4.hpp"
#include "UnkClass_02033F04.hpp"
#include "UnkClass_02041C80.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkClass_020B26A0.hpp"
#include "UnkStruct_02044464.hpp"
#include "scene/DownloadMission.hpp"
#include "sub_02007CF0.hpp"

struct UnkStruct_0210C1C0 {
    u8 unk_00[0x60];
    u8 unk_60;
    void *unk_64;
};

struct UnkStruct_0210C228 {
    u8 unk_000[0x800];
    u8 unk_800;
    void *unk_804;
};

extern UnkClass_02041C80 *MAIN_BSS_0210CA6C;
extern UnkStruct_0210C1C0 MAIN_BSS_0210C1C0;
extern UnkStruct_0210C228 MAIN_BSS_0210C228;

u8 g_downloadMissionKey[16] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F };

void CDownloadMissionStartScene::func6()
{
    unk_0010 = MAIN_BSS_020B26A0.unk_81AC;
    unk_000C = new UnkClass_02027FE8(1);
    unk_0008 = 0;
    game->m_textboxData->sub_02009328(game->unk_0014, game->touchPanel, &game->unk_14AC->unk_0C, game->unk_14B0, game->unk_0024, game->m_audioEngine, 0x10, 0x4000, 0);
    sub_02007D68();
    game->m_textboxData->sub_0200AB28(0);
    game->unk_146C.sub_02008DB4(60);
}

void CDownloadMissionStartScene::func7()
{
    if (unk_000C != NULL) {
        delete unk_000C;
        unk_000C = NULL;
    }
    game->m_textboxData->sub_0200AC90();
    game->m_textboxData->sub_020092D4();
}

u32 CDownloadMissionStartScene::func0()
{
    switch (unk_0008) {
    case 0:
        unk_000C->Load(unk_0010 + 1);
        unk_0008 = 1;
        break;
    case 1: {
        u32 result = unk_000C->sub_0202841C();
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
        UnkClass_02033F04 *script = game->m_scriptManager;
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
        sub_02044AC8(script->m_chapterBuffer);
        unk_0008 = 5;
        game->sub_0201024C();
        MAIN_BSS_020B26A0.unk_8B64 = sub_02041D80(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.unk_001A)->unk_04;
        break;
    }
    case 3:
        unk_000C->Load(0);
        unk_0008 = 4;
        break;
    case 4: {
        u32 result = unk_000C->sub_0202841C();
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
            game->sub_0201024C();
            MAIN_BSS_020B26A0.unk_8B64 = sub_02041D80(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.unk_001A)->unk_04;
        }
        break;
    }
    case 5: {
        UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
        int progress = unk_0010 + 0x45;
        sub_020162BC(save, 0);
        save->unk_8802 = 0;
        save->unk_81AC = unk_0010;
        save->unk_8B68 = 1;
        save->unk_8B6C = progress;
        for (int i = 0; i < 2; i++) {
            save->unk_8AD4[i].unk_00 = 0;
        }

        UnkStruct_020155FC *found = NULL;
        int foundIdx = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 10; j++) {
                if (i == 0 && (save->unk_8804[i][j].unk_08 & 2)) {
                    found = &save->unk_8804[i][j];
                    foundIdx = j;
                } else {
                    sub_020150B8(&save->unk_8804[i][j]);
                }
            }
        }
        if (found != NULL && foundIdx != 0) {
            *(UnkStruct_020155FC_Data *)&save->unk_8804[0][0] = *(UnkStruct_020155FC_Data *)found;
            save->unk_8804[0][0].unk_08 = 0;
            save->unk_8804[0][0].unk_08 |= found->unk_08;
            sub_020150B8(found);
        }

        sub_02016024(save);
        MIi_CpuClearFast(0, save->unk_81B4, sizeof(save->unk_81B4));
        save->unk_8434 = 0;
        save->unk_8AD4[0].unk_00 = 0;
        save->unk_8AD4[1].unk_00 = 0;

        s32 v1 = sub_02019278(&MAIN_BSS_0210C0B0, 1);
        s32 v2 = sub_02019278(&MAIN_BSS_0210C0B0, 2);
        s32 v1B = sub_02019278(&MAIN_BSS_0210C0B0, 0x1B);
        s32 v1C = sub_02019278(&MAIN_BSS_0210C0B0, 0x1C);
        s32 v1D = sub_02019278(&MAIN_BSS_0210C0B0, 0x1D);
        s32 v1E = sub_02019278(&MAIN_BSS_0210C0B0, 0x1E);
        s32 v4 = sub_02019278(&MAIN_BSS_0210C0B0, 4);
        sub_0201135C(&MAIN_BSS_020B2638);
        sub_02018E1C(&MAIN_BSS_0210C0B0);
        sub_02018E30(&MAIN_BSS_0210C0B0);
        sub_02018E94(&MAIN_BSS_0210C0B0, 0);
        sub_02018E94(&MAIN_BSS_0210C0B0, progress);
        sub_020116C0(&MAIN_BSS_020B2638, 0);
        sub_0201926C(&MAIN_BSS_0210C0B0, 1, v1);
        sub_0201926C(&MAIN_BSS_0210C0B0, 2, v2);
        sub_0201926C(&MAIN_BSS_0210C0B0, 0x1B, v1B);
        sub_0201926C(&MAIN_BSS_0210C0B0, 0x1C, v1C);
        sub_0201926C(&MAIN_BSS_0210C0B0, 0x1D, v1D);
        sub_0201926C(&MAIN_BSS_0210C0B0, 0x1E, v1E);
        sub_0201926C(&MAIN_BSS_0210C0B0, 4, v4);
        MI_CpuFill8(&MAIN_BSS_0210C1C0, 0, 0x60);
        MI_CpuFill8(&MAIN_BSS_0210C228, 0, 0x800);
        save->unk_0001 = save->unk_0002;
        save->unk_0004 = 0;

        RTCTime time;
        RTCDate date;
        RTC_GetTime(&time);
        RTC_GetDate(&date);
        MAIN_BSS_020B26A0.unk_8B94 = time;
        MAIN_BSS_020B26A0.unk_8B84 = date;
        return 1;
    }
    case 6:
        game->m_textboxData->sub_0200AA14();
        game->m_textboxData->sub_0200AA84(0, 0x48, 1, 1, 0);
        game->unk_14BC->sub_0200E0E0(3, 5);
        game->unk_14C0->sub_0200E0E0(3, 5);
        unk_0008 = 7;
        break;
    case 7:
        if (game->m_textboxData->sub_02009ECC()) {
            break;
        }
        game->m_textboxData->sub_02009FB0(1, 1);
        unk_0008 = 0x12;
        break;
    case 8:
        game->m_textboxData->sub_0200AA14();
        game->m_textboxData->sub_0200AA84(0, 0x50, 1, 1, 0);
        game->unk_14BC->sub_0200E0E0(3, 5);
        game->unk_14C0->sub_0200E0E0(3, 5);
        unk_0008 = 9;
        break;
    case 9:
        if (game->m_textboxData->sub_02009ECC()) {
            break;
        }
        game->m_textboxData->sub_02009FB0(1, 1);
        unk_0008 = 0x12;
        break;
    case 10:
        unk_000C->Clear(unk_0010 + 1);
        unk_0008 = 11;
        break;
    case 11:
        if (unk_000C->sub_0202841C() == 0) {
            break;
        }
        game->unk_14BC->sub_0200E0E0(3, 5);
        game->unk_14C0->sub_0200E0E0(3, 5);
        game->m_textboxData->sub_0200AA14();
        game->m_textboxData->sub_0200AA84(0, 0x73, 1, 1, 0);
        unk_0008 = 12;
        break;
    case 12:
        if (game->m_textboxData->sub_02009ECC()) {
            break;
        }
        game->m_textboxData->sub_0200AA14();
        game->m_textboxData->sub_0200AA84(0, 0x74, 1, 1, 0);
        unk_0008 = 13;
        break;
    case 13:
        if (game->m_textboxData->sub_02009ECC()) {
            break;
        }
        game->m_textboxData->sub_02009FB0(1, 1);
        unk_0008 = 0x12;
        break;
    case 14:
        game->m_textboxData->sub_0200AA14();
        game->m_textboxData->sub_0200AA84(0, 0x50, 1, 1, 0);
        game->unk_14BC->sub_0200E0E0(3, 5);
        game->unk_14C0->sub_0200E0E0(3, 5);
        unk_0008 = 15;
        break;
    case 15:
        if (game->m_textboxData->sub_02009ECC()) {
            break;
        }
        game->m_textboxData->sub_02009FB0(1, 1);
        unk_0008 = 0x12;
        break;
    case 16:
        game->m_textboxData->sub_0200AA14();
        game->m_textboxData->sub_0200AA84(0, 0x45, 1, 1, 0);
        game->unk_14BC->sub_0200E0E0(3, 5);
        game->unk_14C0->sub_0200E0E0(3, 5);
        unk_0008 = 0x11;
        break;
    case 17:
        break;
    case 18:
        game->unk_14BC->sub_0200E0E0(2, 30);
        game->unk_14C0->sub_0200E0E0(2, 30);
        unk_0008 = 0x13;
        break;
    case 19:
        if (game->unk_14BC->sub_0200E310()) {
            break;
        }
        if (game->unk_14C0->sub_0200E310()) {
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
