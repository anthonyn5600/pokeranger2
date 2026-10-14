#ifndef POKERANGER2_FIELD_CFIELDEFFECTDARKSHADOW_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTDARKSHADOW_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"

// size 0xA74, ctor ov0_02169A08
class CFieldEffectDarkShadow : public CFieldEffect {
public:
    virtual ~CFieldEffectDarkShadow();
    virtual int GetEffectId();
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int ov0_0214239C(int layer);
    virtual int SetParam(int param, int value);
    virtual void sub_0203331C(const Point2D &pos, int arg1);
    virtual void sub_02033388(const Point2D &pos, int arg1);
};

class CFieldEffectDarkShadowFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTDARKSHADOW_HPP
