#include <nitro.h>
#include <string.h>

#include "Camera2D.hpp"
#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "field/CFieldMap.hpp"
#include "field/CFieldMapLayer.hpp"
#include "heap.hpp"
#include "sub_02006000.hpp"

void CFieldMapLayerStatic::DrawPieces(Rectangle view)
{
    for (int i = 0; i < m_pieceCount; i++) {
        if (RectanglesOverlap(view, m_pieces[i].bounds)) {
            MI_SendGXCommand(3, m_pieces[i].displayList, m_pieces[i].displayListSize);
        }
    }
}

int CFieldMapLayerStatic::Draw(Camera2D *camera)
{
    if (m_pieceCount > 0) {
        fx32 scale = FX32_ONE << camera->unk_28;
        G3_RestoreMtx(0);
        G3_Scale(scale, scale, FX32_ONE);
        int baseX = 0;
        int baseY = 0;
        int offsetX = m_offsetX;
        int offsetY = m_offsetY;
        if (m_repeat) {
            Point2D cam = camera->GetOffset();
            if (cam.x <= 0) {
                baseX = m_width * (-cam.x / (m_width << FX32_SHIFT));
            } else {
                baseX = m_width * (-cam.x / (m_width << FX32_SHIFT) - 1);
            }
            if (cam.y <= 0) {
                baseY = m_height * (-cam.y / (m_height << FX32_SHIFT));
            } else {
                baseY = m_height * (-cam.y / (m_height << FX32_SHIFT) - 1);
            }
            while (offsetX > m_width / 2) {
                offsetX -= m_width;
            }
            while (offsetX < -m_width / 2) {
                offsetX += m_width;
            }
            while (offsetY > m_height / 2) {
                offsetY -= m_height;
            }
            while (offsetY < -m_height / 2) {
                offsetY += m_height;
            }
        }
        int x = offsetX + baseX;
        int y = offsetY + baseY;
        G3_Translate(x, y, unk_04);
        G3_Color(m_color);
        Rectangle view;
        view.pos.x = -(camera->unk_1C + (x << FX32_SHIFT));
        view.pos.y = -(camera->unk_20 + (y << FX32_SHIFT));
        view.size.x = FX32_CONST(256);
        view.size.y = FX32_CONST(192);
        DrawPieces(view);
        if (m_repeat) {
            u8 edges = 0;
            fx32 left = view.pos.x - (view.size.x >> 1);
            fx32 right = view.pos.x + (view.size.x >> 1);
            fx32 top = view.pos.y - (view.size.y >> 1);
            fx32 bottom = view.pos.y + (view.size.y >> 1);
            if (left < 0) {
                edges |= 1;
            }
            if (right > m_width << FX32_SHIFT) {
                edges |= 2;
            }
            if (top < 0) {
                edges |= 4;
            }
            if (bottom > m_height << FX32_SHIFT) {
                edges |= 8;
            }
            if (edges & 1) {
                view.pos.x += m_width << FX32_SHIFT;
                G3_Translate(-m_width, 0, 0);
                DrawPieces(view);
                if (edges & 4) {
                    view.pos.y += m_height << FX32_SHIFT;
                    G3_Translate(0, -m_height, 0);
                    DrawPieces(view);
                    G3_Translate(0, m_height, 0);
                    view.pos.y -= m_height << FX32_SHIFT;
                } else if (edges & 8) {
                    view.pos.y -= m_height << FX32_SHIFT;
                    G3_Translate(0, m_height, 0);
                    DrawPieces(view);
                    G3_Translate(0, -m_height, 0);
                    view.pos.y += m_height << FX32_SHIFT;
                }
                G3_Translate(m_width, 0, 0);
                view.pos.x -= m_width << FX32_SHIFT;
            } else if (edges & 2) {
                view.pos.x -= m_width << FX32_SHIFT;
                G3_Translate(m_width, 0, 0);
                DrawPieces(view);
                if (edges & 4) {
                    view.pos.y += m_height << FX32_SHIFT;
                    G3_Translate(0, -m_height, 0);
                    DrawPieces(view);
                    G3_Translate(0, m_height, 0);
                    view.pos.y -= m_height << FX32_SHIFT;
                } else if (edges & 8) {
                    view.pos.y -= m_height << FX32_SHIFT;
                    G3_Translate(0, m_height, 0);
                    DrawPieces(view);
                    G3_Translate(0, -m_height, 0);
                    view.pos.y += m_height << FX32_SHIFT;
                }
                G3_Translate(-m_width, 0, 0);
                view.pos.x += m_width << FX32_SHIFT;
            }
            if (edges & 4) {
                view.pos.y += m_height << FX32_SHIFT;
                G3_Translate(0, -m_height, 0);
                DrawPieces(view);
                G3_Translate(0, m_height, 0);
            } else if (edges & 8) {
                view.pos.y -= m_height << FX32_SHIFT;
                G3_Translate(0, m_height, 0);
                DrawPieces(view);
                G3_Translate(0, -m_height, 0);
            }
        }
        G3_PopMtx(0);
        return 1;
    }
    return 0;
}

