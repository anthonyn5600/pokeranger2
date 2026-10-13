#ifndef POKERANGER2_FIELD_CFIELDEFFECTPARABOLABULLET_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTPARABOLABULLET_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"

// size 0xE0, ctor ov0_0215E334
class CFieldEffectParabolaBullet : public CFieldEffectActor {
public:
    virtual ~CFieldEffectParabolaBullet();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
};

class CFieldEffectParabolaBulletFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTPARABOLABULLET_HPP
