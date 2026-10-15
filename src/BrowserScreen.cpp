#include "BrowserScreen.hpp"

#include "BGLayer.hpp"
#include "DisplayUtil.hpp"
#include "GlobalValues.hpp"
#include "PokeIdTableEntry.hpp"
#include "SaveData.hpp"
#include "file/CBinaryFileMes.hpp"

extern SaveData MAIN_BSS_020B26A0;
extern u16 DAT_0208c55c[];

extern "C" {
u8 *NameTables_GetPokemonName(NameTables *obj, u32 i);
void CopyStringUpper(const u8 *src, u8 *dst, int len);
}

static inline u32 GetPokemonState(SaveData *save, int i)
{
    if (i >= 0 && i < 500) {
        return (save->m_pokemonStates[i >> 4] >> ((i & 0xF) * 2)) & 3;
    }
    return 0;
}

struct BrowserCategory {
    int *list;
    int count;
    int msg;
    u8 unk_0C;
};

static int sList_02122C10[] = { 0, 1, 2, 3, 4 };
static int sList_02122C24[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };
static int sList_02122C48[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 };
static int sList_02122CE0[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 24, 0 };
static BrowserCategory sCategories[] = {
    { sList_02122C24, 9, 7, 0x14 },
    { sList_02122C48, 18, 5, 0x16 },
    { sList_02122CE0, 24, 6, 0x18 },
    { sList_02122C10, 0, 4, 0 },
    { NULL, 0, 0, 0 },
};

void BrowserSprite::Init(OamSpriteSet *anim, u8 no, int x, int y, int priority)
{
    unk_04 = anim;
    unk_09 = no;
    unk_0C = x;
    unk_10 = y;
    unk_00 = anim->AddSprite(no, x, y, priority);
    unk_08 = anim->unk_24;
}

void BrowserButton::Init(BrowserSprite *sprite, s16 width, s16 height, s16 offsetX, s16 offsetY, u8 type)
{
    unk_00 = sprite;
    unk_05 = sprite->unk_09;
    unk_06 = unk_05 + 1;
    unk_04 = 0;
    sprite->unk_00->SetTouchRect(width, height, offsetX, offsetY);
    unk_08 = type;
}

BOOL BrowserButton::IsTouched()
{
    return unk_00->unk_00->GetTouchTrigger();
}

int BrowserButton::IsPressed()
{
    return unk_0C;
}

void BrowserButton::Press(u8 timer)
{
    unk_00->SetAnim(unk_06);
    unk_04 = timer;
}

void BrowserButton::Update()
{
    unk_0C = 0;
    if (!unk_00->unk_00->unk_14) {
        unk_00->SetAnim(unk_05);
        unk_04 = 0;
        return;
    }
    if (unk_00->unk_00->GetTouchTrigger()) {
        unk_09 = 24;
        unk_0C = 1;
    } else if (unk_00->unk_00->GetTouchHold()) {
        if (--unk_09 == 0) {
            unk_09 = 4;
            unk_0C = 1;
        }
    }
    switch (unk_08) {
    case 0:
        if (unk_04 != 0) {
            if (--unk_04 == 0) {
                unk_00->SetAnim(unk_05);
            }
            return;
        }
        if (unk_10 == 0) {
            unk_00->SetAnim(unk_06);
        } else {
            unk_00->SetAnim(unk_05);
        }
        break;
    case 1:
        if (unk_04 != 0) {
            unk_04--;
            return;
        }
        if (*(u32 *)CGame::GetInstance() & 8) {
            unk_00->SetAnim(unk_06);
        } else {
            unk_00->SetAnim(unk_05);
        }
        break;
    case 2:
        if (unk_04 != 0) {
            if (--unk_04 == 0) {
                unk_00->SetAnim(unk_05);
            } else if (unk_04 == 24) {
                unk_00->SetAnim(unk_07);
            }
        } else if (unk_10 == 0) {
            unk_00->SetAnim(unk_06);
        } else {
            unk_00->SetAnim(unk_05);
        }
        break;
    }
}

static inline void *GetWork()
{
    return CGame::GetInstance()->m_nameTables;
}

BrowserScreen::BrowserScreen(CGame *game)
{
    unk_000 = game;
    unk_020 = unk_000->unk_1494;
    unk_010 = NULL;
    unk_024 = NULL;
    unk_028 = NULL;
    Init();
}

static inline void FreeMessageBank(MessageBank *&bank)
{
    if (bank != NULL) {
        for (u32 i = 0; i < bank->count; i++) {
            if (bank->entries[i].data != NULL) {
                delete[] bank->entries[i].data;
                bank->entries[i].data = NULL;
            }
        }
        if (bank->entries != NULL) {
            delete[] bank->entries;
            bank->entries = NULL;
        }
        if (bank != NULL) {
            delete bank;
            bank = NULL;
        }
    }
}

BrowserScreen::~BrowserScreen()
{
    G2_SetWnd0InsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, TRUE);
    G2_SetWnd1InsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, TRUE);
    G2_SetWndOutsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, TRUE);
    G2_SetBG0Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
    GX_SetVisibleWnd(GX_WNDMASK_NONE);
    reg_G2_BLDCNT = 0;
    FreeMessageBank(unk_250);
    FreeMessageBank(unk_254);
    FreeMessageBank(unk_258);
    FreeMessageBank(unk_25C);
    SAFE_DELETE(unk_010);
    SAFE_DELETE(unk_014);
    SAFE_DELETE(unk_018);
    SAFE_DELETE(unk_01C);
    SAFE_DELETE(unk_080);
    for (int i = 0; i < 3; i++) {
        SAFE_DELETE(unk_084[i]);
    }
    SAFE_DELETE(unk_004);
    SAFE_DELETE(unk_008);
    SAFE_DELETE(unk_00C);
    SAFE_DELETE(unk_010);
    SAFE_DELETE(unk_024);
    SAFE_DELETE(unk_028);
}

