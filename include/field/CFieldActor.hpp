#ifndef POKERANGER2_FIELD_CFIELDACTOR_HPP
#define POKERANGER2_FIELD_CFIELDACTOR_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "DrawObjectList.hpp"
#include "common.hpp"
#include "field/CFieldActorScript.hpp"
#include "field/CFieldDrawActor.hpp"

class CFieldMap;
class FieldShadow;

class CFieldDrawObject : public CDrawObject {
public:
    CFieldDrawObject();
    virtual ~CFieldDrawObject();

    BOOL CreateActor(int arg0, u16 arg1, int arg2, u32 mask, int arg4);
    BOOL CreateActorOwnData(int arg0, u16 arg1, int arg2, u32 mask, int arg4);
    void DeleteActor();
    virtual int Draw(Camera2D *camera, int budget);

    inline void SetPos(Point2D pos)
    {
        if (m_actor != NULL) {
            m_actor->m_motion.SetPos(pos);
            if (m_actor->m_sprite != NULL) {
                m_actor->m_sprite->SetPos(pos);
            }
        }
    }

    inline void SetPosXY(fx32 x, fx32 y)
    {
        if (m_actor != NULL) {
            m_actor->SetXY(x, y);
            if (m_actor->m_sprite != NULL) {
                m_actor->m_sprite->SetXY(x, y);
            }
        }
    }

    inline void sub_02012114_(int arg0, int arg1)
    {
        if (m_actor != NULL) {
            m_actor->SetAnim(arg0, arg1);
        }
    }

    inline void sub_020128EC_(u16 arg0)
    {
        if (m_actor != NULL) {
            m_actor->SetDir(arg0);
        }
    }

    inline void sub_0201287C_()
    {
        if (m_actor != NULL) {
            m_actor->FaceMoveDir();
        }
    }

    inline void sub_020129F4_(int arg0, u8 arg1)
    {
        if (m_actor != NULL) {
            m_actor->FadeAlpha(arg0, arg1);
        }
    }

    inline void sub_reset()
    {
        if (m_actor != NULL) {
            m_actor->sub_reset();
        }
    }

    inline void ResetOutlinePhase()
    {
        if (m_actor != NULL) {
            m_actor->m_outlinePhase = 0;
        }
    }

    inline void SetOutlineColor(u16 color)
    {
        if (m_actor != NULL) {
            m_actor->SetOutlineColor(color);
        }
    }

    inline void SetOutlineWidth(u8 width)
    {
        if (m_actor != NULL) {
            m_actor->m_outlineWidth = width;
        }
    }

    inline void SetOutlineAlpha(u8 alpha)
    {
        if (m_actor != NULL) {
            m_actor->m_outlineAlpha = alpha;
        }
    }

    inline void StartOutline(int time)
    {
        if (m_actor != NULL) {
            m_actor->StartOutline(time);
        }
    }

    inline void ClearEffectFlags(u32 bits)
    {
        if (m_actor != NULL) {
            m_actor->m_effectFlags &= ~bits;
        }
    }

    inline void StartBlink()
    {
        if (m_actor != NULL) {
            m_actor->StartBlink();
        }
    }

    inline void SetUnk1DC(int value)
    {
        if (m_actor != NULL) {
            m_actor->SetUnk1DC(value);
        }
    }

    inline void ResetUnk00C()
    {
        if (m_actor != NULL) {
            m_actor->m_motion.m_mode = 0;
        }
    }

    inline void sub_show()
    {
        if (m_actor != NULL) {
            m_actor->sub_show();
        }
    }

    inline Point2D GetPos()
    {
        if (m_actor != NULL) {
            return m_actor->m_motion.m_pos;
        }
        Point2D zero = { 0, 0 };
        return zero;
    }

    inline fx32 GetX()
    {
        if (m_actor != NULL) {
            return m_actor->m_motion.m_pos.x;
        }
        return 0;
    }

