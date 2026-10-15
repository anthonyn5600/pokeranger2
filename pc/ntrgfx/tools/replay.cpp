// ntrgfx_replay: renders a saved display-state snapshot to an image, without the game.
//
// usage: ntrgfx_replay SNAPSHOT OUT.ppm [HIDE]   (HIDE as NTRGFX_HIDE, e.g. "A0,BO")
//        ntrgfx_replay --info SNAPSHOT           (key display registers, decoded)
//        ntrgfx_replay --polys SNAPSHOT          (the snapshot's polygon list)
//        ntrgfx_replay --region SNAPSHOT X0 Y0 X1 Y1   (3D coverage there: stored | ours; '#' opaque, '+' translucent)
//        ntrgfx_replay --diffs SNAPSHOT [N]       (first N 3D pixels that differ: stored vs ours, RGB6 + alpha)
//        ntrgfx_replay --compare3d SNAPSHOT OUT.ppm
//            draws the snapshot's polygon list with our 3D renderer and compares it with the snapshot's 3D picture:
//            OUT = stored | ours | differences (red: color, blue: alpha only); prints the count
// With a polygon list in the snapshot, the 3D layer is drawn from it (NTRGFX_REPLAY_3D=image: use the stored picture).

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
        printf("  BLDCNT %04x BLDALPHA %04x BLDY %04x WININ %04x WINOUT %04x WIN0 H %04x V %04x WIN1 H %04x V %04x MOSAIC %04x\n", Io16(m, b + 0x50), Io16(m, b + 0x52), Io16(m, b + 0x54), Io16(m, b + 0x48), Io16(m, b + 0x4A), Io16(m, b + 0x40), Io16(m, b + 0x44), Io16(m, b + 0x42), Io16(m, b + 0x46), Io16(m, b + 0x4C));
        for (int bg = 2; bg < 4; bg++) {
            unsigned p = b + 0x20 + (bg - 2) * 0x10;
            printf("  BG%d affine PA %04x PB %04x PC %04x PD %04x X %08x Y %08x\n", bg, Io16(m, p), Io16(m, p + 2), Io16(m, p + 4), Io16(m, p + 6), Io32(m, p + 8), Io32(m, p + 12));
        }
    }
    printf("VRAMCNT A-D %02x %02x %02x %02x E-G %02x %02x %02x H-I %02x %02x\n", m->io[0x240], m->io[0x241], m->io[0x242], m->io[0x243], m->io[0x244], m->io[0x245], m->io[0x246], m->io[0x248], m->io[0x249]);
    printf("DISP3DCNT %04x DISPCAPCNT %08x\n", Io16(m, 0x60), Io32(m, 0x64));
}

