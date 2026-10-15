#include "BrowserSubScreen.hpp"

#include "SubTextPrinter.hpp"

BrowserSubScreen::BrowserSubScreen(CGame *game)
{
    unk_48 = game;
    Init();
}

BrowserSubScreen::~BrowserSubScreen()
{
    Release();
}

void BrowserSubScreen::Init()
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

void BrowserSubScreen::Update()
{
    if (unk_08 != NULL) {
        unk_08->Update();
    }
}

void BrowserSubScreen::Render()
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
    ApplyPending();
}

void BrowserSubScreen::LoadPalette()
{
    unk_48->unk_1498->LoadPalette();
}

void BrowserSubScreen::Release()
{
    unk_48->unk_1498->FreeWindows();
    SAFE_DELETE(unk_10);
    SAFE_DELETE(unk_08);
    SAFE_DELETE(unk_3C);
}

void BrowserSubScreen::Load()
{
    SetupBg();

    int charNo = 0;
    int paletteSlot = 0;
    u8 oamIndex = 0x20;
    unk_08->Load(6, &oamIndex, &charNo, &paletteSlot, FALSE);

    SAFE_DELETE(unk_10);
    unk_10 = new MessageTable("data/message/etc/pokebook_info");

    SAFE_DELETE(unk_3C);
    unk_3C = new BGLayer(PTR_CAST(int, unk_48));
    unk_3C->SetBG(5);
    unk_3C->LoadArchive("menu/", "mam000_bg_");
    unk_3C->LoadChar("mam000", 0, 0, 0);
    unk_3C->LoadPltt("mam000", 0, 8, 0);
    unk_3C->LoadScr("mam000_01", 0, 8, 0, 0, 0);
    unk_3C->ReleaseArchive();
}

void BrowserSubScreen::SetupBg()
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

void BrowserSubScreen::LoadToVram()
{
    if (unk_08 != NULL) {
        unk_08->LoadToVram(FALSE);
    }
    unk_3C->LoadCharToVram();
    unk_3C->LoadPlttToVram(FALSE);
    unk_3C->LoadScrToVram();
    SetCurrentArea();
    unk_48->unk_1498->FreeWindows();
    unk_48->unk_1498->SetupBG();
    unk_48->unk_1498->AllocWindows(1);
    unk_48->unk_1498->InitWindow(0, 0x10, 2, 1, 0, 0xD, 0, 2);
}

void BrowserSubScreen::SetEntry(const BrowserEntry *entry)
{
    unk_00 = 1;
    unk_40 = 1;
    unk_14 = *entry;
}

void BrowserSubScreen::ShowEntry(const BrowserEntry *entry)
{
    SetupBg();
    unk_00 = 1;
    unk_40 = 1;
    unk_14 = *entry;
    LoadToVram();
    LoadPalette();
}

BOOL BrowserSubScreen::ShowHabitat()
{
    if (unk_08 != NULL) {
        if (unk_08->ShowHabitat(&unk_14.unk_04)) {
            GXS_SetVisiblePlane(GXS_GetVisiblePlane() & ~GX_PLANEMASK_BG1);
            G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_NONE, GX_BLEND_PLANEMASK_NONE, 8, 8);
        } else {
            GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG1);
            G2S_SetBlendAlpha(GX_BLEND_PLANEMASK_BG2, GX_BLEND_PLANEMASK_BD, 8, 8);
        }
        unk_08->SetAreaMarker(0, 4);
    }
    return TRUE;
}

void BrowserSubScreen::SetArea(u16 id)
{
    unk_44 = id;
    unk_04 = 1;
}

void BrowserSubScreen::ApplyPending()
{
    if (unk_40) {
        ShowHabitat();
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

void BrowserSubScreen::SetCurrentArea()
{
    SetArea(unk_08->unk_56);
}
