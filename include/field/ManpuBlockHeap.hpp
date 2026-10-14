#ifndef POKERANGER2_FIELD_MANPUBLOCKHEAP_HPP
#define POKERANGER2_FIELD_MANPUBLOCKHEAP_HPP

#include <nitro.h>

#include "common.hpp"

// Heap of 32 blocks of 0x100 bytes (bit i of m_used = block i taken, of m_cont = allocation continues in block i + 1).
// The Manpu factory owns the one CFieldEffectManpu::operator new uses.
class ManpuBlockHeap {
public:
    ManpuBlockHeap();
    void *Alloc(u32 size);
    void Free(void *ptr);

    u32 m_used;
    u32 m_cont;
    u8 m_blocks[32][0x100];
};
STATIC_SIZE_ASSERT(ManpuBlockHeap, 0x2008);

#endif // POKERANGER2_FIELD_MANPUBLOCKHEAP_HPP
