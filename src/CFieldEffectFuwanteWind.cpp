#include "field/CFieldEffectFuwanteWind.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "CellAnimController.hpp"
#include "fx_utils.hpp"

// Built through meson.build's pokeranger2_ov0_wind targets, not src/meson.build: the original TU's .data order came
// from a size sort that no class/include layout of ours reproduces (searched: factory/nested-class order, template size
// asserts, include order; the fits need two objects the linker later dropped), so the equal-size typeinfos/vtables are
// put in the original order after compiling (tools/elfdataorder/CFieldEffectFuwanteWind.txt).

CFieldEffectFuwanteWind::CFieldEffectFuwanteWind()
{
}

CFieldEffectFuwanteWind::~CFieldEffectFuwanteWind()
{
}

int CFieldEffectFuwanteWind::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 0x17:
        m_emitter.m_dir = value;
        break;
    case 5:
        m_emitter.m_interval = value;
        break;
    case 6:
        m_emitter.m_count = value;
        break;
    case 3:
        m_emitter.m_width = value << 12;
        break;
    case 4:
        m_emitter.m_height = value << 12;
        break;
    case 8:
        m_emitter.m_lifeMin = value;
        m_emitter.m_lifeMax = value;
        break;
    default:
        ret = TFieldEffectParticle<CSoftwareSprite>::SetParam(param, value);
        break;
    }
    return ret;
}

int CFieldEffectFuwanteWind::ov0_02142344(Camera2D *camera)
{
    if (m_system != NULL) {
        m_system->Draw(camera);
    }
    return 0;
}

void CFieldEffectFuwanteWind::CEmitter::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    fx32 x = RandCentered(m_width);
    fx32 y = RandCentered(m_height);
    p->pos = (Point2D) { m_pos.x + x, m_pos.y + y };
    int life = m_lifeMin << 12;
    p->life = life;
    p->maxLife = life;
    u8 id = m_polygonID++;
    p->sprite.m_polygonID = id + 8;
    m_polygonID &= 0x1F;
    p->rotVel = 0;
    p->sprite.m_alpha = 0x18;
    p->sprite.m_scale[0] = 0x800;
    p->sprite.m_scale[1] = 0x800;
    int flags = 0;
    fx32 vx = 0x355;
    if (m_dir == 0) {
        vx = -vx;
    } else {
        flags = 2;
    }
    flags |= (m_polygonID & 3) << 16;
    fx32 vy = -0x777;
    p->vel.x = vx;
    p->vel.y = vy;
    p->animIdx = flags;
    p->sprite.m_z = vy >> 11;
}

void CFieldEffectFuwanteWind::CAnimator::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    fx32 age = p->maxLife - p->life;
    fx32 scale = FX32_DIV(FX32_MUL(age, FX32_ONE), p->maxLife) + 0x800;
    p->sprite.m_scale[0] = scale;
    p->sprite.m_scale[1] = scale;
    if (age < 0xD2000) {
        p->sprite.m_alpha = 0x18;
    } else if (age < 0xF0000) {
        p->sprite.m_alpha = (FX32_DIV(FX32_MUL(age - 0xD2000, -0x18000), 0x1E000) + 0x18000) >> 12;
    } else {
        p->sprite.m_alpha = 0;
    }
    CGame *game = CGame::GetInstance();
    int phase;
    fx32 vx;
    u32 flags = p->animIdx;
    phase = flags >> 16;
    if (age >= 0x78000 && !(flags & 1)) {
        MATHRandContext32 *rand = &game->m_rand32;
        vx = MATH_Rand32(rand, 0x333) + 0xBBC;
        if (!(flags & 2)) {
            vx = -vx;
        }
        rand = &game->m_rand32;
        fx32 vy = MATH_Rand32(rand, 0x333) - 0x199;
        p->vel.x = vx;
        p->vel.y = vy;
        p->animIdx = (flags & ~1) | 1;
    }
    if (m_cells != NULL && phase < 3) {
        p->sprite.m_cellDataIdx = m_cac->GetCell(m_cells[phase]);
    }
}

CFieldEffectFuwanteWindFactory::~CFieldEffectFuwanteWindFactory()
{
    Release();
}

void CFieldEffectFuwanteWindFactory::Reset()
{
    Release();
}

BOOL CFieldEffectFuwanteWindFactory::Load()
{
    m_data.ov0_021503B8(0x69, TRUE);
    if (m_cells != NULL) {
        delete[] m_cells;
        m_cells = NULL;
    }
    CellAnimController *cac = m_data.GetCac(0);
    if (cac != NULL) {
        m_cells = new u16[3];
        for (int i = 0; i < 3; i++) {
            m_cells[i] = cac->Create(1, 0);
            int n = 6;
            while (n--) {
                cac->UpdateAll();
            }
        }
    }
    return FALSE;
}

void CFieldEffectFuwanteWindFactory::Release()
{
    if (m_cells != NULL) {
        CellAnimController *cac = m_data.GetCac(0);
        if (cac != NULL) {
            for (int i = 0; i < 3; i++) {
                if (m_cells[i] != 0) {
                    cac->Remove(m_cells[i]);
                }
            }
        }
    }
    if (m_cells != NULL) {
        delete[] m_cells;
        m_cells = NULL;
    }
    m_data.Release();
}

CFieldEffect *CFieldEffectFuwanteWindFactory::Create(int arg)
{
    CFieldEffectFuwanteWind *effect = new CFieldEffectFuwanteWind();
    if (effect != NULL) {
        effect->ov0_021423E8(FieldEffectSpriteRes(m_data.GetNcbr(0), m_data.GetPalette(), m_data.GetNcer(0)));
        u16 *cells = m_cells;
        effect->m_animator.m_cac = m_data.GetCac(0);
        effect->m_animator.m_cells = cells;
    }
    return effect;
}

void CFieldEffectFuwanteWindFactory::Update(int frames)
{
    m_data.Update();
}
