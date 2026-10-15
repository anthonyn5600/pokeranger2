#include "scene/CNameInputScene.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "AudioEngine.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "CTouchPanel.hpp"
#include "Collision.hpp"
#include "FontSet.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "SaveData.hpp"
#include "TextPrinter.hpp"
#include "TextboxManager.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CBinaryFileMes.hpp"
#include "file/CNCLRFile.hpp"
#include "file/CNSCRFile.hpp"
#include "primitive/CPrimitiveRECT.hpp"

extern SaveData MAIN_BSS_020B26A0;

#define LOAD_MESSAGES(table, path)                                                                         \
    {                                                                                                      \
        CBinaryFileMes *file = new CBinaryFileMes(path, 1);                                                \
        table = new UnkClass_020091E8_004();                                                               \
        pos = 2;                                                                                           \
        table->unk_00 = ((u32 *)file->unk_4C)[0];                                                          \
        table->unk_04 = ((u32 *)file->unk_4C)[1];                                                          \
        table->unk_08 = new UnkClass_020091E8_004_08[table->unk_04];                                       \
        for (u32 i = 0; i < table->unk_04; ++i) {                                                          \
            table->unk_08[i].unk_00 = ((u32 *)file->unk_4C)[pos];                                          \
            ++pos;                                                                                         \
            table->unk_08[i].unk_04 = new u8[table->unk_08[i].unk_00];                                     \
            MI_CpuCopyFast(&((u32 *)file->unk_4C)[pos], table->unk_08[i].unk_04, table->unk_08[i].unk_00); \
            pos += table->unk_08[i].unk_00 / 4;                                                            \
        }                                                                                                  \
        delete file;                                                                                       \
    }

#define RELEASE_MESSAGES(table)                    \
    if (table != NULL) {                           \
        for (u32 i = 0; i < table->unk_04; ++i) {  \
            if (table->unk_08[i].unk_04 != NULL) { \
                delete[] table->unk_08[i].unk_04;  \
                table->unk_08[i].unk_04 = NULL;    \
            }                                      \
        }                                          \
        if (table->unk_08 != NULL) {               \
            delete[] table->unk_08;                \
            table->unk_08 = NULL;                  \
        }                                          \
        if (table != NULL) {                       \
            delete table;                          \
            table = NULL;                          \
        }                                          \
    }

#define SET_KEY_RECT(idx, px, py, w, h)   \
    unk_00CC[idx] = new CPrimitiveRECT(); \
    unk_00CC[idx]->SetPos(px, py);        \
    unk_00CC[idx]->SetSize(w, h);

static const u32 s_keysUpper[12][5] = {
    { 0x41, 0x48, 0x4F, 0x56, 0x20 },
    { 0x42, 0x49, 0x50, 0x57, 0x20 },
    { 0x43, 0x4A, 0x51, 0x58, 0x20 },
    { 0x44, 0x4B, 0x52, 0x59, 0x20 },
    { 0x45, 0x4C, 0x53, 0x5A, 0x20 },
    { 0x46, 0x4D, 0x54, 0x20, 0x20 },
    { 0x47, 0x4E, 0x55, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x2C, 0x27, 0xE29982, 0x20, 0x20 },
    { 0x2E, 0x2D, 0xE29980, 0x20, 0x20 },
};

static const u32 s_keysLower[12][5] = {
    { 0x61, 0x68, 0x6F, 0x76, 0xC3A9 },
    { 0x62, 0x69, 0x70, 0x77, 0x20 },
    { 0x63, 0x6A, 0x71, 0x78, 0x20 },
    { 0x64, 0x6B, 0x72, 0x79, 0x20 },
    { 0x65, 0x6C, 0x73, 0x7A, 0x20 },
    { 0x66, 0x6D, 0x74, 0x20, 0x20 },
    { 0x67, 0x6E, 0x75, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x20, 0x20, 0x20, 0x20, 0x20 },
    { 0x2C, 0x27, 0xE29982, 0x20, 0x20 },
    { 0x2E, 0x2D, 0xE29980, 0x20, 0x20 },
};

