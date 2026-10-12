#include "CPlayerHPGauge.hpp"

#include <nitro.h>
#include <nnsys.h>

#include "CGame.hpp"
#include "UnkClass_02034478.hpp"
#include "common.hpp"
#include "file/CArchiveGuard.hpp"
#include "fx_utils.hpp"

CPlayerHPGauge::CPlayerHPGauge()
{
    m_game = CGame::GetInstance();
    m_audio = m_game->m_audioEngine;
    Init();
    CreateParts();
}

CPlayerHPGauge::~CPlayerHPGauge()
{
    DeleteParts();
}

void CPlayerHPGauge::CreateParts()
{
    m_parts[0] = new UnkClass_0201AAE0("PGM", "data/interface/i021_LZ.bin", "PGM:i021_00.NCBR", "PGM:i021.NCLR", "PGM:i021_00.NCER", "PGM:i021_00.cac");
    m_parts[1] = new UnkClass_0201AAE0("PGA", "data/interface/i024_LZ.bin", "PGA:i024_00.NCBR", "PGA:i024.NCLR", NULL, NULL);
    m_parts[2] = new UnkClass_0201AAE0("PGB", "data/interface/i023_LZ.bin", "PGB:i023_00.NCBR", "PGB:i023.NCLR", NULL, NULL);
    m_parts[3] = new UnkClass_0201AAE0("PGF", "data/interface/i020_LZ.bin", "PGF:i020_00.NCBR", "PGF:i020.NCLR", "PGF:i020_00.NCER", "PGF:i020_00.cac");
    m_parts[4] = new UnkClass_0201AAE0("PGP", "data/interface/i022_LZ.bin", "PGP:i022_00.NCBR", "PGP:i022.NCLR", NULL, NULL);
    m_parts[5] = new UnkClass_0201AAE0("PGG", "data/interface/i057_LZ.bin", "PGG:i057_00.NCBR", "PGG:i057.NCLR", NULL, NULL);
    m_parts[6] = new UnkClass_0201AAE0("PGC", "data/interface/i020_LZ.bin", "PGC:i020_01.NCBR", "PGC:i020.NCLR", "PGC:i020_01.NCER", "PGC:i020_01.cac");
    unk_5C0 = m_parts[6]->m_anim->sub_02008A80(1, 0);
}

void CPlayerHPGauge::DeleteParts()
{
    for (int i = 0; i < 7; i++) {
        SAFE_DELETE(m_parts[i]);
    }
}

void CPlayerHPGauge::Init()
{
    m_z = 0x3FF;
    m_hpLevel = 2;
    unk_592 = 0;
    m_hp = 0;
    m_maxHP = 0;
    m_shownHP = 0;
    m_trailHP = 0;
    m_flash = 0;
    unk_5AA = 2;
    unk_5A8 = 0;
    unk_5AC = 0;
    unk_5AE = 0;
    unk_5B0 = 0;
    m_alpha = 31;
    unk_5B4 = FX32_CONST(31);
    unk_5B8 = 0;
    unk_5BC = 0;
    unk_5BE = 0;
    InitHPBars();
    InitPartnerBars();
}

