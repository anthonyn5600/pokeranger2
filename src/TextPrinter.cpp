#include "TextPrinter.hpp"

#include "SaveData.hpp"
#include "file/CNCLRFile.hpp"

extern "C" {
u8 *NameTables_GetPokemonName(void *, u32);

extern char s_data_font_prs_lc_jp_NCLR_0208aa0c;
extern char s_data_font_prs_jp_NCLR_0208aa28;
}

TextPrinter::TextPrinter(const NNSG2dFont *font, void *arg1)
{
    unk_04 = font;
    unk_0C = 0;
    unk_00 = arg1;
    unk_08 = NULL;
    unk_10 = 0;
}

TextPrinter::~TextPrinter()
{
    FreeWindows();
}

void TextPrinter::SetFont(const NNSG2dFont *font, u32 arg1)
{
    unk_0C = arg1;
    unk_04 = font;
    LoadPalette();
}

void TextPrinter::FreeWindows()
{
    if (unk_08 != NULL) {
        delete[] unk_08;
        unk_08 = NULL;
    }
}

void TextPrinter::SetupBG(int bg, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    unk_10 = bg;
    switch (bg) {
    case 0:
        G2_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, screenBase, charBase, GX_BG_EXTPLTT_01);
        GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG0);
        break;
    case 1:
        G2_SetBG1Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, screenBase, charBase, GX_BG_EXTPLTT_01);
        GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG1);
        break;
    case 2:
        G2_SetBG2ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, screenBase, charBase);
        GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG2);
        break;
    case 3:
        G2_SetBG3ControlText(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, screenBase, charBase);
        GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_BG3);
        break;
    }
    void *charPtr = GetCharPtr(unk_10);
    void *scrPtr = GetScrPtr(unk_10);
    LoadPalette();
    MI_CpuClearFast(charPtr, 0x20);
    MI_CpuClearFast(scrPtr, 0x800);
}

void TextPrinter::LoadPalette()
{
    if (unk_0C == 0) {
        CNCLRFile *nclrFile = new CNCLRFile(&s_data_font_prs_lc_jp_NCLR_0208aa0c, 1, 0, 0);
        DC_FlushRange(nclrFile->unk_B8->pRawData, 0x20);
        GX_LoadBGPltt(nclrFile->unk_B8->pRawData, 0x1C0, 0x20);
        delete nclrFile;
    } else {
        CNCLRFile *nclrFile = new CNCLRFile(&s_data_font_prs_jp_NCLR_0208aa28, 1, 0, 0);
        DC_FlushRange(nclrFile->unk_B8->pRawData, 0x20);
        GX_LoadBGPltt(nclrFile->unk_B8->pRawData, 0x1C0, 0x20);
        delete nclrFile;
    }
}

void TextPrinter::AllocWindows(int arg0)
{
    if (unk_08 == NULL) {
        unk_08 = new TextPrinterWindow[arg0];
    } else {
        OS_Terminate();
    }
}

void TextPrinter::InitWindow(int idx, int width, int height, int left, int top, int charNo, int hSpace, int vSpace)
{
    void *charPtr = GetCharPtr(unk_10);
    TextPrinterWindow *e = &unk_08[idx];
    e->unk_28 = width;
    e->unk_2C = height;
    NNS_G2dCharCanvasInitForBG(&unk_08[idx].unk_00, (u8 *)charPtr + charNo * 0x20, unk_08[idx].unk_28, unk_08[idx].unk_2C, NNS_G2D_CHARA_COLORMODE_16);
    NNS_G2dTextCanvasInit(&unk_08[idx].unk_18, &unk_08[idx].unk_00, unk_04, hSpace, vSpace);
    TextPrinterWindow *elem = &unk_08[idx];
    NNS_G2dMapScrToCharText(GetScrPtr(unk_10), elem->unk_28, elem->unk_2C, left, top, NNS_G2D_TEXT_BG_WIDTH_256, charNo, 0xE);
    ClearWindow(idx);
}