void BrowserScreen::Init()
{
    OVERLAY21_BSS_021242C4 = 0;
    unk_030 = 0;
    unk_034 = 0;
    unk_06C = 0;
    unk_070 = 0;
    unk_03C = 0;
    unk_040 = 3;
    unk_064 = 0;
    unk_074 = 0;
    unk_078.x = 0;
    unk_078.y = 0;
    InitSubScreen();
    InitText();
    InitGraphics();
    InitButtons();
    InitMenus();
    unk_00C = new SubScreenButton();
    unk_00C->Load(0x3C0, 0, 0xF, 0xF0, 0x10);
}

void BrowserScreen::InitSubScreen()
{
    unk_068 = 0;
    G2S_SetBG0Offset(0, 0);
    G2S_SetBG1Offset(0, 0);
    G2S_SetBG2Offset(0, 0);
    G2S_SetBG3Offset(0, 0);
    unk_008 = new BrowserSubScreen(unk_000);
    unk_008->Load();
    unk_004 = new SubScreenPokemonInfo();
    unk_004->Release();
    unk_004->Load(unk_06C, 0, 0);
}

void BrowserScreen::LoadTextboxFrame()
{
    BGLayer *bg = new BGLayer();
    bg->SetBG(1);
    bg->LoadArchive("interface/", "i059_");
    u8 *chr = (u8 *)bg->LoadChar("i059_00", 0, 0, 0);
    u8 *pltt = (u8 *)bg->LoadPltt("i059_00", 0, 0, 0);
    u8 *scr = (u8 *)bg->LoadScr("i059_00", 0, 0, 0, 0, 0);
    bg->ReleaseArchive();
    bg->LoadCharToVram();
    int n = GlobalValues_Get((GlobalValues *)unk_000->unk_14B4, 1);
    pltt += n << 5;
    DC_FlushRange(pltt, 0x20);
    GX_LoadBGPltt(pltt, 0xC0, 0x20);
    chr += (n + 1) << 8;
    DC_FlushRange(chr, 0x100);
    GX_LoadBG1Char(chr, 0, 0x100);
    MI_CpuCopyFast(scr + 0x600, (u8 *)G2_GetBG1ScrPtr() + 0x500, 0xC0);
    MI_CpuCopyFast(scr + 0x740, (u8 *)G2_GetBG1ScrPtr() + 0x5C0, 0x40);
    delete bg;
}

MessageBank *BrowserScreen::LoadMessageBank(const char *path)
{
    MessageBank *bank = new MessageBank;
    int pos;
    u32 i;
    CBinaryFileMes *file = new CBinaryFileMes(path, 1);
    pos = 2;
    bank->unk_00 = ((u32 *)file->unk_4C)[0];
    bank->count = ((u32 *)file->unk_4C)[1];
    bank->entries = new MessageBank::Entry[bank->count];
    for (i = 0; i < bank->count; i++) {
        bank->entries[i].size = ((u32 *)file->unk_4C)[pos];
        pos++;
        bank->entries[i].data = new u8[bank->entries[i].size];
        MI_CpuCopyFast(&((u32 *)file->unk_4C)[pos], bank->entries[i].data, bank->entries[i].size);
        pos += bank->entries[i].size >> 2;
    }
    delete file;
    return bank;
}

void BrowserScreen::InitText()
{
    unk_250 = LoadMessageBank("data/message/etc/menu_mes");
    unk_254 = LoadMessageBank("data/message/etc/pokebook_info");
    unk_258 = LoadMessageBank("data/message/etc/assist_mes");
    unk_25C = LoadMessageBank("data/message/etc/fieldwaza_name");

    unk_020->FreeWindows();
    unk_020->SetupBG(0, GX_BG_SCRBASE_0xf000, GX_BG_CHARBASE_0x10000);
    unk_020->AllocWindows(16);
    int charNo = 4;
    for (int i = 0; i < 16; i++) {
        unk_020->InitWindow(i, 0x12, 2, 6, i * 2, charNo, 0, 2);
        charNo += 0x24;
    }
    G2_SetBG0Control(GX_BG_SCRSIZE_TEXT_512x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0xf000, GX_BG_CHARBASE_0x10000, GX_BG_EXTPLTT_01);

    unk_024 = new TextPrinter(&CGame::GetInstance()->unk_14AC->unk_14, GetWork());
    unk_024->SetupBG(1, GX_BG_SCRBASE_0x3000, GX_BG_CHARBASE_0x00000);
    MI_CpuClearFast((u8 *)G2_GetBG0ScrPtr() + 0x800, 0x800);
    unk_028 = new TextPrinter(&CGame::GetInstance()->unk_14AC->unk_0C, GetWork());
    unk_028->SetupBG(1, GX_BG_SCRBASE_0x3000, GX_BG_CHARBASE_0x00000);
    G2_SetBG1Control(GX_BG_SCRSIZE_TEXT_512x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x3000, GX_BG_CHARBASE_0x00000, GX_BG_EXTPLTT_01);
    MI_CpuClearFast((u8 *)G2_GetBG1ScrPtr() + 0x800, 0x800);
    LoadTextboxFrame();

    unk_024->AllocWindows(6);
    unk_024->InitWindow(0, 0xB, 0xA, 0x10, 0x22, 0x20, 0, 2);
    unk_024->InitWindow(4, 0xB, 2, 4, 2, 0x8E, 0, 2);
    unk_024->InitWindow(1, 8, 2, 0x11, 2, 0xA4, 0, 2);
    unk_024->InitWindow(2, 8, 2, 4, 0x22, 0xB4, 0, 2);
    unk_024->InitWindow(3, 9, 2, 5, 0x12, 0xC4, 0, 2);
    unk_024->InitWindow(5, 0xE, 2, 9, 0x2F, 0xD6, 0, 2);
    unk_028->AllocWindows(1);
    unk_028->InitWindow(0, 0x1C, 2, 2, 0x15, 0xF2, 0, 2);
    NNS_G2dMapScrToCharText(G2_GetBG1ScrPtr(), 0x1C, 2, 2, 0x15, NNS_G2D_TEXT_BG_WIDTH_256, 0xF2, 0xF);

    unk_024->Print(0, 4, 3, 5, unk_254->entries[sCategories[0].msg].data, TRUE, 0);
    unk_024->Print(0, 4, 0x17, 5, unk_254->entries[sCategories[1].msg].data, TRUE, 0);
    unk_024->Print(0, 4, 0x2B, 5, unk_254->entries[sCategories[2].msg].data, TRUE, 0);
    unk_024->Print(0, 4, 0x3F, 5, unk_254->entries[sCategories[3].msg].data, TRUE, 0);
    unk_024->Print(4, 4, 3, 5, unk_254->entries[sCategories[unk_040].msg].data, TRUE, 0);
    unk_024->Print(1, 0, 2, 5, unk_254->entries[2].data, TRUE, 0);
    unk_024->Print(2, 0, 2, 5, unk_254->entries[2].data, TRUE, 0);
    unk_024->Print(3, 4, 3, 5, unk_254->entries[21].data, TRUE, 0);
}

