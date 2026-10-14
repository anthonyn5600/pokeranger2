#include "field/CFieldEffectWaterGun.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "field/CFieldEffectManage.hpp"
#include "fx_utils.hpp"

CFieldEffectWaterGun::CFieldEffectWaterGun(int id)
    : m_system(1, 0x28)
{
    CFieldEffectAttackActorData *data = new CFieldEffectAttackActorData();
    if (data != NULL) {
        data->ov0_0214FFF0(id, 1, 3);
    }
    unk_18 = data;
    for (int i = 0; i < 2; i++) {
        CellAnimController *cac = unk_18->GetCac(sWaterGunCacKinds[i]);
        if (cac != NULL) {
            m_cacIds[i] = cac->Create(1, 0);
        } else {
            m_cacIds[i] = 0xFFFF;
        }
    }
    InitSprites();
    m_start.x = 0;
    m_start.y = 0;
    m_pos.x = 0;
    m_pos.y = 0;
    m_end.x = 0;
    m_end.y = 0;
    m_vel.x = 0;
    m_vel.y = 0;
    m_system.SetEmitter(0, &m_emitter);
    m_system.m_forceField = &m_animator;
    if (data != NULL) {
        m_system.SetRes(FieldEffectSpriteRes(data->GetNcbr(1), data->GetPalette(), data->GetNcer(1)));
    }
    m_animator.Init(data->GetCac(1));
}

CFieldEffectWaterGun::~CFieldEffectWaterGun()
{
    m_animator.Release();
    if (unk_18 != NULL) {
        for (int i = 0; i < 2; i++) {
            unk_18->GetCac(sWaterGunCacKinds[i])->Remove(m_cacIds[i]);
        }
    }
    SAFE_DELETE(unk_18);
}

int CFieldEffectWaterGun::ov0_02142264(int step)
{
    int state = CFieldEffectActor::ov0_02142264(step);
    if (state != 0 && state != 4) {
        m_animator.Reset();
        if (state == 1) {
            m_pos += m_vel;
        } else if (state == 3) {
            m_emitter.m_timer = 0;
        }
        if (unk_18 != NULL) {
            unk_18->Update();
        }
        m_system.Update(step);
    }
    return state;
}

int CFieldEffectWaterGun::ov0_02142344(Camera2D *camera)
{
    int i;
    int state = m_state;
    if (state != 4 && state != 0) {
        m_sprites[0].SetPos(m_start);
        m_sprites[1].SetPos(m_pos);
        m_system.Draw(camera);
        for (i = 0; i < 2; i++) {
            CellAnimController *cac = unk_18->GetCac(sWaterGunCacKinds[i]);
            if (cac != NULL) {
                m_sprites[i].m_cellDataIdx = cac->GetCell(m_cacIds[i]);
            }
            if ((state != 1 || i != 1 || m_frame >= 10) && (i != 0 || state != 3)) {
                m_sprites[i].Render(camera);
            }
        }
    }
    return 0;
}

int CFieldEffectWaterGun::SetParam(int param, int value)
{
    BOOL ret = TRUE;
    switch (param) {
    case 1:
        m_start.x = value << 12;
        m_emitter.m_pos.x = value << 12;
        break;
    case 2:
        m_start.y = value << 12;
        m_emitter.m_pos.y = value << 12;
        break;
    case 9:
        m_end.x = value << 12;
        m_emitter.m_end.x = value << 12;
        break;
    case 10:
        m_end.y = value << 12;
        m_emitter.m_end.y = value << 12;
        break;
    case 14:
        m_emitter.m_speed = (value << 12) / 60;
        break;
    case 13:
        m_emitter.m_interval = value << 12;
        break;
    default:
        ret = FALSE;
        break;
    }
    return ret;
}

BOOL CFieldEffectWaterGun::ov0_021421F0(int inTime, int holdTime, int outTime)
{
    m_pos = m_start;
    Point2D dir = m_end - m_pos;
    fx32 sq = FX32_MUL(dir.x, dir.x) + FX32_MUL(dir.y, dir.y);
    if (sq != 0 && m_emitter.m_speed != 0) {
        fx32 time = FX32_DIV(FX_Sqrt(sq), m_emitter.m_speed);
        Point2D vel = dir / time;
        inTime = (time + 0xFFF) >> 12;
        m_vel = vel;
    } else {
        inTime = 0;
        m_vel.x = 0;
        m_vel.y = 0;
    }
    u16 angle = FX_Atan2Idx(dir.y, dir.x);
    for (int i = 0; i < 2; i++) {
        m_sprites[i].m_rotAngle = angle;
    }
    m_emitter.m_angle = angle;
    m_emitter.SetDir(dir);
    m_emitter.func2();
    return CFieldEffect::ov0_021421F0(inTime, holdTime, outTime);
}

