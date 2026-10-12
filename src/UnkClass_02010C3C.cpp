#include "UnkClass_02010C3C.hpp"

UnkStruct_02010C3C MAIN_BSS_020AF35C;
UnkStruct_02010C3C MAIN_BSS_020AF3CE[4];

UnkClass_02010C3C::UnkClass_02010C3C()
{
    sub_02010C50(this);
}

extern "C" {

void sub_02010C50(UnkClass_02010C3C *obj)
{
    sub_02010C94(obj, &MAIN_BSS_020AF35C);
    for (u8 i = 0; i < 4; i++) {
        sub_02010C94(obj, &MAIN_BSS_020AF3CE[i]);
    }
}

void sub_02010C94(UnkClass_02010C3C *obj, UnkStruct_02010C3C *entry)
{
    MI_CpuClear8(entry, sizeof(UnkStruct_02010C3C));
    entry->unk_4C = 1;
    entry->unk_6C = 1;
    entry->unk_6E = 1;
}

UnkStruct_02010C3C *sub_02010CC0(void)
{
    return MAIN_BSS_020AF3CE;
}
}
