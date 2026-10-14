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
    unk_04 = 0;
    unk_06 = 0;
    unk_08 = 0;
    unk_0C = 0;
    unk_10 = 0;
    unk_14 = 0;
    unk_18 = 0;
    unk_20 = 0;
    unk_1E = 0;
    unk_24 = FX32_ONE;
}

void CameraController::SetPos(fx32 x, fx32 y)
{
    unk_00->x = x;
    unk_00->y = y;
}

void CameraController::SetScale(fx32 scale)
{
    unk_24 = scale;
}

void CameraController::Move(fx32 dx, fx32 dy)
{
    if (unk_00 == NULL) {
        return;
    }
    SetPos(dx + unk_00->x, dy + unk_00->y);
}

void CameraController::MoveTo(fx32 x, fx32 y, fx32 speed)
{
    UnkStruct_0200D3F8_Target *target = unk_00;
    if (target == NULL) {
        return;
    }
    if (unk_04 != 0) {
        return;
    }

    fx32 step = (speed * 60) / DAT_0208aaf4;
    fx32 dx = x - target->x;
    fx32 dy = y - target->y;
    fx32 dist = FX_Sqrt(FX32_MUL(dx, dx) + FX32_MUL(dy, dy));

    if (dist > step) {
        unk_14 = FX32_MUL(step, FX32_DIV(dx, dist));
        unk_18 = FX32_MUL(step, FX32_DIV(dy, dist));
        if (unk_14 == 0 && unk_18 == 0) {
            SetPos(x, y);
            unk_04 &= ~1;
            return;
        }
        unk_0C = x;
        unk_10 = y;
        unk_04 |= 1;
    } else {
        SetPos(x, y);
        unk_04 &= ~1;
    }
}

void CameraController::MoveToTimed(fx32 x, fx32 y, u16 frames)
{
    if (unk_00 == NULL) {
        return;
    }
    if (unk_04 != 0) {
        return;
    }

    u16 fps = DAT_0208aaf4;
    if (fps <= 30) {
        frames++;
    }
    frames = (frames * fps) / 60;

    unk_14 = FX32_DIV(x - unk_00->x, (fx64)(frames << FX32_SHIFT));
    unk_18 = FX32_DIV(y - unk_00->y, (fx64)(frames << FX32_SHIFT));
    unk_0C = x;
    unk_10 = y;
    unk_06 = 0;
    unk_08 = frames;
    unk_04 |= 2;
}

void CameraController::sub_0200D6E8(fx32 amplitude, u16 speed, u16 duration)
{
    if (unk_00 == NULL) {
        return;
    }
    if (unk_04 != 0) {
        return;
    }

    unk_20 = amplitude;
    unk_1E = 0x3FFF;
    unk_1C = speed;
    unk_0C = unk_00->x;
    unk_10 = unk_00->y;
    unk_06 = 0;
    unk_08 = duration;
    unk_04 |= 4;
}

void CameraController::ZoomTo(fx32 scale, u16 frames)
{
    if (unk_00 == NULL) {
        return;
    }
    if (unk_04 != 0) {
        return;
    }

    unk_20 = FX32_DIV(scale - unk_24, (fx64)(frames << FX32_SHIFT));
    unk_0C = scale;
    unk_06 = 0;
    unk_08 = frames;
    unk_04 |= 8;
}

void CameraController::sub_0200D7B8(u16 speed, u16 duration)
{
    if (unk_00 == NULL) {
        return;
    }
    if (unk_04 != 0) {
        return;
    }

    unk_1C = speed;
    unk_1E = 0;
    unk_06 = 0;
    unk_08 = duration;
    unk_04 |= 0x10;
}

void CameraController::sub_0200D7F4(fx32 scale, u16 speed, u16 frames)
{
    if (unk_00 == NULL) {
        return;
    }
    if (unk_04 != 0) {
        return;
    }

    unk_20 = FX32_DIV(scale - unk_24, (fx64)(frames << FX32_SHIFT));
    unk_0C = scale;
    unk_1C = speed;
    unk_1E = 0;
    unk_06 = 0;
    unk_08 = frames;
    unk_04 |= 0x20;
}

void CameraController::sub_0200D870(fx32 amplitude, u16 duration)
{
    if (unk_00 == NULL) {
        return;
    }
    if (unk_04 != 0) {
        return;
    }

    unk_20 = amplitude;
    unk_1C = 0;
    unk_1E = 0;
    unk_0C = unk_00->x;
    unk_10 = unk_00->y;
    unk_06 = 0;
    unk_08 = duration;
    unk_04 |= 0x40;
}

void CameraController::sub_0200D8C8(fx32 amplitude)
{
    if (unk_00 == NULL) {
        return;
    }
    if (unk_04 != 0) {
        return;
    }

    unk_20 = amplitude;
    unk_1C = 0;
    unk_1E = 0;
    unk_0C = unk_00->x;
    unk_10 = unk_00->y;
    unk_06 = 0;
    unk_08 = 1;
    unk_04 |= 0x100;
}

void CameraController::sub_0200D924(fx32 amplitude)
{
    if (unk_00 == NULL) {
        return;
    }
    if (unk_04 != 0) {
        return;
    }

    unk_20 = amplitude;
    unk_1C = 0;
    unk_1E = 0;
    unk_0C = unk_00->x;
    unk_10 = unk_00->y;
    unk_06 = 0;
    unk_08 = 1;
    unk_04 |= 0x200;
}

void CameraController::sub_0200D980()
{
    if (unk_04 & 0x100) {
        unk_06 = 1;
    }
}

void CameraController::sub_0200D994()
{
    if (unk_04 & 0x200) {
        unk_06 = 1;
    }
}

