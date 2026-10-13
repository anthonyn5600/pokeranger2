#ifndef POKERANGER2_FIELD_CFIELDEFFECTBLOOM_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTBLOOM_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/UnkClass_02151244.hpp"

// size 0x1D0, ctor ov0_021667E4
class CFieldEffectBloom : public CFieldEffect {
public:
    virtual ~CFieldEffectBloom();
    virtual int sub_02033028();
    virtual int sub_020332A4();
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual void sub_02033440(u16 color);
    virtual void sub_020333D8(int arg0, int arg1);
};

class CFieldEffectBloomFactory : public CFieldEffectFactory {
public:
    CFieldEffectBloomFactory()
    {
    }
    virtual ~CFieldEffectBloomFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Reset();

public:
    UnkClass_02151244 m_tex[3];
};

STATIC_SIZE_ASSERT(CFieldEffectBloomFactory, 0x88);

#endif // POKERANGER2_FIELD_CFIELDEFFECTBLOOM_HPP
