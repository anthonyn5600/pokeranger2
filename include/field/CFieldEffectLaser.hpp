#ifndef POKERANGER2_FIELD_CFIELDEFFECTLASER_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTLASER_HPP

#include <nitro.h>

#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "primitive/CSoftwareSprite.hpp"

// A beam from m_pos to m_end: a start sprite, a stretched middle sprite and a head sprite.
class CFieldEffectLaser : public CFieldEffectActor {
public:
    CFieldEffectLaser(int kind);
    virtual ~CFieldEffectLaser();
    virtual int GetEffectId()
    {
        return 3;
    }
    virtual BOOL Start(int inTime, int holdTime, int outTime);
    virtual int Update(int step);
    virtual int Render(Camera2D *camera);
    virtual int SetParam(int param, int value);

    void InitSprites();

public:
    Point2D m_pos;
    Point2D m_end;
    Point2D m_head;
    Point2D m_vel;
    fx32 m_length;
    fx32 m_width;
    fx32 m_widthIn;
    fx32 m_widthOut;
    fx32 m_midWidth;
    CSoftwareSprite m_sprites[3];
    u16 m_cacIds[3];
};

STATIC_SIZE_ASSERT(CFieldEffectLaser, 0x13C);

class CFieldEffectLaserFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTLASER_HPP
