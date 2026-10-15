#include "field/CFieldEffectLaser.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "fx_utils.hpp"

extern "C" void LogInfo(const char *fmt, ...);

CFieldEffectLaser::CFieldEffectLaser(int kind)
{
    CFieldEffectAttackActorData *data = new CFieldEffectAttackActorData();
    if (data != NULL) {
        data->ov0_0214FFF0(kind, 1, 3);
    }
    unk_18 = data;
    for (int i = 0; i < 3; i++) {
        CellAnimController *cac = unk_18->GetCac(i);
        if (cac != NULL) {
            m_cacIds[i] = cac->Create(1, 0);
        } else {
            m_cacIds[i] = 0xFFFF;
        }
        LogInfo("childid= %d", m_cacIds[i]);
    }
    InitSprites();
    m_pos.x = 0;
    m_pos.y = 0;
    m_head.x = 0;
    m_head.y = 0;
    m_end.x = 0;
    m_end.y = 0;
    m_vel.x = 0;
    m_vel.y = 0;
    m_widthIn = 0x1000;
    m_widthOut = 0x1000;
    m_length = 0;
    m_width = 0x1000;
    if (kind == 0x36) {
        m_midWidth = 0x1333;
    } else {
        m_midWidth = 0x1000;
    }
}

CFieldEffectLaser::~CFieldEffectLaser()
{
    for (int i = 0; i < 3; i++) {
        unk_18->GetCac(i)->Remove(m_cacIds[i]);
    }
    SAFE_DELETE(unk_18);
}

int CFieldEffectLaser::ov0_02142264(int step)
{
    int state = CFieldEffectActor::ov0_02142264(step);
    if (state != 0 && state != 4 && unk_18 != NULL) {
        unk_18->Update();
    }
    switch (state) {
    case 1:
        m_width += m_widthIn;
        if (m_width > 0x1000) {
            m_width = 0x1000;
        }
        m_head += m_vel;
        break;
    case 3:
        m_width -= m_widthOut;
        if (m_width < 0) {
            m_width = 0;
        }
        break;
    case 2:
        m_width = 0x1000;
        break;
    }
    Point2D d = m_head - m_pos;
    fx32 sq = FX32_MUL(d.x, d.x) + FX32_MUL(d.y, d.y);
    if (sq == 0) {
        m_length = 0;
    } else {
        m_length = FX_Sqrt(sq) >> 4;
    }
    return state;
}

int CFieldEffectLaser::ov0_02142344(Camera2D *camera)
{
    if (m_state != 4 && m_state != 0) {
        m_sprites[0].SetPos(m_pos);
        m_sprites[1].SetPos((m_head + m_pos) * 0x800);
        m_sprites[1].m_scale[0] = m_length;
        m_sprites[2].SetPos(m_head);
        for (int i = 0; i < 3; i++) {
            if (i != 2 || m_length >= 0x1000) {
                CellAnimController *cac = unk_18->GetCac(i);
                if (i != 1) {
                    m_sprites[i].m_scale[1] = m_width;
                } else {
                    m_sprites[i].m_scale[1] = FX32_MUL(m_width, m_midWidth);
                }
                if (cac != NULL) {
                    m_sprites[i].m_cellDataIdx = cac->GetCell(m_cacIds[i]);
                }
                m_sprites[i].Render(camera);
            }
        }
    }
    return 0;
}

int CFieldEffectLaser::SetParam(int param, int value)
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

BOOL CFieldEffectLaser::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    m_head.x = m_pos.x;
    m_head.y = m_pos.y;
    m_width = 0;
    m_length = 0;
    if (inTime <= 0) {
        m_widthIn = 0x1000;
    } else {
        m_widthIn = FX32_DIV(0x1000, inTime << 12);
    }
    if (outTime <= 0) {
        m_widthOut = 0x1000;
    } else {
        m_widthOut = FX32_DIV(0x1000, outTime << 12);
    }
    Point2D dir = m_end - m_head;
    if (FX32_MUL(dir.x, dir.x) + FX32_MUL(dir.y, dir.y) != 0) {
        if (inTime > 0) {
            Point2D vel = dir / (inTime << 12);
            m_vel = vel;
        } else {
            m_vel = dir;
            m_head = m_end;
        }
    } else {
        m_vel.x = 0;
        m_vel.y = 0;
    }
    u16 angle = FX_Atan2Idx(dir.y, dir.x);
    for (int i = 0; i < 3; i++) {
        m_sprites[i].m_rotAngle = angle;
    }
    return CFieldEffect::ov0_021421F0(inTime, holdTime, outTime);
}

void CFieldEffectLaser::InitSprites()
{
    for (int i = 0; i < 3; i++) {
        m_sprites[i].SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(i), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)unk_18->GetPalette(), (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(i));
        m_sprites[i].m_cellDataIdx = 0;
        m_sprites[i].m_polygonID = i + 8;
    }
    m_sprites[0].m_z = 0x622;
    m_sprites[1].m_z = 0x618;
    m_sprites[2].m_z = 0x622;
}

CFieldEffect *CFieldEffectLaserFactory::Create(int arg)
{
    return new CFieldEffectLaser(arg);
}
