#include "field/CFieldEffectManpuDarkrie.hpp"

#include "CGame.hpp"
#include "CellAnimController.hpp"
#include "field/CFieldEffectManpuPos.hpp"

static const u8 sColors[3][3] = {
    { 12, 0, 31 },
    { 0, 0, 0 },
    { 31, 31, 31 },
};

static const Point2D sOffsets[5] = {
    { 0, 0 },
    { 0x10000, -0x8000 },
    { 0x8000, -0x18000 },
    { -0x8000, -0x20000 },
    { -0x10000, -0x10000 },
};

CFieldEffectManpuDarkrie::CFieldEffectManpuDarkrie(CFieldEffectManage::CResidentResource *res, AnimSlotPool *slots, int cac, int type)
    : CFieldEffectManpu((CEffectActorData *)res)
{
    m_slots = slots;
    m_bobSpeed = 0x2AA;
    m_colorBase = 0;
    m_fadeLen = 16;
    unk_28 = 1;
    Init(cac);
    int i;
    MATHRandContext32 *rand = &CGame::GetInstance()->m_rand32;
    for (i = 0; i < 5; i++) {
        m_anims[i] = m_slots->Acquire();
        m_fade[i] = MATH_Rand32(rand, 16);
        m_colorIdx[i] = MATH_Rand32(rand, 3);
    }
    if (unk_18 != NULL) {
        CellAnimController *ctrl = unk_18->GetCac(cac);
        if (ctrl != NULL) {
            for (int i = 0; i < 5; i++) {
                int n = i * 30;
                while (n--) {
                    ctrl->Update(m_anims[i]);
                }
            }
        }
    }
    m_offset.y = 0;
    m_offset.x = 0;
}

CFieldEffectManpuDarkrie::~CFieldEffectManpuDarkrie()
{
    for (int i = 0; i < 5; i++) {
        m_slots->Free(m_anims[i]);
    }
}

int CFieldEffectManpuDarkrie::ov0_02142264(int step)
{
    UpdatePos(step);
    UpdateColors(step);
    CellAnimController *cac = unk_18->GetCac(m_cac);
    for (int i = 0; i < 5; i++) {
        if (cac != NULL && m_anims[i] != 0) {
            cac->Update(m_anims[i]);
            m_sprites[i].m_cellDataIdx = cac->GetCell(m_anims[i]);
        }
    }
    return CFieldEffectActor::ov0_02142264(step);
}

void CFieldEffectManpuDarkrie::UpdatePos(int step)
{
    if (unk_1C == NULL) {
        return;
    }
    m_offset.y += m_bobSpeed * step;
    if (m_offset.y >= 0x2000) {
        m_offset.y = 0x2000;
        m_bobSpeed = -m_bobSpeed;
    } else if (m_offset.y <= -0x2000) {
        m_offset.y = -0x2000;
        m_bobSpeed = -m_bobSpeed;
    }
    for (int i = 0; i < 5; i++) {
        m_sprites[i].SetPos(GetBalloonPos(unk_1C) + sOffsets[i] + m_offset);
    }
}

void CFieldEffectManpuDarkrie::UpdateColors(int step)
{
    for (int i = 0; i < 5; i++) {
        u8 from = m_colorBase + m_colorIdx[i];
        u8 to = from + 1;
        if (to >= m_colorBase + 3) {
            to = m_colorBase;
        }
        u8 rgb[3];
        for (int j = 0; j < 3; j++) {
            rgb[j] = sColors[from][j] + ((m_fade[i] * (sColors[to][j] - sColors[from][j])) >> 4);
        }
        m_sprites[i].m_color = GX_RGB(rgb[0], rgb[1], rgb[2]);
        m_fade[i] += step;
        if (m_fade[i] >= m_fadeLen) {
            if (++m_colorIdx[i] >= 3) {
                m_colorIdx[i] = 0;
            }
            m_fade[i] -= m_fadeLen;
        }
    }
}

void CFieldEffectManpuDarkrie::Init(int cac)
{
    if (unk_18 != NULL && unk_18->GetNcbr(cac) != NULL && unk_18->GetPalette() != NULL && unk_18->GetNcer(cac) != NULL) {
        for (int i = 0; i < 5; i++) {
            m_sprites[i].SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(cac), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)unk_18->GetPalette(), (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(cac));
            m_sprites[i].m_cellDataIdx = 0;
            m_sprites[i].m_polygonID = 8;
            unk_20 = 1;
        }
    }
    m_cac = cac;
}

int CFieldEffectManpuDarkrie::Draw(Camera2D *camera)
{
    if (unk_1C == NULL || unk_20 == 0 || !IsVisible()) {
        return 0;
    }
    unk_18->GetCac(m_cac);
    for (int i = 0; i < 5; i++) {
        m_sprites[i].Render(camera);
    }
    return 0;
}

void CFieldEffectManpuDarkrie::SetDepth(fx32 z)
{
    for (int i = 0; i < 5; i++) {
        m_sprites[i].m_z = z;
    }
}
