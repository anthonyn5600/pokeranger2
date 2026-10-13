#include "battle/UnkClass_021384F8.hpp"

#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "CTouchPanel.hpp"
#include "UnkClass_02001C04.hpp"
#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "UnkClass_02010D2C.hpp"
#include "UnkClass_02034478.hpp"
#include "UnkClass_020B26A0.hpp"
#include "battle/CBattleDisk.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "fx_utils.hpp"
#include "interpolation.hpp"

static const u16 sRankScores[4] = { 50, 25, 12, 0 };
static const u16 sBonusScores[17] = { 12, 13, 15, 13, 15, 25, 50, 25, 15, 25, 10, 15, 20, 10, 20, 15, 30 };

static inline void SetSpriteRes(CSoftwareSprite *sprite, UnkClass_020074D4 *image, UnkClass_02007AA4 *palette, CNCERFile *cells)
{
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)cells;
}

UnkClass_021384F8::UnkClass_021384F8()
{
    Load();
    m_exp = 0;
    m_baseExp = 0;
    m_bonusIdx = 0;
    m_bonusFlags = 0;
    m_score = 0;
    m_audio = CGame::GetInstance()->m_audioEngine;
    m_levelTable = CGame::GetInstance()->unk_1438;
    m_save = &MAIN_BSS_020B26A0;

    SetSpriteRes(&m_expLabel0, m_image, m_palette, m_cells);
    SetSpriteRes(&m_expLabel1, m_image, m_palette, m_cells);
    for (int i = 0; i < 4; i++) {
        SetSpriteRes(&m_expDigits[i], m_image, m_palette, m_cells);
    }
    SetSpriteRes(&m_bonusLabel0, m_image, m_palette, m_cells);
    SetSpriteRes(&m_bonusLabel1, m_image, m_palette, m_cells);
    for (int i = 0; i < 5; i++) {
        SetSpriteRes(&m_bonusDigits[i], m_image, m_palette, m_cells);
    }
    SetSpriteRes(&m_panel0, m_image, m_palette, m_cells);
    SetSpriteRes(&m_panel1, m_image, m_palette, m_cells);
    SetSpriteRes(&m_panel2, m_image, m_palette, m_cells);
    SetSpriteRes(&m_levelLabel0, m_image, m_palette, m_cells);
    SetSpriteRes(&m_levelLabel1, m_image, m_palette, m_cells);
    SetSpriteRes(&m_levelLabel2, m_image, m_palette, m_cells);
    SetSpriteRes(&m_stat1Label0, m_image, m_palette, m_cells);
    SetSpriteRes(&m_stat1Label1, m_image, m_palette, m_cells);
    SetSpriteRes(&m_stat2Label0, m_image, m_palette, m_cells);
    SetSpriteRes(&m_stat2Label1, m_image, m_palette, m_cells);
    for (int i = 0; i < 2; i++) {
        SetSpriteRes(&m_levelFrom[i], m_image, m_palette, m_cells);
        SetSpriteRes(&m_levelTo[i], m_image, m_palette, m_cells);
    }
    for (int i = 0; i < 3; i++) {
        SetSpriteRes(&m_stat1Digits[i], m_image, m_palette, m_cells);
    }
    for (int i = 0; i < 3; i++) {
        SetSpriteRes(&m_stat2Digits[i], m_image, m_palette, m_cells);
    }
    SetSpriteRes(&m_prompt0, m_image, m_palette, m_cells);
    SetSpriteRes(&m_prompt1, m_image, m_palette, m_cells);

    m_expLabel0.m_cellDataIdx = 13;
    m_expLabel1.m_cellDataIdx = 14;
    m_bonusLabel0.m_cellDataIdx = 17;
    m_bonusLabel1.m_cellDataIdx = 35;
    m_panel0.m_cellDataIdx = 0;
    m_panel1.m_cellDataIdx = 2;
    m_panel2.m_cellDataIdx = 1;
    m_levelLabel0.m_cellDataIdx = 6;
    m_levelLabel1.m_cellDataIdx = 7;
    m_levelLabel2.m_cellDataIdx = 8;
    m_stat1Label0.m_cellDataIdx = 9;
    m_stat1Label1.m_cellDataIdx = 10;
    m_stat2Label0.m_cellDataIdx = 11;
    m_stat2Label1.m_cellDataIdx = 12;
    m_prompt0.m_cellDataIdx = 15;
    m_prompt1.m_cellDataIdx = 16;
    for (int i = 0; i < 2; i++) {
        m_levelFrom[i].m_cellDataIdx = 36;
        m_levelTo[i].m_cellDataIdx = 36;
    }
    for (int i = 0; i < 3; i++) {
        m_stat1Digits[i].m_cellDataIdx = 36;
    }
    for (int i = 0; i < 3; i++) {
        m_stat2Digits[i].m_cellDataIdx = 36;
    }
    for (int i = 0; i < 4; i++) {
        m_expDigits[i].m_cellDataIdx = 36;
    }
    for (int i = 0; i < 5; i++) {
        m_bonusDigits[i].m_cellDataIdx = 36;
    }

    m_panel2.m_alpha = 14;
    m_bonusLabel1.m_alpha = 14;
    m_levelLabel1.m_alpha = 14;
    m_stat1Label1.m_alpha = 14;
    m_stat2Label1.m_alpha = 14;
    m_bonusLabel0.m_alpha = 0;
    for (int i = 0; i < 5; i++) {
        m_bonusDigits[i].m_alpha = 0;
    }

    for (int i = 0; i < 2; i++) {
        m_levelFrom[i].SetScale(0x800, 0x800);
        m_levelTo[i].SetScale(0x800, 0x800);
    }
    for (int i = 0; i < 3; i++) {
        m_stat1Digits[i].SetScale(0x800, 0x800);
    }
    for (int i = 0; i < 3; i++) {
        m_stat2Digits[i].SetScale(0x800, 0x800);
    }

    m_panel0.m_color = GX_RGB(16, 31, 16);
    m_levelLabel0.m_color = GX_RGB(16, 31, 16);
    m_stat1Label0.m_color = GX_RGB(16, 31, 16);
    m_stat2Label0.m_color = GX_RGB(16, 31, 16);
    m_expBar.m_color = GX_RGB(16, 31, 16);
    for (int i = 0; i < 4; i++) {
        m_expDigits[i].m_color = GX_RGB(16, 31, 16);
    }
    for (int i = 0; i < 5; i++) {
        m_bonusDigits[i].m_color = GX_RGB(16, 31, 16);
    }

    SetPanelPos(-0x100000, -0x28000);
    SetLevelPos(-0x100000, 0x28000);
    SetStat1Pos(0x140000, 0x28000);
    SetStat2Pos(0x140000, 0x28000);
    SetExpLabelPos(-0x100000, 0x18000);
    MoveExpBar(-0x100000, 0x18000);
    SetExpPos(0x100000, 0x18000);
    SetPromptPos(0x100000, -0x2C000);
    SetBonusPos(0x100000, -0x48000);
    m_frame = 0;
    m_state = 0;
}

