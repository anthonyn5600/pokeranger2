#ifndef POKERANGER2_UNKCLASS_0201287C_HPP
#define POKERANGER2_UNKCLASS_0201287C_HPP

#include <nitro.h>

#include "common.hpp"
#include "sub_02006000.hpp"

class UnkClass_02011D3C {
public:
    u32 unk_00;
    u8 unk_04[0x10];
};

class UnkStruct_0211CD5C {
public:
    inline void SetPos(Point2D pos)
    {
        unk_18 = pos.x;
        unk_1C = pos.y;
    }

    inline void SetXY(fx32 x, fx32 y)
    {
        unk_18 = x;
        unk_1C = y;
    }

public:
    u8 unk_00[0x18];
    fx32 unk_18;
    fx32 unk_1C;
};

class UnkClass_0201287C {
public:
    inline void sub_reset()
    {
        unk_1DC = 3;
        unk_1E1 = 0;
    }

    inline void SetXY(fx32 x, fx32 y);

    inline void sub_show()
    {
        unk_1DC = 0;
        unk_1E1 = 0;
    }

    inline void SetUnk1DC(int value)
    {
        unk_1DC = value;
        unk_1E1 = 0;
    }

    inline void StartBlink()
    {
        unk_1A8 |= 2;
        unk_1B8 = 0x1F;
        unk_1C6 = 0x1F;
    }

public:
    u8 unk_000[0x4];
    u16 unk_004;
    u8 unk_006[0x6];
    UnkClass_02011D3C unk_00C;
    Point2D m_pos;
    u8 unk_028[0x4A];
    u16 unk_072;
    u8 unk_074[0x18];
    int unk_08C;
    u8 unk_090[0x10];
    int unk_0A0;
    u8 unk_0A4[0xC];
    int unk_0B0;
    u8 unk_0B4[0xC];
    u8 unk_0C0;
    u8 unk_0C1[0x3];
    UnkStruct_0211CD5C *unk_0C4;
    u8 unk_0C8[0xD8];
    int unk_1A0;
    int unk_1A4;
    u32 unk_1A8;
    u8 unk_1AC[0xC];
    u16 unk_1B8;
    u8 unk_1BA[0xC];
    u8 unk_1C6;
    u8 unk_1C7[0x11];
    int unk_1D8;
    int unk_1DC;
    u8 unk_1E0;
    u8 unk_1E1;
};

extern "C" {
void sub_02011D1C(UnkClass_02011D3C *obj, fx32 x);
void sub_02011D2C(UnkClass_02011D3C *obj, fx32 y);
void sub_02011D3C(UnkClass_02011D3C *obj, Point2D pos);
void sub_02011AB0(UnkClass_02011D3C *obj, Point2D pos, int arg2);
void sub_02011C20(UnkClass_02011D3C *obj, Point2D pos, int speed);
void sub_0201287C(UnkClass_0201287C *obj);
void sub_020128D8(UnkClass_0201287C *obj);
void sub_020128EC(UnkClass_0201287C *obj, u16 arg1);
void sub_020129F4(UnkClass_0201287C *obj, int arg1, int arg2);
int sub_02012AFC(UnkClass_0201287C *obj);
void sub_02012B68(UnkClass_0201287C *obj, int arg1, int arg2, int arg3, int arg4, int arg5, int arg6);
void sub_02012C00(UnkClass_0201287C *obj);
}

inline void UnkClass_0201287C::SetXY(fx32 x, fx32 y)
{
    sub_02011D1C(&unk_00C, x);
    sub_02011D2C(&unk_00C, y);
}

#endif // POKERANGER2_UNKCLASS_0201287C_HPP
