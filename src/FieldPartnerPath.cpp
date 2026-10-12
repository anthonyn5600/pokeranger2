#include <nitro.h>

#include "common.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "field/CFieldNpcManage.hpp"
#include "field/CFieldPartner.hpp"
#include "field/CFieldPartnerManage.hpp"
#include "field/CFieldTargetObjectManage.hpp"
#include "scene/CFieldScene.hpp"
#include "sub_02006000.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;

struct CellPos {
    int x;
    int y;
};

struct CellLine {
    Point2D cells[128];
    int count;
};

static inline void AddCell(CellLine *line, int x, int y)
{
    Point2D *cell = &line->cells[line->count];
    cell->x = x;
    cell->y = y;
    line->count++;
}

static inline void TraceX(CellLine *line, const Point2D &from, const Point2D &to, int &x, int &y, int sx, int sy, int dx, int dy)
{
    int err = dy * 2 - dx;
    if (from.x != to.x) {
        do {
            if (err >= 0) {
                y += sy;
                err -= dx;
            }
            x += sx;
            err += dy;
            AddCell(line, x, y);
        } while (x != to.x);
    }
}

extern "C" {
int ov0_0213E53C(CellLine *line, Point2D from, Point2D to);
BOOL ov0_0213E668(Point2D pos, fx32 radius, int floor, int arg3);
BOOL ov0_0213E7C4(Point2D from, fx32 step, Point2D to, int floor, int mode);
BOOL ov0_0213E918(Point2D from, fx32 step, Point2D to, CFieldMapLayerCollision *layer, int mode);
BOOL ov0_0213E9EC(Point2D from, fx32 step, Point2D to, int floor);
BOOL ov0_0213EA6C(Point2D *out, Point2D cell, int floor, int arg3);
BOOL ov0_0213EC1C(Point2D *out, Point2D cell, CFieldMapLayerCollision *coll);
BOOL ov0_0213ED7C(Point2D from, Point2D to, CFieldMapLayerCollision *coll);
int ov0_0213EF68(Point2D *out, Point2D center, int count, int floor);
}

// Cell offsets around the placement center: rings for the first search, diagonals for the last.
static Point2D sDiagonalOffsets[4] = { { -1, -1 }, { -1, 1 }, { 1, 1 }, { 1, -1 } };
static Point2D sRingOffsets[34] = {
    { 0, -2 },
    { -2, 0 },
    { 0, 2 },
    { 2, 0 },
    { -2, -2 },
    { -2, 2 },
    { 2, 2 },
    { 2, -2 },
    { 0, -4 },
    { -4, 0 },
    { 0, 4 },
    { 4, 0 },
    { 2, -4 },
    { -2, -4 },
    { -4, -2 },
    { 4, 2 },
    { -2, 4 },
    { 2, 4 },
    { 4, 2 },
    { -4, -2 },
    { -4, -4 },
    { -4, 4 },
    { 4, 4 },
    { 4, -4 },
    { -6, 0 },
    { 6, 0 },
    { -6, -2 },
    { -6, 2 },
    { 6, 2 },
    { 6, -2 },
    { -6, -4 },
    { -6, 4 },
    { 6, 4 },
    { 6, -4 },
};

int ov0_0213E53C(CellLine *line, Point2D from, Point2D to)
{
    int y = from.y;
    int sx = 1;
    int sy = 1;
    fx32 dx = to.x - from.x;
    fx32 dy = to.y - y;
    if (dx < 0) {
        sx -= 2;
    }
    if (dy < 0) {
        sy = -1;
    }
    dx = MATH_ABS(dx * 2);
    dy = MATH_ABS(dy * 2);
    if (dx >= 0x100 || dy >= 0x100) {
        return 0;
    }
    int x = from.x;
    line->count = 0;
    AddCell(line, x, y);
    if (dx > dy) {
        TraceX(line, from, to, x, y, sx, sy, dx, dy);
    } else {
        int err = dx * 2 - dy;
        while (y != to.y) {
            if (err >= 0) {
                x += sx;
                err -= dy;
            }
            y += sy;
            err += dx;
            AddCell(line, x, y);
        }
    }
    return line->count;
}

BOOL ov0_0213E668(Point2D pos, fx32 radius, int floor, int arg3)
{
    if (MAIN_BSS_0210CA7C != NULL && MAIN_BSS_0210CA7C->sub_02040158(pos, radius, floor)) {
        return TRUE;
    }
    if (MAIN_BSS_0210CA50 != NULL && MAIN_BSS_0210CA50->sub_02040158(pos, radius, floor)) {
        return TRUE;
    }
    CFieldMap *fieldMap = MAIN_BSS_0210CA40->unk_0010;
    if (fieldMap != NULL) {
        CFieldMapLayerCollision *coll = fieldMap->GetLayer(floor);
        if (coll != NULL && coll->IsCircleBlocked(pos, radius, 3)) {
            return TRUE;
        }
        CFieldMapLayerAttribute *attr = fieldMap->GetAttributeLayer(floor);
        if (attr != NULL && attr->IsCircleBlocked(pos, radius, 0x804000)) {
            return TRUE;
        }
    }
    return FALSE;
}

