#include "field/CFieldPartner.hpp"

#include <nitro.h>
#include <string.h>

#include "CGame.hpp"
#include "UnkClass_020B26A0.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldPartnerManage.hpp"
#include "field/CFieldPlayer.hpp"
#include "fx_utils.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;
extern UnkClass_020B26A0 MAIN_BSS_020B26A0;

extern "C" {
void sub_02012A3C(UnkClass_0201287C *obj, int arg1, fx32 arg2, fx32 arg3);
void ov0_0213EA6C(Point2D *out, Point2D cell, int floor, int arg3);
BOOL ov0_0213E668(Point2D pos, fx32 radius, int floor, int arg3);
BOOL ov0_0213E7C4(Point2D from, fx32 step, Point2D to, int floor, int mode);
BOOL ov0_0213E918(Point2D from, fx32 step, Point2D to, CFieldMapLayerCollision *layer, int mode);
}

static Point2D ov0_02136B34(Point2D center, fx32 radius, int angle)
{
    Point2D pos = center;
    pos.x += FX32_MUL(radius, FX_CosIdx(angle));
    pos.y -= FX32_MUL(radius, FX_SinIdx(angle));
    return pos;
}

CFieldPartner::CFieldPartner()
{
    unk_10 = 0x2000;
    unk_1E8 = -1;
    unk_1EC = 0;
    Rectangle bounds = { { 0, -0x8000 }, { 0x10000, 0x20000 } };
    unk_24.pos.x = bounds.pos.x;
    unk_24.pos.y = bounds.pos.y;
    unk_24.size.x = bounds.size.x;
    unk_24.size.y = bounds.size.y;
    unk_1FC = 0;
    unk_1F8 = 0;
    unk_1CC = 0;
    unk_EC.unk_48 = this;
    unk_EC.unk_CC = 1;
    sub_02032A44(1);
    unk_1F4 = 0;
    CFieldScene *scene = MAIN_BSS_0210CA40;
    unk_E0 = scene->unk_001C;
    unk_E4 = scene->ov0_02123060(0);
    unk_E8 = 0;
}

void CFieldPartner::sub_02032A44(int sequence)
{
    unk_EC.ov0_0215674C(sequence);
}

CFieldPartner::~CFieldPartner()
{
}

void CFieldPartner::ov0_02136CFC(BOOL keep, Point2D pos, int arg)
{
    if (unk_08 != NULL && unk_08->unk_0C != NULL) {
        sub_02011AB0(&unk_08->unk_0C->unk_00C, pos, arg);
    }
    if (!keep) {
        unk_04 &= ~1;
    }
}

BOOL CFieldPartner::ov0_02136D50(Point2D *out, int rank, BOOL clear)
{
    Point2D target = unk_E4->GetPos();
    Point2D d = GetPos() - target;
    int angle = FX_Atan2Idx(d.y, d.x);
    int mode;
    if (unk_EC.unk_68 == 3) {
        mode = 2;
    } else {
        mode = 0;
    }
    if (unk_6C == NULL) {
        *out = target;
        return TRUE;
    }
    CFieldMapLayerCollision *layer = unk_6C->GetLayer(unk_14);
    if (layer == NULL) {
        *out = target;
        return TRUE;
    }
    if (rank != 0) {
        fx32 radius;
        if (rank == 1) {
            angle += FX_Div(0x5A0000, 0x168000);
            radius = 0x10000;
        } else if (rank == 2) {
            angle -= FX_Div(0x5A0000, 0x168000);
            radius = 0x18000;
        } else {
            radius = 0x20000;
        }
        target = ov0_02136B34(target, radius, (u16)angle);
    }
    if (!clear) {
        if (!ov0_0213E918(GetPos(), 0x10000, target, layer, mode)) {
            *out = target;
            return TRUE;
        }
    } else {
        if (!ov0_0213E7C4(GetPos(), 0x10000, target, unk_14, mode)) {
            *out = target;
            return TRUE;
        }
    }
    // The trail is read through `player`, but the loop counts re-read unk_E4 (as in the original).
    CFieldPlayer *player = (CFieldPlayer *)unk_E4;
    for (int i = 0; i < ((CFieldPlayer *)unk_E4)->unk_1B0; i++) {
        target = player->GetPartnerTrail(i);
        if (target.x >= 0 && target.y >= 0) {
            if (!clear) {
                if (!ov0_0213E918(GetPos(), 0x10000, target, layer, mode)) {
                    *out = target;
                    return TRUE;
                }
            } else {
                if (!ov0_0213E7C4(GetPos(), 0x10000, target, unk_14, mode)) {
                    *out = target;
                    return TRUE;
                }
            }
        }
    }
    fx32 bestDist = 0x7FFFFFFF;
    int best = 0;
    for (int i = 0; i < ((CFieldPlayer *)unk_E4)->unk_1B0; i++) {
        Point2D diff = player->GetPartnerTrail(i) - GetPos();
        fx32 dist = FX32_MUL(diff.x, diff.x) + FX32_MUL(diff.y, diff.y);
        if (dist <= bestDist) {
            bestDist = dist;
            best = i;
        }
    }
    *out = player->GetPartnerTrail(best);
    return TRUE;
}

