#include <nitro.h>

#include "Camera2D.hpp"
#include "common.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "scene/COPDScreen.hpp"

static const int sBarAlphas[7] = { 5, 13, 24, 30, 24, 13, 5 };
static const fx32 sBarWidths[7] = { 0x1000, 0x1000, 0x2000, 0x18000, 0x2000, 0x1000, 0x1000 };

UnkClass_02129E98::UnkClass_02129E98()
{
    unk_1C0 = 0;
    unk_1C4 = 0;
    unk_1C8 = 0;
    unk_1CC = 0;
    unk_1D0 = -0x70000;
    fx32 x = -0x10000;
    for (int i = 0; i < 7; i++) {
        unk_000[i].m_polygonID = 6;
        unk_000[i].m_z = 0x68;
        unk_000[i].SetSize(sBarWidths[i], 0x64000);
        unk_000[i].SetPos(x + (sBarWidths[i] >> 1), 0);
        unk_000[i].m_polygonMode = GX_POLYGONMODE_SHADOW;
        unk_000[i].m_alpha = sBarAlphas[i];
        x += sBarWidths[i];
    }
}

UnkClass_02129E98::~UnkClass_02129E98()
{
}

void UnkClass_02129E98::Update()
{
    if (unk_1C4 != 0) {
        unk_1C0 += unk_1C4;
        unk_1CC = unk_1C0;
        if (unk_1C0 >= 0x80000) {
            unk_1C4 = 0;
            unk_1C8 = 360;
        }
    } else if (unk_1C8 != 0) {
        unk_1C8--;
    } else {
        unk_1C4 = 0x8000;
        unk_1CC = unk_1C0 = -0xC0000;
    }
}

void UnkClass_02129E98::Render(Camera2D *camera)
{
    if (unk_1C4 == 0) {
        return;
    }
    GX_SetVisibleWnd(GX_WNDMASK_W0);
    u16 cs = camera->unk_28;
    MtxFx33 mtx;
    MTX_RotZ33(&mtx, FX_SinIdx(0x11C0), FX_CosIdx(0x11C0));
    int shift = FX32_SHIFT - cs;
    fx32 x = unk_1CC >> shift;
    fx32 y = unk_1D0 >> shift;
    for (int i = 0; i < 7; i++) {
        G3_RestoreMtx(0);
        G3_Translate(x, y, 0);
        G3_MultMtx33(&mtx);
        unk_000[i].Render(camera);
    }
    GX_SetVisibleWnd(GX_WNDMASK_NONE);
}
