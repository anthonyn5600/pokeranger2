#include "field/CFieldEffectExplosion.hpp"

#include <nitro.h>

#include "field/CFieldPlayer.hpp"
#include "scene/CFieldScene.hpp"
#include "sub_02007254.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;

extern "C" {
void LogInfo(const char *fmt, ...);
int ov0_02163904(UnkClass_021638B8 *obj, int type);
void ov0_02163A08(UnkClass_021638B8 *obj, int kind, int arg2, int x, int y, int param);
}

CFieldEffectExplosion::~CFieldEffectExplosion()
{
    for (int i = 0; i < 2; i++) {
        if (m_data[i] != NULL) {
            UnkClass_02008788 *cac = m_data[i]->GetCac(0);
            if (cac != NULL) {
                cac->sub_02008B80(m_cacIds[i]);
            }
        }
    }
}

void CFieldEffectExplosion::Init(CEffectActorData *data0, CEffectActorData *data1, int kind)
{
    m_kind = kind;
    m_frame = 0;
    m_param = 0;
    m_data[0] = data0;
    m_data[1] = data1;
    unk_18 = m_data[0];
    for (int i = 0; i < 2; i++) {
        UnkClass_02008788 *cac = m_data[i]->GetCac(0);
        if (cac != NULL) {
            m_cacIds[i] = cac->sub_02008A80(1, 0);
        }
    }
    InitSprites();
}

int CFieldEffectExplosion::ov0_02142264(int step)
{
    int state = CFieldEffectActor::ov0_02142264(step);
    if (state != 0 && state != 4) {
        if (m_nextPhase >= 0) {
            m_phase = m_nextPhase;
            m_nextPhase = -1;
            unk_18 = m_data[m_phase];
            UnkClass_02008788 *cac = m_data[m_phase]->GetCac(0);
            cac->sub_020089B8(m_cacIds[m_phase]);
        }
        UnkClass_02008788 *cac = m_data[m_phase]->GetCac(0);
        if (cac != NULL) {
            if (!cac->sub_02008860(m_cacIds[m_phase])) {
                if (m_phase == 0) {
                    m_nextPhase = 1;
                    m_frame = 0;
                } else if (m_phase == 1) {
                    ov0_02142240(0);
                }
            } else if (m_phase == 1 && m_frame < 0x2E) {
                CFieldEffectManage *mgr = MAIN_BSS_0210CA60;
                if (mgr->unk_87C == 0 && IsTouchingPlayer()) {
                    ov0_02163A08(&mgr->unk_7B0, m_kind, 0, m_pos.x >> 12, m_pos.y >> 12, m_param);
                }
                m_frame += step;
            }
        }
    }
    return state;
}

int CFieldEffectExplosion::ov0_02142344(Camera2D *camera)
{
    if (m_state != 0 && m_state != 4) {
        UnkClass_02008788 *cac = m_data[m_phase]->GetCac(0);
        u16 cell = 0;
        if (cac != NULL) {
            cell = cac->sub_02008828(m_cacIds[m_phase]);
        }
        m_sprites[m_phase].m_cellDataIdx = cell;
        m_sprites[m_phase].SetPos(m_pos);
        m_sprites[m_phase].Render(camera);
    }
    return 0;
}

int CFieldEffectExplosion::sub_0203312C(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 1:
        m_pos.x = value << 12;
        break;
    case 2:
        m_pos.y = value << 12;
        break;
    case 18:
        m_param = value;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

BOOL CFieldEffectExplosion::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    m_phase = 0;
    m_nextPhase = -1;
    unk_18 = m_data[0];
    UnkClass_02008788 *cac = m_data[m_phase]->GetCac(0);
    cac->sub_020089B8(m_cacIds[m_phase]);
    return CFieldEffect::ov0_021421F0(0, -1, 0);
}

void CFieldEffectExplosion::InitSprites()
{
    for (int i = 0; i < 2; i++) {
        m_sprites[i].SetResources((UnkClass_CPrimitive_ImageProxy *)m_data[i]->GetNcbr(0), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)m_data[i]->GetPalette(), (UnkClass_CSoftwareSprite_38 *)m_data[i]->GetNcer(0));
        m_sprites[i].m_cellDataIdx = 0;
        m_sprites[i].m_polygonID = 8;
        m_sprites[i].m_z = -1;
        m_sprites[i].SetScale(0x2000, 0x2000);
    }
}

