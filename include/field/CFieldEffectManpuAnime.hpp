#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUANIME_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUANIME_HPP

#include <nitro.h>

#include "field/AnimSlotPool.hpp"
#include "field/CFieldEffectManpu.hpp"

// Manpu whose cell animation runs on a slot taken from a shared pool.
class CFieldEffectManpuAnime : public CFieldEffectManpuSimple {
public:
    CFieldEffectManpuAnime(CEffectActorData *data, AnimSlotPool *slots, int type);
    virtual ~CFieldEffectManpuAnime();
    virtual int Update(int step);
    virtual int Draw(Camera2D *camera);
    virtual void UpdatePos(int step);

    u16 m_anim;
    AnimSlotPool *m_slots;
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUANIME_HPP
