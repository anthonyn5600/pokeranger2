#ifndef POKERANGER2_UNKCLASS_0211D850_HPP
#define POKERANGER2_UNKCLASS_0211D850_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_0211D850;

extern UnkClass_0211D850 *MAIN_BSS_0210CA78;

extern "C" {
void sub_02035720(void *obj, int arg1);
void sub_02035774(void *obj);
}

// Defined in ov0, only inline (first found in CFieldScene::func6)
class UnkClass_0211D850 {
public:
    UnkClass_0211D850()
    {
        MAIN_BSS_0210CA78 = this;
        unk_00 = 0;
        unk_04 = 0;
        sub_02035720(this, 8);
    }

    ~UnkClass_0211D850()
    {
        sub_02035774(this);
        MAIN_BSS_0210CA78 = NULL;
    }

public:
    u32 unk_00;
    u32 unk_04;
};

STATIC_SIZE_ASSERT(UnkClass_0211D850, 0x8);

#endif // POKERANGER2_UNKCLASS_0211D850_HPP
