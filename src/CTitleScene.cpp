#include "scene/CTitleScene.hpp"

#include <nitro.h>
#include <nnsys.h>
#include <string.h>

#include "CGame.hpp"
#include "SaveDataBuffer.hpp"
#include "UnkClass_0200CAB4.hpp"
#include "UnkClass_0200CFF4.hpp"
#include "UnkClass_0200E0B4.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_02018DF4.hpp"
#include "UnkClass_02027FE8.hpp"
#include "UnkClass_02034478.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkClass_020B26A0.hpp"
#include "common.hpp"
#include "file/CBinaryFileMes.hpp"
#include "sub_02006000.hpp"
#include "sub_02007CF0.hpp"

extern "C" {
void sub_02034450(void *scriptManager);
}

extern u32 MAIN_BSS_0208F31C;
extern UnkClass_02041C80 *MAIN_BSS_0210CA6C;

extern "C" BOOL sub_02017298(void);
extern "C" void sub_020172BC(void);

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

static inline UnkClass_0200CAB4 *GetPrinter(CGame *game)
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

CTitleScene::CTitleScene(CGame *game)
{
    m_game = game;
    m_flags = 1;
    unk_10 = 0;
    unk_14 = 0;
    unk_40 = NULL;
    for (int i = 0; i < 4; i++) {
        unk_44[i] = NULL;
    }
    unk_54 = NULL;
    unk_58 = NULL;
    unk_8C = NULL;
    unk_90 = NULL;
    unk_A4 = NULL;
    unk_B0 = NULL;
    unk_A0 = FX32_ONE;
    unk_96 = 0;
    unk_DC = 0;
    unk_E0 = 0;
    unk_E4 = NULL;
    m_bg = NULL;
    m_resource = NULL;
    unk_F4 = 0;
    unk_F8 = 0;
    unk_FC = 0;
}

CTitleScene::~CTitleScene()
{
    func7();
}

void CTitleScene::func5()
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

    G3_SwapBuffers(GX_SORTMODE_AUTO, GX_BUFFERMODE_W);
    GX_SetBankForTex(GX_VRAM_TEX_NONE);
    GX_SetBankForTexPltt(GX_VRAM_TEXPLTT_NONE);
    GX_SetBankForOBJ(GX_VRAM_OBJ_96_EFG);
    GX_SetBankForBG(GX_VRAM_BG_256_AB);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
    G2_SetBG0Priority(0);
    G2_SetBG1Priority(1);
    G2_SetBG2Priority(2);
    G2_SetBG3Priority(3);
    MI_CpuClearFast((void *)HW_BG_VRAM, 0x20000);

    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_128_D);
    G2S_SetBG0Priority(3);
    G2S_SetBG1Priority(2);
    G2S_SetBG2Priority(1);
    G2S_SetBG3Priority(0);
    MI_CpuClearFast((void *)HW_DB_BG_VRAM, 0x20000);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_MAIN_SUB);
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG1 | GX_PLANEMASK_OBJ);
    GX_DispOn();
    GXS_DispOn();
}

void CTitleScene::ov3_0211CD2C()
{
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
    G2S_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x0000, GX_BG_CHARBASE_0x00000, GX_BG_EXTPLTT_01);
    G2S_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x00000, GX_BG_EXTPLTT_01);
}

void CTitleScene::ov3_0211CD6C()
{
    if (m_flags & 0x200) {
        ov3_0211CD8C();
    } else {
        ov3_0211D1B0();
    }
}

void CTitleScene::ov3_0211CD8C()
{
    TextWindow wins[8] = {
        { 15, 2, 2, 3, 0, 3, 1 },
        { 8, 3, 8, 6, -1, 4, 3 },
        { 12, 3, 7, 8, 0, 4, 3 },
        { 9, 3, 22, 6, 5, 3, 3 },
        { 8, 3, 23, 8, 2, 3, 3 },
        { 16, 2, 2, 13, 0, 3, 1 },
        { 15, 2, 2, 17, 0, 4, 1 },
        { 20, 2, 6, 21, -1, 3, 3 },
    };
    UnkClass_0200CAB4 *printer = GetPrinter(m_game);
    printer->sub_0200CAE0();
    printer->sub_0200CB14();
    printer->sub_0200CACC(&m_game->unk_14AC->unk_14, 0);
    printer->sub_0200CC88(8);

    UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
    int minutes = 59;
    u32 hours = 99;
    if (MAIN_BSS_020B26A0.unk_87DA == 0) {
        minutes = save->unk_87D8;
        hours = save->unk_87D4;
    }

    int charNo = 0x20;
    for (int i = 0; i < 8; i++) {
        printer->sub_0200CCD0(i, wins[i].width, wins[i].height, wins[i].left, wins[i].top, charNo, 0, 2);
        charNo += wins[i].width * wins[i].height;
    }

    u8 *texts[8] = { NULL };
    texts[0] = unk_8C->unk_08[33].unk_04;
    texts[1] = &save->unk_87E3;
    texts[2] = unk_8C->unk_08[26].unk_04;
    texts[3] = unk_8C->unk_08[35].unk_04;
    texts[5] = unk_8C->unk_08[34].unk_04;
    texts[6] = unk_8C->unk_08[36].unk_04;
    texts[7] = unk_8C->unk_08[37].unk_04;
    for (int i = 0; i < 8; i++) {
        if (texts[i] != NULL) {
            printer->sub_0200CDA0(i, wins[i].x, wins[i].y, wins[i].color, texts[i], wins[i].x < 0 ? TRUE : FALSE, 0);
        }
    }

    printer->sub_0200CDA0(4, wins[4].x, wins[4].y, wins[4].color, unk_8C->unk_08[(int)((hours / 10) % 10) + 8].unk_04, FALSE, 0);
    printer->sub_0200CDA0(4, wins[4].x + 11, wins[4].y, wins[4].color, unk_8C->unk_08[(int)(hours % 10) + 8].unk_04, FALSE, 0);
    printer->sub_0200CDA0(4, wins[4].x + 22, wins[4].y, wins[4].color, unk_8C->unk_08[52].unk_04, FALSE, 0);
    printer->sub_0200CDA0(4, wins[4].x + 33, wins[4].y, wins[4].color, unk_8C->unk_08[minutes / 10 + 8].unk_04, FALSE, 0);
    printer->sub_0200CDA0(4, wins[4].x + 44, wins[4].y, wins[4].color, unk_8C->unk_08[minutes % 10 + 8].unk_04, FALSE, 0);

    unk_5C.pos.x = 0;
    unk_5C.pos.y = -0x28000;
    unk_5C.size.x = 0x100000;
    unk_5C.size.y = 0x48000;
    unk_6C.pos.x = 0;
    unk_6C.pos.y = 0x10000;
    unk_6C.size.x = 0x100000;
    unk_6C.size.y = 0x20000;
    if (m_flags & 0x400) {
        unk_7C.pos.x = 0;
        unk_7C.pos.y = 0x30000;
        unk_7C.size.x = 0x100000;
        unk_7C.size.y = 0x20000;
    } else {
        unk_7C.pos.x = -0x100000;
        unk_7C.pos.y = -0xC0000;
        unk_7C.size.x = 0;
        unk_7C.size.y = 0;
    }
}

