#include "SubScreenRangerCard.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "CGame.hpp"
#include "DiskHPTable.hpp"
#include "NameTables.hpp"
#include "SaveData.hpp"
#include "SubTextPrinter.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBinaryFileMes.hpp"
#include "file/CNSCRFile.hpp"

extern "C" {
u8 *NameTables_GetFieldMoveName(NameTables *obj, u32 i);
u8 *NameTables_GetPokemonName(NameTables *obj, u32 i);
void sub_0202BC74(const u8 *src, u8 *dst, int len);
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

extern "C" s32 GlobalValues_Get(void *obj, int index);

static inline u32 GetPokemonState(SaveData *save, int i)
{
    if (i >= 0 && i < 500) {
        return (save->m_pokemonStates[i >> 4] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

static inline int CountPokemon(SaveData *save)
{
    int n = 0;
    for (int i = 0; i < 500; i++) {
        if (GetPokemonState(save, i) >= 2) {
            n++;
        }
    }
    return n;
}

#define OAM_SET(i) new OamSpriteSet((GXOamAttr *)&game->unk_0424[i], game->unk_14A8, TRUE, 0x40)

SubScreenRangerCard::SubScreenRangerCard()
{
    unk_00 = 0;
    unk_04 = 0;
    unk_08 = 0;
    unk_0C = 0;
    unk_10 = 0;
    unk_14 = 0;
    unk_18 = 0;
    unk_1C = 0;
    unk_20 = 0;
    unk_24 = 0;
    unk_28 = NULL;
    unk_2C = NULL;
    unk_30 = NULL;
    unk_34 = NULL;
    unk_38 = NULL;
    unk_3C = NULL;
}

SubScreenRangerCard::~SubScreenRangerCard()
{
    Release();
}

void SubScreenRangerCard::Release()
{
    CGame *game = CGame::GetInstance();

    RELEASE_MESSAGES(unk_3C);
    SAFE_DELETE(unk_28);
    SAFE_DELETE(unk_2C);
    SAFE_DELETE(unk_30);
    SAFE_DELETE(unk_34);

    game->unk_1498->FreeWindows();
}

int SubScreenRangerCard::LoadStep(int step)
{
    int next = step + 1;
    CGame *game = CGame::GetInstance();
    u32 pos;

    switch (step) {
    case 0: {
        unk_04 = 0;
        unk_08 = 0;
        SaveData *save = &MAIN_BSS_020B26A0;
        unk_20 = ((u8 *)game->m_missionQuestData)[0];
        unk_24 = ((u8 *)game->m_missionQuestData)[1];
        unk_00 = save->m_sex;
        unk_0C = save->m_rangerClassGrade & 0xF;
        unk_10 = (save->m_rangerClassGrade >> 4) & 0xF;
        unk_14 = save->m_stylerLevel;
        unk_1C = save->m_levelExp;
        unk_18 = DiskHPTable_GetExp(game->m_diskHPTable, unk_14);
        int n = CountPokemon(save);
        if (GetPokemonState(save, 483) == 2) {
            n--;
        }
        if (GetPokemonState(save, 484) == 2) {
            n--;
        }
        if (GetPokemonState(save, 492) == 2) {
            n--;
        }
        unk_08 = n == 267;
        unk_04 = (GlobalValues_Get(game->unk_14B4, 30) >> 3) & 1;
        LOAD_MESSAGES(unk_3C, "/data/message/etc/menu_mes");
        break;
    }
    case 1:
        unk_40 = 0;
        unk_28 = OAM_SET(0x00);
        if (unk_10 == 0) {
            if (unk_00 == 0) {
                unk_40 += unk_28->Load("data/menu", "mp003_00", unk_40 / 32, 0);
            } else {
                unk_40 += unk_28->Load("data/menu", "mp004_00", unk_40 / 32, 0);
            }
        } else if (unk_10 == 1) {
            if (unk_00 == 0) {
                unk_40 += unk_28->Load("data/menu", "mp005_00", unk_40 / 32, 0);
            } else {
                unk_40 += unk_28->Load("data/menu", "mp006_00", unk_40 / 32, 0);
            }
        } else {
            if (unk_00 == 0) {
                unk_40 += unk_28->Load("data/menu", "mp007_00", unk_40 / 32, 0);
            } else {
                unk_40 += unk_28->Load("data/menu", "mp008_00", unk_40 / 32, 0);
            }
        }
        unk_28->AddSprite(0, 0xD0, 0x5B, 0);
        break;
    case 2:
        unk_2C = OAM_SET(0x10);
        unk_40 += unk_2C->Load("data/menu", "mp001_00", unk_40 / 32, 2);
        if (unk_04) {
            unk_2C->AddSprite(0xC, 0x10, 0x11, 0);
        }
        if (unk_08) {
            unk_2C->AddSprite(0xD, 0x23, 0x11, 0);
        }
        unk_2C->AddSprite(unk_14 / 10, 0x78, 0x80, 0);
        unk_2C->AddSprite(unk_14 % 10, 0x88, 0x80, 0);
        unk_2C->AddSprite(0x11, 0x50, 0x88, 1);
        if (unk_20) {
            unk_2C->AddSprite(0xA, 0x72, 0xAB, 1);
        }
        if (unk_24) {
            unk_2C->AddSprite(0xB, 0x8E, 0xAB, 1);
        }
        unk_2C->AddSprite(0xF, 0x40, 0xAB, 1);
        unk_2C->AddSprite(0xE, 0xC0, 0xAB, 1);
        unk_2C->AddSprite(0x10, 0x38, 0x27, 1);
        unk_2C->AddSprite(0x10, 0x38, 0x80, 1);
        break;
    case 3:
        unk_30 = OAM_SET(0x3C);
        unk_40 += unk_30->Load("data/menu", "ma003_00", unk_40 / 32, 7);
        for (int i = 0; i < unk_0C; i++) {
            switch (i) {
            case 0:
                unk_30->AddSprite(0, 0x14, 0x40, 0);
                break;
            case 1:
                unk_30->AddSprite(1, 0x2C, 0x40, 0);
                break;
            case 2:
                unk_30->AddSprite(2, 0x44, 0x40, 0);
                break;
            case 3:
                unk_30->AddSprite(3, 0x5C, 0x40, 0);
                break;
            case 4:
                unk_30->AddSprite(4, 0x74, 0x40, 0);
                break;
            case 5:
                unk_30->AddSprite(5, 0x24, 0x60, 0);
                break;
            case 6:
                unk_30->AddSprite(6, 0x3C, 0x60, 0);
                break;
            case 7:
                unk_30->AddSprite(7, 0x54, 0x60, 0);
                break;
            case 8:
                unk_30->AddSprite(8, 0x6C, 0x60, 0);
                break;
            case 9:
                unk_30->AddSprite(9, 0x84, 0x60, 0);
                break;
            }
        }
        break;
    case 4:
        unk_34 = OAM_SET(0x6E);
        unk_40 += unk_34->Load("data/menu", "ma004_00", unk_40 / 32, 8);
        unk_38 = unk_34->AddSprite(0, 0x80, -8, 3);
        unk_44 = 0;
        break;
    case 5:
        unk_44 = LoadBG(unk_44);
        if (unk_44 != -1) {
            next = 5;
        }
        break;
    case 6:
        SetupBlend();
        DrawTexts();
        DrawGauge();
        next = -1;
        break;
    }

    return next;
}

void SubScreenRangerCard::LoadAll()
{
    CGame *game = CGame::GetInstance();
    u32 pos;

    unk_04 = 0;
    unk_08 = 0;
    SaveData *save = &MAIN_BSS_020B26A0;
    unk_20 = ((u8 *)game->m_missionQuestData)[0];
    unk_24 = ((u8 *)game->m_missionQuestData)[1];
    unk_00 = save->m_sex;
    unk_0C = save->m_rangerClassGrade & 0xF;
    unk_10 = (save->m_rangerClassGrade >> 4) & 0xF;
    unk_14 = save->m_stylerLevel;
    unk_1C = save->m_levelExp;
    unk_18 = DiskHPTable_GetExp(game->m_diskHPTable, unk_14);
    int i;
    int n = 0;
    for (i = 0; i < 500; i++) {
        if (GetPokemonState(save, i) >= 2) {
            n++;
        }
    }
    if (GetPokemonState(save, 483) == 2) {
        n--;
    }
    if (GetPokemonState(save, 484) == 2) {
        n--;
    }
    if (GetPokemonState(save, 492) == 2) {
        n--;
    }
    unk_08 = n == 267;
    unk_04 = (GlobalValues_Get(game->unk_14B4, 30) >> 3) & 1;
    LOAD_MESSAGES(unk_3C, "/data/message/etc/menu_mes");

    int charNo = 0;
    unk_28 = OAM_SET(0x00);
    if (unk_10 == 0) {
        if (unk_00 == 0) {
            charNo += unk_28->Load("data/menu", "mp003_00", charNo / 32, 0);
        } else {
            charNo += unk_28->Load("data/menu", "mp004_00", charNo / 32, 0);
        }
    } else if (unk_10 == 1) {
        if (unk_00 == 0) {
            charNo += unk_28->Load("data/menu", "mp005_00", charNo / 32, 0);
        } else {
            charNo += unk_28->Load("data/menu", "mp006_00", charNo / 32, 0);
        }
    } else {
        if (unk_00 == 0) {
            charNo += unk_28->Load("data/menu", "mp007_00", charNo / 32, 0);
        } else {
            charNo += unk_28->Load("data/menu", "mp008_00", charNo / 32, 0);
        }
    }
    unk_28->AddSprite(0, 0xD0, 0x5B, 0);

    unk_2C = OAM_SET(0x10);
    charNo += unk_2C->Load("data/menu", "mp001_00", charNo / 32, 2);
    if (unk_04) {
        unk_2C->AddSprite(0xC, 0x10, 0x11, 0);
    }
    if (unk_08) {
        unk_2C->AddSprite(0xD, 0x23, 0x11, 0);
    }
    unk_2C->AddSprite(unk_14 / 10, 0x78, 0x80, 0);
    unk_2C->AddSprite(unk_14 % 10, 0x88, 0x80, 0);
    unk_2C->AddSprite(0x11, 0x50, 0x88, 1);
    if (unk_20) {
        unk_2C->AddSprite(0xA, 0x72, 0xAB, 1);
    }
    if (unk_24) {
        unk_2C->AddSprite(0xB, 0x8E, 0xAB, 1);
    }
    unk_2C->AddSprite(0xF, 0x40, 0xAB, 1);
    unk_2C->AddSprite(0xE, 0xC0, 0xAB, 1);
    unk_2C->AddSprite(0x10, 0x38, 0x27, 1);
    unk_2C->AddSprite(0x10, 0x38, 0x80, 1);

    unk_30 = OAM_SET(0x3C);
    charNo += unk_30->Load("data/menu", "ma003_00", charNo / 32, 7);
    for (int i = 0; i < unk_0C; i++) {
        switch (i) {
        case 0:
            unk_30->AddSprite(0, 0x14, 0x40, 0);
            break;
        case 1:
            unk_30->AddSprite(1, 0x2C, 0x40, 0);
            break;
        case 2:
            unk_30->AddSprite(2, 0x44, 0x40, 0);
            break;
        case 3:
            unk_30->AddSprite(3, 0x5C, 0x40, 0);
            break;
        case 4:
            unk_30->AddSprite(4, 0x74, 0x40, 0);
            break;
        case 5:
            unk_30->AddSprite(5, 0x24, 0x60, 0);
            break;
        case 6:
            unk_30->AddSprite(6, 0x3C, 0x60, 0);
            break;
        case 7:
            unk_30->AddSprite(7, 0x54, 0x60, 0);
            break;
        case 8:
            unk_30->AddSprite(8, 0x6C, 0x60, 0);
            break;
        case 9:
            unk_30->AddSprite(9, 0x84, 0x60, 0);
            break;
        }
    }

    unk_34 = OAM_SET(0x6E);
    charNo += unk_34->Load("data/menu", "ma004_00", charNo / 32, 8);
    unk_38 = unk_34->AddSprite(0, 0x80, -8, 3);

    LoadBGAll();
    SetupBlend();
    DrawTexts();
    DrawGauge();
}

int SubScreenRangerCard::LoadBG(int step)
{
    int next = step + 1;

    switch (step) {
    case 0:
        unk_48 = new CArchiveGuard("BGS", "data/menu/mp000_bg_LZ.bin", 0, 1, 0, NULL, 0);
        break;
    case 1:
        unk_4C = new CBGNCGRFile("BGS:mp000.NCGR", 0, 0, 0);
        break;
    case 2:
        unk_50 = new CNCLRFile("BGS:mp000.NCLR", 0, 0, 0);
        break;
    case 3: {
        CNSCRFile *scr = new CNSCRFile("BGS:mp000_00.NSCR", 0, 0, 0);
        NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB1, scr->unk_B8, unk_4C->unk_B8, unk_50->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x00000);
        SAFE_DELETE(scr);
        break;
    }
    case 4: {
        CNSCRFile *scr = new CNSCRFile("BGS:mp000_01.NSCR", 0, 0, 0);
        NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB2, scr->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7000, GX_BG_CHARBASE_0x00000);
        SAFE_DELETE(scr);
        break;
    }
    case 5: {
        CNSCRFile *scr = new CNSCRFile("BGS:mp000_02.NSCR", 0, 0, 0);
        NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB3, scr->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7800, GX_BG_CHARBASE_0x00000);
        SAFE_DELETE(scr);
        SAFE_DELETE(unk_4C);
        SAFE_DELETE(unk_50);
        SAFE_DELETE(unk_48);
        next = -1;
        break;
    }
    }

    return next;
}

void SubScreenRangerCard::LoadBGAll()
{
    CArchiveGuard *archive = new CArchiveGuard("BGS", "data/menu/mp000_bg_LZ.bin", 0, 1, 0, NULL, 0);
    CBGNCGRFile *ncgr = new CBGNCGRFile("BGS:mp000.NCGR", 0, 0, 0);
    CNCLRFile *nclr = new CNCLRFile("BGS:mp000.NCLR", 0, 0, 0);
    CNSCRFile *scr1 = new CNSCRFile("BGS:mp000_00.NSCR", 0, 0, 0);
    CNSCRFile *scr2 = new CNSCRFile("BGS:mp000_01.NSCR", 0, 0, 0);
    CNSCRFile *scr3 = new CNSCRFile("BGS:mp000_02.NSCR", 0, 0, 0);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB1, scr1->unk_B8, ncgr->unk_B8, nclr->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x00000);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB2, scr2->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7000, GX_BG_CHARBASE_0x00000);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB3, scr3->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7800, GX_BG_CHARBASE_0x00000);
    SAFE_DELETE(scr1);
    SAFE_DELETE(scr2);
    SAFE_DELETE(scr3);
    SAFE_DELETE(ncgr);
    SAFE_DELETE(nclr);
    SAFE_DELETE(archive);
}

