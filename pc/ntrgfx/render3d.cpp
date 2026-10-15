// The 3D Rendering Engine (GBATEK "DS 3D Texture Formats" .. "DS 3D Rear-Plane"): draws the polygon list that the
// Geometry Engine (geometry.cpp) handed over at SWAP_BUFFERS into the 3D picture (engine A's BG0, capture source).
//
// GBATEK describes what the hardware does but not its exact arithmetic; the rasterization rules here (edge walking,
// fill rules, interpolation precision, depth test tolerances, anti-aliasing coverage, fog steps) follow melonDS's
// hardware research (its source read as documentation, our own code), checked pixel for pixel against its output
// with melonref.
//
// The picture is drawn line by line, every polygon's part of a line in drawing order, into two layers: the top-most
// pixel and the one below it (anti-aliased edges are blended with the pixel below in the final pass).

#include "internal.hpp"

#include <algorithm>
#include <initializer_list>
#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace ntrgfx;

namespace {

const int W = NTRGFX_WIDTH;
const int H = NTRGFX_HEIGHT;

// 5-bit color component to the 3D engine's 6 bits (GBATEK "DS 3D Texture Blending": X>0 -> X*2+1)
inline uint32_t Expand5(uint32_t c)
{
    c &= 0x1F;
    return c != 0 ? c * 2 + 1 : 0;
}

struct RGBA {
    uint32_t r, g, b, a; // 6-bit color, 5-bit alpha
};

inline RGBA From15(uint16_t c, uint32_t a)
{
    return { Expand5(c), Expand5(c >> 5), Expand5(c >> 10), a };
}

// Texture memory as the rendering engine sees it: 4 texture slots of 128 KB and 6 palette slots of 16 KB, from the
// VRAM banks allocated to them (GBATEK "VRAMCNT", MST 3)
struct TextureMemory {
    uint8_t tex[0x80000];
    uint8_t pal[0x18000];

    explicit TextureMemory(const NtrGfxMemory *mem)
    {
        memset(tex, 0, sizeof(tex));
        memset(pal, 0, sizeof(pal));
        for (int bank = kBankA; bank <= kBankD; bank++) {
            uint8_t cnt = mem->io[0x240 + bank];
            if ((cnt & 0x80) && (cnt & 7) == 3) {
                memcpy(&tex[((cnt >> 3) & 3) * 0x20000], &mem->banks[kBankOffset[bank]], 0x20000);
            }
        }
        uint8_t cntE = mem->io[0x244];
        if ((cntE & 0x80) && (cntE & 7) == 3) {
            memcpy(&pal[0], &mem->banks[kBankOffset[kBankE]], 0x10000);
        }
        for (int bank = kBankF; bank <= kBankG; bank++) {
            uint8_t cnt = mem->io[0x240 + bank];
            if ((cnt & 0x80) && (cnt & 7) == 3) {
                uint32_t ofs = (cnt >> 3) & 3;
                uint32_t slot = (ofs & 1) + (ofs & 2) * 2;
                memcpy(&pal[slot * 0x4000], &mem->banks[kBankOffset[bank]], 0x4000);
            }
        }
    }

    uint8_t Tex8(uint32_t addr) const
    {
        return tex[addr & 0x7FFFF];
    }

    uint16_t Tex16(uint32_t addr) const
    {
        return (uint16_t)(Tex8(addr) | (Tex8(addr + 1) << 8));
    }

