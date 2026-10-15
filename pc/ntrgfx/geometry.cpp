// The 3D Geometry Engine (GBATEK "DS 3D Geometry Commands" .. "DS 3D Tests"): matrix stacks, vertex transform,
// lighting, texture coordinate generation, polygon assembly, culling, clipping and the viewport transform. Its output
// is the polygon list (NtrGfxPolygonList) that SWAP_BUFFERS passes to the Rendering Engine (render3d.cpp).
//
// Where GBATEK leaves the arithmetic open (lighting precision, culling, clipping interpolation, the viewport divider,
// W normalization), this follows melonDS's hardware research (its source read as documentation, our own code).

#include "internal.hpp"

#include <initializer_list>
#include <stddef.h>
#include <stdlib.h>

using namespace ntrgfx;

namespace {

// Matrices are 4x4, m[row * 4 + column], signed 20.12 fixed point (GBATEK "DS 3D Matrix Types")
struct Matrix {
    int32_t m[16];
};

const Matrix kIdentity = { { 0x1000, 0, 0, 0, 0, 0x1000, 0, 0, 0, 0, 0x1000, 0, 0, 0, 0, 0x1000 } };

// Returns a * b (row vectors: a is applied first). rows: rows of a that take part (3 = 3x3 / 4x3 multiplies leave
// the bottom row of the result as b's; translation uses `implicitOne` for the 4x3 bottom row's fourth column).
Matrix Multiply(const Matrix &a, const Matrix &b)
{
    Matrix r;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int64_t sum = 0;
            for (int k = 0; k < 4; k++) {
                sum += (int64_t)a.m[i * 4 + k] * b.m[k * 4 + j];
            }
            r.m[i * 4 + j] = (int32_t)(sum >> 12);
        }
    }
    return r;
}

// Number of parameters per command; -1 = invalid command (ignored, fetches no parameters)
int ParamCount(uint32_t op)
{
    switch (op) {
    case 0x00:
    case 0x11:
    case 0x15:
    case 0x41:
        return 0;
    case 0x10:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2A:
    case 0x2B:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x40:
    case 0x50:
    case 0x60:
    case 0x72:
        return 1;
    case 0x23:
    case 0x71:
        return 2;
    case 0x1B:
    case 0x1C:
    case 0x70:
        return 3;
    case 0x1A:
        return 9;
    case 0x17:
    case 0x19:
        return 12;
    case 0x16:
    case 0x18:
        return 16;
    case 0x34:
        return 32;
    default:
        return -1;
    }
}

// Sign-extends the low `bits` bits of v
inline int32_t SignExtend(uint32_t v, int bits)
{
    return (int32_t)(v << (32 - bits)) >> (32 - bits);
}

// A vertex in clip space, with its attributes
struct ClipVertex {
    int32_t pos[4]; // x, y, z, w
    int32_t color[3]; // 5-bit color << 12, low 12 bits fraction (filled with 0xFFF)
    int16_t s, t;
};

} // namespace

struct NtrGfxGeometry {
    // Matrices (GBATEK "DS 3D Matrix Stack")
    uint32_t mtxMode;
    Matrix projection, position, vector, texture;
    Matrix projStack, posStack[32], vecStack[32], texStack;
    uint32_t projSP, posSP, texSP;
    bool stackError;

    // Vertex state
    int16_t vtx[3]; // last VTX coordinates (VTX_XY/XZ/YZ/DIFF keep the others)
    uint8_t color[3]; // current vertex color, 5-bit
    int16_t rawS, rawT; // TEXCOORD as sent
    int16_t texS, texT; // texture coordinates for the next vertex
    int16_t normal[3]; // NORMAL as sent (1+0+9)

    // Lighting (GBATEK "DS 3D Polygon Light Parameters")
    int32_t lightDir[4][3]; // after the directional matrix, negated, 1+10 bits
    int32_t specRecip[4];
    uint8_t lightColor[4][3];
    uint8_t diffuse[3], ambient[3], specular[3], emission[3];
    bool useShininess;
    uint8_t shininess[128];

    // Polygon state
    uint32_t pendingAttr, attr; // POLYGON_ATTR, applied at BEGIN_VTXS
    uint32_t texParam, texPltt;
    uint32_t primitive; // BEGIN_VTXS type, 4 = outside a vertex list
    ClipVertex strip[4]; // vertices of the polygon being built
    int numInPoly;
    int stripCount; // polygons emitted in the current strip
    int32_t viewX0, viewY0, viewWidth, viewHeight; // viewport, Y counted from the top
    uint32_t swapParam; // bits of the last SWAP_BUFFERS (bit 1: W-buffering for new polygons)
    bool swapPending;
    uint32_t zeroDotWLimit; // DISP_1DOT_DEPTH

    // Test results
    int32_t posResult[4];
    int16_t vecResult[3];
    bool boxResult;

