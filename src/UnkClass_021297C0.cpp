#include "battle/UnkClass_021297C0.hpp"

#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "battle/CaptureMark.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "interpolation.hpp"
#include "primitive/CSoftwareSprite.hpp"

UnkClass_021297C0::UnkClass_021297C0()
{
    Load();
}

UnkClass_021297C0::~UnkClass_021297C0()
{
    Release();
}

void UnkClass_021297C0::Load()
{
    CArchiveGuard *guard = new CArchiveGuard("BOK", "data/interface/i026_LZ.bin", 1, 1, 0, NULL, 0);

    m_image = new VramImage("BOK:i026_00.NCBR", 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->LoadToVram(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->Release();

    m_palette = new VramPalette("BOK:i026.NCLR", 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->LoadToVram(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->Release();

    m_cells = new CNCERFile("BOK:i026_00.NCER", 0, 0, 0);

    SAFE_DELETE(guard);
}

void UnkClass_021297C0::Release()
{
    SAFE_DELETE(m_image);
    SAFE_DELETE(m_palette);
    SAFE_DELETE(m_cells);
    NNS_GfdFreeLnkTexVram(m_texKey);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}

CaptureMark::CaptureMark()
{
    m_data = NULL;
    unk_08 = FALSE;
    m_sprite = new CSoftwareSprite();
    m_sprite->m_z = 0x400;
}

CaptureMark::~CaptureMark()
{
    SAFE_DELETE(m_sprite);
}

void CaptureMark::Update()
{
    if (!unk_08) {
        return;
    }
    m_frame++;
    if (m_duration <= m_frame) {
        unk_08 = FALSE;
        return;
    }
    if (m_frame <= 8) {
        m_scale = LinearInterpolate(0x4000, 0x1000, m_frame, 8);
    }
}

void CaptureMark::Render(Camera2D *camera)
{
    if (!unk_08) {
        return;
    }
    m_sprite->SetPos(m_pos);
    m_sprite->SetScale(m_scale, m_scale);
    m_sprite->Render(camera);
}

void CaptureMark::SetData(UnkClass_021297C0 *data)
{
    m_data = data;
    m_sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)data->m_image, NULL);
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)data->m_palette;
    m_sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)data->m_cells;
    m_sprite->m_cellDataIdx = 0;
}

void CaptureMark::Show(u16 duration)
{
    unk_08 = TRUE;
    m_duration = duration;
    m_frame = 0;
}

int CaptureMark::SetZ(int z)
{
    z += m_sprite->GetCellNumOAMAttrs(m_sprite->m_cellDataIdx);
    m_sprite->m_z = z;
    return z + 1;
}
