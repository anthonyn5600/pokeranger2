#include "field/CFieldEffectBlackStoneAura.hpp"

#include "field/CFieldActor.hpp"
#include "file/CArchiveGuard.hpp"
#include "fx_utils.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;

static u16 sColors0[2] = { 0x0000, 0x6010 };
static u16 sColors1[3] = { 0x211F, 0x23FF, 0x7D08 };

static inline BOOL IsTextureReady(UnkClass_02151244 *tex)
{
    return tex->unk_28 != OS_GetVBlankCount() ? TRUE : FALSE;
}

CFieldEffectBlackStoneAura::CFieldEffectBlackStoneAura(int mode)
    : m_mode(mode)
    , m_actor(NULL)
{
    m_next = 0;
    m_tex = NULL;
    m_life = 60;
    m_spawnTimer = 0;
    m_scaleFrom = 0x1000;
    m_scaleTo = 0x2000;
    m_alphaFrom = 0;
    m_alphaTo = 20;
    m_period = 60;
    m_colorIdx = 0;
    for (int i = 0; i < 4; i++) {
        m_rings[i].life = 0;
        m_sprites[i].m_alpha = 0;
        m_sprites[i].m_z = -1 - i;
        m_sprites[i].m_polygonID = i + 8;
        m_sprites[i].unk_4C = 0x60000;
        m_sprites[i].unk_50 = 0x60000;
        m_sprites[i].m_s1 = 0;
        m_sprites[i].m_t1 = 0;
        m_sprites[i].m_s2 = 0x40000;
        m_sprites[i].m_t2 = 0x40000;
        m_order[i] = -1;
    }
    m_sprites[0].m_color = 0x1F;
    m_sprites[1].m_color = 0x7C00;
    m_sprites[2].m_color = 0x3FF;
    m_offset.x = m_offset.y = 0;
}

CFieldEffectBlackStoneAura::~CFieldEffectBlackStoneAura()
{
}

int CFieldEffectBlackStoneAura::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 1:
        m_offset.x = value << 12;
        for (int i = 0; i < 4; i++) {
            m_sprites[i].m_coords[0] = m_offset.x;
        }
        break;
    case 2:
        m_offset.y = value << 12;
        for (int i = 0; i < 4; i++) {
            m_sprites[i].m_coords[1] = m_offset.y;
        }
        break;
    case 3:
        for (int i = 0; i < 4; i++) {
            m_sprites[i].unk_4C = value << 12;
        }
        break;
    case 4:
        for (int i = 0; i < 4; i++) {
            m_sprites[i].unk_50 = value << 12;
        }
        break;
    case 17:
        if (MAIN_BSS_0210CA40 != NULL) {
            m_actor = MAIN_BSS_0210CA40->FindActor(value);
        }
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

void CFieldEffectBlackStoneAura::SetTexture(UnkClass_02151244 *tex)
{
    m_tex = tex;
    for (int i = 0; i < 4; i++) {
        m_sprites[i].unk_18 = m_tex;
    }
}

BOOL CFieldEffectBlackStoneAura::Start(int inTime, int holdTime, int outTime)
{
    m_spawnTimer = 1;
    m_colorIdx = 0;
    return CFieldEffect::Start(inTime, holdTime, outTime);
}

