#ifndef POKERANGER2_BATTLE_UNKCLASS_02127B48_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02127B48_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class UnkClass_021278E8;

class Camera2D;

// Defined in ov1
class UnkClass_02127B48 {
public:
    UnkClass_02127B48(); // ov1_02127B48
    ~UnkClass_02127B48(); // ov1_02127B88
    void ov1_02127BCC();
    void ov1_02127BF0(Camera2D *camera);
    int ov1_02127CAC(int z);

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }
    void ov1_02127EE4();
    void ov1_02127C60(UnkClass_021278E8 *arg0);

public:
    u8 unk_00[0x8];
    BOOL unk_08;
    Point2D m_pos;
    u8 unk_14[0x4];
};

STATIC_SIZE_ASSERT(UnkClass_02127B48, 0x18);

#endif // POKERANGER2_BATTLE_UNKCLASS_02127B48_HPP
