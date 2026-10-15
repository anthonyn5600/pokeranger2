#include "AudioEngine.hpp"
#include "BGLayer.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "FontSet.hpp"
#include "OamSpriteSet.hpp"
#include "SubTextPrinter.hpp"
#include "file/CBinaryFileMes.hpp"
#include "scene/CEncyclopediaScene.hpp"

int GetTextLineWidth(NNSG2dFont *font, int hSpace, u8 **str);

static const struct {
    int unk_00;
    const char *path;
} sMenuMes = { 1, "data/message/etc/menu_mes" };

CEncycItemDescriptionScreen::CEncycItemDescriptionScreen(EncycPushButton *backButton)
    : unk_0C(0)
    , unk_10(0)
    , unk_14(0)
    , unk_18(NULL)
    , unk_1C(NULL)
    , unk_60(backButton)
    , unk_64(NULL)
    , unk_C8(0)
    , unk_CC(NULL)
{
}

void CEncycItemDescriptionScreen::func0(EncycAnimLoader *loader)
{
    BGS_LoadCharAndPltt("menu/", "md001_bg_", 5, "md001", 0x200, "md001", 1);
    MI_CpuCopy8((void *)(HW_DB_BG_PLTT + 0x20), unk_68, sizeof(unk_68));
    BGS_LoadScr("menu/", "md001_bg_", 5, "md001_01", 1, 0, 0, 0x800);
    BGS_LoadScr("menu/", "md001_bg_", 6, "md001_02", 1, 0, 0, 0x800);
    BGS_LoadScr("menu/", "md001_bg_", 7, "md001_03", 1, 0, 0, 0x800);
    unk_18 = loader->Load("data/menu", "md001_00", 1, -1);
    unk_20[1].Init(1, unk_18, 0, 1, 240, 116, 32, 24, 0);
    unk_20[1].SetListener(this);
    unk_20[0].Init(0, unk_18, 2, 3, 16, 116, 32, 24, 0);
    unk_20[0].SetListener(this);
    loader->ReserveOam(unk_18, 0);
    LoadMessages();
}

void CEncycItemDescriptionScreen::LoadMessages()
{
    CBinaryFileMes mes(sMenuMes.path, 1);
    unk_CC = new UnkStruct_0211E4AC;
    if (unk_CC != NULL && mes.unk_4C != NULL) {
        void *data = mes.unk_4C;
        int idx = 2;
        unk_CC->unk_00 = ((u32 *)data)[0];
        unk_CC->unk_04 = ((u32 *)data)[1];
        unk_CC->unk_08 = new UnkStruct_0211E4AC_Entry[unk_CC->unk_04];
        for (u32 i = 0; i < unk_CC->unk_04; i++) {
            unk_CC->unk_08[i].unk_00 = ((u32 *)data)[idx++];
            unk_CC->unk_08[i].unk_04 = new u8[unk_CC->unk_08[i].unk_00];
            MI_CpuCopy8(&((u32 *)data)[idx], unk_CC->unk_08[i].unk_04, unk_CC->unk_08[i].unk_00);
            idx += unk_CC->unk_08[i].unk_00 >> 2;
        }
    }
}

void CEncycItemDescriptionScreen::func1()
{
    if (unk_CC != NULL) {
        for (u32 i = 0; i < unk_CC->unk_04; i++) {
            SAFE_DELETE_ARRAY(unk_CC->unk_08[i].unk_04);
        }
        SAFE_DELETE_ARRAY(unk_CC->unk_08);
        SAFE_DELETE(unk_CC);
    }
    SAFE_DELETE(unk_18);
}

void CEncycItemDescriptionScreen::SetGroup(int group)
{
    if (group < 0 || group >= 3) {
        group = 0;
    }
    unk_C8 = group;
}

