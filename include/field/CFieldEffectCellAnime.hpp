#ifndef POKERANGER2_FIELD_CFIELDEFFECTCELLANIME_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTCELLANIME_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"

// size 0xD0, ctor ov0_0215DA8C
class CFieldEffectCellAnime : public CFieldEffectActor {
public:
    virtual ~CFieldEffectCellAnime();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual void sub_0203365C(int arg0);
};

class CFieldEffectAttackCellAnimeFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

class CFieldEffectNormalCellAnimeFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTCELLANIME_HPP
