#include "scene/CStaffrollScene.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "AudioEngine.hpp"
#include "BGLayer.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "DisplayUtil.hpp"
#include "FontSet.hpp"
#include "FrameTimer.hpp"
#include "GlobalValues.hpp"
#include "MessageTable.hpp"
#include "MissionQuestData.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "PadInput.hpp"
#include "SaveData.hpp"
#include "TextboxManager.hpp"
#include "common.hpp"
#include "file/CNCLRFile.hpp"
#include "heap.hpp"

struct UnkStruct_0208AC1C {
    char name[0x10];
    u32 mapId;
    int x;
    int y;
};

extern UnkStruct_0208AC1C s_c000First_0208ac1c[];
extern SaveData MAIN_BSS_020B26A0;

struct StaffrollEvent {
    u16 frame;
    u8 type;
    s8 picture;
    int arg0;
    int arg1;
    int unused;
};

static int sPicturesA[16] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
static int sPicturesB[16] = { 0, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30 };
static int *sPictures[2] = { sPicturesA, sPicturesB };

static StaffrollEvent sEvents[20] = {
    { 60, 2, 0, 3079, 0, 0 },
    { 120, 0, 1, 0, 60, 0 },
    { 540, 0, 2, 6, 60, 0 },
    { 960, 0, 3, 6, 60, 0 },
    { 1380, 0, 4, 6, 60, 0 },
    { 1800, 0, 5, 6, 60, 0 },
    { 2220, 0, 6, 6, 60, 0 },
    { 2700, 0, 7, 6, 60, 0 },
    { 3180, 0, 8, 6, 60, 0 },
    { 3660, 0, 9, 6, 60, 0 },
    { 4140, 0, 10, 6, 60, 0 },
    { 4620, 0, 11, 6, 60, 0 },
    { 5100, 0, 12, 6, 60, 0 },
    { 5580, 0, 13, 6, 60, 0 },
    { 6060, 0, 14, 6, 60, 0 },
    { 6540, 0, 15, 6, 60, 0 },
    { 7020, 1, 0, 0, 60, 0 },
    { 7080, 0, 0, 0, 90, 0 },
    { 7200, 4, 0, 0, 0, 0 },
    { 7680, 3, 0, 0, 120, 0 },
};

CStaffrollScene::CStaffrollScene()
{
    unk_04 = 0;
    unk_08 = 0;
    unk_0C = 0;
    unk_18 = NULL;
    unk_10 = NULL;
    unk_14 = NULL;
    unk_24 = NULL;
    unk_2C = 0;
    unk_30 = 0;
}

CStaffrollScene::~CStaffrollScene()
{
}

u32 CStaffrollScene::func0()
{
    if (unk_04 != 2) {
        for (u32 i = 0; i < 20; i++) {
            StaffrollEvent *event = &sEvents[i];
            if (event->frame == unk_2C) {
                switch (event->type) {
                case 0:
                    unk_24->ov25_0211F048(event->picture, 5, event->arg0, event->arg1, event->arg0, event->arg1);
                    break;
                case 1:
                    unk_24->ov25_0211F16C(event->arg0, event->arg1);
                    break;
                case 2:
                    unk_0C = event->arg0;
                    break;
                case 3:
                    unk_04 = 2;
                    s_game->m_mainFade->Start(4, event->arg1);
                    s_game->m_subFade->Start(4, event->arg1);
                    s_game->m_audioEngine->StopBgm(event->arg1);
                    break;
                case 4:
                    unk_28->ov25_0211FA54();
                    break;
                }
            }
        }
    }
    unk_2C++;
    int prev;
    int y;
    int upper;
    int count;
    int chapter = s_game->m_missionQuestData->m_chapter;
    switch (unk_04) {
    case 0:
        if (!s_game->m_mainFade->IsActive() && !s_game->m_subFade->IsActive()) {
            unk_04 = 1;
            unk_08 = 0;
            s_game->m_audioEngine->LoadBgmGroup(0x3B);
            s_game->m_audioEngine->PlayBgm(0x13, 0);
        }
    case 1: {
        fx32 old = unk_08;
        unk_08 += unk_0C;
        y = unk_08 >> FX32_SHIFT;
        prev = old >> FX32_SHIFT;
        if (y != prev) {
            unk_14->ov25_0211DD30(0, y);
            unk_10->ov25_0211DD30(0, y + 0xC0);
            int line = y >> 4;
            if (line != prev >> 4) {
                int lower = line - 1;
                upper = line - 13;
                count = unk_18->GetCount();
                if (lower >= 0) {
                    if (lower < count) {
                        unk_10->ov25_0211DBBC(0x80, y + 0x180, 3, unk_18->GetString(lower), 2);
                    } else {
                        unk_10->ov25_0211DBBC(0x80, y + 0x180, 3, "", 2);
                    }
                }
                if (upper >= 0) {
                    if (upper < count) {
                        unk_14->ov25_0211DBBC(0x80, y + 0xC0, 3, unk_18->GetString(upper), 2);
                    } else {
                        unk_14->ov25_0211DBBC(0x80, y + 0xC0, 3, "", 2);
                    }
                }
            }
        }
        if (chapter == 0x45 && (u16)(s_game->unk_0014->unk_0002 & 0xC0B)) {
            unk_04 = 2;
            s_game->m_mainFade->Start(4, 20);
            s_game->m_subFade->Start(4, 20);
            s_game->m_audioEngine->StopBgm(20);
        }
        break;
    }
    case 2:
        if (!s_game->m_mainFade->IsActive() && !s_game->m_subFade->IsActive()) {
            if (chapter >= 0x45) {
                return 1;
            }
            SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
            // case 1's scratch variables are reused here (the original's registers follow them)
            prev = s_c000First_0208ac1c[0x45].y << FX32_SHIFT;
            y = s_c000First_0208ac1c[0x45].x << FX32_SHIFT;
            count = s_c000First_0208ac1c[0x45].mapId;
            chapter = save->m_maxEnergy;
            save->m_energy = chapter;
            save->m_mapId = count;
            save->SetPos((Point2D) { y, prev });
            save->m_dir = 0;
            GlobalValues_ClearChapterValues((GlobalValues *)s_game->unk_14B4);
            GlobalValues_ApplyProgress((GlobalValues *)s_game->unk_14B4, 0x45);
            s_game->m_missionQuestData->m_chapter = 0x45;
            return 0x18;
        }
        break;
    }
    unk_24->ov25_0211E1B0();
    unk_28->ov25_0211F890();
    return -1;
}

