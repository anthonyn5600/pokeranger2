#include "battle/CDiskCursor.hpp"

#include "CActorData.hpp"
#include "UnkClass_02008788.hpp"
#include "primitive/CSoftwareSprite.hpp"

CDiskCursor::CDiskCursor()
{
    ov1_0212E410();
    sub_02011FF4(unk_184);
    unk_184->sub_020141AC(NNS_GfdGetTexKeyAddr(NNS_GfdAllocLnkTexVram(unk_184->sub_02014310(), FALSE, 0)));
    unk_184->sub_020142B4();
    unk_184->sub_0201429C(NNS_GfdGetPlttKeyAddr(NNS_GfdAllocLnkPlttVram(unk_184->sub_02014364(), FALSE, 0)));
    unk_184->sub_020142F8();
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
    sub_020121F4();
}

void CDiskCursor::vfunc_0C(Camera2D *camera)
{
    CActorAnim *anim = m_data->GetAnim(unk_C0);
    CSoftwareSprite *sprite = m_sprite;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)anim->image, NULL);
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)anim->cells;
    sprite->m_cellDataIdx = anim->bank->sub_02008828(unk_C8[unk_C0]);
    sprite->SetPos(m_motion.GetPos());
    sprite->Render(camera);
}

void CDiskCursor::vfunc_10(Camera2D *camera)
{
}
