#include "battle/UnkClass_021382D0.hpp"

#include "CPlayerHPGauge.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CSoftwareSprite.hpp"

static inline void SetSpriteRes(CSoftwareSprite *sprite, VramImage *image, VramPalette *palette, CNCERFile *cells)
{
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)cells;
}

UnkClass_021382D0::UnkClass_021382D0()
{
    Init();
}

UnkClass_021382D0::~UnkClass_021382D0()
{
    Release();
}

void UnkClass_021382D0::Init()
{
    m_rect = new CPrimitiveRECT();
    m_rect->SetPos(-0x70000, 0x51000);
    m_rect->SetSize(0x20000, 0x20000);
    m_res = new GraphicsSet("BES", "/data/interface/i047_LZ.bin", "BES:i047_00.NCBR", "BES:i047.NCLR", "BES:i047_00.NCER", "BES:i047_00.cac");
    m_sprite = new CSoftwareSprite();
    SetSpriteRes(m_sprite, m_res->m_image, m_res->m_palette, m_res->m_cells);
    m_sprite->SetXY(-0x70000, 0x51000);
}

void UnkClass_021382D0::Release()
{
    SAFE_DELETE(m_rect);
    SAFE_DELETE(m_sprite);
    SAFE_DELETE(m_res);
}

void UnkClass_021382D0::ov1_02138460()
{
    if (m_flags & 1) {
        if (++m_frame >= 16) {
            m_sprite->m_cellDataIdx = 0;
        }
    }
}

void UnkClass_021382D0::ov1_02138490(Camera2D *camera)
{
    m_sprite->Render(camera);
}

void UnkClass_021382D0::ov1_021384A8()
{
    m_flags |= 1;
    m_frame = 0;
    m_sprite->m_cellDataIdx = 1;
}

int UnkClass_021382D0::ov1_021384CC(int z)
{
    int z2 = z + m_sprite->GetCellNumOAMAttrs(m_sprite->m_cellDataIdx);
    m_sprite->m_z = z2;
    return z2 + 1;
}