    inline fx32 GetY()
    {
        if (m_actor != NULL) {
            return m_actor->m_motion.m_pos.y;
        }
        return 0;
    }

    inline u16 GetDir()
    {
        if (m_actor != NULL) {
            return m_actor->m_dir;
        }
        return 0;
    }

    inline int GetBaseHeight()
    {
        if (m_actor != NULL) {
            return m_actor->m_height;
        }
        return 0;
    }

    inline void SetBaseHeight(int value)
    {
        if (m_actor != NULL) {
            m_actor->m_height = value;
        }
    }

    inline BOOL IsUnk00CSet()
    {
        if (m_actor != NULL) {
            return m_actor->m_motion.m_mode != 0 ? TRUE : FALSE;
        }
        return FALSE;
    }

    inline int GetUnk1D8()
    {
        if (m_actor != NULL) {
            return m_actor->unk_1D8;
        }
        return 3;
    }

    inline int GetAnimState()
    {
        if (m_actor != NULL) {
            return m_actor->GetAnimStatus();
        }
        return 2;
    }

    inline u8 GetUnkC0()
    {
        if (m_actor != NULL) {
            return m_actor->unk_C0;
        }
        return 0;
    }

    inline fx32 GetScale()
    {
        if (m_actor != NULL) {
            return m_actor->unk_11C.value;
        }
        return FX32_ONE;
    }

    inline int GetHeight()
    {
        if (m_actor != NULL) {
            return m_actor->m_height + m_actor->m_jumpHeight + m_actor->m_bobHeight;
        }
        return 0;
    }

    void sub_02040740();

    inline BOOL IsJumping()
    {
        if (m_actor != NULL) {
            return m_actor->m_jumping;
        }
        return FALSE;
    }

    inline void Jump(fx32 height, int duration)
    {
        if (m_actor != NULL) {
            m_actor->Jump(height, duration);
        }
    }

    inline void MoveLinear(Point2D dest, u32 duration)
    {
        if (m_actor != NULL) {
            m_actor->m_motion.MoveLinear(dest, duration);
        }
    }

    inline void StopGhost()
    {
        if (m_actor != NULL) {
            m_actor->StopGhosts();
        }
    }

    inline void LookAt(Point2D pos)
    {
        if (m_actor != NULL) {
            m_actor->LookAt(pos);
        }
    }

    inline void SetClipping(s16 x1, s16 x2, s16 y1, s16 y2)
    {
        if (m_actor != NULL) {
            m_actor->SetClipping(x1, x2, y1, y2);
        }
    }

    inline void ClearClipping()
    {
        if (m_actor != NULL) {
            m_actor->ClearClipping();
        }
    }

    inline BOOL IsAnimating()
    {
        if (m_actor != NULL) {
            return (m_actor->m_flags & 8) ? TRUE : FALSE;
        }
        return FALSE;
    }

    inline s16 GetShakeX()
    {
        if (m_actor != NULL) {
            return m_actor->GetShakeX();
        }
        return 0;
    }

    inline s16 GetShakeY()
    {
        if (m_actor != NULL) {
            return m_actor->GetShakeY();
        }
        return 0;
    }

public:
    CFieldDrawActor *m_actor;
    int unk_10;
    int unk_14;
};

class CFieldActor {
public:
    CFieldActor();
    virtual ~CFieldActor();
    virtual BOOL SetScriptBlock(void *script);
    virtual BOOL SetScript(CFieldActorScript *script, void *block);
    virtual BOOL RunScriptLabel(const char *label);
    virtual BOOL StopScript();
    virtual BOOL RestartScriptLabel();
    virtual void sub_0202D394();
    virtual void SetId(u32 id);
    virtual void Process(CFieldMap *map);
    virtual BOOL UpdateMove(CFieldMap *map);
    virtual BOOL sub_0203DA38();
    virtual void SetLayer(int arg0);
    virtual void StopMotion();
    virtual void PlayAnim(int arg0, int arg1);
    virtual void sub_02032A44(int arg0);

