#include "battle/UnkClass_0213F028.hpp"

#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "UnkClass_02008788.hpp"
#include "UnkClass_020091E8.hpp"
#include "UnkClass_02033F04.hpp"
#include "UnkClass_02034478.hpp"
#include "interpolation.hpp"

static inline void SetSpriteRes(CSoftwareSprite *sprite, UnkClass_020074D4 *image, UnkClass_02007AA4 *palette, CNCERFile *cells)
{
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)cells;
}

UnkClass_0213F028::UnkClass_0213F028(u16 type)
{
    m_type = type;
    ov1_0213F0C8(type);
    Point2D pos;
    pos.x = 0;
    pos.y = 0x18000;
    SetPos(pos);
}

UnkClass_0213F028::~UnkClass_0213F028()
{
    ov1_0213F2B4();
}

void UnkClass_0213F028::ov1_0213F0C8(u16 type)
{
    char path[96];
    char ncbr[96];
    char nclr[96];
    char ncer[96];
    char cac[96];

    if (type == 7) {
        return;
    }
    if (type > 7) {
        return;
    }
    u8 id = type + 0x30;
    OS_SPrintf(path, "data/interface/i%03d_LZ.bin", id);
    OS_SPrintf(ncbr, "BCO:i%03d_00.NCBR", id);
    OS_SPrintf(nclr, "BCO:i%03d.NCLR", id);
    OS_SPrintf(ncer, "BCO:i%03d_00.NCER", id);
    OS_SPrintf(cac, "BCO:i%03d_00.cac", id);
    m_bannerRes = new UnkClass_0201AAE0("BCO", path, ncbr, nclr, ncer, cac);
    m_anim = m_bannerRes->m_anim;
    m_animId = m_anim->sub_02008A80(1, 0);
    SetSpriteRes(&m_banner, m_bannerRes->m_image, m_bannerRes->m_palette, m_bannerRes->m_cells);
    m_flashRes = new UnkClass_0201AAE0("BCO", "data/interface/i055_LZ.bin", "BCO:i055_00.NCBR", "BCO:i055.NCLR", "BCO:i055_00.NCER", NULL);
    SetSpriteRes(&m_flash, m_flashRes->m_image, m_flashRes->m_palette, m_flashRes->m_cells);
    SetSpriteRes(&m_flash2, m_flashRes->m_image, m_flashRes->m_palette, m_flashRes->m_cells);
    m_ringRes = new UnkClass_0201AAE0("BCO", "data/interface/i056_LZ.bin", "BCO:i056_00.NCBR", "BCO:i056.NCLR", "BCO:i056_00.NCER", NULL);
    SetSpriteRes(&m_ring, m_ringRes->m_image, m_ringRes->m_palette, m_ringRes->m_cells);
}

void UnkClass_0213F028::ov1_0213F2B4()
{
    SAFE_DELETE(m_bannerRes);
    SAFE_DELETE(m_flashRes);
    SAFE_DELETE(m_ringRes);
}

void UnkClass_0213F028::ov1_0213F338()
{
    switch (m_state) {
    case 0:
        break;
    case 1:
        ov1_0213F3D4();
        break;
    case 2:
        ov1_0213F41C();
        break;
    case 3:
        ov1_0213F490();
        break;
    case 4:
        ov1_0213F504();
        break;
    case 5:
        ov1_0213F578();
        break;
    case 6:
        ov1_0213F5A0();
        break;
    case 7:
        ov1_0213F608();
        break;
    case 8:
        ov1_0213F688();
        break;
    case 9:
        ov1_0213F6D0();
        break;
    case 10:
        ov1_0213F794();
        break;
    case 11:
        ov1_0213F7E4();
        break;
    }
}

void UnkClass_0213F028::ov1_0213F3D4()
{
    m_frame++;
    if (m_frame >= 1) {
        sub_02034184(CGame::GetInstance()->m_scriptManager, "system_000");
        ov1_0213F960(2);
    }
}

void UnkClass_0213F028::ov1_0213F41C()
{
    m_ring.m_scale[0] = LinearInterpolate(0x28, 0x1000, m_frame, 6);
    m_ring.SetPos(m_pos);
    m_frame++;
    if (m_frame > 6) {
        m_ring.m_scale[0] = 0x1000;
        ov1_0213F960(3);
    }
}

void UnkClass_0213F028::ov1_0213F490()
{
    m_ring.m_scale[1] = LinearInterpolate(0x28, 0x1000, m_frame, 10);
    m_ring.SetPos(m_pos);
    m_frame++;
    if (m_frame >= 10) {
        m_ring.m_scale[1] = 0x1000;
        ov1_0213F960(4);
    }
}

