#ifndef POKERANGER2_BATTLE_UNKCLASS_021380AC_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021380AC_HPP

#include <nitro.h>

#include "UnkClass_0214FB28.hpp"
#include "common.hpp"

class Camera2D;

// Defined in ov1
class UnkClass_021380AC {
public:
    UnkClass_021380AC();
    ~UnkClass_021380AC(); // ov1_021380C0
    void ov1_02138238();
    void ov1_02138268(Camera2D *camera);
    u16 ov1_021382A4(u16 z);
    void ov1_02138280();

public:
    u8 unk_00[0x4];
    UnkStruct_0214FB28 *unk_04;
    u8 unk_08[0x8];
};

STATIC_SIZE_ASSERT(UnkClass_021380AC, 0x10);

#endif // POKERANGER2_BATTLE_UNKCLASS_021380AC_HPP
