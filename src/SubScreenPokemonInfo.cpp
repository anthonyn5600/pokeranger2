#include "SubScreenPokemonInfo.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "CGame.hpp"
#include "NameTables.hpp"
#include "PokeIdTableEntry.hpp"
#include "SaveData.hpp"
#include "SubTextPrinter.hpp"
#include "common.hpp"
#include "file/CBinaryFileMes.hpp"
#include "scene/CScene.hpp"

extern u16 DAT_0208c55c[];

extern "C" {
u8 *NameTables_GetFieldMoveName(NameTables *obj, u32 i);
int sub_020107C4(int arg0);
u8 *NameTables_GetPokemonName(NameTables *obj, u32 i);
void CopyStringUpper(const u8 *src, u8 *dst, int len);
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

static inline u32 GetPokemonState(SaveData *save, int i)
{
    if (i >= 0 && i < 500) {
        return (save->m_pokemonStates[i >> 4] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

static inline u32 GetPokemonState2(SaveData *save, int i)
{
    if (i >= 0 && i < 500) {
        return (save->unk_7EB0[i >> 4] >> ((i & 0xF) * 2)) & 3;
    }
    return 3;
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

SubScreenPokemonInfo::SubScreenPokemonInfo()
{
    unk_00 = 0;
    unk_0C = 0;
    unk_0E = 0;
    unk_10 = 0;
    unk_12 = 0;
    unk_14 = 0;
    unk_16 = 0;
    unk_18 = 0;
    unk_1A = 0;
    unk_1B = 0;
    unk_1C = 0;
    unk_1E = 0;
    unk_20 = 0;
    unk_28 = NULL;
    unk_2C = NULL;
    unk_30 = NULL;
    unk_34 = NULL;
    unk_38 = NULL;
    unk_3C = NULL;
    unk_40 = NULL;
    unk_44 = NULL;
    unk_48 = NULL;
    unk_4C = NULL;
    unk_50 = NULL;
    unk_54 = 0;
    unk_58 = NULL;
    unk_5C = NULL;
    unk_60 = NULL;
    unk_64 = NULL;
    unk_68 = NULL;
    unk_6C = NULL;
}

SubScreenPokemonInfo::~SubScreenPokemonInfo()
{
    Release();
    ReleaseBG();
}

void SubScreenPokemonInfo::Release()
{
    CGame *game = CGame::GetInstance();

    RELEASE_MESSAGES(unk_48);
    RELEASE_MESSAGES(unk_4C);
    RELEASE_MESSAGES(unk_50);

    SAFE_DELETE(unk_28);
    SAFE_DELETE(unk_2C);
    SAFE_DELETE(unk_30);
    SAFE_DELETE(unk_34);
    SAFE_DELETE(unk_38);
    SAFE_DELETE(unk_3C);
    SAFE_DELETE(unk_40);

    game->unk_1498->FreeWindows();
    unk_08 = 0;
    unk_54 = 0;
}

void SubScreenPokemonInfo::Load(int arg0, int arg1, int count)
{
    GXS_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    if (unk_28 != NULL) {
        Release();
    }
    unk_00 = arg0;
    unk_04 = arg1;
    CGame *game = CGame::GetInstance();

    if (count == 0) {
        unk_0C = CountPokemon(&MAIN_BSS_020B26A0);
    } else {
        unk_0C = count;
    }

    if (unk_00 != 0) {
        SetPokemon(unk_00, unk_04);
    }

    u32 pos;
    LOAD_MESSAGES(unk_48, "/data/message/etc/pokemon_info");
    LOAD_MESSAGES(unk_4C, "/data/message/etc/menu_mes");
    LOAD_MESSAGES(unk_50, "/data/message/etc/assist_mes");

    int ofs = 0;
    unk_2C = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x00], game->unk_14A8, TRUE, 0x40);
    ofs += unk_2C->Load("data/menu", "mt000_00", 0, 0);
    unk_30 = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x32], game->unk_14A8, TRUE, 0x40);
    ofs += unk_30->Load("data/menu", "ma004_00", ofs / 32, 1);
    unk_34 = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x36], game->unk_14A8, TRUE, 0x40);
    ofs += unk_34->Load("data/menu", "ma000_00", ofs / 32, 2);
    unk_38 = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x3A], game->unk_14A8, TRUE, 0x40);
    ofs += unk_38->Load("data/menu", "ma001_00", ofs / 32, 5);
    unk_3C = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x4A], game->unk_14A8, TRUE, 0x40);
    ofs += unk_3C->Load("data/menu", "ma002_00", ofs / 32, 6);
    unk_40 = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x4C], game->unk_14A8, TRUE, 0x40);
    ofs += unk_40->Load("data/menu", "ma000_01", ofs / 32, 7);
    unk_24 = ofs / 32;

    unk_2C->AddSprite(0, 0x9D, 0x2E, 3);
    unk_2C->AddSprite(5, 0x9D, 0x52, 3);
    unk_2C->AddSprite(6, 0x9D, 0x76, 3);
    unk_2C->AddSprite(3, 0x78, 0x25, 0);
    unk_2C->AddSprite(3, 0x78, 0x37, 0);
    unk_2C->AddSprite(3, 0x78, 0x49, 0);
    unk_2C->AddSprite(3, 0x78, 0x5B, 0);
    unk_2C->AddSprite(3, 0x78, 0x6D, 0);
    unk_2C->AddSprite(3, 0x78, 0x7F, 0);
    unk_2C->AddSprite(4, 0x38, 0x7B, 1);
    unk_44 = unk_30->AddSprite(1, 0x38, 0, 2);

    if (unk_00 != 0) {
        LoadSprites();
    }
    LoadBG();
    SetupBlend();
    SetupTextWindows();
    unk_54 = 0;
}