CFieldMapLayerStatic::CFieldMapLayerStatic()
{
    unk_0C = 0;
    m_width = 0;
    m_height = 0;
    m_color = GX_RGB(31, 31, 31);
    m_alpha = 31;
    m_polygonId = 3;
    m_polygonMode = GX_POLYGONMODE_MODULATE;
    m_pieces = NULL;
    m_pieceCount = 0;
    m_repeat = FALSE;
}

CFieldMapLayerStatic::~CFieldMapLayerStatic()
{
    Release();
}

void CFieldMapLayerStatic::Release()
{
    unk_0C = 0;
    m_width = 0;
    m_height = 0;
    if (m_pieces != NULL) {
        for (int i = 0; i < m_pieceCount; i++) {
            if (m_pieces[i].displayList != NULL) {
                Heap_Free(m_pieces[i].displayList);
                m_pieces[i].displayList = NULL;
            }
        }
    }
    if (m_pieces != NULL) {
        Heap_Free(m_pieces);
        m_pieces = NULL;
    }
    m_pieceCount = 0;
}

BOOL CFieldMapLayerStatic::Load(void *data)
{
    u8 *p;
    int i;
    int j;
    UnkClass_021302BC *tex;
    int imagesPerRow;
    int lastPalette;
    int lastPaletteIndex;
    int lastImage;
    int k;
    BOOL begun;
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u16 s0;
    u16 t0;
    u16 s1;
    u16 t1;
    fx32 texS0;
    fx32 texT0;
    fx32 texS1;
    fx32 texT1;
    fx32 tmp;
    NNSG2dImageProxy *image;
    int cellSize;
    int count;
    int alpha;
    int pieceCount;
    int runCount;
    int texIndex;
    int quadCount;
    u16 cellsX;
    u16 cellsY;
    s16 quadX;
    s16 quadY;
    s16 quadW;
    s16 quadH;
    s16 imageIndex;
    s16 pieceX;
    s16 pieceY;
    s16 pieceW;
    s16 pieceH;
    u8 palette;
    u8 paletteIndex;
    u8 flip;
    u32 buf[0x400];
    GXDLInfo dl;
    Release();
    p = (u8 *)data;
    memcpy(&cellSize, p + 0x0, 4);
    memcpy(&count, p + 0x4, 4);
    memcpy(&m_offsetX, p + 0x8, 2);
    memcpy(&m_offsetY, p + 0xA, 2);
    memcpy(&alpha, p + 0xC, 4);
    memcpy(&cellsX, p + 0x10, 2);
    memcpy(&cellsY, p + 0x12, 2);
    unk_0C = count;
    m_width = cellsX * cellSize;
    m_height = cellsY * cellSize;
    m_alpha = (alpha < 31 && alpha > 0) ? alpha : 31;
    if (count > 0) {
        memcpy(&pieceCount, p + 0x14, 4);
        p += 0x18;
        m_pieces = (FieldMapStaticPiece *)Heap_AllocWithAlignment(pieceCount * sizeof(FieldMapStaticPiece), 4);
        m_pieceCount = pieceCount;
        for (i = 0; i < pieceCount; i++) {
            memcpy(&pieceX, p + 0x0, 2);
            memcpy(&pieceY, p + 0x2, 2);
            memcpy(&pieceW, p + 0x4, 2);
            memcpy(&pieceH, p + 0x6, 2);
            memcpy(&runCount, p + 0x8, 4);
            p += 0xC;
            m_pieces[i].bounds.pos.x = (pieceX * cellSize + ((pieceW * cellSize) >> 1)) << FX32_SHIFT;
            m_pieces[i].bounds.pos.y = (pieceY * cellSize + ((pieceH * cellSize) >> 1)) << FX32_SHIFT;
            m_pieces[i].bounds.size.x = (pieceW * cellSize) << FX32_SHIFT;
            m_pieces[i].bounds.size.y = (pieceH * cellSize) << FX32_SHIFT;
            G3_BeginMakeDL(&dl, buf, sizeof(buf));
            for (j = 0; j < runCount; j++) {
                memcpy(&texIndex, p + 0x0, 4);
                memcpy(&quadCount, p + 0x4, 4);
                p += 8;
                tex = m_textures[texIndex];
                imagesPerRow = tex->m_images[0]->unk_32 / cellSize;
                image = &(*tex->m_images.begin())->unk_08;
                if (!(tex->unk_3C & 1)) {
                    G3C_TexImageParam(&dl, image->attr.fmt, GX_TEXGEN_TEXCOORD, image->attr.sizeS, image->attr.sizeT, GX_TEXREPEAT_ST, GX_TEXFLIP_NONE, image->attr.plttUse, NNS_G2dGetImageLocation(image, NNS_G2D_VRAM_TYPE_3DMAIN));
                }
                G3C_PolygonAttr(&dl, 0, m_polygonMode, GX_CULL_NONE, m_polygonId, m_alpha, 0);
                lastPalette = 0xFF;
                lastPaletteIndex = 0xFF;
                lastImage = -1;
                begun = FALSE;
                for (k = 0; k < quadCount; k++) {
                    memcpy(&quadX, p + 0x0, 2);
                    memcpy(&quadY, p + 0x2, 2);
                    memcpy(&quadW, p + 0x4, 2);
                    memcpy(&quadH, p + 0x6, 2);
                    memcpy(&imageIndex, p + 0x8, 2);
                    x = quadX * cellSize;
                    y = quadY * cellSize;
                    w = quadW * cellSize;
                    h = quadH * cellSize;
                    memcpy(&palette, p + 0xA, 1);
                    memcpy(&paletteIndex, p + 0xB, 1);
                    memcpy(&flip, p + 0xC, 1);
                    p += 0xD;
                    if (tex->unk_3C & 1) {
                        s0 = t0 = 0;
                        s1 = w;
                        t1 = h;
                    } else {
                        s0 = (imageIndex % imagesPerRow) * cellSize;
                        t0 = (imageIndex / imagesPerRow) * cellSize;
                        s1 = w + s0;
                        t1 = h + t0;
                    }
                    texS0 = (s0 << FX32_SHIFT) + 0xFFF;
                    texT0 = (t0 << FX32_SHIFT) + 0xFFF;
                    texS1 = (s1 << FX32_SHIFT) + 0xFFF;
                    texT1 = (t1 << FX32_SHIFT) + 0xFFF;
                    if (flip & 1) {
                        tmp = texS0;
                        texS0 = texS1 - FX32_ONE;
                        texS1 = tmp - FX32_ONE;
                    }
                    if (flip & 2) {
                        tmp = texT0;
                        texT0 = texT1 - FX32_ONE;
                        texT1 = tmp - FX32_ONE;
                    }
                    if ((tex->unk_3C & 1) && lastImage != imageIndex) {
                        if (begun) {
                            G3C_End(&dl);
                            begun = FALSE;
                        }
                        image = &tex->m_images[imageIndex]->unk_08;
                        G3C_TexImageParam(&dl, image->attr.fmt, GX_TEXGEN_TEXCOORD, image->attr.sizeS, image->attr.sizeT, GX_TEXREPEAT_ST, GX_TEXFLIP_NONE, image->attr.plttUse, NNS_G2dGetImageLocation(image, NNS_G2D_VRAM_TYPE_3DMAIN));
                        lastImage = imageIndex;
                    }
                    if (palette != lastPalette || paletteIndex != lastPaletteIndex) {
                        if (begun) {
                            G3C_End(&dl);
                            begun = FALSE;
                        }
                        G3C_TexPlttBase(&dl, NNS_G2dGetImagePaletteLocation(&tex->m_palettes[palette]->unk_08, NNS_G2D_VRAM_TYPE_3DMAIN) + paletteIndex * 32, image->attr.fmt);
                        lastPalette = palette;
                        lastPaletteIndex = paletteIndex;
                    }
                    if (!begun) {
                        G3C_Begin(&dl, GX_BEGIN_QUADS);
                    }
                    G3C_TexCoord(&dl, texS0, texT0);
                    G3C_Vtx(&dl, x, y, 0);
                    G3C_TexCoord(&dl, texS0, texT1);
                    G3C_VtxXY(&dl, x, y + h);
                    G3C_TexCoord(&dl, texS1, texT1);
                    G3C_VtxXY(&dl, x + w, y + h);
                    G3C_TexCoord(&dl, texS1, texT0);
                    G3C_VtxXY(&dl, x + w, y);
                }
                if (begun) {
                    G3C_End(&dl);
                }
            }
            m_pieces[i].displayListSize = G3_EndMakeDL(&dl);
            m_pieces[i].displayList = Heap_AllocWithAlignment(m_pieces[i].displayListSize, 4);
            memcpy(m_pieces[i].displayList, buf, m_pieces[i].displayListSize);
        }
    }
    return TRUE;
}

void CFieldMapLayerStatic::SetPolygonId(int id)
{
    m_polygonId = id;
}

int CFieldMapLayerStatic::GetPolygonCount()
{
    return m_pieceCount > 0 ? 1 : 0;
}

int CFieldMapLayerStatic::GetType()
{
    return 13;
}
