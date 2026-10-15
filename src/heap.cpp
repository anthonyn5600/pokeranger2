#include "heap.hpp"

#define ARENA_ALIGNMENT      16
#define ARENA_ALIGNMENT_MASK (ARENA_ALIGNMENT - 1)
#define ALLOC_ALIGNMENT      4

extern "C" {
extern HeapHandles sHeapHandles;
#ifndef PC_PORT
extern void SDK_MAIN_ARENA_LO(void);
#endif
}

#ifdef PC_PORT
#include <pthread.h>

static u8 sPcOverlayHeap[0x60000] __attribute__((aligned(32)));
static const u8 *sPcArenaStart;
static const u8 *sPcArenaEnd;
static pthread_t sPcGameThread;

void Heap_InitOverlayPc(void)
{
    Heap_InitOverlay(sPcOverlayHeap, sizeof(sPcOverlayHeap));
}

BOOL Heap_IsReadyPc(void)
{
    return sHeapHandles.main != NULL && pthread_equal(pthread_self(), sPcGameThread);
}

BOOL Heap_OwnsPc(const void *ptr)
{
    const u8 *p = (const u8 *)ptr;
    return (p >= sPcArenaStart && p < sPcArenaEnd) || (p >= sPcOverlayHeap && p < sPcOverlayHeap + sizeof(sPcOverlayHeap));
}
#endif

void Heap_Init(u32 secondarySize)
{
    OS_InitArena();
#ifdef PC_PORT
    sPcArenaStart = (const u8 *)OS_GetMainArenaLo();
    sPcArenaEnd = (const u8 *)OS_GetMainArenaHi();
    sPcGameThread = pthread_self();
#endif

    void *secondaryPtr = OS_AllocFromMainArenaLo(secondarySize, ARENA_ALIGNMENT);
    u32 mainArenaSize = (PTR_CAST(u32, OS_GetMainArenaHi()) & ~ARENA_ALIGNMENT_MASK) - (PTR_CAST(u32, OS_GetMainArenaLo()) + ARENA_ALIGNMENT_MASK & ~ARENA_ALIGNMENT_MASK);
    void *mainPtr = OS_AllocFromMainArenaLo(mainArenaSize, ARENA_ALIGNMENT);

    sHeapHandles.secondary = NNS_FndCreateExpHeapEx(secondaryPtr, secondarySize, NNS_FND_HEAP_OPT_0_CLEAR);
    sHeapHandles.main = NNS_FndCreateExpHeapEx(mainPtr, mainArenaSize, NNS_FND_HEAP_OPT_0_CLEAR);
}

void *Heap_Alloc(size_t size)
{
    void *ptr = NNS_FndAllocFromExpHeapEx(sHeapHandles.main, size, ALLOC_ALIGNMENT);

    if (ptr != NULL) {
        return ptr;
    }

    if (sHeapHandles.overlay == NULL) {
        return ptr;
    }

    return NNS_FndAllocFromExpHeapEx(sHeapHandles.overlay, size, ALLOC_ALIGNMENT);
}

void *Heap_AllocWithAlignment(size_t size, u32 alignment)
{
    void *ptr = NNS_FndAllocFromExpHeapEx(sHeapHandles.main, size, alignment);

    if (ptr != NULL) {
        return ptr;
    }

    if (sHeapHandles.overlay == NULL) {
        return ptr;
    }

    return NNS_FndAllocFromExpHeapEx(sHeapHandles.overlay, size, alignment);
}

void Heap_Free(void *ptr)
{
#ifdef PC_PORT
    if ((u8 *)ptr < sPcOverlayHeap || (u8 *)ptr >= sPcOverlayHeap + sizeof(sPcOverlayHeap)) {
#else
    if (PTR_CAST(u32, ptr) >= PTR_CAST(u32, SDK_MAIN_ARENA_LO)) {
#endif
        NNS_FndFreeToExpHeap(sHeapHandles.main, ptr);
    } else {
        NNS_FndFreeToExpHeap(sHeapHandles.overlay, ptr);
    }
}

NNSFndHeapHandle *Heap_GetMainHandle(void)
{
    return &sHeapHandles.main;
}

void *Heap_AllocSecondary(size_t size)
{
    return NNS_FndAllocFromExpHeapEx(sHeapHandles.secondary, size, ALLOC_ALIGNMENT);
}

void Heap_FreeSecondary(void *ptr)
{
    NNS_FndFreeToExpHeap(sHeapHandles.secondary, ptr);
}

NNSFndHeapHandle *Heap_GetSecondaryHandle(void)
{
    return &sHeapHandles.secondary;
}

void Heap_InitOverlay(void *ptr, size_t size)
{
    Heap_DestroyOverlay();

    if (ptr == NULL || size == 0) {
        return;
    }

    sHeapHandles.overlay = NNS_FndCreateExpHeapEx(ptr, size, NNS_FND_HEAP_OPT_0_CLEAR);
}

void Heap_DestroyOverlay(void)
{
    if (sHeapHandles.overlay != NULL) {
        NNS_FndDestroyExpHeap(sHeapHandles.overlay);
    }

    sHeapHandles.overlay = NULL;
}
