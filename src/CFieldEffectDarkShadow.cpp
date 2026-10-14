#include "field/CFieldEffectDarkShadow.hpp"

#include <nitro.h>

#include "CGame.hpp"
#include "FieldShadow.hpp"
#include "field/CFieldActor.hpp"
#include "field/CFieldEffectManage.hpp"
#include "scene/CFieldScene.hpp"

extern CFieldScene *MAIN_BSS_0210CA40;

CFieldEffectDarkShadow::CFieldEffectDarkShadow(int mode)
    : m_layer(0)
    , m_rotSpeed(1)
{
    m_rect.SetTexCoords(0, 0, 0x40000, 0x20000);
    m_rect.SetSize(0x40000, 0x20000);
    m_rect.m_z = -1;
    switch (mode) {
    case 0:
        m_count = 16;
        break;
    case 1:
        m_count = 32;
        break;
    case 2:
        m_count = 16;
        break;
    }
    for (int i = 0; i < 32; i++) {
        m_sprites[i].m_cellDataIdx = 6;
        m_sprites[i].m_z = -1;
        m_sprites[i].m_color = 0;
        if (mode == 2) {
            m_sprites[i].SetScale(0x1800, 0x1800);
        }
        CGame *game = CGame::GetInstance();
        MATHRandContext16 *rand = &game->m_rand16;
        m_rotSpeeds[i] = MATH_Rand16(rand, 0xE38) - 0x71C;
    }
    m_scale.x = m_scale.y = FX32_ONE;
}

CFieldEffectDarkShadow::~CFieldEffectDarkShadow()
{
}

static inline void SetRingX(CFieldEffectDarkShadow *e, fx32 x)
{
    e->m_rect.m_rectangle.pos.x = x;
    int i;
    int angle = 0;
    for (i = 0; i < e->m_count; i++) {
        e->m_sprites[i].m_coords[0] = (0x28 - ((e->m_sprites[i].m_scale[0] * 8) >> FX32_SHIFT)) * FX_CosIdx(angle) + x;
        angle += 0x10000 / e->m_count;
    }
}

static inline void SetRingY(CFieldEffectDarkShadow *e, fx32 y)
{
    e->m_rect.m_rectangle.pos.y = y;
    int i;
    int angle = 0;
    for (i = 0; i < e->m_count; i++) {
        e->m_sprites[i].m_coords[1] = (0x18 - ((e->m_sprites[i].m_scale[1] * 8) >> FX32_SHIFT)) * FX_SinIdx(angle) + y;
        angle += 0x10000 / e->m_count;
    }
}

