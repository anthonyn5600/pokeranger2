// fsc builtin syscalls (table 0). This TU is built with the SDK 2.0/sp2 compiler (mwccarm 3.0-136, see
// src/meson.build): only that version emits Builtin_RadToDeg's full 64x64 multiply.

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

int Builtin_Puts(int *args, int argc)
{
    Log_Println("%s", args[0]);
    return 0;
}

int Builtin_Printf(int *args, int argc)
{
    const char *fmt = (const char *)*args++;
    thunk_FUN_02044308(fmt, (va_list)args);
    return 0;
}

int Builtin_Printf2(int *args, int argc)
{
    const char *fmt = (const char *)*args++;
    thunk_FUN_02044308(fmt, (va_list)args);
    return 0;
}

// Math (ids 0x20..)

int Builtin_FxMul(int *args, int argc)
{
    return FX_Mul(args[0], args[1]);
}

int Builtin_FxDiv(int *args, int argc)
{
    return FX_Div(args[0], args[1]);
}

int Builtin_SinIdx(int *args, int argc)
{
    return FX_SinIdx((u16)args[0]);
}

int Builtin_CosIdx(int *args, int argc)
{
    return FX_CosIdx((u16)args[0]);
}

int Builtin_Sin(int *args, int argc)
{
    return (fx32)(FX_SinFx64c(args[0]) >> 20);
}

int Builtin_Cos(int *args, int argc)
{
    return (fx32)(FX_CosFx64c(args[0]) >> 20);
}

int Builtin_Rand(int *args, int argc)
{
    return MATH_Rand16(&MAIN_BSS_0210CEC8, (u16)args[0]);
}

int Builtin_RandFx(int *args, int argc)
{
    fx32 range = args[0];
    return FX_Mul((MATH_Rand16(&MAIN_BSS_0210CEC8, 0) & 0x7FFF) >> 3, range);
}

int Builtin_RandFxSigned(int *args, int argc)
{
    fx32 range = args[0];
    return FX_Mul((MATH_Rand16(&MAIN_BSS_0210CEC8, 0) & 0x7FFF) >> 3, range) - (range >> 1);
}

int Builtin_Sqrt(int *args, int argc)
{
    return FX_Sqrt(args[0]);
}

int Builtin_Inv(int *args, int argc)
{
    return FX_Inv(args[0]);
}

int Builtin_InvSqrt(int *args, int argc)
{
    return FX_InvSqrt(args[0]);
}

int Builtin_DegToRad(int *args, int argc)
{
    return ((args[0] >> 6) * 0x11DE) >> 12;
}

int Builtin_RadToDeg(int *args, int argc)
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

int Builtin_Atan(int *args, int argc)
{
    return FX_Atan(args[0]);
}

int Builtin_Atan2(int *args, int argc)
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

int Builtin_Floor(int *args, int argc)
{
    return args[0] & ~(FX32_ONE - 1);
}

int Builtin_Abs(int *args, int argc)
{
    return MATH_ABS(args[0]);
}

int Builtin_IntToFx(int *args, int argc)
{
    return args[0] << FX32_SHIFT;
}

int Builtin_FxToInt(int *args, int argc)
{
    return args[0] >> FX32_SHIFT;
}

// String (ids 0x70..)

int Builtin_Strlen(int *args, int argc)
{
    if (args[0] == 0) {
        return 0;
    }
    return strlen((const char *)args[0]);
}
}

// Registered as table 0 by Script_InitSyscalls
ScriptSyscall gScriptBuiltinSyscalls[4][32] = {
    { sub_02046618, Builtin_Puts, Builtin_Printf, Builtin_Printf2 },
    { Builtin_FxMul, Builtin_FxDiv, Builtin_Sin, Builtin_Cos, Builtin_Rand, Builtin_Sqrt, Builtin_Inv, Builtin_InvSqrt, Builtin_SinIdx, Builtin_CosIdx, Builtin_RandFx, Builtin_RandFxSigned, Builtin_DegToRad, Builtin_RadToDeg, sub_02046874, sub_0204688C, sub_02046894, sub_0204689C, sub_020468A4, sub_020468AC, Builtin_Atan, Builtin_Atan2, sub_020468D8, sub_020468E0, sub_020468E8, Builtin_Floor, Builtin_Abs, Builtin_IntToFx, Builtin_FxToInt },
    {},
    { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, Builtin_Strlen },
};
