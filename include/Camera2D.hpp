#ifndef POKERANGER2_CAMERA2D_HPP
#define POKERANGER2_CAMERA2D_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "common.hpp"

class Camera2D {
public:
    Camera2D();
    ~Camera2D();

    void Init();
    void SetOrtho(fx32 arg0, fx32 arg1, fx32 arg2, fx32 arg3, fx32 arg4, fx32 arg5, fx32 arg6);
    void ApplyProjection();
    void ApplyView();
    BOOL IsRectVisible(Rectangle *arg0, fx32 arg1);

    inline const Point2D &GetOffset()
    {
        return *(Point2D *)&unk_1C;
    }

    // By value: the caller's copy is an inline temp (stack slot below the caller's named locals).
    inline Point2D GetOffsetCopy()
    {
        return GetOffset();
    }

    inline void SetOffset(fx32 x, fx32 y)
    {
        unk_1C = x;
        unk_20 = y;
    }

    inline void SetOffset(const Point2D &offset)
    {
        unk_1C = offset.x;
        unk_20 = offset.y;
    }

    inline void SetOrigin(fx32 x, fx32 y)
    {
        unk_1C = 1 - x;
        unk_20 = 1 - y;
    }

public:
    fx32 unk_00;
    fx32 unk_04;
    fx32 unk_08;
    fx32 unk_0C;
    fx32 unk_10;
    fx32 unk_14;
    fx32 unk_18;
    fx32 unk_1C;
    fx32 unk_20;
    u16 unk_24;
    u16 unk_26;
    u16 unk_28;
};

STATIC_SIZE_ASSERT(Camera2D, 0x2C);

#endif // POKERANGER2_CAMERA2D_HPP
