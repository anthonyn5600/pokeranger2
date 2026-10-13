#ifndef POKERANGER2_FIELD_CFIELDEFFECTFACTORY_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTFACTORY_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"

class CFieldEffectManage;

// Creates one kind of effect for CFieldEffectManage (ov0).
class CFieldEffectFactory {
public:
    virtual ~CFieldEffectFactory()
    {
    }
    virtual CFieldEffect *Create(int arg) = 0;
    virtual void Update(int frames)
    {
    }
    virtual void Reset()
    {
    }
    virtual void Release(CFieldEffectManage *mgr)
    {
    }
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTFACTORY_HPP
