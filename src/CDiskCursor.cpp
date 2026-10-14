#include "battle/CDiskCursor.hpp"

#include "CActorData.hpp"
#include "CellAnimController.hpp"
#include "primitive/CSoftwareSprite.hpp"

CDiskCursor::CDiskCursor()
{
    ov1_0212E410();
    SetData(unk_184);
    unk_184->LoadImagesToVram(NNS_GfdGetTexKeyAddr(NNS_GfdAllocLnkTexVram(unk_184->GetImagesSize(), FALSE, 0)));
    unk_184->ReleaseImages();
    unk_184->LoadPaletteToVram(NNS_GfdGetPlttKeyAddr(NNS_GfdAllocLnkPlttVram(unk_184->GetPaletteSize(), FALSE, 0)));
    unk_184->ReleasePalette();
}

CDiskCursor::~CDiskCursor()
{
    ov1_0212E45C();
}

void CDiskCursor::ov1_0212E410()
{
    unk_184 = new CActorData("data/cursor_LZ.bin", "cursor", 1, TRUE, NULL);
}

void CDiskCursor::ov1_0212E45C()
{
    SAFE_DELETE(unk_184);
}

void CDiskCursor::vfunc_08()
{
    Update();
}

void CDiskCursor::vfunc_0C(Camera2D *camera)
{
    CActorAnim *anim = m_data->GetAnim(unk_C0);
    CSoftwareSprite *sprite = m_sprite;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)anim->image, NULL);
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)anim->cells;
    sprite->m_cellDataIdx = anim->bank->GetCell(unk_C8[unk_C0]);
    sprite->SetPos(m_motion.GetPos());
    sprite->Render(camera);
}

void CDiskCursor::vfunc_10(Camera2D *camera)
{
}
