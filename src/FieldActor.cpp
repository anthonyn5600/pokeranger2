#include <nitro.h>
#include <string.h>

#include "CGame.hpp"
#include "UnkClass_020416AC.hpp"
#include "UnkClass_02041D80.hpp"
#include "UnkClass_020B26A0.hpp"
#include "UnkClass_0211E3FC.hpp"
#include "common.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldActorManage.hpp"
#include "field/CFieldActorScript.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectBush.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "fx_utils.hpp"
#include "heap.hpp"

extern "C" {
void LogError(const char *fmt, ...);
}

extern CFieldActor *MAIN_BSS_0210CA48;
extern CFieldActorManage *MAIN_BSS_0210CA4C;
extern CFieldActorManage *MAIN_BSS_0210CA50;
extern CFieldActorManage *MAIN_BSS_0210CA5C;
extern CFieldActorManage *MAIN_BSS_0210CA7C;
extern CFieldEffectManage *MAIN_BSS_0210CA60;
extern UnkClass_02041C80 *MAIN_BSS_0210CA6C;
extern u32 MAIN_BSS_0210CA74;
extern UnkClass_020B26A0 MAIN_BSS_020B26A0;
extern u16 DAT_0208d58c;

CFieldActorScript::CFieldActorScript(int stackSize)
{
    unk_2C = NULL;
    unk_30 = NULL;
    unk_04 = 2;
    unk_30 = (u32 *)Heap_AllocWithAlignment(stackSize * 4, 4);
    unk_34 = stackSize;
}

CFieldActorScript::~CFieldActorScript()
{
    if (unk_30 != NULL) {
        Heap_Free(unk_30);
        unk_30 = NULL;
    }
}

BOOL CFieldActorScript::sub_0203BE48(CFieldActor *actor, const char *func)
{
    if (unk_2C != NULL) {
        sub_02044B48(&unk_08, unk_30, unk_34);
        if (actor != NULL) {
            *--unk_08.unk_04 = (u32)actor;
        }
        if (func != NULL) {
            if (sub_02045A18(&unk_08, unk_2C, func) == -1) {
                LogError("not found func FieldActor.cpp");
                return FALSE;
            }
        } else {
            LogError("null func name FieldActor.cpp");
            return FALSE;
        }
        unk_04 = 8;
    } else {
        LogError("m_pScriptBlock ==  NULL by FieldActor.cpp");
        return FALSE;
    }
    return TRUE;
}

BOOL CFieldActorScript::sub_0203BF00()
{
    sub_02044B84(&unk_08);
    unk_04 = 2;
    return TRUE;
}

void CFieldActorScript::sub_0203BF20()
{
    unk_04 = sub_02044C9C(&unk_08, 0xFFFFF);
}

CFieldActor::CFieldActor()
{
    unk_50 = -1;
    unk_DC = NULL;
    unk_0C = FALSE;
    unk_20 = 2;
    unk_78 = 0;
    unk_7C = 0;
    unk_7D = 0x10;
    unk_7E = 0;
    unk_94 = 0;
    unk_98 = 6;
    Point2D offset = { 0, -0x20000 };
    unk_70 = offset.x;
    unk_74 = offset.y;
    unk_C8 = 0;
    unk_54 = 0;
    unk_D0 = -1;
    unk_D8 = 0;
    sub_0203C310();
}

CFieldActor::~CFieldActor()
{
    sub_0203C560();
    SAFE_DELETE(unk_DC);
    if (unk_D8 != 0 && MAIN_BSS_0210CA60 != NULL) {
        MAIN_BSS_0210CA60->ov0_021430D8(unk_D8);
    }
    sub_02041C1C(this);
}

BOOL CFieldActor::sub_0203C1B4(void *script)
{
    if (unk_DC == NULL) {
        unk_DC = new CFieldActorScript(0x40);
        unk_DC->unk_2C = script;
    } else {
        unk_DC->unk_2C = script;
    }
    return TRUE;
}

BOOL CFieldActor::sub_0203C1FC(CFieldActorScript *script, void *block)
{
    if (unk_DC == NULL && script != NULL) {
        unk_DC = script;
        script->unk_2C = block;
    } else {
        unk_DC->unk_2C = block;
        return FALSE;
    }
    return TRUE;
}

