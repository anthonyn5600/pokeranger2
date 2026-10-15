// Stage 1 glue: runs ntrgfx inside libntr. ntros's display timeline drives it (NtrOsDisplay): at line 0 it copies
// libntr's display state (register variables, VRAM/palette/OAM arrays) into ntrgfx, before each line the registers
// and palettes again (the game's line interrupts change them), and draws the line; after line 191 libntr shows the
// finished picture (SIM_Render -> SIM_ExtRenderFrame, local libntr patch) when the NTRGFX environment variable is 1. The game's geometry commands reach
// ntrgfx's geometry engine through libntr's G3 functions (SIM_ExtG3Command / SIM_ExtG3Fifo, local patch); ntrgfx
// draws the 3D picture itself (NTRGFX_3D=libntr: take libntr's OpenGL picture instead, SIM_Read3DImage). Display
// captures go back into libntr's VRAM.
//
// Debugging (environment variables):
//   NTRGFX=1                 use ntrgfx instead of libntr's renderer
//   NTRGFX=2                 compare: libntr renders and shows; at the dump frames ntrgfx renders the same frame too
//                            and dumps also write frame_N.ref.ppm (libntr's picture) and frame_N.cmp.ppm (libntr's
//                            picture | ntrgfx's | differences in red)
//   NTRGFX_DUMP_AT=600,900   save a snapshot + picture at these frame numbers (ntrgfx_replay re-renders snapshots)
//   NTRGFX_DUMP_EVERY=N      ... every N frames
//   NTRGFX_DUMP_DIR=dir      where (default ntrgfx_dumps)
//   NTRGFX_HIDE=A0,BO        leave layers out (see ntrgfx.h)
//   NTRGFX_3D=libntr         3D picture from libntr's renderer instead of ntrgfx's
//   NTRGFX_TRACK=1           record who writes display memory; dumps then include frame_N.writes (pc/tools/whowrote)
//   NTRGFX_TRACE=bgA:0x4000-0x4100   print writes to that range as they happen (vramtrack.cpp)
//   NTRGFX_G3LOG=N           print the geometry commands sent during frame N (command, parameters; FIFO words)

#include <nitro.h>
#include <set>
#include <simulator/simvariables.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/stat.h>

#include "../ntrgfx/ntrgfx.h"
#include "../ntros/ntros.h"
#include "vramtrack.hpp"

// libntr (local patch): this frame's 3D picture from its OpenGL renderer, 256x192 RGBA, top row first
extern "C" void SIM_Read3DImage(u8 *rgba);
// libntr (local patch): the presented window picture scaled to 256x384 RGBA (call before the swap)
extern "C" void SIM_ReadPresentedScreens(u8 *rgba);
extern "C" void SIM_PreRenderVBlank(void);
extern "C" void *SIM_Render(void *arg);
extern "C" void SIM_PostRenderVBlank(void);

