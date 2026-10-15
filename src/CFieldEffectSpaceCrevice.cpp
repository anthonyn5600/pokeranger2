#include "field/CFieldEffectSpaceCrevice.hpp"

#include "CGame.hpp"
#include "Camera2D.hpp"
#include "file/CArchiveGuard.hpp"
#include "fx_utils.hpp"

static inline BOOL IsTextureReady(UnkClass_02151244 *tex)
{
    return tex->unk_28 != OS_GetVBlankCount() ? TRUE : FALSE;
}

CFieldEffectSpaceCrevice::CFieldEffectSpaceCrevice(int arg)
    : m_spawnTimer(1)
    , m_alpha(31)
    , m_drawAlpha(31)
    , m_drawObj(this)
{
    for (int i = 0; i < 3; i++) {
        m_rasters[i].m_width = 0xA0000;
        m_rasters[i].m_height = 0xA0000;
        m_rasters[i].m_polygonID = i + 8;
        if (i == 2) {
            m_rasters[i].Setup(32, 0xA0000, 0xA0000, -0x50000, -0x20000, 0xD0000, 0xA0000);
        } else {
            m_rasters[i].Setup(32, 0xA0000, 0xA0000, -0x38000, -0x18000, 0xB8000, 0x98000);
        }
        m_tex[i] = NULL;
    }
    m_rasters[0].m_z = -3;
    m_rasters[1].m_z = -2;
    m_rasters[2].m_z = -1;
    for (int i = 0; i < 2; i++) {
        m_slits[i].life = 0;
    }
    m_rasters[0].m_alpha = 0;
    m_rasters[1].m_alpha = 0;
    m_rasters[2].m_alpha = 0;
    m_rasters[0].m_color = 0x211F;
    m_rasters[1].m_color = 0x2108;
    m_rasters[0].m_texGen = TRUE;
    m_rasters[1].m_texGen = TRUE;
    m_offset.x = m_offset.y = 0;
    m_drawObj.unk_04 = 0x80000000;
}

CFieldEffectSpaceCrevice::~CFieldEffectSpaceCrevice()
{
}

void CFieldEffectSpaceCrevice::SetTexture(int i, UnkClass_02151244 *tex)
{
    if (i < 0 || i >= 3) {
        return;
    }
    m_rasters[i].m_tex = (NtfTextureParam *)tex;
    m_tex[i] = tex;
}

void CFieldEffectSpaceCrevice::FadeTo(int arg0, int arg1)
{
    m_fader.from = m_alpha << 12;
    m_fader.to = arg0 << 12;
    m_fader.duration = arg1;
    m_fader.active = TRUE;
    m_fader.cur = m_fader.from;
    m_fader.frame = 0;
}

int CFieldEffectSpaceCrevice::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 1:
        m_offset.x = value << 12;
        for (int i = 0; i < 3; i++) {
            m_rasters[i].m_pos.x = m_offset.x;
        }
        break;
    case 2:
        m_offset.y = value << 12;
        for (int i = 0; i < 3; i++) {
            m_rasters[i].m_pos.y = m_offset.y;
        }
        break;
    case 3:
        for (int i = 0; i < 3; i++) {
            m_rasters[i].m_width = value << 12;
        }
        break;
    case 4:
        for (int i = 0; i < 3; i++) {
            m_rasters[i].m_height = value << 12;
        }
        break;
    case 26:
        m_alpha = value;
        if (m_alpha > 31) {
            m_alpha = 31;
        }
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

