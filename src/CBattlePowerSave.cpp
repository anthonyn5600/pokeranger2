#include "battle/CBattlePowerSave.hpp"

#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "UnkClass_02008788.hpp"
#include "UnkClass_02034478.hpp"
#include "battle/UnkClass_02136730.hpp"
#include "battle/UnkClass_02136AD4.hpp"
#include "fx_utils.hpp"
#include "interpolation.hpp"

struct PowerStreakKey {
    fx32 m_start;
    fx32 m_end;
    u8 m_alpha;
};

static const fx32 sChargeRates[] = { 0x28, 0x22 };
static const char *sResNames[] = { "PSE", "PSS" };
static const char *sResSuffixes[] = { "00", "02" };
static const fx32 sLevelScales[] = { 0x1000, 0x2000, 0x3000 };
static const PowerStreakKey sStreakKeys[] = {
    { 0x1000, 0x1000, 1 },
    { 0x1014, 0x1014, 2 },
    { 0x1028, 0x1028, 3 },
    { 0x103D, 0x103D, 4 },
    { 0x1051, 0x1051, 5 },
    { 0x1066, 0x1066, 6 },
    { 0x107A, 0x107A, 7 },
    { 0x108F, 0x108F, 8 },
    { 0x10A3, 0x10A3, 9 },
    { 0x10B8, 0x10B8, 10 },
    { 0x10CC, 0x10CC, 11 },
    { 0x10E1, 0x10E1, 12 },
    { 0x10F5, 0x10F5, 13 },
    { 0x110A, 0x110A, 14 },
    { 0x111E, 0x111E, 15 },
    { 0x1133, 0x1133, 16 },
    { 0x1137, 0x1137, 17 },
    { 0x113B, 0x113B, 18 },
    { 0x113F, 0x113F, 19 },
    { 0x1143, 0x1143, 20 },
    { 0x1147, 0x1147, 21 },
    { 0x1147, 0x1147, 22 },
    { 0x1147, 0x1147, 23 },
    { 0x1147, 0x1147, 24 },
    { 0x1147, 0x1147, 24 },
    { 0x1147, 0x1147, 24 },
    { 0x1000, 0x1000, 24 },
    { 0xE66, 0x1000, 24 },
    { 0xCCC, 0xE66, 24 },
    { 0xB33, 0xCCC, 24 },
    { 0x999, 0xB33, 24 },
    { 0x800, 0x999, 24 },
    { 0x733, 0x800, 24 },
    { 0x666, 0x733, 24 },
    { 0x599, 0x666, 24 },
    { 0x4CC, 0x599, 24 },
    { 0x400, 0x4CC, 24 },
    { 0x333, 0x400, 20 },
    { 0x266, 0x333, 16 },
    { 0x199, 0x266, 12 },
    { 0xCC, 0x199, 8 },
    { 0, 0xCC, 4 },
};

static inline void AddRandomAngle(u16 *angle, s16 rnd)
{
    *angle += (s16)(rnd - 7000);
}

static inline void SetSpriteRes(CSoftwareSprite *sprite, UnkClass_020074D4 *image, UnkClass_02007AA4 *palette, CNCERFile *cells)
{
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)cells;
}

CBattlePowerSave::CBattlePowerSave()
{
    m_audio = CGame::GetInstance()->m_audioEngine;
    ov1_021371C4();
    ov1_02136E08();
    for (int i = 0; i < 20; i++) {
        m_particles[i] = new UnkClass_02136730();
    }
    m_pool = new UnkClass_02136AD4(m_particles, 20);
    m_pool->ov1_02136BD0(1);
    m_maxLevel = 2;
    m_chargeTimes[0] = 100;
    m_chargeTimes[1] = 120;
    m_streakNext = 0;
    for (u8 i = 0; i < 0x30; i++) {
        m_streaks[i].m_active = 0;
        m_streaks[i].m_line.m_color = 0x13FF;
        m_streaks[i].m_line.m_polygonID = 1;
    }
}

CBattlePowerSave::~CBattlePowerSave()
{
    ov1_02136FB8();
}

