#include "battle/UnkClass_02129B74.hpp"

#include "CellAnimController.hpp"
#include "VramImage.hpp"
#include "VramPalette.hpp"
#include "battle/CaptureEffect.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "interpolation.hpp"
#include "primitive/CPrimitiveSPHERE.hpp"
#include "primitive/CSoftwareSprite.hpp"

UnkClass_02129B74::UnkClass_02129B74()
{
    Load();
}

UnkClass_02129B74::~UnkClass_02129B74()
{
    Release();
}

void UnkClass_02129B74::Load()
{
    CArchiveGuard *guard = new CArchiveGuard("BCE", "data/interface/i033_LZ.bin", 1, 1, 0, NULL, 0);

    m_image = new VramImage("BCE:i033_00.NCBR", 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->LoadToVram(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->Release();

    m_palette = new VramPalette("BCE:i033.NCLR", 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->LoadToVram(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->Release();

    m_cells = new CNCERFile("BCE:i033_00.NCER", 0, 0, 0);
    m_anim = new CellAnimController();
    m_anim->Load("BCE:i033_00.cac", 0, 0);

    SAFE_DELETE(guard);
}

void UnkClass_02129B74::Release()
{
    SAFE_DELETE(m_image);
    SAFE_DELETE(m_palette);
    SAFE_DELETE(m_cells);
    SAFE_DELETE(m_anim);
    NNS_GfdFreeLnkTexVram(m_texKey);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}

CaptureEffect::CaptureEffect()
{
    m_data = NULL;
    unk_14 = FALSE;
    unk_04 = new CSoftwareSprite();
    unk_08 = new CSoftwareSprite();
    m_sphere = new CPrimitiveSPHERE();
    m_sphere->m_color = GX_RGB(31, 31, 31);
}

CaptureEffect::~CaptureEffect()
{
    m_data->m_anim->Remove(m_animId);
    SAFE_DELETE(unk_04);
    SAFE_DELETE(unk_08);
    SAFE_DELETE(m_sphere);
}

void CaptureEffect::Update()
{
    if (!unk_14) {
        return;
    }
    if (unk_18 == 0) {
        unk_14 = FALSE;
        return;
    }
    unk_18--;
    fx32 scale = FX32_DIV(LinearInterpolate(0, unk_0C, unk_1A - unk_18, unk_1A), 0x10000);
    unk_08->SetScale(scale, scale);
    if (unk_18 < 8) {
        m_sphere->m_circle.pos = unk_08->GetPos();
        m_sphere->m_circle.r = LinearInterpolate(0x40000, 0x8000, unk_18, 8);
        m_sphere->m_alpha = (u8)LinearInterpolate(1, 0x10, unk_18, 8);
    }
    m_data->m_anim->Update(m_animId);
}

void CaptureEffect::Render(Camera2D *camera)
{
    if (!unk_14) {
        return;
    }
    unk_04->m_cellDataIdx = m_data->m_anim->GetCell(m_animId);
    unk_04->Render(camera);
    if (unk_18 & 1) {
        unk_08->Render(camera);
    }
    if (unk_18 < 8) {
        m_sphere->Render(camera);
    }
}

void CaptureEffect::SetData(UnkClass_02129B74 *data)
{
    m_data = data;
    unk_04->SetImage((UnkClass_CPrimitive_ImageProxy *)data->m_image, NULL);
    unk_04->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)data->m_palette;
    unk_04->unk_38 = (UnkClass_CSoftwareSprite_38 *)data->m_cells;
    unk_08->SetImage((UnkClass_CPrimitive_ImageProxy *)data->m_image, NULL);
    unk_08->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)data->m_palette;
    unk_08->unk_38 = (UnkClass_CSoftwareSprite_38 *)data->m_cells;
    unk_08->m_cellDataIdx = 8;
    m_animId = data->m_anim->Create(1, 0);
}

int CaptureEffect::SetZ(int z)
{
    m_sphere->m_z = z;
    z += unk_04->GetCellNumOAMAttrs(unk_04->m_cellDataIdx);
    unk_04->m_z = z;
    z += unk_08->GetCellNumOAMAttrs(unk_08->m_cellDataIdx);
    unk_08->m_z = z;
    return z + 1;
}
