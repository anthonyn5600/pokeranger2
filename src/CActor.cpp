#include "CActor.hpp"

#include <nitro.h>

#include "ActorMotion.hpp"
#include "CActorData.hpp"
#include "CellAnimController.hpp"
#include "Collision.hpp"
#include "MathUtil.hpp"
#include "common.hpp"
#include "fx_utils.hpp"
#include "interpolation.hpp"
#include "primitive/CSoftwareSprite.hpp"

CActor::CActor()
{
    m_data = NULL;
    m_sprite = new CSoftwareSprite();
    m_sprites = new CSoftwareSprite[8];
    m_ghosts = new CActorGhost[8];
    m_dirMode = 0;
    MI_CpuFill8(&unk_108, 0, sizeof(unk_108));
    unk_108.value = 0x1F;
    MI_CpuFill8(&unk_11C, 0, sizeof(unk_11C));
    MI_CpuFill8(&unk_134, 0, sizeof(unk_134));
    unk_11C.value = FX32_ONE;
    unk_134.value = FX32_ONE;
    MI_CpuFill8(&m_rotTween, 0, sizeof(m_rotTween));
    m_bobHeight = 0;
    m_bobbing = FALSE;
    m_bobAmplitude = FX32_ONE;
    m_bobAngle = 0;
    m_bobSpeed = 0;
}

CActor::~CActor()
{
    SAFE_DELETE(m_sprite);
    SAFE_DELETE_ARRAY(m_ghosts);
    SAFE_DELETE_ARRAY(m_sprites);
}

void CActor::SetData(CActorData *data)
{
    ClearData();
    m_data = data;
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)data->m_palette;

    for (int i = 0; i < 0x1D; i++) {
        CActorAnim *anim = m_data->GetAnim(i);
        if (anim != NULL && (anim->flags & 1)) {
            unk_C0 = i;
            break;
        }
    }

    for (u8 i = 0; i < 0x1D; i++) {
        CActorAnim *anim = m_data->GetAnim(i);
        if (anim != NULL && anim->bank != NULL) {
            unk_C8[i] = anim->bank->Create(1, data->unk_05);
        }
    }

    m_flags |= 8;
}

void CActor::ClearData()
{
    if (m_data == NULL) {
        return;
    }

    for (u8 i = 0; i < 0x1D; i++) {
        CActorAnim *anim = m_data->GetAnim(i);
        if (anim != NULL && anim->bank != NULL) {
            anim->bank->Remove(unk_C8[i]);
        }
    }

    m_data = NULL;
}

void CActor::SetAnim(int arg0, int arg1)
{
    u8 index = m_data->GetAnimId(arg0, arg1);
    if (index == 0xFF) {
        return;
    }

    CActorAnim *anim = m_data->GetAnim(index);
    if (anim == NULL) {
        return;
    }
    if (!(anim->flags & 1)) {
        return;
    }

    unk_C0 = index;
    UpdateDirection();
    anim->bank->Restart(unk_C8[unk_C0]);
}

void CActor::SetAnimWithSpeed(int arg0, int arg1, fx32 speed)
{
    u8 index = m_data->GetAnimId(arg0, arg1);
    if (index == 0xFF) {
        return;
    }

    CActorAnim *anim = m_data->GetAnim(index);
    if (anim == NULL) {
        return;
    }
    if (!(anim->flags & 1)) {
        return;
    }

    unk_C0 = index;
    anim->bank->SetSpeed(unk_C8[unk_C0], speed);
}

void CActor::Update()
{
    if (!HasData()) {
        return;
    }

    UpdateMotion();
    UpdateHeightTween();
    UpdateJump();
    UpdateBob();
    UpdateDirection();
    UpdateAnimBank();
    UpdateAlphaTween();
    UpdateScaleTween();
    UpdateTween16();

    Point2D pos = m_motion.m_pos;
    pos += GetAnimOffset();
    pos.y -= m_bobHeight + (m_height + m_jumpHeight);
    m_sprite->SetPos(pos);
}

void CActor::UpdateMotion()
{
    Point2D prev = m_motion.GetPos();
    m_motion.Update();
    Point2D delta = m_motion.GetPos() - prev;
    m_speed = ApproxLength(delta.x, delta.y);
}

void CActor::UpdateHeightTween()
{
    if (!m_heightTweening) {
        return;
    }

    m_heightFrame++;
    if (m_heightFrame >= m_heightDuration) {
        m_heightTweening = FALSE;
    }
    m_height = LinearInterpolate(m_heightFrom, m_heightTo, m_heightFrame, m_heightDuration);
}