void CBattlePowerSave::ov1_02136E08()
{
    char arcPath[0x60];
    char ncbr[0x60];
    char nclr[0x60];
    char ncer[0x60];
    char cac[0x60];
    for (int i = 0; i < 2; i++) {
        OS_SPrintf(arcPath, "data/interface/i025_LZ.bin");
        OS_SPrintf(ncbr, "%s:i025_%s.NCBR", sResNames[i], sResSuffixes[i]);
        OS_SPrintf(nclr, "%s:i025.NCLR", sResNames[i]);
        OS_SPrintf(ncer, "%s:i025_%s.NCER", sResNames[i], sResSuffixes[i]);
        OS_SPrintf(cac, "%s:i025_%s.cac", sResNames[i], sResSuffixes[i]);
        UnkClass_0201AAE0 *res = new UnkClass_0201AAE0(sResNames[i], arcPath, ncbr, nclr, ncer, cac);
        m_res[i] = res;
        m_anim[i] = res->m_anim->sub_02008A80(1, 0);
    }
    m_burstRes = new UnkClass_0201AAE0("BLD", "data/interface/i066_LZ.bin", "BLD:i066_00.NCBR", "BLD:i066.NCLR", "BLD:i066_00.NCER", "BLD:i066_00.cac");
    SetSpriteRes(&m_burst, m_burstRes->m_image, m_burstRes->m_palette, m_burstRes->m_cells);
    m_burst.m_cellDataIdx = 1;
    m_burst.m_z = 0x3FF;
    SetSpriteRes(&m_burstFx, m_burstRes->m_image, m_burstRes->m_palette, m_burstRes->m_cells);
    m_burstFx.m_z = 0x3FF;
    m_burstAnim = m_burstRes->m_anim->sub_02008A80(1, 0);
}

void CBattlePowerSave::ov1_02136FB8()
{
    for (int i = 0; i < 20; i++) {
        SAFE_DELETE(m_particles[i]);
    }
    SAFE_DELETE(m_pool);
    for (int i = 0; i < 2; i++) {
        SAFE_DELETE(m_res[i]);
    }
    SAFE_DELETE(m_burstRes);
}

void CBattlePowerSave::ov1_02137094(Point2D pos)
{
    if (m_flags & 1) {
        if (!ov1_021374FC(pos)) {
            m_flags &= ~3;
            m_holdTimer = 0;
            m_chargeTimer = 0;
        }
    } else {
        m_flags |= 1;
        m_touchStart = pos;
        m_audio->sub_02034C5C(0x32);
        m_flags &= ~0x10;
    }
    m_motion.sub_02011D3C(pos);
    m_center = pos;
}

void CBattlePowerSave::ov1_02137144()
{
    m_flags &= ~3;
    m_holdTimer = 0;
    ov1_021371F0();
    m_audio->sub_02034C5C(0x32);
    m_flags &= ~0x10;
    m_flags &= ~0x20;
}

void CBattlePowerSave::ov1_02137194()
{
    m_res[1]->m_anim->sub_020089B8(m_anim[1]);
    m_flags |= 4;
}

void CBattlePowerSave::ov1_021371C4()
{
    m_flags = 0;
    m_tick = 0;
    m_chargeTimer = 0;
    m_level = 0;
    m_holdTimer = 0;
    m_alpha = 0xF;
    m_ratio = 0;
}

void CBattlePowerSave::ov1_021371F0()
{
    m_flashTimer = 0;
    m_level = 0;
    m_chargeTimer = 0;
}

void CBattlePowerSave::ov1_0213720C()
{
    CGame *game = CGame::GetInstance();
    Point2D pos = m_center;
    MATHRandContext16 *rand16 = &game->m_rand16;
    MATHRandContext32 *rand32 = &game->m_rand32;
    u16 angle = 0xC000;
    AddRandomAngle(&angle, MATH_Rand16(rand16, 14000));
    fx32 radius = MATH_Rand32(rand32, 0x10000) + 0x18000;
    fx32 dx = FX32_MUL(radius, FX_CosIdx(angle));
    fx32 dy = FX32_MUL(radius, FX_SinIdx(angle));
    UnkClass_02136730 *particle = m_pool->ov1_02136B24(0x14, pos.x + dx, pos.y + dy, 0, 0x3000, 0x13FF);
    particle->ov1_02136A40(FX32_MUL(FX_CosIdx(angle), -0x1333), 0x1000);
    particle->ov1_02136A58(FX32_MUL(FX_SinIdx(angle), -0x1333), 0x1000);
    particle->ov1_02136A88(0xC, 0x1F);
    particle->ov1_02136AA0(0x1000, 4);
}

