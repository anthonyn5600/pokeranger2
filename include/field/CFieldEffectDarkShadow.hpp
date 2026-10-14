#ifndef POKERANGER2_FIELD_CFIELDEFFECTDARKSHADOW_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTDARKSHADOW_HPP

#include <nitro.h>

// The factory completes before CFieldEffect (included below), which puts the effect's typeinfo before the
// factory's in the TU's size-sorted .data, like CFieldEffectWaveBullet.
#include "field/CFieldEffectFactory.hpp"
class CFieldEffectDarkShadowFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#include "field/CFieldEffect.hpp"
#include "field/FieldPointMover.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CSoftwareSprite.hpp"

// A shadow quad (the field's shadow texture) ringed by up to 32 rotating sprites.
class CFieldEffectDarkShadow : public CFieldEffect {
public:
    CFieldEffectDarkShadow(int mode); // ov0_02169A08
    virtual ~CFieldEffectDarkShadow();
    virtual int GetEffectId()
    {
        return 0x16;
    }
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int ov0_0214239C(int layer);
    virtual int SetParam(int param, int value);
    virtual void sub_0203331C(const Point2D &pos, int arg1);
    virtual void sub_02033388(const Point2D &pos, int arg1);

public:
    CPrimitiveRECT m_rect;
    CSoftwareSprite m_sprites[32];
    s16 m_rotSpeeds[32];
    int m_count;
    int m_layer;
    Point2D m_scale;
    int m_rotSpeed;
    FieldPointMover m_scaleMover;
    FieldPointMover m_posMover;
};

STATIC_SIZE_ASSERT(CFieldEffectDarkShadow, 0xA74);

#endif // POKERANGER2_FIELD_CFIELDEFFECTDARKSHADOW_HPP
