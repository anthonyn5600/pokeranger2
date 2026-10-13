#ifndef POKERANGER2_FIELD_CFIELDEFFECTLASER_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTLASER_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"

// size 0x13C, ctor ov0_0216D898
class CFieldEffectLaser : public CFieldEffectActor {
public:
    virtual ~CFieldEffectLaser();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
};

class CFieldEffectLaserFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTLASER_HPP