void CFieldEffectWaterGun::CEmitter::func2()
{
    m_timer = 0x1000;
}

void CFieldEffectWaterGun::InitSprites()
{
    for (int i = 0; i < 2; i++) {
        int kind = i == 0 ? 0 : 2;
        m_sprites[i].SetResources((UnkClass_CPrimitive_ImageProxy *)unk_18->GetNcbr(kind), NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)unk_18->GetPalette(), (UnkClass_CSoftwareSprite_38 *)unk_18->GetNcer(kind));
        m_sprites[i].m_cellDataIdx = 0;
        m_sprites[i].m_polygonID = i + 8;
        m_sprites[i].m_z = 0x640;
    }
}

void CFieldEffectWaterGun::CEmitter::SetDir(const Point2D &dir)
{
    int ax = dir.x >= 0 ? dir.x : -dir.x;
    int ay = dir.y >= 0 ? dir.y : -dir.y;
    if (ax >= ay) {
        m_life = FX32_DIV(dir.x, FX32_MUL(m_speed, FX_CosIdx(m_angle)));
    } else {
        m_life = FX32_DIV(dir.y, FX32_MUL(m_speed, FX_SinIdx(m_angle)));
    }
}

u32 CFieldEffectWaterGun::CEmitter::Update(int dt)
{
    u32 count = 0;
    if (m_timer > 0) {
        m_timer -= dt;
        if (m_timer <= 0) {
            count = 1;
            if (m_interval > 0) {
                m_timer = m_interval;
            }
        }
    }
    return count;
}

void CFieldEffectWaterGun::CEmitter::Emit(TFieldParticle<CSoftwareSprite> *p)
{
    int idx = (m_angle >> 4) * 2;
    p->pos = (Point2D) { m_pos.x, m_pos.y };
    fx32 speed = m_speed;
    p->vel.x = FX32_MUL(speed, FX_SinCosTable_[idx + 1]);
    p->vel.y = FX32_MUL(speed, FX_SinCosTable_[idx]);
    p->maxLife = p->life = m_life;
    p->rot = m_angle;
    p->animIdx = MATH_Rand32(&CGame::GetInstance()->m_rand32, 16);
}

CFieldEffectWaterGun::CAnimator::CAnimator()
{
    m_cac = NULL;
    MI_CpuFill8(m_ids, 0, sizeof(m_ids));
}

void CFieldEffectWaterGun::CAnimator::Init(CellAnimController *cac)
{
    m_cac = cac;
    if (cac != NULL) {
        for (int i = 0; i < 16; i++) {
            m_ids[i] = cac->Create(1, 0);
            cac->UpdateAll();
        }
    }
}

void CFieldEffectWaterGun::CAnimator::Release()
{
    if (m_cac != NULL) {
        for (int i = 0; i < 16; i++) {
            if (m_ids[i] != 0) {
                m_cac->Remove(m_ids[i]);
                m_ids[i] = 0;
            }
        }
    }
}

void CFieldEffectWaterGun::CAnimator::Reset()
{
    m_count = 0;
}

void CFieldEffectWaterGun::CAnimator::Apply(TFieldParticle<CSoftwareSprite> *p, int dt)
{
    if (p->animIdx >= 0 && p->animIdx < 16) {
        p->sprite.m_cellDataIdx = m_cac->GetCell(m_ids[p->animIdx]);
    }
    int age = p->maxLife - p->life;
    int alpha;
    if (age >= 0xA000) {
        alpha = 0x1F;
    } else {
        alpha = FX32_DIV(FX32_MUL(age, 0x1F000), 0xA000) >> 12;
    }
    p->sprite.m_alpha = alpha;
    p->sprite.m_z = 0x636 - (m_count & 3) * 10;
    m_count++;
}

CFieldEffect *CFieldEffectWaterGunFactory::Create(int arg)
{
    return new CFieldEffectWaterGun(arg);
}
