#include "field/CFieldEffectBloom.hpp"

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

CFieldEffectBloom::CFieldEffectBloom(int mode)
    : m_actor(NULL)
    , m_size(8)
{
    m_blinkTimer = 0;
    m_idleTimer = 0;
    m_angle1 = 0;
    m_angle2 = 0;
    m_cooldown = 1;
    m_mode = mode;
    m_alpha = 31;
    m_fader.duration = 0;
    m_fader.frame = 0;
    m_fader.active = FALSE;
    for (int i = 0; i < 4; i++) {
        m_sprites[i].unk_4C = 0x40000;
        m_sprites[i].unk_50 = 0x40000;
        m_sprites[i].m_polygonID = i + 8;
        m_sprites[i].m_s1 = 0;
        m_sprites[i].m_t1 = 0;
        m_sprites[i].m_s2 = 0x40000;
        m_sprites[i].m_t2 = 0x40000;
        m_tex[i] = NULL;
    }
    m_sprites[3].m_z = -4;
    m_sprites[0].m_z = -3;
    m_sprites[1].m_z = -2;
    m_sprites[2].m_z = -1;
    for (int i = 0; i < 2; i++) {
        m_flash[i] = 0;
        m_sprites[i].m_alpha = 0;
    }
    m_offset.x = m_offset.y = 0;
}

CFieldEffectBloom::~CFieldEffectBloom()
{
}

void CFieldEffectBloom::SetTexture(int i, UnkClass_02151244 *tex)
{
    if (i < 0 || i >= 4) {
        return;
    }
    m_sprites[i].unk_18 = tex;
    m_tex[i] = tex;
}

int CFieldEffectBloom::SetPolygonIDs(int base)
{
    for (int i = 0; i < 4; i++) {
        m_sprites[i].m_polygonID = base + i;
    }
    return 4;
}

void CFieldEffectBloom::FadeTo(int arg0, int arg1)
{
    m_fader.from = m_alpha << 12;
    m_fader.to = arg0 << 12;
    m_fader.duration = arg1;
    m_fader.active = TRUE;
    m_fader.cur = m_fader.from;
    m_fader.frame = 0;
}

int CFieldEffectBloom::SetParam(int param, int value)
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

int CFieldEffectBloom::ov0_02142264(int step)
{
    int state = CFieldEffect::ov0_02142264(step);
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
    m_angle1 += (u16)(step << 7);
    m_angle2 += (u16)(step << 9);
    if (m_mode != 0) {
        for (int i = 0; i < 2; i++) {
            if (m_flash[i] > 0) {
                m_flash[i] -= step;
            }
        }
    }
    if (m_cooldown > 0) {
        m_cooldown -= step;
        if (m_cooldown <= 0) {
            StartFlash();
            switch (m_mode) {
            case 1:
                m_cooldown = 60;
                break;
            case 2:
                m_cooldown = 60;
                break;
            }
        }
    }
    if (m_actor != NULL) {
        Point2D pos = m_actor->GetPos() + m_offset;
        pos.y -= m_actor->GetHeight();
        for (int i = 0; i < 4; i++) {
            m_sprites[i].m_coords[0] = pos.x;
            m_sprites[i].m_coords[1] = pos.y;
        }
    }
    if (m_fader.Update(step)) {
        m_alpha = m_fader.cur >> 12;
        if (m_alpha > 31) {
            m_alpha = 31;
        }
    }
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
    int a = alpha * (m_size + 16) / 31;
    for (int i = 0; i < 4; i++) {
        m_sprites[i].m_alpha = a;
    }
    return state;
}