BOOL CFieldPartner::ov0_021373C0(Point2D *out)
{
    Point2D target = unk_E4->GetPos();
    if (unk_6C == NULL) {
        *out = target;
        return TRUE;
    }
    if (unk_6C->GetLayer(unk_14) == NULL) {
        *out = target;
        return TRUE;
    }
    if (!ov0_0213E7C4(GetPos(), 0x10000, target, unk_14, 0)) {
        *out = target;
        return TRUE;
    }
    // The trail is read through `player`, but the loop counts re-read unk_E4 (as in the original).
    CFieldPlayer *player = (CFieldPlayer *)unk_E4;
    for (int i = 0; i < ((CFieldPlayer *)unk_E4)->unk_1B0; i++) {
        target = player->GetPartnerTrail(i);
        if (target.x >= 0 && target.y >= 0) {
            if (!ov0_0213E7C4(GetPos(), 0x10000, target, unk_14, 0)) {
                *out = target;
                return TRUE;
            }
        }
    }
    fx32 bestDist = 0x7FFFFFFF;
    int best = 0;
    for (int i = 0; i < ((CFieldPlayer *)unk_E4)->unk_1B0 && i < 3; i++) {
        Point2D diff = player->GetPartnerTrail(i) - GetPos();
        fx32 dist = FX32_MUL(diff.x, diff.x) + FX32_MUL(diff.y, diff.y);
        if (dist <= bestDist) {
            bestDist = dist;
            best = i;
        }
    }
    *out = player->GetPartnerTrail(best);
    return TRUE;
}

BOOL CFieldPartner::ov0_02137790(Point2D *out, CFieldPartner *prev)
{
    Point2D target;
    int mode;
    if (unk_EC.unk_68 == 3) {
        mode = 2;
    } else {
        mode = 0;
    }
    if (prev->unk_204.count == 0) {
        target = prev->GetPos();
        if (!ov0_0213E7C4(GetPos(), 0x10000, target, unk_14, mode)) {
            *out = target;
            return TRUE;
        }
    }
    for (int i = 0; i < prev->unk_204.count; i++) {
        target = prev->unk_204.GetPartner(i);
        if (!ov0_0213E7C4(GetPos(), 0x10000, target, unk_14, mode)) {
            *out = target;
            return TRUE;
        }
    }
    fx32 bestDist = 0x7FFFFFFF;
    int best = 0;
    for (int i = 0; i < prev->unk_204.count; i++) {
        Point2D diff = prev->unk_204.GetPartner(i) - GetPos();
        fx32 dist = FX32_MUL(diff.x, diff.x) + FX32_MUL(diff.y, diff.y);
        if (dist <= bestDist) {
            bestDist = dist;
            best = i;
        }
    }
    *out = prev->unk_204.GetPartner(best);
    return TRUE;
}

