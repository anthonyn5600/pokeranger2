// NitroSDK libcrypto allocator hook: built with the crypto TUs (SDK 1.2 compiler, see meson.build), which addresses
// each global through its own literal instead of pooling them

#include "sub_02046D40.hpp"

extern "C" {
HeapAllocFunc sHeapAllocFunc;
HeapFreeFunc sHeapFreeFunc;
}

void CRYPTO_SetAllocator(HeapAllocFunc allocFunc, HeapFreeFunc freeFunc)
{
    sHeapAllocFunc = allocFunc;
    sHeapFreeFunc = freeFunc;
}
