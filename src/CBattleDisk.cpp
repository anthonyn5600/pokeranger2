#include "battle/CBattleDisk.hpp"

#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "UnkClass_02008788.hpp"
#include "UnkClass_020B26A0.hpp"
#include "battle/CBattlePowerSave.hpp"
#include "battle/CDiskCursor.hpp"
#include "battle/CLineEffect.hpp"
#include "battle/UnkClass_0212306C.hpp"
#include "battle/UnkClass_02127CD8.hpp"
#include "battle/UnkClass_02127E14.hpp"
#include "battle/UnkClass_02128860.hpp"
#include "battle/UnkClass_02128A60.hpp"
#include "battle/UnkClass_02128B24.hpp"
#include "battle/UnkClass_0212D2C4.hpp"
#include "battle/UnkClass_02136730.hpp"
#include "battle/UnkClass_02136AD4.hpp"
#include "fx_utils.hpp"
#include "interpolation.hpp"
#include "primitive/CSoftwareSprite.hpp"

extern "C" fx32 ov1_0212EE80(int assistType, int type);

static const fx32 sLineEffectArg0[7] = { 0x4000, 0x4000, 0x4000, 0x3000, 0x3000, 0x2000, 0x2000 };
static const fx32 sLineEffectArg1[7] = { 0x800, 0x733, 0x666, 0x599, 0x4CC, 0x333, 0x199 };

static inline PointPair2D GetLinePoints(CPrimitiveLINE *line)
{
    return line->m_points;
}

static const char *sDiskArcs[] = { "DP1", "DP2" };
static const char *sDiskNums[] = { "00", "01" };

CBattleDisk::CBattleDisk(UnkClass_02136AD4 *particles)
{
    ov1_0212BAD0();
    unk_1B8 = new UnkClass_0212306C();
    unk_1BC = new UnkClass_02128860();
    unk_1C0 = new CBattlePowerSave();
    unk_228 = new CSoftwareSprite();
    unk_234 = new CSoftwareSprite();
    unk_248 = new CDiskCursor();
    unk_24C = new CLineEffect[7];
    unk_258 = new UnkClass_02127CD8();
    unk_254 = new UnkClass_02127E14();
    unk_254->ov1_0212807C(unk_258);
    unk_260 = new UnkClass_02128A60();
    unk_25C = new UnkClass_02128B24();
    unk_25C->ov1_02128BE4(unk_260);
    unk_25C->ov1_02128E74(0x401);

    CActor *leader = this;
    for (int i = 0; i < 7; i++) {
        unk_24C[i].ov1_0212E69C(sLineEffectArg0[i], sLineEffectArg1[i], leader);
        leader = &unk_24C[i];
    }

    unk_198 = 0;
    unk_19A = 0;
    unk_194 = 0x20;
    unk_1B8->ov1_02124548(0, 0);

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
    ov1_0212CF1C();
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
    ov1_0212BC54();
}

void CBattleDisk::ov1_0212BAD0()
{
    char path[96];
    char ncbr[96];
    char nclr[96];
    char ncer[96];
    char cac[96];

    unk_22C = new UnkClass_0201AAE0("BDS", "/data/interface/i019_LZ.bin", "BDS:i019_00.NCBR", "BDS:i019.NCLR", "BDS:i019_00.NCER", "BDS:i019_00.cac");
    unk_230 = unk_22C->m_anim->sub_02008A80(1, 0);

    OS_SPrintf(path, "data/interface/i019_LZ.bin");
    for (int i = 0; i < 2; i++) {
        OS_SPrintf(ncbr, "%s:i019_%s.NCBR", sDiskArcs[i], sDiskNums[i]);
        OS_SPrintf(nclr, "%s:i019.NCLR", sDiskArcs[i]);
        OS_SPrintf(ncer, "%s:i019_%s.NCER", sDiskArcs[i], sDiskNums[i]);
        OS_SPrintf(cac, "%s:i019_%s.cac", sDiskArcs[i], sDiskNums[i]);
        unk_238[i] = new UnkClass_0201AAE0(sDiskArcs[i], path, ncbr, nclr, ncer, cac);
    }
    unk_240 = unk_238[0]->m_anim->sub_02008A80(1, 0);

    unk_264 = new UnkClass_0212D2C4();
}