void CPlayerHPGauge::InitHPBars()
{
    unk_2AC.SetVertexCoordinates(FX32_CONST(-43), FX32_CONST(87), FX32_CONST(-43), FX32_CONST(91), FX32_CONST(93), FX32_CONST(91), FX32_CONST(93), FX32_CONST(87), m_z);
    unk_2AC.m_color = 0x6739;
    unk_24C.SetVertexCoordinates(FX32_CONST(-42), FX32_CONST(88), FX32_CONST(-42), FX32_CONST(90), FX32_CONST(92), FX32_CONST(90), FX32_CONST(92), FX32_CONST(88), m_z + 1);
    unk_24C.m_color = 0x294A;
    unk_1EC.SetVertexCoordinates(FX32_CONST(-42), FX32_CONST(88), FX32_CONST(-42), FX32_CONST(90), FX32_CONST(-42), FX32_CONST(90), FX32_CONST(-42), FX32_CONST(88), m_z + 2);
    unk_1EC.m_color = 0x11;
    unk_18C.SetVertexCoordinates(FX32_CONST(-42), FX32_CONST(88), FX32_CONST(-42), FX32_CONST(90), FX32_CONST(-42), FX32_CONST(90), FX32_CONST(-42), FX32_CONST(88), m_z + 3);
    unk_30C.SetVertexCoordinates(FX32_CONST(-96), FX32_CONST(68), FX32_CONST(-96), FX32_CONST(94), FX32_CONST(96), FX32_CONST(94), FX32_CONST(96), FX32_CONST(68), m_z + 6);
    unk_30C.m_texCoords.x1 = 0;
    unk_30C.m_texCoords.y1 = 0;
    unk_30C.m_texCoords.x2 = 0;
    unk_30C.m_texCoords.y2 = FX32_CONST(24);
    unk_30C.m_texCoords.x3 = FX32_CONST(192);
    unk_30C.m_texCoords.y3 = FX32_CONST(24);
    unk_30C.m_texCoords.x4 = FX32_CONST(192);
    unk_30C.m_texCoords.y4 = 0;
}

void CPlayerHPGauge::InitPartnerBars()
{
    unk_42C[0].m_texCoords.x1 = FX32_CONST(8);
    unk_42C[0].m_texCoords.y1 = 0;
    unk_42C[0].m_texCoords.x2 = FX32_CONST(8);
    unk_42C[0].m_texCoords.y2 = FX32_CONST(8);
    unk_42C[0].m_texCoords.x3 = FX32_CONST(16);
    unk_42C[0].m_texCoords.y3 = FX32_CONST(8);
    unk_42C[0].m_texCoords.x4 = FX32_CONST(16);
    unk_42C[0].m_texCoords.y4 = 0;
    unk_42C[1].m_texCoords.x1 = FX32_CONST(24);
    unk_42C[1].m_texCoords.y1 = 0;
    unk_42C[1].m_texCoords.x2 = FX32_CONST(24);
    unk_42C[1].m_texCoords.y2 = FX32_CONST(8);
    unk_42C[1].m_texCoords.x3 = FX32_CONST(32);
    unk_42C[1].m_texCoords.y3 = FX32_CONST(8);
    unk_42C[1].m_texCoords.x4 = FX32_CONST(32);
    unk_42C[1].m_texCoords.y4 = 0;
    unk_42C[2].m_texCoords.x1 = FX32_CONST(40);
    unk_42C[2].m_texCoords.y1 = 0;
    unk_42C[2].m_texCoords.x2 = FX32_CONST(40);
    unk_42C[2].m_texCoords.y2 = FX32_CONST(8);
    unk_42C[2].m_texCoords.x3 = FX32_CONST(48);
    unk_42C[2].m_texCoords.y3 = FX32_CONST(8);
    unk_42C[2].m_texCoords.x4 = FX32_CONST(48);
    unk_42C[2].m_texCoords.y4 = 0;
    unk_42C[0].SetVertexCoordinates(FX32_CONST(-48), FX32_CONST(78), FX32_CONST(-48), FX32_CONST(86), FX32_CONST(-40), FX32_CONST(86), FX32_CONST(-40), FX32_CONST(78), m_z + 5);
}

void CPlayerHPGauge::vfunc_08()
{
    UpdateHP();
    UpdatePartner();
    UpdateAlpha();
    if (unk_592 & 0x80) {
        m_parts[6]->m_anim->sub_020089EC();
        if (m_shownHP == m_hp << FX32_SHIFT) {
            StopHeal();
        }
    }
}

