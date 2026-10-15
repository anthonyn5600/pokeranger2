// Debugging aids: hidden layers, warn-once log, snapshots, PPM output.

#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "internal.hpp"

using namespace ntrgfx;

static const char kSnapshotMagic[8] = { 'N', 'T', 'R', 'G', 'F', 'X', '0', '3' };
static const char kSnapshotMagicV2[8] = { 'N', 'T', 'R', 'G', 'F', 'X', '0', '2' };

static bool sHidden[2][kLayerCount];
static bool sHiddenInit;

void NtrGfx_SetHiddenLayers(const char *spec)
{
    memset(sHidden, 0, sizeof(sHidden));
    sHiddenInit = true;
    if (spec == NULL) {
        return;
    }
    std::string s(spec);
    size_t pos = 0;
    while (pos < s.size()) {
        size_t end = s.find(',', pos);
        std::string tok = s.substr(pos, end == std::string::npos ? std::string::npos : end - pos);
        pos = end == std::string::npos ? s.size() : end + 1;
        if (tok.size() < 2 || (tok[0] != 'A' && tok[0] != 'B')) {
            fprintf(stderr, "ntrgfx: NTRGFX_HIDE: bad layer '%s' (A0..A3, AO, A3D, B0..B3, BO)\n", tok.c_str());
            continue;
        }
        int engine = tok[0] == 'A' ? 0 : 1;
        std::string layer = tok.substr(1);
        if (layer == "3D") {
            sHidden[engine][kLayer3D] = true;
        } else if (layer == "O") {
            sHidden[engine][kLayerOBJ] = true;
        } else if (layer.size() == 1 && layer[0] >= '0' && layer[0] <= '3') {
            sHidden[engine][kLayerBG0 + (layer[0] - '0')] = true;
        } else {
            fprintf(stderr, "ntrgfx: NTRGFX_HIDE: bad layer '%s'\n", tok.c_str());
        }
    }
}

namespace ntrgfx {

bool LayerHidden(int engine, Layer layer)
{
    if (!sHiddenInit) {
        NtrGfx_SetHiddenLayers(getenv("NTRGFX_HIDE"));
    }
    return sHidden[engine][layer];
}

bool PixelTraced(int engine, int x, int y)
{
    static int sEngine = -2, sX, sY;
    if (sEngine == -2) {
        sEngine = -1;
        char e;
        const char *spec = getenv("NTRGFX_PIXEL");
        if (spec != NULL && sscanf(spec, "%c,%d,%d", &e, &sX, &sY) == 3 && (e == 'A' || e == 'B')) {
            sEngine = e - 'A';
        }
    }
    return engine == sEngine && x == sX && y == sY;
}

} // namespace ntrgfx

void NtrGfx_WarnOnce(const char *what)
{
    static std::set<std::string> sSeen;
    if (sSeen.insert(what).second) {
        fprintf(stderr, "ntrgfx: unsupported: %s\n", what);
    }
}

// Format: magic "NTRGFX03", u32 size + NtrGfxMemory, u32 size + NtrGfx3DImage, u32 count of changed lines, then per
// changed line u32 y + its registers (NTRGFX_IO_SIZE bytes); optionally "PLY1", u32 polygons, u32 vertices, u32
// manualSort, the polygons, the vertices (the 3D input). "NTRGFX02" snapshots end after the 3D picture.
static const char kPolygonMagic[4] = { 'P', 'L', 'Y', '1' };

int NtrGfx_SaveSnapshot(const char *path, const NtrGfxMemory *mem, const NtrGfx3DImage *image3D, const NtrGfxLineRegs *lineRegs, const NtrGfxPolygonList *list)
{
    FILE *f = fopen(path, "wb");
    if (f == NULL) {
        return 0;
    }
    static NtrGfx3DImage sNoImage;
    uint32_t memSize = sizeof(NtrGfxMemory), imageSize = sizeof(NtrGfx3DImage), count = 0;
    if (lineRegs != NULL) {
        for (int y = 0; y < NTRGFX_HEIGHT; y++) {
            count += lineRegs->changed[y] != 0;
        }
    }
    int ok = fwrite(kSnapshotMagic, sizeof(kSnapshotMagic), 1, f) == 1 && fwrite(&memSize, sizeof(memSize), 1, f) == 1 && fwrite(mem, sizeof(*mem), 1, f) == 1 && fwrite(&imageSize, sizeof(imageSize), 1, f) == 1
        && fwrite(image3D != NULL ? image3D : &sNoImage, sizeof(NtrGfx3DImage), 1, f) == 1 && fwrite(&count, sizeof(count), 1, f) == 1;
    for (uint32_t y = 0; ok && count != 0 && y < NTRGFX_HEIGHT; y++) {
        if (lineRegs->changed[y]) {
            ok = fwrite(&y, sizeof(y), 1, f) == 1 && fwrite(lineRegs->io[y], NTRGFX_IO_SIZE, 1, f) == 1;
        }
    }
    if (ok && list != NULL) {
        ok = fwrite(kPolygonMagic, sizeof(kPolygonMagic), 1, f) == 1 && fwrite(&list->numPolygons, sizeof(uint32_t), 3, f) == 3
            && fwrite(list->polygons, sizeof(NtrGfxPolygon3D), list->numPolygons, f) == list->numPolygons
            && fwrite(list->vertices, sizeof(NtrGfxVertex3D), list->numVertices, f) == list->numVertices;
    }
    fclose(f);
    return ok;
}