int CFieldEffectSpaceCrevice::ov0_02142264(int step)
{
    int state = CFieldEffect::ov0_02142264(step);
    if (state == 0 || state == 4) {
        return state;
    }
    if (m_spawnTimer > 0) {
        m_spawnTimer -= step;
        if (m_spawnTimer <= 0) {
            Spawn();
            m_spawnTimer = 30;
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
    default:
        alpha = m_alpha;
        break;
    case 2:
        alpha = m_alpha;
        break;
    case 3: {
        alpha = m_alpha;
        fx32 scale;
        if (m_outTime <= 60) {
            scale = (m_frame * -FX32_ONE) / m_outTime + FX32_ONE;
        } else if (m_outTime - m_frame <= 60) {
            scale = ((60 - (m_outTime - m_frame)) * -0x400) / 60 + 0x400;
        } else {
            scale = (m_frame * -0xC00) / (m_outTime - 60) + FX32_ONE;
        }
        for (int i = 0; i < 3; i++) {
            m_rasters[i].m_scale[0] = scale;
            m_rasters[i].m_scale[1] = FX32_ONE;
        }
        break;
    }
    }
    m_drawAlpha = alpha;
    for (int i = 0; i < 2; i++) {
        if (m_slits[i].life > 0) {
            m_slits[i].life -= step;
            m_slits[i].angle += m_slits[i].speed;
        }
    }
    for (int i = 0; i < 3; i++) {
        m_rasters[i].Advance();
    }
    return state;
}

int CFieldEffectSpaceCrevice::ov0_02142344(Camera2D *camera)
{
    return 0;
}

void CFieldEffectSpaceCrevice::DrawSlits(Camera2D *camera, int depth)
{
    if (m_state == 0 || m_state == 4) {
        return;
    }
    for (int i = 0; i < 2; i++) {
        CFEFRasterTransform *raster = &m_rasters[i];
        fx32 cx = raster->m_s1 + ((raster->m_s2 - raster->m_s1) >> 1);
        fx32 cy = raster->m_t1 + ((raster->m_t2 - raster->m_t1) >> 1);
        fx32 scale = FX_Inv(0x1800 - FX32_DIV(m_slits[i].life << 11, 0x3C000));
        fx32 a;
        if (m_slits[i].life >= 45) {
            a = FX32_DIV((60 - m_slits[i].life) * 0x1F000, 0xF000);
        } else {
            a = -FX32_DIV(m_slits[i].life * -0x1F000, 0x2D000);
        }
        m_rasters[i].m_alpha = a * m_drawAlpha / 31 >> 12;
        m_rasters[i].m_z = depth + i;
        MtxFx44 mtx;
        MtxFx44 rot;
        MTX_Identity43((MtxFx43 *)&mtx);
        MTX_TransApply44(&mtx, &mtx, cx, cy, 0);
        MTX_RotZ44(&rot, FX_SinIdx(m_slits[i].angle), FX_CosIdx(m_slits[i].angle));
        MTX_Concat44(&rot, &mtx, &mtx);
        MTX_ScaleApply44(&mtx, &mtx, scale, scale, FX32_ONE);
        MTX_TransApply44(&mtx, &mtx, -cx, -cy, 0);
        G3_MtxMode(GX_MTXMODE_TEXTURE);
        G3_PushMtx();
        G3_LoadTexMtxTexCoord(&mtx);
        G3_MtxMode(GX_MTXMODE_POSITION);
        raster->Render(camera);
        G3_MtxMode(GX_MTXMODE_TEXTURE);
        G3_PopMtx(1);
        G3_MtxMode(GX_MTXMODE_POSITION);
    }
    m_rasters[2].m_alpha = m_drawAlpha;
    m_rasters[2].m_z = depth + 2;
    m_rasters[2].Render(camera);
}

void CFieldEffectSpaceCrevice::SetColor(u16 color)
{
    m_rasters[0].m_color = color;
    m_rasters[1].m_color = color;
}

void CFieldEffectSpaceCrevice::Spawn()
{
    for (int i = 0; i < 2; i++) {
        if (m_slits[i].life <= 0) {
            m_slits[i].life = 60;
            m_rasters[i].m_alpha = 31;
            m_slits[i].angle = MATH_Rand32(&CGame::GetInstance()->m_rand32, 0x10000);
            m_slits[i].speed = MATH_Rand32(&CGame::GetInstance()->m_rand32, 0x100) - 0x80;
            if (m_slits[i].speed >= 0) {
                m_slits[i].speed += 0x80;
            } else {
                m_slits[i].speed -= 0x80;
            }
            break;
        }
    }
}

void CFieldEffectSpaceCrevice::ov0_02142398(DrawObjectList *renderLists)
{
    renderLists->Insert(&m_drawObj);
}

int CFieldEffectSpaceCrevice::CEffectDrawObject::Draw(Camera2D *camera, int budget)
{
    m_depth = budget;
    if (m_owner != NULL) {
        m_owner->DrawSlits(camera, budget);
    }
    return 3;
}

CFieldEffectSpaceCreviceFactory::~CFieldEffectSpaceCreviceFactory()
{
    ReleaseTextures();
}

CFieldEffect *CFieldEffectSpaceCreviceFactory::Create(int arg)
{
    BOOL ok = TRUE;
    CFieldEffectSpaceCrevice *effect = NULL;
    {
        CArchiveGuard guard("MEF", "data/Field/Effect/ef104_LZ.bin", 1, 1, 0, NULL, 0);
        if (m_tex[0].m_texAddr == 0) {
            ok = LoadTexture(0, 0, TRUE);
        }
        if (m_tex[1].m_texAddr == 0) {
            ok = LoadTexture(1, 1, TRUE);
        }
    }
    if (ok) {
        effect = new CFieldEffectSpaceCrevice(arg);
        if (effect != NULL) {
            effect->SetTexture(0, &m_tex[0]);
            effect->SetTexture(1, &m_tex[0]);
            effect->SetTexture(2, &m_tex[1]);
        }
    }
    return effect;
}

void CFieldEffectSpaceCreviceFactory::Reset()
{
    ReleaseTextures();
}

void CFieldEffectSpaceCreviceFactory::Preload()
{
    CArchiveGuard guard("MEF", "data/Field/Effect/ef104_LZ.bin", 1, 1, 0, NULL, 0);
    if (m_tex[0].m_texAddr == 0) {
        LoadTexture(0, 0, FALSE);
    }
    if (m_tex[1].m_texAddr == 0) {
        LoadTexture(1, 1, FALSE);
    }
}

BOOL CFieldEffectSpaceCreviceFactory::LoadTexture(int i, int num, BOOL deferred)
{
    int formats[2] = { 6, 1 };
    if (i >= 0 && i < 2) {
        char ntft[0x60];
        char ntfp[0x60];
        OS_SPrintf(ntft, "MEF:ef104_%02d.ntft", num);
        OS_SPrintf(ntfp, "MEF:ef104_%02d.ntfp", num);
        BOOL ret;
        if (deferred) {
            if (!m_tex[i].LoadDeferred(ntft, ntfp, 0)) {
                ret = FALSE;
            } else {
                m_tex[i].unk_28 = OS_GetVBlankCount();
                ret = TRUE;
            }
        } else {
            ret = m_tex[i].Load(ntft, ntfp, 0);
        }
        m_tex[i].unk_1C = formats[i];
        m_tex[i].unk_20 = 4;
        m_tex[i].unk_24 = 4;
        return ret;
    }
    return FALSE;
}

void CFieldEffectSpaceCreviceFactory::ReleaseTextures()
{
    for (int i = 0; i < 2; i++) {
        m_tex[i].Release();
    }
}

CFEFRasterTransform::~CFEFRasterTransform()
{
    Release();
}

void CFEFRasterTransform::Setup(int rows, fx32 width, fx32 height, fx32 s1, fx32 t1, fx32 s2, fx32 t2)
{
    m_width = width;
    m_height = height;
    m_s1 = s1;
    m_t1 = t1;
    m_s2 = s2;
    m_t2 = t2;
    m_rows = rows;
    m_verts = (Point2D *)operator new[]((m_rows + 2) << 4);
    m_texCoords = (Point2D *)operator new[]((m_rows + 2) << 4);
    m_waves = (fx32 *)operator new[]((m_rows + 2) << 2);
    Point2D *vert = m_verts;
    Point2D *tex = m_texCoords;
    for (int i = 0; i < m_rows + 2; i++) {
        for (int j = 0; j < 2; j++) {
            vert->x = j == 0 ? -(m_width >> 1) : m_width >> 1;
            tex->x = j == 0 ? s1 : s2;
            vert++;
            tex++;
        }
    }
    m_scroll = 0;
    m_rowHeight = m_height / m_rows;
    m_head = 0;
    m_angle = 0;
    u16 angle = m_angle;
    int row = m_head;
    for (int i = 0; i < m_rows + 2; i++) {
        m_waves[row] = FX32_MUL(FX_SinIdx(angle), 0x20000);
        if (i > 0) {
            angle -= (m_rowHeight >> 12) << 10;
        }
        if (--row < 0) {
            row = m_rows + 1;
        }
    }
    m_shifted = TRUE;
}

void CFEFRasterTransform::Release()
{
    if (m_verts != NULL) {
        delete[] m_verts;
        m_verts = NULL;
    }
    if (m_texCoords != NULL) {
        delete[] m_texCoords;
        m_texCoords = NULL;
    }
    if (m_waves != NULL) {
        delete[] m_waves;
        m_waves = NULL;
    }
}

void CFEFRasterTransform::Advance()
{
    m_angle += 0x400;
    m_scroll += FX32_ONE;
    if (m_scroll >= m_rowHeight) {
        m_scroll -= m_rowHeight;
        m_shifted = TRUE;
        if (++m_head >= m_rows + 2) {
            m_head = 0;
        }
    }
    m_waves[m_head] = FX32_MUL(FX_SinIdx(m_angle), 0x20000);
    if (m_shifted) {
        int prev = m_head - 1;
        if (prev < 0) {
            prev = m_rows + 1;
        }
        m_waves[prev] = m_waves[m_head];
        m_shifted = FALSE;
    }
}

u32 CFEFRasterTransform::Render(Camera2D *camera)
{
    Point2D *vert;
    Point2D *tex;
    fx32 y;
    int row;
    int i;
    int j;
    int shift;
    if (m_alpha > 0) {
        if (m_tex != NULL) {
            if (m_texGen) {
                m_tex->Bind(GX_TEXPLTTCOLOR0_USE, GX_TEXGEN_TEXCOORD);
            } else {
                m_tex->Bind(GX_TEXPLTTCOLOR0_USE, GX_TEXGEN_NONE);
            }
        }
        G3_RestoreMtx(0);
        shift = FX32_SHIFT - camera->unk_28;
        G3_Color(m_color);
        G3_PolygonAttr(GX_LIGHTMASK_NONE, m_polygonMode, GX_CULL_NONE, m_polygonID, m_alpha, GX_POLYGON_ATTR_MISC_NONE);
        vert = m_verts;
        tex = m_texCoords;
        G3_PushMtx();
        G3_Translate(m_pos.x >> shift, m_pos.y >> shift, 0);
        if (m_scale[0] != FX32_ONE || m_scale[1] != FX32_ONE) {
            G3_Scale(m_scale[0], m_scale[1], FX32_ONE);
        }
        G3_Begin(GX_BEGIN_QUAD_STRIP);
        row = m_head;
        y = -m_height >> 1;
        for (i = 0; i < m_rows + 2; i++) {
            fx32 t = m_t1 + FX32_MUL(m_t2 - m_t1, FX32_DIV(y, m_height) + 0x800);
            for (j = 0; j < 2; j++) {
                G3_TexCoord(tex->x + m_waves[row], t);
                G3_Vtx(vert->x >> shift, y >> shift, m_z);
                vert++;
                tex++;
            }
            y += i == 0 ? m_scroll : m_rowHeight;
            if (--row < 0) {
                row = m_rows + 1;
            }
        }
        G3_End();
        G3_PopMtx(1);
    }
    return 1;
}

int CFieldEffectSpaceCrevice::IsReady()
{
    BOOL ret = TRUE;
    for (int i = 0; i < 3; i++) {
        if (m_tex[i] != NULL && !IsTextureReady(m_tex[i])) {
            ret = FALSE;
            break;
        }
    }
    return ret;
}

int CFieldEffectSpaceCrevice::GetEffectId()
{
    return 0x1E;
}
