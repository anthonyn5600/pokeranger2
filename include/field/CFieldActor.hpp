#ifndef POKERANGER2_FIELD_CFIELDACTOR_HPP
#define POKERANGER2_FIELD_CFIELDACTOR_HPP

#include <nitro.h>

#include "UnkClass_0201287C.hpp"
#include "common.hpp"
#include "sub_02006000.hpp"

struct UnkStruct_0211EA94 {
    u8 unk_00[0x4];
    int unk_04;
};

class UnkStruct_0203BF40 {
public:
    inline void SetPos(Point2D pos)
    {
        if (unk_0C != NULL) {
            sub_02011D3C(&unk_0C->unk_00C, pos);
            if (unk_0C->unk_0C4 != NULL) {
                unk_0C->unk_0C4->SetPos(pos);
            }
        }
    }

    inline void SetPosXY(fx32 x, fx32 y)
    {
        if (unk_0C != NULL) {
            unk_0C->SetXY(x, y);
            if (unk_0C->unk_0C4 != NULL) {
                unk_0C->unk_0C4->SetXY(x, y);
            }
        }
    }

    inline void sub_020128EC_(u16 arg0)
    {
        if (unk_0C != NULL) {
            sub_020128EC(unk_0C, arg0);
        }
    }

    inline void sub_0201287C_()
    {
        if (unk_0C != NULL) {
            sub_0201287C(unk_0C);
        }
    }

    inline void sub_020129F4_(int arg0, int arg1)
    {
        if (unk_0C != NULL) {
            sub_020129F4(unk_0C, arg0, arg1);
        }
    }

    inline void sub_reset()
    {
        if (unk_0C != NULL) {
            unk_0C->sub_reset();
        }
    }

    inline void ClearUnk1A8Bits(u32 bits)
    {
        if (unk_0C != NULL) {
            unk_0C->unk_1A8 &= ~bits;
        }
    }

    inline void ResetUnk00C()
    {
        if (unk_0C != NULL) {
            unk_0C->unk_00C.unk_00 = 0;
        }
    }

    inline void sub_show()
    {
        if (unk_0C != NULL) {
            unk_0C->sub_show();
        }
    }

    inline Point2D GetPos()
    {
        if (unk_0C != NULL) {
            return unk_0C->m_pos;
        }
        Point2D zero = { 0, 0 };
        return zero;
    }

    inline fx32 GetX()
    {
        if (unk_0C != NULL) {
            return unk_0C->m_pos.x;
        }
        return 0;
    }

    inline fx32 GetY()
    {
        if (unk_0C != NULL) {
            return unk_0C->m_pos.y;
        }
        return 0;
    }

    inline u16 GetDir()
    {
        if (unk_0C != NULL) {
            return unk_0C->unk_072;
        }
        return 0;
    }

    inline int GetUnk8C()
    {
        if (unk_0C != NULL) {
            return unk_0C->unk_08C;
        }
        return 0;
    }

    inline int GetHeight()
    {
        if (unk_0C != NULL) {
            return unk_0C->unk_08C + unk_0C->unk_0A0 + unk_0C->unk_0B0;
        }
        return 0;
    }

public:
    u8 unk_00[0xC];
    UnkClass_0201287C *unk_0C;
};

class CFieldActor {
public:
    virtual ~CFieldActor();
    virtual void sub_0203C1B4();
    virtual void sub_0203C1FC();
    virtual void sub_0203C22C();
    virtual void sub_0203C288();
    virtual void sub_0203C2D8();
    virtual void sub_0202D394();
    virtual void sub_0203DA60();
    virtual void sub_0203DA40();
    virtual void sub_0203D578();
    virtual void sub_0203DA38();
    virtual void sub_0202E68C(int arg0);
    virtual void sub_0202D7E0();
    virtual void sub_0202DC54(int arg0, int arg1);

    inline void SetPos(Point2D pos)
    {
        if (unk_08 != NULL) {
            unk_08->SetPos(pos);
        }
    }

