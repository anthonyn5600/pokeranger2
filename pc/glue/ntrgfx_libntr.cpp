// Stage 1 glue: runs ntrgfx on libntr's display state. ntros's display timeline drives it (NtrOsDisplay): at line 0
// it copies libntr's display state (register variables, VRAM/palette/OAM arrays) into ntrgfx, before each line the
// registers and palettes again (the game's line interrupts change them), and draws the line; after line 191 the
// frontend shows the finished picture. The game's geometry commands reach ntrgfx's geometry engine through libntr's
// G3 functions (SIM_ExtG3Command / SIM_ExtG3Fifo, local patch). Display captures go back into libntr's VRAM.
//
// Debugging (environment variables):
//   NTRGFX_DUMP_AT=600,900   save a snapshot + picture at these frame numbers (ntrgfx_replay re-renders snapshots)
//   NTRGFX_DUMP_EVERY=N      ... every N frames
//   NTRGFX_DUMP_DIR=dir      where (default ntrgfx_dumps)
//   NTRGFX_HIDE=A0,BO        leave layers out (see ntrgfx.h)
//   NTRGFX_TRACK=1           record who writes display memory; dumps then include frame_N.writes (pc/tools/whowrote)
//   NTRGFX_TRACE=bgA:0x4000-0x4100   print writes to that range as they happen (vramtrack.cpp)
//   NTRGFX_G3LOG=N           print the geometry commands sent during frame N (command, parameters; FIFO words)

#include <chrono>
#include <nitro.h>
#include <set>
#include <simulator/simvariables.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/stat.h>

#include "../frontend/frontend.h"
#include "../ntrgfx/ntrgfx.h"
#include "../ntros/ntros.h"
#include "vramtrack.hpp"

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
uint32_t sPrevRegs[kRegCount];
bool sFirstFrame = true;
uint32_t sFrameNo;

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
#ifdef _WIN32
    mkdir(base.c_str());
#else
    mkdir(base.c_str(), 0755);
#endif
    char name[64];
    snprintf(name, sizeof(name), "/frame_%06u", frame);
    return base + name;
}

void Dump(uint32_t frame)
{
    std::string path = DumpPath(frame);
    if (!NtrGfx_SaveSnapshot((path + ".snap").c_str(), &sMemBefore, &sImage3D, &sLineRegs, &sPolygons) || !NtrGfx_SaveFramePPM((path + ".ppm").c_str(), &sFrame) || !VramTrack_Save((path + ".writes").c_str())) {
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
            case 0x16:
            case 0x18:
                return 16;
            case 0x17:
            case 0x19:
                return 12;
            case 0x1A:
                return 9;
            case 0x1B:
            case 0x1C:
            case 0x70:
                return 3;
            case 0x23:
            case 0x71:
                return 2;
            case 0x34:
                return 32;
            case 0x11:
            case 0x15:
            case 0x41:
                return 0;
            default:
                return 1;
            }
        };
        for (int i = 0; params != NULL && i < count(op); i++) {
            fprintf(stderr, " %08x", params[i]);
        }
        fprintf(stderr, "\n");
    }
    NtrGfx_GeometryCommand(Geometry(), op, reinterpret_cast<const uint32_t *>(params)); // u32 is unsigned long on Windows
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

// libntr skips its own OpenGL 3D: ours draws the 3D picture
extern "C" int SIM_ExtOwns3D(void)
{
    return 1;
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
    sDumpThisFrame = ShouldDump(sFrameNo);
    CopyRegisters();
    CopyMemory();
    NtrGfx_Render3D(&sMem, &sPolygons, &sImage3D);
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

// PC_FPS_LOG=1: frames per second of real time, every 300 frames
void ReportFrameRate()
{
    static const bool sLog = getenv("PC_FPS_LOG") != NULL;
    static auto sStart = std::chrono::steady_clock::now();
    static int sFrames;
    if (!sLog || ++sFrames < 300) {
        return;
    }
    auto now = std::chrono::steady_clock::now();
    fprintf(stderr, "pc: %.2f frames/s\n", sFrames / std::chrono::duration<double>(now - sStart).count());
    sStart = now;
    sFrames = 0;
}

void EndFrame()
{
    if (sRenderer != NULL) {
        int captured = NtrGfx_EndFrame(sRenderer);
        sRenderer = NULL;
        if (captured != 0) {
            WriteBackCapture(captured);
        }
        if (sDumpThisFrame) {
            Dump(sFrameNo);
        }
    }
    sFrameNo++;
    ReportFrameRate();
    Frontend_ShowFrame(reinterpret_cast<const FrontendPicture *>(&sFrame));
}

// Sleep mode: dark screens
void SleepFrame()
{
    memset(sFrame, 0, sizeof(sFrame));
    Frontend_ShowFrame(reinterpret_cast<const FrontendPicture *>(&sFrame));
}

// Line 192: a pending SWAP_BUFFERS hands the new polygon list to the rendering engine
void VBlank()
{
    NtrGfx_GeometryVBlank(Geometry(), &sPolygons);
}

struct RegisterDisplay {
    RegisterDisplay()
    {
        static const NtrOsDisplay display = { BeginFrame, DrawLine, EndFrame, VBlank, SleepFrame };
        NtrOs_SetDisplay(&display);
    }
} sRegisterDisplay;

} // namespace
