#include "battle/BattleAssistMenu.hpp"

#include "AudioEngine.hpp"
#include "BrightnessFade.hpp"
#include "CGame.hpp"
#include "CPlayerHPGauge.hpp"
#include "CellAnimController.hpp"
#include "GridOverlay.hpp"
#include "OamSprite.hpp"
#include "OamSpriteSet.hpp"
#include "ScriptManager.hpp"
#include "TextboxManager.hpp"
#include "UnkStruct_020107A8.hpp"
#include "battle/BattleInfoPanel.hpp"
#include "interpolation.hpp"
#include "scene/CBattleScene.hpp"

static const Point2D sSlotStart = { 0x100000, 0 };
static const Point2D sReturnEnd = { -0x100000, 0 };
static const Point2D sConfirmPos = { 0x100000, 0 };
static const Point2D sSendCtrl = { 0x40000, 0 };
static const Point2D sReturnCtrl = { -0x40000, 0 };
static const Point2D sSendStart = { 0x100000, 0 };

static const fx32 sScrollSpeeds[3] = { 0x8000, 0x4000, 0x2000 };

static const Point2D sSlotPositions[9][8] = {
    { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { -0x18000, -0x10000 }, { 0x18000, -0x10000 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { -0x18000, -0x1c000 }, { 0x18000, -0x1c000 }, { 0, 0x10000 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { -0x24000, -0x1c000 }, { 0xc000, -0x1c000 }, { -0xc000, 0x10000 }, { 0x24000, 0x10000 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { -0x30000, -0x1c000 }, { 0, -0x1c000 }, { 0x30000, -0x1c000 }, { -0x18000, 0x10000 }, { 0x18000, 0x10000 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
    { { -0x3c000, -0x1c000 }, { -0xc000, -0x1c000 }, { 0x24000, -0x1c000 }, { -0x24000, 0x10000 }, { 0xc000, 0x10000 }, { 0x3c000, 0x10000 }, { 0, 0 }, { 0, 0 } },
    { { -0x48000, -0x1c000 }, { -0x18000, -0x1c000 }, { 0x18000, -0x1c000 }, { 0x48000, -0x1c000 }, { -0x30000, 0x10000 }, { 0, 0x10000 }, { 0x30000, 0x10000 }, { 0, 0 } },
    { { -0x54000, -0x1c000 }, { -0x24000, -0x1c000 }, { 0xc000, -0x1c000 }, { 0x3c000, -0x1c000 }, { -0x3c000, 0x10000 }, { -0xc000, 0x10000 }, { 0x24000, 0x10000 }, { 0x54000, 0x10000 } },
};

static inline void SetSpriteRes(CSoftwareSprite *sprite, VramImage *image, VramPalette *palette, CNCERFile *cells)
{
    sprite->SetImage((UnkClass_CPrimitive_ImageProxy *)image, NULL);
    sprite->unk_34 = (UnkClass_CPrimitive_ImagePaletteProxy *)palette;
    sprite->unk_38 = (UnkClass_CSoftwareSprite_38 *)cells;
}

static inline Point2D GetSpritePos(CSoftwareSprite *sprite)
{
    Point2D pos;
    pos.x = sprite->m_coords[0];
    pos.y = sprite->m_coords[1];
    return pos;
}

static inline u32 RandomInt(CGame *game, u32 max)
{
    MATHRandContext32 *rand = &game->m_rand32;
    return MATH_Rand32(rand, max);
}

static inline void PlaySe(int se)
{
    CGame::GetInstance()->m_audioEngine->PlaySe(se);
}

BattleAssistMenu::BattleAssistMenu(void *table, BattlePokemonTable *params, BattleInfoPanel *info, GridOverlay *window)
{
    ov1_0213B27C();
    m_table = table;
    m_params = params;
    m_info = info;
    m_window = window;
    m_selected = FALSE;
    m_index = 0;
    ov1_0213C67C(0x42E);
    for (int i = 0; i < 8; i++) {
        m_rects[i].SetSize(0x30000, 0x30000);
    }
    m_okRect.SetSize(0x30000, 0x20000);
    m_okRect.SetPos(0, -0x48000);
    m_cancelRect.SetSize(0x20000, 0x20000);
    m_cancelRect.SetPos(0x70000, -0x50000);
    for (u8 i = 0; i < 8; i++) {
        SetSpriteRes(&m_slots[i], m_resSlots->m_image, m_resSlots->m_palette, m_resSlots->m_cells);
    }
    SetSpriteRes(&m_sprite67C, m_res060->m_image, m_res060->m_palette, m_res060->m_cells);
    SetSpriteRes(&m_sprite6C8, m_res061->m_image, m_res061->m_palette, m_res061->m_cells);
    SetSpriteRes(&m_sprite714, m_res060->m_image, m_res060->m_palette, m_res060->m_cells);
    SetSpriteRes(&m_sprite760, m_res063->m_image, m_res063->m_palette, m_res063->m_cells);
    SetSpriteRes(&m_sprite7AC, m_res064->m_image, m_res064->m_palette, m_res064->m_cells);
    for (u8 i = 0; i < 3; i++) {
        for (u8 j = 0; j < 6; j++) {
            SetSpriteRes(&m_bubbles[i][j], m_res064->m_image, m_res064->m_palette, m_res064->m_cells);
        }
    }
    for (u8 i = 0; i < 8; i++) {
        m_slots[i].m_cellDataIdx = 0;
    }
    m_sprite67C.m_cellDataIdx = 0;
    m_sprite6C8.m_cellDataIdx = 0;
    m_sprite714.m_cellDataIdx = 1;
    for (u8 i = 0; i < 3; i++) {
        for (u8 j = 0; j < 6; j++) {
            m_bubbles[i][j].m_cellDataIdx = (u8)(i + 1);
        }
    }
    m_sprite67C.SetXY(0, -0x48000);
    m_sprite6C8.SetXY(0x70000, -0x50000);
    m_sprite714.SetXY(0, -0x54000);
    m_sprite760.SetXY(0, -0x36000);
    ov1_0213CAC8();
    for (u8 i = 0; i < 8; i++) {
        m_slots[i].m_alpha = 14;
    }
    m_sprite7AC.SetScale(0x1000, 0x1000);
    m_timer = 0;
    m_state = 0;
}

BattleAssistMenu::~BattleAssistMenu()
{
    ov1_0213B454();
}

void BattleAssistMenu::ov1_0213B27C()
{
    m_resSlots = new GraphicsSet("BAM", "data/interface/i062_LZ.bin", "BAM:i062_00.NCBR", "BAM:i062.NCLR", "BAM:i062_00.NCER", "BAM:i062_00.cac");
    m_anim = m_resSlots->m_anim;
    for (u8 i = 0; i < 8; i++) {
        m_animIds[i] = m_anim->Create(1, 0);
    }
    m_res060 = new GraphicsSet("BAM", "data/interface/i060_LZ.bin", "BAM:i060_00.NCBR", "BAM:i060.NCLR", "BAM:i060_00.NCER", NULL);
    m_res061 = new GraphicsSet("BAM", "data/interface/i061_LZ.bin", "BAM:i061_00.NCBR", "BAM:i061.NCLR", "BAM:i061_00.NCER", NULL);
    m_res063 = new GraphicsSet("BAM", "data/interface/i063_LZ.bin", "BAM:i063_00.NCBR", "BAM:i063.NCLR", "BAM:i063_00.NCER", NULL);
    m_res064 = new GraphicsSet("BAM", "data/interface/i064_LZ.bin", "BAM:i064_00.NCBR", "BAM:i064.NCLR", "BAM:i064_00.NCER", NULL);
}

void BattleAssistMenu::ov1_0213B454()
{
    SAFE_DELETE(m_resSlots);
    SAFE_DELETE(m_res060);
    SAFE_DELETE(m_res061);
    SAFE_DELETE(m_res063);
    SAFE_DELETE(m_res064);
}

void BattleAssistMenu::ov1_0213B528(CTouchPanel *touch)
{
    m_timer++;
    switch (m_state) {
    case 1:
        ov1_0213B6B0();
        break;
    case 2:
        ov1_0213B6D0();
        break;
    case 3:
        ov1_0213B7C0(touch);
        break;
    case 4:
        ov1_0213BC04();
        break;
    case 5:
        ov1_0213BCEC();
        break;
    case 6:
        ov1_0213BD0C();
        break;
    case 7:
        ov1_0213BDC0();
        break;
    case 8:
        ov1_0213BE30();
        break;
    case 9:
        ov1_0213BEE0();
        break;
    }
    for (u8 i = 0; i < 8; i++) {
        m_motions[i].Update();
        ov1_0213C838(i, m_motions[i].m_pos.x, m_motions[i].m_pos.y);
    }
    m_anim->UpdateAll();
    for (u8 i = 0; i < 3; i++) {
        for (u8 j = 0; j < 6; j++) {
            Point2D pos = GetSpritePos(&m_bubbles[i][j]);
            pos.x -= sScrollSpeeds[i];
            if (pos.x <= -0x90000) {
                pos.x += 0x120000;
            }
            m_bubbles[i][j].SetPos(pos);
        }
    }
    ov1_0213BF20();
    m_info->ov1_0213E32C(0);
}

void BattleAssistMenu::ov1_0213B6B0()
{
    if (m_timer >= 8) {
        m_timer = 0;
        m_state = 2;
    }
}

void BattleAssistMenu::ov1_0213B6D0()
{
    switch (m_timer) {
    case 4:
        ov1_0213C8E8(0);
        break;
    case 8:
        ov1_0213C8E8(1);
        break;
    case 12:
        ov1_0213C8E8(2);
        break;
    case 16:
        ov1_0213C8E8(3);
        break;
    case 20:
        ov1_0213C8E8(4);
        break;
    case 24:
        ov1_0213C8E8(5);
        break;
    case 28:
        ov1_0213C8E8(6);
        break;
    case 32:
        ov1_0213C8E8(7);
        break;
    }
    if (m_timer >= 48) {
        m_timer = 0;
        m_state = 3;
    }
}

void BattleAssistMenu::ov1_0213B7C0(CTouchPanel *touch)
{
    if (((CBattleScene *)CGame::GetInstance()->currentScene)->unk_0014 != 0 && (u16)(CGame::GetInstance()->unk_0014->unk_0002 & 2)) {
        m_cancel = TRUE;
        m_timer = 0;
        m_state = 4;
    }
    Point2D tp;
    tp.x = (touch->unk_0A.x - 0x80) << 12;
    tp.y = (touch->unk_0A.y - 0x60) << 12;
    BOOL confirm = FALSE;
    BOOL handled = FALSE;
    if (!touch->unk_04) {
        return;
    }
    for (u8 i = 0; i < m_count; i++) {
        if (m_sources[i] == NULL) {
            continue;
        }
        if (!PointInRect(tp, m_rects[i].m_rectangle, 0)) {
            continue;
        }
        if (!(m_mask & (1 << i))) {
            continue;
        }
        if (m_selected == TRUE && m_index == i) {
            handled = TRUE;
            continue;
        }
        m_selected = TRUE;
        m_index = i;
        UnkStruct_020107A8 *info = PokeIdTable_Get(m_table, m_ids[m_index]);
        ov1_0213CA78(info->unk_04);
        u16 msg = ((CBattleScene *)CGame::GetInstance()->currentScene)->ov1_0211F010(m_ids[m_index]);
        int result = m_info->ov1_0213ECB4(info->unk_04, info->unk_05, info->unk_06);
        m_result = result;
        m_info->ov1_0213E8BC(msg);
        m_info->ov1_0213E68C();
        switch (result) {
        case 0:
            PlaySe(0xC);
            break;
        case 1:
            PlaySe(0xFB);
            break;
        case 2:
            PlaySe(0xFC);
            break;
        }
        handled = TRUE;
    }
    if (PointInRect(tp, m_okRect.m_rectangle, 0) && m_selected) {
        confirm = TRUE;
    }
    if (PointInRect(tp, m_cancelRect.m_rectangle, 0)) {
        m_cancel = TRUE;
        m_timer = 0;
        m_state = 4;
        PlaySe(0xC);
        m_info->ov1_0213EF40(0);
        m_info->ov1_0213EDDC();
        handled = TRUE;
    }
    if (confirm) {
        m_cancel = FALSE;
        m_motions[m_index].SetPos(sConfirmPos);
        m_sprite760.m_cellDataIdx = PokeIdTable_Get(m_table, m_ids[m_index])->unk_04;
        CGame::GetInstance()->m_mainFade->Start(1, 0x40);
        CGame::GetInstance()->m_subFade->Start(1, 0x40);
        m_window->Close();
        CBattleScene *scene = (CBattleScene *)CGame::GetInstance()->currentScene;
        if (m_partner && m_index == 0) {
            scene->ov1_0211EF74(m_ids[m_index], 1);
        } else {
            scene->ov1_0211EF74(m_ids[m_index], 0);
        }
        PlaySe(0xC);
        m_timer = 0;
        m_state = 5;
        return;
    }
    if (handled) {
        return;
    }
    if (!m_selected) {
        return;
    }
    m_selected = FALSE;
    CGame *game = CGame::GetInstance();
    game->m_textboxData->Clear(1);
    ScriptManager_Run(game->m_scriptManager, "sPokeSelect");
    m_info->ov1_0213EDDC();
    PlaySe(0xC);
}

void BattleAssistMenu::ov1_0213BC04()
{
    switch (m_timer) {
    case 4:
        ov1_0213C9B8(0);
        break;
    case 8:
        ov1_0213C9B8(1);
        break;
    case 12:
        ov1_0213C9B8(2);
        break;
    case 16:
        ov1_0213C9B8(3);
        break;
    case 20:
        ov1_0213C9B8(4);
        break;
    case 24:
        ov1_0213C9B8(5);
        break;
    case 28:
        ov1_0213C9B8(6);
        break;
    case 32:
        ov1_0213C9B8(7);
        break;
    }
    if (m_timer >= 48) {
        ov1_0213C60C();
    }
}

void BattleAssistMenu::ov1_0213BCEC()
{
    if (m_timer >= 64) {
        m_timer = 0;
        m_state = 6;
    }
}

void BattleAssistMenu::ov1_0213BD0C()
{
    if (m_timer == 1) {
        Point2D zero = { 0, 0 };
        m_motions[m_index].SetPos(sSendStart);
        m_motions[m_index].MoveQuadratic(zero, sSendCtrl, 16);
    }
    if (m_timer >= 16) {
        m_timer = 0;
        m_state = 7;
    }
}

void BattleAssistMenu::ov1_0213BDC0()
{
    if (m_timer == 1) {
        u16 cry = PokeIdTable_Get(CGame::GetInstance()->unk_1434, m_ids[m_index])->unk_00;
        CGame::GetInstance()->m_audioEngine->PlayStream(cry, 0x40);
    }
    if (m_timer >= 48) {
        m_timer = 0;
        m_state = 8;
    }
}

void BattleAssistMenu::ov1_0213BE30()
{
    if (m_timer == 1) {
        Point2D zero = { 0, 0 };
        m_motions[m_index].SetPos(zero);
        m_motions[m_index].MoveQuadratic(sReturnEnd, sReturnCtrl, 16);
    }
    if (m_timer >= 16) {
        m_timer = 0;
        m_state = 9;
    }
}

void BattleAssistMenu::ov1_0213BEE0()
{
    u8 alpha = LinearInterpolate(31, 1, m_timer, 16);
    ov1_0213CBD8(alpha);
    if (m_timer >= 16) {
        ov1_0213C60C();
    }
}

void BattleAssistMenu::ov1_0213BF20()
{
    if (m_fadeDir) {
        if (++m_fade >= 64) {
            m_fadeDir = 0;
        }
    } else {
        if (--m_fade == 0) {
            m_fadeDir = 1;
        }
    }
    u8 r = LinearInterpolate(31, 12, m_fade, 64);
    u8 g = LinearInterpolate(31, 12, m_fade, 64);
    u8 b = LinearInterpolate(31, 31, m_fade, 64);
    for (u8 i = 0; i < 16; i++) {
        m_palette[i] = GX_RGB(r, g, b);
    }
    DC_FlushRange(m_palette, sizeof(m_palette));
    GX_LoadOBJPltt(m_palette, 0xE0, sizeof(m_palette));
}

void BattleAssistMenu::ov1_0213BFFC(Camera2D *camera)
{
    switch (m_state) {
    case 0:
        break;
    case 1:
    case 2:
    case 3:
    case 4:
        ov1_0213C0F8(camera);
        ov1_0213C090(camera);
        ov1_0213C2A0(camera);
        if (m_selected) {
            ov1_0213C264(camera);
        }
        break;
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        ov1_0213C1A8(camera, m_index);
        ov1_0213C1D8(camera);
        break;
    }
}

void BattleAssistMenu::ov1_0213C090(Camera2D *camera)
{
    for (u8 i = 0; i < 8; i++) {
        u16 cell = m_anim->GetCell(m_animIds[i]);
        m_slots[i].m_cellDataIdx = cell;
        m_slots[i].Render(camera);
    }
}

void BattleAssistMenu::ov1_0213C0F8(Camera2D *camera)
{
    GXOamAttr *oam = (GXOamAttr *)CGame::GetInstance()->unk_0024;
    for (u8 i = 0; i < m_count; i++) {
        if (m_sources[i] != NULL) {
            oam = m_icons[i]->Write(oam, 0, 0);
            if (i == m_index && m_selected) {
                for (int j = 0; j < 4; j++) {
                    oam = m_outlines[i][j]->Write(oam, 0, 0);
                }
            }
        }
    }
}

void BattleAssistMenu::ov1_0213C1A8(Camera2D *camera, u8 index)
{
    m_icons[index]->Write((GXOamAttr *)CGame::GetInstance()->unk_0024, 0, 0);
}

void BattleAssistMenu::ov1_0213C1D8(Camera2D *camera)
{
    for (u8 i = 0; i < 3; i++) {
        for (u8 j = 0; j < 6; j++) {
            m_bubbles[i][j].Render(camera);
        }
    }
    m_sprite760.Render(camera);
    m_sprite7AC.Render(camera);
}

void BattleAssistMenu::ov1_0213C264(Camera2D *camera)
{
    m_sprite67C.Render(camera);
    m_sprite714.Render(camera);
}

void BattleAssistMenu::ov1_0213C2A0(Camera2D *camera)
{
    m_sprite6C8.Render(camera);
}

void BattleAssistMenu::ov1_0213C2BC(int count, OamSpriteSet **sprites, u16 *ids, u8 mask, BOOL partner)
{
    m_dispcnt = GX_GetOBJVRamModeChar();
    GX_SetOBJVRamModeChar(GX_OBJVRAMMODE_CHAR_1D_32K);
    GX_SetVisiblePlane(GX_GetVisiblePlane() | GX_PLANEMASK_OBJ);
    m_sources = sprites;
    m_ids = ids;
    m_count = count;
    for (u8 i = 0; i < 8; i++) {
        if (m_sources[i] != NULL) {
            m_icons[i] = m_sources[i]->AddSprite(0, 0, 0, 0);
            for (int j = 0; j < 4; j++) {
                m_outlines[i][j] = m_sources[i]->AddSprite(0, 0, 0, 0);
                m_outlines[i][j]->unk_1A = 7;
            }
        }
    }
    Point2D pos = sSlotStart;
    for (u8 i = 0; i < 8; i++) {
        m_slots[i].SetPos(sSlotStart);
        // Read through a pointer cast: taking pos's address keeps the optimizer from replacing this argument
        // with its own copy of sSlotStart (fake, needed for the frame layout)
        m_motions[i].SetPos(*(Point2D *)&pos);
        ov1_0213C838(i, pos.x, pos.y);
    }
    m_selected = FALSE;
    m_index = 0;
    m_cancel = TRUE;
    ov1_0213CAC8();
    ov1_0213CBD8(31);
    m_mask = mask;
    m_partner = partner;
    for (int i = 0; i < 8; i++) {
        if (m_sources[i] != NULL) {
            if (m_mask & (1 << i)) {
                m_icons[i]->unk_28 = 0;
                m_slots[i].m_color = GX_RGB(31, 31, 31);
            } else {
                m_icons[i]->unk_28 = 1;
                m_slots[i].m_color = GX_RGB(10, 10, 10);
            }
        }
    }
    for (u8 i = 0; i < 8; i++) {
        if (!(m_mask & (1 << i))) {
            m_anim->SetAnim(m_animIds[i], 0);
        } else {
            switch (m_info->ov1_0213EC40(PokeIdTable_Get(m_table, m_ids[i])->unk_04)) {
            case 0:
                m_anim->SetAnim(m_animIds[i], 0);
                break;
            case 1:
                m_anim->SetAnim(m_animIds[i], 1);
                break;
            case 2:
                m_anim->SetAnim(m_animIds[i], 2);
                break;
            }
        }
    }
    G2_SetBlendAlpha(0, 1, 8, 0);
    ScriptManager_Run(CGame::GetInstance()->m_scriptManager, "sPokeSelect");
    m_timer = 0;
    m_state = 1;
}

int BattleAssistMenu::ov1_0213C5F4()
{
    return m_cancel;
}

u8 BattleAssistMenu::ov1_0213C5FC()
{
    return m_index;
}

int BattleAssistMenu::ov1_0213C604()
{
    return m_result;
}

void BattleAssistMenu::ov1_0213C60C()
{
    GX_SetOBJVRamModeChar((GXOBJVRamModeChar)m_dispcnt);
    GX_SetVisiblePlane(GX_PLANEMASK_BG0);
    for (u8 i = 0; i < 8; i++) {
        if (m_sources[i] != NULL) {
            m_sources[i]->RemoveAll();
        }
    }
    m_timer = 0;
    m_state = 0;
}

int BattleAssistMenu::ov1_0213C67C(int z)
{
    for (u8 i = 0; i < 8; i++) {
        z += m_slots[i].GetCellNumOAMAttrs(m_slots[i].m_cellDataIdx) + 1;
        m_slots[i].m_z = z;
    }
    z += m_sprite67C.GetCellNumOAMAttrs(m_sprite67C.m_cellDataIdx) + 1;
    m_sprite67C.m_z = z;
    z += m_sprite6C8.GetCellNumOAMAttrs(m_sprite6C8.m_cellDataIdx) + 1;
    m_sprite6C8.m_z = z;
    z += m_sprite714.GetCellNumOAMAttrs(m_sprite714.m_cellDataIdx) + 1;
    m_sprite714.m_z = z;
    z += m_sprite760.GetCellNumOAMAttrs(m_sprite760.m_cellDataIdx) + 1;
    m_sprite760.m_z = z;
    z += m_sprite7AC.GetCellNumOAMAttrs(m_sprite7AC.m_cellDataIdx) + 1;
    m_sprite7AC.m_z = z;
    for (u8 i = 0; i < 6; i++) {
        z += m_bubbles[2][i].GetCellNumOAMAttrs(m_bubbles[2][i].m_cellDataIdx) + 1;
        m_bubbles[2][i].m_z = z;
    }
    for (u8 i = 0; i < 6; i++) {
        z += m_bubbles[1][i].GetCellNumOAMAttrs(m_bubbles[1][i].m_cellDataIdx) + 1;
        m_bubbles[1][i].m_z = z;
    }
    for (u8 i = 0; i < 6; i++) {
        z += m_bubbles[0][i].GetCellNumOAMAttrs(m_bubbles[0][i].m_cellDataIdx) + 1;
        m_bubbles[0][i].m_z = z;
    }
    return z;
}

void BattleAssistMenu::ov1_0213C838(u8 index, fx32 x, fx32 y)
{
    m_slots[index].SetXY(x, y);
    m_rects[index].SetPos(x, y);
    if (m_sources[index] != NULL) {
        int px = (x >> 12) + 0x80;
        int py = (y >> 12) + 0x60;
        m_icons[index]->SetPos(px, py);
        m_outlines[index][0]->SetPos(px, py - 2);
        m_outlines[index][1]->SetPos(px, py + 2);
        m_outlines[index][2]->SetPos(px - 2, py);
        m_outlines[index][3]->SetPos(px + 2, py);
    }
}

void BattleAssistMenu::ov1_0213C8E8(u8 index)
{
    if (index >= m_count) {
        return;
    }
    m_motions[index].SetX(sSlotPositions[m_count][index].x + 0x100000);
    m_motions[index].SetY(sSlotPositions[m_count][index].y);
    Point2D ctrl;
    Point2D end = sSlotPositions[m_count][index];

    ctrl.x = end.x + 0x20000;
    ctrl.y = end.y;
    m_motions[index].MoveQuadratic(end, ctrl, 16);
    PlaySe(0xC);
}

void BattleAssistMenu::ov1_0213C9B8(u8 index)
{
    if (index >= m_count) {
        return;
    }
    m_motions[index].SetPos(sSlotPositions[m_count][index]);
    Point2D end = sSlotPositions[m_count][index];
    Point2D ctrl;
    Point2D start = end;
    end.x = start.x - 0x100000;
    ctrl.x = start.x + 0x20000;
    ctrl.y = start.y;
    m_motions[index].MoveQuadratic(end, ctrl, 16);
    PlaySe(0xC);
}

void BattleAssistMenu::ov1_0213CA78(int type)
{
    char name[16];
    OS_SPrintf(name, "sAssist%03d", (u8)type);
    CGame *game = CGame::GetInstance();
    game->m_textboxData->Clear(1);
    ScriptManager_Run(game->m_scriptManager, name);
}

void BattleAssistMenu::ov1_0213CAC8()
{
    CGame *game = CGame::GetInstance();
    for (u8 i = 0; i < 3; i++) {
        for (u8 j = 0; j < 6; j++) {
            Point2D pos;
            pos.x = (RandomInt(game, 256) - 128) << 12;
            pos.y = (RandomInt(game, 64) - 32) << 12;
            m_bubbles[i][j].SetPos(pos);
        }
    }
}

void BattleAssistMenu::ov1_0213CBD8(int alpha)
{
    m_sprite760.m_alpha = alpha;
    m_sprite7AC.m_alpha = alpha;
    for (u8 i = 0; i < 3; i++) {
        for (u8 j = 0; j < 6; j++) {
            m_bubbles[i][j].m_alpha = alpha;
        }
    }
}