    inline void sub_020128EC_(u16 arg0)
    {
        if (unk_08 != NULL) {
            unk_08->sub_020128EC_(arg0);
        }
    }

    inline void sub_0201287C_()
    {
        if (unk_08 != NULL) {
            unk_08->sub_0201287C_();
        }
    }

    inline void sub_020129F4_(int arg0, int arg1)
    {
        if (unk_08 != NULL) {
            unk_08->sub_020129F4_(arg0, arg1);
        }
    }

    inline Point2D GetPos()
    {
        if (unk_08 != NULL) {
            return unk_08->GetPos();
        }
        Point2D zero = { 0, 0 };
        return zero;
    }

    inline fx32 GetX()
    {
        if (unk_08 != NULL) {
            return unk_08->GetX();
        }
        return 0;
    }

    inline fx32 GetY()
    {
        if (unk_08 != NULL) {
            return unk_08->GetY();
        }
        return 0;
    }

    inline u16 GetDir()
    {
        if (unk_08 != NULL) {
            return unk_08->GetDir();
        }
        return 0;
    }

    inline void sub_reset()
    {
        if (unk_08 != NULL) {
            unk_04 &= ~8;
            unk_08->sub_reset();
        }
    }

    inline int GetUnk8C()
    {
        if (unk_08 != NULL) {
            return unk_08->GetUnk8C();
        }
        return 0;
    }

    inline void ClearUnk1A8Bits(u32 bits)
    {
        if (unk_08 != NULL) {
            unk_08->ClearUnk1A8Bits(bits);
        }
    }

    inline void ResetUnk00C()
    {
        if (unk_08 != NULL) {
            unk_08->ResetUnk00C();
        }
    }

    inline int GetHeight()
    {
        if (unk_08 != NULL) {
            return unk_08->GetHeight();
        }
        return 0;
    }

    inline void SetPosXY(fx32 x, fx32 y)
    {
        if (unk_08 != NULL) {
            unk_08->SetPosXY(x, y);
        }
    }

    inline void sub_show()
    {
        if (unk_08 != NULL && !(unk_04 & 8)) {
            unk_04 |= 8;
            unk_08->sub_show();
            unk_94 = 0;
        }
    }

    inline int GetDCState()
    {
        if (unk_DC != NULL) {
            return unk_DC->unk_04;
        }
        return 2;
    }

    inline BOOL IsC8Set()
    {
        return unk_C8 != 0 ? TRUE : FALSE;
    }

    inline BOOL IsActive()
    {
        return unk_20 == 2 || unk_20 == 3;
    }

    inline BOOL IsUnk04Bit0()
    {
        return (unk_04 & 1) ? TRUE : FALSE;
    }

    inline BOOL IsTouchable()
    {
        return (unk_04 & 0x200) ? FALSE : TRUE;
    }

    inline BOOL IsTouched(Point2D pos)
    {
        if (IsTouchable() && unk_24.size.x > 0 && unk_24.size.y > 0) {
            Rectangle rect = unk_24;
            rect.pos.x += GetX();
            rect.pos.y += GetY() - GetHeight();
            return sub_02006000(pos, rect, 0);
        }
        return FALSE;
    }

public:
    u32 unk_04;
    UnkStruct_0203BF40 *unk_08;
    u8 unk_0C[0x8];
    int unk_14;
    u8 unk_18[0x8];
    u8 unk_20;
    u8 unk_21[0x3];
    Rectangle unk_24;
    u8 unk_34[0x24];
    u32 unk_58;
    u32 unk_5C;
    u32 unk_60;
    u8 unk_64[0x30];
    u32 unk_94;
    u8 unk_98[0x30];
    int unk_C8;
    u8 unk_CC[0x10];
    UnkStruct_0211EA94 *unk_DC;
};

extern "C" {
void sub_0203C87C(CFieldActor *actor, int arg1);
void sub_02041C1C(CFieldActor *actor);
}

#endif // POKERANGER2_FIELD_CFIELDACTOR_HPP
