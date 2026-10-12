#ifndef POKERANGER2_UNKCLASS_02025648_HPP
#define POKERANGER2_UNKCLASS_02025648_HPP

#include <nitro.h>

#include "common.hpp"

// Sub-screen panel loaded step by step (UnkClass_02022404::unk_4C); still asm
class UnkClass_02025648 {
public:
    UnkClass_02025648();
    ~UnkClass_02025648();

    void sub_020256A4();
    int sub_020257F4(int step);
    void sub_02027640();
    void sub_02027674();
    void sub_020276A0();

public:
    u8 unk_00[0x54];
};

STATIC_SIZE_ASSERT(UnkClass_02025648, 0x54);

#endif // POKERANGER2_UNKCLASS_02025648_HPP
