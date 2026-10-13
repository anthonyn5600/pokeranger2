#ifndef POKERANGER2_BATTLE_UNKCLASS_02136AD4_HPP
#define POKERANGER2_BATTLE_UNKCLASS_02136AD4_HPP

#include <nitro.h>

#include "common.hpp"

class Camera2D;
class UnkClass_02136730;

// Defined in ov1
class UnkClass_02136AD4 {
public:
    UnkClass_02136AD4(UnkClass_02136730 **items, int count);
    ~UnkClass_02136AD4();
    void ov1_02136AEC();
    UnkClass_02136730 *ov1_02136B24(u16 arg0, fx32 x, fx32 y, int arg3, fx32 arg4, u16 color);
    void ov1_02136B88(Camera2D *camera);
    void ov1_02136BD0(int arg0);

public:
    u16 m_count;
    UnkClass_02136730 **m_items;
    u16 m_next;
    u8 unk_0A[0x1A];
};

STATIC_SIZE_ASSERT(UnkClass_02136AD4, 0x24);

#endif // POKERANGER2_BATTLE_UNKCLASS_02136AD4_HPP
