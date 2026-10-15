#include <nitro.h>

#include "field/CFieldMap.hpp"
#include "field/CFieldPartnerManage.hpp"
#include "field/CFieldPlayer.hpp"
#include "fx_utils.hpp"
#include "scene/CFieldScene.hpp"

// Partner placement around the player for CFieldPartnerManage (separate TU after FieldPartnerManage.cpp).

extern CFieldScene *MAIN_BSS_0210CA40;

extern "C" {
BOOL ov0_0213EA6C(Point2D *out, Point2D cell, int floor, int arg3);
BOOL ov0_0213ED7C(Point2D a, Point2D b, CFieldMapLayerCollision *layer);
BOOL ov0_0213E668(Point2D pos, fx32 radius, int floor, int arg3);
BOOL ov0_0213E7C4(Point2D from, fx32 step, Point2D to, int floor, int mode);
int ov0_0213EF68(Point2D *out, Point2D center, int count, int floor);
}

void CFieldPartnerManage::ov0_0213A96C(BOOL keep, u32 id, BOOL warp)
{
    CFieldActor *player = unk_90->ov0_02123060(0);
    Point2D pos;
    pos = player->GetPos();
    int kind0 = 0;
    int npcs = 0;
    if (id != 0) {
        ov0_0213B150(id);
    }
    CFieldPartner *order[11];
    MI_CpuFill8(order, 0, sizeof(order));
    if (unk_80 == 0) {
        for (int i = 0; i < m_count; i++) {
            CFieldPartner *partner = (CFieldPartner *)Get(i);
            if (partner != NULL) {
                if (unk_54[partner->unk_1E8] == 0) {
                    partner->unk_1C8 = 1;
                    order[partner->unk_1E8] = partner;
                    if (partner->IsKind0()) {
                        kind0++;
                    } else {
                        npcs++;
                    }
                } else {
                    partner->unk_1C8 = 0;
                }
            }
        }
    } else {
        for (int i = 0; i < m_count; i++) {
            CFieldPartner *partner = (CFieldPartner *)Get(i);
            if (partner != NULL) {
                if (unk_6A[partner->unk_1E8] == 1) {
                    partner->unk_1C8 = 1;
                    order[partner->unk_1E8] = partner;
                    if (partner->IsKind0()) {
                        kind0++;
                    } else {
                        npcs++;
                    }
                } else {
                    partner->unk_1C8 = 0;
                }
            }
        }
    }
    if (keep) {
        ov0_02139E14(2);
        for (int j = 0; j < 11; j++) {
            if (order[j] != NULL) {
                order[j]->ov0_02136CFC(keep, pos, 30);
                order[j] = NULL;
            }
        }
    } else {
        // `keep` is 0 here, but the original passes the variable (it stays live and spills `warp`).
        ov0_02139E14(3);
        ov0_0213B410(kind0);
        Point2D npcPos[4];
        ov0_0213BB54(npcPos, npcs);
        int a = 0;
        int b = 0;
        for (int j = 0; j < 11; j++) {
            CFieldPartner *partner = order[j];
            if (partner != NULL) {
                if (warp) {
                    partner->SetPos(player->GetPos());
                }
                if (partner->IsKind0()) {
                    partner->ov0_02136CFC(keep, unk_14[a++], 30);
                } else {
                    partner->ov0_02136CFC(keep, npcPos[b++], 30);
                }
                partner->SetLayer(player->m_layer);
                partner->sub_02032A44(1);
                order[j] = NULL;
            }
        }
    }
    for (int k = 0; k < 11; k++) {
        unk_54[k] = 0;
        unk_6A[k] = 0;
    }
    unk_80 = 0;
}