static const u32 s_keysSymbol[12][5] = {
    { 0x30, 0x2C, 0xE280A6, 0x2B, 0xE29885 },
    { 0x31, 0x2E, 0xC2B7, 0x2D, 0xE2978B },
    { 0x32, 0x3A, 0xEFBD9E, 0x2A, 0xE2978E },
    { 0x33, 0x3B, 0x2F, 0x3D, 0xE29787 },
    { 0x34, 0xE2809C, 0x28, 0x25, 0xE296A1 },
    { 0x35, 0xE2809D, 0x29, 0x40, 0xE296B3 },
    { 0x36, 0xE28098, 0x20, 0x20, 0xE299AA },
    { 0x37, 0xE28099, 0x20, 0x20, 0x20 },
    { 0x38, 0x20, 0x20, 0x20, 0x20 },
    { 0x39, 0x20, 0x20, 0x20, 0x20 },
    { 0x20, 0x21, 0xE29982, 0x20, 0x20 },
    { 0x20, 0x3F, 0xE29980, 0x20, 0x20 },
};

struct NameWindow {
    int width;
    int height;
    int left;
    int top;
    int x;
    int y;
    int color;
    int hSpace;
    int vSpace;
};

CNameInputScene::CNameInputScene()
{
    m_game = CGame::GetInstance();
    m_audioEngine = CGame::GetInstance()->m_audioEngine;
    m_audioEngine->LoadSystemSe();
    m_audioEngine->LoadBgmGroup(3);
    unk_000C = 0;
    unk_0010 = 0;
    unk_0004 = 0;
    unk_0005 = 0;
    unk_0007 = 0;
    unk_0008 = 0;

    for (int i = 0; i < 4; i++) {
        unk_00BC[i] = NULL;
    }

    for (int i = 0; i < 22; i++) {
        unk_0068[i] = 0;
    }
}

CNameInputScene::~CNameInputScene()
{
    m_audioEngine->StopBgm(1);
    func7();
}

void CNameInputScene::SetPage(int page)
{
    unk_00BC[1]->SetAnim(unk_0020, 7);
    unk_00BC[1]->SetAnim(unk_0024, 7);
    unk_00BC[1]->SetAnim(unk_002C, 7);
    TextPrinter *text = m_game->unk_1494;
    text->ClearWindow(0);
    text->ClearWindow(1);
    text->ClearWindow(2);
    text->ClearWindow(3);
    text->ClearWindow(4);
    text->ClearWindow(5);
    text->ClearWindow(6);

    const u32 *keys;
    switch (page) {
    default:
    case 0:
        keys = s_keysUpper[0];
        text->Print(3, 5, 4, 3, unk_01DC->unk_08[1].unk_04, FALSE, 0);
        text->Print(4, 5, 4, 7, unk_01DC->unk_08[2].unk_04, FALSE, 0);
        text->Print(5, 5, 4, 7, unk_01DC->unk_08[4].unk_04, FALSE, 0);
        unk_00BC[1]->SetAnim(unk_0020, 6);
        break;
    case 1:
        keys = s_keysLower[0];
        text->Print(3, 5, 4, 7, unk_01DC->unk_08[1].unk_04, FALSE, 0);
        text->Print(4, 5, 4, 3, unk_01DC->unk_08[2].unk_04, FALSE, 0);
        text->Print(5, 5, 4, 7, unk_01DC->unk_08[4].unk_04, FALSE, 0);
        unk_00BC[1]->SetAnim(unk_0024, 6);
        break;
    case 2:
    case 3:
        keys = s_keysSymbol[0];
        text->Print(3, 5, 4, 7, unk_01DC->unk_08[1].unk_04, FALSE, 0);
        text->Print(4, 5, 4, 7, unk_01DC->unk_08[2].unk_04, FALSE, 0);
        text->Print(5, 5, 4, 3, unk_01DC->unk_08[4].unk_04, FALSE, 0);
        unk_00BC[1]->SetAnim(unk_002C, 6);
        break;
    }

    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 5; j++) {
            u32 c = keys[i * 5 + j];
            int x = i * 16 + 3;
            int y = j * 16 + 3;
            if (!(c & 0x80000000)) {
                PrintChar(0, x, y, 1, c);
            } else {
                switch (c & ~0xFF000000) {
                case 1:
                    m_game->unk_1494->Print(0, x, y, 1, (u8 *)"[...]", FALSE, 0);
                    break;
                case 2:
                    m_game->unk_1494->Print(0, x, y, 1, (u8 *)"[-]", FALSE, 0);
                    break;
                }
            }
        }
    }
    unk_0005 = page;
}

