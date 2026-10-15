#ifndef POKERANGER2_FX_UTILS_HPP
#define POKERANGER2_FX_UTILS_HPP

#include <nitro.h>

#define FX32_MUL(a, b) (fx32)(((fx64)(a) * (b)) >> FX32_SHIFT)
#ifdef PC_PORT
// The DS runtime's 64-bit division (_ll_sdiv) returns the dividend when dividing by 0; x86 would trap
inline fx64 PcLlDiv(fx64 numer, fx64 denom)
{
    return denom == 0 ? numer : numer / denom;
}
#define FX32_DIV(a, b) (fx32) PcLlDiv((fx64)(a) << FX32_SHIFT, (b))
#else
#define FX32_DIV(a, b) (fx32)(((fx64)(a) << FX32_SHIFT) / (b))
#endif

#define FX32_POW2(a) FX32_MUL(a, a)
#define FX32_POW3(a) FX32_MUL(FX32_POW2(a), a)

inline fx32 FX32_RoundUp(fx32 x, fx32 base)
{
    return (x + base) & ~base;
}

#endif // POKERANGER2_FX_UTILS_HPP
