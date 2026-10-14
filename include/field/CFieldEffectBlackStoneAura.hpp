#ifndef POKERANGER2_FIELD_CFIELDEFFECTBLACKSTONEAURA_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTBLACKSTONEAURA_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/UnkClass_02151244.hpp"

// size 0x1D0, ctor ov0_02171060
class CFieldEffectBlackStoneAura : public CFieldEffect {
public:
    virtual ~CFieldEffectBlackStoneAura();
    virtual int GetEffectId();
    virtual int IsReady();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int SetParam(int param, int value);
};

class CFieldEffectBlackStoneAuraFactory : public CFieldEffectFactory {
public:
    virtual ~CFieldEffectBlackStoneAuraFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Reset();

public:
    UnkClass_02151244 m_tex;
};

STATIC_SIZE_ASSERT(CFieldEffectBlackStoneAuraFactory, 0x30);

#endif // POKERANGER2_FIELD_CFIELDEFFECTBLACKSTONEAURA_HPP
