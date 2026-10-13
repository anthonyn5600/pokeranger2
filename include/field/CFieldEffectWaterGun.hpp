#ifndef POKERANGER2_FIELD_CFIELDEFFECTWATERGUN_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTWATERGUN_HPP

#include <nitro.h>

#include "field/TFieldParticle.hpp"
#include "primitive/CSoftwareSprite.hpp"

// The original completes the point emitter (and its base) before the effect classes: their typeinfo/vtable creation
// order at TU end decides the TU's data layout. How the original did it is unknown; this size check does the same.
STATIC_SIZE_ASSERT(TFieldParticlePointEmitter<CSoftwareSprite>, 0x18);

// clang-format off
#include "UnkClass_02008788.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CFieldEffectActor.hpp"
// clang-format on

// Water jet from m_start to m_end (ov0): a nozzle and a head sprite plus a particle spray.
class CFieldEffectWaterGun : public CFieldEffectActor {
public:
    // Picks a random cell animation per particle and fades it in.
    class CEmitter : public TFieldParticlePointEmitter<CSoftwareSprite> {
    public:
        CEmitter()
        {
            m_speed = 0;
            m_angle = 0;
            m_life = 0;
            m_interval = 0;
            m_timer = 0;
            unk_34 = 0;
            m_end.y = 0;
            m_end.x = 0;
        }

        virtual void func2();
        virtual u32 Update(int dt);
        virtual void Emit(TFieldParticle<CSoftwareSprite> *p);

        void SetDir(const Point2D &dir);

        Point2D m_end;
        fx32 m_speed;
        int m_angle;
        int m_life;
        int m_interval;
        int m_timer;
        int unk_34;
    };

    class CAnimator : public TFieldParticleForceField<CSoftwareSprite> {
    public:
        CAnimator();

        virtual void Apply(TFieldParticle<CSoftwareSprite> *p, int dt);

        void Init(UnkClass_02008788 *cac);
        void Release();
        void Reset();

        UnkClass_02008788 *m_cac;
        u16 m_ids[16];
        int m_count;
    };

    // Sprays particles from the head along the jet's direction.

    CFieldEffectWaterGun(int id);
    virtual ~CFieldEffectWaterGun();
    virtual int sub_02033028()
    {
        return 8;
    }
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);

    void InitSprites();

public:
    Point2D m_start;
    Point2D m_end;
    Point2D m_pos;
    Point2D m_vel;
    CSoftwareSprite m_sprites[2];
    u16 m_cacIds[2];
    TFieldParticleSystem<CSoftwareSprite> m_system;
    CEmitter m_emitter;
    CAnimator m_animator;
};

class CFieldEffectWaterGunFactory : public CFieldEffectFactory {
public:
    virtual CFieldEffect *Create(int arg);
};

#endif // POKERANGER2_FIELD_CFIELDEFFECTWATERGUN_HPP
