#ifndef POKERANGER2_UNKCLASS_02042108_HPP
#define POKERANGER2_UNKCLASS_02042108_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in main (still asm)
class UnkClass_02042108 {
public:
    UnkClass_02042108(u8 arg0);
    ~UnkClass_02042108();

public:
    u8 unk_00;
    u8 unk_01[0x1B];
};

STATIC_SIZE_ASSERT(UnkClass_02042108, 0x1C);

class Camera2D;

extern "C" {
void sub_020423F4(UnkClass_02042108 *obj, Camera2D *camera);
int sub_0204240C(UnkClass_02042108 *obj, int z);
}

#endif // POKERANGER2_UNKCLASS_02042108_HPP
