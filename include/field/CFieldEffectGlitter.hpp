#ifndef POKERANGER2_FIELD_CFIELDEFFECTGLITTER_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTGLITTER_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CSimpleSpriteNTF.hpp"
#include "field/UnkClass_02151244.hpp"

class CFieldActor;

// A twinkling glint over an actor: a spinning sprite that blinks at random intervals.
class CFieldEffectGlitter : public CFieldEffect {
public:
    CFieldEffectGlitter();
    virtual ~CFieldEffectGlitter();
    virtual int GetEffectId();
    virtual int IsReady();
    virtual BOOL Start(int inTime, int holdTime, int outTime);
    virtual int Update(int step);
    virtual int Render(Camera2D *camera);
    virtual int SetParam(int param, int value);
    virtual void SetColor(u16 color);

    void SetTexture(UnkClass_02151244 *tex);
    int SetPolygonIDs(int base);

public:
    CFieldActor *m_actor;
    Point2D m_offset;
    int m_size;
    CSimpleSpriteNTF m_sprite;
    UnkClass_02151244 *m_tex;
    s8 m_blinkTimer;
    s8 m_idleTimer;
    u16 m_angle1;
    u16 m_angle2;
    u8 m_alpha;
};

STATIC_SIZE_ASSERT(CFieldEffectGlitter, 0x90);

class CFieldEffectGlitterFactory : public CFieldEffectFactory {
public:
    virtual ~CFieldEffectGlitterFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Reset();

    BOOL LoadTexture(int num);
    void ReleaseTextures();

public:
    UnkClass_02151244 m_tex;
};

STATIC_SIZE_ASSERT(CFieldEffectGlitterFactory, 0x30);

#endif // POKERANGER2_FIELD_CFIELDEFFECTGLITTER_HPP
