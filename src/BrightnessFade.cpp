#include "BrightnessFade.hpp"

#include "fx_utils.hpp"

extern "C" {
extern u8 DAT_0208aaf8;
extern fx32 MAIN_BSS_020AF338;
}

BrightnessFade::BrightnessFade(u8 screen, int brightness)
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

void BrightnessFade::Start(u16 mode, u16 duration)
{
    if (!IsActive()) {
        unk_08 = GetStartBrightness(mode);
    }

    unk_00 = mode;
    unk_06 = duration;
    unk_04 = 0;
    unk_0C = unk_08;
    unk_10 = -unk_0C + GetEndBrightness(mode);

    if (duration != 0) {
        unk_14 = 0;
        unk_18 = FX32_DIV(FX32_ONE, (fx64)(duration << FX32_SHIFT));
        unk_00 |= 0x10;
    } else {
        unk_08 = GetEndBrightness(GetMode());
        unk_0C = 0;
        unk_00 &= ~0x10;
    }
}

int BrightnessFade::GetEndBrightness(u16 mode)
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

int BrightnessFade::GetStartBrightness(u16 mode)
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

void BrightnessFade::Update()
{
    if (!DAT_0208aaf8) {
        return;
    }
    if (!IsActive()) {
        return;
    }

    if (unk_04 == unk_06) {
        unk_08 = GetEndBrightness(GetMode());
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

void BrightnessFade::UpdateAndApply()
{
    Update();
    if (unk_02 & 1) {
        GX_SetMasterBrightness(unk_08);
    } else {
        GXS_SetMasterBrightness(unk_08);
    }
}

BOOL BrightnessFade::IsActive()
{
    return (unk_00 & 0x10) ? TRUE : FALSE;
}

u16 BrightnessFade::GetMode()
{
    return unk_00 & 7;
}
