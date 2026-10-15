#include <nitro.h>
#include <string.h>

#include "CGame.hpp"
#include "DrawObjectList.hpp"
#include "FieldDataRecords.hpp"
#include "FieldShadow.hpp"
#include "SaveData.hpp"
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
extern FieldData *MAIN_BSS_0210CA6C;
extern u32 MAIN_BSS_0210CA74;
extern SaveData MAIN_BSS_020B26A0;
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

BOOL CFieldActorScript::Call(CFieldActor *actor, const char *func)
{
    if (unk_2C != NULL) {
        ScriptVM_Init(&unk_08, unk_30, unk_34);
        if (actor != NULL) {
            *--unk_08.unk_04 = (u32)actor;
        }
        if (func != NULL) {
            if (ScriptVM_Start(&unk_08, unk_2C, func) == -1) {
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

BOOL CFieldActorScript::Stop()
{
    ScriptVM_Reset(&unk_08);
    unk_04 = 2;
    return TRUE;
}

void CFieldActorScript::Step()
{
    unk_04 = ScriptVM_Run(&unk_08, 0xFFFFF);
}

CFieldActor::CFieldActor()
{
    unk_50 = -1;
    m_script = NULL;
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
    m_bushEffect = 0;
    Reset();
}

CFieldActor::~CFieldActor()
{
    DeleteDrawObject();
    SAFE_DELETE(m_script);
    if (m_bushEffect != 0 && MAIN_BSS_0210CA60 != NULL) {
        MAIN_BSS_0210CA60->Remove(m_bushEffect);
    }
    Actor_HideManpu(this);
}

BOOL CFieldActor::SetScriptBlock(void *script)
{
    if (m_script == NULL) {
        m_script = new CFieldActorScript(0x40);
        m_script->unk_2C = script;
    } else {
        m_script->unk_2C = script;
    }
    return TRUE;
}

BOOL CFieldActor::SetScript(CFieldActorScript *script, void *block)
{
    if (m_script == NULL && script != NULL) {
        m_script = script;
        script->unk_2C = block;
    } else {
        m_script->unk_2C = block;
        return FALSE;
    }
    return TRUE;
}

BOOL CFieldActor::RunScriptLabel(const char *label)
{
    if (m_script != NULL && label != NULL) {
        if (m_script->Call(this, label)) {
            strcpy(unk_7F, label);
            return TRUE;
        }
        unk_7F[0] = '\0';
    }
    return FALSE;
}

BOOL CFieldActor::StopScript()
{
    BOOL result = FALSE;
    unk_7F[0] = '\0';
    if (m_script != NULL) {
        result = m_script->Stop();
    }
    return result;
}

void CFieldActor::UpdateScript()
{
    if (unk_0C && m_script != NULL) {
        m_script->Step();
    }
}

BOOL CFieldActor::RestartScriptLabel()
{
    if (m_script == NULL || unk_7F[0] == '\0') {
        return FALSE;
    }
    m_script->Call(this, unk_7F);
    return TRUE;
}

void CFieldActor::Reset()
{
    m_flags = 0;
    m_drawObject = NULL;
    SetPosXY(0, 0);
    unk_18 = 0;
    unk_1C = 0;
    unk_10 = 0;
    SetLayer(0);
    m_lookAt = 0;
    m_lookAtId = 0;
    unk_64.x = -FX32_ONE;
    unk_64.y = -FX32_ONE;
    m_map = NULL;
    unk_7F[0] = '\0';
    unk_94 = 0;
    m_gravity = 0;
    unk_A0 = 0;
    m_fallSpeed = 0;
    m_floatBase = 0;
    m_floatAngle = 0;
    m_floatSpeed = 0;
    m_flags |= 8;
    unk_B4 = 0x109;
    unk_B8 = 0x18;
    unk_7D = 0x10;
    unk_7E = 0;
    m_hasShadow = 1;
    unk_BC = 0;
    unk_BD = 0;
    unk_BE = 0x10;
    unk_BF = 0xA;
    m_bushMode = 4;
    unk_D6 = -10;
}

BOOL CFieldActor::CreateDrawObject(int arg0, u16 arg1, int arg2, u32 mask, int arg4)
{
    DeleteDrawObject();
    m_drawObject = new CFieldDrawObject();
    BOOL result = m_drawObject->CreateActor(arg0, arg1, arg2, mask, arg4);
    if (result) {
        for (int i = 0; i < 0x1D; i++) {
            if (mask & (1 << i)) {
                PlayAnim(1 << i, 0);
                break;
            }
        }
    }
    return result;
}

BOOL CFieldActor::CreateDrawObjectOwnData(int arg0, u16 arg1, int arg2, u32 mask, int arg4)
{
    DeleteDrawObject();
    m_drawObject = new CFieldDrawObject();
    BOOL result = m_drawObject->CreateActorOwnData(arg0, arg1, arg2, mask, arg4);
    if (result) {
        for (int i = 0; i < 0x1D; i++) {
            if (mask & (1 << i)) {
                PlayAnim(1 << i, 0);
                break;
            }
        }
    }
    return result;
}

void CFieldActor::DeleteDrawObject()
{
    SAFE_DELETE(m_drawObject);
}

void CFieldActor::Draw(DrawObjectList *renderLists, FieldShadow *hud)
{
    if (m_flags & 1) {
        return;
    }

    if (renderLists != NULL && m_drawObject != NULL) {
        m_drawObject->unk_04 = m_drawObject->GetY();
        if (m_flags & 0x100) {
            if (!IsUnk04Bit12()) {
                renderLists[4].Insert(m_drawObject);
            } else {
                renderLists[9].Insert(m_drawObject);
            }
        } else {
            if (!IsUnk04Bit12()) {
                renderLists[m_layer].Insert(m_drawObject);
            } else {
                renderLists[m_layer + 5].Insert(m_drawObject);
            }
        }
    }

    int height = GetHeight();
    if (m_hasShadow == 0 || hud == NULL) {
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
    if (m_flags & 0x100) {
        FieldShadow_Add(hud, 4, rect);
    } else {
        FieldShadow_Add(hud, m_layer, rect);
    }
}

void CFieldActor::Update(CFieldMap *map)
{
    m_map = map;
    if (m_drawObject == NULL) {
        return;
    }

    UpdateFall();
    UpdateFloat();
    UpdateLookAt();
    sub_0203CCD4();
    m_drawObject->sub_02040740();
    if (unk_54 != 0 && m_drawObject != NULL && m_drawObject->m_actor != NULL) {
        m_drawObject->m_actor->UpdateGhosts();
    }

    int attr = 0;
    fx32 x = GetX();
    fx32 y = GetY();
    if (m_map != NULL) {
        CFieldMapLayerAttribute *layer = m_map->GetAttributeLayer(m_layer);
        if (layer != NULL) {
            attr = layer->GetCellAtPos(x, y);
        }
    }
    UpdateBushEffect(unk_C8 != 0 ? 0 : attr);

    if (m_drawObject->GetUnk1D8() != 1) {
        if ((u8)((int)m_id >> 24) != 0) {
            return;
        }
        if (GetUnkC0() != 7 && GetUnkC0() != 8) {
            return;
        }
        if (!IsAnimating()) {
            return;
        }
    }

    FieldMapData *info = NULL;
    if (MAIN_BSS_0210CA6C != NULL) {
        info = FieldData_GetMap(MAIN_BSS_0210CA6C, MAIN_BSS_020B26A0.m_mapId);
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
                MAIN_BSS_0210CA60->EmitFootStep(attr, x, y, m_layer, info);
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
    s_game->m_audioEngine->PlaySe(sound);
}

void CFieldActor::sub_0203CCD4()
{
    if (unk_94 > 0) {
        unk_94--;
    }
    if (m_drawObject == NULL) {
        return;
    }
    if (!(m_flags & 8)) {
        return;
    }

    int state = m_drawObject->GetUnk1D8();
    if (m_drawObject->IsUnk00CSet()) {
        if (state != 1) {
            unk_7C = 0;
            unk_7E = 0;
            if (unk_94 <= 0) {
                m_drawObject->SetUnk1DC(1);
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
    m_drawObject->sub_show();
    unk_94 = unk_98;
}

void CFieldActor::UpdateLookAt()
{
    CFieldActorManage *mgr = NULL;
    CFieldActor *target = NULL;
    int i;

    if (m_lookAt != 1) {
        return;
    }

    u32 id = m_lookAtId;
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
            if (actor != NULL && id == actor->m_id) {
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
        m_lookAt = 0;
    }
}

BOOL CFieldActor::CheckSweepCollision(const PointPair2D &move, fx32 radius, u32 flags)
{
    PointPair2D seg = move;
    Point2D hit;
    BOOL found = FALSE;

    if (!(flags & 0x10) && MAIN_BSS_0210CA7C != NULL) {
        if (MAIN_BSS_0210CA7C->SweepCollide(&seg, radius, m_layer, &hit)) {
            seg.p2 = hit;
            found = TRUE;
        }
    }
    if (!(flags & 8) && MAIN_BSS_0210CA50 != NULL) {
        if (MAIN_BSS_0210CA50->SweepCollide(&seg, radius, m_layer, &hit)) {
            seg.p2 = hit;
            found = TRUE;
        }
    }
    if (m_map != NULL) {
        CFieldMapLayerCollision *coll = m_map->GetLayer(m_layer);
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
            CFieldMapLayerAttribute *attr = m_map->GetAttributeLayer(m_layer);
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

BOOL CFieldActor::CheckCircleCollision(Point2D pos, fx32 radius, u32 flags)
{
    if (!(flags & 0x10) && MAIN_BSS_0210CA7C != NULL) {
        if (MAIN_BSS_0210CA7C->CollideCircle(pos, radius, m_layer)) {
            return TRUE;
        }
    }
    if (!(flags & 8) && MAIN_BSS_0210CA50 != NULL) {
        if (MAIN_BSS_0210CA50->CollideCircle(pos, radius, m_layer)) {
            return TRUE;
        }
    }
    if (m_map != NULL) {
        CFieldMapLayerCollision *coll = m_map->GetLayer(m_layer);
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
            CFieldMapLayerAttribute *attr = m_map->GetAttributeLayer(m_layer);
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
    if (!(m_flags & 2)) {
        return;
    }
    if (!(m_flags & 4)) {
        return;
    }
    m_fallSpeed = unk_A0;
    m_flags &= ~4;
}

void CFieldActor::UpdateFall()
{
    if (!(m_flags & 2)) {
        return;
    }
    m_fallSpeed -= m_gravity;
    int height = GetBaseHeight();
    height += m_fallSpeed;
    if (height < 0) {
        m_flags |= 4;
        height = 0;
    }
    SetBaseHeight(height);
}

void CFieldActor::UpdateFloat()
{
    if (!(m_flags & 0x40)) {
        return;
    }
    fx32 height = m_floatBase + FX_Mul(FX_SinIdx(m_floatAngle), m_floatAmp << FX32_SHIFT);
    m_floatAngle += m_floatSpeed;
    SetBaseHeight(height);
}

BOOL CFieldActor::StartMoveTo(Point2D dest)
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
    if (m_drawObject != NULL) {
        unk_54 = 1;
        if (m_drawObject->m_actor != NULL) {
            m_drawObject->m_actor->StartGhosts(2, 8, 1, -2, 0, 0);
        }
    }
    return TRUE;
}

BOOL CFieldActor::UpdateMove(CFieldMap *map)
{
    BOOL result = FALSE;

    switch (unk_C8) {
    case 1:
        if (!IsUnk00CSet() && !IsJumping()) {
            if (unk_CC == 0) {
                Point2D dest = GetPos();
                unk_CC = 1;
                dest.x += 0x78000;
                if (m_drawObject != NULL) {
                    m_drawObject->Jump(0x1E000, 30);
                    m_drawObject->MoveLinear(dest, 30);
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
                if (m_drawObject != NULL) {
                    m_drawObject->Jump(0x1E000, 30);
                    m_drawObject->MoveLinear(dest, 30);
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

    Update(map);
    return result;
}

void CFieldActor::UpdateBushEffect(int attr)
{
    if (attr == 6 && GetHeight() == 0) {
        if (m_bushMode == 0) {
            return;
        }
        if (m_bushEffect != 0) {
            return;
        }
        StartBushEffect();
    } else {
        if (m_bushEffect == 0) {
            return;
        }
        StopBushEffect();
    }
}

void CFieldActor::StartBushEffect()
{
    CFieldEffectManage *mgr = MAIN_BSS_0210CA60;
    if (mgr == NULL) {
        return;
    }

    m_bushEffect = mgr->Create(0x25, 0);
    if (m_bushEffect == 0) {
        return;
    }
    CFieldEffect *effect = mgr->Get(m_bushEffect);
    if (effect != NULL) {
        ((CFieldEffectBush *)effect)->Attach(this, mgr);
    }

    if (m_bushEffect == 0 || m_bushMode == 0) {
        return;
    }
    if (m_bushMode == 1) {
        SetClipping(-0x100, -0x100, -0x100, -0x100);
        m_hasShadow = 0;
    } else {
        SetClipping(-0x100, 0x100, -0x100, unk_D6);
        m_hasShadow = 0;
    }
}

void CFieldActor::StopBushEffect()
{
    if (m_bushEffect != 0 && MAIN_BSS_0210CA60 != NULL) {
        MAIN_BSS_0210CA60->Remove(m_bushEffect);
    }
}

BOOL CFieldActor::Talk()
{
    return TRUE;
}

void CFieldActor::Process(CFieldMap *map)
{
    UpdateScript();
    Update(map);
}

void CFieldActor::SetId(u32 id)
{
    m_id = id;
}
