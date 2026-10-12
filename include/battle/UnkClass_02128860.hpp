#ifndef POKERANGER2_BATTLE_UNKCLASS_02128860_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02128860_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class UnkClass_02128600;

class Camera2D;

// Defined in ov1
class UnkClass_02128860 {
public:
    UnkClass_02128860(); // ov1_02128860
    ~UnkClass_02128860(); // ov1_021288E8
    void ov1_02128970(Camera2D *camera);

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }
    void ov1_02128E34(Point2D pos, int arg1);
    void ov1_0212891C(UnkClass_02128600 *arg0);

public:
    Point2D m_pos;
    u16 m_hp;
    u8 unk_0A[0xE];
};

STATIC_SIZE_ASSERT(UnkClass_02128860, 0x18);

#endif // POKERANGER2_BATTLE_UNKCLASS_02128860_HPP
