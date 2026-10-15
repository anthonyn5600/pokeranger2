#include "UnkClass_0214FD4C.hpp"

#include "CPlayerHPGauge.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CSoftwareSprite.hpp"

static inline void SetSpriteRes(CSoftwareSprite *sprite, VramImage *image, VramPalette *palette, CNCERFile *cells)
{
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)cells;
}

UnkClass_0214FD4C::UnkClass_0214FD4C()
{
    Init();
}

UnkClass_0214FD4C::~UnkClass_0214FD4C()
{
    Release();
}

void UnkClass_0214FD4C::Init()
{
    m_z = 0x424;
    m_rect = new CPrimitiveRECT();
    m_rect->SetPos(0x70000, 0x50000);
    m_rect->SetSize(0x20000, 0x20000);
    m_res = new GraphicsSet("FMB", "/data/interface/i044_LZ.bin", "FMB:i044_00.NCBR", "FMB:i044.NCLR", "FMB:i044_00.NCER", "FMB:i044_00.cac");
    m_sprite = new CSoftwareSprite();
    SetSpriteRes(m_sprite, m_res->m_image, m_res->m_palette, m_res->m_cells);
    m_sprite->SetXY(0x70000, 0x50000);
    m_sprite->m_z = m_z;
}

void UnkClass_0214FD4C::Release()
{
    SAFE_DELETE(m_rect);
    SAFE_DELETE(m_sprite);
    SAFE_DELETE(m_res);
}

void UnkClass_0214FD4C::Update()
{
    if (m_flags & 1) {
        if (++m_frame >= 4) {
            m_sprite->m_cellDataIdx = 0;
        }
    }
}

void UnkClass_0214FD4C::Draw(Camera2D *camera)
{
    m_sprite->m_z = m_z;
    m_sprite->Render(camera);
}

void UnkClass_0214FD4C::Press()
{
    m_frame = 0;
    m_flags |= 1;
    m_sprite->m_cellDataIdx = 1;
}
