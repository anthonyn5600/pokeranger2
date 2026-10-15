#ifndef POKERANGER2_HEAP_HPP
#define POKERANGER2_HEAP_HPP

#include <nitro.h>
#include <nnsys.h>

struct HeapHandles {
    NNSFndHeapHandle main;
    NNSFndHeapHandle secondary;
    NNSFndHeapHandle overlay;
};

void Heap_Init(u32 secondarySize);
void *Heap_Alloc(size_t size);
void *Heap_AllocWithAlignment(size_t size, u32 alignment);
void Heap_Free(void *ptr);
NNSFndHeapHandle *Heap_GetMainHandle(void);
void *Heap_AllocSecondary(size_t size);
void Heap_FreeSecondary(void *ptr);
NNSFndHeapHandle *Heap_GetSecondaryHandle(void);
void Heap_InitOverlay(void *ptr, size_t size);
void Heap_DestroyOverlay(void);
#ifdef PC_PORT
// The overlays are linked into the PC executable, so the overlay heap (on the DS the space between the loaded
// overlay and the main arena, at most 378 KB) gets a fixed buffer.
void Heap_InitOverlayPc(void);
// libntr's own C++ code shares the global operator new/delete with the game (src/heap_operators.cpp): the game heaps
// serve only the game thread once they exist, and delete tells the two apart by address.
BOOL Heap_IsReadyPc(void);
BOOL Heap_OwnsPc(const void *ptr);
#endif

#endif // POKERANGER2_HEAP_HPP
