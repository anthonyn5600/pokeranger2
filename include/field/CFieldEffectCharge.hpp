#ifndef POKERANGER2_FIELD_CFIELDEFFECTCHARGE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTCHARGE_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Charge-up glow (ov0): two sprites of the attack effect 0x64, one circling, one offset from m_pos.
class CFieldEffectCharge : public CFieldEffectActor {
public:
    CFieldEffectCharge();
    virtual ~CFieldEffectCharge();
    virtual int GetEffectId()
    {
        return 0x22;
    }
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142240(int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual void ov0_0214234C(Point2D pos, int arg1, int arg2, int arg3, int arg4);
    virtual int SetParam(int param, int value);

    void InitSprites();

public:
    Point2D m_pos;
    CSoftwareSprite m_sprites[2];
    u16 m_cacIds[2];
};

class CFieldEffectChargeFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTCHARGE_HPP