void CBattleDisk::ov1_0212BC54()
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
    unk_25C->ov1_02128C2C();
    unk_264->ov1_0212D5DC();
    if (!ov1_0212C5C0()) {
        return;
    }
    sub_020121F4();
    unk_1B8->ov1_0212402C();
    if (unk_18C != 0 && unk_190 == 0) {
        ov1_0212C414();
    }
    ov1_0212C3B4();
    unk_1E8.m_rectangle.pos = m_motion.GetPos();
    unk_1C4.m_circle.pos = m_motion.GetPos();
    unk_22C->m_anim->sub_020089EC();
}

void CBattleDisk::vfunc_0C(Camera2D *camera)
{
    unk_25C->ov1_02128C70(camera);
    unk_254->ov1_02127FAC(camera);
    if (IsUnk194Flag80()) {
        unk_264->ov1_0212D974(camera);
    }
    if (!unk_188) {
        return;
    }
    ov1_0212C02C(camera);
    if (unk_18C == 0) {
        return;
    }
    if (unk_190 != 0) {
        return;
    }
    if (unk_1C0->ov1_02137ABC()) {
        ov1_0212C0B8(camera);
    }
    if (unk_1C0->ov1_02137AD4()) {
        ov1_0212C144(camera);
    }
    unk_1C0->vfunc_0C(camera);
}

void CBattleDisk::ov1_0212C00C(Camera2D *camera)
{
    if (unk_188) {
        unk_1B8->ov1_0212372C(camera);
    }
}

void CBattleDisk::vfunc_10(Camera2D *camera)
{
}

void CBattleDisk::ov1_0212C02C(Camera2D *camera)
{
    CSoftwareSprite *sprite = unk_228;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)unk_22C->m_image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)unk_22C->m_palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)unk_22C->m_cells;
    sprite->m_cellDataIdx = unk_22C->m_anim->sub_02008828(unk_230);
    sprite->SetPos(m_motion.GetPos());
    sprite->Render(camera);
}

void CBattleDisk::ov1_0212C0B8(Camera2D *camera)
{
    CSoftwareSprite *sprite = unk_234;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)unk_238[0]->m_image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)unk_238[0]->m_palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)unk_238[0]->m_cells;
    sprite->m_cellDataIdx = unk_238[0]->m_anim->sub_02008828(unk_240);
    sprite->SetPos(m_motion.GetPos());
    sprite->Render(camera);
}

void CBattleDisk::ov1_0212C144(Camera2D *camera)
{
    CSoftwareSprite *sprite = unk_234;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)unk_238[1]->m_image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)unk_238[1]->m_palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)unk_238[1]->m_cells;
    sprite->m_cellDataIdx = unk_1C0->ov1_02137AD4();
    sprite->SetPos(m_motion.GetPos());
    sprite->Render(camera);
}

void CBattleDisk::ov1_0212C1C4(Point2D pos)
{
    unk_194 &= ~0x10;
    UnkClass_0212306C *line = unk_1B8;
    PointPair2D seg;
    seg.p1 = line->m_lines[line->m_head].GetStart();
    seg.p2 = pos;
    if (line->ov1_02124588(seg)) {
        unk_1B8->ov1_021248E8(unk_1B8->m_hitIndex, unk_1B8->m_head);
        unk_1B8->ov1_02124828(unk_1B8->m_hitIndex);
        unk_194 |= 0x10;
    }
    unk_1B8->ov1_021243CC(pos.x, pos.y);
    m_motion.sub_02011D3C(pos);
    if (IsUnk194Flag80()) {
        unk_264->SetPos(pos);
    }
    if (unk_1B8->m_state == 1) {
        ov1_0212D148(pos, 1);
    } else if (unk_1B8->m_state == 2) {
        ov1_0212D148(pos, 2);
    }
}

int CBattleDisk::ov1_0212C33C(u16 damage, u8 type)
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
    unk_1C0->ov1_021371F0();
    ov1_0212C514(FALSE);
    return damage;
}

void CBattleDisk::ov1_0212C3B4()
{
    if (!ov1_0212C5C0()) {
        unk_198 |= 1;
    } else {
        unk_198 &= ~1;
    }
    if (unk_198 & 1) {
        unk_248->m_motion.sub_02011D3C(m_motion.m_pos);
        unk_248->vfunc_08();
    }
}

void CBattleDisk::ov1_0212C414()
{
    if (ov1_0212C5C0()) {
        unk_1C0->ov1_02137094(m_motion.m_pos);
    } else {
        unk_1C0->ov1_02137144();
    }
    u16 prev = unk_1C0->ov1_02137AD4();
    unk_1C0->vfunc_08();
    u16 cur = unk_1C0->ov1_02137AD4();
    if (prev != cur) {
        switch (cur) {
        case 0:
            unk_1B8->ov1_02124F08();
            break;
        case 1:
            unk_1B8->ov1_02124F64();
            break;
        case 2:
            unk_1B8->ov1_02124F84();
            break;
        }
    }
    unk_238[0]->m_anim->sub_020089EC();
}

