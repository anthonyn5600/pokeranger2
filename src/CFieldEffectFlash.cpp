#include "field/CFieldEffectFlash.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "fx_utils.hpp"

CFieldEffectFlash::CFieldEffectFlash(int kind)
    : m_kind(kind)
{
    CFieldEffectAttackActorData *data = new CFieldEffectAttackActorData();
    if (data != NULL) {
        data->ov0_0214FFF0(kind, 1, 1);
    }
    unk_18 = data;
    m_pos.x = m_pos.y = 0;
    m_scale = 0x1000;
    InitSprite();
    UnkClass_02008788 *cac = unk_18->GetCac(0);
    if (cac != NULL) {
        m_cacId = cac->sub_02008A80(1, 0);
        cac->sub_02008990(m_cacId, 0);
    }
}

CFieldEffectFlash::~CFieldEffectFlash()
{
    unk_18->GetCac(0)->sub_02008B80(m_cacId);
    SAFE_DELETE(unk_18);
}

int CFieldEffectFlash::ov0_02142264(int step)
{
    int state = CFieldEffectActor::ov0_02142264(step);
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

int CFieldEffectFlash::ov0_02142344(Camera2D *camera)
{
    UnkClass_02008788 *cac = unk_18->GetCac(0);
    if (cac != NULL) {
        m_sprites[0].m_cellDataIdx = cac->sub_02008828(m_cacId);
        m_sprites[0].Render(camera);
    }
    return 1;
}

void CFieldEffectFlash::ov0_0214234C(Point2D pos, int arg1, int arg2, int arg3, int arg4)
{
}

BOOL CFieldEffectFlash::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    m_sprites[0].SetPos(m_pos);
    return CFieldEffect::ov0_021421F0(inTime, holdTime, outTime);
}

int CFieldEffectFlash::ov0_02142240(int outTime)
{
    return CFieldEffect::ov0_02142240(outTime);
}

int CFieldEffectFlash::sub_0203312C(int param, int value)
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
