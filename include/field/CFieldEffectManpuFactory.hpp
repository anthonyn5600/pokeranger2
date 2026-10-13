#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUFACTORY_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUFACTORY_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CFieldManpuEffectActorData.hpp"
#include "field/UnkClass_0216D2D4.hpp"
#include "field/UnkClass_0216D420.hpp"

// Creates the Manpu effects (balloons over actors) and owns their actor data, heap and animation slot pools.
class CFieldEffectManpuFactory : public CFieldEffectFactory {
public:
    CFieldEffectManpuFactory();
    virtual ~CFieldEffectManpuFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Update(int frames);
    virtual void Reset();
    virtual void Release(CFieldEffectManage *mgr);

    void ov0_0215215C(int arg);

public:
    CFieldManpuEffectActorData m_data[8];
    UnkClass_0216D2D4 m_heap;
    UnkClass_0216D420 m_slots[3];
};

STATIC_SIZE_ASSERT(CFieldEffectManpuFactory, 0x21C4);

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUFACTORY_HPP
