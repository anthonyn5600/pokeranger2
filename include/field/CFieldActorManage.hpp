#ifndef POKERANGER2_FIELD_CFIELDACTORMANAGE_HPP
#define POKERANGER2_FIELD_CFIELDACTORMANAGE_HPP

#include <nitro.h>

#include "UnkClass_020B26A0.hpp"
#include "common.hpp"
#include "field/CFieldActor.hpp"

class CFieldMap;
class UnkClass_0211E3FC;
class UnkClass_020416AC;

class CFieldActorManage {
public:
    CFieldActorManage();
    virtual ~CFieldActorManage();
    virtual void sub_0203EFE4(int capacity);
    virtual void sub_0203F034();
    virtual BOOL sub_0203F0C0(u32 id);
    virtual BOOL sub_0203F144(int index);
    virtual BOOL sub_0203F190();
    virtual void sub_0203F2B0(CFieldMap *map, BOOL update);
    virtual BOOL sub_0203F1FC(int index, fx32 x, fx32 y);
    virtual BOOL sub_0203F278(int index, int arg1, int arg2);
    virtual void sub_02040460();
    virtual void sub_02040428();
    virtual void sub_02040384(Point2D pos);
    virtual void sub_0203F348(UnkClass_0211E3FC *renderLists, UnkClass_020416AC *hud);
    virtual void sub_0203F4B8(u16 color, u8 width, int time);
    virtual void sub_0203F58C(u8 width);
    virtual void sub_0203F604(u16 color);
    virtual void sub_0203F688(u8 alpha);
    virtual void sub_0203F700();
    virtual void sub_0203F754();
    virtual void sub_0203F7AC();

    BOOL sub_0203F7F4(PointPair2D *move, fx32 radius, int layer, Point2D *out);
    BOOL sub_02040158(Point2D pos, fx32 radius, int layer);

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
            if (actor != NULL && (actor->unk_04 & 0x20)) {
                return actor;
            }
        }
        return NULL;
    }

    inline CFieldActor *Find(u32 id)
    {
        for (int i = 0; i < m_count; i++) {
            CFieldActor *actor = m_actors[i];
            if (actor != NULL && id == actor->unk_58) {
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
            if (actor != NULL && id == actor->unk_58) {
                return ((CFieldActor *const *)m_actors)[i];
            }
        }
        return NULL;
    }

    inline CFieldActor *Find(UnkClass_020B26A0 *save)
    {
        u32 id = save->unk_7C38;
        for (int i = 0; i < m_count; i++) {
            CFieldActor *actor = m_actors[i];
            if (actor != NULL && id == actor->unk_58) {
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

void sub_0203F3C8(CFieldActorManage *mgr);
void sub_0203F440(CFieldActorManage *mgr);

#endif // POKERANGER2_FIELD_CFIELDACTORMANAGE_HPP