void SubScreenPokemonInfo::ResetLoad()
{
    unk_70 = 0;
}

int SubScreenPokemonInfo::LoadStep(int arg0, int arg1, int count)
{
    CGame *game = CGame::GetInstance();
    u32 pos;

    switch (unk_70) {
    case 0:
        GXS_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
        if (unk_28 != NULL) {
            Release();
        }
        unk_00 = arg0;
        unk_04 = arg1;
        if (count == 0) {
            unk_0C = CountPokemon(&MAIN_BSS_020B26A0);
        } else {
            unk_0C = count;
        }
        if (unk_00 != 0) {
            SetPokemon(unk_00, unk_04);
        }
        unk_70 = 1;
        break;
    case 1:
        LOAD_MESSAGES(unk_48, "/data/message/etc/pokemon_info");
        unk_70 = 2;
        break;
    case 2:
        LOAD_MESSAGES(unk_4C, "/data/message/etc/menu_mes");
        unk_70 = 3;
        break;
    case 3:
        LOAD_MESSAGES(unk_50, "/data/message/etc/assist_mes");
        unk_70 = 4;
        break;
    case 4:
        unk_74 = 0;
        unk_78 = 0;
        unk_2C = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x00], game->unk_14A8, TRUE, 0x40);
        unk_74 += unk_2C->Load("data/menu", "mt000_00", unk_74 / 32, 0);
        unk_70 = 5;
        break;
    case 5:
        unk_30 = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x32], game->unk_14A8, TRUE, 0x40);
        unk_74 += unk_30->Load("data/menu", "ma004_00", unk_74 / 32, 1);
        unk_70 = 6;
        break;
    case 6:
        unk_34 = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x36], game->unk_14A8, TRUE, 0x40);
        unk_74 += unk_34->Load("data/menu", "ma000_00", unk_74 / 32, 2);
        unk_70 = 7;
        break;
    case 7:
        unk_38 = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x3A], game->unk_14A8, TRUE, 0x40);
        unk_74 += unk_38->Load("data/menu", "ma001_00", unk_74 / 32, 5);
        unk_70 = 8;
        break;
    case 8:
        unk_3C = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x4A], game->unk_14A8, TRUE, 0x40);
        unk_74 += unk_3C->Load("data/menu", "ma002_00", unk_74 / 32, 6);
        unk_70 = 9;
        break;
    case 9:
        unk_40 = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x4C], game->unk_14A8, TRUE, 0x40);
        unk_74 += unk_40->Load("data/menu", "ma000_01", unk_74 / 32, 7);
        unk_70 = 10;
        break;
    case 10:
        unk_24 = unk_74 / 32;
        unk_2C->AddSprite(0, 0x9D, 0x2E, 3);
        unk_2C->AddSprite(5, 0x9D, 0x52, 3);
        unk_2C->AddSprite(6, 0x9D, 0x76, 3);
        unk_2C->AddSprite(3, 0x78, 0x25, 0);
        unk_2C->AddSprite(3, 0x78, 0x37, 0);
        unk_2C->AddSprite(3, 0x78, 0x49, 0);
        unk_2C->AddSprite(3, 0x78, 0x5B, 0);
        unk_2C->AddSprite(3, 0x78, 0x6D, 0);
        unk_2C->AddSprite(3, 0x78, 0x7F, 0);
        unk_2C->AddSprite(4, 0x38, 0x7B, 1);
        unk_44 = unk_30->AddSprite(1, 0x38, 0, 2);
        if (unk_00 != 0) {
            LoadSprites();
        }
        unk_70 = 11;
        break;
    case 11:
        DC_FlushAll();
        NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB1, unk_64->unk_B8, unk_5C->unk_B8, unk_60->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x00000);
        unk_70 = 12;
        break;
    case 12:
        DC_FlushAll();
        NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB2, unk_68->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7000, GX_BG_CHARBASE_0x00000);
        unk_70 = 13;
        break;
    case 13:
        DC_FlushAll();
        NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB3, unk_6C->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7800, GX_BG_CHARBASE_0x00000);
        SetupBlend();
        unk_70 = 15;
        break;
    case 15:
        SetupTextWindows();
        unk_70 = 16;
        break;
    }

    unk_54 = 0;
    return unk_70;
}

