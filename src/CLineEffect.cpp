#include "battle/CLineEffect.hpp"

#include "CActorData.hpp"
#include "UnkClass_02008788.hpp"
#include "fx_utils.hpp"
#include "primitive/CSoftwareSprite.hpp"
#include "sub_02007254.hpp"

CLineEffect::CLineEffect()
{
    ov1_0212E620();
    sub_02011FF4(unk_184);
    unk_184->sub_020141AC(NNS_GfdGetTexKeyAddr(NNS_GfdAllocLnkTexVram(unk_184->sub_02014310(), FALSE, 0)));
    unk_184->sub_020142B4();
    unk_184->sub_0201429C(NNS_GfdGetPlttKeyAddr(NNS_GfdAllocLnkPlttVram(unk_184->sub_02014364(), FALSE, 0)));
    unk_184->sub_020142F8();
    m_leader = NULL;
    unk_194 = 0;
    unk_198 = 0x1000;
}

CLineEffect::~CLineEffect()
{
    ov1_0212E66C();
}

void CLineEffect::ov1_0212E620()
{
    unk_184 = new CActorData("data/disk02_LZ.bin", "disk02", 1, TRUE, NULL);
}

void CLineEffect::ov1_0212E66C()
{
    SAFE_DELETE(unk_184);
}

void CLineEffect::ov1_0212E69C(fx32 arg0, fx32 arg1, CActor *leader)
{
    m_leader = leader;
    unk_194 = arg0;
    unk_198 = arg1;
}

void CLineEffect::vfunc_08()
{
    Point2D pos = m_motion.GetPos();
    if (m_leader == NULL) {
        return;
    }
    Point2D lpos = m_leader->m_motion.GetPos();
    fx32 dx = pos.x - lpos.x;
    fx32 dy = pos.y - lpos.y;
    fx32 dist = sub_02007254(dx, dy);
    u16 angle = FX_Atan2Idx(dy, dx);
    fx32 radius = unk_194;
    if (dist > radius) {
        m_motion.sub_02011D1C(lpos.x + FX32_MUL(radius, FX_CosIdx(angle)));
        m_motion.sub_02011D2C(lpos.y + FX32_MUL(radius, FX_SinIdx(angle)));
    }
    if (dist < unk_194) {
        m_motion.sub_02011D1C(lpos.x + FX32_DIV(dx, 0x2000));
        m_motion.sub_02011D2C(lpos.y + FX32_DIV(dy, 0x2000));
    }
}

void CLineEffect::vfunc_0C(Camera2D *camera)
{
    CActorAnim *anim = m_data->GetAnim(unk_C0);
    CSoftwareSprite *sprite = m_sprite;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)anim->image, NULL);
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)anim->cells;
    sprite->m_cellDataIdx = anim->bank->sub_02008828(unk_C8[unk_C0]);
    sprite->SetPos(m_motion.GetPos());
    sprite->m_alpha = 0x10;
    sprite->m_scale[0] = unk_198;
    sprite->m_scale[1] = unk_198;
    sprite->Render(camera);
}

void CLineEffect::vfunc_10(Camera2D *camera)
{
}
