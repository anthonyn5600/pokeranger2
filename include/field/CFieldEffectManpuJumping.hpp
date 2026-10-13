#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUJUMPING_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUJUMPING_HPP

#include <nitro.h>

#include "field/CFieldEffectManpu.hpp"

// Mark that jumps up out of the actor (factory kinds 0x26, 0x27).
class CFieldEffectManpuJumping : public CFieldEffectManpuSimple {
public:
    CFieldEffectManpuJumping(CEffectActorData *data)
        : CFieldEffectManpuSimple(data)
    {
        unk_28 = 1;
    }
    virtual ~CFieldEffectManpuJumping();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int Draw(Camera2D *camera);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUJUMPING_HPP
