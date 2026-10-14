#include "field/CFieldEffectWaterSplash.hpp"

#include "Camera2D.hpp"
#include "field/CFieldEffectManage.hpp"

CFieldEffectWaterSplash::CFieldEffectWaterSplash()
    : m_active(FALSE)
    , m_cac(NULL)
    , m_anim(0)
{
    m_sprite.m_z = -1;
}

CFieldEffectWaterSplash::~CFieldEffectWaterSplash()
{
    ov0_021423A4();
}

void CFieldEffectWaterSplash::ov0_021423A4()
{
    Deactivate();
}

void CFieldEffectWaterSplash::Setup(UnkClass_020074D4 *ncbr, UnkClass_02007AA4 *palette, CNCERFile *ncer, UnkClass_02008788 *cac)
{
    m_sprite.unk_2C = (UnkClass_CPrimitive_ImageProxy *)ncbr;
    m_sprite.unk_30 = NULL;
    m_sprite.unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
    m_sprite.unk_38 = (UnkClass_CSoftwareSprite_38 *)ncer;
    m_cac = cac;
    if (m_cac != NULL) {
        m_anim = m_cac->sub_02008A80(1, 0);
    }
}

void CFieldEffectWaterSplash::Activate()
{
    m_sprite.m_cellDataIdx = 0;
    m_active = TRUE;
}

void CFieldEffectWaterSplash::Deactivate()
{
    m_active = FALSE;
}

int CFieldEffectWaterSplash::sub_0203312C(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 1:
        m_sprite.m_coords[0] = value << 12;
        break;
    case 2:
        m_drawObj.unk_04 = m_sprite.m_coords[1] = value << 12;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

BOOL CFieldEffectWaterSplash::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    if (m_cac != NULL && m_anim != 0) {
        m_cac->sub_020089B8(m_anim);
    }
    return CFieldEffect::ov0_021421F0(inTime, holdTime, outTime);
}

int CFieldEffectWaterSplash::ov0_02142264(int step)
{
    int ret = CFieldEffect::ov0_02142264(step);
    if (ret != 0 && ret != 4 && m_cac != NULL && m_anim != 0) {
        m_cac->sub_02008A38(m_anim);
        if (m_cac->sub_02008860(m_anim) == 0) {
            ov0_02142240(0);
        }
    }
    return ret;
}

int CFieldEffectWaterSplash::ov0_02142344(Camera2D *camera)
{
    if (m_cac != NULL && m_anim != 0) {
        m_sprite.m_cellDataIdx = m_cac->sub_02008828(m_anim);
    }
    m_sprite.m_z = m_drawObj.m_depth;
    m_sprite.Render(camera);
    return 0;
}

void CFieldEffectWaterSplash::ov0_02142398(UnkClass_0211E3FC *renderLists)
{
    renderLists->sub_0200912C(&m_drawObj);
}

int CFieldEffectWaterSplash::CEffectDrawObject::sub_020091D4(Camera2D *camera, int budget)
{
    m_depth = budget;
    return 10;
}

CFieldEffectWaterSplashFactory::CFieldEffectWaterSplashFactory(CFieldEffectManage *mgr)
{
    if (mgr != NULL) {
        for (int i = 0; i < 16; i++) {
            UnkClass_02008788 *cac = mgr->m_resident.GetCac(8);
            CNCERFile *ncer = mgr->m_resident.GetNcer(8);
            UnkClass_02007AA4 *palette = mgr->m_resident.GetPalette();
            m_splashes[i].Setup(mgr->m_resident.GetNcbr(0), palette, ncer, cac);
        }
    }
}

CFieldEffect *CFieldEffectWaterSplashFactory::Create(int arg)
{
    CFieldEffectWaterSplash *splash = NULL;
    for (int i = 0; i < 16; i++) {
        if (!m_splashes[i].m_active) {
            splash = &m_splashes[i];
            splash->Activate();
            break;
        }
    }
    return splash;
}

int CFieldEffectWaterSplash::sub_02033028()
{
    return 0x26;
}