void CStaffrollScene::func1()
{
    unk_28->ov25_0211FA20();
}

void CStaffrollScene::func2()
{
}

void CStaffrollScene::func3()
{
    LoadOam();
}

void CStaffrollScene::func5()
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
    MI_CpuFillFast((void *)HW_OAM, 192, HW_OAM_SIZE);
    MI_CpuClearFast((void *)HW_PLTT, HW_PLTT_SIZE);
    MI_CpuFillFast((void *)HW_DB_OAM, 192, HW_DB_OAM_SIZE);
    MI_CpuClearFast((void *)HW_DB_PLTT, HW_DB_PLTT_SIZE);

    GX_SetBankForTex(GX_VRAM_TEX_NONE);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_NONE);
    GX_SetBankForOBJ(GX_VRAM_OBJ_NONE);
    GX_SetBankForBG(GX_VRAM_BG_256_AB);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
    GX_SetBankForBGExtPltt(GX_VRAM_BGEXTPLTT_0123_E);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_128_D);
    GX_SetBankForSubBGExtPltt(GX_VRAM_SUB_BGEXTPLTT_0123_H);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);
    GX_SetVisiblePlane(GX_PLANEMASK_NONE);
    GXS_SetVisiblePlane(GX_PLANEMASK_OBJ);
    GX_DispOn();
    GXS_DispOn();
}

void CStaffrollScene::func6()
{
    char arcName[32];
    char name[32];

    s_game->unk_146C.SetFps(60);
    unk_04 = 0;
    unk_08 = 0;
    unk_0C = 0;
    s_game->m_mainFade->Start(3, 30);
    s_game->m_subFade->Start(3, 30);
    s_game->m_textboxData->LoadSystemMessages(0);
    unk_10 = new StaffrollText();
    unk_14 = new StaffrollText();
    unk_10->ov25_0211D6FC(&s_game->unk_14AC->unk_14);
    unk_14->ov25_0211D6FC(&s_game->unk_14AC->unk_14);
    unk_18 = new MessageTable("/data/message/etc/staffroll");
    CNCLRFile *nclr = new CNCLRFile("data/font/prs_lc_jp.NCLR", 1, 0, 0);
    DC_FlushRange(nclr->unk_B8->pRawData, 0x20);
    GX_LoadBGPltt(nclr->unk_B8->pRawData, 0x1E0, 0x20);
    GXS_LoadBGPltt(nclr->unk_B8->pRawData, 0x1E0, 0x20);
    delete nclr;
    unk_10->ov25_0211D758(4, 0, 2, 15, 0);
    unk_14->ov25_0211D758(0, 0, 2, 15, 0);
    MI_CpuClearFast((void *)HW_DB_BG_VRAM, 0x20);
    G2_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_256, GX_BG_SCRBASE_0x0800, GX_BG_CHARBASE_0x10000, GX_BG_EXTPLTT_01);
    G2_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_256, GX_BG_SCRBASE_0x1000, GX_BG_CHARBASE_0x20000);
    G2_SetBG1Priority(1);
    G2_SetBG2Priority(2);
    unk_24 = new StaffrollPictures();
    unk_24->ov25_0211E108(16, 1, 2);
    int set = 0;
    if (MAIN_BSS_020B26A0.m_sex != 0) {
        set = 1;
    }
    int *pictures = sPictures[set];
    for (int i = 0; i < 16; i++) {
        OS_SPrintf(arcName, "edu%03d_", pictures[i]);
        OS_SPrintf(name, "edu%03d", pictures[i]);
        unk_24->ov25_0211EFFC(i, "ending/", arcName, name, 0, 0);
    }
    unk_1C = 0;
    unk_20 = 0;
    unk_2C = 0;
    unk_28 = new StaffrollTheEnd();
    unk_28->ov25_0211F750();
    unk_30 = 0;
}

