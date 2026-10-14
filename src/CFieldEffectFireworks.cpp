#include "field/CFieldEffectFireworks.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "Camera2D.hpp"
#include "field/CFieldEffectManage.hpp"

CMeshSprite::CMeshSprite(u8 rows)
{
    m_rot = 0;
    m_plttOffset = 0;
    m_x1 = 0;
    m_y1 = 0;
    m_x2 = 0;
    m_y2 = 0;
    m_image = NULL;
    m_palette = NULL;
    m_ncer = NULL;
    m_cellIdx = 0;
    m_rows = rows;
    m_pos.x = m_pos.y = 0;
    m_scaleX = m_scaleY = FX32_ONE;
    m_skewY = m_skewX = 0;
    m_stretchX = m_stretchY = FX32_ONE;
    MI_CpuFill8(m_rowOffsets, 0, sizeof(m_rowOffsets));
}

void CMeshSprite::SetRes(VramImage *image, VramPalette *palette, CNCERFile *ncer)
{
    m_image = image;
    m_palette = palette;
    m_ncer = ncer;
}

BOOL CMeshSprite::SetCell(u16 cellIdx, u16 oamIdx)
{
    const NNSG2dCellData *cellData = NNS_G2dGetCellDataByIdx(m_ncer->unk_B8, cellIdx);
    if (cellData == NULL || cellData->numOAMAttrs <= oamIdx) {
        return FALSE;
    }
    GXOamAttr oamAttr;
    NNS_G2dCopyCellAsOamAttr(cellData, oamIdx, &oamAttr);
    GXOamShape oamShape = NNS_G2dGetOAMSize(&oamAttr);
    int sizeX = NNS_G2dGetOamSizeX(&oamShape);
    int sizeY = NNS_G2dGetOamSizeY(&oamShape);
    int texX1 = ((int)oamAttr.charNo & 31) << 3;
    int texX2 = texX1 + sizeX;
    int texY1 = ((int)oamAttr.charNo >> 5) << 3;
    int texY2 = texY1 + sizeY;
    if (oamAttr.flipH) {
        m_s1 = (texX2 - 1) << FX32_SHIFT;
        m_s2 = (texX1 - 1) << FX32_SHIFT;
    } else {
        m_s1 = texX1 << FX32_SHIFT;
        m_s2 = texX2 << FX32_SHIFT;
    }
    if (oamAttr.flipV) {
        m_t1 = (texY2 - 1) << FX32_SHIFT;
        m_t2 = (texY1 - 1) << FX32_SHIFT;
    } else {
        m_t1 = texY1 << FX32_SHIFT;
        m_t2 = texY2 << FX32_SHIFT;
    }
    int x = oamAttr.x;
    if (x > 0xFF) {
        x = (s16)(x | 0xFF00);
    }
    m_x1 = x;
    int y = oamAttr.y;
    if (y > 0x7F) {
        y = (s16)(y | 0xFF00);
    }
    m_y1 = y;
    m_x2 = m_x1 + sizeX;
    m_y2 = m_y1 + sizeY;
    m_plttOffset = oamAttr.cParam << 5;
    m_cellIdx = cellIdx;
    return TRUE;
}

