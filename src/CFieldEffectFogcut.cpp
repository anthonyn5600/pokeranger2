#include "field/CFieldEffectFogcut.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "fx_utils.hpp"

extern MATHRandContext16 MAIN_BSS_0210CEC8;

void CFieldEffectFogcut::CFPEmitterFogcut::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    u8 i = m_emitIdx++;
    Entry *e = &m_entries[i];
    p->animIdx = e->angle;
    p->life = 0x41000;
    p->maxLife = 0x41000;
    p->sprite.m_alpha = 0x1F;
    p->sprite.m_color = e->color;
    p->pos = (Point2D) { e->pos.x, e->pos.y };
    p->sprite.m_z = 1;
    p->sprite.SetScale(0x1000, 0x1000);
}

void CFieldEffectFogcut::CFPEmitterFogcut::Add(int angle, u16 color, fx32 x, fx32 y)
{
    if (m_count < 4) {
        Entry *e = &m_entries[m_count];
        e->angle = angle;
        e->color = color;
        e->pos.x = x;
        e->pos.y = y;
        m_count++;
    }
}

void CFieldEffectFogcut::CFPForceFieldFogcut::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    fx32 t = p->maxLife - p->life + 0xC000;
    p->sprite.m_cellDataIdx = m_cell;
    fx32 r = FX32_MUL(FX32_MUL(t + 0x1000, t), 0x333) >> 1;
    u16 angle = m_angle + p->animIdx;
    p->pos = (Point2D) { m_center.x + FX32_MUL(r, FX_CosIdx(angle)), m_center.y + FX32_MUL(r, FX_SinIdx(angle)) };
}

CFieldEffectFogcut::CFieldEffectFogcut()
    : m_system(1, 0x20)
{
    CFieldEffectAttackActorData *data = new CFieldEffectAttackActorData();
    if (data != NULL) {
        data->ov0_0214FFF0(0x6E, 1, 1);
        UnkClass_02008788 *cac = data->GetCac(0);
        if (cac != NULL) {
            m_cacId = cac->sub_02008A80(1, 0);
            cac->sub_02008990(m_cacId, 1);
        }
        m_system.SetRes(FieldEffectSpriteRes(data->GetNcbr(0), data->GetPalette(), data->GetNcer(0)));
    }
    unk_18 = data;
    m_timer = 1;
    m_angle = 0;
    m_system.SetEmitter(0, &m_emitter);
    m_system.m_forceField = &m_forceField;
}

CFieldEffectFogcut::~CFieldEffectFogcut()
{
    if (unk_18 != NULL) {
        UnkClass_02008788 *cac = unk_18->GetCac(0);
        if (cac != NULL) {
            cac->sub_02008B80(m_cacId);
        }
    }
    SAFE_DELETE(unk_18);
}

int CFieldEffectFogcut::ov0_02142264(int step)
{
    CFieldEffectActor::ov0_02142264(step);
    m_forceField.m_angle += 0x200;
    m_system.Update(step);
    if (unk_18 != NULL) {
        unk_18->Update();
        UnkClass_02008788 *cac = unk_18->GetCac(0);
        if (cac != NULL) {
            m_forceField.m_cell = cac->sub_02008828(m_cacId);
        }
    }
    if (m_state == 2 && --m_timer == 0) {
        AddPoint(m_angle, m_pos.x, m_pos.y);
        m_angle += 0x2000 + (MATH_Rand16(&MAIN_BSS_0210CEC8, 3) << 12);
        m_timer = MATH_Rand16(&MAIN_BSS_0210CEC8, 3) + 3;
    }
    return m_state;
}

int CFieldEffectFogcut::ov0_02142344(Camera2D *camera)
{
    m_system.Draw(camera);
    return 0;
}

void CFieldEffectFogcut::AddPoint(int angle, fx32 x, fx32 y)
{
    m_emitter.Add(angle, 0x7FFF, x, y);
}

void CFieldEffectFogcut::ov0_0214234C(Point2D pos, int arg1, int arg2, int arg3, int arg4)
{
}

BOOL CFieldEffectFogcut::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    m_forceField.Reset(m_pos);
    return CFieldEffect::ov0_021421F0(inTime, holdTime, outTime);
}

int CFieldEffectFogcut::ov0_02142240(int outTime)
{
    return CFieldEffect::ov0_02142240(outTime);
}

int CFieldEffectFogcut::sub_0203312C(int param, int value)
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

CFieldEffect *CFieldEffectFogcutFactory::Create(int arg)
{
    return new CFieldEffectFogcut();
}