    NtrGfxPolygonList list; // being built
    bool overflow;
};

namespace {

Matrix Clip(const NtrGfxGeometry *g)
{
    return Multiply(g->position, g->projection);
}

// Applies a matrix operation to the current matrix (MTX_MODE 2: position and vector; MTX_SCALE only position)
template <typename F>
void ApplyToCurrent(NtrGfxGeometry *g, F op, bool scale)
{
    switch (g->mtxMode) {
    case 0:
        op(g->projection);
        break;
    case 1:
        op(g->position);
        break;
    case 2:
        op(g->position);
        if (!scale) {
            op(g->vector);
        }
        break;
    default:
        op(g->texture);
        break;
    }
}

void LoadParams(Matrix &m, const uint32_t *p, int rows, int cols)
{
    m = kIdentity;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m.m[i * 4 + j] = (int32_t)p[i * cols + j];
        }
    }
}

// MTX_MULT_3x3 leaves the current matrix's bottom row alone
void Mult3x3(Matrix &c, const Matrix &m)
{
    Matrix r = Multiply(m, c);
    for (int j = 0; j < 4; j++) {
        r.m[12 + j] = c.m[12 + j];
    }
    c = r;
}

// MTX_SCALE: rows 0..2 scaled
void Scale(Matrix &c, const uint32_t *p)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            c.m[i * 4 + j] = (int32_t)(((int64_t)(int32_t)p[i] * c.m[i * 4 + j]) >> 12);
        }
    }
}

// MTX_TRANS: row 3 += t * rows 0..2
void Translate(Matrix &c, const uint32_t *p)
{
    for (int j = 0; j < 4; j++) {
        int64_t sum = (int64_t)(int32_t)p[0] * c.m[j] + (int64_t)(int32_t)p[1] * c.m[4 + j] + (int64_t)(int32_t)p[2] * c.m[8 + j];
        c.m[12 + j] += (int32_t)(sum >> 12);
    }
}

// A 1+0+9 vector (NORMAL, LIGHT_VECTOR, VEC_TEST) from a command parameter
void UnpackVector(uint32_t param, int16_t out[3])
{
    out[0] = (int16_t)SignExtend(param, 10);
    out[1] = (int16_t)SignExtend(param >> 10, 10);
    out[2] = (int16_t)SignExtend(param >> 20, 10);
}

// NORMAL: vertex color from the lights (GBATEK "Internal Operation on Normal Command"; precision per melonDS)
void Lighting(NtrGfxGeometry *g)
{
    const int32_t *tm = g->texture.m;
    const int16_t *n = g->normal;
    if ((g->texParam >> 30) == 2) {
        // Texture coordinates from the normal: (Nx Ny Nz) * texture matrix + (S T)
        g->texS = (int16_t)(g->rawS + (int32_t)(((int64_t)n[0] * tm[0] + (int64_t)n[1] * tm[4] + (int64_t)n[2] * tm[8]) >> 21));
        g->texT = (int16_t)(g->rawT + (int32_t)(((int64_t)n[0] * tm[1] + (int64_t)n[1] * tm[5] + (int64_t)n[2] * tm[9]) >> 21));
    }
    // Normal through the directional matrix, to 1 + 10 bits
    const int32_t *vm = g->vector.m;
    int32_t nt[3];
    for (int j = 0; j < 3; j++) {
        nt[j] = (int32_t)((uint32_t)(n[0] * vm[j] + n[1] * vm[4 + j] + n[2] * vm[8 + j]) << 9) >> 21;
    }

    uint32_t acc[3];
    for (int ch = 0; ch < 3; ch++) {
        acc[ch] = (uint32_t)g->emission[ch] << 14;
    }
    for (int i = 0; i < 4; i++) {
        if (!(g->attr & (1u << i))) {
            continue;
        }
        // Dot product; the bottom 9 bits of each product are dropped before adding
        int32_t dot = ((g->lightDir[i][0] * nt[0]) >> 9) + ((g->lightDir[i][1] * nt[1]) >> 9) + ((g->lightDir[i][2] * nt[2]) >> 9);
        int32_t shine = 0;
        if (dot > 0) {
            // Diffuse: dot as signed 11 bits, each product truncated to 20 bits
            int32_t diffDot = SignExtend((uint32_t)dot, 11);
            for (int ch = 0; ch < 3; ch++) {
                acc[ch] += (uint32_t)(g->diffuse[ch] * g->lightColor[i][ch] * diffDot) & 0xFFFFF;
            }
            // Specular, from the half vector's angle: (dot + Nz) as s11, squared to 10 bits, times the reciprocal
            int32_t h = SignExtend((uint32_t)(dot + nt[2]), 11);
            h = ((h * h) >> 10) & 0x3FF;
            shine = ((h * g->specRecip[i]) >> 8) - (1 << 9);
            if (shine < 0) {
                shine = 0;
            } else {
                shine = SignExtend((uint32_t)shine, 14);
                shine = shine < 0 ? 0 : (shine > 0x1FF ? 0x1FF : shine);
            }
        }
        if (g->useShininess) {
            shine = g->shininess[shine >> 2] << 1;
        }
        for (int ch = 0; ch < 3; ch++) {
            acc[ch] += (uint32_t)((g->specular[ch] * shine + (g->ambient[ch] << 9)) * g->lightColor[i][ch]);
        }
    }
    for (int ch = 0; ch < 3; ch++) {
        uint32_t c = acc[ch] >> 14;
        g->color[ch] = (uint8_t)(c > 31 ? 31 : c);
    }
}