void CNameInputScene::SetCursor(u8 pos)
{
    u8 col = pos;
    if (pos >= 7) {
        col = 6;
    }
    unk_0090->SetPos((u16)(col * 11 + 0x5E), 0x20);
    unk_0004 = pos;
}

void CNameInputScene::DeleteChar()
{
    if (unk_0004 == 0) {
        return;
    }
    SetCursor(unk_0004 - 1);
    u16 len = GetNameLength();
    int c = unk_004C[unk_0004];
    unk_004C[unk_0004] = 0;
    int n = 4;
    for (int i = 0; i < 4; i++) {
        if ((c >> ((3 - i) * 8)) & 0xFF) {
            break;
        }
        n--;
    }
    for (int i = 0; i < n; i++) {
        unk_0068[len - 1] = 0;
        len--;
    }
    DrawName();
}

void CNameInputScene::InputChar(int pos, int page, int idx)
{
    u32 c = 0;
    switch (page) {
    case 0:
        c = s_keysUpper[0][idx];
        break;
    case 1:
        c = s_keysLower[0][idx];
        break;
    case 3:
        c = s_keysSymbol[0][idx];
        break;
    }
    u16 len = GetNameLength();
    unk_0030[pos] = idx | (page << 24);
    unk_004C[pos] = c;
    int n = 0;
    for (int i = 0; i < 4; i++) {
        u8 b = c >> ((3 - i) * 8);
        if (b != 0 || n != 0) {
            unk_0068[len] = b;
            len++;
            n++;
        }
    }
    DrawName();
}

BOOL CNameInputScene::UseDefaultNameIfEmpty()
{
    int i;
    for (i = 0; i < 7; i++) {
        int c = unk_004C[i];
        if (c != 0 && c != 0xE38080 && c != 0x20) {
            return FALSE;
        }
    }
    for (i = 0; i < 21; i++) {
        unk_0068[i] = 0;
    }
    for (i = 0; i < 7; i++) {
        unk_0030[i] = 0;
        unk_004C[i] = 0;
    }
    if (MAIN_BSS_020B26A0.m_sex == 0) {
        unk_0068[0] = 'K';
        unk_0068[1] = 'e';
        unk_0068[2] = 'l';
        unk_0068[3] = 'l';
        unk_0068[4] = 'y';
        unk_0068[5] = 'n';
        unk_0030[0] = 0x10;
        unk_0030[1] = 0x01000014;
        unk_0030[2] = 0x01000015;
        unk_0030[3] = 0x01000015;
        unk_0030[4] = 0x01000012;
        unk_0030[5] = 0x0100001F;
        unk_004C[0] = 'K';
        unk_004C[1] = 'e';
        unk_004C[2] = 'l';
        unk_004C[3] = 'l';
        unk_004C[4] = 'y';
        unk_004C[5] = 'n';
        SetCursor(6);
    } else if (MAIN_BSS_020B26A0.m_sex == 1) {
        unk_0068[0] = 'K';
        unk_0068[1] = 'a';
        unk_0068[2] = 't';
        unk_0068[3] = 'e';
        unk_0030[0] = 0x10;
        unk_0030[1] = 0x01000000;
        unk_0030[2] = 0x0100001F;
        unk_0030[3] = 0x0100001B;
        unk_004C[0] = 'K';
        unk_004C[1] = 'a';
        unk_004C[2] = 't';
        unk_004C[3] = 'e';
        SetCursor(4);
    }
    DrawName();
    return TRUE;
}

u32 CNameInputScene::func0()
{
    if (s_game->m_mainFade->IsActive() && s_game->m_subFade->IsActive()) {
        return -1;
    }
    switch (unk_0010) {
    case 0:
        unk_0010 = 2;
        unk_000C = 0;
        m_audioEngine->PlayBgm(0x16, 0x40);
        break;
    case 2:
        UpdateInput();
        break;
    case 3:
        UpdateConfirm();
        break;
    case 4:
        StartMode();
        break;
    case 5:
        SwitchMode();
        break;
    case 6:
        if (!s_game->m_mainFade->IsActive() && !s_game->m_subFade->IsActive()) {
            return 1;
        }
        break;
    }
    return -1;
}