BOOL CFieldActor::sub_0203C22C(const char *label)
{
    if (unk_DC != NULL && label != NULL) {
        if (unk_DC->sub_0203BE48(this, label)) {
            strcpy(unk_7F, label);
            return TRUE;
        }
        unk_7F[0] = '\0';
    }
    return FALSE;
}

BOOL CFieldActor::sub_0203C288()
{
    BOOL result = FALSE;
    unk_7F[0] = '\0';
    if (unk_DC != NULL) {
        result = unk_DC->sub_0203BF00();
    }
    return result;
}

void CFieldActor::sub_0203C2B8()
{
    if (unk_0C && unk_DC != NULL) {
        unk_DC->sub_0203BF20();
    }
}

BOOL CFieldActor::sub_0203C2D8()
{
    if (unk_DC == NULL || unk_7F[0] == '\0') {
        return FALSE;
    }
    unk_DC->sub_0203BE48(this, unk_7F);
    return TRUE;
}

void CFieldActor::sub_0203C310()
{
    unk_04 = 0;
    unk_08 = NULL;
    SetPosXY(0, 0);
    unk_18 = 0;
    unk_1C = 0;
    unk_10 = 0;
    sub_0202E68C(0);
    unk_5C = 0;
    unk_60 = 0;
    unk_64.x = -FX32_ONE;
    unk_64.y = -FX32_ONE;
    unk_6C = NULL;
    unk_7F[0] = '\0';
    unk_94 = 0;
    unk_9C = 0;
    unk_A0 = 0;
    unk_A4 = 0;
    unk_A8 = 0;
    unk_AC = 0;
    unk_AE = 0;
    unk_04 |= 8;
    unk_B4 = 0x109;
    unk_B8 = 0x18;
    unk_7D = 0x10;
    unk_7E = 0;
    unk_90 = 1;
    unk_BC = 0;
    unk_BD = 0;
    unk_BE = 0x10;
    unk_BF = 0xA;
    unk_D4 = 4;
    unk_D6 = -10;
}

BOOL CFieldActor::sub_0203C418(int arg0, u16 arg1, int arg2, u32 mask, int arg4)
{
    sub_0203C560();
    unk_08 = new CFieldDrawObject();
    BOOL result = unk_08->sub_02040530(arg0, arg1, arg2, mask, arg4);
    if (result) {
        for (int i = 0; i < 0x1D; i++) {
            if (mask & (1 << i)) {
                sub_0202DC54(1 << i, 0);
                break;
            }
        }
    }
    return result;
}

BOOL CFieldActor::sub_0203C4BC(int arg0, u16 arg1, int arg2, u32 mask, int arg4)
{
    sub_0203C560();
    unk_08 = new CFieldDrawObject();
    BOOL result = unk_08->sub_020405B4(arg0, arg1, arg2, mask, arg4);
    if (result) {
        for (int i = 0; i < 0x1D; i++) {
            if (mask & (1 << i)) {
                sub_0202DC54(1 << i, 0);
                break;
            }
        }
    }
    return result;
}

void CFieldActor::sub_0203C560()
{
    SAFE_DELETE(unk_08);
}

void CFieldActor::sub_0203C590(UnkClass_0211E3FC *renderLists, UnkClass_020416AC *hud)
{
    if (unk_04 & 1) {
        return;
    }

    if (renderLists != NULL && unk_08 != NULL) {
        unk_08->unk_04 = unk_08->GetY();
        if (unk_04 & 0x100) {
            if (!IsUnk04Bit12()) {
                renderLists[4].sub_0200912C(unk_08);
            } else {
                renderLists[9].sub_0200912C(unk_08);
            }
        } else {
            if (!IsUnk04Bit12()) {
                renderLists[unk_14].sub_0200912C(unk_08);
            } else {
                renderLists[unk_14 + 5].sub_0200912C(unk_08);
            }
        }
    }

    int height = GetHeight();
    if (unk_90 == 0 || hud == NULL) {
        return;
    }
    if (height < 0) {
        return;
    }
    if (height >= 0x60000) {
        return;
    }

    Rectangle rect = GetShadowRect();
    if (height > 0) {
        rect.size.x = FX32_MUL(rect.size.x, 0x60000 - height) / 0x60;
        rect.size.y = FX32_MUL(rect.size.y, 0x60000 - height) / 0x60;
    }
    if (unk_04 & 0x100) {
        sub_020419D8(hud, 4, rect);
    } else {
        sub_020419D8(hud, unk_14, rect);
    }
}

