#ifndef POKERANGER2_BATTLE_UNKCLASS_021291BC_HPP
#define POKERANGER2_BATTLE_UNKCLASS_021291BC_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class UnkClass_02128E88;

class Camera2D;

// Defined in ov1
class UnkClass_021291BC {
public:
    UnkClass_021291BC(); // ov1_021291BC
    ~UnkClass_021291BC(); // ov1_02129240
    void ov1_021292CC();
    void ov1_02129368(Camera2D *camera);
    void ov1_021293D4(Camera2D *camera);
    void ov1_021293D8(int state);
    int ov1_02129490(int z);

    inline void SetPos(Point2D pos)
    {
        m_pos.x = pos.x;
        m_pos.y = pos.y;
    }
    void ov1_02129274(UnkClass_02128E88 *arg0);

public:
    u8 unk_00[0x8];
    BOOL unk_08;
    u8 unk_0C[0xC];
    Point2D m_pos;
    u8 unk_20[0xC];
};

STATIC_SIZE_ASSERT(UnkClass_021291BC, 0x2C);

#endif // POKERANGER2_BATTLE_UNKCLASS_021291BC_HPP
