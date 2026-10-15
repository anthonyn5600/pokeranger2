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
    virtual BOOL Start(int inTime, int holdTime, int outTime);
    virtual int Update(int step);
    virtual int Draw(Camera2D *camera);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUJUMPING_HPP
