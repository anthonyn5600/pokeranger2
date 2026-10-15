#include "battle/CBattleEnemyGauge.hpp"

#include "CPlayerHPGauge.hpp"
#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "battle/BattleEnemyGaugeGfx.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "fx_utils.hpp"
#include "interpolation.hpp"

static inline void SetSpriteRes(CSoftwareSprite *sprite, VramImage *image, VramPalette *palette, CNCERFile *cells)
{
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)cells;
}

CBattleEnemyGauge::CBattleEnemyGauge(BattleEnemyGaugeGfx *res)
{
    m_res = res;
    Init();
}

CBattleEnemyGauge::~CBattleEnemyGauge()
{
}

void CBattleEnemyGauge::Init()
{
    SetZ(0x3FF);
    m_flags = 0;
    m_hp = 0;
    m_maxHP = 0;
    m_width = 0;
    unk_1E4 = 0;
    m_cell = 0;
    m_bar.SetVertexCoordinates(0, 0, 0, 0, 0, 0, 0, 0, m_z + 1);
    m_bar.m_color = 0x3FF;
    m_bar.m_alpha = 0x1F;
    u8 i;
    GraphicsSet *digits = m_res->m_digits;
    SetSpriteRes(&m_dmgLabel, digits->m_image, digits->m_palette, digits->m_cells);
    m_dmgLabel.m_cellDataIdx = 10;
    for (i = 0; i < 4; i++) {
        SetSpriteRes(&m_digits[i], digits->m_image, digits->m_palette, digits->m_cells);
    }
}

void CBattleEnemyGauge::Setup(int type, u16 hp, u16 maxHP, Point2D pos)
{
    m_hp = hp;
    m_maxHP = maxHP;
    m_flags = type;
    switch (m_flags) {
    case 1:
        m_width = 0x19;
        m_cell = 0;
        break;
    case 2:
        m_width = 0x29;
        m_cell = 1;
        break;
    case 4:
        m_width = 0x39;
        m_cell = 2;
        break;
    case 8:
        m_width = 0x99;
        m_cell = 3;
        break;
    }
    m_motion.SetPos(pos);
    m_flags |= 0x10;
}

void CBattleEnemyGauge::SetHP(u16 hp, Point2D pos)
{
    m_hp = hp;
    m_motion.SetPos(pos);
}

void CBattleEnemyGauge::vfunc_08()
{
    fx32 width = m_width << FX32_SHIFT;
    Point2D pos = m_motion.GetPos();
    fx32 left = pos.x - FX32_MUL(width, FX32_HALF);
    fx32 top = pos.y - FX32_ONE;
    fx32 len = FX32_MUL(width, FX32_DIV((m_maxHP - m_hp) << FX32_SHIFT, m_maxHP << FX32_SHIFT));
    m_barLen = len;
    if (m_flags & 8) {
        left += 0x8000;
    }
    m_bar.SetVertexCoordinates(left, top, left + len, top, left + len, top + 0x3000, left, top + 0x3000, (u16)(m_z + 1));
    switch (m_dmgState) {
    case 0:
        break;
    case 1:
        UpdateDamageIn();
        break;
    case 2:
        UpdateDamageHold();
        break;
    case 3:
        UpdateDamageOut();
        break;
    }
}

BOOL CBattleEnemyGauge::IsVisible()
{
    return (m_flags & 0x10) != 0;
}

void CBattleEnemyGauge::vfunc_0C(Camera2D *camera)
{
    if (!IsVisible()) {
        return;
    }
    CSoftwareSprite *sprite = m_sprite;
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)m_res->m_image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)m_res->m_palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)m_res->m_cells;
    sprite->m_cellDataIdx = m_cell;
    sprite->SetPos(m_motion.GetPos());
    sprite->Render(camera);
    if (m_hp < m_maxHP) {
        m_bar.Render(camera);
    }
    if (m_dmgState == 0) {
        return;
    }
    fx32 width = m_width << FX32_SHIFT;
    Point2D pos = m_motion.GetPos();
    pos.x = pos.x - FX32_MUL(width, FX32_HALF) + 0x8000;
    pos.x += m_dmgOffset;
    pos.x += m_barLen;
    pos.y -= FX32_ONE;
    m_dmgLabel.SetPos(pos);
    m_dmgLabel.Render(camera);
    pos.x += 0x5000;
    for (u8 i = 0; i < m_digitCount; i++) {
        m_digits[i].SetPos(pos);
        m_digits[i].Render(camera);
        pos.x += 0x5000;
    }
}