    uint16_t Pal16(uint32_t addr) const
    {
        addr %= sizeof(pal);
        return (uint16_t)(pal[addr] | (pal[(addr + 1) % sizeof(pal)] << 8));
    }
};

// The texel at texture coordinates s, t (1+11+4 fixed point) (GBATEK "DS 3D Texture Formats"): 15-bit color and
// 5-bit alpha
void FetchTexel(const TextureMemory &tm, uint32_t texParam, uint32_t texPltt, int32_t s, int32_t t, uint16_t &color, uint32_t &alpha)
{
    int32_t width = 8 << ((texParam >> 20) & 7);
    int32_t height = 8 << ((texParam >> 23) & 7);
    s >>= 4;
    t >>= 4;
    // Clamp, repeat, or repeat with every second copy flipped
    auto wrap = [](int32_t c, int32_t size, bool repeat, bool flip) {
        if (!repeat) {
            return c < 0 ? 0 : (c >= size ? size - 1 : c);
        }
        if (flip && (c & size)) {
            return (size - 1) - (c & (size - 1));
        }
        return c & (size - 1);
    };
    s = wrap(s, width, texParam & 0x10000, texParam & 0x40000);
    t = wrap(t, height, texParam & 0x20000, texParam & 0x80000);

    uint32_t addr = (texParam & 0xFFFF) * 8;
    uint32_t color0Alpha = (texParam & 0x20000000) ? 0 : 31; // palette formats: color 0 transparent?
    uint32_t index = (uint32_t)(t * width + s);
    uint32_t palBase = texPltt * 16;

    switch ((texParam >> 26) & 7) {
    case 1: { // A3I5: 3-bit alpha expanded as a * 4 + a / 2
        uint8_t v = tm.Tex8(addr + index);
        color = tm.Pal16(palBase + (v & 0x1F) * 2);
        alpha = ((v >> 3) & 0x1C) + (v >> 6);
        return;
    }
    case 2: { // 4 colors, palette base in 8-byte steps
        uint32_t v = (tm.Tex8(addr + index / 4) >> ((s & 3) * 2)) & 3;
        color = tm.Pal16(texPltt * 8 + v * 2);
        alpha = v == 0 ? color0Alpha : 31;
        return;
    }
    case 3: { // 16 colors
        uint32_t v = (tm.Tex8(addr + index / 2) >> ((s & 1) * 4)) & 0xF;
        color = tm.Pal16(palBase + v * 2);
        alpha = v == 0 ? color0Alpha : 31;
        return;
    }
    case 4: { // 256 colors
        uint32_t v = tm.Tex8(addr + index);
        color = tm.Pal16(palBase + v * 2);
        alpha = v == 0 ? color0Alpha : 31;
        return;
    }
    case 5: { // 4x4 texel blocks (slot 0 or 2, 2 bits per texel) + 16-bit palette info per block (slot 1)
        uint32_t block = (addr + (uint32_t)(t & 0x3FC) * (uint32_t)(width >> 2) + (uint32_t)(s & 0x3FC) + (uint32_t)(t & 3)) & 0x7FFFF;
        uint32_t infoAddr = 0x20000 + ((block & 0x1FFFC) >> 1) + (block >= 0x40000 ? 0x10000 : 0);
        // Texels can't come from slot 1 (reads as 0)
        uint32_t texel = (block >= 0x20000 && block < 0x40000) ? 0 : (tm.Tex8(block) >> ((s & 3) * 2)) & 3;
        uint16_t info = tm.Tex16(infoAddr);
        uint32_t pal = palBase + (info & 0x3FFF) * 4;
        uint32_t mode = info >> 14;
        auto mix = [&](uint32_t w0, uint32_t w1) {
            // Per 5-bit component: (c0 * w0 + c1 * w1) / 8
            uint16_t c0 = tm.Pal16(pal), c1 = tm.Pal16(pal + 2);
            uint16_t out = 0;
            for (int sh = 0; sh < 15; sh += 5) {
                out |= (uint16_t)(((((c0 >> sh) & 0x1F) * w0 + ((c1 >> sh) & 0x1F) * w1) >> 3) << sh);
            }
            return out;
        };
        alpha = 31;
        switch (texel) {
        case 0:
        case 1:
            color = tm.Pal16(pal + texel * 2);
            return;
        case 2:
            color = mode == 1 ? mix(4, 4) : (mode == 3 ? mix(5, 3) : tm.Pal16(pal + 4));
            return;
        default:
            if (mode == 2) {
                color = tm.Pal16(pal + 6);
            } else if (mode == 3) {
                color = mix(3, 5);
            } else {
                color = 0;
                alpha = 0;
            }
            return;
        }
    }
    case 6: { // A5I3
        uint8_t v = tm.Tex8(addr + index);
        color = tm.Pal16(palBase + (v & 7) * 2);
        alpha = v >> 3;
        return;
    }
    default: { // 7: direct color, bit 15 = opaque
        color = tm.Tex16(addr + index * 2);
        alpha = (color & 0x8000) ? 31 : 0;
        return;
    }
    }
}

// Interpolation between two points, along Y (edges: 9-bit factor) or X (spans: 8-bit factor). Equal W values with
// their low bits clear interpolate linearly (exact, for 2D-style drawing); otherwise perspective-correct through a
// factor computed from the (normalized) W values, in 32-bit arithmetic. Z uses its own linear method with limited
// precision.
class Interp {
public:
    void Setup(int32_t from, int32_t to, int32_t w0, int32_t w1, bool wBuffer, bool alongY)
    {
        mFrom = from;
        mLen = to - from;
        mWBuffer = wBuffer;
        mAlongY = alongY;
        mZRecip = mLen != 0 ? (1 << 22) / mLen : 0;
        int32_t lowBits = alongY ? 0x7E : 0x7F;
        mLinear = w0 == w1 && !(w0 & lowBits);
        if (alongY) {
            mW0Num = w0 >> 1;
            mW0Den = (w0 + ((w0 & ~w1) & 1)) >> 1;
            mW1Den = w1 >> 1;
            mShift = 9;
        } else {
            mW0Num = mW0Den = w0;
            mW1Den = w1;
            mShift = 8;
        }
        mPos = 0;
        mFactor = 0;
    }

    void Move(int32_t at)
    {
        mPos = at - mFrom;
        if (mLen != 0 && (!mLinear || mWBuffer)) {
            uint32_t num = ((uint32_t)mPos * (uint32_t)mW0Num) << mShift;
            uint32_t den = (uint32_t)mPos * (uint32_t)mW0Den + (uint32_t)(mLen - mPos) * (uint32_t)mW1Den;
            mFactor = den != 0 ? num / den : 0;
        }
    }

    int32_t Value(int32_t a, int32_t b) const
    {
        if (mLen == 0 || a == b) {
            return a;
        }
        // Always from the smaller value up
        if (!mLinear) {
            if (a < b) {
                return a + (int32_t)(((uint32_t)(b - a) * mFactor) >> mShift);
            }
            return b + (int32_t)(((uint32_t)(a - b) * ((1u << mShift) - mFactor)) >> mShift);
        }
        if (a < b) {
            return a + (int32_t)((int64_t)(b - a) * mPos / mLen);
        }
        return b + (int32_t)((int64_t)(a - b) * (mLen - mPos) / mLen);
    }

    int32_t Depth(int32_t a, int32_t b) const
    {
        if (mLen == 0 || a == b) {
            return a;
        }
        if (mWBuffer) {
            if (a < b) {
                return a + (int32_t)(((int64_t)(b - a) * mFactor) >> mShift);
            }
            return b + (int32_t)(((int64_t)(a - b) * ((1 << mShift) - (int64_t)mFactor)) >> mShift);
        }
        int32_t base = a < b ? a : b;
        int32_t diff = a < b ? b - a : a - b;
        int32_t pos = a < b ? mPos : mLen - mPos;
        if (mAlongY) {
            int shift = 0;
            while (diff > 0x3FF) {
                diff >>= 1;
                shift++;
            }
            return base + (int32_t)((((int64_t)diff * pos * mZRecip) >> 22) << shift);
        }
        diff >>= 9;
        return base + (int32_t)(((int64_t)diff * pos * mZRecip) >> 13);
    }

private:
    int32_t mFrom = 0, mLen = 0, mPos = 0;
    bool mWBuffer = false, mAlongY = false, mLinear = false;
    int32_t mZRecip = 0;
    int32_t mW0Num = 0, mW0Den = 0, mW1Den = 0;
    int mShift = 0;
    uint32_t mFactor = 0;
};

// One edge of a polygon (left or right side), walked down one line at a time. X has an 18-bit fraction. A "steep"
// (Y-major) edge covers one pixel per line, a "shallow" (X-major) one a run of pixels.
class Edge {
public:
    // Single point (flat polygons)
    void SetPoint(int32_t x, bool wBuffer)
    {
        mX0 = mXMin = mXMax = x;
        mStep = 0;
        mAcc = 0;
        mShallow = false;
        mGoesLeft = false;
        mInterp.Setup(0, 0, 0, 0, wBuffer, true);
        mInterp.Move(0);
        mCoverageStep = 0;
    }