void CTitleScene::ov3_0211D1B0()
{
    TextWindow wins[3] = {
        { 16, 2, 2, 2, 0, 3, 1 },
        { 15, 2, 2, 6, 0, 3, 1 },
        { 20, 2, 6, 21, -1, 2, 3 },
    };
    UnkClass_0200CAB4 *printer = GetPrinter(m_game);
    printer->sub_0200CAE0();
    printer->sub_0200CB14();
    printer->sub_0200CACC(&m_game->unk_14AC->unk_14, 0);
    printer->sub_0200CC88(3);

    int charNo = 0x20;
    for (int i = 0; i < 3; i++) {
        printer->sub_0200CCD0(i, wins[i].width, wins[i].height, wins[i].left, wins[i].top, charNo, 0, 2);
        charNo += wins[i].width * wins[i].height;
    }

    u8 *texts[3];
    texts[0] = unk_8C->unk_08[34].unk_04;
    texts[1] = unk_8C->unk_08[36].unk_04;
    texts[2] = unk_8C->unk_08[37].unk_04;
    for (int i = 0; i < 3; i++) {
        printer->sub_0200CDA0(i, wins[i].x, wins[i].y, wins[i].color, texts[i], wins[i].x < 0 ? TRUE : FALSE, 0);
    }

    unk_6C.pos.x = 0;
    unk_6C.pos.y = -0x48000;
    unk_6C.size.x = 0x100000;
    unk_6C.size.y = 0x20000;
    if (m_flags & 0x400) {
        unk_7C.pos.x = 0;
        unk_7C.pos.y = -0x28000;
        unk_7C.size.x = 0x100000;
        unk_7C.size.y = 0x20000;
    } else {
        unk_7C.pos.x = -0x100000;
        unk_7C.pos.y = -0xC0000;
        unk_7C.size.x = 0;
        unk_7C.size.y = 0;
    }
}

void CTitleScene::func6()
{
    MAIN_BSS_0208F31C = 1;
    m_resource = (CTitleResource *)m_game->unk_14A4->unk_8BA0;
    if (m_resource == NULL) {
        m_resource = new CTitleResource();
        m_resource->Load(m_game);
    }

    m_game->unk_146C.sub_02008DB4(60);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    GXS_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    m_game->m_textboxData->sub_02009328(m_game->unk_0014, m_game->touchPanel, &m_game->unk_14AC->unk_14, m_game->unk_14B0, m_game->unk_0024, m_game->m_audioEngine, 0x10, 0x4000, 0);
    sub_02007D68();
    m_flags = 0x400;
    ov3_0211CD2C();

    RTCTime time;
    RTC_GetTime(&time);
    int night;
    if (time.hour >= 6 && time.hour < 18) {
        night = 0;
    } else {
        night = 1;
    }
    m_bg = new CTitleBG();
    m_bg->Load(night);
    unk_24 = m_resource->unk_00;

    u32 pos;
    LOAD_MESSAGES(unk_8C, "/data/message/etc/menu_mes");
    LOAD_MESSAGES(unk_90, "/data/message/system/system_mes");

    unk_40 = m_resource->GetSprite(1);
    unk_54 = m_resource->GetSprite(0);
    unk_58 = m_resource->GetSprite(4);
    unk_B0 = m_resource->GetSprite(2);
    unk_D0 = m_resource->GetSprite(3);
    unk_D8 = m_resource->GetSprite(5);
    for (int i = 0; i < 4; i++) {
        unk_44[i] = m_resource->GetSprite(i + 6);
    }
    ov3_02120634();
    ov3_0212069C();

    unk_A4 = m_resource->unk_04;
    unk_B4.r = 0x20000;
    unk_B4.pos.x = -0x40000;
    unk_B4.pos.y = 0;
    unk_C0.r = 0x20000;
    unk_C0.pos.x = 0x40000;
    unk_C0.pos.y = 0;
    m_game->unk_14BC->sub_0200E0E0(1, 30);
    m_game->unk_14C0->sub_0200E0E0(1, 30);
    unk_E4 = new UnkClass_02027FE8(0);
    unk_DC = 0;
    unk_E0 = 0;
    m_audioEngine = m_game->m_audioEngine;
    m_audioEngine->sub_020345D4();
    if (m_game->unk_0008 == 8) {
        m_audioEngine->sub_02034D54(0x200, 0x40);
    }
    unk_E8 = -1;
    unk_F8 = 0;
    unk_FC = 0;
    m_game->sub_0200FAA4();

    RTCDate date;
    RTC_GetTime(&time);
    RTC_GetDate(&date);
    MAIN_BSS_020B26A0.unk_8B94 = time;
    MAIN_BSS_020B26A0.unk_8B84 = date;
}