void BrowserScreen::InitGraphics()
{
    GX_SetVisiblePlane(GX_PLANEMASK_BG0 | GX_PLANEMASK_BG1 | GX_PLANEMASK_BG2 | GX_PLANEMASK_BG3 | GX_PLANEMASK_OBJ);
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    G2_SetBG0Offset(0, 0);
    G2_SetBG1Offset(0, 0);
    G2_SetBG2Offset(0, 0);
    G2_SetBG3Offset(0, 0);
    G2_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_512x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0xe000, GX_BG_CHARBASE_0x04000);
    G2_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_512x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0xd000, GX_BG_CHARBASE_0x04000);
    G2_SetBG1Priority(0);
    G2_SetBG0Priority(1);
    G2_SetBG2Priority(2);
    G2_SetBG3Priority(3);
    BGS_LoadCharAndPltt("menu/", "mb000_bg_", 2, "mb000", 0x80, "mb000", 0);
    BGS_LoadScr("menu/", "mb000_bg_", 2, "mb000_03", 0, 0x80, 0, 0);
    BGS_LoadScr("menu/", "mb000_bg_", 3, "mb000_02", 0, 0x80, 0, 0);
    MI_CpuCopyFast((u8 *)G2_GetBG3ScrPtr() + 0xB80, (u8 *)G2_GetBG3ScrPtr() + 0xE00, 0x180);
    MI_CpuCopyFast((u8 *)G2_GetBG3ScrPtr() + 0x480, (u8 *)G2_GetBG3ScrPtr() + 0xB80, 0x180);

    u8 oamIndex = 2;
    unk_080 = new OamSpriteSet((GXOamAttr *)&unk_000->unk_0024[oamIndex], unk_000->unk_14A8, FALSE, 0x40);
    oamIndex += 100;
    unk_084[0] = new OamSpriteSet((GXOamAttr *)&unk_000->unk_0024[oamIndex], unk_000->unk_14A8, FALSE, 0x40);
    unk_084[1] = new OamSpriteSet((GXOamAttr *)&unk_000->unk_0024[oamIndex], unk_000->unk_14A8, FALSE, 0x40);
    unk_084[2] = new OamSpriteSet((GXOamAttr *)&unk_000->unk_0024[oamIndex], unk_000->unk_14A8, FALSE, 0x40);
    int charSize = 0;
    charSize += unk_080->Load("data/menu", "mb000_00", (charSize / 32 + 3) & 0x3FF, 0);
    charSize += unk_084[0]->Load("data/menu", "mb000_01", (charSize / 32 + 3) & 0x3FF, 6);
    charSize += unk_084[1]->Load("data/menu", "ma000_01", (charSize / 32 + 3) & 0x3FF, 7);
    charSize += unk_084[2]->Load("data/menu", "mb000_02", (charSize / 32 + 3) & 0x3FF, 0xB);

    unk_094[2].Init(unk_080, 0, 0xE0, 0x2D, 2);
    unk_094[3].Init(unk_080, 2, 0xE0, 0x84, 2);
    unk_094[0].Init(unk_080, 4, 0xE0, 0x4C, 2);
    unk_094[1].Init(unk_080, 6, 0xE0, 0x64, 2);
    unk_094[4].Init(unk_080, 8, 0xB0, 0x10, 2);
    unk_094[6].Init(unk_080, 0xB, 0x54, 0x91, 2);
    unk_094[5].Init(unk_080, 9, 0x148, 0x10, 2);
    unk_094[9].Init(unk_080, 0x1A, 0x108, 0x88, 2);
    unk_094[10].Init(unk_080, 0x1C, 0x1F8, 0x88, 2);
    unk_094[7].Init(unk_080, 0x12, 0x80, 0x60, 2);
    unk_094[8].Init(unk_080, 0x14, 0x180, 0x60, 2);
}