void CNameInputScene::UpdateInput()
{
    int i;
    unk_00BC[0]->Update();
    unk_00BC[1]->Update();
    CTouchPanel *tp = m_game->touchPanel;
    Point2D touch;
    touch.x = (tp->unk_0A.x - 0x80) << FX32_SHIFT;
    touch.y = (tp->unk_0A.y - 0x60) << FX32_SHIFT;
    if (tp->unk_04 != 0) {
        for (i = 0; i < 12; i++) {
            for (int j = 0; j < 5; j++) {
                int idx = i * 5 + j;
                if (PointInRect(touch, unk_00CC[idx]->m_rectangle, 0)) {
                    if (unk_0004 < 7) {
                        InputChar(unk_0004, unk_0005, idx);
                        SetCursor(unk_0004 + 1);
                    }
                    unk_0098->SetPos(i * 16 + 0x18, j * 16 + 0x40);
                    unk_0098->unk_14 = 1;
                    m_audioEngine->PlaySe(0xFA);
                }
            }
        }
        if (PointInRect(touch, unk_00CC[62]->m_rectangle, 0)) {
            DeleteChar();
            unk_00A0->SetPos(0xE0, 0x70);
            unk_00A0->unk_14 = 1;
            m_audioEngine->PlaySe(0xFE);
        }
        if (PointInRect(touch, unk_00CC[63]->m_rectangle, 0)) {
            SetPage(0);
            m_audioEngine->PlaySe(0xFA);
        }
        if (PointInRect(touch, unk_00CC[64]->m_rectangle, 0)) {
            SetPage(1);
            m_audioEngine->PlaySe(0xFA);
        }
        if (PointInRect(touch, unk_00CC[66]->m_rectangle, 0)) {
            SetPage(3);
            m_audioEngine->PlaySe(0xFA);
        }
        if (PointInRect(touch, unk_00CC[67]->m_rectangle, 0)) {
            if (!UseDefaultNameIfEmpty()) {
                unk_0006 = 1;
            }
            unk_00BC[1]->SetAnim(unk_001C, 2);
            m_audioEngine->PlaySe(0xFF);
        }
    }
    if (tp->unk_06 != 0) {
        unk_0098->unk_14 = 0;
        unk_00A0->unk_14 = 0;
        unk_00BC[1]->SetAnim(unk_001C, 1);
        if (unk_0006 == 1) {
            char *name = unk_0068;
            SaveData *save = &MAIN_BSS_020B26A0;
            int i;
            for (i = 0; i < 30; i++) {
                (&save->m_playerName)[i] = 0;
            }
            for (i = 0; i < 30 && name[i] != 0; i++) {
                (&save->m_playerName)[i] = name[i];
            }
            unk_0006 = 0;
            s_game->m_mainFade->Start(4, 5);
            s_game->m_subFade->Start(4, 5);
            unk_0010 = 5;
            unk_0014 = 3;
        }
    }
    if (unk_0007 == 12) {
        unk_0007 = 0;
        unk_0008 ^= 1;
        unk_0090->unk_14 = unk_0008 ? 1 : 0;
    } else {
        unk_0007++;
    }
}

void CNameInputScene::UpdateConfirm()
{
    u32 result;
    TextboxManager *textbox = m_game->m_textboxData;
    if (textbox->CloseIfNoPrompt(1)) {
        return;
    }
    result = textbox->GetYesNoResult();
    if (result == 0) {
        textbox->CloseAndClear(1, 1);
        s_game->m_mainFade->Start(2, 20);
        s_game->m_subFade->Start(2, 20);
        unk_0010 = 6;
    }
    if (result == 1) {
        s_game->m_mainFade->Start(4, 5);
        s_game->m_subFade->Start(4, 5);
        textbox->CloseAndClear(1, 1);
        unk_0010 = 5;
        unk_0014 = 2;
    }
}

void CNameInputScene::StartMode()
{
    s_game->m_mainFade->Start(3, 5);
    s_game->m_subFade->Start(3, 5);
    unk_0010 = unk_0014;
}

