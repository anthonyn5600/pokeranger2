#include <nitro.h>
#include <nnsys.h>

#include "CGame.hpp"
#include "DiskHPTable.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "SaveData.hpp"
#include "SubTextPrinter.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CNCLRFile.hpp"
#include "file/CNSCRFile.hpp"
#include "scene/CStylerScreens.hpp"

struct TextWindow {
    int width;
    int height;
    int left;
    int top;
    int x;
    int y;
    int msg;
    int color;
};

CStylerUpperScreen::CStylerUpperScreen(CGame *game, CStylerData *data)
{
    unk_0C = 0;
    m_level = 0;
    m_energy = 0;
    m_maxEnergy = 0;
    unk_1C = 0;
    unk_20 = 0;
    unk_24 = 0;
    unk_28 = 0;
    unk_2C = 0;
    unk_30 = 0;
    unk_34 = 0;
    m_sprites = NULL;
    m_arrowSprites = NULL;
    m_game = game;
    m_data = data;
    m_menuMessages = data->m_menuMessages;
    for (int i = 0; i < 6; i++) {
        m_objs[i] = NULL;
    }
}

CStylerUpperScreen::~CStylerUpperScreen()
{
    Release();
}

void CStylerUpperScreen::Load()
{
    LoadStatus();
    SetupBlend();
    LoadSprites();
    LoadBG();
    DrawTexts();
    DrawGauge();
}

void CStylerUpperScreen::Release()
{
    SAFE_DELETE(m_sprites);
    SAFE_DELETE(m_arrowSprites);
}

void CStylerUpperScreen::LoadStatus()
{
    SaveData *save = (SaveData *)(void *)&MAIN_BSS_020B26A0;
    m_level = save->m_stylerLevel;
    m_energy = save->m_levelExp;
    m_maxEnergy = sub_02010EAC(m_game->unk_1438, m_level);
    unk_1C = save->m_maxEnergy;
    unk_20 = save->m_energy;
    unk_24 = m_data->m_powerLevels[22];
    int bonus[4] = { 0, 3, 5, 7 };
    int idx = m_data->m_powerLevels[23];
    u16 power = sub_02010E90(m_game->unk_1438, m_level);
    unk_28 = power + bonus[idx];
    unk_30 = m_data->m_powerLevels[24];
    unk_34 = m_data->m_powerLevels[25];
}

void CStylerUpperScreen::SetupBlend()
{
    GXS_SetVisiblePlane(GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    G2S_SetBG0Priority(0);
    G2S_SetBG1Priority(1);
    G2S_SetBG2Priority(2);
    G2S_SetBG3Priority(3);
    G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_BG1, GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ, 8, 8);
}

