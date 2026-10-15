// Frame assembly: both 2D engines, display swap, 18-bit -> RGBA output.

#include "internal.hpp"

using namespace ntrgfx;

static void Output(const Color18 *line, uint8_t (*out)[4])
{
    for (int x = 0; x < NTRGFX_WIDTH; x++) {
        Color18 c = line[x];
        for (int ch = 0; ch < 3; ch++) {
            uint32_t i = (c >> (ch * 6)) & 0x3F;
            out[x][ch] = (uint8_t)((i << 2) | (i >> 4));
        }
        out[x][3] = 0xFF;
    }
}

void NtrGfx_RenderFrame(const NtrGfxMemory *mem, NtrGfxFrame *out)
{
    uint16_t powcnt = Io16(mem, 0x304);
    // Display swap: 1 = engine A on the upper screen
    int engineOnTop = (powcnt & 0x8000) ? 0 : 1;

    Engine2D engines[2] = { Engine2D(mem, 0), Engine2D(mem, 1) };
    const uint16_t enableBit[2] = { 0x0002, 0x0200 };

    Color18 line[NTRGFX_WIDTH];
    for (int engine = 0; engine < 2; engine++) {
        int screen = engine == engineOnTop ? 0 : 1;
        for (int y = 0; y < NTRGFX_HEIGHT; y++) {
            if (!(powcnt & 0x0001) || !(powcnt & enableBit[engine])) {
                // LCDs or the engine powered off
                for (int x = 0; x < NTRGFX_WIDTH; x++) {
                    line[x] = 0;
                }
            } else {
                engines[engine].RenderLine(y, line);
            }
            Output(line, (*out)[screen][y]);
        }
    }
}
