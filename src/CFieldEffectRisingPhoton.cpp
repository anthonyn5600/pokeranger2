#include "field/CFieldEffectRisingPhoton.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "Camera2D.hpp"
#include "file/CArchiveGuard.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;

CFieldEffectRisingPhoton::CFieldEffectRisingPhoton()
    : m_count(0)
    , m_photons(NULL)
    , m_sprites(NULL)
    , m_fadeInTime(120)
    , m_speed(FX32_ONE)
{
    m_color = GX_RGB(31, 31, 31);
    LoadTextures();
}

CFieldEffectRisingPhoton::~CFieldEffectRisingPhoton()
{
    for (int i = 0; i < 2; i++) {
        m_tex[i].ReleaseFiles();
    }
    SAFE_DELETE_ARRAY(m_sprites);
    SAFE_DELETE_ARRAY(m_photons);
}

int CFieldEffectRisingPhoton::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 21:
        if (value > 0) {
            m_count = value;
            m_photons = new Photon[m_count];
            m_sprites = new CSimpleSpriteNTF[m_count * 2];
            for (int i = 0; i < m_count * 2; i++) {
                m_sprites[i].unk_18 = &m_tex[i & 1];
                m_sprites[i].unk_4C = 0x10000;
                m_sprites[i].unk_50 = 0x10000;
                m_sprites[i].SetTexCoords(0, 0, 0x40000, 0x40000);
                m_sprites[i].m_polygonID = (i & 0x1F) + 8;
                m_sprites[i].m_alpha = 0;
            }
        } else {
            m_count = 0;
            SAFE_DELETE_ARRAY(m_sprites);
            SAFE_DELETE_ARRAY(m_photons);
        }
        break;
    case 24:
        m_fadeInTime = value;
        break;
    case 25:
        m_speed = (value << 12) / 60;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

int CFieldEffectRisingPhoton::sub_02033244(int arg0, int arg1, int arg2)
{
    int ret = 1;
    if (arg0 == 22) {
        if (m_count > 0 && m_photons != NULL && m_sprites != NULL && arg2 == m_count * 3) {
            int *data = (int *)arg1;
            for (int i = 0; i < m_count; i++) {
                Photon *p = &m_photons[i];
                p->x = data[0] << 12;
                p->y = data[1] << 12;
                p->delay = data[2];
                CSimpleSpriteNTF *s = &m_sprites[i * 2];
                s->m_coords[0] = p->x;
                s->m_coords[1] = p->y;
                s = &m_sprites[i * 2 + 1];
                s->m_coords[0] = p->x;
                s->m_coords[1] = p->y;
                data += 3;
            }
        } else {
            ret = 0;
        }
    } else {
        ret = 0;
    }
    return ret;
}

int CFieldEffectRisingPhoton::IsReady()
{
    if (m_readyFrames >= 2) {
        return 1;
    }
    return 0;
}

BOOL CFieldEffectRisingPhoton::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    for (int i = 0; i < m_count; i++) {
        Photon *p = &m_photons[i];
        if (p->delay > 0) {
            p->state = 0;
        } else if (m_fadeInTime > 0) {
            p->state = 1;
        } else {
            p->state = 2;
        }
        p->timer = 0;
    }
    return CFieldEffect::ov0_021421F0(inTime, holdTime, outTime);
}

