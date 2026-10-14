#include "Collision.hpp"
#include "MathUtil.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldActorManage.hpp"
#include "field/CFieldDrawActor.hpp"

CFieldActorManage::CFieldActorManage()
{
    unk_0C = 0xFF;
    m_actors = NULL;
    m_count = 0;
}

CFieldActorManage::~CFieldActorManage()
{
    Free();
}

void CFieldActorManage::Alloc(int capacity)
{
    Free();
    m_count = capacity;
    m_actors = new CFieldActor *[capacity];
    for (int i = 0; i < capacity; i++) {
        m_actors[i] = NULL;
    }
}

void CFieldActorManage::Free()
{
    if (m_count > 0 && m_actors != NULL) {
        for (int i = 0; i < m_count; i++) {
            if (m_actors[i] != NULL) {
                SAFE_DELETE(m_actors[i]);
            }
        }
    }
    if (m_actors != NULL) {
        delete[] m_actors;
        m_actors = NULL;
    }
    m_count = 0;
}

BOOL CFieldActorManage::RemoveById(u32 id)
{
    if (m_count > 0 && m_actors != NULL) {
        for (int i = 0; i < m_count; i++) {
            CFieldActor *actor = m_actors[i];
            if (actor != NULL && id == actor->unk_58) {
                if (actor != NULL) {
                    SAFE_DELETE(m_actors[i]);
                }
                return TRUE;
            }
        }
    }
    return FALSE;
}

BOOL CFieldActorManage::Remove(int index)
{
    if (m_actors[index] != NULL) {
        if (m_actors[index] != NULL) {
            SAFE_DELETE(m_actors[index]);
        }
        return TRUE;
    }
    return FALSE;
}

BOOL CFieldActorManage::Clear()
{
    if (m_count > 0 && m_actors != NULL) {
        for (int i = m_count - 1; i >= 0; i--) {
            if (m_actors[i] != NULL) {
                SAFE_DELETE(m_actors[i]);
            }
        }
        return TRUE;
    }
    return FALSE;
}

BOOL CFieldActorManage::SetActorPos(int index, fx32 x, fx32 y)
{
    if (index < m_count && m_actors != NULL && m_actors[index] != NULL) {
        CFieldDrawObject *obj = m_actors[index]->unk_08;
        if (obj != NULL && obj->unk_0C != NULL) {
            obj->SetPosXY(x, y);
        }
        return TRUE;
    }
    return FALSE;
}

BOOL CFieldActorManage::sub_0203F278(int index, int arg1, int arg2)
{
    CFieldActor *actor;
    if (index < m_count && m_actors != NULL && (actor = m_actors[index]) != NULL) {
        actor->unk_18 = arg1;
        actor->unk_1C = arg2;
        return TRUE;
    }
    return FALSE;
}

void CFieldActorManage::UpdateAll(CFieldMap *map, BOOL update)
{
    if (m_actors == NULL) {
        return;
    }
    for (int i = 0; i < m_count; i++) {
        CFieldActor *actor = m_actors[i];
        if (actor != NULL && actor->IsActive()) {
            if (update) {
                actor->Process(map);
            } else {
                actor->UpdateMove(map);
            }
        }
    }
}

void CFieldActorManage::DrawAll(DrawObjectList *renderLists, FieldShadow *hud)
{
    if (m_actors == NULL) {
        return;
    }
    for (int i = 0; i < m_count; i++) {
        CFieldActor *actor = m_actors[i];
        if (actor != NULL && actor->IsActive()) {
            actor->Draw(renderLists, hud);
        }
    }
}

void sub_0203F3C8(CFieldActorManage *mgr)
{
    if (mgr->m_actors == NULL) {
        return;
    }
    for (int i = 0; i < mgr->m_count; i++) {
        CFieldActor *actor = mgr->m_actors[i];
        if (actor != NULL && actor->IsActive()) {
            actor->StopMotion();
        }
    }
}

void sub_0203F440(CFieldActorManage *mgr)
{
    if (mgr->m_actors == NULL) {
        return;
    }
    for (int i = 0; i < mgr->m_count; i++) {
        CFieldActor *actor = mgr->m_actors[i];
        if (actor != NULL && actor->IsActive()) {
            actor->RestartScriptLabel();
        }
    }
}

void CFieldActorManage::SetOutlineAll(u16 color, u8 width, int time)
{
    if (m_actors == NULL) {
        return;
    }
    for (int i = 0; i < m_count; i++) {
        CFieldActor *actor = m_actors[i];
        if (actor != NULL && actor->IsActive() && actor->unk_08 != NULL) {
            actor->unk_08->ResetOutlinePhase();
            actor->unk_08->SetOutlineColor(color);
            actor->unk_08->SetOutlineWidth(width);
            actor->unk_08->StartOutline(time);
        }
    }
}

