#include "UnkClass_0200E0B4.hpp"

#include "fx_utils.hpp"

extern "C" {
extern u8 DAT_0208aaf8;
extern fx32 MAIN_BSS_020AF338;
}

UnkClass_0200E0B4::UnkClass_0200E0B4(u8 screen, int brightness)
{
    unk_00 = 0;
    unk_02 = screen;
    unk_04 = 0;
    unk_06 = 0;
    unk_08 = brightness;
    unk_0C = 0;
    unk_10 = 0;
    unk_14 = 0;
    unk_18 = 0;
}

void UnkClass_0200E0B4::sub_0200E0E0(u16 mode, u16 duration)
{
    if (!sub_0200E310()) {
        unk_08 = sub_0200E1DC(mode);
    }

    unk_00 = mode;
    unk_06 = duration;
    unk_04 = 0;
    unk_0C = unk_08;
    unk_10 = -unk_0C + sub_0200E1A4(mode);

    if (duration != 0) {
        unk_14 = 0;
        unk_18 = FX32_DIV(FX32_ONE, (fx64)(duration << FX32_SHIFT));
        unk_00 |= 0x10;
    } else {
        unk_08 = sub_0200E1A4(sub_0200E324());
        unk_0C = 0;
        unk_00 &= ~0x10;
    }
}

int UnkClass_0200E0B4::sub_0200E1A4(u16 mode)
{
    int brightness = 0;
    switch (mode) {
    case 0:
        break;
    case 1:
    case 3:
        brightness = 0;
        break;
    case 2:
        brightness = 16;
        break;
    case 4:
        brightness = -16;
        break;
    }
    return brightness;
}

int UnkClass_0200E0B4::sub_0200E1DC(u16 mode)
{
    int brightness = 0;
    switch (mode) {
    case 0:
        break;
    case 1:
        brightness = 16;
        break;
    case 2:
        break;
    case 3:
        brightness = -16;
        break;
    case 4:
        break;
    }
    return brightness;
}

void UnkClass_0200E0B4::sub_0200E210()
{
    if (!DAT_0208aaf8) {
        return;
    }
    if (!sub_0200E310()) {
        return;
    }

    if (unk_04 == unk_06) {
        unk_08 = sub_0200E1A4(sub_0200E324());
        unk_0C = 0;
        unk_00 &= ~0x10;
        return;
    }

    if (unk_04 < unk_06) {
        unk_14 += FX32_MUL(unk_18, MAIN_BSS_020AF338);
        unk_08 = unk_0C + (FX32_MUL(unk_14, unk_10 << FX32_SHIFT) >> FX32_SHIFT);
        unk_04++;
    }
}

void UnkClass_0200E0B4::sub_0200E2D4()
{
    sub_0200E210();
    if (unk_02 & 1) {
        GX_SetMasterBrightness(unk_08);
    } else {
        GXS_SetMasterBrightness(unk_08);
    }
}

BOOL UnkClass_0200E0B4::sub_0200E310()
{
    return (unk_00 & 0x10) ? TRUE : FALSE;
}

u16 UnkClass_0200E0B4::sub_0200E324()
{
    return unk_00 & 7;
}