void CStylerUpperScreen::LoadSprites()
{
    int charNo = 0x20;
    m_sprites = new OamSpriteSet((GXOamAttr *)m_game->unk_0424, m_game->unk_14A8, TRUE, 0x40);
    charNo += m_sprites->Load("data/menu", "ms000_00", charNo / 32, 0);
    m_arrowSprites = new OamSpriteSet((GXOamAttr *)&m_game->unk_0424[0x5A], m_game->unk_14A8, TRUE, 0x40);
    m_arrowSprites->Load("data/menu", "ma004_00", charNo / 32, 3);

    for (int i = 0; i < 6; i++) {
        m_objs[i] = NULL;
    }

    if (m_data->m_raised[21]) {
        m_objs[1] = m_sprites->AddSprite(0x15, 0xEC, 0x58, 1);
    }
    if (m_data->m_raised[22]) {
        m_objs[2] = m_sprites->AddSprite(0x15, 0xEC, 0x70, 1);
    }
    if (m_data->m_raised[23]) {
        m_objs[3] = m_sprites->AddSprite(0x15, 0xEC, 0x88, 1);
    }
    if (m_data->m_raised[24]) {
        m_objs[4] = m_sprites->AddSprite(0x15, 0xEC, 0x98, 1);
    }
    if (m_data->m_raised[25]) {
        m_objs[5] = m_sprites->AddSprite(0x15, 0xEC, 0xA8, 1);
    }

    m_sprites->AddSprite(m_level / 10, 0x48, 0x38, 1);
    m_sprites->AddSprite(m_level % 10, 0x58, 0x38, 1);
    m_sprites->AddSprite(0x18, 0x80, 0x43, 1);

    if (unk_1C < 100) {
        if (unk_20 >= 10) {
            m_sprites->AddSprite(unk_20 / 10, 0xA0, 0x58, 1);
        }
        m_sprites->AddSprite(unk_20 % 10, 0xB0, 0x58, 1);
        m_sprites->AddSprite(10, 0xC0, 0x58, 1);
        m_sprites->AddSprite(unk_1C / 10, 0xD0, 0x58, 1);
        m_sprites->AddSprite(unk_1C % 10, 0xE0, 0x58, 1);
        m_sprites->AddSprite(0x19, 0x80, 0x50, 1);
        m_slots[0] = m_sprites->unk_24;
    } else {
        if (unk_20 >= 100) {
            m_sprites->AddSprite(unk_20 / 100, 0x80, 0x58, 1);
        }
        if (unk_20 >= 10) {
            m_sprites->AddSprite(unk_20 / 10 % 10, 0x90, 0x58, 1);
        }
        m_sprites->AddSprite(unk_20 % 10, 0xA0, 0x58, 1);
        m_sprites->AddSprite(10, 0xB0, 0x58, 1);
        m_sprites->AddSprite(unk_1C / 100, 0xC0, 0x58, 1);
        m_sprites->AddSprite(unk_1C / 10 % 10, 0xD0, 0x58, 1);
        m_sprites->AddSprite(unk_1C % 10, 0xE0, 0x58, 1);
        m_sprites->AddSprite(0x19, 0x80, 0x50, 1);
        m_slots[0] = m_sprites->unk_24;
    }

    m_sprites->AddSprite(0x1F, unk_24 * 0x18 + 0xB0, 0x70, 1);
    m_sprites->AddSprite(0x1D, 0x80, 0x68, 1);
    if (unk_24 > 0) {
        m_sprites->AddSprite(0x1E, 0xB7, 0x70, 1);
    }
    if (unk_24 > 1) {
        m_sprites->AddSprite(0x1E, 0xCF, 0x70, 1);
    }
    m_sprites->AddSprite(0x1C, 0x80, 0x68, 1);
    m_slots[1] = m_sprites->unk_24;

    if (unk_28 >= 100) {
        m_sprites->AddSprite(unk_28 / 100, 0xC0, 0x88, 1);
    }
    m_sprites->AddSprite(unk_28 / 10 % 10, 0xD0, 0x88, 1);
    m_sprites->AddSprite(unk_28 % 10, 0xE0, 0x88, 1);
    m_sprites->AddSprite(0x1A, 0x80, 0x80, 1);
    m_slots[2] = m_sprites->unk_24;

    if (unk_30 != 0) {
        m_sprites->AddSprite(0x20, 0xD8, 0x98, 1);
        m_sprites->AddSprite(unk_30 + 0xB, 0xDF, 0x99, 1);
        m_sprites->AddSprite(0x1B, 0xAC, 0x98, 1);
        m_slots[3] = m_sprites->unk_24;
    }
    if (unk_34 != 0) {
        m_sprites->AddSprite(0x20, 0xD8, 0xA8, 1);
        m_sprites->AddSprite(unk_34 + 0xB, 0xDF, 0xA9, 1);
        m_sprites->AddSprite(0x1B, 0xAC, 0xA8, 1);
        m_slots[4] = m_sprites->unk_24;
    }

    m_objs[0] = m_arrowSprites->AddSprite(0, 0x80, -8, 3);
}

void CStylerUpperScreen::LoadBG()
{
    CArchiveGuard *archive = new CArchiveGuard("BGS", "data/menu/ms000_bg_LZ.bin", 1, 1, 0, NULL, 0);
    CBGNCGRFile *ncgrFile = new CBGNCGRFile("BGS:ms000.NCGR", 1, 0, 0);
    CNCLRFile *nclrFile = new CNCLRFile("BGS:ms000.NCLR", 1, 0, 0);
    CNSCRFile *nscrFile1 = new CNSCRFile("BGS:ms000_00.NSCR", 1, 0, 0);
    CNSCRFile *nscrFile2 = new CNSCRFile("BGS:ms000_01.NSCR", 1, 0, 0);
    CNSCRFile *nscrFile3 = new CNSCRFile("BGS:ms000_02.NSCR", 1, 0, 0);

    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB1, nscrFile1->unk_B8, ncgrFile->unk_B8, nclrFile->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x00000);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB2, nscrFile2->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7000, GX_BG_CHARBASE_0x00000);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB3, nscrFile3->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x5800, GX_BG_CHARBASE_0x00000);

    SAFE_DELETE(nscrFile1);
    SAFE_DELETE(nscrFile2);
    SAFE_DELETE(nscrFile3);
    SAFE_DELETE(ncgrFile);
    SAFE_DELETE(nclrFile);
    SAFE_DELETE(archive);
}