BOOL CFieldEffectExplosion::IsTouchingPlayer()
{
    CFieldPlayer *player = (CFieldPlayer *)MAIN_BSS_0210CA40->ov0_02123060(0);
    fx32 range = player->unk_E0 + 0x20800;
    Point2D d = player->GetPos() - m_pos;
    if (sub_02007254(d.x, d.y) < range) {
        return TRUE;
    }
    return FALSE;
}

int CFieldEffectExplosion::ov0_02142390(void *buf, void *end)
{
    ExplosionSave save;
    UnkClass_02008788 *cac = m_data[m_phase]->GetCac(0);
    LogInfo("cell %d", cac->sub_02008828(m_cacIds[m_phase]));
    MI_CpuFill8(&save, 0, sizeof(save));
    if ((u32)m_phase <= 1 && m_frame < 0x80) {
        save.type = 0xD;
        save.unk_1C = -1;
        save.param = m_param;
        save.flags = 1;
        save.x = m_pos.x >> 12;
        save.y = m_pos.y >> 12;
        save.frame = (m_phase << 7) | (m_frame & 0x7F);
        if ((u32)buf + sizeof(save) <= (u32)end) {
            MI_CpuCopy8(&save, buf, sizeof(save));
            return sizeof(save);
        }
    }
    return 0;
}

BOOL CFieldEffectExplosion::ov0_02142388(const void *data)
{
    const ExplosionSave *save = (const ExplosionSave *)data;
    if (save->flags & 1) {
        u8 frame = save->frame;
        m_phase = (frame >> 7) & 1;
        m_nextPhase = -1;
        m_frame = frame & 0x7F;
        m_param = save->param;
        unk_18 = m_data[m_phase];
        sub_0203312C(1, save->x);
        sub_0203312C(2, save->y);
        UnkClass_02008788 *cac = m_data[m_phase]->GetCac(0);
        cac->sub_020089B8(m_cacIds[m_phase]);
        for (int n = m_frame; n >= 0; n -= 2) {
            cac->sub_020089EC();
        }
        LogInfo("cell %d", cac->sub_02008828(m_cacIds[m_phase]));
        CFieldEffect::ov0_021421F0(0, -1, 0);
        return TRUE;
    }
    return FALSE;
}

CFieldEffectExplosionFactory::CFieldEffectExplosionFactory(CFieldEffectManage *mgr)
    : m_kind(-1)
    , m_pool(NULL)
{
    if (mgr != NULL) {
        m_kind = ov0_02163904(&mgr->unk_7B0, 1);
    }
}

CFieldEffectExplosionFactory::~CFieldEffectExplosionFactory()
{
    Release();
}

CFieldEffect *CFieldEffectExplosionFactory::Create(int arg)
{
    CFieldEffectExplosion *effect = NULL;
    if (m_data[0].IsLoaded() && m_data[1].IsLoaded() && m_pool != NULL) {
        for (int i = 0; i < 3; i++) {
            if (!m_pool[i].m_used) {
                effect = &m_pool[i];
                effect->m_used = TRUE;
                break;
            }
        }
    }
    return effect;
}

BOOL CFieldEffectExplosionFactory::Load()
{
    if (m_data[0].ov0_0214FFF0(0x1C, 1, 1)) {
        if (m_data[1].ov0_0214FFF0(0x1D, 1, 1)) {
            SAFE_DELETE_ARRAY(m_pool);
            m_pool = new CFieldEffectExplosion[3];
            for (int i = 0; i < 3; i++) {
                m_pool[i].Init(&m_data[0], &m_data[1], m_kind);
            }
            return TRUE;
        }
        m_data[0].Release();
    }
    return FALSE;
}

void CFieldEffectExplosionFactory::Release()
{
    SAFE_DELETE_ARRAY(m_pool);
    m_data[0].Release();
    m_data[1].Release();
}

void CFieldEffectExplosionFactory::Update(int frames)
{
    m_data[0].Update();
    m_data[1].Update();
}

void CFieldEffectExplosionFactory::Reset()
{
    Release();
}
