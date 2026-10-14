#ifndef POKERANGER2_TEXTPRINTER_HPP
#define POKERANGER2_TEXTPRINTER_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"

class TextPrinterWindow {
public:
    ~TextPrinterWindow()
    {
    }

public:
    NNSG2dCharCanvas unk_00;
    NNSG2dTextCanvas unk_18;
    int unk_28;
    int unk_2C;
};

STATIC_SIZE_ASSERT(TextPrinterWindow, 0x30);

class TextPrinter {
public:
    TextPrinter(const NNSG2dFont *font, void *arg1);
    ~TextPrinter();

    void SetFont(const NNSG2dFont *font, u32 arg1);
    void FreeWindows();
    void SetupBG(int bg, GXBGScrBase screenBase, GXBGCharBase charBase);
    void LoadPalette();
    void AllocWindows(int arg0);
    void InitWindow(int idx, int width, int height, int left, int top, int charNo, int hSpace, int vSpace);
    void Print(int idx, int x, int y, int color, u8 *str, BOOL center, int offset);
    void ClearWindow(int idx);
    void FillWindow(int idx, u32 fill);
    void *GetCharPtr(int bg);
    void *GetScrPtr(int bg);
    void SetString(const char *str);
    int GetRemainingWidth(int idx, const u8 *str, int margin);

public:
    void *unk_00;
    const NNSG2dFont *unk_04;
    TextPrinterWindow *unk_08;
    u32 unk_0C;
    u32 unk_10;
    char unk_14[0x18];
    u8 *unk_2C;
    BOOL unk_30;
    u32 unk_34[4];
};

STATIC_SIZE_ASSERT(TextPrinter, 0x44);

#endif // POKERANGER2_TEXTPRINTER_HPP