void CameraController::sub_0200D9A8(fx32 amplitude)
{
    if (unk_04 & 0x100) {
        unk_20 = amplitude;
    }
}

BOOL CameraController::sub_0200D9B8()
{
    return (unk_04 & 2) ? TRUE : FALSE;
}

void CameraController::Update()
{
    if (unk_00 == NULL) {
        return;
    }

    if (unk_04 & 1) {
        if (ABS(unk_0C - unk_00->x) < ABS(unk_14) || ABS(unk_10 - unk_00->y) < ABS(unk_18)) {
            SetPos(unk_0C, unk_10);
            unk_04 &= ~1;
        } else {
            Move(unk_14, unk_18);
        }
    }

    if (unk_04 & 2) {
        if (unk_06 == unk_08) {
            SetPos(unk_0C, unk_10);
            unk_04 &= ~2;
        }
        if (unk_06 < unk_08) {
            Move(unk_14, unk_18);
            unk_06++;
        }
    }

    if (unk_04 & 4) {
        if (0xFFFF - unk_1E < unk_1C) {
            unk_1E = 0;
        } else {
            SetPos(unk_0C + FX32_MUL(unk_20, FX_CosIdx(unk_1E)), unk_10);
            unk_1E += unk_1C;
        }
        if (0x3FFF - unk_1C < unk_1E && unk_1C + 0x3FFF > unk_1E && unk_06 == unk_08) {
            SetPos(unk_0C, unk_10);
            unk_04 &= ~4;
        }
        if (unk_06 < unk_08) {
            unk_06++;
        }
    }

    if (unk_04 & 8) {
        if (unk_06 == unk_08) {
            SetScale(unk_0C);
            unk_04 &= ~8;
        }
        if (unk_06 < unk_08) {
            SetScale(unk_24 + unk_20);
            unk_06++;
        }
    }

    if (unk_04 & 0x10) {
        if (0xFFFF - unk_1E < unk_1C) {
            if (unk_06 == unk_08) {
                unk_00->rotation = 0;
                unk_04 &= ~0x10;
            }
            unk_1E = 0;
        } else {
            unk_00->rotation = unk_1E;
            unk_1E += unk_1C;
        }
        if (unk_06 < unk_08) {
            unk_06++;
        }
    }

    if (unk_04 & 0x20) {
        if (0xFFFF - unk_1E < unk_1C) {
            if (unk_06 == unk_08) {
                SetScale(unk_0C);
                unk_00->rotation = 0;
                unk_04 &= ~0x20;
            }
            unk_1E = 0;
        } else {
            unk_00->rotation = unk_1E;
            unk_1E += unk_1C;
        }
        if (unk_06 < unk_08) {
            SetScale(unk_24 + unk_20);
            unk_06++;
        }
    }

    if (unk_04 & 0x40) {
        if (unk_06 == unk_08) {
            SetPos(unk_0C, unk_10);
            unk_04 &= ~0x40;
        }
        if (unk_06 < unk_08) {
            SetPos(unk_0C + FX32_MUL(unk_20, DAT_020843f8[unk_1E]), unk_10 + FX32_MUL(unk_20, DAT_02084410[unk_1E]));
            unk_06++;
        }
        if (unk_1C < 3) {
            unk_1C++;
        }
        if (unk_1C == 3) {
            if (unk_1E < 6) {
                unk_1E++;
            }
            if (unk_1E == 6) {
                unk_1E = 0;
            }
            unk_1C = 0;
        }
    }

    if (unk_04 & 0x80) {
        if (0xFFFF - unk_1E < unk_1C) {
            unk_1E = 0;
        } else {
            SetPos(unk_0C + FX32_MUL(unk_20, FX_CosIdx(unk_1E)), unk_10);
            unk_1E += unk_1C;
        }
        if (0x3FFF - unk_1C < unk_1E && unk_1C + 0x3FFF > unk_1E && unk_06 == unk_08) {
            SetPos(unk_0C, unk_10);
            unk_04 &= ~0x80;
        }
    }

    if (unk_04 & 0x100) {
        if (unk_06 == unk_08) {
            SetPos(unk_0C, unk_10);
            unk_04 &= ~0x100;
        }
        if (unk_06 < unk_08) {
            SetPos(unk_0C + FX32_MUL(unk_20, DAT_020843f8[unk_1E]), unk_10 + FX32_MUL(unk_20, DAT_02084410[unk_1E]));
        }
        if (unk_1C < 3) {
            unk_1C++;
        }
        if (unk_1C == 3) {
            if (unk_1E < 6) {
                unk_1E++;
            }
            if (unk_1E == 6) {
                unk_1E = 0;
            }
            unk_1C = 0;
        }
    }

    if (unk_04 & 0x200) {
        if (unk_06 == unk_08) {
            SetPos(unk_0C, unk_10);
            unk_04 &= ~0x200;
        }
        if (unk_06 < unk_08) {
            fx32 dir = FX32_ONE;
            if (unk_1E != 0) {
                dir -= 2 * FX32_ONE;
            }
            SetPos(unk_0C + FX32_MUL(unk_20, dir), unk_10);
        }
        if (unk_1C < 3) {
            unk_1C++;
        }
        if (unk_1C == 3) {
            unk_1E = (unk_1E == 0) ? 1 : 0;
            unk_1C = 0;
        }
    }

    G3_Scale(unk_24, unk_24, unk_24);
}

BOOL CameraController::IsBusy()
{
    return unk_04 != 0 ? TRUE : FALSE;
}

void CameraController::SetTarget(UnkStruct_0200D3F8_Target *target)
{
    unk_00 = target;
}
