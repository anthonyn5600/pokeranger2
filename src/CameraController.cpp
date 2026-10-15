#include "CameraController.hpp"

#include "fx_utils.hpp"

extern "C" {
extern u16 DAT_0208aaf4;
extern fx32 DAT_020843f8[];
extern fx32 DAT_02084410[];
}

#define ABS(x) ((x) < 0 ? -(x) : (x))

CameraController::CameraController(UnkStruct_0200D3F8_Target *target)
{
    SetTarget(target);
    Reset();
}

CameraController::~CameraController()
{
}

void CameraController::Reset()
{
    m_flags = 0;
    m_frame = 0;
    m_duration = 0;
    m_destX = 0;
    m_destY = 0;
    m_stepX = 0;
    m_stepY = 0;
    m_amplitude = 0;
    m_phase = 0;
    m_scale = FX32_ONE;
}

void CameraController::SetPos(fx32 x, fx32 y)
{
    m_target->x = x;
    m_target->y = y;
}

void CameraController::SetScale(fx32 scale)
{
    m_scale = scale;
}

void CameraController::Move(fx32 dx, fx32 dy)
{
    if (m_target == NULL) {
        return;
    }
    SetPos(dx + m_target->x, dy + m_target->y);
}

void CameraController::MoveTo(fx32 x, fx32 y, fx32 speed)
{
    UnkStruct_0200D3F8_Target *target = m_target;
    if (target == NULL) {
        return;
    }
    if (m_flags != 0) {
        return;
    }

    fx32 step = (speed * 60) / DAT_0208aaf4;
    fx32 dx = x - target->x;
    fx32 dy = y - target->y;
    fx32 dist = FX_Sqrt(FX32_MUL(dx, dx) + FX32_MUL(dy, dy));

    if (dist > step) {
        m_stepX = FX32_MUL(step, FX32_DIV(dx, dist));
        m_stepY = FX32_MUL(step, FX32_DIV(dy, dist));
        if (m_stepX == 0 && m_stepY == 0) {
            SetPos(x, y);
            m_flags &= ~1;
            return;
        }
        m_destX = x;
        m_destY = y;
        m_flags |= 1;
    } else {
        SetPos(x, y);
        m_flags &= ~1;
    }
}

void CameraController::MoveToTimed(fx32 x, fx32 y, u16 frames)
{
    if (m_target == NULL) {
        return;
    }
    if (m_flags != 0) {
        return;
    }

    u16 fps = DAT_0208aaf4;
    if (fps <= 30) {
        frames++;
    }
    frames = (frames * fps) / 60;

    m_stepX = FX32_DIV(x - m_target->x, (fx64)(frames << FX32_SHIFT));
    m_stepY = FX32_DIV(y - m_target->y, (fx64)(frames << FX32_SHIFT));
    m_destX = x;
    m_destY = y;
    m_frame = 0;
    m_duration = frames;
    m_flags |= 2;
}

void CameraController::Sway(fx32 amplitude, u16 speed, u16 duration)
{
    if (m_target == NULL) {
        return;
    }
    if (m_flags != 0) {
        return;
    }

    m_amplitude = amplitude;
    m_phase = 0x3FFF;
    m_speed = speed;
    m_destX = m_target->x;
    m_destY = m_target->y;
    m_frame = 0;
    m_duration = duration;
    m_flags |= 4;
}

void CameraController::ZoomTo(fx32 scale, u16 frames)
{
    if (m_target == NULL) {
        return;
    }
    if (m_flags != 0) {
        return;
    }

    m_amplitude = FX32_DIV(scale - m_scale, (fx64)(frames << FX32_SHIFT));
    m_destX = scale;
    m_frame = 0;
    m_duration = frames;
    m_flags |= 8;
}

void CameraController::Spin(u16 speed, u16 duration)
{
    if (m_target == NULL) {
        return;
    }
    if (m_flags != 0) {
        return;
    }

    m_speed = speed;
    m_phase = 0;
    m_frame = 0;
    m_duration = duration;
    m_flags |= 0x10;
}

void CameraController::SpinZoom(fx32 scale, u16 speed, u16 frames)
{
    if (m_target == NULL) {
        return;
    }
    if (m_flags != 0) {
        return;
    }

    m_amplitude = FX32_DIV(scale - m_scale, (fx64)(frames << FX32_SHIFT));
    m_destX = scale;
    m_speed = speed;
    m_phase = 0;
    m_frame = 0;
    m_duration = frames;
    m_flags |= 0x20;
}

void CameraController::Shake(fx32 amplitude, u16 duration)
{
    if (m_target == NULL) {
        return;
    }
    if (m_flags != 0) {
        return;
    }

    m_amplitude = amplitude;
    m_speed = 0;
    m_phase = 0;
    m_destX = m_target->x;
    m_destY = m_target->y;
    m_frame = 0;
    m_duration = duration;
    m_flags |= 0x40;
}

void CameraController::StartShake(fx32 amplitude)
{
    if (m_target == NULL) {
        return;
    }
    if (m_flags != 0) {
        return;
    }

    m_amplitude = amplitude;
    m_speed = 0;
    m_phase = 0;
    m_destX = m_target->x;
    m_destY = m_target->y;
    m_frame = 0;
    m_duration = 1;
    m_flags |= 0x100;
}

void CameraController::StartShakeX(fx32 amplitude)
{
    if (m_target == NULL) {
        return;
    }
    if (m_flags != 0) {
        return;
    }

    m_amplitude = amplitude;
    m_speed = 0;
    m_phase = 0;
    m_destX = m_target->x;
    m_destY = m_target->y;
    m_frame = 0;
    m_duration = 1;
    m_flags |= 0x200;
}

