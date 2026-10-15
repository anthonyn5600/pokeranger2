#ifndef POKERANGER2_SUB_02046D40_HPP
#define POKERANGER2_SUB_02046D40_HPP

#include <nitro/types.h>

#ifdef PC_PORT
typedef void *(*HeapAllocFunc)(size_t);
#else
typedef void *(*HeapAllocFunc)(u32);
#endif
typedef void (*HeapFreeFunc)(void *);

void CRYPTO_SetAllocator(HeapAllocFunc, HeapFreeFunc);

#endif // POKERANGER2_SUB_02046D40_HPP
