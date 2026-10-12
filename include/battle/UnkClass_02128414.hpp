#ifndef POKERANGER2_BATTLE_UNKCLASS_02128414_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02128414_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class UnkClass_021281B4;

class Camera2D;

// Defined in ov1
class UnkClass_02128414 {
public:
    UnkClass_02128414(); // ov1_02128414
    ~UnkClass_02128414(); // ov1_02128458
    void ov1_0212849C();
    void ov1_021284C0(Camera2D *camera);
    int ov1_021285D4(int z);

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }
    void ov1_0212854C(UnkClass_021281B4 *arg0);

public:
    u8 unk_00[0x8];
    BOOL unk_08;
    Point2D m_pos;
    u8 unk_14[0x4];
};

STATIC_SIZE_ASSERT(UnkClass_02128414, 0x18);

#endif // POKERANGER2_BATTLE_UNKCLASS_02128414_HPP