int NtrGfx_LoadSnapshot(const char *path, NtrGfxMemory *mem, NtrGfx3DImage *image3D, NtrGfxLineRegs *lineRegs, NtrGfxPolygonList *list)
{
    FILE *f = fopen(path, "rb");
    if (f == NULL) {
        return 0;
    }
    static NtrGfx3DImage sImage;
    if (image3D == NULL) {
        image3D = &sImage;
    }
    if (lineRegs != NULL) {
        memset(lineRegs->changed, 0, sizeof(lineRegs->changed));
    }
    char magic[8];
    uint32_t size = 0, count = 0;
    int ok = fread(magic, sizeof(magic), 1, f) == 1 && (memcmp(magic, kSnapshotMagic, sizeof(magic)) == 0 || memcmp(magic, kSnapshotMagicV2, sizeof(magic)) == 0) && fread(&size, sizeof(size), 1, f) == 1 && size == sizeof(NtrGfxMemory)
        && fread(mem, sizeof(*mem), 1, f) == 1 && fread(&size, sizeof(size), 1, f) == 1 && size == sizeof(NtrGfx3DImage) && fread(image3D, sizeof(*image3D), 1, f) == 1;
    if (ok && memcmp(magic, kSnapshotMagic, sizeof(magic)) == 0) {
        ok = fread(&count, sizeof(count), 1, f) == 1 && count <= NTRGFX_HEIGHT;
        static uint8_t sSkip[NTRGFX_IO_SIZE];
        for (uint32_t i = 0; ok && i < count; i++) {
            uint32_t y;
            ok = fread(&y, sizeof(y), 1, f) == 1 && y < NTRGFX_HEIGHT;
            if (ok) {
                ok = fread(lineRegs != NULL ? lineRegs->io[y] : sSkip, NTRGFX_IO_SIZE, 1, f) == 1;
                if (lineRegs != NULL) {
                    lineRegs->changed[y] = 1;
                }
            }
        }
        char polyMagic[4];
        if (ok && list != NULL && fread(polyMagic, sizeof(polyMagic), 1, f) == 1 && memcmp(polyMagic, kPolygonMagic, 4) == 0) {
            ok = fread(&list->numPolygons, sizeof(uint32_t), 3, f) == 3 && list->numPolygons <= NTRGFX_MAX_POLYGONS && list->numVertices <= NTRGFX_MAX_VERTICES
                && fread(list->polygons, sizeof(NtrGfxPolygon3D), list->numPolygons, f) == list->numPolygons
                && fread(list->vertices, sizeof(NtrGfxVertex3D), list->numVertices, f) == list->numVertices;
            if (ok) {
                fclose(f);
                return 2;
            }
        }
    }
    fclose(f);
    return ok;
}

void NtrGfx_ApplyLineRegs(int y, NtrGfxMemory *mem, void *lineRegs)
{
    const NtrGfxLineRegs *regs = (const NtrGfxLineRegs *)lineRegs;
    if (regs != NULL && regs->changed[y]) {
        memcpy(mem->io, regs->io[y], NTRGFX_IO_SIZE);
    }
}

int NtrGfx_SaveFramePPM(const char *path, const NtrGfxFrame *frame)
{
    FILE *f = fopen(path, "wb");
    if (f == NULL) {
        return 0;
    }
    fprintf(f, "P6\n%d %d\n255\n", NTRGFX_WIDTH, NTRGFX_HEIGHT * 2);
    for (int screen = 0; screen < 2; screen++) {
        for (int y = 0; y < NTRGFX_HEIGHT; y++) {
            for (int x = 0; x < NTRGFX_WIDTH; x++) {
                fwrite((*frame)[screen][y][x], 3, 1, f);
            }
        }
    }
    fclose(f);
    return 1;
}
