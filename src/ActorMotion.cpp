#include "ActorMotion.hpp"

#include <nitro.h>

#include "Collision.hpp"
#include "MathUtil.hpp"
#include "fx_utils.hpp"
#include "interpolation.hpp"

u16 g_actorFps = 60;

ActorMotion::ActorMotion()
{
    m_pos.x = 0;
    m_pos.y = 0;
}

ActorMotion::~ActorMotion()
{
}

void ActorMotion::Update()
{
    m_prev.x = m_pos.x;
    m_prev.y = m_pos.y;
    if (!IsActive()) {
        return;
    }

    int step = g_actorFps == 60 ? 1 : 2;
    m_frame += step;
    if (m_frame > m_duration) {
        m_frame = m_duration;
    }

    switch (m_mode) {
    case MODE_NONE:
        break;
    case MODE_LINEAR:
        m_pos.x = LinearInterpolate(m_start.x, m_end.x, m_frame, m_duration);
        m_pos.y = LinearInterpolate(m_start.y, m_end.y, m_frame, m_duration);
        break;
    case MODE_QUADRATIC:
        m_pos.x = QuadraticInterpolate(m_start.x, m_ctrl1.x, m_end.x, m_frame, m_duration);
        m_pos.y = QuadraticInterpolate(m_start.y, m_ctrl1.y, m_end.y, m_frame, m_duration);
        break;
    case MODE_CUBIC:
        m_pos.x = CubicInterpolate(m_start.x, m_ctrl1.x, m_ctrl2.x, m_end.x, m_frame, m_duration);
        m_pos.y = CubicInterpolate(m_start.y, m_ctrl1.y, m_ctrl2.y, m_end.y, m_frame, m_duration);
        break;
    case MODE_DIRECTION:
        m_pos.x += FX32_MUL(m_speed * step, FX_CosIdx(m_angle));
        m_pos.y += FX32_MUL(m_speed * step, FX_SinIdx(m_angle));
        break;
    case MODE_ORBIT:
        m_orbitAngle += m_orbitSpeed * step;
        m_pos.x = FX32_MUL(m_radius.x, FX_CosIdx(m_orbitAngle));
        m_pos.y = FX32_MUL(m_radius.y, FX_SinIdx(m_orbitAngle));
        if (m_tilt != 0) {
            fx64 sin = FX_SinIdx(m_tilt);
            fx64 cos = FX_CosIdx(m_tilt);
            fx32 x = FX32_MUL(m_pos.x, cos) - FX32_MUL(m_pos.y, sin);
            fx32 y = FX32_MUL(m_pos.x, sin) + FX32_MUL(m_pos.y, cos);
            m_pos.x = x;
            m_pos.y = y;
        }
        m_pos.x += m_center.x;
        m_pos.y += m_center.y;
        break;
    }

    m_dir = FX_Atan2Idx(m_pos.y - m_prev.y, m_pos.x - m_prev.x);
    if (m_frame >= m_duration) {
        m_mode = MODE_NONE;
    }
}

void ActorMotion::MoveLinear(Point2D end, u32 duration)
{
    if (duration != 0) {
        m_frame = 0;
        m_mode = MODE_LINEAR;
        m_duration = duration;
        m_start.x = m_pos.x;
        m_start.y = m_pos.y;
        m_end.x = end.x;
        m_end.y = end.y;
    } else {
        SetPos(end);
    }
}

void ActorMotion::MoveQuadratic(Point2D end, Point2D ctrl, u32 duration)
{
    if (duration != 0) {
        m_frame = 0;
        m_mode = MODE_QUADRATIC;
        m_duration = duration;
        m_start.x = m_pos.x;
        m_start.y = m_pos.y;
        m_end.x = end.x;
        m_end.y = end.y;
        m_ctrl1.x = ctrl.x;
        m_ctrl1.y = ctrl.y;
    } else {
        SetPos(end);
    }
}

void ActorMotion::MoveCubic(Point2D end, Point2D ctrl1, Point2D ctrl2, u32 duration)
{
    if (duration != 0) {
        m_frame = 0;
        m_mode = MODE_CUBIC;
        m_duration = duration;
        m_start.x = m_pos.x;
        m_start.y = m_pos.y;
        m_end.x = end.x;
        m_end.y = end.y;
        m_ctrl1.x = ctrl1.x;
        m_ctrl1.y = ctrl1.y;
        m_ctrl2.x = ctrl2.x;
        m_ctrl2.y = ctrl2.y;
    } else {
        SetPos(end);
    }
}

void ActorMotion::MoveAtSpeed(Point2D end, int speed)
{
    m_frame = 0;
    m_mode = MODE_LINEAR;
    m_duration = ApproxLength(end.x - m_pos.x, end.y - m_pos.y) / speed;
    m_start.x = m_pos.x;
    m_start.y = m_pos.y;
    m_end.x = end.x;
    m_end.y = end.y;
}

void ActorMotion::MoveInDirection(u16 angle, fx32 speed)
{
    m_mode = MODE_DIRECTION;
    m_frame = 0;
    m_duration = -1;
    m_angle = angle;
    m_speed = speed;
}

void ActorMotion::Orbit(Point2D center, fx32 radiusX, fx32 radiusY, u16 angle, u16 angleSpeed, u16 tilt)
{
    m_mode = MODE_ORBIT;
    m_frame = 0;
    m_duration = -1;
    m_center.x = center.x;
    m_center.y = center.y;
    m_radius.x = radiusX;
    m_radius.y = radiusY;
    m_orbitAngle = angle;
    m_orbitSpeed = angleSpeed;
    m_tilt = tilt;
    m_end.x = center.x;
    m_end.y = center.y;
}

void ActorMotion::SetX(fx32 x)
{
    m_mode = MODE_NONE;
    m_pos.x = x;
}

void ActorMotion::SetY(fx32 y)
{
    m_mode = MODE_NONE;
    m_pos.y = y;
}

void ActorMotion::SetPos(Point2D pos)
{
    m_mode = MODE_NONE;
    m_pos.x = pos.x;
    m_pos.y = pos.y;
}