namespace {

struct RegEntry {
    uint32_t offset;
    uint32_t size;
    volatile void *var;
};

const RegEntry kRegs[] = {
#include "regmap.inc"
};

const size_t kRegCount = sizeof(kRegs) / sizeof(kRegs[0]);

NtrGfxMemory sMem;
NtrGfx3DImage sImage3D;
NtrGfxPolygonList sPolygons; // the rendering engine's list (from the last SWAP_BUFFERS)
NtrGfxMemory sMemBefore; // for dumps
NtrGfxLineRegs sLineRegs; // for dumps: register changes between lines
NtrGfxFrame sFrame;
NtrGfxFrameRenderer *sRenderer; // the frame being drawn (NULL: ntrgfx doesn't draw this frame)
bool sDumpThisFrame;
bool sFrameReady; // sFrame holds a finished picture libntr hasn't shown yet
uint32_t sPrevRegs[kRegCount];
bool sFirstFrame = true;
uint32_t sFrameNo;
int sMode = -1; // 0 libntr, 1 ntrgfx, 2 compare
int sCompareFrame = -1; // compare mode: frame whose ntrgfx picture waits for libntr's
bool Libntr3D();

uint32_t ReadVar(const RegEntry &r)
{
    switch (r.size) {
    case 1:
        return *(volatile uint8_t *)r.var;
    case 2:
        return *(volatile uint16_t *)r.var;
    default:
        return *(volatile uint32_t *)r.var;
    }
}

// libntr has separate variables for some overlapping registers (e.g. VRAMCNT and VRAMCNT_A..D): copy only the ones
// that changed since the last frame, so the one the game wrote last wins. First frame: all, bigger ones first.
void CopyRegisters(bool lineChange = false)
{
    for (uint32_t pass = 4; pass >= 1; pass /= 2) {
        for (size_t i = 0; i < kRegCount; i++) {
            const RegEntry &r = kRegs[i];
            if (r.size != pass || r.offset + r.size > NTRGFX_IO_SIZE) {
                continue;
            }
            // Between lines DISPSTAT and VCOUNT always change (the timeline sets them); nothing draws with them
            if (lineChange && r.offset >= 0x004 && r.offset < 0x008) {
                continue;
            }
            uint32_t value = ReadVar(r);
            if (sFirstFrame || value != sPrevRegs[i]) {
                for (uint32_t b = 0; b < r.size; b++) {
                    sMem.io[r.offset + b] = (uint8_t)(value >> (b * 8));
                }
                sPrevRegs[i] = value;
            }
        }
    }
    sFirstFrame = false;
}

void CopyMemory()
{
    memcpy(&sMem.pltt[0x000], s_HW_BG_PLTT, 0x200);
    memcpy(&sMem.pltt[0x200], s_HW_OBJ_PLTT, 0x200);
    memcpy(&sMem.pltt[0x400], s_HW_DB_BG_PLTT, 0x200);
    memcpy(&sMem.pltt[0x600], s_HW_DB_OBJ_PLTT, 0x200);
    memcpy(&sMem.oam[0x000], s_HW_OAM, 0x400);
    memcpy(&sMem.oam[0x400], s_HW_DB_OAM, 0x400);
    memcpy(sMem.bgVramA, s_HW_BG_VRAM, sizeof(sMem.bgVramA));
    memcpy(sMem.objVramA, s_HW_OBJ_VRAM, sizeof(sMem.objVramA));
    memcpy(sMem.bgVramB, s_HW_DB_BG_VRAM, sizeof(sMem.bgVramB));
    memcpy(sMem.objVramB, s_HW_DB_OBJ_VRAM, sizeof(sMem.objVramB));
    memcpy(sMem.banks, s_HW_LCDC_VRAM, sizeof(sMem.banks));
}

void Copy3DImage()
{
    static uint8_t sRgba[NTRGFX_HEIGHT][NTRGFX_WIDTH][4];
    SIM_Read3DImage(&sRgba[0][0][0]);
    for (int y = 0; y < NTRGFX_HEIGHT; y++) {
        for (int x = 0; x < NTRGFX_WIDTH; x++) {
            const uint8_t *px = sRgba[y][x];
            sImage3D.color[y][x] = (uint32_t)((px[0] >> 2) | ((px[1] >> 2) << 6) | ((px[2] >> 2) << 12));
            sImage3D.alpha[y][x] = px[3] >> 3;
        }
    }
}

// ntrgfx did a display capture: libntr's copy of those VRAM banks gets the picture, its DISPCAPCNT the cleared bit
void WriteBackCapture(int banks)
{
    for (int bank = 0; bank < 4; bank++) {
        if (banks & (1 << bank)) {
            memcpy(&s_HW_LCDC_VRAM[bank * 0x20000], &sMem.banks[bank * 0x20000], 0x20000);
        }
    }
    s_reg_GX_DISPCAPCNT &= ~0x80000000u;
}

bool ShouldDump(uint32_t frame)
{
    static bool sInit;
    static std::set<uint32_t> sAt;
    static uint32_t sEvery;
    if (!sInit) {
        sInit = true;
        if (const char *at = getenv("NTRGFX_DUMP_AT")) {
            for (const char *p = at; *p;) {
                char *end;
                unsigned long n = strtoul(p, &end, 10);
                if (end == p) {
                    break;
                }
                sAt.insert((uint32_t)n);
                p = *end == ',' ? end + 1 : end;
            }
        }
        if (const char *every = getenv("NTRGFX_DUMP_EVERY")) {
            sEvery = (uint32_t)strtoul(every, NULL, 10);
        }
    }
    return sAt.count(frame) != 0 || (sEvery != 0 && frame % sEvery == 0);
}

std::string DumpPath(uint32_t frame)
{
    const char *dir = getenv("NTRGFX_DUMP_DIR");
    std::string base = dir != NULL ? dir : "ntrgfx_dumps";
    mkdir(base.c_str(), 0755);
    char name[64];
    snprintf(name, sizeof(name), "/frame_%06u", frame);
    return base + name;
}

// Compare mode: libntr's picture, and libntr | ntrgfx | differences (red where they differ) side by side
void DumpComparison(uint32_t frame)
{
    static uint8_t sRef[NTRGFX_HEIGHT * 2][NTRGFX_WIDTH][4];
    SIM_ReadPresentedScreens(&sRef[0][0][0]);
    std::string path = DumpPath(frame);
    FILE *ref = fopen((path + ".ref.ppm").c_str(), "wb");
    FILE *cmp = fopen((path + ".cmp.ppm").c_str(), "wb");
    if (ref == NULL || cmp == NULL) {
        fprintf(stderr, "ntrgfx: cannot write %s.{ref,cmp}.ppm\n", path.c_str());
        if (ref != NULL) {
            fclose(ref);
        }
        if (cmp != NULL) {
            fclose(cmp);
        }
        return;
    }
    fprintf(ref, "P6\n%d %d\n255\n", NTRGFX_WIDTH, NTRGFX_HEIGHT * 2);
    fprintf(cmp, "P6\n%d %d\n255\n", NTRGFX_WIDTH * 3, NTRGFX_HEIGHT * 2);
    uint32_t differing = 0;
    for (int y = 0; y < NTRGFX_HEIGHT * 2; y++) {
        const uint8_t(*ours)[4] = sFrame[y / NTRGFX_HEIGHT][y % NTRGFX_HEIGHT];
        for (int x = 0; x < NTRGFX_WIDTH; x++) {
            fwrite(sRef[y][x], 3, 1, ref);
            fwrite(sRef[y][x], 3, 1, cmp);
        }
        for (int x = 0; x < NTRGFX_WIDTH; x++) {
            fwrite(ours[x], 3, 1, cmp);
        }
        for (int x = 0; x < NTRGFX_WIDTH; x++) {
            // Differences beyond rounding (libntr's 8-bit vs our 6-bit output) in red, the rest dimmed
            int d = 0;
            for (int c = 0; c < 3; c++) {
                int v = sRef[y][x][c] - ours[x][c];
                d = v > d ? v : (-v > d ? -v : d);
            }
            uint8_t px[3];
            if (d > 12) {
                px[0] = 255, px[1] = 0, px[2] = 0;
                differing++;
            } else {
                px[0] = px[1] = px[2] = (uint8_t)((ours[x][0] + ours[x][1] + ours[x][2]) / 12);
            }
            fwrite(px, 3, 1, cmp);
        }
    }
    fclose(ref);
    fclose(cmp);
    fprintf(stderr, "ntrgfx: frame %u: %u of %u pixels differ from libntr (%s.cmp.ppm)\n", frame, differing, NTRGFX_WIDTH * NTRGFX_HEIGHT * 2, path.c_str());
}

void Dump(uint32_t frame)
{
    std::string path = DumpPath(frame);
    if (!NtrGfx_SaveSnapshot((path + ".snap").c_str(), &sMemBefore, &sImage3D, &sLineRegs, Libntr3D() ? NULL : &sPolygons) || !NtrGfx_SaveFramePPM((path + ".ppm").c_str(), &sFrame) || !VramTrack_Save((path + ".writes").c_str())) {
        fprintf(stderr, "ntrgfx: cannot write %s.*\n", path.c_str());
        return;
    }
    fprintf(stderr, "ntrgfx: dumped frame %u to %s.{snap,ppm}\n", frame, path.c_str());
}

NtrGfxGeometry *Geometry()
{
    static NtrGfxGeometry *sGeo = NtrGfx_GeometryCreate();
    return sGeo;
}

bool Libntr3D()
{
    static int sLibntr = -1;
    if (sLibntr < 0) {
        const char *env = getenv("NTRGFX_3D");
        sLibntr = env != NULL && strcmp(env, "libntr") == 0;
    }
    return sLibntr != 0;
}

} // namespace

