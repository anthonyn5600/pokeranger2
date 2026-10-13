#ifndef POKERANGER2_FIELD_CFIELDEFFECTAIRBUBBLES_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTAIRBUBBLES_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CFieldEffectAirBubbles : public TFieldEffectParticle<CSoftwareSprite> {
public:
    CFieldEffectAirBubbles();
    class CBubbleEmitter : public TFieldParticleRectEmitter<CSoftwareSprite> {
    public:
        virtual ~CBubbleEmitter();
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);
    };

    class CBubbleForceField : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual ~CBubbleForceField();
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    virtual ~CFieldEffectAirBubbles();
    virtual int sub_02033028();
    virtual int sub_0203312C(int param, int value);
    virtual TFieldParticleForceField<CSoftwareSprite> *GetForceField();
    virtual TFieldParticleEmitter<CSoftwareSprite> *GetEmitter();
    void ov0_0216D050(fx32 x, fx32 y);

    u8 unk_28[0x44];
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTAIRBUBBLES_HPP
