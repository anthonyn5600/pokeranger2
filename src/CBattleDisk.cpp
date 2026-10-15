#include "battle/CBattleDisk.hpp"

#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "CellAnimController.hpp"
#include "SaveData.hpp"
#include "battle/BattleDamageNumber.hpp"
#include "battle/BattleDamageNumberGfx.hpp"
#include "battle/BattleDiskRing.hpp"
#include "battle/BattleHPNumber.hpp"
#include "battle/BattleHitEffect.hpp"
#include "battle/BattleHitEffectGfx.hpp"
#include "battle/BattleParticle.hpp"
#include "battle/BattleParticlePool.hpp"
#include "battle/CBattlePowerSave.hpp"
#include "battle/CDiskCursor.hpp"
#include "battle/CLineEffect.hpp"
#include "battle/StylerLine.hpp"
#include "fx_utils.hpp"
#include "interpolation.hpp"
#include "primitive/CSoftwareSprite.hpp"

extern "C" fx32 GetAssistTypeRate(int assistType, int type);

static const fx32 sLineEffectArg0[7] = { 0x4000, 0x4000, 0x4000, 0x3000, 0x3000, 0x2000, 0x2000 };
static const fx32 sLineEffectArg1[7] = { 0x800, 0x733, 0x666, 0x599, 0x4CC, 0x333, 0x199 };

static inline PointPair2D GetLinePoints(CPrimitiveLINE *line)
{
    return line->m_points;
}

static const char *sDiskArcs[] = { "DP1", "DP2" };
static const char *sDiskNums[] = { "00", "01" };

CBattleDisk::CBattleDisk(BattleParticlePool *particles)
{
    Load();
    unk_1B8 = new StylerLine();
    unk_1BC = new BattleHPNumber();
    unk_1C0 = new CBattlePowerSave();
    unk_228 = new CSoftwareSprite();
    unk_234 = new CSoftwareSprite();
    unk_248 = new CDiskCursor();
    unk_24C = new CLineEffect[7];
    unk_258 = new BattleHitEffectGfx();
    unk_254 = new BattleHitEffect();
    unk_254->SetData(unk_258);
    unk_260 = new BattleDamageNumberGfx();
    unk_25C = new BattleDamageNumber();
    unk_25C->SetData(unk_260);
    unk_25C->SetZ(0x401);

    CActor *leader = this;
    for (int i = 0; i < 7; i++) {
        unk_24C[i].Setup(sLineEffectArg0[i], sLineEffectArg1[i], leader);
        leader = &unk_24C[i];
    }

    unk_198 = 0;
    unk_19A = 0;
    unk_194 = 0x20;
    unk_1B8->Reset(0, 0);

    unk_1C4.m_color = 0x1F;
    unk_1C4.m_z = 0x401;
    unk_1C4.m_alpha = 0x10;
    unk_1C4.m_circle.r = 0x8000;
    unk_1C4.m_polygonID = 0x3E;
    unk_1C4.m_circle.pos = m_motion.GetPos();

    unk_1E8.m_color = 0x1F;
    unk_1E8.m_z = 0x400;
    unk_1E8.m_alpha = 0;
    unk_1E8.m_rectangle.size.x = 0x18000;
    unk_1E8.m_rectangle.size.y = 0x18000;
    unk_1E8.m_polygonID = 0x3F;
    unk_1E8.m_rectangle.pos = m_motion.GetPos();

    unk_250 = particles;
    InitTypeGuards();
    unk_18C = 0;
    unk_242[0] = 0x319F;
    unk_242[1] = 0x7D8C;
    unk_242[2] = 0x33FF;
    unk_184 = 0;
    unk_185 = 0;
    unk_186 = 0;
    unk_188 = 0;
}

CBattleDisk::~CBattleDisk()
{
    Release();
}

void CBattleDisk::Load()
{
    char path[96];
    char ncbr[96];
    char nclr[96];
    char ncer[96];
    char cac[96];

    unk_22C = new GraphicsSet("BDS", "/data/interface/i019_LZ.bin", "BDS:i019_00.NCBR", "BDS:i019.NCLR", "BDS:i019_00.NCER", "BDS:i019_00.cac");
    unk_230 = unk_22C->m_anim->Create(1, 0);

    OS_SPrintf(path, "data/interface/i019_LZ.bin");
    for (int i = 0; i < 2; i++) {
        OS_SPrintf(ncbr, "%s:i019_%s.NCBR", sDiskArcs[i], sDiskNums[i]);
        OS_SPrintf(nclr, "%s:i019.NCLR", sDiskArcs[i]);
        OS_SPrintf(ncer, "%s:i019_%s.NCER", sDiskArcs[i], sDiskNums[i]);
        OS_SPrintf(cac, "%s:i019_%s.cac", sDiskArcs[i], sDiskNums[i]);
        unk_238[i] = new GraphicsSet(sDiskArcs[i], path, ncbr, nclr, ncer, cac);
    }
    unk_240 = unk_238[0]->m_anim->Create(1, 0);

    unk_264 = new BattleDiskRing();
}

