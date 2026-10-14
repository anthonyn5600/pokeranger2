#ifndef POKERANGER2_FIELD_CFIELDEFFECTPOISONGAS_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTPOISONGAS_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffectActor.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "field/CFieldEffectManage.hpp"
#include "primitive/CSoftwareSprite.hpp"

// One gas cloud (ov0): drifts out from m_pos and slows down, fades out over its last 30 frames.
struct PoisonGasPuff {
    Point2D pos;
    Point2D vel;
    Point2D accel;
    s16 life;
    u8 alpha;
};

// Saved state (ov0_02142390 / ov0_02142388).
struct PoisonGasSave {
    u8 type;
    u8 mask;
    u8 param;
    u8 age[4];
    struct {
        s16 x;
        s16 y;
    } pos[4];
    u8 unk_18[4];
    int unk_1C;
};

// Four gas clouds spreading diagonally from m_pos (ov0); a cloud touching the player reports a hit (m_kind) and
// vanishes. Pooled by its factory, which owns the actor data.
class CFieldEffectPoisonGas : public CFieldEffectActor {
public:
    CFieldEffectPoisonGas();
    virtual ~CFieldEffectPoisonGas();
    virtual int sub_02033028()
    {
        return 0xC;
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

    void Init(CEffectActorData *data, int kind);
    void InitSprites();
    BOOL IsTouchingPlayer(const Point2D *pos);

public:
    Point2D m_pos;
    PoisonGasPuff m_puffs[4];
    CSoftwareSprite m_sprites[4];
    int m_kind;
    u16 m_cacId;
    int m_param;
    u8 m_used;
};
STATIC_SIZE_ASSERT(CFieldEffectPoisonGas, 0x1D4);

class CFieldEffectPoisonGasFactory : public CFieldEffectFactory {
public:
    CFieldEffectPoisonGasFactory(CFieldEffectManage *mgr);
    virtual ~CFieldEffectPoisonGasFactory();
    virtual CFieldEffect *Create(int arg);
    virtual void Update(int frames);
    virtual void Reset();

    BOOL Load();
    void Release();

public:
    CFieldEffectAttackActorData m_data;
    int m_kind;
    CFieldEffectPoisonGas *m_pool;
};
STATIC_SIZE_ASSERT(CFieldEffectPoisonGasFactory, 0x40);

#endif // POKERANGER2_FIELD_CFIELDEFFECTPOISONGAS_HPP
