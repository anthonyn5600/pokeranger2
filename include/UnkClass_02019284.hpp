#ifndef POKERANGER2_UNKCLASS_02019284_HPP
#define POKERANGER2_UNKCLASS_02019284_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_02003718;

class UnkClass_02019284 {
public:
    UnkClass_02019284();
    virtual ~UnkClass_02019284();
    virtual void func2();
    virtual void func3(UnkClass_02003718 *camera);

public:
    u8 unk_004[0x5E0];
};

STATIC_SIZE_ASSERT(UnkClass_02019284, 0x5E4);

extern "C" {
void sub_0201A000(UnkClass_02019284 *obj, u8 arg1, u8 arg2);
void sub_0201A10C(UnkClass_02019284 *obj, u32 arg1);
void sub_0201A140(UnkClass_02019284 *obj, int arg1);
void sub_0201A178(UnkClass_02019284 *obj, int arg1);
void sub_0201A220(UnkClass_02019284 *obj, u32 arg1, u8 arg2);
void *sub_0201AAC0(UnkClass_02019284 *obj, int arg1);
}

#endif // POKERANGER2_UNKCLASS_02019284_HPP
