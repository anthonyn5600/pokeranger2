#include <nitro.h>
#include <string.h>

#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "sub_02006000.hpp"
#include "sub_02007254.hpp"

CFieldMapLayerCollision::CFieldMapLayerCollision()
{
    m_cells = NULL;
    m_cellCount = 0;
    m_width = 0;
    m_height = 0;
    unk_24 = NULL;
}

CFieldMapLayerCollision::~CFieldMapLayerCollision()
{
    Release();
}

BOOL CFieldMapLayerCollision::Load(void *data)
{
    u8 *p = (u8 *)data;
    int cellSize;
    int count;
    int width;
    int height;
    s16 cell;

    memcpy(&cellSize, p, 4);
    p += 4;
    memcpy(&count, p, 4);
    p += 4;
    memcpy(&width, p, 4);
    p += 4;
    memcpy(&height, p, 4);
    p += 4;
    m_cellCount = count;
    m_width = width;
    m_height = height;
    m_cellSize = cellSize;
    m_cells = new u16[count];
    m_solidCount = 0;
    for (int i = 0; i < count; i++) {
        memcpy(&cell, p, 2);
        p += 2;
        if (cell < 0 || cell >= 66) {
            cell = 0;
        }
        if (cell != 0) {
            m_solidCount++;
        }
        m_cells[i] = cell;
    }
    return TRUE;
}

void CFieldMapLayerCollision::Release()
{
    SAFE_DELETE_ARRAY(m_cells);
    m_cellCount = 0;
    if (unk_24 != NULL) {
        for (int i = 0; i < m_solidCount; i++) {
            SAFE_DELETE(unk_24[i]);
        }
    }
    SAFE_DELETE_ARRAY(unk_24);
    SAFE_DELETE_ARRAY(unk_28);
    m_solidCount = 0;
}

int CFieldMapLayerCollision::Draw(Camera2D *camera)
{
    return 1;
}

BOOL CFieldMapLayerCollision::ToCell(fx32 x, fx32 y, FieldCellPos *out)
{
    if (out != NULL && x >= 0 && x <= (m_width * m_cellSize) << FX32_SHIFT && y >= 0
        && y <= (m_height * m_cellSize) << FX32_SHIFT) {
        out->x = (x >> FX32_SHIFT) / m_cellSize;
        out->y = (y >> FX32_SHIFT) / m_cellSize;
        return TRUE;
    }
    return FALSE;
}

int CFieldMapLayerCollision::GetCell(int index)
{
    if (index >= 0 && index < m_cellCount) {
        return m_cells[index];
    }
    return -1;
}

int CFieldMapLayerCollision::GetCellIndex(int x, int y)
{
    if (x >= 0 && x < m_width && y >= 0) {
        return y * m_width + x;
    }
    return -1;
}

int CFieldMapLayerCollision::GetCellAt(int x, int y)
{
    return GetCell(GetCellIndex(x, y));
}

int CFieldMapLayerCollision::GetCellAtPos(fx32 x, fx32 y)
{
    FieldCellPos pos;
    if (!ToCell(x, y, &pos)) {
        return -1;
    }
    return GetCellAt(pos.x, pos.y);
}

int CFieldMapLayerCollision::GetLeftEdge(int index, PointPair2D *out)
{
    if (index < 0 || m_cellCount <= index) {
        return -1;
    }
    fx32 x = (m_cellSize * (index % m_width)) << FX32_SHIFT;
    fx32 y = (m_cellSize * (index / m_width)) << FX32_SHIFT;
    switch (m_cells[index]) {
    case -1:
    case 1:
    case 2:
    case 3:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 12:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 23:
    case 24:
    case 26:
    case 27:
    case 28:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 37:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 48:
    case 49:
    case 63:
        out->p1.x = x;
        out->p1.y = y;
        out->p2.x = x;
        out->p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 4:
    case 13:
    case 25:
    case 29:
    case 38:
    case 50:
        out->p1.x = x;
        out->p1.y = y;
        out->p2.x = x + (m_cellSize << FX32_SHIFT);
        out->p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 5:
    case 11:
    case 22:
    case 30:
    case 36:
    case 47:
        out->p1.x = x + (m_cellSize << FX32_SHIFT);
        out->p1.y = y;
        out->p2.x = x;
        out->p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    }
    return 0;
}

int CFieldMapLayerCollision::GetRightEdge(int index, PointPair2D *out)
{
    if (index < 0 || m_cellCount <= index) {
        return -1;
    }
    fx32 x = (m_cellSize * (index % m_width)) << FX32_SHIFT;
    fx32 y = (m_cellSize * (index / m_width)) << FX32_SHIFT;
    switch (m_cells[index]) {
    case -1:
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 11:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 25:
    case 26:
    case 29:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 36:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 50:
    case 63:
        out->p1.x = x + (m_cellSize << FX32_SHIFT);
        out->p1.y = y + (m_cellSize << FX32_SHIFT);
        out->p2.x = x + (m_cellSize << FX32_SHIFT);
        out->p2.y = y;
        return 1;
    case 3:
    case 12:
    case 24:
    case 28:
    case 37:
    case 49:
        out->p1.x = x;
        out->p1.y = y + (m_cellSize << FX32_SHIFT);
        out->p2.x = x + (m_cellSize << FX32_SHIFT);
        out->p2.y = y;
        return 1;
    case 2:
    case 10:
    case 23:
    case 27:
    case 35:
    case 48:
        out->p1.x = x + (m_cellSize << FX32_SHIFT);
        out->p1.y = y + (m_cellSize << FX32_SHIFT);
        out->p2.x = x;
        out->p2.y = y;
        return 1;
    }
    return 0;
}

