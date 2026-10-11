#ifndef POKERANGER2_CACTOR_HPP
#define POKERANGER2_CACTOR_HPP

#include <nitro.h>

#include "CActorData.hpp"
#include "UnkClass_02008788.hpp"
#include "UnkClass_0201179C.hpp"
#include "common.hpp"
#include "primitive/CSoftwareSprite.hpp"
#include "sub_02006000.hpp"

struct CActorGhost {
    u8 active;
    int frame;
    int alpha;
    fx32 scale;
};

struct CActorTween8 {
    u8 value;
    BOOL active;
    int frame;
    int duration;
    u8 from;
    u8 to;
};

struct CActorTween16 {
    u16 value;
    BOOL active;
    int frame;
    int duration;
    u16 from;
    u16 to;
};

struct CActorTween32 {
    fx32 value;
    BOOL active;
    int frame;
    int duration;
    fx32 from;
    fx32 to;
};

class CActor {
public:
    CActor();
    virtual ~CActor();
    virtual void vfunc_08() = 0;
    virtual u32 vfunc_0C(CPrimitive_Render_arg *arg) = 0;
    virtual void vfunc_10() = 0;

    void sub_02011FF4(CActorData *data);
    void sub_020120B0();
    void sub_02012114(int arg0, int arg1);
    void sub_02012184(int arg0, int arg1, fx32 speed);
    void sub_020121F4();
    void sub_02012340();
    void sub_020123AC();
    void sub_020123FC();
    void sub_02012470();
    void sub_020124BC();
    void sub_020125FC();
    void sub_02012648();
    void sub_0201267C(CActorTween8 *tween);
    void sub_020126C8();
    void sub_02012710(CActorTween32 *tween);
    void sub_02012750();
    void sub_02012784(CActorTween16 *tween);
    void sub_020127D0(fx32 value, int duration);
    void sub_02012808(fx32 value, fx32 speed);
    void sub_02012860(fx32 height, int duration);
    void sub_0201287C();
    void sub_02012894(Point2D target);
    void sub_020128C0(s16 speed);
    void sub_020128D8();
    void sub_020128EC(u16 dir);
    void sub_02012948(Point2D target);
    void sub_02012990(u16 dir, s16 speed);
    void sub_020129F4(int duration, u8 alpha);
    void sub_02012A3C(int duration, fx32 scaleX, fx32 scaleY);
    void sub_02012AA8(int duration, u16 value);
    int sub_02012AFC();
    void sub_02012B48(CActorGhost *ghost);
    void sub_02012B68(int interval, int life, BOOL fadeAlpha, int alphaStep, u8 fadeScale, fx32 scaleStep);
    void sub_02012C00();
    int sub_02012C10();
    void sub_02012C4C();
    BOOL sub_02012D88();
    u8 sub_02012D9C(int index);
    CSoftwareSprite *sub_02012DA8();
    int sub_02012DB0(int index);
    fx32 sub_02012DC0(int index);
    u16 sub_02012DD0();
    u8 sub_02012E1C();
    void sub_02012E68();
    void sub_02012F5C(Point2D *end, Point2D *ctrl, int speed);

    inline BOOL HasData()
    {
        return m_data != NULL;
    }

    inline Point2D GetAnimOffset()
    {
        if (m_data != NULL) {
            CActorAnim *anim = m_data->GetAnim(unk_C0);
            if (anim != NULL && anim->bank != NULL) {
                return *(Point2D *)anim->bank->sub_02008844(unk_C8[unk_C0]);
            }
        }
        return (Point2D) { 0, 0 };
    }

public:
    u16 m_flags;
    u8 unk_06[0x2];
    fx32 m_speed;
    UnkClass_0201179C m_motion;
    u8 m_dirMode;
    u16 m_dir;
    BOOL m_turning;
    u32 m_turnTarget;
    int m_turnAngle;
    s16 m_turnSpeed;
    Point2D m_lookAt;
    fx32 unk_8C;
    BOOL unk_90;
    u16 unk_94;
    u16 unk_96;
    fx32 unk_98;
    fx32 unk_9C;
    fx32 m_jumpHeight;
    BOOL m_jumping;
    u16 m_jumpDuration;
    u16 m_jumpFrame;
    fx32 m_jumpAmplitude;
    fx32 m_bobHeight;
    BOOL m_bobbing;
    fx32 m_bobAmplitude;
    u16 m_bobAngle;
    u16 m_bobSpeed;
    u8 unk_C0;
    CSoftwareSprite *m_sprite;
    u16 unk_C8[0x1D];
    CActorData *m_data;
    CActorTween8 unk_108;
    CActorTween32 unk_11C;
    CActorTween32 unk_134;
    CActorTween16 unk_14C;
    CSoftwareSprite *m_sprites;
    u8 m_ghostFlags;
    int m_ghostInterval;
    int m_ghostLife;
    int m_ghostTimer;
    int unk_174;
    int m_ghostAlphaStep;
    fx32 m_ghostScaleStep;
    CActorGhost *m_ghosts;
};

STATIC_SIZE_ASSERT(CActor, 0x184);

#endif // POKERANGER2_CACTOR_HPP