void TextPrinter::Print(int idx, int x, int y, int color, u8 *str, BOOL center, int offset)
{
    TextPrinterWindow *elem = &unk_08[idx];
    int hSpace = elem->unk_18.hSpace;
    const NNSG2dFont *font;
    int cx;
    int cy;
    NNSiG2dSplitCharCallback splitter;
    int lineHeight;
    if (center) {
        int width = elem->unk_28;
        x = ((width * 8) - NNS_G2dTextCanvasGetStringWidth(&elem->unk_18, (const NNSG2dChar *)str, NULL)) / 2 - offset;
    }
    font = elem->unk_18.pFont;
    cx = x;
    cy = y - 2;
    splitter = font->cbCharSpliter;
    lineHeight = elem->unk_18.vSpace + NNS_G2dFontGetLineFeed(font);
    while (TRUE) {
        u16 c = splitter((const void **)&str);
        if (c != 0) {
            if (c == '[') {
                switch (splitter((const void **)&str)) {
                case 'E':
                    str++;
                    cx = x;
                    cy += lineHeight;
                    break;
                case 'M':
                    unk_2C = ++str;
                    str = &MAIN_BSS_020B26A0.m_playerName;
                    unk_30 = 1;
                    break;
                case 'P': {
                    str++;
                    u32 v = unk_34[*str & 0xF];
                    str += 2;
                    unk_2C = str;
                    str = NameTables_GetPokemonName(unk_00, v);
                    unk_30 = 1;
                    break;
                }
                case 'K':
                    str += 3;
                    unk_2C = str;
                    str = (u8 *)unk_14;
                    unk_30 = 1;
                    break;
                }
            } else {
                cx += NNS_G2dCharCanvasDrawChar(elem->unk_18.pCanvas, font, cx, cy, color, c);
                cx += hSpace;
            }
        } else {
            if (unk_30 == 0) {
                return;
            }
            unk_30 = 0;
            str = unk_2C;
        }
    }
}

void TextPrinter::ClearWindow(int idx)
{
    TextPrinterWindow *e = &unk_08[idx];
    MI_CpuClearFast(e->unk_00.charBase, e->unk_28 * 0x20 * e->unk_2C);
}

void TextPrinter::FillWindow(int idx, u32 fill)
{
    TextPrinterWindow *e = &unk_08[idx];
    MI_CpuFillFast(e->unk_00.charBase, fill, e->unk_28 * 0x20 * e->unk_2C);
}

void *TextPrinter::GetCharPtr(int bg)
{
    void *ptr = NULL;
    switch (bg) {
    case 0:
        ptr = G2_GetBG0CharPtr();
        break;
    case 1:
        ptr = G2_GetBG1CharPtr();
        break;
    case 2:
        ptr = G2_GetBG2CharPtr();
        break;
    case 3:
        ptr = G2_GetBG3CharPtr();
        break;
    }
    return ptr;
}

void *TextPrinter::GetScrPtr(int bg)
{
    void *ptr = NULL;
    switch (bg) {
    case 0:
        ptr = G2_GetBG0ScrPtr();
        break;
    case 1:
        ptr = G2_GetBG1ScrPtr();
        break;
    case 2:
        ptr = G2_GetBG2ScrPtr();
        break;
    case 3:
        ptr = G2_GetBG3ScrPtr();
        break;
    }
    return ptr;
}

void TextPrinter::SetString(const char *str)
{
    STD_CopyString(unk_14, str);
}

int TextPrinter::GetRemainingWidth(int idx, const u8 *str, int margin)
{
    TextPrinterWindow *e = &unk_08[idx];
    int width = e->unk_28;
    return width * 8 - NNS_G2dTextCanvasGetStringWidth(&e->unk_18, (const NNSG2dChar *)str, NULL) - margin;
}
