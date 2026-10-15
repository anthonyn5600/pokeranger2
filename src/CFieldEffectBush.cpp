#include "field/CFieldEffectBush.hpp"

#include "Camera2D.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldEffectManage.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;

CFieldEffectBush::CFieldEffectBush()
    : m_active(FALSE)
    , m_actor(NULL)
    , m_cac(NULL)
{
    m_anim = 0;
}

CFieldEffectBush::~CFieldEffectBush()
{
    Destroy();
}

void CFieldEffectBush::Destroy()
{
    Detach();
}

void CFieldEffectBush::SetRes(VramImage *ncbr, VramPalette *palette)
{
    m_sprite.unk_2C = (UnkClass_CPrimitive_ImageProxy *)ncbr;
    m_sprite.unk_30 = NULL;
    m_sprite.unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
}

void CFieldEffectBush::Attach(CFieldActor *actor, CFieldEffectManage *mgr)
{
    m_actor = actor;
    if (actor == NULL) {
        return;
    }
    switch (actor->m_bushMode) {
    default:
    case 0:
        m_kind = -1;
        break;
    case 1:
        m_kind = 1;
        break;
    case 2:
        m_kind = 3;
        break;
    case 3:
        m_kind = 4;
        break;
    case 4:
        m_kind = 2;
        break;
    }
    if (m_kind >= 0 && IsOnScreen(m_actor)) {
        m_sprite.unk_38 = (UnkClass_CSoftwareSprite_38 *)mgr->m_resident.GetNcer(m_kind);
        ReleaseAnim();
        m_cac = mgr->m_resident.GetCac(m_kind);
        if (m_cac != NULL) {
            m_anim = m_cac->Create(1, 0);
        }
        return;
    }
    m_actor->StopBushEffect();
}

void CFieldEffectBush::Activate()
{
    m_sprite.m_cellDataIdx = 0;
    m_kind = -1;
    m_active = TRUE;
}

void CFieldEffectBush::Detach()
{
    m_active = FALSE;
    ReleaseAnim();
    CFieldActor *actor = m_actor;
    if (actor == NULL) {
        return;
    }
    actor->m_bushEffect = 0;
    if (actor->m_bushMode != 0) {
        actor->ClearClipping();
        actor->m_hasShadow = 1;
    }
    m_actor = NULL;
}

int CFieldEffectBush::Render(Camera2D *camera)
{
    if (m_actor != NULL) {
        if (!IsOnScreen(m_actor)) {
            m_actor->StopBushEffect();
            return -1;
        }
        if (m_cac != NULL && m_anim != 0) {
            m_sprite.m_cellDataIdx = m_cac->GetCell(m_anim);
        }
        CFieldActor *actor = m_actor;
        int ofs = (actor->unk_D6 + 8) << 12;
        fx32 x = actor->GetX();
        fx32 y = actor->GetY() + ofs;
        m_sprite.m_coords[0] = x;
        m_sprite.m_coords[1] = y;
        m_sprite.m_z = m_actor->GetDepth();
        m_sprite.Render(camera);
    }
    return 0;
}

BOOL CFieldEffectBush::IsOnScreen(CFieldActor *actor)
{
    BOOL ret = FALSE;
    if (!actor->IsActive() || actor->IsHidden()) {
        return FALSE;
    }
    CFieldScene *scene = MAIN_BSS_0210CA40;
    Camera2D *camera;
    if (m_kind >= 0 && scene != NULL && (camera = scene->m_camera) != NULL) {
        Rectangle r;
        r.pos.x = actor->GetX();
        r.pos.y = actor->GetY() + ((actor->unk_D6 + 8) << 12);
        r.size.y = 0x10000;
        switch (m_kind) {
        case 1:
            r.size.x = 0x10000;
            break;
        case 3:
            r.size.x = 0x20000;
            break;
        case 4:
            r.size.x = 0x30000;
            break;
        case 2:
            r.size.x = 0x10000;
            break;
        }
        ret = camera->IsRectVisible(&r, 0x1199);
    }
    return ret;
}

CFieldEffectBushFactory::CFieldEffectBushFactory(CFieldEffectManage *mgr)
{
    if (mgr != NULL) {
        for (int i = 0; i < 16; i++) {
            VramPalette *palette = mgr->m_resident.GetPalette();
            m_bushes[i].SetRes(mgr->m_resident.GetNcbr(0), palette);
        }
    }
}

CFieldEffect *CFieldEffectBushFactory::Create(int arg)
{
    CFieldEffectBush *bush = NULL;
    for (int i = 0; i < 16; i++) {
        if (!m_bushes[i].m_active) {
            bush = &m_bushes[i];
            bush->Activate();
            break;
        }
    }
    return bush;
}

int CFieldEffectBush::GetEffectId()
{
    return 0x25;
}
