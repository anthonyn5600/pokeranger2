#ifndef POKERANGER2_FIELD_CFIELDACTORMANAGE_HPP
#define POKERANGER2_FIELD_CFIELDACTORMANAGE_HPP

#include <nitro.h>

#include "SaveData.hpp"
#include "common.hpp"
#include "field/CFieldActor.hpp"

class CFieldMap;
class DrawObjectList;
class FieldShadow;

class CFieldActorManage {
public:
    CFieldActorManage();
    virtual ~CFieldActorManage();
    virtual void Alloc(int capacity);
    virtual void Free();
    virtual BOOL RemoveById(u32 id);
    virtual BOOL Remove(int index);
    virtual BOOL Clear();
    virtual void UpdateAll(CFieldMap *map, BOOL update);
    virtual BOOL SetActorPos(int index, fx32 x, fx32 y);
    virtual BOOL sub_0203F278(int index, int arg1, int arg2);
    virtual void DeactivateAll();
    virtual void ActivateAll();
    virtual void SetPosAll(Point2D pos);
    virtual void DrawAll(DrawObjectList *renderLists, FieldShadow *hud);
    virtual void SetOutlineAll(u16 color, u8 width, int time);
    virtual void SetOutlineWidthAll(u8 width);
    virtual void SetOutlineColorAll(u16 color);
    virtual void SetAlphaAll(u8 alpha);
    virtual void ResetOutlinePhases();
    virtual void ClearOutlines();
    virtual void ClearOnTop();

    BOOL SweepCollide(PointPair2D *move, fx32 radius, int layer, Point2D *out);
    BOOL CollideCircle(Point2D pos, fx32 radius, int layer);

    inline CFieldActor *Get(int i)
    {
        if (m_count <= i) {
            return NULL;
        }
        return m_actors[i];
    }

    inline BOOL Set(int i, CFieldActor *actor)
    {
        if (i >= 0 && i < m_count) {
            m_actors[i] = actor;
            return TRUE;
        }
        return FALSE;
    }

    inline int CountActors()
    {
        int count = 0;
        for (int i = 0; i < m_count; i++) {
            if (m_actors[i] != NULL) {
                count++;
            }
        }
        return count;
    }

    inline CFieldActor *FindLeader()
    {
        int count = m_count;
        for (int i = 0; i < count; i++) {
            CFieldActor *actor = count <= i ? NULL : m_actors[i];
            if (actor != NULL && (actor->m_flags & 0x20)) {
                return actor;
            }
        }
        return NULL;
    }

    inline CFieldActor *Find(u32 id)
    {
        for (int i = 0; i < m_count; i++) {
            CFieldActor *actor = m_actors[i];
            if (actor != NULL && id == actor->m_id) {
                return actor;
            }
        }
        return NULL;
    }

    // Find, but the match is read again for the result. Through a CFieldActor *const view, or mwcc reuses the
    // first read.
    inline CFieldActor *FindTarget(u32 id)
    {
        int count = m_count;
        for (int i = 0; i < count; i++) {
            CFieldActor *actor = m_actors[i];
            if (actor != NULL && id == actor->m_id) {
                return ((CFieldActor *const *)m_actors)[i];
            }
        }
        return NULL;
    }

    inline CFieldActor *Find(SaveData *save)
    {
        u32 id = save->m_selectedPartyId;
        for (int i = 0; i < m_count; i++) {
            CFieldActor *actor = m_actors[i];
            if (actor != NULL && id == actor->m_id) {
                return actor;
            }
        }
        return NULL;
    }

public:
    int m_count;
    CFieldActor **m_actors;
    u8 unk_0C;
};

STATIC_SIZE_ASSERT(CFieldActorManage, 0x10);

void FieldActorManage_StopAllMotion(CFieldActorManage *mgr);
void FieldActorManage_RestartAllScripts(CFieldActorManage *mgr);

#endif // POKERANGER2_FIELD_CFIELDACTORMANAGE_HPP