void CActor::UpdateJump()
{
    if (!m_jumping) {
        return;
    }

    m_jumpFrame++;
    if (m_jumpFrame >= m_jumpDuration) {
        m_jumping = FALSE;
    }
    m_jumpHeight = FX32_MUL(m_jumpAmplitude, FX_SinIdx(LinearInterpolate(0, 0x8000, m_jumpFrame, m_jumpDuration)));
}

void CActor::UpdateBob()
{
    if (!m_bobbing) {
        return;
    }

    m_bobAngle += m_bobSpeed;
    m_bobHeight = FX32_MUL(m_bobAmplitude, FX_SinIdx(m_bobAngle));
}

void CActor::UpdateDirection()
{
    CActorAnim *anim = m_data->GetAnim(unk_C0);

    switch (m_dirMode) {
    case 0:
        if (m_motion.m_mode == ActorMotion::MODE_LINEAR) {
            m_dir = FX_Atan2Idx(m_motion.m_end.y - m_motion.m_start.y, m_motion.m_end.x - m_motion.m_start.x);
        } else if (m_motion.m_mode == ActorMotion::MODE_DIRECTION) {
            m_dir = m_motion.m_angle;
        } else {
            m_dir = m_motion.m_dir;
        }
        break;
    case 1:
        m_dir = FX_Atan2Idx(m_lookAt.y - m_motion.m_pos.y, m_lookAt.x - m_motion.m_pos.x);
        break;
    case 2:
        m_dir += m_turnSpeed;
        break;
    case 3:
        if (m_turning) {
            int prev = m_turnAngle;
            m_turnAngle += m_turnSpeed;
            if (MATH_MIN(prev, m_turnAngle) <= m_turnTarget && MATH_MAX(prev, m_turnAngle) >= m_turnTarget) {
                m_dir = m_turnTarget;
                m_turning = FALSE;
            } else {
                m_dir = m_turnAngle;
            }
        }
        break;
    }

    if (anim != NULL && anim->bank != NULL) {
        anim->bank->SetDirection(unk_C8[unk_C0], m_dir);
    }
}

void CActor::UpdateAnimBank()
{
    if (!(m_flags & 8)) {
        return;
    }

    CActorAnim *anim = m_data->GetAnim(unk_C0);
    if (anim != NULL && anim->bank != NULL) {
        anim->bank->Update(unk_C8[unk_C0]);
    }
}

void CActor::UpdateAlphaTween()
{
    if (!(m_flags & 2)) {
        return;
    }

    StepTween8(&unk_108);
    if (!unk_108.active) {
        m_flags &= ~2;
    }
}

void CActor::StepTween8(CActorTween8 *tween)
{
    tween->frame++;
    tween->value = LinearInterpolate(tween->from << FX32_SHIFT, tween->to << FX32_SHIFT, tween->frame, tween->duration) >> FX32_SHIFT;
    if (tween->frame >= tween->duration) {
        tween->active = FALSE;
    }
}

void CActor::UpdateScaleTween()
{
    if (!(m_flags & 4)) {
        return;
    }

    StepTween32(&unk_11C);
    StepTween32(&unk_134);
    if (!unk_11C.active && !unk_134.active) {
        m_flags &= ~4;
    }
}

void CActor::StepTween32(CActorTween32 *tween)
{
    tween->frame++;
    tween->value = LinearInterpolate(tween->from, tween->to, tween->frame, tween->duration);
    if (tween->frame >= tween->duration) {
        tween->active = FALSE;
    }
}

void CActor::UpdateTween16()
{
    if (!(m_flags & 0x10)) {
        return;
    }

    StepTween16(&m_rotTween);
    if (!m_rotTween.active) {
        m_flags &= ~0x10;
    }
}

void CActor::StepTween16(CActorTween16 *tween)
{
    tween->frame++;
    tween->value = LinearInterpolate(tween->from << FX32_SHIFT, tween->to << FX32_SHIFT, tween->frame, tween->duration) >> FX32_SHIFT;
    if (tween->frame >= tween->duration) {
        tween->active = FALSE;
    }
}

void CActor::MoveHeightTo(fx32 value, int duration)
{
    if (duration != 0) {
        m_heightTweening = TRUE;
        m_heightFrom = m_height;
        m_heightTo = value;
        m_heightFrame = 0;
        m_heightDuration = duration;
    } else {
        m_height = value;
        m_heightTweening = FALSE;
    }
}

