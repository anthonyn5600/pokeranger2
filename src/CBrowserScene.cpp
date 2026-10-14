#include "scene/CBrowserScene.hpp"

#include "CGame.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_0211D330.hpp"
#include "sub_02007CF0.hpp"

static int sScrollX;

static void ov21_0211C9E0()
{
    int line = GX_GetVCount();
    if (line >= 0x9C && line <= 0xA3) {
        G2_SetBG1Offset(0, 0);
    }
    if (line >= 0xC8 && line <= 0xDC) {
        G2_SetBG1Offset(sScrollX, 0);
    }
    OS_SetIrqCheckFlag(OS_IE_H_BLANK);
}

CBrowserScene::CBrowserScene()
{
    unk_000C = 0;
    unk_0010 = 0;
    unk_0008 = NULL;
    unk_001C = OS_GetIrqFunction(OS_IE_H_BLANK);
    OS_SetIrqFunction(OS_IE_H_BLANK, ov21_0211C9E0);
    OS_EnableIrqMask(OS_IE_H_BLANK);
    GX_HBlankIntr(TRUE);
}

CBrowserScene::~CBrowserScene()
{
}

void CBrowserScene::func5()
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

    GX_SetBankForLCDC(GX_VRAM_LCDC_ALL);
    MI_CpuClearFast((void *)HW_LCDC_VRAM, HW_LCDC_VRAM_SIZE);
    GX_DisableBankForLCDC();

    GX_SetBankForTex(GX_VRAM_TEX_NONE);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_NONE);
    GX_SetBankForBG(GX_VRAM_BG_256_AB);
    GX_SetBankForOBJ(GX_VRAM_OBJ_96_EFG);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);

    G2S_SetBG0Priority(3);
    G2S_SetBG1Priority(2);
    G2S_SetBG2Priority(1);
    G2S_SetBG3Priority(0);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_64K);
    GXS_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_SetBGScrOffset(GX_BGSCROFFSET_0x00000);
    GX_SetBGCharOffset(GX_BGCHAROFFSET_0x00000);
    GX_SetVisiblePlane(GX_PLANEMASK_NONE);
    GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
    GX_DispOn();
    GXS_DispOn();
}

void CBrowserScene::func6()
{
    unk_0014 = GX_GetVisibleWnd();
    unk_0018 = G2_GetWnd0InsidePlane();
    unk_0019 = G2_GetWndOutsidePlane();
    sScrollX = 0;
    unk_000C = 0;
    unk_0010 = 0;
    s_game->unk_146C.sub_02008DB4(60);
    unk_0008 = new UnkClass_0211D330(s_game);
    s_game->unk_14BC->sub_0200E0E0(3, 30);
    s_game->unk_14C0->sub_0200E0E0(3, 30);
}

void CBrowserScene::func7()
{
    SAFE_DELETE(unk_0008);
    s_game->unk_146C.sub_02008DB4(30);
    G2_SetWnd0InsidePlane(unk_0018.planeMask, unk_0018.effect);
    G2_SetWndOutsidePlane(unk_0019.planeMask, unk_0019.effect);
    GX_SetVisibleWnd(unk_0014);
    OS_SetIrqFunction(OS_IE_H_BLANK, unk_001C);
    OS_EnableIrqMask(OS_IE_H_BLANK);
    GX_HBlankIntr(TRUE);
}

u32 CBrowserScene::func0()
{
    unk_0008->ov21_0212004C();
    Point2D slide = unk_0008->unk_078;
    sScrollX = slide.x >> 12;
    switch (unk_0010) {
    case 0:
        if (!s_game->unk_14BC->sub_0200E310() && !s_game->unk_14C0->sub_0200E310()) {
            unk_0010 = 1;
            unk_000C = 0;
        }
        break;
    case 1:
        if (unk_0008->unk_034 == 3) {
            unk_0010 = 2;
            s_game->unk_14BC->sub_0200E0E0(4, 20);
            s_game->unk_14C0->sub_0200E0E0(4, 20);
        }
        break;
    case 2:
        if (!s_game->unk_14BC->sub_0200E310() && !s_game->unk_14C0->sub_0200E310()) {
            return 6;
        }
        break;
    }
    return -1;
}

void CBrowserScene::func1()
{
    unk_0008->ov21_021203A8();
}

void CBrowserScene::func2()
{
    unk_0008->ov21_02120490();
}

void CBrowserScene::func3()
{
    sub_02007D98();
    if (unk_0008 != NULL) {
        unk_0008->ov21_021204B0();
    }
}

u32 CBrowserScene::getSceneId()
{
    return 0x16;
}
