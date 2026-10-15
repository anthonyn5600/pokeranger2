#include "field/CFieldEffectSpark.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "field/TFieldParticle.hpp"

CFieldEffectSpark::CFieldEffectSpark(int kind)
{
    CFieldEffectNormalActorData *data = new CFieldEffectNormalActorData();
    if (data != NULL) {
        data->Load(kind, FALSE);
        VramPalette *palette = data->GetPalette();
        if (palette != NULL) {
            NNSG2dPaletteData *src = palette->GetData();
            u16 *raw = (u16 *)src->pRawData;
            MI_CpuCopy8(raw + 2, m_colorsFrom, 0xE);
            MI_CpuCopy8(raw + 9, m_colorsTo, 0xE);
            for (int i = 0; i < 3; i++) {
                MI_CpuCopy8(raw, m_plttRaw[i], 4);
                m_plttData[i].fmt = src->fmt;
                m_plttData[i].bExtendedPlt = src->bExtendedPlt;
                m_plttData[i].szByte = src->szByte;
                m_plttData[i].pRawData = m_plttRaw[i];
                for (int j = 0; j < 2; j++) {
                    m_palettes[i][j].SetData(&m_plttData[i]);
                    m_plttKeys[i][j] = NNS_GfdAllocLnkPlttVram(m_palettes[i][j].unk_04->szByte, FALSE, 0);
                }
                m_palettes[i][1].LoadToVramDeferred(NNS_GfdGetPlttKeyAddr(m_plttKeys[i][1]));
                m_bank[i] = 0;
            }
        }
    }
    unk_18 = data;
    CellAnimController *cac = unk_18->GetCac(0);
    for (int i = 0; i < 3; i++) {
        if (cac != NULL) {
            m_cacIds[i] = cac->Create(1, 0);
            int n = 6;
            while (n--) {
                cac->UpdateAll();
            }
        } else {
            m_cacIds[i] = 0xFFFF;
        }
    }
    InitSprites();
    m_pos.x = 0;
    m_pos.y = 0;
}

CFieldEffectSpark::~CFieldEffectSpark()
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (m_plttKeys[i][j] != 0) {
                NNS_GfdFreeLnkPlttVram(m_plttKeys[i][j]);
            }
        }
    }
    if (unk_18 != NULL) {
        CellAnimController *cac = unk_18->GetCac(0);
        for (int i = 0; i < 3; i++) {
            cac->Remove(m_cacIds[i]);
        }
    }
    SAFE_DELETE(unk_18);
}

int CFieldEffectSpark::Update(int step)
{
    int state = CFieldEffectActor::Update(step);
    if (state != 0 && state != 4 && unk_18 != NULL) {
        unk_18->Update();
    }
    if (state != 0 && state != 4) {
        for (int i = 0; i < 3; i++) {
            u8 swap = FALSE;
            u8 back = m_bank[i] ^ 1;
            if (m_palettes[i][back].unk_20 != 0) {
                m_bank[i] = back;
                back ^= 1;
                swap = TRUE;
            }
            u16 colors[7];
            fx32 t = m_glow[i].blend;
            for (int n = 0; n < 7; n++) {
                int from = m_colorsFrom[n];
                int to = m_colorsTo[n];
                int b = (from >> 10) & 0x1F;
                int r = from & 0x1F;
                int g = (from >> 5) & 0x1F;
                r += (t * ((to & 0x1F) - r)) >> 12;
                b += (t * (((to >> 10) & 0x1F) - b)) >> 12;
                g += (t * (((to >> 5) & 0x1F) - g)) >> 12;
                colors[n] = r | ((b << 10) | (g << 5));
            }
            m_glow[i].blend += m_glow[i].blendStep;
            if (m_glow[i].blend >= 0x1000) {
                m_glow[i].blend = 0x1000;
                m_glow[i].blendStep = -m_glow[i].blendStep;
            } else if (m_glow[i].blend <= 0) {
                m_glow[i].blend = 0;
                m_glow[i].blendStep = -m_glow[i].blendStep;
            }
            if (swap) {
                VramPalette *palette = &m_palettes[i][back];
                MI_CpuCopy8(colors, (u16 *)palette->unk_04->pRawData + 2, 0xE);
                if (m_plttKeys[i][back] != 0) {
                    palette->LoadToVramDeferred(NNS_GfdGetPlttKeyAddr(m_plttKeys[i][back]));
                }
            }
        }
    }
    return state;
}

// Reads the range after the offset update (the original's m_size.y load waits for the offset store: one object,
// one alias); passing it as an argument loads it first and changes the schedule.
static inline void Bob(CFieldEffectSpark *spark, SparkGlow &g)
{
    g.offset += g.offsetStep;
    fx32 half = spark->m_size.y >> 1;
    if (g.offset >= half) {
        g.offset = half;
        g.offsetStep = -g.offsetStep;
    } else if (g.offset <= -half) {
        g.offset = -half;
        g.offsetStep = -g.offsetStep;
    }
}

int CFieldEffectSpark::Render(Camera2D *camera)
{
    if (m_state != 4 && m_state != 0) {
        for (int i = 0; i < 3; i++) {
            Point2D pos = { m_pos.x, m_pos.y + m_glow[i].offset };
            Bob(this, m_glow[i]);
            m_sprites[i].SetPos(pos);
            CellAnimController *cac = unk_18->GetCac(0);
            if (cac != NULL) {
                m_sprites[i].m_cellDataIdx = cac->GetCell(m_cacIds[i]);
            }
            m_sprites[i].unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)&m_palettes[i][m_bank[i]];
            if (m_palettes[i][m_bank[i]].unk_20 != 0) {
                m_sprites[i].Render(camera);
            }
        }
    }
    return 0;
}

int CFieldEffectSpark::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 1:
        m_pos.x = value << 12;
        break;
    case 2:
        m_pos.y = value << 12;
        break;
    case 3:
        m_size.x = value << 12;
        break;
    case 4:
        m_size.y = value << 12;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

BOOL CFieldEffectSpark::Start(int inTime, int holdTime, int outTime)
{
    m_glow[0].offsetStep = 0x1000;
    m_glow[1].offsetStep = 0x2000;
    m_glow[2].offsetStep = 0x4000;
    m_glow[0].blend = 0;
    m_glow[1].blend = 0x800;
    m_glow[2].blend = 0x1000;
    for (int i = 0; i < 3; i++) {
        SparkGlow *g = &m_glow[i];
        g->offset = MATH_Rand16(&MAIN_BSS_0210CEC8, m_size.y) - (m_size.y >> 1);
        m_glow[i].blendStep = 0xCC;
    }
    return CFieldEffect::Start(inTime, holdTime, outTime);
}

void CFieldEffectSpark::InitSprites()
{
    for (int i = 0; i < 3; i++) {
        m_sprites[i].SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(0), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)&m_palettes[i][0], (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(0));
        m_sprites[i].m_cellDataIdx = 0;
        m_sprites[i].m_polygonID = i + 8;
        m_sprites[i].m_z = i + 0x622;
    }
}

int CFieldEffectSpark::IsReady()
{
    if (unk_18 == NULL) {
        return 1;
    }
    for (int i = 0; i < 3; i++) {
        if (m_palettes[i][1].unk_20 == 0) {
            return 0;
        }
    }
    return unk_18->IsLoaded();
}

CFieldEffect *CFieldEffectSparkFactory::Create(int arg)
{
    return new CFieldEffectSpark(arg);
}

int CFieldEffectSpark::GetEffectId()
{
    return 0xF;
}