void CTitleScene::ov3_0211DD90()
{
    u8 b3 = MAIN_BSS_020B26A0.unk_0003;
    u8 lo = b3 & 0xF;
    u8 b0 = MAIN_BSS_020B26A0.unk_0000;
    u8 hi = (b3 >> 4) & 0xF;

    if (m_flags & 0x200) {
        unk_28 = unk_40->sub_0200F4FC(0, 0x80, 0x38, 2);
        unk_18 = unk_40->unk_24;
        unk_2C = unk_40->sub_0200F4FC(2, 0x80, 0x70, 2);
        unk_1C = unk_40->unk_24;
        if (m_flags & 0x400) {
            unk_30 = unk_40->sub_0200F4FC(2, 0x80, 0x90, 2);
            unk_20 = unk_40->unk_24;
        }
        unk_38 = unk_54->sub_0200F4FC(0, 0x20, 0x4B, 1);
        if (lo != 0) {
            unk_3C = unk_58->sub_0200F4FC(lo - 1, 0x9C, 0x44, 0);
        }
        unk_34 = unk_44[b0 | (hi == 0 ? 0 : 2)]->sub_0200F4FC(0, 0x20, 0x4D, 0);
    } else {
        unk_2C = unk_40->sub_0200F4FC(2, 0x80, 0x18, 2);
        unk_1C = unk_40->unk_24;
        if (m_flags & 0x400) {
            unk_30 = unk_40->sub_0200F4FC(2, 0x80, 0x38, 2);
            unk_20 = unk_40->unk_24;
        }
    }
}

void CTitleScene::ov3_0211DF20()
{
    unk_40->sub_0200F6C4();
    unk_54->sub_0200F6C4();
    unk_58->sub_0200F6C4();
    for (int i = 0; i < 4; i++) {
        if (unk_44[i] != NULL) {
            unk_44[i]->sub_0200F6C4();
        }
    }
}

void CTitleScene::func7()
{
    if (m_bg != NULL) {
        m_bg->ResetOffsets();
        SAFE_DELETE(m_bg);
    }
    SAFE_DELETE(m_resource);
    m_game->unk_14A4->unk_8BA0 = 0;
    RELEASE_MESSAGES(unk_8C);
    RELEASE_MESSAGES(unk_90);
    SAFE_DELETE(unk_E4);

    UnkClass_0200CAB4 *printer = GetPrinter(m_game);
    printer->sub_0200CACC(&m_game->unk_14AC->unk_14, 0);
    printer->sub_0200CAE0();
    G2_SetBG0Offset(0, 0);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
    m_game->unk_146C.sub_02008DB4(30);
    m_game->m_textboxData->sub_020092D4();
    sub_02034450(m_game->m_scriptManager);
    MAIN_BSS_0208F31C = 0;
    G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG1, 0);
}

