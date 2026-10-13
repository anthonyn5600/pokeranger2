#ifndef POKERANGER2_FIELD_CFIELDEFFECTSPARK_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSPARK_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"

// size 0x2EC, ctor ov0_02160E50
class CFieldEffectSpark : public CFieldEffectActor {
public:
    virtual ~CFieldEffectSpark();
    virtual int sub_02033028();
    virtual int sub_020332A4();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
};

class CFieldEffectSparkFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTSPARK_HPP
