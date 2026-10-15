#include "field/CFieldEffectSlime.hpp"

#include <nitro.h>

#include "MathUtil.hpp"
#include "field/CFieldEnemy.hpp"
#include "field/CFieldPlayer.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;

CFieldEffectSlime::CFieldEffectSlime()
    : m_cacId(0)
    , m_timer(0)
    , m_actor(NULL)
    , m_kind(0)
    , m_param(0)
    , m_type(-1)
    , m_flags(0)
{
}

CFieldEffectSlime::~CFieldEffectSlime()
{
    if (unk_18 != NULL) {
        CellAnimController *cac = unk_18->GetCac(0);
        if (cac != NULL) {
            cac->Remove(m_cacId);
        }
    }
}

void CFieldEffectSlime::Init(int type, CEffectActorData *data, int kind)
{
    m_type = type;
    m_actor = NULL;
    m_kind = kind;
    m_param = 0;
    m_flags |= 2;
    unk_18 = data;
    CellAnimController *cac = data->GetCac(0);
    if (cac != NULL) {
        m_cacId = cac->Create(1, 0);
    }
    InitSprites();
    MI_CpuFill8(m_puddles, 0, sizeof(m_puddles));
}

int CFieldEffectSlime::ov0_02142264(int step)
{
    int state = CFieldEffectActor::ov0_02142264(step);
    if (state != 0 && state != 4) {
        m_timer -= step;
        if (m_timer <= 0) {
            if (m_flags & 2) {
                AddPuddle();
            }
            m_timer = 0x1E;
        }
        for (int i = 0; i < 5; i++) {
            if (m_puddles[i].life > 0) {
                m_puddles[i].life -= step;
                UpdatePuddle(i);
                CFieldEffectManage *mgr = MAIN_BSS_0210CA60;
                if (mgr->unk_87C == 0 && IsTouchingPlayer(&m_puddles[i].pos) && m_param > 0) {
                    mgr->unk_7B0.ov0_02163A08(m_kind, 0, m_puddles[i].pos.x >> 12, m_puddles[i].pos.y >> 12, m_param);
                }
            }
        }
    }
    return state;
}

int CFieldEffectSlime::ov0_02142344(Camera2D *camera)
{
    if (m_state != 0 && m_state != 4) {
        CellAnimController *cac = unk_18->GetCac(0);
        u16 cell = 0;
        if (cac != NULL) {
            cell = cac->GetCell(m_cacId);
        }
        CFieldEffectManage *mgr = MAIN_BSS_0210CA60;
        int layer = m_actor->m_layer;
        if (layer < 0) {
            layer = 0;
        }
        int z = mgr->unk_790[layer];
        for (int i = 0; i < 5; i++) {
            if (m_puddles[i].life > 0) {
                m_sprites[i].m_cellDataIdx = (u16)cell;
                m_sprites[i].SetPos(m_puddles[i].pos);
                m_sprites[i].m_alpha = m_puddles[i].alpha;
                m_sprites[i].SetScale(m_puddles[i].scale, m_puddles[i].scale);
                m_sprites[i].m_z = z;
                m_sprites[i].Render(camera);
            }
        }
    }
    return 1;
}

int CFieldEffectSlime::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 1:
        for (int i = 0; i < 5; i++) {
            m_puddles[i].pos.x = value << 12;
        }
        break;
    case 2:
        for (int i = 0; i < 5; i++) {
            m_puddles[i].pos.y = value << 12;
        }
        break;
    case 17:
        if (MAIN_BSS_0210CA40 != NULL) {
            m_actor = MAIN_BSS_0210CA40->ov0_02123060(value);
            if (m_actor != NULL && (m_flags & 0x8000)) {
                BOOL isEnemy;
                if ((u8)(value >> 24) == 1) {
                    isEnemy = TRUE;
                } else {
                    isEnemy = FALSE;
                }
                if (isEnemy) {
                    m_param = ((CFieldEnemy *)m_actor)->unk_130;
                }
            }
        }
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

BOOL CFieldEffectSlime::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    if (m_actor == NULL) {
        return FALSE;
    }
    ov0_021633B8();
    return CFieldEffect::ov0_021421F0(0, -1, 0);
}

void CFieldEffectSlime::Reset(BOOL keepParam)
{
    MI_CpuFill8(m_puddles, 0, sizeof(m_puddles));
    if (keepParam) {
        m_flags |= 0x8000;
    }
}

void CFieldEffectSlime::AddPuddle()
{
    for (int i = 0; i < 5; i++) {
        if (m_puddles[i].life == 0) {
            m_puddles[i].pos = m_actor->GetPos();
            m_puddles[i].scale = 0x800;
            m_puddles[i].life = 0x96;
            m_puddles[i].alpha = 0x1F;
            return;
        }
    }
}

void CFieldEffectSlime::UpdatePuddle(int i)
{
    if (m_puddles[i].life <= 0) {
        m_puddles[i].life = 0;
        m_puddles[i].alpha = 0;
    } else if (m_puddles[i].life > 0x5A) {
        m_puddles[i].scale = (((0x96 - m_puddles[i].life) << 12) >> 7) + 0x800;
        m_puddles[i].alpha = 0x1F;
    } else {
        m_puddles[i].scale = 0x1000;
        if (m_puddles[i].life < 0x1E) {
            m_puddles[i].alpha = m_puddles[i].life;
        } else {
            m_puddles[i].alpha = 0x1F;
        }
    }
}

