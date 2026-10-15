// PC port only: checked pointer -> 32-bit integer conversion (see include/PtrCast.hpp).

#include "PtrCast.hpp"

#include <stdio.h>
#include <stdlib.h>

u32 PcPtrToU32(const volatile void *ptr)
{
    uintptr_t addr = (uintptr_t)ptr;
    // Below 2 GB, so a round trip through a signed int (sign extension) gives the same pointer back.
    if (addr >= 0x80000000u) {
        fprintf(stderr, "PtrCast: pointer %p does not fit in 31 bits (heap outside libntr main memory?)\n", (void *)ptr);
        abort();
    }
    return (u32)addr;
}
