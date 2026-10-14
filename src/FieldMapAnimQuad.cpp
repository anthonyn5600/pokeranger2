#include <nitro.h>
#include <string.h>

#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "field/CFieldMap.hpp"
#include "heap.hpp"

FieldMapAnimQuad::FieldMapAnimQuad()
{
    m_frames = NULL;
    m_pieces = NULL;
    m_width = 0;
    m_height = 0;
    m_pieceCount = 0;
    m_timer = 0;
    m_frame = 0;
    m_polygonId = 3;
}

FieldMapAnimQuad::~FieldMapAnimQuad()
{
    Release();
}

BOOL FieldMapAnimQuad::Load(void *data)
{
    GXDLInfo dl;
    u8 *p = (u8 *)data;

    memcpy(&m_width, p, 4);
    memcpy(&m_height, p + 4, 4);
    memcpy(&m_pieceCount, p + 8, 4);
    p += 12;
    m_frames = (FieldMapCharaFrame *)Heap_AllocWithAlignment(m_pieceCount * sizeof(FieldMapCharaFrame), 4);
    m_pieces = new FieldMapCharaPiece[m_pieceCount];
    for (int i = 0; i < m_pieceCount; i++) {
        // Declared first so it gets its register before piece, like the original.
        VramImage *image;
        FieldMapCharaFrame *frame = &m_frames[i];
        FieldMapCharaPiece *piece = &m_pieces[i];
        frame->unk_00 = p[0];
        frame->texture = p[1];
        frame->palette = p[2];
        frame->paletteOffset = p[3];
        frame->duration = p[4];
        memcpy(&frame->cell, p + 5, 2);
        p += 7;
        Rectangle bounds = { { 0, 0 }, { m_width << 16, m_height << 16 } };
        piece->bounds.pos = bounds.pos;
        piece->bounds.size = bounds.size;
        piece->bufferSize = 0x80;
        // x and y are first used for the duration and the texture index: their position values below then
        // get split live ranges, which gives the original's spill slots.
        s16 y = frame->duration;
        piece->duration = y;
        s16 x = frame->texture;
        FieldMapTextures *tex = m_textures[x];
        int cols = tex->m_images[0]->unk_32 / 16;
        int cell = frame->cell;
        x = piece->bounds.pos.x >> FX32_SHIFT;
        y = piece->bounds.pos.y >> FX32_SHIFT;
        s16 w = piece->bounds.size.x >> FX32_SHIFT;
        s16 h = piece->bounds.size.y >> FX32_SHIFT;
        u16 u = (cell % cols) << 4;
        u16 v = (cell / cols) << 4;
        u16 u2 = u + w;
        u16 v2 = v + h;
        image = tex->m_images[0];
        VramPalette *palette = tex->m_palettes[frame->palette];
        for (int j = 0; j < 4; j++) {
            piece->displayLists[j] = Heap_Alloc(0x80);
            G3_BeginMakeDL(&dl, piece->displayLists[j], piece->bufferSize);
            u16 s0 = u;
            u16 t0 = v;
            u16 s1 = u2;
            u16 t1 = v2;
            if (j & 1) {
                s0 += w - 1;
                s1 -= w;
            }
            if (j & 2) {
                t0 += h - 1;
                t1 -= h;
            }
            G3C_TexImageParam(&dl, image->unk_08.attr.fmt, GX_TEXGEN_TEXCOORD, image->unk_08.attr.sizeS, image->unk_08.attr.sizeT, GX_TEXREPEAT_NONE, GX_TEXFLIP_NONE, image->unk_08.attr.plttUse, NNS_G2dGetImageLocation(&image->unk_08, NNS_G2D_VRAM_TYPE_3DMAIN));
            G3C_TexPlttBase(&dl,
                NNS_G2dGetImagePaletteLocation(&palette->unk_08, NNS_G2D_VRAM_TYPE_3DMAIN)
                    + frame->paletteOffset * 32,
                image->unk_08.attr.fmt);
            G3C_PolygonAttr(&dl, 0, GX_POLYGONMODE_MODULATE, GX_CULL_NONE, m_polygonId, 31, 0);
            G3C_Begin(&dl, GX_BEGIN_QUADS);
            G3C_TexCoord(&dl, s0 << FX32_SHIFT, t0 << FX32_SHIFT);
            G3C_Vtx(&dl, x, y, 0);
            G3C_TexCoord(&dl, s0 << FX32_SHIFT, t1 << FX32_SHIFT);
            G3C_VtxXY(&dl, x, y + h);
            G3C_TexCoord(&dl, s1 << FX32_SHIFT, t1 << FX32_SHIFT);
            G3C_VtxXY(&dl, x + w, y + h);
            G3C_TexCoord(&dl, s1 << FX32_SHIFT, t0 << FX32_SHIFT);
            G3C_VtxXY(&dl, x + w, y);
            G3C_End(&dl);
            if (j == 0) {
                piece->displayListSize = G3_EndMakeDL(&dl);
            }
        }
    }
    m_timer = 0;
    m_frame = 0;
    return TRUE;
}

void FieldMapAnimQuad::Release()
{
    if (m_frames != NULL) {
        Heap_Free(m_frames);
        m_frames = NULL;
    }
    for (int i = 0; i < m_pieceCount; i++) {
        for (int j = 0; j < 4; j++) {
            if (m_pieces[i].displayLists[j] != NULL) {
                Heap_Free(m_pieces[i].displayLists[j]);
                m_pieces[i].displayLists[j] = NULL;
            }
        }
    }
    SAFE_DELETE_ARRAY(m_pieces);
    m_width = 0;
    m_height = 0;
    m_pieceCount = 0;
    m_timer = 0;
    m_frame = 0;
}

void FieldMapAnimQuad::Update(int fps)
{
    FieldMapCharaPiece *piece = GetPiece(m_frame);
    if (piece == NULL) {
        return;
    }
    m_timer += 60 / fps;
    if (m_timer > piece->duration * 2) {
        m_timer = 0;
        m_frame++;
        if (m_frame >= m_pieceCount) {
            m_frame = 0;
        }
    }
}