namespace {

// What NitroSystem reads back (G3X_GetClipMtx, G3X_GetVectorMtx, test results) comes from our geometry engine
void WriteGeometryResults()
{
    static REGType32v *const clip[16] = { &s_reg_G3X_CLIPMTX_RESULT_0, &s_reg_G3X_CLIPMTX_RESULT_1, &s_reg_G3X_CLIPMTX_RESULT_2, &s_reg_G3X_CLIPMTX_RESULT_3, &s_reg_G3X_CLIPMTX_RESULT_4, &s_reg_G3X_CLIPMTX_RESULT_5, &s_reg_G3X_CLIPMTX_RESULT_6, &s_reg_G3X_CLIPMTX_RESULT_7, &s_reg_G3X_CLIPMTX_RESULT_8, &s_reg_G3X_CLIPMTX_RESULT_9, &s_reg_G3X_CLIPMTX_RESULT_10, &s_reg_G3X_CLIPMTX_RESULT_11, &s_reg_G3X_CLIPMTX_RESULT_12, &s_reg_G3X_CLIPMTX_RESULT_13, &s_reg_G3X_CLIPMTX_RESULT_14, &s_reg_G3X_CLIPMTX_RESULT_15 };
    static REGType32v *const vec[9] = { &s_reg_G3X_VECMTX_RESULT_0, &s_reg_G3X_VECMTX_RESULT_1, &s_reg_G3X_VECMTX_RESULT_2, &s_reg_G3X_VECMTX_RESULT_3, &s_reg_G3X_VECMTX_RESULT_4, &s_reg_G3X_VECMTX_RESULT_5, &s_reg_G3X_VECMTX_RESULT_6, &s_reg_G3X_VECMTX_RESULT_7, &s_reg_G3X_VECMTX_RESULT_8 };
    NtrGfxGeometryResults r;
    NtrGfx_GeometryResults(Geometry(), &r);
    for (int i = 0; i < 16; i++) {
        *clip[i] = (u32)r.clipMatrix[i];
    }
    for (int i = 0; i < 9; i++) {
        *vec[i] = (u32)r.vectorMatrix[i];
    }
    s_reg_G3X_POS_RESULT_X = (u32)r.position[0];
    s_reg_G3X_POS_RESULT_Y = (u32)r.position[1];
    s_reg_G3X_POS_RESULT_Z = (u32)r.position[2];
    s_reg_G3X_POS_RESULT_W = (u32)r.position[3];
    s_reg_G3X_VEC_RESULT_X = (u16)r.vector[0];
    s_reg_G3X_VEC_RESULT_Y = (u16)r.vector[1];
    s_reg_G3X_VEC_RESULT_Z = (u16)r.vector[2];
    // GXSTAT: test busy (bit 0) never, box test result (bit 1), geometry engine busy (bit 27) never
    s_reg_G3X_GXSTAT = (s_reg_G3X_GXSTAT & ~0x08000003u) | (r.boxInside ? 0x2u : 0u);
}

} // namespace

