#ifndef POKERANGER2_FIELD_CFIELDEFFECTBULLET_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTBULLET_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Projectile sprite flying from m_pos to m_end over the hold time (ov0); m_kind is the effect archive id.
class CFieldEffectBullet : public CFieldEffectActor {
public:
    CFieldEffectBullet(int kind);
    virtual ~CFieldEffectBullet();
    virtual int GetEffectId()
    {
        return 2;
    }
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int SetParam(int param, int value);

    void InitSprite();

public:
    int m_kind;
    BOOL m_directional;
    u16 m_dir;
    Point2D m_pos;
    Point2D m_end;
    Point2D m_vel;
    u8 m_moving;
    CSoftwareSprite m_sprite;
    u16 m_cacId;
};

class CFieldEffectBulletFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTBULLET_HPP
