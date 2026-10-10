#include "UnkClass_0200E330.hpp"

#include "fx_utils.hpp"

extern "C" {
extern u8 DAT_0208aaf8;
extern u16 DAT_0208aafa;
}

UnkClass_0200E330::UnkClass_0200E330(u8 screen)
{
    unk_0000 = 0;
    unk_0002 = screen;
    unk_0004 = 0;
    unk_0006 = 0;
    unk_000C = 0;
    unk_0010 = 0;
    unk_0008 = 0;
    unk_0014 = 0;
    unk_0018 = 0;
    unk_001C = 0;
    unk_0020 = (screen & 1) ? &reg_G2_WIN0H : &reg_G2S_DB_WIN0H;
}

void UnkClass_0200E330::sub_0200E378(int x, int y, u16 duration, u16 mode)
{
    unk_0008 = 320;
    unk_000C = x;
    unk_0010 = y;
    if (duration <= 3) {
        duration = 3;
    }
    unk_0004 = 0;
    unk_0006 = duration;
    unk_0014 = 0;
    unk_0018 = FX32_DIV(unk_0008 << FX32_SHIFT, (fx64)(duration << FX32_SHIFT));
    unk_0000 = mode & 3;

    int buffer = unk_001C == 0 ? 1 : 0;
    int radius = sub_0200E904();
    sub_0200E614(buffer, radius);
    sub_0200E6F8(buffer, radius);

    G2_SetWnd0InsidePlane(GX_WND_PLANEMASK_BG0 | GX_WND_PLANEMASK_BG1 | GX_WND_PLANEMASK_BG2 | GX_WND_PLANEMASK_BG3 | GX_WND_PLANEMASK_OBJ, FALSE);

    unk_0000 &= ~0x20;
    unk_0000 |= 0x18;
}

void UnkClass_0200E330::sub_0200E44C()
{
    if (!DAT_0208aaf8) {
        return;
    }
    if (!(unk_0000 & 8)) {
        return;
    }

    int buffer = unk_001C == 0 ? 1 : 0;
    sub_0200E6F8(buffer, sub_0200E904());
    sub_0200E834();
}

void UnkClass_0200E330::sub_0200E4A8()
{
    if (unk_0000 & 8) {
        if (unk_0000 & 0x40) {
            unk_001C = (unk_001C ^ 1) & 1;
            unk_0000 &= ~0x40;
        }
        if (unk_0000 & 0x10) {
            sub_0200E5C8(1);
            unk_0000 &= ~0x10;
        }
        if (unk_0000 & 0x20) {
            unk_0000 &= ~0x20;
            unk_0000 &= ~8;
        }
    }

    if (func0()) {
        UnkStruct_0200E330_Rect *rect = &unk_0028[unk_001C][0];
        if (unk_0002 & 1) {
            G2_SetWnd0Position(rect->x1, 0, rect->x2, 191);
        } else {
            G2S_SetWnd0Position(rect->x1, 0, rect->x2, 191);
        }
    }
}

u8 UnkClass_0200E330::sub_0200E5AC(int value, int min, int max)
{
    if (min > value) {
        return min;
    }
    if (max < value) {
        return max;
    }
    return value;
}

void UnkClass_0200E330::sub_0200E5C8(int windows)
{
    if (unk_0002 & 1) {
        GX_SetVisibleWnd(windows);
    } else {
        GXS_SetVisibleWnd(windows);
    }
    unk_0002 |= 4;
}

void UnkClass_0200E330::sub_0200E614(int buffer, int radius)
{
    for (int i = 0; i < 192; i++) {
        unk_0028[buffer][i].x1 = sub_0200E5AC(unk_000C - 1, 0, 255);
        unk_0028[buffer][i].x2 = sub_0200E5AC(unk_000C + 1, 0, 255);
        unk_0028[buffer][i].y1 = sub_0200E5AC(unk_0010 - radius, 0, 191);
        unk_0028[buffer][i].y2 = sub_0200E5AC(unk_0010 + radius + 2, 0, 191);
        unk_0860[buffer][i] = ((unk_0028[buffer][i].x1 << 8) & 0xFF00) | unk_0028[buffer][i].x2;
    }
}

void UnkClass_0200E330::sub_0200E6F8(int buffer, int radius)
{
    int i;
    int halfWidth;
    fx32 radiusSq = FX32_MUL(radius << FX32_SHIFT, radius << FX32_SHIFT);

    for (i = 0; i < 192; i++) {
        halfWidth = 0;
        if (i < unk_0010) {
            int dy = unk_0010 - i;
            if (dy < radius) {
                halfWidth = FX_Sqrt(radiusSq - FX32_MUL(dy << FX32_SHIFT, dy << FX32_SHIFT)) >> FX32_SHIFT;
            }
        } else if (i > unk_0010) {
            int dy = i - unk_0010;
            if (dy < radius) {
                halfWidth = FX_Sqrt(radiusSq - FX32_MUL(dy << FX32_SHIFT, dy << FX32_SHIFT)) >> FX32_SHIFT;
            }
        } else {
            halfWidth = radius;
        }

        if (halfWidth > 0) {
            unk_0028[buffer][i].x1 = sub_0200E5AC(unk_000C - halfWidth, 0, 255);
            unk_0028[buffer][i].x2 = sub_0200E5AC(unk_000C + halfWidth, 0, 255);
        } else {
            unk_0028[buffer][i].x1 = 128;
            unk_0028[buffer][i].x2 = 128;
        }
        unk_0860[buffer][i] = ((unk_0028[buffer][i].x1 << 8) & 0xFF00) | unk_0028[buffer][i].x2;
    }

    unk_0000 |= 0x40;
}

void UnkClass_0200E330::sub_0200E834()
{
    if (unk_0004 == unk_0006) {
        if (unk_0000 & 1) {
            sub_0200E5C8(0);
        }
        if (unk_0000 & 2) {
            unk_0024 = 0;
            unk_0025 = 0;
            unk_0026 = 1;
            unk_0027 = 1;
        }
        unk_0000 |= 0x20;
        unk_0002 &= ~4;
        return;
    }

    if (unk_0004 < unk_0006) {
        unk_0014 += FX32_DIV(FX32_MUL(unk_0018, FX32_CONST(60)), (fx64)(DAT_0208aafa << FX32_SHIFT));
        unk_0004++;
    }
}

int UnkClass_0200E330::sub_0200E904()
{
    int radius = unk_0014 >> FX32_SHIFT;
    if (!(unk_0000 & 1)) {
        radius = 320 - radius;
    }
    return radius;
}

BOOL UnkClass_0200E330::sub_0200E91C()
{
    BOOL result = FALSE;
    BOOL closing = FALSE;
    if (!func0() && (unk_0000 & 2)) {
        closing = TRUE;
    }
    if (closing && !(unk_0002 & 4)) {
        result = TRUE;
    }
    return result;
}