int CFieldMapLayerCollision::GetTopEdge(int index, PointPair2D *out)
{
    if (index < 0 || m_cellCount <= index) {
        return -1;
    }
    fx32 x = (m_cellSize * (index % m_width)) << FX32_SHIFT;
    fx32 y = (m_cellSize * (index / m_width)) << FX32_SHIFT;
    switch (m_cells[index]) {
    case -1:
    case 1:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
    case 9:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 24:
    case 25:
    case 26:
    case 28:
    case 29:
    case 31:
    case 32:
    case 33:
    case 34:
    case 37:
    case 38:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 49:
    case 50:
    case 63:
        out->p1.x = x + (m_cellSize << FX32_SHIFT);
        out->p1.y = y;
        out->p2.x = x;
        out->p2.y = y;
        return 1;
    case 2:
    case 10:
    case 23:
    case 27:
    case 35:
    case 48:
        out->p1.x = x + (m_cellSize << FX32_SHIFT);
        out->p1.y = y + (m_cellSize << FX32_SHIFT);
        out->p2.x = x;
        out->p2.y = y;
        return 1;
    case 5:
    case 11:
    case 22:
    case 30:
    case 36:
    case 47:
        out->p1.x = x;
        out->p1.y = y + (m_cellSize << FX32_SHIFT);
        out->p2.x = x + (m_cellSize << FX32_SHIFT);
        out->p2.y = y;
        return 1;
    }
    return 0;
}

int CFieldMapLayerCollision::GetBottomEdge(int index, PointPair2D *out)
{
    if (index < 0 || m_cellCount <= index) {
        return -1;
    }
    fx32 x = (m_cellSize * (index % m_width)) << FX32_SHIFT;
    fx32 y = (m_cellSize * (index / m_width)) << FX32_SHIFT;
    switch (m_cells[index]) {
    case -1:
    case 1:
    case 2:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 26:
    case 27:
    case 30:
    case 31:
    case 32:
    case 33:
    case 34:
    case 35:
    case 36:
    case 39:
    case 40:
    case 41:
    case 42:
    case 43:
    case 44:
    case 45:
    case 46:
    case 47:
    case 48:
    case 63:
        out->p1.x = x;
        out->p1.y = y + (m_cellSize << FX32_SHIFT);
        out->p2.x = x + (m_cellSize << FX32_SHIFT);
        out->p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 3:
    case 12:
    case 24:
    case 28:
    case 37:
    case 49:
        out->p1.x = x;
        out->p1.y = y + (m_cellSize << FX32_SHIFT);
        out->p2.x = x + (m_cellSize << FX32_SHIFT);
        out->p2.y = y;
        return 1;
    case 4:
    case 13:
    case 25:
    case 29:
    case 38:
    case 50:
        out->p1.x = x;
        out->p1.y = y;
        out->p2.x = x + (m_cellSize << FX32_SHIFT);
        out->p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    }
    return 0;
}

BOOL CFieldMapLayerCollision::Sweep(PointPair2D *move, fx32 radius, Point2D *out, u32 kinds)
{
    fx32 dx;
    fx32 dy;
    fx32 len;
    fx32 step;
    int i;
    fx32 maxStep;
    Point2D delta;
    PointPair2D seg;
    fx32 t;
    fx64 f;

    dx = move->p2.x - move->p1.x;
    if (dx < 0) {
        dx = -dx;
    }
    dy = move->p2.y - move->p1.y;
    if (dy < 0) {
        dy = -dy;
    }
    len = sub_02007254(dx, dy);
    step = 0;
    for (i = 0; i < 4; i++) {
        step += radius >> (i + 1);
    }
    maxStep = (m_cellSize / 4) << FX32_SHIFT;
    if (step >= maxStep) {
        step = maxStep;
    }
    if (len <= step) {
        return Collide(move, radius, out, kinds);
    }
    delta = move->p2 - move->p1;
    seg.p1 = move->p1;
    if (len > 0) {
        t = 0;
        do {
            t += step;
            if (t < len) {
                // Assigning t first stops mwcc from strength-reducing (fx64)t << 12 into a 64-bit induction
                // variable; the original recomputes it in every iteration.
                f = t;
                f = FX32_DIV(f, len);
                seg.p2 = move->p1 + delta * f;
            } else {
                seg.p2 = move->p2;
            }
            if (Collide(&seg, radius, out, kinds)) {
                return TRUE;
            }
            seg.p1 = seg.p2;
        } while (t < len);
    }
    return FALSE;
}

// Whether a cell type blocks movement for the given mask (1: kind A, 2: kind B, 4: kind C).
static inline BOOL IsBlocking(int type, u32 kinds)
{
    BOOL blocking = FALSE;
    if (kinds & 1) {
        blocking |= CFieldMapLayerCollision::IsKindA(type);
    }
    if (kinds & 2) {
        blocking |= CFieldMapLayerCollision::IsKindB(type);
    }
    if (kinds & 4) {
        blocking |= CFieldMapLayerCollision::IsKindC(type);
    }
    return blocking;
}

