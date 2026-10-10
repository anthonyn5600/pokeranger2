#ifndef POKERANGER2_UNKCLASS_02142428_HPP
#define POKERANGER2_UNKCLASS_02142428_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_02143714;

// Defined in ov0
class UnkClass_02142428 {
public:
    UnkClass_02142428(UnkClass_02143714 *arg0);

    virtual void func0();
    virtual ~UnkClass_02142428();

public:
    struct Unk67C {
        virtual int func0();
        virtual int func1();
        virtual int func2(int arg0);
        virtual int func3(int arg0);
        virtual int func4(int arg0);
        virtual int func5();
    };

    u8 unk_004[0x678];
    Unk67C unk_67C;
    u8 unk_680[0x200];
};

STATIC_SIZE_ASSERT(UnkClass_02142428, 0x880);

extern "C" {
void ov0_021434F0(UnkClass_02142428 *obj);
}

#endif // POKERANGER2_UNKCLASS_02142428_HPP
