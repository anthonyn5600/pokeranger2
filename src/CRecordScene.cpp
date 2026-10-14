#include "scene/CRecordScene.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "AudioEngine.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "CTouchPanel.hpp"
#include "Collision.hpp"
#include "FontSet.hpp"
#include "NameTables.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "PadInput.hpp"
#include "SaveData.hpp"
#include "SubTextPrinter.hpp"
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
extern "C" u16 SaveData_GetBestPartner(SaveData *save);
extern "C" u8 sub_020171A0(SaveData *save);
extern "C" u8 *NameTables_GetPokemonName(NameTables *obj, u32 i);

#define LOAD_MESSAGES(table, path)                                                                         \
    {                                                                                                      \
        CBinaryFileMes *file = new CBinaryFileMes(path, 1);                                                \
        table = new UnkClass_020091E8_004();                                                               \
        u32 pos = 2;                                                                                       \
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

struct RecordWindow {
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

CRecordScene::CRecordScene()
{
    unk_10 = 0;
    unk_14 = 0;
    unk_04 = 0;
    unk_08 = 0;
    m_audioEngine = s_game->m_audioEngine;
    m_audioEngine->sub_020345D4();
    m_save = &MAIN_BSS_020B26A0;
}

CRecordScene::~CRecordScene()
{
    func7();
}

u32 CRecordScene::func0()
{
    unk_4C->Update();
    CTouchPanel *tp = s_game->touchPanel;
    Point2D touch;
    touch.x = (tp->unk_0A.x - 0x80) << FX32_SHIFT;
    touch.y = (tp->unk_0A.y - 0x60) << FX32_SHIFT;
    if (s_game->unk_14BC->IsActive() || s_game->unk_14BC->IsActive()) {
        return -1;
    }
    switch (unk_08) {
    case 0:
        unk_08 = 2;
        unk_04 = 0;
        break;
    case 1:
        ov23_0211CBDC();
        break;
    case 2:
        ov23_0211CC44(touch);
        break;
    case 3:
        ov23_0211CDD4(touch);
        break;
    case 4:
        switch (s_game->unk_0008) {
        case 0x1A:
            return 0x15;
        case 1:
            return 1;
        }
        return 0x22;
    }
    return -1;
}

void CRecordScene::ov23_0211CBDC()
{
    unk_08 = unk_0C;
    unk_04 = 0;
    unk_10 = 0;
    unk_14 = 0;
    s_game->unk_14BC->Start(3, 10);
    s_game->unk_14C0->Start(3, 10);
    ov23_0211D214();
}

void CRecordScene::ov23_0211CC44(Point2D touch)
{
    if ((unk_10 & 2) || (unk_14 & 2)) {
        if (unk_04 != 2) {
            unk_04++;
            return;
        }
        unk_08 = 1;
        unk_0C = 3;
        unk_04 = 0;
        unk_4C->SetAnim(unk_1C, 4);
        s_game->unk_14BC->Start(4, 10);
        s_game->unk_14C0->Start(4, 10);
        m_audioEngine->PlaySe(0xFA);
        return;
    }
    if ((u16)(s_game->unk_0014->unk_0002 & 0x10)) {
        unk_10 |= 2;
        unk_4C->SetAnim(unk_1C, 5);
    }
    if (s_game->touchPanel->unk_04 == 0) {
        return;
    }
    if (!PointInRect(touch, unk_50[1]->m_rectangle, 0)) {
        return;
    }
    unk_14 |= 2;
    unk_4C->SetAnim(unk_1C, 5);
}

void CRecordScene::ov23_0211CDD4(Point2D touch)
{
    PadInput *keys = s_game->unk_0014;
    CTouchPanel *tp = s_game->touchPanel;
    if ((unk_10 & 1) || (unk_14 & 1)) {
        if (unk_04 != 2) {
            unk_04++;
        } else {
            unk_08 = 4;
            unk_04 = 0;
            unk_4C->SetAnim(unk_18, 0);
            s_game->unk_14BC->Start(4, 60);
            s_game->unk_14C0->Start(4, 60);
            m_audioEngine->PlaySe(0x103);
        }
    } else if (!(unk_10 & 4) && !(unk_14 & 4)) {
        if ((u16)(keys->unk_0002 & 2)) {
            unk_10 |= 1;
            unk_4C->SetAnim(unk_18, 1);
        }
        if (tp->unk_04 != 0 && PointInRect(touch, unk_50[0]->m_rectangle, 0)) {
            unk_14 |= 1;
            unk_4C->SetAnim(unk_18, 1);
        }
    }
    if ((unk_10 & 4) || (unk_14 & 4)) {
        if (unk_04 != 2) {
            unk_04++;
            return;
        }
        unk_08 = 1;
        unk_0C = 2;
        unk_04 = 0;
        unk_4C->SetAnim(unk_20, 2);
        s_game->unk_14BC->Start(4, 10);
        s_game->unk_14C0->Start(4, 10);
        m_audioEngine->PlaySe(0xFA);
        return;
    }
    if (unk_10 & 1) {
        return;
    }
    if (unk_14 & 1) {
        return;
    }
    if ((u16)(keys->unk_0002 & 0x20)) {
        unk_10 |= 4;
        unk_4C->SetAnim(unk_20, 3);
    }
    if (tp->unk_04 == 0) {
        return;
    }
    if (!PointInRect(touch, unk_50[2]->m_rectangle, 0)) {
        return;
    }
    unk_14 |= 4;
    unk_4C->SetAnim(unk_20, 3);
}

void CRecordScene::func1()
{
    unk_4C->WriteOam();
}

void CRecordScene::func2()
{
}

void CRecordScene::func5()
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

    GX_SetBankForOBJ(GX_VRAM_OBJ_256_AB);
    GX_SetBankForBG(GX_VRAM_BG_128_D);
    GX_SetGraphicsMode(GX_DISPMODE_GRAPHICS, GX_BGMODE_0, GX_BG0_AS_2D);
    GX_SetBankForSubBG(GX_VRAM_SUB_BG_128_C);
    GX_SetBankForSubOBJ(GX_VRAM_SUB_OBJ_16_I);

    G2_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 0, 0);
    G3X_AlphaBlend(TRUE);
    G3X_AntiAlias(TRUE);
    GX_SetPower(GX_POWER_ALL);
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG1);
    G2_SetBG0Priority(0);
    G2_SetBG1Priority(1);
    G2_SetBG2Priority(3);
    G2_SetBG3Priority(2);
    GX_DispOn();
    GXS_DispOn();
}

