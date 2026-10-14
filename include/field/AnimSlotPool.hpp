#ifndef POKERANGER2_FIELD_ANIMSLOTPOOL_HPP
#define POKERANGER2_FIELD_ANIMSLOTPOOL_HPP

#include <nitro.h>

#include "CellAnimController.hpp"
#include "common.hpp"

// Pool of animation slots registered on one cell animation controller; effects take one each.
class AnimSlotPool {
public:
    struct Slot {
        u8 used;
        u16 anim;
    };

    AnimSlotPool();
    ~AnimSlotPool();
    void Init(CellAnimController *cac, u32 count);
    void Release(CellAnimController *cac);
    u16 Acquire();
    void Free(u16 anim);

    Slot *m_slots;
    u32 m_count;
};
STATIC_SIZE_ASSERT(AnimSlotPool, 0x8);

#endif // POKERANGER2_FIELD_ANIMSLOTPOOL_HPP