// Pushes the circle out of `edge` if they overlap. Written out at each use in the original: the hit point
// and the returned position get their own stack slots per use.
#define PUSH_OUT()                                  \
    {                                               \
        Point2D h;                                  \
        if (sub_02006764(edge, circle, &h, 4)) {    \
            circle.pos = sub_0200732C(&circle, &h); \
            hit = TRUE;                             \
        }                                           \
    }

BOOL CFieldMapLayerCollision::Collide(PointPair2D *move, fx32 radius, Point2D *out, u32 kinds)
{
    PointPair2D edge;
    BOOL hit = FALSE;
    FieldCellPos cell;
    ToCell(move->p1.x, move->p1.y, &cell);
    int index = GetCellIndex(cell.x, cell.y);
    Circle circle = { move->p2, radius };
    u8 dirs = 0;
    PointPair2D mv = *move;
    int type = GetCell(index);
    int n;
    if (IsBlocking(type, kinds)) {
        if (((mv.p1.x >> FX32_SHIFT) & (m_cellSize - 1)) > m_cellSize / 2 && mv.p2.x < mv.p1.x) {
            dirs |= 1;
        } else if (((mv.p1.x >> FX32_SHIFT) & (m_cellSize - 1)) < m_cellSize / 2 && mv.p2.x > mv.p1.x) {
            dirs |= 2;
        }
        fx32 y = mv.p1.y;
        if (((y >> FX32_SHIFT) & (m_cellSize - 1)) > m_cellSize / 2 && mv.p2.y < y) {
            dirs |= 4;
        }
        if (((y >> FX32_SHIFT) & (m_cellSize - 1)) < m_cellSize / 2 && mv.p2.y > y) {
            dirs |= 8;
        }
        if ((dirs & 1) && GetRightEdge(index, &edge) > 0) {
            PUSH_OUT();
        }
        if ((dirs & 2) && GetLeftEdge(index, &edge) > 0) {
            PUSH_OUT();
        }
        if ((dirs & 4) && GetBottomEdge(index, &edge) > 0) {
            PUSH_OUT();
        }
        if ((dirs & 8) && GetTopEdge(index, &edge) > 0) {
            PUSH_OUT();
        }
        if (hit) {
            mv.p2 = circle.pos;
        }
    }
    dirs = 0;
    if (mv.p2.x < mv.p1.x) {
        dirs |= 0x31;
    } else if (mv.p2.x > mv.p1.x) {
        dirs |= 0xC2;
    }
    if (mv.p2.y < mv.p1.y) {
        dirs |= 0x54;
    }
    if (mv.p2.y > mv.p1.y) {
        dirs |= 0xA8;
    }
    if (!(dirs & 0xC)) {
        dirs |= 0xC;
    }
    if (!(dirs & 3)) {
        dirs |= 3;
    }
    if (dirs & 1) {
        n = GetCellIndex(cell.x + (-1), cell.y + (0));
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            if (GetRightEdge(n, &edge) > 0) {
                PUSH_OUT();
            }
        }
    }
    if (dirs & 2) {
        n = GetCellIndex(cell.x + (1), cell.y + (0));
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            if (GetLeftEdge(n, &edge) > 0) {
                PUSH_OUT();
            }
        }
    }
    if (dirs & 4) {
        n = GetCellIndex(cell.x + (0), cell.y + (-1));
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            if (GetBottomEdge(n, &edge) > 0) {
                PUSH_OUT();
            }
        }
    }
    if (dirs & 8) {
        n = GetCellIndex(cell.x + (0), cell.y + (1));
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            if (GetTopEdge(n, &edge) > 0) {
                PUSH_OUT();
            }
        }
    }
    if (dirs & 0x10) {
        n = GetCellIndex(cell.x + (-1), cell.y + (-1));
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            if (GetRightEdge(n, &edge) > 0) {
                PUSH_OUT();
            }
            if (GetBottomEdge(n, &edge) > 0) {
                PUSH_OUT();
            }
        }
    }
    if (dirs & 0x20) {
        n = GetCellIndex(cell.x + (-1), cell.y + (1));
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            if (GetRightEdge(n, &edge) > 0) {
                PUSH_OUT();
            }
            if (GetTopEdge(n, &edge) > 0) {
                PUSH_OUT();
            }
        }
    }
    if (dirs & 0x40) {
        n = GetCellIndex(cell.x + (1), cell.y + (-1));
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            if (GetLeftEdge(n, &edge) > 0) {
                PUSH_OUT();
            }
            if (GetBottomEdge(n, &edge) > 0) {
                PUSH_OUT();
            }
        }
    }
    if (dirs & 0x80) {
        n = GetCellIndex(cell.x + (1), cell.y + (1));
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            if (GetLeftEdge(n, &edge) > 0) {
                PUSH_OUT();
            }
            if (GetTopEdge(n, &edge) > 0) {
                PUSH_OUT();
            }
        }
    }
    if (hit) {
        *out = circle.pos;
    }
    return hit;
}