BOOL CFieldPartner::ov0_02137AFC(Point2D *out, CFieldPartner *prev)
{
    Point2D target;
    if (prev->unk_204.count == 0) {
        target = prev->GetPos();
        if (!ov0_0213E7C4(GetPos(), 0x10000, target, unk_14, 0)) {
            *out = target;
            return TRUE;
        }
    }
    for (int i = 0; i < prev->unk_204.count; i++) {
        target = prev->unk_204.GetPartner(i);
        if (!ov0_0213E7C4(GetPos(), 0x10000, target, unk_14, 0)) {
            *out = target;
            return TRUE;
        }
    }
    fx32 bestDist = 0x7FFFFFFF;
    Point2D d = prev->GetPos() - GetPos();
    fx32 selfDist = FX32_MUL(d.x, d.x) + FX32_MUL(d.y, d.y);
    int best = 0;
    for (int i = 0; i < prev->unk_204.count && i < 3; i++) {
        Point2D diff = prev->unk_204.GetPartner(i) - GetPos();
        fx32 dist = FX32_MUL(diff.x, diff.x) + FX32_MUL(diff.y, diff.y);
        if (dist <= bestDist) {
            Point2D gap = prev->GetPos() - prev->unk_204.GetPartner(i);
            if (selfDist > FX32_MUL(gap.x, gap.x) + FX32_MUL(gap.y, gap.y)) {
                bestDist = dist;
                best = i;
            }
        }
    }
    *out = prev->unk_204.GetPartner(best);
    return TRUE;
}

static inline Point2D GetNearestTrail(CFieldPartner *partner, Point2D pos)
{
    FieldTrail *trail = &partner->unk_204;
    fx32 bestDist = 0x7FFFFFFF;
    int best = 0;
    for (int i = 0; i < trail->count; i++) {
        Point2D diff = trail->partner[i] - pos;
        fx32 dist = FX32_MUL(diff.x, diff.x) + FX32_MUL(diff.y, diff.y);
        if (dist <= bestDist) {
            best = i;
            bestDist = dist;
        }
    }
    return trail->partner[best];
}

BOOL CFieldPartner::ov0_0213803C(int arg)
{
    // The original reserves 0x404 bytes of stack that nothing uses (probably a debug buffer whose use was compiled
    // out). A zero-length memset keeps such an array without generating code. Fake, but it gives the same frame.
    char unused[0x404];
    memset(unused, 0, 0);
    Point2D prevPos; // only written: the original keeps this copy of the previous partner's position
    fx32 nearSq;
    fx32 farSq;
    if (unk_EC.unk_44 == 9 || unk_EC.unk_44 == 6) {
        nearSq = 0x400000;
        farSq = 0x240000;
    } else {
        nearSq = 0x900000;
        farSq = 0x640000;
    }
    int order = unk_1E8;
    int rank = order;
    if (IsKind0()) {
        rank -= unk_E0->unk_84;
    }
    if (rank <= 1) {
        Point2D d = GetPos() - unk_E4->GetPos();
        if (FX32_MUL(d.x, d.x) + FX32_MUL(d.y, d.y) < nearSq) {
            return FALSE;
        }
        ov0_02136D50(&unk_1D8, rank + 1, 0);
        return TRUE;
    }
    // The partner two places ahead in the chain.
    CFieldPartner *prev = unk_E0->FindByOrder(unk_1E8 - 2);
    int move = prev->unk_EC.unk_68;
    int kind = prev->unk_268;
    if (move != 5 && kind != 0x27) {
        Point2D d = prevPos = prev->GetPos();
        d -= GetPos();
        if (FX32_MUL(d.x, d.x) + FX32_MUL(d.y, d.y) < farSq) {
            return FALSE;
        }
        if (ov0_02137790(&unk_1D8, prev)) {
            return TRUE;
        }
        unk_1D8 = GetNearestTrail(prev, GetPos());
        return TRUE;
    }
    Point2D d = GetPos() - unk_E4->GetPos();
    if (FX32_MUL(d.x, d.x) + FX32_MUL(d.y, d.y) < nearSq) {
        return FALSE;
    }
    ov0_02136D50(&unk_1D8, 3, 0);
    return TRUE;
}

void CFieldPartner::ov0_02138628()
{
    if (unk_1C8 == 0) {
        return;
    }
    if (unk_1EC == 2) {
        if (IsUnk00CSet()) {
            return;
        }
        SetUnk1EC(4);
        unk_04 |= 1;
    } else if (unk_1EC == 3) {
        if (IsUnk00CSet()) {
            return;
        }
        SetUnk1EC(1);
    }
}

