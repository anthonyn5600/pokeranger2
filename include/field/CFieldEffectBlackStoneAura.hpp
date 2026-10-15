#ifndef POKERANGER2_FIELD_CFIELDEFFECTBLACKSTONEAURA_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTBLACKSTONEAURA_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CSimpleSpriteNTF.hpp"
#include "field/UnkClass_02151244.hpp"

class CFieldActor;

// Rings pulsing out of a black stone: each ring grows and flickers between two alphas until its life runs out.
class CFieldEffectBlackStoneAura : public CFieldEffect {
public:
    struct Ring {
        s16 life;
        u16 frame;
        u8 order;
    };

    CFieldEffectBlackStoneAura(int mode);
    virtual ~CFieldEffectBlackStoneAura();
    virtual int GetEffectId();
    virtual int IsReady();
    virtual BOOL Start(int inTime, int holdTime, int outTime);
    virtual int Update(int step);
    virtual int Render(Camera2D *camera);
    virtual int SetParam(int param, int value);

    void SetTexture(UnkClass_02151244 *tex);
    void Spawn();

public:
    int m_mode;
    CFieldActor *m_actor;
    Point2D m_offset;
    CSimpleSpriteNTF m_sprites[4];
    s8 m_order[4];
    u8 m_next;
    UnkClass_02151244 *m_tex;
    Ring m_rings[4];
    s16 m_life;
    s16 m_spawnTimer;
    fx32 m_scaleFrom;
    fx32 m_scaleTo;
    u8 m_alphaFrom;
    u8 m_alphaTo;
    u16 m_period;
    u8 m_colorIdx;
};

STATIC_SIZE_ASSERT(CFieldEffectBlackStoneAura, 0x1D0);

class CFieldEffectBlackStoneAuraFactory : public CFieldEffectFactory {
public:
    virtual ~CFieldEffectBlackStoneAuraFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Reset();

    BOOL LoadTexture();
    void ReleaseTextures();

public:
    UnkClass_02151244 m_tex;
};

STATIC_SIZE_ASSERT(CFieldEffectBlackStoneAuraFactory, 0x30);

#endif // POKERANGER2_FIELD_CFIELDEFFECTBLACKSTONEAURA_HPP
