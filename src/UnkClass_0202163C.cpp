#include "UnkClass_0202163C.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "UnkClass_0200CAB4.hpp"
#include "UnkClass_0200E960.hpp"
#include "UnkClass_0200ECD0.hpp"
#include "UnkClass_0201FC80.hpp"
#include "UnkClass_02021404.hpp"
#include "UnkClass_02041D80.hpp"
#include "common.hpp"

extern UnkClass_02041C80 *MAIN_BSS_0210CA6C;

UnkClass_0202163C::UnkClass_0202163C(CGame *game)
{
    unk_A8 = game;
    Init();
}

UnkClass_0202163C::~UnkClass_0202163C()
{
    Release();
}

void UnkClass_0202163C::Release()
{
    SAFE_DELETE(unk_3C);
    SAFE_DELETE(unk_40);
    SAFE_DELETE(unk_44);
    SAFE_DELETE(unk_48);
    SAFE_DELETE(unk_4C);
    SAFE_DELETE(unk_50);
    unk_A8->unk_1498->sub_0200CAE0();
    SAFE_DELETE(unk_A4);
}

void UnkClass_0202163C::Update()
{
    if (unk_58 != NULL) {
        unk_58->sub_0200EB28(0x80, unk_A8->unk_15D0 >> 12);
    }
    if (unk_48 != NULL) {
        unk_48->sub_0200F64C();
    }
    if (unk_4C != NULL) {
        unk_4C->sub_0200F64C();
    }
    if (unk_50 != NULL) {
        unk_50->sub_0200F64C();
    }
}

void UnkClass_0202163C::Render()
{
    Draw();
}

void UnkClass_0202163C::Init()
{
    unk_30 = 0;
    unk_34 = 0;
    unk_3C = NULL;
    unk_40 = NULL;
    unk_44 = NULL;
    unk_48 = NULL;
    unk_4C = NULL;
    unk_50 = NULL;
    unk_98 = 0;
    unk_38 = -1;
    unk_A4 = NULL;
    unk_9C = 0;
}

void UnkClass_0202163C::Draw()
{
    int ox = 0;
    int oy = 0;
    if (unk_44 != NULL) {
        unk_44->Scroll((unk_30 >> 2) - 0x80, (unk_34 >> 2) - 0x60);
        ox = unk_44->unk_54;
        oy = unk_44->unk_58;
    }
    unk_54->sub_0200EB28((unk_30 >> 2) - ox, (unk_34 >> 2) - oy);
    if (unk_48 != NULL) {
        unk_48->sub_0200F71C();
    }
    if (unk_4C != NULL) {
        unk_4C->sub_0200F71C();
    }
    if (unk_50 != NULL) {
        DrawIcons(ox, oy);
    }
}

void UnkClass_0202163C::DrawIcons(int x, int y)
{
    for (int i = 0; i < 5; i++) {
        if (unk_5C[i].unk_00 != NULL) {
            int ix = (unk_5C[i].unk_04 >> 2) - x;
            int iy = (unk_5C[i].unk_06 >> 2) - y;
            if (ix < 0 || ix >= 0x100 || iy < 0 || iy >= 0xC0) {
                unk_5C[i].unk_00->unk_14 = 0;
            } else {
                unk_5C[i].unk_00->unk_14 = 1;
                unk_5C[i].unk_00->sub_0200EB28(ix, iy);
            }
        }
    }
    unk_50->sub_0200F71C();
}

void UnkClass_0202163C::Load()
{
    Release();
    SetupBG();
    unk_A4 = new UnkClass_02021404("/data/message/etc/place_name");
    unk_3C = new UnkClass_0201FC80((int)unk_A8);
    unk_40 = new UnkClass_0201FC80((int)unk_A8);
    unk_44 = new UnkClass_0201FC80((int)unk_A8);

    unk_3C->SetBG(5);
    unk_3C->LoadArchive("menu/", "mm000_");
    unk_3C->LoadChar("mm000_00", 0, 0, 0);
    unk_3C->LoadPltt("mm000", 0, 0, 0);
    unk_3C->LoadScr("mm000_00", 0, 0, 0, 0, 0);
    unk_3C->ReleaseArchive();
    unk_3C->Setup(0x100, 0x100);

    unk_40->SetBG(7);
    unk_40->LoadArchive("menu/", "mm000_");
    unk_40->LoadScr("mm000_01", 0, 0, 0, 0, 0);
    unk_40->ReleaseArchive();
    unk_40->Setup(0x100, 0x100);

    unk_44->SetBG(6);
    unk_44->LoadArchive("menu/", "um_");
    unk_44->LoadChar("um000_00", 0, 0, 0);
    unk_44->LoadPltt("um000", 0, 5, 0);
    unk_44->ReleaseArchive();
    unk_44->Setup(0x100, 0x100);

    LoadOAM();
}

void UnkClass_0202163C::LoadOAM()
{
    SAFE_DELETE(unk_48);
    SAFE_DELETE(unk_4C);
    SAFE_DELETE(unk_50);

    int size = 0;
    unk_A0 = 0;
    unk_48 = new UnkClass_0200ECD0((GXOamAttr *)&unk_A8->unk_0424[(u8)unk_A0], unk_A8->unk_14A8, TRUE, 0x40);
    size += unk_48->sub_0200F168("data/menu", "mm001_00", 0, 0);
    unk_48->sub_0200F398();
    unk_54 = unk_48->sub_0200F4FC(0, 0x80, 0x60, 0);
    unk_A0 += unk_48->unk_30;

    unk_4C = new UnkClass_0200ECD0((GXOamAttr *)&unk_A8->unk_0424[(u8)unk_A0], unk_A8->unk_14A8, TRUE, 0x40);
    size += unk_4C->sub_0200F168("data/menu", "ma004_00", size / 32, 3);
    unk_4C->sub_0200F398();
    unk_58 = unk_4C->sub_0200F4FC(0, 0, 0, 2);
    unk_A0 += unk_4C->unk_30;

    unk_50 = new UnkClass_0200ECD0((GXOamAttr *)&unk_A8->unk_0424[(u8)unk_A0], unk_A8->unk_14A8, TRUE, 0x40);
    unk_50->sub_0200F168("data/menu", "mm001_03", size / 32, 4);
    unk_50->sub_0200F398();
}