void CActor::MoveHeightAtSpeed(fx32 value, fx32 speed)
{
    m_heightTweening = TRUE;
    m_heightFrom = m_height;
    m_heightTo = value;
    m_heightFrame = 0;
    m_heightDuration = FX32_DIV(MATH_IAbs(m_heightTo - m_heightFrom), speed) >> FX32_SHIFT;
}

void CActor::Jump(fx32 height, int duration)
{
    m_jumping = TRUE;
    m_jumpFrame = 0;
    m_jumpDuration = duration;
    m_jumpAmplitude = height;
}

void CActor::FaceMoveDir()
{
    m_turning = FALSE;
    m_dirMode = 0;
    m_motion.m_dir = m_dir;
}

void CActor::LookAt(Point2D target)
{
    m_turning = FALSE;
    m_dirMode = 1;
    m_lookAt.x = target.x;
    m_lookAt.y = target.y;
}

void CActor::Spin(u16 speed)
{
    m_turning = TRUE;
    m_dirMode = 2;
    m_turnSpeed = speed;
}

void CActor::FixDir()
{
    m_turning = FALSE;
    m_dirMode = 3;
}

void CActor::SetDir(u16 dir)
{
    m_turning = FALSE;
    m_dirMode = 3;
    m_dir = dir;

    CActorAnim *anim = m_data->GetAnim(unk_C0);
    if (anim != NULL && anim->bank != NULL) {
        anim->bank->SetDirection(unk_C8[unk_C0], dir);
    }
}

void CActor::FaceToward(Point2D target)
{
    m_turning = FALSE;
    m_dirMode = 3;
    m_dir = FX_Atan2Idx(target.y - m_motion.m_pos.y, target.x - m_motion.m_pos.x);
}

void CActor::TurnTo(u16 dir, s16 speed)
{
    if (speed == 0) {
        return;
    }

    m_turning = TRUE;
    m_dirMode = 3;
    m_turnAngle = m_dir + 0x10000;
    m_turnTarget = dir + 0x10000;
    m_turnSpeed = speed;
    if (m_turnSpeed > 0) {
        if (m_turnAngle > m_turnTarget) {
            m_turnTarget += 0x10000;
        }
    } else {
        if (m_turnAngle < m_turnTarget) {
            m_turnAngle += 0x10000;
        }
    }
}

void CActor::FadeAlpha(int duration, u8 alpha)
{
    if (duration != 0) {
        unk_108.active = TRUE;
        unk_108.frame = 0;
        unk_108.duration = duration;
        unk_108.from = unk_108.value;
        unk_108.to = alpha;
        m_flags |= 2;
    } else {
        unk_108.value = alpha;
        m_flags &= ~2;
    }
}

void CActor::ScaleTo(int duration, fx32 scaleX, fx32 scaleY)
{
    if (duration != 0) {
        unk_11C.active = TRUE;
        unk_11C.frame = 0;
        unk_11C.duration = duration;
        unk_11C.from = unk_11C.value;
        unk_11C.to = scaleX;
        unk_134.active = TRUE;
        unk_134.frame = 0;
        unk_134.duration = duration;
        unk_134.from = unk_134.value;
        unk_134.to = scaleY;
        m_flags |= 4;
    } else {
        unk_11C.value = scaleX;
        unk_134.value = scaleY;
        m_flags &= ~4;
    }
}

void CActor::RotateTo(int duration, u16 value)
{
    if (duration != 0) {
        m_rotTween.active = TRUE;
        m_rotTween.frame = 0;
        m_rotTween.duration = duration;
        m_rotTween.from = m_rotTween.value;
        m_rotTween.to = value;
        m_flags |= 0x10;
    } else {
        m_rotTween.value = value;
        m_flags &= ~0x10;
    }
}

int CActor::GetAnimStatus()
{
    if (m_data == NULL) {
        return 0;
    }

    CActorAnim *anim = m_data->GetAnim(unk_C0);
    if (anim == NULL) {
        return 0;
    }
    return anim->bank->GetStatus(unk_C8[unk_C0]);
}

void CActor::ResetGhost(CActorGhost *ghost)
{
    ghost->active = FALSE;
    ghost->frame = 0;
    ghost->alpha = 0x1F;
    ghost->scale = FX32_ONE;
}