void CFieldActor::sub_0203C87C(CFieldMap *map)
{
    unk_6C = map;
    if (unk_08 == NULL) {
        return;
    }

    sub_0203D320();
    sub_0203D394();
    sub_0203CDB0();
    sub_0203CCD4();
    unk_08->sub_02040740();
    if (unk_54 != 0 && unk_08 != NULL && unk_08->unk_0C != NULL) {
        unk_08->unk_0C->sub_02012C4C();
    }

    int attr = 0;
    fx32 x = GetX();
    fx32 y = GetY();
    if (unk_6C != NULL) {
        CFieldMapLayerAttribute *layer = unk_6C->GetAttributeLayer(unk_14);
        if (layer != NULL) {
            attr = layer->GetCellAtPos(x, y);
        }
    }
    sub_0203D890(unk_C8 != 0 ? 0 : attr);

    if (unk_08->GetUnk1D8() != 1) {
        if ((u8)((int)unk_58 >> 24) != 0) {
            return;
        }
        if (GetUnkC0() != 7 && GetUnkC0() != 8) {
            return;
        }
        if (!IsAnimating()) {
            return;
        }
    }

    UnkStruct_02041D80 *info = NULL;
    if (MAIN_BSS_0210CA6C != NULL) {
        info = sub_02041D80(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.unk_001A);
    }
    if (info == NULL) {
        return;
    }
    if (!IsAnimating()) {
        return;
    }

    if (unk_78 != 0 && unk_7D != 0) {
        unk_7E += 60 / DAT_0208d58c;
        if (unk_7E >= unk_7D) {
            if (MAIN_BSS_0210CA60 != NULL) {
                MAIN_BSS_0210CA60->ov0_021431A4(attr, x, y, unk_14, info);
            }
            unk_7E = 0;
        }
    }

    if (unk_B8 <= 0) {
        return;
    }
    unk_7C += 60 / DAT_0208d58c;
    if (unk_7C < unk_B8) {
        return;
    }
    unk_7C = 0;
    if (unk_78 == 0) {
        return;
    }
    if (MAIN_BSS_0210CA74 & 1) {
        return;
    }

    int sound = unk_B4;
    if (sound < 0) {
        return;
    }
    if (sound == 0x109) {
        switch (attr) {
        case 0:
            sound = info->unk_08;
            break;
        case 1:
            sound = info->unk_0C;
            break;
        case 2:
            sound = info->unk_10;
            break;
        case 3:
            sound = info->unk_14;
            break;
        case 4:
            sound = info->unk_18;
            break;
        case 5:
            sound = info->unk_1C;
            break;
        case 6:
            sound = info->unk_20;
            break;
        case 7:
            sound = info->unk_24;
            break;
        case 8:
            sound = info->unk_28;
            break;
        case 9:
            sound = info->unk_2C;
            break;
        case 10:
            sound = info->unk_30;
            break;
        case 11:
            sound = info->unk_34;
            break;
        case 12:
            sound = info->unk_38;
            break;
        case 13:
            sound = info->unk_3C;
            break;
        case 14:
            sound = info->unk_40;
            break;
        case 15:
        case 16:
        case 17:
        case 18:
            sound = info->unk_44;
            break;
        case 19:
        case 20:
        case 21:
        case 22:
            sound = info->unk_48;
            break;
        }
    }
    if (sound < 0) {
        return;
    }
    s_game->m_audioEngine->sub_02034C44(sound);
}

void CFieldActor::sub_0203CCD4()
{
    if (unk_94 > 0) {
        unk_94--;
    }
    if (unk_08 == NULL) {
        return;
    }
    if (!(unk_04 & 8)) {
        return;
    }

    int state = unk_08->GetUnk1D8();
    if (unk_08->IsUnk00CSet()) {
        if (state != 1) {
            unk_7C = 0;
            unk_7E = 0;
            if (unk_94 <= 0) {
                unk_08->SetUnk1DC(1);
                unk_94 = unk_98;
            }
        }
        sub_0203D2F4();
        return;
    }

    if (state == 0) {
        return;
    }
    if (unk_94 > 0) {
        return;
    }
    unk_08->sub_show();
    unk_94 = unk_98;
}