void UnkClass_0213F028::ov1_0213F504()
{
    fx32 dx = LinearInterpolate(0x100000, -0x60000, m_frame, 8);
    Point2D pos = m_pos;
    pos.x += dx;
    m_banner.SetPos(pos);
    m_frame++;
    if (m_frame > 8) {
        ov1_0213F960(5);
    }
}

void UnkClass_0213F028::ov1_0213F578()
{
    m_frame++;
    if (m_frame > 0x30) {
        ov1_0213F960(6);
    }
}

void UnkClass_0213F028::ov1_0213F5A0()
{
    m_anim->sub_02008A38(m_animId);
    m_banner.m_cellDataIdx = m_anim->sub_02008828(m_animId);
    m_frame++;
    if (m_frame > 0x20) {
        CGame::GetInstance()->m_audioEngine->sub_02034C44(0x3B);
        ov1_0213F960(7);
    }
}

void UnkClass_0213F028::ov1_0213F608()
{
    if (m_frame <= 8) {
        m_flash2.m_alpha = (u8)LinearInterpolate(31, 0, m_frame, 8);
        m_flash.m_alpha = 31;
    }
    m_anim->sub_02008A38(m_animId);
    m_banner.m_cellDataIdx = m_anim->sub_02008828(m_animId);
    m_frame++;
    if (m_frame >= 8) {
        ov1_0213F960(8);
    }
}

void UnkClass_0213F028::ov1_0213F688()
{
    m_frame++;
    if (m_frame > 0x18) {
        CGame::GetInstance()->m_textboxData->sub_02009FB0(1, 1);
        ov1_0213F960(9);
    }
}

void UnkClass_0213F028::ov1_0213F6D0()
{
    fx32 dx = LinearInterpolate(-0x60000, -0x180000, m_frame, 8);
    Point2D pos = m_pos;
    pos.x += dx;
    m_banner.SetPos(pos);
    dx = LinearInterpolate(0x3B000, 0x100000, m_frame, 8);
    pos.x = m_pos.x + dx;
    pos.y = m_pos.y + 0x5000;
    m_flash.SetPos(pos);
    m_flash2.SetPos(pos);
    m_frame++;
    if (m_frame > 8) {
        ov1_0213F960(10);
    }
}

void UnkClass_0213F028::ov1_0213F794()
{
    m_ring.m_scale[1] = LinearInterpolate(0x1000, 0x28, m_frame, 10);
    m_frame++;
    if (m_frame > 10) {
        m_ring.m_scale[1] = 0x28;
        ov1_0213F960(11);
    }
}

void UnkClass_0213F028::ov1_0213F7E4()
{
    m_ring.m_scale[0] = LinearInterpolate(0x1000, 0x28, m_frame, 6);
    m_frame++;
    if (m_frame > 6) {
        ov1_0213F960(0);
    }
}

void UnkClass_0213F028::ov1_0213F82C(Camera2D *camera)
{
    if (!IsActive()) {
        return;
    }
    ov1_0213F970(0x406);
    m_banner.Render(camera);
    m_flash.Render(camera);
    m_flash2.Render(camera);
    m_ring.Render(camera);
}

void UnkClass_0213F028::ov1_0213F8B4()
{
    if (m_type == 7) {
        return;
    }
    ov1_0213F960(1);
    m_ring.SetScale(0x28, 0x28);
    m_ring.SetPos(m_pos);
    m_flash.m_cellDataIdx = 0;
    m_flash.m_alpha = 0;
    m_flash.SetXY(m_pos.x + 0x3B000, m_pos.y + 0x5000);
    m_flash2.m_cellDataIdx = 1;
    m_flash2.m_alpha = 0;
    m_flash2.SetXY(m_pos.x + 0x3B000, m_pos.y + 0x5000);
    m_banner.SetXY(m_pos.x + 0x100000, m_pos.y);
}

void UnkClass_0213F028::ov1_0213F960(int state)
{
    m_frame = 0;
    m_state = state;
}

int UnkClass_0213F028::ov1_0213F970(int z)
{
    z += m_ring.GetCellNumOAMAttrs(m_ring.m_cellDataIdx);
    m_ring.m_z = z;
    z += m_banner.GetCellNumOAMAttrs(m_banner.m_cellDataIdx);
    m_banner.m_z = z;
    z += m_flash.GetCellNumOAMAttrs(m_flash.m_cellDataIdx);
    m_flash.m_z = z;
    z += m_flash2.GetCellNumOAMAttrs(m_flash2.m_cellDataIdx);
    m_flash2.m_z = z;
    return z;
}
