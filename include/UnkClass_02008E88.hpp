#ifndef POKERANGER2_UNKCLASS_02008E88_HPP
#define POKERANGER2_UNKCLASS_02008E88_HPP

#include <nitro.h>

#include "UnkClass_020023EC.hpp"
#include "common.hpp"

class UnkClass_02008FA8;

class UnkClass_02008E88 {
public:
    UnkClass_02008E88();
    ~UnkClass_02008E88();

    void sub_02008EDC();
    void sub_02008F78(UnkClass_02008E88 *child);
    UnkClass_02008E88 *sub_02008F80();
    void sub_02008F88(UnkClass_02008FA8 *manager);
    UnkClass_02008FA8 *sub_02008F90();
    UnkClass_020023EC *sub_02008F98();

public:
    void (*unk_00)(UnkClass_02008E88 *process);
    u16 (*unk_04)(UnkClass_02008E88 *process);
    u32 unk_08[16];
    u16 unk_48;
    u16 unk_4A;
    u16 unk_4C;
    u16 unk_4E;
    u16 unk_50;
    u16 unk_52;
    u16 unk_54;
    UnkClass_02008E88 *unk_58;
    UnkClass_02008E88 *unk_5C;
    UnkClass_02008FA8 *unk_60;
};

STATIC_SIZE_ASSERT(UnkClass_02008E88, 0x64);

class UnkClass_02008FA8 {
public:
    UnkClass_02008FA8(UnkClass_020023EC *printer, u32 arg1);
    ~UnkClass_02008FA8();

    void sub_02009020();
    void sub_02009050();
    void sub_02009090();
    void sub_020090E8(int index, u32 value);
    u32 sub_020090F4(int index);
    UnkClass_020023EC *sub_02009100();
    BOOL sub_02009108();
    void sub_0200911C(UnkClass_02008E88 *process);
    void sub_02009124(u16 flags);

public:
    UnkClass_02008E88 unk_00;
    UnkClass_02008E88 *unk_64;
    UnkClass_020023EC *unk_68;
    u32 unk_6C;
    u16 unk_70;
    u32 unk_74[16];
};

STATIC_SIZE_ASSERT(UnkClass_02008FA8, 0xB4);

#endif // POKERANGER2_UNKCLASS_02008E88_HPP
