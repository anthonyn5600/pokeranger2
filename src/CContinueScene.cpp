#include "scene/CContinueScene.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "AudioEngine.hpp"
#include "BGLayer.hpp"
#include "CGame.hpp"
#include "CTouchPanel.hpp"
#include "Collision.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
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

CContinueScene::CContinueScene(CGame *game)
{
    m_game = game;
    m_audioEngine = CGame::GetInstance()->m_audioEngine;
    m_audioEngine->sub_020345D4();
    unk_1C = FX32_ONE;
    unk_10 = 0;
}

CContinueScene::~CContinueScene()
{
}

void CContinueScene::func5()
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

void CContinueScene::ov3_02120CF4()
{
    TextWindow win = { 24, 4, 4, 19, 0, 4, 6 };
    SubTextPrinter *printer = GetPrinter(m_game);
    printer->FreeWindows();
    printer->SetupBG();
    printer->AllocWindows(1);
    printer->InitWindow(0, win.width, win.height, win.left, win.top, 0x20, 0, 2);
    ov3_02120D90(unk_0E);
}

void CContinueScene::ov3_02120D90(int sel)
{
    TextWindow win = { 24, 4, 4, 19, 0, 4, 6 };
    SubTextPrinter *printer = GetPrinter(m_game);
    printer->ClearWindow(0);
    if (sel == 0) {
        printer->Print(0, win.x, win.y, win.color, unk_30->unk_08[39].unk_04, FALSE, 0);
    }
    if (sel == 1) {
        printer->Print(0, win.x, win.y, win.color, unk_30->unk_08[47].unk_04, FALSE, 0);
    }
}

void CContinueScene::func6()
{
    unk_20 = new BGLayer((int)m_game);
    unk_20->SetBG(5);
    unk_20->LoadArchive("menu/", "title004_bg_");
    unk_20->LoadChar("title004", 0, 0, 0);
    unk_20->LoadPltt("title004", 0, 0, 0);
    unk_20->LoadScr("title004_00", 0, 0, 0, 0, 0);
    unk_20->ReleaseArchive();
    unk_20->Setup(0x100, 0x100);
    unk_20->LoadToVram();

    u32 pos;
    {
        CBinaryFileMes *file = new CBinaryFileMes("data/message/etc/menu_mes", 1);
        unk_30 = new UnkClass_020091E8_004();
        pos = 2;
        unk_30->unk_00 = ((u32 *)file->unk_4C)[0];
        unk_30->unk_04 = ((u32 *)file->unk_4C)[1];
        unk_30->unk_08 = new UnkClass_020091E8_004_08[unk_30->unk_04];
        for (u32 i = 0; i < unk_30->unk_04; ++i) {
            unk_30->unk_08[i].unk_00 = ((u32 *)file->unk_4C)[pos];
            ++pos;
            unk_30->unk_08[i].unk_04 = new u8[unk_30->unk_08[i].unk_00];
            MI_CpuCopyFast(&((u32 *)file->unk_4C)[pos], unk_30->unk_08[i].unk_04, unk_30->unk_08[i].unk_00);
            pos += unk_30->unk_08[i].unk_00 / 4;
        }
        delete file;
    }

    ov3_02120CF4();
    ov3_021210A4();
    ov3_02121110();

    unk_34 = new CPrimitiveSPHERE();
    unk_34->m_circle.r = 0x20000;
    Point2D *p = &unk_34->m_circle.pos;
    p->x = -0x40000;
    p->y = -0x20000;
    unk_38 = new CPrimitiveSPHERE();
    unk_38->m_circle.r = 0x20000;
    p = &unk_38->m_circle.pos;
    p->x = 0x40000;
    p->y = -0x20000;
}

void CContinueScene::ov3_021210A4()
{
    unk_2C = new OamSpriteSet((GXOamAttr *)&m_game->unk_0424[0x18], m_game->unk_14A8, TRUE, 0x40);
    unk_2C->Load("data/menu", "title003_00", 0, 0);
}

void CContinueScene::ov3_02121110()
{
    unk_24 = unk_2C->AddSprite(0, 0x40, 0x60, 0);
    unk_14 = unk_2C->unk_24;
    unk_28 = unk_2C->AddSprite(1, 0xC0, 0x60, 0);
    unk_18 = unk_2C->unk_24;
}

void CContinueScene::func7()
{
    SAFE_DELETE(unk_20);
    SAFE_DELETE(unk_2C);
    SAFE_DELETE(unk_30);
    SAFE_DELETE(unk_34);
    SAFE_DELETE(unk_38);
}

void CContinueScene::ov3_02121234(int scale)
{
    MtxFx22 mtx;
    mtx._00 = scale;
    mtx._01 = 0;
    mtx._10 = 0;
    mtx._11 = scale;
    G2_SetOBJAffine((GXOamAffine *)&m_game->unk_0424[4], &mtx);
}

u32 CContinueScene::func0()
{
    ov3_02121234(unk_1C);
    unk_2C->Update();

    CTouchPanel *tp = m_game->touchPanel;
    Point2D touch;
    touch.x = (tp->unk_0A.x - 0x80) << FX32_SHIFT;
    touch.y = (tp->unk_0A.y - 0x80) << FX32_SHIFT;
    if (m_flags & 3) {
        unk_10++;
        if (unk_10 >= 0x10) {
            if (m_flags & 2) {
                if (unk_0E == 0) {
                    unk_0E = 1;
                } else if (unk_0E == 1) {
                    unk_0E = 0;
                }
                ov3_02120D90(unk_0E);
                unk_24->unk_14 = 1;
                unk_28->unk_14 = 1;
                m_flags &= ~1;
                m_flags &= ~2;
            }
            unk_10 = 0;
        }
        if (unk_10 == 2) {
            unk_1C = FX32_ONE;
        }
    } else if (tp->unk_04 != 0) {
        if (PointInCircle(touch, unk_34->m_circle)) {
            unk_1C = 0x1400;
            unk_24->SetAffine(1, FALSE);
            unk_28->unk_14 = 0;
            m_flags |= 1;
            m_audioEngine->PlaySe(0xFF);
        }
        if (PointInCircle(touch, unk_38->m_circle)) {
            unk_1C = 0x1400;
            unk_28->SetAffine(1, FALSE);
            unk_24->unk_14 = 0;
            m_flags |= 2;
            m_audioEngine->PlaySe(0x100);
        }
    }
    return -1;
}

void CContinueScene::func1()
{
}

void CContinueScene::func2()
{
    unk_2C->WriteOam();
}

u32 CContinueScene::getSceneId()
{
    return 15;
}
