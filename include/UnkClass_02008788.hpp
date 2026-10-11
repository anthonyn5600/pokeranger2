#ifndef POKERANGER2_UNKCLASS_02008788_HPP
#define POKERANGER2_UNKCLASS_02008788_HPP

#include <nitro.h>

#include "UnkClass_02007F98.hpp"
#include "common.hpp"

struct AnimFileHeader {
    u8 unk_00[6];
    u8 count;
    u8 loop;
    u32 size;
    AnimCmd cmds[0];
};

class UnkClass_02008788 {
public:
    UnkClass_02008788();
    UnkClass_02008788(const char *path);
    ~UnkClass_02008788();

    u16 sub_02008828(u16 id);
    fx32 *sub_02008844(u16 id);
    int sub_02008860(u16 id);
    BOOL sub_0200887C(const char *path, u32 heapId, u32 arg2);
    BOOL sub_02008968(u16 id, u16 dir);
    BOOL sub_02008990(u16 id, u16 anim);
    void sub_020089B8(u16 id);
    u8 sub_020089D0(u16 id);
    void sub_020089EC();
    BOOL sub_02008A38(u16 id);
    BOOL sub_02008A58(u16 id, fx32 speed);
    u16 sub_02008A80(u32 arg0, u32 arg1);
    BOOL sub_02008B80(u16 id);
    BOOL sub_02008BF0();
    u8 sub_02008C6C();
    void sub_02008C74();
    UnkClass_02007F98 *sub_02008CD0(u16 id);
    u16 sub_02008D20(u16 id);
    u8 sub_02008D38(u16 id);

public:
    u16 unk_00;
    u8 unk_02;
    u8 unk_03;
    AnimCmd *unk_04;
    u8 unk_08;
    u16 unk_0A;
    UnkClass_02007F98 *unk_0C;
};

STATIC_SIZE_ASSERT(UnkClass_02008788, 0x10);

#endif // POKERANGER2_UNKCLASS_02008788_HPP
