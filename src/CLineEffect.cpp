#include "battle/CLineEffect.hpp"

#include "CActorData.hpp"
#include "CellAnimController.hpp"
#include "MathUtil.hpp"
#include "fx_utils.hpp"
#include "primitive/CSoftwareSprite.hpp"

CLineEffect::CLineEffect()
{
    Load();
    SetData(unk_184);
    unk_184->LoadImagesToVram(NNS_GfdGetTexKeyAddr(NNS_GfdAllocLnkTexVram(unk_184->GetImagesSize(), FALSE, 0)));
    unk_184->ReleaseImages();
    unk_184->LoadPaletteToVram(NNS_GfdGetPlttKeyAddr(NNS_GfdAllocLnkPlttVram(unk_184->GetPaletteSize(), FALSE, 0)));
    unk_184->ReleasePalette();
    m_leader = NULL;
    unk_194 = 0;
    unk_198 = 0x1000;
}

CLineEffect::~CLineEffect()
{
    Release();
}

void CLineEffect::Load()
{
    unk_184 = new CActorData("data/disk02_LZ.bin", "disk02", 1, TRUE, NULL);
}

void CLineEffect::Release()
{
    SAFE_DELETE(unk_184);
}

void CLineEffect::Setup(fx32 arg0, fx32 arg1, CActor *leader)
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
    fx32 dist = ApproxLength(dx, dy);
    u16 angle = FX_Atan2Idx(dy, dx);
    fx32 radius = unk_194;
    if (dist > radius) {
        m_motion.SetX(lpos.x + FX32_MUL(radius, FX_CosIdx(angle)));
        m_motion.SetY(lpos.y + FX32_MUL(radius, FX_SinIdx(angle)));
    }
    if (dist < unk_194) {
        m_motion.SetX(lpos.x + FX32_DIV(dx, 0x2000));
        m_motion.SetY(lpos.y + FX32_DIV(dy, 0x2000));
    }
}

void CLineEffect::vfunc_0C(Camera2D *camera)
{
    CActorAnim *anim = m_data->GetAnim(unk_C0);
    CSoftwareSprite *sprite = m_sprite;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)anim->image, NULL);
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)anim->cells;
    sprite->m_cellDataIdx = anim->bank->GetCell(unk_C8[unk_C0]);
    sprite->SetPos(m_motion.GetPos());
    sprite->m_alpha = 0x10;
    sprite->m_scale[0] = unk_198;
    sprite->m_scale[1] = unk_198;
    sprite->Render(camera);
}

void CLineEffect::vfunc_10(Camera2D *camera)
{
}
