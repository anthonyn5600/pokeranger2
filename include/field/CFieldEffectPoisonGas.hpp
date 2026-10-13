#ifndef POKERANGER2_FIELD_CFIELDEFFECTPOISONGAS_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTPOISONGAS_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"

class CFieldEffectPoisonGas : public CFieldEffectActor {
public:
    virtual ~CFieldEffectPoisonGas();
    virtual void ov0_021423A4();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual int ov0_02142390(void *buf, void *end);
    virtual BOOL ov0_02142388(const void *data);
};

class CFieldEffectPoisonGasFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
    virtual void Update(int frames);
    virtual void Reset();
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTPOISONGAS_HPP
