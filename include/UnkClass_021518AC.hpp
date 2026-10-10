#ifndef POKERANGER2_UNKCLASS_021518AC_HPP
#define POKERANGER2_UNKCLASS_021518AC_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in ov0
class UnkClass_021518AC {
public:
    UnkClass_021518AC();

    ~UnkClass_021518AC()
    {
        ov0_021518F4();
    }

    void ov0_021518F4();

public:
    void *unk_00;
};

STATIC_SIZE_ASSERT(UnkClass_021518AC, 0x4);

#endif // POKERANGER2_UNKCLASS_021518AC_HPP
