#include <nitro.h>
#include <nnsys.h>

#include "AudioEngine.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "CTouchPanel.hpp"
#include "Camera2D.hpp"
#include "Collision.hpp"
#include "MathUtil.hpp"
#include "PadInput.hpp"
#include "common.hpp"
#include "heap.hpp"
#include "scene/COPDScreen.hpp"

static inline u32 RandomInt(CGame *game, u32 max)
{
    MATHRandContext32 *rand = &game->m_rand32;
    return MATH_Rand32(rand, max);
}

static inline int NextPolygonID(int *counter)
{
    int id = (*counter)++;
    if (*counter >= 0x40) {
        *counter = 10;
    }
    return id;
}

COPDTitleScreen::COPDTitleScreen()
    : m_sparks(1, 0x40)
    , m_stars(1, 0x10)
    , m_particleId(10)
    , m_sparkEmitter(this)
    , m_starEmitter(this)
{
    unk_5D0 = 0;
    unk_612 = 0;
    unk_613 = 0;
    unk_008 = unk_004 = 0;
}

COPDTitleScreen::~COPDTitleScreen()
{
    Stop();
    Release();
}

void COPDTitleScreen::Init()
{
    m_mesh.ov3_02129AC0(4, 4, -0x80000, -0xC0000, 0, 0, 0x100000, 0xC0000);
}

void COPDTitleScreen::Release()
{
    m_mesh.ov3_02129C54();
}

void COPDTitleScreen::Start(COPDTexture *textures)
{
    CGame *game = CGame::GetInstance();
    G3X_SetClearColor(0x89F, 0x1F, 0x7FFF, 0x3F, FALSE);
    for (int i = 0; i < 7; i++) {
        OPDSpriteDef *def = &sOPDSpriteDefs[i];
        if (def->tex >= 0) {
            m_sprites[i].unk_18 = &textures[def->tex];
        }
        m_sprites[i].SetTexCoords(def->s1, def->t1, def->s2, def->t2);
        m_sprites[i].m_coords[0] = def->x;
        m_sprites[i].m_coords[1] = def->y;
        m_sprites[i].unk_4C = def->width;
        m_sprites[i].unk_50 = def->height;
        m_sprites[i].m_z = def->z;
    }

    m_mesh.unk_18 = &textures[3];
    m_mesh.m_z = 0x5A;
    m_sprites[5].unk_58 = GX_TEXPLTTCOLOR0_TRNS;
    m_sprites[0].m_polygonID = 2;
    m_sprites[1].m_polygonID = 3;
    m_sprites[2].m_polygonID = 3;
    m_sprites[3].m_polygonID = 4;
    m_sprites[3].m_polygonMode = GX_POLYGONMODE_TOON;
    m_sprites[3].m_color = 0;
    m_sprites[3].m_alpha = 0;
    m_sprites[4].m_polygonID = 5;
    m_sprites[6].m_polygonID = 0;
    m_sprites[6].unk_58 = GX_TEXPLTTCOLOR0_TRNS;
    m_sprites[6].m_polygonMode = GX_POLYGONMODE_SHADOW;
    m_sprites[6].m_alpha = 8;
    m_mesh.m_polygonID = 1;

    u32 plttAddr = textures[sOPDSpriteDefs[4].tex].m_tex.m_plttAddr;
    u16 *pltt = (u16 *)Heap_AllocWithAlignment(4, -4);
    *pltt = 0;
    GX_BeginLoadTexPltt();
    DC_FlushRange(pltt, 4);
    GX_LoadTexPltt(pltt, plttAddr, 4);
    GX_EndLoadTexPltt();
    Heap_Free(pltt);

    Point2D offset = sOPDStarOffset;
    m_sparkEmitter.m_pos = offset;
    m_sparks.SetEmitter(0, &m_sparkEmitter);
    m_sparks.m_forceField = &m_sparkAnimator;
    m_sparks.m_res = &textures[4];
    m_sparkEmitter.func2();
    m_starEmitter.m_pos = offset;
    m_stars.SetEmitter(0, &m_starEmitter);
    m_stars.m_forceField = &m_starAnimator;
    m_stars.m_res = &textures[12];
    m_starEmitter.func2();

    fx32 x = -0x40000;
    for (int i = 0; i < 3; i++) {
        fx32 y = -0x90000;
        for (int j = 0; j < 3; j++) {
            unk_2B8.unk_1D4[i][j].angle = RandomInt(game, 0x10000);
            unk_2B8.unk_1D4[i][j].speed = RandomInt(game, 0x200) + 0x100;
            unk_2B8.unk_1D4[i][j].radius = (RandomInt(game, 4) + 2) << FX32_SHIFT;
            unk_2B8.unk_1D4[i][j].x = x;
            unk_2B8.unk_1D4[i][j].y = y;
            y += 0x30000;
        }
        x += 0x40000;
    }

    unk_5D0 = 0;
    ov3_02125CB0();
    unk_008 = 0;
    unk_004 = 0;
    if (unk_613) {
        game->m_audioEngine->PlayBgm(0x45, 0);
    } else {
        game->m_audioEngine->sub_02034D54(0x200, 0x40);
    }
    game->unk_14BC->Start(1, 30);
    game->unk_14C0->Start(1, 30);
}

