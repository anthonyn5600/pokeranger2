#include "field/CFieldEffectGlitter.hpp"

#include "CGame.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldEffectManage.hpp"
#include "file/CArchiveGuard.hpp"
#include "fx_utils.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;

static inline BOOL IsTextureReady(UnkClass_02151244 *tex)
{
    return tex->unk_28 != OS_GetVBlankCount() ? TRUE : FALSE;
}

CFieldEffectGlitter::CFieldEffectGlitter()
    : m_actor(NULL)
    , m_size(8)
{
    m_tex = NULL;
    m_blinkTimer = 0;
    m_idleTimer = 0;
    m_angle1 = 0;
    m_angle2 = 0;
    m_alpha = 31;
    m_sprite.unk_4C = 0x40000;
    m_sprite.unk_50 = 0x40000;
    m_sprite.m_polygonID = 8;
    m_sprite.m_s1 = 0;
    m_sprite.m_t1 = 0;
    m_sprite.m_s2 = 0x40000;
    m_sprite.m_t2 = 0x40000;
    m_sprite.m_z = -1;
    m_offset.x = m_offset.y = 0;
}

CFieldEffectGlitter::~CFieldEffectGlitter()
{
}

void CFieldEffectGlitter::SetTexture(UnkClass_02151244 *tex)
{
    m_sprite.unk_18 = tex;
    m_tex = tex;
}

int CFieldEffectGlitter::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 1:
        m_offset.x = value << 12;
        m_sprite.m_coords[0] = m_offset.x;
        break;
    case 2:
        m_offset.y = value << 12;
        m_sprite.m_coords[1] = m_offset.y;
        break;
    case 3:
        m_sprite.unk_4C = value << 12;
        break;
    case 4:
        m_sprite.unk_50 = value << 12;
        break;
    case 17:
        if (MAIN_BSS_0210CA40 != NULL) {
            m_actor = MAIN_BSS_0210CA40->ov0_02123060(value);
        }
        break;
    case 26:
        m_alpha = value;
        if (m_alpha > 31) {
            m_alpha = 31;
        }
        break;
    case 20:
        m_size = value;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

BOOL CFieldEffectGlitter::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    if (inTime > 0) {
        m_blinkTimer = inTime;
        m_sprite.m_alpha = 0;
    }
    return CFieldEffect::ov0_021421F0(inTime, holdTime, outTime);
}

int CFieldEffectGlitter::ov0_02142264(int step)
{
    int state = CFieldEffect::ov0_02142264(step);
    if (state == 2) {
        if (m_blinkTimer > 0) {
            m_blinkTimer -= step;
            if (m_blinkTimer <= 0) {
                m_idleTimer = MATH_Rand32(&CGame::GetInstance()->m_rand32, 6) + 10;
            }
        } else {
            m_idleTimer -= step;
            if (m_idleTimer <= 0) {
                m_blinkTimer = MATH_Rand32(&CGame::GetInstance()->m_rand32, 0x33) + 10;
                m_angle2 = 0;
            }
        }
    }
    m_angle1 += (u16)(step << 7);
    m_angle2 += (u16)(step << 9);
    if (m_actor != NULL) {
        Point2D pos = m_actor->GetPos() + m_offset;
        pos.y -= m_actor->GetHeight();
        m_sprite.m_coords[0] = pos.x;
        m_sprite.m_coords[1] = pos.y;
    }
    fx32 scale;
    switch (state) {
    case 1:
        scale = (m_frame << 12) / m_inTime;
        break;
    case 2:
        scale = FX32_ONE;
        break;
    case 3:
        scale = ((m_outTime - m_frame) << 12) / m_outTime;
        break;
    }
    if (m_size != 8) {
        scale = FX32_MUL(scale, (m_size - 8) * 0x199 + FX32_ONE);
    }
    m_sprite.m_scale[0] = m_sprite.m_scale[1] = scale;
    int alpha;
    switch (state) {
    case 1:
        alpha = m_alpha * m_frame / m_inTime;
        break;
    case 2:
        alpha = m_alpha;
        break;
    case 3:
        alpha = m_alpha * (m_outTime - m_frame) / m_outTime;
        break;
    }
    m_sprite.m_alpha = alpha * (m_size + 16) / 31;
    return state;
}

int CFieldEffectGlitter::ov0_02142344(Camera2D *camera)
{
    if (m_blinkTimer > 0) {
        m_sprite.m_rotAngle = m_angle1;
        m_sprite.Render(camera);
    }
    return 0;
}

void CFieldEffectGlitter::SetColor(u16 color)
{
    m_sprite.m_color = color;
}

int CFieldEffectGlitter::SetPolygonIDs(int base)
{
    m_sprite.m_polygonID = base;
    return 1;
}

CFieldEffectGlitterFactory::~CFieldEffectGlitterFactory()
{
    ReleaseTextures();
}

void CFieldEffectGlitterFactory::Reset()
{
    ReleaseTextures();
}

CFieldEffect *CFieldEffectGlitterFactory::Create(int arg)
{
    BOOL ok = TRUE;
    CFieldEffectGlitter *effect = NULL;
    if (m_tex.m_texAddr == 0) {
        CArchiveGuard guard("MEF", "data/Field/Effect/ef100_LZ.bin", 1, 1, 0, NULL, 0);
        ok = LoadTexture(1);
    }
    if (ok) {
        effect = new CFieldEffectGlitter();
        if (effect != NULL) {
            effect->SetTexture(&m_tex);
            int n = effect->SetPolygonIDs(MAIN_BSS_0210CA60->unk_87D + 8);
            CFieldEffectManage *mgr = MAIN_BSS_0210CA60;
            mgr->unk_87D += (u8)n;
            mgr->unk_87D &= 0x1F;
        }
    }
    return effect;
}

BOOL CFieldEffectGlitterFactory::LoadTexture(int num)
{
    char ntft[0x60];
    char ntfp[0x60];
    OS_SPrintf(ntft, "MEF:ef100_%02d.ntft", num);
    OS_SPrintf(ntfp, "MEF:ef100_%02d.ntfp", num);
    BOOL ret;
    if (!m_tex.LoadDeferred(ntft, ntfp, 0)) {
        ret = FALSE;
    } else {
        m_tex.unk_28 = OS_GetVBlankCount();
        ret = TRUE;
    }
    m_tex.unk_1C = 6;
    m_tex.unk_20 = 3;
    m_tex.unk_24 = 3;
    return ret;
}

void CFieldEffectGlitterFactory::ReleaseTextures()
{
    m_tex.Release();
}

int CFieldEffectGlitter::IsReady()
{
    BOOL ret = TRUE;
    if (m_tex != NULL && !IsTextureReady(m_tex)) {
        ret = FALSE;
    }
    return ret;
}

int CFieldEffectGlitter::GetEffectId()
{
    return 0x1B;
}