void CStylerUpperScreen::DrawTexts()
{
    int charNo;
    int i;
    SubTextPrinter *printer;
    printer = m_game->unk_1498;
    TextWindow windows[8] = {
        { 16, 2, 8, 1, 0, 0, 40, 1 },
        { 6, 2, 2, 6, 2, 4, 41, 3 },
        { 14, 2, 14, 6, 52, 4, 30, 3 },
        { 8, 2, 4, 10, 2, 4, 42, 3 },
        { 8, 2, 4, 13, 2, 4, 43, 3 },
        { 8, 2, 4, 16, 2, 4, 44, 3 },
        { 16, 2, 12, 18, 2, 4, 45, 5 },
        { 16, 2, 12, 20, 2, 4, 46, 5 },
    };

    printer->FreeWindows();
    printer->SetupBG();
    printer->AllocWindows(8);

    charNo = 0x60;
    for (i = 0; i < 8; i++) {
        printer->InitWindow(i, windows[i].width, windows[i].height, windows[i].left, windows[i].top, charNo, 0, 2);
        charNo += windows[i].width * windows[i].height;
    }

    for (i = 0; i < 8; i++) {
        if (i == 2) {
            continue;
        }
        if (i == 6 && unk_30 == 0) {
            continue;
        }
        if (i == 7 && unk_34 == 0) {
            continue;
        }
        printer->Print(i, windows[i].x, windows[i].y, windows[i].color, m_menuMessages->unk_08[windows[i].msg].unk_04, TRUE, 0);
    }

    if (m_maxEnergy == 0) {
        return;
    }

    printer->Print(2, windows[2].x, windows[2].y, windows[2].color, m_menuMessages->unk_08[30].unk_04, FALSE, 0);
    printer->Print(2, 2, windows[2].y, windows[2].color, m_menuMessages->unk_08[m_energy / 10000 + 8].unk_04, FALSE, 0);
    printer->Print(2, 12, windows[2].y, windows[2].color, m_menuMessages->unk_08[m_energy / 1000 % 10 + 8].unk_04, FALSE, 0);
    printer->Print(2, 22, windows[2].y, windows[2].color, m_menuMessages->unk_08[m_energy / 100 % 10 + 8].unk_04, FALSE, 0);
    printer->Print(2, 32, windows[2].y, windows[2].color, m_menuMessages->unk_08[m_energy / 10 % 10 + 8].unk_04, FALSE, 0);
    printer->Print(2, 42, windows[2].y, windows[2].color, m_menuMessages->unk_08[m_energy % 10 + 8].unk_04, FALSE, 0);
    printer->Print(2, 62, windows[2].y, windows[2].color, m_menuMessages->unk_08[m_maxEnergy / 10000 + 8].unk_04, FALSE, 0);
    printer->Print(2, 72, windows[2].y, windows[2].color, m_menuMessages->unk_08[m_maxEnergy / 1000 % 10 + 8].unk_04, FALSE, 0);
    printer->Print(2, 82, windows[2].y, windows[2].color, m_menuMessages->unk_08[m_maxEnergy / 100 % 10 + 8].unk_04, FALSE, 0);
    printer->Print(2, 92, windows[2].y, windows[2].color, m_menuMessages->unk_08[m_maxEnergy / 10 % 10 + 8].unk_04, FALSE, 0);
    printer->Print(2, 102, windows[2].y, windows[2].color, m_menuMessages->unk_08[m_maxEnergy % 10 + 8].unk_04, FALSE, 0);
}

void CStylerUpperScreen::DrawGauge()
{
    int rate = (m_energy << 7) / m_maxEnergy;
    int full = rate / 8;
    int rest = rate % 8;
    int i;

    if (m_maxEnergy != 0) {
        for (i = 0; i < full; i++) {
            MI_CpuCopy16((u8 *)G2S_GetBG2ScrPtr() + 0x610, (u8 *)G2S_GetBG0ScrPtr() + ((i + 13) * 2 + 0x200), 2);
        }
        MI_CpuCopy16((u8 *)G2S_GetBG2ScrPtr() + (rest * 2 + 0x600), (u8 *)G2S_GetBG0ScrPtr() + ((i + 13) * 2 + 0x200), 2);
    } else {
        for (i = 0; i < 16; i++) {
            MI_CpuCopy16((u8 *)G2S_GetBG2ScrPtr() + 0x610, (u8 *)G2S_GetBG0ScrPtr() + ((i + 13) * 2 + 0x200), 2);
        }
    }
}

int CStylerUpperScreen::Update()
{
    UpdateSprites();
    return 0;
}

void CStylerUpperScreen::UpdateSprites()
{
    m_objs[0]->SetPos(m_objs[0]->unk_0C, m_game->unk_15D0 >> FX32_SHIFT);

    unk_08++;

    int anims[5][2] = {
        { 25, 34 },
        { 28, 35 },
        { 26, 36 },
        { 27, 37 },
        { 27, 37 },
    };
    int blink = (unk_08 >> 3) & 1;
    int dy;

    switch (unk_08 / 8 % 3) {
    case 0:
    case 1:
        if (unk_08 % 8 == 0) {
            dy = -1;
        } else {
            dy = 0;
        }
        break;
    case 2:
        if (unk_08 % 8 == 0) {
            dy = 2;
        } else {
            dy = 0;
        }
        break;
    }

    for (int i = 0; i < 5; i++) {
        if (m_objs[i + 1] != NULL) {
            if (blink) {
                m_sprites->SetAnim(m_slots[i], anims[i][0]);
            } else {
                m_sprites->SetAnim(m_slots[i], anims[i][1]);
            }
            m_objs[i + 1]->SetPos(m_objs[i + 1]->unk_0C, m_objs[i + 1]->unk_0E + dy);
        }
    }

    m_sprites->Update();
    m_arrowSprites->Update();
}

void CStylerUpperScreen::Render()
{
    m_sprites->WriteOam();
    m_arrowSprites->WriteOam();
}

void CStylerUpperScreen::func7()
{
}

void CStylerUpperScreen::func8()
{
}

void CStylerUpperScreen::Reset()
{
}
