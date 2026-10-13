#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUFACTORY_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUFACTORY_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffectFactory.hpp"

class CFieldEffectManpuFactory : public CFieldEffectFactory {
public:
    CFieldEffectManpuFactory();
    virtual ~CFieldEffectManpuFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Update(int frames);
    virtual void Reset();
    virtual void Release(CFieldEffectManage *mgr);

public:
    u8 unk_04[0x21C0];
};

STATIC_SIZE_ASSERT(CFieldEffectManpuFactory, 0x21C4);

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUFACTORY_HPP
