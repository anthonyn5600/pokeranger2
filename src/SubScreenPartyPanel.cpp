#include "SubScreenPartyPanel.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "CGame.hpp"
#include "NameTables.hpp"
#include "PokeIdTableEntry.hpp"
#include "SaveData.hpp"
#include "SubTextPrinter.hpp"
#include "common.hpp"
#include "field/CFieldPartner.hpp"
#include "field/CFieldPartnerManage.hpp"
#include "field/FieldPartnerIndex.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CBinaryFileMes.hpp"

extern "C" {
u8 *NameTables_GetFieldMoveName(NameTables *obj, u32 i);
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

SubScreenPartyPanel::SubScreenPartyPanel()
{
    unk_20 = 0;
    unk_24 = 0;
    unk_28 = 0;
    unk_2C = 0;
    for (int i = 0; i < 8; i++) {
        unk_00[i] = 0;
        unk_30[i] = 0;
        unk_40[i] = 0;
        unk_48[i] = 0;
    }
    unk_50 = NULL;
    unk_54 = NULL;
    unk_58 = NULL;
    unk_74 = NULL;
    unk_68 = NULL;
    unk_6C = NULL;
    unk_70 = NULL;
    unk_60 = NULL;
    unk_64 = NULL;
    Load();
}

SubScreenPartyPanel::~SubScreenPartyPanel()
{
    Release();
    unk_50->ReleaseFiles();
    unk_54->ReleaseFiles();
    unk_58->ReleaseFiles();
    SAFE_DELETE(unk_50);
    SAFE_DELETE(unk_54);
    SAFE_DELETE(unk_58);
    RELEASE_MESSAGES(unk_74);
    SAFE_DELETE(unk_68);
    SAFE_DELETE(unk_6C);
    SAFE_DELETE(unk_70);
    SAFE_DELETE(unk_60);
    SAFE_DELETE(unk_64);
}

void SubScreenPartyPanel::Release()
{
    CGame *game = CGame::GetInstance();

    game->unk_1498->FreeWindows();
    unk_50->RemoveAll();
    unk_54->RemoveAll();
    unk_58->RemoveAll();
}

static inline CFieldPartner *FindPartnerByOrder(CFieldPartnerManage *mgr, int order)
{
    for (int i = 0; i < mgr->m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)mgr->Get(i);
        if (partner != NULL && order == partner->unk_1E8) {
            return partner;
        }
    }
    return NULL;
}

void SubScreenPartyPanel::LoadPanel()
{
    CGame *game = CGame::GetInstance();

    unk_20 = 0;
    unk_24 = 0;
    CFieldPartnerManage *mgr = MAIN_BSS_0210CA4C;
    if (mgr != NULL) {
        int first;
        int i;
        int n = 1;
        unk_28 = mgr->unk_88;
        first = mgr->unk_84;
        for (i = 0; i < unk_28; i++) {
            CFieldPartner *partner = FindPartnerByOrder(mgr, first + i);
            if (partner != NULL) {
                if (partner->m_flags & 0x20) {
                    unk_20 = 1;
                    unk_00[0] = partner->unk_200;
                } else {
                    unk_00[n] = partner->unk_200;
                    n++;
                }
            }
        }
    }

    SaveData *save = &MAIN_BSS_020B26A0;
    unk_2C = SaveData_GetPartyCapacity(save, save->m_rangerClassGrade & 0xF);
    if (unk_20) {
        unk_24 = save->m_partnerMoods[PartnerKindToIndex(unk_00[0])] + 1;
    }

    if (unk_20) {
        unk_28--;
        PokeIdTableEntry *info = PokeIdTable_Get(game->unk_1434, unk_00[0]);
        unk_30[0] = info->unk_00;
        unk_40[0] = info->unk_05;
        unk_48[0] = info->unk_06;
    }
    for (int i = 1; i <= unk_28; i++) {
        PokeIdTableEntry *info = PokeIdTable_Get(game->unk_1434, unk_00[i]);
        unk_30[i] = info->unk_00;
        unk_40[i] = info->unk_05;
        unk_48[i] = info->unk_06;
    }

    char name[12];
    OS_SPrintf(name, "bp%03d", unk_30[0]);

    unk_50->CopyToVram();
    unk_54->CopyToVram();
    for (int i = 1; i <= unk_28; i++) {
        unk_50->AddSprite(unk_40[i], 0xD0, i * 0x10 + 0x30, 0);
        unk_54->AddSprite(unk_48[i], 0xDC, i * 0x10 + 0x30, 0);
    }
    unk_58->CopyToVram();
    unk_5C = unk_58->AddSprite(0, 0x80, -8, 3);

    SetupBG();
    SetupBlend();
    DrawTexts();
}

