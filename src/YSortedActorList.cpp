#include "battle/YSortedActorList.hpp"

#include <list>

#include "CActor.hpp"
#include "Camera2D.hpp"

YSortedActorList::YSortedActorList()
{
}

YSortedActorList::~YSortedActorList()
{
}

BOOL YSortedActorList::ov1_02137DF8(CActor *actor)
{
    if (actor == NULL) {
        return FALSE;
    }
    if (m_actors.empty()) {
        m_actors.push_back(actor);
    } else {
        BOOL inserted = FALSE;
        // if + do-while, not a for loop: IRO then leaves end() in the loop and end gets r1
        std::list<CActor *>::iterator it = m_actors.begin();
        if (it != m_actors.end()) {
            do {
                if (actor->m_motion.m_pos.y < (*it)->m_motion.m_pos.y) {
                    m_actors.insert(it, actor);
                    inserted = TRUE;
                    break;
                }
                ++it;
            } while (it != m_actors.end());
        }
        if (!inserted) {
            m_actors.push_back(actor);
        }
    }
    m_count++;
    return TRUE;
}

void YSortedActorList::ov1_02137EE8()
{
    m_actors.clear();
    m_count = 0;
}

int YSortedActorList::ov1_02137F28(Camera2D *camera)
{
    int z = m_z;
    for (std::list<CActor *>::iterator it = m_actors.begin(); it != m_actors.end(); ++it) {
        z += *(u16 *)(*it)->unk_06;
        (*it)->m_sprite->m_z = z;
        (*it)->vfunc_0C(camera);
    }
    return z + 1;
}