void SubScreenPokemonInfo::SetPokemon(int arg0, int arg1)
{
    CGame *game = CGame::GetInstance();

    unk_00 = arg0;
    unk_04 = arg1;
    PokeIdTableEntry *rec = PokeIdTable_Get(game->unk_1434, arg0);
    unk_0E = rec->unk_03;
    unk_10 = rec->unk_04;
    unk_16 = rec->unk_00;
    if (unk_00 == 0) {
        unk_12 = 0;
    } else {
        u16 v = DAT_0208c55c[unk_16];
        if (v == 0xFFFF) {
            v = 999;
        }
        unk_12 = v;
    }
    unk_18 = rec->unk_02;
    unk_1A = rec->unk_05;
    unk_1B = rec->unk_06;
    if (unk_1B == 9) {
        unk_1B = 0;
    }
    unk_14 = 4;
    if (unk_04 == 0 && game->currentScene->getSceneId() != 0 && unk_16 != 0x141) {
        // declared here: keeps the save's address in a register before the range check
        SaveData *save = &MAIN_BSS_020B26A0;
        unk_14 = GetPokemonState2(save, unk_16);
    }
    unk_1C = rec->unk_10;
    unk_1E = rec->unk_12;
    unk_20 = rec->unk_14;
}

void SubScreenPokemonInfo::LoadSprites()
{
    CGame *game = CGame::GetInstance();

    if (unk_04 == 0) {
        unk_34->RemoveAll();
        unk_34->AddSprite(unk_1A, 0x94, 0x7E, 0);
        unk_38->RemoveAll();
        unk_38->AddSprite(unk_1B, 0xA0, 0x7E, 0);
        unk_3C->RemoveAll();
        if (unk_14 < 4) {
            unk_3C->AddSprite(unk_14, 0x64, 0x68, 0);
        }
        unk_40->RemoveAll();
        unk_40->AddSprite(unk_10, 0x94, 0x5A, 0);
    } else {
        unk_34->RemoveAll();
        unk_38->RemoveAll();
        unk_3C->RemoveAll();
        unk_40->RemoveAll();
    }

    char name[12];
    if (unk_04 == 2) {
        OS_SPrintf(name, "bp000");
    } else {
        OS_SPrintf(name, "bp%03d", unk_16);
    }

    if (unk_28 != NULL) {
        MIi_CpuClearFast(0xC0, (void *)(HW_DB_OAM + 0x230), 0xA0);
        SAFE_DELETE(unk_28);
    }
    unk_28 = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x46], game->unk_14A8, TRUE, 0x40);
    unk_28->LoadFiles("data/pokeOBJ", name, unk_24, 0xB);
    unk_28->TransferToVram();
    unk_28->AddSprite(0, 0x38, 0x50, 1);
    unk_54 = 0;
}

void SubScreenPokemonInfo::StartRefresh()
{
    unk_54 = 1;
}

