#ifndef POKERANGER2_FIELD_CFIELDEFFECTJUMON_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTJUMON_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"

// size 0x340, ctor ov0_021618C0
class CFieldEffectJumon : public CFieldEffect {
public:
    virtual ~CFieldEffectJumon();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
};

class CFieldEffectJumonFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTJUMON_HPP
