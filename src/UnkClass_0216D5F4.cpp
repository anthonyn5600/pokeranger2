#include "UnkClass_0216D5F4.hpp"

#include <nitro.h>

#include "CPlayerHPGauge.hpp"

void UnkClass_0216D5F4::Init(GraphicsSet *gfx)
{
    unk_00.unk_38 = (UnkClass_CPrimitive_ImageProxy *)gfx->m_image;
    unk_00.unk_3C = (UnkClass_CPrimitive_ImagePaletteProxy *)gfx->m_palette;
    unk_00.m_color = 0x7FFF;
    unk_00.m_polygonID = 0;
    unk_00.SetSize(0x10000, 0x20000);
}

static inline void DrawGlyph(UnkClass_0216D5F4 *timer, fx32 u1, fx32 u2, fx32 x, Camera2D *camera)
{
    timer->unk_00.SetTexCoords(u1, 0, u2, 0x10000);
    timer->unk_00.SetPos(x, -0x4F000);
    timer->unk_00.Render(camera);
}

static inline void DrawDigit(UnkClass_0216D5F4 *timer, int d, fx32 x, Camera2D *camera)
{
    DrawGlyph(timer, d << 16, (d * 16 + 10) << 12, x, camera);
}

void UnkClass_0216D5F4::Draw(int time, fx32 z, Camera2D *camera)
{
    int secs = time / 60;
    int min = secs / 60;
    int sec = secs % 60;
    unk_00.m_z = z;
    DrawDigit(this, sec % 10, 0x77000, camera);
    DrawDigit(this, sec / 10, 0x67000, camera);
    DrawGlyph(this, 0xA0000, 0xA8000, 0x57000, camera);
    DrawDigit(this, min % 10, 0x47000, camera);
    min /= 10;
    for (int i = 0; min != 0; i++) {
        DrawDigit(this, min % 10, (0x77 - (i + 4) * 16) << 12, camera);
        min /= 10;
    }
}
