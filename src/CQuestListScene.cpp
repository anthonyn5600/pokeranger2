#include "scene/CQuestListScene.hpp"

#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "DisplayUtil.hpp"

CQuestListScene::CQuestListScene()
    : unk_004(0)
    , unk_010(&unk_384)
{
    unk_008[0] = &unk_010;
    unk_008[1] = &unk_374;
}

CQuestListScene::~CQuestListScene()
{
    CGame::GetInstance()->unk_146C.SetFps(30);
}

u32 CQuestListScene::func0()
{
    int ret = -1;
    CQuestListScreenBase *screen = unk_008[unk_004];
    if (screen != NULL) {
        int next = screen->func4();
        if (next < 0) {
            ret = 6;
        } else {
            int prev = unk_004;
            if (next != prev) {
                unk_004 = next;
                if (unk_008[next] != NULL) {
                    if (next == 1) {
                        unk_374.unk_0C = unk_010.GetSelectedQuestId();
                    }
                    CGame *game = CGame::GetInstance();
                    unk_008[unk_004]->func2();
                    unk_008[unk_004]->func3(prev);
                }
            }
        }
    }
    unk_384.Update();
    return ret;
}

void CQuestListScene::func1()
{
    CQuestListScreenBase *screen = unk_008[unk_004];
    if (screen != NULL) {
        screen->func5();
    }
    unk_384.Render();
}

void CQuestListScene::func2()
{
    CQuestListScreenBase *screen = unk_008[unk_004];
    if (screen != NULL) {
        screen->func6();
    }
    unk_384.OnVBlank();
}

void CQuestListScene::func5()
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
    GX_SetBankForBG(GX_VRAM_BG_128_A);
    GX_SetBankForOBJ(GX_VRAM_OBJ_80_EF);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_3D);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);
    GXS_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);
    GX_SetVisiblePlane(GX_PLANEMASK_NONE);
    GXS_SetVisiblePlane(GX_PLANEMASK_NONE);
    unk_010.SaveSubDisplay();
    GX_DispOn();
    GXS_DispOn();
    CGame::GetInstance()->unk_146C.SetFps(60);
}

void CQuestListScene::func6()
{
    CGame *game = CGame::GetInstance();
    game->InitVramManagers(0x20000, 0, 0x4000);
    for (int i = 0; i < 2; i++) {
        CQuestListScreenBase *screen = unk_008[i];
        if (screen != NULL) {
            screen->func0();
        }
    }
    unk_008[unk_004]->func2();
    unk_008[unk_004]->func3(-1);
    unk_384.Setup(unk_010.unk_338 == 0 ? TRUE : FALSE);
    game->m_mainFade->Start(3, 30);
}

void CQuestListScene::func7()
{
    for (int i = 0; i < 2; i++) {
        CQuestListScreenBase *screen = unk_008[i];
        if (screen != NULL) {
            screen->func1();
        }
    }
    unk_010.RestoreSubDisplay();
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    CGame::GetInstance()->InitVramManagers(0x80000, 0, 0x4000);
}

void CQuestListScene::func3()
{
    CQuestListScreenBase *screen = unk_008[unk_004];
    if (screen != NULL) {
        screen->func7();
    }
    LoadOam();
}

u32 CQuestListScene::getSceneId()
{
    return 31;
}
