#include "scene/COPDCaptureDiscScreen.hpp"

#include <nitro.h>

#include "AudioEngine.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "CTouchPanel.hpp"
#include "CellAnimController.hpp"
#include "PadInput.hpp"
#include "common.hpp"
#include "heap.hpp"

// The sprite table is defined before the emitter offset: file statics are created in definition order, before the
// TU-end RTTI/vtable walk (data order).
static OPDSpriteDef sOPDDiscSpriteDefs[2] = {
    { 0, -0x70000, 0x8000, 0x8000, 0, 0, 0x40000, 0x40000, 0, 2 },
    { 0, 0x60000, 0x100000, 0x10000, 0, 0, 0x100000, 0x10000, 9, 0 },
};

// Position of the line and spark emitters
static const Point2D sOPDDiscOffset = { 0, -0x70000 };

static inline u32 RandomInt(CGame *game, u32 max)
{
    MATHRandContext32 *rand = &game->m_rand32;
    return MATH_Rand32(rand, max);
}

static inline int GetQuadrant(const u16 &angle)
{
    return (angle >> 14) & 3;
}

COPDCaptureDiscScreen::COPDCaptureDiscScreen()
    : unk_05C(0)
    , unk_1B8(NULL)
    , unk_1BC(0)
    , unk_2BC(0)
    , m_sparks(1, 8)
    , m_lines(1, 0x40)
{
    unk_804 = 0;
    MI_CpuFill8(&unk_058, 0, sizeof(unk_058));
}

COPDCaptureDiscScreen::~COPDCaptureDiscScreen()
{
    Stop();
    Release();
}

void COPDCaptureDiscScreen::Init()
{
    unk_058 = new GraphicsSet("OPD", "data/interface/i019_LZ.bin", "OPD:i019_00.NCBR", "OPD:i019.NCLR", "OPD:i019_00.NCER", "OPD:i019_00.cac");
    if (unk_058->m_anim != NULL) {
        unk_05C = unk_058->m_anim->Create(1, 0);
    }
    CreateLoopPath();
    unk_138.Init(0x400);
}

void COPDCaptureDiscScreen::Release()
{
    unk_138.Release();
    if (unk_1B8 != NULL) {
        delete[] unk_1B8;
        unk_1B8 = NULL;
    }
    if (unk_05C != 0 && unk_058->m_anim != NULL) {
        unk_058->m_anim->Remove(unk_05C);
        unk_05C = 0;
    }
    SAFE_DELETE(unk_058);
}