void CBattlePowerSave::ov1_021373FC()
{
    CGame *game = CGame::GetInstance();
    PowerStreak *streak = &m_streaks[m_streakNext];
    streak->m_active = 1;
    streak->m_frame = 0;
    MATHRandContext16 *rand16 = &game->m_rand16;
    s16 rnd = MATH_Rand16(rand16, 14000);
    streak->m_angle = 0xC000;
    streak->m_angle += (s16)(rnd - 7000);
    MATHRandContext32 *rand32 = &game->m_rand32;
    streak->m_dist = 0x20000;
    streak->m_dist += MATH_Rand32(rand32, 0x18000);
    m_streakNext++;
    if (m_streakNext >= 0x30) {
        m_streakNext = 0;
    }
}

BOOL CBattlePowerSave::ov1_021374FC(Point2D pos)
{
    fx64 dx = m_touchStart.x - pos.x;
    fx64 dy = m_touchStart.y - pos.y;
    return FX32_POW2(dx) + FX32_POW2(dy) <= FX32_POW2(0x8000);
}

void CBattlePowerSave::vfunc_08()
{
    if (m_flags & 1) {
        if (m_holdTimer == 30) {
            m_flags |= 2;
        } else {
            m_holdTimer++;
        }
    }
    if ((m_flags & 2) && !(m_flags & 4) && !(m_flags & 8)) {
        if (m_level < m_maxLevel) {
            if (m_chargeTimer == m_chargeTimes[m_level]) {
                m_level++;
                m_chargeTimer = 0;
                ov1_02137194();
                m_audio->sub_02034C5C(0x32);
                m_audio->sub_02034C44(0x33);
                m_flags &= ~0x10;
                ov1_02137D44(m_level);
            } else {
                m_chargeTimer++;
                if (!(m_flags & 0x10)) {
                    m_audio->sub_02034C44(0x32);
                    m_flags |= 0x10;
                }
            }
        }
        m_tick++;
    }
    if (m_flags & 8) {
        if (m_flashTimer == 0x18) {
            m_flashTimer = 0;
            m_flags &= ~8;
        } else {
            m_flashTimer++;
        }
    }
    fx32 t = FX32_MUL(m_chargeTimer << FX32_SHIFT, sChargeRates[m_level]);
    m_ratio = FX32_ONE - t;
    m_alpha = (0x1F000 - FX32_MUL(t, 0xF000)) >> FX32_SHIFT;
    unk_198 = m_motion.GetPos();
    if ((m_flags & 2) && m_level < m_maxLevel && (m_tick & 1)) {
        ov1_0213720C();
    }
    m_pool->ov1_02136AEC();
    m_res[0]->m_anim->sub_020089EC();
    if (m_flags & 4) {
        UnkClass_02008788 *anim = m_res[1]->m_anim;
        if (!anim->sub_02008860(m_anim[1])) {
            m_flags |= 8;
            m_flags &= ~4;
        } else {
            anim->sub_020089EC();
        }
    }
    if (m_flags & 0x20) {
        m_burstFrame++;
        switch (m_burstState) {
        case 1: {
            fx32 scale = LinearInterpolate(0x2000, 0xCCC, m_burstFrame, 8);
            m_burst.SetScale(scale, scale);
            m_burstFx.m_alpha = 1;
            if (m_burstFrame >= 8) {
                m_burstRes->m_anim->sub_020089B8(m_burstAnim);
                m_burstState = 2;
                m_burstFrame = 0;
            }
            break;
        }
        case 2:
            m_burst.SetScale(0x1000, 0x1000);
            m_burstRes->m_anim->sub_02008A38(m_burstAnim);
            m_burstFx.m_alpha = 0x1F;
            if (!m_burstRes->m_anim->sub_02008860(m_burstAnim)) {
                if (m_burstCount != 0) {
                    m_burstCount--;
                    m_burstRes->m_anim->sub_020089B8(m_burstAnim);
                } else {
                    m_burstState = 3;
                    m_burstFrame = 0;
                }
            }
            break;
        case 3: {
            fx32 scale = LinearInterpolate(0x1666, 0x800, m_burstFrame, 8);
            m_burst.SetScale(0x1000, scale);
            m_burstFx.m_alpha = 1;
            if (m_burstFrame >= 8) {
                m_burstState = 0;
                m_burstFrame = 0;
                m_flags &= ~0x20;
            }
            break;
        }
        }
    }
    if (!(m_flags & 2) || m_level >= m_maxLevel) {
        return;
    }
    if (m_tick & 1) {
        ov1_021373FC();
    }
    for (u8 i = 0; i < 0x30; i++) {
        PowerStreak *streak = &m_streaks[i];
        if (!streak->m_active) {
            continue;
        }
        Point2D pos = m_center;
        fx32 d = FX32_MUL(streak->m_dist, sStreakKeys[streak->m_frame].m_start);
        pos.x += FX32_MUL(d, FX_CosIdx(streak->m_angle));
        pos.y += FX32_MUL(d, FX_SinIdx(streak->m_angle));
        streak->m_line.SetStart(pos);
        pos = m_center;
        d = FX32_MUL(streak->m_dist, sStreakKeys[streak->m_frame].m_end);
        pos.x += FX32_MUL(d, FX_CosIdx(streak->m_angle));
        pos.y += FX32_MUL(d, FX_SinIdx(streak->m_angle));
        streak->m_line.SetEnd(pos);
        streak->m_line.m_alpha = sStreakKeys[streak->m_frame].m_alpha;
        streak->m_frame++;
        if (streak->m_frame >= 0x2A) {
            streak->m_active = 0;
        }
    }
}