int SubScreenPokemonInfo::LoadSpritesStep(int step)
{
    CGame *game = CGame::GetInstance();

    switch (step) {
    case 0:
        break;
    case 1:
        unk_34->RemoveAll();
        unk_38->RemoveAll();
        unk_3C->RemoveAll();
        unk_40->RemoveAll();
        if (unk_04 == 0) {
            unk_34->AddSprite(unk_1A, 0x94, 0x7E, 0);
            unk_38->AddSprite(unk_1B, 0xA0, 0x7E, 0);
            if (unk_14 < 4) {
                unk_3C->AddSprite(unk_14, 0x64, 0x68, 0);
            }
            unk_40->AddSprite(unk_10, 0x94, 0x5A, 0);
        }
        step = 2;
        break;
    case 2:
        char name[12];
        if (unk_04 == 2) {
            OS_SPrintf(name, "bp000");
        } else {
            OS_SPrintf(name, "bp%03d", unk_16);
        }
        if (unk_28 != NULL) {
            MIi_CpuClearFast(0xC0, (void *)(HW_DB_OAM + 0x230), 0xA0);
            SAFE_DELETE(unk_28);
        }
        unk_28 = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x46], game->unk_14A8, TRUE, 0x40);
        unk_28->LoadFiles("data/pokeOBJ", name, unk_24, 0xB);
        step = 3;
        break;
    case 3:
        unk_28->TransferToVram();
        unk_28->AddSprite(0, 0x38, 0x50, 1);
        DrawTexts();
        step = 0;
        break;
    }
    return step;
}

void SubScreenPokemonInfo::LoadBG()
{
    CArchiveGuard *archive = new CArchiveGuard("BGS", "data/menu/mt000_bg_LZ.bin", 1, 1, 0, NULL, 0);
    CBGNCGRFile *ncgrFile = new CBGNCGRFile("BGS:mt000.NCGR", 1, 0, 0);
    CNCLRFile *nclrFile = new CNCLRFile("BGS:mt000.NCLR", 1, 0, 0);
    CNSCRFile *nscrFile1 = new CNSCRFile("BGS:mt000_01_1.NSCR", 1, 0, 0);
    CNSCRFile *nscrFile2 = new CNSCRFile("BGS:mt000_02.NSCR", 1, 0, 0);
    CNSCRFile *nscrFile3 = new CNSCRFile("BGS:mt000_03.NSCR", 1, 0, 0);

    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB1, nscrFile1->unk_B8, ncgrFile->unk_B8, nclrFile->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x00000);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB2, nscrFile2->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7000, GX_BG_CHARBASE_0x00000);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB3, nscrFile3->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7800, GX_BG_CHARBASE_0x00000);

    // SAFE_DELETE, not delete: removing its redundant null check makes mwcc reschedule the setup block after
    // register allocation, which orders the last setup's arguments like the original
    SAFE_DELETE(nscrFile1);
    SAFE_DELETE(nscrFile2);
    SAFE_DELETE(nscrFile3);
    SAFE_DELETE(ncgrFile);
    SAFE_DELETE(nclrFile);
    SAFE_DELETE(archive);
}

void SubScreenPokemonInfo::LoadPTC()
{
    SAFE_DELETE(unk_58);
    unk_58 = new CArchiveGuard("PTC", "data/menu/mt000_bg_LZ.bin", 1, 1, 0, NULL, 0);
    SAFE_DELETE(unk_5C);
    unk_5C = new CBGNCGRFile("PTC:mt000.NCGR", 2, 0, 0);
    SAFE_DELETE(unk_60);
    unk_60 = new CNCLRFile("PTC:mt000.NCLR", 2, 0, 0);
    SAFE_DELETE(unk_64);
    unk_64 = new CNSCRFile("PTC:mt000_01_1.NSCR", 2, 0, 0);
    SAFE_DELETE(unk_68);
    unk_68 = new CNSCRFile("PTC:mt000_02.NSCR", 2, 0, 0);
    SAFE_DELETE(unk_6C);
    unk_6C = new CNSCRFile("PTC:mt000_03.NSCR", 2, 0, 0);
}

