#include "Camera2D.hpp"

#include "fx_utils.hpp"

extern "C" {
extern Rectangle DAT_020842f8;
}

Camera2D::Camera2D()
{
    Init();
}

Camera2D::~Camera2D()
{
}

void Camera2D::Init()
{
    unk_1C = FX32_CONST(0);
    unk_20 = FX32_CONST(0);
    unk_26 = 22;
    unk_28 = 2;

    SetOrtho(FX32_CONST(0), FX32_CONST(GX_LCD_SIZE_Y), FX32_CONST(0), FX32_CONST(GX_LCD_SIZE_X), FX32_CONST(-1024), FX32_CONST(1024), FX32_CONST(16));
}

void Camera2D::SetOrtho(fx32 arg0, fx32 arg1, fx32 arg2, fx32 arg3, fx32 arg4, fx32 arg5, fx32 arg6)
{
    unk_00 = arg0;
    unk_04 = arg1;
    unk_08 = arg2;
    unk_0C = arg3;
    unk_10 = arg4;
    unk_14 = arg5;
    unk_18 = arg6;
}

void Camera2D::ApplyProjection()
{
    G3_ViewPort(0, 0, GX_LCD_SIZE_X - 1, GX_LCD_SIZE_Y - 1);
    G3_OrthoW(unk_00, unk_04, unk_08, unk_0C, unk_10, unk_14, unk_18, NULL);
    G3_MtxMode(GX_MTXMODE_POSITION);
}

void Camera2D::ApplyView()
{
    G3_Translate(unk_1C + FX32_CONST(GX_LCD_SIZE_X / 2), unk_20 + FX32_CONST(GX_LCD_SIZE_Y / 2), FX32_CONST(0));

    fx32 scale = 1 << unk_26;
    G3_Scale(scale, scale, scale);

    MtxFx33 mtx;
    MTX_RotZ33(&mtx, FX_SinIdx(unk_24), FX_CosIdx(unk_24));
    G3_MultMtx33(&mtx);
}

BOOL Camera2D::IsRectVisible(Rectangle *arg0, fx32 arg1)
{
    Rectangle v0 = DAT_020842f8;

    v0.pos.x = -unk_1C;
    v0.pos.y = -unk_20;

    if (arg1 != FX32_CONST(1)) {
        v0.size.x = FX32_MUL(v0.size.x, arg1);
        v0.size.y = FX32_MUL(v0.size.y, arg1);
    }

    return RectanglesOverlap(v0, *arg0);
}
