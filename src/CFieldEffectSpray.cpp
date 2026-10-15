// clang-format off
#include "field/TFieldParticle.hpp"

// Completing the emitter template before the effect classes gives the original typeinfo order (emitter, effect,
// animator, factory); in the header it would also instantiate it in FieldEffectFactories.cpp. The effect header must
// come before CFieldEffectManage.hpp too.
template class TFieldParticleEmitter<CSoftwareSprite>;

#include "field/CFieldEffectSpray.hpp"
// clang-format on

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "fx_utils.hpp"

extern "C" {
void LogError(const char *fmt, ...);
}

CFieldEffectSpray::CFieldEffectSpray(int kind)
    : m_kind(kind)
    , m_system(1, 0x20)
{
    CFieldEffectAttackActorData *data = new CFieldEffectAttackActorData();
    if (data != NULL) {
        data->Load(kind, 1, 1);
    }
    unk_18 = data;
    CellAnimController *cac = unk_18->GetCac(0);
    if (cac != NULL) {
        m_cacId = cac->Create(1, 0);
    } else {
        LogError("effect anime data is null");
    }
    m_system.SetEmitter(0, &m_emitter);
    m_system.m_forceField = &m_animator;
    if (data != NULL) {
        m_system.SetRes(FieldEffectSpriteRes(data->GetNcbr(0), data->GetPalette(), data->GetNcer(0)));
    }
    if (kind == 0x5B) {
        m_animator.m_scaleStart = 0x800;
        m_animator.m_scaleEnd = 0x2000;
    }
}

CFieldEffectSpray::~CFieldEffectSpray()
{
    if (unk_18 != NULL) {
        CellAnimController *cac = unk_18->GetCac(0);
        if (cac != NULL) {
            cac->Remove(m_cacId);
        }
    }
    SAFE_DELETE(unk_18);
}

int CFieldEffectSpray::Update(int step)
{
    int state = CFieldEffectActor::Update(step);
    if (state != 4 && state != 0) {
        if (unk_18 != NULL) {
            unk_18->Update();
        }
        CellAnimController *cac = unk_18->GetCac(0);
        if (cac != NULL) {
            m_animator.m_cell = cac->GetCell(m_cacId);
        }
        m_system.Update(step);
    }
    return state;
}

int CFieldEffectSpray::Render(Camera2D *camera)
{
    if (m_state != 4 && m_state != 0) {
        if (m_state == 3) {
            m_emitter.m_timer = 0;
        }
        m_system.Draw(camera);
    }
    return 0;
}

int CFieldEffectSpray::SetParam(int param, int value)
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

BOOL CFieldEffectSpray::Start(int inTime, int holdTime, int outTime)
{
    m_emitter.func2();
    return CFieldEffect::Start(inTime, holdTime, outTime);
}

u32 CFieldEffectSpray::CWaveParticleEmitter::Update(int dt)
{
    u32 emit = 0;
    if (m_timer > 0) {
        m_timer -= dt;
        if (m_timer <= 0) {
            if (m_spread != 0) {
                m_offsets[0] = RandCentered(2000);
                m_offsets[1] = RandCentered(5000);
                emit = 2;
            } else {
                m_offsets[1] = 0;
                m_offsets[0] = 0;
                emit = 1;
            }
            m_index = 0;
            m_spread ^= 1;
            if (m_interval > 0) {
                m_timer = m_interval << 12;
            }
        }
    }
    return emit;
}

void CFieldEffectSpray::CWaveParticleEmitter::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    p->pos = (Point2D) { m_pos.x, m_pos.y };
    p->maxLife = p->life = m_life;
    p->sprite.m_cellDataIdx = 0;
    p->rot = m_dir + 0x2000;
    int idx = ((u16)(m_dir + m_offsets[m_index]) >> 4) * 2;
    fx32 speed = m_speed;
    p->vel.x = FX32_MUL(speed, FX_SinCosTable_[idx + 1]);
    p->vel.y = FX32_MUL(speed, FX_SinCosTable_[idx]);
    p->rotVel = m_rotVel;
    p->sprite.m_alpha = 0x1F;
    if (m_index + 1 < 3) {
        m_index++;
    }
}

void CFieldEffectSpray::CWaveParticleEmitter::func2()
{
    m_dir = FX_Atan2Idx(m_target.y - m_pos.y, m_target.x - m_pos.x);
    m_timer = 0x1000;
    m_spread = 0;
}

void CFieldEffectSpray::CWaveParticleAnimator::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    p->sprite.m_cellDataIdx = m_cell;
    fx32 life = p->life;
    if (m_scaleStart != m_scaleEnd) {
        fx32 maxLife = p->maxLife;
        fx32 scale = m_scaleStart + FX32_DIV(FX32_MUL(maxLife - life, m_scaleEnd - m_scaleStart), maxLife);
        p->sprite.m_scale[0] = scale;
        p->sprite.m_scale[1] = scale;
    }
    if (life < 0x10000) {
        p->sprite.m_alpha = (life >> 12) * 2;
    }
}

CFieldEffect *CFieldEffectSprayFactory::Create(int arg)
{
    return new CFieldEffectSpray(arg);
}

int CFieldEffectSpray::GetEffectId()
{
    return 7;
}
