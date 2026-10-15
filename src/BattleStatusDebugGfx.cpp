#include "battle/BattleStatusDebugGfx.hpp"

#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "battle/BattleStatusDebug.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "primitive/CSoftwareSprite.hpp"

BattleStatusDebugGfx::BattleStatusDebugGfx()
{
    Load();
}

BattleStatusDebugGfx::~BattleStatusDebugGfx()
{
    Release();
}

void BattleStatusDebugGfx::Load()
{
    CArchiveGuard *guard = new CArchiveGuard("BST", "data/battle/system/battle_status_debug_LZ.bin", 1, 1, 0, NULL, 0);

    m_image = new VramImage("BST:battle_status_debug.NCBR", 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->LoadToVram(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->Release();

    m_palette = new VramPalette("BST:battle_status_debug.NCLR", 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->LoadToVram(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->Release();

    m_cells = new CNCERFile("BST:battle_status_debug.NCER", 0, 0, 0);

    SAFE_DELETE(guard);
}

void BattleStatusDebugGfx::Release()
{
    SAFE_DELETE(m_image);
    SAFE_DELETE(m_palette);
    SAFE_DELETE(m_cells);
    NNS_GfdFreeLnkTexVram(m_texKey);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}

BattleStatusDebug::BattleStatusDebug()
{
    m_data = NULL;
    m_sprite = new CSoftwareSprite();
    m_sprite->SetTransformParams(0, 0, 0x1000, 0x1000, 0, 0x401);
    m_sprite->m_color = GX_RGB(31, 31, 31);
    m_sprite->m_alpha = 31;
    m_sprite->m_polygonID = 0;
}

BattleStatusDebug::~BattleStatusDebug()
{
    SAFE_DELETE(m_sprite);
}

void BattleStatusDebug::SetData(BattleStatusDebugGfx *data)
{
    m_data = data;
    m_sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)data->m_image, NULL);
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)data->m_palette;
    m_sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)data->m_cells;
    m_sprite->m_cellDataIdx = 0;
}