BOOL CBattlePowerSave::ov1_02137ABC()
{
    return (m_flags & 2) != 0;
}

u16 CBattlePowerSave::ov1_02137AD4()
{
    return m_level;
}

fx32 CBattlePowerSave::ov1_02137ADC()
{
    return sLevelScales[m_level];
}

void CBattlePowerSave::vfunc_0C(Camera2D *camera)
{
    if (ov1_02137ABC() && !(m_flags & 4) && !(m_flags & 8)) {
        ov1_02137B94(camera);
        m_pool->ov1_02136B88(camera);
    }
    if (m_flags & 4) {
        ov1_02137B98(camera);
    }
    ov1_02137C3C(camera);
    if ((m_flags & 2) && m_level < m_maxLevel) {
        ov1_02137CF0(camera);
    }
}

void CBattlePowerSave::vfunc_10(Camera2D *camera)
{
}

void CBattlePowerSave::ov1_02137B94(Camera2D *camera)
{
}

void CBattlePowerSave::ov1_02137B98(Camera2D *camera)
{
    CSoftwareSprite *sprite = m_sprite;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)m_res[1]->m_image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)m_res[1]->m_palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)m_res[1]->m_cells;
    sprite->m_cellDataIdx = m_res[1]->m_anim->sub_02008828(m_anim[1]);
    sprite->SetPos(m_motion.GetPos());
    sprite->SetScale(0x1800, 0x1000);
    sprite->m_alpha = 0x1F;
    sprite->Render(camera);
}

void CBattlePowerSave::ov1_02137C3C(Camera2D *camera)
{
    if (!(m_flags & 0x20)) {
        return;
    }
    Point2D pos = m_motion.GetPos();
    pos.y -= 0x20000;
    m_burstFx.m_cellDataIdx = m_burstRes->m_anim->sub_02008828(m_burstAnim);
    m_burstFx.SetPos(pos);
    m_burstFx.Render(camera);
    m_burst.SetPos(pos);
    m_burst.Render(camera);
}

void CBattlePowerSave::ov1_02137CF0(Camera2D *camera)
{
    for (u8 i = 0; i < 0x30; i++) {
        if (m_streaks[i].m_active) {
            m_streaks[i].m_line.Render(camera);
        }
    }
}

void CBattlePowerSave::ov1_02137D44(u8 level)
{
    if (level == 0) {
        return;
    }
    m_burstState = 1;
    m_burstFrame = 0;
    m_burstCount = level - 1;
    m_flags |= 0x20;
}

int CBattlePowerSave::ov1_02137D7C(int z)
{
    CSoftwareSprite *sprite = m_sprite;
    z += sprite->GetCellNumOAMAttrs(sprite->m_cellDataIdx);
    sprite->m_z = z;
    return z + 1;
}
