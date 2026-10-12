#include "UnkClass_0201B724.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "CGame.hpp"
#include "UnkClass_0200CAB4.hpp"
#include "UnkClass_02018208.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkClass_020B26A0.hpp"
#include "common.hpp"
#include "file/CBinaryFileMes.hpp"

extern UnkClass_02041D80 *MAIN_BSS_0210CA6C;

extern "C" {
u8 *sub_02018B48(UnkClass_02018208 *obj, u32 i);
u8 *sub_02018B80(UnkClass_02018208 *obj, u32 i);
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

UnkClass_0201B724::UnkClass_0201B724()
{
    unk_04 = 0;
    unk_00 = 0;
    unk_08 = 0;
    unk_0A = 0;
    unk_0B = 0;
    unk_0C = 0;
    unk_0E = 0;
    unk_10 = 0;
    unk_12 = 0;
    unk_14 = NULL;
    unk_18 = NULL;
    unk_1C = NULL;
    unk_20 = NULL;
    unk_24 = NULL;
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
}

UnkClass_0201B724::~UnkClass_0201B724()
{
    Release();
    ReleaseBG();
}

void UnkClass_0201B724::Release()
{
    CGame *game = CGame::GetInstance();

    RELEASE_MESSAGES(unk_2C);
    RELEASE_MESSAGES(unk_30);
    RELEASE_MESSAGES(unk_34);

    SAFE_DELETE(unk_14);
    SAFE_DELETE(unk_18);
    SAFE_DELETE(unk_1C);
    SAFE_DELETE(unk_20);
    SAFE_DELETE(unk_24);

    game->unk_1498->sub_0200CAE0();
}

void UnkClass_0201B724::ResetLoad()
{
    unk_50 = 0;
}

int UnkClass_0201B724::Load(u32 id)
{
    CGame *game = CGame::GetInstance();
    u32 pos;

    switch (unk_50) {
    case 0: {
        if (unk_14 != NULL) {
            Release();
        }
        unk_04 = id;
        UnkClass_02041D80 *table = MAIN_BSS_0210CA6C;
        unk_00 = sub_02041D80(table, MAIN_BSS_020B26A0.unk_001A)->unk_00;
        FieldTargetObjectData *info = sub_02041D6C(table, id);
        unk_08 = info->unk_00;
        unk_0A = info->unk_02;
        unk_0B = info->unk_04;
        unk_0C = info->unk_05;
        unk_12 = info->unk_1C;
        unk_0E = info->unk_18;
        unk_10 = info->unk_1A;
        if (unk_0E >= 0xE && unk_0E <= 0x12) {
            if ((int)game->m_missionQuestData->unk_08 <= 0x1C) {
                unk_0E = 0x80;
                unk_10 = 0x80;
            }
        }
        unk_50 = 1;
        break;
    }
    case 1:
        LOAD_MESSAGES(unk_2C, "/data/message/etc/place_name");
        unk_50 = 2;
        break;
    case 2:
        LOAD_MESSAGES(unk_30, "/data/message/etc/yakumono_info");
        unk_50 = 3;
        break;
    case 3:
        LOAD_MESSAGES(unk_34, "/data/message/etc/menu_mes");
        unk_50 = 4;
        break;
    case 4: {
        unk_54 = 0;
        char name[12];
        OS_SPrintf(name, "bt%03d_%02d", unk_08, unk_0A);
        unk_14 = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0424[0x20], game->unk_14A8, TRUE, 0x40);
        unk_54 = unk_14->sub_0200EE14("data/targetOBJ", name, 0, 0);
        unk_14->sub_0200F4FC(0, 0x38, 0x50, 1);
        unk_50 = 5;
        break;
    }
    case 5:
        unk_18 = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0424[0x00], game->unk_14A8, TRUE, 0x40);
        unk_54 += unk_18->sub_0200EE14("data/menu", "mt000_00", unk_54 / 32, 1);
        unk_18->sub_0200F4FC(1, 0x9C, 0x4B, 3);
        unk_18->sub_0200F4FC(3, 0x78, 0x25, 0);
        unk_18->sub_0200F4FC(3, 0x78, 0x37, 0);
        unk_18->sub_0200F4FC(3, 0x78, 0x49, 0);
        unk_18->sub_0200F4FC(3, 0x78, 0x5B, 0);
        unk_18->sub_0200F4FC(3, 0x78, 0x6D, 0);
        unk_18->sub_0200F4FC(3, 0x78, 0x7F, 0);
        unk_18->sub_0200F4FC(4, 0x38, 0x7B, 1);
        unk_50 = 6;
        break;
    case 6:
        unk_1C = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0424[0x30], game->unk_14A8, TRUE, 0x40);
        unk_54 += unk_1C->sub_0200EE14("data/menu", "ma004_00", unk_54 / 32, 2);
        unk_28 = unk_1C->sub_0200F4FC(1, 0x38, 0, 2);
        unk_50 = 7;
        break;
    case 7:
        unk_20 = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0424[0x40], game->unk_14A8, TRUE, 0x40);
        unk_54 += unk_20->sub_0200EE14("data/menu", "ma000_00", unk_54 / 32, 3);
        unk_20->sub_0200F4FC(unk_0B, 0x94, 0x5A, 0);
        unk_50 = 8;
        break;
    case 8:
        unk_24 = new UnkClass_0200ECD0((GXOamAttr *)&game->unk_0424[0x50], game->unk_14A8, TRUE, 0x40);
        unk_54 += unk_24->sub_0200EE14("data/menu", "ma001_00", unk_54 / 32, 6);
        unk_24->sub_0200F4FC(unk_0C, 0xA0, 0x5A, 0);
        unk_50 = 11;
        break;
    case 11:
        DC_FlushAll();
        NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB1, unk_44->unk_B8, unk_3C->unk_B8, unk_40->unk_B8, NULL, NULL, GX_BG_SCRBASE_0x6800, GX_BG_CHARBASE_0x00000);
        unk_50 = 12;
        break;
    case 12:
        DC_FlushAll();
        NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB2, unk_48->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7000, GX_BG_CHARBASE_0x00000);
        unk_50 = 13;
        break;
    case 13:
        DC_FlushAll();
        NNS_G2dBGSetupEx(NNS_G2D_BGSELECT_SUB3, unk_4C->unk_B8, NULL, NULL, NULL, NULL, GX_BG_SCRBASE_0x7800, GX_BG_CHARBASE_0x00000);
        SetupBlend();
        unk_50 = 15;
        break;
    case 15:
        DrawTexts();
        unk_50 = 16;
        break;
    }

    return unk_50;
}