void SubScreenRangerCard::SetupBlend()
{
    GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    G2S_SetBG1Priority(1);
    G2S_SetBG2Priority(2);
    G2S_SetBG3Priority(3);
    G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_BG1, GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ, 8, 8);
}

void SubScreenRangerCard::DrawTexts()
{
    TextWindow windows[6] = {
        { 16, 2, 8, 1, 0, 0, 1 },
        { 12, 2, 0, 4, 2, 3, 3 },
        { 12, 2, 0, 15, 2, 4, 3 },
        { 10, 2, 2, 20, 4, 6, 3 },
        { 10, 2, 20, 20, 4, 6, 3 },
        { 16, 2, 3, 18, 60, 0, 3 },
    };
    CGame *game = CGame::GetInstance();

    game->unk_1498->FreeWindows();
    game->unk_1498->SetupBG();
    game->unk_1498->AllocWindows(6);

    int charNo = 0x60;
    for (int i = 0; i < 6; i++) {
        game->unk_1498->InitWindow(i, windows[i].width, windows[i].height, windows[i].left, windows[i].top, charNo, 0, 2);
        charNo += windows[i].width * windows[i].height;
    }

    game->unk_1498->Print(0, windows[0].x, windows[0].y, windows[0].color, &MAIN_BSS_020B26A0.m_playerName, TRUE, 4);
    game->unk_1498->Print(1, windows[1].x, windows[1].y, windows[1].color, unk_3C->unk_08[26].unk_04, TRUE, 0);
    game->unk_1498->Print(2, windows[2].x, windows[2].y, windows[2].color, unk_3C->unk_08[27].unk_04, TRUE, 0);
    game->unk_1498->Print(3, windows[3].x, windows[3].y, windows[3].color, unk_3C->unk_08[28].unk_04, TRUE, 0);
    game->unk_1498->Print(4, windows[4].x, windows[4].y, windows[4].color, unk_3C->unk_08[29].unk_04, TRUE, 0);

    if (unk_18 != 0) {
        game->unk_1498->Print(5, windows[5].x, windows[5].y, windows[5].color, unk_3C->unk_08[30].unk_04, FALSE, 0);
        game->unk_1498->Print(5, 10, windows[5].y, windows[5].color, unk_3C->unk_08[unk_1C / 10000 + 8].unk_04, FALSE, 0);
        game->unk_1498->Print(5, 20, windows[5].y, windows[5].color, unk_3C->unk_08[unk_1C / 1000 % 10 + 8].unk_04, FALSE, 0);
        game->unk_1498->Print(5, 30, windows[5].y, windows[5].color, unk_3C->unk_08[unk_1C / 100 % 10 + 8].unk_04, FALSE, 0);
        game->unk_1498->Print(5, 40, windows[5].y, windows[5].color, unk_3C->unk_08[unk_1C / 10 % 10 + 8].unk_04, FALSE, 0);
        game->unk_1498->Print(5, 50, windows[5].y, windows[5].color, unk_3C->unk_08[unk_1C % 10 + 8].unk_04, FALSE, 0);
        game->unk_1498->Print(5, 70, windows[5].y, windows[5].color, unk_3C->unk_08[unk_18 / 10000 + 8].unk_04, FALSE, 0);
        game->unk_1498->Print(5, 80, windows[5].y, windows[5].color, unk_3C->unk_08[unk_18 / 1000 % 10 + 8].unk_04, FALSE, 0);
        game->unk_1498->Print(5, 90, windows[5].y, windows[5].color, unk_3C->unk_08[unk_18 / 100 % 10 + 8].unk_04, FALSE, 0);
        game->unk_1498->Print(5, 100, windows[5].y, windows[5].color, unk_3C->unk_08[unk_18 / 10 % 10 + 8].unk_04, FALSE, 0);
        game->unk_1498->Print(5, 110, windows[5].y, windows[5].color, unk_3C->unk_08[unk_18 % 10 + 8].unk_04, FALSE, 0);
    }
}

