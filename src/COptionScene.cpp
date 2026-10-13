#include "scene/COptionScene.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "CGame.hpp"
#include "UnkClass_020091E8.hpp"
#include "UnkClass_0200C38C.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_02018DF4.hpp"
#include "UnkClass_02025648.hpp"
#include "UnkClass_02034478.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBGNCGRFile.hpp"
#include "file/CBinaryFileMes.hpp"
#include "file/CNCLRFile.hpp"
#include "file/CNSCRFile.hpp"
#include "sub_02007CF0.hpp"

COptionScene::COptionScene(CGame *game)
{
    m_game = game;
    game->unk_146C.sub_02008DB4(60);
    m_messages = NULL;
    m_fadeTimer = 0;
    m_sprites = NULL;
    m_backSprites = NULL;
    unk_84 = NULL;
    if (sub_02019278((UnkClass_02018DF4 *)game->unk_14B4, 2) == 0) {
        sub_0201926C((UnkClass_02018DF4 *)game->unk_14B4, 2, 4);
        game->m_textboxData->unk_074 = 4;
    }
}

COptionScene::~COptionScene()
{
    m_game->m_textboxData->sub_02009FB0(1, 1);
    m_game->m_textboxData->sub_020092D4();

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

    SAFE_DELETE(m_sprites);
    SAFE_DELETE(m_backSprites);
    NNS_GfdResetLnkTexVramState();
    NNS_GfdResetLnkPlttVramState();
    SAFE_DELETE(unk_84);
    m_game->unk_146C.sub_02008DB4(30);
}

void COptionScene::func5()
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

    unk_84 = new UnkClass_02025648();
    unk_84->LoadAll();
}

void COptionScene::func6()
{
    m_game->m_textboxData->sub_02009328(m_game->unk_0014, m_game->touchPanel, &m_game->unk_14AC->unk_0C, m_game->unk_14B0, m_game->unk_0024, NULL, 0x10, 0x4000, 0);
    m_frame = sub_02019278((UnkClass_02018DF4 *)m_game->unk_14B4, 1);
    m_textSpeed = sub_02019278((UnkClass_02018DF4 *)m_game->unk_14B4, 2);

    CBinaryFileMes *file = new CBinaryFileMes("data/message/etc/menu_mes", 1);

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

    int charSize = 0;
    m_sprites = new UnkClass_0200ECD0((GXOamAttr *)m_game->unk_0024, m_game->unk_14A8, charSize, 0x40);
    charSize += m_sprites->sub_0200EE14("data/menu", "mo000_00", 0, 0);

    m_buttons[0] = m_sprites->sub_0200F4FC(0, 0x4C, 0x40, 1);
    m_buttonIds[0] = m_sprites->unk_24;
    m_buttons[1] = m_sprites->sub_0200F4FC(0x11, 0x80, 0x40, 1);
    m_buttonIds[1] = m_sprites->unk_24;
    m_buttons[2] = m_sprites->sub_0200F4FC(0x14, 0xB4, 0x40, 1);
    m_buttonIds[2] = m_sprites->unk_24;

    switch (m_textSpeed) {
    case 3:
        m_sprites->sub_0200F628(m_buttonIds[0], 0);
        m_sprites->sub_0200F628(m_buttonIds[1], 0xD);
        m_sprites->sub_0200F628(m_buttonIds[2], 0xF);
        break;
    case 2:
        m_sprites->sub_0200F628(m_buttonIds[0], 1);
        m_sprites->sub_0200F628(m_buttonIds[1], 0xC);
        m_sprites->sub_0200F628(m_buttonIds[2], 0xF);
        break;
    case 1:
        m_sprites->sub_0200F628(m_buttonIds[0], 1);
        m_sprites->sub_0200F628(m_buttonIds[1], 0xD);
        m_sprites->sub_0200F628(m_buttonIds[2], 0xE);
        break;
    }

    m_buttons[3] = m_sprites->sub_0200F4FC(2, 0x38, 0x74, 1);
    m_buttonIds[3] = m_sprites->unk_24;
    m_buttons[4] = m_sprites->sub_0200F4FC(3, 0x68, 0x74, 1);
    m_buttonIds[4] = m_sprites->unk_24;
    m_buttons[5] = m_sprites->sub_0200F4FC(4, 0x98, 0x74, 1);
    m_buttonIds[5] = m_sprites->unk_24;
    m_buttons[6] = m_sprites->sub_0200F4FC(5, 0xC8, 0x74, 1);
    m_buttonIds[6] = m_sprites->unk_24;
    m_buttons[7] = m_sprites->sub_0200F4FC(6, 0x38, 0x8C, 1);
    m_buttonIds[7] = m_sprites->unk_24;
    m_buttons[8] = m_sprites->sub_0200F4FC(7, 0x68, 0x8C, 1);
    m_buttonIds[8] = m_sprites->unk_24;
    m_buttons[9] = m_sprites->sub_0200F4FC(8, 0x98, 0x8C, 1);
    m_buttonIds[9] = m_sprites->unk_24;
    m_buttons[10] = m_sprites->sub_0200F4FC(9, 0xC8, 0x8C, 1);
    m_buttonIds[10] = m_sprites->unk_24;
    m_sprites->sub_0200F4FC(0xA, 0x80, 0x10, 2);
    m_buttons[11] = m_sprites->sub_0200F4FC(0xB, m_buttons[m_frame + 3]->unk_0C, m_buttons[m_frame + 3]->unk_0E, 1);
    m_buttonIds[11] = m_sprites->unk_24;

    m_backSprites = new UnkClass_0200ECD0((GXOamAttr *)&m_game->unk_0024[0x32], m_game->unk_14A8, FALSE, 0x40);
    m_backSprites->sub_0200EE14("data/menu", "ma005_00", charSize / 32, 0xB);
    m_backButton = m_backSprites->sub_0200F4FC(0, 0xF0, 0x10, 0);
    m_backButton->sub_0200EBF4(0x20, 0x20, 0, 0);

    for (int i = 0; i < 3; i++) {
        m_buttons[i]->sub_0200EBF4(0x28, 0x18, 0, 0);
    }
    for (int i = 3; i < 11; i++) {
        m_buttons[i]->sub_0200EBF4(0x2A, 0x10, 0, 0);
    }

    ov6_0211D460();
    ov6_0211D638();
    ov6_0211D6B4();
    m_game->m_textboxData->sub_0200AB28(2);
    m_game->m_textboxData->sub_0200AA04(m_textSpeed);
    m_game->m_textboxData->sub_0200AD34(4, 1, 0, 0);
}

