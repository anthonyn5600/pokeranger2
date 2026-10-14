#include "field/CFieldEffectScatterLeaves.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"

CFieldEffectScatterLeaves::CFieldEffectScatterLeaves(int kind)
{
}

int CFieldEffectScatterLeaves::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 6:
        m_emitter.m_count = value;
        break;
    case 3:
        m_emitter.m_width = value << 12;
        break;
    case 4:
        m_emitter.m_height = value << 12;
        break;
    case 5:
        m_emitter.m_interval = value;
        break;
    case 8:
        m_emitter.m_life = value << 12;
        break;
    default:
        ret = TFieldEffectParticle<CSoftwareSprite>::SetParam(param, value);
        break;
    }
    return ret;
}

u32 CFieldParticleLeavesEmitter::Update(int dt)
{
    u32 count = 0;
    if (m_timer > 0) {
        m_timer -= dt;
        if (m_timer <= 0) {
            count = MATH_Rand32(&CGame::GetInstance()->m_rand32, 5) + 8;
            if (m_interval > 0) {
                m_timer = m_interval << 12;
            }
        }
    }
    return count;
}

void CFieldParticleLeavesEmitter::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    static int sLeafCells[4] = { 0, 3, 4, 5 };
    CGame *game = CGame::GetInstance();
    fx32 vx;
    fx32 vy;
    s16 rotVel;
    fx32 x = RandCentered(m_width);
    fx32 y = RandCentered(m_height);
    p->pos = (Point2D) { m_pos.x + x, m_pos.y + y };
    fx32 life = m_life;
    p->life = life;
    p->maxLife = life;
    MATHRandContext32 *cellRand = &game->m_rand32;
    TFieldParticleRes<CSoftwareSprite>::SetCell(p, sLeafCells[MATH_Rand32(cellRand, 4)]);
    rotVel = 0xB6;
    MATHRandContext32 *xRand = &game->m_rand32;
    vx = FX_CosIdx(MATH_Rand32(xRand, 0x4000)) * 2;
    if (p->pos.x == 0) {
        MATHRandContext32 *flipRand = &game->m_rand32;
        if (MATH_Rand32(flipRand, 2) == 0) {
            rotVel = -rotVel;
            vx = -vx;
        }
    } else if (p->pos.x < 0) {
        rotVel = -rotVel;
        vx = -vx;
    }
    MATHRandContext32 *yRand = &game->m_rand32;
    vy = FX_SinIdx(MATH_Rand32(yRand, 0x4000)) * 2;
    if (p->pos.y == 0) {
        MATHRandContext32 *flipRand = &game->m_rand32;
        if (MATH_Rand32(flipRand, 2) == 0) {
            vy = -vy;
        }
    } else if (p->pos.y < 0) {
        vy = -vy;
    }
    p->vel.x = vx;
    p->vel.y = vy;
    p->rotVel = rotVel;
}

void CFieldParticleLeavesAnimator::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    p->vel.y += FX32_MUL(dt, 0x199);
}

CFieldEffect *CFieldEffectScatterLeavesFactory::Create(int arg)
{
    CFieldEffectScatterLeaves *effect = new CFieldEffectScatterLeaves(arg);
    CFieldEffectManage *mgr;
    if (effect != NULL && (mgr = MAIN_BSS_0210CA60) != NULL) {
        effect->ov0_021423E8(FieldEffectSpriteRes(mgr->m_resident.GetNcbr(0), mgr->m_resident.GetPalette(), mgr->m_resident.GetNcer(0)));
    }
    return effect;
}