void BrowserScreen::InitButtons()
{
    unk_170[2].Init(&unk_094[2], 0x18, 0x18, 0, 0, 0);
    unk_170[3].Init(&unk_094[3], 0x18, 0x18, 0, 0, 0);
    unk_170[0].Init(&unk_094[0], 0x12, 0x12, 0, 0, 0);
    unk_170[1].Init(&unk_094[1], 0x12, 0x12, 0, 0, 0);
    unk_170[4].Init(&unk_094[4], 0x48, 0x10, -4, 8, 2);
    unk_170[4].unk_05 = 8;
    unk_170[4].unk_06 = 10;
    unk_170[4].unk_07 = 9;
    unk_170[4].unk_00->SetAnim(8);
    unk_170[6].Init(&unk_094[6], 0x48, 0x10, -4, 8, 0);
    unk_170[5].Init(&unk_094[5], 0x48, 0x10, -4, 8, 0);
    unk_170[9].Init(&unk_094[9], 0x10, 0x10, 0, 0, 0);
    unk_170[10].Init(&unk_094[10], 0x10, 0x10, 0, 0, 0);
    unk_170[7].Init(&unk_094[7], 0, 0, 0, 0, 0);
    unk_170[8].Init(&unk_094[8], 0, 0, 0, 0, 0);
}

void BrowserScreen::InitMenus()
{
    unk_010 = new BrowserEntryList();
    unk_014 = new CBrowserMenuManagerPokemon();
    unk_014->Init(unk_080, this);
    CBrowserMenuManagerType *types = new CBrowserMenuManagerType();
    unk_018 = types;
    types->Init(unk_080);
    types->SetList(sList_02122C10, 4, unk_040);
    unk_01C = new CBrowserMenuManagerIcon();
    unk_01C->Init(unk_084, unk_080, this);
    SetCategory(unk_040);
    ApplyFilter(unk_040, unk_03C, 0);
    PrintHelp(0x12);
}

void BrowserScreen::UpdateTouch()
{
    if (unk_030 == 0) {
        if (unk_014->UpdateTouch()) {
            if (unk_06C != GetEntryId(unk_014->unk_10)) {
                unk_000->m_audioEngine->PlaySe(0xFA);
            }
            return;
        }
        if (unk_170[2].IsPressed()) {
            if (unk_014->PagePrev()) {
                unk_170[2].Press(4);
                unk_000->m_audioEngine->PlaySe(0x108);
                RefreshRows(1);
            } else if (!unk_014->CanScrollPrev()) {
                unk_000->m_audioEngine->PlaySe(0xFD);
            }
            return;
        }
        if (unk_170[3].IsPressed()) {
            if (unk_014->PageNext()) {
                unk_170[3].Press(4);
                unk_000->m_audioEngine->PlaySe(0x108);
                RefreshRows(1);
            } else if (!unk_014->CanScrollNext()) {
                unk_000->m_audioEngine->PlaySe(0xFD);
            }
            return;
        }
        if (unk_170[0].IsPressed()) {
            if (unk_014->SelectPrev()) {
                unk_170[0].Press(4);
                unk_000->m_audioEngine->PlaySe(0x108);
                RefreshRows(0);
            } else if (!unk_014->CanSelectPrev()) {
                unk_000->m_audioEngine->PlaySe(0xFD);
            }
            return;
        }
        if (unk_170[1].IsPressed()) {
            if (unk_014->SelectNext()) {
                unk_170[1].Press(4);
                unk_000->m_audioEngine->PlaySe(0x108);
                RefreshRows(0);
            } else if (!unk_014->CanSelectNext()) {
                unk_000->m_audioEngine->PlaySe(0xFD);
            }
            return;
        }
        if (unk_170[4].IsTouched()) {
            if (unk_014->unk_18 == 0) {
                SwitchPage(1, 0);
            }
            return;
        }
        if (unk_170[6].IsTouched()) {
            unk_170[6].Press(8);
            unk_170[7].Press(8);
            unk_000->m_audioEngine->PlaySe(0xFA);
            unk_000->m_subFade->Start(4, 10);
            unk_034 = 2;
        }
    } else if (unk_030 == 1) {
        if (unk_018->UpdateTouch()) {
            if (unk_040 != unk_018->GetSelectedValue()) {
                SetCategory(unk_018->GetSelectedValue());
                unk_000->m_audioEngine->PlaySe(0xFA);
            }
        }
        if (unk_01C->UpdateTouch()) {
            if (unk_03C == unk_01C->GetSelectedValue()) {
                return;
            }
            ApplyFilter(unk_040, unk_01C->GetSelectedValue(), 0);
            SelectValue(unk_01C->GetSelectedValue());
            unk_000->m_audioEngine->PlaySe(0xFA);
            return;
        }
        if (unk_170[9].IsPressed()) {
            unk_170[9].Press(4);
            if (!unk_01C->SelectPrev()) {
                return;
            }
            ApplyFilter(unk_040, unk_01C->GetSelectedValue(), 0);
            SelectValue(unk_01C->GetSelectedValue());
            unk_000->m_audioEngine->PlaySe(0x108);
            return;
        }
        if (unk_170[10].IsPressed()) {
            unk_170[10].Press(4);
            if (!unk_01C->SelectNext()) {
                return;
            }
            ApplyFilter(unk_040, unk_01C->GetSelectedValue(), 0);
            SelectValue(unk_01C->GetSelectedValue());
            unk_000->m_audioEngine->PlaySe(0x108);
            return;
        }
        if (unk_170[5].IsTouched()) {
            SwitchPage(0, 0);
        }
    }
}