u32 CTitleScene::func0()
{
    UnkClass_0200CAB4 *printer;
    RTCTime time;
    RTCDate date;

    if (m_bg != NULL) {
        m_bg->Update();
    }
    if (unk_D8 != NULL) {
        unk_D8->sub_0200F64C();
    }
    if (unk_D0 != NULL) {
        unk_D0->sub_0200F64C();
    }

    UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
    UnkClass_02001C04 *pad = m_game->unk_0014;
    CTouchPanel *tp = m_game->touchPanel;
    Point2D touch;
    touch.x = (tp->unk_0A.x - 0x80) << FX32_SHIFT;
    touch.y = (tp->unk_0A.y - 0x60) << FX32_SHIFT;

    switch (unk_DC) {
    case 0:
        m_game->sub_0200FAA4();
        printer = GetPrinter(m_game);
        printer->sub_0200CAE0();
        printer->sub_0200CB14();
        unk_E4->SetDevice(0);
        unk_E4->Load(1);
        SetState(1);
        break;
    case 1: {
        u32 result = unk_E4->sub_0202841C();
        if (result == 0) {
            break;
        }
        if (result & 0x80) {
            switch (result & ~0x80) {
            case 0:
            case 1:
            case 2:
            case 8:
                SetState(0x30);
                break;
            case 10:
                SetState(0x19);
                break;
            case 3:
            case 9:
            case 11:
                SetState(0x15);
                break;
            }
        } else if (sub_02017298() == 0) {
            sub_020172BC();
            SetState(0x19);
        } else {
            SetState(2);
            m_flags |= 0x100;
            m_game->sub_0201024C();
            save->unk_8B64 = sub_02041D80(MAIN_BSS_0210CA6C, save->unk_001A)->unk_04;
        }
        break;
    }
    case 2:
        G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG1, 0);
        unk_A4->LoadToVram();
        ov3_021202E0();
        ov3_0212038C(unk_DC);
        unk_A8->unk_14 = 1;
        unk_AC->unk_14 = 1;
        unk_A8->sub_0200EB34(0x20, FALSE);
        unk_AC->sub_0200EB34(0x20, FALSE);
        m_flags &= ~3;
        SetState(3);
        break;
    case 3:
        ov3_021206E8(unk_A0);
        unk_B0->sub_0200F64C();
        if (m_flags & 3) {
            unk_96++;
            if (unk_96 >= 16) {
                if (m_flags & 1) {
                    SetState(7);
                }
                if (m_flags & 2) {
                    SetState(5);
                }
                unk_96 = 0;
            }
            if (unk_96 == 2) {
                unk_A0 = 0x1000;
            }
        } else if ((u16)(pad->unk_0002 & 1)) {
            unk_A0 = 0x1400;
            unk_A8->sub_0200EB34(1, FALSE);
            unk_AC->unk_14 = 0;
            m_flags |= 1;
            m_audioEngine->sub_02034C44(0xFF);
            unk_96 = 0;
        } else if ((u16)(pad->unk_0002 & 2)) {
            unk_A0 = 0x1400;
            unk_AC->sub_0200EB34(1, FALSE);
            unk_A8->unk_14 = 0;
            m_flags |= 2;
            m_audioEngine->sub_02034C44(0x100);
            unk_96 = 0;
        } else if (tp->unk_04 != 0) {
            if (sub_02006100(touch, unk_B4)) {
                unk_A0 = 0x1400;
                unk_A8->sub_0200EB34(1, FALSE);
                unk_AC->unk_14 = 0;
                m_flags |= 1;
                m_audioEngine->sub_02034C44(0xFF);
                unk_96 = 0;
            } else if (sub_02006100(touch, unk_C0)) {
                unk_A0 = 0x1400;
                unk_AC->sub_0200EB34(1, FALSE);
                unk_A8->unk_14 = 0;
                m_flags |= 2;
                m_audioEngine->sub_02034C44(0x100);
                unk_96 = 0;
            }
        }
        break;
    case 7:
        ov3_0212038C(unk_DC);
        unk_A8->unk_14 = 0;
        unk_AC->unk_14 = 0;
        SetState(8);
        break;
    case 8:
        if (tp->unk_04 != 0 || (u16)(pad->unk_0002 & 3)) {
            SetState(9);
            m_audioEngine->sub_02034C44(3);
        }
        break;
    case 9:
        ov3_0212038C(unk_DC);
        unk_A8->unk_14 = 1;
        unk_AC->unk_14 = 1;
        unk_A8->sub_0200EB34(0x20, FALSE);
        unk_AC->sub_0200EB34(0x20, FALSE);
        m_flags &= ~3;
        SetState(10);
        break;
    case 10:
        ov3_021206E8(unk_A0);
        unk_B0->sub_0200F64C();
        if (m_flags & 3) {
            unk_96++;
            if (unk_96 >= 16) {
                if (m_flags & 1) {
                    SetState(11);
                }
                if (m_flags & 2) {
                    SetState(2);
                }
                unk_96 = 0;
            }
            if (unk_96 == 2) {
                unk_A0 = 0x1000;
            }
        } else if ((u16)(pad->unk_0002 & 1)) {
            unk_A0 = 0x1400;
            unk_A8->sub_0200EB34(1, FALSE);
            unk_AC->unk_14 = 0;
            m_flags |= 1;
            m_audioEngine->sub_02034C44(0xFF);
            unk_96 = 0;
        } else if ((u16)(pad->unk_0002 & 2)) {
            unk_A0 = 0x1400;
            unk_AC->sub_0200EB34(1, FALSE);
            unk_A8->unk_14 = 0;
            m_flags |= 2;
            m_audioEngine->sub_02034C44(0x100);
            unk_96 = 0;
        } else if (tp->unk_04 != 0) {
            if (sub_02006100(touch, unk_B4)) {
                unk_A0 = 0x1400;
                unk_A8->sub_0200EB34(1, FALSE);
                unk_AC->unk_14 = 0;
                m_flags |= 1;
                m_audioEngine->sub_02034C44(0xFF);
                unk_96 = 0;
            } else if (sub_02006100(touch, unk_C0)) {
                unk_A0 = 0x1400;
                unk_AC->sub_0200EB34(1, FALSE);
                unk_A8->unk_14 = 0;
                m_flags |= 2;
                m_audioEngine->sub_02034C44(0x100);
                unk_96 = 0;
            }
        }
        break;
    case 11:
        ov3_0212038C(unk_DC);
        unk_A8->unk_14 = 0;
        unk_AC->unk_14 = 0;
        SetState(12);
        break;
    case 12:
        if (tp->unk_04 != 0 || (u16)(pad->unk_0002 & 3)) {
            SetState(13);
            m_audioEngine->sub_02034C44(3);
        }
        break;
    case 13:
        ov3_0212038C(unk_DC);
        unk_A8->unk_14 = 0;
        unk_AC->unk_14 = 0;
        SetState(14);
        break;
    case 14:
        if (tp->unk_04 != 0 || (u16)(pad->unk_0002 & 3)) {
            SetState(4);
            m_audioEngine->sub_02034C44(3);
        }
        break;
    case 4:
        save->unk_8B68 = 0;
        save->unk_8B6C = 0;
        MAIN_BSS_0210C1C0.unk_60 = 1;
        MAIN_BSS_0210C228.unk_800 = 1;
        SetState(0xF);
        break;
    case 5:
        ov3_0212038C(unk_DC);
        unk_A8->unk_14 = 1;
        unk_AC->unk_14 = 1;
        unk_A8->sub_0200EB34(0x20, FALSE);
        unk_AC->sub_0200EB34(0x20, FALSE);
        m_flags &= ~3;
        SetState(6);
        break;
    case 6:
        ov3_021206E8(unk_A0);
        unk_B0->sub_0200F64C();
        if (m_flags & 3) {
            unk_96++;
            if (unk_96 >= 16) {
                if (m_flags & 1) {
                    SetState(18);
                }
                if (m_flags & 2) {
                    SetState(2);
                }
                unk_96 = 0;
            }
            if (unk_96 == 2) {
                unk_A0 = 0x1000;
            }
        } else if ((u16)(pad->unk_0002 & 1)) {
            unk_A0 = 0x1400;
            unk_A8->sub_0200EB34(1, FALSE);
            unk_AC->unk_14 = 0;
            m_flags |= 1;
            m_audioEngine->sub_02034C44(0xFF);
            unk_96 = 0;
        } else if ((u16)(pad->unk_0002 & 2)) {
            unk_A0 = 0x1400;
            unk_AC->sub_0200EB34(1, FALSE);
            unk_A8->unk_14 = 0;
            m_flags |= 2;
            m_audioEngine->sub_02034C44(0x100);
            unk_96 = 0;
        } else if (tp->unk_04 != 0) {
            if (sub_02006100(touch, unk_B4)) {
                unk_A0 = 0x1400;
                unk_A8->sub_0200EB34(1, FALSE);
                unk_AC->unk_14 = 0;
                m_flags |= 1;
                m_audioEngine->sub_02034C44(0xFF);
                unk_96 = 0;
            } else if (sub_02006100(touch, unk_C0)) {
                unk_A0 = 0x1400;
                unk_AC->sub_0200EB34(1, FALSE);
                unk_A8->unk_14 = 0;
                m_flags |= 2;
                m_audioEngine->sub_02034C44(0x100);
                unk_96 = 0;
            }
        }
        break;
    case 15:
        ov3_0212038C(unk_DC);
        SetState(0x10);
        if (unk_FC != 0) {
            unk_10 = 30;
        } else {
            m_audioEngine->sub_02034DC8(30);
            unk_10 = 0;
            unk_FC = 1;
        }
        break;
    case 16:
        unk_10++;
        if (unk_10 >= 30) {
            unk_E4->SetDevice(1);
            unk_E4->Clear(1);
            SetState(0x11);
        }
        break;
    case 17:
        if (unk_E4->sub_0202841C() != 0) {
            unk_E8 = save->unk_81AC > 0 ? 30 : 1;
            SetState(0x35);
        }
        break;
    case 18:
        ov3_0212038C(unk_DC);
        SetState(0x13);
        if (unk_FC != 0) {
            unk_10 = 30;
        } else {
            m_audioEngine->sub_02034DC8(30);
            unk_10 = 0;
            unk_FC = 1;
        }
        break;
    case 19:
        unk_10++;
        if (unk_10 >= 30) {
            unk_E4->SetDevice(1);
            unk_E4->Clear(1);
            SetState(0x14);
        }
        break;
    case 20:
        if (unk_E4->sub_0202841C() != 0) {
            SetState(0x19);
        }
        break;
    case 21:
        G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG1, 0);
        unk_A4->LoadToVram();
        ov3_021202E0();
        ov3_0212038C(unk_DC);
        SetState(0x16);
        if (unk_FC != 0) {
            unk_10 = 30;
        } else {
            m_audioEngine->sub_02034DC8(30);
            unk_10 = 0;
            unk_FC = 1;
        }
        break;
    case 22:
        unk_10++;
        if (unk_10 >= 30) {
            unk_E4->SetDevice(1);
            unk_E4->Clear(1);
            SetState(0x17);
        }
        break;
    case 23:
        if (unk_E4->sub_0202841C() != 0) {
            SetState(0x18);
            m_audioEngine->sub_02034C44(2);
        }
        break;
    case 24:
        if (tp->unk_04 != 0 || (u16)(pad->unk_0002 & 3)) {
            SetState(0x19);
            m_audioEngine->sub_02034C44(3);
        }
        break;
    case 25:
        m_game->sub_0200FAA4();
        G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG1, -31);
        sub_02015198(save);
        printer = GetPrinter(m_game);
        printer->sub_0200CAE0();
        printer->sub_0200CB14();
        unk_E4->SetDevice(0);
        unk_E4->Load(0);
        SetState(0x1A);
        break;
    case 26: {
        u32 result = unk_E4->sub_0202841C();
        if (result == 0) {
            break;
        }
        if (result & 0x80) {
            switch (result & ~0x80) {
            case 0:
            case 1:
            case 2:
            case 8:
                SetState(0x30);
                break;
            case 10:
                SetState(0x27);
                break;
            case 3:
            case 9:
            case 11:
                SetState(0x1B);
                break;
            }
        } else if (sub_02017298() == 0) {
            sub_020172BC();
            SetState(0x1B);
        } else {
            SetState(0x27);
            m_flags |= 0x200;
            m_game->sub_0201024C();
            save->unk_8B64 = sub_02041D80(MAIN_BSS_0210CA6C, save->unk_001A)->unk_04;
        }
        break;
    }
    case 27:
        SetState(0x1C);
        if (unk_FC != 0) {
            unk_10 = 30;
        } else {
            m_audioEngine->sub_02034DC8(30);
            unk_10 = 0;
            unk_FC = 1;
        }
        break;
    case 28:
        unk_10++;
        if (unk_10 >= 30) {
            unk_E4->SetDevice(1);
            unk_E4->Clear(0);
            SetState(0x1D);
        }
        break;
    case 29:
        if (unk_E4->sub_0202841C() != 0) {
            SetState(0x1F);
        }
        break;
    case 30:
        if (tp->unk_04 != 0 || (u16)(pad->unk_0002 & 3)) {
            SetState(0x1F);
            m_audioEngine->sub_02034C44(3);
        }
        break;
    case 31:
        sub_02015198(save);
        unk_E4->SetDevice(0);
        unk_E4->Load(0);
        SetState(0x20);
        break;
    case 32: {
        u32 result = unk_E4->sub_0202841C();
        if (result == 0) {
            break;
        }
        if (result & 0x80) {
            switch (result & ~0x80) {
            case 0:
            case 1:
            case 2:
            case 8:
                SetState(0x30);
                break;
            case 10:
                SetState(0x23);
                break;
            case 3:
            case 9:
            case 11:
                SetState(0x23);
                break;
            }
        } else if (sub_02017298() == 0) {
            sub_020172BC();
            SetState(0x23);
        } else {
            SetState(0x21);
            m_flags |= 0x200;
            m_game->sub_0201024C();
            save->unk_8B64 = sub_02041D80(MAIN_BSS_0210CA6C, save->unk_001A)->unk_04;
        }
        break;
    }
    case 33:
        SetState(0x22);
        m_audioEngine->sub_02034C44(2);
        G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG1, 0);
        unk_A4->LoadToVram();
        ov3_021202E0();
        ov3_0212038C(unk_DC);
        break;
    case 34:
        if (tp->unk_04 != 0 || (u16)(pad->unk_0002 & 3)) {
            SetState(0x27);
            m_audioEngine->sub_02034C44(3);
        }
        break;
    case 35:
        SetState(0x24);
        if (unk_FC != 0) {
            unk_10 = 30;
        } else {
            m_audioEngine->sub_02034DC8(30);
            unk_10 = 0;
            unk_FC = 1;
        }
        break;
    case 36:
        unk_10++;
        if (unk_10 >= 30) {
            unk_E4->SetDevice(1);
            unk_E4->Clear(0);
            SetState(0x25);
        }
        break;
    case 37:
        if (unk_E4->sub_0202841C() != 0) {
            G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG1, 0);
            unk_A4->LoadToVram();
            ov3_021202E0();
            ov3_0212038C(unk_DC);
            SetState(0x26);
            m_audioEngine->sub_02034C44(2);
        }
        break;
    case 38:
        if (tp->unk_04 != 0 || (u16)(pad->unk_0002 & 3)) {
            SetState(0x27);
            m_audioEngine->sub_02034C44(3);
        }
        break;
    case 39:
        m_flags &= ~0x1E;
        G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG1, 0);
        unk_24->LoadToVram();
        ov3_0211CD6C();
        ov3_0211DF20();
        ov3_0211DD90();
        SetState(0x28);
        unk_F4 = 0xB40;
        if (unk_FC != 0) {
            m_audioEngine->sub_02034D54(0x200, 0x40);
            unk_FC = 0;
        }
        break;
    case 40:
        unk_40->sub_0200F64C();
        if (m_flags & 0x200) {
            for (int i = 0; i < 4; i++) {
                unk_44[i]->sub_0200F64C();
            }
            unk_54->sub_0200F64C();
            unk_58->sub_0200F64C();
        }
        if (unk_F4-- <= 0) {
            SetState(0x34);
            break;
        }
        if (!(m_flags & 0x10) && tp->unk_04 != 0) {
            if ((m_flags & 0x200) && sub_02006000(touch, unk_5C, 0)) {
                m_audioEngine->sub_02034C44(0xFF);
                unk_40->sub_0200F628(unk_18, 1);
                m_flags |= 0x12;
                unk_10 = 0;
            } else if ((m_flags & 0x400) && sub_02006000(touch, unk_7C, 0)) {
                m_audioEngine->sub_02034C44(0xFF);
                unk_40->sub_0200F628(unk_20, 3);
                m_flags |= 0x18;
                unk_10 = 0;
            } else if (sub_02006000(touch, unk_6C, 0)) {
                m_audioEngine->sub_02034C44(0xFF);
                unk_40->sub_0200F628(unk_1C, 3);
                m_flags |= 0x14;
                unk_10 = 0;
            }
        } else if (m_flags & 0x10) {
            unk_10++;
            if (unk_10 == 4) {
                if (m_flags & 2) {
                    unk_40->sub_0200F628(unk_18, 0);
                    SetState(0x29);
                } else if (m_flags & 8) {
                    unk_40->sub_0200F628(unk_20, 2);
                    SetState(0x2B);
                } else if (m_flags & 4) {
                    unk_40->sub_0200F628(unk_1C, 2);
                    if (m_flags & 0x200) {
                        SetState(0x2C);
                    } else {
                        SetState(0x2A);
                    }
                }
                m_flags &= ~0x10;
                m_flags &= ~2;
                m_flags &= ~4;
                m_flags &= ~8;
                unk_10 = 0;
            }
        }
        break;
    case 41:
        save->unk_8B68 = 0;
        save->unk_8B6C = 0;
        MAIN_BSS_0210C1C0.unk_60 = 1;
        MAIN_BSS_0210C228.unk_800 = 1;
        unk_E8 = 1;
        SetState(0x35);
        break;
    case 42:
        sub_02018E94((UnkClass_02018DF4 *)m_game->unk_14B4, 0);
        sub_02018E94((UnkClass_02018DF4 *)m_game->unk_14B4, 0x10);
        m_game->sub_0201024C();
        unk_E8 = 0x13;
        SetState(0x35);
        break;
    case 43:
        unk_E8 = 8;
        SetState(0x35);
        break;
    case 52:
        unk_E8 = 0x12;
        SetState(0x35);
        break;
    case 44:
        G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG1, 0);
        unk_A4->LoadToVram();
        ov3_021202E0();
        ov3_0212038C(unk_DC);
        unk_A8->unk_14 = 1;
        unk_AC->unk_14 = 1;
        unk_A8->sub_0200EB34(0x20, FALSE);
        unk_AC->sub_0200EB34(0x20, FALSE);
        m_flags &= ~3;
        SetState(0x2D);
        break;
    case 45:
        ov3_021206E8(unk_A0);
        unk_B0->sub_0200F64C();
        if (m_flags & 3) {
            unk_96++;
            if (unk_96 >= 16) {
                if (m_flags & 1) {
                    SetState(0x2E);
                }
                if (m_flags & 2) {
                    SetState(0x2F);
                }
                unk_96 = 0;
            }
            if (unk_96 == 2) {
                unk_A0 = 0x1000;
            }
        } else if ((u16)(pad->unk_0002 & 1)) {
            unk_A0 = 0x1400;
            unk_A8->sub_0200EB34(1, FALSE);
            unk_AC->unk_14 = 0;
            m_flags |= 1;
            m_audioEngine->sub_02034C44(0xFF);
            unk_96 = 0;
        } else if ((u16)(pad->unk_0002 & 2)) {
            unk_A0 = 0x1400;
            unk_AC->sub_0200EB34(1, FALSE);
            unk_A8->unk_14 = 0;
            m_flags |= 2;
            m_audioEngine->sub_02034C44(0x100);
            unk_96 = 0;
        } else if (tp->unk_04 != 0) {
            if (sub_02006100(touch, unk_B4)) {
                unk_A0 = 0x1400;
                unk_A8->sub_0200EB34(1, FALSE);
                unk_AC->unk_14 = 0;
                m_flags |= 1;
                m_audioEngine->sub_02034C44(0xFF);
                unk_96 = 0;
            } else if (sub_02006100(touch, unk_C0)) {
                unk_A0 = 0x1400;
                unk_AC->sub_0200EB34(1, FALSE);
                unk_A8->unk_14 = 0;
                m_flags |= 2;
                m_audioEngine->sub_02034C44(0x100);
                unk_96 = 0;
            }
        }
        break;
    case 46:
        sub_02018E94((UnkClass_02018DF4 *)m_game->unk_14B4, 0);
        sub_02018E94((UnkClass_02018DF4 *)m_game->unk_14B4, 0x10);
        m_game->sub_0201024C();
        sub_02015198(save);
        unk_E8 = 0x13;
        SetState(0x35);
        break;
    case 47:
        SetState(0x27);
        break;
    case 48:
        m_audioEngine->sub_02034DC8(0);
        G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG1, 0);
        unk_A4->LoadToVram();
        ov3_021202E0();
        ov3_0212038C(unk_DC);
        m_audioEngine->sub_02034C44(2);
        SetState(0x31);
        break;
    case 49:
        if (tp->unk_04 != 0 || (u16)(pad->unk_0002 & 3)) {
            SetState(0x32);
        }
        break;
    case 50:
        G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG1, 0);
        unk_A4->LoadToVram();
        ov3_021202E0();
        ov3_0212038C(unk_DC);
        m_audioEngine->sub_02034C44(5);
        SetState(0x33);
        break;
    case 53:
        unk_DC = 0x41;
        break;
    case 54:
        unk_10++;
        if (unk_10 >= 30) {
            if (unk_F8 & 1) {
                unk_DC = 0x37;
            } else if (unk_F8 & 2) {
                unk_DC = 0x38;
            } else if (unk_F8 & 4) {
                unk_DC = 0x3B;
            } else {
                unk_DC = 0x41;
            }
        }
        break;
    case 55:
        G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG1, 0);
        unk_A4->LoadToVram();
        ov3_021202E0();
        ov3_0212038C(unk_DC);
        unk_E4->SetDevice(1);
        unk_E4->Clear(1);
        SetState(0x39);
        break;
    case 56:
        G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG1, 0);
        unk_A4->LoadToVram();
        ov3_021202E0();
        ov3_0212038C(unk_DC);
        unk_E4->SetDevice(1);
        unk_E4->Clear(1);
        SetState(0x39);
        break;
    case 57:
        if (unk_E4->sub_0202841C() != 0) {
            SetState(0x3A);
        }
        break;
    case 58:
        unk_E0 = unk_DC;
        if (unk_F8 & 4) {
            unk_DC = 0x3B;
        } else {
            unk_DC = 0x41;
        }
        break;
    case 59:
        G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG1, 0);
        unk_A4->LoadToVram();
        ov3_021202E0();
        ov3_0212038C(unk_DC);
        unk_E4->SetDevice(1);
        unk_E4->Clear(0);
        SetState(0x3C);
        break;
    case 60:
        if (unk_E4->sub_0202841C() != 0) {
            SetState(0x3D);
        }
        break;
    case 61:
        unk_E0 = unk_DC;
        if (unk_F8 & 8) {
            unk_DC = 0x3E;
        } else {
            unk_DC = 0x41;
        }
        break;
    case 62:
        G2S_SetBlendBrightness(GX_BLEND_PLANEMASK_BG1, 0);
        unk_A4->LoadToVram();
        ov3_021202E0();
        ov3_0212038C(unk_DC);
        unk_E4->SetDevice(1);
        unk_E4->Clear(0);
        SetState(0x3F);
        break;
    case 63:
        if (unk_E4->sub_0202841C() != 0) {
            SetState(0x40);
        }
        break;
    case 64:
        unk_DC = 0x41;
        break;
    case 65:
        m_game->unk_14BC->sub_0200E0E0(4, 30);
        m_game->unk_14C0->sub_0200E0E0(4, 30);
        m_audioEngine->sub_02034DC8(30);
        unk_DC = 0x42;
        break;
    case 66:
        if (!m_game->unk_14BC->sub_0200E310() && !m_game->unk_14C0->sub_0200E310()) {
            RTC_GetTime(&time);
            RTC_GetDate(&date);
            MAIN_BSS_020B26A0.unk_8B94 = time;
            MAIN_BSS_020B26A0.unk_8B84 = date;
            return unk_E8;
        }
        break;
    }
    return -1;
}

