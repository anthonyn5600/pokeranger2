#ifndef POKERANGER2_FIELD_CFIELDEFFECTBLOOM_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTBLOOM_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CSimpleSpriteNTF.hpp"
#include "field/UnkClass_02151244.hpp"

class CFieldActor;

// Moves a value from `from` to `to` over `duration` frames.
struct BloomFader {
    BOOL Update(int dt)
    {
        if (!active) {
            return FALSE;
        }
        frame += dt;
        fx32 t;
        if (duration <= 0) {
            t = FX32_ONE;
        } else if (frame >= duration) {
            t = FX32_ONE;
        } else {
            t = (frame << 12) / duration;
        }
        cur = from + FX32_MUL(t, to - from);
        if (frame >= duration) {
            active = FALSE;
        }
        return TRUE;
    }

    fx32 from;
    fx32 to;
    fx32 cur;
    int duration;
    int frame;
    BOOL active;
};

// A glowing bloom over an actor: two flaring halos (sprites 0 and 3) and a wobbling, spinning sparkle (sprite 2).
class CFieldEffectBloom : public CFieldEffect {
public:
    CFieldEffectBloom(int mode);
    virtual ~CFieldEffectBloom();
    virtual int sub_02033028();
    virtual int sub_020332A4();
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual void sub_02033440(u16 color);
    virtual void sub_020333D8(int arg0, int arg1);

    void SetTexture(int i, UnkClass_02151244 *tex);
    int SetPolygonIDs(int base);
    void StartFlash();

public:
    CFieldActor *m_actor;
    Point2D m_offset;
    int m_size;
    CSimpleSpriteNTF m_sprites[4];
    UnkClass_02151244 *m_tex[4];
    s8 m_blinkTimer;
    s8 m_idleTimer;
    u16 m_angle1;
    u16 m_angle2;
    s16 m_flash[2];
    s16 m_cooldown;
    u8 m_mode;
    u8 m_alpha;
    BloomFader m_fader;
};

STATIC_SIZE_ASSERT(CFieldEffectBloom, 0x1D0);

class CFieldEffectBloomFactory : public CFieldEffectFactory {
public:
    CFieldEffectBloomFactory()
    {
    }
    virtual ~CFieldEffectBloomFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Reset();

    BOOL LoadTexture(int i, int num);
    void ReleaseTextures();

public:
    UnkClass_02151244 m_tex[3];
};

STATIC_SIZE_ASSERT(CFieldEffectBloomFactory, 0x88);

#endif // POKERANGER2_FIELD_CFIELDEFFECTBLOOM_HPP
