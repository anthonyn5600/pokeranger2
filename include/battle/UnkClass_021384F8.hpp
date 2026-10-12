#ifndef POKERANGER2_BATTLE_UNKCLASS_021384F8_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021384F8_HPP

#include <nitro.h>

#include "common.hpp"

class CBattleDisk;
class Camera2D;
class CPlayerHPGauge;

// Defined in ov1
class UnkClass_021384F8 {
public:
    UnkClass_021384F8();
    ~UnkClass_021384F8(); // ov1_02138CAC
    void ov1_02138FEC();
    void ov1_02139C30(CBattleDisk *disk, CPlayerHPGauge *gauge);
    void ov1_021399A8(Camera2D *camera);
    int ov1_02139CE4(int z);
    u8 ov1_0213A4A0(u16 arg0);

    inline BOOL IsActive()
    {
        return unk_004 != 0;
    }

public:
    u8 unk_000[0x4];
    u32 unk_004;
    s16 unk_008;
    u16 unk_00A;
    u8 unk_00C[0x1C];
    u32 unk_028;
    u8 unk_02C[0x2];
    u16 unk_02E;
    u8 unk_030[0xAF0];
};

STATIC_SIZE_ASSERT(UnkClass_021384F8, 0xB20);

#endif // POKERANGER2_BATTLE_UNKCLASS_021384F8_HPP
