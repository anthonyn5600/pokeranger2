#ifndef POKERANGER2_FIELD_CFIELDEFFECTFLASH_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTFLASH_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"

// size 0x80, ctor ov0_021466B0
class CFieldEffectFlash : public CFieldEffectActor {
public:
    virtual ~CFieldEffectFlash();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142240(int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual void ov0_0214234C(Point2D pos, int arg1, int arg2, int arg3, int arg4);
    virtual int sub_0203312C(int param, int value);
};

class CFieldEffectFlashFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTFLASH_HPP
