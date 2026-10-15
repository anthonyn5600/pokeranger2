#include "field/CFieldEffectSteam.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "fx_utils.hpp"

CFieldEffectSteam::CFieldEffectSteam(int kind)
    : TFieldEffectSmoke<CSoftwareSprite>(1)
{
    m_animator.m_scaleStart = 0x800;
    m_animator.m_scaleEnd = 0x2000;
    if (kind == 1) {
        SetParam(0, 8);
        SetParam(6, 1);
        SetParam(7, 0x18);
        SetParam(5, 0x1E);
        SetParam(8, 0x1E);
        SetParam(3, 4);
        SetParam(4, 4);
    }
}

int CFieldEffectSteam::SetParam(int param, int value)
{
    switch (param) {
    case 7:
        m_animator.m_alpha = value;
        return 1;
    }
    return TFieldEffectSmoke<CSoftwareSprite>::SetParam(param, value);
}

CFieldEffect *CFieldEffectSteamFactory::Create(int arg)
{
    CFieldEffectSteam *effect = new CFieldEffectSteam(arg);
    CFieldEffectManage *mgr;
    if (effect != NULL && (mgr = MAIN_BSS_0210CA60) != NULL) {
        effect->SetParticleRes(FieldEffectSpriteRes(mgr->m_resident.GetNcbr(0), mgr->m_resident.GetPalette(), mgr->m_resident.GetNcer(0)));
    }
    return effect;
}