void CTitleScene::func1()
{
}

void CTitleScene::func2()
{
    int state = unk_DC;
    if (state == 0x35 || state == 0x36 || state == 0x41 || state == 0x42) {
        state = unk_E0;
    }
    switch (state) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 7:
    case 9:
    case 11:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 31:
    case 32:
    case 33:
    case 35:
    case 36:
    case 37:
    case 44:
    case 46:
    case 47:
    case 48:
        break;
    case 3:
        if (unk_E8 == -1) {
            unk_B0->sub_0200F71C();
        }
        break;
    case 6:
        unk_B0->sub_0200F71C();
        break;
    case 8:
        unk_D0->sub_0200F71C();
        break;
    case 10:
        unk_B0->sub_0200F71C();
        break;
    case 12:
        unk_D0->sub_0200F71C();
        break;
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
        unk_40->sub_0200F71C();
        if (m_flags & 0x200) {
            for (int i = 0; i < 4; i++) {
                unk_44[i]->sub_0200F71C();
            }
            unk_54->sub_0200F71C();
            unk_58->sub_0200F71C();
        }
        break;
    case 45:
        unk_B0->sub_0200F71C();
        break;
    case 24:
    case 30:
    case 34:
    case 38:
    case 49:
        unk_D0->sub_0200F71C();
        break;
    }
}

