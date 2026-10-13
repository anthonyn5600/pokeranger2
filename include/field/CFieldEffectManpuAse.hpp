#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUASE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUASE_HPP

#include <nitro.h>

#include "field/CFieldEffectManpu.hpp"

// size 0xCC, ctor ov0_021644B0
class CFieldEffectManpuAse : public CFieldEffectManpu {
public:
    virtual ~CFieldEffectManpuAse();
    virtual int ov0_02142264(int step);
    virtual int Draw(Camera2D *camera);
    virtual void SetDepth(fx32 z);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUASE_HPP