// Clipping against one pair of planes (comp <= w, then comp >= -w): each vertex outside is replaced by the points
// where its two edges cross the plane (interpolated from the outside vertex towards the inside one). Polygons crossing
// the far plane are rejected unless POLYGON_ATTR bit 12. Returns the new vertex count (0 = rejected).
int ClipAxis(ClipVertex *v, int n, int comp, bool farPlaneOk)
{
    auto cross = [&](const ClipVertex &out, const ClipVertex &in, int plane) {
        int64_t num = (int64_t)out.pos[3] - plane * out.pos[comp];
        int32_t den = (int32_t)(num - ((int64_t)in.pos[3] - plane * in.pos[comp]));
        auto lerp = [&](int32_t a, int32_t b) { return (int32_t)(a + ((int64_t)(b - a) * num) / den); };
        ClipVertex r = out;
        for (int k = 0; k < 4; k++) {
            if (k != comp) {
                r.pos[k] = lerp(out.pos[k], in.pos[k]);
            }
        }
        r.pos[comp] = plane * r.pos[3];
        for (int ch = 0; ch < 3; ch++) {
            r.color[ch] = lerp(out.color[ch], in.color[ch]);
        }
        r.s = (int16_t)lerp(out.s, in.s);
        r.t = (int16_t)lerp(out.t, in.t);
        return r;
    };
    ClipVertex tmp[10];
    int c = 0;
    for (int i = 0; i < n; i++) {
        const ClipVertex &cur = v[i];
        const ClipVertex &prev = v[(i + n - 1) % n], &next = v[(i + 1) % n];
        if (cur.pos[comp] > cur.pos[3]) {
            if (comp == 2 && !farPlaneOk) {
                return 0;
            }
            if (prev.pos[comp] <= prev.pos[3]) {
                tmp[c++] = cross(cur, prev, 1);
            }
            if (next.pos[comp] <= next.pos[3]) {
                tmp[c++] = cross(cur, next, 1);
            }
        } else {
            tmp[c++] = cur;
        }
    }
    n = c;
    c = 0;
    for (int i = 0; i < n; i++) {
        const ClipVertex &cur = tmp[i];
        const ClipVertex &prev = tmp[(i + n - 1) % n], &next = tmp[(i + 1) % n];
        if (cur.pos[comp] < -cur.pos[3]) {
            if (prev.pos[comp] >= -prev.pos[3]) {
                v[c++] = cross(cur, prev, -1);
            }
            if (next.pos[comp] >= -next.pos[3]) {
                v[c++] = cross(cur, next, -1);
            }
        } else {
            v[c++] = cur;
        }
    }
    // Colors keep only their integer part (fraction refilled)
    for (int i = 0; i < c; i++) {
        for (int ch = 0; ch < 3; ch++) {
            v[i].color[ch] = (v[i].color[ch] & ~0xFFF) + 0xFFF;
        }
    }
    return c;
}

// Z, then Y, then X
int ClipPolygon(ClipVertex *v, int n, bool farPlaneOk)
{
    for (int comp : { 2, 1, 0 }) {
        n = ClipAxis(v, n, comp, farPlaneOk);
        if (n == 0) {
            return 0;
        }
    }
    return n;
}

bool SamePosition(const ClipVertex &a, const ClipVertex &b)
{
    return a.pos[0] == b.pos[0] && a.pos[1] == b.pos[1] && a.pos[2] == b.pos[2] && a.pos[3] == b.pos[3];
}

