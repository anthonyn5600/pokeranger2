#include <nitro.h>
#include <string.h>

#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "sub_02006000.hpp"
#include "sub_02007254.hpp"

CFieldMapLayerAttribute::CFieldMapLayerAttribute()
{
    m_cells = NULL;
    m_cellCount = 0;
    m_width = 0;
    m_height = 0;
}

CFieldMapLayerAttribute::~CFieldMapLayerAttribute()
{
    Release();
}

BOOL CFieldMapLayerAttribute::Load(void *data)
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
    for (int i = 0; i < count; i++) {
        memcpy(&cell, p, 2);
        p += 2;
        m_cells[i] = cell;
    }
    return TRUE;
}

void CFieldMapLayerAttribute::Release()
{
    SAFE_DELETE_ARRAY(m_cells);
    m_cellCount = 0;
}

int CFieldMapLayerAttribute::Draw(Camera2D *camera)
{
    return 0;
}

BOOL CFieldMapLayerAttribute::ToCell(fx32 x, fx32 y, FieldCellPos *out)
{
    if (out != NULL && x >= 0 && x <= (m_width * m_cellSize) << FX32_SHIFT && y >= 0
        && y <= (m_height * m_cellSize) << FX32_SHIFT) {
        out->x = (x >> FX32_SHIFT) / m_cellSize;
        out->y = (y >> FX32_SHIFT) / m_cellSize;
        return TRUE;
    }
    return FALSE;
}

int CFieldMapLayerAttribute::GetCell(int index)
{
    if (index >= 0 && index < m_cellCount) {
        return m_cells[index];
    }
    return -1;
}

int CFieldMapLayerAttribute::GetCellIndex(int x, int y)
{
    if (x >= 0 && x < m_width && y >= 0) {
        return y * m_width + x;
    }
    return -1;
}

int CFieldMapLayerAttribute::GetCellAt(int x, int y)
{
    return GetCell(GetCellIndex(x, y));
}

int CFieldMapLayerAttribute::GetCellAtPos(fx32 x, fx32 y)
{
    FieldCellPos pos;
    if (!ToCell(x, y, &pos)) {
        return -1;
    }
    return GetCellAt(pos.x, pos.y);
}

BOOL CFieldMapLayerAttribute::Sweep(PointPair2D *move, fx32 radius, u32 kinds, Point2D *out)
{
    fx32 len = MATH_ABS(move->p2.x - move->p1.x);
    fx32 dy = MATH_ABS(move->p2.y - move->p1.y);
    if (len < dy) {
        len = dy;
    }
    fx32 step = radius * 2;
    fx32 maxStep = (m_cellSize / 4) << FX32_SHIFT;
    if (step >= maxStep) {
        step = maxStep;
    }
    if (len <= step) {
        return Collide(move, radius, kinds, out);
    }
    Point2D inc = move->p2 - move->p1;
    inc.x = FX32_DIV(FX32_MUL(inc.x, step), len);
    inc.y = FX32_DIV(FX32_MUL(inc.y, step), len);
    PointPair2D seg;
    seg.p1 = move->p1;
    seg.p2 = move->p1 + inc;
    while (len > 0) {
        if (Collide(&seg, radius, kinds, out)) {
            return TRUE;
        }
        seg.p1 = seg.p2;
        seg.p2 += inc;
        len -= step;
    }
    return FALSE;
}

#define PUSH_OUT(x1, y1, x2, y2)                    \
    {                                               \
        edge.p1.x = x1;                             \
        edge.p1.y = y1;                             \
        edge.p2.x = x2;                             \
        edge.p2.y = y2;                             \
        if (sub_02006764(edge, circle, &h, 0)) {    \
            circle.pos = sub_0200732C(&circle, &h); \
            hit = TRUE;                             \
        }                                           \
    }