void CRecordScene::ov23_0211D214()
{
    if (unk_08 == 0) {
        ov23_0211D270();
        ov23_0211DEB8();
        return;
    }
    switch (unk_0C) {
    case 2:
        ov23_0211D270();
        ov23_0211DEB8();
        break;
    case 3:
        ov23_0211D870();
        ov23_0211DEDC();
        break;
    }
}

void CRecordScene::ov23_0211D270()
{
    {
        int ofs;
        int i;
        RecordWindow upper[8] = {
            { 16, 2, 8, 1, 4, 4, 1, 0, 2 },
            { 10, 2, 18, 5, 4, 4, 9, 0, 2 },
            { 24, 2, 4, 9, 4, 4, 3, 0, 2 },
            { 24, 2, 4, 14, 4, 4, 3, 0, 2 },
            { 24, 2, 4, 19, 4, 4, 3, 0, 2 },
            { 10, 2, 18, 11, 4, 4, 9, 0, 2 },
            { 7, 2, 21, 16, 2, 4, 9, 0, 2 },
            { 7, 2, 21, 21, 2, 4, 9, 0, 2 },
        };
        SubTextPrinter *top = s_game->unk_1498;
        top->FreeWindows();
        top->SetupBG();
        top->AllocWindows(0x16);
        ofs = 0x40;
        for (i = 0; i < 8; i++) {
            top->InitWindow(i, upper[i].width, upper[i].height, upper[i].left, upper[i].top, ofs, upper[i].hSpace, upper[i].vSpace);
            ofs += upper[i].width * upper[i].height;
        }
        top->Print(0, upper[0].x, upper[0].y, upper[0].color, m_recodeMes->unk_08[1].unk_04, TRUE, 0);
        u8 *str = m_recodeMes->unk_08[2].unk_04;
        top->Print(1, top->GetRemainingWidth(1, str, 0), upper[1].y, upper[1].color, str, FALSE, 0);
        top->Print(2, upper[2].x, upper[2].y, upper[2].color, m_recodeMes->unk_08[3].unk_04, FALSE, 0);
        top->Print(3, upper[3].x, upper[3].y, upper[3].color, m_recodeMes->unk_08[4].unk_04, FALSE, 0);
        top->Print(4, upper[4].x, upper[4].y, upper[4].color, m_recodeMes->unk_08[5].unk_04, FALSE, 0);
        ov23_0211E818(7, m_save->m_stepsWalked);
        top->Print(5, top->GetRemainingWidth(5, (u8 *)unk_24, 0), upper[5].y, upper[5].color, (u8 *)unk_24, FALSE, 0);
        ov23_0211E818(5, m_save->m_conversations);
        top->Print(6, top->GetRemainingWidth(6, (u8 *)unk_24, 0), upper[6].y, upper[6].color, (u8 *)unk_24, FALSE, 0);
        ov23_0211E818(5, m_save->m_targetsChecked);
        top->Print(7, top->GetRemainingWidth(7, (u8 *)unk_24, 0), upper[7].y, upper[7].color, (u8 *)unk_24, FALSE, 0);
    }
    {
        int ofs;
        int i;
        RecordWindow lower[8] = {
            { 24, 2, 4, 1, 4, 4, 3, 0, 2 },
            { 24, 2, 4, 6, 4, 4, 3, 0, 2 },
            { 24, 2, 4, 11, 4, 4, 3, 0, 2 },
            { 24, 2, 4, 16, 4, 4, 3, 0, 2 },
            { 7, 2, 21, 3, 2, 4, 9, 0, 2 },
            { 7, 2, 21, 8, 2, 4, 9, 0, 2 },
            { 7, 2, 21, 13, 2, 4, 9, 0, 2 },
            { 7, 2, 21, 18, 2, 4, 9, 0, 2 },
        };
        TextPrinter *text = s_game->unk_1494;
        text->FreeWindows();
        text->SetupBG(0, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x00000);
        text->AllocWindows(0x18);
        ofs = 0x40;
        for (i = 0; i < 8; i++) {
            text->InitWindow(i, lower[i].width, lower[i].height, lower[i].left, lower[i].top, ofs, lower[i].hSpace, lower[i].vSpace);
            ofs += lower[i].width * lower[i].height;
        }
        text->Print(0, lower[0].x, lower[0].y, lower[0].color, m_recodeMes->unk_08[6].unk_04, FALSE, 0);
        text->Print(1, lower[1].x, lower[1].y, lower[1].color, m_recodeMes->unk_08[7].unk_04, FALSE, 0);
        text->Print(2, lower[2].x, lower[2].y, lower[2].color, m_recodeMes->unk_08[8].unk_04, FALSE, 0);
        text->Print(3, lower[3].x, lower[3].y, lower[3].color, m_recodeMes->unk_08[9].unk_04, FALSE, 0);
        ov23_0211E818(5, m_save->m_saveCount);
        text->Print(4, text->GetRemainingWidth(4, (u8 *)unk_24, 0), lower[4].y, lower[4].color, (u8 *)unk_24, FALSE, 0);
        ov23_0211E818(5, m_save->m_pokemonRides);
        text->Print(5, text->GetRemainingWidth(5, (u8 *)unk_24, 0), lower[5].y, lower[5].color, (u8 *)unk_24, FALSE, 0);
        ov23_0211E8A8(sub_020171A0(m_save));
        text->Print(6, text->GetRemainingWidth(6, (u8 *)unk_24, 0), lower[6].y, lower[6].color, (u8 *)unk_24, FALSE, 0);
        int hours = 99;
        int minutes = 59;
        if (m_save->unk_87DA == 0) {
            minutes = m_save->m_playMinutes;
            hours = m_save->m_playHours;
        }
        ov23_0211E940(hours, minutes);
        text->Print(7, text->GetRemainingWidth(7, (u8 *)unk_24, 0), lower[7].y, lower[7].color, (u8 *)unk_24, FALSE, 0);
    }
}

