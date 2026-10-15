#include "field/CFieldEffectFlash.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "fx_utils.hpp"

CFieldEffectFlash::CFieldEffectFlash(int kind)
    : m_kind(kind)
{
    CFieldEffectAttackActorData *data = new CFieldEffectAttackActorData();
    if (data != NULL) {
        data->Load(kind, 1, 1);
    }
    unk_18 = data;
    m_pos.x = m_pos.y = 0;
    m_scale = 0x1000;
    InitSprite();
    CellAnimController *cac = unk_18->GetCac(0);
    if (cac != NULL) {
        m_cacId = cac->Create(1, 0);
        cac->SetAnim(m_cacId, 0);
    }
}

CFieldEffectFlash::~CFieldEffectFlash()
{
    unk_18->GetCac(0)->Remove(m_cacId);
    SAFE_DELETE(unk_18);
}

int CFieldEffectFlash::Update(int step)
{
    int state = CFieldEffectActor::Update(step);
    if (state != 0 && state != 4) {
        unk_18->Update();
    }
    if (m_kind == 0x79) {
        m_scale += 0x199;
        m_sprites[0].m_scale[1] = m_sprites[0].m_scale[0] = m_scale;
        m_sprites[0].m_alpha = 0xC;
    }
    if (m_kind == 0x78) {
        if (m_state == 1) {
            m_scale = (m_frame << 12) / m_inTime;
        } else if (m_state == 3) {
            m_scale = ((m_outTime - m_frame) << 12) / m_outTime;
        } else {
            m_scale = 0x1000;
        }
        m_sprites[0].m_scale[1] = m_sprites[0].m_scale[0] = m_scale;
    }
    return m_state;
}

int CFieldEffectFlash::Render(Camera2D *camera)
{
    CellAnimController *cac = unk_18->GetCac(0);
    if (cac != NULL) {
        m_sprites[0].m_cellDataIdx = cac->GetCell(m_cacId);
        m_sprites[0].Render(camera);
    }
    return 1;
}

void CFieldEffectFlash::StartAt(Point2D pos, int arg1, int arg2, int arg3, int arg4)
{
}

BOOL CFieldEffectFlash::Start(int inTime, int holdTime, int outTime)
{
    m_sprites[0].SetPos(m_pos);
    return CFieldEffect::Start(inTime, holdTime, outTime);
}

int CFieldEffectFlash::Stop(int outTime)
{
    return CFieldEffect::Stop(outTime);
}

int CFieldEffectFlash::SetParam(int param, int value)
{
    switch (param) {
    case 1:
        m_pos.x = value << 12;
        break;
    case 2:
        m_pos.y = value << 12;
        break;
    }
    return 0;
}

void CFieldEffectFlash::InitSprite()
{
    m_sprites[0].SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(0), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)unk_18->GetPalette(), (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(0));
    m_sprites[0].m_cellDataIdx = 0;
    m_sprites[0].m_polygonID = 8;
    m_sprites[0].m_z = 0x67C;
}

CFieldEffect *CFieldEffectFlashFactory::Create(int arg)
{
    return new CFieldEffectFlash(arg);
}
