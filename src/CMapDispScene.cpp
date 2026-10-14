#include "scene/CMapDispScene.hpp"

CMapDispScene::CMapDispScene(CGame *game)
{
    m_game = game;
    ov28_0211CAAC();
}

CMapDispScene::~CMapDispScene()
{
    SAFE_DELETE(unk_08);
}

void CMapDispScene::ov28_0211CAAC()
{
    unk_08 = new CMapDispScreen(m_game);
}

u32 CMapDispScene::func0()
{
    if (unk_08 != NULL) {
        unk_08->ov28_0211D218();
        if (unk_08->ov28_0211DAB0() != -1) {
            return 6;
        }
    }
    return -1;
}

void CMapDispScene::func1()
{
    if (unk_08 != NULL) {
        unk_08->ov28_0211D2DC();
    }
}

void CMapDispScene::func2()
{
    if (unk_08 != NULL) {
        unk_08->ov28_0211D344();
    }
}

void CMapDispScene::func5()
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
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_128_D);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_SetVisiblePlane(GX_PLANEMASK_BG3);
    GX_SetBGScrOffset(GX_BGSCROFFSET_0x00000);
    GX_SetBGCharOffset(GX_BGCHAROFFSET_0x00000);
    GX_DispOn();
    GXS_DispOn();
}

void CMapDispScene::func6()
{
    if (unk_08 != NULL) {
        unk_08->ov28_0211D700();
        unk_08->ov28_0211D9E0();
    }
}

void CMapDispScene::func7()
{
}

u32 CMapDispScene::getSceneId()
{
    return 0x20;
}