void COptionScene::ov6_0211D460()
{
    CArchiveGuard *archive = new CArchiveGuard("BGS", "data/menu/mo000_bg_LZ.bin", 1, 1, 0, NULL, 0);
    CBGNCGRFile *ncgr = new CBGNCGRFile("BGS:mo000.NCGR", 1, 0, 0);
    CNCLRFile *nclr = new CNCLRFile("BGS:mo000.NCLR", 1, 0, 0);
    CNSCRFile *nscr2 = new CNSCRFile("BGS:mo000_02.NSCR", 1, 0, 0);
    CNSCRFile *nscr3 = new CNSCRFile("BGS:mo000_03.NSCR", 1, 0, 0);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_MAIN2, nscr2->unk_B8, ncgr->unk_B8, nclr->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x7000, GX_BG_CHARBASE_0x04000);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_MAIN3, nscr3->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7800, GX_BG_CHARBASE_0x04000);
    delete nscr2;
    delete nscr3;
    delete ncgr;
    delete nclr;
    delete archive;
}

void COptionScene::ov6_0211D638()
{
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    G2_SetBG1Priority(0);
    G2_SetBG0Priority(1);
    G2_SetBG2Priority(2);
    G2_SetBG3Priority(3);
    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_BG2, GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ, 8, 0x17);
}

void COptionScene::ov6_0211D6B4()
{
    int params[3][7] = {
        { 12, 2, 10, 1, 4, 3, 1 },
        { 14, 2, 0, 4, 4, 3, 3 },
        { 14, 2, 0, 11, 4, 3, 3 },
    };
    int charNo = 0x240;

    m_game->unk_1494->sub_0200C3D0();
    m_game->unk_1494->sub_0200C408(0, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x00000);
    m_game->unk_1494->sub_0200C680(3);

    for (int i = 0; i < 3; i++) {
        m_game->unk_1494->sub_0200C6C8(i, params[i][0], params[i][1], params[i][2], params[i][3], charNo, 0, 2);
        charNo += params[i][0] * params[i][1];
    }

    m_game->unk_1494->sub_0200C7A4(0, params[0][4], params[0][5], params[0][6], m_messages->unk_08[49].unk_04, TRUE, 0);
    m_game->unk_1494->sub_0200C7A4(1, params[1][4], params[1][5], params[1][6], m_messages->unk_08[50].unk_04, TRUE, 0);
    m_game->unk_1494->sub_0200C7A4(2, params[2][4], params[2][5], params[2][6], m_messages->unk_08[51].unk_04, TRUE, 0);
    m_game->unk_14BC->sub_0200E0E0(3, 30);
    m_game->unk_14C0->sub_0200E0E0(3, 30);
}

