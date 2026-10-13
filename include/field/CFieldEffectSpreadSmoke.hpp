#ifndef POKERANGER2_FIELD_CFIELDEFFECTSPREADSMOKE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSPREADSMOKE_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// size 0x94, ctor ov0_0215C75C
class CFieldEffectSpreadSmoke : public TFieldEffectParticle<CSoftwareSprite> {
public:
    virtual ~CFieldEffectSpreadSmoke();
    virtual int sub_02033028();
    virtual int sub_0203312C(int param, int value);
    virtual TFieldParticleForceField<CSoftwareSprite> *GetForceField();
    virtual TFieldParticleEmitter<CSoftwareSprite> *GetEmitter();
};

class CFieldEffectSpreadSmokeFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTSPREADSMOKE_HPP
