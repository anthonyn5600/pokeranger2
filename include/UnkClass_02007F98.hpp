#ifndef POKERANGER2_UNKCLASS_02007F98_HPP
#define POKERANGER2_UNKCLASS_02007F98_HPP

#include <nitro.h>

#include "common.hpp"

extern u16 g_animFps;

fx32 sub_02007DE4(u16 value);
int sub_02007DF0(int count, u16 dir, int arg2);

struct AnimCmd {
    u8 op;
    u16 arg;
};

class UnkClass_02007F98 {
public:
    UnkClass_02007F98(u32 arg0, u32 arg1);
    ~UnkClass_02007F98();

    u8 sub_02008014();
    fx32 *sub_02008024();
    int sub_0200802C();
    void sub_0200805C(fx32 speed);
    void sub_02008064(u32 arg0, u32 arg1);
    BOOL sub_02008104(u16 dir);
    void sub_02008170();
    BOOL sub_020081E4(int index);
    void sub_0200827C();
    void sub_02008584();
    void sub_020086B4();
    void sub_0200870C(UnkClass_02007F98 *prev);
    void sub_02008714(UnkClass_02007F98 *next);
    UnkClass_02007F98 *sub_0200871C();
    UnkClass_02007F98 *sub_02008724();
    u16 sub_0200872C();
    void sub_02008734(AnimCmd *script, u16 length, u8 count, u8 loop);
    void sub_02008778(u16 id);
    u8 sub_02008780();

    inline void ClearFrames()
    {
        for (int i = 0; i < unk_2E; i++) {
            unk_00[i] = 0;
            unk_04[i] = 0;
            unk_08[i] = 0;
        }
    }

public:
    u8 *unk_00;
    u8 *unk_04;
    u8 *unk_08;
    u8 unk_0C;
    u16 unk_0E;
    u8 unk_10;
    u8 unk_11;
    fx32 unk_14;
    fx32 unk_18;
    fx32 unk_1C;
    fx32 unk_20;
    fx32 unk_24;
    fx32 unk_28;
    u16 unk_2C;
    u8 unk_2E;
    u8 unk_2F;
    AnimCmd *unk_30;
    fx32 unk_34;
    fx32 unk_38;
    u16 unk_3C;
    u16 unk_3E;
    UnkClass_02007F98 *unk_40;
    UnkClass_02007F98 *unk_44;
    u16 unk_48;
};

STATIC_SIZE_ASSERT(UnkClass_02007F98, 0x4C);

#endif // POKERANGER2_UNKCLASS_02007F98_HPP
