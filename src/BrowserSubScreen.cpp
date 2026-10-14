#include "BrowserSubScreen.hpp"

#include "SubTextPrinter.hpp"

BrowserSubScreen::BrowserSubScreen(CGame *game)
{
    unk_48 = game;
    ov21_021220B8();
}

BrowserSubScreen::~BrowserSubScreen()
{
    ov21_02122180();
}

void BrowserSubScreen::ov21_021220B8()
{
    unk_00 = 0;
    unk_10 = NULL;
    for (int i = 0; i < 6; i++) {
        unk_24[i] = 0;
    }
    unk_04 = 0;
    unk_3C = NULL;
    unk_08 = new RegionMap(unk_48);
    unk_40 = 0;
}

void BrowserSubScreen::ov21_02122114()
{
    if (unk_08 != NULL) {
        unk_08->Update();
    }
}

void BrowserSubScreen::ov21_0212212C()
{
    if (unk_08 != NULL) {
        unk_08->Render();
    }
}

void BrowserSubScreen::ov21_02122144()
{
    if (unk_08 != NULL) {
        unk_08->sub_0202A5F8();
    }
    ov21_02122608();
}

void BrowserSubScreen::ov21_02122168()
{
    unk_48->unk_1498->LoadPalette();
}

void BrowserSubScreen::ov21_02122180()
{
    unk_48->unk_1498->FreeWindows();
    SAFE_DELETE(unk_10);
    SAFE_DELETE(unk_08);
    SAFE_DELETE(unk_3C);
}

void BrowserSubScreen::ov21_02122214()
{
    ov21_02122368();

    int charNo = 0;
    int paletteSlot = 0;
    u8 oamIndex = 0x20;
    unk_08->Load(6, &oamIndex, &charNo, &paletteSlot, FALSE);

    SAFE_DELETE(unk_10);
    unk_10 = new MessageTable("data/message/etc/pokebook_info");

    SAFE_DELETE(unk_3C);
    unk_3C = new BGLayer((int)unk_48);
    unk_3C->SetBG(5);
    unk_3C->LoadArchive("menu/", "mam000_bg_");
    unk_3C->LoadChar("mam000", 0, 0, 0);
    unk_3C->LoadPltt("mam000", 0, 8, 0);
    unk_3C->LoadScr("mam000_01", 0, 8, 0, 0, 0);
    unk_3C->ReleaseArchive();
}

void BrowserSubScreen::ov21_02122368()
{
    GXS_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    GXS_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
    G2S_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x4000, GX_BG_CHARBASE_0x0c000, GX_BG_EXTPLTT_01);
    G2S_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_256, GX_BG_SCRBASE_0x4800, GX_BG_CHARBASE_0x10000);
    G2S_SetBG0Priority(0);
    G2S_SetBG1Priority(0);
    G2S_SetBG2Priority(3);
}

void BrowserSubScreen::ov21_021223FC()
{
    if (unk_08 != NULL) {
        unk_08->LoadToVram(FALSE);
    }
    unk_3C->LoadCharToVram();
    unk_3C->LoadPlttToVram(FALSE);
    unk_3C->LoadScrToVram();
    ov21_021226AC();
    unk_48->unk_1498->FreeWindows();
    unk_48->unk_1498->SetupBG();
    unk_48->unk_1498->AllocWindows(1);
    unk_48->unk_1498->InitWindow(0, 0x10, 2, 1, 0, 0xD, 0, 2);
}

void BrowserSubScreen::ov21_021224B4(const UnkStruct_02123618 *entry)
{
    unk_00 = 1;
    unk_40 = 1;
    unk_14 = *entry;
}

void BrowserSubScreen::ov21_021224E4(const UnkStruct_02123618 *entry)
{
    ov21_02122368();
    unk_00 = 1;
    unk_40 = 1;
    unk_14 = *entry;
    ov21_021223FC();
    ov21_02122168();
}

BOOL BrowserSubScreen::ov21_02122534()
{
    if (unk_08 != NULL) {
        if (unk_08->sub_0202AF5C(&unk_14.unk_04)) {
            GXS_SetVisiblePlane(GXS_GetVisiblePlane() & ~GX_PLANEMASK_BG1);
            G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 8, 8);
        } else {
            GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG1);
            G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_BG2, GX_BLEND_PLANEMASK_BD, 8, 8);
        }
        unk_08->sub_0202B50C(0, 4);
    }
    return TRUE;
}

void BrowserSubScreen::ov21_021225F8(u16 id)
{
    unk_44 = id;
    unk_04 = 1;
}

void BrowserSubScreen::ov21_02122608()
{
    if (unk_40) {
        ov21_02122534();
        unk_40 = 0;
    }
    if (!unk_04) {
        return;
    }
    unk_04 = 0;
    if (unk_08 == NULL) {
        return;
    }
    unk_48->unk_1498->ClearWindow(0);
    SubTextPrinter *text = unk_48->unk_1498;
    text->Print(0, 0, 3, 3, (u8 *)unk_10->GetString(0x15), TRUE, 0);
}

void BrowserSubScreen::ov21_021226AC()
{
    ov21_021225F8(unk_08->unk_56);
}