void SubScreenRangerCard::DrawGauge()
{
    int rate = (unk_1C << 7) / unk_18;
    int full = rate / 8;
    int rest = rate % 8;
    int i;

    if (unk_18 != 0) {
        for (i = 0; i < full; i++) {
            MI_CpuCopy16((u8 *)G2S_GetBG1ScrPtr() + 0x610, (u8 *)G2S_GetBG0ScrPtr() + ((i + 2) * 2 + 0x440), 2);
        }
        MI_CpuCopy16((u8 *)G2S_GetBG1ScrPtr() + (rest * 2 + 0x600), (u8 *)G2S_GetBG0ScrPtr() + ((i + 2) * 2 + 0x440), 2);
    } else {
        for (i = 0; i < 16; i++) {
            MI_CpuCopy16((u8 *)G2S_GetBG1ScrPtr() + 0x610, (u8 *)G2S_GetBG0ScrPtr() + ((i + 2) * 2 + 0x440), 2);
        }
    }
}

void SubScreenRangerCard::Update()
{
    CGame *game = CGame::GetInstance();
    unk_38->SetPos(unk_38->unk_0C, game->unk_15D0 >> FX32_SHIFT);
    unk_34->Update();
}

void SubScreenRangerCard::Render()
{
    unk_28->WriteOam();
    unk_2C->WriteOam();
    unk_30->WriteOam();
    unk_34->WriteOam();
}

void SubScreenRangerCard::ReleaseMessages()
{
    RELEASE_MESSAGES(unk_3C);
}