void CameraController::StopShake()
{
    if (m_flags & 0x100) {
        m_frame = 1;
    }
}

void CameraController::StopShakeX()
{
    if (m_flags & 0x200) {
        m_frame = 1;
    }
}

void CameraController::SetShakeAmplitude(fx32 amplitude)
{
    if (m_flags & 0x100) {
        m_amplitude = amplitude;
    }
}

BOOL CameraController::IsMoving()
{
    return (m_flags & 2) ? TRUE : FALSE;
}

void CameraController::Update()
{
    if (m_target == NULL) {
        return;
    }

    if (m_flags & 1) {
        if (ABS(m_destX - m_target->x) < ABS(m_stepX) || ABS(m_destY - m_target->y) < ABS(m_stepY)) {
            SetPos(m_destX, m_destY);
            m_flags &= ~1;
        } else {
            Move(m_stepX, m_stepY);
        }
    }

    if (m_flags & 2) {
        if (m_frame == m_duration) {
            SetPos(m_destX, m_destY);
            m_flags &= ~2;
        }
        if (m_frame < m_duration) {
            Move(m_stepX, m_stepY);
            m_frame++;
        }
    }

    if (m_flags & 4) {
        if (0xFFFF - m_phase < m_speed) {
            m_phase = 0;
        } else {
            SetPos(m_destX + FX32_MUL(m_amplitude, FX_CosIdx(m_phase)), m_destY);
            m_phase += m_speed;
        }
        if (0x3FFF - m_speed < m_phase && m_speed + 0x3FFF > m_phase && m_frame == m_duration) {
            SetPos(m_destX, m_destY);
            m_flags &= ~4;
        }
        if (m_frame < m_duration) {
            m_frame++;
        }
    }

    if (m_flags & 8) {
        if (m_frame == m_duration) {
            SetScale(m_destX);
            m_flags &= ~8;
        }
        if (m_frame < m_duration) {
            SetScale(m_scale + m_amplitude);
            m_frame++;
        }
    }

    if (m_flags & 0x10) {
        if (0xFFFF - m_phase < m_speed) {
            if (m_frame == m_duration) {
                m_target->rotation = 0;
                m_flags &= ~0x10;
            }
            m_phase = 0;
        } else {
            m_target->rotation = m_phase;
            m_phase += m_speed;
        }
        if (m_frame < m_duration) {
            m_frame++;
        }
    }

    if (m_flags & 0x20) {
        if (0xFFFF - m_phase < m_speed) {
            if (m_frame == m_duration) {
                SetScale(m_destX);
                m_target->rotation = 0;
                m_flags &= ~0x20;
            }
            m_phase = 0;
        } else {
            m_target->rotation = m_phase;
            m_phase += m_speed;
        }
        if (m_frame < m_duration) {
            SetScale(m_scale + m_amplitude);
            m_frame++;
        }
    }

    if (m_flags & 0x40) {
        if (m_frame == m_duration) {
            SetPos(m_destX, m_destY);
            m_flags &= ~0x40;
        }
        if (m_frame < m_duration) {
            SetPos(m_destX + FX32_MUL(m_amplitude, DAT_020843f8[m_phase]), m_destY + FX32_MUL(m_amplitude, DAT_02084410[m_phase]));
            m_frame++;
        }
        if (m_speed < 3) {
            m_speed++;
        }
        if (m_speed == 3) {
            if (m_phase < 6) {
                m_phase++;
            }
            if (m_phase == 6) {
                m_phase = 0;
            }
            m_speed = 0;
        }
    }

    if (m_flags & 0x80) {
        if (0xFFFF - m_phase < m_speed) {
            m_phase = 0;
        } else {
            SetPos(m_destX + FX32_MUL(m_amplitude, FX_CosIdx(m_phase)), m_destY);
            m_phase += m_speed;
        }
        if (0x3FFF - m_speed < m_phase && m_speed + 0x3FFF > m_phase && m_frame == m_duration) {
            SetPos(m_destX, m_destY);
            m_flags &= ~0x80;
        }
    }

    if (m_flags & 0x100) {
        if (m_frame == m_duration) {
            SetPos(m_destX, m_destY);
            m_flags &= ~0x100;
        }
        if (m_frame < m_duration) {
            SetPos(m_destX + FX32_MUL(m_amplitude, DAT_020843f8[m_phase]), m_destY + FX32_MUL(m_amplitude, DAT_02084410[m_phase]));
        }
        if (m_speed < 3) {
            m_speed++;
        }
        if (m_speed == 3) {
            if (m_phase < 6) {
                m_phase++;
            }
            if (m_phase == 6) {
                m_phase = 0;
            }
            m_speed = 0;
        }
    }

    if (m_flags & 0x200) {
        if (m_frame == m_duration) {
            SetPos(m_destX, m_destY);
            m_flags &= ~0x200;
        }
        if (m_frame < m_duration) {
            fx32 dir = FX32_ONE;
            if (m_phase != 0) {
                dir -= 2 * FX32_ONE;
            }
            SetPos(m_destX + FX32_MUL(m_amplitude, dir), m_destY);
        }
        if (m_speed < 3) {
            m_speed++;
        }
        if (m_speed == 3) {
            m_phase = (m_phase == 0) ? 1 : 0;
            m_speed = 0;
        }
    }

    G3_Scale(m_scale, m_scale, m_scale);
}

BOOL CameraController::IsBusy()
{
    return m_flags != 0 ? TRUE : FALSE;
}

void CameraController::SetTarget(UnkStruct_0200D3F8_Target *target)
{
    m_target = target;
}
