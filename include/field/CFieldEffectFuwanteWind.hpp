#ifndef POKERANGER2_FIELD_CFIELDEFFECTFUWANTEWIND_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTFUWANTEWIND_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CellAnimController;

// Wind gusts drifting left or right (param 0x17 picks the side), swirling after half their life.
class CFieldEffectFuwanteWind : public TFieldEffectParticle<CSoftwareSprite> {
public:
    class CEmitter : public TFieldParticleSmokeRectEmitter<CSoftwareSprite> {
    public:
        CEmitter()
            : TFieldParticleSmokeRectEmitter<CSoftwareSprite>(0)
        {
        }
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);

        int m_dir;
    };

    // Fades the gusts out and swaps their cell by the phase in the particle's flags (animIdx >> 16).
    class CAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        CAnimator()
        {
            m_cac = NULL;
            m_cells = NULL;
        }
        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);

        CellAnimController *m_cac;
        u16 *m_cells;
    };

    CFieldEffectFuwanteWind();
    virtual ~CFieldEffectFuwanteWind();
    virtual int GetEffectId()
    {
        return 26;
    }
    virtual int Render(Camera2D *camera);
    virtual int SetParam(int param, int value);
    virtual TFieldParticleEmitter<CSoftwareSprite> *GetEmitter()
    {
        return &m_emitter;
    }
    virtual TFieldParticleForceField<CSoftwareSprite> *GetForceField()
    {
        return &m_animator;
    }

    CEmitter m_emitter;
    CAnimator m_animator;
};

STATIC_SIZE_ASSERT(CFieldEffectFuwanteWind, 0x90);

class CFieldEffectFuwanteWindFactory : public CFieldEffectFactory {
public:
    CFieldEffectFuwanteWindFactory()
    {
        m_cells = NULL;
    }
    virtual ~CFieldEffectFuwanteWindFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Update(int frames);
    virtual void Reset();
    BOOL Load();
    void Release();

public:
    CFieldEffectNormalActorData m_data;
    u16 *m_cells;
};

STATIC_SIZE_ASSERT(CFieldEffectFuwanteWindFactory, 0x3C);

#endif // POKERANGER2_FIELD_CFIELDEFFECTFUWANTEWIND_HPP
