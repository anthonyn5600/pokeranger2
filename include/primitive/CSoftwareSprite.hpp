#ifndef POKERANGER2_PRIMITIVE_CSOFTWARESPRITE_HPP
#define POKERANGER2_PRIMITIVE_CSOFTWARESPRITE_HPP

#include <nitro.h>

#include "primitive/CPrimitive.hpp"
#include "sub_02006000.hpp"

// TODO: Figure out what this is
class UnkClass_CSoftwareSprite_30 {
public:
    inline u32 GetUnk08()
    {
        return unk_08;
    }

public:
    UnkClass_CPrimitive_ImageProxy *unk_00;
    u8 unk_04[0x4];
    u32 unk_08;
};

// TODO: Figure out what this is
class UnkClass_CSoftwareSprite_38 {
public:
    u8 unk_00[0xB8];
    const NNSG2dCellDataBank *unk_B8;
};

class CSoftwareSprite : public CPrimitive {
public:
    CSoftwareSprite();
    virtual ~CSoftwareSprite();

    virtual u32 Render(Camera2D *camera);

    void SetTransformParams(fx32 posX, fx32 posY, fx32 scaleX, fx32 scaleY, u16 rotAngle, fx32 posZ);
    u16 sub_0200527C(Camera2D *camera);
    u16 sub_020058BC(Camera2D *camera);
    s16 GetObjPosX(const GXOamAttr *oamAttr);
    s16 GetObjPosY(const GXOamAttr *oamAttr);
    s16 FixObjPosX(s16 objPosX);
    s16 FixObjPosY(s16 objPosY);
    u32 ObjSizeToTexSize(u16 objSize);
    u16 GetCellNumOAMAttrs(u16 cellIdx);

    static u32 sub_020050C8(void);
    static u32 sub_02005120(void);

    inline Point2D GetPos()
    {
        return *(Point2D *)m_coords;
    }
    inline void SetPos(Point2D pos)
    {
        m_coords[0] = pos.x;
        m_coords[1] = pos.y;
    }

    inline void SetClipping(s16 x1, s16 x2, s16 y1, s16 y2)
    {
        m_clipping.x1 = x1;
        m_clipping.x2 = x2;
        m_clipping.y1 = y1;
        m_clipping.y2 = y2;
        m_clipping.enabled = TRUE;
    }

    inline void SetColorAlpha(GXRgb color, int alpha, BOOL arg2)
    {
        m_color = color;
        m_alpha = alpha;
        unk_3C = arg2;
    }

    inline void SetImage(UnkClass_CPrimitive_ImageProxy *image, UnkClass_CSoftwareSprite_30 *pal)
    {
        unk_2C = image;
        unk_30 = pal;
    }

    inline void SetScale(fx32 x, fx32 y)
    {
        m_scale[0] = x;
        m_scale[1] = y;
    }

    inline void SetXY(fx32 x, fx32 y)
    {
        m_coords[0] = x;
        m_coords[1] = y;
    }

public:
    struct Clipping {
        s16 x1;
        s16 x2;
        s16 y1;
        s16 y2;
        BOOL enabled;
    };

    fx32 m_coords[2];
    fx32 m_scale[2];
    u16 m_rotAngle;
    u16 m_cellDataIdx;
    UnkClass_CPrimitive_ImageProxy *unk_2C;
    UnkClass_CSoftwareSprite_30 *unk_30;
    UnkClass_CPrimitive_ImagePaletteProxy *unk_34;
    UnkClass_CSoftwareSprite_38 *unk_38;
    BOOL unk_3C;
    Clipping m_clipping;
};

#endif // POKERANGER2_PRIMITIVE_CSOFTWARESPRITE_HPP
