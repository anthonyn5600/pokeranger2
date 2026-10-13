#include "sub_02044440.hpp"

#include <nitro.h>

#include "UnkStruct_02044464.hpp"

extern "C" {
extern u32 MAIN_BSS_0210CED4;
}

extern ScriptSyscall gScriptBuiltinSyscalls[4][32];

void sub_02044440(void)
{
    MAIN_BSS_0210CED4 = 0;
    sub_02044B38(0, gScriptBuiltinSyscalls[0]);
}