void COPDCaptureDiscScreen::Start(COPDTexture *textures)
{
    unk_008 = 0;
    unk_004 = 0;
    G3X_SetClearColor(0, 0x1F, 0x7FFF, 0x3F, FALSE);
    GraphicsSet *res = unk_058;
    unk_00C[0].SetResources((UnkClass_CPrimitive_ImageProxy *)res->m_image, NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)res->m_palette, (UnkClass_CSoftwareSprite_38 *)res->m_cells);
    unk_00C[0].SetXY(0, 0);
    unk_00C[0].m_z = 0x64;
    unk_00C[0].m_alpha = 0;
    for (int i = 0; i < 2; i++) {
        OPDSpriteDef *def = &sOPDDiscSpriteDefs[i];
        unk_060[i].unk_18 = &textures[def->tex];
        unk_060[i].SetTexCoords(def->s1, def->t1, def->s2, def->t2);
        unk_060[i].m_coords[0] = def->x;
        unk_060[i].m_coords[1] = def->y;
        unk_060[i].unk_4C = def->width;
        unk_060[i].unk_50 = def->height;
        unk_060[i].m_z = def->z;
    }
    unk_060[0].m_alpha = 0;

    u32 plttAddr = textures[sOPDDiscSpriteDefs[1].tex].m_tex.m_plttAddr;
    u16 *pltt = (u16 *)Heap_AllocWithAlignment(4, -4);
    *pltt = 0x7FFF;
    GX_BeginLoadTexPltt();
    DC_FlushRange(pltt, 4);
    GX_LoadTexPltt(pltt, plttAddr, 4);
    GX_EndLoadTexPltt();
    Heap_Free(pltt);

    unk_138.unk_28 = 0;
    unk_138.unk_18 = &textures[11];
    unk_138.SetPoints(unk_1B8, unk_1BC);

    Point2D offset = sOPDDiscOffset;
    m_lineEmitter.m_pos = offset;
    m_lines.SetEmitter(0, &m_lineEmitter);
    m_lines.m_forceField = &m_lineAnimator;
    m_sparkEmitter.m_pos = offset;
    m_sparks.SetEmitter(0, &m_sparkEmitter);
    m_sparks.m_forceField = &m_sparkAnimator;

    CGame *game = CGame::GetInstance();
    MI_CpuFill8(unk_75C, 0, sizeof(unk_75C));
    for (int i = 0; i < 10; i++) {
        unk_374[i].unk_18 = (NtfTextureParam *)&textures[2];
        unk_374[i].m_tex[0].x = unk_374[i].m_tex[1].x = 0;
        unk_374[i].m_tex[0].y = unk_374[i].m_tex[3].y = 0;
        unk_374[i].m_tex[2].x = unk_374[i].m_tex[3].x = 0x20000;
        unk_374[i].m_tex[1].y = unk_374[i].m_tex[2].y = 0x40000;
        unk_374[i].m_vtx[0].x = 0;
        unk_374[i].m_vtx[0].y = -0x70000;
        unk_374[i].m_vtx[3].x = 0;
        unk_374[i].m_vtx[3].y = -0x70000;
        unk_374[i].m_polygonID = 0x3F - i;
        unk_75C[i].unk_0C = (RandomInt(game, 50) + 50) << FX32_SHIFT;
        unk_75C[i].unk_04 = 0x8000;
        unk_75C[i].unk_08 = unk_75C[i].unk_04 + (RandomInt(game, 32) << FX32_SHIFT);
        unk_75C[i].angle = ((int)(i * 36 + RandomInt(game, 36) - 18) << 16) / 360;
        unk_75C[i].speed = (RandomInt(game, 0x4000) + 0x4000) / 360;
    }
    unk_7FC = 0;
    unk_804 = 0;
    game->m_mainFade->Start(3, 30);
    game->m_subFade->Start(3, 30);
}

void COPDCaptureDiscScreen::CreateLoopPath()
{
    CGame *game = CGame::GetInstance();
    int i;
    int j;
    int q;
    MATHRandContext32 *rand;
    unk_1B8 = new Point2D[0x400];
    Point2D *pt = unk_1B8;
    rand = &game->m_rand32;
    fx32 ry = (MATH_Rand32(rand, 16) + 0x1C) << FX32_SHIFT;
    for (i = 0; i < 6; i++) {
        unk_1C0[i].angle = 0xE000;
        fx32 c = FX_CosIdx(0xE000);
        fx32 s = FX_SinIdx(0xE000);
        u16 angle = 0xC000;
        fx32 rx = (MATH_Rand32(rand, 16) + 0x26) << FX32_SHIFT;
        int start = GetQuadrant(angle);
        unk_1C0[i].radii[start].x = rx;
        unk_1C0[i].radii[start].y = ry;
        for (j = 0; j < 0x80; j++) {
            fx32 py = FX32_MUL(ry, FX_SinIdx(angle));
            fx32 px = FX32_MUL(rx, FX_CosIdx(angle));
            pt->x = FX32_MUL(c, px) - FX32_MUL(s, py);
            pt->y = FX32_MUL(s, px) + FX32_MUL(c, py) - 0x70000;
            angle -= 0x200;
            if (!(angle & 0x3FFF) && j != 0x7F) {
                q = (angle >> 14) & 3;
                if (q & 1) {
                    rx = (RandomInt(game, 16) + 0x26) << FX32_SHIFT;
                } else {
                    ry = (RandomInt(game, 16) + 0x1C) << FX32_SHIFT;
                }
                unk_1C0[i].radii[q].x = rx;
                unk_1C0[i].radii[q].y = ry;
            }
            pt++;
        }
    }
    fx32 x = pt[-1].x;
    fx32 y = pt[-1].y;
    fx32 step = (fx32)(((fx64)(-0xA0000 - x) << FX32_SHIFT) / 0x1E000);
    for (fx32 t = 0; t < 0x1E000; t += FX32_ONE) {
        x += step;
        pt->x = x;
        y -= step;
        pt->y = y;
        pt++;
    }
    unk_1BC = pt - unk_1B8;
}

