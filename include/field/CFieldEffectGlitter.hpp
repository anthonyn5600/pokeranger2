#ifndef POKERANGER2_FIELD_CFIELDEFFECTGLITTER_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTGLITTER_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/UnkClass_02151244.hpp"

// size 0x90, ctor ov0_0217087C
class CFieldEffectGlitter : public CFieldEffect {
public:
    virtual ~CFieldEffectGlitter();
    virtual int sub_02033028();
    virtual int sub_020332A4();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual void sub_02033440(u16 color);
};

class CFieldEffectGlitterFactory : public CFieldEffectFactory {
public:
    virtual ~CFieldEffectGlitterFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Reset();

public:
    UnkClass_02151244 m_tex;
};

STATIC_SIZE_ASSERT(CFieldEffectGlitterFactory, 0x30);

#endif // POKERANGER2_FIELD_CFIELDEFFECTGLITTER_HPP
