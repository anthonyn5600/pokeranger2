#include "field/CFieldEffectFlowerStorm.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "fx_utils.hpp"

extern MATHRandContext16 MAIN_BSS_0210CEC8;

void CFieldEffectFlowerStorm::CFPEmitterFlowerStorm::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    u8 i = m_emitIdx++;
    Entry *e = &m_entries[i];
    p->animIdx = e->angle;
    p->life = 0x2D000;
    p->maxLife = 0x2D000;
    p->sprite.m_alpha = 0x1F;
    p->sprite.m_color = 0x7FFF;
    p->pos = (Point2D) { e->pos.x, e->pos.y };
    p->sprite.m_z = 1;
    p->sprite.SetScale(0x1000, 0x1000);
    p->sprite.m_cellDataIdx = MATH_Rand16(&MAIN_BSS_0210CEC8, 6);
}

void CFieldEffectFlowerStorm::CFPEmitterFlowerStorm::Add(fx32 x, fx32 y, int angle)
{
    if (m_count < 6) {
        Entry *e = &m_entries[m_count];
        e->pos.x = x;
        e->pos.y = y;
        e->angle = angle;
        m_count++;
    }
}

void CFieldEffectFlowerStorm::CFPForceFieldFlowerStorm::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    fx32 r = FX32_MUL(p->maxLife - p->life, 0x3000) + 0x10000;
    u16 angle = m_angle + p->animIdx;
    p->pos = (Point2D) { m_center.x + FX32_MUL(r, FX_CosIdx(angle)), m_center.y + FX32_MUL(r * 3 >> 2, FX_SinIdx(angle)) };
    p->rot = angle;
}

void CFieldEffectFlowerStorm::CFPForceFieldFlowerStorm::Step(int step)
{
    m_angle += (step == 0x3C ? 1 : 2) << 8;
}

CFieldEffectFlowerStorm::CFieldEffectFlowerStorm()
    : m_system(1, 0xA0)
{
    CFieldEffectNormalActorData *data = new CFieldEffectNormalActorData();
    if (data != NULL) {
        data->Load(0x67, 0);
        m_system.SetRes(FieldEffectSpriteRes(data->GetNcbr(0), data->GetPalette(), data->GetNcer(0)));
    }
    unk_18 = data;
    m_timer = 1;
    m_angle = 0;
    m_system.SetEmitter(0, &m_emitter);
    m_system.m_forceField = &m_forceField;
}

CFieldEffectFlowerStorm::~CFieldEffectFlowerStorm()
{
    SAFE_DELETE(unk_18);
}

int CFieldEffectFlowerStorm::Update(int step)
{
    CFieldEffectActor::Update(step);
    m_forceField.Step(step);
    m_system.Update(step);
    if (unk_18 != NULL) {
        unk_18->Update();
        m_forceField.unk_04 = 0;
    }
    if (m_state == 2 && --m_timer == 0) {
        int n = MATH_Rand16(&MAIN_BSS_0210CEC8, 5) + 1;
        for (int i = 0; i < n; i++) {
            m_emitter.Add(m_pos.x, m_pos.y, m_angle);
            m_angle = MATH_Rand16(&MAIN_BSS_0210CEC8, 64) << 10;
        }
        MATH_Rand16(&MAIN_BSS_0210CEC8, 0);
        m_timer = 1;
    }
    return m_state;
}

int CFieldEffectFlowerStorm::Render(Camera2D *camera)
{
    m_system.Draw(camera);
    return 0;
}

void CFieldEffectFlowerStorm::StartAt(Point2D pos, int arg1, int arg2, int arg3, int arg4)
{
}

BOOL CFieldEffectFlowerStorm::Start(int inTime, int holdTime, int outTime)
{
    m_forceField.Reset(m_pos);
    return CFieldEffect::Start(inTime, holdTime, outTime);
}

int CFieldEffectFlowerStorm::Stop(int outTime)
{
    return CFieldEffect::Stop(outTime);
}

int CFieldEffectFlowerStorm::SetParam(int param, int value)
{
    switch (param) {
    case 1:
        m_pos.x = value << 12;
        break;
    case 2:
        m_pos.y = value << 12;
        break;
    }
    return 0;
}

CFieldEffect *CFieldEffectFlowerStormFactory::Create(int arg)
{
    return new CFieldEffectFlowerStorm();
}