void CStaffrollScene::func7()
{
    if (unk_14 != NULL) {
        unk_14->ov25_0211DD30(0, 0);
        unk_14->ov25_0211DD14();
    }
    if (unk_10 != NULL) {
        unk_10->ov25_0211DD30(0, 0);
        unk_10->ov25_0211DD14();
    }
    SAFE_DELETE(unk_24);
    SAFE_DELETE(unk_10);
    SAFE_DELETE(unk_14);
    s_game->m_textboxData->FreeSystemMessages();
    SAFE_DELETE(unk_18);
    SAFE_DELETE(unk_28);
}

u32 CStaffrollScene::getSceneId()
{
    return 0x1A;
}

StaffrollPicture::StaffrollPicture()
{
    unk_10 = 0;
    ov25_0211D5DC();
}

StaffrollPicture::~StaffrollPicture()
{
    ov25_0211D514();
}

void StaffrollPicture::ov25_0211D514()
{
    SAFE_DELETE(unk_04);
}

BOOL StaffrollPicture::ov25_0211D548()
{
    switch (unk_00) {
    case 1:
        break;
    case 2:
        unk_04->LoadCharToVramPartial(unk_08, unk_0C);
        unk_08++;
        if (unk_08 >= unk_0C) {
            unk_00 = 3;
        }
        break;
    case 3:
        unk_04->LoadPlttToVram(TRUE);
        unk_00 = 4;
        break;
    case 4:
        unk_04->LoadScrToVram();
        unk_00 = 5;
        break;
    case 0:
    case 5:
        return FALSE;
    }
    return TRUE;
}

void StaffrollPicture::ov25_0211D5DC()
{
    unk_04 = NULL;
    unk_00 = 0;
}

void StaffrollPicture::ov25_0211D5EC(const char *dir, const char *name, const char *file, u32 charOffset, u32 plttNo)
{
    delete unk_04;
    unk_04 = new BGLayer(unk_10);
    unk_04->LoadArchive(dir, name);
    unk_04->LoadChar(file, 0, charOffset, 0);
    unk_04->LoadPltt(file, 0, plttNo, 0);
    unk_04->LoadScr(file, 0, plttNo, charOffset, 0, 0);
    unk_04->ReleaseArchive();
}

void StaffrollPicture::ov25_0211D6A8(int bg, int steps)
{
    unk_00 = 2;
    unk_04->SetBG(bg);
    unk_0C = steps;
    unk_08 = 0;
}

StaffrollText::StaffrollText()
{
    unk_04 = NULL;
    unk_08 = NULL;
    unk_00 = NULL;
}

StaffrollText::~StaffrollText()
{
    ov25_0211D704();
}

void StaffrollText::ov25_0211D6FC(NNSG2dFont *font)
{
    unk_00 = font;
}

void StaffrollText::ov25_0211D704()
{
    SAFE_DELETE(unk_04);
    SAFE_DELETE(unk_08);
    if (unk_1C != NULL) {
        Heap_Free(unk_1C);
        unk_1C = NULL;
    }
}

