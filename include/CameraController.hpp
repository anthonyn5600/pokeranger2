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
    void sub_0200D6E8(fx32 amplitude, u16 speed, u16 duration);
    void ZoomTo(fx32 scale, u16 frames);
    void sub_0200D7B8(u16 speed, u16 duration);
    void sub_0200D7F4(fx32 scale, u16 speed, u16 frames);
    void sub_0200D870(fx32 amplitude, u16 duration);
    void sub_0200D8C8(fx32 amplitude);
    void sub_0200D924(fx32 amplitude);
    void sub_0200D980();
    void sub_0200D994();
    void sub_0200D9A8(fx32 amplitude);
    BOOL sub_0200D9B8();
    void Update();
    BOOL IsBusy();
    void SetTarget(UnkStruct_0200D3F8_Target *target);

public:
    UnkStruct_0200D3F8_Target *unk_00;
    u16 unk_04;
    u16 unk_06;
    u16 unk_08;
    fx32 unk_0C;
    fx32 unk_10;
    fx32 unk_14;
    fx32 unk_18;
    u16 unk_1C;
    u16 unk_1E;
    fx32 unk_20;
    fx32 unk_24;
};

STATIC_SIZE_ASSERT(CameraController, 0x28);

#endif // POKERANGER2_CAMERACONTROLLER_HPP