void CPlayerHPGauge::UpdateHP()
{
    if (m_hp << FX32_SHIFT > m_shownHP) {
        if (unk_592 & 0x80) {
            m_shownHP += m_healRate;
        } else {
            m_shownHP += 0x333;
        }
        if (!(unk_592 & 4)) {
            unk_592 |= 4;
        }
    }
    if (m_shownHP > m_hp << FX32_SHIFT) {
        m_shownHP = m_hp << FX32_SHIFT;
    }
    if ((unk_592 & 4) && m_shownHP == m_hp << FX32_SHIFT) {
        unk_592 &= ~4;
    }
    if (m_shownHP > m_trailHP) {
        m_trailHP = m_shownHP;
    }
    if (m_shownHP < m_trailHP) {
        m_trailHP -= 0x199;
        unk_592 |= 8;
    }
    fx32 max = m_maxHP << FX32_SHIFT;
    fx32 ratio = FX32_DIV(m_shownHP, max);
    fx32 width = FX32_MUL(ratio, FX32_CONST(136));
    fx32 trailWidth = FX32_MUL(FX32_DIV(m_trailHP, max), FX32_CONST(136));
    unk_18C.SetVertexCoordinates(FX32_CONST(-43), FX32_CONST(87), FX32_CONST(-43), FX32_CONST(91), width - FX32_CONST(43), FX32_CONST(91), width - FX32_CONST(43), FX32_CONST(87), m_z + 3);
    unk_1EC.SetVertexCoordinates(FX32_CONST(-43), FX32_CONST(87), FX32_CONST(-43), FX32_CONST(91), trailWidth - FX32_CONST(43), FX32_CONST(91), trailWidth - FX32_CONST(43), FX32_CONST(87), m_z + 2);
    UpdateHPLevel(ratio);
    UpdateLowHPFlash(ratio);
    unk_592 &= ~8;
}

void CPlayerHPGauge::UpdatePartner()
{
    if (!IsPartnerVisible()) {
        return;
    }
    fx32 u0, v1, u1, v0;
    if (unk_5AA & 0x10) {
        u0 = FX32_CONST(32);
        v0 = 0;
        v1 = FX32_CONST(3);
        u1 = FX32_CONST(40);
    } else {
        u0 = FX32_CONST(24);
        v0 = 0;
        v1 = FX32_CONST(3);
        u1 = FX32_CONST(32);
    }
    unk_36C.m_texCoords.x1 = u0;
    unk_36C.m_texCoords.y1 = v0;
    unk_36C.m_texCoords.x2 = u0;
    unk_36C.m_texCoords.y2 = v1;
    unk_36C.m_texCoords.x3 = u1;
    unk_36C.m_texCoords.y3 = v1;
    unk_36C.m_texCoords.x4 = u1;
    unk_36C.m_texCoords.y4 = v0;
    if (unk_5AA & 4) {
        if (unk_5AC == 32) {
            unk_5AA &= ~8;
            unk_5AA &= ~4;
            unk_5AA |= 0x10;
            unk_5A8 = 0;
            unk_5AC = 0;
            m_audio->sub_02034C44(0x42);
        } else if (unk_5AC < 32) {
            unk_5A8 += 2;
            if (unk_5AC != 0 && unk_5AC % 16 == 0) {
                unk_5A8 = 0;
                m_audio->sub_02034F3C(0x3F);
                m_audio->sub_02034C44(0x42);
                m_audio->sub_02034F3C(0x7F);
            }
            unk_5AC++;
        }
    }
    unk_36C.SetVertexCoordinates(FX32_CONST(-43), FX32_CONST(80), FX32_CONST(-43), FX32_CONST(83), (unk_5AE - 43) << FX32_SHIFT, FX32_CONST(83), (unk_5AE - 43) << FX32_SHIFT, FX32_CONST(80), m_z + 4);
}

