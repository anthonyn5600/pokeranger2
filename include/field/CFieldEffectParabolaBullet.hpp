#ifndef POKERANGER2_FIELD_CFIELDEFFECTPARABOLABULLET_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTPARABOLABULLET_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Defined before the effect: the TU-end walk then makes the effect's typeinfo first (the original's data order).
class CFieldEffectParabolaBulletFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

// Projectile thrown from m_pos to m_end on an arc over the hold time (ov0): m_vel moves it straight, m_gravity starts
// upwards and grows each frame. m_kind is the effect archive id (up to two animations, one per state change).
class CFieldEffectParabolaBullet : public CFieldEffectActor {
public:
    CFieldEffectParabolaBullet(int kind);
    virtual ~CFieldEffectParabolaBullet();
    virtual int GetEffectId()
    {
        return 4;
    }
    virtual BOOL Start(int inTime, int holdTime, int outTime);
    virtual int Update(int step);
    virtual int Render(Camera2D *camera);
    virtual int SetParam(int param, int value);

    void InitSprites();

public:
    int m_kind;
    Point2D m_pos;
    Point2D m_end;
    Point2D m_vel;
    fx32 m_gravity;
    int m_index;
    int m_lastState;
    CSoftwareSprite m_sprites[2];
    u16 m_cacIds[2];
};
STATIC_SIZE_ASSERT(CFieldEffectParabolaBullet, 0xE0);

#endif // POKERANGER2_FIELD_CFIELDEFFECTPARABOLABULLET_HPP
