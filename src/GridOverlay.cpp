#include "GridOverlay.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "common.hpp"
#include "fx_utils.hpp"
#include "interpolation.hpp"

GridOverlay::GridOverlay()
{
    unk_01 = 0;
    unk_04 = 0;
    unk_08 = 0;

    unk_0C = new CPrimitiveRECT();
    for (int i = 0; i < 16; i++) {
        unk_10[i] = new CPrimitiveTRIANGLE();
    }
    for (int i = 0; i < 12; i++) {
        unk_50[i] = new CPrimitiveTRIANGLE();
    }
    for (int i = 0; i < 22; i++) {
        unk_80[i] = new CPrimitiveRECT();
    }

    SetZ(0, 0, 0);
    SetPolygonID(0, 0, 0);
    Reset();
}

GridOverlay::~GridOverlay()
{
    SAFE_DELETE(unk_0C);
    for (int i = 0; i < 16; i++) {
        SAFE_DELETE(unk_10[i]);
    }
    for (int i = 0; i < 12; i++) {
        SAFE_DELETE(unk_50[i]);
    }
    for (int i = 0; i < 22; i++) {
        SAFE_DELETE(unk_80[i]);
    }
}

void GridOverlay::Update()
{
    if (!(unk_00 & 1)) {
        return;
    }

    switch (unk_04) {
    case 1:
        UpdateOpen();
        break;
    case 2:
        UpdateClose();
        break;
    }

    unk_08++;
    if (unk_08 >= 0xD8) {
        unk_08 = 0;
    }

    int scroll = CGame::GetInstance()->unk_15D0;
    for (int i = 0; i < 22; i++) {
        CPrimitiveRECT *bar = unk_80[i];
        bar->m_rectangle.pos.x = 0;
        bar->m_rectangle.pos.y = ((scroll >> FX32_SHIFT) - i - 0x60) << FX32_SHIFT;
    }
}

void GridOverlay::UpdateOpen()
{
    unk_0C->m_alpha = LinearInterpolate(0x1000, 0x13000, ++unk_01, 16) >> FX32_SHIFT;

    int alpha = LinearInterpolate(0x1000, 0x10000, unk_01, 16) >> FX32_SHIFT;
    SetVLinesAlpha(alpha);
    SetHLinesAlpha(alpha);
    SetBarsAlpha(LinearInterpolate(0x1000, 0x18000, unk_01, 16) >> FX32_SHIFT);

    fx32 scale = LinearInterpolate(0x4000, 0x1000, unk_01, 16);
    for (int i = 0; i < 16; i++) {
        fx32 x0 = i * 0x10000;
        fx32 x = FX32_MUL(x0 - 0x80000, scale);
        unk_10[i]->SetVertex1(x, -0x60000);
        unk_10[i]->SetVertex2(x, -0x60000);
        unk_10[i]->SetVertex3(x, 0x60000);
    }
    for (int i = 0; i < 12; i++) {
        fx32 y0 = i * 0x10000;
        fx32 y = FX32_MUL(y0 - 0x60000, scale);
        unk_50[i]->SetVertex1(-0x80000, y);
        unk_50[i]->SetVertex2(-0x80000, y);
        unk_50[i]->SetVertex3(0x80000, y);
    }

    if (unk_01 >= 16) {
        unk_04 = 0;
    }
}

void GridOverlay::UpdateClose()
{
    unk_0C->m_alpha = LinearInterpolate(0x13000, 0x1000, ++unk_01, 16) >> FX32_SHIFT;

    int alpha = LinearInterpolate(0x10000, 0x1000, unk_01, 16) >> FX32_SHIFT;
    SetVLinesAlpha(alpha);
    SetHLinesAlpha(alpha);
    SetBarsAlpha(LinearInterpolate(0x18000, 0x1000, unk_01, 16) >> FX32_SHIFT);

    fx32 scale = LinearInterpolate(0x1000, 0x4000, unk_01, 16);
    for (int i = 0; i < 16; i++) {
        fx32 x0 = i * 0x10000;
        fx32 x = FX32_MUL(x0 - 0x80000, scale);
        unk_10[i]->SetVertex1(x, -0x60000);
        unk_10[i]->SetVertex2(x, -0x60000);
        unk_10[i]->SetVertex3(x, 0x60000);
    }
    for (int i = 0; i < 12; i++) {
        fx32 y0 = i * 0x10000;
        fx32 y = FX32_MUL(y0 - 0x60000, scale);
        unk_50[i]->SetVertex1(-0x80000, y);
        unk_50[i]->SetVertex2(-0x80000, y);
        unk_50[i]->SetVertex3(0x80000, y);
    }

    if (unk_01 >= 16) {
        unk_00 &= ~1;
        unk_04 = 0;
    }
}

