// 2D graphics engines A and B (GBATEK "DS Video", "LCD VRAM BG Screen Data Format", "LCD OBJ").

#include <initializer_list>

#include "internal.hpp"

namespace ntrgfx {

const uint32_t kBankOffset[kBankCount] = { 0x00000, 0x20000, 0x40000, 0x60000, 0x80000, 0x90000, 0x94000, 0x98000, 0xA0000 };
const uint32_t kBankSize[kBankCount] = { 0x20000, 0x20000, 0x20000, 0x20000, 0x10000, 0x4000, 0x4000, 0x8000, 0x4000 };

// VRAMCNT_A..I (0x240-0x246, 0x248-0x249)
static uint8_t VramCnt(const NtrGfxMemory *mem, Bank bank)
{
    return mem->io[bank <= kBankG ? 0x240 + bank : 0x248 + (bank - kBankH)];
}

Engine2D::Engine2D(const NtrGfxMemory *mem, int engine)
    : mMem(mem)
    , mEngine(engine)
    , mBase(engine == 0 ? 0x000 : 0x1000)
    , mDispcnt(Io32(mem, engine == 0 ? 0x000 : 0x1000))
    , mBgPltt(&mem->pltt[engine == 0 ? 0x000 : 0x400])
    , mObjPltt(&mem->pltt[engine == 0 ? 0x200 : 0x600])
    , mOam(&mem->oam[engine == 0 ? 0x000 : 0x400])
    , mBgVram(engine == 0 ? mem->bgVramA : mem->bgVramB)
    , mBgVramMask(engine == 0 ? sizeof(mem->bgVramA) - 1 : sizeof(mem->bgVramB) - 1)
    , mObjVram(engine == 0 ? mem->objVramA : mem->objVramB)
    , mObjVramMask(engine == 0 ? sizeof(mem->objVramA) - 1 : sizeof(mem->objVramB) - 1)
{
}

uint32_t Engine2D::Reg(uint32_t offset) const
{
    return Io32(mMem, mBase + offset);
}

uint16_t Engine2D::Reg16(uint32_t offset) const
{
    return Io16(mMem, mBase + offset);
}

uint8_t Engine2D::BgVram8(uint32_t addr) const
{
    return mBgVram[addr & mBgVramMask];
}

uint16_t Engine2D::BgVram16(uint32_t addr) const
{
    return Read16(&mBgVram[addr & mBgVramMask & ~1u]);
}

uint8_t Engine2D::ObjVram8(uint32_t addr) const
{
    return mObjVram[addr & mObjVramMask];
}

uint16_t Engine2D::ObjVram16(uint32_t addr) const
{
    return Read16(&mObjVram[addr & mObjVramMask & ~1u]);
}

// BG extended palette slot (0-3, 8 KB each), from the VRAM bank allocation; NULL if none is allocated
const uint8_t *Engine2D::BgExtPalette(int slot) const
{
    if (mEngine == 0) {
        uint8_t e = VramCnt(mMem, kBankE);
        if ((e & 0x80) && (e & 7) == 4) {
            return &mMem->banks[kBankOffset[kBankE] + slot * 0x2000];
        }
        for (Bank bank : { kBankF, kBankG }) {
            uint8_t cnt = VramCnt(mMem, bank);
            int firstSlot = ((cnt >> 3) & 1) * 2;
            if ((cnt & 0x80) && (cnt & 7) == 4 && slot >= firstSlot && slot < firstSlot + 2) {
                return &mMem->banks[kBankOffset[bank] + (slot - firstSlot) * 0x2000];
            }
        }
    } else {
        uint8_t h = VramCnt(mMem, kBankH);
        if ((h & 0x80) && (h & 3) == 2) {
            return &mMem->banks[kBankOffset[kBankH] + slot * 0x2000];
        }
    }
    return NULL;
}

// OBJ extended palette (8 KB), from the VRAM bank allocation; NULL if none is allocated
const uint8_t *Engine2D::ObjExtPalette() const
{
    if (mEngine == 0) {
        for (Bank bank : { kBankF, kBankG }) {
            uint8_t cnt = VramCnt(mMem, bank);
            if ((cnt & 0x80) && (cnt & 7) == 5) {
                return &mMem->banks[kBankOffset[bank]];
            }
        }
    } else {
        uint8_t i = VramCnt(mMem, kBankI);
        if ((i & 0x80) && (i & 3) == 3) {
            return &mMem->banks[kBankOffset[kBankI]];
        }
    }
    return NULL;
}

void Engine2D::RenderLine(int y, Color18 *line)
{
    // Display mode: engine A 0..3, engine B 0..1 (bit 17 unused)
    uint32_t mode = (mDispcnt >> 16) & (mEngine == 0 ? 3 : 1);

    switch (mode) {
    case 0: // display off: white
        for (int x = 0; x < NTRGFX_WIDTH; x++) {
            line[x] = kWhite18;
        }
        break;
    case 1:
        RenderGraphics(y, line);
        break;
    case 2:
        RenderVramDisplay(y, line);
        break;
    case 3:
        NtrGfx_WarnOnce("display mode 3 (main memory display)");
        for (int x = 0; x < NTRGFX_WIDTH; x++) {
            line[x] = 0;
        }
        break;
    }

    ApplyMasterBrightness(line);
}

void Engine2D::RenderGraphics(int y, Color18 *line)
{
    uint32_t bgMode = mDispcnt & 7;
    uint32_t bgLine[4][NTRGFX_WIDTH];
    uint32_t objLine[NTRGFX_WIDTH];
    uint8_t objWindow[NTRGFX_WIDTH];
    bool bgOn[4];

    if (mDispcnt & 0x80) {
        NtrGfx_WarnOnce("forced blank (DISPCNT bit 7)");
        for (int x = 0; x < NTRGFX_WIDTH; x++) {
            line[x] = kWhite18;
        }
        return;
    }
    if (mEngine == 1 && bgMode == 6) {
        NtrGfx_WarnOnce("engine B BG mode 6");
    }

    for (int bg = 0; bg < 4; bg++) {
        bgOn[bg] = (mDispcnt & (0x100 << bg)) && !LayerHidden(mEngine, (Layer)(kLayerBG0 + bg));
        memset(bgLine[bg], 0, sizeof(bgLine[bg]));
        if (!bgOn[bg]) {
            continue;
        }
        if (bg == 0 && mEngine == 0 && (mDispcnt & 8)) {
            NtrGfx_WarnOnce("3D layer (BG0 as 3D)");
            bgOn[bg] = false;
            continue;
        }
        // Which kind of BG this is in this mode (GBATEK "BG Mode" table)
        bool text = bg <= 1 || (bg == 2 && (bgMode == 0 || bgMode == 1 || bgMode == 3)) || (bg == 3 && bgMode == 0);
        if (text) {
            RenderTextBG(bg, y, bgLine[bg]);
        } else {
            NtrGfx_WarnOnce("affine / extended / large BGs");
            bgOn[bg] = false;
        }
    }

    memset(objLine, 0, sizeof(objLine));
    memset(objWindow, 0, sizeof(objWindow));
    bool objOn = (mDispcnt & 0x1000) && !LayerHidden(mEngine, kLayerOBJ);
    if (objOn) {
        RenderOBJs(y, objLine, objWindow);
    }

    uint32_t bgPrio[4];
    for (int bg = 0; bg < 4; bg++) {
        bgPrio[bg] = Reg16(0x008 + bg * 2) & 3;
    }
    Color18 backdrop = Color18From15(Read16(&mBgPltt[0]) & 0x7FFF);

    // Priority: lower value first; at equal value OBJ before BG, BG0 before BG3
    for (int x = 0; x < NTRGFX_WIDTH; x++) {
        uint32_t top = 0;
        bool found = false;
        for (uint32_t prio = 0; prio < 4 && !found; prio++) {
            if (objOn && (objLine[x] & kPixOpaque) && ((objLine[x] >> 16) & 3) == prio) {
                top = objLine[x];
                found = true;
                break;
            }
            for (int bg = 0; bg < 4; bg++) {
                if (bgOn[bg] && bgPrio[bg] == prio && (bgLine[bg][x] & kPixOpaque)) {
                    top = bgLine[bg][x];
                    found = true;
                    break;
                }
            }
        }
        line[x] = found ? Color18From15(top & 0x7FFF) : backdrop;
    }
}

// Text BG (GBATEK "LCD VRAM BG Screen Data Format"): 16-bit map entries, 16/16 or 256/1 (or extended) colors
void Engine2D::RenderTextBG(int bg, int y, uint32_t *out)
{
    uint16_t cnt = Reg16(0x008 + bg * 2);
    uint32_t hofs = Reg16(0x010 + bg * 4) & 0x1FF;
    uint32_t vofs = Reg16(0x012 + bg * 4) & 0x1FF;
    uint32_t charBase = ((cnt >> 2) & 0xF) * 0x4000;
    uint32_t screenBase = ((cnt >> 8) & 0x1F) * 0x800;
    if (mEngine == 0) {
        charBase += ((mDispcnt >> 24) & 7) * 0x10000;
        screenBase += ((mDispcnt >> 27) & 7) * 0x10000;
    }
    bool color256 = cnt & 0x80;
    uint32_t size = cnt >> 14;
    uint32_t widthMask = (size & 1) ? 511 : 255;
    uint32_t heightMask = (size & 2) ? 511 : 255;
    if (cnt & 0x40) {
        NtrGfx_WarnOnce("BG mosaic");
    }

    const uint8_t *extPal = NULL;
    if (color256 && (mDispcnt & 0x40000000)) {
        int slot = bg;
        if (bg <= 1 && (cnt & 0x2000)) {
            slot += 2;
        }
        extPal = BgExtPalette(slot);
        if (extPal == NULL) {
            NtrGfx_WarnOnce("BG extended palette with no VRAM allocated");
        }
    }

    uint32_t sy = (y + vofs) & heightMask;
    for (int x = 0; x < NTRGFX_WIDTH; x++) {
        uint32_t sx = (x + hofs) & widthMask;
        // 32x32-tile areas SC0..SC3, 2 KB each: SC1 right of SC0 (or below it for 256x512), SC2/SC3 the lower row
        uint32_t area = (sx >> 8) + ((sy >> 8) * ((size & 1) ? 2 : 1));
        uint32_t entryAddr = screenBase + area * 0x800 + (((sy & 255) >> 3) * 32 + ((sx & 255) >> 3)) * 2;
        uint16_t entry = BgVram16(entryAddr);
        uint32_t tile = entry & 0x3FF;
        uint32_t px = sx & 7, py = sy & 7;
        if (entry & 0x400) {
            px = 7 - px;
        }
        if (entry & 0x800) {
            py = 7 - py;
        }
        uint32_t palette = entry >> 12;
        uint16_t color;
        if (color256) {
            uint8_t index = BgVram8(charBase + tile * 64 + py * 8 + px);
            if (index == 0) {
                continue;
            }
            if (mDispcnt & 0x40000000) {
                color = extPal != NULL ? Read16(&extPal[(palette * 256 + index) * 2]) : 0;
            } else {
                color = Read16(&mBgPltt[index * 2]);
            }
        } else {
            uint8_t b = BgVram8(charBase + tile * 32 + py * 4 + px / 2);
            uint8_t index = (px & 1) ? b >> 4 : b & 0xF;
            if (index == 0) {
                continue;
            }
            color = Read16(&mBgPltt[(palette * 16 + index) * 2]);
        }
        out[x] = (color & 0x7FFF) | kPixOpaque;
    }
}

void Engine2D::RenderOBJs(int y, uint32_t *out, uint8_t *objWindow)
{
    // DS priority: the 2-bit priority first, then the OAM index (lower wins)
    for (int i = 0; i < 128; i++) {
        RenderOBJ(i, y, out, objWindow);
    }
}

void Engine2D::RenderOBJ(int index, int y, uint32_t *out, uint8_t *objWindow)
{
    static const uint8_t kSizes[3][4][2] = {
        { { 8, 8 }, { 16, 16 }, { 32, 32 }, { 64, 64 } }, // square
        { { 16, 8 }, { 32, 8 }, { 32, 16 }, { 64, 32 } }, // horizontal
        { { 8, 16 }, { 8, 32 }, { 16, 32 }, { 32, 64 } }, // vertical
    };
    const uint8_t *oam = &mOam[index * 8];
    uint16_t attr0 = Read16(&oam[0]);
    uint16_t attr1 = Read16(&oam[2]);
    uint16_t attr2 = Read16(&oam[4]);

    bool affine = attr0 & 0x100;
    if (!affine && (attr0 & 0x200)) {
        return; // disabled
    }
    uint32_t shape = attr0 >> 14;
    if (shape == 3) {
        return;
    }
    uint32_t mode = (attr0 >> 10) & 3;
    int width = kSizes[shape][attr1 >> 14][0];
    int height = kSizes[shape][attr1 >> 14][1];
    int boxWidth = width, boxHeight = height;
    if (affine && (attr0 & 0x200)) { // double size
        boxWidth *= 2;
        boxHeight *= 2;
    }

    // Y wraps at 256 (the OBJ shows at the top and the bottom); X is 9-bit signed
    int line = (y - (attr0 & 0xFF)) & 0xFF;
    if (line >= boxHeight) {
        return;
    }
    int x0 = attr1 & 0x1FF;
    if (x0 >= 256) {
        x0 -= 512;
    }
    if (attr0 & 0x1000) {
        NtrGfx_WarnOnce("OBJ mosaic");
    }

    uint32_t prio = (attr2 >> 10) & 3;
    uint32_t tile = attr2 & 0x3FF;
    bool color256 = attr0 & 0x2000;
    uint32_t palette = attr2 >> 12;

    // Affine parameters (8.8): group n at OAM n*32 + 6, 14, 22, 30
    int16_t pa = 0x100, pb = 0, pc = 0, pd = 0x100;
    if (affine) {
        const uint8_t *group = &mOam[((attr1 >> 9) & 0x1F) * 32];
        pa = (int16_t)Read16(&group[6]);
        pb = (int16_t)Read16(&group[14]);
        pc = (int16_t)Read16(&group[22]);
        pd = (int16_t)Read16(&group[30]);
    }

    const uint8_t *extPal = NULL;
    if (mode != 3 && color256 && (mDispcnt & 0x80000000)) {
        extPal = ObjExtPalette();
        if (extPal == NULL) {
            NtrGfx_WarnOnce("OBJ extended palette with no VRAM allocated");
        }
    }

    // Source addressing
    uint32_t tileBoundary = (mDispcnt & 0x10) ? 32u << ((mDispcnt >> 20) & 3) : 32;
    uint32_t bmpBase = 0, bmpStride = 0;
    if (mode == 3) {
        if (mDispcnt & 0x40) {
            if (mDispcnt & 0x20) {
                return; // reserved
            }
            bmpBase = tile * (mEngine == 0 && (mDispcnt & 0x400000) ? 256 : 128);
            bmpStride = width * 2;
        } else {
            uint32_t maskX = (mDispcnt & 0x20) ? 0x1F : 0x0F;
            bmpBase = (tile & maskX) * 0x10 + (tile & ~maskX) * 0x80;
            bmpStride = ((mDispcnt & 0x20) ? 256 : 128) * 2;
        }
        if ((attr2 >> 12) == 0) {
            return; // alpha 0: invisible
        }
    }

    for (int bx = 0; bx < boxWidth; bx++) {
        int sx = x0 + bx;
        if (sx < 0 || sx >= NTRGFX_WIDTH) {
            continue;
        }
        // Texel within the OBJ
        int tx, ty;
        if (affine) {
            int dx = bx - boxWidth / 2, dy = line - boxHeight / 2;
            int fx = pa * dx + pb * dy + (width << 7);
            int fy = pc * dx + pd * dy + (height << 7);
            tx = fx >> 8;
            ty = fy >> 8;
            if (fx < 0 || fy < 0 || tx >= width || ty >= height) {
                continue;
            }
        } else {
            tx = (attr1 & 0x1000) ? width - 1 - bx : bx;
            ty = (attr1 & 0x2000) ? height - 1 - line : line;
        }

        uint16_t color;
        if (mode == 3) {
            color = ObjVram16(bmpBase + ty * bmpStride + tx * 2);
            if (!(color & 0x8000)) {
                continue;
            }
        } else {
            uint32_t tileX = tx >> 3, tileY = ty >> 3, px = tx & 7, py = ty & 7;
            uint32_t addr;
            if (mDispcnt & 0x10) { // 1D
                uint32_t tileBytes = color256 ? 64 : 32;
                addr = tile * tileBoundary + (tileY * (width >> 3) + tileX) * tileBytes;
            } else { // 2D: rows of 32 tiles (256-color tiles take two)
                addr = color256 ? ((tile & ~1u) + tileY * 32 + tileX * 2) * 32 : (tile + tileY * 32 + tileX) * 32;
            }
            uint8_t colorIndex;
            if (color256) {
                colorIndex = ObjVram8(addr + py * 8 + px);
            } else {
                uint8_t b = ObjVram8(addr + py * 4 + px / 2);
                colorIndex = (px & 1) ? b >> 4 : b & 0xF;
            }
            if (colorIndex == 0) {
                continue;
            }
            if (mode == 2) { // OBJ window: mask only
                objWindow[sx] = 1;
                continue;
            }
            if (color256) {
                color = (mDispcnt & 0x80000000) ? (extPal != NULL ? Read16(&extPal[(palette * 256 + colorIndex) * 2]) : 0)
                                                : Read16(&mObjPltt[colorIndex * 2]);
            } else {
                color = Read16(&mObjPltt[(palette * 16 + colorIndex) * 2]);
            }
        }

        // Keep the existing pixel unless this OBJ has a strictly better priority (lower OAM index came first)
        uint32_t cur = out[sx];
        if ((cur & kPixOpaque) && ((cur >> 16) & 3) <= prio) {
            continue;
        }
        uint32_t pix = (color & 0x7FFF) | kPixOpaque | (prio << 16);
        if (mode == 1) {
            pix |= kPixSemiTrans;
        } else if (mode == 3) {
            pix |= kPixBitmap | ((uint32_t)(attr2 >> 12) << 20);
        }
        out[sx] = pix;
    }
}

void Engine2D::RenderVramDisplay(int y, Color18 *line)
{
    // Engine A only: VRAM bank A..D (DISPCNT bits 18-19) shown as a 256x192 direct color bitmap
    uint32_t bank = (mDispcnt >> 18) & 3;
    const uint8_t *src = &mMem->banks[bank * 0x20000 + y * NTRGFX_WIDTH * 2];
    for (int x = 0; x < NTRGFX_WIDTH; x++) {
        line[x] = Color18From15(Read16(&src[x * 2]));
    }
}

void Engine2D::ApplyMasterBrightness(Color18 *line)
{
    uint16_t bright = Reg16(0x06C);
    uint32_t mode = bright >> 14;
    uint32_t factor = bright & 0x1F;
    if (factor > 16) {
        factor = 16;
    }
    if (mode != 1 && mode != 2) { // 0 = off, 3 = reserved
        return;
    }
    for (int x = 0; x < NTRGFX_WIDTH; x++) {
        Color18 c = line[x];
        Color18 out = 0;
        for (int shift = 0; shift < 18; shift += 6) {
            uint32_t i = (c >> shift) & 0x3F;
            // Up: New = Old + (63-Old) * Factor/16; down: New = Old - Old * Factor/16
            i = mode == 1 ? i + (63 - i) * factor / 16 : i - i * factor / 16;
            out |= i << shift;
        }
        line[x] = out;
    }
}

} // namespace ntrgfx
