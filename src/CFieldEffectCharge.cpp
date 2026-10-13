#include "field/CFieldEffectCharge.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "fx_utils.hpp"

CFieldEffectCharge::CFieldEffectCharge()
{
    CFieldEffectAttackActorData *data = new CFieldEffectAttackActorData();
    if (data != NULL) {
        data->ov0_0214FFF0(0x64, 1, 1);
    }
    unk_18 = data;
    m_pos.x = m_pos.y = 0;
    InitSprites();
    UnkClass_02008788 *cac = unk_18->GetCac(0);
    if (cac != NULL) {
        m_cacIds[0] = cac->sub_02008A80(1, 0);
        cac->sub_02008990(m_cacIds[0], 4);
        m_cacIds[1] = cac->sub_02008A80(1, 0);
        cac->sub_02008990(m_cacIds[1], 5);
    }
}

CFieldEffectCharge::~CFieldEffectCharge()
{
    for (int i = 0; i < 2; i++) {
        unk_18->GetCac(0)->sub_02008B80(m_cacIds[i]);
    }
    SAFE_DELETE(unk_18);
}

int CFieldEffectCharge::ov0_02142264(int step)
{
    int state = CFieldEffectActor::ov0_02142264(step);
    if (state != 0 && state != 4) {
        unk_18->Update();
    }
    return m_state;
}

int CFieldEffectCharge::ov0_02142344(Camera2D *camera)
{
    UnkClass_02008788 *cac = unk_18->GetCac(0);
    if (cac != NULL) {
        for (int i = 0; i < 2; i++) {
            m_sprites[i].m_cellDataIdx = cac->sub_02008828(m_cacIds[i]);
            m_sprites[i].Render(camera);
        }
    }
    return 1;
}

void CFieldEffectCharge::ov0_0214234C(Point2D pos, int arg1, int arg2, int arg3, int arg4)
{
}

BOOL CFieldEffectCharge::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    Point2D pos;
    pos.y = m_pos.y + FX32_MUL(FX_CosIdx(0x1B00), 0x30000);
    pos.x = m_pos.x - FX32_MUL(FX_SinIdx(0x1B00), 0x30000);
    m_sprites[0].SetPos(pos);
    m_sprites[0].m_rotAngle = 0x1B00;
    pos.x = m_pos.x - 0x4A000;
    pos.y = m_pos.y + 0x4A000;
    m_sprites[1].SetPos(pos);
    return CFieldEffect::ov0_021421F0(inTime, holdTime, outTime);
}

int CFieldEffectCharge::ov0_02142240(int outTime)
{
    return CFieldEffect::ov0_02142240(outTime);
}

int CFieldEffectCharge::sub_0203312C(int param, int value)
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

void CFieldEffectCharge::InitSprites()
{
    m_sprites[0].SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(0), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)unk_18->GetPalette(), (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(0));
    m_sprites[0].m_cellDataIdx = 0;
    m_sprites[0].m_polygonID = 8;
    m_sprites[0].m_z = 0x488;
    m_sprites[1].SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(0), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)unk_18->GetPalette(), (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(0));
    m_sprites[1].m_cellDataIdx = 0;
    m_sprites[1].m_polygonID = 9;
    m_sprites[1].m_z = 0x489;
}

CFieldEffect *CFieldEffectChargeFactory::Create(int arg)
{
    return new CFieldEffectCharge();
}
