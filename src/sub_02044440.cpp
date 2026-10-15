#include "sub_02044440.hpp"

#include <nitro.h>

#include "ScriptVM.hpp"

extern "C" {
extern u32 MAIN_BSS_0210CED4;
}

extern ScriptSyscall gScriptBuiltinSyscalls[4][32];

void Script_InitSyscalls(void)
{
    MAIN_BSS_0210CED4 = 0;
    Script_RegisterSyscalls(0, gScriptBuiltinSyscalls[0]);
}
