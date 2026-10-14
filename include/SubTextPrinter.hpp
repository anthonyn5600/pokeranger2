#ifndef POKERANGER2_SUBTEXTPRINTER_HPP
#define POKERANGER2_SUBTEXTPRINTER_HPP

#include <nitro.h>
#include <nnsys.h>

#include "TextPrinter.hpp"
#include "common.hpp"

class SubTextPrinter {
public:
    SubTextPrinter(const NNSG2dFont *font, void *arg1);

    void SetFont(const NNSG2dFont *font, u32 arg1);
    void FreeWindows();
    void SetupBG();
    void LoadPalette();
    void AllocWindows(int arg0);
    void InitWindow(int idx, int width, int height, int left, int top, int charNo, int hSpace, int vSpace);
    void Print(int idx, int x, int y, int color, u8 *str, BOOL center, int offset);
    void ClearWindow(int idx);
    void SetString(const char *str);
    int GetRemainingWidth(int idx, const u8 *str, int margin);

public:
    void *unk_00;
    const NNSG2dFont *unk_04;
    TextPrinterWindow *unk_08;
    u32 unk_0C;
    char unk_10[0x18];
    u8 *unk_28;
    BOOL unk_2C;
    u32 unk_30[4];
};

STATIC_SIZE_ASSERT(SubTextPrinter, 0x40);

#endif // POKERANGER2_SUBTEXTPRINTER_HPP
