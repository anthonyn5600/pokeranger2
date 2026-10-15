#include "field/CFieldEffectWaveBullet.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "field/CFieldEffectManage.hpp"
#include "fx_utils.hpp"

extern "C" {
void LogError(const char *fmt, ...);
}

CFieldEffectWaveBullet::CFieldEffectWaveBullet(int kind)
    : m_kind(kind)
    , m_se(-1)
    , m_system(1, 0x20)
{
    CFieldEffectAttackActorData *data = new CFieldEffectAttackActorData();
    if (data != NULL) {
        data->Load(kind, m_kind == 0x4F ? 2 : 1, 1);
    }
    unk_18 = data;
    if (unk_18 != NULL) {
        CellAnimController *cac = unk_18->GetCac(0);
        if (cac != NULL) {
            m_cacId = cac->Create(1, 0);
        } else {
            LogError("effect anime data is null");
        }
    }
    m_system.SetEmitter(0, &m_emitter);
    m_system.m_forceField = &m_animator;
    if (data != NULL) {
        m_system.SetRes(FieldEffectSpriteRes(data->GetNcbr(0), data->GetPalette(), data->GetNcer(0)));
    }
    if (kind == 0x20 || kind == 0x22 || kind == 0x5B) {
        m_animator.m_scaleStart = 0x800;
        m_animator.m_scaleEnd = 0x2000;
    }
}

CFieldEffectWaveBullet::~CFieldEffectWaveBullet()
{
    if (unk_18 != NULL) {
        CellAnimController *cac = unk_18->GetCac(0);
        if (cac != NULL) {
            cac->Remove(m_cacId);
        }
    }
    SAFE_DELETE(unk_18);
}

int CFieldEffectWaveBullet::Update(int step)
{
    int state = CFieldEffectActor::Update(step);
    if (state != 0 && state != 4 && unk_18 != NULL) {
        unk_18->Update();
    }
    if (state != 4 && state != 0) {
        CellAnimController *cac = unk_18->GetCac(0);
        if (cac != NULL) {
            m_animator.m_cell = cac->GetCell(m_cacId);
        }
        if (m_system.Update(step) != 0 && m_se >= 0) {
            CGame *game = CGame::GetInstance();
            game->m_audioEngine->PlaySe(m_se);
        }
    }
    return state;
}

int CFieldEffectWaveBullet::Render(Camera2D *camera)
{
    if (m_state != 4 && m_state != 0) {
        if (m_state == 3) {
            m_emitter.m_timer = 0;
        }
        m_system.Draw(camera);
    }
    return 0;
}

int CFieldEffectWaveBullet::SetParam(int param, int value)
{
    BOOL ret = TRUE;
    switch (param) {
    case 1:
        m_emitter.m_pos.x = value << 12;
        break;
    case 2:
        m_emitter.m_pos.y = value << 12;
        break;
    case 9:
        m_emitter.m_target.x = value << 12;
        break;
    case 10:
        m_emitter.m_target.y = value << 12;
        break;
    case 12:
        m_emitter.m_period = value;
        break;
    case 11:
        if (value >= 0 && value <= 180) {
            m_emitter.m_amp = (u16)((value << 16) / 360);
        } else {
            m_emitter.m_amp = 0;
        }
        break;
    case 13:
        m_emitter.m_interval = value;
        break;
    case 14:
        m_emitter.m_speed = (value << 12) / 60;
        break;
    case 8:
        m_emitter.m_life = value << 12;
        break;
    case 15:
        m_emitter.m_rotVel = (value << 16) / 21600;
        break;
    default:
        ret = FALSE;
        break;
    }
    return ret;
}

BOOL CFieldEffectWaveBullet::Start(int inTime, int holdTime, int outTime)
{
    m_emitter.func2();
    return CFieldEffect::Start(inTime, holdTime, outTime);
}

void CFieldEffectWaveBullet::SetSe(int arg0)
{
    m_se = arg0;
}

u32 CFieldEffectWaveBullet::CWaveParticleEmitter::Update(int dt)
{
    u32 emit = 0;
    if (m_timer > 0) {
        m_timer -= dt;
        if (m_timer <= 0) {
            emit = 1;
            if (m_interval > 0) {
                m_timer = m_interval << 12;
            }
        }
    }
    m_phase += m_phaseStep;
    if (m_phase >= m_amp) {
        m_phaseStep = -m_phaseStep;
    } else if (m_phase <= -m_amp) {
        m_phaseStep = -m_phaseStep;
    }
    return emit;
}

void CFieldEffectWaveBullet::CWaveParticleEmitter::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    p->pos = (Point2D) { m_pos.x, m_pos.y };
    p->maxLife = p->life = m_life;
    p->sprite.m_cellDataIdx = 0;
    int idx = ((u16)(m_dir + m_phase) >> 4) * 2;
    fx32 speed = m_speed;
    p->vel.x = FX32_MUL(speed, FX_SinCosTable_[idx + 1]);
    p->vel.y = FX32_MUL(speed, FX_SinCosTable_[idx]);
    p->rotVel = m_rotVel;
}

void CFieldEffectWaveBullet::CWaveParticleEmitter::func2()
{
    m_dir = FX_Atan2Idx(m_target.y - m_pos.y, m_target.x - m_pos.x);
    m_timer = 0x1000;
    m_phase = 0;
    if (m_period > 0) {
        m_phaseStep = (m_amp * 4) / m_period;
    } else {
        m_phaseStep = 0;
    }
}

void CFieldEffectWaveBullet::CWaveParticleAnimator::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    p->sprite.m_cellDataIdx = m_cell;
    if (m_scaleStart == m_scaleEnd) {
        return;
    }
    fx32 life = p->life;
    fx32 maxLife = p->maxLife;
    fx32 scale;
    if (life < 0x8000) {
        scale = FX32_MUL(m_scaleEnd, life) >> 3;
    } else {
        scale = m_scaleStart + FX32_DIV(FX32_MUL(maxLife - life, m_scaleEnd - m_scaleStart), maxLife - 8);
    }
    p->sprite.m_scale[0] = scale;
    p->sprite.m_scale[1] = scale;
}

CFieldEffect *CFieldEffectWaveBulletFactory::Create(int arg)
{
    return new CFieldEffectWaveBullet(arg);
}

// Out of line (not inline in the class): the original emits it here, before the nested classes' deleting dtors.
int CFieldEffectWaveBullet::GetEffectId()
{
    return 5;
}

// Never called, so not emitted. Deleting the emitter and animator makes mwcc generate their implicit deleting dtors
// here, before the TU-end class walk queues the factory's: the original's D0 order (emitter, animator, factory). The
// class order can't change (it fixes the RTTI/vtable data order).
static void DeleteWaveParticles(CFieldEffectWaveBullet::CWaveParticleEmitter *emitter,
    CFieldEffectWaveBullet::CWaveParticleAnimator *animator)
{
    delete emitter;
    delete animator;
}
