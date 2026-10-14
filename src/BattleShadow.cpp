#include "BattleShadow.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "common.hpp"

BattleShadow::BattleShadow()
{
    Load();
}

BattleShadow::~BattleShadow()
{
    Release();
}

void BattleShadow::Load()
{
    unk_00 = new VramImage("data/shadow.NCBR", 0, 0, 0);
    unk_0C = NNS_GfdAllocLnkTexVram(unk_00->unk_38, FALSE, 0);
    unk_00->LoadToVram(NNS_GfdGetTexKeyAddr(unk_0C));
    unk_00->Release();

    unk_04 = new VramPalette("data/shadow.NCLR", 0, 0);
    unk_10 = NNS_GfdAllocLnkPlttVram(unk_04->unk_04->szByte, FALSE, 0);
    unk_04->LoadToVram(NNS_GfdGetPlttKeyAddr(unk_10));
    unk_04->Release();

    unk_08 = new CPrimitiveRECT();
    unk_08->SetRectangle(0, 0, 0, 0, 0x3FF);
    unk_08->SetTexCoords(0, 0, FX32_CONST(64), FX32_CONST(32));
    unk_08->unk_38 = (UnkClass_CPrimitive_ImageProxy *)unk_00;
    unk_08->unk_3C = (UnkClass_CPrimitive_ImagePaletteProxy *)unk_04;
}

void BattleShadow::Release()
{
    SAFE_DELETE(unk_00);
    SAFE_DELETE(unk_04);
    if (unk_08 != NULL) {
        delete unk_08;
        unk_08 = NULL;
    }
    NNS_GfdFreeLnkTexVram(unk_0C);
    NNS_GfdFreeLnkPlttVram(unk_10);
}

void BattleShadow::SetRectangle(Rectangle *rect, fx32 z)
{
    if (rect == NULL) {
        return;
    }
    unk_08->SetRectangle(rect->pos.x, rect->pos.y, rect->size.x, rect->size.y, z);
}

void BattleShadow::SetPolygonID(int id)
{
    unk_08->m_polygonID = id;
}

void BattleShadow::SetAlpha(int alpha)
{
    unk_08->m_alpha = alpha;
}

void BattleShadow::Render(Camera2D *camera)
{
    unk_08->Render(camera);
}