void CPlayerHPGauge::UpdateHPLevel(fx32 ratio)
{
    fx32 u0, v0, v1, u1, v2;
    if (ratio > 0x666) {
        m_hpLevel = 0;
        u0 = 0;
        v0 = 0;
        v2 = 0;
        v1 = FX32_CONST(4);
        u1 = FX32_CONST(8);
    } else if (ratio > 0x333) {
        if (m_hpLevel != 1 && (unk_592 & 8)) {
            m_audio->sub_02034C44(0x104);
        }
        m_hpLevel = 1;
        u0 = FX32_CONST(8);
        v0 = 0;
        v2 = 0;
        v1 = FX32_CONST(4);
        u1 = FX32_CONST(16);
    } else {
        if (m_hpLevel != 2 && (unk_592 & 8)) {
            m_audio->sub_02034C44(0x105);
        }
        m_hpLevel = 2;
        u0 = FX32_CONST(16);
        v0 = 0;
        v2 = 0;
        v1 = FX32_CONST(4);
        u1 = FX32_CONST(24);
    }
    unk_18C.m_texCoords.x1 = u0;
    unk_18C.m_texCoords.y1 = v0;
    unk_18C.m_texCoords.x2 = u0;
    unk_18C.m_texCoords.y2 = v1;
    unk_18C.m_texCoords.x3 = u1;
    unk_18C.m_texCoords.y3 = v1;
    unk_18C.m_texCoords.x4 = u1;
    unk_18C.m_texCoords.y4 = v2;
}

void CPlayerHPGauge::UpdateLowHPFlash(fx32 ratio)
{
    if (!(unk_592 & 0x10) && ratio < 0x333) {
        unk_592 |= 0x10;
        unk_592 |= 0x20;
        m_flash = FX32_CONST(10);
    }
    if ((unk_592 & 0x10) && ratio >= 0x333) {
        unk_592 &= ~0x10;
        unk_24C.m_color = 0x294A;
    }
    if (unk_592 & 0x10) {
        if (unk_592 & 0x20) {
            if (m_flash < FX32_CONST(31)) {
                m_flash += FX32_ONE;
            } else {
                unk_592 &= ~0x20;
            }
        } else {
            if (m_flash > 0) {
                m_flash -= FX32_ONE;
            } else {
                unk_592 |= 0x20;
            }
        }
        u16 c = m_flash >> FX32_SHIFT;
        if (c > 31) {
            c = 31;
        }
        unk_24C.m_color = GX_RGB(c, c, c);
    }
}

void CPlayerHPGauge::UpdateAlpha()
{
    if ((unk_592 & 0x40) && unk_5B4 > FX32_CONST(15)) {
        if (unk_5BC >= unk_5BE) {
            unk_5B4 = FX32_CONST(15);
        } else {
            unk_5BC++;
            unk_5B4 -= unk_5B8;
        }
    }
    if (!(unk_592 & 0x40) && unk_5B4 < FX32_CONST(31)) {
        if (unk_5BC >= unk_5BE) {
            unk_5B4 = FX32_CONST(31);
        } else {
            unk_5BC++;
            unk_5B4 += unk_5B8;
        }
    }
    m_alpha = unk_5B4 >> FX32_SHIFT;
    if (m_alpha > 31) {
        m_alpha = 31;
    }
}

void CPlayerHPGauge::SetHP(u16 hp, u16 maxHP)
{
    m_shownHP = hp << FX32_SHIFT;
    m_hp = hp;
    m_maxHP = maxHP;
}

void CPlayerHPGauge::SetCurrentHP(u16 hp)
{
    m_hp = hp;
}

void CPlayerHPGauge::StartHeal(u16 anim)
{
    int frames = m_game->unk_146C.sub_02008E50() * 2;
    m_healRate = FX32_DIV((m_hp << FX32_SHIFT) - m_shownHP, frames << FX32_SHIFT);
    m_parts[6]->m_anim->sub_02008990(unk_5C0, anim);
    m_audio->sub_02034C44(0x106);
    unk_592 |= 0x80;
}

void CPlayerHPGauge::StopHeal()
{
    m_audio->sub_02034C5C(0x106);
    unk_592 &= ~0x80;
}

BOOL CPlayerHPGauge::IsHealing()
{
    return (unk_592 & 0x80) ? TRUE : FALSE;
}

BOOL CPlayerHPGauge::IsHPChanging()
{
    return (unk_592 & 4) ? TRUE : FALSE;
}

u16 CPlayerHPGauge::SetZ(u16 z)
{
    m_z = z;
    return m_z + 8;
}

BOOL CPlayerHPGauge::IsVisible()
{
    return (unk_592 & 1) ? TRUE : FALSE;
}

