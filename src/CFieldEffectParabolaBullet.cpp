#include "field/CFieldEffectParabolaBullet.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "fx_utils.hpp"

CFieldEffectParabolaBullet::CFieldEffectParabolaBullet(int kind)
    : m_kind(kind)
    , m_index(-1)
{
    CFieldEffectAttackActorData *data = new CFieldEffectAttackActorData();
    if (data != NULL) {
        int count;
        if (m_kind == 0x43 || m_kind == 0x4D) {
            count = 2;
        } else {
            count = 1;
        }
        data->ov0_0214FFF0(kind, 1, count);
    }
    unk_18 = data;
    for (int i = 0; i < 2; i++) {
        CellAnimController *cac = unk_18->GetCac(i);
        if (cac != NULL) {
            m_cacIds[i] = cac->Create(1, 0);
        } else {
            m_cacIds[i] = 0;
        }
    }
    InitSprites();
    m_pos.x = 0;
    m_pos.y = 0;
    m_end.x = 0;
    m_end.y = 0;
    m_vel.x = 0;
    m_vel.y = 0;
    m_lastState = 0;
}

CFieldEffectParabolaBullet::~CFieldEffectParabolaBullet()
{
    if (unk_18 != NULL) {
        for (int i = 0; i < 2; i++) {
            CellAnimController *cac = unk_18->GetCac(i);
            if (cac != NULL) {
                cac->Remove(m_cacIds[i]);
            }
        }
    }
    SAFE_DELETE(unk_18);
}

int CFieldEffectParabolaBullet::ov0_02142264(int step)
{
    int state = CFieldEffectActor::ov0_02142264(step);
    if (unk_18 != NULL) {
        unk_18->Update();
    }
    if (state != m_lastState) {
        if ((u32)(m_index + 1) < unk_18->GetCount()) {
            m_index++;
        }
        if (m_index >= 0) {
            CellAnimController *cac = unk_18->GetCac(m_index);
            if (cac != NULL) {
                cac->Restart(m_cacIds[m_index]);
            }
        }
        m_lastState = state;
    }
    if (state == 4 && m_index == 1) {
        CellAnimController *cac = unk_18->GetCac(m_index);
        if (cac != NULL && cac->GetStatus(m_cacIds[m_index]) == 1) {
            state = 3;
        }
    }
    switch (state) {
    case 1:
        break;
    case 2:
        m_pos += m_vel;
        m_pos.y += m_gravity;
        m_gravity += 0x666;
        break;
    case 3:
        break;
    }
    return state;
}

int CFieldEffectParabolaBullet::ov0_02142344(Camera2D *camera)
{
    if (m_state != 0 && m_index >= 0) {
        CellAnimController *cac = unk_18->GetCac(m_index);
        m_sprites[m_index].SetPos(m_pos);
        if (cac != NULL) {
            m_sprites[m_index].m_cellDataIdx = cac->GetCell(m_cacIds[m_index]);
        }
        m_sprites[m_index].Render(camera);
    }
    return 0;
}

int CFieldEffectParabolaBullet::SetParam(int param, int value)
{
    BOOL ret = TRUE;
    switch (param) {
    case 1:
        m_pos.x = value << 12;
        break;
    case 2:
        m_pos.y = value << 12;
        break;
    case 9:
        m_end.x = value << 12;
        break;
    case 10:
        m_end.y = value << 12;
        break;
    default:
        ret = FALSE;
        break;
    }
    return ret;
}

BOOL CFieldEffectParabolaBullet::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    Point2D dir = m_end - m_pos;
    if (FX32_MUL(dir.x, dir.x) + FX32_MUL(dir.y, dir.y) != 0) {
        if (holdTime > 0) {
            Point2D vel = dir / (holdTime << 12);
            m_vel = vel;
        } else {
            m_vel.x = 0;
            m_vel.y = 0;
        }
    } else {
        m_vel.x = 0;
        m_vel.y = 0;
    }
    m_index = -1;
    if (holdTime > 0) {
        m_gravity = holdTime * -0x333;
    } else {
        m_gravity = 0;
    }
    return CFieldEffect::ov0_021421F0(0, holdTime, 0);
}

void CFieldEffectParabolaBullet::InitSprites()
{
    u32 count = unk_18->GetCount();
    if (count > 2) {
        count = 2;
    }
    for (u32 i = 0; i < count; i++) {
        m_sprites[i].SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(i), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)unk_18->GetPalette(), (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(i));
        m_sprites[i].m_cellDataIdx = 0;
        m_sprites[i].m_z = 0x622;
        m_sprites[i].m_polygonID = 8;
        m_sprites[i].m_rotAngle = 0;
    }
}

CFieldEffect *CFieldEffectParabolaBulletFactory::Create(int arg)
{
    return new CFieldEffectParabolaBullet(arg);
}
