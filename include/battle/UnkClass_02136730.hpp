#ifndef POKERANGER2_BATTLE_UNKCLASS_02136730_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02136730_HPP

#include <nitro.h>

#include "common.hpp"

// Defined in ov1
class UnkClass_02136730 {
public:
    UnkClass_02136730();
    ~UnkClass_02136730(); // ov1_0213674C
    void ov1_02136A40(fx32 x, fx32 y);
    void ov1_02136A58(fx32 x, fx32 y);
    void ov1_02136A88(u8 arg0, u8 arg1);
    void ov1_02136AA0(fx32 arg0, int arg1);

public:
    u8 unk_00[0xB4];
};

STATIC_SIZE_ASSERT(UnkClass_02136730, 0xB4);

#endif // POKERANGER2_BATTLE_UNKCLASS_02136730_HPP
