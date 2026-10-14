#include "field/CFieldEffectManpuGokigen.hpp"

#include "CGame.hpp"
#include "field/CFieldEffectManpuPos.hpp"
#include "fx_utils.hpp"

static const u8 sColors[6][3] = {
    { 31, 0, 0 },
    { 31, 31, 0 },
    { 0, 31, 0 },
    { 0, 31, 31 },
    { 0, 0, 31 },
    { 31, 0, 31 },
};

CFieldEffectManpuGokigen::CFieldEffectManpuGokigen(CEffectActorData *data)
    : CFieldEffectManpu(data)
    , m_system(1, 3)
{
    unk_28 = 1;
    m_system.SetEmitter(0, &m_emitter);
    m_system.m_forceField = &m_animator;
    m_system.SetRes(FieldEffectSpriteRes(data->GetNcbr(0), data->GetPalette(), data->GetNcer(0)));
    m_emitter.m_interval = 30;
}

CFieldEffectManpuGokigen::~CFieldEffectManpuGokigen()
{
}

void CFieldEffectManpuGokigen::SetType(int type)
{
    m_animator.m_type = type;
    m_emitter.m_interval = type == 11 ? 30 : 60;
    unk_24 = type;
}

BOOL CFieldEffectManpuGokigen::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    m_emitter.m_actor = unk_1C;
    m_emitter.func2();
    return CFieldEffect::ov0_021421F0(inTime, holdTime, outTime);
}

int CFieldEffectManpuGokigen::ov0_02142264(int step)
{
    int state = CFieldEffectActor::ov0_02142264(step);
    if (state != 0 && state != 4) {
        m_animator.Step(step);
        m_system.Update(step);
    }
    return state;
}

void CFieldEffectManpuGokigen::SetDepth(fx32 z)
{
    m_system.m_depth = z;
}

int CFieldEffectManpuGokigen::Draw(Camera2D *camera)
{
    if (m_state != 0 && m_state != 4) {
        m_system.Draw(camera);
    }
    return 0;
}

void CFieldEffectManpuGokigen::CEmitter::func2()
{
    m_timer = FX32_ONE;
}

u32 CFieldEffectManpuGokigen::CEmitter::Update(int dt)
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

void CFieldEffectManpuGokigen::CEmitter::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    if (m_actor == NULL) {
        return;
    }
    const fx32 ofs = 0x8000;
    Point2D pos = GetBalloonPos(m_actor);
    p->life = 0x3C000;
    p->maxLife = 0x3C000;
    p->rotVel = 0;
    p->sprite.m_alpha = 31;
    p->sprite.m_color = 0;
    m_dir = m_dir + 1 + MATH_Rand32(&CGame::GetInstance()->m_rand32, 2);
    if (m_dir >= 3) {
        m_dir -= 3;
    }
    switch (m_dir) {
    case 0:
        p->SetPos(pos.x - ofs, pos.y);
        break;
    case 1:
        p->SetPos(pos.x + ofs, pos.y);
        break;
    default:
        p->SetPos(pos.x, pos.y);
        break;
    }
    p->animIdx = MATH_Rand32(&CGame::GetInstance()->m_rand32, 0xFFFF) | (m_dir << 16);
}

void CFieldEffectManpuGokigen::CAnimator::Step(int dt)
{
    if (m_type == 11) {
        m_timer += dt;
        if (m_timer >= 12) {
            m_frame++;
            if (m_frame >= 6) {
                m_frame = 0;
            }
            m_timer -= 12;
        }
    }
}

void CFieldEffectManpuGokigen::CAnimator::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    int life = p->life;
    fx32 vx = FX_CosIdx((u16)(FX32_MUL(p->maxLife - life, 0x666) + (u16)p->animIdx));
    switch ((u16)((u32)p->animIdx >> 16)) {
    case 0:
        vx -= 0x666 >> 1;
        break;
    case 1:
        vx += 0x333;
        break;
    }
    p->vel.x = vx;
    p->vel.y = -FX32_ONE;
    switch (m_type) {
    case 10:
        break;
    case 11: {
        u8 next = m_frame + 1;
        if ((int)next >= 6) {
            next = 0;
        }
        u8 rgb[3];
        for (int i = 0; i < 3; i++) {
            rgb[i] = sColors[m_frame][i] + ((m_timer * (sColors[next][i] - sColors[m_frame][i])) >> 5);
        }
        p->sprite.m_color = GX_RGB(rgb[0], rgb[1], rgb[2]);
        break;
    }
    }
    if (life < 0x20000) {
        p->sprite.m_alpha = life >> 12;
    }
}