    void Setup(bool rightSide, int32_t x0, int32_t x1, int32_t y0, int32_t y1, int32_t w0, int32_t w1, int32_t y, bool wBuffer)
    {
        mRight = rightSide;
        mX0 = x0;
        mY = y;
        mGoesLeft = x1 < x0;
        mXMin = std::min(x0, x1);
        mXMax = x1 != x0 ? std::max(x0, x1) - 1 : x0;
        mXLen = mXMax + 1 - mXMin;
        mYLen = y1 - y0;

        // Slope = dx * (1 / dy), the reciprocal with an 18-bit fraction; 45 degrees is exact
        if (mYLen == 0) {
            mStep = 0;
        } else if (mYLen == mXLen && mXLen != 1) {
            mStep = 0x40000;
        } else {
            mStep = std::abs((x1 - x0) * ((1 << 18) / mYLen));
        }
        mShallow = mStep > 0x40000;

        // Where on its first line the edge starts, per side and direction
        if (mShallow) {
            if (mRight) {
                mAcc = mGoesLeft ? 0x60000 : mStep - 0x20000;
            } else {
                mAcc = mGoesLeft ? mStep - 0x20000 + 0x40000 : 0x20000;
            }
        } else {
            mAcc = (mStep != 0 && mGoesLeft) ? 0x40000 : 0;
        }
        mAcc += (y - y0) * mStep;

        // Attributes along the edge: edges at 45 degrees or shallower that lean outwards are one line ahead
        int32_t ahead = (mStep >= 0x40000 && (mRight != mGoesLeft)) ? 1 : 0;
        mInterp.Setup(y0 - ahead, y1 - ahead, w0, w1, wBuffer, true);
        mInterp.Move(y);
        if (mShallow) {
            mCoverageStep = (mYLen << 10) / mXLen;
        }
    }

    void NextLine()
    {
        mAcc += mStep;
        mY++;
        mInterp.Move(mY);
    }

    int32_t X() const
    {
        int32_t x = mGoesLeft ? mX0 - (mAcc >> 18) : mX0 + (mAcc >> 18);
        return std::clamp(x, mXMin, mXMax);
    }

    // Pixels the edge covers on this line, and the anti-aliasing coverage of the first one (bit 31 set: X-major,
    // bits 12-21 start coverage and bits 0-9 the step per pixel; else 0..31). swapped: the polygon's left and right
    // edges have crossed.
    void Params(bool swapped, int32_t &length, int32_t &coverage) const
    {
        if (mShallow) {
            if (!swapped || mRight) {
                if (mRight != mGoesLeft) {
                    length = (mAcc >> 18) - ((mAcc - mStep) >> 18);
                } else {
                    length = ((mAcc + mStep) >> 18) - (mAcc >> 18);
                }
            }
            int32_t startX = mAcc >> 18;
            if (mGoesLeft) {
                startX = mXLen - startX;
            }
            if (mRight) {
                startX = startX - length + 1;
            }
            int32_t startCoverage = (((startX << 10) + 0x1FF) * mYLen) / mXLen;
            coverage = (int32_t)(0x80000000u | ((uint32_t)(startCoverage & 0x3FF) << 12) | (uint32_t)(mCoverageStep & 0x3FF));
            if (swapped) {
                length = 1;
            }
            return;
        }
        length = 1;
        if (mStep == 0) {
            coverage = swapped ? 0 : 31; // vertical edges invert too when swapped
            return;
        }
        int32_t cov = ((mAcc >> 9) + (mStep >> 10)) >> 4;
        if ((cov >> 5) != (mAcc >> 18)) {
            cov = 31;
        }
        cov &= 0x1F;
        bool invert = swapped ? (mRight != mGoesLeft) : (mRight == mGoesLeft);
        coverage = invert ? 0x1F - cov : cov;
    }

    int32_t mStep = 0;
    bool mGoesLeft = false;
    bool mShallow = false;
    Interp mInterp;

private:
    bool mRight = false;
    int32_t mX0 = 0, mXMin = 0, mXMax = 0, mXLen = 0, mYLen = 0;
    int32_t mAcc = 0;
    int32_t mY = 0;
    int32_t mCoverageStep = 0;
};

// What one pixel of the frame holds
struct Pixel {
    uint8_t r, g, b, a; // 6-bit color, 5-bit alpha
    uint32_t depth; // 24-bit Z or W
    uint8_t opaqueId; // polygon ID of the last opaque polygon (edge marking)
    uint8_t transId; // polygon ID of the last translucent polygon, if translucent
    bool translucent;
    bool fog;
    bool backFacing; // last drawn by a polygon seen from behind
    uint8_t edges; // polygon edge flags: 1 left, 2 right, 4 top, 8 bottom (0: polygon inside / rear plane)
    uint8_t coverage; // anti-aliasing coverage 0..31
};

class Renderer {
public:
    Renderer(const NtrGfxMemory *mem, const NtrGfxPolygonList *list, NtrGfx3DImage *out)
        : mMem(mem)
        , mList(list)
        , mOut(out)
        , mTex(mem)
        , mDispcnt(Io16(mem, 0x060))
        , mAlphaRef((mDispcnt & 0x4) ? (mem->io[0x340] & 0x1F) : 0)
    {
        for (int i = 0; i < 32; i++) {
            mToon[i] = Io16(mem, 0x380 + i * 2);
        }
    }

