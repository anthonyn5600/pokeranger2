#ifndef POKERANGER2_FIELD_CFIELDEFFECTAIRBUBBLES_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTAIRBUBBLES_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Bubbles rising from a point (FieldEffectManage's m_airBubbles): Start() sets a burst of a few bubbles.
class CFieldEffectAirBubbles : public TFieldEffectParticle<CSoftwareSprite> {
public:
    class CBubbleEmitter : public TFieldParticleRectEmitter<CSoftwareSprite> {
    public:
        CBubbleEmitter()
        {
            m_count = 0;
            m_timer = 0;
        }
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);
        void Start(fx32 x, fx32 y, int count);

        Point2D m_origin;
        int m_count;
        int m_timer;
    };

    class CBubbleForceField : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);
    };

    CFieldEffectAirBubbles();
    virtual ~CFieldEffectAirBubbles();
    virtual int GetEffectId();
    virtual int SetParam(int param, int value);
    virtual TFieldParticleForceField<CSoftwareSprite> *GetForceField();
    virtual TFieldParticleEmitter<CSoftwareSprite> *GetEmitter();
    BOOL Emit(fx32 x, fx32 y);

    CBubbleForceField m_forceField;
    CBubbleEmitter m_emitter;
};

STATIC_SIZE_ASSERT(CFieldEffectAirBubbles, 0x6C);

#endif // POKERANGER2_FIELD_CFIELDEFFECTAIRBUBBLES_HPP