void CFieldActor::sub_0203CDB0()
{
    CFieldActorManage *mgr = NULL;
    CFieldActor *target = NULL;
    int i;

    if (unk_5C != 1) {
        return;
    }

    u32 id = unk_60;
    switch ((u8)((int)id >> 24)) {
    case 0:
        target = MAIN_BSS_0210CA48;
        break;
    case 1:
        mgr = MAIN_BSS_0210CA5C;
        break;
    case 2:
        mgr = MAIN_BSS_0210CA50;
        break;
    case 4:
    case 5:
    case 6:
        mgr = MAIN_BSS_0210CA4C;
        break;
    }
    // Find() written out: with the inline, its counter is an inline temp and colors before the id (r3 instead
    // of lr); a named counter declared before the id gives the original's order.
    if (mgr != NULL) {
        for (i = 0; i < mgr->m_count; i++) {
            CFieldActor *actor = mgr->m_actors[i];
            if (actor != NULL && id == actor->unk_58) {
                target = actor;
                goto found;
            }
        }
        target = NULL;
    }
found:
    if (target != NULL) {
        Point2D pos = target->GetPos();
        LookAt(pos);
    } else {
        unk_5C = 0;
    }
}

BOOL CFieldActor::sub_0203CF40(const PointPair2D &move, fx32 radius, u32 flags)
{
    PointPair2D seg = move;
    Point2D hit;
    BOOL found = FALSE;

    if (!(flags & 0x10) && MAIN_BSS_0210CA7C != NULL) {
        if (MAIN_BSS_0210CA7C->sub_0203F7F4(&seg, radius, unk_14, &hit)) {
            seg.p2 = hit;
            found = TRUE;
        }
    }
    if (!(flags & 8) && MAIN_BSS_0210CA50 != NULL) {
        if (MAIN_BSS_0210CA50->sub_0203F7F4(&seg, radius, unk_14, &hit)) {
            seg.p2 = hit;
            found = TRUE;
        }
    }
    if (unk_6C != NULL) {
        CFieldMapLayerCollision *coll = unk_6C->GetLayer(unk_14);
        if (coll != NULL) {
            u32 kinds = 3;
            if (flags & 0x20) {
                kinds |= 4;
            }
            BOOL blocked;
            if (flags & 1) {
                blocked = coll->SweepFine(&seg, radius, &hit, kinds);
            } else {
                blocked = coll->Sweep(&seg, radius, &hit, kinds);
            }
            if (blocked) {
                seg.p2 = hit;
                found = TRUE;
            }
        }
        if (!(flags & 2) && (flags & 4)) {
            CFieldMapLayerAttribute *attr = unk_6C->GetAttributeLayer(unk_14);
            if (attr != NULL && attr->Sweep(&seg, radius, 0x804000, &hit)) {
                seg.p2 = hit;
                found = TRUE;
            }
        }
    }
    if (found) {
        unk_64 = seg.p2;
    }
    return found;
}

