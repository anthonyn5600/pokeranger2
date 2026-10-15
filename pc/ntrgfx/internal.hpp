// ntrgfx internals shared by the renderer's source files.
#ifndef NTRGFX_INTERNAL_HPP
#define NTRGFX_INTERNAL_HPP

#include <stdint.h>
#include <string.h>

#include "ntrgfx.h"

namespace ntrgfx {

// Little-endian reads
inline uint16_t Read16(const uint8_t *p)
{
    return (uint16_t)(p[0] | (p[1] << 8));
}

inline uint16_t Io16(const NtrGfxMemory *mem, uint32_t offset)
{
    return Read16(&mem->io[offset]);
}

inline uint32_t Io32(const NtrGfxMemory *mem, uint32_t offset)
{
    return Io16(mem, offset) | ((uint32_t)Io16(mem, offset + 2) << 16);
}

// A pixel inside the renderer: 6-bit R, G, B (the DS LCD's 18-bit color) in bits 0-5, 6-11, 12-17
typedef uint32_t Color18;

// 2D colors (15-bit) go to 6 bits per channel as X*2 (the 3D engine instead uses X*2+1 for non-zero values)
inline Color18 Color18From15(uint16_t c)
{
    uint32_t r = c & 0x1F, g = (c >> 5) & 0x1F, b = (c >> 10) & 0x1F;
    return (r << 1) | (g << 7) | (b << 13);
}

// Back to 15-bit (display capture stores 15-bit color): drop each channel's lowest bit
inline uint16_t Color15From18(Color18 c)
{
    return (uint16_t)(((c >> 1) & 0x1F) | (((c >> 7) & 0x1F) << 5) | (((c >> 13) & 0x1F) << 10));
}

const Color18 kWhite18 = 0x3FFFF;

// VRAM banks in NtrGfxMemory::banks (LCDC layout)
enum Bank {
    kBankA,
    kBankB,
    kBankC,
    kBankD,
    kBankE,
    kBankF,
    kBankG,
    kBankH,
    kBankI,
    kBankCount
};
extern const uint32_t kBankOffset[kBankCount];
extern const uint32_t kBankSize[kBankCount];

// Debug switches (debug.cpp)
enum Layer {
    kLayerBG0,
    kLayerBG1,
    kLayerBG2,
    kLayerBG3,
    kLayerOBJ,
    kLayer3D,
    kLayerCount
};
bool LayerHidden(int engine, Layer layer);
// NTRGFX_PIXEL=A,x,y (or B,x,y): print how that pixel was composited
bool PixelTraced(int engine, int x, int y);

// Layer line buffers: one entry per pixel
//   bits 0-17 color (Color18), bit 24 opaque
//   OBJ only: bits 25-26 priority, bit 27 semi-transparent, bit 28 bitmap OBJ, bits 18-21 bitmap alpha (0..15)
//   3D layer only: bit 29, bits 18-22 alpha (1..31)
const uint32_t kPixColor = 0x3FFFF;
const uint32_t kPixOpaque = 1u << 24;
const uint32_t kPixSemiTrans = 1u << 27;
const uint32_t kPixBitmap = 1u << 28;
const uint32_t kPix3D = 1u << 29;

inline uint32_t PixPriority(uint32_t pix)
{
    return (pix >> 25) & 3;
}

inline uint32_t PixAlpha(uint32_t pix)
{
    return (pix >> 18) & 0x1F;
}

// Color math for special effects, per 6-bit channel (GBATEK "LCD I/O Color Special Effects", there given for
// 5-bit channels)
Color18 BlendColors(Color18 first, Color18 second, uint32_t eva, uint32_t evb);
Color18 BrightenColor(Color18 color, uint32_t evy);
Color18 DarkenColor(Color18 color, uint32_t evy);

// What a BG layer is in the current BG mode (GBATEK "DS Video BG Modes / Control")
enum BgKind {
    kBgOff,
    kBgText,
    kBgAffine, // 8-bit map entries, 256-color tiles
    kBgExtTiles, // extended: affine with 16-bit map entries
    kBgBitmap256, // extended: 256-color bitmap
    kBgBitmapDirect, // extended: direct color bitmap
    kBgLarge, // mode 6 BG2: 256-color bitmap, all of engine A's BG VRAM
    kBg3D, // engine A BG0: the 3D layer
};

// A 2D graphics engine (0 = A, 1 = B): renders one 256-pixel line of its screen
class Engine2D {
public:
    Engine2D(const NtrGfxMemory *mem, int engine, const NtrGfx3DImage *image3D);
    // Every line, in order, before RenderLine (also when the engine is off): picks up register changes and advances
    // the affine BGs' internal reference points
    void BeginLine(int y);
    // The screen's line (after master brightness) into line; if graphics is not NULL, also the graphics screen
    // (BG+3D+OBJ before master brightness) for display capture, whatever the display mode
    void RenderLine(int y, Color18 *line, Color18 *graphics);

private:
    uint32_t Reg(uint32_t offset) const;
    uint16_t Reg16(uint32_t offset) const;
    uint8_t BgVram8(uint32_t addr) const;
    uint16_t BgVram16(uint32_t addr) const;
    uint8_t ObjVram8(uint32_t addr) const;
    uint16_t ObjVram16(uint32_t addr) const;
    const uint8_t *BgExtPalette(int slot) const;
    const uint8_t *ObjExtPalette() const;
    BgKind KindOfBG(int bg) const;
    const uint8_t *BgExtPaletteFor(int bg) const;

    void RenderGraphics(int y, Color18 *out);
    void RenderVramDisplay(int y, Color18 *line);
    void RenderTextBG(int bg, int y, uint32_t *out);
    void RenderAffineBG(int bg, BgKind kind, int y, uint32_t *out);
    void Render3DLayer(int y, uint32_t *out);
    void ApplyBgMosaic(int bg, uint32_t *out);
    void RenderOBJs(int y, uint32_t *out, uint8_t *objWindow);
    void RenderOBJ(int index, int y, uint32_t *out, uint8_t *objWindow);
    void WindowControls(int y, const uint8_t *objWindow, uint8_t *controls);
    void ApplyMasterBrightness(Color18 *line);

    const NtrGfxMemory *mMem;
    int mEngine;
    uint32_t mBase; // I/O offset of the engine's registers (0x000 / 0x1000)
    uint32_t mDispcnt;
    const uint8_t *mBgPltt;
    const uint8_t *mObjPltt;
    const uint8_t *mOam;
    const uint8_t *mBgVram;
    uint32_t mBgVramMask;
    const uint8_t *mObjVram;
    uint32_t mObjVramMask;
    const NtrGfx3DImage *mImage3D;
    // Affine BG2/BG3 internal reference points per line (20.8): loaded from BGxX/BGxY at line 0 and whenever the
    // game writes them, otherwise advanced by (PB, PD) every line
    int32_t mRefX[2][NTRGFX_HEIGHT];
    int32_t mRefY[2][NTRGFX_HEIGHT];
    int32_t mLastRegX[2];
    int32_t mLastRegY[2];
};

} // namespace ntrgfx

#endif // NTRGFX_INTERNAL_HPP
