#include "scene/CLetterScene.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "CGame.hpp"
#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200C38C.hpp"
#include "UnkClass_0200CFF4.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_0201164C.hpp"
#include "UnkClass_02034478.hpp"
#include "UnkClass_020B26A0.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CBinaryFileMes.hpp"
#include "file/CNCLRFile.hpp"
#include "file/CNSCRFile.hpp"

CLetterScene::CLetterScene(CGame *game)
{
    m_game = game;
    game->unk_146C.sub_02008DB4(30);
    m_messages = NULL;
    unk_2C = NULL;
    unk_20 = 0;
    unk_24 = 0;
    unk_28 = 0;
}

CLetterScene::~CLetterScene()
{
    if (m_messages != NULL) {
        for (u32 i = 0; i < m_messages->unk_04; ++i) {
            if (m_messages->unk_08[i].unk_04 != NULL) {
                delete[] m_messages->unk_08[i].unk_04;
                m_messages->unk_08[i].unk_04 = NULL;
            }
        }

        if (m_messages->unk_08 != NULL) {
            delete[] m_messages->unk_08;
            m_messages->unk_08 = NULL;
        }

        if (m_messages != NULL) {
            delete m_messages;
            m_messages = NULL;
        }
    }

    SAFE_DELETE(unk_2C);
    NNS_GfdResetLnkTexVramState();
    NNS_GfdResetLnkPlttVramState();
    m_game->unk_146C.sub_02008DB4(30);
}

void CLetterScene::func5()
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

    GX_SetBankForBG(GX_VRAM_BG_128_A);
    GX_SetBankForOBJ(GX_VRAM_OBJ_64_E);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);

    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_DispOn();
    GXS_DispOn();
}

void CLetterScene::func6()
{
    char path[64];

    unk_2C = new UnkClass_0200ECD0((GXOamAttr *)m_game->unk_0024, m_game->unk_14A8, FALSE, 0x40);
    unk_2C->sub_0200EE14("data/eventicon", "eventicon000", 0, 0);
    unk_2C->sub_0200F4FC(0, 0xF0, 0xB3, 0);

    m_chapter = m_game->m_missionQuestData->unk_10;
    unk_18 = 8;
    unk_1C = 8;
    switch (m_chapter) {
    case 10:
    case 12:
    case 14:
    case 19:
    case 20:
        unk_18 = 12;
        unk_1C = 18;
        unk_10 = 0x33333333;
        unk_14 = 0;
        break;
    case 40:
    case 42:
        unk_10 = 0x33333333;
        unk_14 = 1;
        break;
    case 8:
    case 22:
    case 25:
    case 32:
    case 34:
    case 37:
    case 44:
    case 47:
    case 49:
    case 57:
    case 900:
        unk_10 = 0x66666666;
        unk_14 = 2;
        break;
    default:
        m_chapter = 49;
        unk_10 = 0x66666666;
        unk_14 = 2;
        break;
    }

    if (unk_10 == 0x33333333) {
        m_game->unk_14BC->sub_0200E0E0(2, 0);
        m_game->unk_14C0->sub_0200E0E0(2, 0);
    } else {
        m_game->unk_14BC->sub_0200E0E0(4, 0);
        m_game->unk_14C0->sub_0200E0E0(4, 0);
    }

    OS_SPrintf(path, "data/message/chapter/chapter%03d_mes", m_chapter);
    CBinaryFileMes *file = new CBinaryFileMes(path, 1);

    m_messages = new UnkClass_020091E8_004();
    u32 pos = 2;
    m_messages->unk_00 = ((u32 *)file->unk_4C)[0];
    m_messages->unk_04 = ((u32 *)file->unk_4C)[1];
    m_messages->unk_08 = new UnkClass_020091E8_004_08[m_messages->unk_04];

    for (u32 i = 0; i < m_messages->unk_04; ++i) {
        m_messages->unk_08[i].unk_00 = ((u32 *)file->unk_4C)[pos];
        ++pos;

        m_messages->unk_08[i].unk_04 = new u8[m_messages->unk_08[i].unk_00];
        MI_CpuCopyFast(&((u32 *)file->unk_4C)[pos], m_messages->unk_08[i].unk_04, m_messages->unk_08[i].unk_00);

        pos += m_messages->unk_08[i].unk_00 / 4;
    }

    delete file;

    ov4_0211D060();
    ov4_0211D394();
    ov4_0211D440();
}

