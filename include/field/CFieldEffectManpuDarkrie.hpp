#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUDARKRIE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUDARKRIE_HPP

#include <nitro.h>

#include "field/AnimSlotPool.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldEffectManpu.hpp"

// size 0x1D4
class CFieldEffectManpuDarkrie : public CFieldEffectManpu {
public:
    CFieldEffectManpuDarkrie(CFieldEffectManage::CResidentResource *res, AnimSlotPool *slots, int cac, int type);
    virtual ~CFieldEffectManpuDarkrie();
    virtual int ov0_02142264(int step);
    virtual int Draw(Camera2D *camera);
    virtual void SetDepth(fx32 z);

    u8 unk_2C[0x1A8];
};

STATIC_SIZE_ASSERT(CFieldEffectManpuDarkrie, 0x1D4);

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUDARKRIE_HPP
