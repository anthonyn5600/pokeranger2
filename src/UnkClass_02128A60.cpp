#include "battle/UnkClass_02128A60.hpp"

#include "CPlayerHPGauge.hpp"
#include "battle/UnkClass_02128B24.hpp"
#include "interpolation.hpp"
#include "primitive/CSoftwareSprite.hpp"

UnkClass_02128A60::UnkClass_02128A60()
{
    ov1_02128A88();
}

UnkClass_02128A60::~UnkClass_02128A60()
{
    ov1_02128AF0();
}

void UnkClass_02128A60::ov1_02128A88()
{
    m_res = new UnkClass_0201AAE0("BDN", "/data/interface/i069_LZ.bin", "BDN:i069_00.NCBR", "BDN:i069.NCLR", "BDN:i069_00.NCER", "BDN:i069_00.cac");
}

void UnkClass_02128A60::ov1_02128AF0()
{
    SAFE_DELETE(m_res);
}

UnkClass_02128B24::UnkClass_02128B24()
{
    m_pos.x = 0;
    m_pos.y = 0;
    m_value = 0;
    m_sprite = new CSoftwareSprite();
    m_sprite->SetTransformParams(0, 0, FX32_ONE, FX32_ONE, 0, 0);
    m_sprite->m_color = GX_RGB(31, 31, 31);
    m_sprite->m_alpha = 31;
    m_sprite->m_polygonID = 0;
    m_data = NULL;
}

UnkClass_02128B24::~UnkClass_02128B24()
{
    SAFE_DELETE(m_sprite);
}

void UnkClass_02128B24::ov1_02128BE4(UnkClass_02128A60 *data)
{
    m_data = data;
    m_sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)data->m_res->m_image, NULL);
    m_sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)data->m_res->m_palette;
    m_sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)data->m_res->m_cells;
    m_sprite->m_cellDataIdx = 0;
}

void UnkClass_02128B24::ov1_02128C2C()
{
    if (m_state == 0) {
        return;
    }
    m_timer++;
    switch (m_state) {
    case 1:
        ov1_02128DD4();
        break;
    case 2:
        ov1_02128DF4();
        break;
    }
}

void UnkClass_02128B24::ov1_02128C70(Camera2D *camera)
{
    if (m_state == 0) {
        return;
    }
    u16 value = m_value;
    u8 count = value >= 10 ? 2 : 1;
    u8 digits[2];
    if (count == 1) {
        digits[0] = value;
    } else {
        digits[0] = value / 10;
        digits[1] = value % 10;
    }

    Point2D pos;
    pos.x = m_pos.x - (((count - 1) * 0xC000) >> 1);
    pos.y = m_pos.y - 0x6000;
    m_sprite->m_z = m_zDigits;
    for (u8 i = 0; i < count; i++) {
        m_sprite->SetPos(pos);
        m_sprite->m_cellDataIdx = digits[i];
        m_sprite->Render(camera);
        pos.x += 0xC000;
    }

    pos.x = m_pos.x;
    pos.y = m_pos.y + 0x5000;
    m_sprite->m_z = m_zLabel;
    m_sprite->SetPos(pos);
    m_sprite->m_cellDataIdx = 12;
    m_sprite->Render(camera);
}

void UnkClass_02128B24::ov1_02128DD4()
{
    if (m_timer >= 10) {
        m_state = 2;
        m_timer = 0;
    }
}

void UnkClass_02128B24::ov1_02128DF4()
{
    if (m_timer >= 20) {
        m_state = 0;
        m_timer = 0;
    }
    m_sprite->m_alpha = (u8)LinearInterpolate(31, 1, m_timer, 20);
}

void UnkClass_02128B24::ov1_02128E34(Point2D pos, int value)
{
    m_state = 1;
    m_timer = 0;
    SetPos(pos);
    m_value = value;
}

int UnkClass_02128B24::ov1_02128E74(int z)
{
    m_zDigits = z;
    z++;
    m_zLabel = z;
    return z;
}