void CRecordScene::ov23_0211D870()
{
    u8 *name;
    u16 nameId = SaveData_GetBestPartner(m_save);
    if (nameId == 0) {
        name = m_recodeMes->unk_08[0x12].unk_04;
    } else {
        name = NameTables_GetPokemonName(s_game->unk_14B0, nameId);
    }
    {
        int ofs;
        int i;
        RecordWindow upper[8] = {
            { 16, 2, 8, 1, 4, 4, 1, 0, 2 },
            { 10, 2, 18, 5, 4, 4, 9, 0, 2 },
            { 24, 2, 4, 9, 4, 4, 3, 0, 2 },
            { 24, 2, 4, 14, 4, 4, 3, 0, 2 },
            { 24, 2, 4, 19, 4, 4, 3, 0, 2 },
            { 0, 2, 0, 11, 4, 4, 9, 0, 2 },
            { 6, 2, 22, 16, 2, 4, 9, 0, 2 },
            { 6, 2, 22, 21, 2, 4, 9, 0, 2 },
        };
        upper[5].width = 24;
        upper[5].left = 4;
        SubTextPrinter *top = s_game->unk_1498;
        top->FreeWindows();
        top->SetupBG();
        top->AllocWindows(0x10);
        ofs = 0x40;
        for (i = 0; i < 8; i++) {
            top->InitWindow(i, upper[i].width, upper[i].height, upper[i].left, upper[i].top, ofs, upper[i].hSpace, upper[i].vSpace);
            ofs += upper[i].width * upper[i].height;
        }
        top->Print(0, upper[0].x, upper[0].y, upper[0].color, m_recodeMes->unk_08[1].unk_04, TRUE, 0);
        u8 *str = m_recodeMes->unk_08[10].unk_04;
        top->Print(1, top->GetRemainingWidth(1, str, 0), upper[1].y, upper[1].color, str, FALSE, 0);
        top->Print(2, upper[2].x, upper[2].y, upper[2].color, m_recodeMes->unk_08[11].unk_04, FALSE, 0);
        top->Print(3, upper[3].x, upper[3].y, upper[3].color, m_recodeMes->unk_08[12].unk_04, FALSE, 0);
        top->Print(4, upper[4].x, upper[4].y, upper[4].color, m_recodeMes->unk_08[13].unk_04, FALSE, 0);
        top->Print(5, top->GetRemainingWidth(5, name, 0), upper[5].y, upper[5].color, name, FALSE, 0);
        u16 value = m_save->m_totalCaptures;
        ov23_0211DF00();
        ov23_0211E818(4, value);
        top->Print(6, top->GetRemainingWidth(6, (u8 *)unk_24, 0), upper[6].y, upper[6].color, (u8 *)unk_24, FALSE, 0);
        ov23_0211E818(4, m_save->m_fledCount);
        top->Print(7, top->GetRemainingWidth(7, (u8 *)unk_24, 0), upper[7].y, upper[7].color, (u8 *)unk_24, FALSE, 0);
    }
    {
        int ofs;
        int i;
        RecordWindow lower[28] = {
            { 24, 2, 4, 1, 4, 4, 3, 0, 2 },
            { 24, 2, 4, 6, 4, 4, 3, 0, 2 },
            { 24, 2, 4, 11, 4, 4, 3, 0, 2 },
            { 24, 2, 4, 16, 4, 4, 3, 0, 2 },
            { 6, 2, 22, 3, 2, 4, 9, 0, 2 },
            { 9, 2, 19, 8, 6, 4, 9, 0, 2 },
            { 9, 2, 19, 13, 6, 4, 9, 0, 2 },
            { 10, 2, 18, 18, 4, 4, 9, 0, 2 },
        };
        TextPrinter *text = s_game->unk_1494;
        text->FreeWindows();
        text->SetupBG(0, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x00000);
        text->AllocWindows(0x1C);
        ofs = 0x40;
        for (i = 0; i < 8; i++) {
            text->InitWindow(i, lower[i].width, lower[i].height, lower[i].left, lower[i].top, ofs, lower[i].hSpace, lower[i].vSpace);
            ofs += lower[i].width * lower[i].height;
        }
        text->Print(0, lower[0].x, lower[0].y, lower[0].color, m_recodeMes->unk_08[14].unk_04, FALSE, 0);
        text->Print(1, lower[1].x, lower[1].y, lower[1].color, m_recodeMes->unk_08[15].unk_04, FALSE, 0);
        text->Print(2, lower[2].x, lower[2].y, lower[2].color, m_recodeMes->unk_08[16].unk_04, FALSE, 0);
        text->Print(3, lower[3].x, lower[3].y, lower[3].color, m_recodeMes->unk_08[17].unk_04, FALSE, 0);
        ov23_0211E818(4, m_save->m_assistsUsed);
        text->Print(4, text->GetRemainingWidth(4, (u8 *)unk_24, 0), lower[4].y, lower[4].color, (u8 *)unk_24, FALSE, 0);
        ov23_0211E818(6, m_save->m_captureLineLength * 0x21 / 0x1E0);
        text->Print(5, text->GetRemainingWidth(5, (u8 *)unk_24, 0), lower[5].y, lower[5].color, (u8 *)unk_24, FALSE, 0);
        ov23_0211E818(6, m_save->m_loopCount);
        text->Print(6, text->GetRemainingWidth(6, (u8 *)unk_24, 0), lower[6].y, lower[6].color, (u8 *)unk_24, FALSE, 0);
        ov23_0211E818(7, m_save->m_exp);
        text->Print(7, text->GetRemainingWidth(7, (u8 *)unk_24, 0), lower[7].y, lower[7].color, (u8 *)unk_24, FALSE, 0);
    }
}

