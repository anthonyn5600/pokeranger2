#ifndef POKERANGER2_FIELD_CFIELDEFFECTRISINGPHOTON_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTRISINGPHOTON_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"

// size 0x88, ctor ov0_0216E128
class CFieldEffectRisingPhoton : public CFieldEffect {
public:
    virtual ~CFieldEffectRisingPhoton();
    virtual int sub_02033028();
    virtual int sub_020332A4();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual int sub_02033244(int arg0, int arg1, int arg2);
    virtual void sub_02033440(u16 color);
};

class CFieldEffectRisingPhotonFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTRISINGPHOTON_HPP
