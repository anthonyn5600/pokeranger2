#ifndef POKERANGER2_FIELD_CFIELDEFFECTMANPUDOKARIMO_HPP
#define POKERANGER2_FIELD_CFIELDEFFECTMANPUDOKARIMO_HPP

#include <nitro.h>

#include "field/CFieldEffect.hpp"
#include "field/CFieldEffectManage.hpp"
#include "field/CFieldEffectManpuAnime.hpp"

// Manpu that bobs above the actor and cycles its tint through 3 colours (start set by the type).
class CFieldEffectManpuDokarimo : public CFieldEffectManpuAnime {
public:
    CFieldEffectManpuDokarimo(CFieldEffectManage::CResidentResource *res, UnkClass_0216D420 *slots, int cac, int type);
    virtual ~CFieldEffectManpuDokarimo();
    virtual void UpdatePos(int step);

    void SetColors(int type);

    Point2D m_offset;
    fx32 m_bobSpeed;
    u8 m_fade;
    u8 m_colorBase;
    u8 m_colorIdx;
    u8 m_fadeLen;
};

STATIC_SIZE_ASSERT(CFieldEffectManpuDokarimo, 0x94);

#endif // POKERANGER2_FIELD_CFIELDEFFECTMANPUDOKARIMO_HPP
