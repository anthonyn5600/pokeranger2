#ifndef POKERANGER2_FIELD_CFIELDEFFECTBUSH_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTBUSH_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"

class CFieldEffectBush : public CFieldEffect {
public:
    virtual ~CFieldEffectBush();
    virtual void ov0_021423A4();
    virtual int sub_02033028();
    virtual int ov0_02142344(Camera2D *camera);

public:
    u8 unk_18[0x5C];
};

STATIC_SIZE_ASSERT(CFieldEffectBush, 0x74);

class CFieldEffectBushFactory : public CFieldEffectFactory {
public:
    CFieldEffectBushFactory(CFieldEffectManage *mgr);
    virtual CFieldEffect *Create(int arg);

public:
    CFieldEffectBush m_bushes[16];
};

STATIC_SIZE_ASSERT(CFieldEffectBushFactory, 0x744);

#endif // POKERANGER2_FIELD_CFIELDEFFECTBUSH_HPP