void CEncycItemDescriptionScreen::func2()
{
    G2S_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x0800, GX_BG_CHARBASE_0x08000, GX_BG_EXTPLTT_01);
    G2S_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x1800, GX_BG_CHARBASE_0x08000);
    G2S_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x2800, GX_BG_CHARBASE_0x08000);
    G2S_SetBG0Priority(0);
    G2S_SetBG1Priority(1);
    G2S_SetBG2Priority(2);
    G2S_SetBG3Priority(3);
    GXS_SetVisibleWnd(GX_WNDMASK_NONE);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
    NNS_GfdRegisterNewVramTransferTask(NNS_GFD_DST_2D_BG_PLTT_SUB, 0x20, unk_68[unk_C8], 0x20);
}

void CEncycItemDescriptionScreen::func3(EncycMainScreen *display)
{
    unk_1C = display;
    SubTextPrinter *text = CGame::GetInstance()->unk_1498;
    text->FreeWindows();
    text->AllocWindows(1);
    text->InitWindow(0, 32, 32, 0, 0, 0, 0, 2);
    unk_10 = 0;
    LoadPicture(unk_10);
    DrawPage(unk_10);
    unk_60->ResetInput();
    unk_04 = 0;
}

int CEncycItemDescriptionScreen::func4()
{
    CGame *game = CGame::GetInstance();
    int ret = 1;
    switch (unk_04) {
    case 0:
        if (!game->m_mainFade->IsActive() && !game->m_subFade->IsActive()) {
            unk_04 = 1;
            unk_0C = 0;
        }
        break;
    case 1:
        switch (unk_0C) {
        case 1:
            if (!game->m_mainFade->IsActive() && !game->m_subFade->IsActive()) {
                LoadPicture(unk_10);
                unk_0C = 2;
                game->m_mainFade->Start(3, 15);
            }
            break;
        case 2:
            if (!game->m_mainFade->IsActive() && !game->m_subFade->IsActive()) {
                unk_0C = 0;
            }
            break;
        }
        unk_20[1].unk_14 = game->unk_0014->unk_0000 & PAD_KEY_RIGHT;
        unk_20[0].unk_14 = game->unk_0014->unk_0000 & PAD_KEY_LEFT;
        for (int i = 0; i <= 1; i++) {
            unk_20[i].Update();
        }
        if (unk_14) {
            game->m_mainFade->Start(4, 15);
            unk_0C = 1;
            unk_14 = FALSE;
        }
        if (unk_18 != NULL) {
            unk_18->Update();
        }
        unk_60->Update();
        unk_60->UpdateAnim();
        if ((u16)(game->unk_0014->unk_0002 & PAD_BUTTON_B)) {
            func6();
        }
        break;
    case 2:
        if (!game->m_mainFade->IsActive() && !game->m_subFade->IsActive()) {
            ret = 0;
        }
        break;
    }
    for (int i = 0; i <= 1; i++) {
        unk_20[i].UpdateAnim();
    }
    return ret;
}

void CEncycItemDescriptionScreen::func5()
{
    if (unk_18 != NULL) {
        unk_18->WriteOam();
    }
    if (unk_1C != NULL) {
        unk_1C->Render();
    }
}

void CEncycItemDescriptionScreen::func6()
{
    CGame *game = CGame::GetInstance();
    unk_04 = 2;
    unk_0C = 0;
    game->m_audioEngine->PlaySe(0x103);
    game->m_mainFade->Start(4, 15);
    game->m_subFade->Start(4, 15);
}