void CFieldPartner::SetUnk1EC(int value)
{
    unk_1EC = value;
}

void CFieldPartner::ov0_02138714(int arg)
{
    unk_EC.unk_BC = 0;
    if ((unk_1CC & 1) ? TRUE : FALSE) {
        if (unk_EC.unk_44 == 1 || unk_EC.unk_44 == 6) {
            return;
        }
        sub_02032A44(1);
        return;
    }
    if (unk_14 != unk_E4->unk_14) {
        ov0_0213905C();
        return;
    }
    if ((unk_1E8 & 2) != (CGame::GetInstance()->unk_0000 & 2)) {
        return;
    }
    if (unk_EC.unk_68 == 1 || unk_EC.unk_68 == 2) {
        if (GetUnk8C() > 0) {
            return;
        }
    }
    if (ov0_0213803C(arg)) {
        if (unk_EC.unk_44 == 1) {
            unk_EC.ov0_02152AD0(this, unk_1D8, unk_1F8);
            sub_02032A44(9);
            return;
        }
        unk_EC.SetUnk04(unk_1D8);
        return;
    }
    if (unk_EC.unk_44 == 1 || unk_EC.unk_44 == 6) {
        return;
    }
    sub_02032A44(1);
}

void CFieldPartner::ov0_0213889C()
{
    if (!ov0_0213E668(GetPos(), 0x7000, unk_14, 0)) {
        unk_1D8 = GetPos();
        return;
    }
    CFieldPlayer *player = (CFieldPlayer *)unk_E4;
    int i = unk_1E8 + 1;
    if (player->unk_1B0 > i) {
        unk_1D8 = player->GetPartnerTrail(i);
        if (!ov0_0213E668(unk_1D8, 0x7000, unk_14, 0)) {
            return;
        }
    }
    unk_1D8 = player->GetPos();
}

void CFieldPartner::ov0_02138A7C()
{
    if (unk_EC.unk_68 == 1 || unk_EC.unk_68 == 2) {
        if (GetUnk8C() > 0) {
            return;
        }
    }
    unk_1F4 = 0;
    if (unk_EC.unk_44 == 9 || unk_EC.unk_44 == 6) {
        unk_1D4 = 0;
        unk_EC.SetUnk04(unk_1D8);
    } else {
        unk_1D4 = 0;
        unk_EC.ov0_02152AD0(this, unk_1D8, unk_1F8);
        sub_02032A44(9);
    }
}

void CFieldPartner::ov0_02138B44()
{
    if ((unk_1CC & 1) ? TRUE : FALSE) {
        if (unk_EC.unk_44 == 1 || unk_EC.unk_44 == 6) {
            return;
        }
        sub_02032A44(1);
        return;
    }
    unk_EC.unk_BC = 0;
    if (unk_14 != unk_E4->unk_14) {
        ov0_0213905C();
        return;
    }
    if ((unk_1E8 & 2) != (CGame::GetInstance()->unk_0000 & 2)) {
        return;
    }
    if (unk_EC.unk_68 == 1 || unk_EC.unk_68 == 2) {
        if (GetUnk8C() > 0) {
            return;
        }
    }
    if (unk_1D0 == 1) {
        ov0_02138714(0x18000);
        return;
    }
    unk_EC.unk_BC = 0;
    Point2D d = GetPos() - unk_1D8;
    fx32 dist = FX32_MUL(d.x, d.x) + FX32_MUL(d.y, d.y);
    if (dist == 0) {
        return;
    }
    if (!ov0_0213E7C4(GetPos(), 0x10000, unk_1D8, unk_14, 0)) {
        if (unk_EC.unk_44 == 9 || unk_EC.unk_44 == 6) {
            unk_EC.SetUnk04(unk_1D8);
        } else {
            unk_EC.ov0_02152AD0(this, unk_1D8, unk_1F8);
            sub_02032A44(9);
        }
        unk_1D4 = 0;
        unk_1F4 = 1;
        return;
    }
    if (unk_1F4 == 0) {
        Point2D p = GetPos() - unk_E4->GetPos();
        fx32 playerDist = FX32_MUL(p.x, p.x) + FX32_MUL(p.y, p.y);
        if (playerDist < dist && playerDist > 0x40000 && ov0_02136D50(&unk_1E0, 0, FALSE)) {
            unk_1D4 = 1;
            if (unk_EC.unk_44 == 9 || unk_EC.unk_44 == 6) {
                unk_EC.SetUnk04(unk_1E0);
                return;
            }
            unk_EC.ov0_02152AD0(this, unk_1E0, unk_1F8);
            sub_02032A44(9);
            return;
        }
    }
    unk_1F4 = 1;
    unk_1D4 = 0;
    if (unk_EC.unk_44 == 9 || unk_EC.unk_44 == 6) {
        unk_EC.SetUnk04(unk_1D8);
        return;
    }
    unk_EC.ov0_02152AD0(this, unk_1D8, unk_1F8);
    sub_02032A44(9);
}