void UnkClass_0202163C::LoadOAMToVram()
{
    unk_48->sub_0200F398();
    unk_4C->sub_0200F398();
    unk_50->sub_0200F398();
}

void UnkClass_0202163C::LoadMapScr()
{
    char path[0x40];
    UnkClass_02041C80 *table = MAIN_BSS_0210CA6C;
    u8 a = sub_02041D80(table, unk_38)->unk_00;
    u8 b = sub_02041D80(table, unk_38)->unk_01;
    u8 c = sub_02041D80(table, unk_38)->unk_02;
    if (c == 0xFF) {
        OS_SPrintf(path, "data/menu/um%03d_%03d_LZ.bin", a, b);
    } else {
        OS_SPrintf(path, "data/menu/um%03d_%03d%c_LZ.bin", a, b, c + 'a');
    }
    if (unk_44->LoadScrFile(path, 0, 5, 0, 0, 1) == NULL) {
        unk_44->LoadScrFile("data/menu/um004_001_LZ.bin", 0, 5, 0, 0, 1);
    }
}

void UnkClass_0202163C::Hide()
{
    if (unk_44 != NULL) {
        unk_38 = -1;
        unk_44->FreeScr();
        unk_A8->unk_1498->sub_0200CAE0();
    }
}

void UnkClass_0202163C::DrawPlaceName()
{
    u8 id = sub_02041D80(MAIN_BSS_0210CA6C, unk_38)->unk_00;
    if (id >= 200) {
        id -= 155;
    }
    unk_A8->unk_1498->sub_0200CAE0();
    unk_A8->unk_1498->sub_0200CB14();
    unk_A8->unk_1498->sub_0200CC88(1);
    unk_A8->unk_1498->sub_0200CCD0(0, 0x10, 2, 8, 1, 0x334, 0, 2);
    UnkClass_0200CAB4 *printer = unk_A8->unk_1498;
    printer->sub_0200CDA0(0, 0, 0, 1, (u8 *)unk_A4->GetString(id), TRUE, 0);
}

void UnkClass_0202163C::LoadToVram()
{
    SetupBG();
    unk_3C->LoadToVram();
    unk_40->LoadToVram();
    unk_44->LoadCharToVram();
    unk_44->LoadPlttToVram(FALSE);
    DrawPlaceName();
    unk_44->Draw((unk_30 >> 2) - 0x80, (unk_34 >> 2) - 0x60);
    LoadOAMToVram();
}

void UnkClass_0202163C::SetupBG()
{
    GXS_SetGraphicsMode(GX_BGMODE_0);
    GXS_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    G2S_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x1000, GX_BG_CHARBASE_0x00000, GX_BG_EXTPLTT_01);
    G2S_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x1800, GX_BG_CHARBASE_0x04000);
    G2S_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x2000, GX_BG_CHARBASE_0x00000);
    G2S_SetBG0Priority(0);
    G2S_SetBG1Priority(1);
    G2S_SetBG2Priority(2);
    G2S_SetBG3Priority(3);
    G2S_BG0Mosaic(FALSE);
    G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_BG2 | GX_BLEND_PLANEMASK_BG3, 5, 0x1A);
}

BOOL UnkClass_0202163C::Show(int mapId, int x, int y)
{
    SetPos(x, y);
    if (unk_38 != mapId) {
        unk_38 = mapId;
        SetupBG();
        LoadMapScr();
    }
    unk_38 = mapId;
    LoadToVram();
    return TRUE;
}

BOOL UnkClass_0202163C::SetMap(int mapId, int x, int y)
{
    SetPos(x, y);
    if (unk_38 != mapId) {
        unk_38 = mapId;
        LoadMapScr();
    }
    unk_38 = mapId;
    return TRUE;
}

void UnkClass_0202163C::SetPos(int x, int y)
{
    unk_30 = x;
    unk_34 = y;
}

void UnkClass_0202163C::ClearIcons()
{
    for (int i = 0; i < 5; i++) {
        unk_5C[i].unk_08 = 3;
        unk_5C[i].unk_00 = NULL;
        unk_5C[i].unk_04 = 0;
        unk_5C[i].unk_06 = 0;
    }
    if (unk_50 != NULL) {
        unk_50->sub_0200F6C4();
    }
}

BOOL UnkClass_0202163C::AddIcon(int x, int y, int kind)
{
    if (unk_48 == NULL) {
        return FALSE;
    }
    for (int i = 0; i < 5; i++) {
        if (unk_5C[i].unk_00 == NULL) {
            int anim;
            switch (kind) {
            case 0:
                anim = 0;
                break;
            case 1:
                anim = 1;
                break;
            default:
                anim = 0;
                break;
            }
            unk_5C[i].unk_00 = unk_50->sub_0200F4FC(anim, 0, 0, 2);
            unk_5C[i].unk_04 = x;
            unk_5C[i].unk_06 = y;
            unk_5C[i].unk_08 = kind;
            unk_A0 += unk_48->unk_30;
            return TRUE;
        }
    }
    return FALSE;
}