void COPDTitleScreen::CSparkEmitter::func2()
{
    m_timer = FX32_ONE;
}

void COPDTitleScreen::CStarEmitter::func2()
{
    m_timer = FX32_ONE;
}

void COPDTitleScreen::ov3_02125CB0()
{
    for (int i = 0; i < 32; i++) {
        int c = 31 - i;
        m_toonTable[i] = GX_RGB(c, c, c);
    }
    G3X_SetToonTable(m_toonTable);
    G3X_SetShading(GX_SHADING_HIGHLIGHT);
}

void COPDTitleScreen::Stop()
{
}

int COPDTitleScreen::Update()
{
    CGame *game = CGame::GetInstance();
    PadInput *pad = game->unk_0014;
    CTouchPanel *tp = game->touchPanel;
    if (!unk_613 && unk_008 <= 1 && ((u16)(pad->unk_0002 & PAD_BUTTON_A) || tp->unk_04 != 0)) {
        game->m_audioEngine->PlaySe(0xFA);
        game->unk_14BC->Start(2, 60);
        game->unk_14C0->Start(2, 60);
        unk_008 = 2;
    }
    switch (unk_008) {
    case 0:
        if (!game->unk_14BC->IsActive() && !game->unk_14C0->IsActive()) {
            unk_008 = 1;
            unk_004 = unk_613 ? 600 : 3240;
            unk_612 = 0x40;
        }
        break;
    case 1:
        if (--unk_004 < 0) {
            game->unk_14BC->Start(4, 60);
            game->unk_14C0->Start(4, 60);
            if (unk_613) {
                game->m_audioEngine->StopBgm(60);
                unk_008 = 2;
            } else {
                game->m_audioEngine->sub_02034DC8(60);
                unk_008 = 3;
            }
        }
        break;
    case 3:
        if (!game->unk_14BC->IsActive() && !game->unk_14C0->IsActive()) {
            unk_004 = 60;
            unk_008 = 4;
        }
        break;
    case 4:
        if (--unk_004 < 0) {
            return 0;
        }
        break;
    case 2:
        if (!game->unk_14BC->IsActive() && !game->unk_14C0->IsActive()) {
            return -1;
        }
        break;
    }

    unk_2B8.ov3_02129F78();
    m_sparks.Update(1);
    m_stars.Update(1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            unk_2B8.unk_1D4[i][j].angle += unk_2B8.unk_1D4[i][j].speed;
        }
    }
    if (!unk_613) {
        unk_5D0++;
    }
    if (unk_612 != 0) {
        if (--unk_612 >= 0x20) {
            s8 alpha = 31 - (unk_612 - 0x20);
            if (alpha < 0) {
                alpha = 0;
            }
            m_sprites[3].m_alpha = alpha;
        } else {
            m_sprites[3].m_color = (u8)(31 - unk_612);
        }
    }
    return 1;
}

void COPDTitleScreen::Render(Camera2D *camera, int flip)
{
    m_sparks.Draw(camera);
    m_stars.Draw(camera);
    for (u16 i = 0; i < 3; i++) {
        for (u16 j = 0; j < 3; j++) {
            UnkStruct_02129E98_1D4 *cell = &unk_2B8.unk_1D4[i][j];
            fx32 s = FX_SinIdx(cell->angle);
            fx32 c = FX_CosIdx(cell->angle);
            m_mesh.SetVertex(i + 1, j + 1, cell->x + FX32_MUL(cell->radius, c), cell->y + FX32_MUL(cell->radius, s));
        }
    }
    if (!flip) {
        m_mesh.Render(camera);
        m_sprites[0].Render(camera);
        m_sprites[1].Render(camera);
        m_sprites[6].Render(camera);
        unk_2B8.ov3_02129FE0(camera);
        m_sprites[3].Render(camera);
    }
    if (!unk_613 && !(unk_5D0 & 0x20)) {
        m_sprites[4].Render(camera);
    }
    m_sprites[5].Render(camera);
}

u32 COPDTitleScreen::CSparkEmitter::Update(int dt)
{
    u32 count = 0;
    if (m_timer > 0) {
        CGame *game = CGame::GetInstance();
        m_timer -= dt;
        if (m_timer <= 0) {
            count = RandomInt(game, 8) + 1;
            m_timer = (RandomInt(game, 25) + 5) << FX32_SHIFT;
        }
    }
    return count;
}