// Stores one finished polygon (3 or 4 vertices, in order around it)
void SubmitPolygon(NtrGfxGeometry *g, const ClipVertex *in, int n)
{
    // Facing: the normal of (v0 - v1, v2 - v1) in (x, y, w), reduced to fit 32 bits, dotted with v1
    const int32_t *p0 = in[0].pos, *p1 = in[1].pos, *p2 = in[2].pos;
    int64_t nx = (int64_t)(p0[1] - p1[1]) * (p2[3] - p1[3]) - (int64_t)(p0[3] - p1[3]) * (p2[1] - p1[1]);
    int64_t ny = (int64_t)(p0[3] - p1[3]) * (p2[0] - p1[0]) - (int64_t)(p0[0] - p1[0]) * (p2[3] - p1[3]);
    int64_t nz = (int64_t)(p0[0] - p1[0]) * (p2[1] - p1[1]) - (int64_t)(p0[1] - p1[1]) * (p2[0] - p1[0]);
    auto fits32 = [](int64_t v) { return ((v >> 31) ^ (v >> 63)) == 0; };
    while (!fits32(nx) || !fits32(ny) || !fits32(nz)) {
        nx >>= 4;
        ny >>= 4;
        nz >>= 4;
    }
    int64_t dot = (int64_t)p1[0] * nx + (int64_t)p1[1] * ny + (int64_t)p1[3] * nz;
    bool facing = dot <= 0;
    if ((dot < 0 && !(g->attr & 0x80)) || (dot > 0 && !(g->attr & 0x40))) {
        return; // culled (dot = 0: always drawn)
    }

    ClipVertex v[10];
    for (int i = 0; i < n; i++) {
        v[i] = in[i];
    }
    // Triangles with two equal vertices are line segments
    bool line = n == 3 && (SamePosition(v[0], v[1]) || SamePosition(v[0], v[2]) || SamePosition(v[1], v[2]));

    n = ClipPolygon(v, n, (g->attr & 0x1000) != 0);
    if (n == 0) {
        return;
    }
    NtrGfxPolygonList &list = g->list;
    if (list.numPolygons >= NTRGFX_MAX_POLYGONS || list.numVertices + n > NTRGFX_MAX_VERTICES) {
        g->overflow = true;
        return;
    }

    // Screen position (GBATEK "VIEWPORT"). The hardware divides with 32 bits: W is cut to 24 bits, and above 16 bits
    // the operands are halved.
    int32_t sx[10], sy[10];
    for (int i = 0; i < n; i++) {
        v[i].pos[3] &= 0xFFFFFF;
        uint32_t w = (uint32_t)v[i].pos[3];
        uint32_t px = 0, py = 0;
        if (w != 0) {
            px = (uint32_t)v[i].pos[0] + w;
            py = (uint32_t)-v[i].pos[1] + w;
            uint32_t den = w;
            if (w > 0xFFFF) {
                px >>= 1;
                py >>= 1;
                den >>= 1;
            }
            den <<= 1;
            px = (px * (uint32_t)g->viewWidth) / den + (uint32_t)g->viewX0;
            py = (py * (uint32_t)g->viewHeight) / den + (uint32_t)g->viewY0;
        }
        sx[i] = (int32_t)(px & 0x1FF);
        sy[i] = (int32_t)(py & 0xFF);
    }

    // "1-dot" polygons (all vertices on one pixel) further than DISP_1DOT_DEPTH are hidden, unless POLYGON_ATTR bit 13
    if (!(g->attr & 0x2000)) {
        bool zeroDot = true, allBehind = true;
        for (int i = 0; i < n; i++) {
            if (sx[i] != sx[0] || sy[i] != sy[0]) {
                zeroDot = false;
                break;
            }
            if ((uint32_t)v[i].pos[3] <= g->zeroDotWLimit) {
                allBehind = false;
                break;
            }
        }
        if (zeroDot && allBehind) {
            return;
        }
    }

    NtrGfxPolygon3D &poly = list.polygons[list.numPolygons++];
    poly.attr = g->attr;
    poly.texParam = g->texParam;
    poly.texPltt = g->texPltt;
    poly.numVertices = (uint8_t)n;
    poly.wBuffer = (g->swapParam >> 1) & 1;
    poly.backFacing = !facing;
    poly.line = line;

    // W normalized so that the polygon's W values fit 16 bits (the rasterizer's interpolation); the screen position
    // above used the full W. Depth: Z/W scaled to 24 bits, or the (normalized) W for W-buffering.
    uint32_t wSize = 0;
    for (int i = 0; i < n; i++) {
        uint32_t w = (uint32_t)v[i].pos[3];
        while (wSize < 32 && (w >> wSize)) {
            wSize += 4;
        }
    }
    for (int i = 0; i < n; i++) {
        NtrGfxVertex3D &o = list.vertices[list.numVertices];
        poly.vertices[i] = (uint16_t)list.numVertices++;
        int32_t w = v[i].pos[3], wNorm, wShifted;
        if (wSize < 16) {
            wNorm = w << (16 - wSize);
            wShifted = wNorm >> (16 - wSize);
        } else {
            wNorm = w >> (wSize - 16);
            wShifted = wNorm << (wSize - 16);
        }
        int64_t z;
        if (g->swapParam & 2) {
            z = wShifted;
        } else if (w != 0) {
            z = (((int64_t)v[i].pos[2] * 0x4000) / w + 0x3FFF) * 0x200;
        } else {
            z = 0x7FFE00;
        }
        o.x = sx[i];
        o.y = sy[i];
        o.z = (int32_t)(z < 0 ? 0 : (z > 0xFFFFFF ? 0xFFFFFF : z));
        o.w = wNorm;
        o.s = v[i].s;
        o.t = v[i].t;
        // 5-bit color to 6 bits with 3 fraction bits (0 stays 0)
        for (int ch = 0; ch < 3; ch++) {
            int32_t c = v[i].color[ch] >> 12;
            o.color[ch] = (uint16_t)(c != 0 ? (c << 4) + 0xF : 0);
        }
    }
}

