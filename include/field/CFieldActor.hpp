#ifndef POKERANGER2_FIELD_CFIELDACTOR_HPP
#define POKERANGER2_FIELD_CFIELDACTOR_HPP

#include <nitro.h>

#include "UnkClass_0201287C.hpp"
#include "common.hpp"
#include "sub_02006000.hpp"

class CFieldMap;

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

    inline void StartBlink()
    {
        if (unk_0C != NULL) {
            unk_0C->StartBlink();
        }
    }

    inline void SetUnk1DC(int value)
    {
        if (unk_0C != NULL) {
            unk_0C->SetUnk1DC(value);
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

    inline void SetUnk8C(int value)
    {
        if (unk_0C != NULL) {
            unk_0C->unk_08C = value;
        }
    }

    inline BOOL IsUnk00CSet()
    {
        if (unk_0C != NULL) {
            return unk_0C->unk_00C.unk_00 != 0 ? TRUE : FALSE;
        }
        return FALSE;
    }

    inline int GetUnk1D8()
    {
        if (unk_0C != NULL) {
            return unk_0C->unk_1D8;
        }
        return 3;
    }

    inline int GetAnimState()
    {
        if (unk_0C != NULL) {
            return sub_02012AFC(unk_0C);
        }
        return 2;
    }

    inline u8 GetUnkC0()
    {
        if (unk_0C != NULL) {
            return unk_0C->unk_0C0;
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
    CFieldActor();
    virtual ~CFieldActor();
    virtual BOOL sub_0203C1B4(void *script);
    virtual void sub_0203C1FC();
    virtual void sub_0203C22C(const char *label);
    virtual void sub_0203C288();
    virtual void sub_0203C2D8();
    virtual void sub_0202D394();
    virtual void sub_0203DA60(u32 id);
    virtual void sub_0203DA40(CFieldMap *map);
    virtual BOOL sub_0203D578();
    virtual void sub_0203DA38();
    virtual void sub_0202E68C(int arg0);
    virtual void sub_0202D7E0();
    virtual void sub_0202DC54(int arg0, int arg1);
    virtual void sub_02032A44(int arg0);

    inline void SetPos(Point2D pos)
    {
        if (unk_08 != NULL) {
            unk_08->SetPos(pos);
        }
    }

    inline void SetHomePos(Point2D pos)
    {
        unk_18 = pos.x;
        unk_1C = pos.y;
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

    inline void StartBlink()
    {
        if (unk_08 != NULL) {
            unk_08->StartBlink();
        }
    }

    inline void SetUnk8C(int value)
    {
        if (unk_08 != NULL) {
            unk_08->SetUnk8C(value);
        }
    }

    inline void ShowSprite()
    {
        if (unk_08 != NULL) {
            unk_08->sub_show();
        }
    }

    inline BOOL IsUnk00CSet()
    {
        if (unk_08 != NULL) {
            return unk_08->IsUnk00CSet();
        }
        return FALSE;
    }

    inline int GetUnk1D8()
    {
        if (unk_08 != NULL) {
            return unk_08->GetUnk1D8();
        }
        return 3;
    }

    inline int GetAnimState()
    {
        if (unk_08 != NULL) {
            return unk_08->GetAnimState();
        }
        return 2;
    }

    inline void SetUnk1DC(int value)
    {
        if (unk_08 != NULL) {
            unk_08->SetUnk1DC(value);
        }
    }

    inline void SetUnk004Bit8()
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->unk_004 |= 8;
        }
    }

    inline void ClearUnk004Bit8()
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->unk_004 &= ~8;
        }
    }

    inline Point2D GetPrevPos()
    {
        return unk_64;
    }

    inline void MoveTo(Point2D pos, int speed)
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            sub_02011C20(&unk_08->unk_0C->unk_00C, pos, speed);
        }
    }

    inline void sub_020128D8_()
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            sub_020128D8(unk_08->unk_0C);
        }
    }

    inline u8 GetUnkC0()
    {
        if (unk_08 != NULL) {
            return unk_08->GetUnkC0();
        }
        return 0;
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

    inline void SetMasks(int a, int b)
    {
        unk_08->unk_0C->unk_1A0 = a;
        unk_08->unk_0C->unk_1A4 = b;
    }

    inline void SetUnkBC(s8 a, s8 b)
    {
        unk_BC = a;
        unk_BD = b;
    }

    inline void SetUnkBE(s8 a, s8 b)
    {
        unk_BE = a;
        unk_BF = b;
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
    BOOL unk_0C;
    fx32 unk_10;
    int unk_14;
    fx32 unk_18;
    fx32 unk_1C;
    u8 unk_20;
    u8 unk_21[0x3];
    Rectangle unk_24;
    u8 unk_34[0x20];
    int unk_54;
    u32 unk_58;
    u32 unk_5C;
    u32 unk_60;
    Point2D unk_64;
    CFieldMap *unk_6C;
    fx32 unk_70;
    fx32 unk_74;
    int unk_78;
    u8 unk_7C;
    u8 unk_7D[0x13];
    int unk_90;
    u32 unk_94;
    int unk_98;
    fx32 unk_9C;
    fx32 unk_A0;
    fx32 unk_A4;
    u8 unk_A8[0xC];
    int unk_B4;
    int unk_B8;
    s8 unk_BC;
    s8 unk_BD;
    s8 unk_BE;
    s8 unk_BF;
    u8 unk_C0[0x8];
    int unk_C8;
    u8 unk_CC[0x4];
    int unk_D0;
    u8 unk_D4;
    u8 unk_D5;
    s16 unk_D6;
    u8 unk_D8[0x4];
    UnkStruct_0211EA94 *unk_DC;
};

extern "C" {
BOOL sub_0203C418(CFieldActor *actor, int arg1, u16 arg2, int arg3, u32 arg4, int arg5);
void sub_0203C87C(CFieldActor *actor, int arg1);
void sub_02041C1C(CFieldActor *actor);
}

#endif // POKERANGER2_FIELD_CFIELDACTOR_HPP
