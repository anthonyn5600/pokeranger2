#ifndef POKERANGER2_BATTLE_UNKCLASS_0212770C_HPP
#define POKERANGER2_BATTLE_UNKCLASS_0212770C_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class UnkClass_021274AC;

class Camera2D;

// Defined in ov1
class UnkClass_0212770C {
public:
    UnkClass_0212770C(); // ov1_0212770C
    ~UnkClass_0212770C(); // ov1_0212774C
    void ov1_02127780();
    void ov1_02127810(Camera2D *camera);
    int ov1_021278BC(int z);

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }
    void ov1_02127854(UnkClass_021274AC *arg0);

public:
    u8 unk_00[0x8];
    BOOL unk_08;
    u8 unk_0C[0xC];
    Point2D m_pos;
};

STATIC_SIZE_ASSERT(UnkClass_0212770C, 0x20);

#endif // POKERANGER2_BATTLE_UNKCLASS_0212770C_HPP
