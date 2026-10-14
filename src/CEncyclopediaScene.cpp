#include "scene/CEncyclopediaScene.hpp"

#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "DisplayUtil.hpp"
#include "OamSpriteSet.hpp"
#include "SubTextPrinter.hpp"
#include "TextPrinter.hpp"

CEncyclopediaScene::CEncyclopediaScene()
    : unk_008(0)
    , unk_028(NULL)
    , unk_3A4(NULL)
{
    unk_014 = new CEncycItemListScreen(&unk_02C);
    unk_018 = new CEncycItemDescriptionScreen(&unk_02C);
    unk_00C[0] = unk_014;
    unk_00C[1] = unk_018;
}

CEncyclopediaScene::~CEncyclopediaScene()
{
    SAFE_DELETE(unk_3A4);
    for (int i = 0; i < 2; i++) {
        SAFE_DELETE(unk_00C[i]);
    }
    CGame::GetInstance()->unk_146C.SetFps(30);
}

u32 CEncyclopediaScene::func0()
{
    int ret = -1;
    CEncycMenuScreen *screen = unk_00C[unk_008];
    if (screen != NULL) {
        int next = screen->func4();
        if (next < 0) {
            ret = 6;
        } else if (next != unk_008) {
            unk_008 = next;
            if (unk_00C[next] != NULL) {
                CGame *game = CGame::GetInstance();
                if (next == 1) {
                    if (unk_3A4 != NULL) {
                        unk_3A4->unk_18 = unk_014->ov22_0211DE9C();
                    }
                    unk_018->ov22_0211E66C(unk_014->unk_18);
                }
                unk_00C[unk_008]->func2();
                unk_00C[unk_008]->func3(&unk_04C);
                game->unk_14BC->Start(3, 15);
                game->unk_14C0->Start(3, 15);
            }
        }
    }
    return ret;
}

void CEncyclopediaScene::func1()
{
    CEncycMenuScreen *screen = unk_00C[unk_008];
    if (screen != NULL) {
        screen->func5();
    }
    unk_028->WriteOam();
}

void CEncyclopediaScene::func2()
{
}

void CEncyclopediaScene::func5()
{
    unk_3A8 = GXS_GetVisibleWnd();
    unk_3AC = G2S_GetWnd0InsidePlane();
    unk_3AD = G2S_GetWndOutsidePlane();

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

    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);
    GXS_SetGraphicsMode(GX_BGMODE_0);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
    GXS_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2S_SetWnd0Position(0, 48, 255, 176);
    G2S_SetWnd0InsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ,
        FALSE);
    G2S_SetWndOutsidePlane(GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_OBJ, FALSE);
    unk_04C.ov22_0211F594();
    G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);

    unk_008 = 0;
    CEncycMenuScreen *screen = unk_00C[unk_008];
    if (screen != NULL) {
        screen->func2();
    }
    GX_DispOn();
    GXS_DispOn();
    CGame::GetInstance()->unk_146C.SetFps(60);
}

void CEncyclopediaScene::func6()
{
    ov22_0211D1A4();
    ov22_0211D294();
    ov22_0211D200();
    for (int i = 0; i < 2; i++) {
        unk_00C[i]->func0(&unk_01C);
    }
    SAFE_DELETE(unk_3A4);
    unk_3A4 = new EncycDictionary();
    if (unk_3A4 != NULL) {
        unk_3A4->Load("/data/message/etc/dictionary01_mes", "/data/message/etc/dictionary03_mes");
    }
    unk_018->unk_64 = unk_3A4;
    unk_00C[unk_008]->func3(&unk_04C);
    CGame *game = CGame::GetInstance();
    game->unk_14BC->Start(3, 15);
    game->unk_14C0->Start(3, 15);
}

void CEncyclopediaScene::func7()
{
    SAFE_DELETE(unk_3A4);
    for (int i = 0; i < 2; i++) {
        CEncycMenuScreen *screen = unk_00C[i];
        if (screen != NULL) {
            screen->func1();
        }
    }
    SAFE_DELETE(unk_028);
    CGame::GetInstance()->unk_1494->FreeWindows();
    G2S_SetWnd0InsidePlane(unk_3AC.planeMask, unk_3AC.effect);
    G2S_SetWndOutsidePlane(unk_3AD.planeMask, unk_3AD.effect);
    GXS_SetVisibleWnd(unk_3A8);
}

void CEncyclopediaScene::ov22_0211D1A4()
{
    CGame::GetInstance()->unk_1498->SetupBG();
    G2S_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x3000, GX_BG_CHARBASE_0x0c000, GX_BG_EXTPLTT_01);
    MI_CpuClearFast(G2S_GetBG0CharPtr(), 0x20);
    MI_CpuClearFast(G2S_GetBG0ScrPtr(), 0x800);
}

void CEncyclopediaScene::ov22_0211D200()
{
    unk_028 = unk_01C.ov22_0211F3F0("data/menu", "ma005_00", 1, 0);
    unk_02C.ov22_0211F134(0, unk_028, 0, 0, 240, 16, 24, 24, 0);
    unk_02C.SetListener(this);
    unk_01C.ov22_0211F4A4(unk_028, 0);
}

void CEncyclopediaScene::ov22_0211D294()
{
    unk_04C.ov22_0211F72C();
}

void CEncyclopediaScene::func3()
{
    CEncycMenuScreen *screen = unk_00C[unk_008];
    if (screen != NULL) {
        screen->func7();
    }
    LoadOam();
}

void CEncyclopediaScene::OnPushButton(int id)
{
    if (id != 0) {
        return;
    }
    CEncycMenuScreen *screen = unk_00C[unk_008];
    if (screen == NULL) {
        return;
    }
    screen->func6();
}

u32 CEncyclopediaScene::getSceneId()
{
    return 23;
}
