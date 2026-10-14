#include "battle/BattleDiskRing.hpp"

#include "CPlayerHPGauge.hpp"
#include "CellAnimController.hpp"
#include "fx_utils.hpp"
#include "interpolation.hpp"
#include "primitive/CSoftwareSprite.hpp"

static inline void SetSpriteRes(CSoftwareSprite *sprite, VramImage *image, VramPalette *palette, CNCERFile *cells)
{
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)cells;
}

BattleDiskRing::BattleDiskRing()
{
    m_res = new GraphicsSet("BSE", "data/interface/i071_LZ.bin", "BSE:i071_00.NCBR", "BSE:i071.NCLR", "BSE:i071_00.NCER", "BSE:i071_00.cac");
    m_anim = m_res->m_anim;
    for (u8 i = 0; i < 3; i++) {
        m_cells0[i] = m_anim->Create(1, 0);
        m_cells1[i] = m_anim->Create(1, 0);
    }
    for (u8 i = 0; i < 3; i++) {
        m_sprites0[i] = new CSoftwareSprite();
        SetSpriteRes(m_sprites0[i], m_res->m_image, m_res->m_palette, m_res->m_cells);
        m_sprites0[i]->m_alpha = 0x12;
        m_sprites1[i] = new CSoftwareSprite();
        SetSpriteRes(m_sprites1[i], m_res->m_image, m_res->m_palette, m_res->m_cells);
        m_sprites1[i]->m_alpha = 0x1F;
    }
    for (u8 i = 0; i < 3; i++) {
        m_anim->SetAnim(m_cells0[i], (int)i);
        m_anim->SetAnim(m_cells1[i], i + 3);
    }
    u16 colors[3] = { 0x7F39, 0x739F, 0x33FF };
    for (u8 i = 0; i < 3; i++) {
        for (u8 j = 0; j < 8; j++) {
            m_lines[i][j].m_color = colors[i];
        }
    }
    m_angle = 0;
    m_radius = 0x20000;
    m_pos.x = 0;
    m_pos.y = 0;
}

BattleDiskRing::~BattleDiskRing()
{
    for (u8 i = 0; i < 3; i++) {
        SAFE_DELETE(m_sprites0[i]);
        SAFE_DELETE(m_sprites1[i]);
    }
    SAFE_DELETE(m_res);
}

void BattleDiskRing::ov1_0212D5DC()
{
    m_angle += 0x400;
    m_anim->UpdateAll();
    switch (m_state) {
    case 1:
        ov1_0212D774();
        break;
    case 3:
        ov1_0212D880();
        break;
    case 2:
    default:
        ov1_0212D870();
        break;
    }
    u16 angle;
    for (u8 i = 0; i < 3; i++) {
        angle = m_angle + i * 0x5555;
        Point2D prev = m_pos;
        prev.x += FX32_MUL(m_radius, FX_CosIdx(angle));
        prev.y += FX32_MUL(m_radius, FX_SinIdx(angle));
        for (u8 j = 0; j < 8; j++) {
            angle -= 0x555;
            Point2D next = m_pos;
            next.x += FX32_MUL(m_radius, FX_CosIdx(angle));
            next.y += FX32_MUL(m_radius, FX_SinIdx(angle));
            m_lines[i][j].SetStart(prev);
            m_lines[i][j].SetEnd(next);
            prev = next;
        }
    }
}

void BattleDiskRing::ov1_0212D774()
{
    m_frame++;
    m_radius = LinearInterpolate(0x40000, 0x20000, m_frame, 0x10);
    u8 alpha0 = LinearInterpolate(1, 0x12, m_frame, 0x10);
    for (u8 i = 0; i < 3; i++) {
        m_sprites0[i]->m_alpha = alpha0;
    }
    u8 alpha1 = LinearInterpolate(1, 0x1F, m_frame, 0x10);
    for (u8 i = 0; i < 3; i++) {
        m_sprites1[i]->m_alpha = alpha1;
    }
    ov1_0212DBB0(alpha1);
    if (m_frame >= 0x10) {
        m_radius = 0x20000;
        for (u8 i = 0; i < 3; i++) {
            m_sprites0[i]->m_alpha = 0x12;
            m_sprites1[i]->m_alpha = 0x1F;
        }
        m_state = 2;
        m_frame = 0;
    }
}

void BattleDiskRing::ov1_0212D870()
{
    ov1_0212DBB0(0x1F);
}

void BattleDiskRing::ov1_0212D880()
{
    m_frame++;
    m_radius = LinearInterpolate(0x20000, 0x40000, m_frame, 0x10);
    u8 alpha0 = LinearInterpolate(0x12, 1, m_frame, 0x10);
    for (u8 i = 0; i < 3; i++) {
        m_sprites0[i]->m_alpha = alpha0;
    }
    u8 alpha1 = LinearInterpolate(0x1F, 1, m_frame, 0x10);
    for (u8 i = 0; i < 3; i++) {
        m_sprites1[i]->m_alpha = alpha1;
    }
    ov1_0212DBB0(alpha1);
    if (m_frame >= 0x10) {
        m_radius = 0x40000;
        for (u8 i = 0; i < 3; i++) {
            m_sprites0[i]->m_alpha = 1;
            m_sprites1[i]->m_alpha = 1;
        }
        m_state = 0;
        m_frame = 0;
    }
}

void BattleDiskRing::ov1_0212D974(Camera2D *camera)
{
    if (m_state == 0) {
        return;
    }
    u16 angle = m_angle;
    for (u8 i = 0; i < 3; i++) {
        Point2D pos = m_pos;
        pos.x += FX32_MUL(m_radius, FX_CosIdx(angle));
        pos.y += FX32_MUL(m_radius, FX_SinIdx(angle));
        m_sprites0[i]->m_cellDataIdx = m_anim->GetCell(m_cells0[i]);
        m_sprites0[i]->SetPos(pos);
        m_sprites0[i]->Render(camera);
        m_sprites1[i]->m_cellDataIdx = m_anim->GetCell(m_cells1[i]);
        m_sprites1[i]->SetPos(pos);
        m_sprites1[i]->m_rotAngle = angle;
        m_sprites1[i]->Render(camera);
        angle += 0x5555;
        for (u8 j = 0; j < 8; j++) {
            m_lines[i][j].Render(camera);
        }
    }
}

void BattleDiskRing::ov1_0212DAF0()
{
    m_state = 1;
    m_frame = 0;
}

void BattleDiskRing::ov1_0212DB04()
{
    m_state = 3;
    m_frame = 0;
}

int BattleDiskRing::ov1_0212DB18(int z)
{
    for (u8 i = 0; i < 3; i++) {
        z += m_sprites0[i]->GetCellNumOAMAttrs(m_sprites0[i]->m_cellDataIdx);
        m_sprites0[i]->m_z = z;
        z += m_sprites1[i]->GetCellNumOAMAttrs(m_sprites1[i]->m_cellDataIdx) + 1;
        m_sprites1[i]->m_z = z;
        for (u8 j = 0; j < 8; j++) {
            m_lines[i][j].m_z = ++z;
        }
    }
    return z + 1;
}

void BattleDiskRing::ov1_0212DBB0(u8 alpha)
{
    for (u8 i = 0; i < 3; i++) {
        for (u8 j = 0; j < 8; j++) {
            m_lines[i][j].m_alpha = (u8)(LinearInterpolate(alpha << FX32_SHIFT, 0x1000, j, 8) >> FX32_SHIFT);
        }
    }
}