BOOL ov0_0213E7C4(Point2D from, fx32 step, Point2D to, int floor, int mode)
{
    PointPair2D seg;
    Point2D hit;
    CellLine line;
    seg.p1 = from;
    seg.p2 = to;
    CFieldMap *fieldMap = MAIN_BSS_0210CA40->unk_0010;
    if (fieldMap != NULL) {
        CFieldMapLayerCollision *coll = fieldMap->GetLayer(floor);
        if (coll != NULL) {
            Point2D a = { from.x >> 16, from.y >> 16 };
            Point2D b = { to.x >> 16, to.y >> 16 };
            int count = ov0_0213E53C(&line, a, b);
            for (int i = 1; i < count - 1; i++) {
                if (CFieldMapLayerCollision::IsWall(coll->GetCellAt(line.cells[i].x, line.cells[i].y))) {
                    return TRUE;
                }
            }
        }
    }
    if (MAIN_BSS_0210CA7C != NULL && MAIN_BSS_0210CA7C->sub_0203F7F4(&seg, step, floor, &hit)) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov0_0213E918(Point2D from, fx32 step, Point2D to, CFieldMapLayerCollision *layer, int mode)
{
    CellLine line;
    if (layer != NULL) {
        Point2D a = { from.x >> 16, from.y >> 16 };
        Point2D b = { to.x >> 16, to.y >> 16 };
        int count = ov0_0213E53C(&line, a, b);
        for (int i = 1; i < count - 1; i++) {
            if (CFieldMapLayerCollision::IsWall(layer->GetCellAt(line.cells[i].x, line.cells[i].y))) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

static inline void SetPoint(Point2D *p, fx32 x, fx32 y)
{
    p->x = x;
    p->y = y;
}

BOOL ov0_0213E9EC(Point2D from, fx32 step, Point2D to, int floor)
{
    PointPair2D seg;
    Point2D hit;
    SetPoint(&seg.p1, from.x, from.y);
    seg.p2 = to;
    if (MAIN_BSS_0210CA7C != NULL && MAIN_BSS_0210CA7C->sub_0203F7F4(&seg, step, floor, &hit)) {
        return TRUE;
    }
    return FALSE;
}

BOOL ov0_0213EA6C(Point2D *out, Point2D cell, int floor, int arg3)
{
    Point2D offsets[16] = {
        { 0, 0 },
        { -1, -1 },
        { 1, -1 },
        { 0, -1 },
        { -1, 1 },
        { -1, 0 },
        { 0, 0 },
        { -1, -1 },
        { 1, 1 },
        { 0, 0 },
        { 1, 0 },
        { 1, -1 },
        { 0, 1 },
        { -1, 1 },
        { 1, 1 },
        { 0, 0 },
    };
    *out = cell;
    CFieldMap *fieldMap = MAIN_BSS_0210CA40->unk_0010;
    if (fieldMap == NULL) {
        return FALSE;
    }
    CFieldMapLayerCollision *coll = fieldMap->GetLayer(floor);
    if (coll == NULL) {
        return FALSE;
    }
    int mask = 0;
    if (CFieldMapLayerCollision::IsWall(coll->GetCellAt(cell.x, cell.y))) {
        mask |= 1;
    }
    if (cell.x == 0 || CFieldMapLayerCollision::IsWall(coll->GetCellAt(cell.x - 1, cell.y))) {
        mask |= 2;
    }
    if (cell.y == 0 || CFieldMapLayerCollision::IsWall(coll->GetCellAt(cell.x, cell.y - 1))) {
        mask |= 4;
    }
    if (cell.y == 0 || cell.x == 0 || CFieldMapLayerCollision::IsWall(coll->GetCellAt(cell.x - 1, cell.y - 1))) {
        mask |= 8;
    }
    *out = cell;
    if (mask == 15) {
        return FALSE;
    }
    if (mask == 0) {
        return TRUE;
    }
    out->x += offsets[mask].x;
    out->y += offsets[mask].y;
    return TRUE;
}

BOOL ov0_0213EC1C(Point2D *out, Point2D cell, CFieldMapLayerCollision *coll)
{
    Point2D offsets[16] = {
        { 0, 0 },
        { -1, -1 },
        { 1, -1 },
        { 0, -1 },
        { -1, 1 },
        { -1, 0 },
        { 0, 0 },
        { -1, -1 },
        { 1, 1 },
        { 0, 0 },
        { 1, 0 },
        { 1, -1 },
        { 0, 1 },
        { -1, 1 },
        { 1, 1 },
        { 0, 0 },
    };
    *out = cell;
    int mask = 0;
    if (CFieldMapLayerCollision::IsWall(coll->GetCellAt(cell.x, cell.y))) {
        mask |= 1;
    }
    if (cell.x == 0 || CFieldMapLayerCollision::IsWall(coll->GetCellAt(cell.x - 1, cell.y))) {
        mask |= 2;
    }
    if (cell.y == 0 || CFieldMapLayerCollision::IsWall(coll->GetCellAt(cell.x, cell.y - 1))) {
        mask |= 4;
    }
    if (cell.y == 0 || cell.x == 0 || CFieldMapLayerCollision::IsWall(coll->GetCellAt(cell.x - 1, cell.y - 1))) {
        mask |= 8;
    }
    *out = cell;
    if (mask == 15) {
        return FALSE;
    }
    if (mask == 0) {
        return TRUE;
    }
    out->x += offsets[mask].x;
    out->y += offsets[mask].y;
    return TRUE;
}

BOOL ov0_0213ED7C(Point2D from, Point2D to, CFieldMapLayerCollision *coll)
{
    int dx = from.x - to.x;
    int dy = from.y - to.y;
    if (MATH_ABS(dx) + MATH_ABS(dy) < 2) {
        return TRUE;
    }
    Point2D next = from;
    if (dx > 0) {
        next.x--;
        if (!CFieldMapLayerCollision::IsWall(coll->GetCellAt(next.x, next.y)) && ov0_0213ED7C(next, to, coll)) {
            return TRUE;
        }
    } else if (dx < 0) {
        next.x++;
        if (!CFieldMapLayerCollision::IsWall(coll->GetCellAt(next.x, next.y)) && ov0_0213ED7C(next, to, coll)) {
            return TRUE;
        }
    }
    next.x = from.x;
    if (dy > 0) {
        next.y--;
        if (CFieldMapLayerCollision::IsWall(coll->GetCellAt(next.x, next.y))) {
            return FALSE;
        }
        return ov0_0213ED7C(next, to, coll);
    } else if (dy < 0) {
        next.y++;
        if (CFieldMapLayerCollision::IsWall(coll->GetCellAt(next.x, next.y))) {
            return FALSE;
        }
        return ov0_0213ED7C(next, to, coll);
    }
    return FALSE;
}

int ov0_0213EF68(Point2D *out, Point2D center, int count, int floor)
{
    Point2D others[2];
    Point2D found[12];
    CFieldMapLayerCollision *coll = NULL;
    CFieldMap *fieldMap = MAIN_BSS_0210CA40->unk_0010;
    if (fieldMap != NULL) {
        coll = fieldMap->GetLayer(floor);
    }
    Point2D centerCell = { (center.x + 0x8000) >> 16, (center.y + 0x8000) >> 16 };
    Point2D snapped;
    int k = 0;
    if (ov0_0213EA6C(&snapped, centerCell, floor, 0)) {
        centerCell = snapped;
    }

    int n = 0;
    CFieldPartnerManage *partners = MAIN_BSS_0210CA40->unk_001C;
    for (int i = 0; i < partners->m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)partners->Get(i);
        if (partner != NULL && partner->unk_1FC == 1) {
            others[n].x = (partner->GetPos().x + 0x8000) >> 16;
            others[n].y = (partner->GetPos().y + 0x8000) >> 16;
            n++;
        }
    }

    fx32 steps[10] = {
        FX_Div(0 << 16, FX32_CONST(360)),
        FX_Div(0 << 16, FX32_CONST(360)),
        FX_Div(180 << 16, FX32_CONST(360)),
        FX_Div(120 << 16, FX32_CONST(360)),
        FX_Div(90 << 16, FX32_CONST(360)),
        FX_Div(72 << 16, FX32_CONST(360)),
        FX_Div(60 << 16, FX32_CONST(360)),
        FX_Div(51 << 16, FX32_CONST(360)),
        FX_Div(45 << 16, FX32_CONST(360)),
        FX_Div(40 << 16, FX32_CONST(360)),
    };
    fx32 starts[10] = {
        FX_Div(0 << 16, FX32_CONST(360)),
        FX_Div(300 << 16, FX32_CONST(360)),
        FX_Div(90 << 16, FX32_CONST(360)),
        FX_Div(0 << 16, FX32_CONST(360)),
        FX_Div(0 << 16, FX32_CONST(360)),
        FX_Div(0 << 16, FX32_CONST(360)),
        FX_Div(0 << 16, FX32_CONST(360)),
        FX_Div(0 << 16, FX32_CONST(360)),
        FX_Div(0 << 16, FX32_CONST(360)),
        FX_Div(0 << 16, FX32_CONST(360)),
    };
    fx32 radii[10] = { 0, 0x20000, 0x20000, 0x20000, 0x20000, 0x28000, 0x28000, 0x28000, 0x30000, 0x30000 };

    fx32 angle = starts[count];
    fx32 st = steps[count];
    fx32 r = radii[count];
    for (int i = 0; i < count; i++) {
        Point2D pos;
        pos.x = center.x - FX32_MUL(r, FX_SinIdx((u16)(angle + st * i)));
        pos.y = center.y - FX32_MUL(r, FX_CosIdx((u16)(angle + st * i)));
        if (pos.x > 0x14000 && pos.y > 0x14000 && !ov0_0213E668(pos, 0xF000, floor, 0)) {
            int cx = (pos.x + 0x8000) >> 16;
            int cy = (pos.y + 0x8000) >> 16;
            Point2D to = { snapped.x << 16, snapped.y << 16 };
            if (!ov0_0213E918(pos, 0xF000, to, coll, 0)) {
                BOOL near = FALSE;
                for (int m = 0; m < n; m++) {
                    int dx = MATH_ABS(others[m].x - cx);
                    int dy = MATH_ABS(others[m].y - cy);
                    if (dx < 2 && dy < 2) {
                        near = TRUE;
                        break;
                    }
                }
                if (!near) {
                    out[k].x = pos.x;
                    out[k].y = pos.y;
                    found[k].x = cx;
                    found[k].y = cy;
                    k++;
                }
            }
        }
    }

    if (count - k >= 4) {
        k = 0;
    }
    int ring = k;

    for (int j = 0; j < 34 && k < count; j++) {
        Point2D cand = centerCell + sRingOffsets[j];
        if (coll != NULL) {
            Point2D cell;
            if (!ov0_0213EC1C(&cell, cand, coll)) {
                continue;
            }
            Point2D pos = cell;
            pos.x <<= 16;
            pos.y <<= 16;
            if (ov0_0213E668(pos, 0xF000, floor, 0)) {
                continue;
            }
            if (!ov0_0213ED7C(cell, centerCell, coll)) {
                continue;
            }
            if (ov0_0213E9EC(pos, 0x1000, center, floor)) {
                continue;
            }
            BOOL near = FALSE;
            for (int m = 0; m < k; m++) {
                int dx = MATH_ABS(found[m].x - cell.x);
                int dy = MATH_ABS(found[m].y - cell.y);
                if (dx < 2 && dy < 1) {
                    near = TRUE;
                    break;
                }
            }
            if (near) {
                continue;
            }
            near = FALSE;
            for (int m = 0; m < n; m++) {
                int dx = MATH_ABS(others[m].x - cell.x);
                int dy = MATH_ABS(others[m].y - cell.y);
                if (dx < 2 && dy < 1) {
                    near = TRUE;
                    break;
                }
            }
            if (near) {
                continue;
            }
            cand = cell;
        }
        found[k].x = cand.x;
        found[k].y = cand.y;
        k++;
    }

    for (int j = 0; j < 4 && k < count; j++) {
        Point2D cand = centerCell + sDiagonalOffsets[j];
        if (coll != NULL) {
            Point2D cell;
            if (!ov0_0213EC1C(&cell, cand, coll)) {
                continue;
            }
            Point2D pos = cell;
            pos.x <<= 16;
            pos.y <<= 16;
            if (!ov0_0213ED7C(cell, centerCell, coll)) {
                continue;
            }
            if (ov0_0213E9EC(pos, 0x1000, center, floor)) {
                continue;
            }
            BOOL near = FALSE;
            for (int m = 0; m < k; m++) {
                int dx = MATH_ABS(found[m].x - cell.x);
                int dy = MATH_ABS(found[m].y - cell.y);
                if (dx < 1 && dy < 1) {
                    near = TRUE;
                    break;
                }
            }
            if (near) {
                continue;
            }
            cand = cell;
        }
        found[k].x = cand.x;
        found[k].y = cand.y;
        k++;
    }

    if (k == count) {
        for (int i = ring; i < count; i++) {
            out[i].x = found[i].x << 16;
            out[i].y = found[i].y << 16;
        }
        return count;
    }
    for (int i = k; i < count; i++) {
        found[i] = centerCell;
    }
    for (int i = ring; i < count; i++) {
        out[i].x = found[i].x << 16;
        out[i].y = found[i].y << 16;
    }
    return k;
}

// Fake: an unreferenced const after the last function (own section, stripped by mwld, so no bytes) flips the
// size-sort tie of the two equal 128-byte offset templates of EA6C/EC1C to the original order. The original TU
// likely had some such unreferenced object; which one is unknown.
extern const int kFieldPartnerPathUnused = 1;
