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
    Destroy();
}

void CFieldEffectWaterSplash::Destroy()
{
    Deactivate();
}

void CFieldEffectWaterSplash::Setup(VramImage *ncbr, VramPalette *palette, CNCERFile *ncer, CellAnimController *cac)
{
    m_sprite.unk_2C = (UnkClass_CPrimitive_ImageProxy *)ncbr;
    m_sprite.unk_30 = NULL;
    m_sprite.unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
    m_sprite.unk_38 = (UnkClass_CSoftwareSprite_38 *)ncer;
    m_cac = cac;
    if (m_cac != NULL) {
        m_anim = m_cac->Create(1, 0);
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

int CFieldEffectWaterSplash::SetParam(int param, int value)
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

BOOL CFieldEffectWaterSplash::Start(int inTime, int holdTime, int outTime)
{
    if (m_cac != NULL && m_anim != 0) {
        m_cac->Restart(m_anim);
    }
    return CFieldEffect::Start(inTime, holdTime, outTime);
}

int CFieldEffectWaterSplash::Update(int step)
{
    int ret = CFieldEffect::Update(step);
    if (ret != 0 && ret != 4 && m_cac != NULL && m_anim != 0) {
        m_cac->Update(m_anim);
        if (m_cac->GetStatus(m_anim) == 0) {
            Stop(0);
        }
    }
    return ret;
}

int CFieldEffectWaterSplash::Render(Camera2D *camera)
{
    if (m_cac != NULL && m_anim != 0) {
        m_sprite.m_cellDataIdx = m_cac->GetCell(m_anim);
    }
    m_sprite.m_z = m_drawObj.m_depth;
    m_sprite.Render(camera);
    return 0;
}

void CFieldEffectWaterSplash::AddToRenderLists(DrawObjectList *renderLists)
{
    renderLists->Insert(&m_drawObj);
}

int CFieldEffectWaterSplash::CEffectDrawObject::Draw(Camera2D *camera, int budget)
{
    m_depth = budget;
    return 10;
}

CFieldEffectWaterSplashFactory::CFieldEffectWaterSplashFactory(CFieldEffectManage *mgr)
{
    if (mgr != NULL) {
        for (int i = 0; i < 16; i++) {
            CellAnimController *cac = mgr->m_resident.GetCac(8);
            CNCERFile *ncer = mgr->m_resident.GetNcer(8);
            VramPalette *palette = mgr->m_resident.GetPalette();
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

int CFieldEffectWaterSplash::GetEffectId()
{
    return 0x26;
}