void CPlayerHPGauge::SetVisible(BOOL visible)
{
    if (visible) {
        unk_592 |= 1;
    } else {
        unk_592 &= ~1;
    }
}

BOOL CPlayerHPGauge::IsPartnerVisible()
{
    return (unk_5AA & 1) ? TRUE : FALSE;
}

void CPlayerHPGauge::SetPartnerVisible(BOOL visible)
{
    if (visible) {
        unk_5AA |= 1;
    } else {
        unk_5AA &= ~1;
    }
}

u16 CPlayerHPGauge::GetHPLevel()
{
    return m_hpLevel;
}

void CPlayerHPGauge::SetPartnerEnergy(u16 energy)
{
    unk_5AE = energy;
    if (energy == 0) {
        unk_5AA &= ~0x14;
        unk_5AA |= 2;
    }
    if (unk_5AE > unk_5B0) {
        unk_5AE = unk_5B0;
    }
    if (unk_5AE == unk_5B0 && (unk_5AA & 2)) {
        unk_5AA &= ~2;
        unk_5AA |= 4;
        unk_5AC = 0;
    }
}

void CPlayerHPGauge::SetPartner(u16 energy, u16 maxEnergy)
{
    SetPartnerMax(maxEnergy);
    SetPartnerEnergy(energy);
    if (maxEnergy == energy) {
        unk_5AA &= ~6;
        unk_5AA |= 0x10;
    }
}

void CPlayerHPGauge::SetPartnerMax(u16 maxEnergy)
{
    unk_5AE = 0;
    unk_5B0 = maxEnergy;
    int mid = (u16)(unk_5B0 - 8);
    unk_3CC.SetVertexCoordinates(FX32_CONST(-43), FX32_CONST(80), FX32_CONST(-43), FX32_CONST(83), (unk_5B0 - 43) << FX32_SHIFT, FX32_CONST(83), (unk_5B0 - 43) << FX32_SHIFT, FX32_CONST(80), m_z + 3);
    unk_3CC.m_color = 0x294A;
    unk_42C[1].SetVertexCoordinates(FX32_CONST(-40), FX32_CONST(78), FX32_CONST(-40), FX32_CONST(86), (mid - 40) << FX32_SHIFT, FX32_CONST(86), (mid - 40) << FX32_SHIFT, FX32_CONST(78), m_z + 5);
    u16 end = mid + 8;
    unk_42C[2].SetVertexCoordinates((mid - 40) << FX32_SHIFT, FX32_CONST(78), (mid - 40) << FX32_SHIFT, FX32_CONST(86), (end - 40) << FX32_SHIFT, FX32_CONST(86), (end - 40) << FX32_SHIFT, FX32_CONST(78), m_z + 5);
}

void CPlayerHPGauge::vfunc_0C(Camera2D *camera)
{
    if (IsVisible()) {
        DrawIcon(camera);
        DrawHPNumber(camera);
        DrawMaxHPNumber(camera);
        DrawHPBars(camera);
        if (IsPartnerVisible()) {
            DrawPartner(camera);
        }
        if (unk_592 & 0x80) {
            DrawHealEffect(camera);
        }
    }
}

void CPlayerHPGauge::vfunc_10()
{
}

void CPlayerHPGauge::DrawIcon(Camera2D *camera)
{
    unk_30C.unk_58 = (UnkClass_CPrimitive_ImageProxy *)m_parts[3]->m_image;
    unk_30C.unk_5C = (UnkClass_CPrimitive_ImagePaletteProxy *)m_parts[3]->m_palette;
    unk_30C.m_alpha = m_alpha;
    unk_30C.m_z = m_z + 6;
    unk_30C.Render(camera);
}

void CPlayerHPGauge::DrawHPNumber(Camera2D *camera)
{
    Point2D pos;
    u16 hp = m_hp;
    int value = hp >= 100 ? hp - 100 : hp;
    int tens = value / 10;
    int ones = value - tens * 10;
    pos.x = FX32_CONST(-81);
    pos.y = FX32_CONST(86);
    if (hp >= 100) {
        pos.x = FX32_CONST(-88);
        DrawDigit(1, 1, pos, camera);
        pos.x = FX32_CONST(-81);
        DrawDigit(tens, 1, pos, camera);
    } else if (tens > 0) {
        pos.x = FX32_CONST(-81);
        DrawDigit(tens, 1, pos, camera);
    }
    pos.x = FX32_CONST(-72);
    DrawDigit(ones, 1, pos, camera);
}

