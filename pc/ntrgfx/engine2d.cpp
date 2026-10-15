// 2D graphics engines A and B (GBATEK "DS Video", "LCD VRAM BG Screen Data Format", "LCD OBJ", "LCD I/O Window
// Feature", "LCD I/O Mosaic Function", "LCD I/O Color Special Effects", "DS 3D Display Control" (3D layer)).

#include <initializer_list>
#include <stdio.h>

#include "internal.hpp"

namespace ntrgfx {

const uint32_t kBankOffset[kBankCount] = { 0x00000, 0x20000, 0x40000, 0x60000, 0x80000, 0x90000, 0x94000, 0x98000, 0xA0000 };
const uint32_t kBankSize[kBankCount] = { 0x20000, 0x20000, 0x20000, 0x20000, 0x10000, 0x4000, 0x4000, 0x8000, 0x4000 };

// VRAMCNT_A..I (0x240-0x246, 0x248-0x249)
static uint8_t VramCnt(const NtrGfxMemory *mem, Bank bank)
{
    return mem->io[bank <= kBankG ? 0x240 + bank : 0x248 + (bank - kBankH)];
}

Engine2D::Engine2D(const NtrGfxMemory *mem, int engine, const NtrGfx3DImage *image3D)
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
    , mImage3D(image3D)
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

Color18 BlendColors(Color18 first, Color18 second, uint32_t eva, uint32_t evb)
{
    // I = MIN(63, I1st*EVA + I2nd*EVB), coefficients in 1/16, rounded to nearest (matches melonDS's output)
    Color18 out = 0;
    for (int shift = 0; shift < 18; shift += 6) {
        uint32_t i = (((first >> shift) & 0x3F) * eva + ((second >> shift) & 0x3F) * evb + 8) / 16;
        out |= (i > 63 ? 63 : i) << shift;
    }
    return out;
}

// The 3D layer over a 2nd target: (3D * (A+1) + 2D * (31-A)) / 32 per channel, rounded to nearest
static Color18 Blend3D(Color18 color3D, Color18 below, uint32_t alpha)
{
    Color18 out = 0;
    for (int shift = 0; shift < 18; shift += 6) {
        uint32_t i = (((color3D >> shift) & 0x3F) * (alpha + 1) + ((below >> shift) & 0x3F) * (31 - alpha) + 16) / 32;
        out |= i << shift;
    }
    return out;
}

Color18 BrightenColor(Color18 color, uint32_t evy)
{
    Color18 out = 0;
    for (int shift = 0; shift < 18; shift += 6) {
        uint32_t i = (color >> shift) & 0x3F;
        out |= (i + (63 - i) * evy / 16) << shift;
    }
    return out;
}

Color18 DarkenColor(Color18 color, uint32_t evy)
{
    Color18 out = 0;
    for (int shift = 0; shift < 18; shift += 6) {
        uint32_t i = (color >> shift) & 0x3F;
        out |= (i - i * evy / 16) << shift;
    }
    return out;
}

// Coefficients 17..31 act as 16
static uint32_t Coefficient(uint32_t value)
{
    return value > 16 ? 16 : value;
}

// BG extended palette of a BG (BG0/BG1 can use slot 2/3 instead, BGxCNT bit 13)
const uint8_t *Engine2D::BgExtPaletteFor(int bg) const
{
    int slot = bg;
    if (bg <= 1 && (Reg16(0x008 + bg * 2) & 0x2000)) {
        slot += 2;
    }
    const uint8_t *pal = BgExtPalette(slot);
    if (pal == NULL) {
        NtrGfx_WarnOnce("BG extended palette with no VRAM allocated");
    }
    return pal;
}

BgKind Engine2D::KindOfBG(int bg) const
{
    // T text, A affine, E extended, L large bitmap, - none (GBATEK "BG Mode" table)
    static const char kModes[8][5] = { "TTTT", "TTTA", "TTAA", "TTTE", "TTAE", "TTEE", "T-L-", "----" };
    uint32_t mode = mDispcnt & 7;
    if (mEngine == 0 && bg == 0 && ((mDispcnt & 8) || mode == 6)) {
        return kBg3D;
    }
    if (mEngine == 1 && mode == 6) {
        NtrGfx_WarnOnce("engine B BG mode 6 (reserved)");
        return kBgOff;
    }
    if (mode == 7) {
        NtrGfx_WarnOnce("BG mode 7 (reserved)");
    }
    switch (kModes[mode][bg]) {
    case 'T':
        return kBgText;
    case 'A':
        return kBgAffine;
    case 'L':
        return kBgLarge;
    case 'E': {
        // BGxCNT bit 7, bit 2: 0x = 16-bit map entries, 10 = 256-color bitmap, 11 = direct color bitmap
        uint16_t cnt = Reg16(0x008 + bg * 2);
        if (!(cnt & 0x80)) {
            return kBgExtTiles;
        }
        return (cnt & 4) ? kBgBitmapDirect : kBgBitmap256;
    }
    default:
        return kBgOff;
    }
}

void Engine2D::BeginLine(int y)
{
    mDispcnt = Reg(0x000);
    for (int i = 0; i < 2; i++) {
        uint32_t p = 0x020 + i * 0x10;
        int32_t regX = (int32_t)(Reg(p + 8) << 4) >> 4;
        int32_t regY = (int32_t)(Reg(p + 12) << 4) >> 4;
        if (y == 0) {
            mRefX[i][0] = regX;
            mRefY[i][0] = regY;
        } else {
            // A write reloads the internal point; otherwise it moves by (dmx, dmy) = (PB, PD)
            mRefX[i][y] = regX != mLastRegX[i] ? regX : mRefX[i][y - 1] + (int16_t)Reg16(p + 2);
            mRefY[i][y] = regY != mLastRegY[i] ? regY : mRefY[i][y - 1] + (int16_t)Reg16(p + 6);
        }
        mLastRegX[i] = regX;
        mLastRegY[i] = regY;
    }
}

void Engine2D::RenderLine(int y, Color18 *line, Color18 *graphicsOut)
{
    // Display mode: engine A 0..3, engine B 0..1 (bit 17 unused)
    uint32_t mode = (mDispcnt >> 16) & (mEngine == 0 ? 3 : 1);
    Color18 own[NTRGFX_WIDTH];
    Color18 *graphics = graphicsOut != NULL ? graphicsOut : own;
    if (mode == 1 || graphicsOut != NULL) {
        RenderGraphics(y, graphics);
    }

    switch (mode) {
    case 0: // display off: white
        for (int x = 0; x < NTRGFX_WIDTH; x++) {
            line[x] = kWhite18;
        }
        break;
    case 1:
        for (int x = 0; x < NTRGFX_WIDTH; x++) {
            line[x] = graphics[x];
        }
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

void Engine2D::RenderGraphics(int y, Color18 *out)
{
    uint32_t bgLine[4][NTRGFX_WIDTH];
    uint32_t objLine[NTRGFX_WIDTH];
    uint8_t objWindow[NTRGFX_WIDTH];
    uint8_t controls[NTRGFX_WIDTH];
    bool bgOn[4];

    if (mDispcnt & 0x80) {
        NtrGfx_WarnOnce("forced blank (DISPCNT bit 7)");
        for (int x = 0; x < NTRGFX_WIDTH; x++) {
            out[x] = kWhite18;
        }
        return;
    }

    for (int bg = 0; bg < 4; bg++) {
        BgKind kind = KindOfBG(bg);
        bgOn[bg] = kind != kBgOff && (mDispcnt & (0x100 << bg)) && !LayerHidden(mEngine, kind == kBg3D ? kLayer3D : (Layer)(kLayerBG0 + bg));
        memset(bgLine[bg], 0, sizeof(bgLine[bg]));
        if (!bgOn[bg]) {
            continue;
        }
        switch (kind) {
        case kBgText:
            RenderTextBG(bg, y, bgLine[bg]);
            break;
        case kBg3D:
            Render3DLayer(y, bgLine[bg]);
            break;
        default:
            RenderAffineBG(bg, kind, y, bgLine[bg]);
            break;
        }
        if (kind != kBg3D) { // no mosaic on the 3D layer
            ApplyBgMosaic(bg, bgLine[bg]);
        }
    }

    memset(objLine, 0, sizeof(objLine));
    memset(objWindow, 0, sizeof(objWindow));
    bool objOn = (mDispcnt & 0x1000) && !LayerHidden(mEngine, kLayerOBJ);
    if (objOn) {
        RenderOBJs(y, objLine, objWindow);
    }
    WindowControls(y, objWindow, controls);

    uint32_t bgPrio[4];
    for (int bg = 0; bg < 4; bg++) {
        bgPrio[bg] = Reg16(0x008 + bg * 2) & 3;
    }
    Color18 backdrop = Color18From15(Read16(&mBgPltt[0]));
    uint16_t bldcnt = Reg16(0x050);
    uint16_t bldalpha = Reg16(0x052);
    uint32_t effect = (bldcnt >> 6) & 3;
    uint32_t eva = Coefficient(bldalpha & 0x1F), evb = Coefficient((bldalpha >> 8) & 0x1F);
    uint32_t evy = Coefficient(Reg16(0x054) & 0x1F);

    for (int x = 0; x < NTRGFX_WIDTH; x++) {
        uint8_t ctl = controls[x];
        // The top-most two pixels (1st and 2nd target candidates). Priority: lower value first; at equal value OBJ
        // before BG, BG0 before BG3; the backdrop below everything. Layers: BG0-3 = 0-3, OBJ = 4, backdrop = 5.
        uint32_t pix[2];
        int layer[2];
        int found = 0;
        for (uint32_t prio = 0; prio < 4 && found < 2; prio++) {
            if (objOn && (ctl & 0x10) && (objLine[x] & kPixOpaque) && PixPriority(objLine[x]) == prio) {
                pix[found] = objLine[x];
                layer[found++] = 4;
            }
            for (int bg = 0; bg < 4 && found < 2; bg++) {
                if (bgOn[bg] && (ctl & (1 << bg)) && bgPrio[bg] == prio && (bgLine[bg][x] & kPixOpaque)) {
                    pix[found] = bgLine[bg][x];
                    layer[found++] = bg;
                }
            }
        }
        while (found < 2) {
            pix[found] = backdrop | kPixOpaque;
            layer[found++] = 5;
        }

        Color18 first = pix[0] & kPixColor, second = pix[1] & kPixColor;
        bool secondIsTarget = bldcnt & (0x100 << layer[1]);
        bool effects = ctl & 0x20;
        Color18 color = first;
        if (layer[0] == 4 && (pix[0] & (kPixSemiTrans | kPixBitmap)) && secondIsTarget && effects) {
            // Semi-transparent OBJs: always alpha blending, whatever BLDCNT's effect and 1st targets say.
            // Bitmap OBJs blend by their own alpha (OAM 0..15 taken as (alpha+1)/16).
            if (pix[0] & kPixBitmap) {
                uint32_t a = (PixAlpha(pix[0]) & 0xF) + 1;
                color = BlendColors(first, second, a, 16 - a);
            } else {
                color = BlendColors(first, second, eva, evb);
            }
        } else if ((pix[0] & kPix3D) && secondIsTarget && PixAlpha(pix[0]) < 31) {
            // The 3D layer as 1st target blends by its per-pixel alpha (GBATEK guesses EVA = A/2, EVB = 16 - A/2;
            // melonDS's hardware-tested output matches the 3D engine's own blend: (3D*(A+1) + 2D*(31-A)) / 32)
            uint32_t a = PixAlpha(pix[0]);
            color = Blend3D(first, second, a);
        } else if (effects && (bldcnt & (1 << layer[0]))) {
            switch (effect) {
            case 1:
                if (secondIsTarget && !(pix[0] & kPix3D)) {
                    color = BlendColors(first, second, eva, evb);
                }
                break;
            case 2:
                color = BrightenColor(first, evy);
                break;
            case 3:
                color = DarkenColor(first, evy);
                break;
            }
        }
        out[x] = color;
        if (PixelTraced(mEngine, x, y)) {
            fprintf(stderr, "ntrgfx: pixel engine %c (%d,%d): window ctl %02x, top layer %d pix %08x, second layer %d pix %08x, BLDCNT %04x EVA %u EVB %u EVY %u -> %05x\n", 'A' + mEngine, x, y, ctl, layer[0], pix[0], layer[1], pix[1], bldcnt, eva, evb, evy, color);
        }
    }
}

// Per pixel: which layers (bits 0-4: BG0-3, OBJ) and whether color effects (bit 5) are on, from the windows
void Engine2D::WindowControls(int y, const uint8_t *objWindow, uint8_t *controls)
{
    bool win[2] = { (mDispcnt & 0x2000) != 0, (mDispcnt & 0x4000) != 0 };
    bool objWin = (mDispcnt & 0x8000) != 0;
    if (!win[0] && !win[1] && !objWin) {
        memset(controls, 0x3F, NTRGFX_WIDTH);
        return;
    }
    // The OBJ window needs the OBJ layer on too
    objWin = objWin && (mDispcnt & 0x1000);
    uint16_t winin = Reg16(0x048), winout = Reg16(0x04A);

    // Rectangles: X1/Y1 first inside, X2/Y2 first outside; X2 = 0 means 256 (DS), X1 = X2 = 0 is empty. When the
    // first coordinate is past the second the window wraps around (it switches on at X1/Y1 and off at X2/Y2).
    bool inY[2];
    uint32_t x1[2], x2[2];
    bool empty[2];
    for (int w = 0; w < 2; w++) {
        uint16_t h = Reg16(0x040 + w * 2), v = Reg16(0x044 + w * 2);
        uint32_t y1 = v >> 8, y2 = v & 0xFF;
        inY[w] = y1 <= y2 ? (uint32_t)y >= y1 && (uint32_t)y < y2 : (uint32_t)y >= y1 || (uint32_t)y < y2;
        x1[w] = h >> 8;
        x2[w] = h & 0xFF;
        empty[w] = x1[w] == 0 && x2[w] == 0;
        if (x2[w] == 0) {
            x2[w] = 256;
        }
    }
    for (int x = 0; x < NTRGFX_WIDTH; x++) {
        bool in[2];
        for (int w = 0; w < 2; w++) {
            uint32_t ux = (uint32_t)x;
            in[w] = win[w] && inY[w] && !empty[w] && (x1[w] <= x2[w] ? ux >= x1[w] && ux < x2[w] : ux >= x1[w] || ux < x2[w]);
        }
        // Window 0 over window 1 over the OBJ window over the outside
        if (in[0]) {
            controls[x] = winin & 0x3F;
        } else if (in[1]) {
            controls[x] = (winin >> 8) & 0x3F;
        } else if (objWin && objWindow[x]) {
            controls[x] = (winout >> 8) & 0x3F;
        } else {
            controls[x] = winout & 0x3F;
        }
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
    if (cnt & 0x40) { // vertical mosaic: repeat the block's first line
        y -= y % (((Reg16(0x04C) >> 4) & 0xF) + 1);
    }

    bool extended = color256 && (mDispcnt & 0x40000000);
    const uint8_t *extPal = extended ? BgExtPaletteFor(bg) : NULL;

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
            if (extended) {
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
        out[x] = Color18From15(color) | kPixOpaque;
    }
}

// Affine (rotation/scaling) BGs: affine tiles, extended tiles, 256-color and direct color bitmaps, the large bitmap
void Engine2D::RenderAffineBG(int bg, BgKind kind, int y, uint32_t *out)
{
    // bgcnt size -> dimensions: affine/extended tiles 128..1024 square; bitmaps 128x128, 256x256, 512x256, 512x512;
    // large bitmap 512x1024, 1024x512
    static const uint16_t kBitmapSizes[4][2] = { { 128, 128 }, { 256, 256 }, { 512, 256 }, { 512, 512 } };
    uint16_t cnt = Reg16(0x008 + bg * 2);
    uint32_t size = cnt >> 14;
    int32_t width, height;
    switch (kind) {
    case kBgAffine:
    case kBgExtTiles:
        width = height = 128 << size;
        break;
    case kBgLarge:
        if (size >= 2) {
            NtrGfx_WarnOnce("large bitmap BG size 2-3 (reserved)");
        }
        width = (size & 1) ? 1024 : 512;
        height = (size & 1) ? 512 : 1024;
        break;
    default:
        width = kBitmapSizes[size][0];
        height = kBitmapSizes[size][1];
        break;
    }

    // Parameters PA, PC (8.8) at 0x20.. (BG2) / 0x30.. (BG3); the line's starting point is the internal reference
    // point (BeginLine)
    uint32_t p = 0x020 + (bg - 2) * 0x10;
    int32_t pa = (int16_t)Reg16(p), pc = (int16_t)Reg16(p + 4);
    if (cnt & 0x40) { // vertical mosaic
        y -= y % (((Reg16(0x04C) >> 4) & 0xF) + 1);
    }

    uint32_t charBase = ((cnt >> 2) & 0xF) * 0x4000;
    uint32_t screenBase = ((cnt >> 8) & 0x1F) * 0x800;
    if (mEngine == 0) {
        charBase += ((mDispcnt >> 24) & 7) * 0x10000;
        screenBase += ((mDispcnt >> 27) & 7) * 0x10000;
    }
    // Bitmaps: screen base in 16 KB steps, without the DISPCNT offset; the large bitmap starts at 0
    uint32_t bitmapBase = kind == kBgLarge ? 0 : ((cnt >> 8) & 0x1F) * 0x4000;
    bool wrap = cnt & 0x2000; // display area overflow: 1 = wraparound, 0 = transparent
    bool extended = kind == kBgExtTiles && (mDispcnt & 0x40000000);
    const uint8_t *extPal = extended ? BgExtPaletteFor(bg) : NULL;

    int32_t fx = mRefX[bg - 2][y], fy = mRefY[bg - 2][y];
    for (int x = 0; x < NTRGFX_WIDTH; x++, fx += pa, fy += pc) {
        int32_t tx = fx >> 8, ty = fy >> 8;
        if (wrap) {
            tx &= width - 1;
            ty &= height - 1;
        } else if (tx < 0 || ty < 0 || tx >= width || ty >= height) {
            continue;
        }
        uint16_t color;
        switch (kind) {
        case kBgAffine: {
            uint8_t tile = BgVram8(screenBase + (ty >> 3) * (width >> 3) + (tx >> 3));
            uint8_t index = BgVram8(charBase + tile * 64 + (ty & 7) * 8 + (tx & 7));
            if (index == 0) {
                continue;
            }
            color = Read16(&mBgPltt[index * 2]);
            break;
        }
        case kBgExtTiles: {
            uint16_t entry = BgVram16(screenBase + ((ty >> 3) * (width >> 3) + (tx >> 3)) * 2);
            uint32_t px = tx & 7, py = ty & 7;
            if (entry & 0x400) {
                px = 7 - px;
            }
            if (entry & 0x800) {
                py = 7 - py;
            }
            uint8_t index = BgVram8(charBase + (entry & 0x3FF) * 64 + py * 8 + px);
            if (index == 0) {
                continue;
            }
            if (extended) {
                color = extPal != NULL ? Read16(&extPal[((entry >> 12) * 256 + index) * 2]) : 0;
            } else {
                color = Read16(&mBgPltt[index * 2]);
            }
            break;
        }
        case kBgBitmap256:
        case kBgLarge: {
            uint8_t index = BgVram8(bitmapBase + ty * width + tx);
            if (index == 0) {
                continue;
            }
            color = Read16(&mBgPltt[index * 2]);
            break;
        }
        default: { // direct color: bit 15 = shown
            uint16_t c = BgVram16(bitmapBase + (ty * width + tx) * 2);
            if (!(c & 0x8000)) {
                continue;
            }
            color = c;
            break;
        }
        }
        out[x] = Color18From15(color) | kPixOpaque;
    }
}

// The 3D layer (engine A BG0): no vertical scroll; BG0HOFS scrolls it in a 512-pixel loop (256 3D + 256 transparent)
void Engine2D::Render3DLayer(int y, uint32_t *out)
{
    if (mImage3D == NULL) {
        return;
    }
    uint32_t hofs = Reg16(0x010) & 0x1FF;
    for (int x = 0; x < NTRGFX_WIDTH; x++) {
        uint32_t sx = (x + hofs) & 0x1FF;
        if (sx >= NTRGFX_WIDTH) {
            continue;
        }
        uint32_t a = mImage3D->alpha[y][sx];
        if (a == 0) {
            continue;
        }
        if (a > 31) {
            a = 31;
        }
        out[x] = (mImage3D->color[y][sx] & kPixColor) | kPixOpaque | kPix3D | (a << 18);
    }
}

// Horizontal mosaic (GBATEK "LCD I/O Mosaic Function"): each block of H-Size pixels takes its first pixel
void Engine2D::ApplyBgMosaic(int bg, uint32_t *out)
{
    if (!(Reg16(0x008 + bg * 2) & 0x40)) {
        return;
    }
    int h = (Reg16(0x04C) & 0xF) + 1;
    if (h == 1) {
        return;
    }
    for (int x = 0; x < NTRGFX_WIDTH; x++) {
        out[x] = out[x - x % h];
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
    // Mosaic: blocks on the screen grid (from screen pixel 0 / line 0). A vertical block starting above the OBJ hides
    // that line of it; a horizontal one starting left of it repeats its first column. (Close to melonDS's output; its
    // top-row edge case still differs, see NOTES "melonDS reference".)
    int mosaicH = 1, srcLine = line;
    if (attr0 & 0x1000) {
        uint16_t mosaic = Reg16(0x04C);
        mosaicH = ((mosaic >> 8) & 0xF) + 1;
        srcLine -= y % (((mosaic >> 12) & 0xF) + 1);
        if (srcLine < 0) {
            return;
        }
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
        int srcX = bx - sx % mosaicH;
        if (srcX < 0) {
            srcX = 0;
        }
        if (affine) {
            int dx = srcX - boxWidth / 2, dy = srcLine - boxHeight / 2;
            int fx = pa * dx + pb * dy + (width << 7);
            int fy = pc * dx + pd * dy + (height << 7);
            tx = fx >> 8;
            ty = fy >> 8;
            if (fx < 0 || fy < 0 || tx >= width || ty >= height) {
                continue;
            }
        } else {
            tx = (attr1 & 0x1000) ? width - 1 - srcX : srcX;
            ty = (attr1 & 0x2000) ? height - 1 - srcLine : srcLine;
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
        if ((cur & kPixOpaque) && PixPriority(cur) <= prio) {
            continue;
        }
        uint32_t pix = Color18From15(color) | kPixOpaque | (prio << 25);
        if (mode == 1) {
            pix |= kPixSemiTrans;
        } else if (mode == 3) {
            pix |= kPixBitmap | ((uint32_t)(attr2 >> 12) << 18);
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
            // Up: New = Old + (63-Old) * Factor/16; down: New = Old - Old * Factor/16, where the result rounds down
            // (Old * (16-Factor) / 16; matches melonDS's hardware-tested output)
            i = mode == 1 ? i + (63 - i) * factor / 16 : i * (16 - factor) / 16;
            out |= i << shift;
        }
        line[x] = out;
    }
}

} // namespace ntrgfx