void CRecordScene::ov23_0211DEB8()
{
    unk_44->unk_14 = TRUE;
    unk_48->unk_14 = FALSE;
    unk_40->unk_14 = FALSE;
}

void CRecordScene::ov23_0211DEDC()
{
    unk_44->unk_14 = FALSE;
    unk_48->unk_14 = TRUE;
    unk_40->unk_14 = TRUE;
}

void CRecordScene::ov23_0211DF00()
{
    for (int i = 0; i < 0x15; i++) {
        unk_24[i] = 0;
    }
}

void CRecordScene::func6()
{
    unk_04 = 0;
    unk_08 = 0;
    CGame *game = s_game;
    game->m_textboxData->Init(game->unk_0014, game->touchPanel, &game->unk_14AC->unk_0C, game->unk_14B0, game->unk_0024, game->m_audioEngine, 0x10, 0x4000, 0);
    ov23_0211E19C();
    ov23_0211E454();
    ov23_0211E668();
    ov23_0211E75C();
    ov23_0211D214();
    s_game->unk_14BC->Start(3, 60);
    s_game->unk_14C0->Start(3, 60);
}

void CRecordScene::func7()
{
    SAFE_DELETE(unk_4C);
    for (int i = 0; i < 3; i++) {
        SAFE_DELETE(unk_50[i]);
    }
    RELEASE_MESSAGES(m_recodeMes);
    RELEASE_MESSAGES(m_menuMes);
    s_game->m_textboxData->Reset();
}

