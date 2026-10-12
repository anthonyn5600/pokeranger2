#ifndef POKERANGER2_BATTLE_UNKCLASS_0212E88C_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0212E88C_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class Camera2D;

// Defined in ov1
class UnkClass_0212E88C {
public:
    UnkClass_0212E88C();
    ~UnkClass_0212E88C(); // ov1_0212E8FC
    void ov1_0212E940();
    void ov1_0212E998(Camera2D *camera);
    int ov1_0212EDB4(int z);
    void ov1_0212EA1C(Point2D pos);
    void ov1_0212EA7C(Point2D pos);
    void ov1_0212EAD4();

public:
    u8 unk_0000[0x341C];
};

STATIC_SIZE_ASSERT(UnkClass_0212E88C, 0x341C);

#endif // POKERANGER2_BATTLE_UNKCLASS_0212E88C_HPP
