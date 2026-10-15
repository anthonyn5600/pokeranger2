#ifndef POKERANGER2_FIELD_CFIELDEFFECTVOLCANICSTEAM_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTVOLCANICSTEAM_HPP

#include <nitro.h>

// clang-format off
// CFieldEffectFactory.hpp before CFieldEffect.hpp: the factory classes complete first (typeinfo order).
#include "field/CFieldEffectFactory.hpp"
#include "DrawObjectList.hpp"
#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CSimpleSpriteNTF.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"
#include "field/UnkClass_02151244.hpp"
// clang-format on

// Volcano steam (ov0): NTF smoke whose particles grow and fade in, drawn through a render-list object.
class CFieldEffectVolcanicSteam : public TFieldEffectSmoke<CSimpleSpriteNTF> {
public:
    class CAnimator : public TFieldParticleForceField<CSimpleSpriteNTF> {
    public:
        // Hands the render list's depth to the particle system.
        class CEffectDrawObject : public CDrawObject {
        public:
            CEffectDrawObject()
            {
                m_depth = 0;
                m_system = NULL;
            }
            virtual int Draw(Camera2D *camera, int budget);

        public:
            int m_depth;
            TFieldParticleSystem<CSimpleSpriteNTF> *m_system;
        };

        virtual void Apply(TFieldParticle<CSimpleSpriteNTF> *p, int dt);
        void Register(DrawObjectList *renderLists);

    public:
        CEffectDrawObject m_drawObj;
    };

    CFieldEffectVolcanicSteam();
    virtual ~CFieldEffectVolcanicSteam();
    virtual int GetEffectId()
    {
        return 25;
    }
    virtual int ov0_02142344(Camera2D *camera);
    virtual void ov0_02142398(DrawObjectList *renderLists);
    virtual int SetParam(int param, int value);
    virtual TFieldParticleForceField<CSimpleSpriteNTF> *GetForceField()
    {
        return &m_animator;
    }

public:
    CAnimator m_animator;
};

STATIC_SIZE_ASSERT(CFieldEffectVolcanicSteam, 0x90);

class CFieldEffectVolcanicSteamFactory : public CFieldEffectFactory {
public:
    virtual ~CFieldEffectVolcanicSteamFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Reset();

    BOOL Load();
    void Release();

public:
    UnkClass_02151244 m_tex;
};

STATIC_SIZE_ASSERT(CFieldEffectVolcanicSteamFactory, 0x30);

#endif // POKERANGER2_FIELD_CFIELDEFFECTVOLCANICSTEAM_HPP
