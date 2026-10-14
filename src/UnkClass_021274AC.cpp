#include "battle/UnkClass_021274AC.hpp"

#include "CellAnimController.hpp"
#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "battle/UnkClass_0212770C.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "interpolation.hpp"
#include "primitive/CSoftwareSprite.hpp"

UnkClass_021274AC::UnkClass_021274AC()
{
    ov1_021274D4();
}

UnkClass_021274AC::~UnkClass_021274AC()
{
    ov1_02127654();
}

void UnkClass_021274AC::ov1_021274D4()
{
    CArchiveGuard *guard = new CArchiveGuard("BEX", "data/interface/i034_LZ.bin", 1, 1, 0, NULL, 0);

    m_image = new VramImage("BEX:i034_00.NCBR", 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->LoadToVram(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->Release();

    m_palette = new VramPalette("BEX:i034.NCLR", 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->LoadToVram(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->Release();

    m_cells = new CNCERFile("BEX:i034_00.NCER", 0, 0, 0);
    m_anim = new CellAnimController();
    m_anim->Load("BEX:i034_00.cac", 0, 0);

    SAFE_DELETE(guard);
}

void UnkClass_021274AC::ov1_02127654()
{
    SAFE_DELETE(m_image);
    SAFE_DELETE(m_palette);
    SAFE_DELETE(m_cells);
    SAFE_DELETE(m_anim);
    NNS_GfdFreeLnkTexVram(m_texKey);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}

UnkClass_0212770C::UnkClass_0212770C()
{
    m_data = NULL;
    unk_08 = FALSE;
    m_sprite = new CSoftwareSprite();
    m_sprite->m_z = 0x400;
}

UnkClass_0212770C::~UnkClass_0212770C()
{
    SAFE_DELETE(m_sprite);
}

void UnkClass_0212770C::ov1_02127780()
{
    if (!unk_08) {
        return;
    }
    m_frame++;
    if (m_frame > 16) {
        m_offsetY = 0;
    } else {
        m_offsetY = FX32_MUL(FX_SinIdx((u16)LinearInterpolate(0, 0x8000, m_frame, 16)), 0x10000);
    }
    if (m_frame >= m_duration) {
        unk_08 = FALSE;
    }
}

void UnkClass_0212770C::ov1_02127810(Camera2D *camera)
{
    if (!unk_08) {
        return;
    }
    m_sprite->m_coords[0] = m_pos.x;
    m_sprite->m_coords[1] = m_pos.y - m_offsetY;
    m_sprite->Render(camera);
}

void UnkClass_0212770C::ov1_02127854(UnkClass_021274AC *data)
{
    m_data = data;
    m_sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)data->m_image, NULL);
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)data->m_palette;
    m_sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)data->m_cells;
}

void UnkClass_0212770C::ov1_02127888(int cell, u16 duration)
{
    if (m_data == NULL || duration == 0) {
        return;
    }
    unk_08 = TRUE;
    m_duration = duration;
    m_frame = 0;
    m_cell = cell;
    m_sprite->m_cellDataIdx = cell;
}

int UnkClass_0212770C::ov1_021278BC(int z)
{
    z += m_sprite->GetCellNumOAMAttrs(m_sprite->m_cellDataIdx);
    m_sprite->m_z = z;
    return z + 1;
}
