#ifndef POKERANGER2_FIELD_CFIELDEFFECTSTEAM_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSTEAM_HPP

#include <nitro.h>

// CFieldEffect.hpp comes through TFieldEffectParticle.hpp: completing CFieldEffect before CFieldEffectFactory swaps
// two typeinfos in this TU's data.
#include "field/CFieldEffectFactory.hpp"
#include "field/CFieldParticleSmokeAnimator.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CFieldEffectSteam : public TFieldEffectSmoke<CSoftwareSprite> {
public:
    CFieldEffectSteam(int kind);
    virtual ~CFieldEffectSteam()
    {
    }
    virtual int GetEffectId()
    {
        return 9;
    }
    virtual int SetParam(int param, int value);
    virtual TFieldParticleForceField<CSoftwareSprite> *GetForceField()
    {
        return &m_animator;
    }

    CFieldParticleSmokeAnimator m_animator;
};
STATIC_SIZE_ASSERT(CFieldEffectSteam, 0x94);

class CFieldEffectSteamFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTSTEAM_HPP