void Vertex(NtrGfxGeometry *g)
{
    if (g->primitive > 3) {
        return; // VTX outside BEGIN/END
    }
    Matrix clip = Clip(g);
    const int32_t *m = clip.m;
    int64_t x = g->vtx[0], y = g->vtx[1], z = g->vtx[2];
    ClipVertex v;
    for (int j = 0; j < 4; j++) {
        v.pos[j] = (int32_t)((x * m[j] + y * m[4 + j] + z * m[8 + j] + 0x1000 * (int64_t)m[12 + j]) >> 12);
    }
    for (int ch = 0; ch < 3; ch++) {
        v.color[ch] = (g->color[ch] << 12) + 0xFFF;
    }
    if ((g->texParam >> 30) == 3) {
        // Texture coordinates from the vertex: (Vx Vy Vz) * texture matrix + (S T)
        const int32_t *tm = g->texture.m;
        v.s = (int16_t)(((x * tm[0] + y * tm[4] + z * tm[8]) >> 24) + g->rawS);
        v.t = (int16_t)(((x * tm[1] + y * tm[5] + z * tm[9]) >> 24) + g->rawT);
    } else {
        v.s = g->texS;
        v.t = g->texT;
    }

    ClipVertex *s = g->strip;
    s[g->numInPoly++] = v;
    switch (g->primitive) {
    case 0: // separate triangles
        if (g->numInPoly == 3) {
            SubmitPolygon(g, s, 3);
            g->numInPoly = 0;
        }
        break;
    case 1: // separate quads
        if (g->numInPoly == 4) {
            SubmitPolygon(g, s, 4);
            g->numInPoly = 0;
        }
        break;
    case 2: // triangle strip: every second triangle has its first two vertices swapped
        if (g->numInPoly == 3) {
            if (g->stripCount & 1) {
                ClipVertex t[3] = { s[1], s[0], s[2] };
                SubmitPolygon(g, t, 3);
            } else {
                SubmitPolygon(g, s, 3);
            }
            g->stripCount++;
            s[0] = s[1];
            s[1] = s[2];
            g->numInPoly = 2;
        }
        break;
    case 3: // quad strip: vertices come in pairs, v0 v1 v3 v2 around the quad
        if (g->numInPoly == 4) {
            ClipVertex q[4] = { s[0], s[1], s[3], s[2] };
            SubmitPolygon(g, q, 4);
            g->stripCount++;
            s[0] = s[2];
            s[1] = s[3];
            g->numInPoly = 2;
        }
        break;
    }
}

// Viewport parameter (0,0 = lower left) to the top-down form used for the screen transform
void SetViewport(NtrGfxGeometry *g, uint32_t p)
{
    int32_t x1 = p & 0xFF, y1 = (p >> 8) & 0xFF, x2 = (p >> 16) & 0xFF, y2 = p >> 24;
    int32_t yBottom = (191 - y1) & 0xFF, yTop = (191 - y2) & 0xFF;
    g->viewX0 = x1;
    g->viewY0 = yTop;
    g->viewWidth = (x2 - x1 + 1) & 0x1FF;
    g->viewHeight = (yBottom - yTop + 1) & 0xFF;
}

// BOX_TEST: is any face of the box (partly) inside the view volume?
bool BoxTest(NtrGfxGeometry *g, const uint32_t *p)
{
    int32_t x0 = (int16_t)(p[0] & 0xFFFF), y0 = (int16_t)(p[0] >> 16), z0 = (int16_t)(p[1] & 0xFFFF);
    int32_t x1 = (int16_t)(x0 + (int16_t)(p[1] >> 16)), y1 = (int16_t)(y0 + (int16_t)(p[2] & 0xFFFF)), z1 = (int16_t)(z0 + (int16_t)(p[2] >> 16));
    const int32_t corners[8][3] = { { x0, y0, z0 }, { x1, y0, z0 }, { x1, y1, z0 }, { x0, y1, z0 }, { x0, y1, z1 }, { x0, y0, z1 }, { x1, y0, z1 }, { x1, y1, z1 } };
    Matrix clip = Clip(g);
    ClipVertex c[8] = {};
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            c[i].pos[j] = (int32_t)(((int64_t)corners[i][0] * clip.m[j] + (int64_t)corners[i][1] * clip.m[4 + j] + (int64_t)corners[i][2] * clip.m[8 + j] + 0x1000 * (int64_t)clip.m[12 + j]) >> 12);
        }
    }
    static const int kFaces[6][4] = { { 0, 1, 2, 3 }, { 4, 5, 6, 7 }, { 0, 3, 4, 5 }, { 1, 2, 7, 6 }, { 0, 1, 6, 5 }, { 2, 3, 4, 7 } };
    for (const auto &f : kFaces) {
        ClipVertex face[10] = { c[f[0]], c[f[1]], c[f[2]], c[f[3]] };
        if (ClipPolygon(face, 4, (g->attr & 0x1000) != 0) > 0) {
            return true;
        }
    }
    return false;
}

