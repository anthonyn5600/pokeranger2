#include "field/CFieldEffectAirBubbles.hpp"

#include <nitro.h>

#include "CGame.hpp"

CFieldEffectAirBubbles::CFieldEffectAirBubbles()
{
    m_emitter.m_width = 0xA000;
}

CFieldEffectAirBubbles::~CFieldEffectAirBubbles()
{
}

int CFieldEffectAirBubbles::SetParam(int param, int value)
{
    return TFieldEffectParticle<CSoftwareSprite>::SetParam(param, value);
}

BOOL CFieldEffectAirBubbles::ov0_0216D050(fx32 x, fx32 y)
{
    m_emitter.Start(x, y, MATH_Rand32(&CGame::GetInstance()->m_rand32, 2) + 2);
    return TRUE;
}

void CFieldEffectAirBubbles::CBubbleForceField::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    p->vel.x = FX_CosIdx((u16)FX32_MUL(p->maxLife - p->life, 0xCCC));
    p->vel.y = -FX32_ONE;
}

void CFieldEffectAirBubbles::CBubbleEmitter::Start(fx32 x, fx32 y, int count)
{
    m_origin.x = x;
    m_origin.y = y;
    m_pos.x = m_origin.x;
    m_pos.y = m_origin.y;
    m_count = count;
    m_timer = 1;
}

u32 CFieldEffectAirBubbles::CBubbleEmitter::Update(int dt)
{
    if (m_count > 0) {
        if (--m_timer <= 0) {
            m_count--;
            m_timer = 5;
            return 1;
        }
    }
    return 0;
}

void CFieldEffectAirBubbles::CBubbleEmitter::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    fx32 x = RandCentered(m_width);
    fx32 y = RandCentered(m_height);
    p->pos = (Point2D) { m_pos.x + x, m_pos.y + y };
    p->life = 0x78000;
    p->maxLife = 0x78000;
    p->sprite.m_cellDataIdx = MATH_Rand32(&CGame::GetInstance()->m_rand32, 3);
    p->sprite.m_z = -1;
}

TFieldParticleEmitter<CSoftwareSprite> *CFieldEffectAirBubbles::GetEmitter()
{
    return &m_emitter;
}

TFieldParticleForceField<CSoftwareSprite> *CFieldEffectAirBubbles::GetForceField()
{
    return &m_forceField;
}

int CFieldEffectAirBubbles::GetEffectId()
{
    return 0x28;
}

// Never called (mwld strips it): makes CBubbleForceField's implicit D0 come out here, before CBubbleEmitter's as in
// the original (rule E-WEAK-TAIL-WALK; the three virtuals above are out of line so they stay before it).
static void DeleteForceField(CFieldEffectAirBubbles::CBubbleForceField *forceField)
{
    delete forceField;
}
