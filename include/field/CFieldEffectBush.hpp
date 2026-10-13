#ifndef POKERANGER2_FIELD_CFIELDEFFECTBUSH_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTBUSH_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"

class CFieldEffectBush : public CFieldEffect {
public:
    virtual ~CFieldEffectBush();
    virtual void ov0_021423A4();
    virtual int sub_02033028();
    virtual int ov0_02142344(Camera2D *camera);
};

class CFieldEffectBushFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTBUSH_HPP