void CNameInputScene::SwitchMode()
{
    if (unk_0014 == 2) {
        func7();
        GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
        m_game->m_textboxData->Init(m_game->unk_0014, m_game->touchPanel, &m_game->unk_14AC->unk_0C, m_game->m_nameTables, m_game->unk_0024, m_game->m_audioEngine, 0x10, 0x4000, 0);
        LoadBG();
        LoadMessages();
        SetupWindows();
        LoadSprites(0);
        CreateKeyRects();
        unk_0098->unk_14 = 0;
        unk_00A0->unk_14 = 0;
        DrawName();
        SetCursor(unk_0004);
        SetPage(0);
    }
    if (unk_0014 == 3) {
        ReleaseSprites();
        ShowConfirm();
        LoadBG();
        LoadSprites(1);
    }
    unk_0010 = 4;
}

void CNameInputScene::func1()
{
    switch (unk_0010) {
    case 0:
    case 2:
        unk_00BC[0]->WriteOam();
        unk_00BC[1]->WriteOam();
        break;
    case 3:
        unk_00BC[2]->WriteOam();
        unk_00BC[3]->WriteOam();
        break;
    }
}

void CNameInputScene::func2()
{
}

void CNameInputScene::func5()
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

    GX_SetBankForTex(GX_VRAM_TEX_0_C);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_0_G);
    GX_SetBankForOBJ(GX_VRAM_OBJ_256_AB);
    GX_SetBankForBG(GX_VRAM_BG_128_D);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_32_H);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);

    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG1);
    G2_SetBG0Priority(0);
    G2_SetBG1Priority(1);
    G2_SetBG2Priority(2);
    G2_SetBG3Priority(3);
    GX_DispOn();
    GXS_DispOn();
}

void CNameInputScene::SetupWindows()
{
    NameWindow windows[9] = {
        { 24, 10, 2, 7, 2, 3, 1, 6, 6 },
        { 2, 2, 27, 7, 4, 4, 1, 1, 6 },
        { 2, 2, 27, 9, 4, 4, 1, 1, 6 },
        { 7, 2, 7, 17, 4, 4, 7, 1, 6 },
        { 7, 2, 14, 17, 4, 4, 7, 1, 6 },
        { 5, 2, 21, 17, 8, 4, 7, 1, 6 },
        { 2, 2, 29, 17, 4, 4, 7, 1, 6 },
        { 4, 2, 14, 21, 0, 3, 3, 1, 6 },
        { 10, 2, 11, 2, 8, 4, 1, 1, 6 },
    };
    int ofs;
    int i;
    TextPrinter *text = m_game->unk_1494;
    text->FreeWindows();
    text->SetupBG(0, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x00000);
    text->AllocWindows(9);
    ofs = 0x40;
    for (i = 0; i < 9; i++) {
        text->InitWindow(i, windows[i].width, windows[i].height, windows[i].left, windows[i].top, ofs, windows[i].hSpace, windows[i].vSpace);
        ofs += windows[i].width * windows[i].height;
    }
    text->Print(3, windows[3].x, windows[3].y, windows[3].color, unk_01DC->unk_08[1].unk_04, FALSE, 0);
    text->Print(4, windows[4].x, windows[4].y, windows[4].color, unk_01DC->unk_08[2].unk_04, FALSE, 0);
    text->Print(5, windows[5].x, windows[5].y, windows[5].color, unk_01DC->unk_08[4].unk_04, FALSE, 0);
    text->Print(7, windows[7].x, windows[7].y, windows[7].color, unk_01DC->unk_08[5].unk_04, TRUE, 0);
}

void CNameInputScene::ShowConfirm()
{
    int i;
    TextPrinter *text = m_game->unk_1494;
    for (i = 0; i < 9; i++) {
        text->ClearWindow(i);
    }
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    m_game->m_textboxData->Init(m_game->unk_0014, m_game->touchPanel, &m_game->unk_14AC->unk_0C, m_game->m_nameTables, m_game->unk_0024, m_game->m_audioEngine, 0x10, 0x4000, 0);
    m_game->m_textboxData->LoadSystemMessages(2);
    m_game->m_textboxData->SetTextSpeed(0);
    m_game->m_textboxData->ShowSystemMessage(5, 1, 1, 0);
}