int CFieldEffectBlackStoneAura::Update(int step)
{
    int state = CFieldEffect::Update(step);
    fx32 fade;
    switch (state) {
    case 1:
        fade = (m_frame << 12) / m_inTime;
        break;
    case 3:
        fade = ((m_outTime - m_frame) << 12) / m_outTime;
        break;
    default:
        fade = FX32_ONE;
        break;
    }
    for (int i = 0; i < 4; i++) {
        if (m_rings[i].life > 0) {
            m_rings[i].life -= step;
            m_rings[i].frame += step;
            int period = m_period;
            u16 t = m_rings[i].frame % period;
            fx32 phase = FX32_DIV(t << 12, period << 12);
            fx32 alpha;
            if (phase < 0x800) {
                alpha = FX32_MUL(phase, (m_alphaTo - m_alphaFrom) << 12) + (m_alphaFrom << 12);
            } else {
                alpha = FX32_MUL(phase, (m_alphaFrom - m_alphaTo) << 12) + (m_alphaTo << 12);
            }
            m_sprites[i].m_alpha = FX32_MUL(alpha, fade) >> 12;
            fx32 scale = m_scaleTo - FX32_DIV((m_scaleTo - m_scaleFrom) * m_rings[i].life, m_life << 12);
            m_sprites[i].m_scale[0] = m_sprites[i].m_scale[1] = scale;
            if (m_rings[i].life <= 0) {
                m_order[m_rings[i].order] = -1;
            }
        }
    }
    if (m_spawnTimer > 0) {
        m_spawnTimer -= step;
        if (m_spawnTimer <= 0) {
            Spawn();
            if (m_mode == 0) {
                m_spawnTimer = m_life / 2;
            } else {
                m_spawnTimer = m_life / 3;
            }
        }
    }
    return state;
}

int CFieldEffectBlackStoneAura::Render(Camera2D *camera)
{
    int idx = m_next;
    int n = 0;
    for (int j = 0; j < 4; j++) {
        int k = m_order[idx];
        if (k >= 0 && m_rings[k].life > 0) {
            m_sprites[k].m_z = n - 5;
            m_sprites[k].Render(camera);
            n++;
        }
        if (++idx >= 4) {
            idx = 0;
        }
    }
    return 0;
}

void CFieldEffectBlackStoneAura::Spawn()
{
    for (int i = 0; i < 4; i++) {
        if (m_rings[i].life <= 0) {
            m_rings[i].life = m_life;
            m_rings[i].frame = 0;
            m_sprites[i].m_alpha = m_alphaFrom;
            if (m_mode == 0) {
                m_sprites[i].m_color = sColors0[m_colorIdx];
            } else {
                m_sprites[i].m_color = sColors1[m_colorIdx];
            }
            m_colorIdx++;
            if ((m_mode == 0 && m_colorIdx >= 2) || (m_mode == 1 && m_colorIdx >= 3)) {
                m_colorIdx = 0;
            }
            m_order[m_next] = i;
            m_rings[i].order = m_next;
            if (++m_next >= 4) {
                m_next = 0;
            }
            return;
        }
    }
}

CFieldEffectBlackStoneAuraFactory::~CFieldEffectBlackStoneAuraFactory()
{
    ReleaseTextures();
}

CFieldEffect *CFieldEffectBlackStoneAuraFactory::Create(int arg)
{
    CFieldEffectBlackStoneAura *effect = NULL;
    BOOL ok = TRUE;
    if (m_tex.m_texAddr == 0) {
        ok = LoadTexture();
    }
    if (ok) {
        effect = new CFieldEffectBlackStoneAura(arg);
        if (effect != NULL) {
            effect->SetTexture(&m_tex);
        }
    }
    return effect;
}

void CFieldEffectBlackStoneAuraFactory::Reset()
{
    ReleaseTextures();
}

BOOL CFieldEffectBlackStoneAuraFactory::LoadTexture()
{
    CArchiveGuard guard("FEF", "data/field/effect/ef101_LZ.bin", 1, 1, 0, NULL, 0);
    const char *ntfp = "FEF:ef101_00.ntfp";
    const char *ntft = "FEF:ef101_00.ntft";
    if (m_tex.LoadDeferred(ntft, ntfp, 0)) {
        m_tex.unk_28 = OS_GetVBlankCount();
    }
    m_tex.unk_1C = 6;
    m_tex.unk_20 = 3;
    m_tex.unk_24 = 3;
    return TRUE;
}

void CFieldEffectBlackStoneAuraFactory::ReleaseTextures()
{
    m_tex.Release();
}

int CFieldEffectBlackStoneAura::IsReady()
{
    BOOL ret = TRUE;
    if (m_tex != NULL && !IsTextureReady(m_tex)) {
        ret = FALSE;
    }
    return ret;
}

int CFieldEffectBlackStoneAura::GetEffectId()
{
    return 0x1C;
}
