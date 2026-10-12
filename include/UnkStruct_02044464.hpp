#ifndef POKERANGER2_UNKSTRUCT_02044464_HPP
#define POKERANGER2_UNKSTRUCT_02044464_HPP

#include <nitro.h>

#include "common.hpp"

// Script interpreter state (arm9, around 0x02044464), embedded in CFieldMap and CFieldActorScript.
struct UnkStruct_02044464 {
    u32 unk_00;
    u32 *unk_04; // stack pointer
    u8 unk_08[0x1C];
};

STATIC_SIZE_ASSERT(UnkStruct_02044464, 0x24);

extern "C" {
void sub_02044AC8(void *script);
void sub_02044B38(u32 id, u32 *handlers);
void sub_02044B48(UnkStruct_02044464 *vm, void *stack, u32 stackSize);
void sub_02044B78(UnkStruct_02044464 *vm);
void sub_02044B84(UnkStruct_02044464 *vm);
int sub_02044C9C(UnkStruct_02044464 *vm, u32 steps);
int sub_02045A18(UnkStruct_02044464 *vm, void *script, const char *name);
int sub_02046040(UnkStruct_02044464 *vm, void *script, const char *name, int argc);
}

#endif // POKERANGER2_UNKSTRUCT_02044464_HPP