int CFieldEffectBloom::ov0_02142344(Camera2D *camera)
{
    switch (m_mode) {
    case 0: {
        fx32 scale = MATH_Rand32(&CGame::GetInstance()->m_rand32, 2) ? 0x14CC : FX32_ONE;
        m_sprites[0].m_scale[0] = m_sprites[0].m_scale[1] = scale;
        m_sprites[3].m_scale[0] = m_sprites[3].m_scale[1] = scale;
        m_sprites[0].Render(camera);
        m_sprites[3].Render(camera);
        break;
    }
    case 1: {
        fx32 scale = FX32_MUL(((60 - m_flash[0]) << 12) / 60, 0xB33) + 0x800;
        int alpha = m_flash[0] > 16 ? 31 : m_flash[0] >> 1;
        m_sprites[0].m_alpha = alpha;
        m_sprites[0].m_scale[0] = m_sprites[0].m_scale[1] = scale;
        m_sprites[3].m_alpha = alpha;
        m_sprites[3].m_scale[0] = m_sprites[3].m_scale[1] = scale;
        m_sprites[0].Render(camera);
        m_sprites[3].Render(camera);
        break;
    }
    case 2: {
        fx32 scale = FX32_MUL(((60 - m_flash[0]) << 12) / 60, 0xB33) + 0x800;
        int alpha = m_flash[0] > 16 ? 31 : m_flash[0] >> 1;
        m_sprites[3].m_alpha = alpha;
        m_sprites[3].m_scale[0] = m_sprites[3].m_scale[1] = scale;
        if (MATH_Rand32(&CGame::GetInstance()->m_rand32, 2)) {
            scale = FX32_MUL(scale, 0xB33);
        }
        m_sprites[0].m_scale[0] = m_sprites[0].m_scale[1] = scale;
        m_sprites[0].Render(camera);
        m_sprites[3].Render(camera);
        break;
    }
    }
    if (m_blinkTimer > 0) {
        fx32 scale = FX32_MUL(FX_SinIdx(m_angle2), 0x4CC) + FX32_ONE;
        if (m_size != 8) {
            scale = FX32_MUL(scale, (m_size - 8) * 0x199 + FX32_ONE);
        }
        m_sprites[2].m_scale[0] = m_sprites[2].m_scale[1] = scale;
        m_sprites[2].m_rotAngle = m_angle1;
        m_sprites[2].Render(camera);
    }
    return 0;
}

void CFieldEffectBloom::SetColor(u16 color)
{
    m_sprites[3].m_color = color;
}

void CFieldEffectBloom::StartFlash()
{
    for (int i = 0; i < 2; i++) {
        if (m_flash[i] <= 0) {
            m_flash[i] = 60;
            return;
        }
    }
}

CFieldEffectBloomFactory::~CFieldEffectBloomFactory()
{
    ReleaseTextures();
}

void CFieldEffectBloomFactory::Reset()
{
    ReleaseTextures();
}

CFieldEffect *CFieldEffectBloomFactory::Create(int arg)
{
    CFieldEffectBloom *effect = NULL;
    BOOL ok = TRUE;
    {
        CArchiveGuard guard("MEF", "data/Field/Effect/ef100_LZ.bin", 1, 1, 0, NULL, 0);
        if (m_tex[0].m_texAddr == 0) {
            ok = LoadTexture(0, 0);
        }
        if (m_tex[1].m_texAddr == 0) {
            ok = LoadTexture(1, 1);
        }
        if (m_tex[2].m_texAddr == 0) {
            ok = LoadTexture(2, 2);
        }
    }
    if (ok) {
        effect = new CFieldEffectBloom(arg);
        if (effect != NULL) {
            effect->SetTexture(0, &m_tex[0]);
            effect->SetTexture(1, &m_tex[0]);
            effect->SetTexture(2, &m_tex[1]);
            effect->SetTexture(3, &m_tex[2]);
            int n = effect->SetPolygonIDs(MAIN_BSS_0210CA60->unk_87D + 8);
            CFieldEffectManage *mgr = MAIN_BSS_0210CA60;
            mgr->unk_87D += (u8)n;
            mgr->unk_87D &= 0x1F;
        }
    }
    return effect;
}

BOOL CFieldEffectBloomFactory::LoadTexture(int i, int num)
{
    if (i >= 0 && i < 3) {
        char ntft[0x60];
        char ntfp[0x60];
        OS_SPrintf(ntft, "MEF:ef100_%02d.ntft", num);
        OS_SPrintf(ntfp, "MEF:ef100_%02d.ntfp", num);
        BOOL ret;
        if (!m_tex[i].LoadDeferred(ntft, ntfp, 0)) {
            ret = FALSE;
        } else {
            m_tex[i].unk_28 = OS_GetVBlankCount();
            ret = TRUE;
        }
        m_tex[i].unk_1C = 6;
        m_tex[i].unk_20 = 3;
        m_tex[i].unk_24 = 3;
        return ret;
    }
    return FALSE;
}

void CFieldEffectBloomFactory::ReleaseTextures()
{
    for (int i = 0; i < 3; i++) {
        m_tex[i].Release();
    }
}

int CFieldEffectBloom::IsReady()
{
    BOOL ret = TRUE;
    for (int i = 0; i < 4; i++) {
        if (m_tex[i] != NULL && !IsTextureReady(m_tex[i])) {
            ret = FALSE;
            break;
        }
    }
    return ret;
}

int CFieldEffectBloom::GetEffectId()
{
    return 0x13;
}
