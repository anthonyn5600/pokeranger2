#ifndef POKERANGER2_FIELD_CFIELDEFFECTBLACKSTONEAURA_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTBLACKSTONEAURA_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"

// size 0x1D0, ctor ov0_02171060
class CFieldEffectBlackStoneAura : public CFieldEffect {
public:
    virtual ~CFieldEffectBlackStoneAura();
    virtual int sub_02033028();
    virtual int sub_020332A4();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
};

class CFieldEffectBlackStoneAuraFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
    virtual void Reset();
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTBLACKSTONEAURA_HPP
