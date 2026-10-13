#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUFACTORY_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUFACTORY_HPP

#include <nitro.h>

#include "field/CFieldEffectFactory.hpp"

class CFieldEffectManpuFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
    virtual void Update(int frames);
    virtual void Reset();
    virtual void Release(CFieldEffectManage *mgr);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUFACTORY_HPP