int CFieldEffectRisingPhoton::ov0_02142264(int step)
{
    if (m_readyFrames < 2) {
        m_readyFrames++;
    }
    int ret = CFieldEffect::ov0_02142264(step);
    if (ret != 0 && ret != 4) {
        int active = 0;
        Camera2D *camera = MAIN_BSS_0210CA40->m_camera;
        for (int i = 0; i < m_count; i++) {
            Photon *p = &m_photons[i];
            if (p->state == 3) {
                continue;
            }
            active++;
            switch (p->state) {
            case 0:
                p->timer += step;
                if (p->timer >= p->delay) {
                    p->timer -= p->delay;
                    p->state = 1;
                }
                break;
            case 1: {
                p->y -= m_speed;
                int alpha = p->timer;
                if (alpha >= 30) {
                    alpha = 31;
                }
                m_sprites[i * 2].m_alpha = alpha;
                m_sprites[i * 2 + 1].m_alpha = alpha;
                CSimpleSpriteNTF *s = &m_sprites[i * 2];
                s->m_coords[0] = p->x;
                s->m_coords[1] = p->y;
                s = &m_sprites[i * 2 + 1];
                s->m_coords[0] = p->x;
                s->m_coords[1] = p->y;
                p->timer += step;
                if (p->timer >= m_fadeInTime) {
                    p->timer -= m_fadeInTime;
                    p->state = 2;
                }
                break;
            }
            case 2: {
                p->y -= FX32_MUL(m_speed, 0xA000);
                m_sprites[i * 2].m_alpha = 31;
                m_sprites[i * 2 + 1].m_alpha = 31;
                CSimpleSpriteNTF *s = &m_sprites[i * 2];
                s->m_coords[0] = p->x;
                s->m_coords[1] = p->y;
                s = &m_sprites[i * 2 + 1];
                s->m_coords[0] = p->x;
                s->m_coords[1] = p->y;
                p->timer += step;
                if (camera != NULL) {
                    Rectangle r;
                    r.pos.x = p->x;
                    r.pos.y = p->y;
                    r.size.x = r.size.y = 0x10000;
                    if (!camera->IsRectVisible(&r, 0x1199)) {
                        p->timer = 0;
                        p->state = 3;
                    }
                }
                break;
            }
            default:
                active--;
                break;
            }
        }
        if (active == 0) {
            ov0_02142240(0);
            ret = 4;
        }
    }
    return ret;
}

int CFieldEffectRisingPhoton::ov0_02142344(Camera2D *camera)
{
    if (m_state != 0 && m_state != 4) {
        for (int i = 0; i < m_count; i++) {
            if (m_photons[i].state == 1 || m_photons[i].state == 2) {
                CGame *game = CGame::GetInstance();
                MATHRandContext32 *rand = &game->m_rand32;
                fx32 scale = MATH_Rand32(rand, 2) ? 0x1333 : 0x1000;
                CSimpleSpriteNTF *s = &m_sprites[i * 2];
                s->m_scale[1] = scale;
                s->m_scale[0] = scale;
                m_sprites[i * 2].Render(camera);
                m_sprites[i * 2 + 1].m_color = m_color;
                s = &m_sprites[i * 2 + 1];
                s->m_scale[1] = scale;
                s->m_scale[0] = scale;
                m_sprites[i * 2 + 1].Render(camera);
            }
        }
    }
    return 0;
}

void CFieldEffectRisingPhoton::LoadTextures()
{
    CArchiveGuard guard("MEF", "data/Field/Effect/ef100_LZ.bin", 1, 1, 0, NULL, 0);
    m_tex[0].LoadDeferred("MEF:ef100_00.ntft", "MEF:ef100_00.ntfp", 0);
    m_tex[0].unk_1C = 6;
    m_tex[0].unk_20 = 3;
    m_tex[0].unk_24 = 3;
    m_tex[1].LoadDeferred("MEF:ef100_02.ntft", "MEF:ef100_02.ntfp", 0);
    m_tex[1].unk_1C = 6;
    m_tex[1].unk_20 = 3;
    m_tex[1].unk_24 = 3;
    m_readyFrames = 0;
}

CFieldEffect *CFieldEffectRisingPhotonFactory::Create(int arg)
{
    return new CFieldEffectRisingPhoton();
}

void CFieldEffectRisingPhoton::SetColor(u16 color)
{
    m_color = color;
}

int CFieldEffectRisingPhoton::GetEffectId()
{
    return 24;
}
