#ifndef POKERANGER2_FIELD_CFIELDACTOR_HPP
#define POKERANGER2_FIELD_CFIELDACTOR_HPP

#include <nitro.h>

#include "UnkClass_0211E3FC.hpp"
#include "common.hpp"
#include "field/CFieldActorScript.hpp"
#include "field/CFieldDrawActor.hpp"
#include "sub_02006000.hpp"

class CFieldMap;
class UnkClass_020416AC;

class CFieldDrawObject : public CDrawObject {
public:
    CFieldDrawObject();
    virtual ~CFieldDrawObject();

    BOOL sub_02040530(int arg0, u16 arg1, int arg2, u32 mask, int arg4);
    BOOL sub_020405B4(int arg0, u16 arg1, int arg2, u32 mask, int arg4);
    void sub_02040638();
    virtual int sub_020091D4(Camera2D *camera, int budget);

    inline void SetPos(Point2D pos)
    {
        if (unk_0C != NULL) {
            unk_0C->m_motion.sub_02011D3C(pos);
            if (unk_0C->m_sprite != NULL) {
                unk_0C->m_sprite->SetPos(pos);
            }
        }
    }

    inline void SetPosXY(fx32 x, fx32 y)
    {
        if (unk_0C != NULL) {
            unk_0C->SetXY(x, y);
            if (unk_0C->m_sprite != NULL) {
                unk_0C->m_sprite->SetXY(x, y);
            }
        }
    }

    inline void sub_02012114_(int arg0, int arg1)
    {
        if (unk_0C != NULL) {
            unk_0C->sub_02012114(arg0, arg1);
        }
    }

    inline void sub_020128EC_(u16 arg0)
    {
        if (unk_0C != NULL) {
            unk_0C->sub_020128EC(arg0);
        }
    }

    inline void sub_0201287C_()
    {
        if (unk_0C != NULL) {
            unk_0C->sub_0201287C();
        }
    }

    inline void sub_020129F4_(int arg0, u8 arg1)
    {
        if (unk_0C != NULL) {
            unk_0C->sub_020129F4(arg0, arg1);
        }
    }

    inline void sub_reset()
    {
        if (unk_0C != NULL) {
            unk_0C->sub_reset();
        }
    }

    inline void ResetOutlinePhase()
    {
        if (unk_0C != NULL) {
            unk_0C->m_outlinePhase = 0;
        }
    }

    inline void SetOutlineColor(u16 color)
    {
        if (unk_0C != NULL) {
            unk_0C->SetOutlineColor(color);
        }
    }

    inline void SetOutlineWidth(u8 width)
    {
        if (unk_0C != NULL) {
            unk_0C->m_outlineWidth = width;
        }
    }

    inline void SetOutlineAlpha(u8 alpha)
    {
        if (unk_0C != NULL) {
            unk_0C->m_outlineAlpha = alpha;
        }
    }

    inline void StartOutline(int time)
    {
        if (unk_0C != NULL) {
            unk_0C->StartOutline(time);
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
            unk_0C->m_motion.m_mode = 0;
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
            return unk_0C->m_motion.m_pos;
        }
        Point2D zero = { 0, 0 };
        return zero;
    }

    inline fx32 GetX()
    {
        if (unk_0C != NULL) {
            return unk_0C->m_motion.m_pos.x;
        }
        return 0;
    }

    inline fx32 GetY()
    {
        if (unk_0C != NULL) {
            return unk_0C->m_motion.m_pos.y;
        }
        return 0;
    }

    inline u16 GetDir()
    {
        if (unk_0C != NULL) {
            return unk_0C->m_dir;
        }
        return 0;
    }

    inline int GetUnk8C()
    {
        if (unk_0C != NULL) {
            return unk_0C->unk_8C;
        }
        return 0;
    }

    inline void SetUnk8C(int value)
    {
        if (unk_0C != NULL) {
            unk_0C->unk_8C = value;
        }
    }

    inline BOOL IsUnk00CSet()
    {
        if (unk_0C != NULL) {
            return unk_0C->m_motion.m_mode != 0 ? TRUE : FALSE;
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
            return unk_0C->sub_02012AFC();
        }
        return 2;
    }

    inline u8 GetUnkC0()
    {
        if (unk_0C != NULL) {
            return unk_0C->unk_C0;
        }
        return 0;
    }

    inline fx32 GetScale()
    {
        if (unk_0C != NULL) {
            return unk_0C->unk_11C.value;
        }
        return FX32_ONE;
    }

    inline int GetHeight()
    {
        if (unk_0C != NULL) {
            return unk_0C->unk_8C + unk_0C->m_jumpHeight + unk_0C->m_bobHeight;
        }
        return 0;
    }

    void sub_02040740();

