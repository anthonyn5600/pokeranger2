#ifndef POKERANGER2_BATTLE_UNKCLASS_0213F028_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0213F028_HPP

#include <nitro.h>

#include "common.hpp"

class Camera2D;

// Defined in ov1
class UnkClass_0213F028 {
public:
    UnkClass_0213F028(u16 arg0);
    ~UnkClass_0213F028(); // ov1_0213F094
    void ov1_0213F338();
    void ov1_0213F82C(Camera2D *camera);
    int ov1_0213F970(int z);
    void ov1_0213F8B4();

    inline BOOL IsActive()
    {
        return unk_004 != 0;
    }

public:
    u8 unk_000[0x4];
    u32 unk_004;
    u8 unk_008[0x150];
};

STATIC_SIZE_ASSERT(UnkClass_0213F028, 0x158);

#endif // POKERANGER2_BATTLE_UNKCLASS_0213F028_HPP