void COPDCaptureDiscScreen::Stop()
{
    CGame::GetInstance()->m_audioEngine->StopCaptureLineSe(0);
}

int COPDCaptureDiscScreen::Update()
{
    CGame *game = CGame::GetInstance();
    PadInput *pad = game->unk_0014;
    CTouchPanel *tp = game->touchPanel;
    if (unk_008 <= 3 && ((u16)(pad->unk_0002 & PAD_BUTTON_A) || tp->unk_04 != 0)) {
        game->m_audioEngine->PlaySe(0xFA);
        game->m_mainFade->Start(2, 30);
        game->m_subFade->Start(2, 30);
        unk_008 = 6;
    }
    switch (unk_008) {
    case 0:
        if (!game->m_mainFade->IsActive() && !game->m_subFade->IsActive()) {
            unk_008 = 1;
            unk_004 = 0;
            m_sparkEmitter.func2();
        }
        break;
    case 1:
        if (++unk_004 > 60) {
            unk_008 = 2;
            unk_004 = 0;
            unk_118.x = 0x90000;
            unk_118.y = unk_1B8[0].y;
            unk_118.z = 0x30000;
            unk_118.vx = -0x6000;
            unk_118.vy = 0;
            unk_118.vz = 0;
            unk_118.gravity = -0x4CC;
            unk_118.bounces = 0;
            unk_00C[0].SetXY(unk_118.x, unk_118.y - unk_118.z);
            unk_00C[0].m_alpha = 31;
            game->m_audioEngine->PlaySe(0xA1);
        }
        break;
    case 2:
        unk_00C[0].SetXY(unk_118.x, unk_118.y - unk_118.z);
        if (unk_118.bounces < 2) {
            if (unk_118.z <= 0) {
                if (++unk_118.bounces == 1) {
                    unk_118.z = 0;
                    unk_118.vx = FX32_MUL(unk_118.vx, 0x800);
                    unk_118.vy = FX32_MUL(unk_118.vy, 0x800);
                    unk_118.vz = 0x2800;
                } else if (unk_118.bounces == 2) {
                    unk_118.z = 0;
                    unk_118.vx = 0;
                    unk_118.vy = 0;
                    unk_118.vz = 0;
                    unk_118.gravity = 0;
                    unk_004 = 45;
                }
                game->m_audioEngine->PlaySe(0x99);
            }
        } else if (unk_118.bounces == 2) {
            if (--unk_004 <= 0) {
                unk_118.bounces++;
            }
        }
        if (unk_118.bounces < 3) {
            unk_118.x += unk_118.vx;
            unk_118.y += unk_118.vy;
            unk_118.z += unk_118.vz;
            unk_118.vz += unk_118.gravity;
        } else {
            unk_008 = 3;
            unk_004 = 0;
            unk_2BC = 0;
            unk_2C0 = 0;
            unk_800 = 0;
            game->m_audioEngine->PlayCaptureLineSe(0);
        }
        break;
    case 3:
    case 4:
        if (unk_058->m_anim != NULL) {
            unk_058->m_anim->UpdateAll();
        }
        unk_138.unk_28 = unk_2BC;
        if (unk_2BC != 0 && (u32)unk_2BC <= (u32)unk_1BC) {
            unk_00C[0].m_alpha = 31;
            unk_00C[0].SetPos(unk_1B8[unk_2BC - 1]);
        } else {
            unk_00C[0].m_alpha = 0;
        }
        unk_2BC += 8;
        if ((u32)unk_2BC <= (u32)unk_1BC && !(unk_2BC & 0x7F)) {
            m_lineEmitter.Burst(20, &unk_1C0[unk_2C0]);
            if (unk_2C0 <= 5) {
                game->m_audioEngine->PlaySe(unk_2C0 + 0x1A);
            } else {
                game->m_audioEngine->PlaySe(0x1F);
            }
            if (++unk_2C0 == 2) {
                unk_060[0].m_alpha = 31;
                unk_800 = 0x40;
            }
            if (unk_2C0 == 5) {
                unk_7FC = 0x800;
                game->m_mainFade->Start(2, 30);
                game->m_subFade->Start(2, 30);
                unk_008 = 4;
            }
        }
        unk_060[0].m_scale[0] = unk_060[0].m_scale[1] = unk_800;
        if (unk_2C0 < 5) {
            unk_800 += 0x40;
        } else {
            unk_800 += 0x800;
        }
        if (unk_008 == 4 && !game->m_mainFade->IsActive() && !game->m_subFade->IsActive() && (u32)unk_2BC > (u32)unk_1BC) {
            unk_004 = 90;
            game->m_audioEngine->StopSe(0xB);
            unk_008 = 5;
        }
        break;
    case 5:
        if (--unk_004 < 0) {
            return 1;
        }
        break;
    case 6:
        if (!game->m_mainFade->IsActive() && !game->m_subFade->IsActive()) {
            game->m_audioEngine->StopSe(0xB);
            return 1;
        }
        break;
    }

    m_lines.Update(1);
    m_sparks.Update(1);
    unk_138.UpdateAnim();
    if (unk_7FC != 0) {
        for (int i = 0; i < 10; i++) {
            UnkStruct_COPDBeam *beam = &unk_75C[i];
            if (beam->unk_04 != 0) {
                beam->angle += beam->speed;
                if (beam->unk_04 < beam->unk_08) {
                    beam->unk_04 += 0x1000;
                }
            }
        }
        unk_7FC += 0x400;
    }
    unk_804++;
    return 0;
}