    inline BOOL IsJumping()
    {
        if (unk_0C != NULL) {
            return unk_0C->m_jumping;
        }
        return FALSE;
    }

    inline void Jump(fx32 height, int duration)
    {
        if (unk_0C != NULL) {
            unk_0C->sub_02012860(height, duration);
        }
    }

    inline void MoveLinear(Point2D dest, u32 duration)
    {
        if (unk_0C != NULL) {
            unk_0C->m_motion.sub_02011AB0(dest, duration);
        }
    }

    inline void StopGhost()
    {
        if (unk_0C != NULL) {
            unk_0C->sub_02012C00();
        }
    }

    inline void LookAt(Point2D pos)
    {
        if (unk_0C != NULL) {
            unk_0C->sub_02012894(pos);
        }
    }

    inline void SetClipping(s16 x1, s16 x2, s16 y1, s16 y2)
    {
        if (unk_0C != NULL) {
            unk_0C->SetClipping(x1, x2, y1, y2);
        }
    }

    inline void ClearClipping()
    {
        if (unk_0C != NULL) {
            unk_0C->ClearClipping();
        }
    }

    inline BOOL IsAnimating()
    {
        if (unk_0C != NULL) {
            return (unk_0C->m_flags & 8) ? TRUE : FALSE;
        }
        return FALSE;
    }

    inline s16 GetShadowOffsetX()
    {
        if (unk_0C != NULL) {
            return unk_0C->GetShadowOffsetX();
        }
        return 0;
    }

    inline s16 GetShadowOffsetY()
    {
        if (unk_0C != NULL) {
            return unk_0C->GetShadowOffsetY();
        }
        return 0;
    }

public:
    CFieldDrawActor *unk_0C;
    int unk_10;
    int unk_14;
};

class CFieldActor {
public:
    CFieldActor();
    virtual ~CFieldActor();
    virtual BOOL sub_0203C1B4(void *script);
    virtual BOOL sub_0203C1FC(CFieldActorScript *script, void *block);
    virtual BOOL sub_0203C22C(const char *label);
    virtual BOOL sub_0203C288();
    virtual BOOL sub_0203C2D8();
    virtual void sub_0202D394();
    virtual void sub_0203DA60(u32 id);
    virtual void sub_0203DA40(CFieldMap *map);
    virtual BOOL sub_0203D578(CFieldMap *map);
    virtual BOOL sub_0203DA38();
    virtual void sub_0202E68C(int arg0);
    virtual void sub_0202D7E0();
    virtual void sub_0202DC54(int arg0, int arg1);
    virtual void sub_02032A44(int arg0);

    void sub_0203C2B8();
    void sub_0203C310();
    BOOL sub_0203C418(int arg0, u16 arg1, int arg2, u32 mask, int arg4);
    BOOL sub_0203C4BC(int arg0, u16 arg1, int arg2, u32 mask, int arg4);
    void sub_0203C560();
    void sub_0203C590(UnkClass_0211E3FC *renderLists, UnkClass_020416AC *hud);
    void sub_0203C87C(CFieldMap *map);
    void sub_0203CCD4();
    void sub_0203CDB0();
    BOOL sub_0203CF40(const PointPair2D &move, fx32 radius, u32 flags);
    BOOL sub_0203D110(Point2D pos, fx32 radius, u32 flags);
    BOOL sub_0203D404(Point2D dest);
    void sub_0203D320();
    void sub_0203D2F4();
    void sub_0203D394();
    void sub_0203D890(int attr);
    void sub_0203D910();
    void sub_0203DA10();

    inline BOOL IsJumping()
    {
        if (unk_08 != NULL) {
            return unk_08->IsJumping();
        }
        return FALSE;
    }

    inline void StopGhost()
    {
        if (unk_08 != NULL) {
            unk_08->StopGhost();
        }
    }

    inline void LookAt(Point2D pos)
    {
        if (unk_08 != NULL) {
            unk_08->LookAt(pos);
        }
    }

    inline void SetClipping(s16 x1, s16 x2, s16 y1, s16 y2)
    {
        if (unk_08 != NULL) {
            unk_08->SetClipping(x1, x2, y1, y2);
        }
    }

    inline void ClearClipping()
    {
        if (unk_08 != NULL) {
            unk_08->ClearClipping();
        }
    }

    inline fx32 GetDepth()
    {
        if (unk_08 != NULL) {
            return unk_08->unk_10;
        }
        return -0x4000;
    }

    inline BOOL IsAnimating()
    {
        if (unk_08 != NULL) {
            return unk_08->IsAnimating();
        }
        return FALSE;
    }

    inline s16 GetShadowOffsetX()
    {
        if (unk_08 != NULL) {
            return unk_08->GetShadowOffsetX();
        }
        return 0;
    }