void CRecordScene::ov23_0211E19C()
{
    CArchiveGuard *archive = new CArchiveGuard("BGU", "data/menu/mre000_bg_LZ.bin", 1, 1, 0, NULL, 0);
    CBGNCGRFile *ncgr = new CBGNCGRFile("BGU:mre000.NCGR", 1, 0, 0);
    CNCLRFile *nclr = new CNCLRFile("BGU:mre000.NCLR", 1, 0, 0);
    CNSCRFile *nscr = new CNSCRFile("BGU:mre000_00.NSCR", 1, 0, 0);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB1, nscr->unk_B8, ncgr->unk_B8, nclr->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x00000);
    delete nscr;
    delete ncgr;
    delete nclr;
    delete archive;

    archive = new CArchiveGuard("BGD", "data/menu/mre001_bg_LZ.bin", 1, 1, 0, NULL, 0);
    ncgr = new CBGNCGRFile("BGD:mre001.NCGR", 1, 0, 0);
    nclr = new CNCLRFile("BGD:mre001.NCLR", 1, 0, 0);
    nscr = new CNSCRFile("BGD:mre001_00.NSCR", 1, 0, 0);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_MAIN2, nscr->unk_B8, ncgr->unk_B8, nclr->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x7000, GX_BG_CHARBASE_0x04000);
    delete nscr;
    delete ncgr;
    delete nclr;
    delete archive;
}

