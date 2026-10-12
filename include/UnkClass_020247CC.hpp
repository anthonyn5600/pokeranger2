#ifndef POKERANGER2_UNKCLASS_020247CC_HPP
#define POKERANGER2_UNKCLASS_020247CC_HPP

#include <nitro.h>

#include "common.hpp"

// Sub-screen panel (UnkClass_02022404::unk_30); still asm
class UnkClass_020247CC {
public:
    UnkClass_020247CC();
    ~UnkClass_020247CC();

    void sub_02024A2C();
    void sub_02024A60();
    void sub_020255F0();
    void sub_02025624();

public:
    u8 unk_00[0x78];
};

STATIC_SIZE_ASSERT(UnkClass_020247CC, 0x78);

#endif // POKERANGER2_UNKCLASS_020247CC_HPP