void StaffrollText::ov25_0211D758(int bg, int scrBase, int charBase, int plttNo, int priority)
{
    ov25_0211D704();
    unk_04 = new NNSG2dCharCanvas;
    unk_08 = new NNSG2dTextCanvas;
    unk_0C = bg;
    unk_10 = scrBase;
    unk_14 = charBase;
    void *scr = NULL;
    unk_18 = plttNo;
    void *chr = NULL;
    switch (bg) {
    case 0:
        G2_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, (GXBGScrBase)scrBase, (GXBGCharBase)charBase, GX_BG_EXTPLTT_23);
        GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG0);
        G2_SetBG0Priority(priority);
        scr = G2_GetBG0ScrPtr();
        chr = G2_GetBG0CharPtr();
        break;
    case 1:
        G2_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, (GXBGScrBase)scrBase, (GXBGCharBase)charBase, GX_BG_EXTPLTT_23);
        GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG1);
        G2_SetBG1Priority(priority);
        scr = G2_GetBG1ScrPtr();
        chr = G2_GetBG1CharPtr();
        break;
    case 2:
        G2_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, (GXBGScrBase)scrBase, (GXBGCharBase)charBase);
        GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG2);
        G2_SetBG2Priority(priority);
        scr = G2_GetBG2ScrPtr();
        chr = G2_GetBG2CharPtr();
        break;
    case 3:
        G2_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, (GXBGScrBase)scrBase, (GXBGCharBase)charBase);
        GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG3);
        G2_SetBG3Priority(priority);
        scr = G2_GetBG3ScrPtr();
        chr = G2_GetBG3CharPtr();
        break;
    case 4:
        G2S_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, (GXBGScrBase)scrBase, (GXBGCharBase)charBase, GX_BG_EXTPLTT_23);
        GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG0);
        G2S_SetBG0Priority(priority);
        scr = G2S_GetBG0ScrPtr();
        chr = G2S_GetBG0CharPtr();
        break;
    case 5:
        G2S_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, (GXBGScrBase)scrBase, (GXBGCharBase)charBase, GX_BG_EXTPLTT_23);
        GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG1);
        G2S_SetBG1Priority(priority);
        scr = G2S_GetBG1ScrPtr();
        chr = G2S_GetBG1CharPtr();
        break;
    case 6:
        G2S_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, (GXBGScrBase)scrBase, (GXBGCharBase)charBase);
        GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG2);
        G2S_SetBG2Priority(priority);
        scr = G2S_GetBG2ScrPtr();
        chr = G2S_GetBG2CharPtr();
        break;
    case 7:
        G2S_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, (GXBGScrBase)scrBase, (GXBGCharBase)charBase);
        GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG3);
        G2S_SetBG3Priority(priority);
        scr = G2S_GetBG3ScrPtr();
        chr = G2S_GetBG3CharPtr();
        break;
    }
    MI_CpuClearFast(scr, 0x800);
    NNS_G2dCharCanvasInitForBG(unk_04, chr, 32, 32, NNS_G2D_CHARA_COLORMODE_16);
    NNS_G2dTextCanvasInit(unk_08, unk_04, unk_00, 1, 3);
    NNS_G2dMapScrToCharText(scr, 32, 32, 0, 0, NNS_G2D_TEXT_BG_WIDTH_256, 0, plttNo);
    ov25_0211DD14();
    unk_1C = (u16 *)Heap_AllocWithAlignment(0x800, 4);
    for (int i = 0; i < 0x400; i++) {
        unk_1C[i] = i | (plttNo << 12);
    }
    unk_20 = 0;
    unk_24 = 0;
}

void StaffrollText::ov25_0211DBBC(int x0, int y0, int color, const char *str, int align)
{
    x0 = (u8)x0;
    y0 = (u8)y0;
    NNSG2dTextCanvas *txn = unk_08;
    const NNSG2dFont *font = txn->pFont;
    int lineHeight = txn->vSpace + font->pRes->linefeed;
    int hSpace = txn->hSpace;
    int cx;
    NNSiG2dSplitCharCallback split = font->cbCharSpliter;
    switch (align & 3) {
    case 1:
        break;
    case 2:
        x0 -= NNS_G2dTextCanvasGetTextWidth(txn, (const NNSG2dChar *)str) >> 1;
        break;
    case 3:
        x0 -= NNS_G2dTextCanvasGetTextWidth(txn, (const NNSG2dChar *)str);
        break;
    }
    NNS_G2dCharCanvasClearArea(unk_04, 0, 0, y0, unk_04->areaWidth * 8, lineHeight);
    cx = x0;
    for (;;) {
        u16 c = split((const void **)&str);
        if (c == 0) {
            return;
        }
        if (c == '[') {
            if (split((const void **)&str) == 'E') {
                y0 += lineHeight;
                cx = x0;
                NNS_G2dCharCanvasClearArea(unk_08->pCanvas, 0, x0, y0, unk_04->areaWidth * 8 - x0, lineHeight);
            }
            str++;
        } else {
            cx += NNS_G2dCharCanvasDrawChar(unk_04, font, cx, y0, color, c);
            cx += hSpace;
        }
    }
}

void StaffrollText::ov25_0211DD14()
{
    MI_CpuClearFast(unk_04->charBase, 0x8000);
}