void CRecordScene::ov23_0211E454()
{
    LOAD_MESSAGES(m_recodeMes, "/data/message/etc/recode_mes");
    LOAD_MESSAGES(m_menuMes, "data/message/etc/menu_mes");
}

void CRecordScene::ov23_0211E668()
{
    unk_4C = new OamSpriteSet((GXOamAttr *)&s_game->unk_0024[0], s_game->unk_14A8, FALSE, 0x40);
    unk_4C->Load("data/menu", "mre000_00", 0, 4);
    unk_40 = unk_4C->AddSprite(0, 0xD8, 0xAC, 0);
    unk_18 = unk_4C->unk_24;
    unk_44 = unk_4C->AddSprite(4, 0xF5, 0x60, 0);
    unk_1C = unk_4C->unk_24;
    unk_48 = unk_4C->AddSprite(2, 0xB, 0x60, 0);
    unk_20 = unk_4C->unk_24;
}

void CRecordScene::ov23_0211E75C()
{
    unk_50[0] = new CPrimitiveRECT();
    unk_50[0]->SetPos(FX32_CONST(88), FX32_CONST(76));
    unk_50[0]->SetSize(FX32_CONST(64), FX32_CONST(32));
    unk_50[1] = new CPrimitiveRECT();
    unk_50[1]->SetPos(FX32_CONST(117), 0);
    unk_50[1]->SetSize(FX32_CONST(32), FX32_CONST(32));
    unk_50[2] = new CPrimitiveRECT();
    unk_50[2]->SetPos(FX32_CONST(-117), 0);
    unk_50[2]->SetSize(FX32_CONST(32), FX32_CONST(32));
}

void CRecordScene::ov23_0211E818(int digits, u32 value)
{
    MI_CpuFill8(unk_24, 0, sizeof(unk_24));
    for (int i = 0; i < digits; i++) {
        unk_24[digits - 1 - i] = (int)value / ov23_0211EA18(i, 10) % 10 + '0';
    }
}

void CRecordScene::ov23_0211E8A8(int value)
{
    MI_CpuFill8(unk_24, 0, sizeof(unk_24));
    for (int i = 0; i < 2; i++) {
        unk_24[1 - i] = value / ov23_0211EA18(i, 10) % 10 + '0';
    }
    unk_24[2] = '/';
    unk_24[3] = '6';
    unk_24[4] = '0';
}

void CRecordScene::ov23_0211E940(int hours, int minutes)
{
    int i;
    for (i = 0; i < 2; i++) {
        unk_24[4 - i] = minutes / ov23_0211EA18(i, 10) % 10 + '0';
    }
    unk_24[2] = ':';
    for (i = 3; i < 5; i++) {
        unk_24[4 - i] = hours / ov23_0211EA18(i - 3, 10) % 10 + '0';
    }
}

int CRecordScene::ov23_0211EA18(int exp, int base)
{
    if (exp == 0) {
        return 1;
    }
    return base * ov23_0211EA18(exp - 1, base);
}

u32 CRecordScene::getSceneId()
{
    return 0x18;
}