void CFieldPartnerManage::ov0_0213AD8C(BOOL warp)
{
    CFieldActor *player = unk_90->ov0_02123060(0);
    Point2D pos = player->GetPos();
    int kind0 = 0;
    int npcs = 0;
    CFieldPartner *order[11];
    MI_CpuFill8(order, 0, sizeof(order));
    for (int i = 0; i < m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)Get(i);
        if (partner != NULL) {
            partner->unk_1C8 = 1;
            order[partner->unk_1E8] = partner;
            if (partner->IsKind0()) {
                kind0++;
            } else {
                npcs++;
            }
        }
    }
    ov0_02139E14(3);
    ov0_0213BDE8(kind0);
    Point2D npcPos[4];
    ov0_0213BE94(npcPos, npcs);
    int a = 0;
    int b = 0;
    for (int j = 0; j < 11; j++) {
        CFieldPartner *partner = order[j];
        if (partner != NULL) {
            if (warp) {
                partner->SetPos(player->GetPos());
            }
            if (partner->IsKind0()) {
                partner->ov0_02136CFC(FALSE, unk_14[a++], 30);
            } else {
                partner->ov0_02136CFC(FALSE, npcPos[b++], 30);
            }
            partner->SetLayer(player->m_layer);
            partner->sub_02032A44(1);
            order[j] = NULL;
        }
    }
    for (int k = 0; k < 11; k++) {
        unk_54[k] = 0;
        unk_6A[k] = 0;
    }
    unk_80 = 0;
}

BOOL CFieldPartnerManage::ov0_0213B048()
{
    for (int i = 0; i < m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)Get(i);
        if (partner != NULL && partner->IsUnk00CSet()) {
            if (partner->unk_1EC == 2 || partner->unk_1EC == 3) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

BOOL CFieldPartnerManage::ov0_0213B0F0()
{
    for (int i = 0; i < m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)Get(i);
        if (partner != NULL) {
            return partner->IsHidden() ? TRUE : FALSE;
        }
    }
    return FALSE;
}

void CFieldPartnerManage::ov0_0213B150(u32 id)
{
    if (id == 0) {
        return;
    }
    CFieldPartner *partner = (CFieldPartner *)unk_90->ov0_02123060(id);
    if (partner == NULL) {
        return;
    }
    unk_54[partner->unk_1E8] = 1;
}

void CFieldPartnerManage::ov0_0213B184(u32 id)
{
    if (id == 0) {
        return;
    }
    CFieldPartner *partner = (CFieldPartner *)unk_90->ov0_02123060(id);
    if (partner == NULL) {
        return;
    }
    unk_6A[partner->unk_1E8] = 1;
    unk_80 = 1;
}

static inline void SetDest(CFieldPartner *partner, Point2D pos)
{
    partner->unk_1D8 = pos;
}

void CFieldPartnerManage::ov0_0213B1BC()
{
    int count = unk_88;
    if (count == 0) {
        return;
    }
    if (count > 8) {
        count = 8;
    }
    CFieldActor *player = unk_90->ov0_02123060(0);
    int n = ov0_0213EF68(unk_14, player->GetPos(), count, player->m_layer);
    for (int i = 0; i < m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)Get(i);
        if (partner != NULL && partner->IsKind0()) {
            int idx = partner->unk_1E8 - unk_84;
            if (idx >= 8) {
                idx = 7;
            }
            // The flag is stored before the destination is read (setter after the store).
            if (idx < n) {
                partner->unk_1D0 = 0;
                SetDest(partner, unk_14[idx]);
            } else {
                partner->unk_1D0 = 1;
                SetDest(partner, unk_14[idx]);
            }
        }
    }
}

void CFieldPartnerManage::ov0_0213B340()
{
    if (unk_84 == 0) {
        return;
    }
    CFieldActor *player = unk_90->ov0_02123060(0);
    Point2D pos = player->GetPos();
    for (int i = 0; i < m_count; i++) {
        CFieldPartner *partner = (CFieldPartner *)Get(i);
        if (partner != NULL && partner->IsNpc()) {
            partner->ov0_0213889C();
        }
    }
}

