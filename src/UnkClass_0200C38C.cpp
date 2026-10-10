#include "UnkClass_0200C38C.hpp"

#include "file/CNCLRFile.hpp"

extern "C" {
u8 *sub_02018B10(void *, u32);

extern u8 MAIN_BSS_020BAE83;
extern char s_data_font_prs_lc_jp_NCLR_0208aa0c;
extern char s_data_font_prs_jp_NCLR_0208aa28;
}

UnkClass_0200C38C::UnkClass_0200C38C(const NNSG2dFont *font, void *arg1)
{
    unk_04 = font;
    unk_0C = 0;
    unk_00 = arg1;
    unk_08 = NULL;
    unk_10 = 0;
}

UnkClass_0200C38C::~UnkClass_0200C38C()
{
    sub_0200C3D0();
}

void UnkClass_0200C38C::sub_0200C3BC(const NNSG2dFont *font, u32 arg1)
{
    unk_0C = arg1;
    unk_04 = font;
    sub_0200C588();
}

void UnkClass_0200C38C::sub_0200C3D0()
{
    if (unk_08 != NULL) {
        delete[] unk_08;
        unk_08 = NULL;
    }
}

void UnkClass_0200C38C::sub_0200C408(int bg, GXBGScrBase screenBase, GXBGCharBase charBase)
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
    void *charPtr = sub_0200C9E8(unk_10);
    void *scrPtr = sub_0200CA2C(unk_10);
    sub_0200C588();
    MI_CpuClearFast(charPtr, 0x20);
    MI_CpuClearFast(scrPtr, 0x800);
}

void UnkClass_0200C38C::sub_0200C588()
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

void UnkClass_0200C38C::sub_0200C680(int arg0)
{
    if (unk_08 == NULL) {
        unk_08 = new UnkClass_0200C404[arg0];
    } else {
        OS_Terminate();
    }
}

void UnkClass_0200C38C::sub_0200C6C8(int idx, int width, int height, int left, int top, int charNo, int hSpace, int vSpace)
{
    void *charPtr = sub_0200C9E8(unk_10);
    UnkClass_0200C404 *e = &unk_08[idx];
    e->unk_28 = width;
    e->unk_2C = height;
    NNS_G2dCharCanvasInitForBG(&unk_08[idx].unk_00, (u8 *)charPtr + charNo * 0x20, unk_08[idx].unk_28, unk_08[idx].unk_2C, NNS_G2D_CHARA_COLORMODE_16);
    NNS_G2dTextCanvasInit(&unk_08[idx].unk_18, &unk_08[idx].unk_00, unk_04, hSpace, vSpace);
    UnkClass_0200C404 *elem = &unk_08[idx];
    NNS_G2dMapScrToCharText(sub_0200CA2C(unk_10), elem->unk_28, elem->unk_2C, left, top, NNS_G2D_TEXT_BG_WIDTH_256, charNo, 0xE);
    sub_0200C980(idx);
}

void UnkClass_0200C38C::sub_0200C7A4(int idx, int x, int y, int color, u8 *str, BOOL center, int offset)
{
    UnkClass_0200C404 *elem = &unk_08[idx];
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
                    str = &MAIN_BSS_020BAE83;
                    unk_30 = 1;
                    break;
                case 'P': {
                    str++;
                    u32 v = unk_34[*str & 0xF];
                    str += 2;
                    unk_2C = str;
                    str = sub_02018B10(unk_00, v);
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

void UnkClass_0200C38C::sub_0200C980(int idx)
{
    UnkClass_0200C404 *e = &unk_08[idx];
    MI_CpuClearFast(e->unk_00.charBase, e->unk_28 * 0x20 * e->unk_2C);
}

void UnkClass_0200C38C::sub_0200C9B4(int idx, u32 fill)
{
    UnkClass_0200C404 *e = &unk_08[idx];
    MI_CpuFillFast(e->unk_00.charBase, fill, e->unk_28 * 0x20 * e->unk_2C);
}

void *UnkClass_0200C38C::sub_0200C9E8(int bg)
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

void *UnkClass_0200C38C::sub_0200CA2C(int bg)
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

void UnkClass_0200C38C::sub_0200CA70(const char *str)
{
    STD_CopyString(unk_14, str);
}

int UnkClass_0200C38C::sub_0200CA80(int idx, const u8 *str, int margin)
{
    UnkClass_0200C404 *e = &unk_08[idx];
    int width = e->unk_28;
    return width * 8 - NNS_G2dTextCanvasGetStringWidth(&e->unk_18, (const NNSG2dChar *)str, NULL) - margin;
}
