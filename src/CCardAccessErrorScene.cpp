#include "scene/CCardAccessErrorScene.hpp"

#include "CGame.hpp"

u32 CCardAccessErrorScene::func0()
{
    return -1;
}

void CCardAccessErrorScene::func1()
{
}

void CCardAccessErrorScene::func5()
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

    GX_SetBankForBG(GX_VRAM_BG_256_AB);
    GX_SetBankForOBJ(GX_VRAM_OBJ_NONE);
    GX_SetBankForTex(GX_VRAM_TEX_NONE);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_NONE);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_DisableBankForSubBG();
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_48_HI);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_NONE);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_SetVisiblePlane(GX_PLANEMASK_NONE);
    GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
    GX_DispOn();
    GXS_DispOn();

    G2_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x0000, GX_BG_CHARBASE_0x08000, GX_BG_EXTPLTT_01);
    G2_SetBG0Offset(0, 0);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
}

void CCardAccessErrorScene::func6()
{
    s_game->unk_146C.sub_02008DB4(60);
    s_game->m_textboxData->sub_02009328(s_game->unk_0014, s_game->touchPanel, &s_game->unk_14AC->unk_0C, s_game->unk_14B0, s_game->unk_0024, s_game->m_audioEngine, 0x10, 0x4000, 0);
    s_game->m_textboxData->sub_0200AB28(0);
    s_game->m_audioEngine->sub_020345D4();
    s_game->unk_14BC->sub_0200E0E0(3, 0);
    s_game->m_textboxData->sub_0200AA84(0, 0x45, 1, 1, 0);
}

void CCardAccessErrorScene::func7()
{
    s_game->unk_146C.sub_02008DB4(30);
    s_game->m_textboxData->sub_0200AC90();
    s_game->m_textboxData->sub_020092D4();
}