void StaffrollText::ov25_0211DD30(int x0, int y0)
{
    u8 x = x0;
    u8 y = y0;
    int row = y >> 3;
    BOOL changed = FALSE;
    if (unk_20 != x >> 3 || row != unk_24) {
        unk_20 = x >> 3;
        unk_24 = row;
        changed = TRUE;
    }
    int size;
    switch (unk_0C) {
    case 0:
        G2_SetBG0Offset(x, y & 7);
        if (changed) {
            size = (32 - row) << 6;
            GX_LoadBG0Scr(&unk_1C[row * 32], 0, size);
            if (row != 0) {
                GX_LoadBG0Scr(unk_1C, size, row << 6);
            }
        }
        break;
    case 1:
        G2_SetBG1Offset(x, y & 7);
        if (changed) {
            size = (32 - row) << 6;
            GX_LoadBG1Scr(&unk_1C[row * 32], 0, size);
            if (row != 0) {
                GX_LoadBG1Scr(unk_1C, size, row << 6);
            }
        }
        break;
    case 2:
        G2_SetBG2Offset(x, y & 7);
        if (changed) {
            size = (32 - row) << 6;
            GX_LoadBG2Scr(&unk_1C[row * 32], 0, size);
            if (row != 0) {
                GX_LoadBG2Scr(unk_1C, size, row << 6);
            }
        }
        break;
    case 3:
        G2_SetBG3Offset(x, y & 7);
        if (changed) {
            size = (32 - row) << 6;
            GX_LoadBG3Scr(&unk_1C[row * 32], 0, size);
            if (row != 0) {
                GX_LoadBG3Scr(unk_1C, size, row << 6);
            }
        }
        break;
    case 4:
        G2S_SetBG0Offset(x, y & 7);
        if (changed) {
            size = (32 - row) << 6;
            GXS_LoadBG0Scr(&unk_1C[row * 32], 0, size);
            if (row != 0) {
                GXS_LoadBG0Scr(unk_1C, size, row << 6);
            }
        }
        break;
    case 5:
        G2S_SetBG1Offset(x, y & 7);
        if (changed) {
            size = (32 - row) << 6;
            GXS_LoadBG1Scr(&unk_1C[row * 32], 0, size);
            if (row != 0) {
                GXS_LoadBG1Scr(unk_1C, size, row << 6);
            }
        }
        break;
    case 6:
        G2S_SetBG2Offset(x, y & 7);
        if (changed) {
            size = (32 - row) << 6;
            GXS_LoadBG2Scr(&unk_1C[row * 32], 0, size);
            if (row != 0) {
                GXS_LoadBG2Scr(unk_1C, size, row << 6);
            }
        }
        break;
    case 7:
        G2S_SetBG3Offset(x, y & 7);
        if (changed) {
            size = (32 - row) << 6;
            GXS_LoadBG3Scr(&unk_1C[row * 32], 0, size);
            if (row != 0) {
                GXS_LoadBG3Scr(unk_1C, size, row << 6);
            }
        }
        break;
    }
}

StaffrollPictures::StaffrollPictures()
{
    unk_00 = NULL;
    unk_04 = 0;
    unk_08 = 0;
    unk_0C = 0;
    unk_10 = 0;
    unk_18 = 0;
    unk_14 = 0;
    unk_1C = 0;
    unk_20[0] = 0;
    unk_20[1] = 0;
    unk_28 = 0;
    unk_2C = NULL;
}

StaffrollPictures::~StaffrollPictures()
{
    ov25_0211E174();
}

void StaffrollPictures::ov25_0211E108(int count, int bg0, int bg1)
{
    unk_00 = new StaffrollPicture[count];
    unk_04 = count;
    unk_08 = 0;
    unk_0C = 0;
    unk_10 = 0;
    unk_18 = 0;
    unk_14 = 0;
    unk_1C = 0;
    unk_20[0] = bg0;
    unk_20[1] = bg1;
    unk_28 = 0;
    unk_2C = NULL;
}

void StaffrollPictures::ov25_0211E174()
{
    if (unk_00 != NULL) {
        delete[] unk_00;
        unk_00 = NULL;
    }
    unk_04 = 0;
}

