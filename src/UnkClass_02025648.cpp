#include "UnkClass_02025648.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "CGame.hpp"
#include "UnkClass_0200CAB4.hpp"
#include "UnkClass_02010D2C.hpp"
#include "UnkClass_02018208.hpp"
#include "UnkClass_020B26A0.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBinaryFileMes.hpp"
#include "file/CNSCRFile.hpp"

extern "C" {
u8 *sub_02018B80(UnkClass_02018208 *obj, u32 i);
u8 *sub_02018B10(UnkClass_02018208 *obj, u32 i);
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

extern "C" s32 sub_02019278(void *obj, int index);

static inline u32 GetPokemonState(UnkClass_020B26A0 *save, int i)
{
    if (i >= 0 && i < 500) {
        return (save->unk_7C3C[i >> 4] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

static inline int CountPokemon(UnkClass_020B26A0 *save)
{
    int n = 0;
    for (int i = 0; i < 500; i++) {
        if (GetPokemonState(save, i) >= 2) {
            n++;
        }
    }
    return n;
}

#define OAM_SET(i) new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0424[i], game->unk_14A8, TRUE, 0x40)

UnkClass_02025648::UnkClass_02025648()
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

UnkClass_02025648::~UnkClass_02025648()
{
    sub_020256A4();
}

void UnkClass_02025648::sub_020256A4()
{
    CGame *game = CGame::GetInstance();

    RELEASE_MESSAGES(unk_3C);
    SAFE_DELETE(unk_28);
    SAFE_DELETE(unk_2C);
    SAFE_DELETE(unk_30);
    SAFE_DELETE(unk_34);

    game->unk_1498->sub_0200CAE0();
}

int UnkClass_02025648::sub_020257F4(int step)
{
    int next = step + 1;
    CGame *game = CGame::GetInstance();
    u32 pos;

    switch (step) {
    case 0: {
        unk_04 = 0;
        unk_08 = 0;
        UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
        unk_20 = ((u8 *)game->m_missionQuestData)[0];
        unk_24 = ((u8 *)game->m_missionQuestData)[1];
        unk_00 = save->unk_0000;
        unk_0C = save->unk_0003 & 0xF;
        unk_10 = (save->unk_0003 >> 4) & 0xF;
        unk_14 = save->unk_87DB;
        unk_1C = save->unk_0028;
        unk_18 = sub_02010EAC(game->unk_1438, unk_14);
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
        unk_04 = (sub_02019278(game->unk_14B4, 30) >> 3) & 1;
        LOAD_MESSAGES(unk_3C, "/data/message/etc/menu_mes");
        break;
    }
    case 1:
        unk_40 = 0;
        unk_28 = OAM_SET(0x00);
        if (unk_10 == 0) {
            if (unk_00 == 0) {
                unk_40 += unk_28->sub_0200EE14("data/menu", "mp003_00", unk_40 / 32, 0);
            } else {
                unk_40 += unk_28->sub_0200EE14("data/menu", "mp004_00", unk_40 / 32, 0);
            }
        } else if (unk_10 == 1) {
            if (unk_00 == 0) {
                unk_40 += unk_28->sub_0200EE14("data/menu", "mp005_00", unk_40 / 32, 0);
            } else {
                unk_40 += unk_28->sub_0200EE14("data/menu", "mp006_00", unk_40 / 32, 0);
            }
        } else {
            if (unk_00 == 0) {
                unk_40 += unk_28->sub_0200EE14("data/menu", "mp007_00", unk_40 / 32, 0);
            } else {
                unk_40 += unk_28->sub_0200EE14("data/menu", "mp008_00", unk_40 / 32, 0);
            }
        }
        unk_28->sub_0200F4FC(0, 0xD0, 0x5B, 0);
        break;
    case 2:
        unk_2C = OAM_SET(0x10);
        unk_40 += unk_2C->sub_0200EE14("data/menu", "mp001_00", unk_40 / 32, 2);
        if (unk_04) {
            unk_2C->sub_0200F4FC(0xC, 0x10, 0x11, 0);
        }
        if (unk_08) {
            unk_2C->sub_0200F4FC(0xD, 0x23, 0x11, 0);
        }
        unk_2C->sub_0200F4FC(unk_14 / 10, 0x78, 0x80, 0);
        unk_2C->sub_0200F4FC(unk_14 % 10, 0x88, 0x80, 0);
        unk_2C->sub_0200F4FC(0x11, 0x50, 0x88, 1);
        if (unk_20) {
            unk_2C->sub_0200F4FC(0xA, 0x72, 0xAB, 1);
        }
        if (unk_24) {
            unk_2C->sub_0200F4FC(0xB, 0x8E, 0xAB, 1);
        }
        unk_2C->sub_0200F4FC(0xF, 0x40, 0xAB, 1);
        unk_2C->sub_0200F4FC(0xE, 0xC0, 0xAB, 1);
        unk_2C->sub_0200F4FC(0x10, 0x38, 0x27, 1);
        unk_2C->sub_0200F4FC(0x10, 0x38, 0x80, 1);
        break;
    case 3:
        unk_30 = OAM_SET(0x3C);
        unk_40 += unk_30->sub_0200EE14("data/menu", "ma003_00", unk_40 / 32, 7);
        for (int i = 0; i < unk_0C; i++) {
            switch (i) {
            case 0:
                unk_30->sub_0200F4FC(0, 0x14, 0x40, 0);
                break;
            case 1:
                unk_30->sub_0200F4FC(1, 0x2C, 0x40, 0);
                break;
            case 2:
                unk_30->sub_0200F4FC(2, 0x44, 0x40, 0);
                break;
            case 3:
                unk_30->sub_0200F4FC(3, 0x5C, 0x40, 0);
                break;
            case 4:
                unk_30->sub_0200F4FC(4, 0x74, 0x40, 0);
                break;
            case 5:
                unk_30->sub_0200F4FC(5, 0x24, 0x60, 0);
                break;
            case 6:
                unk_30->sub_0200F4FC(6, 0x3C, 0x60, 0);
                break;
            case 7:
                unk_30->sub_0200F4FC(7, 0x54, 0x60, 0);
                break;
            case 8:
                unk_30->sub_0200F4FC(8, 0x6C, 0x60, 0);
                break;
            case 9:
                unk_30->sub_0200F4FC(9, 0x84, 0x60, 0);
                break;
            }
        }
        break;
    case 4:
        unk_34 = OAM_SET(0x6E);
        unk_40 += unk_34->sub_0200EE14("data/menu", "ma004_00", unk_40 / 32, 8);
        unk_38 = unk_34->sub_0200F4FC(0, 0x80, -8, 3);
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

void UnkClass_02025648::LoadAll()
{
    CGame *game = CGame::GetInstance();
    u32 pos;

    unk_04 = 0;
    unk_08 = 0;
    UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
    unk_20 = ((u8 *)game->m_missionQuestData)[0];
    unk_24 = ((u8 *)game->m_missionQuestData)[1];
    unk_00 = save->unk_0000;
    unk_0C = save->unk_0003 & 0xF;
    unk_10 = (save->unk_0003 >> 4) & 0xF;
    unk_14 = save->unk_87DB;
    unk_1C = save->unk_0028;
    unk_18 = sub_02010EAC(game->unk_1438, unk_14);
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
    unk_04 = (sub_02019278(game->unk_14B4, 30) >> 3) & 1;
    LOAD_MESSAGES(unk_3C, "/data/message/etc/menu_mes");

    int charNo = 0;
    unk_28 = OAM_SET(0x00);
    if (unk_10 == 0) {
        if (unk_00 == 0) {
            charNo += unk_28->sub_0200EE14("data/menu", "mp003_00", charNo / 32, 0);
        } else {
            charNo += unk_28->sub_0200EE14("data/menu", "mp004_00", charNo / 32, 0);
        }
    } else if (unk_10 == 1) {
        if (unk_00 == 0) {
            charNo += unk_28->sub_0200EE14("data/menu", "mp005_00", charNo / 32, 0);
        } else {
            charNo += unk_28->sub_0200EE14("data/menu", "mp006_00", charNo / 32, 0);
        }
    } else {
        if (unk_00 == 0) {
            charNo += unk_28->sub_0200EE14("data/menu", "mp007_00", charNo / 32, 0);
        } else {
            charNo += unk_28->sub_0200EE14("data/menu", "mp008_00", charNo / 32, 0);
        }
    }
    unk_28->sub_0200F4FC(0, 0xD0, 0x5B, 0);

    unk_2C = OAM_SET(0x10);
    charNo += unk_2C->sub_0200EE14("data/menu", "mp001_00", charNo / 32, 2);
    if (unk_04) {
        unk_2C->sub_0200F4FC(0xC, 0x10, 0x11, 0);
    }
    if (unk_08) {
        unk_2C->sub_0200F4FC(0xD, 0x23, 0x11, 0);
    }
    unk_2C->sub_0200F4FC(unk_14 / 10, 0x78, 0x80, 0);
    unk_2C->sub_0200F4FC(unk_14 % 10, 0x88, 0x80, 0);
    unk_2C->sub_0200F4FC(0x11, 0x50, 0x88, 1);
    if (unk_20) {
        unk_2C->sub_0200F4FC(0xA, 0x72, 0xAB, 1);
    }
    if (unk_24) {
        unk_2C->sub_0200F4FC(0xB, 0x8E, 0xAB, 1);
    }
    unk_2C->sub_0200F4FC(0xF, 0x40, 0xAB, 1);
    unk_2C->sub_0200F4FC(0xE, 0xC0, 0xAB, 1);
    unk_2C->sub_0200F4FC(0x10, 0x38, 0x27, 1);
    unk_2C->sub_0200F4FC(0x10, 0x38, 0x80, 1);

    unk_30 = OAM_SET(0x3C);
    charNo += unk_30->sub_0200EE14("data/menu", "ma003_00", charNo / 32, 7);
    for (int i = 0; i < unk_0C; i++) {
        switch (i) {
        case 0:
            unk_30->sub_0200F4FC(0, 0x14, 0x40, 0);
            break;
        case 1:
            unk_30->sub_0200F4FC(1, 0x2C, 0x40, 0);
            break;
        case 2:
            unk_30->sub_0200F4FC(2, 0x44, 0x40, 0);
            break;
        case 3:
            unk_30->sub_0200F4FC(3, 0x5C, 0x40, 0);
            break;
        case 4:
            unk_30->sub_0200F4FC(4, 0x74, 0x40, 0);
            break;
        case 5:
            unk_30->sub_0200F4FC(5, 0x24, 0x60, 0);
            break;
        case 6:
            unk_30->sub_0200F4FC(6, 0x3C, 0x60, 0);
            break;
        case 7:
            unk_30->sub_0200F4FC(7, 0x54, 0x60, 0);
            break;
        case 8:
            unk_30->sub_0200F4FC(8, 0x6C, 0x60, 0);
            break;
        case 9:
            unk_30->sub_0200F4FC(9, 0x84, 0x60, 0);
            break;
        }
    }

    unk_34 = OAM_SET(0x6E);
    charNo += unk_34->sub_0200EE14("data/menu", "ma004_00", charNo / 32, 8);
    unk_38 = unk_34->sub_0200F4FC(0, 0x80, -8, 3);

    LoadBGAll();
    SetupBlend();
    DrawTexts();
    DrawGauge();
}

int UnkClass_02025648::LoadBG(int step)
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

void UnkClass_02025648::LoadBGAll()
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

void UnkClass_02025648::SetupBlend()
{
    GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    G2S_SetBG1Priority(1);
    G2S_SetBG2Priority(2);
    G2S_SetBG3Priority(3);
    G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_BG1, GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ, 8, 8);
}

void UnkClass_02025648::DrawTexts()
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

    game->unk_1498->sub_0200CAE0();
    game->unk_1498->sub_0200CB14();
    game->unk_1498->sub_0200CC88(6);

    int charNo = 0x60;
    for (int i = 0; i < 6; i++) {
        game->unk_1498->sub_0200CCD0(i, windows[i].width, windows[i].height, windows[i].left, windows[i].top, charNo, 0, 2);
        charNo += windows[i].width * windows[i].height;
    }

    game->unk_1498->sub_0200CDA0(0, windows[0].x, windows[0].y, windows[0].color, &MAIN_BSS_020B26A0.unk_87E3, TRUE, 4);
    game->unk_1498->sub_0200CDA0(1, windows[1].x, windows[1].y, windows[1].color, unk_3C->unk_08[26].unk_04, TRUE, 0);
    game->unk_1498->sub_0200CDA0(2, windows[2].x, windows[2].y, windows[2].color, unk_3C->unk_08[27].unk_04, TRUE, 0);
    game->unk_1498->sub_0200CDA0(3, windows[3].x, windows[3].y, windows[3].color, unk_3C->unk_08[28].unk_04, TRUE, 0);
    game->unk_1498->sub_0200CDA0(4, windows[4].x, windows[4].y, windows[4].color, unk_3C->unk_08[29].unk_04, TRUE, 0);

    if (unk_18 != 0) {
        game->unk_1498->sub_0200CDA0(5, windows[5].x, windows[5].y, windows[5].color, unk_3C->unk_08[30].unk_04, FALSE, 0);
        game->unk_1498->sub_0200CDA0(5, 10, windows[5].y, windows[5].color, unk_3C->unk_08[unk_1C / 10000 + 8].unk_04, FALSE, 0);
        game->unk_1498->sub_0200CDA0(5, 20, windows[5].y, windows[5].color, unk_3C->unk_08[unk_1C / 1000 % 10 + 8].unk_04, FALSE, 0);
        game->unk_1498->sub_0200CDA0(5, 30, windows[5].y, windows[5].color, unk_3C->unk_08[unk_1C / 100 % 10 + 8].unk_04, FALSE, 0);
        game->unk_1498->sub_0200CDA0(5, 40, windows[5].y, windows[5].color, unk_3C->unk_08[unk_1C / 10 % 10 + 8].unk_04, FALSE, 0);
        game->unk_1498->sub_0200CDA0(5, 50, windows[5].y, windows[5].color, unk_3C->unk_08[unk_1C % 10 + 8].unk_04, FALSE, 0);
        game->unk_1498->sub_0200CDA0(5, 70, windows[5].y, windows[5].color, unk_3C->unk_08[unk_18 / 10000 + 8].unk_04, FALSE, 0);
        game->unk_1498->sub_0200CDA0(5, 80, windows[5].y, windows[5].color, unk_3C->unk_08[unk_18 / 1000 % 10 + 8].unk_04, FALSE, 0);
        game->unk_1498->sub_0200CDA0(5, 90, windows[5].y, windows[5].color, unk_3C->unk_08[unk_18 / 100 % 10 + 8].unk_04, FALSE, 0);
        game->unk_1498->sub_0200CDA0(5, 100, windows[5].y, windows[5].color, unk_3C->unk_08[unk_18 / 10 % 10 + 8].unk_04, FALSE, 0);
        game->unk_1498->sub_0200CDA0(5, 110, windows[5].y, windows[5].color, unk_3C->unk_08[unk_18 % 10 + 8].unk_04, FALSE, 0);
    }
}

void UnkClass_02025648::DrawGauge()
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

void UnkClass_02025648::sub_02027640()
{
    CGame *game = CGame::GetInstance();
    unk_38->sub_0200EB28(unk_38->unk_0C, game->unk_15D0 >> FX32_SHIFT);
    unk_34->sub_0200F64C();
}

void UnkClass_02025648::sub_02027674()
{
    unk_28->sub_0200F71C();
    unk_2C->sub_0200F71C();
    unk_30->sub_0200F71C();
    unk_34->sub_0200F71C();
}

void UnkClass_02025648::sub_020276A0()
{
    RELEASE_MESSAGES(unk_3C);
}