    void Run()
    {
        const char *trace = getenv("NTRGFX_PIXEL3D");
        if (trace == NULL || sscanf(trace, "%d,%d", &mTraceX, &mTraceY) != 2) {
            mTraceX = mTraceY = -1;
        }
        ClearRearPlane();
        SetupPolygons();
        mPrevShadowMask = false;
        for (int y = 0; y < H; y++) {
            for (Poly &p : mPolys) {
                if (y >= p.yTop && (y < p.yBottom || (y == p.yTop && p.yBottom == p.yTop))) {
                    DrawLine(p, y);
                }
            }
        }
        FinalPass();
        for (int y = 0; y < H; y++) {
            for (int x = 0; x < W; x++) {
                const Pixel &p = mTop[y][x];
                mOut->color[y][x] = p.r | (p.g << 6) | (p.b << 12);
                mOut->alpha[y][x] = p.a;
            }
        }
    }

private:
    // A polygon prepared for drawing: its vertices, top/bottom, and the two edges being walked
    struct Poly {
        const NtrGfxPolygon3D *data;
        uint32_t index;
        const NtrGfxVertex3D *v[10];
        int n;
        int vTop, vBottom;
        int32_t yTop, yBottom;
        bool frontFacing;
        bool shadowMask, shadow;
        int curL, nextL, curR, nextR;
        Edge left, right;
    };

    const NtrGfxMemory *mMem;
    const NtrGfxPolygonList *mList;
    NtrGfx3DImage *mOut;
    TextureMemory mTex;
    uint16_t mDispcnt;
    uint32_t mAlphaRef;
    uint16_t mToon[32];
    std::vector<Poly> mPolys;
    Pixel mTop[H][W]; // top-most pixel
    Pixel mBelow[H][W]; // the pixel under it
    Pixel mBorder; // outside the screen (edge marking looks at neighbours)
    uint8_t mStencil[2][W]; // shadow mask bits, per line (alternating)
    bool mPrevShadowMask;
    int mTraceX, mTraceY;

    // Rear plane (GBATEK "DS 3D Rear-Plane"); depth 15 -> 24 bits as X * 0x200 + 0x1FF
    void ClearRearPlane()
    {
        uint32_t clearColor = Io32(mMem, 0x350);
        uint32_t clearDepth = Io32(mMem, 0x354);
        Pixel border = {};
        border.depth = (clearDepth & 0x7FFF) * 0x200 + 0x1FF;
        border.opaqueId = (clearColor >> 24) & 0x3F;
        mBorder = border;
        if (mDispcnt & 0x4000) {
            // Bitmap: color in texture slot 2, depth + fog in slot 3, scrolled by CLRIMAGE_OFFSET
            uint8_t yOff = (clearDepth >> 24) & 0xFF;
            for (int y = 0; y < H; y++, yOff++) {
                uint8_t xOff = (clearDepth >> 16) & 0xFF;
                for (int x = 0; x < W; x++, xOff++) {
                    uint32_t at = ((uint32_t)yOff << 9) + ((uint32_t)xOff << 1);
                    uint16_t c = mTex.Tex16(0x40000 + at);
                    uint16_t d = mTex.Tex16(0x60000 + at);
                    RGBA rgba = From15(c, (c & 0x8000) ? 31 : 0);
                    Pixel p = border;
                    p.r = (uint8_t)rgba.r, p.g = (uint8_t)rgba.g, p.b = (uint8_t)rgba.b, p.a = (uint8_t)rgba.a;
                    p.depth = (d & 0x7FFF) * 0x200 + 0x1FF;
                    p.fog = (d & 0x8000) != 0;
                    mTop[y][x] = p;
                }
            }
        } else {
            RGBA rgba = From15((uint16_t)clearColor, (clearColor >> 16) & 0x1F);
            Pixel p = border;
            p.r = (uint8_t)rgba.r, p.g = (uint8_t)rgba.g, p.b = (uint8_t)rgba.b, p.a = (uint8_t)rgba.a;
            p.fog = (clearColor & 0x8000) != 0;
            for (int y = 0; y < H; y++) {
                for (int x = 0; x < W; x++) {
                    mTop[y][x] = p;
                }
            }
        }
        memset(mBelow, 0, sizeof(mBelow));
    }

    static bool Translucent(const NtrGfxPolygon3D &poly)
    {
        uint32_t alpha = (poly.attr >> 16) & 0x1F;
        uint32_t format = (poly.texParam >> 26) & 7;
        return (alpha != 0 && alpha != 31) || format == 1 || format == 6;
    }

