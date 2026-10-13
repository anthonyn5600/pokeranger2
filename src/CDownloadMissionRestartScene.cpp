#include "scene/CDownloadMissionRestartScene.hpp"

#include "UnkClass_02010D2C.hpp"
#include "UnkClass_02033F04.hpp"
#include "UnkClass_02041C80.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkClass_020B26A0.hpp"
#include "UnkStruct_02044464.hpp"
#include "scene/DownloadMission.hpp"
#include "sub_02007CF0.hpp"

extern UnkClass_02041C80 *MAIN_BSS_0210CA6C;

void CDownloadMissionRestartScene::func6()
{
    unk_0010 = MAIN_BSS_020B26A0.unk_81AC;
    unk_000C = new UnkClass_02027FE8(1);
    unk_0008 = 0;
    game->m_textboxData->sub_02009328(game->unk_0014, game->touchPanel, &game->unk_14AC->unk_0C, game->unk_14B0, game->unk_0024, game->m_audioEngine, 0x10, 0x4000, 0);
    sub_02007D68();
    game->m_textboxData->sub_0200AB28(0);
    game->unk_146C.sub_02008DB4(60);
}

void CDownloadMissionRestartScene::func7()
{
    if (unk_000C != NULL) {
        delete unk_000C;
        unk_000C = NULL;
    }
    game->m_textboxData->sub_0200AC90();
    game->m_textboxData->sub_020092D4();
}

u32 CDownloadMissionRestartScene::func0()
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
            game->sub_0201024C();
            MAIN_BSS_020B26A0.unk_8B64 = sub_02041D80(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.unk_001A)->unk_04;
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
        return 1;
    }
    case 3:
        unk_000C->Clear(unk_0010 + 1);
        unk_0008 = 4;
        break;
    case 4:
        if (unk_000C->sub_0202841C() == 0) {
            break;
        }
        game->unk_14BC->sub_0200E0E0(3, 5);
        game->unk_14C0->sub_0200E0E0(3, 5);
        game->m_textboxData->sub_0200AA14();
        game->m_textboxData->sub_0200AA84(0, 0x73, 1, 1, 0);
        unk_0008 = 5;
        break;
    case 5:
        if (game->m_textboxData->sub_02009ECC()) {
            break;
        }
        game->m_textboxData->sub_0200AA14();
        game->m_textboxData->sub_0200AA84(0, 0x74, 1, 1, 0);
        unk_0008 = 6;
        break;
    case 6:
        if (game->m_textboxData->sub_02009ECC()) {
            break;
        }
        game->m_textboxData->sub_02009FB0(1, 1);
        unk_0008 = 11;
        break;
    case 9:
        game->m_textboxData->sub_0200AA14();
        game->m_textboxData->sub_0200AA84(0, 0x50, 1, 1, 0);
        game->unk_14BC->sub_0200E0E0(3, 5);
        game->unk_14C0->sub_0200E0E0(3, 5);
        unk_0008 = 10;
        break;
    case 10:
        if (game->m_textboxData->sub_02009ECC()) {
            break;
        }
        game->m_textboxData->sub_02009FB0(1, 1);
        unk_0008 = 11;
        break;
    case 7:
        game->m_textboxData->sub_0200AA14();
        game->m_textboxData->sub_0200AA84(0, 0x45, 1, 1, 0);
        game->unk_14BC->sub_0200E0E0(3, 5);
        game->unk_14C0->sub_0200E0E0(3, 5);
        unk_0008 = 8;
        break;
    case 8:
        break;
    case 11:
        game->unk_14BC->sub_0200E0E0(2, 30);
        game->unk_14C0->sub_0200E0E0(2, 30);
        unk_0008 = 12;
        break;
    case 12:
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