    inline s16 GetShadowOffsetY()
    {
        if (unk_08 != NULL) {
            return unk_08->GetShadowOffsetY();
        }
        return 0;
    }

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

    inline void sub_02012114_(int arg0, int arg1)
    {
        if (unk_08 != NULL) {
            unk_08->sub_02012114_(arg0, arg1);
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

    inline void sub_020129F4_(int arg0, u8 arg1)
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

    inline void SetOutlineColor(u16 color)
    {
        if (unk_08 != NULL) {
            unk_08->SetOutlineColor(color);
        }
    }

    inline void SetOutlineWidth(u8 width)
    {
        if (unk_08 != NULL) {
            unk_08->SetOutlineWidth(width);
        }
    }

    inline void SetOutlineAlpha(u8 alpha)
    {
        if (unk_08 != NULL) {
            unk_08->SetOutlineAlpha(alpha);
        }
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
            unk_08->unk_0C->m_flags |= 8;
        }
    }

    inline void ClearUnk004Bit8()
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->m_flags &= ~8;
        }
    }

    inline Point2D GetPrevPos()
    {
        return unk_64;
    }

    inline void MoveTo(Point2D pos, int speed)
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->m_motion.sub_02011C20(pos, speed);
        }
    }

    inline void MoveLinear(Point2D pos, u32 duration)
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->m_motion.sub_02011AB0(pos, duration);
        }
    }

    inline void MoveCurve(Point2D end, Point2D ctrl, u32 duration)
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->m_motion.sub_02011B18(end, ctrl, duration);
        }
    }

    inline void MoveCurve(Point2D end, Point2D ctrl1, Point2D ctrl2, u32 duration)
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->m_motion.sub_02011B94(end, ctrl1, ctrl2, duration);
        }
    }

    inline void MoveCurve(Point2D *end, Point2D *ctrl, int speed)
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->sub_02012F5C(end, ctrl, speed);
        }
    }

    inline void sub_02012948_(Point2D pos)
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->sub_02012948(pos);
        }
    }

    inline void SetUnk19C(fx32 value)
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->unk_19C = value;
        }
    }

    inline void Jump(fx32 height, u16 duration)
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->sub_02012860(height, duration);
        }
    }

    inline void sub_02012A3C_(int arg0, fx32 arg1, fx32 arg2)
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->sub_02012A3C(arg0, arg1, arg2);
        }
    }

    inline void sub_020128D8_()
    {
        if (unk_08 != NULL && unk_08->unk_0C != NULL) {
            unk_08->unk_0C->sub_020128D8();
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

    inline fx32 GetScale()
    {
        if (unk_08 != NULL) {
            return unk_08->GetScale();
        }
        return FX32_ONE;
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

    inline Rectangle GetShadowRect()
    {
        Rectangle rect;
        rect.pos.x = GetX() + unk_BC * FX32_ONE + GetShadowOffsetX() * FX32_ONE;
        rect.pos.y = GetY() + unk_BD * FX32_ONE + GetShadowOffsetY() * FX32_ONE;
        rect.size.x = (u8)unk_BE << FX32_SHIFT;
        rect.size.y = (u8)unk_BF << FX32_SHIFT;
        return rect;
    }

    inline BOOL IsUnk04Bit12()
    {
        return (unk_04 & 0x1000) ? TRUE : FALSE;
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
    CFieldDrawObject *unk_08;
    BOOL unk_0C;
    fx32 unk_10;
    int unk_14;
    fx32 unk_18;
    fx32 unk_1C;
    u8 unk_20;
    u8 unk_21[0x3];
    Rectangle unk_24;
    Rectangle unk_34;
    Circle unk_44;
    int unk_50;
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
    u8 unk_7D;
    u8 unk_7E;
    char unk_7F[0x11];
    int unk_90;
    int unk_94;
    int unk_98;
    fx32 unk_9C;
    fx32 unk_A0;
    fx32 unk_A4;
    int unk_A8;
    u16 unk_AC;
    u16 unk_AE;
    u16 unk_B0;
    u8 unk_B2[0x2];
    int unk_B4;
    int unk_B8;
    s8 unk_BC;
    s8 unk_BD;
    s8 unk_BE;
    s8 unk_BF;
    Point2D unk_C0;
    int unk_C8;
    int unk_CC;
    int unk_D0;
    u8 unk_D4;
    u8 unk_D5;
    s16 unk_D6;
    u16 unk_D8;
    u8 unk_DA[0x2];
    CFieldActorScript *unk_DC;
};

extern "C" {
void sub_02041C1C(CFieldActor *actor);
}

#endif // POKERANGER2_FIELD_CFIELDACTOR_HPP
