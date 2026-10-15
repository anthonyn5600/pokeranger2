// ntrgfx: the PC port's DS graphics renderer (2D engines A/B, 3D, display capture), written from GBATEK.
//
// The renderer works from its own copy of the display state (NtrGfxMemory): the caller copies the game's registers
// and video memory in, then calls NtrGfx_RenderFrame. That copy is also the debug snapshot format: saved to a file,
// it re-renders the same frame anywhere (pc/ntrgfx/tools/replay.cpp), without the game.
#ifndef NTRGFX_H
#define NTRGFX_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NTRGFX_WIDTH  256
#define NTRGFX_HEIGHT 192

// I/O registers 0x04000000..0x040010FF at their DS offsets (engine A 0x000.., 3D 0x060 / 0x320..0x3FF, power 0x304,
// engine B 0x1000..)
#define NTRGFX_IO_SIZE 0x1100

typedef struct NtrGfxMemory {
    uint8_t io[NTRGFX_IO_SIZE];
    uint8_t pltt[0x800]; // 0x05000000: engine A BG, A OBJ, B BG, B OBJ (0x200 each)
    uint8_t oam[0x800]; // 0x07000000: engine A, engine B (0x400 each)
    uint8_t bgVramA[0x80000]; // 0x06000000
    uint8_t objVramA[0x40000]; // 0x06400000
    uint8_t bgVramB[0x20000]; // 0x06200000
    uint8_t objVramB[0x20000]; // 0x06600000
    uint8_t banks[0xA4000]; // VRAM banks A..I in LCDC layout (0x06800000): textures, palettes, captures
} NtrGfxMemory;

// RGBA8888, top screen then bottom screen
typedef uint8_t NtrGfxFrame[2][NTRGFX_HEIGHT][NTRGFX_WIDTH][4];

void NtrGfx_RenderFrame(const NtrGfxMemory *mem, NtrGfxFrame *out);

// Debugging
// Layers to leave out, e.g. "A0,A3,AO,B2,A3D": engine (A/B) + BG number, O = OBJ, 3D = engine A's 3D layer.
// Also read from the NTRGFX_HIDE environment variable on first use.
void NtrGfx_SetHiddenLayers(const char *spec);
// Prints "ntrgfx: unsupported: <what>" once per distinct text.
void NtrGfx_WarnOnce(const char *what);
int NtrGfx_SaveSnapshot(const char *path, const NtrGfxMemory *mem);
int NtrGfx_LoadSnapshot(const char *path, NtrGfxMemory *mem);
// Both screens stacked (256x384) as a binary PPM
int NtrGfx_SaveFramePPM(const char *path, const NtrGfxFrame *frame);

#ifdef __cplusplus
}
#endif

#endif // NTRGFX_H