void SubScreenPokemonInfo::ReleaseBG()
{
    SAFE_DELETE(unk_6C);
    SAFE_DELETE(unk_68);
    SAFE_DELETE(unk_64);
    SAFE_DELETE(unk_5C);
    SAFE_DELETE(unk_60);
    SAFE_DELETE(unk_58);
}

void SubScreenPokemonInfo::SetupBlend()
{
    GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3);
    G2S_SetBG1Priority(1);
    G2S_SetBG2Priority(2);
    G2S_SetBG3Priority(3);
    G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ, 4, 0x1B);
}

void SubScreenPokemonInfo::SetupTextWindows()
{
    TextWindow windows[10] = {
        { 16, 2, 16, 1, 0, 0, 1 },
        { 14, 2, 18, 4, 2, 0, 5 },
        { 14, 2, 18, 8, 4, 4, 5 },
        { 14, 2, 18, 13, 2, 1, 5 },
        { 9, 2, 3, 1, 8, 2, 5 },
        { 14, 2, 18, 6, 0, 0, 3 },
        { 11, 2, 21, 10, 0, 6, 3 },
        { 11, 2, 21, 15, 0, 2, 3 },
        { 12, 2, 1, 14, 4, 6, 3 },
        { 28, 4, 2, 19, 0, 0, 1 },
    };
    CGame *game = CGame::GetInstance();

    game->unk_1498->FreeWindows();
    game->unk_1498->SetupBG();
    game->unk_1498->AllocWindows(10);

    int charNo = 0x40;
    for (int i = 0; i < 10; i++) {
        game->unk_1498->InitWindow(i, windows[i].width, windows[i].height, windows[i].left, windows[i].top, charNo, 0, 2);
        charNo += windows[i].width * windows[i].height;
    }

    game->unk_1498->Print(0, windows[0].x, windows[0].y, windows[0].color, unk_4C->unk_08[4].unk_04, FALSE, 0);
    game->unk_1498->Print(0, 0x5C, windows[0].y, windows[0].color, unk_4C->unk_08[unk_0C / 100 + 8].unk_04, FALSE, 0);
    game->unk_1498->Print(0, 0x66, windows[0].y, windows[0].color, unk_4C->unk_08[(unk_0C / 10) % 10 + 8].unk_04, FALSE, 0);
    game->unk_1498->Print(0, 0x70, windows[0].y, windows[0].color, unk_4C->unk_08[unk_0C % 10 + 8].unk_04, FALSE, 0);

    if (unk_08 == 0) {
        PrintLabels();
    } else {
        sub_0201F38C();
    }
    if (unk_00 != 0) {
        DrawTexts();
    }
}

void SubScreenPokemonInfo::DrawTexts()
{
    TextWindow windows[10] = {
        { 16, 2, 16, 1, 0, 0, 1 },
        { 14, 2, 18, 4, 2, 0, 5 },
        { 14, 2, 18, 8, 4, 4, 5 },
        { 14, 2, 18, 13, 2, 1, 5 },
        { 9, 2, 3, 1, 8, 2, 5 },
        { 14, 2, 18, 6, 0, 0, 3 },
        { 12, 2, 20, 10, 0, 5, 3 },
        { 12, 2, 20, 15, 0, 1, 3 },
        { 12, 2, 1, 14, 4, 6, 3 },
        { 28, 4, 2, 19, 0, 0, 1 },
    };
    u8 name[0x20];
    CGame *game = CGame::GetInstance();

    for (int i = 0; i < 10; i++) {
        if (i > 3) {
            game->unk_1498->ClearWindow(i);
        }
    }

    if (unk_00 > 0) {
        if (unk_12 < 1000) {
            game->unk_1498->Print(4, windows[4].x, windows[4].y, windows[4].color, unk_4C->unk_08[7].unk_04, FALSE, 0);
            game->unk_1498->Print(4, 0x1C, windows[4].y, windows[4].color, unk_4C->unk_08[unk_12 / 100 + 8].unk_04, FALSE, 0);
            game->unk_1498->Print(4, 0x26, windows[4].y, windows[4].color, unk_4C->unk_08[(unk_12 / 10) % 10 + 8].unk_04, FALSE, 0);
            game->unk_1498->Print(4, 0x30, windows[4].y, windows[4].color, unk_4C->unk_08[unk_12 % 10 + 8].unk_04, FALSE, 0);
        } else {
            game->unk_1498->Print(4, windows[4].x, windows[4].y, windows[4].color, unk_4C->unk_08[61].unk_04, TRUE, 0);
            unk_12 -= 1000;
        }

        if (unk_04 <= 1) {
            CopyStringUpper(NameTables_GetPokemonName(game->m_nameTables, unk_16), name, 0x1F);
            game->unk_1498->Print(8, windows[8].x, windows[8].y, windows[8].color, name, TRUE, 0);
        } else {
            game->unk_1498->Print(8, windows[8].x, windows[8].y, windows[8].color, unk_4C->unk_08[18].unk_04, TRUE, 0);
        }
    }

    if (unk_00 > 0) {
        if (unk_04 == 0) {
            game->unk_1498->Print(9, windows[9].x, windows[9].y, windows[9].color, unk_48->unk_08[unk_16].unk_04, FALSE, 0);
        } else {
            game->unk_1498->Print(9, windows[9].x, windows[9].y, windows[9].color, unk_4C->unk_08[18].unk_04, FALSE, 0);
        }
    }

    if (unk_00 > 0) {
        if (unk_08 == 0) {
            PrintValues();
        } else {
            sub_0201F48C();
        }
    }
}

