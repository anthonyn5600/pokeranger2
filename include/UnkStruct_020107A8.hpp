#ifndef POKERANGER2_UNKSTRUCT_020107A8_HPP
#define POKERANGER2_UNKSTRUCT_020107A8_HPP

#include <nitro.h>

// Record returned by sub_020107A8 (from the table at CGame::unk_1434)
struct UnkStruct_020107A8 {
    u8 unk_00[0x5];
    u8 unk_05;
    u8 unk_06;
};

extern "C" {
UnkStruct_020107A8 *sub_020107A8(void *obj, u16 arg1);
}

#endif // POKERANGER2_UNKSTRUCT_020107A8_HPP
