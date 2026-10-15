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

// The 3D engine's picture, as engine A's BG0 (3D layer) and display capture source A see it
typedef struct NtrGfx3DImage {
    uint32_t color[NTRGFX_HEIGHT][NTRGFX_WIDTH]; // 6-bit R, G, B in bits 0-5, 6-11, 12-17
    uint8_t alpha[NTRGFX_HEIGHT][NTRGFX_WIDTH]; // 0 (transparent) .. 31 (opaque)
} NtrGfx3DImage;

// 3D: the Geometry Engine turns geometry commands into a polygon list; SWAP_BUFFERS hands that list to the
// Rendering Engine, which draws it into an NtrGfx3DImage (GBATEK "DS 3D Overview").
#define NTRGFX_MAX_POLYGONS 2048
#define NTRGFX_MAX_VERTICES 6144
typedef struct NtrGfxVertex3D {
    int32_t x, y; // screen position in pixels, upper-left origin (0..256, 0..192)
    int32_t z; // 24-bit Z depth (0..0xFFFFFF)
    int32_t w; // clip-space W (1+19+12 fixed point), > 0
    int16_t s, t; // texture coordinates (1+11+4 fixed point)
    uint16_t color[3]; // R, G, B: 6-bit color with 3 fractional bits (0..511)
} NtrGfxVertex3D;
typedef struct NtrGfxPolygon3D {
    uint32_t attr; // POLYGON_ATTR at the polygon's BEGIN_VTXS
    uint32_t texParam; // TEXIMAGE_PARAM
    uint32_t texPltt; // PLTT_BASE
    uint8_t numVertices; // 3..10 (clipping can add vertices)
    uint8_t wBuffer; // depth buffering with W (SWAP_BUFFERS bit 1 in effect)
    uint8_t backFacing; // 1 = the back side faces the viewer
    uint8_t line; // 1 = line segment / degenerate (rendered from both sides)
    uint16_t vertices[10]; // indices into NtrGfxPolygonList::vertices, in order around the polygon
} NtrGfxPolygon3D;
typedef struct NtrGfxPolygonList {
    uint32_t numPolygons;
    uint32_t numVertices;
    uint32_t manualSort; // SWAP_BUFFERS bit 0: translucent polygons keep their order
    NtrGfxPolygon3D polygons[NTRGFX_MAX_POLYGONS];
    NtrGfxVertex3D vertices[NTRGFX_MAX_VERTICES];
} NtrGfxPolygonList;

typedef struct NtrGfxGeometry NtrGfxGeometry;
// Power-on state (identity matrices, empty lists)
NtrGfxGeometry *NtrGfx_GeometryCreate(void);
void NtrGfx_GeometryDestroy(NtrGfxGeometry *geo);
// One command (0x10..0x72) with all its parameters, as written to its port (0x4000440 + ...)
void NtrGfx_GeometryCommand(NtrGfxGeometry *geo, uint32_t op, const uint32_t *params);
// DISP_1DOT_DEPTH (0x4000610): not routed through the FIFO, takes effect at once
void NtrGfx_GeometrySet1DotDepth(NtrGfxGeometry *geo, uint32_t value);
// Words written to GXFIFO (0x4000400): packed or unpacked commands with their parameters (display lists)
void NtrGfx_GeometryFifo(NtrGfxGeometry *geo, const uint32_t *words, uint32_t count);
// VBlank: if SWAP_BUFFERS was sent, copies the finished polygon list to out, empties the geometry engine's list and
// returns 1; otherwise returns 0 (the rendering engine keeps drawing its old list).
int NtrGfx_GeometryVBlank(NtrGfxGeometry *geo, NtrGfxPolygonList *out);
// Draws a polygon list with the rendering registers (mem->io 0x060, 0x330..0x3BF) and texture VRAM (mem->banks as
// mapped by VRAMCNT)
void NtrGfx_Render3D(const NtrGfxMemory *mem, const NtrGfxPolygonList *list, NtrGfx3DImage *out);

// RGBA8888, top screen then bottom screen
typedef uint8_t NtrGfxFrame[2][NTRGFX_HEIGHT][NTRGFX_WIDTH][4];

// Register changes between lines (raster effects: the game's HBlank / VCount interrupt handlers, HBlank DMA)
typedef struct NtrGfxLineRegs {
    uint8_t changed[NTRGFX_HEIGHT]; // 1: io[y] holds all registers from line y on
    uint8_t io[NTRGFX_HEIGHT][NTRGFX_IO_SIZE];
} NtrGfxLineRegs;

// Called before line y (0..191) of both screens is drawn; may change mem->io (register writes between lines)
typedef void (*NtrGfxLineHook)(int y, NtrGfxMemory *mem, void *user);

// A line hook that applies an NtrGfxLineRegs (user)
void NtrGfx_ApplyLineRegs(int y, NtrGfxMemory *mem, void *lineRegs);

// Renders both screens, line by line. image3D may be NULL (no 3D picture: the 3D layer is transparent). hook may be
// NULL (registers fixed for the frame).
// Display capture (DISPCAPCNT) writes into mem->banks and clears the capture enable bit in mem->io, as the hardware
// does; returns the VRAM banks it wrote (bit 0 = A .. bit 3 = D), 0 if none.
int NtrGfx_RenderFrame(NtrGfxMemory *mem, const NtrGfx3DImage *image3D, NtrGfxFrame *out, NtrGfxLineHook hook, void *user);

// Debugging
// Layers to leave out, e.g. "A0,A3,AO,B2,A3D": engine (A/B) + BG number, O = OBJ, 3D = engine A's 3D layer.
// Also read from the NTRGFX_HIDE environment variable on first use.
void NtrGfx_SetHiddenLayers(const char *spec);
// Prints "ntrgfx: unsupported: <what>" once per distinct text.
void NtrGfx_WarnOnce(const char *what);
// Snapshot = the display state, the 3D picture, the register changes between lines and the 3D polygon list the
// picture was drawn from (NULL when saving: none / transparent; older snapshots load with none). Load returns 0 on
// error, 2 if the snapshot had a polygon list (and list != NULL), else 1.
int NtrGfx_SaveSnapshot(const char *path, const NtrGfxMemory *mem, const NtrGfx3DImage *image3D, const NtrGfxLineRegs *lineRegs, const NtrGfxPolygonList *list);
int NtrGfx_LoadSnapshot(const char *path, NtrGfxMemory *mem, NtrGfx3DImage *image3D, NtrGfxLineRegs *lineRegs, NtrGfxPolygonList *list);
// Both screens stacked (256x384) as a binary PPM
int NtrGfx_SaveFramePPM(const char *path, const NtrGfxFrame *frame);

#ifdef __cplusplus
}
#endif

#endif // NTRGFX_H