int CFieldMapLayerCollision::GetLeftEdges(int index, PointPair2D *out)
{
    if (index < 0 || m_cellCount <= index) {
        return -1;
    }
    fx32 x = (m_cellSize * (index % m_width)) << FX32_SHIFT;
    fx32 y = (m_cellSize * (index / m_width)) << FX32_SHIFT;
    switch (m_cells[index]) {
    case -1:
    case 1:
    case 2:
    case 3:
    case 6:
    case 10:
    case 12:
    case 14:
    case 15:
    case 19:
    case 20:
    case 26:
    case 27:
    case 28:
    case 31:
    case 35:
    case 37:
    case 39:
    case 40:
    case 44:
    case 45:
    case 63:
        out[0].p1.x = x;
        out[0].p1.y = y;
        out[0].p2.x = x;
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 4:
    case 29:
        out[0].p1.x = x;
        out[0].p1.y = y;
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 5:
    case 30:
        out[0].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p1.y = y;
        out[0].p2.x = x;
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 7:
    case 32:
        out[0].p1.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p1.y = y;
        out[0].p2.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 8:
    case 24:
    case 33:
    case 49:
        out[0].p1.x = x;
        out[0].p1.y = y;
        out[0].p2.x = x;
        out[0].p2.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        return 1;
    case 9:
    case 23:
    case 34:
    case 48:
        out[0].p1.x = x;
        out[0].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.x = x;
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 16:
    case 41:
        out[0].p1.x = x;
        out[0].p1.y = y;
        out[0].p2.x = x;
        out[0].p2.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[1].p1.x = x;
        out[1].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[1].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[1].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 2;
    case 17:
    case 42:
        out[0].p1.x = x;
        out[0].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.x = x;
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        out[1].p1.x = x;
        out[1].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[1].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[1].p2.y = y;
        return 2;
    case 18:
    case 43:
        out[0].p1.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p1.y = y;
        out[0].p2.x = x;
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 21:
    case 46:
        out[0].p1.x = x;
        out[0].p1.y = y;
        out[0].p2.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 13:
    case 38:
        out[0].p1.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p1.y = y;
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 25:
    case 50:
        out[0].p1.x = x;
        out[0].p1.y = y;
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        return 1;
    case 11:
    case 36:
        out[0].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p1.y = y;
        out[0].p2.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 22:
    case 47:
        out[0].p1.x = x;
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        return 1;
    }
    return 0;
}

int CFieldMapLayerCollision::GetRightEdges(int index, PointPair2D *out)
{
    if (index < 0 || m_cellCount <= index) {
        return -1;
    }
    fx32 x = (m_cellSize * (index % m_width)) << FX32_SHIFT;
    fx32 y = (m_cellSize * (index / m_width)) << FX32_SHIFT;
    switch (m_cells[index]) {
    case -1:
    case 1:
    case 4:
    case 5:
    case 7:
    case 11:
    case 13:
    case 16:
    case 17:
    case 18:
    case 21:
    case 26:
    case 29:
    case 30:
    case 32:
    case 36:
    case 38:
    case 41:
    case 42:
    case 43:
    case 46:
    case 63:
        out[0].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y;
        return 1;
    case 3:
    case 28:
        out[0].p1.x = x;
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y;
        return 1;
    case 2:
    case 27:
        out[0].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x;
        out[0].p2.y = y;
        return 1;
    case 6:
    case 31:
        out[0].p1.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.y = y;
        return 1;
    case 8:
    case 25:
    case 33:
    case 50:
        out[0].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p1.y = y;
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        return 1;
    case 9:
    case 22:
    case 34:
    case 47:
        out[0].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 15:
    case 40:
        out[0].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p1.y = y;
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[1].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[1].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[1].p2.x = x;
        out[1].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 2;
    case 14:
    case 39:
        out[0].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        out[1].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[1].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[1].p2.x = x;
        out[1].p2.y = y;
        return 2;
    case 19:
    case 44:
        out[0].p1.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p1.y = y;
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 20:
    case 45:
        out[0].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p1.y = y;
        out[0].p2.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 12:
    case 37:
        out[0].p1.x = x;
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.y = y;
        return 1;
    case 24:
    case 49:
        out[0].p1.x = x;
        out[0].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y;
        return 1;
    case 10:
    case 35:
        out[0].p1.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x;
        out[0].p2.y = y;
        return 1;
    case 23:
    case 48:
        out[0].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x;
        out[0].p2.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        return 1;
    }
    return 0;
}

int CFieldMapLayerCollision::GetTopEdges(int index, PointPair2D *out)
{
    if (index < 0 || m_cellCount <= index) {
        return -1;
    }
    fx32 x = (m_cellSize * (index % m_width)) << FX32_SHIFT;
    fx32 y = (m_cellSize * (index / m_width)) << FX32_SHIFT;
    switch (m_cells[index]) {
    case -1:
    case 1:
    case 3:
    case 4:
    case 8:
    case 15:
    case 16:
    case 20:
    case 21:
    case 24:
    case 25:
    case 26:
    case 28:
    case 29:
    case 33:
    case 40:
    case 41:
    case 45:
    case 46:
    case 49:
    case 50:
    case 63:
        out[0].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p1.y = y;
        out[0].p2.x = x;
        out[0].p2.y = y;
        return 1;
    case 2:
    case 27:
        out[0].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x;
        out[0].p2.y = y;
        return 1;
    case 5:
    case 30:
        out[0].p1.x = x;
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y;
        return 1;
    case 9:
    case 34:
        out[0].p1.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.x = x;
        out[0].p2.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        return 1;
    case 6:
    case 12:
    case 31:
    case 37:
        out[0].p1.x = x;
        out[0].p1.y = y;
        out[0].p2.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.y = y;
        return 1;
    case 7:
    case 13:
    case 32:
    case 38:
        out[0].p1.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p1.y = y;
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y;
        return 1;
    case 14:
    case 39:
        out[0].p1.x = x;
        out[0].p1.y = y;
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        return 1;
    case 17:
    case 42:
        out[0].p1.x = x;
        out[0].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y;
        return 1;
    case 18:
    case 43:
        out[0].p1.x = x;
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.y = y;
        out[1].p1.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[1].p1.y = y;
        out[1].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[1].p2.y = y;
        return 2;
    case 19:
    case 44:
        out[0].p1.x = x;
        out[0].p1.y = y;
        out[0].p2.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.y = y;
        out[1].p1.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[1].p1.y = y;
        out[1].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[1].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 2;
    case 10:
    case 35:
        out[0].p1.x = x;
        out[0].p1.y = y;
        out[0].p2.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 23:
    case 48:
        out[0].p1.x = x;
        out[0].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 11:
    case 36:
        out[0].p1.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y;
        return 1;
    case 22:
    case 47:
        out[0].p1.x = x;
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        return 1;
    }
    return 0;
}