void BrowserScreen::UpdateKeys()
{
    PadInput *pad = unk_000->unk_0014;
    if (unk_030 == 0) {
        if ((u16)(pad->unk_0006 & PAD_KEY_UP)) {
            if (unk_014->SelectPrev()) {
                unk_170[0].Press(4);
                unk_000->m_audioEngine->PlaySe(0x108);
                RefreshRows(0);
            } else if (!unk_014->CanSelectPrev()) {
                unk_000->m_audioEngine->PlaySe(0xFD);
            }
            return;
        }
        if ((u16)(pad->unk_0006 & PAD_KEY_DOWN)) {
            if (unk_014->SelectNext()) {
                unk_170[1].Press(4);
                unk_000->m_audioEngine->PlaySe(0x108);
                RefreshRows(0);
            } else if (!unk_014->CanSelectNext()) {
                unk_000->m_audioEngine->PlaySe(0xFD);
            }
            return;
        }
        if ((u16)(pad->unk_0006 & PAD_KEY_LEFT)) {
            if (unk_014->PagePrev()) {
                unk_170[2].Press(4);
                unk_000->m_audioEngine->PlaySe(0x108);
                RefreshRows(1);
            } else if (!unk_014->CanScrollPrev()) {
                unk_000->m_audioEngine->PlaySe(0xFD);
            }
            return;
        }
        if ((u16)(pad->unk_0006 & PAD_KEY_RIGHT)) {
            if (unk_014->PageNext()) {
                unk_170[3].Press(4);
                unk_000->m_audioEngine->PlaySe(0x108);
                RefreshRows(1);
            } else if (!unk_014->CanScrollNext()) {
                unk_000->m_audioEngine->PlaySe(0xFD);
            }
            return;
        }
        if ((u16)(pad->unk_0002 & PAD_BUTTON_L)) {
            unk_170[6].Press(8);
            unk_170[7].Press(8);
            unk_000->m_audioEngine->PlaySe(0xFA);
            unk_000->m_subFade->Start(4, 10);
            unk_034 = 2;
            return;
        }
        if ((u16)(pad->unk_0002 & PAD_BUTTON_R)) {
            if (unk_014->unk_18 == 0) {
                SwitchPage(1, 0);
            }
        }
    } else {
        if ((u16)(pad->unk_0006 & PAD_KEY_UP)) {
            if (unk_018->SelectPrev()) {
                unk_000->m_audioEngine->PlaySe(0xFA);
                SetCategory(unk_018->GetSelectedValue());
            }
            return;
        }
        if ((u16)(pad->unk_0006 & PAD_KEY_DOWN)) {
            if (unk_018->SelectNext()) {
                unk_000->m_audioEngine->PlaySe(0xFA);
                SetCategory(unk_018->GetSelectedValue());
            }
            return;
        }
        if ((u16)(pad->unk_0006 & PAD_KEY_LEFT)) {
            if (unk_040 == 3) {
                return;
            }
            if (!unk_01C->SelectPrev()) {
                return;
            }
            unk_170[9].Press(4);
            unk_000->m_audioEngine->PlaySe(0x108);
            ApplyFilter(unk_040, unk_01C->GetSelectedValue(), 0);
            SelectValue(unk_01C->GetSelectedValue());
            return;
        }
        if ((u16)(pad->unk_0006 & PAD_KEY_RIGHT)) {
            if (unk_040 == 3) {
                return;
            }
            if (!unk_01C->SelectNext()) {
                return;
            }
            unk_170[10].Press(4);
            unk_000->m_audioEngine->PlaySe(0x108);
            ApplyFilter(unk_040, unk_01C->GetSelectedValue(), 0);
            SelectValue(unk_01C->GetSelectedValue());
            return;
        }
        if ((u16)(pad->unk_0002 & PAD_BUTTON_A)) {
            SwitchPage(0, 0);
        }
    }
}

void BrowserScreen::UpdateButtons()
{
    unk_170[0].unk_10 = unk_014->CanSelectPrev() ? TRUE : FALSE;
    unk_170[1].unk_10 = unk_014->CanSelectNext() ? TRUE : FALSE;
    unk_170[2].unk_10 = unk_014->CanScrollPrev() ? TRUE : FALSE;
    unk_170[3].unk_10 = unk_014->CanScrollNext() ? TRUE : FALSE;
    for (int i = 0; i < 11; i++) {
        unk_170[i].Update();
    }
}

void BrowserScreen::SetSlideX(int x)
{
    unk_094[0].unk_00->SetPos(unk_094[0].unk_0C + x, unk_094[0].unk_10);
    unk_094[1].unk_00->SetPos(unk_094[1].unk_0C + x, unk_094[1].unk_10);
    unk_094[2].unk_00->SetPos(unk_094[2].unk_0C + x, unk_094[2].unk_10);
    unk_094[3].unk_00->SetPos(unk_094[3].unk_0C + x, unk_094[3].unk_10);
    unk_094[4].unk_00->SetPos(unk_094[4].unk_0C + x, unk_094[4].unk_10);
    unk_094[5].unk_00->SetPos(unk_094[5].unk_0C + x, unk_094[5].unk_10);
    unk_094[6].unk_00->SetPos(unk_094[6].unk_0C + x, unk_094[6].unk_10);
    unk_094[7].unk_00->SetPos(unk_094[7].unk_0C + x, unk_094[7].unk_10);
    unk_094[8].unk_00->SetPos(unk_094[8].unk_0C + x, unk_094[8].unk_10);
    unk_094[9].unk_00->SetPos(unk_094[9].unk_0C + x, unk_094[9].unk_10);
    unk_094[10].unk_00->SetPos(unk_094[10].unk_0C + x, unk_094[10].unk_10);
    unk_014->SetPos(x + 0x70, 0x30);
    unk_018->SetPos(x + 0x1B0, 0x10);
    unk_01C->SetPos(x + 0x120, 0x94);
}