void SubScreenPokemonInfo::PrintLabels()
{
    TextWindow windows[3] = {
        { 14, 2, 18, 4, 2, 0, 5 },
        { 14, 2, 18, 8, 4, 4, 5 },
        { 14, 2, 18, 13, 2, 0, 5 },
    };
    CGame *game = CGame::GetInstance();

    game->unk_1498->Print(1, windows[0].x, windows[0].y, windows[0].color, unk_4C->unk_08[5].unk_04, TRUE, 0);
    game->unk_1498->Print(2, windows[1].x, windows[1].y, windows[1].color, unk_4C->unk_08[6].unk_04, TRUE, 0);
    game->unk_1498->Print(3, windows[2].x, windows[2].y, windows[2].color, unk_4C->unk_08[3].unk_04, TRUE, 0);
}

void SubScreenPokemonInfo::PrintValues()
{
    TextWindow windows[4] = {
        { 14, 2, 18, 6, 0, 0, 3 },
        { 11, 2, 21, 10, 0, 6, 3 },
        { 11, 2, 21, 15, 0, 2, 3 },
        { 14, 2, 18, 13, 2, 0, 5 },
    };
    CGame *game = CGame::GetInstance();
    int type = 0;

    if (unk_04 == 0) {
        game->unk_1498->Print(5, windows[0].x, windows[0].y, windows[0].color, unk_50->unk_08[unk_0E + 1].unk_04, TRUE, 0);
        game->unk_1498->Print(6, windows[1].x, windows[1].y, windows[1].color, unk_50->unk_08[unk_10 + 1].unk_04, TRUE, 0);
        SubTextPrinter *text = game->unk_1498;
        text->Print(7, windows[2].x, windows[2].y, windows[2].color, NameTables_GetFieldMoveName(game->m_nameTables, unk_1A), TRUE, 0);
        type = sub_020107C4(unk_1A);
    } else {
        game->unk_1498->Print(5, windows[0].x, windows[0].y, windows[0].color, unk_4C->unk_08[18].unk_04, TRUE, 0);
        game->unk_1498->Print(6, windows[1].x, windows[1].y, windows[1].color, unk_4C->unk_08[18].unk_04, TRUE, 0);
        game->unk_1498->Print(7, windows[2].x, windows[2].y, windows[2].color, unk_4C->unk_08[18].unk_04, TRUE, 0);
    }

    game->unk_1498->ClearWindow(3);
    u8 *str;
    switch (type) {
    case 2:
        str = unk_4C->unk_08[60].unk_04;
        break;
    case 3:
        str = unk_4C->unk_08[59].unk_04;
        break;
    default:
        str = unk_4C->unk_08[3].unk_04;
        break;
    }
    game->unk_1498->Print(3, windows[3].x, windows[3].y, windows[3].color, str, TRUE, 0);
}

