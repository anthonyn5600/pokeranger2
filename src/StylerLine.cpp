#include "battle/StylerLine.hpp"

#include "Camera2D.hpp"
#include "CellAnimController.hpp"
#include "MathUtil.hpp"
#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "fx_utils.hpp"

static const u8 sTypeFileIds[] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18 };
static const GXRgb sFlashColors[12] = { 0x421F, 0x431F, 0x43FF, 0x43F8, 0x43F0, 0x63F0, 0x7FF0, 0x7F10, 0x7E10, 0x7E18, 0x7E1F, 0x621F };
static const fx32 sFlashScale1[7] = { 0x2000, 0x1CCC, 0x1999, 0x1666, 0x1333, 0x1199, 0x1000 };
static const fx32 sFlashScale2[7] = { 0x4000, 0x3999, 0x3333, 0x2CCC, 0x2666, 0x2333, 0x2000 };

static inline void SetSpriteGraphics(CSoftwareSprite *sprite,
    VramImage *image,
    VramPalette *palette,
    CNCERFile *cells)
{
    sprite->unk_2C = (UnkClass_CPrimitive_ImageProxy *)image;
    sprite->unk_30 = NULL;
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)cells;
}

StylerLine::StylerLine()
{
    unk_54C0 = 0;
    Load();
    Reset(0, 0);
    ExtendTo(FX32_CONST(32), FX32_CONST(32));
    unk_54C8 = 0;
    m_maxCount = 0x60;
    m_width = 0x3800;
    m_lines2Count = 0;
    SetSpriteGraphics(&m_sprite0, m_image, m_palette, m_cells);
    m_sprite0.SetTransformParams(0, 0, FX32_ONE, FX32_ONE, 0, 1000);
    SetSpriteGraphics(&m_sprite1, m_image, m_palette, m_cells);
    m_sprite1.SetTransformParams(0, 0, FX32_ONE, FX32_ONE, 0, 1000);
}

StylerLine::~StylerLine()
{
    Release();
}

