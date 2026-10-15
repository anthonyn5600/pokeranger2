#ifndef POKERANGER2_CACTOR_HPP
#define POKERANGER2_CACTOR_HPP

#include <nitro.h>

#include "ActorMotion.hpp"
#include "CActorData.hpp"
#include "CellAnimController.hpp"
#include "Collision.hpp"
#include "common.hpp"
#include "primitive/CSoftwareSprite.hpp"

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
    virtual void vfunc_0C(Camera2D *camera) = 0;
    virtual void vfunc_10(Camera2D *camera) = 0;

    void SetData(CActorData *data);
    void ClearData();
    void SetAnim(int arg0, int arg1);
    void SetAnimWithSpeed(int arg0, int arg1, fx32 speed);
    void Update();
    void UpdateMotion();
    void UpdateHeightTween();
    void UpdateJump();
    void UpdateBob();
    void UpdateDirection();
    void UpdateAnimBank();
    void UpdateAlphaTween();
    void StepTween8(CActorTween8 *tween);
    void UpdateScaleTween();
    void StepTween32(CActorTween32 *tween);
    void UpdateTween16();
    void StepTween16(CActorTween16 *tween);
    void MoveHeightTo(fx32 value, int duration);
    void MoveHeightAtSpeed(fx32 value, fx32 speed);
    void Jump(fx32 height, int duration);
    void FaceMoveDir();
    void LookAt(Point2D target);
    void Spin(u16 speed);
    void FixDir();
    void SetDir(u16 dir);
    void FaceToward(Point2D target);
    void TurnTo(u16 dir, s16 speed);
    void FadeAlpha(int duration, u8 alpha);
    void ScaleTo(int duration, fx32 scaleX, fx32 scaleY);
    void RotateTo(int duration, u16 value);
    int GetAnimStatus();
    void ResetGhost(CActorGhost *ghost);
    void StartGhosts(int interval, int life, BOOL fadeAlpha, int alphaStep, u8 fadeScale, fx32 scaleStep);
    void StopGhosts();
    int AllocGhost();
    void UpdateGhosts();
    BOOL IsGhosting();
    u8 IsGhostActive(int index);
    CSoftwareSprite *GetSprites();
    int GetGhostAlpha(int index);
    fx32 GetGhostScale(int index);
    u16 GetAnimScriptPos();
    u8 sub_02012E1C();
    void RestartAnim();
    void MoveCurveAtSpeed(Point2D *end, Point2D *ctrl, int speed);

    inline BOOL HasData()
    {
        return m_data != NULL;
    }

    inline Point2D GetAnimOffset()
    {
        if (m_data != NULL) {
            CActorAnim *anim = m_data->GetAnim(unk_C0);
            if (anim != NULL && anim->bank != NULL) {
                return *(Point2D *)anim->bank->GetOffsets(unk_C8[unk_C0]);
            }
        }
        return (Point2D) { 0, 0 };
    }

public:
    u16 m_flags;
    u8 unk_06[0x2];
    fx32 m_speed;
    ActorMotion m_motion;
    u8 m_dirMode;
    u16 m_dir;
    BOOL m_turning;
    u32 m_turnTarget;
    int m_turnAngle;
    s16 m_turnSpeed;
    Point2D m_lookAt;
    fx32 m_height;
    BOOL m_heightTweening;
    u16 m_heightDuration;
    u16 m_heightFrame;
    fx32 m_heightFrom;
    fx32 m_heightTo;
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
    CActorTween16 m_rotTween;
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