void COPDCaptureDiscScreen::Render(Camera2D *camera, int flip)
{
    for (TFieldParticle<CLineParticle> *p = m_lines.m_active; p != NULL; p = p->next) {
        if (m_lines.m_depth < 0) {
            p->sprite.m_z = m_lines.m_depth;
        }
        fx32 h = FX32_MUL(p->sprite.unk_60, 0x800);
        fx32 x = p->pos.x + m_lines.m_offset.x;
        fx32 y = p->pos.y + m_lines.m_offset.y;
        p->sprite.SetVertexCoordinates(x, y - h, x + h, y, x, y + h, x - h, y, p->sprite.m_z);
        G3_RestoreMtx(0);
        p->sprite.Render(camera);
    }
    for (TFieldParticle<CSparkLine> *p = m_sparks.m_active; p != NULL; p = p->next) {
        if (m_sparks.m_depth < 0) {
            p->sprite.m_z = m_sparks.m_depth;
        }
        G3_RestoreMtx(0);
        p->sprite.Render(camera);
    }
    unk_060[0].Render(camera);
    if (!(unk_804 & 0x20)) {
        unk_060[1].Render(camera);
    }
    OS_GetTick();
    unk_138.Render(camera);
    OS_GetTick();
    if (unk_7FC != 0) {
        for (int i = 0; i < 10; i++) {
            UnkStruct_COPDBeam *beam = &unk_75C[i];
            if (beam->unk_04 != 0) {
                fx32 half = FX32_MUL(beam->unk_04, 0x800);
                fx32 c = FX_CosIdx(beam->angle);
                fx32 s = FX_SinIdx(beam->angle);
                fx32 len = FX32_MUL(beam->unk_0C, unk_7FC);
                fx32 wid = FX32_MUL(unk_7FC, half);
                fx32 lc = FX32_MUL(len, c);
                fx32 ls = FX32_MUL(len, s) - 0x70000;
                unk_374[i].m_vtx[1].x = lc + FX32_MUL(wid, -s);
                unk_374[i].m_vtx[1].y = ls + FX32_MUL(wid, c);
                unk_374[i].m_vtx[2].x = lc + FX32_MUL(wid, s);
                unk_374[i].m_vtx[2].y = ls + FX32_MUL(wid, -c);
                unk_374[i].Render(camera);
            }
        }
    }
    if (unk_05C != 0 && unk_058->m_anim != NULL) {
        unk_00C[0].m_cellDataIdx = unk_058->m_anim->GetCell(unk_05C);
    }
    unk_00C[0].Render(camera);
}

