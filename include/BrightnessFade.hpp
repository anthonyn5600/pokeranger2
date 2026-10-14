#ifndef POKERANGER2_BRIGHTNESSFADE_HPP
#define POKERANGER2_BRIGHTNESSFADE_HPP

#include <nitro.h>

#include "common.hpp"

class BrightnessFade {
public:
    BrightnessFade(u8 screen, int brightness);

    void Start(u16 mode, u16 duration);
    int GetEndBrightness(u16 mode);
    int GetStartBrightness(u16 mode);
    void Update();
    void UpdateAndApply();
    BOOL IsActive();
    u16 GetMode();

public:
    u16 unk_00;
    u8 unk_02;
    u16 unk_04;
    u16 unk_06;
    int unk_08;
    int unk_0C;
    int unk_10;
    fx32 unk_14;
    fx32 unk_18;
};

STATIC_SIZE_ASSERT(BrightnessFade, 0x1C);

#endif // POKERANGER2_BRIGHTNESSFADE_HPP
