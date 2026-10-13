#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUPOS_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUPOS_HPP

#include <nitro.h>

#include "field/CFieldActor.hpp"

// Where a Manpu balloon sits over its actor.
static inline Point2D GetOffset(CFieldActor *actor)
{
    return *(Point2D *)&actor->unk_70;
}

static inline Point2D GetBalloonPos(CFieldActor *actor)
{
    Point2D pos = *(Point2D *)&actor->unk_70 + actor->GetPos();
    pos.y -= actor->GetHeight();
    return pos;
}

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUPOS_HPP
