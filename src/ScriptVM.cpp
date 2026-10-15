#include "ScriptVM.hpp"

#include <nitro.h>

struct ScriptGlobals {
    ScriptHeader *scripts;
    ScriptSyscall *syscalls[64];
};

extern "C" {
extern ScriptGlobals MAIN_BSS_0210CED4;
extern ScriptSyscall *MAIN_BSS_0210CED8[64];

void DecodeSymbol(const u32 *values, char *out);
void ScriptVM_Log(ScriptVM *vm, const char *fmt, ...);
ScriptSymbol *Script_FindGlobalSymbol(const u32 *key, ScriptHeader **script);
u32 *Script_FindFunction(ScriptHeader *script, const char *name);
void ScriptVM_PushCall(ScriptVM *vm, ScriptHeader *script, u32 *pc);
void thunk_FUN_020459b0(ScriptVM *vm, ScriptHeader *script, u32 *pc);
int ScriptVM_CallSync(ScriptVM *vm, ScriptHeader *script, u32 *pc, int argc);
}

union ScriptInsn {
    u32 word;
    struct {
        u8 op;
        u8 sub;
        s16 arg;
    };
};

static inline BOOL SymbolKeyEquals(const u32 *a, const u32 *b)
{
    return a[0] == b[0] && a[1] == b[1];
}

// fsc symbol characters: '\0' 0-9 A-Z _ - / map to 0..39 (lower case as upper case)
static inline int GetSymbolCode(char c)
{
    return (c >= '0' && c <= '9') ? c - '0' + 1
        : (c >= 'A' && c <= 'Z')  ? c - 'A' + 11
        : (c >= 'a' && c <= 'z')  ? c - 'a' + 11
        : (c == '_')              ? 37
        : (c == '-')              ? 38
        : (c == '/')              ? 39
                                  : 0;
}

#define ENCODE_SYMBOL_CHAR(code, name) \
    (code) = GetSymbolCode(*(name));   \
    if ((code) != 0) {                 \
        (name)++;                      \
    }

#define ENCODE_SYMBOL_WORD(v, code, name) \
    ENCODE_SYMBOL_CHAR(code, name);       \
    (v) = (code);                         \
    (v) *= 40;                            \
    ENCODE_SYMBOL_CHAR(code, name);       \
    (v) += (code);                        \
    (v) *= 40;                            \
    ENCODE_SYMBOL_CHAR(code, name);       \
    (v) += (code);                        \
    (v) *= 40;                            \
    ENCODE_SYMBOL_CHAR(code, name);       \
    (v) += (code);                        \
    (v) *= 40;                            \
    ENCODE_SYMBOL_CHAR(code, name);       \
    (v) += (code);                        \
    (v) *= 40;                            \
    ENCODE_SYMBOL_CHAR(code, name);       \
    (v) += (code);

// name packed into two base-40 words, 6 characters each. The walker is a local copy (not the parameter) and the
// classifier a ?: expression: both decide the register allocation of the three expansions.
static inline void EncodeSymbol(u32 *key, const char *name)
{
    const char *s = name;
    int code;
    u32 v;
    ENCODE_SYMBOL_WORD(v, code, s);
    *key++ = v;
    ENCODE_SYMBOL_WORD(v, code, s);
    *key = v;
}

