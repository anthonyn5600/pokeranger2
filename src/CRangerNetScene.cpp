#include "scene/CRangerNetScene.hpp"

#include "CGame.hpp"
#include "CPowerManage.hpp"
#include "RangerNetMenu.hpp"

CRangerNetScene::CRangerNetScene(CGame *game)
{
    m_game = game;
    Init();
}

CRangerNetScene::~CRangerNetScene()
{
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    SAFE_DELETE(unk_08);
    CPowerManage::SetMode(0);
}

void CRangerNetScene::Init()
{
    unk_08 = new RangerNetMenu(m_game, 0);
    m_game->unk_146C.SetFps(60);
    CPowerManage::SetMode(1);
}

void CRangerNetScene::func5()
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

    GX_SetBankForTex(GX_VRAM_TEX_0_B);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_0_G);
    GX_SetBankForOBJ(GX_VRAM_OBJ_80_EF);
    GX_SetBankForBG(GX_VRAM_BG_128_A);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
    GXS_SetGraphicsMode(GX_BGMODE_0);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_DisableBankForSubBG();
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_128_D);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_48_HI);

    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);
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

void CRangerNetScene::func6()
{
    m_game->InitVramManagers(0x20000, 0, 0x4000);
    if (unk_08 != NULL) {
        unk_08->Setup();
    }
}

void CRangerNetScene::func7()
{
    m_game->InitVramManagers(0x80000, 0, 0x4000);
}

u32 CRangerNetScene::func0()
{
    if (unk_08 != NULL) {
        unk_08->Update();
        int result = unk_08->GetNextScene();
        if (result != -1) {
            switch (result) {
            case 0:
                return 0xE;
            default:
            case 1:
                return 0x1C;
            case 2:
                return 0x21;
            }
        }
    }
    return -1;
}

void CRangerNetScene::func1()
{
    if (unk_08 != NULL) {
        unk_08->Draw();
    }
}

void CRangerNetScene::func2()
{
    if (unk_08 != NULL) {
        unk_08->ov11_0211E438();
    }
}

u32 CRangerNetScene::getSceneId()
{
    return 8;
}
