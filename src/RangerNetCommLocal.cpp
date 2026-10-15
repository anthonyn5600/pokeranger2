#include "common.hpp"

// Per-comm-type limits of the Ranger Net packet layer (0212CE10..0212CE58); pokeplatinum unk_0203266C.c (CommLocal)

u16 CommLocal_MaxMachines(u16 type)
{
    u8 maxMachines[] = { 1, 1, 1, 1, 3, 3, 3, 4, 3, 4, 7, 3, 7, 4, 1, 1, 1, 1, 4, 1, 1, 1, 1, 1, 0, 0 };
    return maxMachines[type];
}

// Never called (mwld strips it); its table template stays in .rodata (pokeplatinum sub_02032698)
u16 ov11_RangerNetCommLocalUnused(u16 type)
{
    u8 table[] = { 1, 1, 1, 1, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 };
    return table[type];
}