void CBattleDisk::Release()
{
    for (int i = 0; i < 2; i++) {
        SAFE_DELETE(unk_238[i]);
    }
    SAFE_DELETE(unk_228);
    SAFE_DELETE(unk_234);
    SAFE_DELETE(unk_1C0);
    SAFE_DELETE(unk_248);
    if (unk_24C != NULL) {
        delete[] unk_24C;
        unk_24C = NULL;
    }
    SAFE_DELETE(unk_258);
    SAFE_DELETE(unk_254);
    SAFE_DELETE(unk_25C);
    SAFE_DELETE(unk_260);
    SAFE_DELETE(unk_264);
    SAFE_DELETE(unk_22C);
    SAFE_DELETE(unk_1B8);
    SAFE_DELETE(unk_1BC);
}

void CBattleDisk::vfunc_08()
{
    unk_25C->Update();
    unk_264->Update();
    if (!IsActive()) {
        return;
    }
    Update();
    unk_1B8->Update();
    if (unk_18C != 0 && unk_190 == 0) {
        UpdatePowerCharge();
    }
    UpdateCursor();
    unk_1E8.m_rectangle.pos = m_motion.GetPos();
    unk_1C4.m_circle.pos = m_motion.GetPos();
    unk_22C->m_anim->UpdateAll();
}

void CBattleDisk::vfunc_0C(Camera2D *camera)
{
    unk_25C->Render(camera);
    unk_254->Render(camera);
    if (IsUnk194Flag80()) {
        unk_264->Render(camera);
    }
    if (!unk_188) {
        return;
    }
    RenderDisk(camera);
    if (unk_18C == 0) {
        return;
    }
    if (unk_190 != 0) {
        return;
    }
    if (unk_1C0->IsCharging()) {
        RenderChargeEffect(camera);
    }
    if (unk_1C0->GetLevel()) {
        RenderChargeLevel(camera);
    }
    unk_1C0->vfunc_0C(camera);
}

void CBattleDisk::RenderLine(Camera2D *camera)
{
    if (unk_188) {
        unk_1B8->Render(camera);
    }
}

void CBattleDisk::vfunc_10(Camera2D *camera)
{
}

void CBattleDisk::RenderDisk(Camera2D *camera)
{
    CSoftwareSprite *sprite = unk_228;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)unk_22C->m_image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)unk_22C->m_palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)unk_22C->m_cells;
    sprite->m_cellDataIdx = unk_22C->m_anim->GetCell(unk_230);
    sprite->SetPos(m_motion.GetPos());
    sprite->Render(camera);
}

void CBattleDisk::RenderChargeEffect(Camera2D *camera)
{
    CSoftwareSprite *sprite = unk_234;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)unk_238[0]->m_image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)unk_238[0]->m_palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)unk_238[0]->m_cells;
    sprite->m_cellDataIdx = unk_238[0]->m_anim->GetCell(unk_240);
    sprite->SetPos(m_motion.GetPos());
    sprite->Render(camera);
}

void CBattleDisk::RenderChargeLevel(Camera2D *camera)
{
    CSoftwareSprite *sprite = unk_234;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)unk_238[1]->m_image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)unk_238[1]->m_palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)unk_238[1]->m_cells;
    sprite->m_cellDataIdx = unk_1C0->GetLevel();
    sprite->SetPos(m_motion.GetPos());
    sprite->Render(camera);
}

void CBattleDisk::AddLinePoint(Point2D pos)
{
    unk_194 &= ~0x10;
    StylerLine *line = unk_1B8;
    PointPair2D seg;
    seg.p1 = line->m_lines[line->m_head].GetStart();
    seg.p2 = pos;
    if (line->FindCrossing(seg)) {
        unk_1B8->BuildLoop(unk_1B8->m_hitIndex, unk_1B8->m_head);
        unk_1B8->CutAt(unk_1B8->m_hitIndex);
        unk_194 |= 0x10;
    }
    unk_1B8->ExtendTo(pos.x, pos.y);
    m_motion.SetPos(pos);
    if (IsUnk194Flag80()) {
        unk_264->SetPos(pos);
    }
    if (unk_1B8->m_state == 1) {
        SpawnSparks(pos, 1);
    } else if (unk_1B8->m_state == 2) {
        SpawnSparks(pos, 2);
    }
}