u32 CMeshSprite::Render(Camera2D *camera)
{
    if (m_image == NULL || m_palette == NULL) {
        return 0;
    }
    u16 shift = camera->unk_28;
    G3_RestoreMtx(0);
    G3_Translate((m_pos.x >> FX32_SHIFT) << shift, (m_pos.y >> FX32_SHIFT) << shift, 0);
    if (m_stretchX != FX32_ONE || m_stretchY != FX32_ONE) {
        G3_Scale(m_stretchX, m_stretchY, FX32_ONE);
    }
    if (m_skewY != 0 || m_skewX != 0) {
        MtxFx33 skew;
        MTX_Identity33(&skew);
        skew._01 = m_skewX;
        skew._10 = m_skewY;
        G3_MultMtx33(&skew);
    }
    if (m_rot != 0) {
        MtxFx33 rot;
        MTX_RotZ33(&rot, FX_SinIdx(m_rot), FX_CosIdx(m_rot));
        G3_MultMtx33(&rot);
    }
    if (m_scaleX != FX32_ONE || m_scaleY != FX32_ONE) {
        G3_Scale(m_scaleX, m_scaleY, FX32_ONE);
    }
    G3_Color(m_color);
    G3_PolygonAttr(GX_LIGHTMASK_NONE, m_polygonMode, GX_CULL_NONE, m_polygonID, m_alpha, GX_POLYGON_ATTR_MISC_NONE);
    NNSG2dImageProxy *image = &m_image->unk_08;
    G3_TexImageParam(image->attr.fmt, GX_TEXGEN_TEXCOORD, image->attr.sizeS, image->attr.sizeT, GX_TEXREPEAT_NONE, GX_TEXFLIP_NONE, image->attr.plttUse, NNS_G2dGetImageLocation(image, NNS_G2D_VRAM_TYPE_3DMAIN));
    G3_TexPlttBase(m_plttOffset + NNS_G2dGetImagePaletteLocation(&m_palette->unk_08, NNS_G2D_VRAM_TYPE_3DMAIN), image->attr.fmt);
    G3_Begin(GX_BEGIN_QUAD_STRIP);
    s16 x1 = m_x1 << shift;
    s16 y1 = m_y1 << shift;
    s16 x2 = m_x2 << shift;
    s16 y2 = m_y2 << shift;
    fx32 rows = m_rows << FX32_SHIFT;
    int stepY = (s16)FX32_DIV(y2 - y1, rows);
    fx32 t1 = m_t1;
    fx32 stepT = FX32_DIV(m_t2 - t1, rows);
    G3_TexCoord(m_s2, t1);
    G3_Vtx(m_rowOffsets[0] + x2, y1, m_z);
    G3_TexCoord(m_s1, t1);
    G3_VtxXY(m_rowOffsets[0] + x1, y1);
    y1 += stepY;
    fx32 t = t1 + stepT;
    for (int i = 0; i < m_rows - 1; i++) {
        G3_TexCoord(m_s2, t);
        G3_VtxXY(m_rowOffsets[i + 1] + x2, y1);
        G3_TexCoord(m_s1, t);
        G3_VtxXY(m_rowOffsets[i + 1] + x1, y1);
        y1 += stepY;
        t += stepT;
    }
    G3_TexCoord(m_s2, m_t2);
    G3_VtxXY(m_rowOffsets[4] + x2, y2);
    G3_TexCoord(m_s1, m_t2);
    G3_VtxXY(m_rowOffsets[4] + x1, y2);
    G3_End();
    G3_PopMtx(0);
    return 1;
}

CFieldEffectFireworks::CFieldEffectFireworks(int arg)
    : m_arg(arg)
    , m_time(0)
    , m_mesh(1)
{
    m_mesh.m_scaleX = 0;
    m_mesh.m_scaleY = 0;
    CGame *game = CGame::GetInstance();
    MATHRandContext32 *rand = &game->m_rand32;
    m_mesh.m_rot = (MATH_Rand32(rand, 9) * 0xA0000) / 360;
}

void CFieldEffectFireworks::SetRes(VramImage *image, VramPalette *palette, CNCERFile *ncer)
{
    m_mesh.SetRes(image, palette, ncer);
    m_mesh.SetCell(6, 0);
}

int CFieldEffectFireworks::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 1:
        m_mesh.m_pos.x = value << 12;
        break;
    case 2:
        m_mesh.m_pos.y = value << 12;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

int CFieldEffectFireworks::ov0_02142264(int step)
{
    int state = CFieldEffect::ov0_02142264(step);
    switch (state) {
    case 1: {
        fx32 scale;
        if (m_inTime <= 0) {
            scale = 0x2000;
        } else {
            scale = FX32_MUL(m_time << 12, 0x2000) / m_inTime;
        }
        m_mesh.m_scaleX = scale;
        m_mesh.m_scaleY = scale;
        break;
    }
    case 2:
        m_mesh.m_scaleX = 0x2000;
        m_mesh.m_scaleY = 0x2000;
        break;
    case 3:
        if (m_outTime > 0) {
            fx32 scale = (m_frame << 12) / m_outTime + 0x2000;
            m_mesh.m_scaleX = scale;
            m_mesh.m_scaleY = scale;
            m_mesh.m_alpha = 31 - m_frame * 31 / m_outTime;
        }
        break;
    }
    if (state != 4 && state != 0) {
        m_time += step;
    }
    return state;
}

int CFieldEffectFireworks::ov0_02142344(Camera2D *camera)
{
    if (m_state != 4 && m_state != 0 && m_mesh.m_alpha > 0) {
        m_mesh.Render(camera);
    }
    return 0;
}

void CFieldEffectFireworks::SetColor(u16 color)
{
    m_mesh.m_color = color;
}

CFieldEffect *CFieldEffectFireworksFactory::Create(int arg)
{
    CFieldEffectFireworks *effect = new CFieldEffectFireworks(arg);
    if (effect != NULL) {
        CFieldEffectManage *mgr = MAIN_BSS_0210CA60;
        CNCERFile *ncer = mgr->m_resident.GetNcer(0);
        VramPalette *palette = mgr->m_resident.GetPalette();
        effect->SetRes(mgr->m_resident.GetNcbr(0), palette, ncer);
    }
    return effect;
}