u32 COPDCaptureDiscScreen::CLineParticleEmitter::Update(int dt)
{
    u32 count = unk_18;
    unk_18 = 0;
    unk_20 = 0;
    return count;
}

void COPDCaptureDiscScreen::CLineParticleEmitter::Emit(TFieldParticle<CLineParticle> *p)
{
    u16 angle = (unk_20 << 16) / 20;
    u16 q = ((angle + 0x3FFF) >> 14) & 3;
    fx32 py = FX32_MUL(((UnkStruct_COPDRing *)unk_1C)->radii[q].y, FX_SinIdx(angle));
    fx32 px = FX32_MUL(((UnkStruct_COPDRing *)unk_1C)->radii[q].x, FX_CosIdx(angle));
    fx32 s = FX_SinIdx(((UnkStruct_COPDRing *)unk_1C)->angle);
    fx32 c = FX_CosIdx(((UnkStruct_COPDRing *)unk_1C)->angle);
    fx32 x = FX32_MUL(c, px) - FX32_MUL(s, py);
    fx32 y = FX32_MUL(s, px) + FX32_MUL(c, py);
    p->SetPos(x + m_pos.x, y + m_pos.y);
    p->life = 0xC000;
    p->maxLife = 0xC000;
    p->sprite.m_z = 1;
    p->vel.x = FX32_DIV(-x, 0xC000);
    p->vel.y = FX32_DIV(-y, 0xC000);
    p->sprite.m_alpha = 31;
    p->sprite.unk_60 = 0x8000;
    unk_20++;
}

void COPDCaptureDiscScreen::CLineParticleAnimator::Apply(TFieldParticle<CLineParticle> *p, int dt)
{
    p->sprite.m_alpha = FX32_MUL(p->life, 0x2955) >> FX32_SHIFT;
    p->sprite.unk_60 = FX32_MUL(p->life, 0x800) + 0x2000;
}

u32 COPDCaptureDiscScreen::CSparkEmitter::Update(int dt)
{
    u32 count = 0;
    if (m_timer > 0) {
        CGame *game = CGame::GetInstance();
        m_timer -= dt;
        if (m_timer <= 0) {
            count = RandomInt(game, 8);
            m_timer = (RandomInt(game, 5) + 5) << FX32_SHIFT;
            count++;
        }
    }
    return count;
}

void COPDCaptureDiscScreen::CSparkEmitter::Emit(TFieldParticle<CSparkLine> *p)
{
    p->SetPos(m_pos.x, m_pos.y);
    p->life = 0xA000;
    p->maxLife = 0xA000;
    p->sprite.m_z = 0;
    CGame *game = CGame::GetInstance();
    u16 angle = RandomInt(game, 0x10000);
    p->vel.x = FX_CosIdx(angle) * 2;
    p->vel.y = FX_SinIdx(angle) * 2;
    p->sprite.m_alpha = 31;
}

void COPDCaptureDiscScreen::CSparkAnimator::Apply(TFieldParticle<CSparkLine> *p, int dt)
{
    p->sprite.SetStart(p->pos.x, p->pos.y);
    p->sprite.SetEnd(p->pos.x + p->vel.x * 6, p->pos.y + p->vel.y * 6);
    p->sprite.unk_28 = p->pos.x;
    p->sprite.unk_2C = p->pos.y;
    if (p->life <= 0x4000) {
        p->sprite.m_alpha = (p->life * 4) >> FX32_SHIFT;
    }
}
