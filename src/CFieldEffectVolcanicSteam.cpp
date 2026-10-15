#include "field/CFieldEffectVolcanicSteam.hpp"

#include <nitro.h>

#include "file/CArchiveGuard.hpp"
#include "fx_utils.hpp"

CFieldEffectVolcanicSteam::CFieldEffectVolcanicSteam()
    : TFieldEffectSmoke<CSimpleSpriteNTF>(3)
{
    m_emitter.m_vel.x = 0;
    m_emitter.m_vel.y = -0xAAA;
}

CFieldEffectVolcanicSteam::~CFieldEffectVolcanicSteam()
{
}

void CFieldEffectVolcanicSteam::ov0_02142398(DrawObjectList *renderLists)
{
    m_animator.Register(renderLists);
}

int CFieldEffectVolcanicSteam::SetParam(int param, int value)
{
    if (param == 2) {
        m_animator.m_drawObj.unk_04 = value << 12;
    }
    return TFieldEffectSmoke<CSimpleSpriteNTF>::SetParam(param, value);
}

int CFieldEffectVolcanicSteam::ov0_02142344(Camera2D *camera)
{
    m_animator.m_drawObj.m_system = m_system;
    if (m_system != NULL) {
        m_system->Draw(camera);
    }
    return 0;
}

void CFieldEffectVolcanicSteam::CAnimator::Register(DrawObjectList *renderLists)
{
    renderLists->Insert(&m_drawObj);
}

int CFieldEffectVolcanicSteam::CAnimator::CEffectDrawObject::Draw(Camera2D *camera, int budget)
{
    m_depth = budget;
    if (m_system != NULL) {
        m_system->m_depth = m_depth;
    }
    return 1;
}

void CFieldEffectVolcanicSteam::CAnimator::Apply(TFieldParticle<CSimpleSpriteNTF> *p, int dt)
{
    p->sprite.SetTexCoords(0, 0, 0x20000, 0x20000);
    p->sprite.unk_4C = 0x20000;
    p->sprite.unk_50 = 0x20000;
    fx32 age = p->maxLife - p->life;
    fx32 maxLife = p->maxLife;
    fx32 scale = FX32_DIV(FX32_MUL(age, 0x14CD), maxLife) + 0xB33;
    scale = FX32_MUL(scale, 0x800);
    p->sprite.m_scale[0] = scale;
    p->sprite.m_scale[1] = scale;
    fx32 alpha;
    if (age < 0x1E000) {
        alpha = FX32_DIV(age * 31, 0x1E000);
    } else {
        alpha = FX32_DIV(p->life * 31, maxLife - 0x1E000);
    }
    p->sprite.m_alpha = alpha >> 12;
}

CFieldEffectVolcanicSteamFactory::~CFieldEffectVolcanicSteamFactory()
{
    Release();
}

void CFieldEffectVolcanicSteamFactory::Reset()
{
    Release();
}

BOOL CFieldEffectVolcanicSteamFactory::Load()
{
    CArchiveGuard guard("MEF", "data/Field/Effect/ef102_LZ.bin", 1, 1, 0, NULL, 0);
    m_tex.Load("MEF:ef102_00.ntft", "MEF:ef102_00.ntfp", 0);
    m_tex.unk_20 = 2;
    m_tex.unk_24 = 2;
    m_tex.unk_1C = 6;
    return FALSE;
}

void CFieldEffectVolcanicSteamFactory::Release()
{
    m_tex.Release();
}

CFieldEffect *CFieldEffectVolcanicSteamFactory::Create(int arg)
{
    CFieldEffectVolcanicSteam *effect = new CFieldEffectVolcanicSteam();
    if (effect != NULL) {
        NtfTextureParam *texture = (NtfTextureParam *)&m_tex;
        effect->ov0_021423E8(texture);
    }
    return effect;
}
