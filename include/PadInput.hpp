#ifndef POKERANGER2_PADINPUT_HPP
#define POKERANGER2_PADINPUT_HPP

#include <nitro.h>

#include "common.hpp"

class PadInput {
public:
    PadInput();
    void Update();

    void *operator new(size_t size);
    void operator delete(void *ptr);

public:
    u16 unk_0000;
    u16 unk_0002;
    u16 unk_0004;
    u16 unk_0006;
    u8 unk_0008;
    u8 unk_0009;
    s16 unk_000A[0x10];
    u8 unk_002A;
};

STATIC_SIZE_ASSERT(PadInput, 0x2C);

#endif // POKERANGER2_PADINPUT_HPP