BOOL CBattleDisk::ov1_0212C4B8()
{
    return unk_19C != 0;
}

BOOL CBattleDisk::ov1_0212C4CC()
{
    return (unk_194 & 0x10) != 0;
}

u8 CBattleDisk::ov1_0212C4E4()
{
    return unk_188;
}

void CBattleDisk::ov1_0212C4EC(u8 enabled)
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

void CBattleDisk::ov1_0212C514(BOOL active)
{
    if (active) {
        unk_188 = TRUE;
        unk_194 |= 2;
        if (IsUnk194Flag80()) {
            unk_264->ov1_0212DAF0();
        }
    } else {
        unk_1C0->ov1_02137144();
        switch (unk_1B8->m_state) {
        case 1:
        case 2:
            unk_1B8->ov1_02124F08();
        }
        if (IsUnk194Flag80() && unk_264->m_state != 0) {
            unk_264->ov1_0212DB04();
        }
        unk_188 = FALSE;
        unk_194 &= ~2;
    }
}

BOOL CBattleDisk::ov1_0212C5C0()
{
    return (unk_194 & 2) != 0;
}

BOOL CBattleDisk::ov1_0212C5D8()
{
    return (unk_194 & 0x40) != 0;
}

void CBattleDisk::ov1_0212C5F0(BOOL arg0)
{
    if (arg0) {
        unk_194 |= 0x40;
    } else {
        unk_194 &= ~0x40;
    }
}

void CBattleDisk::ov1_0212C610(fx32 x, fx32 y)
{
    unk_1B8->ov1_02124548(x, y);
    if (IsUnk194Flag80()) {
        unk_264->SetPos((Point2D) { x, y });
    }
}

Point2D CBattleDisk::ov1_0212C670(int index)
{
    return unk_1B8->m_lines[index].GetStart();
}

Point2D CBattleDisk::ov1_0212C690(int index)
{
    return unk_1B8->m_lines[index].GetEnd();
}

int CBattleDisk::ov1_0212C6B0(u16 index)
{
    return unk_1B8->ov1_02124AD4(index);
}

int CBattleDisk::ov1_0212C6C0()
{
    return unk_1B8->m_count;
}

void CBattleDisk::ov1_0212C6D0(u16 color)
{
    CGame *game = CGame::GetInstance();
    for (int i = 0; i < ov1_0212C6C0(); i++) {
        Point2D end;
        end = ov1_0212C690(ov1_0212C6B0((u8)i));
        UnkClass_02136730 *particle = unk_250->ov1_02136B24(0x50, end.x, end.y, 0, 0x2800, color);
        MATHRandContext32 *rand = &game->m_rand32;
        particle->ov1_02136A58(-(MATH_Rand32(rand, 0x3000) + 0x1000), 0x1028);
        particle->ov1_02136A88(0x1F, 0);
        particle->ov1_02136AA0(0x1000, 0x28);
    }
}

void CBattleDisk::ov1_0212C7E8(Point2D pos, int count, fx32 arg2, u16 color)
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
            UnkClass_02136730 *particle = unk_250->ov1_02136B24(0xC, x, y, 0, 0x1000, color);
            particle->ov1_02136A40((pos.x - x) / 12, 0x1000);
            particle->ov1_02136A58((pos.y - y) / 12, 0x1000);
            particle->ov1_02136AA0(arg2, 0x1000);
            particle->ov1_02136A88(0x1F, 0x10);
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
            UnkClass_02136730 *particle = unk_250->ov1_02136B24(0x18, x, y, 0, 0x1000, color);
            dx = (pos.x - x) / 12;
            dy = (pos.y - y) / 12;
            particle->ov1_02136A40(dx, 0x1000);
            particle->ov1_02136A58(dy, 0x1000);
            particle->ov1_02136AA0(arg2, 0x1000);
            particle->ov1_02136A88(0x1F, 0x10);
            particle->ov1_02136AB8(FX32_DIV(-dx, 0x4000), FX32_DIV(-dy, 0x4000), 0);
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
            UnkClass_02136730 *particle = unk_250->ov1_02136B24(0xC, x, y, 0, 0x1000, unk_242[colorIdx]);
            particle->ov1_02136A40((pos.x - x) / 12, 0x1000);
            particle->ov1_02136A58((pos.y - y) / 12, 0x1000);
            particle->ov1_02136AA0(arg2, 0x1000);
            particle->ov1_02136A88(0x1F, 0x10);
            colorIdx++;
            if (colorIdx >= 3) {
                colorIdx -= 3;
            }
            t += step;
            i++;
        } while (i < count);
    }
}