void CFieldActorManage::SetOutlineWidthAll(u8 width)
{
    if (m_actors == NULL) {
        return;
    }
    for (int i = 0; i < m_count; i++) {
        if (m_actors[i] != NULL && m_actors[i]->IsActive()) {
            m_actors[i]->SetOutlineWidth(width);
        }
    }
}

void CFieldActorManage::SetOutlineColorAll(u16 color)
{
    if (m_actors == NULL) {
        return;
    }
    for (int i = 0; i < m_count; i++) {
        if (m_actors[i] != NULL && m_actors[i]->IsActive()) {
            m_actors[i]->SetOutlineColor(color);
        }
    }
}

void CFieldActorManage::SetAlphaAll(u8 alpha)
{
    if (m_actors == NULL) {
        return;
    }
    for (int i = 0; i < m_count; i++) {
        if (m_actors[i] != NULL && m_actors[i]->IsActive()) {
            m_actors[i]->SetOutlineAlpha(alpha);
        }
    }
}

void CFieldActorManage::sub_0203F700()
{
    if (m_actors == NULL) {
        return;
    }
    for (int i = 0; i < m_count; i++) {
        CFieldActor *actor = m_actors[i];
        if (actor != NULL && actor->unk_08 != NULL && actor->unk_08->unk_0C != NULL) {
            actor->unk_08->unk_0C->m_outlinePhase = 0;
        }
    }
}

void CFieldActorManage::sub_0203F754()
{
    if (m_actors == NULL) {
        return;
    }
    for (int i = 0; i < m_count; i++) {
        CFieldActor *actor = m_actors[i];
        if (actor != NULL) {
            actor->ClearUnk1A8Bits(1);
        }
    }
}

void CFieldActorManage::sub_0203F7AC()
{
    if (m_actors == NULL) {
        return;
    }
    for (int i = 0; i < m_count; i++) {
        CFieldActor *actor = m_actors[i];
        if (actor != NULL) {
            actor->unk_04 &= ~0x100;
        }
    }
}

struct ActorHit {
    CFieldActor *actor;
    fx32 dist;
    Point2D pos;
    ActorHit *next;
};

#define ADD_HIT()                                                           \
    {                                                                       \
        ActorHit *entry = &hits[count];                                     \
        entry->actor = actor;                                               \
        entry->pos = hit;                                                   \
        entry->dist = ApproxLength(hit.x - move->p1.x, hit.y - move->p1.y); \
        if (count == 0) {                                                   \
            head = entry;                                                   \
        } else {                                                            \
            ActorHit *prev = NULL;                                          \
            ActorHit *cur = head;                                           \
            while (cur != NULL) {                                           \
                if (entry->dist < cur->dist) {                              \
                    if (prev != NULL) {                                     \
                        prev->next = entry;                                 \
                    } else {                                                \
                        head = entry;                                       \
                    }                                                       \
                    entry->next = cur;                                      \
                    break;                                                  \
                }                                                           \
                prev = cur;                                                 \
                cur = cur->next;                                            \
            }                                                               \
            if (cur == NULL) {                                              \
                prev->next = entry;                                         \
            }                                                               \
        }                                                                   \
        count++;                                                            \
    }

