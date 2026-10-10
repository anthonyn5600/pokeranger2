#ifndef POKERANGER2_UNKCLASS_020416AC_HPP
#define POKERANGER2_UNKCLASS_020416AC_HPP

#include <nitro.h>

#include "common.hpp"

class UnkClass_020416AC {
public:
    UnkClass_020416AC(int arg0);
    ~UnkClass_020416AC();

public:
    u8 unk_00[0x918];
};

STATIC_SIZE_ASSERT(UnkClass_020416AC, 0x918);

#endif // POKERANGER2_UNKCLASS_020416AC_HPP
