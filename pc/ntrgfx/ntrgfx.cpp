// Frame assembly: both 2D engines, display capture, display swap, 18-bit -> RGBA output.

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

// Display capture (GBATEK "DS Video Capture and Main Memory Display Mode"): engine A only, one line at a time, while
// the frame is drawn
class Capture {
public:
    Capture(NtrGfxMemory *mem, const NtrGfx3DImage *image3D)
        : mMem(mem)
        , mImage3D(image3D)
        , mCnt(Io32(mem, 0x064))
    {
        static const int kSizes[4][2] = { { 128, 128 }, { 256, 64 }, { 256, 128 }, { 256, 192 } };
        mWidth = kSizes[(mCnt >> 20) & 3][0];
        mHeight = kSizes[(mCnt >> 20) & 3][1];
        mWriteBank = (mCnt >> 16) & 3;
        if (Active()) {
            // The destination should be allocated to LCDC (VRAMCNT MST 0)
            uint8_t vramcnt = mem->io[0x240 + mWriteBank];
            if ((vramcnt & 0x80) && (vramcnt & 7) != 0) {
                NtrGfx_WarnOnce("display capture into a VRAM bank not allocated to LCDC");
            }
            if (((mCnt >> 29) & 3) != 0 && (mCnt & 0x02000000)) {
                NtrGfx_WarnOnce("display capture source B = main memory display FIFO");
            }
        }
    }

    bool Active() const
    {
        return (mCnt & 0x80000000) != 0;
    }

    void Line(int y, const Color18 *graphics)
    {
        if (!Active() || y >= mHeight) {
            return;
        }
        uint32_t source = (mCnt >> 29) & 3; // 0 = A, 1 = B, 2/3 = A+B blended
        uint32_t eva = mCnt & 0x1F, evb = (mCnt >> 8) & 0x1F;
        eva = eva > 16 ? 16 : eva;
        evb = evb > 16 ? 16 : evb;
        // Offsets wrap inside the 128 KB bank. Source B: the VRAM read block (DISPCNT bits 18-19), as 256-pixel lines
        uint32_t writeOffset = ((mCnt >> 18) & 3) * 0x8000;
        uint32_t readOffset = ((mCnt >> 26) & 3) * 0x8000;
        uint32_t readBank = (Io32(mMem, 0x000) >> 18) & 3;
        uint8_t *dst = &mMem->banks[mWriteBank * 0x20000];
        const uint8_t *vram = &mMem->banks[readBank * 0x20000];

        for (int x = 0; x < mWidth; x++) {
            // Source A: the graphics screen (always opaque) or the 3D screen
            uint16_t a;
            bool alphaA;
            if (mCnt & 0x01000000) {
                a = mImage3D != NULL ? Color15From18(mImage3D->color[y][x]) : 0;
                alphaA = mImage3D != NULL && mImage3D->alpha[y][x] != 0;
            } else {
                a = Color15From18(graphics[x]);
                alphaA = true;
            }
            // Source B: VRAM (bit 15 = alpha) or the main memory FIFO (not emulated: transparent black)
            uint16_t b = 0;
            if (!(mCnt & 0x02000000)) {
                b = Read16(&vram[(readOffset + (y * NTRGFX_WIDTH + x) * 2) & 0x1FFFF]);
            }
            bool alphaB = (b & 0x8000) != 0;

            uint16_t out;
            switch (source) {
            case 0:
                out = a | (alphaA ? 0x8000 : 0);
                break;
            case 1:
                out = b;
                break;
            default: {
                // (A * alphaA * EVA + B * alphaB * EVB) / 16; alpha = (alphaA and EVA > 0) or (alphaB and EVB > 0)
                uint32_t ka = alphaA ? eva : 0, kb = alphaB ? evb : 0;
                uint16_t mixed = 0;
                for (int shift = 0; shift < 15; shift += 5) {
                    uint32_t i = (((a >> shift) & 0x1F) * ka + ((b >> shift) & 0x1F) * kb) / 16;
                    mixed |= (uint16_t)((i > 31 ? 31 : i) << shift);
                }
                bool alpha = (alphaA && eva > 0) || (alphaB && evb > 0);
                out = mixed | (alpha ? 0x8000 : 0);
                break;
            }
            }
            uint32_t addr = (writeOffset + (y * mWidth + x) * 2) & 0x1FFFF;
            dst[addr] = (uint8_t)out;
            dst[addr + 1] = (uint8_t)(out >> 8);
        }
    }

    // After the frame: the hardware clears the enable bit (at line 192, whatever the size). Returns the banks written.
    int Finish()
    {
        if (!Active()) {
            return 0;
        }
        mCnt &= ~0x80000000u;
        mMem->io[0x067] &= 0x7F;
        return 1 << mWriteBank;
    }

private:
    NtrGfxMemory *mMem;
    const NtrGfx3DImage *mImage3D;
    uint32_t mCnt;
    int mWidth;
    int mHeight;
    uint32_t mWriteBank;
};

int NtrGfx_RenderFrame(NtrGfxMemory *mem, const NtrGfx3DImage *image3D, NtrGfxFrame *out, NtrGfxLineHook hook, void *user)
{
    if (hook != NULL) {
        hook(0, mem, user);
    }
    Engine2D engines[2] = { Engine2D(mem, 0, image3D), Engine2D(mem, 1, NULL) };
    const uint16_t enableBit[2] = { 0x0002, 0x0200 };
    Capture capture(mem, image3D);

    Color18 line[NTRGFX_WIDTH];
    Color18 graphics[NTRGFX_WIDTH];
    // Line by line, both screens, so register changes between lines (hook) reach both engines at the same point
    for (int y = 0; y < NTRGFX_HEIGHT; y++) {
        if (hook != NULL && y != 0) {
            hook(y, mem, user);
        }
        uint16_t powcnt = Io16(mem, 0x304);
        // Display swap: 1 = engine A on the upper screen
        int engineOnTop = (powcnt & 0x8000) ? 0 : 1;
        for (int engine = 0; engine < 2; engine++) {
            int screen = engine == engineOnTop ? 0 : 1;
            bool capturing = engine == 0 && capture.Active();
            engines[engine].BeginLine(y);
            if (!(powcnt & 0x0001) || !(powcnt & enableBit[engine])) {
                // LCDs or the engine powered off
                for (int x = 0; x < NTRGFX_WIDTH; x++) {
                    line[x] = 0;
                    graphics[x] = 0;
                }
            } else {
                engines[engine].RenderLine(y, line, capturing ? graphics : NULL);
            }
            if (capturing) {
                capture.Line(y, graphics);
            }
            Output(line, (*out)[screen][y]);
        }
    }
    return capture.Finish();
}
