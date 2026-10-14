#ifndef POKERANGER2_FIELD_CFIELDEFFECTJUMON_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTJUMON_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "primitive/CSoftwareSprite.hpp"

// One ring of the seal (jumon) effect: a sprite circling m_pos at a radius that jumps to a random value every
// m_timerReset frames; m_trail keeps the last three positions (one sprite each).
struct JumonRing {
    u16 m_angle;
    u16 m_angleStep;
    u16 m_radius;
    u16 m_targetRadius;
    s16 m_timer;
    s16 m_timerReset;
    Point2D m_trail[3];
};

class CFieldEffectJumon : public CFieldEffect {
public:
    CFieldEffectJumon(int arg);
    virtual ~CFieldEffectJumon();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);

    void InitSprites();

public:
    Point2D m_pos;
    Point2D m_size;
    CSoftwareSprite m_sprites[3][3];
    JumonRing m_rings[3];
};
STATIC_SIZE_ASSERT(CFieldEffectJumon, 0x340);

class CFieldEffectJumonFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTJUMON_HPP
