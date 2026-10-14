#ifndef POKERANGER2_FIELD_CFIELDEFFECTEXPLOSION_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTEXPLOSION_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CFieldEffectManage.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Saved state (ov0_02142390 / ov0_02142388).
struct ExplosionSave {
    u8 type;
    u8 flags;
    u8 param;
    u8 frame; // bit 7 = phase
    u8 unk_04[4];
    s16 x;
    s16 y;
    u8 unk_0C[0x10];
    int unk_1C;
};

// Two-phase explosion at m_pos (ov0): phase 0 plays the first animation, phase 1 the blast, which hurts the player
// in range during its first 0x2E frames. Pooled by its factory, which owns one actor data per phase.
class CFieldEffectExplosion : public CFieldEffectActor {
public:
    CFieldEffectExplosion()
        : m_phase(0)
        , m_nextPhase(0)
        , m_kind(0)
        , m_frame(0)
        , m_param(0)
        , m_used(FALSE)
    {
        m_cacIds[0] = m_cacIds[2] = 0; // [2] is out of bounds (low half of m_data[0]) in the original
        m_data[0] = m_data[1] = NULL;
    }
    virtual ~CFieldEffectExplosion();
    virtual int sub_02033028()
    {
        return 0xD;
    }
    virtual void ov0_021423A4()
    {
        m_used = FALSE;
    }
    virtual BOOL ov0_021421F0(int inTime, int holdTime, int outTime);
    virtual int ov0_02142264(int step);
    virtual int ov0_02142344(Camera2D *camera);
    virtual int sub_0203312C(int param, int value);
    virtual int ov0_02142390(void *buf, void *end);
    virtual BOOL ov0_02142388(const void *data);

    void Init(CEffectActorData *data0, CEffectActorData *data1, int kind);
    void InitSprites();
    BOOL IsTouchingPlayer();

public:
    Point2D m_pos;
    CSoftwareSprite m_sprites[2];
    u16 m_cacIds[2];
    CEffectActorData *m_data[2];
    int m_phase;
    int m_nextPhase;
    int m_kind;
    int m_frame;
    int m_param;
    u8 m_used;
};
STATIC_SIZE_ASSERT(CFieldEffectExplosion, 0xE0);

class CFieldEffectExplosionFactory : public CFieldEffectFactory {
public:
    CFieldEffectExplosionFactory(CFieldEffectManage *mgr);
    virtual ~CFieldEffectExplosionFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Update(int frames);
    virtual void Reset();

    BOOL Load();
    void Release();

public:
    CFieldEffectAttackActorData m_data[2];
    int m_kind;
    CFieldEffectExplosion *m_pool;
};
STATIC_SIZE_ASSERT(CFieldEffectExplosionFactory, 0x74);

#endif // POKERANGER2_FIELD_CFIELDEFFECTEXPLOSION_HPP