void StaffrollPictures::ov25_0211E1B0()
{
    BOOL main = unk_20[unk_28] <= 3;
    BOOL loading = FALSE;
    if (unk_2C != NULL) {
        if (!unk_2C->ov25_0211D548()) {
            unk_2C = NULL;
        } else {
            loading = TRUE;
        }
    }
    switch (unk_08) {
    case 1: {
        if (loading) {
            return;
        }
        ov25_0211F1D4(unk_20[unk_28]);
        unk_0C++;
        if (unk_0C >= unk_18) {
            if (main) {
                G2_BlendNone();
                GX_SetVisibleWnd(GX_WNDMASK_NONE);
            } else {
                G2S_BlendNone();
                GX_SetVisibleWnd(GX_WNDMASK_NONE); // main screen's window mask
            }
            ov25_0211F5CC(unk_20[unk_28], 0, 0);
            ov25_0211F5CC(unk_20[!unk_28], 0, 0);
            ov25_0211F344(unk_20[!unk_28]);
            unk_08 = 2;
            return;
        }
        int ev = unk_0C * 16 / unk_18;
        int brightness = 16 - ev;
        int dx = (unk_0C << 8) / unk_18;
        int dy = unk_0C * 192 / unk_18;
        switch (unk_10) {
        default:
        case 0:
            if (main) {
                G2_SetBlendBrightness(1 << (unk_20[unk_28] & 3), -brightness);
            } else {
                G2S_SetBlendBrightness(1 << (unk_20[unk_28] & 3), -brightness);
            }
            break;
        case 1:
            if (main) {
                G2_SetBlendBrightness(1 << (unk_20[unk_28] & 3), brightness);
            } else {
                G2S_SetBlendBrightness(1 << (unk_20[unk_28] & 3), brightness);
            }
            break;
        case 6:
            if (main) {
                G2_SetBlendAlpha(1 << (unk_20[!unk_28] & 3), 1 << (unk_20[unk_28] & 3), brightness, ev);
            } else {
                G2S_SetBlendAlpha(1 << (unk_20[!unk_28] & 3), 1 << (unk_20[unk_28] & 3), brightness, ev);
            }
            break;
        case 2:
            ov25_0211F5CC(unk_20[!unk_28], dx, 0);
            ov25_0211F5CC(unk_20[unk_28], -(0x100 - dx), 0);
            if (main) {
                GX_SetVisibleWnd(GX_WNDMASK_W0);
                G2_SetWnd0InsidePlane(~(1 << (unk_20[!unk_28] & 3)) & 0x1F, FALSE);
                G2_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2_SetWnd0Position(0x100 - dx, 0, 0xFF, 0xBF);
            } else {
                GXS_SetVisibleWnd(GX_WNDMASK_W0);
                G2S_SetWnd0InsidePlane(~(1 << (unk_20[!unk_28] & 3)) & 0x1F, FALSE);
                G2S_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2S_SetWnd0Position(0x100 - dx, 0, 0xFF, 0xBF);
            }
            break;
        case 3:
            ov25_0211F5CC(unk_20[!unk_28], -dx, 0);
            ov25_0211F5CC(unk_20[unk_28], 0x100 - dx, 0);
            if (main) {
                GX_SetVisibleWnd(GX_WNDMASK_W0);
                G2_SetWnd0InsidePlane(~(1 << (unk_20[!unk_28] & 3)) & 0x1F, FALSE);
                G2_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2_SetWnd0Position(0, 0, dx, 0xBF);
            } else {
                GXS_SetVisibleWnd(GX_WNDMASK_W0);
                G2S_SetWnd0InsidePlane(~(1 << (unk_20[!unk_28] & 3)) & 0x1F, FALSE);
                G2S_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2S_SetWnd0Position(0, 0, dx, 0xBF);
            }
            break;
        case 4:
            ov25_0211F5CC(unk_20[!unk_28], 0, dy);
            ov25_0211F5CC(unk_20[unk_28], 0, -(0xC0 - dy));
            if (main) {
                GX_SetVisibleWnd(GX_WNDMASK_W0);
                G2_SetWnd0InsidePlane(~(1 << (unk_20[!unk_28] & 3)) & 0x1F, FALSE);
                G2_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2_SetWnd0Position(0, 0xC0 - dy, 0xFF, 0xBF);
            } else {
                GXS_SetVisibleWnd(GX_WNDMASK_W0);
                G2S_SetWnd0InsidePlane(~(1 << (unk_20[!unk_28] & 3)) & 0x1F, FALSE);
                G2S_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2S_SetWnd0Position(0, 0xC0 - dy, 0xFF, 0xBF);
            }
            break;
        case 5:
            ov25_0211F5CC(unk_20[!unk_28], 0, -dy);
            ov25_0211F5CC(unk_20[unk_28], 0, 0xC0 - dy);
            if (main) {
                GX_SetVisibleWnd(GX_WNDMASK_W0);
                G2_SetWnd0InsidePlane(~(1 << (unk_20[!unk_28] & 3)) & 0x1F, FALSE);
                G2_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2_SetWnd0Position(0, 0, 0xFF, dy);
            } else {
                GXS_SetVisibleWnd(GX_WNDMASK_W0);
                G2S_SetWnd0InsidePlane(~(1 << (unk_20[!unk_28] & 3)) & 0x1F, FALSE);
                G2S_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2S_SetWnd0Position(0, 0, 0xFF, dy);
            }
            break;
        }
        break;
    }
    case 3: {
        int frame = ++unk_0C;
        int duration = unk_1C;
        if (frame >= duration) {
            if (main) {
                G2_BlendNone();
                GX_SetVisibleWnd(GX_WNDMASK_NONE);
            } else {
                G2S_BlendNone();
                GXS_SetVisibleWnd(GX_WNDMASK_NONE);
            }
            ov25_0211F5CC(unk_20[unk_28], 0, 0);
            ov25_0211F5CC(unk_20[!unk_28], 0, 0);
            ov25_0211F344(unk_20[unk_28]);
            if (unk_18 >= 0) {
                unk_28 = unk_28 == 0 ? 1 : 0;
                unk_0C = 0;
                unk_08 = 1;
                return;
            }
            unk_08 = 0;
            return;
        }
        int ev = frame * 31 / duration;
        int dx = (frame << 8) / duration;
        int dy = frame * 192 / duration;
        switch (unk_14) {
        default:
        case 0:
        case 6:
            if (main) {
                G2_ChangeBlendBrightness(-ev / 2);
            } else {
                G2S_ChangeBlendBrightness(-ev / 2);
            }
            break;
        case 1:
            if (main) {
                G2_ChangeBlendBrightness(ev / 2);
            } else {
                G2S_ChangeBlendBrightness(ev / 2);
            }
            break;
        case 2:
            ov25_0211F5CC(unk_20[unk_28], dx, 0);
            if (main) {
                GX_SetVisibleWnd(GX_WNDMASK_W0);
                G2_SetWnd0InsidePlane(0x1F, FALSE);
                G2_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2_SetWnd0Position(0, 0, 0x100 - dx, 0xBF);
            } else {
                G2S_SetWnd0InsidePlane(0x1F, FALSE);
                G2S_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2S_SetWnd0Position(0, 0, 0x100 - dx, 0xBF);
            }
            break;
        case 3:
            ov25_0211F5CC(unk_20[unk_28], -dx, 0);
            if (main) {
                GX_SetVisibleWnd(GX_WNDMASK_W0);
                G2_SetWnd0InsidePlane(0x1F, FALSE);
                G2_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2_SetWnd0Position(dx, 0, 0xFF, 0xBF);
            } else {
                G2S_SetWnd0InsidePlane(0x1F, FALSE);
                G2S_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2S_SetWnd0Position(dx, 0, 0xFF, 0xBF);
            }
            break;
        case 4:
            ov25_0211F5CC(unk_20[unk_28], 0, dy);
            if (main) {
                GX_SetVisibleWnd(GX_WNDMASK_W0);
                G2_SetWnd0InsidePlane(0x1F, FALSE);
                G2_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2_SetWnd0Position(0, 0, 0xFF, 0xC0 - dy);
            } else {
                G2S_SetWnd0InsidePlane(0x1F, FALSE);
                G2S_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2S_SetWnd0Position(0, 0, 0xFF, 0xC0 - dy);
            }
            break;
        case 5:
            ov25_0211F5CC(unk_20[unk_28], 0, -dy);
            if (main) {
                GX_SetVisibleWnd(GX_WNDMASK_W0);
                G2_SetWnd0InsidePlane(0x1F, FALSE);
                G2_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2_SetWnd0Position(0, dy, 0xFF, 0xBF);
            } else {
                G2S_SetWnd0InsidePlane(0x1F, FALSE);
                G2S_SetWndOutsidePlane(~(1 << (unk_20[unk_28] & 3)) & 0x1F, FALSE);
                G2S_SetWnd0Position(0, dy, 0xFF, 0xBF);
            }
            break;
        }
        break;
    }
    case 0:
    case 2:
        break;
    }
}