void SubScreenPartyPanel::Load()
{
    u32 pos;

    LOAD_MESSAGES(unk_74, "/data/message/etc/menu_mes");

    CArchiveGuard *archive = new CArchiveGuard("BGS", "data/menu/mc000_bg_LZ.bin", 1, 1, 0, NULL, 0);
    unk_60 = new CBGNCGRFile("BGS:mc000.NCGR", 0, 0, 0);
    unk_64 = new CNCLRFile("BGS:mc000.NCLR", 0, 0, 0);
    unk_68 = new CNSCRFile("BGS:mc000_01.NSCR", 0, 0, 0);
    unk_6C = new CNSCRFile("BGS:mc000_02.NSCR", 0, 0, 0);
    unk_70 = new CNSCRFile("BGS:mc000_03.NSCR", 0, 0, 0);
    delete archive;

    int charNo = 0;
    CGame *game = CGame::GetInstance();
    unk_50 = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x00], game->unk_14A8, TRUE, 0x40);
    unk_50->LoadFiles("data/menu", "ma000_00", 0, 0);
    charNo += unk_50->unk_28;
    unk_54 = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x10], game->unk_14A8, TRUE, 0x40);
    unk_54->LoadFiles("data/menu", "ma001_00", charNo, 3);
    charNo += unk_54->unk_28;
    unk_58 = new OamSpriteSet((GXOamAttr *)&game->unk_0424[0x50], game->unk_14A8, TRUE, 0x40);
    unk_58->LoadFiles("data/menu", "ma004_00", charNo, 8);
}

void SubScreenPartyPanel::SetupBG()
{
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB1, unk_68->unk_B8, unk_60->unk_B8, unk_64->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x00000);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB2, unk_6C->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7000, GX_BG_CHARBASE_0x00000);
    NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB3, unk_70->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7800, GX_BG_CHARBASE_0x00000);
}

void SubScreenPartyPanel::SetupBlend()
{
    if (unk_20 == 1) {
        MI_CpuCopyFast((u8 *)G2S_GetBG1ScrPtr() + 0x600, (u8 *)G2S_GetBG1ScrPtr() + 0xC0, 0x100);
    }
    if (unk_2C - unk_20 > 2) {
        for (int i = 0; i < 5; i++) {
            MI_CpuCopy16((u8 *)G2S_GetBG1ScrPtr() + 0x700, (u8 *)G2S_GetBG1ScrPtr() + ((i * 2 + 11) * 0x40 + 6), 0x34);
            MI_CpuCopy16((u8 *)G2S_GetBG1ScrPtr() + 0x740, (u8 *)G2S_GetBG1ScrPtr() + ((i * 2 + 12) * 0x40 + 6), 0x34);
            if (i + 3 >= unk_2C - unk_20) {
                break;
            }
        }
    }
    GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    G2S_SetBG1Priority(1);
    G2S_SetBG2Priority(2);
    G2S_SetBG3Priority(3);
    G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_BG1, GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ, 8, 8);
}

