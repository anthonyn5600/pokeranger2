#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUBALLOON_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUBALLOON_HPP

#include <nitro.h>

#include "field/CFieldEffectManpu.hpp"

// Balloon that pops up, sways and shrinks away (factory kinds 0x24, 0x25).
class CFieldEffectManpuBalloon : public CFieldEffectManpuSimple {
public:
    CFieldEffectManpuBalloon(CEffectActorData *data)
        : CFieldEffectManpuSimple(data)
    {
        m_frames = 0;
        unk_28 = 0;
    }
    virtual ~CFieldEffectManpuBalloon();
    virtual int Update(int step);
    virtual void SetType(int type);
    virtual int Draw(Camera2D *camera);

    int m_frames;
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUBALLOON_HPP
