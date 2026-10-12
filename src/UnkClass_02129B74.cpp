#include "battle/UnkClass_02129B74.hpp"

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "UnkClass_02008788.hpp"
#include "battle/UnkClass_02129DD4.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "interpolation.hpp"
#include "primitive/CPrimitiveSPHERE.hpp"
#include "primitive/CSoftwareSprite.hpp"

UnkClass_02129B74::UnkClass_02129B74()
{
    ov1_02129B9C();
}

UnkClass_02129B74::~UnkClass_02129B74()
{
    ov1_02129D1C();
}

void UnkClass_02129B74::ov1_02129B9C()
{
    CArchiveGuard *guard = new CArchiveGuard("BCE", "data/interface/i033_LZ.bin", 1, 1, 0, NULL, 0);

    m_image = new UnkClass_020074D4("BCE:i033_00.NCBR", 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->sub_020076E8(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->sub_020076B0();

    m_palette = new UnkClass_02007AA4("BCE:i033.NCLR", 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->sub_02007BFC(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->sub_02007BC4();

    m_cells = new CNCERFile("BCE:i033_00.NCER", 0, 0, 0);
    m_anim = new UnkClass_02008788();
    m_anim->sub_0200887C("BCE:i033_00.cac", 0, 0);

    SAFE_DELETE(guard);
}

void UnkClass_02129B74::ov1_02129D1C()
{
    SAFE_DELETE(m_image);
    SAFE_DELETE(m_palette);
    SAFE_DELETE(m_cells);
    SAFE_DELETE(m_anim);
    NNS_GfdFreeLnkTexVram(m_texKey);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}

UnkClass_02129DD4::UnkClass_02129DD4()
{
    m_data = NULL;
    unk_14 = FALSE;
    unk_04 = new CSoftwareSprite();
    unk_08 = new CSoftwareSprite();
    m_sphere = new CPrimitiveSPHERE();
    m_sphere->m_color = GX_RGB(31, 31, 31);
}

UnkClass_02129DD4::~UnkClass_02129DD4()
{
    m_data->m_anim->sub_02008B80(m_animId);
    SAFE_DELETE(unk_04);
    SAFE_DELETE(unk_08);
    SAFE_DELETE(m_sphere);
}

void UnkClass_02129DD4::ov1_02129ED4()
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
    m_data->m_anim->sub_02008A38(m_animId);
}

void UnkClass_02129DD4::ov1_02129FD0(Camera2D *camera)
{
    if (!unk_14) {
        return;
    }
    unk_04->m_cellDataIdx = m_data->m_anim->sub_02008828(m_animId);
    unk_04->Render(camera);
    if (unk_18 & 1) {
        unk_08->Render(camera);
    }
    if (unk_18 < 8) {
        m_sphere->Render(camera);
    }
}

void UnkClass_02129DD4::ov1_0212A058(UnkClass_02129B74 *data)
{
    m_data = data;
    unk_04->SetImage((UnkClass_CPrimitive_ImageProxy *)data->m_image, NULL);
    unk_04->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)data->m_palette;
    unk_04->unk_38 = (UnkClass_CSoftwareSprite_38 *)data->m_cells;
    unk_08->SetImage((UnkClass_CPrimitive_ImageProxy *)data->m_image, NULL);
    unk_08->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)data->m_palette;
    unk_08->unk_38 = (UnkClass_CSoftwareSprite_38 *)data->m_cells;
    unk_08->m_cellDataIdx = 8;
    m_animId = data->m_anim->sub_02008A80(1, 0);
}

int UnkClass_02129DD4::ov1_0212A0D8(int z)
{
    m_sphere->m_z = z;
    z += unk_04->GetCellNumOAMAttrs(unk_04->m_cellDataIdx);
    unk_04->m_z = z;
    z += unk_08->GetCellNumOAMAttrs(unk_08->m_cellDataIdx);
    unk_08->m_z = z;
    return z + 1;
}
