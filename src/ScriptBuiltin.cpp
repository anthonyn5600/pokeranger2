// fsc builtin syscalls (table 0). This TU is built with the SDK 2.0/sp2 compiler (mwccarm 3.0-136, see
// src/meson.build): only that version emits sub_02046840's full 64x64 multiply.

#include <nitro.h>
#include <string.h>

#include "Log.hpp"
#include "UnkStruct_02044464.hpp"

extern "C" {
extern MATHRandContext16 MAIN_BSS_0210CEC8;

// System (ids 0x00..)

int sub_02046618(int *args, int argc)
{
    return 0;
}

int sub_02046620(int *args, int argc)
{
    sub_02044340("%s", args[0]);
    return 0;
}

int sub_0204663C(int *args, int argc)
{
    const char *fmt = (const char *)*args++;
    thunk_FUN_02044308(fmt, (va_list)args);
    return 0;
}

int sub_02046654(int *args, int argc)
{
    const char *fmt = (const char *)*args++;
    thunk_FUN_02044308(fmt, (va_list)args);
    return 0;
}

// Math (ids 0x20..)

int sub_0204666C(int *args, int argc)
{
    return FX_Mul(args[0], args[1]);
}

int sub_0204668C(int *args, int argc)
{
    return FX_Div(args[0], args[1]);
}

int sub_020466A0(int *args, int argc)
{
    return FX_SinIdx((u16)args[0]);
}

int sub_020466C4(int *args, int argc)
{
    return FX_CosIdx((u16)args[0]);
}

int sub_020466F0(int *args, int argc)
{
    return (fx32)(FX_SinFx64c(args[0]) >> 20);
}

int sub_02046708(int *args, int argc)
{
    return (fx32)(FX_CosFx64c(args[0]) >> 20);
}

int sub_02046720(int *args, int argc)
{
    return MATH_Rand16(&MAIN_BSS_0210CEC8, (u16)args[0]);
}

int sub_02046758(int *args, int argc)
{
    fx32 range = args[0];
    return FX_Mul((MATH_Rand16(&MAIN_BSS_0210CEC8, 0) & 0x7FFF) >> 3, range);
}

int sub_020467A4(int *args, int argc)
{
    fx32 range = args[0];
    return FX_Mul((MATH_Rand16(&MAIN_BSS_0210CEC8, 0) & 0x7FFF) >> 3, range) - (range >> 1);
}

int sub_020467F4(int *args, int argc)
{
    return FX_Sqrt(args[0]);
}

int sub_02046804(int *args, int argc)
{
    return FX_Inv(args[0]);
}

int sub_02046814(int *args, int argc)
{
    return FX_InvSqrt(args[0]);
}

int sub_02046824(int *args, int argc)
{
    return ((args[0] >> 6) * 0x11DE) >> 12;
}

int sub_02046840(int *args, int argc)
{
    return FX_MUL(args[0], FX32_CONST(57.3));
}

int sub_02046874(int *args, int argc)
{
    return FX_Div(args[0] << 4, 0x168000);
}

int sub_0204688C(int *args, int argc)
{
    return 0;
}

int sub_02046894(int *args, int argc)
{
    return 0;
}

int sub_0204689C(int *args, int argc)
{
    return 0;
}

int sub_020468A4(int *args, int argc)
{
    return 0;
}

int sub_020468AC(int *args, int argc)
{
    return 0;
}

int sub_020468B4(int *args, int argc)
{
    return FX_Atan(args[0]);
}

int sub_020468C4(int *args, int argc)
{
    return FX_Atan2(args[0], args[1]);
}

int sub_020468D8(int *args, int argc)
{
    return 0;
}

int sub_020468E0(int *args, int argc)
{
    return 0;
}

int sub_020468E8(int *args, int argc)
{
    return 0;
}

int sub_020468F0(int *args, int argc)
{
    return args[0] & ~(FX32_ONE - 1);
}

int sub_02046904(int *args, int argc)
{
    return MATH_ABS(args[0]);
}

int sub_02046914(int *args, int argc)
{
    return args[0] << FX32_SHIFT;
}

int sub_02046920(int *args, int argc)
{
    return args[0] >> FX32_SHIFT;
}

// String (ids 0x70..)

int sub_0204692C(int *args, int argc)
{
    if (args[0] == 0) {
        return 0;
    }
    return strlen((const char *)args[0]);
}
}

// Registered as table 0 by sub_02044440
ScriptSyscall gScriptBuiltinSyscalls[4][32] = {
    { sub_02046618, sub_02046620, sub_0204663C, sub_02046654 },
    { sub_0204666C, sub_0204668C, sub_020466F0, sub_02046708, sub_02046720, sub_020467F4, sub_02046804, sub_02046814, sub_020466A0, sub_020466C4, sub_02046758, sub_020467A4, sub_02046824, sub_02046840, sub_02046874, sub_0204688C, sub_02046894, sub_0204689C, sub_020468A4, sub_020468AC, sub_020468B4, sub_020468C4, sub_020468D8, sub_020468E0, sub_020468E8, sub_020468F0, sub_02046904, sub_02046914, sub_02046920 },
    {},
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, sub_0204692C },
};