    // Drawing order: opaque polygons first, by bottom Y then top Y; then translucent ones, sorted the same way unless
    // SWAP_BUFFERS asked for manual sorting (then in the order sent). Degenerate polygons (W = 0, or below the screen)
    // aren't drawn.
    void SetupPolygons()
    {
        std::vector<std::pair<uint32_t, Poly>> keyed;
        for (uint32_t i = 0; i < mList->numPolygons; i++) {
            const NtrGfxPolygon3D &data = mList->polygons[i];
            Poly p = {};
            p.data = &data;
            p.index = i;
            p.n = std::min<int>(data.numVertices, 10);
            if (p.n < 3) {
                continue;
            }
            bool degenerate = false;
            // Top: the first vertex with the smallest Y; bottom: largest Y, rightmost on ties
            p.yTop = H;
            p.yBottom = 0;
            int32_t xBottom = 0;
            for (int k = 0; k < p.n; k++) {
                const NtrGfxVertex3D *v = &mList->vertices[data.vertices[k]];
                p.v[k] = v;
                if (v->y < p.yTop) {
                    p.yTop = v->y;
                    p.vTop = k;
                }
                if (v->y > p.yBottom || (v->y == p.yBottom && v->x > xBottom)) {
                    p.yBottom = v->y;
                    xBottom = v->x;
                    p.vBottom = k;
                }
                degenerate |= v->w == 0;
            }
            if (degenerate || p.yBottom > H) {
                continue;
            }
            p.frontFacing = !data.backFacing;
            p.shadowMask = (data.attr & 0x3F000030) == 0x00000030;
            p.shadow = (data.attr & 0x30) == 0x30 && !p.shadowMask;
            uint32_t key = ((uint32_t)p.yBottom << 8) | (uint32_t)p.yTop;
            if (Translucent(data)) {
                key = 0x10000 | (mList->manualSort ? 0 : key);
            }
            keyed.push_back({ key, p });
        }
        std::stable_sort(keyed.begin(), keyed.end(), [](const auto &a, const auto &b) { return a.first < b.first; });
        mPolys.clear();
        mPolys.reserve(keyed.size());
        for (auto &k : keyed) {
            mPolys.push_back(k.second);
            StartPolygon(mPolys.back());
        }
    }

    // Vertex order around the polygon: the left side goes forwards from the top for front-facing polygons
    int Next(const Poly &p, int k, bool leftSide) const
    {
        bool forwards = leftSide == p.frontFacing;
        return forwards ? (k + 1) % p.n : (k + p.n - 1) % p.n;
    }

    void StartPolygon(Poly &p)
    {
        p.curL = p.curR = p.vTop;
        p.nextL = Next(p, p.vTop, true);
        p.nextR = Next(p, p.vTop, false);
        bool wBuffer = p.data->wBuffer;
        if (p.yTop == p.yBottom) {
            // Flat: from the leftmost to the rightmost of vertices 0, 1 and the last
            int l = 0, r = 0;
            for (int k : { 1, p.n - 1 }) {
                if (p.v[k]->x < p.v[l]->x) {
                    l = k;
                }
                if (p.v[k]->x > p.v[r]->x) {
                    r = k;
                }
            }
            p.curL = p.nextL = l;
            p.curR = p.nextR = r;
            p.left.SetPoint(p.v[l]->x, wBuffer);
            p.right.SetPoint(p.v[r]->x, wBuffer);
            return;
        }
        SetupEdge(p, true, p.yTop);
        SetupEdge(p, false, p.yTop);
    }

    // Moves a side on to the edge that contains line y
    void SetupEdge(Poly &p, bool leftSide, int32_t y)
    {
        int &cur = leftSide ? p.curL : p.curR;
        int &next = leftSide ? p.nextL : p.nextR;
        while (y >= p.v[next]->y && cur != p.vBottom) {
            cur = next;
            next = Next(p, cur, leftSide);
        }
        Edge &e = leftSide ? p.left : p.right;
        e.Setup(!leftSide, p.v[cur]->x, p.v[next]->x, p.v[cur]->y, p.v[next]->y, p.v[cur]->w, p.v[next]->w, y, p.data->wBuffer);
    }

    // Depth test (GBATEK "Depth Test"; tolerance of "equal": Z +-0x200, W +-0xFF). A front-facing pixel also wins
    // over an opaque back-facing one at equal depth.
    bool DepthPasses(const Poly &p, const Pixel &dst, int32_t z) const
    {
        int32_t d = (int32_t)dst.depth;
        if (p.data->attr & 0x4000) {
            int32_t diff = d - z;
            return p.data->wBuffer ? (uint32_t)(diff + 0xFF) <= 0x1FE : (uint32_t)(diff + 0x200) <= 0x400;
        }
        if (p.frontFacing && !dst.translucent && dst.backFacing) {
            return z <= d;
        }
        return z < d;
    }

