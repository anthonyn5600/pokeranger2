#include "field/CFieldEffectPoisonGas.hpp"

#include <nitro.h>

#include "MathUtil.hpp"
#include "field/CFieldPlayer.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;

CFieldEffectPoisonGas::CFieldEffectPoisonGas()
    : m_kind(0)
    , m_cacId(0)
    , m_param(0)
    , m_used(FALSE)
{
}

CFieldEffectPoisonGas::~CFieldEffectPoisonGas()
{
    if (unk_18 != NULL) {
        CellAnimController *cac = unk_18->GetCac(0);
        if (cac != NULL) {
            cac->Remove(m_cacId);
        }
    }
}

void CFieldEffectPoisonGas::Init(CEffectActorData *data, int kind)
{
    m_kind = kind;
    m_param = 0;
    unk_18 = data;
    CellAnimController *cac = data->GetCac(0);
    if (cac != NULL) {
        m_cacId = cac->Create(1, 0);
    }
    InitSprites();
    MI_CpuFill8(m_puffs, 0, sizeof(m_puffs));
}

int CFieldEffectPoisonGas::Update(int step)
{
    int state = CFieldEffectActor::Update(step);
    if (state != 0 && state != 4) {
        int alive = 0;
        for (int i = 0; i < 4; i++) {
            if (m_puffs[i].life > 0) {
                m_puffs[i].pos.x += step * m_puffs[i].vel.x;
                m_puffs[i].pos.y += step * m_puffs[i].vel.y;
                m_puffs[i].vel.x += step * m_puffs[i].accel.x;
                m_puffs[i].vel.y += step * m_puffs[i].accel.y;
                m_puffs[i].life -= step;
                if (m_puffs[i].life < 0x1E) {
                    m_puffs[i].alpha = m_puffs[i].life;
                } else {
                    CFieldEffectManage *mgr = MAIN_BSS_0210CA60;
                    if (mgr->unk_87C == 0 && IsTouchingPlayer(&m_puffs[i].pos)) {
                        mgr->unk_7B0.CallEventHandle(m_kind, 0, m_puffs[i].pos.x >> 12, m_puffs[i].pos.y >> 12, m_param);
                        m_puffs[i].life = 0;
                    }
                }
                alive++;
            }
        }
        if (alive == 0) {
            Stop(0);
        }
    }
    return state;
}

int CFieldEffectPoisonGas::Render(Camera2D *camera)
{
    if (m_state != 0 && m_state != 4) {
        CellAnimController *cac = unk_18->GetCac(0);
        u16 cell = 0;
        if (cac != NULL) {
            cell = cac->GetCell(m_cacId);
        }
        for (int i = 0; i < 4; i++) {
            if (m_puffs[i].life > 0) {
                // The redundant cast is a hoisted loop-invariant temp: cell is colored after the loop pointers.
                m_sprites[i].m_cellDataIdx = (u16)cell;
                m_sprites[i].SetPos(m_puffs[i].pos);
                m_sprites[i].m_alpha = m_puffs[i].alpha;
                m_sprites[i].Render(camera);
            }
        }
    }
    return 1;
}

int CFieldEffectPoisonGas::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 1:
        m_pos.x = value << 12;
        for (int i = 0; i < 4; i++) {
            m_puffs[i].pos.x = m_pos.x;
        }
        break;
    case 2:
        m_pos.y = value << 12;
        for (int i = 0; i < 4; i++) {
            m_puffs[i].pos.y = m_pos.y;
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

BOOL CFieldEffectPoisonGas::Start(int inTime, int holdTime, int outTime)
{
    for (int i = 0; i < 4; i++) {
        m_puffs[i].life = 0x5A;
        m_puffs[i].alpha = 0x1F;
    }
    m_puffs[0].vel.x = 0xE66;
    m_puffs[0].vel.y = 0xE66;
    m_puffs[1].vel.x = -0xE66;
    m_puffs[1].vel.y = 0xE66;
    m_puffs[2].vel.x = 0xE66;
    m_puffs[2].vel.y = -0xE66;
    m_puffs[3].vel.x = -0xE66;
    m_puffs[3].vel.y = -0xE66;
    m_puffs[0].accel.x = -0x21;
    m_puffs[0].accel.y = -0x21;
    m_puffs[1].accel.x = 0x21;
    m_puffs[1].accel.y = -0x21;
    m_puffs[2].accel.x = -0x21;
    m_puffs[2].accel.y = 0x21;
    m_puffs[3].accel.x = 0x21;
    m_puffs[3].accel.y = 0x21;
    return CFieldEffect::Start(0, -1, 0);
}

void CFieldEffectPoisonGas::InitSprites()
{
    for (int i = 0; i < 4; i++) {
        m_sprites[i].SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(0), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)unk_18->GetPalette(), (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(0));
        m_sprites[i].m_cellDataIdx = 0;
        m_sprites[i].m_polygonID = i + 8;
        m_sprites[i].m_z = -1;
    }
}