void CEncycItemDescriptionScreen::DrawPage(int page)
{
    FontSet *font;
    u8 *str;
    SubTextPrinter *text;
    unk_20[0].SetVisible(unk_10 > 0 ? TRUE : FALSE);
    BOOL next = unk_64 != NULL ? TRUE : FALSE;
    if (next) {
        next = unk_10 < unk_64->GetPageCount() - 1 ? TRUE : FALSE;
    }
    unk_20[1].SetVisible(next);
    text = CGame::GetInstance()->unk_1498;
    text->ClearWindow(0);
    if (unk_64 == NULL) {
        return;
    }
    text->Print(0, 0, 11, 1, unk_64->GetName(), TRUE, 0);
    text->Print(0, 48, 51, 3, (u8 *)unk_64->GetDescription(page), FALSE, 0);
    if (unk_CC == NULL) {
        return;
    }
    font = CGame::GetInstance()->unk_14AC;
    str = unk_CC->unk_08[page + 9].unk_04;
    u8 *tmp = str;
    text->Print(0, (10 - GetTextLineWidth(&font->unk_14, 1, &tmp)) / 2 + 221, 180, 1, str, FALSE, 0);
    str = unk_CC->unk_08[30].unk_04;
    tmp = str;
    text->Print(0, (10 - GetTextLineWidth(&font->unk_14, 1, &tmp)) / 2 + 232, 180, 1, str, FALSE, 0);
    str = unk_CC->unk_08[unk_64->GetPageCount() + 8].unk_04;
    tmp = str;
    text->Print(0, (10 - GetTextLineWidth(&font->unk_14, 1, &tmp)) / 2 + 243, 180, 1, str, FALSE, 0);
}

BOOL CEncycItemDescriptionScreen::NextPage()
{
    if (unk_64 != NULL && unk_10 < unk_64->GetPageCount() - 1) {
        int prev = unk_64->GetPicture(unk_10);
        unk_10++;
        DrawPage(unk_10);
        CGame::GetInstance()->m_audioEngine->PlaySe(0xFA);
        return prev != unk_64->GetPicture(unk_10) ? TRUE : FALSE;
    }
    CGame::GetInstance()->m_audioEngine->PlaySe(0xFD);
    return FALSE;
}

BOOL CEncycItemDescriptionScreen::PrevPage()
{
    if (unk_10 > 0) {
        int prev = unk_64->GetPicture(unk_10);
        unk_10--;
        DrawPage(unk_10);
        CGame::GetInstance()->m_audioEngine->PlaySe(0xFA);
        return prev != unk_64->GetPicture(unk_10) ? TRUE : FALSE;
    }
    CGame::GetInstance()->m_audioEngine->PlaySe(0xFD);
    return FALSE;
}

void CEncycItemDescriptionScreen::LoadPicture(int page)
{
    char archive[0x60];
    char file[0x60];
    int i;
    EncycMarker *marker;
    u8 x;
    u8 y;
    int arg;
    int color;
    EncycDictionary *pair;
    int idx;
    int count;
    if (unk_64 == NULL) {
        return;
    }
    int picture = unk_64->GetPicture(page);
    OS_SPrintf(archive, "data/menu/rd%03d_LZ.bin", picture);
    OS_SPrintf(file, "rd%03d.nbfs", picture);
    unk_1C->LoadBitmap(archive, file);
    unk_1C->ClearLabels();
    count = unk_64->GetMarkerCount(page);
    for (i = 0; i < count; i++) {
        marker = unk_64->GetMarker(page, i);
        if (marker != NULL) {
            x = marker->unk_00;
            y = marker->unk_01;
            arg = marker->unk_06;
            switch (marker->unk_02) {
            default:
            case 0:
                color = 3;
                break;
            case 1:
                color = 1;
                break;
            case 2:
                color = 5;
                break;
            }
            pair = unk_64;
            idx = marker->unk_04 + 1;
            if (idx >= pair->unk_0C.GetCount()) {
                idx = pair->unk_0C.GetCount() - 1;
            }
            unk_1C->AddLabel(x, y, color, pair->unk_0C.GetString(idx), arg);
        }
    }
}

void CEncycItemDescriptionScreen::OnPushButton(int id)
{
    switch (id) {
    case 0:
        unk_14 = PrevPage();
        break;
    case 1:
        unk_14 = NextPage();
        break;
    }
}

EncycMarker *EncycDictionary::GetMarker(int page, int idx)
{
    if (unk_18 == NULL) {
        return NULL;
    }
    return unk_18->GetMarker(page, idx);
}

CEncycItemDescriptionScreen::~CEncycItemDescriptionScreen()
{
}