void StylerLine::Load()
{
    char arcPath[0x60];
    char ncbrPath[0x60];
    char nclrPath[0x60];
    char ncerPath[0x60];
    char cacPath[0x60];

    OS_SPrintf(arcPath, "data/interface/i001_LZ.bin");
    OS_SPrintf(ncbrPath, "BLN:i001_00.NCBR");
    OS_SPrintf(nclrPath, "BLN:i001.NCLR");
    OS_SPrintf(ncerPath, "BLN:i001_00.NCER");
    OS_SPrintf(cacPath, "BLN:i001_00.cac");

    CArchiveGuard *guard = new CArchiveGuard("BLN", arcPath, 1, 1, 0, NULL, 0);

    m_image = new VramImage(ncbrPath, 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->LoadToVram(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->Release();

    m_palette = new VramPalette(nclrPath, 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->LoadToVram(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->Release();

    m_cells = new CNCERFile(ncerPath, 0, 0, 0);
    m_anim = new CellAnimController();
    m_anim->Load(cacPath, 0, 0);
    m_animCell = m_anim->Create(1, 0);
    m_anim->SetAnim(m_animCell, unk_54C0);
    delete guard;

    unk_64FC = new NtfResource("data/interface/i072_00.ntft",
        "data/interface/i072_00.ntfp");
    unk_6500 = new NtfResource("data/interface/i072_01.ntft",
        "data/interface/i072_01.ntfp");

    for (int i = 0; i < 0x60; i++) {
        m_lines[i].m_color = GX_RGB(31, 0, 0);
        m_quads[i].unk_58 = (UnkClass_CPrimitive_ImageProxy *)m_image;
        m_quads[i].unk_5C = (UnkClass_CPrimitive_ImagePaletteProxy *)m_palette;
        m_quads[i].m_alpha = 30;
        m_tris[i].unk_48 = (UnkClass_CPrimitive_ImageProxy *)m_image;
        m_tris[i].unk_4C = (UnkClass_CPrimitive_ImagePaletteProxy *)m_palette;
        m_tris[i].m_alpha = 30;
        m_lines2[i].m_color = GX_RGB(0, 0, 31);
    }

    unk_6428 = FX32_DIV(m_image->unk_34 << FX32_SHIFT, FX32_CONST(96));
    m_rect.m_color = GX_RGB(0, 0, 31);
    m_rect.m_alpha = 8;
    m_rect.m_z = -16;
}

void StylerLine::Release()
{
    ReleaseTypeGfx();
    SAFE_DELETE(m_image);
    SAFE_DELETE(m_palette);
    SAFE_DELETE(m_cells);
    SAFE_DELETE(m_anim);
    SAFE_DELETE(unk_64FC);
    SAFE_DELETE(unk_6500);
    NNS_GfdFreeLnkTexVram(m_texKey);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}

void StylerLine::Render(Camera2D *camera)
{
    if (m_state == 1) {
        RenderPowered(camera);
    } else if (m_state == 2) {
        RenderPowered(camera);
    } else {
        RenderNormal(camera);
    }
    ov1_02123770(camera);
}

void StylerLine::ov1_02123770(Camera2D *camera)
{
}

void StylerLine::RenderNormal(Camera2D *camera)
{
    u16 shift = camera->unk_28;
    m_sprite0.Render(camera);
    m_sprite1.Render(camera);
    if (m_count == 0) {
        return;
    }

    NNSG2dImageProxy *img;
    NNSG2dImagePaletteProxy *pltt;
    if (m_image2 != NULL) {
        img = &m_image2->unk_08;
        pltt = &m_palette2->unk_08;
    } else {
        img = &m_image->unk_08;
        pltt = &m_palette->unk_08;
    }
    int t = unk_54B4;

    G3_PolygonAttr(GX_LIGHTMASK_NONE, GX_POLYGONMODE_MODULATE, GX_CULL_NONE, 0, 31, GX_POLYGON_ATTR_MISC_NONE);
    G3_TexImageParam(img->attr.fmt, GX_TEXGEN_TEXCOORD, img->attr.sizeS, img->attr.sizeT, GX_TEXREPEAT_ST, GX_TEXFLIP_NONE, img->attr.plttUse, NNS_G2dGetImageLocation(img, NNS_G2D_VRAM_TYPE_3DMAIN));
    G3_TexPlttBase(NNS_G2dGetImagePaletteLocation(pltt, NNS_G2D_VRAM_TYPE_3DMAIN),
        img->attr.fmt);
    G3_Begin(GX_BEGIN_QUAD_STRIP);
    G3_Color(GX_RGB(31, 31, 31));

    u16 idx = GetIndex(0);
    Point2D *prev = NULL;
    u16 i = 0;
    do {
        idx = GetIndex(i);
        u16 angle;
        Point2D *dir;
        if (prev != NULL) {
            angle = FX_Atan2Idx(prev->y + m_dirs[idx].y, prev->x + m_dirs[idx].x);
            dir = &m_dirs[idx];
        } else {
            angle = FX_Atan2Idx(m_dirs[idx].y, m_dirs[idx].x);
            dir = &m_dirs[idx];
        }
        angle = angle + 0x4001;
        Point2D pos = m_lines[idx].GetStart();
        fx32 cos = FX32_MUL(m_width, FX_CosIdx(angle));
        fx32 sin = FX32_MUL(m_width, FX_SinIdx(angle));

        G3_TexCoord(FX32_CONST(32), t);
        G3_Vtx(FX_Whole(pos.x + cos) << shift, FX_Whole(pos.y + sin) << shift, unk_54BC + i);
        G3_TexCoord(0, t);
        G3_Vtx(FX_Whole(pos.x - cos) << shift, FX_Whole(pos.y - sin) << shift, unk_54BC + i);
        t += unk_54B8;
        prev = dir;
        i++;
    } while (i <= m_count);
    G3_End();
}

void StylerLine::RenderPowered(Camera2D *camera)
{
    u16 shift = camera->unk_28;

    G3_PolygonAttr(GX_LIGHTMASK_NONE, GX_POLYGONMODE_MODULATE, GX_CULL_NONE, 0, 31, GX_POLYGON_ATTR_MISC_NONE);
    G3_TexImageParam(GX_TEXFMT_A5I3, GX_TEXGEN_TEXCOORD, GX_TEXSIZE_S16, GX_TEXSIZE_T16, GX_TEXREPEAT_NONE, GX_TEXFLIP_NONE, GX_TEXPLTTCOLOR0_USE, unk_6500->m_texAddr);
    G3_TexPlttBase(unk_6500->m_plttAddr, GX_TEXFMT_A5I3);
    u8 colorIdx = unk_54D1;
    G3_Begin(GX_BEGIN_QUADS);
    G3_Color(GX_RGB(31, 31, 31));

    Point2D pos = *(Point2D *)m_sprite0.m_coords;
    G3_TexCoord(0, 0);
    G3_Vtx(FX_Whole(pos.x - unk_54AC) << shift,
        FX_Whole(pos.y - unk_54AC) << shift,
        unk_54BC + 0x60);
    G3_TexCoord(FX32_CONST(16), 0);
    G3_VtxXY(FX_Whole(pos.x + unk_54AC) << shift, FX_Whole(pos.y - unk_54AC) << shift);
    G3_TexCoord(FX32_CONST(16), FX32_CONST(16));
    G3_VtxXY(FX_Whole(pos.x + unk_54AC) << shift, FX_Whole(pos.y + unk_54AC) << shift);
    G3_TexCoord(0, FX32_CONST(16));
    G3_VtxXY(FX_Whole(pos.x - unk_54AC) << shift, FX_Whole(pos.y + unk_54AC) << shift);

    Point2D pos1 = *(Point2D *)m_sprite1.m_coords;
    G3_TexCoord(0, 0);
    G3_VtxXY(FX_Whole(pos1.x - unk_54AC) << shift, FX_Whole(pos1.y - unk_54AC) << shift);
    G3_TexCoord(FX32_CONST(16), 0);
    G3_VtxXY(FX_Whole(pos1.x + unk_54AC) << shift, FX_Whole(pos1.y - unk_54AC) << shift);
    G3_TexCoord(FX32_CONST(16), FX32_CONST(16));
    G3_VtxXY(FX_Whole(pos1.x + unk_54AC) << shift, FX_Whole(pos1.y + unk_54AC) << shift);
    G3_TexCoord(0, FX32_CONST(16));
    G3_VtxXY(FX_Whole(pos1.x - unk_54AC) << shift, FX_Whole(pos1.y + unk_54AC) << shift);
    G3_End();

    if (m_count == 0) {
        return;
    }

    int t = unk_54B4;
    G3_TexImageParam(GX_TEXFMT_NONE, GX_TEXGEN_TEXCOORD, GX_TEXSIZE_S32, GX_TEXSIZE_T32, GX_TEXREPEAT_ST, GX_TEXFLIP_NONE, GX_TEXPLTTCOLOR0_USE, unk_64FC->m_texAddr);
    G3_TexPlttBase(unk_64FC->m_plttAddr, GX_TEXFMT_NONE);
    G3_Begin(GX_BEGIN_QUAD_STRIP);

    u16 idx = GetIndex(0);
    Point2D *prev = NULL;
    u16 i = 0;
    do {
        if (colorIdx >= 11) {
            colorIdx = 0;
        } else {
            colorIdx++;
        }
        G3_Color(sFlashColors[colorIdx]);
        idx = GetIndex(i);
        u16 angle;
        Point2D *dir;
        if (prev != NULL) {
            angle = FX_Atan2Idx(prev->y + m_dirs[idx].y, prev->x + m_dirs[idx].x);
            dir = &m_dirs[idx];
        } else {
            angle = FX_Atan2Idx(m_dirs[idx].y, m_dirs[idx].x);
            dir = &m_dirs[idx];
        }
        angle = angle + 0x4001;
        Point2D pos = m_lines[idx].GetStart();
        fx32 cos = FX32_MUL(m_width, FX_CosIdx(angle));
        fx32 sin = FX32_MUL(m_width, FX_SinIdx(angle));

        fx16 z = unk_54BC + i;
        G3_TexCoord(FX32_CONST(32), t);
        G3_Vtx(FX_Whole(pos.x + cos) << shift, FX_Whole(pos.y + sin) << shift, z);
        G3_TexCoord(0, t);
        G3_Vtx(FX_Whole(pos.x - cos) << shift, FX_Whole(pos.y - sin) << shift, z);
        t += unk_54B8;
        prev = dir;
        i++;
    } while (i <= m_count);
    G3_End();
}

void StylerLine::Update()
{
    u16 cell;
    if (m_image2 != NULL) {
        m_anim2->Update(m_animCell2);
        cell = m_anim2->GetCell(m_animCell2);
    } else {
        m_anim->Update(m_animCell);
        cell = m_anim->GetCell(m_animCell);
    }
    m_sprite0.m_cellDataIdx = cell;
    m_sprite1.m_cellDataIdx = cell;
    m_sprite0.SetPos(m_lines[m_tail].GetStart());

    if (m_state == 1) {
        if (++unk_54D0 >= 7) {
            unk_54D0 -= 7;
        }
        m_width = FX32_MUL(sFlashScale1[unk_54D0], FX32_ONE);
        unk_54AC = FX32_MUL(sFlashScale1[unk_54D0], FX32_CONST(10));
        if (++unk_54D1 >= 12) {
            unk_54D1 -= 12;
        }
        m_color = sFlashColors[unk_54D1];
    }
    if (m_state == 2) {
        if (++unk_54D0 >= 7) {
            unk_54D0 -= 7;
        }
        m_width = FX32_MUL(sFlashScale2[unk_54D0], FX32_ONE);
        unk_54AC = FX32_MUL(sFlashScale2[unk_54D0], FX32_CONST(10));
        if (++unk_54D1 >= 12) {
            unk_54D1 -= 12;
        }
        m_color = sFlashColors[unk_54D1];
    }
    if (m_state == 4) {
        unk_54B4 += 0x3000;
        if (unk_54B4 <= -FX32_CONST(32)) {
            unk_54B4 += FX32_CONST(32);
        } else if (unk_54B4 >= FX32_CONST(32)) {
            unk_54B4 -= FX32_CONST(32);
        }
    }
}

void StylerLine::AddSegment(fx32 x, fx32 y)
{
    CPrimitiveLINE *line = &m_lines[m_head];
    line->m_points.p2.x = x;
    line->m_points.p2.y = y;
    Point2D start = line->GetStart();
    Point2D end = line->GetEnd();
    m_dirs[m_head].x = end.x - start.x;
    m_dirs[m_head].y = end.y - start.y;
    m_head++;
    m_head = WrapIndex(m_head);
    line = &m_lines[m_head];
    line->m_points.p1.x = x;
    line->m_points.p1.y = y;
    m_count++;
    if (m_count > m_maxCount) {
        m_tail++;
        m_tail = WrapIndex(m_tail);
        m_count = m_maxCount;
    }
}

u8 StylerLine::ExtendTo(fx32 x, fx32 y)
{
    Point2D target = { x, y };
    CPrimitiveLINE *line = &m_lines[m_head];
    fx32 dx = x - line->m_points.p1.x;
    fx32 dy = y - line->m_points.p1.y;
    u8 count = 0;
    fx32 len = ApproxLength(dx, dy);
    fx32 ux = FX32_DIV(dx, len);
    fx32 uy = FX32_DIV(dy, len);
    if (len >= FX32_CONST(8)) {
        int steps = FX_Whole(FX32_DIV(len, FX32_CONST(8)));
        for (int i = 0; i < steps; i++) {
            AddSegment(m_lines[m_head].m_points.p1.x + FX32_MUL(ux, FX32_CONST(8)),
                m_lines[m_head].m_points.p1.y + FX32_MUL(uy, FX32_CONST(8)));
            unk_54C8++;
            unk_54CC++;
            count++;
        }
    }
    m_sprite1.SetXY(target.x, target.y);
    return count;
}

void StylerLine::Reset(fx32 x, fx32 y)
{
    m_count = 0;
    m_tail = 0;
    m_head = 0;
    m_hitIndex = 0;
    unk_54CC = 0;
    m_sprite0.SetXY(x, y);
    m_sprite1.SetXY(x, y);
    m_lines[0].m_points.p1.x = x;
    m_lines[0].m_points.p1.y = y;
}

BOOL StylerLine::FindCrossing(PointPair2D seg)
{
    u16 idx;
    for (u16 i = 0; i < m_count - 1; i++) {
        idx = i + m_tail;
        if (idx >= 0x60) {
            idx -= 0x60;
        }
        if (SegmentHitSegmentBBox(m_lines[idx].m_points, seg, NULL)) {
            m_hitIndex = idx;
            return TRUE;
        }
    }
    return FALSE;
}

BOOL StylerLine::IsInsideLoop(fx32 x, fx32 y)
{
    Point2D pos = { x, y };
    if (!PointInRect(pos, m_rect.m_rectangle, 0)) {
        return FALSE;
    }

    u16 hitsY = 0;
    u16 hitsX = 0;
    PointPair2D ray;
    ray.p1.x = x;
    ray.p1.y = y;
    ray.p2.x = -FX32_CONST(128);
    ray.p2.y = y;
    for (u16 i = 0; i < m_lines2Count; i++) {
        if (SegmentHitSegment(ray, m_lines2[i].m_points, NULL, FALSE)) {
            hitsX++;
            m_lines2[i].m_color = GX_RGB(31, 31, 0);
        }
    }
    if (hitsX == 0) {
        return FALSE;
    }

    ray.p2.x = x;
    ray.p2.y = -FX32_CONST(128);
    for (u16 i = 0; i < m_lines2Count; i++) {
        if (SegmentHitSegment(ray, m_lines2[i].m_points, NULL, FALSE)) {
            hitsY++;
            m_lines2[i].m_color = GX_RGB(0, 31, 31);
        }
    }
    if (hitsY == 0) {
        return FALSE;
    }
    if ((hitsY & 1) && (hitsX & 1)) {
        return TRUE;
    }
    return FALSE;
}

void StylerLine::CutAt(u16 hit)
{
    if (hit == m_tail) {
        Point2D pos = m_lines[m_head].GetStart();
        m_count = 0;
        m_tail = 0;
        m_head = 0;
        m_hitIndex = 0;
        m_lines[0].m_points.p1.x = pos.x;
        m_lines[0].m_points.p1.y = pos.y;
        return;
    }

    if (hit != 0) {
        m_head = hit - 1;
    } else {
        m_head = 0x5F;
    }
    u16 i = m_tail;
    m_count = 0;
    while (TRUE) {
        if (i == m_head) {
            return;
        }
        i = WrapIndex(i + 1);
        m_count++;
    }
}

void StylerLine::BuildLoop(u16 from, u16 to)
{
    m_lines2Count = 0;
    u16 i = from;
    while (TRUE) {
        m_lines2[m_lines2Count] = m_lines[i];
        m_lines2[m_lines2Count].m_color = GX_RGB(0, 0, 31);
        if (i == to) {
            break;
        }
        m_lines2Count++;
        i = WrapIndex(i + 1);
    }

    m_lines2[m_lines2Count].SetStart(m_lines2[m_lines2Count - 1].GetEnd());
    m_lines2[m_lines2Count].SetEnd(m_lines2[0].GetStart());
    m_lines2[m_lines2Count].m_color = GX_RGB(0, 0, 31);
    m_lines2Count++;
    fx32 minX = m_lines2[0].m_points.p2.x;
    fx32 maxX = minX;
    fx32 minY = m_lines2[0].m_points.p2.y;
    fx32 maxY = minY;
    for (int j = 0; j < m_lines2Count; j++) {
        fx32 px = m_lines2[j].m_points.p2.x;
        if (minX >= px) {
            minX = px;
        }
        if (maxX <= px) {
            maxX = px;
        }
        fx32 py = m_lines2[j].m_points.p2.y;
        if (minY >= py) {
            minY = py;
        }
        if (maxY <= py) {
            maxY = py;
        }
    }
    m_rect.m_rectangle.pos.x = (minX + maxX) >> 1;
    m_rect.m_rectangle.pos.y = (minY + maxY) >> 1;
    m_rect.m_rectangle.size.x = maxX - minX;
    m_rect.m_rectangle.size.y = maxY - minY;
}

u16 StylerLine::WrapIndex(u16 index)
{
    return index >= 0x60 ? (u16)(index - 0x60) : index;
}

u16 StylerLine::GetIndex(u16 i)
{
    return WrapIndex(i + m_tail);
}

void StylerLine::SetMaxCount(u16 arg0)
{
    if (arg0 >= 0x60) {
        m_maxCount = 0x60;
    } else {
        m_maxCount = arg0;
    }
}

void StylerLine::LoadTypeGfx(int type)
{
    char arcPath[0x60];
    char ncbrPath[0x60];
    char nclrPath[0x60];
    char ncerPath[0x60];
    char cacPath[0x60];

    ReleaseTypeGfx();
    u8 id = sTypeFileIds[type];
    OS_SPrintf(arcPath, "data/interface/i%03d_LZ.bin", id);
    OS_SPrintf(ncbrPath, "BAL:i%03d_00.NCBR", id);
    OS_SPrintf(nclrPath, "BAL:i%03d.NCLR", id);
    OS_SPrintf(ncerPath, "BAL:i%03d_00.NCER", id);
    OS_SPrintf(cacPath, "BAL:i%03d_00.cac", id);

    CArchiveGuard *guard = new CArchiveGuard("BAL", arcPath, 1, 1, 0, NULL, 0);

    m_image2 = new VramImage(ncbrPath, 0, 0, 0);
    m_texKey2 = NNS_GfdAllocLnkTexVram(m_image2->unk_38, FALSE, 0);
    m_image2->LoadToVram(NNS_GfdGetTexKeyAddr(m_texKey2));
    m_image2->Release();

    m_palette2 = new VramPalette(nclrPath, 0, 0);
    m_plttKey2 = NNS_GfdAllocLnkPlttVram(m_palette2->unk_04->szByte, FALSE, 0);
    m_palette2->LoadToVram(NNS_GfdGetPlttKeyAddr(m_plttKey2));
    m_palette2->Release();

    m_cells2 = new CNCERFile(ncerPath, 0, 0, 0);
    m_anim2 = new CellAnimController();
    m_anim2->Load(cacPath, 0, 0);
    m_animCell2 = m_anim2->Create(1, 0);
    m_anim2->SetAnim(m_animCell2, unk_54C0);
    delete guard;

    for (u8 i = 0; i < 0x60; i++) {
        m_quads[i].unk_58 = (UnkClass_CPrimitive_ImageProxy *)m_image2;
        m_quads[i].unk_5C = (UnkClass_CPrimitive_ImagePaletteProxy *)m_palette2;
    }
    SetSpriteGraphics(&m_sprite0, m_image2, m_palette2, m_cells2);
    SetSpriteGraphics(&m_sprite1, m_image2, m_palette2, m_cells2);

    if (type == 6) {
        m_state = 4;
        unk_54B4 = 0;
        unk_54B8 = FX32_CONST(24);
    } else {
        m_state = 3;
        unk_54B4 = 0;
        unk_54B8 = FX32_CONST(8);
    }
}

void StylerLine::ReleaseTypeGfx()
{
    if (m_image2 == NULL) {
        return;
    }
    m_anim2->Remove(m_animCell2);
    SAFE_DELETE(m_image2);
    SAFE_DELETE(m_palette2);
    SAFE_DELETE(m_cells2);
    SAFE_DELETE(m_anim2);
    NNS_GfdFreeLnkTexVram(m_texKey2);
    NNS_GfdFreeLnkPlttVram(m_plttKey2);
    unk_54B4 = 0;
    unk_54B8 = FX32_CONST(8);
    SetNormal();
}

void StylerLine::SetNormal()
{
    m_width = 0x3800;
    SetSpriteGraphics(&m_sprite0, m_image, m_palette, m_cells);
    SetSpriteGraphics(&m_sprite1, m_image, m_palette, m_cells);
    m_state = 0;
}

void StylerLine::SetPowerLevel1()
{
    unk_54A6 = 0;
    unk_54D0 = 0;
    unk_54D1 = 0;
    m_state = 1;
}

void StylerLine::SetPowerLevel2()
{
    m_state = 2;
}