int CBattleDisk::TakeDamage(u16 damage, u8 type)
{
    if (unk_194 & 0x40) {
        return 0;
    }
    if (damage > unk_1A4[type]) {
        damage = damage - unk_1A4[type];
        if (unk_19C <= damage) {
            unk_19C = 0;
        } else {
            unk_19C -= damage;
        }
    } else {
        damage = 0;
    }
    unk_1C0->ResetCharge();
    SetActive(FALSE);
    return damage;
}

void CBattleDisk::UpdateCursor()
{
    if (!IsActive()) {
        unk_198 |= 1;
    } else {
        unk_198 &= ~1;
    }
    if (unk_198 & 1) {
        unk_248->m_motion.SetPos(m_motion.m_pos);
        unk_248->vfunc_08();
    }
}

void CBattleDisk::UpdatePowerCharge()
{
    if (IsActive()) {
        unk_1C0->Hold(m_motion.m_pos);
    } else {
        unk_1C0->StopHold();
    }
    u16 prev = unk_1C0->GetLevel();
    unk_1C0->vfunc_08();
    u16 cur = unk_1C0->GetLevel();
    if (prev != cur) {
        switch (cur) {
        case 0:
            unk_1B8->SetNormal();
            break;
        case 1:
            unk_1B8->SetPowerLevel1();
            break;
        case 2:
            unk_1B8->SetPowerLevel2();
            break;
        }
    }
    unk_238[0]->m_anim->UpdateAll();
}

BOOL CBattleDisk::HasEnergy()
{
    return unk_19C != 0;
}

BOOL CBattleDisk::IsLoopClosed()
{
    return (unk_194 & 0x10) != 0;
}

u8 CBattleDisk::IsVisible()
{
    return unk_188;
}

void CBattleDisk::SetVisible(u8 enabled)
{
    unk_188 = enabled;
}

void CBattleDisk::ov1_0212C4F4(BOOL arg0)
{
    if (arg0) {
        unk_194 |= 0x20;
    } else {
        unk_194 &= ~0x20;
    }
}

void CBattleDisk::SetActive(BOOL active)
{
    if (active) {
        unk_188 = TRUE;
        unk_194 |= 2;
        if (IsUnk194Flag80()) {
            unk_264->Open();
        }
    } else {
        unk_1C0->StopHold();
        switch (unk_1B8->m_state) {
        case 1:
        case 2:
            unk_1B8->SetNormal();
        }
        if (IsUnk194Flag80() && unk_264->m_state != 0) {
            unk_264->Close();
        }
        unk_188 = FALSE;
        unk_194 &= ~2;
    }
}

BOOL CBattleDisk::IsActive()
{
    return (unk_194 & 2) != 0;
}

BOOL CBattleDisk::IsInvincible()
{
    return (unk_194 & 0x40) != 0;
}

void CBattleDisk::SetInvincible(BOOL arg0)
{
    if (arg0) {
        unk_194 |= 0x40;
    } else {
        unk_194 &= ~0x40;
    }
}

void CBattleDisk::ResetLine(fx32 x, fx32 y)
{
    unk_1B8->Reset(x, y);
    if (IsUnk194Flag80()) {
        unk_264->SetPos((Point2D) { x, y });
    }
}

Point2D CBattleDisk::GetLineStart(int index)
{
    return unk_1B8->m_lines[index].GetStart();
}

Point2D CBattleDisk::GetLineEnd(int index)
{
    return unk_1B8->m_lines[index].GetEnd();
}

int CBattleDisk::GetLineIndex(u16 index)
{
    return unk_1B8->GetIndex(index);
}

int CBattleDisk::GetLineCount()
{
    return unk_1B8->m_count;
}

void CBattleDisk::ShatterLine(u16 color)
{
    CGame *game = CGame::GetInstance();
    for (int i = 0; i < GetLineCount(); i++) {
        Point2D end;
        end = GetLineEnd(GetLineIndex((u8)i));
        BattleParticle *particle = unk_250->Spawn(0x50, end.x, end.y, 0, 0x2800, color);
        MATHRandContext32 *rand = &game->m_rand32;
        particle->SetVelocityY(-(MATH_Rand32(rand, 0x3000) + 0x1000), 0x1028);
        particle->SetAlphaFade(0x1F, 0);
        particle->SetScaleFade(0x1000, 0x28);
    }
}