void Reset(NtrGfxGeometry *g)
{
    memset(g, 0, sizeof(*g));
    g->projection = g->position = g->vector = g->texture = kIdentity;
    g->primitive = 4;
    SetViewport(g, 0xBFFF0000); // full screen: 0,0 .. 255,191
    g->zeroDotWLimit = 0xFFFFFF;
}

} // namespace

NtrGfxGeometry *NtrGfx_GeometryCreate(void)
{
    NtrGfxGeometry *g = (NtrGfxGeometry *)malloc(sizeof(NtrGfxGeometry));
    Reset(g);
    return g;
}

void NtrGfx_GeometryDestroy(NtrGfxGeometry *geo)
{
    free(geo);
}

void NtrGfx_GeometrySet1DotDepth(NtrGfxGeometry *geo, uint32_t value)
{
    geo->zeroDotWLimit = (value & 0x7FFF) * 0x200 + 0x1FF;
}

void NtrGfx_GeometryCommand(NtrGfxGeometry *g, uint32_t op, const uint32_t *p)
{
    switch (op) {
    case 0x10: // MTX_MODE
        g->mtxMode = p[0] & 3;
        break;
    case 0x11: // MTX_PUSH (MTX_MODE 1 and 2: position and vector stacks)
        if (g->mtxMode == 0) {
            g->stackError |= g->projSP > 0;
            g->projStack = g->projection;
            g->projSP = (g->projSP + 1) & 1;
        } else if (g->mtxMode == 3) {
            g->stackError |= g->texSP > 0;
            g->texStack = g->texture;
            g->texSP = (g->texSP + 1) & 1;
        } else {
            g->stackError |= g->posSP > 30;
            g->posStack[g->posSP & 31] = g->position;
            g->vecStack[g->posSP & 31] = g->vector;
            g->posSP = (g->posSP + 1) & 63;
        }
        break;
    case 0x12: // MTX_POP
        if (g->mtxMode == 0) {
            g->stackError |= g->projSP == 0;
            g->projSP = (g->projSP - 1) & 1;
            g->projection = g->projStack;
        } else if (g->mtxMode == 3) {
            g->stackError |= g->texSP == 0;
            g->texSP = (g->texSP - 1) & 1;
            g->texture = g->texStack;
        } else {
            g->posSP = (g->posSP - SignExtend(p[0], 6)) & 63;
            g->stackError |= g->posSP > 30;
            g->position = g->posStack[g->posSP & 31];
            g->vector = g->vecStack[g->posSP & 31];
        }
        break;
    case 0x13: // MTX_STORE
        if (g->mtxMode == 0) {
            g->projStack = g->projection;
        } else if (g->mtxMode == 3) {
            g->texStack = g->texture;
        } else {
            uint32_t n = p[0] & 31;
            g->stackError |= n > 30;
            g->posStack[n] = g->position;
            g->vecStack[n] = g->vector;
        }
        break;
    case 0x14: // MTX_RESTORE
        if (g->mtxMode == 0) {
            g->projection = g->projStack;
        } else if (g->mtxMode == 3) {
            g->texture = g->texStack;
        } else {
            uint32_t n = p[0] & 31;
            g->stackError |= n > 30;
            g->position = g->posStack[n];
            g->vector = g->vecStack[n];
        }
        break;
    case 0x15: // MTX_IDENTITY
        ApplyToCurrent(g, [](Matrix &c) { c = kIdentity; }, false);
        break;
    case 0x16: // MTX_LOAD_4x4
    case 0x17: { // MTX_LOAD_4x3
        Matrix m;
        LoadParams(m, p, 4, op == 0x16 ? 4 : 3);
        ApplyToCurrent(g, [&](Matrix &c) { c = m; }, false);
        break;
    }
    case 0x18: // MTX_MULT_4x4
    case 0x19: { // MTX_MULT_4x3
        Matrix m;
        LoadParams(m, p, 4, op == 0x18 ? 4 : 3);
        ApplyToCurrent(g, [&](Matrix &c) { c = Multiply(m, c); }, false);
        break;
    }
    case 0x1A: { // MTX_MULT_3x3
        Matrix m;
        LoadParams(m, p, 3, 3);
        ApplyToCurrent(g, [&](Matrix &c) { Mult3x3(c, m); }, false);
        break;
    }
    case 0x1B: // MTX_SCALE
        ApplyToCurrent(g, [&](Matrix &c) { Scale(c, p); }, true);
        break;
    case 0x1C: // MTX_TRANS
        ApplyToCurrent(g, [&](Matrix &c) { Translate(c, p); }, false);
        break;
    case 0x20: // COLOR
        for (int ch = 0; ch < 3; ch++) {
            g->color[ch] = (p[0] >> (ch * 5)) & 0x1F;
        }
        break;
    case 0x21: // NORMAL
        UnpackVector(p[0], g->normal);
        Lighting(g);
        break;
    case 0x22: // TEXCOORD
        g->rawS = (int16_t)(p[0] & 0xFFFF);
        g->rawT = (int16_t)(p[0] >> 16);
        if ((g->texParam >> 30) == 1) {
            // (S T 1/16 1/16) * texture matrix
            const int32_t *m = g->texture.m;
            g->texS = (int16_t)((g->rawS * m[0] + g->rawT * m[4] + m[8] + m[12]) >> 12);
            g->texT = (int16_t)((g->rawS * m[1] + g->rawT * m[5] + m[9] + m[13]) >> 12);
        } else {
            g->texS = g->rawS;
            g->texT = g->rawT;
        }
        break;
    case 0x23: // VTX_16
        g->vtx[0] = (int16_t)(p[0] & 0xFFFF);
        g->vtx[1] = (int16_t)(p[0] >> 16);
        g->vtx[2] = (int16_t)(p[1] & 0xFFFF);
        Vertex(g);
        break;
    case 0x24: // VTX_10 (6-bit fraction)
        g->vtx[0] = (int16_t)((p[0] & 0x3FF) << 6);
        g->vtx[1] = (int16_t)(((p[0] >> 10) & 0x3FF) << 6);
        g->vtx[2] = (int16_t)(((p[0] >> 20) & 0x3FF) << 6);
        Vertex(g);
        break;
    case 0x25: // VTX_XY
        g->vtx[0] = (int16_t)(p[0] & 0xFFFF);
        g->vtx[1] = (int16_t)(p[0] >> 16);
        Vertex(g);
        break;
    case 0x26: // VTX_XZ
        g->vtx[0] = (int16_t)(p[0] & 0xFFFF);
        g->vtx[2] = (int16_t)(p[0] >> 16);
        Vertex(g);
        break;
    case 0x27: // VTX_YZ
        g->vtx[1] = (int16_t)(p[0] & 0xFFFF);
        g->vtx[2] = (int16_t)(p[0] >> 16);
        Vertex(g);
        break;
    case 0x28: // VTX_DIFF (differences in 1/8 of the 12-bit fraction's unit... i.e. raw 12-bit units)
        g->vtx[0] = (int16_t)(g->vtx[0] + SignExtend(p[0], 10));
        g->vtx[1] = (int16_t)(g->vtx[1] + SignExtend(p[0] >> 10, 10));
        g->vtx[2] = (int16_t)(g->vtx[2] + SignExtend(p[0] >> 20, 10));
        Vertex(g);
        break;
    case 0x29: // POLYGON_ATTR
        g->pendingAttr = p[0];
        break;
    case 0x2A: // TEXIMAGE_PARAM
        g->texParam = p[0];
        break;
    case 0x2B: // PLTT_BASE
        g->texPltt = p[0] & 0x1FFF;
        break;
    case 0x30: // DIF_AMB
        for (int ch = 0; ch < 3; ch++) {
            g->diffuse[ch] = (p[0] >> (ch * 5)) & 0x1F;
            g->ambient[ch] = (p[0] >> (16 + ch * 5)) & 0x1F;
        }
        if (p[0] & 0x8000) {
            for (int ch = 0; ch < 3; ch++) {
                g->color[ch] = g->diffuse[ch];
            }
        }
        break;
    case 0x31: // SPE_EMI
        for (int ch = 0; ch < 3; ch++) {
            g->specular[ch] = (p[0] >> (ch * 5)) & 0x1F;
            g->emission[ch] = (p[0] >> (16 + ch * 5)) & 0x1F;
        }
        g->useShininess = (p[0] & 0x8000) != 0;
        break;
    case 0x32: { // LIGHT_VECTOR: through the directional matrix, negated, as signed 11 bits
        int i = p[0] >> 30;
        int16_t dir[3];
        UnpackVector(p[0], dir);
        const int32_t *vm = g->vector.m;
        for (int j = 0; j < 3; j++) {
            int32_t d = dir[0] * vm[j] + dir[1] * vm[4 + j] + dir[2] * vm[8 + j];
            g->lightDir[i][j] = SignExtend((uint32_t)-(d >> 12), 11);
        }
        // Reciprocal for the specular term, from the transformed Z
        int32_t dz = dir[0] * vm[2] + dir[1] * vm[6] + dir[2] * vm[10];
        int32_t den = -((int32_t)((uint32_t)dz << 9) >> 21) + (1 << 9);
        g->specRecip[i] = den != 0 ? (1 << 18) / den : 0;
        break;
    }
    case 0x33: // LIGHT_COLOR
        for (int ch = 0; ch < 3; ch++) {
            g->lightColor[p[0] >> 30][ch] = (p[0] >> (ch * 5)) & 0x1F;
        }
        break;
    case 0x34: // SHININESS
        for (int i = 0; i < 32; i++) {
            for (int b = 0; b < 4; b++) {
                g->shininess[i * 4 + b] = (uint8_t)(p[i] >> (b * 8));
            }
        }
        break;
    case 0x40: // BEGIN_VTXS (applies POLYGON_ATTR)
        g->primitive = p[0] & 3;
        g->attr = g->pendingAttr;
        g->numInPoly = 0;
        g->stripCount = 0;
        break;
    case 0x41: // END_VTXS: no effect on the hardware
        break;
    case 0x50: // SWAP_BUFFERS: happens at the next VBlank; its bits apply to the polygons after it
        g->swapPending = true;
        g->swapParam = p[0] & 3;
        break;
    case 0x60: // VIEWPORT
        SetViewport(g, p[0]);
        break;
    case 0x70: // BOX_TEST
        g->boxResult = BoxTest(g, p);
        break;
    case 0x71: { // POS_TEST (also sets the vertex coordinates)
        g->vtx[0] = (int16_t)(p[0] & 0xFFFF);
        g->vtx[1] = (int16_t)(p[0] >> 16);
        g->vtx[2] = (int16_t)(p[1] & 0xFFFF);
        Matrix clip = Clip(g);
        for (int j = 0; j < 4; j++) {
            g->posResult[j] = (int32_t)(((int64_t)g->vtx[0] * clip.m[j] + (int64_t)g->vtx[1] * clip.m[4 + j] + (int64_t)g->vtx[2] * clip.m[8 + j] + 0x1000 * (int64_t)clip.m[12 + j]) >> 12);
        }
        break;
    }
    case 0x72: { // VEC_TEST
        int16_t v[3];
        UnpackVector(p[0], v);
        const int32_t *vm = g->vector.m;
        for (int j = 0; j < 3; j++) {
            int32_t r = (v[0] * vm[j] + v[1] * vm[4 + j] + v[2] * vm[8 + j]) >> 9;
            g->vecResult[j] = (int16_t)((r & 0x1000) ? (r | 0xF000) : r);
        }
        break;
    }
    default:
        break;
    }
}