void COptionScene::func7()
{
    m_game->m_textboxData->sub_020092D4();
}

u32 COptionScene::func0()
{
    unk_84->sub_02027640();
    m_sprites->sub_0200F64C();

    if (m_fadeTimer != 0) {
        if (--m_fadeTimer == 0) {
            return 6;
        }
    } else {
        UnkClass_02001C04 *pad = m_game->unk_0014;
        if (m_backButton->sub_0200EB84() || (u16)(pad->unk_0002 & 2)) {
            m_game->unk_14BC->sub_0200E0E0(4, 30);
            m_game->unk_14C0->sub_0200E0E0(4, 30);
            m_fadeTimer = 30;
            m_game->m_audioEngine->sub_02034C44(0x103);
        } else {
            for (int i = 0; i < 3; i++) {
                if (m_buttons[i]->sub_0200EB84()) {
                    switch (i) {
                    case 0:
                        m_sprites->sub_0200F628(m_buttonIds[0], 0);
                        m_sprites->sub_0200F628(m_buttonIds[1], 0xD);
                        m_sprites->sub_0200F628(m_buttonIds[2], 0xF);
                        m_textSpeed = 3;
                        sub_0201926C((UnkClass_02018DF4 *)m_game->unk_14B4, 2, m_textSpeed);
                        m_game->m_textboxData->unk_074 = m_textSpeed;
                        break;
                    case 1:
                        m_sprites->sub_0200F628(m_buttonIds[0], 1);
                        m_sprites->sub_0200F628(m_buttonIds[1], 0xC);
                        m_sprites->sub_0200F628(m_buttonIds[2], 0xF);
                        m_textSpeed = 2;
                        sub_0201926C((UnkClass_02018DF4 *)m_game->unk_14B4, 2, m_textSpeed);
                        m_game->m_textboxData->unk_074 = m_textSpeed;
                        break;
                    case 2:
                        m_sprites->sub_0200F628(m_buttonIds[0], 1);
                        m_sprites->sub_0200F628(m_buttonIds[1], 0xD);
                        m_sprites->sub_0200F628(m_buttonIds[2], 0xE);
                        m_textSpeed = 1;
                        sub_0201926C((UnkClass_02018DF4 *)m_game->unk_14B4, 2, m_textSpeed);
                        m_game->m_textboxData->unk_074 = m_textSpeed;
                        break;
                    }
                    m_game->m_audioEngine->sub_02034C44(0xFA);
                    m_game->m_textboxData->sub_0200A088(1);
                    m_game->m_textboxData->sub_0200AA04(m_textSpeed);
                    m_game->m_textboxData->sub_0200AD34(4, 1, 0, 0);
                    return -1;
                }
            }

            for (int i = 3; i < 11; i++) {
                if (m_buttons[i]->sub_0200EB84()) {
                    if (m_frame != i - 3) {
                        m_frame = i - 3;
                        m_buttons[11]->sub_0200EB28(m_buttons[i]->unk_0C, m_buttons[i]->unk_0E);
                        sub_0201926C((UnkClass_02018DF4 *)m_game->unk_14B4, 1, m_frame);
                        m_game->m_textboxData->unk_070 = m_frame;
                        m_game->m_textboxData->sub_0200978C(0);
                        m_game->m_audioEngine->sub_02034C44(0xFA);
                    }
                    return -1;
                }
            }
        }
    }

    return -1;
}

void COptionScene::func1()
{
    unk_84->sub_02027674();
    m_sprites->sub_0200F71C();
    m_backSprites->sub_0200F71C();
}

void COptionScene::func3()
{
    sub_02007D98();
}

u32 COptionScene::getSceneId()
{
    return 4;
}
