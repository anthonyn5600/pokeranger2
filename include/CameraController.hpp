#ifndef POKERANGER2_CAMERACONTROLLER_HPP
#define POKERANGER2_CAMERACONTROLLER_HPP

#include <nitro.h>

#include "common.hpp"

struct UnkStruct_0200D3F8_Target {
    u8 unk_00[0x1C];
    fx32 x;
    fx32 y;
    u16 rotation;
};

class CameraController {
public:
    CameraController(UnkStruct_0200D3F8_Target *target);
    ~CameraController();

    void Reset();
    void SetPos(fx32 x, fx32 y);
    void SetScale(fx32 scale);
    void Move(fx32 dx, fx32 dy);
    void MoveTo(fx32 x, fx32 y, fx32 speed);
    void MoveToTimed(fx32 x, fx32 y, u16 frames);
    void Sway(fx32 amplitude, u16 speed, u16 duration);
    void ZoomTo(fx32 scale, u16 frames);
    void Spin(u16 speed, u16 duration);
    void SpinZoom(fx32 scale, u16 speed, u16 frames);
    void Shake(fx32 amplitude, u16 duration);
    void StartShake(fx32 amplitude);
    void StartShakeX(fx32 amplitude);
    void StopShake();
    void StopShakeX();
    void SetShakeAmplitude(fx32 amplitude);
    BOOL IsMoving();
    void Update();
    BOOL IsBusy();
    void SetTarget(UnkStruct_0200D3F8_Target *target);

public:
    UnkStruct_0200D3F8_Target *m_target;
    u16 m_flags;
    u16 m_frame;
    u16 m_duration;
    fx32 m_destX;
    fx32 m_destY;
    fx32 m_stepX;
    fx32 m_stepY;
    u16 m_speed;
    u16 m_phase;
    fx32 m_amplitude;
    fx32 m_scale;
};

STATIC_SIZE_ASSERT(CameraController, 0x28);

#endif // POKERANGER2_CAMERACONTROLLER_HPP