BOOL CFieldMapLayerAttribute::Collide(PointPair2D *move, fx32 radius, u32 kinds, Point2D *out)
{
    BOOL hit = FALSE;
    FieldCellPos cell;
    ToCell(move->p1.x, move->p1.y, &cell);
    GetCellIndex(cell.x, cell.y);
    Circle circle = { move->p2, radius };
    u8 dirs = 0;
    PointPair2D mv = *move;
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
        int type = GetCellAt(cell.x - 1, cell.y);
        if (type >= 0 && (kinds & (1 << type))) {
            PointPair2D edge;
            Point2D h;
            fx32 x = (cell.x * m_cellSize) << FX32_SHIFT;
            fx32 y = (cell.y * m_cellSize) << FX32_SHIFT;
            PUSH_OUT(x, y, x, y + (m_cellSize << FX32_SHIFT));
        }
    }
    if (dirs & 2) {
        int type = GetCellAt(cell.x + 1, cell.y);
        if (type >= 0 && (kinds & (1 << type))) {
            PointPair2D edge;
            Point2D h;
            fx32 x = ((cell.x + 1) * m_cellSize) << FX32_SHIFT;
            fx32 y = (cell.y * m_cellSize) << FX32_SHIFT;
            PUSH_OUT(x, y, x, y + (m_cellSize << FX32_SHIFT));
        }
    }
    if (dirs & 4) {
        int type = GetCellAt(cell.x, cell.y - 1);
        if (type >= 0 && (kinds & (1 << type))) {
            PointPair2D edge;
            Point2D h;
            fx32 x = (cell.x * m_cellSize) << FX32_SHIFT;
            fx32 y = (cell.y * m_cellSize) << FX32_SHIFT;
            PUSH_OUT(x, y, x + (m_cellSize << FX32_SHIFT), y);
        }
    }
    if (dirs & 8) {
        int type = GetCellAt(cell.x, cell.y + 1);
        if (type >= 0 && (kinds & (1 << type))) {
            PointPair2D edge;
            Point2D h;
            fx32 x = (cell.x * m_cellSize) << FX32_SHIFT;
            fx32 y = ((cell.y + 1) * m_cellSize) << FX32_SHIFT;
            PUSH_OUT(x, y, x + (m_cellSize << FX32_SHIFT), y);
        }
    }
    if (dirs & 0x10) {
        int type = GetCellAt(cell.x - 1, cell.y - 1);
        if (type >= 0 && (kinds & (1 << type))) {
            PointPair2D edge;
            Point2D h;
            fx32 x = (cell.x * m_cellSize) << FX32_SHIFT;
            fx32 y = ((cell.y - 1) * m_cellSize) << FX32_SHIFT;
            PUSH_OUT(x, y, x, y + (m_cellSize << FX32_SHIFT));
            x = ((cell.x - 1) * m_cellSize) << FX32_SHIFT;
            y = (cell.y * m_cellSize) << FX32_SHIFT;
            PUSH_OUT(x, y, x + (m_cellSize << FX32_SHIFT), y);
        }
    }
    if (dirs & 0x20) {
        int type = GetCellAt(cell.x - 1, cell.y + 1);
        if (type >= 0 && (kinds & (1 << type))) {
            PointPair2D edge;
            Point2D h;
            fx32 x = (cell.x * m_cellSize) << FX32_SHIFT;
            fx32 y = ((cell.y + 1) * m_cellSize) << FX32_SHIFT;
            PUSH_OUT(x, y, x, y + (m_cellSize << FX32_SHIFT));
            x = ((cell.x - 1) * m_cellSize) << FX32_SHIFT;
            y = ((cell.y + 1) * m_cellSize) << FX32_SHIFT;
            PUSH_OUT(x, y, x + (m_cellSize << FX32_SHIFT), y);
        }
    }
    if (dirs & 0x40) {
        int type = GetCellAt(cell.x + 1, cell.y - 1);
        if (type >= 0 && (kinds & (1 << type))) {
            PointPair2D edge;
            Point2D h;
            fx32 x = ((cell.x + 1) * m_cellSize) << FX32_SHIFT;
            fx32 y = ((cell.y - 1) * m_cellSize) << FX32_SHIFT;
            PUSH_OUT(x, y, x, y + (m_cellSize << FX32_SHIFT));
            x = ((cell.x + 1) * m_cellSize) << FX32_SHIFT;
            y = (cell.y * m_cellSize) << FX32_SHIFT;
            PUSH_OUT(x, y, x + (m_cellSize << FX32_SHIFT), y);
        }
    }
    if (dirs & 0x80) {
        int type = GetCellAt(cell.x + 1, cell.y + 1);
        if (type >= 0 && (kinds & (1 << type))) {
            PointPair2D edge;
            Point2D h;
            fx32 x = ((cell.x + 1) * m_cellSize) << FX32_SHIFT;
            fx32 y = ((cell.y + 1) * m_cellSize) << FX32_SHIFT;
            PUSH_OUT(x, y, x + (m_cellSize << FX32_SHIFT), y);
            x = ((cell.x + 1) * m_cellSize) << FX32_SHIFT;
            y = ((cell.y + 1) * m_cellSize) << FX32_SHIFT;
            PUSH_OUT(x, y, x, y + (m_cellSize << FX32_SHIFT));
        }
    }
    if (hit) {
        *out = circle.pos;
    }
    return hit;
}

BOOL CFieldMapLayerAttribute::IsCircleBlocked(Point2D pos, fx32 radius, u32 kinds)
{
    FieldCellPos cell;
    cell.x = pos.x - radius;
    cell.y = pos.y - radius;
    int n = (m_cellSize - 1 + ((radius * 2) >> FX32_SHIFT)) / m_cellSize;
    ToCell(cell.x, cell.y, &cell);
    int x;
    int y;
    for (y = 0; y < n; y++) {
        for (x = 0; x < n; x++) {
            int type = GetCellAt(cell.x + x, cell.y + y);
            if (type >= 0 && (kinds & (1 << type))) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

BOOL CFieldMapLayerAttribute::IsCircleBlockedFine(Point2D pos, fx32 radius, u32 kinds)
{
    Circle circle;
    Point2D poly[4];
    Circle init = { pos, radius };
    memcpy(&circle, &init, sizeof(Circle));
    FieldCellPos cell;
    cell.x = pos.x - radius;
    cell.y = pos.y - radius;
    int n = (m_cellSize - 1 + ((radius * 2) >> FX32_SHIFT)) / m_cellSize;
    ToCell(cell.x, cell.y, &cell);
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int type = GetCellAt(cell.x + x, cell.y + y);
            if (type >= 0 && (kinds & (1 << type))) {
                fx32 px = (m_cellSize * (cell.x + x)) << FX32_SHIFT;
                fx32 py = (m_cellSize * (cell.y + y)) << FX32_SHIFT;
                poly[0].x = px;
                poly[0].y = py;
                poly[1].x = px;
                poly[1].y = py + (m_cellSize << FX32_SHIFT);
                poly[2].x = px + (m_cellSize << FX32_SHIFT);
                poly[2].y = py + (m_cellSize << FX32_SHIFT);
                poly[3].x = px + (m_cellSize << FX32_SHIFT);
                poly[3].y = py;
                for (int i = 0; i < 4; i++) {
                    PointPair2D edge = { poly[i], poly[(i + 1) % 4] };
                    if (sub_02006764(edge, circle, NULL, 0)) {
                        return TRUE;
                    }
                }
            }
        }
    }
    return FALSE;
}

int CFieldMapLayerAttribute::GetPolygonCount()
{
    return 0;
}

int CFieldMapLayerAttribute::GetType()
{
    return 6;
}
