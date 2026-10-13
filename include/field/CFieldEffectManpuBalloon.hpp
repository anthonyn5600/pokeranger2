#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUBALLOON_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUBALLOON_HPP

#include <nitro.h>

#include "field/CFieldEffectManpu.hpp"

class CFieldEffectManpuBalloon : public CFieldEffectManpuSimple {
public:
    virtual ~CFieldEffectManpuBalloon();
    virtual int ov0_02142264(int step);
    virtual void SetType(int type);
    virtual int Draw(Camera2D *camera);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUBALLOON_HPP