void CFieldEffectSlime::InitSprites()
{
    for (int i = 0; i < 5; i++) {
        m_sprites[i].SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(0), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)unk_18->GetPalette(), (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(0));
        m_sprites[i].m_cellDataIdx = 0;
        m_sprites[i].m_polygonID = i + 8;
    }
}

int CFieldEffectSlime::ov0_0214239C(int layer)
{
    return 0xA;
}

BOOL CFieldEffectSlime::IsTouchingPlayer(const Point2D *pos)
{
    CFieldPlayer *player = (CFieldPlayer *)MAIN_BSS_0210CA40->ov0_02123060(0);
    fx32 range = player->unk_E0 + 0x9000;
    Point2D d = player->GetPos() - *pos;
    if (ApproxLength(d.x, d.y) < range) {
        return TRUE;
    }
    return FALSE;
}

void CFieldEffectSlime::ov0_021633B8()
{
    m_flags &= ~2;
}

void CFieldEffectSlime::ov0_021633CC()
{
    if (!(m_flags & 2)) {
        AddPuddle();
        m_timer = 0x1E;
        m_flags |= 2;
    }
}

int CFieldEffectSlime::ov0_02142390(void *buf, void *end)
{
    SlimeSave save;
    u8 mask = 0;
    MI_CpuFill8(&save, 0, sizeof(save));
    int kind = -1;
    switch (m_type) {
    case 0x84:
        kind = 0;
        break;
    case 0x85:
        kind = 1;
        break;
    case 0x86:
        if (m_flags & 0x8000) {
            kind = 3;
        } else {
            kind = 2;
        }
        break;
    }
    if (kind >= 0) {
        save.type = (kind << 6) | 0x12;
        save.actorId = m_actor->m_id;
        save.param = m_param;
        for (int i = 0; i < 5; i++) {
            if (m_puddles[i].life > 0) {
                mask |= 1 << i;
                save.pos[i].x = m_puddles[i].pos.x >> 12;
                save.pos[i].y = m_puddles[i].pos.y >> 12;
                save.age[i] = 0x96 - m_puddles[i].life;
            }
        }
        if (m_state == 3) {
            mask |= 0x80;
        }
        save.mask = mask;
        if ((u32)buf + sizeof(save) <= (u32)end) {
            MI_CpuCopy8(&save, buf, sizeof(save));
            return sizeof(save);
        }
    }
    return 0;
}

BOOL CFieldEffectSlime::ov0_02142388(const void *data)
{
    const SlimeSave *save = (const SlimeSave *)data;
    for (int i = 0; i < 5; i++) {
        m_param = save->param;
        if (save->mask & (1 << i)) {
            m_puddles[i].life = 0x96 - save->age[i];
            m_puddles[i].pos.x = save->pos[i].x << 12;
            m_puddles[i].pos.y = save->pos[i].y << 12;
            UpdatePuddle(i);
        }
    }
    if (save->actorId != 0) {
        if (MAIN_BSS_0210CA40 != NULL) {
            m_actor = MAIN_BSS_0210CA40->ov0_02123060(save->actorId);
        }
        if (save->mask & 0x80) {
            CFieldEffect::ov0_021421F0(0, 0, 0x96);
        } else {
            CFieldEffect::ov0_021421F0(0, -1, 0);
        }
        return TRUE;
    }
    return FALSE;
}

CFieldEffectSlimeFactory::CFieldEffectSlimeFactory(CFieldEffectManage *mgr)
    : m_type(-1)
    , m_kind(-1)
    , m_pool(NULL)
{
    if (mgr != NULL) {
        m_kind = mgr->unk_7B0.ov0_02163904(2);
    }
}

CFieldEffectSlimeFactory::~CFieldEffectSlimeFactory()
{
    Release();
}

CFieldEffect *CFieldEffectSlimeFactory::Create(int arg)
{
    CFieldEffectSlime *effect = NULL;
    if (m_type == (arg & 0xFF) && m_data.IsLoaded() && m_pool != NULL) {
        for (int i = 0; i < 4; i++) {
            if (!(m_pool[i].m_flags & 1)) {
                effect = &m_pool[i];
                effect->Reset(arg >= 0x400);
                m_pool[i].m_flags = m_pool[i].m_flags | 1;
                break;
            }
        }
    }
    return effect;
}

BOOL CFieldEffectSlimeFactory::Load(int type)
{
    if (m_data.ov0_0214FFF0(type, 1, 1)) {
        SAFE_DELETE_ARRAY(m_pool);
        m_pool = new CFieldEffectSlime[4];
        for (int i = 0; i < 4; i++) {
            m_pool[i].Init(type, &m_data, m_kind);
        }
        m_type = type;
        return TRUE;
    }
    return FALSE;
}

void CFieldEffectSlimeFactory::Release()
{
    SAFE_DELETE_ARRAY(m_pool);
    m_data.Release();
    m_type = -1;
}

void CFieldEffectSlimeFactory::Update(int frames)
{
    m_data.Update();
}

void CFieldEffectSlimeFactory::Reset()
{
    Release();
}