void COPDTitleScreen::CSparkEmitter::Emit(TFieldParticle<CSimpleSpriteNTF> *p)
{
    CGame *game = CGame::GetInstance();
    p->SetPos(m_pos.x, m_pos.y);
    p->life = 0x12C000;
    p->maxLife = 0x12C000;
    u16 angle = RandomInt(CGame::GetInstance(), 0x10000);
    fx32 speed = RandomInt(game, 0x3000) + 0x3000;
    p->vel.x = FX32_MUL(speed, FX_CosIdx(angle));
    p->vel.y = FX32_MUL(speed, FX_SinIdx(angle));
    p->rot = angle + 0x4000;
    p->sprite.m_z = 0x50;
    p->sprite.m_polygonID = NextPolygonID(m_counter);
    p->sprite.m_alpha = RandomInt(game, 11) + 7;
    p->sprite.SetTexCoords(0, 0, 0x20000, 0x40000);
    p->sprite.unk_4C = 0x4000;
    p->sprite.unk_50 = (RandomInt(game, 0x60) + 0x20) << FX32_SHIFT;
}

void COPDTitleScreen::CSparkAnimator::Apply(TFieldParticle<CSimpleSpriteNTF> *p, int dt)
{
    fx32 dist = ApproxLength(p->pos.x, p->pos.y + 0x60000) - 0x32000;
    BOOL out;
    fx32 sx = FX32_MUL(dist, 0x41) + FX32_ONE;
    fx32 sy = FX32_MUL(dist, 0x10) + FX32_ONE;
    p->sprite.m_scale[0] = sx;
    p->sprite.m_scale[1] = sy;
    fx32 half = FX32_MUL(sy, p->sprite.unk_50 >> 1);
    out = FALSE;
    if (p->vel.x < 0) {
        if (half + p->pos.x < -0x80000) {
            out = TRUE;
        }
    } else if (p->pos.x - half > 0x80000) {
        out = TRUE;
    }
    if (!out) {
        if (p->vel.y < 0) {
            if (half + p->pos.y < -0xC0000) {
                out = TRUE;
            }
        } else if (p->pos.y - half > 0xC0000) {
            out = TRUE;
        }
    }
    if (out) {
        p->life = 0;
        p->maxLife = 0;
    }
}

u32 COPDTitleScreen::CStarEmitter::Update(int dt)
{
    u32 count = 0;
    if (m_timer > 0) {
        CGame *game = CGame::GetInstance();
        m_timer -= dt;
        if (m_timer <= 0) {
            count = RandomInt(game, 2) + 1;
            m_timer = (RandomInt(game, 20) + 10) << FX32_SHIFT;
        }
    }
    return count;
}

void COPDTitleScreen::CStarEmitter::Emit(TFieldParticle<CSimpleSpriteNTF> *p)
{
    CGame *game = CGame::GetInstance();
    p->SetPos(m_pos.x, m_pos.y);
    p->life = 0x12C000;
    p->maxLife = 0x12C000;
    u16 angle = RandomInt(CGame::GetInstance(), 0x10000);
    fx32 speed = RandomInt(game, 0x2000) + 0x2000;
    p->vel.x = FX32_MUL(speed, FX_CosIdx(angle));
    p->vel.y = FX32_MUL(speed, FX_SinIdx(angle));
    p->rot = angle + 0x4000;
    p->sprite.m_z = 0x51;
    p->sprite.m_polygonID = NextPolygonID(m_counter);
    p->rotVel = 0x444;
    p->sprite.SetTexCoords(0, 0, 0x20000, 0x20000);
    p->sprite.unk_4C = 0x20000;
    p->sprite.unk_50 = 0x20000;
    p->sprite.m_scale[0] = 0x800;
    p->sprite.m_scale[1] = 0x800;
}

void COPDTitleScreen::CStarAnimator::Apply(TFieldParticle<CSimpleSpriteNTF> *p, int dt)
{
    fx32 dist = ApproxLength(p->pos.x, p->pos.y + 0x60000) - 0x32000;
    fx32 scale = FX32_MUL(dist, 0x18) + 0x800;
    p->sprite.m_scale[0] = scale;
    p->sprite.m_scale[1] = scale;
    fx32 half = p->sprite.unk_50 >> 1;
    BOOL out = FALSE;
    if (p->vel.x < 0) {
        if (p->pos.x + half < -0x80000) {
            out = TRUE;
        }
    } else if (p->pos.x - half > 0x80000) {
        out = TRUE;
    }
    if (!out) {
        if (p->vel.y < 0) {
            if (p->pos.y + half < -0xC0000) {
                out = TRUE;
            }
        } else if (p->pos.y - half > 0xC0000) {
            out = TRUE;
        }
    }
    if (out) {
        p->life = 0;
        p->maxLife = 0;
    }
}

// Never called, so not emitted. Deleting a CSparkEmitter makes mwcc generate its (implicit) deleting dtor here, before
// the TU-end class walk queues the other D0s: the original's D0 order (CSparkEmitter first). The original likely had
// unused code like this; the class order can't change (it fixes the RTTI/vtable data order).
static void DeleteSparkEmitter(COPDTitleScreen::CSparkEmitter *emitter)
{
    delete emitter;
}