// Not referenced (mwld strips it); its use of the archive path is what places that string before "TGT"
void UnkClass_0201B724::LoadArchive(const char *name)
{
    unk_38 = new CArchiveGuard(name, "data/menu/mt000_bg_LZ.bin", 1, 1, 0, NULL, 0);
}

void UnkClass_0201B724::LoadBG()
{
    unk_38 = new CArchiveGuard("TGT", "data/menu/mt000_bg_LZ.bin", 1, 1, 0, NULL, 0);
    unk_3C = new CBGNCGRFile("TGT:mt000.NCGR", 2, 0, 0);
    unk_40 = new CNCLRFile("TGT:mt000.NCLR", 2, 0, 0);
    unk_44 = new CNSCRFile("TGT:mt000_01_2.NSCR", 2, 0, 0);
    unk_48 = new CNSCRFile("TGT:mt000_02.NSCR", 2, 0, 0);
    unk_4C = new CNSCRFile("TGT:mt000_03.NSCR", 2, 0, 0);
}

void UnkClass_0201B724::ReleaseBG()
{
    SAFE_DELETE(unk_4C);
    SAFE_DELETE(unk_48);
    SAFE_DELETE(unk_44);
    SAFE_DELETE(unk_3C);
    SAFE_DELETE(unk_40);
    SAFE_DELETE(unk_38);
}

void UnkClass_0201B724::SetupBlend()
{
    GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    G2S_SetBG1Priority(1);
    G2S_SetBG2Priority(2);
    G2S_SetBG3Priority(3);
    G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3 | GX_BLEND_PLANEMASK_OBJ, 4, 0x1B);
}

void UnkClass_0201B724::DrawTexts()
{
    TextWindow windows[6] = {
        { 17, 2, 15, 1, 0, 0, 1 },
        { 14, 2, 18, 6, 4, 2, 5 },
        { 14, 2, 18, 8, 4, 2, 5 },
        { 10, 2, 22, 10, 0, 6, 3 },
        { 12, 2, 1, 14, 4, 6, 3 },
        { 28, 4, 2, 19, 0, 0, 1 },
    };
    CGame *game = CGame::GetInstance();

    game->unk_1498->sub_0200CAE0();
    game->unk_1498->sub_0200CB14();
    game->unk_1498->sub_0200CC88(6);

    int charNo = 0x40;
    for (int i = 0; i < 6; i++) {
        game->unk_1498->sub_0200CCD0(i, windows[i].width, windows[i].height, windows[i].left, windows[i].top, charNo, 0, 2);
        charNo += windows[i].width * windows[i].height;
    }

    game->unk_1498->sub_0200CDA0(0, windows[0].x, windows[0].y, windows[0].color, unk_2C->unk_08[unk_00].unk_04, TRUE, -2);
    game->unk_1498->sub_0200CDA0(1, windows[1].x, windows[1].y, windows[1].color, unk_34->unk_08[2].unk_04, TRUE, 0);
    game->unk_1498->sub_0200CDA0(2, windows[2].x, windows[2].y, windows[2].color, unk_34->unk_08[3].unk_04, TRUE, 0);
    UnkClass_0200CAB4 *text = game->unk_1498;
    text->sub_0200CDA0(3, windows[3].x, windows[3].y, windows[3].color, sub_02018B80(game->unk_14B0, unk_0B), TRUE, 0);
    text = game->unk_1498;
    text->sub_0200CDA0(4, windows[4].x, windows[4].y, windows[4].color, sub_02018B48(game->unk_14B0, unk_0E), TRUE, 0);
    game->unk_1498->sub_0200CDA0(5, windows[5].x, windows[5].y, windows[5].color, unk_30->unk_08[unk_10].unk_04, FALSE, 0);
}

void UnkClass_0201B724::Update()
{
    if (unk_14 == NULL) {
        return;
    }

    CGame *game = CGame::GetInstance();
    unk_28->sub_0200EB28(unk_28->unk_0C, game->unk_15D0 >> FX32_SHIFT);
    unk_18->sub_0200F64C();
    unk_1C->sub_0200F64C();
}

void UnkClass_0201B724::Render()
{
    if (unk_14 == NULL) {
        return;
    }

    unk_14->sub_0200F71C();
    unk_18->sub_0200F71C();
    unk_1C->sub_0200F71C();
    unk_20->sub_0200F71C();
    unk_24->sub_0200F71C();
}

void UnkClass_0201B724::ReleaseMessages()
{
    RELEASE_MESSAGES(unk_2C);
    RELEASE_MESSAGES(unk_30);
    RELEASE_MESSAGES(unk_34);
}
