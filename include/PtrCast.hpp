#ifndef POKERANGER2_PTRCAST_HPP
#define POKERANGER2_PTRCAST_HPP

// Pointers the game keeps in 32-bit integers (script values, u32 fields, address arithmetic).
//
// PTR_CAST(type, x): x is a pointer (or a value that may hold one, like a script value) stored as `type`.
// PTR_BITS(type, x): x is a number carried in a pointer type (OSMessage payloads, callback arguments).
// PTR32(T): a T * field of a structure laid over file data (stays 4 bytes on PC).
//
// On the DS they are the plain cast / pointer. The PC port links the game below 2 GB (non-PIE; libntr's main memory, which
// holds every game heap, is a static array), so keeping a pointer in an int stays lossless there; PTR_CAST stops the
// game if a pointer ever lies above that.
#ifdef PC_PORT
#include <nitro/types.h>
#include <stdint.h>

u32 PcPtrToU32(const volatile void *ptr);

template <class T>
inline T PcPtrBits(T value)
{
    return value; // integers pass through unchanged
}

template <class T>
inline u32 PcPtrBits(T *ptr)
{
    return PcPtrToU32((const volatile void *)ptr);
}

template <class R, class... A>
inline u32 PcPtrBits(R (*func)(A...))
{
    return PcPtrToU32((const volatile void *)func);
}

#define PTR_CAST(type, x) ((type)PcPtrBits(x))
#define PTR_BITS(type, x) ((type)(intptr_t)(x))

// A 32-bit pointer field of a structure that lies over file data (4 bytes, as on the DS); behaves like a T *.
template <class T>
struct Ptr32 {
    u32 bits;

    operator T *() const
    {
        return (T *)(uintptr_t)bits;
    }
    T *operator->() const
    {
        return (T *)(uintptr_t)bits;
    }
    Ptr32 &operator=(T *ptr)
    {
        bits = PcPtrToU32((const volatile void *)ptr);
        return *this;
    }
};

#define PTR32(T) Ptr32<T>
#else
#define PTR_CAST(type, x) ((type)(x))
#define PTR_BITS(type, x) ((type)(x))
#define PTR32(T)          T *
#endif

#endif // POKERANGER2_PTRCAST_HPP
