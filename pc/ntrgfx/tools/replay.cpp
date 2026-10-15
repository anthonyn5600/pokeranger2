// ntrgfx_replay: renders a saved display-state snapshot to an image, without the game.
//
// usage: ntrgfx_replay SNAPSHOT OUT.ppm [HIDE]   (HIDE as NTRGFX_HIDE, e.g. "A0,BO")
//        ntrgfx_replay --info SNAPSHOT           (key display registers, decoded)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../ntrgfx.h"

static unsigned Io16(const NtrGfxMemory *m, unsigned o)
{
    return m->io[o] | (m->io[o + 1] << 8);
}

static unsigned Io32(const NtrGfxMemory *m, unsigned o)
{
    return Io16(m, o) | (Io16(m, o + 2) << 16);
}

static void PrintInfo(const NtrGfxMemory *m)
{
    unsigned pow = Io16(m, 0x304);
    printf("POWCNT %04x: LCD %u, A %u, 3D render %u, geometry %u, B %u, engine A on %s screen\n", pow, pow & 1, (pow >> 1) & 1, (pow >> 2) & 1, (pow >> 3) & 1, (pow >> 9) & 1, (pow & 0x8000) ? "top" : "bottom");
    for (int e = 0; e < 2; e++) {
        unsigned b = e ? 0x1000 : 0;
        unsigned d = Io32(m, b);
        printf("engine %c: DISPCNT %08x mode %u bgmode %u%s layers%s%s%s%s%s, MASTER_BRIGHT %04x, backdrop %04x\n", 'A' + e, d, (d >> 16) & 3, d & 7, (!e && (d & 8)) ? " BG0=3D" : "", (d & 0x100) ? " BG0" : "", (d & 0x200) ? " BG1" : "", (d & 0x400) ? " BG2" : "", (d & 0x800) ? " BG3" : "", (d & 0x1000) ? " OBJ" : "", Io16(m, b + 0x6C), m->pltt[e * 0x400] | (m->pltt[e * 0x400 + 1] << 8));
        for (int bg = 0; bg < 4; bg++) {
            printf("  BG%dCNT %04x HOFS %3u VOFS %3u\n", bg, Io16(m, b + 8 + bg * 2), Io16(m, b + 0x10 + bg * 4) & 0x1FF, Io16(m, b + 0x12 + bg * 4) & 0x1FF);
        }
        printf("  BLDCNT %04x BLDALPHA %04x BLDY %04x WININ %04x WINOUT %04x\n", Io16(m, b + 0x50), Io16(m, b + 0x52), Io16(m, b + 0x54), Io16(m, b + 0x48), Io16(m, b + 0x4A));
    }
    printf("VRAMCNT A-D %02x %02x %02x %02x E-G %02x %02x %02x H-I %02x %02x\n", m->io[0x240], m->io[0x241], m->io[0x242], m->io[0x243], m->io[0x244], m->io[0x245], m->io[0x246], m->io[0x248], m->io[0x249]);
    printf("DISP3DCNT %04x DISPCAPCNT %08x\n", Io16(m, 0x60), Io32(m, 0x64));
}

int main(int argc, char **argv)
{
    if (argc == 3 && strcmp(argv[1], "--info") == 0) {
        static NtrGfxMemory info;
        if (!NtrGfx_LoadSnapshot(argv[2], &info)) {
            fprintf(stderr, "%s: cannot load snapshot\n", argv[2]);
            return 1;
        }
        PrintInfo(&info);
        return 0;
    }
    if (argc < 3) {
        fprintf(stderr, "usage: %s SNAPSHOT OUT.ppm [HIDE]\n", argv[0]);
        return 2;
    }
    static NtrGfxMemory mem;
    static NtrGfxFrame frame;
    if (!NtrGfx_LoadSnapshot(argv[1], &mem)) {
        fprintf(stderr, "%s: cannot load snapshot (wrong file or older format)\n", argv[1]);
        return 1;
    }
    NtrGfx_SetHiddenLayers(argc > 3 ? argv[3] : getenv("NTRGFX_HIDE"));
    NtrGfx_RenderFrame(&mem, &frame);
    if (!NtrGfx_SaveFramePPM(argv[2], &frame)) {
        fprintf(stderr, "%s: cannot write\n", argv[2]);
        return 1;
    }
    return 0;
}