void CActor::StartGhosts(int interval, int life, BOOL fadeAlpha, int alphaStep, u8 fadeScale, fx32 scaleStep)
{
    m_ghostFlags |= 1;
    m_ghostInterval = interval;
    m_ghostLife = life;
    m_ghostTimer = 0;
    unk_174 = 0;
    if (fadeAlpha) {
        m_ghostFlags |= 2;
    }
    if (fadeScale) {
        m_ghostFlags |= 4;
    }
    m_ghostAlphaStep = alphaStep;
    m_ghostScaleStep = scaleStep;

    CActorGhost *ghost = m_ghosts;
    CSoftwareSprite *sprite = m_sprites;
    for (int i = 0; i < 8; i++) {
        ResetGhost(ghost);
        sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)m_data->m_palette;
        ghost++;
        sprite++;
    }
}

void CActor::StopGhosts()
{
    m_ghostFlags &= ~1;
}

int CActor::AllocGhost()
{
    for (int i = 0; i < 8; i++) {
        CActorGhost *ghost = &m_ghosts[i];
        if (!ghost->active) {
            ResetGhost(ghost);
            return i;
        }
    }
    return -1;
}

void CActor::UpdateGhosts()
{
    int slot = -1;

    if (m_ghostFlags & 1) {
        if (m_ghostTimer != m_ghostInterval) {
            m_ghostTimer++;
        } else {
            m_ghostTimer = 0;
            slot = AllocGhost();
        }
    } else {
        m_ghostFlags &= ~1;
    }

    CActorGhost *ghost = m_ghosts;
    CSoftwareSprite *sprite = m_sprites;
    for (int i = 0; i < 8; i++) {
        if (i == slot) {
            ghost->active = TRUE;
            Point2D pos = m_motion.GetPos();
            sprite->SetXY(pos.x, pos.y - (m_bobHeight + (m_height + m_jumpHeight)));
        }
        if (ghost->active) {
            if (ghost->frame <= m_ghostLife) {
                ghost->frame++;
            } else {
                ghost->active = FALSE;
            }
            if (m_ghostFlags & 2) {
                ghost->alpha += m_ghostAlphaStep;
                if (ghost->alpha < 1) {
                    ghost->alpha = 1;
                }
                if (ghost->alpha > 0x1F) {
                    ghost->alpha = 0x1F;
                }
            }
            if (m_ghostFlags & 4) {
                ghost->scale += m_ghostScaleStep;
                if (ghost->scale < 0) {
                    ghost->scale = 0;
                }
            }
        }
        ghost++;
        sprite++;
    }
}

BOOL CActor::IsGhosting()
{
    return (m_ghostFlags & 1) ? TRUE : FALSE;
}

u8 CActor::IsGhostActive(int index)
{
    return m_ghosts[index].active;
}

CSoftwareSprite *CActor::GetSprites()
{
    return m_sprites;
}

int CActor::GetGhostAlpha(int index)
{
    return m_ghosts[index].alpha;
}

fx32 CActor::GetGhostScale(int index)
{
    return m_ghosts[index].scale;
}

u16 CActor::GetAnimScriptPos()
{
    if (m_data == NULL) {
        return 0;
    }

    CActorAnim *anim = m_data->GetAnim(unk_C0);
    if (anim == NULL) {
        return 0;
    }
    return anim->bank->GetScriptPos(unk_C8[unk_C0]);
}

u8 CActor::GetAnimLoopCount()
{
    if (m_data == NULL) {
        return 0;
    }

    CActorAnim *anim = m_data->GetAnim(unk_C0);
    if (anim == NULL) {
        return 0;
    }
    return anim->bank->GetLoopCount(unk_C8[unk_C0]);
}

void CActor::RestartAnim()
{
    if (m_data == NULL) {
        return;
    }

    CActorAnim *anim = m_data->GetAnim(unk_C0);
    if (anim == NULL) {
        return;
    }
    UpdateDirection();
    anim->bank->Restart(unk_C8[unk_C0]);
}

static fx32 CurveLength(Point2D *start, Point2D *ctrl, Point2D *end, int steps)
{
    fx32 length = 0;
    fx32 prevX = start->x;
    fx32 prevY = start->y;

    for (int i = 1; i <= steps; i++) {
        fx32 x = QuadraticInterpolate(start->x, ctrl->x, end->x, i, steps);
        fx32 y = QuadraticInterpolate(start->y, ctrl->y, end->y, i, steps);
        length += ApproxLength(x - prevX, y - prevY);
        prevX = x;
        prevY = y;
    }
    return length;
}

void CActor::MoveCurveAtSpeed(Point2D *end, Point2D *ctrl, int speed)
{
    Point2D pos = m_motion.m_pos;
    int duration = CurveLength(&pos, ctrl, end, 8) / speed;
    if (duration < 1) {
        duration = 1;
    }
    m_motion.MoveQuadratic(*end, *ctrl, duration);
}