void CFieldPartner::ov0_0213905C()
{
    unk_1E0 = MAIN_BSS_020B26A0.GetUnk0020();
    if (unk_EC.unk_40 != 0) {
        sub_0202E68C(unk_E4->unk_14);
        ov0_02138A7C();
        return;
    }
    if (unk_EC.unk_44 == 9 || unk_EC.unk_44 == 6) {
        unk_EC.SetUnk04(unk_1E0);
    } else {
        unk_EC.ov0_02152AD0(this, unk_1E0, unk_1F8);
        sub_02032A44(9);
    }
    unk_1D4 = 1;
}

void CFieldPartner::ov0_02139134()
{
    unk_204.count = 0;
    for (int i = 0; i < 6; i++) {
        unk_204.pos[i].x = unk_204.pos[i].y = -1;
        unk_204.partner[i].x = unk_204.partner[i].y = -1;
    }
}

void CFieldPartner::PushHistory(Point2D pos, Point2D partnerPos)
{
    Point2D tmp[6];
    MI_CpuCopyFast(unk_204.pos, tmp, sizeof(tmp));
    MI_CpuCopyFast(tmp, &unk_204.pos[1], sizeof(Point2D) * 5);
    MI_CpuCopyFast(unk_204.partner, tmp, sizeof(tmp));
    MI_CpuCopyFast(tmp, &unk_204.partner[1], sizeof(Point2D) * 5);
    unk_204.pos[0] = pos;
    unk_204.partner[0] = partnerPos;
    if (unk_204.count < 6) {
        unk_204.count++;
    }
}

void CFieldPartner::ov0_02139164()
{
    if (unk_6C == NULL) {
        return;
    }
    if (unk_6C->GetLayer(unk_14) == NULL) {
        return;
    }
    Point2D cell;
    Point2D pos;
    pos.x = GetPos().x >> FX32_SHIFT;
    pos.y = GetPos().y >> FX32_SHIFT;
    cell.x = ((pos.x & 8) ? 1 : 0) + (pos.x >> 4);
    cell.y = ((pos.y & 8) ? 1 : 0) + (pos.y >> 4);
    int lx = GetTrail(0).x >> FX32_SHIFT;
    int ly = GetTrail(0).y >> FX32_SHIFT;
    Point2D last;
    last.x = lx >> 4;
    last.y = ly >> 4;
    if (cell.x == last.x && cell.y == last.y) {
        return;
    }
    if (MATH_ABS(cell.x - last.x) > 1 || MATH_ABS(cell.y - last.y) > 1) {
        ov0_02139134();
    }
    Point2D partner;
    ov0_0213EA6C(&partner, cell, unk_14, 0);
    cell.x <<= 16;
    cell.y <<= 16;
    partner.x <<= 16;
    partner.y <<= 16;
    PushHistory(cell, partner);
}

void CFieldPartner::sub_0202D7E0()
{
    sub_02032A44(1);
    if (unk_08 != NULL && unk_08->unk_0C != NULL) {
        sub_02012A3C(unk_08->unk_0C, 0, 0x1000, 0x1000);
    }
    sub_show();
    sub_0201287C_();
    ResetUnk00C();
}