void StaffrollPictures::ov25_0211EFFC(int idx, const char *dir, const char *name, const char *file, u32 charOffset, u32 plttNo)
{
    if (idx >= unk_04) {
        return;
    }
    unk_00[idx].ov25_0211D5EC(dir, name, file, charOffset, plttNo);
}

void StaffrollPictures::ov25_0211F048(int idx, int steps, int type, int duration, int outType, int outDuration)
{
    if (idx >= unk_04) {
        return;
    }
    unk_00[idx].ov25_0211D6A8(unk_20[!unk_28], steps);
    unk_2C = &unk_00[idx];
    switch (type) {
    default:
    case 0:
    case 1:
        if (unk_08 == 0) {
            unk_08 = 1;
            unk_28 = unk_28 == 0 ? 1 : 0;
        } else {
            ov25_0211F16C(outType, outDuration);
            unk_08 = 3;
        }
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
        unk_08 = 1;
        unk_28 = unk_28 == 0 ? 1 : 0;
        ov25_0211F4C0(unk_20[unk_28], 2);
        ov25_0211F4C0(unk_20[!unk_28], 1);
        break;
    }
    unk_10 = type;
    unk_18 = duration;
    unk_0C = 0;
}

void StaffrollPictures::ov25_0211F16C(int type, int duration)
{
    unk_08 = 3;
    unk_14 = type;
    unk_1C = duration;
    unk_0C = 0;
    unk_10 = -1;
    unk_18 = -1;
    if (unk_20[unk_28] <= 3) {
        G2_SetBlendBrightness(1 << (unk_20[unk_28] & 3), 0);
    } else {
        G2S_SetBlendBrightness(1 << (unk_20[unk_28] & 3), 0);
    }
}

void StaffrollPictures::ov25_0211F1D4(int bg)
{
    switch (bg) {
    case 0:
        GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG0);
        break;
    case 1:
        GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG1);
        break;
    case 2:
        GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG2);
        break;
    case 3:
        GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG3);
        break;
    case 4:
        GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG0);
        break;
    case 5:
        GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG1);
        break;
    case 6:
        GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG2);
        break;
    case 7:
        GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG3);
        break;
    }
}

void StaffrollPictures::ov25_0211F344(int bg)
{
    switch (bg) {
    case 0:
        GX_SetVisiblePlane(GX_GetVisiblePlane() & ~GX_PLANEMASK_BG0);
        break;
    case 1:
        GX_SetVisiblePlane(GX_GetVisiblePlane() & ~GX_PLANEMASK_BG1);
        break;
    case 2:
        GX_SetVisiblePlane(GX_GetVisiblePlane() & ~GX_PLANEMASK_BG2);
        break;
    case 3:
        GX_SetVisiblePlane(GX_GetVisiblePlane() & ~GX_PLANEMASK_BG3);
        break;
    case 4:
        GXS_SetVisiblePlane(GX_GetVisiblePlane() & ~GX_PLANEMASK_BG0);
        break;
    case 5:
        GXS_SetVisiblePlane(GX_GetVisiblePlane() & ~GX_PLANEMASK_BG1);
        break;
    case 6:
        GXS_SetVisiblePlane(GX_GetVisiblePlane() & ~GX_PLANEMASK_BG2);
        break;
    case 7:
        GXS_SetVisiblePlane(GX_GetVisiblePlane() & ~GX_PLANEMASK_BG3);
        break;
    }
}

