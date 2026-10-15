#include "scene/CMapDispScreen.hpp"

#include "AudioEngine.hpp"
#include "BrightnessFade.hpp"
#include "TextPrinter.hpp"

CMapDispScreen::CMapDispScreen(CGame *game)
{
    unk_3C = game;
    ov28_0211D19C();
}

CMapDispScreen::~CMapDispScreen()
{
    ov28_0211D380();
}

void CMapDispScreen::ov28_0211D19C()
{
    unk_00 = 0;
    unk_18 = NULL;
    unk_14 = NULL;
    unk_08 = NULL;
    for (int i = 0; i < 6; i++) {
        unk_20[i] = NULL;
    }
    unk_04 = 0;
    unk_0C = new RegionMap(unk_3C);
    unk_08 = new CMapDispRscLoader();
    unk_08->m_pathBuilder = &unk_40;
}

void CMapDispScreen::ov28_0211D218()
{
    if (unk_18 != NULL) {
        unk_18->Update();
    }
    if (unk_08 != NULL) {
        unk_08->Update();
    }
    if (unk_0C != NULL) {
        unk_0C->Update();
    }
    switch (unk_00) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 5:
        break;
    case 1:
        ov28_0211D794();
        break;
    case 6:
        if (unk_08 != NULL && !unk_08->Quit()) {
            break;
        }
        unk_00 = 7;
        break;
    case 7:
        if (unk_08 != NULL && !unk_08->IsDone()) {
            break;
        }
        ov28_0211DA24();
        unk_00 = 2;
        break;
    }
}

void CMapDispScreen::ov28_0211D2DC()
{
    if (unk_0C != NULL) {
        unk_0C->Render();
    }
    switch (unk_00) {
    case 2:
        if (!ov28_0211DA68()) {
            unk_00 = 4;
        }
    case 1:
    case 3:
    case 5:
    case 6:
    case 7:
        ov28_0211D450();
        break;
    }
}

void CMapDispScreen::ov28_0211D344()
{
    if (unk_0C != NULL) {
        unk_0C->sub_0202A5F8();
    }
    ov28_0211D8AC();
}

void CMapDispScreen::ov28_0211D368()
{
    unk_3C->unk_1494->LoadPalette();
}

void CMapDispScreen::ov28_0211D380()
{
    unk_3C->unk_146C.SetFps(30);
    unk_3C->unk_1494->FreeWindows();
    SAFE_DELETE(unk_08);
    SAFE_DELETE(unk_14);
    SAFE_DELETE(unk_18);
    SAFE_DELETE(unk_0C);
}

void CMapDispScreen::ov28_0211D450()
{
    if (unk_18 != NULL) {
        unk_18->WriteOam();
    }
}

void CMapDispScreen::ov28_0211D468()
{
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG2 | GX_PLANEMASK_OBJ);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2_SetBG0Offset(0, 0);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
    G2_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_256, GX_BG_SCRBASE_0x4800, GX_BG_CHARBASE_0x10000);
    G2_SetBG0Priority(0);
    G2_SetBG1Priority(1);
    G2_SetBG2Priority(3);
    unk_3C->m_audioEngine->LoadSystemSe();

    int charNo = 0;
    u8 oamIndex = 0x20;
    SAFE_DELETE(unk_18);
    unk_18 = new OamSpriteSet((GXOamAttr *)&unk_3C->unk_0024[oamIndex], unk_3C->unk_14A8, FALSE, 0x40);
    charNo += unk_18->Load("data/menu", "ma005_00", charNo / 32, 0);
    unk_20[3] = unk_18->AddSprite(0, 0xF0, 0x10, 0);
    unk_20[3]->SetTouchRect(0x20, 0x20, 0, 0);
    oamIndex += unk_18->unk_30;
    int paletteSlot = 2;
    unk_0C->Load(2, &oamIndex, &charNo, &paletteSlot, FALSE);

    SAFE_DELETE(unk_14);
    unk_14 = new MessageTable("/data/message/etc/place_name");

    if (unk_08 != NULL) {
        unk_08->SetupBG();
    }
    ov28_0211D980();
    unk_3C->unk_1494->FreeWindows();
    unk_3C->unk_1494->SetupBG(0, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x00000);
    unk_3C->unk_1494->AllocWindows(1);
    unk_3C->unk_1494->InitWindow(0, 0x10, 2, 1, 0, 0xD, 0, 2);
}

BOOL CMapDispScreen::ov28_0211D700()
{
    unk_00 = 1;
    ov28_0211D718();
    return TRUE;
}

BOOL CMapDispScreen::ov28_0211D718()
{
    ov28_0211D468();
    ov28_0211D368();
    unk_3C->unk_146C.SetFps(60);
    return TRUE;
}