void CBattleDisk::SpawnLoopParticles(Point2D pos, int count, fx32 arg2, u16 color)
{
    CGame::GetInstance();
    int step = (unk_1B8->m_lines2Count << 15) / count;
    int i = 0;
    if (count > 0) {
        int t = 0;
        do {
            fx32 f = t;
            f = FX32_DIV(f, 0x8000);
            u16 idx = f >> FX32_SHIFT;
            int frac = t - (idx << 15);
            PointPair2D p;
            p = GetLinePoints(&unk_1B8->m_lines2[idx]);
            fx32 x = LinearInterpolate(p.p1.x, p.p2.x, frac, 8);
            fx32 y = LinearInterpolate(p.p1.y, p.p2.y, frac, 8);
            BattleParticle *particle = unk_250->Spawn(0xC, x, y, 0, 0x1000, color);
            particle->SetVelocityX((pos.x - x) / 12, 0x1000);
            particle->SetVelocityY((pos.y - y) / 12, 0x1000);
            particle->SetScaleFade(arg2, 0x1000);
            particle->SetAlphaFade(0x1F, 0x10);
            t += step;
            i++;
        } while (i < count);
    }
}

void CBattleDisk::ov1_0212C990(Point2D pos, int count, fx32 arg2, u16 color)
{
    CGame::GetInstance();
    int step = (unk_1B8->m_lines2Count << 15) / count;
    int i = 0;
    if (count > 0) {
        fx32 dx;
        fx32 dy;
        int t = 0;
        do {
            fx32 f = t;
            f = FX32_DIV(f, 0x8000);
            u16 idx = f >> FX32_SHIFT;
            int frac = t - (idx << 15);
            PointPair2D p;
            p = GetLinePoints(&unk_1B8->m_lines2[idx]);
            fx32 x = LinearInterpolate(p.p1.x, p.p2.x, frac, 8);
            fx32 y = LinearInterpolate(p.p1.y, p.p2.y, frac, 8);
            BattleParticle *particle = unk_250->Spawn(0x18, x, y, 0, 0x1000, color);
            dx = (pos.x - x) / 12;
            dy = (pos.y - y) / 12;
            particle->SetVelocityX(dx, 0x1000);
            particle->SetVelocityY(dy, 0x1000);
            particle->SetScaleFade(arg2, 0x1000);
            particle->SetAlphaFade(0x1F, 0x10);
            particle->SetAcceleration(FX32_DIV(-dx, 0x4000), FX32_DIV(-dy, 0x4000), 0);
            t += step;
            i++;
        } while (i < count);
    }
}

void CBattleDisk::ov1_0212CBA0(Point2D pos, int count, fx32 arg2)
{
    CGame::GetInstance();
    int step = (unk_1B8->m_lines2Count << 15) / count;
    u8 colorIdx = 0;
    int i = 0;
    if (count > 0) {
        int t = 0;
        do {
            fx32 f = t;
            f = FX32_DIV(f, 0x8000);
            u16 idx = f >> FX32_SHIFT;
            int frac = t - (idx << 15);
            PointPair2D p;
            p = GetLinePoints(&unk_1B8->m_lines2[idx]);
            fx32 x = LinearInterpolate(p.p1.x, p.p2.x, frac, 8);
            fx32 y = LinearInterpolate(p.p1.y, p.p2.y, frac, 8);
            BattleParticle *particle = unk_250->Spawn(0xC, x, y, 0, 0x1000, unk_242[colorIdx]);
            particle->SetVelocityX((pos.x - x) / 12, 0x1000);
            particle->SetVelocityY((pos.y - y) / 12, 0x1000);
            particle->SetScaleFade(arg2, 0x1000);
            particle->SetAlphaFade(0x1F, 0x10);
            colorIdx++;
            if (colorIdx >= 3) {
                colorIdx -= 3;
            }
            t += step;
            i++;
        } while (i < count);
    }
}