    // One line of a polygon: left edge pixels, inside, right edge pixels
    void DrawLine(Poly &p, int32_t y)
    {
        const NtrGfxPolygon3D &data = *p.data;
        uint32_t polyAlpha = (data.attr >> 16) & 0x1F;
        bool wire = polyAlpha == 0;
        if (p.shadowMask) {
            // A run of shadow mask polygons starts with a clear stencil
            if (!mPrevShadowMask) {
                memset(mStencil[y & 1], 0, W);
            }
            mPrevShadowMask = true;
        } else {
            mPrevShadowMask = false;
        }

        if (p.yTop != p.yBottom) {
            if (y >= p.v[p.nextL]->y && p.curL != p.vBottom) {
                SetupEdge(p, true, y);
            }
            if (y >= p.v[p.nextR]->y && p.curR != p.vBottom) {
                SetupEdge(p, false, y);
            }
        }

        int32_t xStart = p.left.X(), xEnd = p.right.X();
        int32_t wl = p.left.mInterp.Value(p.v[p.curL]->w, p.v[p.nextL]->w);
        int32_t wr = p.right.mInterp.Value(p.v[p.curR]->w, p.v[p.nextR]->w);
        int32_t zl = p.left.mInterp.Depth(p.v[p.curL]->z, p.v[p.nextL]->z);
        int32_t zr = p.right.mInterp.Depth(p.v[p.curR]->z, p.v[p.nextR]->z);

        // A vertical right edge is moved one pixel left (unless the left edge is vertical too and the span has
        // zero width, or it's at the screen's left border)
        if (p.right.mStep == 0 && (p.left.mStep != 0 || xStart != xEnd) && xEnd != 0) {
            xEnd--;
        }

        // Fill rules: which edge pixels are drawn. Always all of them with anti-aliasing / edge marking, for
        // translucent pixels with alpha blending, and for wireframes.
        const Edge *le = &p.left, *re = &p.right;
        int lc = p.curL, ln = p.nextL, rc = p.curR, rn = p.nextR;
        int32_t lLen = 0, rLen = 0, lCov = 0, rCov = 0;
        bool alwaysFill = (mDispcnt & 0x30) || (polyAlpha < 31 && (mDispcnt & 0x8)) || wire;
        bool lastLine = y == p.yBottom - 1;
        bool lFill, rFill;
        if (xStart > xEnd) {
            // Edges crossed: drawn from the right edge to the left one
            std::swap(le, re);
            std::swap(lc, rc);
            std::swap(ln, rn);
            p.right.Params(true, lLen, lCov);
            p.left.Params(true, rLen, rCov);
            std::swap(xStart, xEnd);
            std::swap(wl, wr);
            std::swap(zl, zr);
            bool besideFlatBottom = lastLine && p.v[ln]->x != p.v[rn]->x;
            lFill = alwaysFill || p.right.mGoesLeft || !p.right.mShallow || (besideFlatBottom && p.right.mShallow);
            rFill = alwaysFill || (!p.left.mGoesLeft && p.left.mShallow) || (!(p.left.mGoesLeft && p.left.mShallow) && p.right.mStep == 0)
                || (besideFlatBottom && p.left.mShallow);
        } else {
            p.left.Params(false, lLen, lCov);
            p.right.Params(false, rLen, rCov);
            bool besideFlatBottom = lastLine && p.v[ln]->x != p.v[rn]->x;
            // Left edge: unless shallow and leaning inwards; right edge: shallow and leaning outwards, or vertical;
            // shallow edges on the last line next to a flat bottom; identical overlapping edges
            lFill = alwaysFill || p.left.mGoesLeft || !p.left.mShallow || (besideFlatBottom && p.left.mShallow)
                || (p.left.mStep == p.right.mStep && xStart + lLen == xEnd + 1);
            rFill = alwaysFill || (!p.right.mGoesLeft && p.right.mShallow) || p.right.mStep == 0 || (besideFlatBottom && p.right.mShallow);
        }

        // Attributes at both ends of the line
        const Interp &il = le->mInterp, &ir = re->mInterp;
        LineEnds ends;
        for (int ch = 0; ch < 3; ch++) {
            ends.cl[ch] = il.Value(p.v[lc]->color[ch], p.v[ln]->color[ch]);
            ends.cr[ch] = ir.Value(p.v[rc]->color[ch], p.v[rn]->color[ch]);
        }
        ends.sl = il.Value(p.v[lc]->s, p.v[ln]->s);
        ends.tl = il.Value(p.v[lc]->t, p.v[ln]->t);
        ends.sr = ir.Value(p.v[rc]->s, p.v[rn]->s);
        ends.tr = ir.Value(p.v[rc]->t, p.v[rn]->t);
        ends.zl = zl;
        ends.zr = zr;
        ends.ix.Setup(xStart, xEnd + 1, wl, wr, data.wBuffer, false);

        uint8_t yEdge = y == p.yTop ? 4 : (lastLine ? 8 : 0);
        int32_t x = std::max(xStart, 0);

        // Part 1: left edge
        int32_t limit = std::min({ xStart + lLen, xEnd + 1, W });
        int32_t xCov = StartCoverage(lCov);
        if (!lFill) {
            x = limit;
        } else {
            for (; x < limit; x++) {
                PlotPixel(p, ends, x, y, yEdge | 1, lCov, &xCov, true);
            }
        }
        // Part 2: inside (wireframe polygons: only on their top and bottom lines)
        limit = std::min({ xEnd - rLen + 1, xEnd + 1, W });
        if (wire && yEdge == 0) {
            x = std::max(x, limit);
        } else {
            for (; x < limit; x++) {
                PlotPixel(p, ends, x, y, yEdge, 0, NULL, false);
            }
        }
        // Part 3: right edge
        limit = std::min(xEnd + 1, W);
        xCov = StartCoverage(rCov);
        if (rFill) {
            for (; x < limit; x++) {
                PlotPixel(p, ends, x, y, yEdge | 2, rCov, &xCov, false);
            }
        }

        p.left.NextLine();
        p.right.NextLine();
    }

    // A line's attributes at its two ends, and the interpolation across it
    struct LineEnds {
        int32_t cl[3], cr[3];
        int32_t sl, tl, sr, tr;
        int32_t zl, zr;
        Interp ix;
    };

    // X-major anti-aliasing coverage: the running value starts here (0 for Y-major edges)
    static int32_t StartCoverage(int32_t edgeCoverage)
    {
        if (!(edgeCoverage & (int32_t)0x80000000)) {
            return 0;
        }
        int32_t c = (edgeCoverage >> 12) & 0x3FF;
        return c == 0x3FF ? 0 : c;
    }