void CBattleEnemyGauge::vfunc_10(Camera2D *camera)
{
}

int CBattleEnemyGauge::SetZ(int z)
{
    CSoftwareSprite *sprite = m_sprite;
    z = sprite->GetCellNumOAMAttrs(sprite->m_cellDataIdx);
    sprite->m_z = z;
    m_bar.m_z = z + 1;
    m_dmgLabel.m_z = z + 2;
    for (u8 i = 0; i < 4; i++) {
        m_digits[i].m_z = z + 2;
    }
    m_z = z + 3;
    return m_z;
}

void CBattleEnemyGauge::ShowDamage(int damage)
{
    if ((u32)damage >= 10000) {
        m_damage = 9999;
    } else {
        m_damage = damage;
    }
    m_dmgFrame = 0;
    m_dmgState = 1;
    char buf[8];
    m_digitCount = OS_SPrintf(buf, "%d", damage);
    for (u8 i = 0; i < m_digitCount; i++) {
        m_digits[i].m_cellDataIdx = (u8)(buf[i] - '0');
    }
}

void CBattleEnemyGauge::UpdateDamageIn()
{
    m_dmgFrame++;
    if (m_dmgFrame >= 12) {
        m_dmgFrame = 0;
        m_dmgState = 2;
    }
    m_dmgOffset = LinearInterpolate(-0x8000, 0, m_dmgFrame, 12);
    u8 alpha = LinearInterpolate(1, 0x1F, m_dmgFrame, 12);
    m_dmgLabel.m_alpha = alpha;
    for (u8 i = 0; i < 4; i++) {
        m_digits[i].m_alpha = alpha;
    }
}

void CBattleEnemyGauge::UpdateDamageHold()
{
    m_dmgFrame++;
    if (m_dmgFrame >= 0x20) {
        m_dmgFrame = 0;
        m_dmgState = 3;
    }
    m_dmgOffset = 0;
    m_dmgLabel.m_alpha = 0x1F;
    for (u8 i = 0; i < 4; i++) {
        m_digits[i].m_alpha = 0x1F;
    }
}

void CBattleEnemyGauge::UpdateDamageOut()
{
    m_dmgFrame++;
    if (m_dmgFrame >= 12) {
        m_dmgFrame = 0;
        m_dmgState = 0;
    }
    m_dmgOffset = LinearInterpolate(0, 0x8000, m_dmgFrame, 12);
    u8 alpha = LinearInterpolate(0x1F, 1, m_dmgFrame, 12);
    m_dmgLabel.m_alpha = alpha;
    for (u8 i = 0; i < 4; i++) {
        m_digits[i].m_alpha = alpha;
    }
}

BattleEnemyGaugeGfx::BattleEnemyGaugeGfx()
{
    Load();
}

BattleEnemyGaugeGfx::~BattleEnemyGaugeGfx()
{
    Release();
}

void BattleEnemyGaugeGfx::Load()
{
    CArchiveGuard *guard = new CArchiveGuard("BEG", "data/interface/i000_LZ.bin", 1, 1, 0, NULL, 0);

    m_image = new VramImage("BEG:i000_00.NCBR", 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->LoadToVram(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->Release();

    m_palette = new VramPalette("BEG:i000.NCLR", 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->LoadToVram(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->Release();

    m_cells = new CNCERFile("BEG:i000_00.NCER", 1, 0, 0);

    SAFE_DELETE(guard);

    m_digits = new GraphicsSet("BDN", "/data/interface/i070_LZ.bin", "BDN:i070_00.NCBR", "BDN:i070.NCLR", "BDN:i070_00.NCER", "BDN:i070_00.cac");
}

void BattleEnemyGaugeGfx::Release()
{
    SAFE_DELETE(m_image);
    SAFE_DELETE(m_palette);
    SAFE_DELETE(m_cells);
    NNS_GfdFreeLnkTexVram(m_texKey);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
    SAFE_DELETE(m_digits);
}
