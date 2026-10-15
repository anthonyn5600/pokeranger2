#include "field/CFieldEffectFootStepSmoke.hpp"

#include <nitro.h>

#include "field/CFieldEffectManage.hpp"
#include "fx_utils.hpp"

CFieldEffectFootStepSmoke::CFieldEffectFootStepSmoke()
    : m_system(1, 4)
{
    m_cac = NULL;
    m_system.SetEmitter(0, &m_emitter);
    m_system.m_forceField = &m_animator;
    MI_CpuFill8(m_puffs, 0, sizeof(m_puffs));
}

CFieldEffectFootStepSmoke::~CFieldEffectFootStepSmoke()
{
}

void CFieldEffectFootStepSmoke::SetSmokeRes(VramImage *ncbr, VramPalette *palette, CNCERFile *ncer)
{
    m_system.m_res.ncbr = ncbr;
    m_system.m_res.palette = palette;
    m_system.m_res.ncer = ncer;
}

void CFieldEffectFootStepSmoke::SetPuffRes(VramImage *ncbr, VramPalette *palette, CNCERFile *ncer, CellAnimController *cac)
{
    m_cac = cac;
    for (int i = 0; i < 4; i++) {
        m_sprites[i].SetResources((UnkClass_CPrimitive_ImageProxy *)ncbr, NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)palette, (UnkClass_CSoftwareSprite_38 *)ncer);
        m_sprites[i].m_polygonID = 8;
        if (m_cac != NULL) {
            m_puffs[i].cacId = m_cac->Create(1, 0);
            if (m_puffs[i].cacId != 0) {
                m_cac->SetAnim(m_puffs[i].cacId, 4);
            }
        }
    }
}

void CFieldEffectFootStepSmoke::ReleasePuffs()
{
    if (m_cac == NULL) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (m_puffs[i].cacId != 0) {
            m_cac->Remove(m_puffs[i].cacId);
            m_puffs[i].cacId = 0;
        }
    }
}

void CFieldEffectFootStepSmoke::Emit(int idx, int x, int y, int layer)
{
    switch (idx) {
    case 2:
        m_emitter.Add(0x439C, x, y, 1, layer);
        break;
    case 3:
        m_emitter.Add(0x7FFF, x, y, 1, layer);
        break;
    case 0:
        m_emitter.Add(0x7FFF, x, y, 0, layer);
        break;
    case 1:
        m_emitter.Add(0x7FFF, x, y, 2, layer);
        for (int i = 0; i < 4; i++) {
            if (m_puffs[i].timer == 0) {
                m_puffs[i].timer = 0x18;
                m_puffs[i].layer = layer;
                if (m_cac != NULL) {
                    m_cac->Restart(m_puffs[i].cacId);
                }
                m_sprites[i].m_coords[0] = x;
                m_sprites[i].m_coords[1] = y + 0x8000;
                return;
            }
        }
        break;
    }
}

int CFieldEffectFootStepSmoke::Update(int step)
{
    m_system.Update(step);
    for (int i = 0; i < 4; i++) {
        if (m_puffs[i].timer > 0) {
            m_puffs[i].timer -= step;
            if (m_puffs[i].timer < 0) {
                m_puffs[i].timer = 0;
            }
        }
    }
    return 0;
}

void CFieldEffectFootStepSmoke::AddToRenderLists(DrawObjectList *renderLists)
{
    m_emitter.AddToRenderLists(renderLists);
}

int CFieldEffectFootStepSmoke::Render(Camera2D *camera)
{
    m_system.Draw(camera);
    CFieldEffectManage *mgr = MAIN_BSS_0210CA60;
    for (int i = 0; i < 4; i++) {
        if (m_puffs[i].timer > 0) {
            if (m_cac != NULL) {
                m_sprites[i].m_cellDataIdx = m_cac->GetCell(m_puffs[i].cacId);
            }
            m_sprites[i].m_z = mgr->unk_790[m_puffs[i].layer];
            m_sprites[i].Render(camera);
        }
    }
    return 0;
}

void CFieldEffectFootStepSmoke::CFieldParticleOneShotEmitter::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    Entry *e = &m_entries[m_emitIdx++];
    p->life = 0x18000;
    p->maxLife = 0x18000;
    p->sprite.m_alpha = 0x1F;
    p->sprite.m_color = e->color;
    p->pos = (Point2D) { e->x, e->y };
    p->sprite.m_cellDataIdx = e->kind;
    p->rot = 0;
    if (e->kind == 1) {
        p->rotVel = 0;
    } else {
        p->rotVel = 0xB6;
    }
    e->obj.unk_04 = e->y;
    e->obj.m_particle = p;
}

void CFieldEffectFootStepSmoke::CFieldParticleOneShotEmitter::AddToRenderLists(DrawObjectList *lists)
{
    for (u8 i = 0; i < 8; i++) {
        if (m_entries[i].obj.m_particle != NULL && m_entries[i].obj.m_particle->life != 0) {
            if (m_entries[i].layer >= 0 && m_entries[i].layer < 4) {
                lists[m_entries[i].layer].Insert(&m_entries[i].obj);
            }
        }
    }
}

void CFieldEffectFootStepSmoke::CFieldParticleOneShotEmitter::Add(u16 color, fx32 x, fx32 y, u16 kind, int layer)
{
    if (m_count >= 8) {
        return;
    }
    Entry *e = &m_entries[m_count];
    e->color = color;
    e->x = x;
    e->y = y;
    e->kind = kind;
    e->layer = layer;
    m_count++;
}

int CFieldEffectFootStepSmoke::CDrawObjectParticle::Draw(Camera2D *camera, int budget)
{
    if (m_particle != NULL) {
        m_particle->sprite.m_z = budget;
    }
    return 1;
}

void CFieldEffectFootStepSmoke::CFieldParticleAlphaAnimator::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    u16 kind = p->sprite.m_cellDataIdx;
    fx32 maxLife = p->maxLife;
    fx32 age = maxLife - p->life;
    fx32 scale;
    if (kind == 1) {
        scale = age >> 3;
        if (scale > 0x1000) {
            scale = 0x1000;
        }
    } else {
        scale = FX32_DIV(age, maxLife);
    }
    p->sprite.m_scale[0] = scale;
    p->sprite.m_scale[1] = scale;
    if (kind == 1) {
        p->sprite.m_alpha = FX32_DIV(p->life * 31, maxLife) >> 12;
    }
}