    void UpdateScript();
    void Reset();
    BOOL CreateDrawObject(int arg0, u16 arg1, int arg2, u32 mask, int arg4);
    BOOL CreateDrawObjectOwnData(int arg0, u16 arg1, int arg2, u32 mask, int arg4);
    void DeleteDrawObject();
    void Draw(DrawObjectList *renderLists, FieldShadow *hud);
    void Update(CFieldMap *map);
    void sub_0203CCD4();
    void UpdateLookAt();
    BOOL CheckSweepCollision(const PointPair2D &move, fx32 radius, u32 flags);
    BOOL CheckCircleCollision(Point2D pos, fx32 radius, u32 flags);
    BOOL StartMoveTo(Point2D dest);
    void UpdateFall();
    void sub_0203D2F4();
    void UpdateFloat();
    void UpdateBushEffect(int attr);
    void StartBushEffect();
    void StopBushEffect();

    inline BOOL IsJumping()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->IsJumping();
        }
        return FALSE;
    }

    inline void StopGhost()
    {
        if (m_drawObject != NULL) {
            m_drawObject->StopGhost();
        }
    }

    inline void LookAt(Point2D pos)
    {
        if (m_drawObject != NULL) {
            m_drawObject->LookAt(pos);
        }
    }

    inline void SetClipping(s16 x1, s16 x2, s16 y1, s16 y2)
    {
        if (m_drawObject != NULL) {
            m_drawObject->SetClipping(x1, x2, y1, y2);
        }
    }

    inline void ClearClipping()
    {
        if (m_drawObject != NULL) {
            m_drawObject->ClearClipping();
        }
    }

    inline fx32 GetDepth()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->unk_10;
        }
        return -0x4000;
    }

    inline BOOL IsAnimating()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->IsAnimating();
        }
        return FALSE;
    }

    inline s16 GetShakeX()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->GetShakeX();
        }
        return 0;
    }

    inline s16 GetShakeY()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->GetShakeY();
        }
        return 0;
    }

    inline void SetPos(Point2D pos)
    {
        if (m_drawObject != NULL) {
            m_drawObject->SetPos(pos);
        }
    }

    inline void SetHomePos(Point2D pos)
    {
        unk_18 = pos.x;
        unk_1C = pos.y;
    }

    inline void sub_02012114_(int arg0, int arg1)
    {
        if (m_drawObject != NULL) {
            m_drawObject->sub_02012114_(arg0, arg1);
        }
    }

    inline void sub_020128EC_(u16 arg0)
    {
        if (m_drawObject != NULL) {
            m_drawObject->sub_020128EC_(arg0);
        }
    }

    inline void sub_0201287C_()
    {
        if (m_drawObject != NULL) {
            m_drawObject->sub_0201287C_();
        }
    }

    inline void sub_020129F4_(int arg0, u8 arg1)
    {
        if (m_drawObject != NULL) {
            m_drawObject->sub_020129F4_(arg0, arg1);
        }
    }

    inline Point2D GetPos()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->GetPos();
        }
        Point2D zero = { 0, 0 };
        return zero;
    }

    inline fx32 GetX()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->GetX();
        }
        return 0;
    }

    inline fx32 GetY()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->GetY();
        }
        return 0;
    }

    inline u16 GetDir()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->GetDir();
        }
        return 0;
    }

    inline void sub_reset()
    {
        if (m_drawObject != NULL) {
            m_flags &= ~8;
            m_drawObject->sub_reset();
        }
    }

    inline int GetBaseHeight()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->GetBaseHeight();
        }
        return 0;
    }

    inline void SetOutlineColor(u16 color)
    {
        if (m_drawObject != NULL) {
            m_drawObject->SetOutlineColor(color);
        }
    }

    inline void SetOutlineWidth(u8 width)
    {
        if (m_drawObject != NULL) {
            m_drawObject->SetOutlineWidth(width);
        }
    }

    inline void SetOutlineAlpha(u8 alpha)
    {
        if (m_drawObject != NULL) {
            m_drawObject->SetOutlineAlpha(alpha);
        }
    }

    inline void ClearEffectFlags(u32 bits)
    {
        if (m_drawObject != NULL) {
            m_drawObject->ClearEffectFlags(bits);
        }
    }

    inline void StartBlink()
    {
        if (m_drawObject != NULL) {
            m_drawObject->StartBlink();
        }
    }

    inline void SetBaseHeight(int value)
    {
        if (m_drawObject != NULL) {
            m_drawObject->SetBaseHeight(value);
        }
    }

    inline void ShowSprite()
    {
        if (m_drawObject != NULL) {
            m_drawObject->sub_show();
        }
    }

    inline BOOL IsUnk00CSet()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->IsUnk00CSet();
        }
        return FALSE;
    }

    inline int GetUnk1D8()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->GetUnk1D8();
        }
        return 3;
    }

    inline int GetAnimState()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->GetAnimState();
        }
        return 2;
    }

    inline void SetUnk1DC(int value)
    {
        if (m_drawObject != NULL) {
            m_drawObject->SetUnk1DC(value);
        }
    }

    inline void SetUnk004Bit8()
    {
        if (m_drawObject != NULL && m_drawObject->m_actor != NULL) {
            m_drawObject->m_actor->m_flags |= 8;
        }
    }

    inline void ClearUnk004Bit8()
    {
        if (m_drawObject != NULL && m_drawObject->m_actor != NULL) {
            m_drawObject->m_actor->m_flags &= ~8;
        }
    }

    inline Point2D GetPrevPos()
    {
        return unk_64;
    }

    inline void MoveTo(Point2D pos, int speed)
    {
        if (m_drawObject != NULL && m_drawObject->m_actor != NULL) {
            m_drawObject->m_actor->m_motion.MoveAtSpeed(pos, speed);
        }
    }

    inline void MoveLinear(Point2D pos, u32 duration)
    {
        if (m_drawObject != NULL && m_drawObject->m_actor != NULL) {
            m_drawObject->m_actor->m_motion.MoveLinear(pos, duration);
        }
    }

    inline void MoveCurve(Point2D end, Point2D ctrl, u32 duration)
    {
        if (m_drawObject != NULL && m_drawObject->m_actor != NULL) {
            m_drawObject->m_actor->m_motion.MoveQuadratic(end, ctrl, duration);
        }
    }

    inline void MoveCurve(Point2D end, Point2D ctrl1, Point2D ctrl2, u32 duration)
    {
        if (m_drawObject != NULL && m_drawObject->m_actor != NULL) {
            m_drawObject->m_actor->m_motion.MoveCubic(end, ctrl1, ctrl2, duration);
        }
    }

    inline void MoveCurve(Point2D *end, Point2D *ctrl, int speed)
    {
        if (m_drawObject != NULL && m_drawObject->m_actor != NULL) {
            m_drawObject->m_actor->MoveCurveAtSpeed(end, ctrl, speed);
        }
    }

    inline void sub_02012948_(Point2D pos)
    {
        if (m_drawObject != NULL && m_drawObject->m_actor != NULL) {
            m_drawObject->m_actor->FaceToward(pos);
        }
    }

    inline void SetUnk19C(fx32 value)
    {
        if (m_drawObject != NULL && m_drawObject->m_actor != NULL) {
            m_drawObject->m_actor->m_animSpeed = value;
        }
    }

    inline void Jump(fx32 height, u16 duration)
    {
        if (m_drawObject != NULL && m_drawObject->m_actor != NULL) {
            m_drawObject->m_actor->Jump(height, duration);
        }
    }

    inline void sub_02012A3C_(int arg0, fx32 arg1, fx32 arg2)
    {
        if (m_drawObject != NULL && m_drawObject->m_actor != NULL) {
            m_drawObject->m_actor->ScaleTo(arg0, arg1, arg2);
        }
    }

    inline void sub_020128D8_()
    {
        if (m_drawObject != NULL && m_drawObject->m_actor != NULL) {
            m_drawObject->m_actor->FixDir();
        }
    }

    inline u8 GetUnkC0()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->GetUnkC0();
        }
        return 0;
    }

    inline void ResetUnk00C()
    {
        if (m_drawObject != NULL) {
            m_drawObject->ResetUnk00C();
        }
    }

    inline int GetHeight()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->GetHeight();
        }
        return 0;
    }

    inline fx32 GetScale()
    {
        if (m_drawObject != NULL) {
            return m_drawObject->GetScale();
        }
        return FX32_ONE;
    }

    inline void SetPosXY(fx32 x, fx32 y)
    {
        if (m_drawObject != NULL) {
            m_drawObject->SetPosXY(x, y);
        }
    }

    inline void sub_show()
    {
        if (m_drawObject != NULL && !(m_flags & 8)) {
            m_flags |= 8;
            m_drawObject->sub_show();
            unk_94 = 0;
        }
    }

    inline int GetDCState()
    {
        if (m_script != NULL) {
            return m_script->unk_04;
        }
        return 2;
    }

    inline void SetMasks(int a, int b)
    {
        m_drawObject->m_actor->unk_1A0 = a;
        m_drawObject->m_actor->unk_1A4 = b;
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
        rect.pos.x = GetX() + unk_BC * FX32_ONE + GetShakeX() * FX32_ONE;
        rect.pos.y = GetY() + unk_BD * FX32_ONE + GetShakeY() * FX32_ONE;
        rect.size.x = (u8)unk_BE << FX32_SHIFT;
        rect.size.y = (u8)unk_BF << FX32_SHIFT;
        return rect;
    }

    inline BOOL IsUnk04Bit12()
    {
        return (m_flags & 0x1000) ? TRUE : FALSE;
    }

    inline BOOL IsHidden()
    {
        return (m_flags & 1) ? TRUE : FALSE;
    }

    inline BOOL IsTouchable()
    {
        return (m_flags & 0x200) ? FALSE : TRUE;
    }

    inline BOOL IsTouched(Point2D pos)
    {
        if (IsTouchable() && unk_24.size.x > 0 && unk_24.size.y > 0) {
            Rectangle rect = unk_24;
            rect.pos.x += GetX();
            rect.pos.y += GetY() - GetHeight();
            return PointInRect(pos, rect, 0);
        }
        return FALSE;
    }

