#include "field/CFieldEffectCellAnime.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "field/CFieldEffectManage.hpp"

CFieldEffectCellAnime::CFieldEffectCellAnime(int kind, BOOL attack)
    : m_kind(kind)
    , m_index(-1)
    , m_se(-1)
{
    if (attack == TRUE) {
        CFieldEffectAttackActorData *data = new CFieldEffectAttackActorData();
        if (data != NULL) {
            data->ov0_0214FFF0(kind, 1, kind == 0x12 ? 2 : 1);
        }
        unk_18 = data;
    } else if (kind < 0) {
        unk_18 = (CEffectActorData *)(CEffectResource *)&MAIN_BSS_0210CA60->m_resident;
    } else {
        CFieldEffectNormalActorData *data = new CFieldEffectNormalActorData();
        if (data != NULL) {
            data->ov0_021503B8(kind, FALSE);
        }
        unk_18 = data;
    }
    if (kind >= 0) {
        for (int i = 0; i < 2; i++) {
            CellAnimController *cac = unk_18->GetCac(i);
            if (cac != NULL) {
                m_cacIds[i] = cac->Create(1, 0);
            } else {
                m_cacIds[i] = 0;
            }
        }
    } else {
        CellAnimController *cac = unk_18->GetCac(-1 - kind);
        if (cac != NULL) {
            m_cacIds[0] = cac->Create(1, 0);
        } else {
            m_cacIds[0] = 0;
        }
    }
    InitSprites();
    m_pos.x = 0;
    m_pos.y = 0;
    m_lastState = 0;
}

CFieldEffectCellAnime::~CFieldEffectCellAnime()
{
    if (unk_18 != NULL) {
        if (m_kind < 0) {
            CellAnimController *cac = unk_18->GetCac(-1 - m_kind);
            if (cac != NULL && m_cacIds[0] != 0) {
                cac->Remove(m_cacIds[0]);
            }
        } else {
            for (int i = 0; i < 2; i++) {
                CellAnimController *cac = unk_18->GetCac(i);
                if (cac != NULL && m_cacIds[i] != 0) {
                    cac->Remove(m_cacIds[i]);
                }
            }
            SAFE_DELETE(unk_18);
        }
    }
}

int CFieldEffectCellAnime::ov0_02142264(int step)
{
    int state = CFieldEffectActor::ov0_02142264(step);
    if (state != 0 && state != 4 && m_kind >= 0 && unk_18 != NULL) {
        unk_18->Update();
    }
    if (state != m_lastState) {
        if (m_kind >= 0) {
            if ((u32)(m_index + 1) < unk_18->GetCount()) {
                m_index++;
                if (m_kind == 0x12 && m_index == 1) {
                    m_pos.y -= 0x40000;
                    if (m_se >= 0) {
                        CGame *game = CGame::GetInstance();
                        game->m_audioEngine->PlaySe(m_se);
                    }
                }
            }
        } else {
            m_index = 0;
        }
        if (m_index >= 0) {
            CellAnimController *cac = GetCac();
            if (cac != NULL) {
                cac->Restart(m_cacIds[m_index]);
            }
        }
        m_lastState = state;
    }
    if (state == 2 && m_index >= 0) {
        if (GetCac()->GetStatus(m_cacIds[m_index]) == 0 && m_holdTime < 0) {
            ov0_02142240(0);
        }
    }
    return state;
}

int CFieldEffectCellAnime::ov0_02142344(Camera2D *camera)
{
    if (m_state != 4 && m_state != 0 && m_index >= 0) {
        CellAnimController *cac = GetCac();
        m_sprites[m_index].SetPos(m_pos);
        if (cac != NULL) {
            m_sprites[m_index].m_cellDataIdx = cac->GetCell(m_cacIds[m_index]);
        }
        m_sprites[m_index].Render(camera);
    }
    return 0;
}

int CFieldEffectCellAnime::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 1:
        m_pos.x = value << 12;
        break;
    case 2:
        m_pos.y = value << 12;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

BOOL CFieldEffectCellAnime::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    m_index = -1;
    return CFieldEffect::ov0_021421F0(inTime, holdTime, outTime);
}

void CFieldEffectCellAnime::InitSprites()
{
    if (m_kind < 0) {
        m_sprites[0].SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(0), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)unk_18->GetPalette(), (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(-1 - m_kind));
        m_sprites[0].m_cellDataIdx = 0;
        m_sprites[0].m_z = 0x622;
        m_sprites[0].m_polygonID = 8;
        m_sprites[0].m_rotAngle = 0;
        return;
    }
    u32 count = unk_18->GetCount();
    if (count > 2) {
        count = 2;
    }
    for (u32 i = 0; i < count; i++) {
        m_sprites[i].SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(i), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)unk_18->GetPalette(), (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(i));
        m_sprites[i].m_cellDataIdx = 0;
        m_sprites[i].m_z = 0x622;
        m_sprites[i].m_polygonID = 8;
        m_sprites[i].m_rotAngle = 0;
    }
}

void CFieldEffectCellAnime::sub_0203365C(int arg0)
{
    m_se = arg0;
}

CFieldEffect *CFieldEffectNormalCellAnimeFactory::Create(int arg)
{
    return new CFieldEffectCellAnime(arg, FALSE);
}

CFieldEffect *CFieldEffectAttackCellAnimeFactory::Create(int arg)
{
    return new CFieldEffectCellAnime(arg, TRUE);
}