    // edgeCoverage / xCov: the edge's coverage and the running X-major coverage (NULL inside the polygon)
    void PlotPixel(const Poly &p, LineEnds &ends, int32_t x, int32_t y, uint8_t edge, int32_t edgeCoverage, int32_t *xCov, bool leftEdge)
    {
        const NtrGfxPolygon3D &data = *p.data;
        ends.ix.Move(x);
        int32_t z = ends.ix.Depth(ends.zl, ends.zr);
        bool below = false;
        Pixel *dst = &mTop[y][x];

        if (p.shadowMask) {
            // Shadow volume mask: nothing drawn; the stencil records where the depth test fails
            if (!DepthPasses(p, *dst, z)) {
                mStencil[y & 1][x] = 1;
            }
            if (dst->edges && !DepthPasses(p, mBelow[y][x], z)) {
                mStencil[y & 1][x] |= 2;
            }
            return;
        }

        bool edgesBelow = dst->edges != 0;
        if (p.shadow) {
            uint8_t st = mStencil[y & 1][x];
            if (!st) {
                return;
            }
            if (!(st & 1)) {
                dst = &mBelow[y][x];
                below = true;
            }
            if (!(st & 2)) {
                edgesBelow = false; // no shadow under anti-aliased edges
            }
        }

        // Against the top pixel; if that fails and it's an anti-aliased edge, against the pixel under it
        if (!DepthPasses(p, *dst, z)) {
            if (!edgesBelow || below) {
                return;
            }
            dst = &mBelow[y][x];
            below = true;
            if (!DepthPasses(p, *dst, z)) {
                return;
            }
        }

        int32_t col[3];
        for (int ch = 0; ch < 3; ch++) {
            col[ch] = ends.ix.Value(ends.cl[ch], ends.cr[ch]);
        }
        int16_t s = (int16_t)ends.ix.Value(ends.sl, ends.sr), t = (int16_t)ends.ix.Value(ends.tl, ends.tr);
        RGBA c = Shade(data, (uint32_t)col[0] >> 3, (uint32_t)col[1] >> 3, (uint32_t)col[2] >> 3, s, t);
        if (x == mTraceX && y == mTraceY) {
            fprintf(stderr, "3D pixel %d,%d: polygon %u edge %x z %06x s %d t %d color %d,%d,%d -> %u,%u,%u a%u over %u,%u,%u a%u z %06x%s\n", x, y, p.index, edge, z, s, t, col[0], col[1], col[2], c.r, c.g, c.b, c.a, dst->r, dst->g, dst->b, dst->a, dst->depth, below ? " (lower layer)" : "");
        }
        if (c.a <= mAlphaRef) {
            return; // alpha test
        }

        if (c.a == 31) {
            Pixel n = {};
            n.r = (uint8_t)c.r, n.g = (uint8_t)c.g, n.b = (uint8_t)c.b, n.a = 31;
            n.depth = (uint32_t)z;
            n.opaqueId = (data.attr >> 24) & 0x3F;
            n.fog = (data.attr >> 15) & 1;
            n.backFacing = !p.frontFacing;
            n.edges = edge;
            if (mDispcnt & 0x10) {
                // Anti-aliasing: edge pixels get a coverage; the old pixel moves down a layer
                if (xCov == NULL) {
                    n.coverage = edge ? 31 : 0;
                } else if (edgeCoverage & (int32_t)0x80000000) {
                    n.coverage = (uint8_t)(leftEdge ? std::min(*xCov >> 5, 31) : std::max(0x1F - (*xCov >> 5), 0));
                    *xCov += edgeCoverage & 0x3FF;
                } else {
                    n.coverage = (uint8_t)edgeCoverage;
                }
                if (!below && (xCov != NULL || edge)) {
                    mBelow[y][x] = *dst;
                }
            }
            *dst = n;
            return;
        }

        if (!(data.attr & 0x800)) {
            z = -1; // translucent pixels keep the old depth unless POLYGON_ATTR bit 11
        }
        PlotTranslucent(p, *dst, c, z);
        if (edgesBelow && !below) {
            PlotTranslucent(p, mBelow[y][x], c, z);
        }
    }

    void PlotTranslucent(const Poly &p, Pixel &dst, RGBA c, int32_t z)
    {
        uint8_t id = (p.data->attr >> 24) & 0x3F;
        // Not twice with the same translucent polygon ID (shadows: nor on an opaque pixel of their own ID)
        if (dst.translucent) {
            if (dst.transId == id) {
                return;
            }
        } else if (p.shadow && dst.opaqueId == id) {
            return;
        }
        // GBATEK "Alpha-Blending": (Poly * (A + 1) + FrameBuf * (31 - A)) / 32, unless the old pixel is transparent
        if (dst.a != 0) {
            if (mDispcnt & 0x8) {
                c.r = (c.r * (c.a + 1) + dst.r * (31 - c.a)) >> 5;
                c.g = (c.g * (c.a + 1) + dst.g * (31 - c.a)) >> 5;
                c.b = (c.b * (c.a + 1) + dst.b * (31 - c.a)) >> 5;
            }
            c.a = std::max<uint32_t>(c.a, dst.a);
        }
        dst.r = (uint8_t)c.r, dst.g = (uint8_t)c.g, dst.b = (uint8_t)c.b, dst.a = (uint8_t)c.a;
        if (z != -1) {
            dst.depth = (uint32_t)z;
        }
        dst.fog = dst.fog && ((p.data->attr >> 15) & 1);
        dst.backFacing = !p.frontFacing;
        dst.transId = id;
        dst.translucent = true;
    }

    // Vertex color (6-bit) and texture combined (GBATEK "DS 3D Texture Blending")
    RGBA Shade(const NtrGfxPolygon3D &data, uint32_t vr, uint32_t vg, uint32_t vb, int16_t s, int16_t t) const
    {
        uint32_t mode = (data.attr >> 4) & 3;
        uint32_t polyAlpha = (data.attr >> 16) & 0x1F;
        bool highlight = mode == 2 && (mDispcnt & 0x2);
        uint32_t toonIndex = vr >> 1;
        if (mode == 2) {
            if (highlight) {
                vg = vb = vr; // the vertex red is used for all three, the toon color added at the end
            } else {
                RGBA toon = From15(mToon[toonIndex], 0);
                vr = toon.r, vg = toon.g, vb = toon.b;
            }
        }
        RGBA out;
        if ((mDispcnt & 1) && ((data.texParam >> 26) & 7) != 0) {
            uint16_t tcolor;
            uint32_t ta;
            FetchTexel(mTex, data.texParam, data.texPltt, s, t, tcolor, ta);
            RGBA tx = From15(tcolor, ta);
            if (mode & 1) {
                // Decal (and shadow polygons)
                if (ta == 0) {
                    out = { vr, vg, vb, polyAlpha };
                } else if (ta == 31) {
                    out = { tx.r, tx.g, tx.b, polyAlpha };
                } else {
                    out = { (tx.r * ta + vr * (31 - ta)) >> 5, (tx.g * ta + vg * (31 - ta)) >> 5, (tx.b * ta + vb * (31 - ta)) >> 5, polyAlpha };
                }
            } else {
                // Modulation
                out = { ((tx.r + 1) * (vr + 1) - 1) >> 6, ((tx.g + 1) * (vg + 1) - 1) >> 6, ((tx.b + 1) * (vb + 1) - 1) >> 6, ((ta + 1) * (polyAlpha + 1) - 1) >> 5 };
            }
        } else {
            out = { vr, vg, vb, polyAlpha };
        }
        if (highlight) {
            RGBA toon = From15(mToon[toonIndex], 0);
            out.r = std::min(out.r + toon.r, 63u);
            out.g = std::min(out.g + toon.g, 63u);
            out.b = std::min(out.b + toon.b, 63u);
        }
        if (polyAlpha == 0) {
            out.a = 31; // wireframe
        }
        return out;
    }