int CBattleDisk::CalcCapturePower(u16 level, int assistType, u8 type)
{
    fx32 power;
    fx32 base = level << FX32_SHIFT;
    SaveData *save = &MAIN_BSS_020B26A0;
    power = FX32_MUL(base, unk_1C0->GetLevelScale());

    switch (SaveData_GetPartsLevel(save, STYLER_PART_SOKO)) {
    case 0:
        break;
    case 1:
        if (unk_19D == 2) {
            power += (level >> 1) << FX32_SHIFT;
        }
        break;
    case 2:
        if (unk_19D == 1 || unk_19D == 2) {
            power += (level >> 1) << FX32_SHIFT;
        }
        break;
    }

    switch (SaveData_GetPartsLevel(save, STYLER_PART_COMBO)) {
    case 0:
        break;
    case 1:
        if (unk_187 >= 6) {
            power += (level >> 1) << FX32_SHIFT;
        }
        break;
    case 2:
        if (unk_187 >= 6) {
            power += base;
        }
        break;
    }

    switch (assistType) {
    case 0:
    case 1:
    case 6:
        power += unk_19E << FX32_SHIFT;
        break;
    case 15:
        power -= unk_19E << FX32_SHIFT;
        break;
    }

    switch (assistType) {
    case 0:
    case 1:
    case 6:
    case 15:
        power = FX32_MUL(power, GetAssistTypeRate(assistType, type));
        break;
    }

    int bonus = SaveData_GetPartsLevel(save, STYLER_PART_POWPLS);
    if (bonus != 0) {
        switch (bonus) {
        case 0:
            break;
        case 1:
            power += 0x3000;
            break;
        case 2:
            power += 0x5000;
            break;
        case 3:
            power += 0x7000;
            break;
        }
    }

    return (u16)(power >> FX32_SHIFT);
}

void CBattleDisk::ShowHitEffect(fx32 x, fx32 y, int arg2)
{
    unk_254->Show(x, y, arg2);
}

void CBattleDisk::InitTypeGuards()
{
    MI_CpuFill8(unk_1A4, 0, sizeof(unk_1A4));
    unk_1A4[4] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_LEAF_G);
    unk_1A4[2] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_AQUA_G);
    unk_1A4[3] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_LIGHT_G);
    unk_1A4[1] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_FIRE_G);
    unk_1A4[6] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_FIGHT_G);
    unk_1A4[7] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_POISON_G);
    unk_1A4[10] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_PSYCHO_G);
    unk_1A4[11] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_INSECT_G);
    unk_1A4[8] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_GROUND_G);
    unk_1A4[12] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_ROCK_G);
    unk_1A4[9] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_AIR_G);
    unk_1A4[15] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_DARK_G);
    unk_1A4[13] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_HORROR_G);
    unk_1A4[5] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_ICE_G);
    unk_1A4[0] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_NORMAL_G);
    unk_1A4[16] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_METAL_G);
    unk_1A4[14] += SaveData_GetPartsBonus(&MAIN_BSS_020B26A0, STYLER_PART_DRAGON_G);
}

int CBattleDisk::SetZ(int z)
{
    z = unk_1C0->SetZ(z);
    z += unk_234->GetCellNumOAMAttrs(unk_234->m_cellDataIdx);
    unk_234->m_z = z;
    z += unk_228->GetCellNumOAMAttrs(unk_228->m_cellDataIdx);
    unk_228->m_z = z;
    return unk_264->SetZ(z);
}

int CBattleDisk::SetLineZ(int z)
{
    StylerLine *line = unk_1B8;
    line->unk_54BC = z;
    line->m_sprite0.m_z = z + 0x60;
    line->m_sprite1.m_z = z + 0x60;
    return z + 0x61;
}

void CBattleDisk::SpawnSparks(Point2D pos, int count)
{
    CGame *game = CGame::GetInstance();
    for (u8 i = 0; i < count; i++) {
        MATHRandContext32 *rand = &game->m_rand32;
        BattleParticle *particle = unk_250->Spawn(
            (u16)(MATH_Rand32(rand, 0x20) + 0x20), pos.x, pos.y, 0, 0x1000, 0x7FFF);
        particle->SetVelocityX(MATH_Rand32(rand, 0x999) - 0x4CC, 0x1000);
        particle->SetVelocityZ(-0x333, 0x1199);
        particle->SetAlphaFade(0x18, 1);
    }
}

// Uncalled, so mwld strips it, but its initializer template stays in this TU's .rodata (0x0213FBF0, ahead of the
// line effect tables), as in the original.
void CBattleDisk_ov1_0213FBF0(u16 *out)
{
    u16 values[3] = { 12, 12, 12 };
    MI_CpuCopy16(values, out, sizeof(values));
}

// Unreferenced (own section, stripped by mwld): one more data object flips mwcc's unstable size sort so that
// the 3-byte "00"/"01" literals come out in the original order.
extern const int CBattleDisk_sortPad = 0;
