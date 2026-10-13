#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUASE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUASE_HPP

#include <nitro.h>

#include "field/CFieldEffectManpu.hpp"
#include "field/UnkClass_0216D420.hpp"

// size 0xCC
class CFieldEffectManpuAse : public CFieldEffectManpu {
public:
    CFieldEffectManpuAse(CEffectActorData *data, UnkClass_0216D420 *slots);
    virtual ~CFieldEffectManpuAse();
    virtual int ov0_02142264(int step);
    virtual int Draw(Camera2D *camera);
    virtual void SetDepth(fx32 z);

    u8 unk_2C[0xA0];
};

STATIC_SIZE_ASSERT(CFieldEffectManpuAse, 0xCC);

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUASE_HPP
