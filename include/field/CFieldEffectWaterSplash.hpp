#ifndef POKERANGER2_FIELD_CFIELDEFFECTWATERSPLASH_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTWATERSPLASH_HPP

#include <nitro.h>

#include "UnkClass_0211E3FC.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"

class CFieldEffectWaterSplash : public CFieldEffect {
public:
    class CEffectDrawObject : public CDrawObject {
    public:
        virtual ~CEffectDrawObject();
        virtual int sub_020091D4(Camera2D *camera, int budget);
    };

    virtual ~CFieldEffectWaterSplash();
    virtual void ov0_021423A4();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual void ov0_02142398(UnkClass_0211E3FC *renderLists);
    virtual int sub_0203312C(int param, int value);
};

class CFieldEffectWaterSplashFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTWATERSPLASH_HPP
