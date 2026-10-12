#include "battle/UnkClass_021294BC.hpp"

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "battle/UnkClass_021296C8.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "primitive/CSoftwareSprite.hpp"

UnkClass_021294BC::UnkClass_021294BC()
{
    ov1_021294E4();
}

UnkClass_021294BC::~UnkClass_021294BC()
{
    ov1_02129638();
}

void UnkClass_021294BC::ov1_021294E4()
{
    CArchiveGuard *guard = new CArchiveGuard("BST", "data/battle/system/battle_status_debug_LZ.bin", 1, 1, 0, NULL, 0);

    m_image = new UnkClass_020074D4("BST:battle_status_debug.NCBR", 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->sub_020076E8(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->sub_020076B0();

    m_palette = new UnkClass_02007AA4("BST:battle_status_debug.NCLR", 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->sub_02007BFC(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->sub_02007BC4();

    m_cells = new CNCERFile("BST:battle_status_debug.NCER", 0, 0, 0);

    SAFE_DELETE(guard);
}

void UnkClass_021294BC::ov1_02129638()
{
    SAFE_DELETE(m_image);
    SAFE_DELETE(m_palette);
    SAFE_DELETE(m_cells);
    NNS_GfdFreeLnkTexVram(m_texKey);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}

UnkClass_021296C8::UnkClass_021296C8()
{
    m_data = NULL;
    m_sprite = new CSoftwareSprite();
    m_sprite->SetTransformParams(0, 0, 0x1000, 0x1000, 0, 0x401);
    m_sprite->m_color = GX_RGB(31, 31, 31);
    m_sprite->m_alpha = 31;
    m_sprite->m_polygonID = 0;
}

UnkClass_021296C8::~UnkClass_021296C8()
{
    SAFE_DELETE(m_sprite);
}

void UnkClass_021296C8::ov1_02129784(UnkClass_021294BC *data)
{
    m_data = data;
    m_sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)data->m_image, NULL);
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)data->m_palette;
    m_sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)data->m_cells;
    m_sprite->m_cellDataIdx = 0;
}
