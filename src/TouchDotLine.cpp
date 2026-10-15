#include "TouchDotLine.hpp"

#include "CellAnimController.hpp"

TouchDotLine::TouchDotLine()
{
    m_visible = FALSE;
    m_cac = NULL;
    m_cacId = 0;
    m_alpha = 0;
    m_alphaStep = 1;
    m_cursor.m_cellDataIdx = 6;
    m_cursor.m_z = 100;
    m_dot.m_z = 99;
}

TouchDotLine::~TouchDotLine()
{
    if (m_cac != NULL && m_cacId != 0) {
        m_cac->Remove(m_cacId);
    }
}

extern "C" {

void TouchDotLine_SetRes(TouchDotLine *obj, VramImage *ncbr, VramPalette *palette, CNCERFile *ncer, CellAnimController *cac)
{
    obj->m_dot.SetResources((UnkClass_CPrimitive_ImageProxy *)ncbr, NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)palette, (UnkClass_CSoftwareSprite_38 *)ncer);
    obj->m_dot.m_cellDataIdx = 0;
    obj->m_dot.m_color = 0x7C00;
    obj->m_cursor.SetResources((UnkClass_CPrimitive_ImageProxy *)ncbr, NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)palette, (UnkClass_CSoftwareSprite_38 *)ncer);
    if (obj->m_cac != NULL && obj->m_cacId != 0) {
        obj->m_cac->Remove(obj->m_cacId);
        obj->m_cacId = 0;
        obj->m_cac = NULL;
    }
    obj->m_cac = cac;
    if (cac != NULL) {
        obj->m_cacId = cac->Create(1, 0);
    }
}

void TouchDotLine_Update(TouchDotLine *obj, int fps)
{
    if (!obj->m_visible) {
        return;
    }
    int frames = 60 / fps;
    obj->m_phase += FX32_DIV(0x40000, fps << FX32_SHIFT);
    if (obj->m_phase >= 0x10000) {
        obj->m_phase -= 0x10000;
    }
    obj->m_alpha += obj->m_alphaStep * frames;
    if (obj->m_alpha >= 0x20) {
        obj->m_alpha = 0x1F;
        obj->m_alphaStep = -1;
    } else if (obj->m_alpha <= 0) {
        obj->m_alpha = 0;
        obj->m_alphaStep = 1;
    }
}

void TouchDotLine_Draw(TouchDotLine *obj, Camera2D *camera)
{
    if (!obj->m_visible) {
        return;
    }
    fx32 dx = FX32_MUL(obj->m_dir.x, 0x10000);
    fx32 dy = FX32_MUL(obj->m_dir.y, 0x10000);
    fx32 x = obj->m_start.x + FX32_MUL(obj->m_phase, obj->m_dir.x);
    fx32 y = obj->m_start.y + FX32_MUL(obj->m_phase, obj->m_dir.y) + 0x8000;
    obj->m_dot.m_color = GX_RGB(0, obj->m_alpha, 31);
    switch (obj->m_kind) {
    case 0:
        while (x <= obj->m_end.x) {
            obj->m_dot.SetXY(x, y);
            obj->m_dot.Render(camera);
            x += dx;
            y += dy;
        }
        break;
    case 1:
        while (y >= obj->m_end.y + 0x8000) {
            obj->m_dot.SetXY(x, y);
            obj->m_dot.Render(camera);
            x += dx;
            y += dy;
        }
        break;
    case 2:
        while (x >= obj->m_end.x) {
            obj->m_dot.SetXY(x, y);
            obj->m_dot.Render(camera);
            x += dx;
            y += dy;
        }
        break;
    default:
        while (y <= obj->m_end.y + 0x8000) {
            obj->m_dot.SetXY(x, y);
            obj->m_dot.Render(camera);
            x += dx;
            y += dy;
        }
        break;
    }
    if (obj->m_cac != NULL && obj->m_cacId != 0) {
        obj->m_cursor.m_cellDataIdx = obj->m_cac->GetCell(obj->m_cacId);
    }
    obj->m_cursor.Render(camera);
    obj->m_visible = FALSE;
}

void TouchDotLine_SetLine(TouchDotLine *obj, Point2D *pos, Point2D *target)
{
    obj->m_start = *pos;
    obj->m_end = *target;
    obj->m_cursor.SetXY(target->x, target->y + 0x10000);
    Point2D d = *target - *pos;
    fx32 len = FX_Sqrt(FX32_MUL(d.x, d.x) + FX32_MUL(d.y, d.y));
    if (len <= 0x199) {
        return;
    }
    fx64 inv = FX_Inv(len);
    obj->m_dir.x = FX32_MUL(d.x, inv);
    obj->m_dir.y = FX32_MUL(d.y, inv);
    fx32 ax = obj->m_dir.x >= 0 ? obj->m_dir.x : -obj->m_dir.x;
    fx32 ay = obj->m_dir.y >= 0 ? obj->m_dir.y : -obj->m_dir.y;
    if (ax > ay) {
        if (obj->m_dir.x >= 0) {
            obj->m_kind = 0;
        } else {
            obj->m_kind = 2;
        }
    } else {
        if (obj->m_dir.y >= 0) {
            obj->m_kind = 3;
        } else {
            obj->m_kind = 1;
        }
    }
    obj->m_visible = TRUE;
}
}