public:
    u32 m_flags;
    CFieldDrawObject *m_drawObject;
    BOOL unk_0C;
    fx32 unk_10;
    int m_layer;
    fx32 unk_18;
    fx32 unk_1C;
    u8 unk_20;
    u8 unk_21[0x3];
    Rectangle unk_24;
    Rectangle unk_34;
    Circle unk_44;
    int unk_50;
    int unk_54;
    u32 m_id;
    u32 m_lookAt;
    u32 m_lookAtId;
    Point2D unk_64;
    CFieldMap *m_map;
    fx32 unk_70;
    fx32 unk_74;
    int unk_78;
    u8 unk_7C;
    u8 unk_7D;
    u8 unk_7E;
    char unk_7F[0x11];
    int m_hasShadow;
    int unk_94;
    int unk_98;
    fx32 m_gravity;
    fx32 unk_A0;
    fx32 m_fallSpeed;
    int m_floatBase;
    u16 m_floatAngle;
    u16 m_floatSpeed;
    u16 m_floatAmp;
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
    u8 m_bushMode;
    u8 unk_D5;
    s16 unk_D6;
    u16 m_bushEffect;
    u8 unk_DA[0x2];
    CFieldActorScript *m_script;
};

extern "C" {
void Actor_HideManpu(CFieldActor *actor);
}

#endif // POKERANGER2_FIELD_CFIELDACTOR_HPP
