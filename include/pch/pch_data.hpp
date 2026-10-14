#ifndef POKERANGER2_PCH_DATA_HPP
#define POKERANGER2_PCH_DATA_HPP

// Constants the original defined in its precompiled header. mwcc keeps such initialized objects as pending data in
// the .mch and emits them at the very end of each TU that uses them (after the TU-end vtable/typeinfo passes), so
// they are the last-created objects in the TU's data size sort: defining them in a .cpp gives a different layout.

#include "Collision.hpp"

// CAC kinds of the water gun's nozzle and head sprites (CFieldEffectWaterGun).
static const int sWaterGunCacKinds[2] = { 0, 2 };

// Opening demo title screen (ov3 COPDTitleScreen): the stars' and sparks' emitter position and the screen's sprites.
static const Point2D sOPDStarOffset = { 0, -0x60000 };

struct OPDSpriteDef {
    fx32 x;
    fx32 y;
    fx32 width;
    fx32 height;
    fx32 s1;
    fx32 t1;
    fx32 s2;
    fx32 t2;
    int tex;
    int z;
};

static OPDSpriteDef sOPDSpriteDefs[7] = {
    { 0x1000, -0x63000, 0xB0000, 0x60000, 0, 0, 0xB0000, 0x60000, 5, 0x64 },
    { 0x1000, -0x6F000, 0xB0000, 0x50000, 0, 0, 0xB0000, 0x50000, 6, 0x66 },
    { 0x3C000, -0x78000, 0x88000, 0x30000, 0, 0, 0x88000, 0x30000, 0xD, 0x66 },
    { 0x1000, -0x40000, 0xB0000, 0x10000, 0, 0, 0xB0000, 0x10000, 0xE, 0x67 },
    { 0, 0x60000, 0x100000, 0x10000, 0, 0, 0x100000, 0x10000, 9, 0x65 },
    { 0, 0xB0000, 0x100000, 0x20000, 0, 0, 0x100000, 0x20000, 0xA, 0x65 },
    { 0, -0x70000, 0x100000, 0xC0000, 0, 0, 0x100000, 0xC0000, -0x1, 0x65 },
};

#endif // POKERANGER2_PCH_DATA_HPP
