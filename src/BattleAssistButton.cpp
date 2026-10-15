#include "battle/BattleAssistButton.hpp"

#include "CPlayerHPGauge.hpp"
#include "primitive/CPrimitiveRECT.hpp"
#include "primitive/CSoftwareSprite.hpp"

static inline void SetSpriteRes(CSoftwareSprite *sprite, VramImage *image, VramPalette *palette, CNCERFile *cells)
{
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)cells;
}

BattleAssistButton::BattleAssistButton()
{
    Init();
}

BattleAssistButton::~BattleAssistButton()
{
    Release();
}

void BattleAssistButton::Init()
{
    m_rect = new CPrimitiveRECT();
    m_rect->SetPos(0x70000, 0x50000);
    m_rect->SetSize(0x20000, 0x20000);
    m_res = new GraphicsSet("BAS", "/data/interface/i046_LZ.bin", "BAS:i046_00.NCBR", "BAS:i046.NCLR", "BAS:i046_00.NCER", "BAS:i046_00.cac");
    m_sprite = new CSoftwareSprite();
    SetSpriteRes(m_sprite, m_res->m_image, m_res->m_palette, m_res->m_cells);
    m_sprite->SetXY(0x70000, 0x50000);
}

void BattleAssistButton::Release()
{
    SAFE_DELETE(m_rect);
    SAFE_DELETE(m_sprite);
    SAFE_DELETE(m_res);
}

void BattleAssistButton::Update()
{
    if (m_flags & 1) {
        if (++m_frame >= 16) {
            m_sprite->m_cellDataIdx = 0;
        }
    }
}

void BattleAssistButton::Render(Camera2D *camera)
{
    m_sprite->Render(camera);
}

void BattleAssistButton::Press()
{
    m_flags |= 1;
    m_frame = 0;
    m_sprite->m_cellDataIdx = 1;
}

int BattleAssistButton::SetZ(int z)
{
    int z2 = z + m_sprite->GetCellNumOAMAttrs(m_sprite->m_cellDataIdx);
    m_sprite->m_z = z2;
    return z2 + 1;
}
