#include "battle/BattleHPNumberGfx.hpp"

#include "CellAnimController.hpp"
#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "battle/BattleHPNumber.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "primitive/CSoftwareSprite.hpp"

static const u16 sDigitDivisors[] = { 10000, 1000, 100, 10, 1 };

BattleHPNumberGfx::BattleHPNumberGfx()
{
    ov1_02128628();
}

BattleHPNumberGfx::~BattleHPNumberGfx()
{
    ov1_021287A8();
}

void BattleHPNumberGfx::ov1_02128628()
{
    CArchiveGuard *guard = new CArchiveGuard("BHP", "data/battle/system/battle_number01_LZ.bin", 1, 1, 0, NULL, 0);

    m_image = new VramImage("BHP:battle_number01.NCBR", 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->LoadToVram(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->Release();

    m_palette = new VramPalette("BHP:battle_number01.NCLR", 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->LoadToVram(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->Release();

    m_cells = new CNCERFile("BHP:battle_number01.NCER", 0, 0, 0);
    m_anim = new CellAnimController();
    m_anim->Load("BHP:battle_number01.cac", 0, 0);

    SAFE_DELETE(guard);
}

void BattleHPNumberGfx::ov1_021287A8()
{
    SAFE_DELETE(m_image);
    SAFE_DELETE(m_palette);
    SAFE_DELETE(m_cells);
    SAFE_DELETE(m_anim);
    NNS_GfdFreeLnkTexVram(m_texKey);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}

BattleHPNumber::BattleHPNumber()
{
    m_data = NULL;
    m_sprite = new CSoftwareSprite();
    m_sprite->SetTransformParams(0, 0, FX32_ONE, FX32_ONE, 0, 0x401);
    m_sprite->m_color = GX_RGB(31, 31, 31);
    m_sprite->m_alpha = 31;
    m_sprite->m_polygonID = 0;
}

BattleHPNumber::~BattleHPNumber()
{
    SAFE_DELETE(m_sprite);
}

void BattleHPNumber::ov1_0212891C(BattleHPNumberGfx *data)
{
    m_data = data;
    m_sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)data->m_image, NULL);
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)data->m_palette;
    m_sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)data->m_cells;
    m_sprite->m_cellDataIdx = 0;
    m_animId = data->m_anim->Create(1, 0);
}

void BattleHPNumber::ov1_02128970(Camera2D *camera)
{
    BOOL started;
    u16 value;
    u8 digit;
    int i;
    u16 divisor;

    value = m_hp;
    Point2D pos = m_pos;
    m_sprite->SetPos(pos);
    m_sprite->m_cellDataIdx = 10;
    started = FALSE;
    m_sprite->Render(camera);

    for (i = 0; i < 5; i++) {
        divisor = sDigitDivisors[i];
        digit = value / divisor;
        if (digit != 0 || started) {
            m_sprite->SetPos(pos);
            m_sprite->m_cellDataIdx = digit;
            started = TRUE;
            m_sprite->Render(camera);
            pos.x += 0x4000;
        }
        value -= digit * divisor;
    }
}
