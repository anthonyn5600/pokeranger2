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

// A screen pixel on its way out: 6-bit R, G, B (the DS LCD's 18-bit color) in bits 0-5, 6-11, 12-17
typedef uint32_t Color18;

inline Color18 Color18From15(uint16_t c)
{
    // 5 -> 6 bits per channel, as the hardware's 18-bit output stage
    uint32_t r = c & 0x1F, g = (c >> 5) & 0x1F, b = (c >> 10) & 0x1F;
    r = (r << 1) | (r >> 4);
    g = (g << 1) | (g >> 4);
    b = (b << 1) | (b >> 4);
    return r | (g << 6) | (b << 12);
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

// Layer line buffers: one entry per pixel
//   bits 0-14 color (15-bit), bit 15 opaque
//   OBJ only: bits 16-17 priority, bit 18 semi-transparent, bit 19 bitmap OBJ, bits 20-23 bitmap alpha
const uint32_t kPixOpaque = 0x8000;
const uint32_t kPixSemiTrans = 1u << 18;
const uint32_t kPixBitmap = 1u << 19;

// A 2D graphics engine (0 = A, 1 = B): renders one 256-pixel line of its screen
class Engine2D {
public:
    Engine2D(const NtrGfxMemory *mem, int engine);
    void RenderLine(int y, Color18 *line);

private:
    uint32_t Reg(uint32_t offset) const;
    uint16_t Reg16(uint32_t offset) const;
    uint8_t BgVram8(uint32_t addr) const;
    uint16_t BgVram16(uint32_t addr) const;
    uint8_t ObjVram8(uint32_t addr) const;
    uint16_t ObjVram16(uint32_t addr) const;
    const uint8_t *BgExtPalette(int slot) const;
    const uint8_t *ObjExtPalette() const;

    void RenderGraphics(int y, Color18 *line);
    void RenderVramDisplay(int y, Color18 *line);
    void RenderTextBG(int bg, int y, uint32_t *out);
    void RenderOBJs(int y, uint32_t *out, uint8_t *objWindow);
    void RenderOBJ(int index, int y, uint32_t *out, uint8_t *objWindow);
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
};

} // namespace ntrgfx

#endif // NTRGFX_INTERNAL_HPP
