#include "UnkClass_02008D50.hpp"

#include <nitro.h>

#include "UnkClass_02007F98.hpp"

extern u16 DAT_0208b46c;
extern u16 DAT_0208aaf4;
extern u16 DAT_0208aafa;
extern fx32 MAIN_BSS_020AF338;

UnkClass_02008D50::UnkClass_02008D50()
{
    unk_12 = 0;
    sub_02008DB4(30);
    unk_18 = 0;
    unk_1C = 0;
}

void UnkClass_02008D50::sub_02008D7C()
{
    while (unk_12 < unk_14) {
    }
    unk_12 = 0;
    unk_1C = 1;
    OS_WaitVBlankIntr();
    unk_1C = 0;
}

void UnkClass_02008D50::sub_02008DB4(u16 fps)
{
    if (fps > 60) {
        return;
    }
    unk_10 = fps;
    unk_14 = 60 / fps;
    unk_08 = fps * 0x01FF7D0E / 60;
    g_animFps = fps;
    DAT_0208b46c = fps;
    DAT_0208aaf4 = fps;
    DAT_0208aafa = 60;
    MAIN_BSS_020AF338 = FX32_ONE;
}

u16 UnkClass_02008D50::sub_02008E50()
{
    return unk_10;
}

void UnkClass_02008D50::sub_02008E58()
{
    unk_12++;
}

void UnkClass_02008D50::sub_02008E68()
{
    if (unk_1C == 0) {
        return;
    }
    unk_00 = OS_GetTick();
}
