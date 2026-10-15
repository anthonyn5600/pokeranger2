#ifndef POKERANGER2_FIELDEFFECTFACTORYSET_HPP
#define POKERANGER2_FIELDEFFECTFACTORYSET_HPP

#include <nitro.h>

#include "common.hpp"

class CFieldEffectManage;
struct FieldEffectFactories;

// Owns the field effect factories (ov0)
class FieldEffectFactorySet {
public:
    FieldEffectFactorySet();

    ~FieldEffectFactorySet()
    {
        Release();
    }

    void Create(CFieldEffectManage *mgr);
    void Release();

public:
    FieldEffectFactories *unk_00;
};

STATIC_SIZE_ASSERT(FieldEffectFactorySet, 0x4);

#endif // POKERANGER2_FIELDEFFECTFACTORYSET_HPP
