#ifndef POKERANGER2_FIELD_CFIELDEFFECTFIREWORKS_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTFIREWORKS_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"

// size 0x94, ctor ov0_02169670
class CFieldEffectFireworks : public CFieldEffect {
public:
    virtual ~CFieldEffectFireworks();
    virtual int sub_02033028();
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual void sub_02033440(u16 color);
};

class CFieldEffectFireworksFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTFIREWORKS_HPP
