#ifndef POKERANGER2_UNKSTRUCT_02044464_HPP
#define POKERANGER2_UNKSTRUCT_02044464_HPP

#include <nitro.h>

#include "common.hpp"

typedef int (*ScriptSyscall)(int *args, int argc);

// fsc symbol: name packed into two base-40 words, then the code address (a word index until relocated)
struct ScriptSymbol {
    u32 key[2];
    u32 *code;
};

// fsc import: a symbol of another loaded script, resolved on first call
struct ScriptImport {
    u32 key[2];
    struct ScriptHeader *script;
    ScriptSymbol *symbol;
};

// Loaded .fsb file header (offsets relocated to pointers by Script_Link)
struct ScriptHeader {
    u32 *code;
    ScriptSymbol *symbols; // up to imports
    ScriptImport *imports;
    u8 *data;
    ScriptHeader *next;
};

// Script interpreter state (arm9, around 0x02044464), embedded in CFieldMap and CFieldActorScript.
struct UnkStruct_02044464 {
    u32 *unk_00; // program counter
    u32 *unk_04; // stack pointer (grows down)
    u32 *unk_08; // call stack pointer (grows up from the stack base)
    u32 *unk_0C; // frame pointer
    int unk_10; // last syscall/return value
    ScriptHeader *unk_14; // current script
    u32 unk_18; // stack size in words
    u32 *unk_1C; // stack base
    int unk_20; // wait counter
};

STATIC_SIZE_ASSERT(UnkStruct_02044464, 0x24);

extern "C" {
void Script_Link(void *script);
void Script_RegisterSyscalls(u32 id, ScriptSyscall *handlers);
void ScriptVM_Init(UnkStruct_02044464 *vm, void *stack, u32 stackSize);
void ScriptVM_Clear(UnkStruct_02044464 *vm);
void ScriptVM_Reset(UnkStruct_02044464 *vm);
int ScriptVM_Run(UnkStruct_02044464 *vm, u32 steps);
int ScriptVM_Start(UnkStruct_02044464 *vm, void *script, const char *name);
int ScriptVM_CallFunction(UnkStruct_02044464 *vm, void *script, const char *name, int argc);
}

#endif // POKERANGER2_UNKSTRUCT_02044464_HPP
