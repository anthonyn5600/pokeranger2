#ifndef POKERANGER2_FIELD_CFIELDEFFECTCHARGE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTCHARGE_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"

// size 0xC0, ctor ov0_02146180
class CFieldEffectCharge : public CFieldEffectActor {
public:
    virtual ~CFieldEffectCharge();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142240(int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual void ov0_0214234C(Point2D pos, int arg1, int arg2, int arg3, int arg4);
    virtual int sub_0203312C(int param, int value);
};

class CFieldEffectChargeFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTCHARGE_HPP