BOOL CFieldActor::sub_0203D110(Point2D pos, fx32 radius, u32 flags)
{
    if (!(flags & 0x10) && MAIN_BSS_0210CA7C != NULL) {
        if (MAIN_BSS_0210CA7C->sub_02040158(pos, radius, unk_14)) {
            return TRUE;
        }
    }
    if (!(flags & 8) && MAIN_BSS_0210CA50 != NULL) {
        if (MAIN_BSS_0210CA50->sub_02040158(pos, radius, unk_14)) {
            return TRUE;
        }
    }
    if (unk_6C != NULL) {
        CFieldMapLayerCollision *coll = unk_6C->GetLayer(unk_14);
        if (coll != NULL) {
            u32 kinds = 3;
            if (flags & 0x20) {
                kinds |= 4;
            }
            if (flags & 1) {
                if (coll->IsCircleBlockedFine(pos, radius, kinds)) {
                    return TRUE;
                }
            } else if (coll->IsCircleBlocked(pos, radius, kinds)) {
                return TRUE;
            }
        }
        if (flags & 4) {
            CFieldMapLayerAttribute *attr = unk_6C->GetAttributeLayer(unk_14);
            if (attr != NULL) {
                if (flags & 1) {
                    if (attr->IsCircleBlockedFine(pos, radius, 0x804000)) {
                        return TRUE;
                    }
                } else if (attr->IsCircleBlocked(pos, radius, 0x804000)) {
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

void CFieldActor::sub_0203D2F4()
{
    if (!(unk_04 & 2)) {
        return;
    }
    if (!(unk_04 & 4)) {
        return;
    }
    unk_A4 = unk_A0;
    unk_04 &= ~4;
}

void CFieldActor::sub_0203D320()
{
    if (!(unk_04 & 2)) {
        return;
    }
    unk_A4 -= unk_9C;
    int height = GetUnk8C();
    height += unk_A4;
    if (height < 0) {
        unk_04 |= 4;
        height = 0;
    }
    SetUnk8C(height);
}

void CFieldActor::sub_0203D394()
{
    if (!(unk_04 & 0x40)) {
        return;
    }
    fx32 height = unk_A8 + FX_Mul(FX_SinIdx(unk_AC), unk_B0 << FX32_SHIFT);
    unk_AC += unk_AE;
    SetUnk8C(height);
}

BOOL CFieldActor::sub_0203D404(Point2D dest)
{
    unk_C0 = dest;
    Point2D target = GetPos();
    if (GetX() <= unk_C0.x) {
        unk_C8 = 1;
        target.x = dest.x + 0x50000;
    } else {
        unk_C8 = 2;
        target.x = dest.x - 0x50000;
    }
    MoveTo(target, 0x2000);
    unk_CC = 0;
    if (unk_08 != NULL) {
        unk_54 = 1;
        if (unk_08->unk_0C != NULL) {
            unk_08->unk_0C->sub_02012B68(2, 8, 1, -2, 0, 0);
        }
    }
    return TRUE;
}

BOOL CFieldActor::sub_0203D578(CFieldMap *map)
{
    BOOL result = FALSE;

    switch (unk_C8) {
    case 1:
        if (!IsUnk00CSet() && !IsJumping()) {
            if (unk_CC == 0) {
                Point2D dest = GetPos();
                unk_CC = 1;
                dest.x += 0x78000;
                if (unk_08 != NULL) {
                    unk_08->Jump(0x1E000, 30);
                    unk_08->MoveLinear(dest, 30);
                }
                result = TRUE;
            } else {
                unk_54 = 0;
                StopGhost();
                unk_C8 = 0;
            }
        }
        break;
    case 2:
        if (!IsUnk00CSet() && !IsJumping()) {
            if (unk_CC == 0) {
                Point2D dest = GetPos();
                unk_CC = 1;
                dest.x -= 0x78000;
                if (unk_08 != NULL) {
                    unk_08->Jump(0x1E000, 30);
                    unk_08->MoveLinear(dest, 30);
                }
                result = TRUE;
            } else {
                unk_54 = 0;
                StopGhost();
                unk_C8 = 0;
            }
        }
        break;
    }

    sub_0203C87C(map);
    return result;
}

void CFieldActor::sub_0203D890(int attr)
{
    if (attr == 6 && GetHeight() == 0) {
        if (unk_D4 == 0) {
            return;
        }
        if (unk_D8 != 0) {
            return;
        }
        sub_0203D910();
    } else {
        if (unk_D8 == 0) {
            return;
        }
        sub_0203DA10();
    }
}

void CFieldActor::sub_0203D910()
{
    CFieldEffectManage *mgr = MAIN_BSS_0210CA60;
    if (mgr == NULL) {
        return;
    }

    unk_D8 = mgr->ov0_02142F6C(0x25, 0);
    if (unk_D8 == 0) {
        return;
    }
    CFieldEffect *effect = mgr->ov0_02143088(unk_D8);
    if (effect != NULL) {
        ((CFieldEffectBush *)effect)->Attach(this, mgr);
    }

    if (unk_D8 == 0 || unk_D4 == 0) {
        return;
    }
    if (unk_D4 == 1) {
        SetClipping(-0x100, -0x100, -0x100, -0x100);
        unk_90 = 0;
    } else {
        SetClipping(-0x100, 0x100, -0x100, unk_D6);
        unk_90 = 0;
    }
}

void CFieldActor::sub_0203DA10()
{
    if (unk_D8 != 0 && MAIN_BSS_0210CA60 != NULL) {
        MAIN_BSS_0210CA60->ov0_021430D8(unk_D8);
    }
}

BOOL CFieldActor::sub_0203DA38()
{
    return TRUE;
}

void CFieldActor::sub_0203DA40(CFieldMap *map)
{
    sub_0203C2B8();
    sub_0203C87C(map);
}

void CFieldActor::sub_0203DA60(u32 id)
{
    unk_58 = id;
}