void BrowserScreen::ApplyFilter(u32 mode, int arg, BOOL keep)
{
    unk_010->Filter(mode, arg);
    int count = unk_010->unk_80C;
    unk_014->SetList(unk_010->unk_808, count, 0);
    RefreshRows(2);
    if (keep) {
        return;
    }
    if (count == 0) {
        unk_170[5].unk_08 = 0;
        PrintHelp(0x13);
    } else {
        unk_170[5].unk_08 = 1;
        unk_170[5].unk_05 = 9;
        unk_170[5].unk_06 = 10;
        unk_170[5].unk_07 = 11;
        unk_170[5].unk_00->SetAnim(9);
        PrintHelp(0x17);
    }
}

BOOL BrowserScreen::SwitchPage(int mode, BOOL arg1)
{
    if (mode == unk_030) {
        return FALSE;
    }
    if (mode == 1) {
        unk_170[4].Press(0x20);
        unk_000->m_audioEngine->PlaySe(0xFA);
        unk_034 = 1;
        unk_030 = 1;
        unk_00C->unk_20 = 0;
        unk_044 = unk_03C;
        unk_048 = unk_040;
        unk_04C = unk_014->unk_14;
        unk_058 = unk_014->unk_0C;
        unk_050 = unk_01C->unk_14;
        unk_05C = unk_01C->unk_0C;
        unk_054 = unk_018->unk_14;
        unk_060 = unk_018->unk_0C;
        unk_170[5].unk_08 = 0;
        unk_018->Select(-1);
        SetCategory(4);
    } else if (unk_010->unk_80C != 0 && (arg1 != FALSE || unk_040 != 4)) {
        if (arg1 == FALSE) {
            unk_170[5].Press(0x18);
        }
        unk_000->m_audioEngine->PlaySe(0xFA);
        unk_034 = 1;
        unk_030 = 0;
        unk_00C->unk_20 = 0;
    } else {
        return FALSE;
    }
    return TRUE;
}

void BrowserScreen::SetCategory(int category)
{
    unk_040 = category;
    if (category == 4) {
        unk_094[8].unk_00->unk_14 = FALSE;
        unk_01C->unk_1C = FALSE;
        unk_01C->unk_20 = unk_040;
        unk_01C->SetList(sCategories[unk_040].list, sCategories[unk_040].count, 0);
        SelectValue(0);
        return;
    }
    unk_01C->unk_1C = TRUE;
    unk_01C->unk_20 = unk_040;
    unk_01C->SetList(sCategories[unk_040].list, sCategories[unk_040].count, 0);
    unk_024->ClearWindow(4);
    unk_024->Print(4, 4, 3, 5, unk_254->entries[sCategories[unk_040].msg].data, TRUE, 0);
    if (category >= 3) {
        unk_094[8].unk_00->unk_14 = FALSE;
    } else {
        unk_094[8].unk_00->unk_14 = TRUE;
        u8 no = sCategories[unk_040].unk_0C;
        unk_170[8].unk_05 = no;
        unk_170[8].unk_06 = no + 1;
        unk_170[8].unk_07 = no + 2;
        unk_170[8].unk_00->SetAnim(no);
        unk_170[8].Press(8);
    }
    ApplyFilter(unk_040, unk_01C->GetSelectedValue(), 0);
    SelectValue(unk_01C->GetSelectedValue());
}

void BrowserScreen::SelectValue(int value)
{
    unk_03C = value;
    u8 *str = NULL;
    switch (unk_040) {
    case 0:
        str = unk_254->entries[unk_03C + 9].data;
        break;
    case 1:
        if (unk_010->unk_814[value] != 0) {
            str = unk_258->entries[unk_03C + 1].data;
        } else {
            str = unk_254->entries[22].data;
        }
        break;
    case 2:
        if (unk_010->unk_85C[value] != 0) {
            str = unk_25C->entries[unk_03C].data;
            break;
        }
        str = unk_254->entries[22].data;
        break;
    case 3:
    case 4:
        break;
    }
    unk_024->ClearWindow(5);
    if (str != NULL) {
        unk_024->Print(5, 4, 3, 3, str, TRUE, 0);
    }
    unk_094[9].unk_00->unk_14 = FALSE;
    unk_094[10].unk_00->unk_14 = FALSE;
    switch (unk_040) {
    case 0:
        break;
    case 1:
        if (unk_01C->CanScrollPrev()) {
            unk_094[9].unk_00->unk_14 = TRUE;
        }
        if (unk_01C->CanScrollNext()) {
            unk_094[10].unk_00->unk_14 = TRUE;
        }
        break;
    case 2:
        if (unk_01C->CanScrollPrev()) {
            unk_094[9].unk_00->unk_14 = TRUE;
        }
        if (unk_01C->CanScrollNext()) {
            unk_094[10].unk_00->unk_14 = TRUE;
        }
        break;
    case 3:
    case 4:
        break;
    }
}

void BrowserScreen::ToggleAreaView()
{
    if (unk_068 == 0) {
        unk_024->ClearWindow(3);
        unk_024->Print(3, 4, 3, 5, unk_254->entries[20].data, TRUE, 0);
        unk_068 = 1;
        unk_008->Load();
        RefreshSubScreen(TRUE);
    } else {
        unk_024->ClearWindow(3);
        unk_024->Print(3, 4, 3, 5, unk_254->entries[21].data, TRUE, 0);
        unk_068 = 0;
        unk_004->Release();
        unk_004->Load(0, 0, 0);
        RefreshSubScreen(TRUE);
    }
}

