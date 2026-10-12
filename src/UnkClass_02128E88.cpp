#include "battle/UnkClass_02128E88.hpp"

#include "UnkClass_020074D4.hpp"
#include "UnkClass_02007AA4.hpp"
#include "UnkClass_02008788.hpp"
#include "battle/UnkClass_021291BC.hpp"
#include "file/CArchiveGuard.hpp"
#include "file/CNCERFile.hpp"
#include "fx_utils.hpp"
#include "interpolation.hpp"
#include "primitive/CSoftwareSprite.hpp"

UnkClass_02128E88::UnkClass_02128E88()
{
    ov1_02128EB0();
}

UnkClass_02128E88::~UnkClass_02128E88()
{
    ov1_021290D4();
}

void UnkClass_02128E88::ov1_02128EB0()
{
    char path[0x60];
    const char *archive = "BST";
    u8 num = 29;

    for (int i = 1; i < 5; i++) {
        OS_SPrintf(path, "data/interface/i%03d_LZ.bin", num);
        CArchiveGuard *guard = new CArchiveGuard(archive, path, 1, 1, 0, NULL, 0);

        OS_SPrintf(path, "%s:i%03d_00.NCBR", archive, num);
        m_image[i] = new UnkClass_020074D4(path, 0, 0, 0);
        m_texKey[i] = NNS_GfdAllocLnkTexVram(m_image[i]->unk_38, FALSE, 0);
        m_image[i]->sub_020076E8(NNS_GfdGetTexKeyAddr(m_texKey[i]));
        m_image[i]->sub_020076B0();

        OS_SPrintf(path, "%s:i%03d.NCLR", archive, num);
        m_palette[i] = new UnkClass_02007AA4(path, 0, 0);
        m_plttKey[i] = NNS_GfdAllocLnkPlttVram(m_palette[i]->unk_04->szByte, FALSE, 0);
        m_palette[i]->sub_02007BFC(NNS_GfdGetPlttKeyAddr(m_plttKey[i]));
        m_palette[i]->sub_02007BC4();

        OS_SPrintf(path, "%s:i%03d_00.NCER", archive, num);
        m_cells[i] = new CNCERFile(path, 0, 0, 0);

        OS_SPrintf(path, "%s:i%03d_00.cac", archive, num);
        m_anim[i] = new UnkClass_02008788();
        m_anim[i]->sub_0200887C(path, 0, 0);

        SAFE_DELETE(guard);
        num++;
    }
}

void UnkClass_02128E88::ov1_021290D4()
{
    for (int i = 1; i < 5; i++) {
        SAFE_DELETE(m_image[i]);
        SAFE_DELETE(m_palette[i]);
        SAFE_DELETE(m_cells[i]);
        SAFE_DELETE(m_anim[i]);
        NNS_GfdFreeLnkTexVram(m_texKey[i]);
        NNS_GfdFreeLnkPlttVram(m_plttKey[i]);
    }
}

UnkClass_021291BC::UnkClass_021291BC()
{
    m_data = NULL;
    m_offsetY = 0;
    m_sprite = new CSoftwareSprite();
    m_sprite->SetTransformParams(0, 0, FX32_ONE, FX32_ONE, 0, 0);
    m_sprite->m_color = GX_RGB(31, 31, 31);
    m_sprite->m_alpha = 31;
    m_sprite->m_polygonID = 0;
}

UnkClass_021291BC::~UnkClass_021291BC()
{
    SAFE_DELETE(m_sprite);
}

void UnkClass_021291BC::ov1_02129274(UnkClass_02128E88 *data)
{
    m_data = data;
    m_sprite->m_cellDataIdx = 0;
    for (int i = 1; i < 5; i++) {
        m_animIds[i] = data->GetAnim(i)->sub_02008A80(1, 0);
    }
}

void UnkClass_021291BC::ov1_021292CC()
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
    m_data->GetAnim(m_state)->sub_02008A38(m_animIds[m_state]);
}

void UnkClass_021291BC::ov1_02129368(Camera2D *camera)
{
    m_sprite->m_coords[0] = m_pos.x;
    m_sprite->m_coords[1] = m_pos.y - m_offsetY;
    m_sprite->m_cellDataIdx = m_data->GetAnim(m_state)->sub_02008828(m_animIds[m_state]);
    m_sprite->Render(camera);
}

void UnkClass_021291BC::ov1_021293D4(Camera2D *camera)
{
}

void UnkClass_021291BC::ov1_021293D8(int state)
{
    m_state = state;
    if (state == 0) {
        unk_08 = FALSE;
        return;
    }
    m_sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)m_data->GetImage(state), NULL);
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)m_data->GetPalette(state);
    m_sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)m_data->GetCells(state);
    m_data->GetAnim(m_state)->sub_020089B8(m_animIds[m_state]);
    m_sprite->m_cellDataIdx = m_data->GetAnim(m_state)->sub_02008828(m_animIds[m_state]);
    m_frame = 0;
    unk_08 = TRUE;
}

int UnkClass_021291BC::ov1_02129490(int z)
{
    z += m_sprite->GetCellNumOAMAttrs(m_sprite->m_cellDataIdx);
    m_sprite->m_z = z;
    return z + 1;
}
