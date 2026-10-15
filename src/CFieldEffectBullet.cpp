#include "field/CFieldEffectBullet.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "fx_utils.hpp"

extern "C" {
void LogError(const char *fmt, ...);
}

CFieldEffectBullet::CFieldEffectBullet(int kind)
    : m_kind(kind)
    , m_directional(FALSE)
    , m_dir(0)
{
    CFieldEffectAttackActorData *data = new CFieldEffectAttackActorData();
    if (data != NULL) {
        data->Load(kind, 1, 1);
    }
    unk_18 = data;
    CellAnimController *cac = data->GetCac(0);
    if (cac != NULL) {
        m_cacId = cac->Create(1, 0);
        if (cac->GetAnimCount(m_cacId) > 1) {
            m_directional = TRUE;
        }
    } else {
        LogError("effect anime data is null");
    }
    InitSprite();
    m_pos.x = 0;
    m_pos.y = 0;
    m_end.x = 0;
    m_end.y = 0;
    m_vel.x = 0;
    m_vel.y = 0;
    m_moving = TRUE;
}

CFieldEffectBullet::~CFieldEffectBullet()
{
    if (unk_18 != NULL) {
        CellAnimController *cac = unk_18->GetCac(0);
        if (cac != NULL) {
            cac->Remove(m_cacId);
        }
    }
    SAFE_DELETE(unk_18);
}

int CFieldEffectBullet::Update(int step)
{
    int state = CFieldEffectActor::Update(step);
    if (state != 0 && state != 4 && unk_18 != NULL) {
        unk_18->Update();
    }
    switch (state) {
    case 1:
        break;
    case 2:
        m_pos += m_vel;
        break;
    case 3:
        break;
    }
    return state;
}

int CFieldEffectBullet::Render(Camera2D *camera)
{
    if (m_state != 4 && m_state != 0) {
        CellAnimController *cac = unk_18->GetCac(0);
        m_sprite.SetPos(m_pos);
        if (cac != NULL) {
            if (m_directional) {
                cac->SetAnim(m_cacId, m_dir);
            }
            m_sprite.m_cellDataIdx = cac->GetCell(m_cacId);
        }
        m_sprite.Render(camera);
    }
    return 0;
}

int CFieldEffectBullet::SetParam(int param, int value)
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
    case 16:
        m_moving = value != 0 ? TRUE : FALSE;
        break;
    default:
        ret = FALSE;
        break;
    }
    return ret;
}

BOOL CFieldEffectBullet::Start(int inTime, int holdTime, int outTime)
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
    if (m_directional) {
        if (dir.x >= 0) {
            if (dir.y >= 0) {
                m_dir = 3;
            } else {
                m_dir = 2;
            }
        } else {
            if (dir.y >= 0) {
                m_dir = 0;
            } else {
                m_dir = 1;
            }
        }
    } else {
        switch (m_kind) {
        case 0x2E:
        case 0x2F:
        case 0x30:
        case 0x31:
            if (dir.x > 0) {
                m_sprite.m_scale[1] = -0x1000;
            }
        case 0x2B:
        case 0x4F:
        case 0x51:
        case 0x56:
            m_sprite.m_rotAngle = FX_Atan2Idx(dir.y, dir.x);
            break;
        }
    }
    if (!m_moving) {
        m_vel.y = 0;
        m_vel.x = 0;
    }
    CellAnimController *cac = unk_18->GetCac(0);
    if (cac != NULL) {
        cac->Restart(m_cacId);
    }
    return CFieldEffect::Start(inTime, holdTime, outTime);
}

void CFieldEffectBullet::InitSprite()
{
    m_sprite.SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(0), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)unk_18->GetPalette(), (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(0));
    m_sprite.m_cellDataIdx = 0;
    m_sprite.m_z = 0x622;
    m_sprite.m_polygonID = 8;
}

CFieldEffect *CFieldEffectBulletFactory::Create(int arg)
{
    return new CFieldEffectBullet(arg);
}
