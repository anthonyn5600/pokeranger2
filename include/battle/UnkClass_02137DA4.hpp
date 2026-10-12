#ifndef POKERANGER2_BATTLE_UNKCLASS_02137DA4_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02137DA4_HPP

#include <nitro.h>

#include "common.hpp"

class CActor;
class Camera2D;

// Defined in ov1
class UnkClass_02137DA4 {
public:
    UnkClass_02137DA4();
    ~UnkClass_02137DA4(); // ov1_02137DBC
    void ov1_02137DF8(CActor *actor);
    void ov1_02137EE8();
    int ov1_02137F28(Camera2D *camera);

public:
    u8 unk_00[0xC];
    s32 unk_0C;
    u8 unk_10[0x4];
};

STATIC_SIZE_ASSERT(UnkClass_02137DA4, 0x14);

#endif // POKERANGER2_BATTLE_UNKCLASS_02137DA4_HPP