namespace {
bool G3LogThisFrame()
{
    static long sLogFrame = -2;
    if (sLogFrame == -2) {
        const char *env = getenv("NTRGFX_G3LOG");
        sLogFrame = env != NULL ? atol(env) : -1;
    }
    return sLogFrame >= 0 && (uint32_t)sLogFrame == sFrameNo;
}
} // namespace

// libntr G3 functions (local patch): one geometry command, and display lists sent to GXFIFO
extern "C" void SIM_ExtG3Command(u32 op, const u32 *params)
{
    if (G3LogThisFrame()) {
        fprintf(stderr, "G3 %02x", op);
        auto count = [](u32 o) {
            switch (o) {
            case 0x16: case 0x18: return 16;
            case 0x17: case 0x19: return 12;
            case 0x1A: return 9;
            case 0x1B: case 0x1C: case 0x70: return 3;
            case 0x23: case 0x71: return 2;
            case 0x34: return 32;
            case 0x11: case 0x15: case 0x41: return 0;
            default: return 1;
            }
        };
        for (int i = 0; params != NULL && i < count(op); i++) {
            fprintf(stderr, " %08x", params[i]);
        }
        fprintf(stderr, "\n");
    }
    NtrGfx_GeometryCommand(Geometry(), op, params);
    // Matrix commands change the clip / vector matrices; the tests set their results
    if ((op >= 0x10 && op <= 0x1C) || (op >= 0x70 && op <= 0x72)) {
        WriteGeometryResults();
    }
}

extern "C" void SIM_ExtG3Fifo(const void *words, u32 bytes)
{
    if (G3LogThisFrame()) {
        fprintf(stderr, "FIFO %u words:", bytes / 4);
        for (u32 i = 0; i < bytes / 4; i++) {
            fprintf(stderr, " %08x", ((const uint32_t *)words)[i]);
        }
        fprintf(stderr, "\n");
    }
    NtrGfx_GeometryFifo(Geometry(), (const uint32_t *)words, bytes / 4);
    WriteGeometryResults();
}

