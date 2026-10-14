#ifndef POKERANGER2_FIELD_CFIELDEFFECTBUSH_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTBUSH_HPP

#include <nitro.h>

#include "common.hpp"
#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectFactory.hpp"
#include "primitive/CSoftwareSprite.hpp"

class CFieldActor;
class CFieldEffectManage;

// Grass drawn over an actor's feet while it walks through a bush (kinds 1..4 from the actor's unk_D4).
class CFieldEffectBush : public CFieldEffect {
public:
    CFieldEffectBush();
    virtual ~CFieldEffectBush();
    virtual void ov0_021423A4();
    virtual int GetEffectId();
    virtual int ov0_02142344(Camera2D *camera);

    void SetRes(VramImage *ncbr, VramPalette *palette);
    void Attach(CFieldActor *actor, CFieldEffectManage *mgr);
    void Activate();
    void Detach();
    BOOL IsOnScreen(CFieldActor *actor);

    inline void ReleaseAnim()
    {
        if (m_cac != NULL && m_anim != 0) {
            m_cac->Remove(m_anim);
            m_anim = 0;
            m_cac = NULL;
        }
    }

public:
    u8 m_active;
    CFieldActor *m_actor;
    CellAnimController *m_cac;
    CSoftwareSprite m_sprite;
    u16 m_anim;
    s8 m_kind;
};

STATIC_SIZE_ASSERT(CFieldEffectBush, 0x74);

class CFieldEffectBushFactory : public CFieldEffectFactory {
public:
    CFieldEffectBushFactory(CFieldEffectManage *mgr);
    virtual CFieldEffect *Create(int arg);

public:
    CFieldEffectBush m_bushes[16];
};

STATIC_SIZE_ASSERT(CFieldEffectBushFactory, 0x744);

#endif // POKERANGER2_FIELD_CFIELDEFFECTBUSH_HPP