static const u16 sPlaceRsc[][2] = {
    { 0x08, 0x1F8 },
    { 0x07, 0x1F4 },
    { 0x04, 0x1F6 },
    { 0x05, 0x1F6 },
    { 0x02, 0x1F4 },
    { 0x03, 0x1F4 },
    { 0x01, 0x1F5 },
    { 0x06, 0x1F7 },
    { 0x09, 0x1F4 },
    { 0x0A, 0x1F9 },
    { 0x0E, 0x1FB },
    { 0xC9, 0x1F4 },
    { 0x0B, 0x1FA },
    { 0x0F, 0x1F4 },
    { 0x11, 0x1FE },
    { 0x10, 0x1FD },
    { 0xCA, 0x1F4 },
    { 0x12, 0x1FF },
    { 0x13, 0x200 },
    { 0x14, 0x201 },
    { 0x78, 0x201 },
    { 0x15, 0x1F4 },
    { 0x16, 0x202 },
    { 0x17, 0x203 },
    { 0x18, 0x1F4 },
    { 0x1A, 0x1F4 },
    { 0x19, 0x204 },
    { 0x1B, 0x1F4 },
    { 0x1C, 0x205 },
    { 0xCB, 0x1F4 },
    { 0x1D, 0x206 },
    { 0x1E, 0x207 },
    { 0xCC, 0x1F4 },
    { 0x20, 0x208 },
    { 0x21, 0x208 },
    { 0x22, 0x1F4 },
    { 0x23, 0x1F4 },
    { 0x24, 0x209 },
    { 0x26, 0x1FC },
    { 0x27, 0x20A },
    { 0x29, 0x20B },
    { 0x2A, 0x20B },
    { 0x2B, 0x20B },
    { 0x2C, 0x20B },
};

void CMapDispScreen::ov28_0211D748(int id)
{
    CMapDispRscLoader *loader = unk_08;
    if (loader == NULL) {
        return;
    }
    u32 i;
    u16 rsc = 1;
    for (i = 0; i < 0x2C; i++) {
        if (id == sPlaceRsc[i][0]) {
            rsc = sPlaceRsc[i][1];
        }
    }
    loader->Request(rsc);
}

void CMapDispScreen::ov28_0211D794()
{
    u32 cancel = (u16)(unk_3C->unk_0014->unk_0002 & PAD_BUTTON_B);
    BOOL touched = unk_20[3]->GetTouchTrigger() ? TRUE : FALSE;
    if (touched | cancel) {
        ov28_0211D844();
        return;
    }
    s16 kind;
    u16 id;
    unk_0C->GetSelection(&kind, &id);
    switch ((u16)kind) {
    case 1:
        unk_3C->m_audioEngine->PlaySe(0xFA);
        ov28_0211D980();
        break;
    case 6:
        unk_3C->m_audioEngine->PlaySe(0xFA);
        ov28_0211D9AC(id);
        break;
    }
}

void CMapDispScreen::ov28_0211D844()
{
    unk_3C->m_audioEngine->PlaySe(0x103);
    if (unk_08 != NULL) {
        unk_00 = 6;
        return;
    }
    unk_00 = 2;
    ov28_0211DA24();
}

void CMapDispScreen::ov28_0211D88C(u16 id)
{
    ov28_0211D748(id);
    unk_38 = id;
    unk_04 = 1;
}

void CMapDispScreen::ov28_0211D8AC()
{
    if (!unk_04) {
        return;
    }
    unk_04 = 0;
    if (unk_0C == NULL) {
        return;
    }
    u8 idx = unk_38;
    if (idx > 200) {
        idx -= 155;
    } else if (idx > 100) {
        idx %= 100;
    }
    unk_3C->unk_1494->ClearWindow(0);
    TextPrinter *text = unk_3C->unk_1494;
    text->Print(0, 0, 3, 3, (u8 *)unk_14->GetString(idx), TRUE, 0);
}

void CMapDispScreen::ov28_0211D980()
{
    u16 id = unk_0C->unk_56;
    ov28_0211D9D0(id, 1);
    ov28_0211D88C(id);
}

void CMapDispScreen::ov28_0211D9AC(u16 id)
{
    ov28_0211D9D0(id, 3);
    ov28_0211D88C(id);
}

void CMapDispScreen::ov28_0211D9D0(u16 id, int mode)
{
    unk_0C->sub_0202B50C(id, mode);
}

void CMapDispScreen::ov28_0211D9E0()
{
    if (unk_3C != NULL) {
        unk_3C->m_subFade->Start(3, 15);
        unk_3C->m_mainFade->Start(3, 15);
    }
}

void CMapDispScreen::ov28_0211DA24()
{
    if (unk_3C != NULL) {
        unk_3C->m_subFade->Start(4, 15);
        unk_3C->m_mainFade->Start(4, 15);
    }
}

BOOL CMapDispScreen::ov28_0211DA68()
{
    if (unk_3C->m_subFade->IsActive() || unk_3C->m_subFade->IsActive()) {
        return TRUE;
    }
    return FALSE;
}

int CMapDispScreen::ov28_0211DAB0()
{
    return unk_00 != 4 ? -1 : 0;
}

BOOL CMapDispScreen::CPathBuilder::GetArchivePath(int id, char *buf, int size)
{
    OS_SPrintf(buf, "data/menu/rd%03d_LZ.bin", id);
    return TRUE;
}

BOOL CMapDispScreen::CPathBuilder::GetFilePath(int id, char *buf, int size)
{
    OS_SPrintf(buf, "rd%03d.nbfs", id);
    return TRUE;
}