int CFieldMapLayerCollision::GetBottomEdges(int index, PointPair2D *out)
{
    if (index < 0 || m_cellCount <= index) {
        return -1;
    }
    fx32 x = (m_cellSize * (index % m_width)) << FX32_SHIFT;
    fx32 y = (m_cellSize * (index / m_width)) << FX32_SHIFT;
    switch (m_cells[index]) {
    case -1:
    case 1:
    case 2:
    case 5:
    case 9:
    case 14:
    case 17:
    case 18:
    case 19:
    case 22:
    case 23:
    case 26:
    case 27:
    case 30:
    case 34:
    case 39:
    case 42:
    case 43:
    case 44:
    case 47:
    case 48:
    case 63:
        out[0].p1.x = x;
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 3:
    case 28:
        out[0].p1.x = x;
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y;
        return 1;
    case 4:
    case 29:
        out[0].p1.x = x;
        out[0].p1.y = y;
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 8:
    case 33:
        out[0].p1.x = x;
        out[0].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        return 1;
    case 6:
    case 10:
    case 31:
    case 35:
        out[0].p1.x = x;
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 7:
    case 11:
    case 32:
    case 36:
        out[0].p1.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 15:
    case 40:
        out[0].p1.x = x;
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        return 1;
    case 16:
    case 41:
        out[0].p1.x = x;
        out[0].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 20:
    case 45:
        out[0].p1.x = x;
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        out[1].p1.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[1].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[1].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[1].p2.y = y;
        return 2;
    case 21:
    case 46:
        out[0].p1.x = x;
        out[0].p1.y = y;
        out[0].p2.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        out[1].p1.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[1].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[1].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[1].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 2;
    case 12:
    case 37:
        out[0].p1.x = x;
        out[0].p1.y = y + (m_cellSize << FX32_SHIFT);
        out[0].p2.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.y = y;
        return 1;
    case 24:
    case 49:
        out[0].p1.x = x;
        out[0].p1.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y;
        return 1;
    case 13:
    case 38:
        out[0].p1.x = x + ((m_cellSize / 2) << FX32_SHIFT);
        out[0].p1.y = y;
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + (m_cellSize << FX32_SHIFT);
        return 1;
    case 25:
    case 50:
        out[0].p1.x = x;
        out[0].p1.y = y;
        out[0].p2.x = x + (m_cellSize << FX32_SHIFT);
        out[0].p2.y = y + ((m_cellSize / 2) << FX32_SHIFT);
        return 1;
    }
    return 0;
}

BOOL CFieldMapLayerCollision::SweepFine(PointPair2D *move, fx32 radius, Point2D *out, u32 kinds)
{
    fx32 dx;
    fx32 dy;
    fx32 len;
    fx32 step;
    int i;
    fx32 maxStep;
    Point2D delta;
    PointPair2D seg;
    fx32 t;
    fx64 f;

    dx = move->p2.x - move->p1.x;
    if (dx < 0) {
        dx = -dx;
    }
    dy = move->p2.y - move->p1.y;
    if (dy < 0) {
        dy = -dy;
    }
    len = sub_02007254(dx, dy);
    step = 0;
    for (i = 0; i < 4; i++) {
        step += radius >> (i + 1);
    }
    maxStep = (m_cellSize / 4) << FX32_SHIFT;
    if (step >= maxStep) {
        step = maxStep;
    }
    if (len <= step) {
        return CollideFine(move, radius, out, kinds);
    }
    delta = move->p2 - move->p1;
    seg.p1 = move->p1;
    if (len > 0) {
        t = 0;
        do {
            t += step;
            if (t < len) {
                // Assigning t first stops mwcc from strength-reducing (fx64)t << 12 into a 64-bit induction
                // variable; the original recomputes it in every iteration.
                f = t;
                f = FX32_DIV(f, len);
                seg.p2 = move->p1 + delta * f;
            } else {
                seg.p2 = move->p2;
            }
            if (CollideFine(&seg, radius, out, kinds)) {
                return TRUE;
            }
            seg.p1 = seg.p2;
        } while (t < len);
    }
    return FALSE;
}

