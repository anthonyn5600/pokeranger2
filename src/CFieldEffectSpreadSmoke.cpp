#include "field/CFieldEffectSpreadSmoke.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"

CFieldEffectSpreadSmoke::CFieldEffectSpreadSmoke(int kind)
    : m_emitter(2)
{
    m_animator.m_scaleStart = 0x800;
    m_animator.m_scaleEnd = 0x1800;
}

CFieldEffectSpreadSmoke::~CFieldEffectSpreadSmoke()
{
}

int CFieldEffectSpreadSmoke::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 7:
        m_animator.m_alpha = value;
        break;
    case 6:
        m_emitter.m_count = value;
        break;
    case 3:
        m_emitter.m_width = value << 12;
        break;
    case 4:
        m_emitter.m_height = value << 12;
        break;
    case 0x13:
        m_emitter.m_colorMode = value;
        break;
    default:
        ret = TFieldEffectParticle<CSoftwareSprite>::SetParam(param, value);
        break;
    }
    return ret;
}

CFieldEffect *CFieldEffectSpreadSmokeFactory::Create(int arg)
{
    CFieldEffectSpreadSmoke *effect = new CFieldEffectSpreadSmoke(arg);
    CFieldEffectManage *mgr;
    if (effect != NULL && (mgr = MAIN_BSS_0210CA60) != NULL) {
        effect->SetParticleRes(FieldEffectSpriteRes(mgr->m_resident.GetNcbr(0), mgr->m_resident.GetPalette(), mgr->m_resident.GetNcer(0)));
    }
    return effect;
}
