#include <nitro.h>

#include "CPlayerHPGauge.hpp"
#include "Camera2D.hpp"
#include "CellAnimController.hpp"
#include "common.hpp"
#include "primitive/CSoftwareSprite.hpp"
#include "scene/COPDScreen.hpp"

static void BindLineTexture(COPDCaptureLine *line);

static inline void SetSpriteRes(CSoftwareSprite *sprite, VramImage *image, VramPalette *palette, CNCERFile *cells)
{
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)cells;
}

COPDCaptureLine::~COPDCaptureLine()
{
    Release();
}

void COPDCaptureLine::Init(int count)
{
    if (unk_1C != NULL) {
        delete[] unk_1C;
        unk_1C = NULL;
    }
    unk_20 = count * 2;
    if (unk_20 > 0) {
        unk_1C = new Point2D[unk_20];
    }
    m_res = new GraphicsSet("OPD", "data/interface/i001_LZ.bin", "OPD:i001_00.NCBR", "OPD:i001.NCLR", "OPD:i001_00.NCER", "OPD:i001_00.cac");
    SetSpriteRes(&m_sprite, m_res->m_image, m_res->m_palette, m_res->m_cells);
    m_sprite.m_coords[0] = 0;
    m_sprite.m_coords[1] = 0;
    if (m_res->m_anim != NULL) {
        m_cellId = m_res->m_anim->Create(1, 0);
    }
    unk_24 = unk_28 = 0;
}

void COPDCaptureLine::Release()
{
    if (m_res != NULL && m_cellId != 0 && m_res->m_anim != NULL) {
        m_res->m_anim->Remove(m_cellId);
        m_cellId = 0;
    }
    SAFE_DELETE(m_res);
    if (unk_1C != NULL) {
        delete unk_1C;
        unk_1C = NULL;
    }
    unk_20 = 0;
}

void COPDCaptureLine::SetPoints(Point2D *points, int count)
{
    if ((u32)count < 2) {
        return;
    }
    Point2D *p = &points[1];
    for (int i = 1; (u32)i < (u32)count; i++, p++) {
        if (i < 2) {
            Point2D n = p[0] - p[-1];
            fx32 w = FX32_MUL(FX_InvSqrt(FX32_MUL(n.x, n.x) + FX32_MUL(n.y, n.y)), 0x4000);
            n *= w;
            fx32 x = p[-1].x;
            fx32 y = p[-1].y;
            unk_1C[(i - 1) * 2].x = x + n.y;
            unk_1C[(i - 1) * 2].y = y - n.x;
            unk_1C[(i - 1) * 2 + 1].x = x - n.y;
            unk_1C[(i - 1) * 2 + 1].y = y + n.x;
        } else {
            Point2D a = p[0] - p[-2];
            a *= FX_InvSqrt(FX32_MUL(a.x, a.x) + FX32_MUL(a.y, a.y));
            Point2D b = p[-1] - p[-2];
            b *= FX_InvSqrt(FX32_MUL(b.x, b.x) + FX32_MUL(b.y, b.y));
            fx32 k = FX32_DIV(0x4000, FX32_MUL(a.x, b.x) + FX32_MUL(a.y, b.y));
            fx32 mx = FX32_MUL(a.x, k);
            fx32 my = FX32_MUL(a.y, k);
            fx32 x = p[-1].x;
            fx32 y = p[-1].y;
            unk_1C[(i - 1) * 2].x = x + my;
            unk_1C[(i - 1) * 2].y = y - mx;
            unk_1C[(i - 1) * 2 + 1].x = x - my;
            unk_1C[(i - 1) * 2 + 1].y = y + mx;
        }
    }
    Point2D *last = points + count - 1;
    Point2D n = *last - last[-1];
    fx32 w = FX32_MUL(FX_InvSqrt(FX32_MUL(n.x, n.x) + FX32_MUL(n.y, n.y)), 0x4000);
    n *= w;
    fx32 x = last->x;
    fx32 y = last->y;
    unk_1C[(count - 1) * 2].x = x + n.y;
    unk_1C[(count - 1) * 2].y = y - n.x;
    unk_1C[(count - 1) * 2 + 1].x = x - n.y;
    unk_1C[(count - 1) * 2 + 1].y = y + n.x;
    unk_24 = count;
}

