#include "field/CFieldEffectSandBurial.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "fx_utils.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;
extern MATHRandContext16 MAIN_BSS_0210CEC8;

void CFieldEffectSandBurial::CFPEmitterSandBurial::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    u8 i = m_emitIdx++;
    p->life = 0x28000;
    p->maxLife = 0x28000;
    p->sprite.m_alpha = 0x1F;
    Entry *e = &m_entries[i];
    p->sprite.m_color = e->color;
    p->pos = (Point2D) { e->pos.x, e->pos.y };
    p->sprite.m_cellDataIdx = 6;
    p->sprite.m_z = -1;
}

void CFieldEffectSandBurial::CFPEmitterSandBurial::Add(u16 color, fx32 x, fx32 y)
{
    if (m_count < 8) {
        Entry *e = &m_entries[m_count];
        e->color = color;
        e->pos.x = x;
        e->pos.y = y;
        m_count++;
    }
}

void CFieldEffectSandBurial::CFPForceFieldSandBurial::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    fx32 scale = FX32_MUL(p->maxLife - p->life, 0x200);
    if (scale > 0x3000) {
        scale = 0x3000;
    }
    p->sprite.SetScale(scale, scale);
    p->sprite.m_alpha = p->life < 0x1E000 ? p->life >> 12 : 0x1E;
}

CFieldEffectSandBurial::CFieldEffectSandBurial()
    : m_system(1, 0x28)
{
    m_system.SetEmitter(0, &m_emitter);
    m_system.m_forceField = &m_forceField;
    CFieldEffectManage *mgr = MAIN_BSS_0210CA40->m_effects;
    m_system.SetRes(FieldEffectSpriteRes(mgr->m_resident.GetNcbr(0), mgr->m_resident.GetPalette(), mgr->m_resident.GetNcer(0)));
}

CFieldEffectSandBurial::~CFieldEffectSandBurial()
{
}

int CFieldEffectSandBurial::ov0_02142264(int step)
{
    CFieldEffectActor::ov0_02142264(step);
    m_system.Update(step);
    if (m_state == 2 && m_timer++ == 1) {
        if (MATH_Rand16(&MAIN_BSS_0210CEC8, 2) == 0) {
            int dx = MATH_Rand16(&MAIN_BSS_0210CEC8, 64);
            int dy = MATH_Rand16(&MAIN_BSS_0210CEC8, 64);
            AddPoint(m_center.x + ((dx - 32) << 12), m_center.y + ((dy - 32) << 12));
        } else {
            int dx = MATH_Rand16(&MAIN_BSS_0210CEC8, 0x30);
            int dy = MATH_Rand16(&MAIN_BSS_0210CEC8, 0x30);
            AddPoint(m_center.x + ((dx - 0x18) << 12), m_center.y + ((dy - 0x18) << 12));
        }
        m_timer = 0;
    }
    return m_state;
}

int CFieldEffectSandBurial::ov0_02142344(Camera2D *camera)
{
    m_system.Draw(camera);
    return 0;
}

void CFieldEffectSandBurial::ov0_0214234C(Point2D pos, int arg1, int arg2, int arg3, int arg4)
{
    m_center = pos;
    m_timer = 0;
    ov0_021421F0(120, 120, 120);
}

void CFieldEffectSandBurial::AddPoint(fx32 x, fx32 y)
{
    m_emitter.Add(0x7FFF, x, y);
}

CFieldEffect *CFieldEffectSandBurialFactory::Create(int arg)
{
    return new CFieldEffectSandBurial();
}
