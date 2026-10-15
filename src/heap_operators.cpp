#include <nitro.h>

#include "heap.hpp"

#ifdef PC_PORT
#include <stdlib.h>

// libntr's C++ code (SDL/ImGui setup before NitroMain, its helper threads) also comes here: it gets host memory.
// pc/exe.map keeps these out of the dynamic symbol table, so shared libraries keep the standard operators.
void *operator new(size_t size)
{
    return Heap_IsReadyPc() ? Heap_Alloc(size) : malloc(size);
}

void *operator new[](size_t size)
{
    return Heap_IsReadyPc() ? Heap_Alloc(size) : malloc(size);
}

void operator delete(void *ptr) noexcept
{
    if (Heap_OwnsPc(ptr)) {
        Heap_Free(ptr);
    } else {
        free(ptr);
    }
}

void operator delete[](void *ptr) noexcept
{
    operator delete(ptr);
}

void operator delete(void *ptr, size_t) noexcept
{
    operator delete(ptr);
}

void operator delete[](void *ptr, size_t) noexcept
{
    operator delete(ptr);
}
#else
void *operator new(size_t size)
{
    return Heap_Alloc(size);
}

void *operator new[](size_t size)
{
    return Heap_Alloc(size);
}

void operator delete(void *ptr)
{
    Heap_Free(ptr);
}

void operator delete[](void *ptr)
{
    Heap_Free(ptr);
}
#endif