// libntr skips its own OpenGL 3D when ours draws the 3D picture
extern "C" int SIM_ExtOwns3D(void)
{
    static int sOwns = -1;
    if (sOwns < 0) {
        const char *env = getenv("NTRGFX");
        sOwns = env != NULL && atoi(env) == 1 && !Libntr3D();
    }
    return sOwns;
}

namespace {

void CopyPalettes()
{
    memcpy(&sMem.pltt[0x000], s_HW_BG_PLTT, 0x200);
    memcpy(&sMem.pltt[0x200], s_HW_OBJ_PLTT, 0x200);
    memcpy(&sMem.pltt[0x400], s_HW_DB_BG_PLTT, 0x200);
    memcpy(&sMem.pltt[0x600], s_HW_DB_OBJ_PLTT, 0x200);
}

void BeginFrame()
{
    VramTrack_SetFrame(sFrameNo);
    if (sMode < 0) {
        const char *env = getenv("NTRGFX");
        sMode = env == NULL ? 0 : atoi(env);
        if (sMode == 1) {
            fprintf(stderr, "ntrgfx: rendering with ntrgfx\n");
        } else if (sMode == 2) {
            fprintf(stderr, "ntrgfx: comparing ntrgfx with libntr at the dump frames\n");
        }
    }
    sDumpThisFrame = ShouldDump(sFrameNo);
    if (sMode != 1 && !(sMode == 2 && sDumpThisFrame)) {
        return;
    }
    CopyRegisters();
    CopyMemory();
    if (Libntr3D()) {
        Copy3DImage();
    } else {
        NtrGfx_Render3D(&sMem, &sPolygons, &sImage3D);
    }
    if (sDumpThisFrame) {
        // The snapshot is the state before rendering (capture changes VRAM), so a replay renders the same frame
        sMemBefore = sMem;
        memset(sLineRegs.changed, 0, sizeof(sLineRegs.changed));
    }
    sRenderer = NtrGfx_BeginFrame(&sMem, &sImage3D, &sFrame);
}

void DrawLine(int y)
{
    if (sRenderer == NULL) {
        return;
    }
    if (y != 0) {
        CopyRegisters(true);
        CopyPalettes();
        if (sDumpThisFrame && memcmp(sMem.io, y == 1 ? sMemBefore.io : sLineRegs.io[y - 1], NTRGFX_IO_SIZE) != 0) {
            sLineRegs.changed[y] = 1;
        }
        if (sDumpThisFrame) {
            memcpy(sLineRegs.io[y], sMem.io, NTRGFX_IO_SIZE);
        }
    } else if (sDumpThisFrame) {
        memcpy(sLineRegs.io[0], sMem.io, NTRGFX_IO_SIZE);
    }
    NtrGfx_RenderLine(sRenderer, y);
}

void EndFrame()
{
    if (sRenderer != NULL) {
        int captured = NtrGfx_EndFrame(sRenderer);
        sRenderer = NULL;
        // Compare mode: libntr does its own captures
        if (captured != 0 && sMode == 1) {
            WriteBackCapture(captured);
        }
        if (sDumpThisFrame) {
            Dump(sFrameNo);
        }
        if (sMode == 2) {
            sCompareFrame = (int)sFrameNo;
        } else {
            sFrameReady = true;
        }
    }
    sFrameNo++;
    // libntr shows the picture (ours via SIM_ExtRenderFrame, or its own), reads input and paces to 60 Hz
    SIM_PreRenderVBlank();
    SIM_Render(NULL);
    SIM_PostRenderVBlank();
}

// Line 192: a pending SWAP_BUFFERS hands the new polygon list to the rendering engine
void VBlank()
{
    NtrGfx_GeometryVBlank(Geometry(), &sPolygons);
}

struct RegisterDisplay {
    RegisterDisplay()
    {
        static const NtrOsDisplay display = { BeginFrame, DrawLine, EndFrame, VBlank };
        NtrOs_SetDisplay(&display);
    }
} sRegisterDisplay;

} // namespace

// rgba: 256x384, top screen first. Returns 0 to let libntr render instead.
extern "C" int SIM_ExtRenderFrame(uint8_t *rgba)
{
    if (!sFrameReady) {
        return 0;
    }
    sFrameReady = false;
    memcpy(rgba, sFrame, sizeof(sFrame));
    return 1;
}

// libntr: just before the buffer swap. Compare mode: libntr's picture of the frame ntrgfx rendered is ready.
extern "C" void SIM_ExtBeforeSwap(void)
{
    if (sCompareFrame >= 0) {
        DumpComparison((uint32_t)sCompareFrame);
        sCompareFrame = -1;
    }
}