// Pushes the circle out of each segment of an edge list it overlaps.
#define PUSH_OUT_EDGES(count)                            \
    {                                                    \
        Point2D h;                                       \
        for (int i = 0; i < (count); i++) {              \
            if (sub_02006764(edges[i], circle, &h, 4)) { \
                circle.pos = sub_0200732C(&circle, &h);  \
                hit = TRUE;                              \
            }                                            \
        }                                                \
    }

// Same, but a hit on a segment's end is retested against the segment stretched past both ends.
// seg.p1 is read as const so mwcc doesn't forward the copied values into the subtraction.
#define PUSH_OUT_EDGES_EXTENDED(count)                                   \
    {                                                                    \
        Point2D h;                                                       \
        for (int i = 0; i < (count); i++) {                              \
            if (sub_02006764(edges[i], circle, &h, 4)) {                 \
                if ((h.x == edges[i].p1.x && h.y == edges[i].p1.y)       \
                    || (h.x == edges[i].p2.x && h.y == edges[i].p2.y)) { \
                    PointPair2D seg = edges[i];                          \
                    Point2D d = (const Point2D &)seg.p1 - seg.p2;        \
                    d *= FX32_CONST(4);                                  \
                    seg.p1 += d;                                         \
                    seg.p2 -= d;                                         \
                    sub_02006764(seg, circle, &h, 4);                    \
                }                                                        \
                circle.pos = sub_0200732C(&circle, &h);                  \
                hit = TRUE;                                              \
            }                                                            \
        }                                                                \
    }

BOOL CFieldMapLayerCollision::CollideFine(PointPair2D *move, fx32 radius, Point2D *out, u32 kinds)
{
    PointPair2D edges[2];
    BOOL hit = FALSE;
    FieldCellPos cell;
    ToCell(move->p1.x, move->p1.y, &cell);
    int index = GetCellIndex(cell.x, cell.y);
    Circle circle = { move->p2, radius };
    u8 dirs = 0;
    PointPair2D mv = *move;
    int type = GetCell(index);
    int n;
    int count;
    fx32 y;
    if (IsBlocking(type, kinds)) {
        if (((mv.p1.x >> FX32_SHIFT) & (m_cellSize - 1)) > m_cellSize / 2 && mv.p2.x < mv.p1.x) {
            dirs |= 1;
        } else if (((mv.p1.x >> FX32_SHIFT) & (m_cellSize - 1)) < m_cellSize / 2 && mv.p2.x > mv.p1.x) {
            dirs |= 2;
        }
        y = mv.p1.y;
        if (((y >> FX32_SHIFT) & (m_cellSize - 1)) > m_cellSize / 2 && mv.p2.y < y) {
            dirs |= 4;
        }
        if (((y >> FX32_SHIFT) & (m_cellSize - 1)) < m_cellSize / 2 && mv.p2.y > y) {
            dirs |= 8;
        }
        if (dirs & 1) {
            int count = GetRightEdges(index, edges);
            PUSH_OUT_EDGES_EXTENDED(count);
        }
        if (dirs & 2) {
            int count = GetLeftEdges(index, edges);
            PUSH_OUT_EDGES_EXTENDED(count);
        }
        if (dirs & 4) {
            int count = GetBottomEdges(index, edges);
            PUSH_OUT_EDGES_EXTENDED(count);
        }
        if (dirs & 8) {
            int count = GetTopEdges(index, edges);
            PUSH_OUT_EDGES_EXTENDED(count);
        }
        if (hit) {
            fx32 moveLen = sub_02007254(mv.p2.x - mv.p1.x, mv.p2.y - y);
            Point2D d = circle.pos - mv.p1;
            fx32 pushLen = sub_02007254(d.x, d.y);
            if (pushLen > moveLen) {
                d *= moveLen;
                d /= pushLen;
                circle.pos = mv.p1 + d;
            }
            mv.p2 = circle.pos;
        }
    }
    dirs = 0;
    if (mv.p2.x < mv.p1.x) {
        dirs |= 0x31;
    } else if (mv.p2.x > mv.p1.x) {
        dirs |= 0xC2;
    }
    if (mv.p2.y < mv.p1.y) {
        dirs |= 0x54;
    }
    if (mv.p2.y > mv.p1.y) {
        dirs |= 0xA8;
    }
    if (!(dirs & 0xC)) {
        dirs |= 0xC;
    }
    if (!(dirs & 3)) {
        dirs |= 3;
    }
    if (dirs & 1) {
        n = GetCellIndex(cell.x - 1, cell.y);
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            int count = GetRightEdges(n, edges);
            PUSH_OUT_EDGES(count);
        }
    }
    if (dirs & 2) {
        n = GetCellIndex(cell.x + 1, cell.y);
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            int count = GetLeftEdges(n, edges);
            PUSH_OUT_EDGES(count);
        }
    }
    if (dirs & 4) {
        n = GetCellIndex(cell.x, cell.y - 1);
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            int count = GetBottomEdges(n, edges);
            PUSH_OUT_EDGES(count);
        }
    }
    if (dirs & 8) {
        n = GetCellIndex(cell.x, cell.y + 1);
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            int count = GetTopEdges(n, edges);
            PUSH_OUT_EDGES(count);
        }
    }
    if (dirs & 0x10) {
        n = GetCellIndex(cell.x - 1, cell.y - 1);
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            int count = GetRightEdges(n, edges);
            PUSH_OUT_EDGES(count);
            count = GetBottomEdges(n, edges);
            PUSH_OUT_EDGES(count);
        }
    }
    if (dirs & 0x20) {
        n = GetCellIndex(cell.x - 1, cell.y + 1);
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            int count = GetRightEdges(n, edges);
            PUSH_OUT_EDGES(count);
            count = GetTopEdges(n, edges);
            PUSH_OUT_EDGES(count);
        }
    }
    if (dirs & 0x40) {
        n = GetCellIndex(cell.x + 1, cell.y - 1);
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            int count = GetLeftEdges(n, edges);
            PUSH_OUT_EDGES(count);
            count = GetBottomEdges(n, edges);
            PUSH_OUT_EDGES(count);
        }
    }
    if (dirs & 0x80) {
        n = GetCellIndex(cell.x + 1, cell.y + 1);
        type = GetCell(n);
        if (IsBlocking(type, kinds)) {
            int count = GetLeftEdges(n, edges);
            PUSH_OUT_EDGES(count);
            count = GetTopEdges(n, edges);
            PUSH_OUT_EDGES(count);
        }
    }
    if (hit) {
        *out = circle.pos;
    }
    return hit;
}

