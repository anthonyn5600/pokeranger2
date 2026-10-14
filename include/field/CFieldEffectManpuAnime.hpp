#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUANIME_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUANIME_HPP

#include <nitro.h>

#include "field/CFieldEffectManpu.hpp"
#include "field/UnkClass_0216D420.hpp"

// Manpu whose cell animation runs on a slot taken from a shared pool.
class CFieldEffectManpuAnime : public CFieldEffectManpuSimple {
public:
    CFieldEffectManpuAnime(CEffectActorData *data, UnkClass_0216D420 *slots, int type);
    virtual ~CFieldEffectManpuAnime();
    virtual int ov0_02142264(int step);
    virtual int Draw(Camera2D *camera);
    virtual void UpdatePos(int step);

    u16 m_anim;
    UnkClass_0216D420 *m_slots;
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUANIME_HPP