void GridOverlay::Reset()
{
    unk_0C->m_color = 0xE2;
    unk_0C->SetPos(0, 0);
    unk_0C->m_rectangle.size.x = 0x100000;
    unk_0C->m_rectangle.size.y = 0xC0000;
    unk_0C->m_alpha = 0x13;

    for (int i = 0; i < 16; i++) {
        fx32 x = i * 0x10000;
        unk_10[i]->m_color = 0x1312;
        unk_10[i]->m_alpha = 0x10;
        unk_10[i]->SetVertex1(x - 0x80000, 0x60000);
        unk_10[i]->SetVertex2(x - 0x80000, 0x60000);
        unk_10[i]->SetVertex3(x - 0x80000, -0x60000);
    }
    for (int i = 0; i < 12; i++) {
        fx32 y = i * 0x10000;
        unk_50[i]->m_color = 0x1312;
        unk_50[i]->m_alpha = 0x10;
        unk_50[i]->SetVertex1(0x80000, y - 0x60000);
        unk_50[i]->SetVertex2(0x80000, y - 0x60000);
        unk_50[i]->SetVertex3(-0x80000, y - 0x60000);
    }
    for (int i = 0; i < 22; i++) {
        unk_80[i]->m_color = 0x373;
        unk_80[i]->SetPos(0, (0x60 - i) << FX32_SHIFT);
        unk_80[i]->m_rectangle.size.x = 0x100000;
        unk_80[i]->m_rectangle.size.y = 0x1000;
        int alpha = 0x18 - i;
        if (alpha >= 0) {
            unk_80[i]->m_alpha = alpha;
        } else {
            unk_80[i]->m_alpha = 0;
        }
    }
}

void GridOverlay::Render(Camera2D *camera)
{
    if (!(unk_00 & 1)) {
        return;
    }

    for (int i = 0; i < 22; i++) {
        unk_80[i]->Render(camera);
    }
    for (int i = 0; i < 16; i++) {
        unk_10[i]->Render(camera);
    }
    for (int i = 0; i < 12; i++) {
        unk_50[i]->Render(camera);
    }
    unk_0C->Render(camera);
}

void GridOverlay::Open()
{
    unk_04 = 1;
    unk_00 |= 1;
    unk_01 = 0;

    unk_0C->m_alpha = 1;
    for (int i = 0; i < 16; i++) {
        unk_10[i]->m_alpha = 1;
    }
    for (int i = 0; i < 12; i++) {
        unk_50[i]->m_alpha = 1;
    }
}

void GridOverlay::Close()
{
    unk_04 = 2;
    unk_00 |= 1;
    unk_01 = 0;

    unk_0C->m_alpha = 0x13;
    for (int i = 0; i < 16; i++) {
        unk_10[i]->m_alpha = 0x10;
    }
    for (int i = 0; i < 12; i++) {
        unk_50[i]->m_alpha = 0x10;
    }
}

void GridOverlay::Show()
{
    Reset();
    unk_04 = 0;
    unk_00 |= 1;
}

void GridOverlay::SetZ(fx32 backZ, fx32 linesZ, fx32 barsZ)
{
    unk_0C->m_z = backZ;
    for (int i = 0; i < 16; i++) {
        unk_10[i]->m_z = linesZ;
    }
    for (int i = 0; i < 12; i++) {
        unk_50[i]->m_z = linesZ;
    }
    for (int i = 0; i < 22; i++) {
        unk_80[i]->m_z = barsZ;
    }
}

void GridOverlay::SetPolygonID(int backID, int linesID, int barsID)
{
    unk_0C->m_polygonID = backID;
    for (int i = 0; i < 16; i++) {
        unk_10[i]->m_polygonID = linesID;
    }
    for (int i = 0; i < 12; i++) {
        unk_50[i]->m_polygonID = linesID;
    }
    for (int i = 0; i < 22; i++) {
        unk_80[i]->m_polygonID = barsID;
    }
}

void GridOverlay::SetVLinesAlpha(int alpha)
{
    for (int i = 0; i < 16; i++) {
        unk_10[i]->m_alpha = alpha;
    }
}

void GridOverlay::SetHLinesAlpha(int alpha)
{
    for (int i = 0; i < 12; i++) {
        unk_50[i]->m_alpha = alpha;
    }
}

void GridOverlay::SetBarsAlpha(int alpha)
{
    for (int i = 0; i < 22; i++) {
        unk_80[i]->m_alpha = alpha;
        if (alpha > 1) {
            alpha--;
        }
    }
}