BOOL CFieldEffectPoisonGas::IsTouchingPlayer(const Point2D *pos)
{
    CFieldPlayer *player = (CFieldPlayer *)MAIN_BSS_0210CA40->FindActor(0);
    fx32 range = player->unk_E0 + 0xB000;
    Point2D d = player->GetPos() - *pos;
    if (ApproxLength(d.x, d.y) < range) {
        return TRUE;
    }
    return FALSE;
}

int CFieldEffectPoisonGas::SaveState(void *buf, void *end)
{
    PoisonGasSave save;
    u8 mask = 0;
    MI_CpuFill8(&save, 0, sizeof(save));
    save.type = 0xC;
    save.unk_1C = -1;
    save.param = m_param;
    for (int i = 0; i < 4; i++) {
        if (m_puffs[i].life > 0) {
            mask |= 1 << i;
            save.pos[i].x = m_puffs[i].pos.x >> 12;
            save.pos[i].y = m_puffs[i].pos.y >> 12;
            save.age[i] = 0x5A - m_puffs[i].life;
        }
    }
    save.mask = mask;
    if ((u32)buf + sizeof(save) > (u32)end) {
        return 0;
    }
    MI_CpuCopy8(&save, buf, sizeof(save));
    return sizeof(save);
}

BOOL CFieldEffectPoisonGas::RestoreState(const void *data)
{
    const PoisonGasSave *save = (const PoisonGasSave *)data;
    int count = 0;
    // The original walks five clouds.
    for (int i = 0; i < 5; i++) {
        m_param = save->param;
        if (save->mask & (1 << i)) {
            count++;
            m_puffs[i].life = 0x5A - save->age[i];
            m_puffs[i].pos.x = save->pos[i].x << 12;
            m_puffs[i].pos.y = save->pos[i].y << 12;
            if (m_puffs[i].life < 0x1E) {
                m_puffs[i].alpha = m_puffs[i].life;
            } else {
                m_puffs[i].alpha = 0x1F;
            }
        }
    }
    if (count > 0) {
        m_puffs[0].vel.x = 0xE66;
        m_puffs[0].vel.y = 0xE66;
        m_puffs[0].accel.x = -0x21;
        m_puffs[0].accel.y = -0x21;
        m_puffs[1].vel.x = -0xE66;
        m_puffs[1].vel.y = 0xE66;
        m_puffs[1].accel.x = 0x21;
        m_puffs[1].accel.y = -0x21;
        m_puffs[2].vel.x = 0xE66;
        m_puffs[2].vel.y = -0xE66;
        m_puffs[2].accel.x = -0x21;
        m_puffs[2].accel.y = 0x21;
        m_puffs[3].vel.x = -0xE66;
        m_puffs[3].vel.y = -0xE66;
        m_puffs[3].accel.x = 0x21;
        m_puffs[3].accel.y = 0x21;
        CFieldEffect::Start(0, -1, 0);
        return TRUE;
    }
    return FALSE;
}

CFieldEffectPoisonGasFactory::CFieldEffectPoisonGasFactory(CFieldEffectManage *mgr)
    : m_kind(-1)
    , m_pool(NULL)
{
    if (mgr != NULL) {
        m_kind = mgr->unk_7B0.LoadScript(0);
    }
}

CFieldEffectPoisonGasFactory::~CFieldEffectPoisonGasFactory()
{
    Release();
}

CFieldEffect *CFieldEffectPoisonGasFactory::Create(int arg)
{
    CFieldEffectPoisonGas *effect = NULL;
    if (m_data.IsLoaded() && m_pool != NULL) {
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

BOOL CFieldEffectPoisonGasFactory::Load()
{
    if (m_data.Load(0x13, 1, 1)) {
        SAFE_DELETE_ARRAY(m_pool);
        m_pool = new CFieldEffectPoisonGas[3];
        for (int i = 0; i < 3; i++) {
            m_pool[i].Init(&m_data, m_kind);
        }
        return TRUE;
    }
    return FALSE;
}

void CFieldEffectPoisonGasFactory::Release()
{
    SAFE_DELETE_ARRAY(m_pool);
    m_data.Release();
}

void CFieldEffectPoisonGasFactory::Update(int frames)
{
    m_data.Update();
}

void CFieldEffectPoisonGasFactory::Reset()
{
    Release();
}