BOOL CFieldActorManage::SweepCollide(PointPair2D *move, fx32 radius, int layer, Point2D *out)
{
    ActorHit hits[128];
    int count = 0;
    ActorHit *head = NULL;
    Point2D hit;

    MI_CpuClear32(hits, m_count * sizeof(ActorHit));
    for (int i = 0; i < m_count; i++) {
        CFieldActor *actor = m_actors[i];
        if (actor == NULL) {
            continue;
        }
        BOOL solid = (actor->unk_04 & 0x80) ? FALSE : TRUE;
        BOOL active = actor->IsActive();
        if (!(active & solid)) {
            continue;
        }
        if (layer != actor->unk_14) {
            continue;
        }
        switch (actor->unk_50) {
        case 0: {
            Rectangle rect = actor->unk_34;
            if (rect.size.x != 0 && rect.size.y != 0) {
                rect.pos.x += actor->GetX();
                rect.pos.y += actor->GetY();
                rect.size.x += radius * 2;
                rect.size.y += radius * 2;
                if (SegmentHitRect(*move, rect, &hit)) {
                    ADD_HIT();
                }
            }
            break;
        }
        case 1: {
            Circle shape = actor->unk_44;
            if (shape.r != 0) {
                shape.pos.x += actor->GetX();
                shape.pos.y += actor->GetY();
                shape.r += radius;
                if (SegmentHitCircle(*move, shape, &hit, 0)) {
                    ADD_HIT();
                }
            }
            break;
        }
        }
    }
    if (count != 0) {
        fx32 dx = move->p2.x - move->p1.x;
        if (dx < 0) {
            dx = -dx;
        }
        fx32 dy = move->p2.y - move->p1.y;
        if (dy < 0) {
            dy = -dy;
        }
        fx32 len = ApproxLength(dx, dy);
        fx32 step = 0;
        for (int k = 0; k < 4; k++) {
            step += radius >> (k + 1);
        }
        Circle circle;
        Point2D pos;
        for (ActorHit *entry = head; entry != NULL; entry = entry->next) {
            CFieldActor *actor = entry->actor;
            switch (actor->unk_50) {
            case 0: {
                Rectangle rect = actor->unk_34;
                rect.pos.x += actor->GetX();
                rect.pos.y += actor->GetY();
                circle = (Circle) { move->p1, radius };
                Point2D delta;
                delta = move->p2 - move->p1;
                if (len > 0) {
                    fx32 t = 0;
                    do {
                        fx64 f;
                        t += step;
                        circle.r = radius;
                        if (t < len) {
                            f = t;
                            f = FX32_DIV(f, len);
                            circle.pos = move->p1 + delta * f;
                        } else {
                            circle.pos = move->p2;
                        }
                        if (sub_02006E30(circle, rect, &pos, 4)) {
                            if (out != NULL) {
                                *out = sub_0200732C(&circle, &pos);
                            }
                            return TRUE;
                        }
                    } while (t < len);
                }
                break;
            }
            case 1: {
                Circle shape = actor->unk_44;
                shape.pos.x += actor->GetX();
                shape.pos.y += actor->GetY();
                circle = (Circle) { move->p1, radius };
                Point2D delta;
                delta = move->p2 - move->p1;
                if (len > 0) {
                    fx32 t = 0;
                    do {
                        Circle c;
                        fx64 f;
                        t += step;
                        c.r = radius;
                        if (t < len) {
                            f = t;
                            f = FX32_DIV(f, len);
                            c.pos = move->p1 + delta * f;
                        } else {
                            c.pos = move->p2;
                        }
                        if (CircleHitCircle(c, shape, &pos)) {
                            pos -= shape.pos;
                            fx32 l = ApproxLength(pos.x, pos.y);
                            pos.x = FX32_DIV(FX32_MUL(pos.x, shape.r), l);
                            pos.y = FX32_DIV(FX32_MUL(pos.y, shape.r), l);
                            pos += shape.pos;
                            if (out != NULL) {
                                *out = sub_0200732C(&c, &pos);
                            }
                            return TRUE;
                        }
                    } while (t < len);
                }
                break;
            }
            }
        }
    }
    return FALSE;
}

BOOL CFieldActorManage::CollideCircle(Point2D pos, fx32 radius, int layer)
{
    Circle circle = { pos, radius };
    for (int i = 0; i < m_count; i++) {
        CFieldActor *actor = m_actors[i];
        if (actor == NULL) {
            continue;
        }
        BOOL solid = (actor->unk_04 & 0x80) ? FALSE : TRUE;
        BOOL active = actor->IsActive();
        if (!(active & solid)) {
            continue;
        }
        if (layer != actor->unk_14) {
            continue;
        }
        switch (actor->unk_50) {
        case 0: {
            Rectangle rect = actor->unk_34;
            if (rect.size.x != 0 && rect.size.y != 0) {
                rect.pos.x += actor->GetX();
                rect.pos.y += actor->GetY();
                if (CircleHitRect(circle, rect)) {
                    return TRUE;
                }
            }
            break;
        }
        case 1: {
            Circle shape = actor->unk_44;
            if (shape.r != 0) {
                shape.pos.x += actor->GetX();
                shape.pos.y += actor->GetY();
                if (CircleHitCircle(circle, shape, NULL)) {
                    return TRUE;
                }
            }
            break;
        }
        }
    }
    return FALSE;
}

void CFieldActorManage::SetPosAll(Point2D pos)
{
    for (int i = 0; i < m_count; i++) {
        CFieldActor *actor = m_actors[i];
        if (actor != NULL && actor->unk_08 != NULL && actor->unk_08->unk_0C != NULL) {
            actor->unk_08->SetPos(pos);
        }
    }
}

void CFieldActorManage::sub_02040428()
{
    for (int i = 0; i < m_count; i++) {
        CFieldActor *actor = m_actors[i];
        if (actor != NULL) {
            actor->unk_20 = 2;
        }
    }
}

void CFieldActorManage::sub_02040460()
{
    for (int i = 0; i < m_count; i++) {
        CFieldActor *actor = m_actors[i];
        if (actor != NULL) {
            Actor_HideManpu(actor);
            actor->unk_20 = 0;
            actor->sub_0202D394();
        }
    }
}