void CLetterScene::ov4_0211D060()
{
    CArchiveGuard *archive = new CArchiveGuard("BGM", "data/menu/ml000_bg_LZ.bin", 0, 1, 0, NULL, 0);
    CBGNCGRFile *ncgr = new CBGNCGRFile("BGM:ml000.NCGR", 0, 0, 0);
    CNCLRFile *nclr = new CNCLRFile("BGM:ml000.NCLR", 0, 0, 0);
    CNSCRFile *nscr;
    switch (unk_14) {
    case 0:
        nscr = new CNSCRFile("BGM:ml000_00_2.NSCR", 0, 0, 0);
        break;
    case 1:
        nscr = new CNSCRFile("BGM:ml000_00_1.NSCR", 0, 0, 0);
        break;
    case 2:
        nscr = new CNSCRFile("BGM:ml000_00_0.NSCR", 0, 0, 0);
        break;
    }
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_MAIN1, nscr->unk_B8, ncgr->unk_B8, nclr->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x00000);
    delete nscr;
    delete ncgr;
    delete nclr;
    delete archive;

    archive = new CArchiveGuard("BGM", "data/menu/mnd000_bg_LZ.bin", 0, 1, 0, NULL, 0);
    ncgr = new CBGNCGRFile("BGM:mnd000.NCGR", 0, 0, 0);
    nclr = new CNCLRFile("BGM:mnd000.NCLR", 0, 0, 0);
    nscr = new CNSCRFile("BGM:mnd000_00.NSCR", 0, 0, 0);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB0, nscr->unk_B8, ncgr->unk_B8, nclr->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x00000);
    delete nscr;
    delete ncgr;
    delete nclr;
    delete archive;
}

void CLetterScene::ov4_0211D394()
{
    GX_SetVisiblePlane(GX_PLANEMASK_BG1 | GX_PLANEMASK_OBJ);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG0);
    G2_SetBG0Priority(0);
    G2_SetBG1Priority(1);
    G2_SetBG2Priority(2);
    G2_SetBG3Priority(3);
    G2S_SetBG0Priority(0);
    G2S_SetBG1Priority(1);
    G2S_SetBG2Priority(2);
    G2S_SetBG3Priority(3);
}

void CLetterScene::ov4_0211D440()
{
    m_game->unk_1494->sub_0200C3BC(&m_game->unk_14AC->unk_0C, 1);
    m_game->unk_1494->sub_0200C3D0();
    m_game->unk_1494->sub_0200C408(0, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x00000);
    m_game->unk_1494->sub_0200C680(1);
    m_game->unk_1494->sub_0200C6C8(0, 30, 20, 1, 2, 0x80, 0, 2);
    if (unk_10 == 0x33333333) {
        m_game->unk_14BC->sub_0200E0E0(1, 180);
        m_game->unk_14C0->sub_0200E0E0(1, 180);
    } else {
        m_game->unk_14BC->sub_0200E0E0(3, 180);
        m_game->unk_14C0->sub_0200E0E0(3, 180);
    }
}

void CLetterScene::func7()
{
}

u32 CLetterScene::func0()
{
    unk_2C->sub_0200F64C();

    if (unk_20 != 0) {
        if (--unk_20 == 0) {
            m_game->unk_1494->sub_0200C3BC(&m_game->unk_14AC->unk_14, 0);
            return 1;
        }
    } else {
        CTouchPanel *touchPanel = m_game->touchPanel;
        UnkClass_02001C04 *pad = m_game->unk_0014;
        if (unk_24 < 0xF0) {
            unk_24++;
        } else if (unk_10 == 0x33333333) {
            if ((u16)(pad->unk_0002 & 1) || (u16)(pad->unk_0002 & 2) || touchPanel->unk_04 != 0) {
                m_game->unk_14BC->sub_0200E0E0(2, 60);
                m_game->unk_14C0->sub_0200E0E0(2, 60);
                unk_20 = 60;
                m_game->m_audioEngine->sub_02034C44(3);
            }
        } else {
            if ((u16)(pad->unk_0002 & 1) || (u16)(pad->unk_0002 & 2) || touchPanel->unk_04 != 0) {
                m_game->unk_14BC->sub_0200E0E0(4, 60);
                m_game->unk_14C0->sub_0200E0E0(4, 60);
                unk_20 = 60;
                m_game->m_audioEngine->sub_02034C44(3);
            }
        }

        if (unk_28 < 10) {
            unk_28++;
        }
        if (unk_28 == 2) {
            int color = unk_10 == 0x33333333 ? 4 : 1;
            int msg;
            u8 gender = m_game->unk_14A4->unk_0000;
            if (m_chapter == 10 || m_chapter == 12 || m_chapter == 14 || m_chapter == 19 || m_chapter == 20) {
                if (gender == 0) {
                    msg = 1;
                } else {
                    msg = 2;
                }
            } else {
                msg = 1;
            }
            m_game->unk_1494->sub_0200C7A4(0, unk_18, unk_1C, color, m_messages->unk_08[msg].unk_04, FALSE, 0);
        }
    }

    return -1;
}

void CLetterScene::func1()
{
    if (unk_24 >= 0xF0) {
        unk_2C->sub_0200F71C();
    }
}

u32 CLetterScene::getSceneId()
{
    return 2;
}