BOOL CFieldMapLayerCollision::IsKindA(int type)
{
    if (type >= 1 && type <= 25) {
        return TRUE;
    }
    return FALSE;
}

BOOL CFieldMapLayerCollision::IsKindB(int type)
{
    if (type >= 26 && type <= 50) {
        return TRUE;
    }
    return FALSE;
}

BOOL CFieldMapLayerCollision::IsWall(int type)
{
    if (type >= 1 && type <= 50) {
        return TRUE;
    }
    return FALSE;
}

BOOL CFieldMapLayerCollision::IsKindC(int type)
{
    return type == 63;
}

BOOL CFieldMapLayerCollision::IsCircleBlocked(Point2D pos, fx32 radius, u32 kinds)
{
    // `i` is reused as the row counter: mwcc then gives the counter its own late register node, which the
    // original's register choice needs. cell.y is read as an int for ToCell so mwcc doesn't forward the
    // value stored above (the original loads it).
    Point2D cell = pos;
    fx32 left = cell.x -= radius;
    cell.y -= radius;
    if (left < 0 || pos.x + radius > (m_width * m_cellSize) << FX32_SHIFT || cell.y < 0
        || pos.y + radius > (m_height * m_cellSize) << FX32_SHIFT) {
        return TRUE;
    }
    int i = ((left + radius * 2) >> FX32_SHIFT) / m_cellSize;
    int cols = i - (left >> FX32_SHIFT) / m_cellSize + 1;
    i = ((cell.y + radius * 2) >> FX32_SHIFT) / m_cellSize;
    int rows = i - (cell.y >> FX32_SHIFT) / m_cellSize + 1;
    ToCell(cell.x, ((FieldCellPos *)&cell)->y, (FieldCellPos *)&cell);
    for (i = 0; i < rows; i++) {
        for (int x = 0; x < cols; x++) {
            int type = GetCellAt(cell.x + x, cell.y + i);
            if (IsBlocking(type, kinds)) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

BOOL CFieldMapLayerCollision::IsCircleBlockedFine(Point2D pos, fx32 radius, u32 kinds)
{
    // The 12-byte memcpy is the original's block copy of the circle; ToCell's arguments are read as ints for
    // the same reason as in IsCircleBlocked.
    Circle circle;
    Point2D poly[4];
    Circle init = { pos, radius };
    memcpy(&circle, &init, sizeof(Circle));
    Point2D cell = pos;
    cell.x -= radius;
    cell.y -= radius;
    if (cell.x < 0 || pos.x + radius > (m_width * m_cellSize) << FX32_SHIFT || cell.y < 0
        || pos.y + radius > (m_height * m_cellSize) << FX32_SHIFT) {
        return TRUE;
    }
    int i = ((cell.x + radius * 2) >> FX32_SHIFT) / m_cellSize;
    int cols = i - (cell.x >> FX32_SHIFT) / m_cellSize + 1;
    i = ((cell.y + radius * 2) >> FX32_SHIFT) / m_cellSize;
    int rows = i - (cell.y >> FX32_SHIFT) / m_cellSize + 1;
    ToCell(((FieldCellPos *)&cell)->x, ((FieldCellPos *)&cell)->y, (FieldCellPos *)&cell);
    for (int y = 0; y < rows; y++) {
        for (int x = 0; x < cols; x++) {
            int type = GetCellAt(cell.x + x, cell.y + y);
            if (IsBlocking(type, kinds)) {
                fx32 px = (m_cellSize * (cell.x + x)) << FX32_SHIFT;
                fx32 py = (m_cellSize * (cell.y + y)) << FX32_SHIFT;
                int count = 0;
                switch (type) {
                case -1:
                case 1:
                case 26:
                case 63:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px;
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py + (m_cellSize << FX32_SHIFT);
                    poly[3].x = px + (m_cellSize << FX32_SHIFT);
                    poly[3].y = py;
                    count = 4;
                    break;
                case 2:
                case 27:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px;
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py + (m_cellSize << FX32_SHIFT);
                    count = 3;
                    break;
                case 5:
                case 30:
                    poly[0].x = px;
                    poly[0].y = py + (m_cellSize << FX32_SHIFT);
                    poly[1].x = px + (m_cellSize << FX32_SHIFT);
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py;
                    count = 3;
                    break;
                case 9:
                case 34:
                    poly[0].x = px;
                    poly[0].y = py + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[1].x = px;
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py + (m_cellSize << FX32_SHIFT);
                    poly[3].x = px + (m_cellSize << FX32_SHIFT);
                    poly[3].y = py + ((m_cellSize / 2) << FX32_SHIFT);
                    count = 4;
                    break;
                case 14:
                case 39:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px;
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py + (m_cellSize << FX32_SHIFT);
                    poly[3].x = px + (m_cellSize << FX32_SHIFT);
                    poly[3].y = py + ((m_cellSize / 2) << FX32_SHIFT);
                    count = 4;
                    break;
                case 17:
                case 42:
                    poly[0].x = px;
                    poly[0].y = py + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[1].x = px;
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py + (m_cellSize << FX32_SHIFT);
                    poly[3].x = px + (m_cellSize << FX32_SHIFT);
                    poly[3].y = py;
                    count = 4;
                    break;
                case 18:
                case 43:
                    poly[0].x = px + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[0].y = py;
                    poly[1].x = px;
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py + (m_cellSize << FX32_SHIFT);
                    poly[3].x = px + (m_cellSize << FX32_SHIFT);
                    poly[3].y = py;
                    count = 4;
                    break;
                case 19:
                case 44:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px;
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py + (m_cellSize << FX32_SHIFT);
                    poly[3].x = px + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[3].y = py;
                    count = 4;
                    break;
                case 23:
                case 48:
                    poly[0].x = px;
                    poly[0].y = py + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[1].x = px;
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py + (m_cellSize << FX32_SHIFT);
                    count = 3;
                    break;
                case 22:
                case 47:
                    poly[0].x = px;
                    poly[0].y = py + (m_cellSize << FX32_SHIFT);
                    poly[1].x = px + (m_cellSize << FX32_SHIFT);
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py + ((m_cellSize / 2) << FX32_SHIFT);
                    count = 3;
                    break;
                case 3:
                case 28:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px;
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py;
                    count = 3;
                    break;
                case 4:
                case 29:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px + (m_cellSize << FX32_SHIFT);
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py;
                    count = 3;
                    break;
                case 8:
                case 33:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px;
                    poly[1].y = py + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[3].x = px + (m_cellSize << FX32_SHIFT);
                    poly[3].y = py;
                    count = 4;
                    break;
                case 6:
                case 31:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px;
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[2].y = py + (m_cellSize << FX32_SHIFT);
                    poly[3].x = px + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[3].y = py;
                    count = 4;
                    break;
                case 10:
                case 35:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px;
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[2].y = py + (m_cellSize << FX32_SHIFT);
                    count = 3;
                    break;
                case 7:
                case 32:
                    poly[0].x = px + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[0].y = py;
                    poly[1].x = px + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py + (m_cellSize << FX32_SHIFT);
                    poly[3].x = px + (m_cellSize << FX32_SHIFT);
                    poly[3].y = py;
                    count = 4;
                    break;
                case 11:
                case 36:
                    poly[0].x = px + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[0].y = py + (m_cellSize << FX32_SHIFT);
                    poly[1].x = px + (m_cellSize << FX32_SHIFT);
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py;
                    count = 3;
                    break;
                case 15:
                case 40:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px;
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[3].x = px + (m_cellSize << FX32_SHIFT);
                    poly[3].y = py;
                    count = 4;
                    break;
                case 16:
                case 41:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px;
                    poly[1].y = py + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py + (m_cellSize << FX32_SHIFT);
                    poly[3].x = px + (m_cellSize << FX32_SHIFT);
                    poly[3].y = py;
                    count = 4;
                    break;
                case 20:
                case 45:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px;
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[2].y = py + (m_cellSize << FX32_SHIFT);
                    poly[3].x = px + (m_cellSize << FX32_SHIFT);
                    poly[3].y = py;
                    count = 4;
                    break;
                case 21:
                case 46:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py + (m_cellSize << FX32_SHIFT);
                    poly[3].x = px + (m_cellSize << FX32_SHIFT);
                    poly[3].y = py;
                    count = 4;
                    break;
                case 12:
                case 37:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px;
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[2].y = py;
                    count = 3;
                    break;
                case 24:
                case 49:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px;
                    poly[1].y = py + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py;
                    count = 3;
                    break;
                case 13:
                case 38:
                    poly[0].x = px + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[0].y = py;
                    poly[1].x = px + (m_cellSize << FX32_SHIFT);
                    poly[1].y = py + (m_cellSize << FX32_SHIFT);
                    poly[2].x = px + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[2].y = py;
                    count = 3;
                    break;
                case 25:
                case 50:
                    poly[0].x = px;
                    poly[0].y = py;
                    poly[1].x = px + (m_cellSize << FX32_SHIFT);
                    poly[1].y = py + ((m_cellSize / 2) << FX32_SHIFT);
                    poly[2].x = px + (m_cellSize << FX32_SHIFT);
                    poly[2].y = py;
                    count = 3;
                    break;
                }
                for (int i = 0; i < count; i++) {
                    PointPair2D edge = { poly[i], poly[(i + 1) % count] };
                    if (sub_02006764(edge, circle, NULL, 4)) {
                        return TRUE;
                    }
                }
            }
        }
    }
    return FALSE;
}

int CFieldMapLayerCollision::GetPolygonCount()
{
    return 1;
}

int CFieldMapLayerCollision::GetType()
{
    return 3;
}
