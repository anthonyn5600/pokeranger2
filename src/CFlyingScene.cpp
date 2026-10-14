#include "scene/CFlyingScene.hpp"

CFlyingScene::CFlyingScene(CGame *game)
{
    m_game = game;
    ov9_0211CAAC();
}

CFlyingScene::~CFlyingScene()
{
    SAFE_DELETE(unk_08);
}

void CFlyingScene::ov9_0211CAAC()
{
    unk_08 = new FlyingMap(m_game);
}

void CFlyingScene::func5()
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

    GX_SetBankForTex(GX_VRAM_TEX_NONE);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_NONE);
    GX_SetBankForOBJ(GX_VRAM_OBJ_128_B);
    GX_SetBankForBG(GX_VRAM_BG_128_A);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
    GX_SetBankForBGExtPltt(GX_VRAM_BGEXTPLTT_0123_E);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_128_D);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetBGScrOffset(GX_BGSCROFFSET_0x00000);
    GX_SetBGCharOffset(GX_BGCHAROFFSET_0x00000);
    GX_SetVisiblePlane(GX_PLANEMASK_NONE);
    GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
    GX_DispOn();
    GXS_DispOn();
}

void CFlyingScene::func6()
{
    if (unk_08 != NULL) {
        unk_08->ov9_0211D484();
        unk_08->ov9_0211D9F0();
    }
}

void CFlyingScene::func7()
{
}

u32 CFlyingScene::func0()
{
    if (unk_08 != NULL) {
        unk_08->ov9_0211CD40();
        if (unk_08->ov9_0211DAC0() != -1) {
            return 1;
        }
    }
    return -1;
}

void CFlyingScene::func1()
{
    if (unk_08 != NULL) {
        unk_08->ov9_0211CE80();
    }
}

void CFlyingScene::func2()
{
    if (unk_08 != NULL) {
        unk_08->ov9_0211CEF0();
    }
}

u32 CFlyingScene::getSceneId()
{
    return 0xB;
}
