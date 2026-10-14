#include "field/CFieldEffectManpuAnime.hpp"

#include <nitro.h>

#include "field/CFieldEffectManpuPos.hpp"

CFieldEffectManpuAnime::CFieldEffectManpuAnime(CEffectActorData *data, AnimSlotPool *slots, int type)
    : CFieldEffectManpuSimple(data, type)
{
    m_slots = slots;
    m_anim = slots->Acquire();
}

CFieldEffectManpuAnime::~CFieldEffectManpuAnime()
{
    m_slots->Free(m_anim);
}

int CFieldEffectManpuAnime::ov0_02142264(int step)
{
    UpdatePos(step);
    CellAnimController *cac = unk_18->GetCac(unk_78);
    if (cac != NULL && m_anim != 0) {
        cac->Update(m_anim);
        m_sprite.m_cellDataIdx = cac->GetCell(m_anim);
    }
    return CFieldEffectActor::ov0_02142264(step);
}

void CFieldEffectManpuAnime::UpdatePos(int step)
{
    if (unk_1C == NULL) {
        return;
    }
    m_sprite.SetPos(GetBalloonPos(unk_1C));
}

int CFieldEffectManpuAnime::Draw(Camera2D *camera)
{
    if (unk_1C == NULL || unk_20 == 0 || !IsVisible()) {
        return 0;
    }
    m_sprite.Render(camera);
    return 0;
}
