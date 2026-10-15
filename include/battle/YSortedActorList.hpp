#ifndef POKERANGER2_BATTLE_YSORTEDACTORLIST_HPP
#define POKERANGER2_BATTLE_YSORTEDACTORLIST_HPP

#include <list>
#include <nitro.h>

#include "common.hpp"

class CActor;
class Camera2D;

// Defined in ov1
// Actors drawn in order of their y position
class YSortedActorList {
public:
    YSortedActorList();
    ~YSortedActorList(); // ov1_02137DBC
    BOOL Add(CActor *actor);
    void Clear();
    int Render(Camera2D *camera);

public:
    std::list<CActor *> m_actors;
    int m_z;
    u16 m_count;
};

STATIC_SIZE_ASSERT(YSortedActorList, 0x14);

#endif // POKERANGER2_BATTLE_YSORTEDACTORLIST_HPP
