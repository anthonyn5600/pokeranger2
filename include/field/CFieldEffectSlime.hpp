#ifndef POKERANGER2_FIELD_CFIELDEFFECTSLIME_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTSLIME_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CFieldEffectManage.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CFieldActor;

// One slime puddle left behind the actor (ov0): grows over 60 frames, stays, fades out over its last 30.
struct SlimePuddle {
    Point2D pos;
    fx32 scale;
    s16 life;
    u8 alpha;
};

// Saved state (ov0_02142390 / ov0_02142388).
struct SlimeSave {
    u8 type; // bits 6-7 = kind
    u8 mask; // bit 7 = fading out
    u8 param;
    u8 age[5];
    struct {
        s16 x;
        s16 y;
    } pos[5];
    int actorId;
};

// Slime trail (ov0, effects 0x84..0x86): every 30 frames the actor m_actor drops a puddle (up to five); a puddle
// touching the player reports a hit with m_param. Pooled by its factory.
class CFieldEffectSlime : public CFieldEffectActor {
public:
    CFieldEffectSlime();
    virtual ~CFieldEffectSlime();
    virtual int GetEffectId()
    {
        return 0x12;
    }
    virtual void ov0_021423A4()
    {
        m_flags = 0;
    }
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int ov0_0214239C(int layer);
    virtual int SetParam(int param, int value);
    virtual int ov0_02142390(void *buf, void *end);
    virtual BOOL ov0_02142388(const void *data);

    void Init(int type, CEffectActorData *data, int kind);
    void Reset(BOOL keepParam);
    void AddPuddle();
    void UpdatePuddle(int i);
    void InitSprites();
    BOOL IsTouchingPlayer(const Point2D *pos);
    void ov0_021633B8();
    void ov0_021633CC();

public:
    SlimePuddle m_puddles[5];
    CSoftwareSprite m_sprites[5];
    u16 m_cacId;
    s16 m_timer;
    CFieldActor *m_actor;
    int m_kind;
    int m_param;
    int m_type;
    u16 m_flags; // 1 = used, 2 = dropping puddles, 0x8000 = param from the enemy
};
STATIC_SIZE_ASSERT(CFieldEffectSlime, 0x200);

class CFieldEffectSlimeFactory : public CFieldEffectFactory {
public:
    CFieldEffectSlimeFactory(CFieldEffectManage *mgr);
    virtual ~CFieldEffectSlimeFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Update(int frames);
    virtual void Reset();

    BOOL Load(int type);
    void Release();

public:
    CFieldEffectAttackActorData m_data;
    int m_type;
    int m_kind;
    CFieldEffectSlime *m_pool;
};
STATIC_SIZE_ASSERT(CFieldEffectSlimeFactory, 0x44);

#endif // POKERANGER2_FIELD_CFIELDEFFECTSLIME_HPP