void NtrGfx_GeometryFifo(NtrGfxGeometry *g, const uint32_t *words, uint32_t count)
{
    uint32_t i = 0;
    while (i < count) {
        uint32_t packed = words[i++];
        // Up to four commands per word; each takes its parameters from the following words
        for (int k = 0; k < 4; k++) {
            uint32_t op = (packed >> (k * 8)) & 0xFF;
            int n = ParamCount(op);
            if (n > 0) {
                if (i + n > count) {
                    return; // truncated list
                }
                NtrGfx_GeometryCommand(g, op, &words[i]);
                i += n;
            } else if (n == 0 && op != 0) {
                NtrGfx_GeometryCommand(g, op, NULL);
            }
            if ((packed >> ((k + 1) * 8)) == 0) {
                break; // no more commands in this word
            }
        }
    }
}

void NtrGfx_GeometryResults(const NtrGfxGeometry *g, NtrGfxGeometryResults *out)
{
    Matrix clip = Clip(g);
    for (int i = 0; i < 16; i++) {
        out->clipMatrix[i] = clip.m[i];
    }
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            out->vectorMatrix[row * 3 + col] = g->vector.m[row * 4 + col];
        }
    }
    for (int i = 0; i < 4; i++) {
        out->position[i] = g->posResult[i];
    }
    for (int i = 0; i < 3; i++) {
        out->vector[i] = g->vecResult[i];
    }
    out->boxInside = g->boxResult ? 1 : 0;
}

int NtrGfx_GeometryVBlank(NtrGfxGeometry *g, NtrGfxPolygonList *out)
{
    if (!g->swapPending) {
        return 0;
    }
    g->swapPending = false;
    out->numPolygons = g->list.numPolygons;
    out->numVertices = g->list.numVertices;
    out->manualSort = g->swapParam & 1;
    memcpy(out->polygons, g->list.polygons, sizeof(NtrGfxPolygon3D) * g->list.numPolygons);
    memcpy(out->vertices, g->list.vertices, sizeof(NtrGfxVertex3D) * g->list.numVertices);
    g->list.numPolygons = 0;
    g->list.numVertices = 0;
    if (g->overflow) {
        NtrGfx_WarnOnce("3D polygon/vertex RAM overflow");
        g->overflow = false;
    }
    return 1;
}
