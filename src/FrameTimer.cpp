#include "FrameTimer.hpp"

#include <nitro.h>

#include "ActorMotion.hpp"
#include "CellAnimInstance.hpp"

extern u16 DAT_0208aaf4;
extern u16 DAT_0208aafa;
extern fx32 MAIN_BSS_020AF338;

FrameTimer::FrameTimer()
{
    unk_12 = 0;
    SetFps(30);
    unk_18 = 0;
    unk_1C = 0;
}

void FrameTimer::WaitFrame()
{
    while (unk_12 < unk_14) {
    }
    unk_12 = 0;
    unk_1C = 1;
    OS_WaitVBlankIntr();
    unk_1C = 0;
}

void FrameTimer::SetFps(u16 fps)
{
    if (fps > 60) {
        return;
    }
    unk_10 = fps;
    unk_14 = 60 / fps;
    unk_08 = fps * 0x01FF7D0E / 60;
    g_animFps = fps;
    g_actorFps = fps;
    DAT_0208aaf4 = fps;
    DAT_0208aafa = 60;
    MAIN_BSS_020AF338 = FX32_ONE;
}

u16 FrameTimer::GetFps()
{
    return unk_10;
}

void FrameTimer::CountVBlank()
{
    unk_12++;
}

void FrameTimer::SampleTick()
{
    if (unk_1C == 0) {
        return;
    }
    unk_00 = OS_GetTick();
}