static int Compare3D(const char *snapPath, const char *outPath)
{
    static NtrGfxMemory mem;
    static NtrGfx3DImage stored, ours;
    static NtrGfxPolygonList list;
    if (NtrGfx_LoadSnapshot(snapPath, &mem, &stored, NULL, &list) != 2) {
        fprintf(stderr, "%s: no polygon list in the snapshot\n", snapPath);
        return 1;
    }
    NtrGfx_Render3D(&mem, &list, &ours);
    FILE *f = fopen(outPath, "wb");
    if (f == NULL) {
        fprintf(stderr, "%s: cannot write\n", outPath);
        return 1;
    }
    fprintf(f, "P6\n%d %d\n255\n", NTRGFX_WIDTH * 3, NTRGFX_HEIGHT);
    unsigned colorDiff = 0, alphaDiff = 0;
    auto put = [&](uint32_t c, uint8_t a) {
        // Over a checkerboard-free gray: transparent pixels dark
        uint8_t px[3];
        for (int ch = 0; ch < 3; ch++) {
            uint32_t i = (c >> (ch * 6)) & 0x3F;
            px[ch] = a == 0 ? 24 : (uint8_t)((i << 2) | (i >> 4));
        }
        fwrite(px, 3, 1, f);
    };
    for (int y = 0; y < NTRGFX_HEIGHT; y++) {
        for (int x = 0; x < NTRGFX_WIDTH; x++) {
            put(stored.color[y][x], stored.alpha[y][x]);
        }
        for (int x = 0; x < NTRGFX_WIDTH; x++) {
            put(ours.color[y][x], ours.alpha[y][x]);
        }
        for (int x = 0; x < NTRGFX_WIDTH; x++) {
            bool sa = stored.alpha[y][x] != 0, oa = ours.alpha[y][x] != 0;
            bool cd = (sa || oa) && (stored.color[y][x] != ours.color[y][x] || sa != oa);
            bool ad = stored.alpha[y][x] != ours.alpha[y][x];
            uint8_t px[3] = { 0, 0, 0 };
            if (cd) {
                px[0] = 255;
                colorDiff++;
            } else if (ad) {
                px[2] = 255;
                alphaDiff++;
            } else {
                uint32_t c = ours.color[y][x];
                px[0] = px[1] = px[2] = (uint8_t)((((c & 0x3F) + ((c >> 6) & 0x3F) + ((c >> 12) & 0x3F)) * 4 / 3) / 4);
            }
            fwrite(px, 3, 1, f);
        }
    }
    fclose(f);
    printf("%u polygons: %u pixels differ in color, %u in alpha only\n", list.numPolygons, colorDiff, alphaDiff);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 3 && strcmp(argv[1], "--info") == 0) {
        static NtrGfxMemory info;
        static NtrGfxLineRegs sInfoLines;
        if (!NtrGfx_LoadSnapshot(argv[2], &info, NULL, &sInfoLines, NULL)) {
            fprintf(stderr, "%s: cannot load snapshot\n", argv[2]);
            return 1;
        }
        PrintInfo(&info);
        int changed = 0;
        for (int y = 0; y < NTRGFX_HEIGHT; y++) {
            if (sInfoLines.changed[y]) {
                printf("%sline %d", changed++ ? ", " : "registers change between lines: ", y);
            }
        }
        if (changed) {
            printf("\n");
        }
        // Which 16-bit registers each change touches: offset old -> new
        const uint8_t *prev = info.io;
        for (int y = 0; y < NTRGFX_HEIGHT; y++) {
            if (!sInfoLines.changed[y]) {
                continue;
            }
            printf("  line %d:", y);
            for (int o = 0; o < NTRGFX_IO_SIZE; o += 2) {
                unsigned a = prev[o] | (prev[o + 1] << 8), b = sInfoLines.io[y][o] | (sInfoLines.io[y][o + 1] << 8);
                if (a != b) {
                    printf(" %03x %04x->%04x", o, a, b);
                }
            }
            printf("\n");
            prev = sInfoLines.io[y];
        }
        return 0;
    }
    if (argc == 3 && strcmp(argv[1], "--polys") == 0) {
        static NtrGfxMemory mem;
        static NtrGfxPolygonList list;
        if (NtrGfx_LoadSnapshot(argv[2], &mem, NULL, NULL, &list) != 2) {
            fprintf(stderr, "%s: no polygon list in the snapshot\n", argv[2]);
            return 1;
        }
        printf("DISP3DCNT %04x, %u polygons, %u vertices, manual sort %u\n", Io16(&mem, 0x60), list.numPolygons, list.numVertices, list.manualSort);
        for (uint32_t i = 0; i < list.numPolygons; i++) {
            const NtrGfxPolygon3D &p = list.polygons[i];
            printf("%u: attr %08x tex %08x pltt %04x%s%s%s:", i, p.attr, p.texParam, p.texPltt, p.wBuffer ? " W" : "", p.backFacing ? " back" : "", p.line ? " line" : "");
            for (int k = 0; k < p.numVertices; k++) {
                const NtrGfxVertex3D &v = list.vertices[p.vertices[k]];
                printf(" (%d,%d z%06x w%x st%d,%d c%u,%u,%u)", v.x, v.y, v.z, v.w, v.s, v.t, v.color[0], v.color[1], v.color[2]);
            }
            printf("\n");
        }
        return 0;
    }
    if ((argc == 3 || argc == 4) && strcmp(argv[1], "--diffs") == 0) {
        static NtrGfxMemory mem;
        static NtrGfx3DImage stored, ours;
        static NtrGfxPolygonList list;
        if (NtrGfx_LoadSnapshot(argv[2], &mem, &stored, NULL, &list) != 2) {
            fprintf(stderr, "%s: no polygon list in the snapshot\n", argv[2]);
            return 1;
        }
        NtrGfx_Render3D(&mem, &list, &ours);
        int limit = argc == 4 ? atoi(argv[3]) : 20, shown = 0;
        auto rgb = [](uint32_t c) { static char b[4][16]; static int i; i = (i + 1) & 3; snprintf(b[i], 16, "%2u,%2u,%2u", c & 0x3F, (c >> 6) & 0x3F, (c >> 12) & 0x3F); return b[i]; };
        for (int y = 0; y < NTRGFX_HEIGHT && shown < limit; y++) {
            for (int x = 0; x < NTRGFX_WIDTH && shown < limit; x++) {
                if (stored.color[y][x] != ours.color[y][x] || stored.alpha[y][x] != ours.alpha[y][x]) {
                    printf("(%3d,%3d) stored %s a%2u   ours %s a%2u\n", x, y, rgb(stored.color[y][x]), stored.alpha[y][x], rgb(ours.color[y][x]), ours.alpha[y][x]);
                    shown++;
                }
            }
        }
        return 0;
    }
    if (argc == 7 && strcmp(argv[1], "--region") == 0) {
        static NtrGfxMemory mem;
        static NtrGfx3DImage stored, ours;
        static NtrGfxPolygonList list;
        if (NtrGfx_LoadSnapshot(argv[2], &mem, &stored, NULL, &list) != 2) {
            fprintf(stderr, "%s: no polygon list in the snapshot\n", argv[2]);
            return 1;
        }
        NtrGfx_Render3D(&mem, &list, &ours);
        static NtrGfx3DImage bg; // the rear plane alone
        uint32_t numPolygons = list.numPolygons;
        list.numPolygons = 0;
        NtrGfx_Render3D(&mem, &list, &bg);
        list.numPolygons = numPolygons;
        int x0 = atoi(argv[3]), y0 = atoi(argv[4]), x1 = atoi(argv[5]), y1 = atoi(argv[6]);
        // '.' = rear plane, '#' = drawn; right: '#'/'.' agree, 'X' = we draw a different color, 'o' = we miss it, '!' =
        // we draw where melonDS shows the rear plane
        auto drawn = [&](const NtrGfx3DImage &im, int x, int y) { return im.color[y][x] != bg.color[y][x] || im.alpha[y][x] != bg.alpha[y][x]; };
        printf("    ");
        for (int x = x0; x <= x1; x++) {
            putchar('0' + x % 10);
        }
        printf("\n");
        for (int y = y0; y <= y1 && y < NTRGFX_HEIGHT; y++) {
            printf("%3d ", y);
            for (int x = x0; x <= x1 && x < NTRGFX_WIDTH; x++) {
                putchar(drawn(stored, x, y) ? '#' : '.');
            }
            printf("   ");
            for (int x = x0; x <= x1 && x < NTRGFX_WIDTH; x++) {
                bool s = drawn(stored, x, y), o = drawn(ours, x, y);
                bool same = stored.color[y][x] == ours.color[y][x] && stored.alpha[y][x] == ours.alpha[y][x];
                putchar(s && o ? (same ? '#' : 'X') : (s ? 'o' : (o ? '!' : '.')));
            }
            printf("\n");
        }
        return 0;
    }
    if (argc == 4 && strcmp(argv[1], "--compare3d") == 0) {
        return Compare3D(argv[2], argv[3]);
    }
    if (argc < 3) {
        fprintf(stderr, "usage: %s SNAPSHOT OUT.ppm [HIDE]\n", argv[0]);
        return 2;
    }
    static NtrGfxMemory mem;
    static NtrGfx3DImage image3D;
    static NtrGfxLineRegs lineRegs;
    static NtrGfxFrame frame;
    static NtrGfxPolygonList list;
    int loaded = NtrGfx_LoadSnapshot(argv[1], &mem, &image3D, &lineRegs, &list);
    if (!loaded) {
        fprintf(stderr, "%s: cannot load snapshot (wrong file or older format)\n", argv[1]);
        return 1;
    }
    const char *use = getenv("NTRGFX_REPLAY_3D");
    if (loaded == 2 && !(use != NULL && strcmp(use, "image") == 0)) {
        NtrGfx_Render3D(&mem, &list, &image3D);
    }
    NtrGfx_SetHiddenLayers(argc > 3 ? argv[3] : getenv("NTRGFX_HIDE"));
    NtrGfx_RenderFrame(&mem, &image3D, &frame, NtrGfx_ApplyLineRegs, &lineRegs);
    if (!NtrGfx_SaveFramePPM(argv[2], &frame)) {
        fprintf(stderr, "%s: cannot write\n", argv[2]);
        return 1;
    }
    return 0;
}
