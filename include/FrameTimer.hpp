#ifndef POKERANGER2_FRAMETIMER_HPP
#define POKERANGER2_FRAMETIMER_HPP

#include <nitro.h>

#include "common.hpp"

class FrameTimer {
public:
    FrameTimer();

    void WaitFrame();
    void SetFps(u16 fps);
    u16 GetFps();
    void CountVBlank();
    void SampleTick();

public:
    OSTick unk_00;
    s64 unk_08;
    u16 unk_10;
    vu16 unk_12;
    u16 unk_14;
    u32 unk_18;
    u32 unk_1C;
};

STATIC_SIZE_ASSERT(FrameTimer, 0x20);

#endif // POKERANGER2_FRAMETIMER_HPP