void CTitleScene::func3()
{
    sub_02007D98();
    if (m_bg != NULL) {
        m_bg->Apply();
    }
}

void CTitleScene::ov3_021202E0()
{
    TextWindow win = { 28, 4, 2, 19, 3, 2, 4 };
    UnkClass_0200CAB4 *printer = GetPrinter(m_game);
    printer->sub_0200CAE0();
    printer->sub_0200CB14();
    printer->sub_0200CC88(1);
    printer->sub_0200CACC(&m_game->unk_14AC->unk_0C, 1);
    printer->sub_0200CCD0(0, win.width, win.height, win.left, win.top, 0x20, 0, 4);
}

void CTitleScene::ov3_0212038C(int msg)
{
    TextWindow win = { 28, 4, 2, 19, 0, 2, 4 };
    UnkClass_0200CAB4 *printer = GetPrinter(m_game);
    printer->sub_0200CF7C(0);
    u8 *text = NULL;
    switch (msg) {
    case 2:
    case 3:
        text = unk_8C->unk_08[39].unk_04;
        break;
    case 7:
    case 8:
        text = unk_90->unk_08[117].unk_04;
        break;
    case 9:
    case 10:
        text = unk_90->unk_08[118].unk_04;
        break;
    case 11:
    case 12:
        text = unk_90->unk_08[119].unk_04;
        break;
    case 13:
    case 14:
        text = unk_90->unk_08[120].unk_04;
        break;
    case 5:
    case 6:
        text = unk_8C->unk_08[47].unk_04;
        break;
    case 15:
    case 16:
    case 17:
        text = unk_90->unk_08[105].unk_04;
        break;
    case 18:
    case 19:
    case 20:
        text = unk_8C->unk_08[47].unk_04;
        break;
    case 21:
    case 23:
        text = unk_90->unk_08[70].unk_04;
        break;
    case 27:
    case 29:
    case 30:
    case 33:
    case 34:
        text = unk_90->unk_08[71].unk_04;
        break;
    case 35:
        text = unk_90->unk_08[71].unk_04;
        break;
    case 37:
    case 38:
        text = unk_90->unk_08[72].unk_04;
        break;
    case 44:
    case 45:
        text = unk_8C->unk_08[38].unk_04;
        break;
    case 48:
    case 49:
        text = unk_90->unk_08[95].unk_04;
        break;
    case 50:
    case 51:
        text = unk_90->unk_08[96].unk_04;
        break;
    case 55:
    case 56:
    case 57:
        text = unk_90->unk_08[70].unk_04;
        break;
    case 59:
    case 60:
        text = unk_90->unk_08[71].unk_04;
        break;
    case 62:
    case 63:
        text = unk_90->unk_08[72].unk_04;
        break;
    }
    if (text != NULL) {
        printer->sub_0200CDA0(0, win.x, win.y, win.color, text, FALSE, 0);
    }
}

void CTitleScene::ov3_02120634()
{
    unk_A8 = unk_B0->sub_0200F4FC(0, 0x40, 0x60, 0);
    unk_98 = unk_B0->unk_24;
    unk_AC = unk_B0->sub_0200F4FC(1, 0xC0, 0x60, 0);
    unk_9C = unk_B0->unk_24;
}

void CTitleScene::ov3_0212069C()
{
    unk_CC = unk_D0->sub_0200F4FC(0, 0xF8, 0xB0, 0);
    unk_D4 = unk_D8->sub_0200F4FC(0, 0xF8, 0xB0, 0);
}

void CTitleScene::ov3_021206E8(int scale)
{
    MtxFx22 mtx;
    mtx._00 = scale;
    mtx._01 = 0;
    mtx._10 = 0;
    mtx._11 = scale;
    G2_SetOBJAffine((GXOamAffine *)&m_game->unk_0424[4], &mtx);
}

u32 CTitleScene::getSceneId()
{
    return 14;
}
