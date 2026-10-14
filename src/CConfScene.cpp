#include "scene/CConfScene.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "AudioEngine.hpp"
#include "BGLayer.hpp"
#include "CGame.hpp"
#include "CTouchPanel.hpp"
#include "Collision.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "PadInput.hpp"
#include "SubTextPrinter.hpp"
#include "TextboxManager.hpp"
#include "common.hpp"
#include "file/CBinaryFileMes.hpp"
#include "primitive/CPrimitiveSPHERE.hpp"

static inline SubTextPrinter *GetPrinter(CGame *game)
{
    return game->unk_1498;
}

struct TextWindow {
    int width;
    int height;
    int left;
    int top;
    int x;
    int y;
    int color;
};

CConfScene::CConfScene(CGame *game)
{
    m_game = game;
    m_audioEngine = CGame::GetInstance()->m_audioEngine;
    m_audioEngine->sub_020345D4();
    unk_18 = FX32_ONE;
    unk_0E = 0;
}

CConfScene::~CConfScene()
{
}

void CConfScene::func5()
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
    G2_SetBG0Priority(3);
    G2_SetBG1Priority(2);
    G2_SetBG2Priority(1);
    G2_SetBG3Priority(0);

    GX_SetBankForSubBG(GX_VRAM_SUB_BG_32_H);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);
    G2S_SetBG0Priority(3);
    G2S_SetBG1Priority(2);
    G2S_SetBG2Priority(1);
    G2S_SetBG3Priority(0);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);
    GX_SetVisiblePlane(GX_PLANEMASK_NONE);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG1);
    GX_DispOn();
    GXS_DispOn();
}

void CConfScene::ov3_02121674()
{
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
    G2S_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x00000, GX_BG_EXTPLTT_01);
}

void CConfScene::ov3_021216A8()
{
    TextWindow win = { 24, 4, 4, 19, 0, 4, 6 };
    SubTextPrinter *printer = GetPrinter(m_game);
    printer->FreeWindows();
    printer->SetupBG();
    printer->AllocWindows(1);
    printer->InitWindow(0, win.width, win.height, win.left, win.top, 0x20, 0, 2);
    printer->Print(0, win.x, win.y, win.color, unk_2C->unk_08[38].unk_04, FALSE, 0);
}

void CConfScene::func6()
{
    ov3_02121674();
    unk_1C = new BGLayer((int)m_game);
    unk_1C->SetBG(5);
    unk_1C->LoadArchive("menu/", "title004_bg_");
    unk_1C->LoadChar("title004", 0, 0, 0);
    unk_1C->LoadPltt("title004", 0, 0, 0);
    unk_1C->LoadScr("title004_00", 0, 0, 0, 0, 0);
    unk_1C->ReleaseArchive();
    unk_1C->Setup(0x100, 0x100);
    unk_1C->LoadToVram();

    u32 pos;
    {
        CBinaryFileMes *file = new CBinaryFileMes("data/message/etc/menu_mes", 1);
        unk_2C = new UnkClass_020091E8_004();
        pos = 2;
        unk_2C->unk_00 = ((u32 *)file->unk_4C)[0];
        unk_2C->unk_04 = ((u32 *)file->unk_4C)[1];
        unk_2C->unk_08 = new UnkClass_020091E8_004_08[unk_2C->unk_04];
        for (u32 i = 0; i < unk_2C->unk_04; ++i) {
            unk_2C->unk_08[i].unk_00 = ((u32 *)file->unk_4C)[pos];
            ++pos;
            unk_2C->unk_08[i].unk_04 = new u8[unk_2C->unk_08[i].unk_00];
            MI_CpuCopyFast(&((u32 *)file->unk_4C)[pos], unk_2C->unk_08[i].unk_04, unk_2C->unk_08[i].unk_00);
            pos += unk_2C->unk_08[i].unk_00 / 4;
        }
        delete file;
    }

    ov3_021216A8();
    ov3_021219BC();
    ov3_02121A28();

    unk_30 = new CPrimitiveSPHERE();
    unk_30->m_circle.r = 0x20000;
    Point2D *p = &unk_30->m_circle.pos;
    p->x = -0x40000;
    p->y = -0x20000;
    unk_34 = new CPrimitiveSPHERE();
    unk_34->m_circle.r = 0x20000;
    p = &unk_34->m_circle.pos;
    p->x = 0x40000;
    p->y = -0x20000;
}

void CConfScene::ov3_021219BC()
{
    unk_28 = new OamSpriteSet((GXOamAttr *)&m_game->unk_0424[0x18], m_game->unk_14A8, TRUE, 0x40);
    unk_28->Load("data/menu", "title003_00", 0, 0);
}

void CConfScene::ov3_02121A28()
{
    unk_20 = unk_28->AddSprite(0, 0x40, 0x60, 0);
    unk_10 = unk_28->unk_24;
    unk_24 = unk_28->AddSprite(1, 0xC0, 0x60, 0);
    unk_14 = unk_28->unk_24;
}

void CConfScene::func7()
{
    SAFE_DELETE(unk_1C);
    SAFE_DELETE(unk_28);
    SAFE_DELETE(unk_2C);
    SAFE_DELETE(unk_30);
    SAFE_DELETE(unk_34);
}

void CConfScene::ov3_02121B4C(int scale)
{
    MtxFx22 mtx;
    mtx._00 = scale;
    mtx._01 = 0;
    mtx._10 = 0;
    mtx._11 = scale;
    G2_SetOBJAffine((GXOamAffine *)&m_game->unk_0424[4], &mtx);
}

u32 CConfScene::func0()
{
    int ret = -1;
    ov3_02121B4C(unk_18);
    unk_28->Update();

    if ((u16)(m_game->unk_0014->unk_0002 & PAD_BUTTON_A)) {
        ret = 34;
    }
    CTouchPanel *tp = m_game->touchPanel;
    Point2D touch;
    touch.x = (tp->unk_0A.x - 0x80) << FX32_SHIFT;
    touch.y = (tp->unk_0A.y - 0x80) << FX32_SHIFT;
    if (m_flags & 3) {
        unk_0E++;
        if (unk_0E >= 0x10) {
            if (m_flags & 2) {
                ret = 14;
            }
            unk_0E = 0;
        }
        if (unk_0E == 2) {
            unk_18 = FX32_ONE;
        }
    } else if (tp->unk_04 != 0) {
        if (PointInCircle(touch, unk_30->m_circle)) {
            unk_18 = 0x1400;
            unk_20->SetAffine(1, FALSE);
            unk_24->unk_14 = 0;
            m_flags |= 1;
            m_audioEngine->PlaySe(0xFF);
        }
        if (PointInCircle(touch, unk_34->m_circle)) {
            unk_18 = 0x1400;
            unk_24->SetAffine(1, FALSE);
            unk_20->unk_14 = 0;
            m_flags |= 2;
            m_audioEngine->PlaySe(0x100);
        }
    }
    return ret;
}

void CConfScene::func1()
{
}

void CConfScene::func2()
{
    unk_28->WriteOam();
}

u32 CConfScene::getSceneId()
{
    return 15;
}