u32 COPDCaptureLine::Render(Camera2D *camera)
{
    u32 n;
    int i;
    Point2D *p;
    p = unk_1C;
    n = (u32)unk_28 > (u32)unk_24 ? unk_24 : unk_28;
    if ((u32)unk_28 > 0xC0) {
        if ((u32)unk_28 > (u32)unk_24) {
            n = 0xC0 - (unk_28 - unk_24);
            if ((int)n <= 0) {
                return 0;
            }
            p += (unk_28 - 0xC0) * 2;
        } else {
            p += (n - 0xC0) * 2;
            n = 0xC0;
        }
    }
    if ((int)n < 2) {
        return 0;
    }
    Point2D *end = p + n * 2;
    Point2D *a = end - 2;
    Point2D *b = end - 1;
    Point2D head;
    head.x = (p[0].x + p[1].x) >> 1;
    head.y = (p[0].y + p[1].y) >> 1;
    Point2D tail;
    tail.x = (a->x + b->x) >> 1;
    tail.y = (a->y + b->y) >> 1;
    s16 cs = camera->unk_28;
    G3_RestoreMtx(0);
    BindLineTexture(this);
    G3_Color(m_color);
    s16 shift = FX32_SHIFT - cs;
    i = 0;
    while ((int)n >= 2) {
        G3_PolygonAttr(GX_LIGHTMASK_NONE, m_polygonMode, GX_CULL_NONE, i + m_polygonID, m_alpha, 0);
        G3_Begin(GX_BEGIN_QUAD_STRIP);
        fx32 s = 0;
        G3_TexCoord(s, 0);
        G3_Vtx(p->x >> shift, p->y >> shift, m_z + i);
        p++;
        if (p >= unk_1C + unk_20) {
            p = unk_1C;
        }
        u32 count = ((int)n < 0x40 ? n : 0x40) * 2;
        for (u32 j = 1; j < count; j++) {
            s = 0x20000 - s;
            G3_TexCoord(s, 0);
            G3_VtxXY(p->x >> shift, p->y >> shift);
            p++;
            if (p >= unk_1C + unk_20) {
                p = unk_1C;
            }
        }
        n -= 0x3F;
        G3_End();
        p -= 2;
        i++;
    }
    G3_PopMtx(0);
    if (m_cellId != 0 && m_res->m_anim != NULL) {
        m_sprite.m_cellDataIdx = m_res->m_anim->GetCell(m_cellId);
    }
    m_sprite.SetPos(head);
    m_sprite.m_z = m_z;
    m_sprite.Render(camera);
    m_sprite.SetPos(tail);
    m_sprite.m_z = m_z + i;
    m_sprite.Render(camera);
    return 1;
}

static void BindLineTexture(COPDCaptureLine *line)
{
    COPDTexture *tex = line->unk_18;
    if (tex == NULL) {
        return;
    }
    G3_TexImageParam((GXTexFmt)tex->unk_1C, GX_TEXGEN_TEXCOORD, (GXTexSizeS)tex->unk_20, (GXTexSizeT)tex->unk_24, GX_TEXREPEAT_ST, GX_TEXFLIP_NONE, GX_TEXPLTTCOLOR0_USE, tex->m_tex.m_texAddr);
    G3_TexPlttBase(tex->m_tex.m_plttAddr, (GXTexFmt)tex->unk_1C);
}

void COPDCaptureLine::UpdateAnim()
{
    if (m_res->m_anim != NULL) {
        m_res->m_anim->UpdateAll();
    }
}
