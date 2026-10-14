#include "SubTextPrinter.hpp"

#include "SaveData.hpp"
#include "file/CNCLRFile.hpp"

extern "C" {
u8 *NameTables_GetPokemonName(void *, u32);

extern char s_data_font_prs_lc_jp_NCLR_0208aa40;
extern char s_data_font_prs_jp_NCLR_0208aa5c;
}

SubTextPrinter::SubTextPrinter(const NNSG2dFont *font, void *arg1)
{
    unk_04 = font;
    unk_0C = 0;
    unk_00 = arg1;
    unk_08 = NULL;
}

void SubTextPrinter::SetFont(const NNSG2dFont *font, u32 arg1)
{
    unk_0C = arg1;
    unk_04 = font;
    LoadPalette();
}

void SubTextPrinter::FreeWindows()
{
    if (unk_08 != NULL) {
        delete[] unk_08;
        unk_08 = NULL;
    }
}

void SubTextPrinter::SetupBG()
{
    G2S_SetBG0Control(GX_BG_SCRSIZE_TEXT_256x256, GX_BG_COLORMODE_16, GX_BG_SCRBASE_0x6000, GX_BG_CHARBASE_0x00000, GX_BG_EXTPLTT_23);
    GXS_SetVisiblePlane(GXS_GetVisiblePlane() | GX_PLANEMASK_BG0);
    LoadPalette();
    G2S_SetBG0Priority(0);
    MI_CpuClearFast((void *)HW_DB_BG_VRAM, 0x20);
    MI_CpuClearFast(G2S_GetBG0ScrPtr(), 0x800);
}

void SubTextPrinter::LoadPalette()
{
    if (unk_0C == 0) {
        CNCLRFile *nclrFile = new CNCLRFile(&s_data_font_prs_lc_jp_NCLR_0208aa40, 1, 0, 0);
        DC_FlushRange(nclrFile->unk_B8->pRawData, 0x20);
        GXS_LoadBGPltt(nclrFile->unk_B8->pRawData, 0x1C0, 0x20);
        delete nclrFile;
    } else {
        CNCLRFile *nclrFile = new CNCLRFile(&s_data_font_prs_jp_NCLR_0208aa5c, 1, 0, 0);
        DC_FlushRange(nclrFile->unk_B8->pRawData, 0x20);
        GXS_LoadBGPltt(nclrFile->unk_B8->pRawData, 0x1C0, 0x20);
        delete nclrFile;
    }
}

void SubTextPrinter::AllocWindows(int arg0)
{
    if (unk_08 == NULL) {
        unk_08 = new TextPrinterWindow[arg0];
    } else {
        OS_Terminate();
    }
}

void SubTextPrinter::InitWindow(int idx, int width, int height, int left, int top, int charNo, int hSpace, int vSpace)
{
    void *charPtr = G2S_GetBG0CharPtr();
    TextPrinterWindow *e = &unk_08[idx];
    e->unk_28 = width;
    e->unk_2C = height;
    NNS_G2dCharCanvasInitForBG(&unk_08[idx].unk_00, (u8 *)charPtr + charNo * 0x20, unk_08[idx].unk_28, unk_08[idx].unk_2C, NNS_G2D_CHARA_COLORMODE_16);
    NNS_G2dTextCanvasInit(&unk_08[idx].unk_18, &unk_08[idx].unk_00, unk_04, hSpace, vSpace);
    TextPrinterWindow *elem = &unk_08[idx];
    NNS_G2dMapScrToCharText(G2S_GetBG0ScrPtr(), elem->unk_28, elem->unk_2C, left, top, NNS_G2D_TEXT_BG_WIDTH_256, charNo, 0xE);
    ClearWindow(idx);
}

void SubTextPrinter::Print(int idx, int x, int y, int color, u8 *str, BOOL center, int offset)
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
                    unk_28 = ++str;
                    str = &MAIN_BSS_020B26A0.m_playerName;
                    unk_2C = 1;
                    break;
                case 'P': {
                    str++;
                    u32 v = unk_30[*str & 0xF];
                    str += 2;
                    unk_28 = str;
                    str = NameTables_GetPokemonName(unk_00, v);
                    unk_2C = 1;
                    break;
                }
                case 'K':
                    str += 3;
                    unk_28 = str;
                    str = (u8 *)unk_10;
                    unk_2C = 1;
                    break;
                }
            } else {
                cx += NNS_G2dCharCanvasDrawChar(elem->unk_18.pCanvas, font, cx, cy, color, c);
                cx += hSpace;
            }
        } else {
            if (unk_2C == 0) {
                return;
            }
            unk_2C = 0;
            str = unk_28;
        }
    }
}

void SubTextPrinter::ClearWindow(int idx)
{
    TextPrinterWindow *e = &unk_08[idx];
    MI_CpuClearFast(e->unk_00.charBase, e->unk_28 * 0x20 * e->unk_2C);
}

void SubTextPrinter::SetString(const char *str)
{
    STD_CopyString(unk_10, str);
}

int SubTextPrinter::GetRemainingWidth(int idx, const u8 *str, int margin)
{
    TextPrinterWindow *e = &unk_08[idx];
    int width = e->unk_28;
    return width * 8 - NNS_G2dTextCanvasGetStringWidth(&e->unk_18, (const NNSG2dChar *)str, NULL) - margin;
}