void StaffrollPictures::ov25_0211F4C0(int bg, int priority)
{
    switch (bg) {
    case 0:
        G2_SetBG0Priority(priority);
        break;
    case 1:
        G2_SetBG1Priority(priority);
        break;
    case 2:
        G2_SetBG2Priority(priority);
        break;
    case 3:
        G2_SetBG3Priority(priority);
        break;
    case 4:
        G2S_SetBG0Priority(priority);
        break;
    case 5:
        G2S_SetBG1Priority(priority);
        break;
    case 6:
        G2S_SetBG2Priority(priority);
        break;
    case 7:
        G2S_SetBG3Priority(priority);
        break;
    }
}

void StaffrollPictures::ov25_0211F5CC(int bg, int x, int y)
{
    switch (bg) {
    case 0:
        G2_SetBG0Offset(x, y);
        break;
    case 1:
        G2_SetBG1Offset(x, y);
        break;
    case 2:
        G2_SetBG2Offset(x, y);
        break;
    case 3:
        G2_SetBG3Offset(x, y);
        break;
    case 4:
        G2S_SetBG0Offset(x, y);
        break;
    case 5:
        G2S_SetBG1Offset(x, y);
        break;
    case 6:
        G2S_SetBG2Offset(x, y);
        break;
    case 7:
        G2S_SetBG3Offset(x, y);
        break;
    }
}

StaffrollTheEnd::StaffrollTheEnd()
{
    unk_00 = NULL;
    unk_04 = NULL;
    unk_08 = NULL;
    unk_0C = NULL;
    unk_10 = 0;
    unk_14 = 0;
}

StaffrollTheEnd::~StaffrollTheEnd()
{
    ov25_0211F840();
}

BOOL StaffrollTheEnd::ov25_0211F750()
{
    ov25_0211F840();
    unk_00 = new OamSpriteSet((GXOamAttr *)&s_game->unk_0424[0], 0, TRUE, 0x40);
    unk_00->Load("data/ending", "edobj000", 0, 0);
    unk_0C = unk_00->AddSprite(0, -0x20, 0x40, 0);
    unk_04 = unk_00->AddSprite(1, 0x80, 0x40, 0);
    unk_08 = unk_00->AddSprite(2, 0x80, 0x70, 0);
    unk_04->unk_14 = FALSE;
    unk_08->unk_14 = FALSE;
    unk_0C->unk_14 = FALSE;
    return TRUE;
}

BOOL StaffrollTheEnd::ov25_0211F840()
{
    SAFE_DELETE(unk_00);
    unk_04 = NULL;
    unk_08 = NULL;
    unk_0C = NULL;
    unk_10 = 0;
    unk_14 = 0;
    return TRUE;
}

BOOL StaffrollTheEnd::ov25_0211F890()
{
    switch (unk_10) {
    case 1:
        unk_04->unk_14 = TRUE;
        unk_08->unk_14 = FALSE;
        unk_0C->unk_14 = TRUE;
        unk_14 = 0;
        unk_10 = 2;
        break;
    case 2:
        unk_14++;
        unk_0C->SetPos(unk_14 * 4 - 0x20, 0x40);
        if (unk_14 >= 0x48) {
            unk_14 = 0;
            unk_10 = 3;
        }
        break;
    case 3:
        unk_0C->SetPos(-0x20, 0x70);
        unk_0C->unk_14 = FALSE;
        unk_14 = 0;
        unk_10 = 5;
        break;
    case 5:
        unk_04->unk_14 = TRUE;
        unk_08->unk_14 = FALSE;
        unk_0C->unk_14 = TRUE;
        unk_14 = 0;
        unk_10 = 6;
        break;
    case 6:
        unk_14++;
        unk_0C->SetPos(unk_14 * 4 - 0x20, 0x70);
        if (unk_14 == 8) {
            unk_08->unk_14 = TRUE;
        }
        if (unk_14 >= 0x48) {
            unk_14 = 0;
            unk_10 = 7;
        }
        break;
    case 7:
        unk_0C->unk_14 = FALSE;
        unk_14 = 0;
        unk_10 = 8;
        break;
    case 9:
        break;
    }
    if (unk_00 != NULL) {
        unk_00->Update();
    }
    return TRUE;
}

BOOL StaffrollTheEnd::ov25_0211FA20()
{
    if (unk_00 != NULL && unk_10 >= 1 && unk_10 <= 8) {
        unk_00->WriteOam();
    }
    return TRUE;
}

BOOL StaffrollTheEnd::ov25_0211FA54()
{
    unk_10 = 1;
    return TRUE;
}