void CNameInputScene::func6()
{
    unk_000C = 0;
    unk_0010 = 0;
    m_game->m_textboxData->Init(m_game->unk_0014, m_game->touchPanel, &m_game->unk_14AC->unk_0C, m_game->m_nameTables, m_game->unk_0024, m_game->m_audioEngine, 0x10, 0x4000, 0);
    LoadBG();
    LoadMessages();
    SetupWindows();
    LoadSprites(0);
    CreateKeyRects();
    unk_0098->unk_14 = 0;
    unk_00A0->unk_14 = 0;
    s_game->m_mainFade->Start(1, 30);
    s_game->m_subFade->Start(1, 30);
    SetPage(unk_0005);
}

void CNameInputScene::LoadBG()
{
    CArchiveGuard *archive = new CArchiveGuard("BGU", "data/menu/mnd000_bg_LZ.bin", 1, 1, 0, NULL, 0);
    CBGNCGRFile *ncgr = new CBGNCGRFile("BGU:mnd000.NCGR", 1, 0, 0);
    CNCLRFile *nclr = new CNCLRFile("BGU:mnd000.NCLR", 1, 0, 0);
    CNSCRFile *nscr = new CNSCRFile("BGU:mnd000_00.NSCR", 1, 0, 0);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB1, nscr->unk_B8, ncgr->unk_B8, nclr->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x00000);
    delete nscr;
    delete ncgr;
    delete nclr;
    delete archive;

    archive = new CArchiveGuard("BGD", "data/menu/mni000_bg_LZ.bin", 1, 1, 0, NULL, 0);
    ncgr = new CBGNCGRFile("BGD:mni000.NCGR", 1, 0, 0);
    nclr = new CNCLRFile("BGD:mni000.NCLR", 1, 0, 0);
    CNSCRFile *nscr1 = new CNSCRFile("BGD:mni000_01.NSCR", 1, 0, 0);
    CNSCRFile *nscr2 = new CNSCRFile("BGD:mni000_02.NSCR", 1, 0, 0);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_MAIN2, nscr1->unk_B8, ncgr->unk_B8, nclr->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x7000, GX_BG_CHARBASE_0x04000);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_MAIN3, nscr2->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7800, GX_BG_CHARBASE_0x04000);
    delete nscr1;
    delete nscr2;
    delete ncgr;
    delete nclr;
    delete archive;
}

void CNameInputScene::LoadMessages()
{
    u32 pos;
    LOAD_MESSAGES(unk_01DC, "/data/message/etc/name_entry");
}

void CNameInputScene::LoadSprites(int mode)
{
    if (mode == 0) {
        LoadInputSprites();
    }
    if (mode == 1) {
        LoadConfirmSprites();
    }
}

void CNameInputScene::LoadInputSprites()
{
    char name[0x60];
    int ofs = 0;
    OS_SPrintf(name, "tp%03d", MAIN_BSS_020B26A0.m_sex);
    unk_00BC[0] = new OamSpriteSet((GXOamAttr *)&m_game->unk_0024[8], m_game->unk_14A8, FALSE, 0x40);
    ofs += unk_00BC[0]->Load("data/menu", name, 0, 4);
    unk_008C = unk_00BC[0]->AddSprite(0, 0x4A, 0x20, 0);
    unk_0018 = unk_00BC[0]->unk_24;
    unk_00BC[1] = new OamSpriteSet((GXOamAttr *)&m_game->unk_0024[0x10], m_game->unk_14A8, FALSE, 0x40);
    unk_00BC[1]->Load("data/menu", "mni000_00", ofs / 32, 5);
    unk_0090 = unk_00BC[1]->AddSprite(0, 0x5E, 0x20, 0);
    unk_0094 = unk_00BC[1]->AddSprite(1, 0x80, 0xB0, 1);
    unk_001C = unk_00BC[1]->unk_24;
    unk_0098 = unk_00BC[1]->AddSprite(3, 0, 0, 1);
    unk_00A0 = unk_00BC[1]->AddSprite(5, 0, 0, 1);
    unk_00A4 = unk_00BC[1]->AddSprite(6, 0x48, 0x90, 1);
    unk_0020 = unk_00BC[1]->unk_24;
    unk_00A8 = unk_00BC[1]->AddSprite(7, 0x80, 0x90, 1);
    unk_0024 = unk_00BC[1]->unk_24;
    unk_00B0 = unk_00BC[1]->AddSprite(7, 0xB8, 0x90, 1);
    unk_002C = unk_00BC[1]->unk_24;
    unk_0090->unk_14 = 0;
}

