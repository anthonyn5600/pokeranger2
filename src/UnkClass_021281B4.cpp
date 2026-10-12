#include "battle/UnkClass_021281B4.hpp"

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "UnkClass_02008788.hpp"
#include "battle/UnkClass_02128414.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "primitive/CSoftwareSprite.hpp"

UnkClass_021281B4::UnkClass_021281B4()
{
    ov1_021281DC();
}

UnkClass_021281B4::~UnkClass_021281B4()
{
    ov1_0212835C();
}

void UnkClass_021281B4::ov1_021281DC()
{
    CArchiveGuard *guard = new CArchiveGuard("BSW", "data/interface/i028_LZ.bin", 1, 1, 0, NULL, 0);

    m_image = new UnkClass_020074D4("BSW:i028_00.NCBR", 0, 0, 0);
    m_texKey = NNS_GfdAllocLnkTexVram(m_image->unk_38, FALSE, 0);
    m_image->sub_020076E8(NNS_GfdGetTexKeyAddr(m_texKey));
    m_image->sub_020076B0();

    m_palette = new UnkClass_02007AA4("BSW:i028.NCLR", 0, 0);
    m_plttKey = NNS_GfdAllocLnkPlttVram(m_palette->unk_04->szByte, FALSE, 0);
    m_palette->sub_02007BFC(NNS_GfdGetPlttKeyAddr(m_plttKey));
    m_palette->sub_02007BC4();

    m_cells = new CNCERFile("BSW:i028_00.NCER", 0, 0, 0);
    m_anim = new UnkClass_02008788();
    m_anim->sub_0200887C("BSW:i028_00.cac", 0, 0);

    SAFE_DELETE(guard);
}

void UnkClass_021281B4::ov1_0212835C()
{
    SAFE_DELETE(m_image);
    SAFE_DELETE(m_palette);
    SAFE_DELETE(m_cells);
    SAFE_DELETE(m_anim);
    NNS_GfdFreeLnkTexVram(m_texKey);
    NNS_GfdFreeLnkPlttVram(m_plttKey);
}

UnkClass_02128414::UnkClass_02128414()
{
    m_data = NULL;
    unk_08 = FALSE;
    m_sprite = new CSoftwareSprite();
    m_sprite->m_z = 0x3FF;
}

UnkClass_02128414::~UnkClass_02128414()
{
    m_data->m_anim->sub_02008B80(m_animId);
    SAFE_DELETE(m_sprite);
}

void UnkClass_02128414::ov1_0212849C()
{
    if (!unk_08) {
        return;
    }
    m_data->m_anim->sub_02008A38(m_animId);
}

void UnkClass_02128414::ov1_021284C0(Camera2D *camera)
{
    if (!unk_08) {
        return;
    }
    m_sprite->m_cellDataIdx = m_data->m_anim->sub_02008828(m_animId);
    m_sprite->SetPos(m_pos);
    m_sprite->Render(camera);
    if (!m_data->m_anim->sub_02008860(m_animId)) {
        unk_08 = FALSE;
    }
}

void UnkClass_02128414::ov1_0212854C(UnkClass_021281B4 *data)
{
    m_data = data;
    m_sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)data->m_image, NULL);
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)data->m_palette;
    m_sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)data->m_cells;
    m_animId = data->m_anim->sub_02008A80(1, 0);
}

void UnkClass_02128414::ov1_02128598(int anim)
{
    unk_08 = TRUE;
    m_data->m_anim->sub_02008990(m_animId, anim);
    m_data->m_anim->sub_020089B8(m_animId);
}

int UnkClass_02128414::ov1_021285D4(int z)
{
    z += m_sprite->GetCellNumOAMAttrs(m_sprite->m_cellDataIdx);
    m_sprite->m_z = z;
    return z + 1;
}
