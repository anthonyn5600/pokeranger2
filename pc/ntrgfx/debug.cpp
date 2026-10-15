// Debugging aids: hidden layers, warn-once log, snapshots, PPM output.

#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "internal.hpp"

using namespace ntrgfx;

static const char kSnapshotMagic[8] = { 'N', 'T', 'R', 'G', 'F', 'X', '0', '1' };

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

} // namespace ntrgfx

void NtrGfx_WarnOnce(const char *what)
{
    static std::set<std::string> sSeen;
    if (sSeen.insert(what).second) {
        fprintf(stderr, "ntrgfx: unsupported: %s\n", what);
    }
}

int NtrGfx_SaveSnapshot(const char *path, const NtrGfxMemory *mem)
{
    FILE *f = fopen(path, "wb");
    if (f == NULL) {
        return 0;
    }
    uint32_t size = sizeof(NtrGfxMemory);
    int ok = fwrite(kSnapshotMagic, sizeof(kSnapshotMagic), 1, f) == 1 && fwrite(&size, sizeof(size), 1, f) == 1 && fwrite(mem, sizeof(*mem), 1, f) == 1;
    fclose(f);
    return ok;
}

int NtrGfx_LoadSnapshot(const char *path, NtrGfxMemory *mem)
{
    FILE *f = fopen(path, "rb");
    if (f == NULL) {
        return 0;
    }
    char magic[8];
    uint32_t size = 0;
    int ok = fread(magic, sizeof(magic), 1, f) == 1 && memcmp(magic, kSnapshotMagic, sizeof(magic)) == 0 && fread(&size, sizeof(size), 1, f) == 1 && size == sizeof(NtrGfxMemory) && fread(mem, sizeof(*mem), 1, f) == 1;
    fclose(f);
    return ok;
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