void CNameInputScene::LoadConfirmSprites()
{
    char name[0x60];
    int ofs = 0;
    unk_00BC[2] = new OamSpriteSet((GXOamAttr *)&m_game->unk_0024[0x20], m_game->unk_14A8, FALSE, 0x40);
    ofs += unk_00BC[2]->Load("data/menu", "mps000_00", 0, 4);
    unk_00B4 = unk_00BC[2]->AddSprite(0, 0x80, 0x48, 1);
    OS_SPrintf(name, "mp%03d_00", (u8)(MAIN_BSS_020B26A0.m_sex + 3));
    unk_00BC[3] = new OamSpriteSet((GXOamAttr *)&m_game->unk_0024[0x40], m_game->unk_14A8, FALSE, 0x40);
    unk_00BC[3]->Load("data/menu", name, ofs / 32, 6);
    unk_00B8 = unk_00BC[3]->AddSprite(1, 0x80, 0x48, 0);
}

void CNameInputScene::CreateKeyRects()
{
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 5; j++) {
            int idx = i * 5 + j;
            unk_00CC[idx] = new CPrimitiveRECT();
            unk_00CC[idx]->SetPos((i * 16 - 0x68) << FX32_SHIFT, (j * 16 - 0x20) << FX32_SHIFT);
            unk_00CC[idx]->SetSize(0x10000, 0x10000);
        }
    }
    SET_KEY_RECT(60, 0x60000, -0x20000, 0x20000, 0x10000);
    SET_KEY_RECT(61, 0x60000, -0x10000, 0x20000, 0x10000);
    SET_KEY_RECT(62, 0x60000, 0x10000, 0x20000, 0x30000);
    SET_KEY_RECT(63, -0x38000, 0x30000, 0x40000, 0x10000);
    SET_KEY_RECT(64, 0, 0x30000, 0x40000, 0x10000);
    SET_KEY_RECT(65, 0x38000, 0x30000, 0x40000, 0x10000);
    SET_KEY_RECT(66, 0x38000, 0x30000, 0x40000, 0x10000);
    SET_KEY_RECT(67, 0, 0x50000, 0x60000, 0x20000);
}

void CNameInputScene::func7()
{
    m_game->m_textboxData->CloseAndClear(1, 1);
    m_game->m_textboxData->Reset();
    for (int i = 0; i < 0x44; i++) {
        SAFE_DELETE(unk_00CC[i]);
    }
    RELEASE_MESSAGES(unk_01DC);
    for (int i = 0; i < 0x44; i++) {
        SAFE_DELETE(unk_00CC[i]);
    }
    for (int i = 0; i < 4; i++) {
        SAFE_DELETE(unk_00BC[i]);
    }
}

void CNameInputScene::ReleaseSprites()
{
    for (int i = 0; i < 4; i++) {
        SAFE_DELETE(unk_00BC[i]);
    }
}

u16 CNameInputScene::GetNameLength()
{
    u16 len = 0;
    for (int i = 0; i < 7 && unk_004C[i] != 0; i++) {
        int c = unk_004C[i];
        int n = 4;
        for (int j = 0; j < 4; j++) {
            if ((c >> ((3 - j) * 8)) & 0xFF) {
                break;
            }
            n--;
        }
        len += (u16)n;
    }
    return len;
}

void CNameInputScene::PrintChar(int idx, int x, int y, int color, int c)
{
    char buf[8];
    int n = 4;
    for (int i = 0; i < 4 && !((c >> ((3 - i) * 8)) & 0xFF); i++) {
        n--;
    }
    for (int i = 0; i < n; i++) {
        buf[i] = c >> ((n - i - 1) * 8);
    }
    for (; n < 7; n++) {
        buf[n] = 0;
    }
    int width = NNS_G2dFontGetTextWidth(&m_game->unk_14AC->unk_0C, 0, buf);
    m_game->unk_1494->Print(idx, x + 5 - ((width & 1) + (width >> 1)), y, color, (u8 *)buf, FALSE, 0);
}

void CNameInputScene::DrawName()
{
    m_game->unk_1494->ClearWindow(8);
    int i;
    int x;
    for (i = 0, x = 2; i < 7 && unk_004C[i] != 0; i++) {
        PrintChar(8, x, 4, 1, unk_004C[i]);
        x += 11;
    }
}

u32 CNameInputScene::getSceneId()
{
    return 20;
}
