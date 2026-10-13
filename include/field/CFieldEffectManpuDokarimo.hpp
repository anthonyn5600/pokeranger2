#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUDOKARIMO_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUDOKARIMO_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectManage.hpp"

// size 0x94
class CFieldEffectManpuDokarimo : public CFieldEffectManpuAnime {
public:
    CFieldEffectManpuDokarimo(CFieldEffectManage::CResidentResource *res, UnkClass_0216D420 *slots, int cac, int type);
    virtual ~CFieldEffectManpuDokarimo();
    virtual void UpdatePos();

    u8 unk_84[0x10];
};

STATIC_SIZE_ASSERT(CFieldEffectManpuDokarimo, 0x94);

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUDOKARIMO_HPP
