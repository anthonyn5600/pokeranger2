#ifndef POKERANGER2_FIELD_CFIELDEFFECTEXPLOSION_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTEXPLOSION_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"

class CFieldEffectExplosion : public CFieldEffectActor {
public:
    virtual ~CFieldEffectExplosion();
    virtual void ov0_021423A4();
    virtual int sub_02033028();
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual int ov0_02142390(void *buf, void *end);
    virtual BOOL ov0_02142388(const void *data);
};

class CFieldEffectExplosionFactory : public CFieldEffectFactory {
public:
    CFieldEffectExplosionFactory(CFieldEffectManage *mgr);
    virtual ~CFieldEffectExplosionFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Update(int frames);
    virtual void Reset();

public:
    u8 unk_04[0x70];
};

STATIC_SIZE_ASSERT(CFieldEffectExplosionFactory, 0x74);

#endif // POKERANGER2_FIELD_CFIELDEFFECTEXPLOSION_HPP