void SubScreenPokemonInfo::sub_0201F38C()
{
    TextWindow windows[3] = {
        { 14, 2, 18, 4, 2, 0, 5 },
        { 14, 2, 18, 8, 4, 4, 5 },
        { 14, 2, 18, 13, 2, 1, 5 },
    };
    CGame *game = CGame::GetInstance();

    game->unk_1498->Print(1, windows[0].x, windows[0].y, windows[0].color, unk_4C->unk_08[53].unk_04, TRUE, 0);
    game->unk_1498->Print(2, windows[1].x, windows[1].y, windows[1].color, unk_4C->unk_08[54].unk_04, TRUE, 0);
    game->unk_1498->Print(3, windows[2].x, windows[2].y, windows[2].color, unk_4C->unk_08[55].unk_04, TRUE, 0);
}

void SubScreenPokemonInfo::sub_0201F48C()
{
    TextWindow windows[3] = {
        { 14, 2, 18, 6, 0, 0, 3 },
        { 12, 2, 20, 10, 0, 4, 3 },
        { 12, 2, 20, 15, 0, 2, 3 },
    };
    CGame *game = CGame::GetInstance();

    game->unk_1498->Print(5, 0x04, windows[0].y, windows[0].color, unk_4C->unk_08[unk_1C / 1000 + 8].unk_04, FALSE, 0);
    game->unk_1498->Print(5, 0x0E, windows[0].y, windows[0].color, unk_4C->unk_08[(unk_1C / 100) % 10 + 8].unk_04, FALSE, 0);
    game->unk_1498->Print(5, 0x18, windows[0].y, windows[0].color, unk_4C->unk_08[(unk_1C / 10) % 10 + 8].unk_04, FALSE, 0);
    game->unk_1498->Print(5, 0x22, windows[0].y, windows[0].color, unk_4C->unk_08[56].unk_04, FALSE, 0);
    game->unk_1498->Print(5, 0x2C, windows[0].y, windows[0].color, unk_4C->unk_08[unk_1C % 10 + 8].unk_04, FALSE, 0);
    game->unk_1498->Print(5, 0x36, windows[0].y, windows[0].color, unk_4C->unk_08[57].unk_04, FALSE, 0);

    game->unk_1498->Print(6, 0x14, windows[1].y, windows[1].color, unk_4C->unk_08[unk_1E / 1000 + 8].unk_04, FALSE, 0);
    game->unk_1498->Print(6, 0x1E, windows[1].y, windows[1].color, unk_4C->unk_08[(unk_1E / 100) % 10 + 8].unk_04, FALSE, 0);
    game->unk_1498->Print(6, 0x28, windows[1].y, windows[1].color, unk_4C->unk_08[(unk_1E / 10) % 10 + 8].unk_04, FALSE, 0);
    game->unk_1498->Print(6, 0x32, windows[1].y, windows[1].color, unk_4C->unk_08[56].unk_04, FALSE, 0);
    game->unk_1498->Print(6, 0x3C, windows[1].y, windows[1].color, unk_4C->unk_08[unk_1E % 10 + 8].unk_04, FALSE, 0);
    game->unk_1498->Print(6, 0x46, windows[1].y, windows[1].color, unk_4C->unk_08[58].unk_04, FALSE, 0);

    game->unk_1498->Print(7, windows[2].x, windows[2].y, windows[2].color, unk_4C->unk_08[unk_20].unk_04, TRUE, 0);
}

void SubScreenPokemonInfo::Update()
{
    unk_54 = LoadSpritesStep(unk_54);
    CGame *game = CGame::GetInstance();
    unk_44->SetPos(unk_44->unk_0C, game->unk_15D0 >> FX32_SHIFT);
    unk_2C->Update();
    unk_30->Update();
    if (unk_28 == NULL && unk_00 == 0) {
        return;
    }
}

void SubScreenPokemonInfo::Render()
{
    unk_2C->WriteOam();
    unk_30->WriteOam();
    if (unk_28 == NULL && unk_00 != 0) {
        return;
    }
    if (unk_54 != 0) {
        return;
    }
    if (unk_00 != 0) {
        unk_28->WriteOam();
    }
    if (unk_00 == 0) {
        return;
    }
    if (unk_08 == 0) {
        unk_34->WriteOam();
        unk_38->WriteOam();
        unk_40->WriteOam();
    }
    if (unk_14 < 4) {
        unk_3C->WriteOam();
    }
}

void SubScreenPokemonInfo::ReleaseMessages()
{
    RELEASE_MESSAGES(unk_48);
    RELEASE_MESSAGES(unk_4C);
    RELEASE_MESSAGES(unk_50);
}
