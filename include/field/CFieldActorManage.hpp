#ifndef POKERANGER2_FIELD_CFIELDACTORMANAGE_HPP
#define POKERANGER2_FIELD_CFIELDACTORMANAGE_HPP

#include <nitro.h>

#include "UnkClass_020B26A0.hpp"
#include "common.hpp"
#include "field/CFieldActor.hpp"

class UnkClass_02124CDC;
class UnkClass_0211E3FC;
class UnkClass_020416AC;

class CFieldActorManage {
public:
    CFieldActorManage();
    virtual ~CFieldActorManage();
    virtual void sub_0203EFE4(int capacity);
    virtual void sub_0203F034();
    virtual void sub_0203F0C0();
    virtual void sub_0203F144();
    virtual void sub_0203F190();
    virtual void sub_0203F2B0(UnkClass_02124CDC *map, BOOL update);
    virtual void sub_0203F1FC();
    virtual void sub_0203F278();
    virtual void sub_02040460();
    virtual void sub_02040428();
    virtual void sub_02040384();
    virtual void sub_0203F348(UnkClass_0211E3FC *renderLists, UnkClass_020416AC *hud);
    virtual void sub_0203F4B8();
    virtual void sub_0203F58C();
    virtual void sub_0203F604();
    virtual void sub_0203F688();
    virtual void sub_0203F700();
    virtual void sub_0203F754();
    virtual void sub_0203F7AC();

    inline CFieldActor *Get(int i)
    {
        if (m_count <= i) {
            return NULL;
        }
        return m_actors[i];
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

#endif // POKERANGER2_FIELD_CFIELDACTORMANAGE_HPP