extern "C" {

ScriptSymbol *Script_FindSymbol(ScriptHeader *script, const u32 *key)
{
    // the symbol table ends where the imports start; re-read every iteration
    for (ScriptSymbol *sym = script->symbols; sym < (ScriptSymbol *)((void **)script)[2]; sym++) {
        if (SymbolKeyEquals(key, sym->key)) {
            return sym;
        }
    }
    return NULL;
}

ScriptSymbol *Script_FindGlobalSymbol(const u32 *key, ScriptHeader **script)
{
    for (ScriptHeader *s = MAIN_BSS_0210CED4.scripts; s != NULL; s = s->next) {
        ScriptSymbol *sym = Script_FindSymbol(s, key);
        if (sym != NULL) {
            if (script != NULL) {
                *script = s;
            }
            return sym;
        }
    }
    return NULL;
}

u32 *Script_FindFunction(ScriptHeader *script, const char *name)
{
    u32 key[2];
    EncodeSymbol(key, name);
    ScriptSymbol *sym = Script_FindSymbol(script, key);
    if (sym != NULL) {
        return sym->code;
    }
    return NULL;
}

void Script_Link(void *data)
{
    ScriptHeader *script = (ScriptHeader *)data;
    if (script == NULL) {
        return;
    }
#ifdef PC_PORT
    // The header fields are 32-bit offsets from the file start (see PTR32)
    u32 base = PTR_CAST(u32, script);
    script->code.bits += base;
    script->symbols.bits += base;
    script->imports.bits += base;
    script->data.bits += base;
    script->next = NULL;
    for (ScriptSymbol *sym = script->symbols; sym < (ScriptSymbol *)(ScriptImport *)script->imports; sym++) {
        sym->code.bits = base + sym->code.bits * sizeof(u32);
    }
#else
    script->code = (u32 *)((u32)script->code + (u32)script);
    script->symbols = (ScriptSymbol *)((u32)script->symbols + (u32)script);
    script->imports = (ScriptImport *)((u32)script->imports + (u32)script);
    script->data = (u8 *)((u32)script->data + (u32)script);
    script->next = NULL;
    for (ScriptSymbol *sym = script->symbols; sym < (ScriptSymbol *)script->imports; sym++) {
        sym->code = (u32 *)script + (u32)sym->code;
    }
#endif
}

void Script_RegisterSyscalls(u32 id, ScriptSyscall *handlers)
{
    MAIN_BSS_0210CED8[id] = handlers;
}

void ScriptVM_Init(ScriptVM *vm, void *stack, u32 stackSize)
{
    vm->unk_04 = NULL;
    vm->unk_08 = NULL;
    vm->unk_0C = NULL;
    vm->unk_10 = 0;
    vm->unk_14 = NULL;
    vm->unk_20 = 0;
    vm->unk_18 = stackSize;
    vm->unk_1C = (u32 *)stack;
    ScriptVM_Reset(vm);
}

void ScriptVM_Clear(ScriptVM *vm)
{
    ScriptVM_Reset(vm);
}

void ScriptVM_Reset(ScriptVM *vm)
{
    vm->unk_00 = NULL;
    vm->unk_04 = vm->unk_1C + vm->unk_18;
    vm->unk_08 = vm->unk_1C;
    vm->unk_20 = 0;
}

struct ScriptLogArgs {
    const char *fmt;
    va_list args;
};

void ScriptVM_Log(ScriptVM *vm, const char *fmt, ...)
{
    ScriptLogArgs log;
    log.fmt = fmt;
#ifdef PC_PORT
    va_start(log.args, fmt);
    if (MAIN_BSS_0210CED4.syscalls[0] != NULL) {
        MAIN_BSS_0210CED4.syscalls[0][2]((int *)&log, 1);
    }
    va_end(log.args);
#else
    // va_start without MSL's alignment of the parameter address
    log.args = (va_list)(&fmt + 1);
    if (MAIN_BSS_0210CED4.syscalls[0] == NULL) {
        return;
    }
    MAIN_BSS_0210CED4.syscalls[0][2]((int *)&log, 1);
#endif
}

ScriptImport *ScriptVM_ResolveImport(ScriptVM *vm, int index)
{
    ScriptImport *import = &vm->unk_14->imports[index];
    if (import->symbol != NULL) {
        return import;
    }
    ScriptHeader *script;
    u32 key[2];
    key[0] = import->key[0];
    key[1] = import->key[1];
    ScriptSymbol *sym = Script_FindGlobalSymbol(key, &script);
    if (sym != NULL) {
        import->symbol = sym;
        import->script = script;
        return import;
    }
    char name[16];
    DecodeSymbol(key, name);
    ScriptVM_Log(vm, "fsc:symbol not found %s\n", name);
    return NULL;
}

static inline u32 Pop(ScriptVM *vm)
{
    return *vm->unk_04++;
}

static inline void Push(ScriptVM *vm, u32 value)
{
    *--vm->unk_04 = value;
}

static inline void RPush(ScriptVM *vm, u32 value)
{
    *vm->unk_08++ = value;
}

#define POP(vm)      Pop(vm)
#define PUSH(vm, v)  Push(vm, (u32)(v))
#define RPUSH(vm, v) RPush(vm, PTR_CAST(u32, (v)))

int ScriptVM_Run(ScriptVM *vm, u32 steps)
{
    if (vm->unk_20 != 0) {
        vm->unk_20--;
        return 0x10;
    }
    while (steps-- != 0) {
        if (vm->unk_00 == NULL) {
            return 2;
        }
        ScriptInsn insn;
        insn.word = *vm->unk_00++;
        switch (insn.op) {
        case 2:
            switch (insn.sub) {
            case 0:
                vm->unk_20 = insn.arg;
                return 4;
            case 1:
                return 1;
            case 2:
                ScriptVM_Reset(vm);
                break;
            case 3:
                vm->unk_20 = POP(vm);
                return 4;
            case 4:
                if (POP(vm) != 0) {
                    vm->unk_20 = POP(vm) - 1;
                    return 4;
                }
                break;
            }
            break;
        case 8:
            switch (insn.sub) {
            case 1:
                if (POP(vm) != 0) {
                    vm->unk_00 += insn.arg;
                }
                break;
            case 2:
                if (POP(vm) == 0) {
                    vm->unk_00 += insn.arg;
                }
                break;
            case 3:
                if (POP(vm) != 0) {
                    vm->unk_00 += insn.arg;
                    return 4;
                }
                break;
            case 4:
                if (POP(vm) == 0) {
                    vm->unk_00 += insn.arg;
                    return 4;
                }
                break;
            case 5:
                if (POP(vm) != 0) {
                    vm->unk_00 += insn.arg;
                    PUSH(vm, 1);
                }
                break;
            case 6:
                if (POP(vm) == 0) {
                    vm->unk_00 += insn.arg;
                    PUSH(vm, 0);
                }
                break;
            case 7:
                if (vm->unk_04[0] == vm->unk_04[1]) {
                    vm->unk_00 += insn.arg;
                    vm->unk_04 += 2;
                } else {
                    vm->unk_04 += 1;
                }
                break;
            case 0:
            default:
                vm->unk_00 += insn.arg;
                break;
            }
            break;
        case 10:
            if (insn.sub == *vm->unk_04) {
                vm->unk_00 += insn.arg;
                vm->unk_04++;
            }
            break;
        case 1: {
            int id = insn.arg & 0x3FF;
            int page = (insn.arg >> 10) & 0x3F;
            int argc = insn.sub;
            ScriptSyscall *table = MAIN_BSS_0210CED8[page];
            if (table == NULL) {
                ScriptVM_Log(vm, "fsc:undef syscall page=%d\n", page);
            } else if (table[id] == NULL) {
                ScriptVM_Log(vm, "fsc:undef syscall function page=%d id=%x\n", page, id);
            } else {
                vm->unk_10 = table[id]((int *)vm->unk_04, argc);
            }
            if (vm->unk_00 != NULL) {
                vm->unk_04 += argc;
                steps++;
            }
            break;
        }
        case 4: {
            int offset = *vm->unk_00++;
            RPUSH(vm, vm->unk_00);
            RPUSH(vm, vm->unk_0C);
            RPUSH(vm, vm->unk_14);
            vm->unk_0C = vm->unk_04;
            vm->unk_00 += offset;
            break;
        }
        case 3:
            RPUSH(vm, vm->unk_00);
            RPUSH(vm, vm->unk_0C);
            RPUSH(vm, vm->unk_14);
            vm->unk_0C = vm->unk_04;
            vm->unk_00 += insn.arg;
            break;
        case 5: {
            ScriptImport *import = ScriptVM_ResolveImport(vm, insn.arg);
            if (import != NULL) {
                RPUSH(vm, vm->unk_00);
                RPUSH(vm, vm->unk_0C);
                RPUSH(vm, vm->unk_14);
                vm->unk_00 = import->symbol->code;
                vm->unk_14 = import->script;
                vm->unk_0C = vm->unk_04;
            }
            break;
        }
        case 6:
            vm->unk_14 = (ScriptHeader *)*--vm->unk_08;
            vm->unk_0C = (u32 *)*--vm->unk_08;
            vm->unk_00 = (u32 *)*--vm->unk_08;
            if (insn.sub != 0) {
                steps++;
                vm->unk_10 = POP(vm);
            }
            vm->unk_04 += insn.arg;
            break;
        case 7:
            vm->unk_04 -= insn.arg;
            break;
        case 15:
            vm->unk_04 += insn.arg;
            break;
        case 13: {
            u32 v = vm->unk_04[insn.arg];
            PUSH(vm, v);
            break;
        }
        case 11:
            PUSH(vm, vm->unk_0C[insn.arg]);
            break;
        case 12:
            switch (insn.sub) {
            case 0:
                vm->unk_0C[insn.arg] = POP(vm);
                break;
            case 1:
                vm->unk_0C[insn.arg] += POP(vm);
                break;
            case 2:
                vm->unk_0C[insn.arg] -= POP(vm);
                break;
            }
            break;
        case 16:
            PUSH(vm, insn.arg);
            break;
        case 17: {
            u32 v = *vm->unk_00++;
            PUSH(vm, v);
            break;
        }
        case 25:
            *--vm->unk_04 = PTR_CAST(u32, (vm->unk_00 + ((int)insn.word >> 8)));
            break;
        case 26: {
            int index = 0;
            int size = insn.arg;
            if (insn.sub & 0x10) {
                index = size * (int)POP(vm);
            }
            u32 addr = POP(vm);
            switch (size) {
            default:
                *--vm->unk_04 = *(int *)(index + addr);
                break;
            case 2:
                *--vm->unk_04 = *(s16 *)(index + addr);
                break;
            case 1:
                *--vm->unk_04 = *(s8 *)(index + addr);
                break;
            }
            break;
        }
        case 27: {
            int index = 0;
            int size = insn.arg;
            if (insn.sub & 0x10) {
                index = size * (int)POP(vm);
            }
            u32 addr = POP(vm);
            int value = POP(vm);
            switch (insn.sub & 0xF) {
            case 0:
                switch (size) {
                case 4:
                    *(int *)(index + addr) = value;
                    break;
                case 2:
                    *(s16 *)(index + addr) = value;
                    break;
                case 1:
                    *(s8 *)(index + addr) = value;
                    break;
                }
                break;
            case 1:
                switch (size) {
                case 4:
                    *(int *)(index + addr) += value;
                    break;
                case 2:
                    *(s16 *)(index + addr) += value;
                    break;
                case 1:
                    *(s8 *)(index + addr) += value;
                    break;
                }
                break;
            case 2:
                switch (size) {
                case 4:
                    *(int *)(index + addr) -= value;
                    break;
                case 2:
                    *(s16 *)(index + addr) -= value;
                    break;
                case 1:
                    *(s8 *)(index + addr) -= value;
                    break;
                }
                break;
            }
            break;
        }
        case 18:
            *--vm->unk_04 = vm->unk_10;
            break;
        case 19:
            *--vm->unk_04 = PTR_CAST(u32, (vm->unk_14->data + ((int)insn.word >> 8)));
            break;
        case 20:
            switch (insn.arg) {
            case 0:
            default: {
                int r = ((int *)vm->unk_04)[1] + ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 2: {
                int r = ((int *)vm->unk_04)[1] * ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 1: {
                int r = ((int *)vm->unk_04)[1] - ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 3: {
                int r = ((int *)vm->unk_04)[1] / ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 4: {
                int r = ((int *)vm->unk_04)[1] % ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 5: {
                int r = ((int *)vm->unk_04)[1] & ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 6: {
                int r = ((int *)vm->unk_04)[1] | ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 7: {
                int r = ((int *)vm->unk_04)[1] ^ ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 8:
                *vm->unk_04 = ~*vm->unk_04;
                break;
            case 9:
                *vm->unk_04 = !*vm->unk_04;
                break;
            case 10:
                *vm->unk_04 = -*vm->unk_04;
                break;
            }
            break;
        case 21:
            ScriptVM_Log(vm, "fsc:float operator not imprement\n");
            break;
        case 22:
            switch (insn.arg) {
            case 11:
            default: {
                int r = ((int *)vm->unk_04)[1] == ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 12: {
                int r = ((int *)vm->unk_04)[1] != ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 13: {
                int r = ((int *)vm->unk_04)[1] > ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 14: {
                int r = ((int *)vm->unk_04)[1] < ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 15: {
                int r = ((int *)vm->unk_04)[1] >= ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 16: {
                int r = ((int *)vm->unk_04)[1] <= ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            }
            break;
        case 23:
            ScriptVM_Log(vm, "fsc:float operator not imprement\n");
            break;
        case 24:
            switch (insn.arg) {
            case 0:
            default: {
                int r = ((int *)vm->unk_04)[1] << ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 1: {
                int r = ((int *)vm->unk_04)[1] >> ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            case 2: {
                int r = ((u32 *)vm->unk_04)[1] >> ((int *)vm->unk_04)[0];
                vm->unk_04++;
                *vm->unk_04 = r;
            } break;
            }
            break;
        case 28:
            ScriptVM_Log(vm, "fsc:float operator not imprement\n");
            break;
        case 0:
            break;
        default:
            ScriptVM_Log(vm, "fsc:unknown opcode %x\n", insn.word);
            return 1;
        }
        if (PTR_CAST(int, vm->unk_04) <= PTR_CAST(int, vm->unk_08)) {
            ScriptVM_Log(vm, "fsc:stack overflow stacksize=%d\n", vm->unk_18);
        }
    }
    return 8;
}

void ScriptVM_PushCall(ScriptVM *vm, ScriptHeader *script, u32 *pc)
{
    RPUSH(vm, vm->unk_00);
    RPUSH(vm, vm->unk_0C);
    RPUSH(vm, vm->unk_14);
    vm->unk_20 = 0;
    vm->unk_0C = vm->unk_04;
    vm->unk_14 = script;
    vm->unk_00 = pc;
}

void thunk_FUN_020459b0(ScriptVM *vm, ScriptHeader *script, u32 *pc)
{
    ScriptVM_PushCall(vm, script, pc);
}

int ScriptVM_Start(ScriptVM *vm, void *script, const char *name)
{
    u32 key[2];
    EncodeSymbol(key, name);
    u32 *pc = Script_FindFunction((ScriptHeader *)script, name);
    if (pc == NULL) {
        return 0;
    }
    thunk_FUN_020459b0(vm, (ScriptHeader *)script, pc);
    return 1;
}

int ScriptVM_CallSync(ScriptVM *vm, ScriptHeader *script, u32 *pc, int argc)
{
    u32 *ret = vm->unk_00;
    int wait = vm->unk_20;
    ScriptVM_PushCall(vm, script, pc);
    while (vm->unk_00 != ret) {
        if (ScriptVM_Run(vm, 1) & 3) {
            return -2;
        }
    }
    vm->unk_20 = wait;
    return vm->unk_10;
}

int ScriptVM_CallFunction(ScriptVM *vm, void *script, const char *name, int argc)
{
    u32 key[2];
    EncodeSymbol(key, name);
    u32 *pc = Script_FindFunction((ScriptHeader *)script, name);
    if (pc == NULL) {
        return -1;
    }
    return ScriptVM_CallSync(vm, (ScriptHeader *)script, pc, argc);
}
}