void SubScreenPartyPanel::DrawTexts()
{
    u8 name[32];
    TextWindow windows[18] = {
        { 16, 2, 8, 1, 0, 0, 1 },
        { 10, 2, 20, 21, 4, 4, 3 },
        { 8, 2, 6, 4, 4, 3, 3 },
        { 11, 2, 15, 4, 4, 3, 3 },
        { 8, 2, 4, 7, 0, 3, 3 },
        { 11, 2, 13, 7, 2, 3, 3 },
        { 8, 2, 4, 9, 2, 3, 3 },
        { 11, 2, 13, 9, 2, 3, 3 },
        { 8, 2, 4, 11, 2, 3, 3 },
        { 11, 2, 13, 11, 2, 3, 3 },
        { 8, 2, 4, 13, 2, 3, 3 },
        { 11, 2, 13, 13, 2, 3, 3 },
        { 8, 2, 4, 15, 2, 3, 3 },
        { 11, 2, 13, 15, 2, 3, 3 },
        { 8, 2, 4, 17, 2, 3, 3 },
        { 11, 2, 13, 17, 2, 3, 3 },
        { 8, 2, 4, 19, 2, 3, 3 },
        { 11, 2, 13, 19, 2, 3, 3 },
    };
    CGame *game = CGame::GetInstance();

    game->unk_1498->FreeWindows();
    game->unk_1498->SetupBG();
    game->unk_1498->AllocWindows(18);

    int charNo = 0x60;
    for (int i = 0; i < 18; i++) {
        game->unk_1498->InitWindow(i, windows[i].width, windows[i].height, windows[i].left, windows[i].top, charNo, 0, 2);
        charNo += windows[i].width * windows[i].height;
    }

    game->unk_1498->Print(0, windows[0].x, windows[0].y, windows[0].color, unk_74->unk_08[19].unk_04, TRUE, 0);
    game->unk_1498->Print(1, windows[1].x, windows[1].y, windows[1].color, unk_74->unk_08[20].unk_04, FALSE, 0);
    game->unk_1498->Print(1, 0x33, windows[1].y, windows[1].color, unk_74->unk_08[unk_28 + 8].unk_04, FALSE, 0);
    game->unk_1498->Print(1, 0x3D, windows[1].y, windows[1].color, unk_74->unk_08[30].unk_04, FALSE, 0);
    game->unk_1498->Print(1, 0x47, windows[1].y, windows[1].color, unk_74->unk_08[unk_2C + 8 - unk_20].unk_04, FALSE, 0);

    if (unk_20 != 0) {
        CopyStringUpper(NameTables_GetPokemonName(game->m_nameTables, unk_30[0]), name, 0x1F);
        game->unk_1498->Print(2, windows[2].x, windows[2].y, windows[2].color, name, TRUE, 0);
        game->unk_1498->Print(3, windows[3].x, windows[3].y, windows[3].color, unk_74->unk_08[unk_24 + 0x15].unk_04, TRUE, 0);
    }

    for (int i = 0; i < unk_28; i++) {
        int n = i + 1;
        int j = i * 2 + 4;
        int k = i * 2 + 5;
        CopyStringUpper(NameTables_GetPokemonName(game->m_nameTables, unk_30[n]), name, 0x1F);
        game->unk_1498->Print(j, windows[j].x, windows[j].y, windows[j].color, name, TRUE, 0);
        SubTextPrinter *text = game->unk_1498;
        text->Print(k, windows[k].x, windows[k].y, windows[k].color, NameTables_GetFieldMoveName(game->m_nameTables, unk_40[n]), TRUE, 0);
    }
}

void SubScreenPartyPanel::Update()
{
    CGame *game = CGame::GetInstance();
    unk_5C->SetPos(unk_5C->unk_0C, game->unk_15D0 >> FX32_SHIFT);
    unk_58->Update();
}

void SubScreenPartyPanel::Render()
{
    unk_50->WriteOam();
    unk_54->WriteOam();
    unk_58->WriteOam();
}
