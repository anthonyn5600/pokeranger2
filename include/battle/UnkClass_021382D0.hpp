#ifndef POKERANGER2_BATTLE_UNKCLASS_021382D0_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021382D0_HPP

#include <nitro.h>

#include "UnkClass_0214FB28.hpp"
#include "common.hpp"

class Camera2D;

// Defined in ov1
class UnkClass_021382D0 {
public:
    UnkClass_021382D0();
    ~UnkClass_021382D0(); // ov1_021382E4
    void ov1_02138460();
    void ov1_02138490(Camera2D *camera);
    int ov1_021384CC(int z);
    void ov1_021384A8();

public:
    u8 unk_00[0x4];
    UnkStruct_0214FB28 *unk_04;
    u8 unk_08[0x8];
};

STATIC_SIZE_ASSERT(UnkClass_021382D0, 0x10);

#endif // POKERANGER2_BATTLE_UNKCLASS_021382D0_HPP
