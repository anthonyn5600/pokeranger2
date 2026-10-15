#include "battle/BattleHitEffectGfx.hpp"

#include "CPlayerHPGauge.hpp"
#include "CellAnimController.hpp"
#include "battle/BattleHitEffect.hpp"
#include "primitive/CSoftwareSprite.hpp"

BattleHitEffectGfx::BattleHitEffectGfx()
{
    Load();
}

BattleHitEffectGfx::~BattleHitEffectGfx()
{
    Release();
}

void BattleHitEffectGfx::Load()
{
    m_res0 = new GraphicsSet("BHM", "data/interface/i027_LZ.bin", "BHM:i027_00.NCBR", "BHM:i027.NCLR", "BHM:i027_00.NCER", "BHM:i027_00.cac");
    m_res1 = new GraphicsSet("BHM", "data/interface/i068_LZ.bin", "BHM:i068_00.NCBR", "BHM:i068.NCLR", "BHM:i068_00.NCER", "BHM:i068_00.cac");
}

void BattleHitEffectGfx::Release()
{
    SAFE_DELETE(m_res0);
    SAFE_DELETE(m_res1);
}

BattleHitEffect::BattleHitEffect()
{
    m_data = NULL;
    unk_04 = FALSE;
    m_sprite0 = new CSoftwareSprite();
    m_sprite0->m_z = 0x3FF;
    m_sprite0->m_cellDataIdx = 1;
    m_sprite1 = new CSoftwareSprite();
    m_sprite1->m_z = 0x400;
    m_sprite1->m_cellDataIdx = 1;
}

BattleHitEffect::~BattleHitEffect()
{
    SAFE_DELETE(m_sprite0);
    SAFE_DELETE(m_sprite1);
}

void BattleHitEffect::Update()
{
    CellAnimController *anim;
    u16 id;
    BOOL done;

    if (!unk_04) {
        return;
    }
    done = TRUE;
    if (m_flags & 1) {
        anim = m_anim0;
        id = m_animId0;
        anim->UpdateAll();
        m_cell0 = anim->GetCell(id);
        done &= anim->GetStatus(id) == 0;
    }
    if (m_flags & 2) {
        anim = m_anim1;
        id = m_animId1;
        anim->UpdateAll();
        m_cell1 = anim->GetCell(id);
        done &= anim->GetStatus(id) == 0;
    }
    m_alpha = 31;
    m_scale = FX32_ONE;
    if (done) {
        unk_04 = FALSE;
    }
}

void BattleHitEffect::Render(Camera2D *camera)
{
    if (!unk_04) {
        return;
    }
    if (m_flags & 1) {
        CSoftwareSprite *sprite = m_sprite0;
        sprite->m_alpha = m_alpha;
        sprite->SetScale(m_scale, m_scale);
        sprite->SetPos(m_pos);
        sprite->m_cellDataIdx = m_cell0;
        sprite->Render(camera);
    }
    if (m_flags & 2) {
        CSoftwareSprite *sprite = m_sprite1;
        sprite->m_alpha = m_alpha;
        sprite->SetScale(m_scale, m_scale);
        sprite->SetPos(m_pos);
        sprite->m_cellDataIdx = m_cell1;
        sprite->Render(camera);
    }
}

void BattleHitEffect::SetData(BattleHitEffectGfx *data)
{
    m_data = data;
    m_anim0 = data->m_res0->m_anim;
    m_animId0 = m_anim0->Create(1, 0);
    m_anim1 = data->m_res1->m_anim;
    m_animId1 = m_anim1->Create(1, 0);

    GraphicsSet *res = m_data->m_res0;
    m_sprite0->SetImage((UnkClass_CPrimitive_ImageProxy *)res->m_image, NULL);
    m_sprite0->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)res->m_palette;
    m_sprite0->unk_38 = (UnkClass_CSoftwareSprite_38 *)res->m_cells;
    res = m_data->m_res1;
    m_sprite1->SetImage((UnkClass_CPrimitive_ImageProxy *)res->m_image, NULL);
    m_sprite1->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)res->m_palette;
    m_sprite1->unk_38 = (UnkClass_CSoftwareSprite_38 *)res->m_cells;
}

void BattleHitEffect::Show(fx32 x, fx32 y, int flags)
{
    unk_04 = TRUE;
    unk_08 = 0;
    m_pos.x = x;
    m_pos.y = y;
    m_alpha = 31;
    m_scale = FX32_ONE;
    m_flags = flags;
    if (m_flags & 1) {
        m_anim0->SetAnim(m_animId0, 0);
        m_anim0->Restart(m_animId0);
    }
    if (m_flags & 2) {
        m_anim1->SetAnim(m_animId1, 0);
        m_anim1->Restart(m_animId1);
    }
}
