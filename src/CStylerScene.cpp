#include "scene/CStylerScene.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_02008D50.hpp"
#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_02018DF4.hpp"
#include "UnkClass_0202A2AC.hpp"
#include "UnkClass_02034478.hpp"
#include "UnkClass_020B26A0.hpp"
#include "file/CBinaryFileMes.hpp"
#include "scene/CStylerScreens.hpp"
#include "sub_02007CF0.hpp"

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

CStylerScene::CStylerScene(CGame *game)
{
    m_data = NULL;
    m_upper = NULL;
    m_game = game;
    m_screens[2] = NULL; // out of bounds (one past m_screens; sizeof is 0x24)
}

CStylerScene::~CStylerScene()
{
}

void CStylerScene::func5()
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

    GX_SetBankForBG(GX_VRAM_BG_128_A);
    GX_SetBankForOBJ(GX_VRAM_OBJ_128_B);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);

    G2_SetBG0Offset(0, 0);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);

    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_DispOn();
    GXS_DispOn();
}

void CStylerScene::func6()
{
    m_game->unk_146C.sub_02008DB4(60);

    m_data = new CStylerData(m_game);
    m_data->Init();
    m_screenIdx = m_data->m_level != 0 ? 1 : 0;

    m_upper = new CStylerUpperScreen(m_game, m_data);
    m_upper->Load();

    m_screens[1] = new CStylerPartsScreen(m_game, m_data);
    m_screens[1]->Load();

    if (m_screenIdx == 0) {
        m_screens[0] = new CStylerStatusScreen(m_game, m_data);
        m_screens[0]->Load();
    }

    m_game->unk_14BC->sub_0200E0E0(3, 20);
    m_game->unk_14C0->sub_0200E0E0(3, 20);
}

void CStylerScene::func7()
{
    SAFE_DELETE(m_upper);

    for (int i = 0; i < 2; i++) {
        SAFE_DELETE(m_screens[i]);
    }

    SAFE_DELETE(m_data);
    m_game->unk_146C.sub_02008DB4(30);
}

u32 CStylerScene::func0()
{
    m_upper->Update();

    int result = m_screens[m_screenIdx]->Update();
    if (result == -1) {
        return m_screens[0] != NULL ? 6 : 1;
    }

    if (result == 1) {
        m_screenIdx ^= 1;
        m_screens[m_screenIdx]->Reset();
        m_game->unk_14BC->sub_0200E0E0(3, 20);
    }

    return -1;
}

void CStylerScene::func1()
{
    m_upper->Render();
    m_screens[m_screenIdx]->Render();
}

void CStylerScene::func2()
{
}

void CStylerScene::func3()
{
    sub_02007D98();
    m_screens[m_screenIdx]->func8();
}

u32 CStylerScene::getSceneId()
{
    return 3;
}

CStylerData::CStylerData(CGame *game)
{
    m_level = 0;
    m_menuMessages = NULL;
    m_assistMessages = NULL;
    unk_10 = NULL;
    m_game = game;
}

CStylerData::~CStylerData()
{
    Release();
}

void CStylerData::Init()
{
    LoadLevels();
    LoadMessages();

    unk_10 = new UnkClass_0202A2AC();
    unk_10->sub_0202A32C(0x3F0, 0, 15, 240, 16);
}

void CStylerData::Release()
{
    SAFE_DELETE(unk_10);
    RELEASE_MESSAGES(m_menuMessages);
    RELEASE_MESSAGES(m_assistMessages);

    m_game->m_textboxData->sub_02009FB0(1, 1);
    m_game->m_textboxData->sub_020092D4();
}

void CStylerData::LoadLevels()
{
    UnkClass_02018DF4 *vars = (UnkClass_02018DF4 *)m_game->unk_14B4;
    m_level = sub_02019278(vars, 3);
    sub_0201926C((UnkClass_02018DF4 *)m_game->unk_14B4, 3, 0);

    switch (m_level) {
    case 0x1B:
        m_level = 0x1A;
        break;
    case 0x1F:
        m_level = 0x1E;
        break;
    case 0x22:
        m_level = 0x21;
        break;
    case 0x26:
        m_level = 0x25;
        break;
    case 0x28:
        m_level = 0x27;
        break;
    }

    s32 count = sub_02019278((UnkClass_02018DF4 *)m_game->unk_14B4, 4);
    if (m_level != 0) {
        sub_0201926C((UnkClass_02018DF4 *)m_game->unk_14B4, 4, count + 1);
        m_game->m_audioEngine->sub_020349E8(0xAB);
    }

    UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
    for (int i = 0; i < 26; i++) {
        m_powerLevels[i] = sub_02016C14(save, i);
    }

    m_powerLevels[24] = 0;
    m_powerLevels[25] = 0;

    if (((save->unk_0003 >> 4) & 0xF) == 2) {
        m_powerLevels[24]++;
        m_powerLevels[25]++;
    }
    if ((u32)(save->unk_0003 & 0xF) >= 6) {
        m_powerLevels[24]++;
    }
    if ((u32)(save->unk_0003 & 0xF) >= 8) {
        m_powerLevels[25]++;
    }

    ApplyLevelUp();
}

