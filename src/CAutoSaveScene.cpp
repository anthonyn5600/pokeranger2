#include "scene/CAutoSaveScene.hpp"

#include "CGame.hpp"
#include "sub_02007CF0.hpp"

extern UnkClass_020B26A0 MAIN_BSS_020B26A0;

CAutoSaveScene::CAutoSaveScene()
{
    unk_0004 = 0;
    unk_0008 = 0;
}

CAutoSaveScene::~CAutoSaveScene()
{
}

u32 CAutoSaveScene::func0()
{
    switch (unk_0008) {
    case 0: {
        if (s_game->unk_14BC->sub_0200E310()) {
            break;
        }
        if (s_game->unk_14C0->sub_0200E310()) {
            break;
        }

        s_game->m_audioEngine->sub_020349E8(0x45);
        s_game->m_audioEngine->sub_02034DE8(0x42, 0, 0x100);

        RTCTime time;
        RTCDate date;
        RTC_GetTime(&time);
        RTC_GetDate(&date);
        MAIN_BSS_020B26A0.sub_0201630C(&time, &date);
        s_game->sub_02010400();

        unk_000C = new UnkClass_02027FE8(1);
        unk_000C->sub_02028220(0);

        s_game->m_textboxData->sub_0200AA14();
        s_game->m_textboxData->sub_0200AA84(0, 0x1E, 1, 1, 0);
        unk_0008 = 1;
        break;
    }
    case 1: {
        u32 result = unk_000C->sub_0202841C();
        if (result == 0) {
            break;
        }
        if (!(result & 0x80)) {
            s_game->m_textboxData->sub_0200AA14();
            s_game->m_textboxData->sub_0200AA84(0, 0x21, 1, 1, 0);
            unk_0008 = 3;
        } else {
            s_game->m_textboxData->sub_0200AA14();
            s_game->m_textboxData->sub_0200AA84(0, 0x56, 1, 1, 0);
            unk_0008 = 2;
        }
        s_game->m_audioEngine->sub_02034E38(0);
        break;
    }
    case 2:
        break;
    case 3:
        if (s_game->m_textboxData->sub_02009ECC()) {
            break;
        }
        s_game->m_textboxData->sub_02009FB0(1, 1);
        s_game->unk_14BC->sub_0200E0E0(2, 30);
        s_game->unk_14C0->sub_0200E0E0(2, 30);
        unk_0008 = 4;
        break;
    case 4:
        if (s_game->unk_14BC->sub_0200E310()) {
            break;
        }
        if (s_game->unk_14C0->sub_0200E310()) {
            break;
        }
        return 0x11;
    }

    return -1;
}

void CAutoSaveScene::func1()
{
    UnkClass_020023EC *printer = s_game->unk_0C24;
    printer->unk_24 = 0;
    printer->sub_020028A4(10, 10, "Auto Save");
}

void CAutoSaveScene::func2()
{
}

void CAutoSaveScene::func5()
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
    GX_SetVisiblePlane(0);
    GXS_SetVisiblePlane(0);
    GX_DispOn();
    GXS_DispOn();
}

void CAutoSaveScene::func6()
{
    unk_0004 = 0;
    unk_0008 = 0;
    s_game->m_textboxData->sub_02009328(s_game->unk_0014, s_game->touchPanel, &s_game->unk_14AC->unk_0C, s_game->unk_14B0, s_game->unk_0024, s_game->m_audioEngine, 0x10, 0x4000, 0);
    sub_02007D68();
    s_game->m_textboxData->sub_0200AB28(0);
    s_game->unk_14BC->sub_0200E0E0(3, 10);
    s_game->unk_14C0->sub_0200E0E0(3, 10);
    s_game->unk_146C.sub_02008DB4(60);
}

void CAutoSaveScene::func7()
{
    if (unk_000C != NULL) {
        delete unk_000C;
        unk_000C = NULL;
    }
    s_game->m_textboxData->sub_0200AC90();
    s_game->m_textboxData->sub_020092D4();
}

u32 CAutoSaveScene::getSceneId()
{
    return 0x15;
}
