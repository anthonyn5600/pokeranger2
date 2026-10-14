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
        sub_0203312C(0, 8);
        sub_0203312C(6, 1);
        sub_0203312C(7, 0x18);
        sub_0203312C(5, 0x1E);
        sub_0203312C(8, 0x1E);
        sub_0203312C(3, 4);
        sub_0203312C(4, 4);
    }
}

int CFieldEffectSteam::sub_0203312C(int param, int value)
{
    switch (param) {
    case 7:
        m_animator.m_alpha = value;
        return 1;
    }
    return TFieldEffectSmoke<CSoftwareSprite>::sub_0203312C(param, value);
}

CFieldEffect *CFieldEffectSteamFactory::Create(int arg)
{
    CFieldEffectSteam *effect = new CFieldEffectSteam(arg);
    CFieldEffectManage *mgr;
    if (effect != NULL && (mgr = MAIN_BSS_0210CA60) != NULL) {
        effect->ov0_021423E8(FieldEffectSpriteRes(mgr->m_resident.GetNcbr(0), mgr->m_resident.GetPalette(), mgr->m_resident.GetNcer(0)));
    }
    return effect;
}