    const Pixel &At(int x, int y) const
    {
        if (x < 0 || x >= W || y < 0 || y >= H) {
            return mBorder;
        }
        return mTop[y][x];
    }

    // Fog density 0..128 at a depth (GBATEK "FOG_OFFSET"; one step = 0x80000 >> shift in 24-bit depth units)
    uint32_t FogDensity(uint32_t depth) const
    {
        uint32_t offset = (Io16(mMem, 0x35C) & 0x7FFF) * 0x200;
        uint32_t shift = (mDispcnt >> 8) & 0xF;
        uint32_t id, frac;
        if (depth < offset) {
            id = 0;
            frac = 0;
        } else {
            uint32_t z = ((depth - offset) >> 2) << shift;
            id = z >> 17;
            if (id >= 32) {
                id = 32;
                frac = 0;
            } else {
                frac = z & 0x1FFFF;
            }
        }
        // The table, with entry 0 repeated in front and entry 31 behind
        auto table = [&](uint32_t i) { return (uint32_t)(mMem->io[0x360 + (i == 0 ? 0 : std::min(i - 1, 31u))] & 0x7F); };
        uint32_t density = (table(id) * (0x20000 - frac) + table(id + 1) * frac) >> 17;
        return density >= 127 ? 128 : density;
    }

    void ApplyFog(Pixel &p) const
    {
        uint32_t fogColor = Io32(mMem, 0x358);
        RGBA f = From15((uint16_t)fogColor, (fogColor >> 16) & 0x1F);
        uint32_t d = FogDensity(p.depth);
        if (!(mDispcnt & 0x40)) {
            p.r = (uint8_t)((f.r * d + p.r * (128 - d)) >> 7);
            p.g = (uint8_t)((f.g * d + p.g * (128 - d)) >> 7);
            p.b = (uint8_t)((f.b * d + p.b * (128 - d)) >> 7);
        }
        p.a = (uint8_t)((f.a * d + p.a * (128 - d)) >> 7);
    }

    // Edge marking, fog, anti-aliasing (GBATEK "DS 3D Toon, Edge, Fog, Alpha-Blending, Anti-Aliasing")
    void FinalPass()
    {
        if (mDispcnt & 0x20) {
            // Edge marking: polygon edge pixels next to a pixel of another polygon ID that lies further away (looks at
            // IDs and depths only, which marking doesn't change)
            static const int kDir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
            for (int y = 0; y < H; y++) {
                for (int x = 0; x < W; x++) {
                    Pixel &p = mTop[y][x];
                    if (!p.edges) {
                        continue;
                    }
                    bool mark = false;
                    for (const auto &d : kDir) {
                        const Pixel &n = At(x + d[0], y + d[1]);
                        mark |= n.opaqueId != p.opaqueId && p.depth < n.depth;
                    }
                    if (mark) {
                        RGBA e = From15(Io16(mMem, 0x330 + (p.opaqueId >> 3) * 2), 0);
                        p.r = (uint8_t)e.r, p.g = (uint8_t)e.g, p.b = (uint8_t)e.b;
                        p.coverage = 0x10; // marking breaks the anti-aliasing coverage
                    }
                }
            }
        }
        if (mDispcnt & 0x80) {
            // Fog, on the top two pixels
            for (int y = 0; y < H; y++) {
                for (int x = 0; x < W; x++) {
                    Pixel &p = mTop[y][x];
                    if (p.fog) {
                        ApplyFog(p);
                    }
                    if (p.edges && mBelow[y][x].fog) {
                        ApplyFog(mBelow[y][x]);
                    }
                }
            }
        }
        if (mDispcnt & 0x10) {
            // Anti-aliasing: edge pixels blend with the pixel below by their coverage
            for (int y = 0; y < H; y++) {
                for (int x = 0; x < W; x++) {
                    Pixel &top = mTop[y][x];
                    if (!top.edges || top.coverage == 0x1F) {
                        continue;
                    }
                    const Pixel &bot = mBelow[y][x];
                    if (top.coverage == 0) {
                        top.r = bot.r, top.g = bot.g, top.b = bot.b, top.a = bot.a;
                        continue;
                    }
                    uint32_t cv = top.coverage + 1u;
                    if (bot.a > 0) {
                        top.r = (uint8_t)((top.r * cv + bot.r * (32 - cv)) >> 5);
                        top.g = (uint8_t)((top.g * cv + bot.g * (32 - cv)) >> 5);
                        top.b = (uint8_t)((top.b * cv + bot.b * (32 - cv)) >> 5);
                    }
                    top.a = (uint8_t)((top.a * cv + bot.a * (32 - cv)) >> 5);
                }
            }
        }
    }
};

} // namespace

void NtrGfx_Render3D(const NtrGfxMemory *mem, const NtrGfxPolygonList *list, NtrGfx3DImage *out)
{
    std::unique_ptr<Renderer> renderer(new Renderer(mem, list, out)); // large (pixel buffers, texture memory)
    renderer->Run();
}
