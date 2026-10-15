#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUDARKRIE_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUDARKRIE_HPP

#include <nitro.h>

#include "field/AnimSlotPool.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldEffectManpu.hpp"
#include "primitive/CSoftwareSprite.hpp"

// Five sprites bobbing around the actor's balloon, each fading through its own color cycle.
class CFieldEffectManpuDarkrie : public CFieldEffectManpu {
public:
    CFieldEffectManpuDarkrie(CFieldEffectManage::CResidentResource *res, AnimSlotPool *slots, int cac, int type);
    virtual ~CFieldEffectManpuDarkrie();
    virtual int ov0_02142264(int step);
    virtual int Draw(Camera2D *camera);
    virtual void SetDepth(fx32 z);

    void UpdatePos(int step);
    void UpdateColors(int step);
    void Init(int cac);

    CSoftwareSprite m_sprites[5];
    u16 m_anims[5];
    AnimSlotPool *m_slots;
    int m_cac;
    Point2D m_offset;
    fx32 m_bobSpeed;
    u8 m_fade[5];
    u8 m_colorIdx[5];
    u8 m_colorBase;
    u8 m_fadeLen;
};

STATIC_SIZE_ASSERT(CFieldEffectManpuDarkrie, 0x1D4);

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUDARKRIE_HPP