int CFieldEffectDarkShadow::SetParam(int param, int value)
{
    int ret = 1;
    switch (param) {
    case 1:
        SetRingX(this, value << FX32_SHIFT);
        break;
    case 2:
        SetRingY(this, value << FX32_SHIFT);
        break;
    case 3:
        m_rect.m_rectangle.size.x = value << FX32_SHIFT;
        break;
    case 4:
        m_rect.m_rectangle.size.y = value << FX32_SHIFT;
        break;
    case 17:
        if (MAIN_BSS_0210CA40 != NULL) {
            CFieldActor *actor = MAIN_BSS_0210CA40->ov0_02123060(value);
            if (actor != NULL) {
                m_layer = actor->unk_14;
            }
        }
        break;
    case 20:
        m_rotSpeed = value;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

int CFieldEffectDarkShadow::ov0_02142264(int step)
{
    if (m_scaleMover.Update(step)) {
        const Point2D &cur = m_scaleMover.cur;
        m_scale.x = cur.x;
        m_scale.y = cur.y;
    }
    if (m_posMover.Update(step)) {
        {
            int angle = 0;
            int i;
            m_rect.m_rectangle.pos.x = m_posMover.cur.x;
            for (i = 0; i < m_count; i++) {
                m_sprites[i].m_coords[0] = (0x28 - ((m_sprites[i].m_scale[0] * 8) >> FX32_SHIFT)) * FX_CosIdx(angle) + m_posMover.cur.x;
                angle += 0x10000 / m_count;
            }
        }
        {
            int angle = 0;
            int i;
            m_rect.m_rectangle.pos.y = m_posMover.cur.y;
            for (i = 0; i < m_count; i++) {
                m_sprites[i].m_coords[1] = (0x18 - ((m_sprites[i].m_scale[1] * 8) >> FX32_SHIFT)) * FX_SinIdx(angle) + m_posMover.cur.y;
                angle += 0x10000 / m_count;
            }
        }
    }
    int state = CFieldEffect::ov0_02142264(step);
    for (int i = 0; i < m_count; i++) {
        int d = m_rotSpeed * m_rotSpeeds[i];
        m_sprites[i].m_rotAngle = d + m_sprites[i].m_rotAngle;
    }
    return state;
}

int CFieldEffectDarkShadow::ov0_02142344(Camera2D *camera)
{
    if (m_state != 0 && m_state != 4) {
        int angle;
        int i;
        int z = MAIN_BSS_0210CA60->unk_790[m_layer];
        m_rect.m_z = z;
        if (m_scale.x != FX32_ONE || m_scale.y != FX32_ONE) {
            m_rect.m_rectangle.size.x = FX32_MUL(m_scale.x, 0x40000);
            m_rect.m_rectangle.size.y = FX32_MUL(m_scale.y, 0x20000);
            angle = 0;
            fx32 t = m_scale.x - FX32_ONE;
            if (t < 0) {
                t = 0;
            } else if (t > FX32_ONE) {
                t = FX32_ONE;
            }
            m_count = ((t * 16) >> FX32_SHIFT) + 16;
            for (i = 0; i < m_count; i++) {
                int scale = FX32_MUL(t, 0x800) + 0x1800;
                m_sprites[i].SetScale(scale, scale);
                m_sprites[i].m_coords[0] = m_rect.m_rectangle.pos.x
                    + FX32_MUL((m_scale.x << 3) + (m_rect.m_rectangle.size.x >> 1) - m_sprites[i].m_scale[0] * 8, FX_CosIdx(angle));
                m_sprites[i].m_coords[1] = m_rect.m_rectangle.pos.y
                    + FX32_MUL((m_scale.y << 3) + (m_rect.m_rectangle.size.y >> 1) - m_sprites[i].m_scale[1] * 8, FX_SinIdx(angle));
                angle += 0x10000 / m_count;
            }
        }
        m_rect.Render(camera);
        for (int i = 0; i < m_count; i++) {
            m_sprites[i].m_z = z;
            m_sprites[i].Render(camera);
        }
    }
    return 0;
}

int CFieldEffectDarkShadow::ov0_0214239C(int layer)
{
    return 1;
}

void CFieldEffectDarkShadow::sub_02033388(const Point2D &pos, int arg1)
{
    m_scaleMover.Start(m_scale, pos, arg1);
    if (arg1 == 0) {
        m_scale.x = pos.x;
        m_scale.y = pos.y;
    }
}

void CFieldEffectDarkShadow::sub_0203331C(const Point2D &pos, int arg1)
{
    Point2D cur;
    CPrimitiveRECT::sub_02003C00(&cur, &m_rect);
    m_posMover.Start(cur, pos, arg1);
}

static inline void SetRectImage(CPrimitiveRECT *rect, VramImage *image, VramPalette *palette)
{
    rect->unk_38 = (UnkClass_CPrimitive_ImageProxy *)image;
    rect->unk_3C = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
}

CFieldEffect *CFieldEffectDarkShadowFactory::Create(int arg)
{
    CFieldEffectDarkShadow *effect = new CFieldEffectDarkShadow(arg);
    if (effect != NULL) {
        if (MAIN_BSS_0210CA40 != NULL) {
            FieldShadow *shadow = MAIN_BSS_0210CA40->unk_0048;
            SetRectImage(&effect->m_rect, shadow->unk_00, shadow->unk_04);
        }
        CFieldEffectManage *mgr = MAIN_BSS_0210CA60;
        if (mgr != NULL) {
            CNCERFile *ncer = mgr->m_resident.GetNcer(0);
            VramPalette *palette = mgr->m_resident.GetPalette();
            VramImage *ncbr = mgr->m_resident.GetNcbr(0);
            for (int i = 0; i < 32; i++) {
                effect->m_sprites[i].SetResources((UnkClass_CPrimitive_ImageProxy *)ncbr, NULL, (UnkClass_CPrimitive_ImagePaletteProxy *)palette, (UnkClass_CSoftwareSprite_38 *)ncer);
            }
        }
    }
    return effect;
}
