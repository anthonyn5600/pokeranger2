#include "UnkClass_02008E88.hpp"

#include <nitro.h>

UnkClass_02008E88::UnkClass_02008E88()
{
    unk_48 = 0;
    unk_4A = 0;
    unk_4C = 0;
    unk_4E = 0;
    unk_50 = 0;
    unk_54 = 1;
    unk_00 = NULL;
    unk_04 = NULL;
    unk_58 = NULL;
    unk_5C = NULL;
    unk_60 = NULL;
    for (int i = 0; i < 16; i++) {
        unk_08[i] = 0;
    }
}

UnkClass_02008E88::~UnkClass_02008E88()
{
}

void UnkClass_02008E88::sub_02008EDC()
{
    if (&sub_02008F90()->unk_00 != this) {
        UnkClass_02008E88 *parent = unk_58;
        UnkClass_02008E88 *child = parent->sub_02008F80();
        SAFE_DELETE(child);
        parent->sub_02008F78(NULL);
        parent->unk_50 = 1;
        sub_02008F90()->sub_0200911C(parent);
    }
    if (&sub_02008F90()->unk_00 == this) {
        sub_02008F98()->sub_020028A4(0, 0, "");
    }
    sub_02008F90()->sub_02009124(1);
}

void UnkClass_02008E88::sub_02008F78(UnkClass_02008E88 *child)
{
    unk_5C = child;
}

UnkClass_02008E88 *UnkClass_02008E88::sub_02008F80()
{
    return unk_5C;
}

void UnkClass_02008E88::sub_02008F88(UnkClass_02008FA8 *manager)
{
    unk_60 = manager;
}

UnkClass_02008FA8 *UnkClass_02008E88::sub_02008F90()
{
    return unk_60;
}

UnkClass_020023EC *UnkClass_02008E88::sub_02008F98()
{
    return sub_02008F90()->sub_02009100();
}

UnkClass_02008FA8::UnkClass_02008FA8(UnkClass_020023EC *printer, u32 arg1)
{
    unk_68 = printer;
    unk_6C = arg1;
    unk_00.sub_02008F78(NULL);
    unk_00.sub_02008F88(this);
    unk_64 = &unk_00;
    for (int i = 0; i < 16; i++) {
        unk_74[i] = 0;
    }
}

UnkClass_02008FA8::~UnkClass_02008FA8()
{
    sub_02009020();
}

void UnkClass_02008FA8::sub_02009020()
{
    while (&unk_00 != unk_64) {
        unk_64->sub_02008EDC();
    }
    unk_70 = 1;
}

void UnkClass_02008FA8::sub_02009050()
{
    if (!sub_02009108()) {
        return;
    }
    if (unk_64->unk_04 != NULL) {
        unk_70 |= unk_64->unk_04(unk_64);
    }
    sub_02009090();
}

void UnkClass_02008FA8::sub_02009090()
{
    if (unk_70 == 0) {
        return;
    }
    UnkClass_02008E88 *process = unk_00.sub_02008F80();
    while (process != NULL) {
        if (unk_64->unk_00 != NULL) {
            process->unk_00(process);
        }
        process = process->sub_02008F80();
    }
    unk_70 = 0;
}

void UnkClass_02008FA8::sub_020090E8(int index, u32 value)
{
    unk_74[index] = value;
}

u32 UnkClass_02008FA8::sub_020090F4(int index)
{
    return unk_74[index];
}

UnkClass_020023EC *UnkClass_02008FA8::sub_02009100()
{
    return unk_68;
}

BOOL UnkClass_02008FA8::sub_02009108()
{
    return &unk_00 != unk_64;
}

void UnkClass_02008FA8::sub_0200911C(UnkClass_02008E88 *process)
{
    unk_64 = process;
}

void UnkClass_02008FA8::sub_02009124(u16 flags)
{
    unk_70 = flags;
}
