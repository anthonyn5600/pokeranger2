#ifndef POKERANGER2_FIELD_CMESHSPRITE_HPP
#define POKERANGER2_FIELD_CMESHSPRITE_HPP

#include <nitro.h>

#include "Collision.hpp"
#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "primitive/CPrimitive.hpp"

class CNCERFile;

// One OAM of a cell drawn as a textured quad strip of m_rows rows, each row's edge shifted by m_rowOffsets.
class CMeshSprite : public CPrimitive {
public:
    CMeshSprite(u8 rows); // ov0_02168F60
    virtual u32 Render(Camera2D *camera);

    void SetRes(VramImage *image, VramPalette *palette, CNCERFile *ncer); // ov0_02168FE4
    BOOL SetCell(u16 cellIdx, u16 oamIdx); // ov0_02168FF4

public:
    Point2D m_pos;
    fx32 m_scaleX;
    fx32 m_scaleY;
    fx32 m_skewY;
    fx32 m_skewX;
    fx32 m_stretchX;
    fx32 m_stretchY;
    s16 m_rot;
    u16 m_plttOffset;
    s16 m_x1;
    s16 m_y1;
    s16 m_x2;
    s16 m_y2;
    fx32 m_s1;
    fx32 m_t1;
    fx32 m_s2;
    fx32 m_t2;
    s16 m_rowOffsets[5];
    VramImage *m_image;
    VramPalette *m_palette;
    CNCERFile *m_ncer;
    int m_cellIdx;
    u8 m_rows;
};

STATIC_SIZE_ASSERT(CMeshSprite, 0x74);

#endif // POKERANGER2_FIELD_CMESHSPRITE_HPP