void CPlayerHPGauge::DrawMaxHPNumber(Camera2D *camera)
{
    Point2D pos;
    int tens;
    int value = m_maxHP;
    if (m_maxHP >= 100) {
        value -= 100;
    }
    tens = value / 10;
    value -= tens * 10;
    fx32 offset = 0;
    pos.x = offset - FX32_CONST(66);
    pos.y = FX32_CONST(87);
    DrawDigit(10, 2, pos, camera);
    if (m_maxHP >= 100) {
        offset = FX32_CONST(4);
        pos.x = offset - FX32_CONST(65);
        DrawDigit(1, 2, pos, camera);
    }
    pos.x = offset - FX32_CONST(60);
    DrawDigit(tens, 2, pos, camera);
    pos.x = offset - FX32_CONST(53);
    DrawDigit(value, 2, pos, camera);
}

void CPlayerHPGauge::DrawDigit(int digit, int part, Point2D pos, Camera2D *camera)
{
    int w, h;
    if (part == 1) {
        w = 16;
        h = 16;
    } else {
        w = 8;
        h = 16;
    }
    unk_54C.unk_38 = (UnkClass_CPrimitive_ImageProxy *)m_parts[part]->m_image;
    unk_54C.unk_3C = (UnkClass_CPrimitive_ImagePaletteProxy *)m_parts[part]->m_palette;
    unk_54C.SetPos(pos);
    unk_54C.m_rectangle.size.x = w << FX32_SHIFT;
    unk_54C.m_rectangle.size.y = h << FX32_SHIFT;
    unk_54C.SetTexCoords((w * digit) << FX32_SHIFT, 0, (w * (digit + 1)) << FX32_SHIFT, h << FX32_SHIFT);
    unk_54C.m_alpha = m_alpha;
    unk_54C.m_z = m_z + 7;
    unk_54C.Render(camera);
}

void CPlayerHPGauge::DrawHPBars(Camera2D *camera)
{
    unk_18C.m_alpha = m_alpha;
    unk_1EC.m_alpha = m_alpha;
    unk_2AC.m_alpha = m_alpha;
    unk_24C.m_alpha = m_alpha;
    if (m_hp != 0) {
        unk_18C.unk_58 = (UnkClass_CPrimitive_ImageProxy *)m_parts[5]->m_image;
        unk_18C.unk_5C = (UnkClass_CPrimitive_ImagePaletteProxy *)m_parts[5]->m_palette;
        unk_18C.Render(camera);
    }
    unk_1EC.m_z = m_z + 2;
    unk_2AC.m_z = m_z;
    unk_24C.m_z = m_z + 1;
    unk_1EC.Render(camera);
    unk_2AC.Render(camera);
    unk_24C.Render(camera);
}

void CPlayerHPGauge::DrawPartner(Camera2D *camera)
{
    if (unk_5AE != 0) {
        DrawPartnerBar(camera);
    }
    DrawPartnerFrame(camera);
    DrawPartnerLeft(camera);
    DrawPartnerMiddle(camera);
    DrawPartnerRight(camera);
}

void CPlayerHPGauge::DrawPartnerFrame(Camera2D *camera)
{
    unk_3CC.m_alpha = m_alpha;
    unk_3CC.m_z = m_z + 3;
    unk_3CC.Render(camera);
}