UnkClass_021384F8::~UnkClass_021384F8()
{
    Release();
}

void UnkClass_021384F8::Load()
{
    char path[0x60];

    OS_SPrintf(path, "data/battle/result/r000_00_LZ.bin");
    CArchiveGuard *guard = new CArchiveGuard("BRM", path, 1, 1, 0, NULL, 0);

    OS_SPrintf(path, "BRM:r000_00.NCBR");
    m_image = new UnkClass_020074D4(path, 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->sub_020076E8(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->sub_020076B0();

    OS_SPrintf(path, "BRM:r000.NCLR");
    m_palette = new UnkClass_02007AA4(path, 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->sub_02007BFC(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->sub_02007BC4();

    m_cells = new CNCERFile("BRM:r000_00.NCER", 0, 0, 0);

    SAFE_DELETE(guard);
}

void UnkClass_021384F8::Release()
{
    SAFE_DELETE(m_image);
    SAFE_DELETE(m_palette);
    SAFE_DELETE(m_cells);
    NNS_GfdFreeLnkTexVram(m_texKey);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}

void UnkClass_021384F8::ov1_02138FEC()
{
    m_frame++;
    switch (m_state) {
    case 0:
        break;
    case 1:
        ov1_02139088();
        break;
    case 2:
        ov1_021390A8();
        break;
    case 3:
        ov1_02139154();
        break;
    case 4:
        ov1_02139280();
        break;
    case 5:
        ov1_021392F8();
        break;
    case 6:
        ov1_02139364();
        break;
    case 7:
        ov1_021396C0();
        break;
    case 9:
        ov1_0213985C();
        break;
    case 8:
        ov1_021397FC();
        break;
    case 10:
        ov1_021398F4();
        break;
    }
}

void UnkClass_021384F8::ov1_02139088()
{
    if (m_frame >= 16) {
        m_frame = 0;
        m_state = 2;
    }
}

void UnkClass_021384F8::ov1_021390A8()
{
    SetExpDigits(m_exp);
    SetExpBar(m_save->unk_0028 << FX32_SHIFT, m_nextExp << FX32_SHIFT);
    fx32 x = LinearInterpolate(-0x100000, 0, m_frame, 24);
    SetExpLabelPos(x, 0x18000);
    MoveExpBar(x, 0x18000);
    SetExpPos(LinearInterpolate(0x100000, 0, m_frame, 24), 0x18000);
    if (m_frame >= 40) {
        m_frame = 0;
        m_state = 3;
    }
}

void UnkClass_021384F8::ov1_02139154()
{
    for (;;) {
        if (m_bonusIdx >= 17) {
            u8 rank = ov1_0213A4A0(m_score);
            m_panel1.m_cellDataIdx = rank + 2;
            if (rank == 0) {
                m_audio->sub_02034C44(20);
            } else {
                m_audio->sub_02034C44(53);
            }
            SetBonusPos(0x100000, -0x48000);
            m_frame = 0;
            m_state = 5;
            return;
        }
        if (m_bonusFlags & (1 << m_bonusIdx)) {
            m_bonusLabel0.m_alpha = 31;
            m_bonusLabel0.m_cellDataIdx = m_bonusIdx + 17;
            m_bonus = m_baseExp * sBonusScores[m_bonusIdx] / 100;
            m_score += sBonusScores[m_bonusIdx];
            SetBonusDigits(m_bonus);
            m_audio->sub_02034C44(56);
            m_frame = 0;
            m_state = 4;
            m_bonusIdx++;
            return;
        }
        m_bonusIdx++;
    }
}

void UnkClass_021384F8::ov1_02139280()
{
    SetBonusPos(LinearInterpolate(0x100000, 0, m_frame, 8), -0x48000);
    if (m_frame == 8) {
        m_exp = m_exp + m_bonus;
        SetExpDigits(m_exp);
    }
    if (m_frame >= 40) {
        m_frame = 0;
        m_state = 3;
    }
}

void UnkClass_021384F8::ov1_021392F8()
{
    SetPanelPos(LinearInterpolate(-0x100000, -0x80000, m_frame, 8), -0x28000);
    if (m_frame >= 40) {
        m_audio->sub_02034C5C(53);
        m_audio->sub_02034C44(54);
        m_frame = 0;
        m_state = 6;
    }
}

void UnkClass_021384F8::ov1_02139364()
{
    if (m_baseExp == 0) {
        m_audio->sub_02034C5C(54);
        m_frame = 0;
        m_state = 10;
        return;
    }

    if (m_tally >= 64) {
        if (!m_maxLevel) {
            int exp = m_exp - m_levelExp;
            exp += m_save->unk_0028;
            if (exp < 0) {
                exp = 0;
            }
            m_save->unk_0028 = exp;
        }
        u8 startLevel = m_startLevel;
        if (startLevel != m_level) {
            u8 stat1 = sub_02010E90(m_levelTable, m_level) - sub_02010E90(m_levelTable, startLevel);
            u8 stat2 = sub_02010E78(m_levelTable, m_level) - sub_02010E78(m_levelTable, m_startLevel);
            SetLevelDigits(m_startLevel, m_level);
            SetStat1Digits(stat1);
            SetStat2Digits(stat2);
            m_audio->sub_02034C5C(54);
            m_audio->sub_02034DE8(11, 0, 256);
            m_frame = 0;
            m_state = 9;
        } else {
            m_audio->sub_02034C5C(54);
            m_frame = 0;
            m_state = 10;
        }
        return;
    }

    UnkClass_02001C04 *pad = CGame::GetInstance()->unk_0014;
    CTouchPanel *touch = CGame::GetInstance()->touchPanel;
    if ((u16)(pad->unk_0000 & PAD_BUTTON_A) || touch->unk_05 != 0) {
        m_tally += 2;
        if (m_tally > 64) {
            m_tally = 64;
        }
    } else {
        m_tally++;
    }

    m_shownExp = LinearInterpolate(m_exp << FX32_SHIFT, 0, m_tally, 64);
    if (!m_maxLevel) {
        m_shownTotal = LinearInterpolate(0, m_exp << FX32_SHIFT, m_tally, 64);
        m_shownTotal += m_save->unk_0028 << FX32_SHIFT;
        m_shownTotal -= m_levelExp << FX32_SHIFT;
    }

    if ((m_shownTotal >> FX32_SHIFT) >= m_nextExp && !m_maxLevel) {
        u32 exp = m_save->unk_0028;
        m_levelExp += sub_02010EAC(m_levelTable, m_level) - exp;
        m_level++;
        m_nextExp = sub_02010EAC(m_levelTable, m_level);
        m_save->unk_0028 = 0;
        sub_020160B8(m_save, m_level);
        if (m_level == sub_02010E60(CGame::GetInstance()->unk_1438)) {
            m_maxLevel = TRUE;
        }
        SetExpDigits(m_exp - m_levelExp);
        SetExpBar(1, 1);
        SetExpLabelPos(0, 0x18000);
        MoveExpBar(0, 0x18000);
        u8 hp = m_save->unk_0002;
        m_disk->unk_19C = hp;
        m_gauge->SetHP(hp, hp);
        m_audio->sub_02034C5C(54);
        m_audio->sub_02034C44(55);
        m_frame = 0;
        m_state = 8;
        return;
    }

    SetExpDigits(m_shownExp >> FX32_SHIFT);
    SetExpLabelPos(0, 0x18000);
    SetExpBar(m_shownTotal, m_nextExp << FX32_SHIFT);
    MoveExpBar(0, 0x18000);
}

void UnkClass_021384F8::ov1_021396C0()
{
    if (m_tally >= 64) {
        UnkClass_020B26A0 *save = m_save;
        int total;
        if (MATH_IAbs(m_exp) >= save->unk_0028) {
            total = 0;
        } else {
            total = m_exp + save->unk_0028;
        }
        if (total < 0) {
            total = 0;
        }
        save->unk_0028 = total;
        m_audio->sub_02034C5C(54);
        m_frame = 0;
        m_state = 10;
        return;
    }

    UnkClass_02001C04 *pad = CGame::GetInstance()->unk_0014;
    CTouchPanel *touch = CGame::GetInstance()->touchPanel;
    if ((u16)(pad->unk_0000 & PAD_BUTTON_A) || touch->unk_05 != 0) {
        m_tally += 2;
        if (m_tally > 64) {
            m_tally = 64;
        }
    } else {
        m_tally++;
    }

    m_shownExp = LinearInterpolate(m_exp << FX32_SHIFT, 0, m_tally, 64);
    m_shownTotal = LinearInterpolate(0, m_exp << FX32_SHIFT, m_tally, 64);
    m_shownTotal += m_save->unk_0028 << FX32_SHIFT;
    SetExpDigits(m_shownExp >> FX32_SHIFT);
    SetExpBar(m_shownTotal, m_nextExp << FX32_SHIFT);
    SetExpLabelPos(0, 0x18000);
}

void UnkClass_021384F8::ov1_021397FC()
{
    m_expBar.m_alpha = (u8)LinearInterpolate(31, 4, m_frame, 32);
    m_expBar.m_color = GX_RGB(31, 31, 31);
    if (m_frame >= 64) {
        m_audio->sub_02034C44(54);
        m_frame = 0;
        m_state = 6;
    }
}

void UnkClass_021384F8::ov1_0213985C()
{
    SetLevelPos(LinearInterpolate(-0x100000, -0x80000, m_frame, 8), 0x28000);
    SetStat1Pos(LinearInterpolate(0x140000, 0x80000, m_frame, 8), 0x28000);
    SetStat2Pos(LinearInterpolate(0x140000, 0x80000, m_frame, 8), 0x28000);
    if (m_frame >= 40) {
        m_frame = 0;
        m_state = 10;
    }
}

void UnkClass_021384F8::ov1_021398F4()
{
    SetPromptPos(0, -0x2C000);
    m_angle += 0x400;
    if (m_angle >= 0x8000) {
        m_angle -= 0x8000;
    }
    m_prompt0.m_coords[1] = FX32_MUL(FX_SinIdx(m_angle), 0x8000) - 0x2C000;
    m_prompt0.m_alpha = 31;
    m_prompt1.m_alpha = 31;

    UnkClass_02001C04 *pad = CGame::GetInstance()->unk_0014;
    CTouchPanel *touch = CGame::GetInstance()->touchPanel;
    if (touch->unk_04 != 0 || (u16)(pad->unk_0002 & PAD_BUTTON_A)) {
        m_frame = 0;
        m_state = 0;
    }
}

void UnkClass_021384F8::ov1_021399A8(Camera2D *camera)
{
    m_panel0.Render(camera);
    m_panel1.Render(camera);
    m_panel2.Render(camera);
    m_levelLabel0.Render(camera);
    m_levelLabel1.Render(camera);
    m_levelLabel2.Render(camera);
    for (int i = 0; i < 2; i++) {
        m_levelFrom[i].Render(camera);
    }
    for (int i = 0; i < 2; i++) {
        m_levelTo[i].Render(camera);
    }
    m_stat1Label0.Render(camera);
    m_stat1Label1.Render(camera);
    for (int i = 0; i < 3; i++) {
        m_stat1Digits[i].Render(camera);
    }
    m_stat2Label0.Render(camera);
    m_stat2Label1.Render(camera);
    for (int i = 0; i < 3; i++) {
        m_stat2Digits[i].Render(camera);
    }
    m_expLabel0.Render(camera);
    m_expLabel1.Render(camera);
    m_expBar.Render(camera);
    for (int i = 0; i < 4; i++) {
        m_expDigits[i].Render(camera);
    }
    m_bonusLabel0.Render(camera);
    m_bonusLabel1.Render(camera);
    for (int i = 0; i < 5; i++) {
        m_bonusDigits[i].Render(camera);
    }
    m_prompt0.Render(camera);
    m_prompt1.Render(camera);
}

void UnkClass_021384F8::ov1_02139C30(CBattleDisk *disk, CPlayerHPGauge *gauge)
{
    m_exp = (m_bonusFlags & 0x20000) ? 0 : m_baseExp;
    m_tally = 0;
    m_shownExp = m_exp;
    m_shownTotal = m_exp;
    m_levelExp = 0;
    m_startLevel = m_save->unk_87DB;
    m_level = m_startLevel;
    m_nextExp = sub_02010EAC(m_levelTable, m_startLevel);
    m_audio->sub_02034A40(4, 1);
    m_disk = disk;
    m_gauge = gauge;
    m_maxLevel = m_startLevel == sub_02010E60(CGame::GetInstance()->unk_1438);
    m_frame = 0;
    m_state = 1;
}

int UnkClass_021384F8::ov1_02139CE4(int z)
{
    int front = z + 0x40;
    int back = z + 0x20;

    m_panel0.m_z = front;
    m_panel1.m_z = front;
    m_panel2.m_z = back;
    m_levelLabel0.m_z = front;
    m_levelLabel2.m_z = front;
    m_levelLabel1.m_z = back;
    for (int i = 0; i < 2; i++) {
        m_levelFrom[i].m_z = front;
    }
    for (int i = 0; i < 2; i++) {
        m_levelTo[i].m_z = front;
    }
    m_stat1Label0.m_z = front;
    m_stat1Label1.m_z = back;
    for (int i = 0; i < 3; i++) {
        m_stat1Digits[i].m_z = front;
    }
    m_stat2Label0.m_z = front;
    m_stat2Label1.m_z = back;
    for (int i = 0; i < 3; i++) {
        m_stat2Digits[i].m_z = front;
    }
    m_prompt0.m_z = front;
    m_prompt1.m_z = front;
    m_expLabel0.m_z = front;
    m_expLabel1.m_z = back;
    m_expBar.m_z = front;
    for (int i = 0; i < 4; i++) {
        m_expDigits[i].m_z = back;
    }
    m_bonusLabel0.m_z = front;
    m_bonusLabel1.m_z = back;
    for (int i = 0; i < 5; i++) {
        m_bonusDigits[i].m_z = back;
    }
    return z + 0x41;
}

void UnkClass_021384F8::SetPanelPos(fx32 x, fx32 y)
{
    m_panel0.SetXY(x, y);
    m_panel1.SetXY(x, y);
    m_panel2.SetXY(x, y);
}

void UnkClass_021384F8::SetLevelPos(fx32 x, fx32 y)
{
    int i;

    m_levelLabel0.SetXY(x, y - 0x2000);
    m_levelLabel1.SetXY(x, y);
    m_levelLabel2.SetXY(x, y - 0x6000);
    fx32 digitY = y + 0x17000;
    x += 0x1A000;
    for (i = 0; i < 2; i++) {
        m_levelFrom[i].SetXY(x, digitY);
        x += 0x10000;
    }
    x += 0x9000;
    for (i = 0; i < 2; i++) {
        m_levelTo[i].SetXY(x, digitY);
        x += 0x10000;
    }
}

void UnkClass_021384F8::SetStat1Pos(fx32 x, fx32 y)
{
    int i;

    m_stat1Label0.SetXY(x, y);
    m_stat1Label1.SetXY(x, y);
    fx32 digitY = y + 0x2000;
    x -= 0x30000;
    for (i = 0; i < 3; i++) {
        m_stat1Digits[i].SetXY(x, digitY);
        x += 0x10000;
    }
}

void UnkClass_021384F8::SetStat2Pos(fx32 x, fx32 y)
{
    int i;

    m_stat2Label0.SetXY(x, y);
    m_stat2Label1.SetXY(x, y);
    fx32 digitY = y + 0x1F000;
    x -= 0x40000;
    for (i = 0; i < 3; i++) {
        m_stat2Digits[i].SetXY(x, digitY);
        x += 0x10000;
    }
}

void UnkClass_021384F8::SetExpLabelPos(fx32 x, fx32 y)
{
    m_expLabel0.SetXY(x, y);
    m_expLabel1.SetXY(x, y);
}

static inline void SetVertex(CPrimitiveQUAD *quad, u8 i, Point2D pos)
{
    ((Point2D *)&quad->m_vtxCoords)[i] = pos;
}

void UnkClass_021384F8::MoveExpBar(fx32 x, fx32 y)
{
    x -= 0x12000;
    y -= 0x6000;
    for (u8 i = 0; i < 4; i++) {
        Point2D p;
        Point2D v = ((Point2D *)&m_expBar.m_vtxCoords)[i];
        p.x = v.x + x;
        p.y = v.y + y;
        SetVertex(&m_expBar, i, p);
    }
}

void UnkClass_021384F8::SetExpPos(fx32 x, fx32 y)
{
    int i;

    fx32 digitY = y - 0xC000;
    x += 0x10000;
    for (i = 0; i < 4; i++) {
        m_expDigits[i].SetXY(x, digitY);
        x += 0x20000;
    }
}

void UnkClass_021384F8::SetBonusPos(fx32 x, fx32 y)
{
    int i;

    m_bonusLabel0.SetXY(x, y);
    m_bonusLabel1.SetXY(x, y);
    fx32 digitY = y + 0x32000;
    x -= 0x10000;
    for (i = 0; i < 5; i++) {
        m_bonusDigits[i].SetXY(x, digitY);
        x += 0x20000;
    }
}

void UnkClass_021384F8::SetPromptPos(fx32 x, fx32 y)
{
    m_prompt0.SetXY(x, y);
    m_prompt1.SetXY(x, y);
}

static inline void SetDigit(CSoftwareSprite *sprite, const char *c)
{
    if (*c == ' ') {
        sprite->m_alpha = 0;
    } else {
        sprite->m_alpha = 31;
        switch (*c) {
        case '+':
            sprite->m_cellDataIdx = 46;
            break;
        case '-':
            sprite->m_cellDataIdx = 47;
            break;
        default:
            sprite->m_cellDataIdx = *c - '0' + 36;
            break;
        }
    }
}

void UnkClass_021384F8::SetExpDigits(s16 exp)
{
    char buf[8];

    if (exp >= 10000) {
        OS_SPrintf(buf, "%4d", 9999);
    } else {
        OS_SPrintf(buf, "%4d", exp);
    }
    for (int i = 0; i < 4; i++) {
        SetDigit(&m_expDigits[i], &buf[i]);
    }
}

void UnkClass_021384F8::SetExpBar(fx32 exp, fx32 next)
{
    u8 width;

    if (m_maxLevel) {
        width = 139;
    } else if (exp >= next) {
        width = 139;
    } else if (exp <= 0) {
        width = 0;
    } else {
        width = FX32_MUL(FX32_DIV(exp, next), 139 << FX32_SHIFT) >> FX32_SHIFT;
    }

    if (width != 0) {
        m_expBar.m_alpha = 31;
    } else {
        m_expBar.m_alpha = 1;
        return;
    }
    m_expBar.m_color = GX_RGB(16, 31, 16);
    m_expBar.m_vtxCoords.x1 = 0;
    m_expBar.m_vtxCoords.y1 = 0;
    m_expBar.m_vtxCoords.x2 = width << FX32_SHIFT;
    m_expBar.m_vtxCoords.y2 = 0;
    m_expBar.m_vtxCoords.x3 = width << FX32_SHIFT;
    m_expBar.m_vtxCoords.y3 = 0x2000;
    m_expBar.m_vtxCoords.x4 = 0;
    m_expBar.m_vtxCoords.y4 = 0x2000;
}

void UnkClass_021384F8::SetBonusDigits(s16 bonus)
{
    char buf[8];

    if (bonus < 0) {
        OS_SPrintf(buf, "%5d", bonus);
    } else {
        OS_SPrintf(buf, "+%4d", bonus);
    }
    for (int i = 0; i < 5; i++) {
        SetDigit(&m_bonusDigits[i], &buf[i]);
    }
}

void UnkClass_021384F8::SetLevelDigits(u8 from, u8 to)
{
    char buf[4];

    OS_SPrintf(buf, "%2d", from);
    for (int i = 0; i < 2; i++) {
        SetDigit(&m_levelFrom[i], &buf[i]);
    }
    OS_SPrintf(buf, "%2d", to);
    for (int i = 0; i < 2; i++) {
        SetDigit(&m_levelTo[i], &buf[i]);
    }
}

void UnkClass_021384F8::SetStat1Digits(u8 value)
{
    char buf[4];

    OS_SPrintf(buf, "+%2d", value);
    for (int i = 0; i < 3; i++) {
        SetDigit(&m_stat1Digits[i], &buf[i]);
    }
}

void UnkClass_021384F8::SetStat2Digits(u8 value)
{
    char buf[4];

    OS_SPrintf(buf, "+%2d", value);
    for (int i = 0; i < 3; i++) {
        SetDigit(&m_stat2Digits[i], &buf[i]);
    }
}

u8 UnkClass_021384F8::ov1_0213A4A0(u16 score)
{
    for (u8 i = 0; i < 4; i++) {
        if (score >= sRankScores[i]) {
            return i;
        }
    }
    return 3;
}