void CFieldPartnerManage::ov0_0213B410(int count)
{
    fx32 step[9] = {
        FX_Div(300 << 16, FX32_CONST(360)),
        FX_Div(180 << 16, FX32_CONST(360)),
        FX_Div(120 << 16, FX32_CONST(360)),
        FX_Div(90 << 16, FX32_CONST(360)),
        FX_Div(72 << 16, FX32_CONST(360)),
        FX_Div(60 << 16, FX32_CONST(360)),
        FX_Div(51 << 16, FX32_CONST(360)),
        FX_Div(45 << 16, FX32_CONST(360)),
        FX_Div(40 << 16, FX32_CONST(360)),
    };
    fx32 start[9] = {
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
    fx32 radius[9] = {
        FX32_CONST(32),
        FX32_CONST(32),
        FX32_CONST(32),
        FX32_CONST(32),
        FX32_CONST(40),
        FX32_CONST(40),
        FX32_CONST(40),
        FX32_CONST(48),
        FX32_CONST(48),
    };
    if (count == 0) {
        return;
    }
    if (count > 8) {
        count = 8;
    }
    CFieldActor *player = unk_90->ov0_02123060(0);
    Point2D pos = player->GetPos();
    int n = 0;
    fx32 angle = start[count - 1];
    fx32 st = step[count - 1];
    fx32 r = radius[count - 1];
    // A second read for the first ring: a plain `r` there keeps the radius in a register and spills its sign.
    fx32 r0 = radius[count - 1];
    for (int i = 0; i < count; i++) {
        Point2D p;
        p.x = pos.x - FX32_MUL(r0, FX_SinIdx((u16)(angle + st * i)));
        p.y = pos.y - FX32_MUL(r0, FX_CosIdx((u16)(angle + st * i)));
        if (p.x > 0x14000 && p.y > 0x14000) {
            if (!ov0_0213E668(p, 0x14000, player->m_layer, 0)) {
                unk_14[n].x = p.x;
                unk_14[n].y = p.y;
                n++;
            }
        }
    }
    angle += FX32_MUL(st, FX32_HALF);
    fx32 r1 = r + 0x10000;
    for (int i = 0; i < count && n < count; i++) {
        Point2D p;
        p.x = pos.x - FX32_MUL(r1, FX_SinIdx((u16)(angle + st * i)));
        p.y = pos.y - FX32_MUL(r1, FX_CosIdx((u16)(angle + st * i)));
        if (p.x > 0x14000 && p.y > 0x14000) {
            if (!ov0_0213E668(p, 0x14000, player->m_layer, 0)) {
                if (!ov0_0213E7C4(p, 0x14000, pos, player->m_layer, 0)) {
                    unk_14[n].x = p.x;
                    unk_14[n].y = p.y;
                    n++;
                }
            }
        }
    }
    fx32 r2 = r - 0x10000;
    for (int i = 0; i < count && n < count; i++) {
        Point2D p;
        p.x = pos.x - FX32_MUL(r2, FX_SinIdx((u16)(angle + st * i)));
        p.y = pos.y - FX32_MUL(r2, FX_CosIdx((u16)(angle + st * i)));
        if (p.x > 0x14000 && p.y > 0x14000) {
            if (!ov0_0213E668(p, 0x14000, player->m_layer, 0)) {
                unk_14[n].x = p.x;
                unk_14[n].y = p.y;
                n++;
            }
        }
    }
    // Reusing `angle` and `st` for the last ring matches the original's spill slots (late split temps).
    angle = start[count - 1];
    st = FX32_MUL(st, FX32_HALF);
    fx32 r3 = r + 0x20000;
    for (int i = 0; i < count * 2 && n < count; i++) {
        Point2D p;
        p.x = pos.x - FX32_MUL(r3, FX_SinIdx((u16)(angle + st * i)));
        p.y = pos.y - FX32_MUL(r3, FX_CosIdx((u16)(angle + st * i)));
        if (p.x > 0x14000 && p.y > 0x14000) {
            if (!ov0_0213E668(p, 0x14000, player->m_layer, 0)) {
                if (!ov0_0213E7C4(p, 0x14000, pos, player->m_layer, 0)) {
                    unk_14[n].x = p.x;
                    unk_14[n].y = p.y;
                    n++;
                }
            }
        }
    }
    for (int i = n; i < count; i++) {
        unk_14[i].x = pos.x;
        unk_14[i].y = pos.y;
    }
}

static inline void ToCell(Point2D *cell, const Point2D &pos)
{
    cell->x = (pos.x + 0x8000) >> 16;
    cell->y = (pos.y + 0x8000) >> 16;
}

void CFieldPartnerManage::ov0_0213BB54(Point2D *out, int count)
{
    Point2D dirs[8] = { { -1, -1 }, { -1, 1 }, { 1, 1 }, { 1, -1 }, { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    int n;
    int i;
    if (count == 0) {
        return;
    }
    CFieldActor *player = unk_90->ov0_02123060(0);
    Point2D pos = player->GetPos();
    int floor = player->m_layer;
    Point2D cell;
    ToCell(&cell, pos);
    Point2D found;
    if (ov0_0213EA6C(&found, cell, floor, 0)) {
        cell = found;
    }
    Point2D slots[4];
    n = 0;
    for (i = 0; i < 8 && n < count; i++) {
        Point2D near;
        if (ov0_0213EA6C(&near, cell + dirs[i], floor, 0)) {
            if (cell.x != near.x || cell.y != near.y) {
                slots[n] = near;
                n++;
            }
        }
    }
    if (n == count) {
        for (int j = 0; j < count; j++) {
            out[j].x = slots[j].x << 16;
            out[j].y = slots[j].y << 16;
        }
        return;
    }
    for (int j = n; j < count; j++) {
        slots[j] = cell;
    }
    for (int j = 0; j < n; j++) {
        out[j].x = slots[j].x << 16;
        out[j].y = slots[j].y << 16;
    }
}

void CFieldPartnerManage::ov0_0213BDE8(int count)
{
    if (count == 0) {
        return;
    }
    CFieldActor *player = unk_90->ov0_02123060(0);
    ov0_0213EF68(unk_14, player->GetPos(), count, player->m_layer);
}

void CFieldPartnerManage::ov0_0213BE94(Point2D *out, int count)
{
    Point2D dirs[8] = { { -1, -1 }, { -1, 1 }, { 1, 1 }, { 1, -1 }, { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    int i;
    int n;
    if (count == 0) {
        return;
    }
    CFieldActor *player = unk_90->ov0_02123060(0);
    Point2D pos = player->GetPos();
    CFieldMap *map = MAIN_BSS_0210CA40->m_map;
    int floor = player->m_layer;
    CFieldMapLayerCollision *layer = NULL;
    if (map != NULL) {
        layer = map->GetLayer(floor);
    }
    Point2D cell;
    ToCell(&cell, pos);
    Point2D found;
    if (ov0_0213EA6C(&found, cell, floor, 0)) {
        cell = found;
    }
    Point2D slots[4];
    n = 0;
    for (i = 0; i < 8 && n < count; i++) {
        Point2D near;
        if (ov0_0213EA6C(&near, cell + dirs[i], floor, 0)) {
            if (cell.x != near.x || cell.y != near.y) {
                Point2D p = near;
                p.x <<= 16;
                p.y <<= 16;
                if (!ov0_0213E668(p, 0x7000, floor, 0)) {
                    if (layer == NULL || ov0_0213ED7C(near, cell, layer)) {
                        slots[n] = near;
                        n++;
                    }
                }
            }
        }
    }
    if (n == count) {
        for (int j = 0; j < count; j++) {
            out[j].x = slots[j].x << 16;
            out[j].y = slots[j].y << 16;
        }
        return;
    }
    for (; n < count; n++) {
        slots[n] = cell;
    }
    for (int j = 0; j < count; j++) {
        out[j].x = slots[j].x << 16;
        out[j].y = slots[j].y << 16;
    }
}
