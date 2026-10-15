// Stage 1 glue: runs ntrgfx inside libntr. Copies libntr's display state (register variables, VRAM/palette/OAM
// arrays) into ntrgfx each frame and gives libntr the finished picture (SIM_ExtRenderFrame, called from libntr's
// SIM_Render when the NTRGFX environment variable is 1; local libntr patch). The game's geometry commands reach
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

#include <nitro.h>
#include <set>
#include <simulator/simvariables.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/stat.h>

#include "../ntrgfx/ntrgfx.h"
#include "vramtrack.hpp"

// libntr (local patch): this frame's 3D picture from its OpenGL renderer, 256x192 RGBA, top row first
extern "C" void SIM_Read3DImage(u8 *rgba);
// libntr (local patch): the presented window picture scaled to 256x384 RGBA (call before the swap)
extern "C" void SIM_ReadPresentedScreens(u8 *rgba);

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
NtrGfxFrame sFrame;
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
void CopyRegisters()
{
    for (uint32_t pass = 4; pass >= 1; pass /= 2) {
        for (size_t i = 0; i < kRegCount; i++) {
            const RegEntry &r = kRegs[i];
            if (r.size != pass || r.offset + r.size > NTRGFX_IO_SIZE) {
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
    if (!NtrGfx_SaveSnapshot((path + ".snap").c_str(), &sMemBefore, &sImage3D, NULL, Libntr3D() ? NULL : &sPolygons) || !NtrGfx_SaveFramePPM((path + ".ppm").c_str(), &sFrame) || !VramTrack_Save((path + ".writes").c_str())) {
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

// libntr G3 functions (local patch): one geometry command, and display lists sent to GXFIFO
extern "C" void SIM_ExtG3Command(u32 op, const u32 *params)
{
    NtrGfx_GeometryCommand(Geometry(), op, params);
}

extern "C" void SIM_ExtG3Fifo(const void *words, u32 bytes)
{
    NtrGfx_GeometryFifo(Geometry(), (const uint32_t *)words, bytes / 4);
}

// rgba: 256x384, top screen first. Returns 0 to let libntr render instead.
extern "C" int SIM_ExtRenderFrame(uint8_t *rgba)
{
    VramTrack_SetFrame(sFrameNo);
    // VBlank: a pending SWAP_BUFFERS hands the new polygon list to the rendering engine
    NtrGfx_GeometryVBlank(Geometry(), &sPolygons);
    if (sMode < 0) {
        const char *env = getenv("NTRGFX");
        sMode = env == NULL ? 0 : atoi(env);
        if (sMode == 1) {
            fprintf(stderr, "ntrgfx: rendering with ntrgfx\n");
        } else if (sMode == 2) {
            fprintf(stderr, "ntrgfx: comparing ntrgfx with libntr at the dump frames\n");
        }
    }
    bool dump = ShouldDump(sFrameNo);
    if (sMode != 1 && !(sMode == 2 && dump)) {
        sFrameNo++;
        return 0;
    }

    CopyRegisters();
    CopyMemory();
    if (Libntr3D()) {
        Copy3DImage();
    } else {
        NtrGfx_Render3D(&sMem, &sPolygons, &sImage3D);
    }
    if (dump) {
        // The snapshot is the state before rendering (capture changes VRAM), so a replay renders the same frame
        sMemBefore = sMem;
    }
    int captured = NtrGfx_RenderFrame(&sMem, &sImage3D, &sFrame, NULL, NULL);
    // Compare mode: libntr does its own captures
    if (captured != 0 && sMode == 1) {
        WriteBackCapture(captured);
    }
    if (dump) {
        Dump(sFrameNo);
    }
    if (sMode == 2) {
        sCompareFrame = (int)sFrameNo;
        sFrameNo++;
        return 0;
    }
    sFrameNo++;
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
