#include "field/CFieldEffectManpuAse.hpp"

#include "field/CFieldEffectManpuPos.hpp"

static const Point2D sDropOffset = { 0x2000, 0 };

CFieldEffectManpuAse::CFieldEffectManpuAse(CEffectActorData *data, AnimSlotPool *slots)
    : CFieldEffectManpu(data)
{
    m_slots = slots;
    unk_28 = 1;
    InitSprites();
    if (unk_18 != NULL) {
        CellAnimController *cac = unk_18->GetCac(0);
        if (cac != NULL) {
            for (int i = 0; i < 2; i++) {
                m_anims[i] = slots->Acquire();
                cac->Restart(m_anims[i]);
            }
            int n = 5;
            while (n--) {
                cac->Update(m_anims[0]);
            }
        }
    }
}

CFieldEffectManpuAse::~CFieldEffectManpuAse()
{
    for (int i = 0; i < 2; i++) {
        if (m_anims[i] != 0) {
            m_slots->Free(m_anims[i]);
        }
    }
}

int CFieldEffectManpuAse::Update(int step)
{
    int state = CFieldEffectActor::Update(step);
    if (state != 0 && state != 4) {
        CellAnimController *cac = unk_18->GetCac(0);
        if (IsVisible() && cac != NULL) {
            for (int i = 0; i < 2; i++) {
                if (m_anims[i] != 0) {
                    cac->Update(m_anims[i]);
                }
            }
        }
    }
    return state;
}

void CFieldEffectManpuAse::SetDepth(fx32 z)
{
    for (int i = 0; i < 2; i++) {
        m_sprites[i].m_z = z;
    }
}

int CFieldEffectManpuAse::Draw(Camera2D *camera)
{
    if (unk_1C == NULL || unk_20 == 0) {
        return 0;
    }
    CellAnimController *cac = unk_18->GetCac(0);
    if (cac != NULL) {
        for (int i = 0; i < 2; i++) {
            if (m_anims[i] != 0) {
                m_sprites[i].m_cellDataIdx = cac->GetCell(m_anims[i]);
            }
        }
    }
    Point2D pos = GetBalloonPos(unk_1C);
    m_sprites[0].SetPos(pos + sDropOffset);
    m_sprites[1].SetPos(pos - sDropOffset);
    for (int i = 0; i < 2; i++) {
        m_sprites[i].Render(camera);
    }
    return 0;
}

void CFieldEffectManpuAse::InitSprites()
{
    if (unk_18 == NULL) {
        return;
    }
    for (int i = 0; i < 2; i++) {
        m_sprites[i].SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(0), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)unk_18->GetPalette(), (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(0));
        m_sprites[i].m_polygonID = 8;
        unk_20 = 1;
    }
    m_sprites[1].m_scale[0] = -FX32_ONE;
    m_sprites[1].m_scale[1] = FX32_ONE;
}
