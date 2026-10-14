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
        ov0_021518F4();
    }

    void ov0_021518B8(CFieldEffectManage *mgr);
    void ov0_021518F4();

public:
    FieldEffectFactories *unk_00;
};

STATIC_SIZE_ASSERT(FieldEffectFactorySet, 0x4);

#endif // POKERANGER2_FIELDEFFECTFACTORYSET_HPP