void CPlayerHPGauge::DrawPartnerBar(Camera2D *camera)
{
    if (unk_5AA & 4) {
        unk_36C.unk_58 = NULL;
        unk_36C.unk_5C = NULL;
        u8 c = 0;
        if (unk_5A8 != 0) {
            c = unk_5A8 - 1;
        }
        unk_36C.m_color = GX_RGB(c, c, c);
    } else {
        unk_36C.unk_58 = (UnkClass_CPrimitive_ImageProxy *)m_parts[5]->m_image;
        unk_36C.unk_5C = (UnkClass_CPrimitive_ImagePaletteProxy *)m_parts[5]->m_palette;
    }
    unk_36C.m_alpha = m_alpha;
    unk_36C.m_z = m_z + 4;
    unk_36C.Render(camera);
}

void CPlayerHPGauge::DrawPartnerLeft(Camera2D *camera)
{
    unk_42C[0].unk_58 = (UnkClass_CPrimitive_ImageProxy *)m_parts[4]->m_image;
    unk_42C[0].unk_5C = (UnkClass_CPrimitive_ImagePaletteProxy *)m_parts[4]->m_palette;
    unk_42C[0].m_alpha = m_alpha;
    unk_42C[0].m_z = m_z + 5;
    unk_42C[0].Render(camera);
}

void CPlayerHPGauge::DrawPartnerMiddle(Camera2D *camera)
{
    unk_42C[1].unk_58 = (UnkClass_CPrimitive_ImageProxy *)m_parts[4]->m_image;
    unk_42C[1].unk_5C = (UnkClass_CPrimitive_ImagePaletteProxy *)m_parts[4]->m_palette;
    unk_42C[1].m_alpha = m_alpha;
    unk_42C[1].m_z = m_z + 5;
    unk_42C[1].Render(camera);
}

void CPlayerHPGauge::DrawPartnerRight(Camera2D *camera)
{
    unk_42C[2].unk_58 = (UnkClass_CPrimitive_ImageProxy *)m_parts[4]->m_image;
    unk_42C[2].unk_5C = (UnkClass_CPrimitive_ImagePaletteProxy *)m_parts[4]->m_palette;
    unk_42C[2].m_alpha = m_alpha;
    unk_42C[2].m_z = m_z + 5;
    unk_42C[2].Render(camera);
}

void CPlayerHPGauge::DrawHealEffect(Camera2D *camera)
{
    CSoftwareSprite *sprite = m_sprite;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)m_parts[6]->m_image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)m_parts[6]->m_palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)m_parts[6]->m_cells;
    sprite->m_cellDataIdx = m_parts[6]->m_anim->sub_02008828(unk_5C0);
    sprite->m_alpha = m_alpha;
    sprite->m_z = m_z + 8;
    sprite->SetXY(0, FX32_CONST(86));
    sprite->Render(camera);
}

UnkClass_0201AAE0 *CPlayerHPGauge::GetPart(int index)
{
    if (index >= 0 && index < 7) {
        return m_parts[index];
    }
    return NULL;
}

UnkClass_0201AAE0::UnkClass_0201AAE0(const char *arcName, const char *arcPath, const char *ncbr, const char *nclr, const char *ncer, const char *cac)
{
    Load(arcName, arcPath, ncbr, nclr, ncer, cac);
}

UnkClass_0201AAE0::~UnkClass_0201AAE0()
{
    Release();
}

void UnkClass_0201AAE0::Load(const char *arcName, const char *arcPath, const char *ncbr, const char *nclr, const char *ncer, const char *cac)
{
    CArchiveGuard *guard = new CArchiveGuard(arcName, arcPath, 1, 1, 0, NULL, 0);

    m_image = new UnkClass_020074D4(ncbr, 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->sub_020076E8(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->sub_020076B0();

    m_palette = new UnkClass_02007AA4(nclr, 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->sub_02007BFC(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->sub_02007BC4();

    if (ncer != NULL) {
        m_cells = new CNCERFile(ncer, 0, 0, 0);
    }
    if (cac != NULL) {
        m_anim = new UnkClass_02008788(cac);
    }
    delete guard;
}

void UnkClass_0201AAE0::Release()
{
    SAFE_DELETE(m_anim);
    SAFE_DELETE(m_cells);
    SAFE_DELETE(m_palette);
    SAFE_DELETE(m_image);
    NNS_GfdFreeLnkTexVram(m_texKey);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}