int CBattleDisk::ov1_0212CD6C(u16 level, int assistType, u8 type)
{
    fx32 power;
    fx32 base = level << FX32_SHIFT;
    UnkClass_020B26A0 *save = &MAIN_BSS_020B26A0;
    power = FX32_MUL(base, unk_1C0->ov1_02137ADC());

    switch (sub_02016C14(save, 0x12)) {
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

    switch (sub_02016C14(save, 0x13)) {
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
        power = FX32_MUL(power, ov1_0212EE80(assistType, type));
        break;
    }

    int bonus = sub_02016C14(save, 0x17);
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

void CBattleDisk::ov1_0212CF0C(fx32 x, fx32 y, int arg2)
{
    unk_254->ov1_0212812C(x, y, arg2);
}

void CBattleDisk::ov1_0212CF1C()
{
    MI_CpuFill8(unk_1A4, 0, sizeof(unk_1A4));
    unk_1A4[4] += sub_02016CF0(&MAIN_BSS_020B26A0, 0);
    unk_1A4[2] += sub_02016CF0(&MAIN_BSS_020B26A0, 1);
    unk_1A4[3] += sub_02016CF0(&MAIN_BSS_020B26A0, 2);
    unk_1A4[1] += sub_02016CF0(&MAIN_BSS_020B26A0, 3);
    unk_1A4[6] += sub_02016CF0(&MAIN_BSS_020B26A0, 4);
    unk_1A4[7] += sub_02016CF0(&MAIN_BSS_020B26A0, 5);
    unk_1A4[10] += sub_02016CF0(&MAIN_BSS_020B26A0, 6);
    unk_1A4[11] += sub_02016CF0(&MAIN_BSS_020B26A0, 7);
    unk_1A4[8] += sub_02016CF0(&MAIN_BSS_020B26A0, 8);
    unk_1A4[12] += sub_02016CF0(&MAIN_BSS_020B26A0, 9);
    unk_1A4[9] += sub_02016CF0(&MAIN_BSS_020B26A0, 10);
    unk_1A4[15] += sub_02016CF0(&MAIN_BSS_020B26A0, 11);
    unk_1A4[13] += sub_02016CF0(&MAIN_BSS_020B26A0, 12);
    unk_1A4[5] += sub_02016CF0(&MAIN_BSS_020B26A0, 13);
    unk_1A4[0] += sub_02016CF0(&MAIN_BSS_020B26A0, 14);
    unk_1A4[16] += sub_02016CF0(&MAIN_BSS_020B26A0, 15);
    unk_1A4[14] += sub_02016CF0(&MAIN_BSS_020B26A0, 16);
}

int CBattleDisk::ov1_0212D0D4(int z)
{
    z = unk_1C0->ov1_02137D7C(z);
    z += unk_234->GetCellNumOAMAttrs(unk_234->m_cellDataIdx);
    unk_234->m_z = z;
    z += unk_228->GetCellNumOAMAttrs(unk_228->m_cellDataIdx);
    unk_228->m_z = z;
    return unk_264->ov1_0212DB18(z);
}

int CBattleDisk::ov1_0212D124(int z)
{
    UnkClass_0212306C *line = unk_1B8;
    line->unk_54BC = z;
    line->m_sprite0.m_z = z + 0x60;
    line->m_sprite1.m_z = z + 0x60;
    return z + 0x61;
}

void CBattleDisk::ov1_0212D148(Point2D pos, int count)
{
    CGame *game = CGame::GetInstance();
    for (u8 i = 0; i < count; i++) {
        MATHRandContext32 *rand = &game->m_rand32;
        UnkClass_02136730 *particle = unk_250->ov1_02136B24(
            (u16)(MATH_Rand32(rand, 0x20) + 0x20), pos.x, pos.y, 0, 0x1000, 0x7FFF);
        particle->ov1_02136A40(MATH_Rand32(rand, 0x999) - 0x4CC, 0x1000);
        particle->ov1_02136A70(-0x333, 0x1199);
        particle->ov1_02136A88(0x18, 1);
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
