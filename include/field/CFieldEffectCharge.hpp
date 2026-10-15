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
    virtual BOOL Start(int inTime, int holdTime, int outTime);
    virtual int Stop(int outTime);
    virtual int Update(int step);
    virtual int Render(Camera2D *camera);
    virtual void StartAt(Point2D pos, int arg1, int arg2, int arg3, int arg4);
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
