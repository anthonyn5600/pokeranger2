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
    BOOL ov1_02137DF8(CActor *actor);
    void ov1_02137EE8();
    int ov1_02137F28(Camera2D *camera);

public:
    std::list<CActor *> m_actors;
    int m_z;
    u16 m_count;
};

STATIC_SIZE_ASSERT(YSortedActorList, 0x14);

#endif // POKERANGER2_BATTLE_YSORTEDACTORLIST_HPP
