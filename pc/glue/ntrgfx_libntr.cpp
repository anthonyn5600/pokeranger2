// Stage 1 glue: runs ntrgfx inside libntr. Copies libntr's display state (register variables, VRAM/palette/OAM
// arrays) into ntrgfx each frame and gives libntr the finished picture (SIM_ExtRenderFrame, called from libntr's
// SIM_Render when the NTRGFX environment variable is 1; local libntr patch).
//
// Debugging (environment variables):
//   NTRGFX=1                 use ntrgfx instead of libntr's renderer
//   NTRGFX_DUMP_AT=600,900   save a snapshot + picture at these frame numbers (ntrgfx_replay re-renders snapshots)
//   NTRGFX_DUMP_EVERY=N      ... every N frames
//   NTRGFX_DUMP_DIR=dir      where (default ntrgfx_dumps)
//   NTRGFX_HIDE=A0,BO        leave layers out (see ntrgfx.h)

#include <nitro.h>
#include <set>
#include <simulator/simvariables.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/stat.h>

#include "../ntrgfx/ntrgfx.h"

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
NtrGfxFrame sFrame;
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

void Dump(uint32_t frame)
{
    const char *dir = getenv("NTRGFX_DUMP_DIR");
    std::string base = dir != NULL ? dir : "ntrgfx_dumps";
    mkdir(base.c_str(), 0755);
    char name[64];
    snprintf(name, sizeof(name), "/frame_%06u", frame);
    std::string path = base + name;
    if (!NtrGfx_SaveSnapshot((path + ".snap").c_str(), &sMem) || !NtrGfx_SaveFramePPM((path + ".ppm").c_str(), &sFrame)) {
        fprintf(stderr, "ntrgfx: cannot write %s.*\n", path.c_str());
        return;
    }
    fprintf(stderr, "ntrgfx: dumped frame %u to %s.{snap,ppm}\n", frame, path.c_str());
}

} // namespace

// rgba: 256x384, top screen first. Returns 0 to let libntr render instead.
extern "C" int SIM_ExtRenderFrame(uint8_t *rgba)
{
    static int sEnabled = -1;
    if (sEnabled < 0) {
        const char *env = getenv("NTRGFX");
        sEnabled = env != NULL && strcmp(env, "1") == 0;
        if (sEnabled) {
            fprintf(stderr, "ntrgfx: rendering with ntrgfx\n");
        }
    }
    if (!sEnabled) {
        return 0;
    }

    CopyRegisters();
    CopyMemory();
    NtrGfx_RenderFrame(&sMem, &sFrame);
    if (ShouldDump(sFrameNo)) {
        Dump(sFrameNo);
    }
    sFrameNo++;
    memcpy(rgba, sFrame, sizeof(sFrame));
    return 1;
}