void BrowserScreen::RefreshSubScreen(BOOL arg0)
{
    BrowserEntry unknown = { 0, 0, 0 };
    u16 no = PokeIdTable_Get(unk_000->unk_1434, unk_06C)->unk_00;
    SaveData *save = &MAIN_BSS_020B26A0;
    u32 state = GetPokemonState(save, no);
    if (unk_068 == 0) {
        unk_004->SetPokemon(unk_06C, OVERLAY21_BSS_021242C4 != 0 ? 0 : 2 - state);
        unk_004->StartRefresh();
        return;
    }
    const BrowserEntry *entry = &OVERLAY21_DATA_02123618[unk_014->GetSelectedValue()];
    if (state == 0) {
        entry = &unknown;
    }
    if (arg0) {
        unk_008->ShowEntry(entry);
    } else {
        unk_008->SetEntry(entry);
    }
}

void BrowserScreen::PrintRow(int row, int id, int no)
{
    unk_020->ClearWindow(row);
    if (id == -1) {
        return;
    }
    PokeIdTableEntry *rec = PokeIdTable_Get(unk_000->unk_1434, id);
    u16 species = rec->unk_00;
    SaveData *save = &MAIN_BSS_020B26A0;
    if (no < 1000) {
        unk_020->Print(row, 4, 3, 3, unk_250->entries[7].data, FALSE, 0);
        unk_020->Print(row, 0x17, 3, 3, unk_250->entries[no / 100 + 8].data, FALSE, 0);
        unk_020->Print(row, 0x21, 3, 3, unk_250->entries[no / 10 % 10 + 8].data, FALSE, 0);
        unk_020->Print(row, 0x2B, 3, 3, unk_250->entries[no % 10 + 8].data, FALSE, 0);
    } else {
        unk_020->Print(row, 4, 3, 3, unk_250->entries[61].data, FALSE, 0);
    }
    if (OVERLAY21_BSS_021242C4 != 0 || GetPokemonState(save, species) != 0) {
        u8 name[32];
        CopyStringUpper(NameTables_GetPokemonName(unk_000->m_nameTables, rec->unk_00), name, 0x1F);
        unk_020->Print(row, 0x50, 3, 3, name, FALSE, 0);
    } else {
        unk_020->Print(row, 0x50, 3, 3, unk_250->entries[18].data, FALSE, 0);
    }
}

void BrowserScreen::RefreshRows(int mode)
{
    int scroll = unk_014->unk_14;
    if (mode != 0) {
        for (int i = 0; i < 16; i++) {
            PrintRow(i, -1, -1);
        }
    }
    if (mode == 0) {
        if (scroll != 0) {
            PrintRow((scroll - 1) & 0xF, GetEntryId(scroll - 1), GetDexNo(scroll - 1));
        }
        if (!unk_014->IsLastPage()) {
            int index = scroll + unk_014->GetVisibleCount();
            PrintRow(index & 0xF, GetEntryId(index), GetDexNo(index));
        }
    }
    switch (mode) {
    case 1:
        for (int i = 0; i < unk_014->GetVisibleCount(); i++) {
            int index = scroll + i;
            PrintRow(index & 0xF, GetEntryId(index), GetDexNo(index));
        }
        break;
    case 2:
        unk_074 = unk_014->GetVisibleCount();
        break;
    }
}

void BrowserScreen::PrintPendingRow()
{
    if (unk_074 == 0) {
        return;
    }
    unk_074--;
    int scroll = unk_014->unk_14;
    PrintRow((scroll + unk_074) & 0xF, GetEntryId(scroll + unk_074), GetDexNo(scroll + unk_074));
}

void BrowserScreen::PrintHelp(int msg)
{
    unk_028->FillWindow(0, 0x33333333);
    unk_028->Print(0, 4, 3, 4, unk_254->entries[msg].data, FALSE, 0);
}

u16 BrowserScreen::GetEntryId(int index)
{
    BrowserEntry *entry = &OVERLAY21_DATA_02123618[unk_014->unk_04[index]];
    return entry->id;
}

int BrowserScreen::GetDexNo(int index)
{
    u16 no = DAT_0208c55c[PokeIdTable_Get(unk_000->unk_1434, GetEntryId(index))->unk_00];
    if (no == 0xFFFF) {
        no = 999;
    }
    return no;
}

