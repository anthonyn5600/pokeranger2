#ifndef POKERANGER2_UNKCLASS_0200C38C_HPP
#define POKERANGER2_UNKCLASS_0200C38C_HPP

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"

class UnkClass_0200C404 {
public:
    ~UnkClass_0200C404()
    {
    }

public:
    NNSG2dCharCanvas unk_00;
    NNSG2dTextCanvas unk_18;
    int unk_28;
    int unk_2C;
};

STATIC_SIZE_ASSERT(UnkClass_0200C404, 0x30);

class UnkClass_0200C38C {
public:
    UnkClass_0200C38C(const NNSG2dFont *font, void *arg1);
    ~UnkClass_0200C38C();

    void sub_0200C3BC(const NNSG2dFont *font, u32 arg1);
    void sub_0200C3D0();
    void sub_0200C408(int bg, GXBGScrBase screenBase, GXBGCharBase charBase);
    void sub_0200C588();
    void sub_0200C680(int arg0);
    void sub_0200C6C8(int idx, int width, int height, int left, int top, int charNo, int hSpace, int vSpace);
    void sub_0200C7A4(int idx, int x, int y, int color, u8 *str, BOOL center, int offset);
    void sub_0200C980(int idx);
    void sub_0200C9B4(int idx, u32 fill);
    void *sub_0200C9E8(int bg);
    void *sub_0200CA2C(int bg);
    void sub_0200CA70(const char *str);
    int sub_0200CA80(int idx, const u8 *str, int margin);

public:
    void *unk_00;
    const NNSG2dFont *unk_04;
    UnkClass_0200C404 *unk_08;
    u32 unk_0C;
    u32 unk_10;
    char unk_14[0x18];
    u8 *unk_2C;
    BOOL unk_30;
    u32 unk_34[4];
};

STATIC_SIZE_ASSERT(UnkClass_0200C38C, 0x44);

#endif // POKERANGER2_UNKCLASS_0200C38C_HPP
