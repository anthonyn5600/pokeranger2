#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUASE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUASE_HPP

#include <nitro.h>

#include "field/CFieldEffectManpu.hpp"
#include "field/UnkClass_0216D420.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Sweat drops (manpu) on both sides of an actor's head.
class CFieldEffectManpuAse : public CFieldEffectManpu {
public:
    CFieldEffectManpuAse(CEffectActorData *data, UnkClass_0216D420 *slots);
    virtual ~CFieldEffectManpuAse();
    virtual int ov0_02142264(int step);
    virtual int Draw(Camera2D *camera);
    virtual void SetDepth(fx32 z);

    void InitSprites();

    CSoftwareSprite m_sprites[2];
    u16 m_anims[2];
    UnkClass_0216D420 *m_slots;
};

STATIC_SIZE_ASSERT(CFieldEffectManpuAse, 0xCC);

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUASE_HPP
