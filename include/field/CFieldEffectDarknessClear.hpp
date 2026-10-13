#ifndef POKERANGER2_FIELD_CFIELDEFFECTDARKNESSCLEAR_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTDARKNESSCLEAR_HPP

#include <nitro.h>

#include "field/CFieldEffectFactory.hpp"
#include "field/CSimpleSpriteNTF.hpp"
#include "field/TFieldEffectParticle.hpp"
#include "field/TFieldParticle.hpp"

// Dark particles drifting off a 4x4 grid over the screen.
class CFieldEffectDarknessClear : public TFieldEffectParticle<CSimpleSpriteNTF> {
public:
    class CForceField : public TFieldParticleForceField<CSimpleSpriteNTF> {
    public:
        CForceField()
        {
            m_delay = 0;
        }
        virtual void Apply(TFieldParticle<CSimpleSpriteNTF> *p, int dt);

        fx32 m_delay;
    };

    class CEmitter : public TFieldParticleSmokeRectEmitter<CSimpleSpriteNTF> {
    public:
        CEmitter()
            : TFieldParticleSmokeRectEmitter<CSimpleSpriteNTF>(0)
        {
            m_polyCounter = 0;
            m_cell = 0;
        }
        virtual void Emit(TFieldParticle<CSimpleSpriteNTF> *p);

        u8 m_polyCounter;
        u8 m_cell;
    };

    CFieldEffectDarknessClear(int kind);
    virtual ~CFieldEffectDarknessClear();
    virtual int sub_02033028()
    {
        return 0x17;
    }
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual TFieldParticleForceField<CSimpleSpriteNTF> *GetForceField()
    {
        return &m_forceField;
    }
    virtual TFieldParticleEmitter<CSimpleSpriteNTF> *GetEmitter()
    {
        return &m_emitter;
    }

    void Load();

    CForceField m_forceField;
    CEmitter m_emitter;
    UnkClass_02041D98 m_texture;
    int unk_A8;
};
STATIC_SIZE_ASSERT(CFieldEffectDarknessClear, 0xAC);

// Same particles, gathered from fixed points and swirling around the centre.
class CFieldEffectDarknessClear2 : public TFieldEffectParticle<CSimpleSpriteNTF> {
public:
    class CForceField : public TFieldParticleForceField<CSimpleSpriteNTF> {
    public:
        CForceField()
        {
            m_delay = 0;
        }
        virtual void Apply(TFieldParticle<CSimpleSpriteNTF> *p, int dt);

        fx32 m_delay;
        Point2D m_center;
    };

    class CEmitter : public TFieldParticleSmokeRectEmitter<CSimpleSpriteNTF> {
    public:
        CEmitter()
            : TFieldParticleSmokeRectEmitter<CSimpleSpriteNTF>(0)
        {
            m_polyCounter = 0;
            unk_56 = 0;
            m_index = 0;
            m_emitted = 0;
        }
        virtual void Emit(TFieldParticle<CSimpleSpriteNTF> *p);

        u8 m_polyCounter;
        u8 unk_56;
        u8 m_index;
        u8 m_emitted;
    };

    CFieldEffectDarknessClear2(int kind);
    virtual ~CFieldEffectDarknessClear2();
    virtual int sub_02033028()
    {
        return 0x17;
    }
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual TFieldParticleForceField<CSimpleSpriteNTF> *GetForceField()
    {
        return &m_forceField;
    }
    virtual TFieldParticleEmitter<CSimpleSpriteNTF> *GetEmitter()
    {
        return &m_emitter;
    }

    void Load();

    CForceField m_forceField;
    CEmitter m_emitter;
    UnkClass_02041D98 m_texture;
    int unk_B4;
};
STATIC_SIZE_ASSERT(CFieldEffectDarknessClear2, 0xB8);

class CFieldEffectDarknessClearFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTDARKNESSCLEAR_HPP