static UnkClass_020091E8_004 *LoadMessageTable(const char *path);

void CStylerData::LoadMessages()
{
    m_game->m_textboxData->sub_02009328(m_game->unk_0014, m_game->touchPanel, &m_game->unk_14AC->unk_0C, m_game->unk_14B0, m_game->unk_0024, NULL, 0x10, 0x4000, 0);
    m_menuMessages = LoadMessageTable("data/message/etc/menu_mes");
    m_assistMessages = LoadMessageTable("data/message/etc/assist_mes");
}

void CStylerData::RaiseLevel(int idx, int max)
{
    m_raised[idx] = 1;
    if (m_powerLevels[idx] >= max) {
        m_powerLevels[idx] = max;
    } else {
        m_powerLevels[idx]++;
    }
    sub_02016C40(&MAIN_BSS_020B26A0, idx, m_powerLevels[idx]);
}

void CStylerData::ApplyLevelUp()
{
    int i;
    for (i = 0; i < 26; i++) {
        m_raised[i] = 0;
    }

    switch (m_level) {
    case 1:
        RaiseLevel(14, 3);
        break;
    case 2:
        RaiseLevel(0, 3);
        break;
    case 3:
        RaiseLevel(1, 3);
        break;
    case 4:
        RaiseLevel(9, 3);
        break;
    case 5:
        RaiseLevel(7, 3);
        break;
    case 6:
        RaiseLevel(10, 3);
        break;
    case 7:
        RaiseLevel(3, 3);
        break;
    case 8:
        RaiseLevel(4, 3);
        break;
    case 9:
        RaiseLevel(2, 3);
        break;
    case 10:
        RaiseLevel(8, 3);
        break;
    case 11:
        RaiseLevel(15, 3);
        break;
    case 12:
        RaiseLevel(5, 3);
        break;
    case 13:
        RaiseLevel(12, 3);
        break;
    case 14:
        RaiseLevel(6, 3);
        break;
    case 15:
        RaiseLevel(11, 3);
        break;
    case 16:
        RaiseLevel(13, 3);
        break;
    case 17:
        RaiseLevel(16, 3);
        break;
    case 25:
        for (i = 0; i < 17; i++) {
            RaiseLevel(i, 3);
        }
        break;
    case 26:
        RaiseLevel(22, 2);
        break;
    case 30:
        RaiseLevel(17, 2);
        break;
    case 33:
        RaiseLevel(18, 2);
        break;
    case 35:
        RaiseLevel(19, 1);
        break;
    case 37:
        RaiseLevel(20, 2);
        break;
    case 39:
        RaiseLevel(23, 2);
        break;
    case 42:
        RaiseLevel(21, 1);
        break;
    }
}

static UnkClass_020091E8_004 *LoadMessageTable(const char *path)
{
    UnkClass_020091E8_004 *table = new UnkClass_020091E8_004();
    CBinaryFileMes *file = new CBinaryFileMes(path, 1);

    u32 pos = 2;
    table->unk_00 = ((u32 *)file->unk_4C)[0];
    table->unk_04 = ((u32 *)file->unk_4C)[1];
    table->unk_08 = new UnkClass_020091E8_004_08[table->unk_04];

    for (u32 i = 0; i < table->unk_04; ++i) {
        table->unk_08[i].unk_00 = ((u32 *)file->unk_4C)[pos];
        ++pos;

        table->unk_08[i].unk_04 = new u8[table->unk_08[i].unk_00];
        MI_CpuCopyFast(&((u32 *)file->unk_4C)[pos], table->unk_08[i].unk_04, table->unk_08[i].unk_00);

        pos += table->unk_08[i].unk_00 / 4;
    }

    delete file;
    return table;
}
