#ifndef POKERANGER2_FIELD_UNKCLASS_0216D420_HPP
#define POKERANGER2_FIELD_UNKCLASS_0216D420_HPP

#include <nitro.h>

#include "UnkClass_02008788.hpp"
#include "common.hpp"

// Pool of animation slots registered on one cell animation controller; effects take one each.
class UnkClass_0216D420 {
public:
    struct Slot {
        u8 used;
        u16 anim;
    };

    UnkClass_0216D420();
    ~UnkClass_0216D420();
    void Init(UnkClass_02008788 *cac, u32 count);
    void Release(UnkClass_02008788 *cac);
    u16 Acquire();
    void Free(u16 anim);

    Slot *m_slots;
    u32 m_count;
};
STATIC_SIZE_ASSERT(UnkClass_0216D420, 0x8);

#endif // POKERANGER2_FIELD_UNKCLASS_0216D420_HPP
