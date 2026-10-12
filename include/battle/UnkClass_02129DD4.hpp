#ifndef POKERANGER2_BATTLE_UNKCLASS_02129DD4_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02129DD4_HPP

#include <nitro.h>

#include "common.hpp"
#include "primitive/CSoftwareSprite.hpp"
#include "sub_02006000.hpp"

class UnkClass_02129B74;

class Camera2D;

// Defined in ov1
class UnkClass_02129DD4 {
public:
    UnkClass_02129DD4(); // ov1_02129DD4
    ~UnkClass_02129DD4(); // ov1_02129E48
    void ov1_02129ED4();
    void ov1_02129FD0(Camera2D *camera);
    int ov1_0212A0D8(int z);

    inline void Stop()
    {
        unk_14 = FALSE;
        unk_18 = 0;
        unk_1A = 0;
        unk_0C = FX32_ONE;
    }
    void ov1_0212A058(UnkClass_02129B74 *arg0);

public:
    u8 unk_00[0x4];
    CSoftwareSprite *unk_04;
    CSoftwareSprite *unk_08;
    fx32 unk_0C;
    u8 unk_10[0x4];
    BOOL unk_14;
    u16 unk_18;
    u16 unk_1A;
    u8 unk_1C[0x4];
};

STATIC_SIZE_ASSERT(UnkClass_02129DD4, 0x20);

#endif // POKERANGER2_BATTLE_UNKCLASS_02129DD4_HPP
