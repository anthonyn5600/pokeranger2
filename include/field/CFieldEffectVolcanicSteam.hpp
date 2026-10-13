#ifndef POKERANGER2_FIELD_CFIELDEFFECTVOLCANICSTEAM_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTVOLCANICSTEAM_HPP

#include <nitro.h>

#include "UnkClass_0211E3FC.hpp"
#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CSimpleSpriteNTF.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"
#include "field/UnkClass_02151244.hpp"

// size 0x90, ctor ov0_0216EB4C
class CFieldEffectVolcanicSteam : public TFieldEffectSmoke<CSimpleSpriteNTF> {
public:
    class CAnimator : public TFieldParticleForceField<CSimpleSpriteNTF> {
    public:
        class CEffectDrawObject : public CDrawObject {
        public:
            virtual ~CEffectDrawObject();
            virtual int sub_020091D4(Camera2D *camera, int budget);
        };

        virtual ~CAnimator();
        virtual void Apply(TFieldParticle<CSimpleSpriteNTF> *p, int dt);
    };

    virtual ~CFieldEffectVolcanicSteam();
    virtual int sub_02033028();
    virtual int ov0_02142344(Camera2D *camera);
    virtual void ov0_02142398(UnkClass_0211E3FC *renderLists);
    virtual int sub_0203312C(int param, int value);
    virtual TFieldParticleForceField<CSimpleSpriteNTF> *GetForceField();
};

class CFieldEffectVolcanicSteamFactory : public CFieldEffectFactory {
public:
    virtual ~CFieldEffectVolcanicSteamFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Reset();

public:
    UnkClass_02151244 m_tex;
};

STATIC_SIZE_ASSERT(CFieldEffectVolcanicSteamFactory, 0x30);

#endif // POKERANGER2_FIELD_CFIELDEFFECTVOLCANICSTEAM_HPP
