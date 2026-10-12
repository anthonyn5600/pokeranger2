#ifndef POKERANGER2_BATTLE_UNKCLASS_0213AE18_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0213AE18_HPP

#include <nitro.h>

#include "common.hpp"

class CTouchPanel;
class Camera2D;
class UnkClass_0200ECD0;
class UnkClass_0201AD60;
class UnkClass_0212DC20;
class UnkClass_0213CC28;

// Defined in ov1
class UnkClass_0213AE18 {
public:
    UnkClass_0213AE18(void *arg0, UnkClass_0212DC20 *arg1, UnkClass_0213CC28 *arg2, UnkClass_0201AD60 *arg3);
    ~UnkClass_0213AE18(); // ov1_0213B1B0
    void ov1_0213B528(CTouchPanel *touch);
    void ov1_0213BFFC(Camera2D *camera);
    int ov1_0213C5F4();
    u8 ov1_0213C5FC();
    int ov1_0213C604();

    inline BOOL IsActive()
    {
        return unk_004 != 0;
    }
    int ov1_0213C67C(int z);
    void ov1_0213C2BC(int count, UnkClass_0200ECD0 **sprites, u16 *ids, u8 mask, BOOL partner);

public:
    u8 unk_000[0x4];
    u32 unk_004;
    u8 unk_008[0xFF4];
};

STATIC_SIZE_ASSERT(UnkClass_0213AE18, 0xFFC);

#endif // POKERANGER2_BATTLE_UNKCLASS_0213AE18_HPP