void BrowserScreen::Update()
{
    OSTick start = OS_GetTick();
    if (unk_00C != NULL && unk_034 == 0 && unk_00C->UpdateInput()) {
        if (unk_030 == 0) {
            unk_034 = 3;
        } else {
            ApplyFilter(unk_048, unk_044, TRUE);
            unk_064 = 1;
            unk_014->SetScroll(unk_04C);
            unk_014->Select(unk_058);
            unk_024->ClearWindow(4);
            unk_024->Print(4, 4, 3, 5, unk_254->entries[sCategories[unk_048].msg].data, TRUE, 0);
            SwitchPage(0, TRUE);
        }
    }
    UpdateButtons();
    if (unk_034 == 0) {
        UpdateKeys();
        if (unk_034 == 0) {
            UpdateTouch();
        }
        if (unk_06C != GetEntryId(unk_014->unk_10)) {
            unk_06C = GetEntryId(unk_014->unk_10);
            unk_070 = 1;
        }
    }
    if (unk_014 != NULL) {
        unk_014->Update();
    }
    if (unk_018 != NULL) {
        unk_018->Update();
    }
    if (unk_01C != NULL) {
        unk_01C->Update();
    }
    if (unk_034 == 1) {
        if (unk_030 == 1) {
            unk_078.x += 0x8000;
            if (unk_078.x >= 0x100000) {
                unk_078.x = 0x100000;
                unk_034 = 0;
                unk_00C->unk_20 = TRUE;
                PrintHelp(0x17);
            }
        } else {
            unk_078.x -= 0x8000;
            if (unk_078.x <= 0) {
                unk_078.x = 0;
                unk_034 = 0;
                unk_00C->unk_20 = TRUE;
                if (unk_064 != 0) {
                    unk_040 = unk_048;
                    unk_03C = unk_044;
                    unk_064 = 0;
                }
                PrintHelp(0x12);
            }
        }
    }
    if (unk_034 == 2) {
        if (!unk_000->m_subFade->IsActive()) {
            ToggleAreaView();
            unk_034 = 0;
            unk_000->m_subFade->Start(3, 10);
        }
    }
    SetSlideX(-unk_078.x >> 12);
    if (unk_080 != NULL) {
        unk_080->Update();
    }
    if (unk_040 < 3 && unk_084[unk_040] != NULL) {
        unk_084[unk_040]->Update();
    }
    if (unk_068 == 0) {
        if (unk_004 != NULL) {
            unk_004->Update();
        }
    } else if (unk_008 != NULL) {
        unk_008->Update();
    }
    if (OS_TicksToMicroSeconds(OS_GetTick() - start) <= 5000) {
        PrintPendingRow();
    }
    OS_GetTick();
}

void BrowserScreen::Draw()
{
    if (unk_00C != NULL) {
        unk_00C->Render();
    }
    if (unk_080 != NULL) {
        unk_080->WriteOam();
    }
    if (unk_040 < 3 && unk_084[unk_040] != NULL) {
        unk_084[unk_040]->WriteOam();
    }
    if (unk_014 != NULL) {
        unk_014->Draw();
    }
    if (unk_018 != NULL) {
        unk_018->Draw();
    }
    if (unk_01C != NULL) {
        unk_01C->Draw();
    }
    if (unk_068 == 0) {
        if (unk_004 != NULL) {
            unk_004->Render();
        }
    } else if (unk_008 != NULL) {
        unk_008->Render();
    }
    if (unk_070 != 0) {
        if (--unk_070 == 0) {
            RefreshSubScreen(FALSE);
        }
    }
}

void BrowserScreen::ov21_02120490()
{
    if (unk_068 != 0 && unk_008 != NULL) {
        unk_008->ov21_02122144();
    }
}

// Marks the visible rows of caught Pokemon on BG2; also hands the save data pointer back to the caller.
static inline void UpdateRowMarks(BrowserScreen *w, SaveData *&save)
{
    CBrowserMenuManagerPokemon *list = w->unk_014;
    int scroll = list->unk_14;
    int i = list->unk_18 == 3 ? -1 : 0;
    int end;
    if (list->unk_18 == 4) {
        end = 8;
    } else {
        end = list->GetVisibleCount();
    }
    save = &MAIN_BSS_020B26A0;
    for (; i < end; i++) {
        u16 no = PokeIdTable_Get(w->unk_000->unk_1434, w->GetEntryId(i + scroll))->unk_00;
        if (GetPokemonState(save, no) == 2) {
            MI_CpuCopyFast((u8 *)G2_GetBG2ScrPtr() + 0x700, (u8 *)G2_GetBG2ScrPtr() + (i * 2 + 4) * 64, 0x80);
        } else {
            MI_CpuCopyFast((u8 *)G2_GetBG2ScrPtr() + 0x780, (u8 *)G2_GetBG2ScrPtr() + (i * 2 + 4) * 64, 0x80);
        }
    }
    for (; i < 8; i++) {
        MI_CpuClearFast((u8 *)G2_GetBG2ScrPtr() + (i * 2 + 4) * 64, 0x80);
    }
}

void BrowserScreen::ov21_021204B0()
{
    SaveData *save;

    G2_SetBG0Offset(unk_078.x >> 12, (unk_014->unk_14 * 16 + (unk_014->unk_88 >> 12) - 0x28) & 0xFF);
    G2_SetBG1Offset(unk_078.x >> 12, 0);
    G2_SetBG2Offset(unk_078.x >> 12, (unk_014->unk_88 >> 12) - 8);
    G2_SetBG3Offset(unk_078.x >> 12, 0);
    int wnd = GX_WNDMASK_NONE;
    G2_SetWndOutsidePlane(GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, FALSE);
    if ((unk_078.x >> 12) < 200) {
        G2_SetWnd0InsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, FALSE);
        wnd |= GX_WNDMASK_W0;
        int x = 0x20 - (unk_078.x >> 12);
        if (x < 0) {
            x = 0;
        }
        G2_SetWnd0Position(x, 0x28, 200 - (unk_078.x >> 12), 0x88);
    }
    GX_SetVisibleWnd(wnd);
    if (unk_040 >= 3) {
        MI_CpuCopyFast((u8 *)G2_GetBG3ScrPtr() + 0x480, (u8 *)G2_GetBG3ScrPtr() + 0xB80, 0x180);
    } else {
        MI_CpuCopyFast((u8 *)G2_GetBG3ScrPtr() + 0xE00, (u8 *)G2_GetBG3ScrPtr() + 0xB80, 0x180);
    }

    UpdateRowMarks(this, save);
}
