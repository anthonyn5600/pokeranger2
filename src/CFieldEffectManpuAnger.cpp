#include "field/CFieldEffectManpuAnger.hpp"

#include "CGame.hpp"
#include "field/CFieldEffectManpuPos.hpp"
#include "fx_utils.hpp"

CFieldEffectManpuAnger::CFieldEffectManpuAnger(CEffectActorData *data)
    : CFieldEffectManpu(data)
    , m_system(1, 3)
{
    unk_28 = 1;
    m_system.SetEmitter(0, &m_emitter);
    m_system.m_forceField = &m_animator;
    m_system.SetRes(FieldEffectSpriteRes(data->GetNcbr(0), data->GetPalette(), data->GetNcer(0)));
    m_emitter.m_interval = 20;
}

CFieldEffectManpuAnger::~CFieldEffectManpuAnger()
{
}

BOOL CFieldEffectManpuAnger::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    m_emitter.m_actor = unk_1C;
    m_emitter.func2();
    return CFieldEffect::ov0_021421F0(inTime, holdTime, outTime);
}

int CFieldEffectManpuAnger::ov0_02142264(int step)
{
    int state = CFieldEffectActor::ov0_02142264(step);
    if (state != 0 && state != 4) {
        m_system.Update(step);
    }
    return state;
}

void CFieldEffectManpuAnger::SetDepth(fx32 z)
{
    m_system.m_depth = z;
}

int CFieldEffectManpuAnger::Draw(Camera2D *camera)
{
    if (m_state != 0 && m_state != 4) {
        m_system.Draw(camera);
    }
    return 0;
}

void CFieldEffectManpuAnger::CEmitter::func2()
{
    m_timer = FX32_ONE;
}

u32 CFieldEffectManpuAnger::CEmitter::Update(int dt)
{
    u32 count = 0;
    if (m_timer > 0) {
        m_timer -= dt;
        if (m_timer <= 0) {
            count = 1;
            if (m_interval > 0) {
                m_timer = m_interval << 12;
            }
        }
    }
    return count;
}

void CFieldEffectManpuAnger::CEmitter::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    if (m_actor == NULL) {
        return;
    }
    Point2D pos = GetBalloonPos(m_actor);
    p->life = 0x14000;
    p->maxLife = 0x14000;
    p->rotVel = 0;
    p->sprite.m_alpha = 31;
    m_dir = m_dir + 1 + MATH_Rand32(&CGame::GetInstance()->m_rand32, 2);
    if (m_dir >= 3) {
        m_dir -= 3;
    }
    switch (m_dir) {
    case 0:
        p->SetPos(pos.x - 0x4000, pos.y);
        p->vel.x = -0x1C00;
        p->vel.y = -0x1C00;
        p->animIdx = 1;
        break;
    case 1:
        p->SetPos(pos.x + 0x4000, pos.y);
        p->vel.x = 0x1C00;
        p->vel.y = -0x1C00;
        p->animIdx = 0;
        break;
    default:
        p->SetPos(pos.x, pos.y);
        p->vel.x = 0;
        p->vel.y = -0x1C00;
        p->animIdx = 0;
        break;
    }
}

void CFieldEffectManpuAnger::CAnimator::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    fx32 scale;
    fx32 maxLife = p->maxLife;
    fx32 age = maxLife - p->life;
    if (age < 0x4000) {
        scale = 0x800;
    } else {
        p->vel.x = 0;
        p->vel.y = 0;
        scale = 0x800 + FX32_MUL(FX32_DIV(age - 0x4000, maxLife - 0x4000), FX32_ONE);
    }
    if (p->animIdx & 1) {
        p->sprite.m_scale[0] = -scale;
    } else {
        p->sprite.m_scale[0] = scale;
    }
    p->sprite.m_scale[1] = scale;
}
