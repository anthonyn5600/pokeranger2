#ifndef POKERANGER2_UNKCLASS_0200CAB4_HPP
#define POKERANGER2_UNKCLASS_0200CAB4_HPP

#include <nitro.h>
#include <nnsys.h>

#include "UnkClass_0200C38C.hpp"
#include "common.hpp"

class UnkClass_0200CAB4 {
public:
    UnkClass_0200CAB4(const NNSG2dFont *font, void *arg1);

    void sub_0200CACC(const NNSG2dFont *font, u32 arg1);
    void sub_0200CAE0();
    void sub_0200CB14();
    void sub_0200CB90();
    void sub_0200CC88(int arg0);
    void sub_0200CCD0(int idx, int width, int height, int left, int top, int charNo, int hSpace, int vSpace);
    void sub_0200CDA0(int idx, int x, int y, int color, u8 *str, BOOL center, int offset);
    void sub_0200CF7C(int idx);
    void sub_0200CFB0(const char *str);
    int sub_0200CFC0(int idx, const u8 *str, int margin);

public:
    void *unk_00;
    const NNSG2dFont *unk_04;
    UnkClass_0200C404 *unk_08;
    u32 unk_0C;
    char unk_10[0x18];
    u8 *unk_28;
    BOOL unk_2C;
    u32 unk_30[4];
};

STATIC_SIZE_ASSERT(UnkClass_0200CAB4, 0x40);

#endif // POKERANGER2_UNKCLASS_0200CAB4_HPP
